"""Round 51 stage A (labels and rows only; types are stage B, the bitfield structs stage C).
The gap 0x408d38-0x408d75 between dumped-table blocks 8A57 and 8D79 is FOUR absent blocks back to back
(8B9B 16 + 8C2C 24 + 8BB2 20 + 8B6B 2 bytes), which is why round 50's one / two-block search and the three-block
search found nothing. The same transmission / trip information modules give four more absent blocks whose layouts
match existing rows record for record: 8C2D (RAM 0x40b626), 8B6C (RAM 0x40b638), 8B6D (EEPROM mirror 0x3fee58)
and 8D1B (EEPROM mirror 0x3fee4c, table-resolved). Cites every row, renames where the e2m shows the code-derived
name is wrong or out of family, adds three rows (0x408d74 8B6B, 0x40b642 8B6C +A, no new type), renames
sensorDiagnosticsConfiguration and fixes the stale 8C34 citation at 0x40b58c.
Idempotent.  usage: apply_r51a.py <repo> <map.csv>"""
import ast
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
CM = os.path.join(repo, "firmware/CM848_S90140.06_analysis")
gp = os.path.join(CM, "output/global_variables.csv")
fp = os.path.join(CM, "output/function_renames.csv")
src = open("/home/linux/.claude/jobs/374b0424/tmp/w15/apply_hand_worklist.py").read()
BANNED = ast.literal_eval(re.search(r"BANNED = (\{.*?\})", src, re.S).group(1))
R = "PR #53 round 51"
ram = open(os.path.join(CM, "originals/cm848_ram.bin"), "rb").read()
rom = open(os.path.join(CM, "originals/cm848_rom.bin"), "rb").read()
recs = {}
for line in open(os.path.join(repo, "e2m-analysis/CHR/CHR_CC_11.45.01.07.e2m"), errors="replace"):
    head, _, desc = line.strip().partition(";")
    f = head.split(",")
    if len(f) > 11 and re.fullmatch(r"[0-9A-Fa-f]{4}", f[2]) and re.fullmatch(r"[0-9A-Fa-f]{1,4}", f[3]):
        labels = f[19] if len(f) > 19 and "=" in f[19] else ""
        recs.setdefault((int(f[2], 16), int(f[3], 16)), (f[0], f[1], f[7], f[9], f[10], desc.strip(), labels))


def numeric_scale(scale):
    """A scale is a number only with a decimal point or exponent, or without a leading zero ('1', '10');
    '00FF' / '0004' / '07' are enumerations or bit masks and give no engineering value."""
    if re.fullmatch(r"0[0-9A-Fa-f]+", scale) or re.search(r"[A-Da-fF]", scale.replace("E-", "").replace("E+", "")):
        return None
    try:
        return float(scale)
    except ValueError:
        return None


def cite(block, off, a):
    name, unit, size, sign, scale, desc, labels = recs[(block, off)]
    size = int(size)
    if 0x3FA000 <= a < 0x3FA000 + len(ram):
        v, where = int.from_bytes(ram[a - 0x3FA000:a - 0x3FA000 + size], "big"), "the dump"
    else:
        v, where = int.from_bytes(rom[a:a + size], "big"), "ROM"
    if sign == "S" and v >> (8 * size - 1):
        v -= 1 << (8 * size)
    head = f"e2m {block:04X} +{off:X} {name} '{desc}'"
    if unit.upper() == "HEX":
        return f"{head} (bit-mapped; 0x{v:0{2 * size}x} in {where})."
    s = numeric_scale(scale)
    unit = f"{unit}, " if unit.upper() not in ("NONE", "UNITLESS", "") else ""
    if s is None:
        lab = f" {labels.replace(':', ' / ')};" if labels else ""
        return f"{head} ({unit}enumerated;{lab} {v} in {where})."
    return (f"{head} ({unit}{'signed, ' if sign == 'S' else ''}{s:g} per count; {v} = {v * s:.6g} in {where}).")


g = open(gp).read().split("\n")
names = {l.split(",")[1] for l in g if l.startswith("0x") and len(l.split(",")) > 1}
if "trip_information_fault_minimum_time" in names:
    print("already applied")
    sys.exit(0)


def index():
    return {l[:10]: k for k, l in enumerate(g) if l.startswith("0x")}


idx = index()
mapping = ["address,name,old_label,kind,dims"]


def check(new):
    assert new not in names and not any(t in BANNED for t in new.split("_")), new
    names.add(new)


def row(a):
    p = g[idx[a]].split(",", 3)
    return p + [""] * (4 - len(p))


def cite_only(a, cur, block, off, extra=""):
    p = row(a)
    assert p[1] == cur, (a, p[1], cur)
    assert f"e2m {block:04X} +{off:X} " not in p[3], (a, "already cited")
    g[idx[a]] = f"{a},{p[1]},{p[2]},{cite(block, off, int(a, 16))}{extra} ({R}) {p[3]}".rstrip()


def rename(a, cur, new, block, off, text):
    p = row(a)
    assert p[1] == cur, (a, p[1], cur)
    check(new)
    head = (cite(block, off, int(a, 16)) + " " if block is not None else "") + text
    g[idx[a]] = f"{a},{new},{p[2]},{head} (was {cur}; {R})" + (f" | earlier note: {p[3]}" if p[3] else "")
    mapping.append(f"{a},{new},{cur},global,1")


def add(a, new, typ, block, off, text, rendered):
    global idx
    assert a not in idx, a
    check(new)
    later = sorted(x for x in idx if int(x, 16) > int(a, 16))
    g.insert(idx[later[0]] if later else len(g), f"{a},{new},{typ},{cite(block, off, int(a, 16))} {text} ({R})")
    idx = index()
    if rendered:
        mapping.append(f"{a},{new},{rendered},global,1")


SEL = "cm848_selectTransmissionTemperatureInUse"
CHECK = "cm848_checkTransmissionTemperatureSensorPerformance"
TRIP = "cm848_updateTripAndLifetimeCounters"
TILE = (" The gap 0x408d38-0x408d75 between dumped-table blocks 8A57 and 8D79 is four absent blocks back to back:"
        " 8B9B (16 bytes) + 8C2C (24) + 8BB2 (20) + 8B6B (2); every load / store in it lands on a record of its"
        " width and lha / lhz agree with the records' signs")
NEXT = " {} is the {} of the four blocks tiling 0x408d38-0x408d75 (see transmission_temperature_limp_in_delay_minimum_vehicle_speed)"

# ---- 8B9B at 0x408d38: the transmission temperature defaults and their limp-in delay -----------------------
rename("0x00408d38", "transmission_temperature_late_substitute_minimum_vehicle_speed",
       "transmission_temperature_limp_in_delay_minimum_vehicle_speed", 0x8B9B, 0,
       f"{SEL} counts transmission_temperature_limp_in_delay_timer down only while the engine runs above this vehicle "
       "speed out of park / neutral." + TILE)
cite_only("0x00408d3a", "transmission_temperature_adc_unchanged_reading_limit", 0x8B9B, 2,
          " The e2m's pass count before the initial transmission temperature is picked")
rename("0x00408d3c", "transmission_temperature_early_substitute_countdown_reload",
       "transmission_temperature_limp_in_delay_maximum", 0x8B9B, 4,
       f"The reload of transmission_temperature_limp_in_delay_timer: {SEL} reloads it while park / neutral is on "
       "and the delay has not run out")
rename("0x00408d40", "transmission_temperature_late_substitute", "transmission_temperature_default_after_limp_in_delay",
       0x8B9B, 8, f"{SEL}: transmission_temperature_in_use when the transmission and coolant temperature sensors both "
       "fault once transmission_temperature_limp_in_delay_timer has run out")
rename("0x00408d42", "transmission_temperature_early_substitute",
       "transmission_temperature_default_during_limp_in_delay", 0x8B9B, 0xA,
       f"{SEL}: transmission_temperature_in_use when both sensors fault while transmission_temperature_limp_in_delay_"
       "timer still runs")
cite_only("0x00408d44", "transmission_temperature_coolant_model_scale", 0x8B9B, 0xC)
cite_only("0x00408d46", "transmission_temperature_coolant_model_offset", 0x8B9B, 0xE)
rename("0x0040b622", "transmission_temperature_early_substitute_countdown", "transmission_temperature_limp_in_delay_timer",
       None, None,
       "e2m 8B9B's 'Trans Temp Delay Timer' (Trans_Sump_Limpin_Delay; no RAM record of its own in the e2m): while "
       "nonzero a double sensor fault gives transmission_temperature_default_during_limp_in_delay and at 0 "
       f"transmission_temperature_default_after_limp_in_delay. {SEL} counts it down once per pass while the engine "
       "runs above transmission_temperature_limp_in_delay_minimum_vehicle_speed out of park / neutral and reloads it "
       "from transmission_temperature_limp_in_delay_maximum in park / neutral")

# ---- 8C2C at 0x408d48: the P0711 transmission temperature rationality calibrations --------------------------
cite_only("0x00408d48", "transmission_temperature_rationality_start_test_maximum_battery_temperature", 0x8C2C, 0,
          NEXT.format("8C2C", "second"))
rename("0x00408d4a", "transmission_temperature_rationality_cold_soak_maximum_temperature",
       "transmission_temperature_rationality_start_test_maximum_transmission_temperature", 0x8C2C, 2,
       "The start test's transmission temperature limit (the twin of the coolant and battery limits at +4 / +0): "
       f"{CHECK} clears P0711 at or under it while transmission_temperature_rationality_insufficient_rise_flag_cal is "
       "clear; over it with the coolant and battery under their limits the start-too-hot flag is set")
cite_only("0x00408d4c", "transmission_temperature_rationality_start_test_maximum_coolant_temperature", 0x8C2C, 4)
cite_only("0x00408d4e", "transmission_temperature_rationality_start_snapshot_minimum_temperature", 0x8C2C, 6)
cite_only("0x00408d50", "transmission_temperature_rationality_start_snapshot_maximum_temperature", 0x8C2C, 8)
cite_only("0x00408d52", "transmission_temperature_rationality_minimum_swing", 0x8C2C, 0xA)
rename("0x00408d54", "transmission_temperature_rationality_minimum_driving_passes",
       "transmission_temperature_rationality_maximum_test_time", 0x8C2C, 0xC,
       f"{CHECK}: a swing still under transmission_temperature_rationality_minimum_swing once "
       "transmission_temperature_rationality_test_timer reaches it fails the check (insufficient rise) - with the "
       "soak qualified; the old name read the limit as a minimum")
rename("0x00408d56", "transmission_temperature_check_minimum_engine_off_time",
       "transmission_temperature_rationality_minimum_engine_off_time", 0x8C2C, 0xE,
       f"{CHECK} qualifies a cold soak only with engine_off_time_at_key_on at or over it (or the engine-off time "
       "unusable); minutes per the e2m. The prefix joins the transmission_temperature_rationality_* family")
cite_only("0x00408d58", "transmission_temperature_rationality_soak_maximum_coolant_battery_difference", 0x8C2C, 0x10)
cite_only("0x00408d5a", "transmission_temperature_rationality_start_wait_passes", 0x8C2C, 0x12)
cite_only("0x00408d5c", "transmission_temperature_rationality_swing_test_maximum_start_temperature", 0x8C2C, 0x14)
cite_only("0x00408d5e", "transmission_temperature_rationality_minimum_vehicle_speed", 0x8C2C, 0x16)

# ---- 8C2D at RAM 0x40b626: the P0711 check's own words ---------------------------------------------------------
rename("0x0040b626", "transmission_temperature_rationality_driving_pass_count",
       "transmission_temperature_rationality_test_timer", 0x8C2D, 0,
       "Zeroed on entering state 1 (sth @ 0x522ea0), +1 per pass with vehicle_speed_copy above 30 mph, capped at "
       "0xffff (lhz @ 0x522fa0, sth @ 0x522fb8), compared with transmission_temperature_rationality_maximum_test_time "
       "(lhz @ 0x522ff8). The 8C2D layout (three records) matches the three P0711 check words at 0x40b626-0x40b62b, "
       "record for record")
cite_only("0x0040b628", "transmission_temperature_rationality_driving_range", 0x8C2D, 2)
cite_only("0x0040b62a", "transmission_temperature_rationality_state", 0x8C2D, 4,
          " States 5 / 6 are this check's own transient pass / fail states before the report")

# ---- 8BB2 at 0x408d60: the output shaft speed sensor -------------------------------------------------------------
cite_only("0x00408d60", "output_speed_to_vehicle_speed_default_ratio", 0x8BB2, 0, NEXT.format("8BB2", "third"))
cite_only("0x00408d62", "transmission_output_speed_filter_coefficient", 0x8BB2, 2)
cite_only("0x00408d64", "transmission_output_speed_maximum", 0x8BB2, 4)
rename("0x00408d66", "transmission_output_speed_floor", "transmission_output_speed_minimum", 0x8BB2, 6,
       "The output shaft speed used while the sensor period is over transmission_output_speed_period_maximum; the "
       "twin of transmission_output_speed_maximum")
cite_only("0x00408d68", "transmission_output_speed_period_maximum", 0x8BB2, 8)
cite_only("0x00408d6c", "transmission_output_speed_period_minimum", 0x8BB2, 0xC)
cite_only("0x00408d70", "output_speed_sensor_periods_accumulated", 0x8BB2, 0x10)
cite_only("0x00408d71", "output_speed_sensor_pulses_per_revolution", 0x8BB2, 0x11)
cite_only("0x00408d72", "transmission_output_speed_pulse_timeout_reload", 0x8BB2, 0x12)

# ---- 8B6B at 0x408d74: the trip information fault time -----------------------------------------------------------
add("0x00408d74", "trip_information_fault_minimum_time", "word", 0x8B6B, 0,
    f"{TRIP}: once distance_sensor_fault_count (+1 per PCI 0x5D send while a vehicle speed sensor fault is set) "
    "passes it, bits 0x12 go into trip_information_distance_fault_status_cal. Read by one lhz and never stored: a "
    "ROM-copied calibration (ROM 0x6e98e = 100). 32 one-record blocks fit these last 2 bytes of the gap by width; "
    "the use picks 8B6B, a calibration compared with a fault persistence count (not a state, flag, learned value or "
    "counter)." + NEXT.format("8B6B", "fourth"), "DAT_00408d74")
p = row("0x003fcfb8")
assert p[1] == "distance_sensor_fault_count" and "the ROM limit at 0x408d74" in p[3]
g[idx["0x003fcfb8"]] = ",".join(p[:3]) + "," + p[3].replace(
    "the ROM limit at 0x408d74", f"trip_information_fault_minimum_time (e2m 8B6B TI_Fault_Period; {R})")

# ---- 8B6D at EEPROM mirror 0x3fee58: the lifetime and trip totals ------------------------------------------------
LAYOUT = (" The 8B6D layout (nine records) matches the nine rows 0x3fee58-0x3fee77 record for record; the next block "
          "(1191 Cruise_Saved_Set_Speed_On_Poweroff) starts at 0x3fee78")
cite_only("0x003fee58", "lifetime_fuel_used_cal", 0x8B6D, 0, LAYOUT)
cite_only("0x003fee5c", "lifetime_idle_time_cal", 0x8B6D, 4)
cite_only("0x003fee60", "lifetime_engine_run_time_cal", 0x8B6D, 8)
rename("0x003fee64", "trip_counter_status_flags_cal", "trip_information_distance_fault_status_cal", 0x8B6D, 0xC,
       f"{TRIP} sets 0x12 when a vehicle speed sensor fault outlasts trip_information_fault_minimum_time, 0x20 on a "
       "trip distance overflow and 0x04 on a lifetime distance overflow; a trip reset clears 0x30. Named for what "
       "the code logs here (distance faults): the e2m calls this word Trip_Info_Auto_Fault_Status, and 8B6B "
       "TI_Fault_Period's description says the delayed fault is logged in Trip_Info_Fault_Status (+E), yet the code "
       "logs it in this word")
rename("0x003fee66", "trip_and_lifetime_overflow_flags_cal", "trip_information_fault_status_cal", 0x8B6D, 0xE,
       f"{TRIP} keeps one overflow bit per counter here (lifetime 0x10 run time / 0x20 fuel / 0x40 idle fuel / 0x80 "
       "idle time; trip 0x400 run time / 0x800 fuel / 0x1000 idle fuel / 0x2000 idle time) and "
       "cm848_flagTripInformationPowerDownDataLoss sets 0x208 on a power-down data loss; a trip reset clears 0x3c08")
cite_only("0x003fee68", "trip_fuel_used_cal", 0x8B6D, 0x10)
cite_only("0x003fee6c", "trip_idle_fuel_used_cal", 0x8B6D, 0x14)
cite_only("0x003fee70", "trip_idle_time_cal", 0x8B6D, 0x18)
cite_only("0x003fee74", "trip_engine_run_time_cal", 0x8B6D, 0x1C)

# (8D1B at EEPROM mirror 0x3fee4c is table-resolved and both rows already cite it: nothing to do.)

# ---- 8B6C at RAM 0x40b638: the trip information cycle words ------------------------------------------------------
cite_only("0x0040b638", "fuel_used_increment", 0x8B6C, 0,
          " The 8B6C layout (six records) covers 0x40b638-0x40b647: five rows match their records' descriptions and "
          "+A J1850_Fuel_Used has no access")
cite_only("0x0040b63c", "trip_counter_pulse_delta", 0x8B6C, 4)
cite_only("0x0040b640", "pci_transmit_message_11_distance_pulses", 0x8B6C, 8)
add("0x0040b642", "pci_transmit_message_11_fuel_used", "word", 0x8B6C, 0xA,
    "Between pci_transmit_message_11_distance_pulses (+8) and engine_idling_flag (+C Trip_Info_State) in the 8B6C "
    "layout. No direct access found (raw lis + displacement scan of the ROM and the live flash2) and no pointer to it",
    None)
cite_only("0x0040b644", "engine_idling_flag", 0x8B6C, 0xC, " Only the idle state is used in this build")
cite_only("0x0040b646", "trip_counter_pulse_delta_raw", 0x8B6C, 0xE)

# ---- 0x40b58c: drop the stale 8C34 +12 citation -------------------------------------------------------------------
p = row("0x0040b58c")
stale = ("e2m 8C34 +12 TCC_Function_Timer 'Count of how long the TCC driver has been on this drive cycle' (SEC): ")
older = ("An older note put e2m 8C34 +12 TCC_Function_Timer here; 8BB6 and the code say otherwise")
assert p[1] == "governor_pressure_derivative_term" and p[3].startswith(stale) and older in p[3]
g[idx["0x0040b58c"]] = ",".join(p[:3]) + "," + p[3][len(stale):].replace(older, (
    "8C34's +12 / +14 / +16 records (TCC_Function_Timer / OD_Function_Timer / TCC_Ratio) exist only in the seven "
    "CHR_CC releases from 11.25.05.07 on; the earlier releases end 8C34 at +11, the layout this build's code uses "
    f"(8BB6 runs 0x40b58c-0x40b5a7; {R})"))
open(gp, "w").write("\n".join(g))

# ---- sensorDiagnosticsConfiguration -> cm848_flagTripInformationPowerDownDataLoss ----------------------------------
t = open(fp).read()
old = "0x00523760,sensorDiagnosticsConfiguration\n"
assert t.count(old) == 1
new_fn = "cm848_flagTripInformationPowerDownDataLoss"
assert re.fullmatch(r"(cm848|hpcr|mpc555)_[a-z][A-Za-z0-9]*", new_fn) and new_fn not in t
plate = ("Power-down step (cm848_applicationMain calls it twice after the RAM calibration refresh): while "
         "fault_detected_cal.power_down_data_lost_error is set it sets bits 0x208 of trip_information_fault_status_cal "
         "(e2m 8B6D +E Trip_Info_Fault_Status): bit 3 (a trip reset clears it) and bit 9 (a trip reset keeps it) "
         f"(was sensorDiagnosticsConfiguration; {R})")
assert "," not in plate
open(fp, "w").write(t.replace(old, f"0x00523760,{new_fn},{plate}\n"))
mapping.append(f"0x00523760,{new_fn},sensorDiagnosticsConfiguration,function,1")
with open(map_path, "w") as fh:
    fh.write("\n".join(mapping) + "\n")
print(f"{len(mapping) - 1} map entries")
