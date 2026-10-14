// SHIM: MAME logmacro.h stand-in. pokey.cpp sets VERBOSE 0, so MAME's own
// macros never log; here they keep MAME's dead `if (VERBOSE & mask)` branch (args type-checked, never run).
#ifndef POKEY_SHIM_LOGMACRO_H
#define POKEY_SHIM_LOGMACRO_H
#ifndef VERBOSE
#define VERBOSE 0
#endif
#define LOG_GENERAL (1U << 0)
template <typename... T> inline void shim_log(T &&...) {}
#define LOGMASKED(mask, ...) do { if (VERBOSE & (mask)) shim_log(__VA_ARGS__); } while (false)
#define LOG(...) LOGMASKED(LOG_GENERAL, __VA_ARGS__)
#endif
