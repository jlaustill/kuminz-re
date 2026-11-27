"""Round 41 stage A: the injector driver booster capacitor monitor, typed and named.
cm848_processFaultScanLookup (0x35fa8, run per cylinder event by engine_injectionAngle_tpuChannel6EventHandler) reads
the cylinder's booster capacitor channel (54 / 55) through a ROM record and checks it three ways: high threshold
(fault 328 / 330), low threshold (329 / 331), and the low voltage at injection count (stage C names). Its tables were
loose rows (j1939_pgn_lookup_ptr / j1939_message_def_ptr bytes, untyped pointers, calibration_constant_1).
- injector_driver_booster_capacitor_monitor_record_t[2] at 0x5762c (52 bytes each, decoded from the ROM: the channel,
  pointers into the channel's config and state, the fault numbers, the count pointers, the mask) and
  injector_driver_booster_capacitor_cylinder_record_t[8] at 0x57694 (10 bytes: the capacitor index and the four
  injector circuit faults that skip the cylinder; the table ends at the watchdog answer table 0x576e4).
- The RAM: the lookup cache, three per-capacitor word[2] counts, three per-cylinder word[8] counts, the low voltage
  mask (was injection_check_flags).
- The monitor and its initializer (mpc555_initSensorCalibrationTables) renamed.
Writes the label map (address,name,old_label,kind,dims). Idempotent.  usage: apply_r41a.py <repo> <map.csv>"""
import ast
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
src = open("/home/linux/.claude/jobs/374b0424/tmp/w15/apply_hand_worklist.py").read()
BANNED = ast.literal_eval(re.search(r"BANNED = (\{.*?\})", src, re.S).group(1))
P = "injector_driver_booster_capacitor"
R39 = "PR #53 round 41"
REC = f"{P}_monitor_record_t"
CYL = f"{P}_cylinder_record_t"
REC_FIELDS = [
    ("sensor_channel", "word", 2, "the capacitor's sensor channel (54 / 55): indexes sensor_channel_filtered_output and "
                                  "the channel enable / held value / forced reading bitmaps"),
    ("high_threshold_pointer", "word*", 4, "points at the channel config's high_threshold (0x5b560 / 0x5b570)"),
    ("low_threshold_pointer", "word*", 4, "points at the channel config's low_threshold"),
    ("high_fault", "word", 2, "fault number set above the high threshold: 328 / 330 "
                              "(booster_capacitor_1 / 2_voltage_high_error)"),
    ("low_fault", "word", 2, "fault number set below the low threshold: 329 / 331 "
                             "(booster_capacitor_1 / 2_voltage_low_error)"),
    ("debounce_limit_pointer", "word*", 4, "points at the channel config's debounce_limit (the per-cylinder count limit "
                                           "of both threshold checks)"),
    ("raw_value_pointer", "word*", 4, "points at the channel state's raw_adc_counts (0x40b722 / 0x40b72e): the QADC "
                                      "reading is stored there"),
    ("value_pointer", "word*", 4, "points at the channel state's value: the linearized reading is stored there"),
    ("held_value_pointer", "word*", 4, "points at the channel state's held_value (used while the channel's held value "
                                       "bit is set)"),
    ("linearization_axis_pointer", "word*", 4, "points at the capacitor's linearization axis (0x6429c / 0x642a8)"),
    ("linearization_values_pointer", "word*", 4, "points at the capacitor's linearization values"),
    ("high_fault_debounce_count_pointer", "word*", 4, f"points at {P}_high_fault_debounce_counts[capacitor]"),
    ("low_fault_debounce_count_pointer", "word*", 4, f"points at {P}_low_fault_debounce_counts[capacitor]"),
    ("spare_count_pointer", "word*", 4, f"points at {P}_spare_counts[capacitor]; no code reads this field"),
    ("low_voltage_mask", "word", 2, f"1 / 2: the bit {P}_low_voltage_mask takes when this capacitor's cylinders reach "
                                    f"{P}_low_voltage_count_limit"),
]
CYL_FIELDS = [
    ("capacitor_index", "word", 2, f"0 / 1: the cylinder's record in {P}_monitor_records"),
    ("injector_fast_decay_fault", "word", 2, "fault number (270 = injector_1_fast_decay_error for record 0)"),
    ("injector_open_circuit_fault", "word", 2, "fault number (286 = injector_1_open_circuit_error)"),
    ("injector_short_to_ground_fault", "word", 2, "fault number (269 = injector_1_short_to_ground_error)"),
    ("injector_short_to_battery_fault", "word", 2, "fault number (268 = injector_1_short_to_battery_error)"),
]
assert sum(f[2] for f in REC_FIELDS) == 0x34 and sum(f[2] for f in CYL_FIELDS) == 10
MON = "cm848_monitorInjectorDriverBoosterCapacitorVoltage"
INIT = "cm848_initializeInjectorDriverBoosterCapacitorMonitor"
# global rows: (address, name now or None for a new row, new name, type, comment)
GLOBALS = [
    ("0x0005762c", None, f"{P}_monitor_records", f"{REC}[2]",
     f"The booster capacitor records of {MON}, one per capacitor (channels 54 / 55), decoded from the ROM. Were 12 "
     "loose rows (j1939_pgn_lookup_ptr / j1939_message_def_ptr were the fault numbers)"),
    ("0x00057694", "calibration_constant_1", f"{P}_cylinder_records", f"{CYL}[8]",
     f"Per cylinder event: the capacitor that drives the cylinder's injector and the four injector circuit faults; "
     f"{MON} skips the cylinder while any of them is set. Capacitors alternate 0 / 1 by cylinder event; records 6 / 7 "
     "are unused on 6 cylinders (the table ends at supervisor_watchdog_answer_3_table)"),
    ("0x003fb228", None, f"{P}_voltage_linearization_cached_axis_offset", "word",
     f"The lookup cache both capacitors' linearizations share in {MON}; {INIT} sets it to 2"),
    ("0x003fb22a", None, f"{P}_high_fault_debounce_counts", "word[2]",
     "Per capacitor: the count of cylinders debouncing a high reading (the record's high_fault_debounce_count_pointer); "
     "the high fault heals when it and the cylinder's count are 0"),
    ("0x003fb22e", None, f"{P}_low_fault_debounce_counts", "word[2]",
     "Per capacitor: the same count for the low threshold (low_fault_debounce_count_pointer)"),
    ("0x003fb232", None, f"{P}_spare_counts", "word[2]",
     f"Per capacitor (spare_count_pointer): only {INIT} writes it and nothing reads it"),
    ("0x003fb236", "per_cylinder_timing_array", f"{P}_cylinder_high_fault_debounce_counts", "word[8]",
     f"Per cylinder: counts up while the capacitor reading is above the high threshold (up to the debounce limit, "
     f"then the high fault sets) and down otherwise ({MON}; cleared by {INIT})"),
    ("0x003fb246", "per_cylinder_sync_counter", f"{P}_cylinder_low_fault_debounce_counts", "word[8]",
     "Per cylinder: the same count for the low threshold"),
    ("0x003fb256", "per_cylinder_timing_counter", f"{P}_cylinder_low_voltage_counts", "word[8]",
     f"Per cylinder: counts up to {P}_low_voltage_count_limit while the reading is at or below "
     f"{P}_low_voltage_threshold (no cylinder cutout active), then sets {P}_low_voltage_mask; above it the count "
     f"falls (final_fueling below 0x3b) or resets"),
    ("0x0040b1fc", "injection_check_flags", f"{P}_low_voltage_mask", None,
     f"The record's low_voltage_mask (1 / 2) of the capacitor whose cylinders reached the low voltage count limit, 0 "
     f"when none: {MON} sets it and clears the bit once no cylinder of that capacitor counts; "
     "engine_injectionAngle_updateCutoutAndTimingDemand compares it with 1 / 2 / 0 (cutout class bit 8)"),
]
LOOSE = ["0x0005762e", "0x00057632", "0x00057636", "0x00057638", "0x0005763a", "0x0005763e", "0x00057642",
         "0x00057646", "0x0005764a", "0x0005764e", "0x00057652", "0x00057656"]
FUNCS = [
    ("0x00035fa8", "cm848_processFaultScanLookup", MON,
     f"The injector driver booster capacitor monitor, run for each cylinder event by "
     f"engine_injectionAngle_tpuChannel6EventHandler. For the cylinder's capacitor ({P}_cylinder_records -> "
     f"{P}_monitor_records) it stores the QADC reading of channel 54 / 55 and its linearization (or the held value), "
     f"then, while the engine is RUNNING, the cylinder's four injector circuit faults are clear, the driver ASIC is not "
     f"shut off, final_fueling is above 0x3a and supervisor register 36 bit 1 is not held low: above the high threshold "
     f"it debounces the cylinder and the capacitor counts up to the debounce limit and then sets the high fault (328 / "
     f"330), healing it once both counts are back at 0; the low threshold does the same for the low fault (329 / 331); "
     f"at or below {P}_low_voltage_threshold (no cutout active) it counts {P}_cylinder_low_voltage_counts up to the limit "
     f"and sets {P}_low_voltage_mask. (was cm848_processFaultScanLookup) | review-function-readability reviewed "
     f"2026-11-22 - Readability Medium Accuracy Confidence High"),
    ("0x00035f14", "mpc555_initSensorCalibrationTables", INIT,
     f"Clears the booster capacitor monitor's per-cylinder counts (three word[8] arrays) and per-capacitor counts, "
     f"{P}_low_voltage_mask, and sets the linearization lookup cache to 2 (was mpc555_initSensorCalibrationTables)"),
]
gp = os.path.join(out, "global_variables.csv")
g = open(gp).read().split("\n")
names = {l.split(",")[1] for l in g if l.startswith("0x") and len(l.split(",")) > 1}
if f"{P}_monitor_records" in names:
    print("already applied")
    sys.exit(0)
for r in GLOBALS:
    assert not any(t in BANNED for t in r[2].split("_")), r[2]
    assert r[2] not in names, r[2]
rows = ["address,name,old_label,kind,dims"]
for a in LOOSE:
    hits = [k for k, l in enumerate(g) if l.startswith(a + ",")]
    assert len(hits) == 1, a
    del g[hits[0]]
for a, cur, new, typ, comment in GLOBALS:
    if cur is None:
        assert not any(l.startswith(a + ",") for l in g), a
        j = max(k for k, l in enumerate(g) if l.startswith("0x") and int(l[:10], 16) < int(a, 16))
        g.insert(j + 1, f"{a},{new},{typ},{comment} ({R39})")
    else:
        i = next(k for k, l in enumerate(g) if l.startswith(a + "," + cur + ","))
        p = g[i].split(",", 3)
        old = p[3].strip() if len(p) > 3 else ""
        g[i] = f"{a},{new},{typ or p[2]},{comment} (was {cur}; {R39})" + (f" | earlier note: {old}" if old else "")
        rows.append(f"{a},{new},{cur},global,1")
open(gp, "w").write("\n".join(g))
sp = os.path.join(out, "structure_definitions.csv")
s = open(sp).read()
if f"\n{REC}," not in s:
    add = [f'{REC},,{n},{t},{z},"{c} ({R39})",,verified' for n, t, z, c in REC_FIELDS]
    add += [f'{CYL},,{n},{t},{z},"{c} ({R39})",,verified' for n, t, z, c in CYL_FIELDS]
    s = s.rstrip("\n") + "\n" + "\n".join(add) + "\n"
    open(sp, "w").write(s)
fp = os.path.join(out, "function_renames.csv")
f = open(fp).read().split("\n")
for a, cur, new, plate in FUNCS:
    i = next(k for k, l in enumerate(f) if l.startswith(a + "," + cur))
    f[i] = f"{a},{new},{plate}"
    rows.append(f"{a},{new},{cur},function,1")
open(fp, "w").write("\n".join(f))
with open(map_path, "w") as fh:
    fh.write("\n".join(rows) + "\n")
print(f"{len(GLOBALS)} global rows, {len(LOOSE)} loose rows removed, 2 struct types, 2 functions")
