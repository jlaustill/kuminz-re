"""Round 48 stage A: the two OBD cooling monitors, placed from the default e2m CHR_CC_11.45.01.07:
  8A8B (22 bytes) 0x409fb8  tiled between 1901 and 18F1: the thermostat monitor (P0128) calibrations
  8A8C (26 bytes) 0x40ba48  anchored at its end by 18F0 (0x40ba62); a field match of 11 / 13 records on named rows
  8A9D (20 bytes) ROM 0x642ce tiled between 1631 and 164A: the coolant temperature in-range (CTIR) calibrations; the
                  test timer's limit DAT_000642d8 is +A CTIR_Max_Test_Time
  8A9E (6 bytes here) 0x40b9a2 field match +0..+4 (its +6 would collide with 1AEA's base 0x40b9a8)
Every signed record is loaded with lha and every unsigned one with lhz, so the signed ones are i16. The thermostat
calibrations +4 / +6 / +8 are retyped word -> i16 by the same rule. 'cssc_' was an invented abbreviation.
Idempotent.  usage: apply_r48a.py <repo> <map.csv>"""
import ast
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
CM = os.path.join(repo, "firmware/CM848_S90140.06_analysis")
gp = os.path.join(CM, "output/global_variables.csv")
src = open("/home/linux/.claude/jobs/374b0424/tmp/w15/apply_hand_worklist.py").read()
BANNED = ast.literal_eval(re.search(r"BANNED = (\{.*?\})", src, re.S).group(1))
R = "PR #53 round 48"
ram = open(os.path.join(CM, "originals/cm848_ram.bin"), "rb").read()
rom = open(os.path.join(CM, "originals/cm848_rom.bin"), "rb").read()
recs = {}
for line in open(os.path.join(repo, "e2m-analysis/CHR/CHR_CC_11.45.01.07.e2m"), errors="replace"):
    head, _, desc = line.strip().partition(";")
    f = head.split(",")
    if len(f) > 11 and re.fullmatch(r"[0-9A-Fa-f]{4}", f[2]) and re.fullmatch(r"[0-9A-Fa-f]{1,4}", f[3]):
        recs.setdefault((int(f[2], 16), int(f[3], 16)), (f[0], f[1], f[7], f[9], f[10], desc.strip()))


def cite(block, off, a, extra=""):
    name, unit, size, sign, scale, desc = recs[(block, off)]
    size = int(size)
    if 0x3FA000 <= a < 0x3FA000 + len(ram):
        v, where = int.from_bytes(ram[a - 0x3FA000:a - 0x3FA000 + size], "big"), "the dump"
    else:
        v, where = int.from_bytes(rom[a:a + size], "big"), "ROM"
    if sign == "S" and v >> (8 * size - 1):
        v -= 1 << (8 * size)
    unit = f"{unit}, " if unit.upper() not in ("NONE", "UNITLESS", "") else ""
    try:
        s = float(scale)
    except ValueError:  # an enumerated record (scale '00FF'): no engineering value
        return f"e2m {block:04X} +{off:X} {name} '{desc}' ({unit}enumerated; {v} in {where}){extra}."
    return (f"e2m {block:04X} +{off:X} {name} '{desc}' ({unit}{'signed, ' if sign == 'S' else ''}{s:g} per count; "
            f"{v} = {v * s:.6g} in {where}){extra}.")


g = open(gp).read().split("\n")
names = {l.split(",")[1] for l in g if l.startswith("0x") and len(l.split(",")) > 1}
if "thermostat_monitor_idle_timer" in names:
    print("already applied")
    sys.exit(0)


def index():
    return {l[:10]: k for k, l in enumerate(g) if l.startswith("0x")}


idx = index()
mapping = ["address,name,old_label,kind,dims"]


def row(a):
    p = g[idx[a]].split(",", 3)
    return p + [""] * (4 - len(p))


def check(new):
    assert new not in names and not any(t in BANNED for t in new.split("_")), new
    names.add(new)


def prefix(a, cur, text, typ=None):
    p = row(a)
    assert p[1] == cur, (a, p[1], cur)
    retype = f" (retyped {p[2]} -> {typ}: a signed record, every load lha; {R})" if typ else ""
    g[idx[a]] = f"{a},{p[1]},{typ or p[2]},{text}{retype} {p[3]}".rstrip()


def rename(a, cur, new, text):
    global idx
    p = row(a)
    assert p[1] == cur, (a, p[1], cur)
    check(new)
    g[idx[a]] = f"{a},{new},{p[2]},{text} (was {cur}; {R})" + (f" | earlier note: {p[3]}" if p[3] else "")
    mapping.append(f"{a},{new},{cur},global,1")


def add(a, new, typ, text, rendered):
    global idx
    assert a not in idx, a
    check(new)
    later = sorted(x for x in idx if int(x, 16) > int(a, 16))
    k = idx[later[0]] if later else len(g)
    g.insert(k, f"{a},{new},{typ},{text} ({R})")
    idx = index()
    mapping.append(f"{a},{new},{rendered},global,1")


TILE = " - the block fills the gap between dumped-table blocks {} and {} exactly"
# --- 8A8B: the thermostat monitor calibrations
add("0x00409fb8", "thermostat_monitor_minimum_start_coolant_temperature", "i16",
    cite(0x8A8B, 0, 0x409fb8, TILE.format("1901", "18F1")) + " cm848_runThermostatMonitor starts the test only with "
    "coolant_temperature_sensor_filtered at or above it (lha)", "DAT_00409fb8")
add("0x00409fba", "thermostat_monitor_maximum_start_coolant_temperature", "i16",
    cite(0x8A8B, 2, 0x409fba) + " ... and at or below it (lha)", "DAT_00409fba")
prefix("0x00409fbc", "thermostat_monitor_cold_soak_limit", cite(0x8A8B, 4, 0x409fbc), "i16")
prefix("0x00409fbe", "thermostat_monitor_battery_temperature_drop_limit", cite(0x8A8B, 6, 0x409fbe), "i16")
prefix("0x00409fc0", "thermostat_monitor_target_coolant_temperature", cite(0x8A8B, 8, 0x409fc0), "i16")
add("0x00409fc2", "thermostat_monitor_predicted_fuel_coefficient", "i16",
    cite(0x8A8B, 0xA, 0x409fc2) + " thermostat_monitor_maximum_fuel_to_pass = thermostat_monitor_coolant_rise_needed "
    "x 320 / (this + thermostat_monitor_predicted_fuel_alpha); the e2m's 'energy' is the fuel used (lha)", "DAT_00409fc2")
add("0x00409fc4", "thermostat_monitor_predicted_fuel_alpha", "i16",
    cite(0x8A8B, 0xC, 0x409fc4) + " Added to thermostat_monitor_predicted_fuel_coefficient (lha)", "DAT_00409fc4")
add("0x00409fc6", "thermostat_monitor_start_delay", "i16",
    cite(0x8A8B, 0xE, 0x409fc6) + " cm848_initDataStructures loads thermostat_monitor_start_delay_countdown from it (lha)",
    "DAT_00409fc6")
add("0x00409fc8", "thermostat_monitor_maximum_idle_time", "word",
    cite(0x8A8B, 0x10, 0x409fc8) + " The test aborts (state 7) once thermostat_monitor_idle_timer is above it and the "
    "test timer is below thermostat_monitor_abort_timer_percent of the initial test timer (lhz)", "DAT_00409fc8")
add("0x00409fca", "thermostat_monitor_abort_timer_percent", "word",
    cite(0x8A8B, 0x12, 0x409fca) + " Of thermostat_monitor_initial_test_timer, in 1/256 % (25600 = 100 %) (lhz)",
    "DAT_00409fca")
add("0x00409fcc", "thermostat_monitor_fan_inhibit_maximum_start_coolant_temperature", "i16",
    cite(0x8A8B, 0x14, 0x409fcc) + " A start coolant temperature above it sends the monitor to state 8 (lha)",
    "DAT_00409fcc")
# --- 8A8C: the thermostat monitor state
FM = " - 8A8C lies past the dumped table: its end meets 18F0's base, and 11 of its 13 records land on rows named from the code"
prefix("0x0040ba48", "thermostat_monitor_fuel_since_start", cite(0x8A8C, 0, 0x40ba48, FM))
prefix("0x0040ba4a", "thermostat_monitor_start_fuel_total", cite(0x8A8C, 2, 0x40ba4a))
add("0x0040ba4c", "thermostat_monitor_fuel_total", "word",
    cite(0x8A8C, 4, 0x40ba4c) + " cm848_runThermostatMonitor stores the scaled injected_fuel_running_total in it each step "
    "(sth); thermostat_monitor_fuel_since_start = this - thermostat_monitor_start_fuel_total", "DAT_0040ba4c")
prefix("0x0040ba4e", "thermostat_monitor_minimum_fuel_to_fail", cite(0x8A8C, 6, 0x40ba4e))
prefix("0x0040ba50", "thermostat_monitor_maximum_fuel_to_pass", cite(0x8A8C, 8, 0x40ba50))
prefix("0x0040ba52", "thermostat_monitor_start_coolant_temperature", cite(0x8A8C, 0xA, 0x40ba52))
prefix("0x0040ba54", "thermostat_monitor_coolant_rise_needed", cite(0x8A8C, 0xC, 0x40ba54))
prefix("0x0040ba56", "thermostat_monitor_start_battery_temperature", cite(0x8A8C, 0xE, 0x40ba56))
prefix("0x0040ba58", "thermostat_monitor_test_timer", cite(0x8A8C, 0x10, 0x40ba58))
add("0x0040ba5a", "thermostat_monitor_test_timer_rate", "word",
    cite(0x8A8C, 0x12, 0x40ba5a) + " Looked up from engine_load_at_current_speed_percent each pass and added to "
    "thermostat_monitor_test_timer_rate_accumulator", "DAT_0040ba5a")
prefix("0x0040ba5c", "thermostat_monitor_state", cite(0x8A8C, 0x14, 0x40ba5c))
rename("0x0040ba5e", "cssc_initial_warmup_budget", "thermostat_monitor_initial_test_timer",
       cite(0x8A8C, 0x16, 0x40ba5e) + " cm848_runThermostatMonitor copies thermostat_monitor_test_timer into it at the start")
rename("0x0040ba60", "cssc_conditioning_cycle_count", "thermostat_monitor_idle_timer", cite(0x8A8C, 0x18, 0x40ba60))
rename("0x003fd262", "cssc_oiltemp_cooling_rate_fraction", "thermostat_monitor_test_timer_rate_accumulator",
       "Adds thermostat_monitor_test_timer_rate each pass; every 100 takes one step of the fuel and timer update in "
       "cm848_runThermostatMonitor. No e2m record: named by code membership (beside the monitor's lookup caches)")
# --- 8A9D: the coolant temperature in-range (CTIR) calibrations, ROM
C = "coolant_temperature_sensor_performance_"
add("0x000642ce", C + "maximum_start_intake_air_temperature", "i16",
    cite(0x8A9D, 0, 0x642ce, TILE.format("1631", "164A")) + " Read by cm848_checkCoolantTemperatureSensorPerformance (lha)",
    "DAT_000642ce")
add("0x000642d0", C + "maximum_start_coolant_temperature", "i16", cite(0x8A9D, 2, 0x642d0) + " (lha)", "DAT_000642d0")
add("0x000642d2", C + "minimum_start_temperature", "i16", cite(0x8A9D, 4, 0x642d2) + " (lha)", "DAT_000642d2")
add("0x000642d4", C + "maximum_start_temperature", "i16", cite(0x8A9D, 6, 0x642d4) + " (lha)", "DAT_000642d4")
add("0x000642d6", C + "minimum_temperature_span", "i16",
    cite(0x8A9D, 8, 0x642d6) + " The least coolant_temperature_sensor_performance_temperature_span that passes (lha)",
    "DAT_000642d6")
add("0x000642d8", C + "maximum_test_time", "word",
    cite(0x8A9D, 0xA, 0x642d8) + " The limit of coolant_temperature_sensor_performance_test_timer (lhz)", "DAT_000642d8")
add("0x000642da", C + "start_delay", "i16", cite(0x8A9D, 0xC, 0x642da) + " (lha)", "DAT_000642da")
rename("0x000642dc", "coolant_temperature_check_minimum_engine_off_time", C + "minimum_engine_off_time",
       cite(0x8A9D, 0xE, 0x642dc) + " Named into the monitor's family")
add("0x000642de", C + "maximum_start_temperature_difference", "word", cite(0x8A9D, 0x10, 0x642de) + " (lhz)",
    "DAT_000642de")
add("0x000642e0", C + "key_on_delay", "word", cite(0x8A9D, 0x12, 0x642e0) + " (lhz)", "DAT_000642e0")
# --- 8A9E: the CTIR state
rename("0x0040b9a2", "cssc_coolant_monitoring_cycle_count", C + "test_timer",
       cite(0x8A9E, 0, 0x40b9a2, " - 8A9E lies past the dumped table; its +0..+4 land on the monitor's rows (its +6 would "
            "collide with 1AEA's base 0x40b9a8). The table's 1632 +4 BIR_Ratio here is drift") +
       " cm848_checkCoolantTemperatureSensorPerformance counts it up each pass against " + C + "maximum_test_time")
prefix("0x0040b9a4", C + "temperature_span", cite(0x8A9E, 2, 0x40b9a4))
prefix("0x0040b9a6", C + "state", cite(0x8A9E, 4, 0x40b9a6))
open(gp, "w").write("\n".join(g))
with open(map_path, "w") as fh:
    fh.write("\n".join(mapping) + "\n")
print(f"{len(mapping) - 1} names for the map (new rows + renames)")
