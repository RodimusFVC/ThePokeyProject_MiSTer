-- POKEY bus capture for unmodified MAME (plan 3.1).  Autoboot script.
-- Env:
--   POKEY_OUT     output file (raw event log, CPU-cycle timestamps, NO skew applied)
--   POKEY_INPUTS  optional scripted input: "Field Name@f0-f1;Other Field@f2-f3"
--                 (field held from frame f0 up to f1, frames counted by the frame notifier)
-- Raw format (tools/raw2ptr.py converts it to .ptr):
--   # raw v1 set=<s> clk=<hz> aspc=<attoseconds per cycle>
--   C <chip> <reg_base_hex> <pot_cb_mask_hex> <allpot_cb 0|1>
--   W <c> <chip> <reg> <data>   write tap, c = CPU cycle at the tap (= machine.time / aspc)
--   R <c> <chip> <reg> <data>   read tap, data = value the POKEY returned
--   P <c> <chip> <idx> <val>    pot_r port value (logged at reset and on every POTGO write)
--   F <c> <frame>               frame notifier (info)
--   E <c>                       machine stop
-- API refs (MAME 0.289 src): install_*_tap luaengine_mem.cpp:673-681 (handler kept in a global),
-- machine.time luaengine.cpp:1606, attotime.seconds/attoseconds 1119-1120, ioport fields
-- luaengine_input.cpp:243-270, notifiers luaengine.cpp:990-993.

local SETS = {
  centiped = { clk = 1512000, chips = { { "pokey", ":pokey", 0x1000, 0x100f, 0x00, 0 } } },
  warlords = { clk = 1512000, chips = { { "pokey", ":pokey", 0x1000, 0x100f, 0x0f, 0 } },
               paddles = { ":PADDLE0", ":PADDLE1", ":PADDLE2", ":PADDLE3" } },
  milliped = { clk = 1512000, chips = { { "pokey", ":pokey", 0x0400, 0x040f, 0x00, 1 },
                                        { "pokey2", ":pokey2", 0x0800, 0x080f, 0x00, 1 } } },
  -- mazeinv / multiped machine configs derive from milliped (centiped.cpp:1916,1961): allpot_r DSW1/DSW2
  mazeinv  = { clk = 1512000, chips = { { "pokey", ":pokey", 0x0400, 0x040f, 0x00, 1 },
                                        { "pokey2", ":pokey2", 0x0800, 0x080f, 0x00, 1 } } },
  multiped = { clk = 1512000, chips = { { "pokey", ":pokey", 0x1400, 0x140f, 0x00, 1 },
                                        { "pokey2", ":pokey2", 0x0800, 0x080f, 0x00, 1 } } },
  ccastles = { clk = 1250000, chips = { { "pokey1", ":pokey1", 0x9800, 0x99ff, 0x00, 0 },
                                        { "pokey2", ":pokey2", 0x9a00, 0x9bff, 0x00, 1 } } },
}

local machine = manager.machine
local sys = machine.system
local cfg = SETS[sys.name] or (sys.parent and SETS[sys.parent])
if cfg == nil then error("capture_pokey: no config for set " .. sys.name) end

local ATTO = 1000000000000000000
local ASPC = ATTO // cfg.clk
local Q, R = ATTO // ASPC, ATTO % ASPC
local function clk_of(t) return t.seconds * Q + (t.seconds * R + t.attoseconds) // ASPC end
local function now() return clk_of(machine.time) end

local out = io.open(os.getenv("POKEY_OUT"), "w")
local buf, nbuf = {}, 0
local function emit(s)
  nbuf = nbuf + 1
  buf[nbuf] = s
  if nbuf >= 4096 then out:write(table.concat(buf, "\n", 1, nbuf), "\n"); buf, nbuf = {}, 0 end
end

emit(string.format("# raw v1 set=%s clk=%d aspc=%d", sys.name, cfg.clk, ASPC))
local space = machine.devices[":maincpu"].spaces["program"]

local function log_paddles(c, chip)
  if cfg.paddles == nil then return end
  for i, tag in ipairs(cfg.paddles) do
    emit(string.format("P %d %s %d %d", c, chip, i - 1, machine.ioport.ports[tag]:read()))
  end
end

taps = {}   -- global: handlers must stay referenced
for _, ch in ipairs(cfg.chips) do
  local name, base = ch[1], ch[3]
  emit(string.format("C %s %x %02x %d", name, base, ch[5], ch[6]))
  table.insert(taps, space:install_write_tap(ch[3], ch[4], "pokeycap_w_" .. name,
    function(offset, data, mask)
      local c = now()
      local reg = offset & 0x0f
      emit(string.format("W %d %s %d %d", c, name, reg, data))
      if reg == 0x0b then log_paddles(c, name) end
    end))
  table.insert(taps, space:install_read_tap(ch[3], ch[4], "pokeycap_r_" .. name,
    function(offset, data, mask)
      emit(string.format("R %d %s %d %d", now(), name, offset & 0x0f, data))
    end))
  -- device_reset() ran pokey_potgo() at time 0 (pokey.cpp:380): log the pot values it saw
  log_paddles(0, name)
end
emit(string.format("# taps installed at c=%d", now()))

-- scripted input
local inputs = {}
local spec = os.getenv("POKEY_INPUTS")
if spec ~= nil and spec ~= "" then
  for item in string.gmatch(spec, "[^;]+") do
    local fname, f0, f1 = string.match(item, "^(.-)@(%d+)-(%d+)$")
    if fname == nil then error("capture_pokey: bad POKEY_INPUTS item " .. item) end
    local found = nil
    for _, port in pairs(machine.ioport.ports) do
      local f = port.fields[fname]
      if f ~= nil then found = f end
    end
    if found == nil then error("capture_pokey: no input field named '" .. fname .. "'") end
    table.insert(inputs, { field = found, f0 = tonumber(f0), f1 = tonumber(f1), name = fname })
  end
end

local frame = 0
frame_sub = emu.add_machine_frame_notifier(function()
  frame = frame + 1
  if frame % 60 == 0 then emit(string.format("F %d %d", now(), frame)) end
  for _, inp in ipairs(inputs) do
    if frame == inp.f0 then inp.field:set_value(1); emit(string.format("# input %s on f%d c=%d", inp.name, frame, now())) end
    if frame == inp.f1 then inp.field:clear_value(); emit(string.format("# input %s off f%d c=%d", inp.name, frame, now())) end
  end
end)

stop_sub = emu.add_machine_stop_notifier(function()
  emit(string.format("E %d", now()))
  out:write(table.concat(buf, "\n", 1, nbuf), "\n")
  out:close()
end)
