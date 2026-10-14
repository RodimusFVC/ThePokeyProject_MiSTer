// SHIM: minimal stand-in for MAME's emu.h so that the PRISTINE MAME 0.289
// ref/mame_0289/pokey.{cpp,h} compile unmodified as a standalone oracle.
//
// Only what pokey.{cpp,h} touch is provided.  Semantics that matter:
//  * scheduler().synchronize(cb, param)  -> push {cb,param} on the device's
//    deferred queue (MAME: zero-delay timer, fires after the POKEY's current
//    step / right after the current write).  The rig drains the queue.
//  * scheduler().synchronize()           -> no-op (read() resync, plan M-1).
//  * emu_timer::adjust(zero)             -> remove + append to the queue
//    (MAME timer_list remove/insert; equal expire = FIFO, schedule.cpp:847).
//  * devcb_write_line                    -> stores the last level (pins).
//  * devcb_read8 / allpot callbacks      -> std::function set by the rig.
//  * stream / save_item / state_add / LOG -> no-ops.
// Everything private/protected in pokey.h is made public (below) so the rig
// can read the MAME members directly (no accessor edits in MAME code).
#ifndef POKEY_SHIM_EMU_H
#define POKEY_SHIM_EMU_H

#include <cstdint>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <deque>
#include <iterator>
#include <string>
#include <type_traits>
#include <utility>

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef int32_t  s32;
typedef uint64_t u64;
typedef uint32_t offs_t;

#define ATTR_COLD
#define FUNC(x) &x, #x
#define TIMER_CALLBACK_MEMBER(name) void name(s32 param)
enum { CLEAR_LINE = 0, ASSERT_LINE = 1 };

namespace util {
template <typename T, typename U> constexpr T make_bitmask(U n)
{
	return T((static_cast<std::size_t>(n) < (8 * sizeof(T)) ? (std::make_unsigned_t<T>(1) << n) : std::make_unsigned_t<T>(0)) - 1);
}
}
template <typename T, typename U> constexpr T BIT(T x, U n) noexcept { return (x >> n) & T(1); }

struct attotime
{
	double v = 0.0;
	static const attotime zero;
	double as_double() const { return v; }
	std::string to_string() const { return std::to_string(v); }
};
// attotime::zero is defined in ref/pokey_ref.cpp (keeps this header C++14-clean)

class machine_config {};
typedef int device_type;
#define DECLARE_DEVICE_TYPE(Type, Class) extern const device_type Type;
#define DEFINE_DEVICE_TYPE(Type, Class, Short, Full) const device_type Type = 0;

// deferred queue entry: a bound callback + its param
struct shim_deferred
{
	std::function<void(s32)> fn;
	s32 param;
	const void *timer; // non-null for emu_timer entries (adjust re-queues)
};

class timer_expired_delegate
{
public:
	template <class T>
	timer_expired_delegate(void (T::*f)(s32), const char *, T *obj) : fn([obj, f](s32 p) { (obj->*f)(p); }) {}
	std::function<void(s32)> fn;
};

class device_scheduler
{
public:
	std::deque<shim_deferred> queue;
	void synchronize() {}
	void synchronize(timer_expired_delegate d, s32 param = 0) { queue.push_back({ d.fn, param, nullptr }); }
};

class emu_timer
{
public:
	device_scheduler *sched = nullptr;
	std::function<void(s32)> fn;
	void adjust(attotime, s32 param = 0)
	{
		auto &q = sched->queue;
		q.erase(std::remove_if(q.begin(), q.end(), [this](const shim_deferred &e) { return e.timer == this; }), q.end());
		q.push_back({ fn, param, this });
	}
};

class running_machine
{
public:
	device_scheduler m_sched;
	attotime m_time;
	device_scheduler &scheduler() { return m_sched; }
	const attotime &time() const { return m_time; }
	std::string describe_context() const { return std::string(); }
};

class sound_stream
{
public:
	using sample_t = float;
	void update() {}
	void set_sample_rate(uint32_t) {}
	void fill(int, sample_t) {}
	void put(int, int, sample_t) {}
	int samples() const { return 0; }
};

class device_t;

class devcb_read8
{
public:
	devcb_read8() {}
	devcb_read8(device_t &, uint8_t = 0) {}
	template <unsigned N>
	class array
	{
	public:
		array(device_t &, uint8_t) {}
		devcb_read8 &operator[](unsigned i) { return m_cb[i]; }
		devcb_read8 m_cb[N];
	};
	devcb_read8 &bind() { return *this; }
	bool isunset() const { return !fn; }
	uint8_t operator()(offs_t offset) { return fn(offset); }
	std::function<uint8_t(offs_t)> fn;
};

class devcb_write_line
{
public:
	devcb_write_line(device_t &, int init = 0) : level(init) {}
	devcb_write_line &bind() { return *this; }
	void operator()(int state) { level = state ? 1 : 0; ++writes; }
	int level;
	unsigned writes = 0;
};

template <typename Sig> class device_delegate;
template <typename R, typename... A>
class device_delegate<R (A...)>
{
public:
	device_delegate(device_t &) {}
	void resolve() {}
	template <typename F> void set(F &&f) { fn = std::forward<F>(f); }
	bool isnull() const { return !fn; }
	R operator()(A... a) { return fn(a...); }
	std::function<R (A...)> fn;
};

class device_t
{
public:
	device_t(const machine_config &, device_type, const char *, device_t *, uint32_t clock) : m_clock(clock) {}
	virtual ~device_t() {}
	running_machine &machine() { return m_machine; }
	uint32_t clock() const { return m_clock; }
	attotime clocks_to_attotime(uint64_t n) const { return attotime{ double(n) / double(m_clock) }; }
	template <class T>
	emu_timer *timer_alloc(void (T::*f)(s32), const char *, T *obj)
	{
		m_timers.emplace_back();
		emu_timer &t = m_timers.back();
		t.sched = &m_machine.m_sched;
		t.fn = [obj, f](s32 p) { (obj->*f)(p); };
		return &t;
	}
	template <typename... T> void save_item(T &&...) {}
	virtual void device_start() {}
	virtual void device_reset() {}
	virtual void device_post_load() {}
	virtual void device_clock_changed() {}

	running_machine m_machine;
	uint32_t m_clock;
	std::deque<emu_timer> m_timers; // deque: stable addresses
};
#define NAME(x) x
#define STRUCT_MEMBER(s, m) s

class device_sound_interface
{
public:
	device_sound_interface(const machine_config &, device_t &) {}
	virtual ~device_sound_interface() {}
	sound_stream *stream_alloc(int, int, uint32_t) { return &m_shim_stream; }
	virtual void sound_stream_update(sound_stream &) {}
	sound_stream m_shim_stream;
};

class device_execute_interface
{
public:
	device_execute_interface(const machine_config &, device_t &) {}
	virtual ~device_execute_interface() {}
	void set_icountptr(int &) {}
	virtual void execute_run() {}
};

class device_state_interface
{
public:
	device_state_interface(const machine_config &, device_t &) {}
	virtual ~device_state_interface() {}
	template <typename T> void state_add(int, const char *, T &) {}
};

// Expose MAME's private/protected members to the rig (std headers are all
// included above, so this only affects pokey.h).
#define private public
#define protected public

#endif
