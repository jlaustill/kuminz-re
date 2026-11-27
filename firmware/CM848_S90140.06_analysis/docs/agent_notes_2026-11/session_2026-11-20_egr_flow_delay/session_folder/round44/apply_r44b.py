"""Round 44 stage B: name and cite the rows of nine e2m blocks that lie past the dumped parameter ID table. Each block's
CHR_CC layout fills a gap between dumped-table blocks exactly, and every record's description matches the code:
  8C30 (vacuum throttle, 6 bytes)     0x3ff6ca-0x3ff6cf   107D ends +0x42 @ 0x3ff6c8 | 107B @ 0x3ff6d0
  8B12 (cruise transition, 4 bytes)   0x408e96-0x408e99   118F ends +0x0C @ 0x408e94 | 1071 @ 0x408e9a
  8B4E (OCM thresholds, 12 bytes)     0x408a66-0x408a71   8C5F ends +0x12 @ 0x408a64 | then 8BAC
  8BAC (PPS cals, 28 bytes)           0x408a72-0x408a8d   then 8C55 @ 0x408a8e
  8B4F (OCM severity, 2 bytes)        0x40b54a-0x40b54b   8C60 ends +0x08 @ 0x40b548 (2 bytes) | then 8BAD
  8BAD (PPS state, 14 bytes)          0x40b54c-0x40b559   then 8C56 @ 0x40b55a
  8B50 (OCM EEPROM, 18 bytes)         0x3fee34-0x3fee45   then 8BAE
  8BAE (PPS auto zero, 4 bytes)       0x3fee46-0x3fee49
  8B51-8B55 (OCM tables)              ROM 0x5c80e-0x5c92d (back to back in block order)
  8B59 (OCM minimum miles)            0x3fd8ec            by meaning only (2000 miles)
PPS / vacuum throttle / cruise records come from the default e2m CHR_CC_11.45.01.07; the OCM blocks only exist in the
older CHR_CC_11.20.13.16 / CHR_CC_11.25.05.07 (same layout in both). Idempotent.
usage: apply_r44b.py <repo> <map.csv>"""
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
R = "PR #53 round 44"
ram = open(os.path.join(CM, "originals/cm848_ram.bin"), "rb").read()
CC = os.path.join(repo, "e2m-analysis/CHR/CHR_CC_11.45.01.07.e2m")
OCM = os.path.join(repo, "e2m-analysis/CHR/CHR_CC_11.25.05.07.e2m")
OCM_BLOCKS = {0x8B4E, 0x8B4F, 0x8B50, 0x8B51, 0x8B52, 0x8B53, 0x8B54, 0x8B55, 0x8B59}


def load(path):
    out = {}
    for line in open(path, errors="replace"):
        head, _, desc = line.strip().partition(";")
        f = head.split(",")
        if len(f) > 11 and re.fullmatch(r"[0-9A-Fa-f]{4}", f[2]) and re.fullmatch(r"[0-9A-Fa-f]{1,4}", f[3]):
            out.setdefault((int(f[2], 16), int(f[3], 16)), (f[0], f[1], f[9], f[10], desc.strip()))
    return out


E = {"cc": load(CC), "ocm": load(OCM)}


def rec(block, off):
    r = E["ocm" if block in OCM_BLOCKS else "cc"].get((block, off))
    assert r, f"no e2m record {block:04X} +{off:X}"
    return r


def dump(a, size, signed):
    v = int.from_bytes(ram[a - 0x3FA000:a - 0x3FA000 + size], "big")
    return v - (1 << (8 * size)) if signed and v >> (8 * size - 1) else v


def cite(block, off, a=None, size=2, note=None):
    name, unit, sign, scale, desc = rec(block, off)
    s = float(scale)
    if note is None and a is not None:
        v = dump(a, size, sign == "S")
        note = f"{v} = {v * s:.6g} here" if a < 0x3fd482 or a > 0x3feec1 else f"{v} in the dump"
    unit = f"{unit}, " if unit and unit.upper() not in ("NONE", "UNITLESS") else ""
    sgn = "signed, " if sign == "S" else ""
    return f"e2m {block:04X} +{off:X} {name} '{desc}' ({unit}{sgn}{s:g} per count{'; ' + note if note else ''})."


g = open(gp).read().split("\n")
idx = {l[:10]: k for k, l in enumerate(g) if l.startswith("0x")}
names = {l.split(",")[1] for l in g if l.startswith("0x") and len(l.split(",")) > 1}


def row(a):
    p = g[idx[a]].split(",", 3)
    return p + [""] * (4 - len(p))


def set_row(a, name, typ, comment):
    g[idx[a]] = f"{a},{name},{typ},{comment}"


if "oil_change_monitor_soot_percentage_cal" in names:
    print("already applied")
    sys.exit(0)
mapping = ["address,name,old_label,kind,dims"]


def rename(a, cur, new, head, history=None, tail="old", typ=None):
    p = row(a)
    assert p[1] == cur, (a, p[1], cur)
    assert not any(t in BANNED for t in new.split("_")), new
    assert new not in names, new
    old_comment = p[3]
    if tail == "old":
        rest = old_comment
    else:  # keep only the round 39 note of a stage A comment
        rest = old_comment.split(" | earlier note: ", 1)[1] if " | earlier note: " in old_comment else ""
    hist = history or f"was {cur}"
    set_row(a, new, typ or p[2], f"{head} ({hist}; {R})" + (f" | earlier note: {rest}" if rest else ""))
    names.add(new)
    mapping.append(f"{a},{new},{cur},global,1")


def prefix(a, cur, text, drop=None):
    p = row(a)
    assert p[1] == cur, (a, p[1], cur)
    c = p[3]
    if drop:
        assert c.startswith(drop), (a, c[:60])
        c = c[len(drop):]
    set_row(a, p[1], p[2], f"{text} {c}" if c else text)


# --- the three stage A rows get their e2m names
rename("0x003ff6ce", "all_speed_governor_vacuum_cruise_fueling_reduction", "vacuum_throttle_all_speed_governor_fueling_reduction",
       cite(0x8C30, 4, 0x3ff6ce) + " cm848_runOperatingModeSpeedGovernor (lhz @ 0xf738, the only direct access) subtracts it "
       "from all_speed_governor_fueling, floored at 0, while cruise_control_engaged_flag is 1 and "
       "algorithm_enable_flags_43_cal.vacuum_throttle_cruise_enable is set. 8C30 lies past the dumped parameter ID table; "
       "its CHR_CC layout (+0 / +2 / +4, 6 bytes) fills 0x3ff6ca-0x3ff6cf, between 107D's last record (+0x42 at "
       "0x3ff6c8) and 107B (0x3ff6d0)",
       history="was all_speed_governor_vacuum_cruise_fueling_reduction in a0c4d30, before that governor_override_fuel_decay",
       tail="round39")
rename("0x00408e96", "cruise_accelerator_override_throttle_threshold", "cruise_throttle_transition_threshold",
       cite(0x8B12, 0, 0x408e96) + " cm848_selectCruiseOrUserFueling (lhz @ 0x41270, the only direct access): on the "
       "accelerator path the operating mode governor takes the fueling from cruise only while "
       "commanded_throttle_state.commanded_throttle is above this, its fuel demand is above the cruise fueling and the "
       "cruise output differs from the road speed governor's; TSC1, modes 37 / 38 and the calibrated fixed fuel demand "
       "take it regardless. 8B12 lies past the dumped parameter ID table; its CHR_CC layout (+0 / +2, 4 bytes) fills "
       "0x408e96-0x408e99, between 118F's last record (+0x0C at 0x408e94) and 1071 (0x408e9a)",
       history="was cruise_accelerator_override_throttle_threshold in a0c4d30, before that governor_override_fuel_threshold",
       tail="round39")
rename("0x00408a76", "accelerator_pedal_single_channel_minimum_idle_threshold", "accelerator_pedal_test_cell_idle_threshold",
       cite(0x8BAC, 4, 0x408a76) + " The auto zero is the learned idle threshold (8BAE +0 PPS1_Auto_Zero = "
       "accelerator_pedal_idle_threshold_a_cal). cm848_calculateAcceleratorPedalDemandFromChannels (lhz @ 0x3d358, the "
       "only direct access): with the pedal fault latched, the demand stays valid only while the fault is "
       "pedal_position_sensor_2_low_error (fault 349, P2127: channel 98) and channel 97's idle threshold is at least this "
       "(78 >= 68 in the dump), the test cell case. 8BAC's CHR_CC layout (28 bytes) fills 0x408a72-0x408a8d, between 8B4E "
       "and 8C55 (0x408a8e)",
       history="was accelerator_pedal_single_channel_minimum_idle_threshold in a0c4d30, before that cruise_speed_target_min",
       tail="round39")
# --- the oil change monitor: the third accumulator is the oil soot percentage
SOOT = ("cm848_updateOilChangeMonitor adds oil_change_monitor_soot_percentage_by_end_of_injection_values (e2m 8B55, 0.01 % "
        "per 250 operating hours) x 85048 / 900000 on each pass that injects fuel: 900000 s = 250 h and 85048 = 0.01 / "
        "2.351589501e-8 x 0.2, so a pass counts 0.2 s (main_loop calls it once per 40-phase cycle).")
rename("0x00408a6e", "oil_change_monitor_engine_power_accumulator_threshold", "oil_change_monitor_soot_percentage_threshold",
       cite(0x8B4E, 8, 0x408a6e, size=4) + " Compared with oil_change_monitor_soot_percentage_cal in "
       "cm848_updateOilChangeMonitor. 8B4E lies past the dumped parameter ID table; its CHR_CC layout (three dwords) "
       "fills 0x408a66-0x408a71, between 8C5F's last record (+0x12 at 0x408a64) and 8BAC (0x408a72)")
rename("0x003fee3e", "oil_change_monitor_engine_power_accumulator_cal", "oil_change_monitor_soot_percentage_cal",
       cite(0x8B50, 0xA, 0x3fee3e, size=4) + " " + SOOT + " 8B50's CHR_CC layout (18 bytes) fills 0x3fee34-0x3fee45, up "
       "to 8BAE (0x3fee46)")
SEV = "oil_change_monitor_severity_factor_by_coolant_and_rpm"
SOOT_TABLE = "oil_change_monitor_soot_percentage_by_end_of_injection"
rename("0x0005c80e", "fuel_accumulation_weight_by_coolant_and_rpm_x_axis", f"{SEV}_x_axis",
       cite(0x8B51, 0, note="-50 .. 250 F") + " Lookup table - x axis of 10 breakpoints after its byte-length word - read "
       "by cm848_updateOilChangeMonitor. 8B51-8B55 sit back to back in block order at 0x5c80e-0x5c92d", tail="none")
rename("0x0005c824", "fuel_accumulation_weight_by_coolant_and_rpm_y_axis", f"{SEV}_y_axis",
       cite(0x8B52, 0, note="0 .. 3000 rpm") + " Lookup table - y axis of 10 breakpoints after its byte-length word - "
       "read by cm848_updateOilChangeMonitor", tail="none")
rename("0x0005c83a", "fuel_accumulation_weight_by_coolant_and_rpm_grid", f"{SEV}_grid",
       cite(0x8B53, 0, note="1.00 .. 2.00") + " Lookup table - 2-D grid: 10 rows of 10 values (z[(y - 1) x 10 + x - 1] / "
       "no header) - read by cm848_updateOilChangeMonitor", tail="none")
p = row("0x003fced8")
rename("0x003fced8", "fuel_accumulation_weight_by_coolant_and_rpm_cached_axis_offsets", f"{SEV}_cached_axis_offsets",
       p[3].split(" (was ")[0].replace("the lookup cache of fuel_accumulation_weight_by_coolant_and_rpm",
                                       f"the lookup cache of {SEV}"), tail="none")
rename("0x0040b54a", "oil_change_monitor_fuel_weight_percent", "oil_change_monitor_severity_factor",
       cite(0x8B4F, 0, 0x40b54a) + f" The output of {SEV}_grid: the weighted fuel adds the injected fuel x this / 100. "
       "8B4F (2 bytes in CHR_CC) fills 0x40b54a-0x40b54b, between 8C60's last record (+0x08 at 0x40b548) and 8BAD "
       "(0x40b54c)")
rename("0x0005c902", "engine_power_accumulator_increment_axis", f"{SOOT_TABLE}_axis",
       cite(0x8B54, 0, note="-20.04 .. -5.04 deg") + " Lookup table - x axis of 10 breakpoints after its byte-length "
       "word - read by cm848_updateOilChangeMonitor with main_injection_end_timing", tail="none")
rename("0x0005c918", "engine_power_accumulator_increment_values", f"{SOOT_TABLE}_values",
       cite(0x8B55, 0, note="47 .. 0.37 %") + " Lookup table - data: 10 values (one per axis breakpoint) after a "
       "byte-length word - read by cm848_updateOilChangeMonitor", tail="none")
p = row("0x003fcedc")
rename("0x003fcedc", "engine_power_accumulator_increment_cached_axis_offset", f"{SOOT_TABLE}_cached_axis_offset",
       p[3].split(" (was ")[0].replace("the lookup cache of engine_power_accumulator_increment",
                                       f"the lookup cache of {SOOT_TABLE}"), tail="none")
# --- citations on the rows whose names already fit
NOSCAN = "No direct access found (raw lis + displacement scan of the ROM and the live flash2)"
for a, cur, block, off, size in [
        ("0x00408a72", "accelerator_pedal_idle_learning_debounce_limit", 0x8BAC, 0x0, 2),
        ("0x00408a74", "accelerator_pedal_channel_disagreement_debounce_limit", 0x8BAC, 0x2, 2),
        ("0x00408a78", "accelerator_pedal_idle_position_initial", 0x8BAC, 0x6, 2),
        ("0x00408a7a", "accelerator_pedal_idle_threshold_offset", 0x8BAC, 0x8, 2),
        ("0x00408a7c", "accelerator_pedal_travel_span", 0x8BAC, 0xA, 2),
        ("0x00408a7e", "accelerator_pedal_idle_learning_deadband", 0x8BAC, 0xC, 2),
        ("0x00408a80", "accelerator_pedal_channel_disagreement_threshold", 0x8BAC, 0xE, 2),
        ("0x00408a82", "accelerator_pedal_off_idle_threshold", 0x8BAC, 0x10, 2),
        ("0x00408a84", "accelerator_pedal_dual_channel_enable_flag", 0x8BAC, 0x12, 1),
        ("0x00408a85", "accelerator_pedal_compare_relative_to_idle_flag", 0x8BAC, 0x13, 1),
        ("0x00408a86", "accelerator_pedal_idle_learning_gain", 0x8BAC, 0x14, 2),
        ("0x00408a88", "accelerator_pedal_disagreement_zero_demand_enable", 0x8BAC, 0x16, 2),
        ("0x00408a8a", "accelerator_pedal_idle_learning_total_step_limit", 0x8BAC, 0x18, 2),
        ("0x00408a8c", "accelerator_pedal_idle_learning_channel_step_limit", 0x8BAC, 0x1A, 2),
        ("0x0040b54c", "accelerator_pedal_dual_channel_validated_demand", 0x8BAD, 0x0, 2),
        ("0x0040b54e", "accelerator_pedal_dual_channel_demand", 0x8BAD, 0x2, 2),
        ("0x0040b550", "accelerator_pedal_channel_disagreement_flag", 0x8BAD, 0x4, 1),
        ("0x0040b551", "accelerator_pedal_sensor_fault_latched_flag", 0x8BAD, 0x5, 1),
        ("0x0040b552", "accelerator_pedal_channel97_circuit_fault_flag", 0x8BAD, 0x6, 1),
        ("0x0040b553", "accelerator_pedal_channel98_circuit_fault_flag", 0x8BAD, 0x7, 1),
        ("0x0040b554", "accelerator_pedal_idle_position_a", 0x8BAD, 0x8, 2),
        ("0x0040b556", "accelerator_pedal_idle_position_b", 0x8BAD, 0xA, 2),
        ("0x0040b558", "accelerator_pedal_input_fault_flag", 0x8BAD, 0xC, 2),
        ("0x003fee46", "accelerator_pedal_idle_threshold_a_cal", 0x8BAE, 0x0, 2),
        ("0x003fee48", "accelerator_pedal_idle_threshold_b_cal", 0x8BAE, 0x2, 2),
        ("0x00408a66", "oil_change_monitor_fuel_threshold_hundredth_gallons", 0x8B4E, 0x0, 4),
        ("0x00408a6a", "oil_change_monitor_distance_threshold_pulses", 0x8B4E, 0x4, 4),
        ("0x003fee34", "oil_change_monitor_fault_event_bits_cal", 0x8B50, 0x0, 2),
        ("0x003fee36", "oil_change_monitor_fuel_hundredth_gallons_cal", 0x8B50, 0x2, 4),
        ("0x003fee3a", "oil_change_monitor_distance_pulses_cal", 0x8B50, 0x6, 4),
        ("0x003fee42", "oil_change_monitor_reset_distance_pulses_cal", 0x8B50, 0xE, 4)]:
    prefix(a, cur, cite(block, off, int(a, 16), size=size))
prefix("0x003fd8ec", "oil_change_monitor_minimum_distance_pulses_cal",
       cite(0x8B59, 0, 0x3fd8ec, size=4) + " By meaning: 8B59 lies past the dumped table and no neighbour tiles it.")
prefix("0x00408e98", "cruise_bump_up_step_margin_scale", cite(0x8B12, 2, 0x408e98), drop="ROM (no e2m record): ")
p = row("0x00408e94")
old = ("No code reads it: no instruction in the ROM or the live flash2 forms its address (raw lis + displacement scan), "
       "and none forms a pointer to the 118F block.")
assert old in p[3]
set_row("0x00408e94", p[1], p[2], p[3].replace(old, "No direct access found: no instruction in the ROM or the live "
        "flash2 forms its address (raw lis + displacement scan; the firmware uses no small-data base register), and none "
        "forms a pointer to the 118F block."))
# --- documentation rows for 8C30 +0 / +2 (no direct access)
for a, new, off in [("0x003ff6ca", "vacuum_throttle_override_duty_cycle_threshold", 0),
                    ("0x003ff6cc", "vacuum_throttle_override_position_error_threshold", 2)]:
    assert a not in idx and new not in names and not any(t in BANNED for t in new.split("_")), new
    k = idx["0x003ff6ce"]
    g.insert(k, f"{a},{new},i16,{cite(0x8C30, off, int(a, 16))} {NOSCAN}; i16 from the signed record ({R})")
    idx = {l[:10]: j for j, l in enumerate(g) if l.startswith("0x")}
    names.add(new)
open(gp, "w").write("\n".join(g))
# --- plates
f = open(fp).read()
old = ("Updates the oil change monitor while it is enabled (config word mask 0x2000 and feature_selection_bits_cal mask "
       "0x04): it accumulates the distance since the last reset in speed-sensor pulses, the injected fuel weighted by "
       "coolant temperature and target rpm (one count per 0.01 US gallon at 100 percent weight) and a third table-driven "
       "accumulator (probably the oil soot estimate), and sets the flag at 0x40ae5e when any exceeds its threshold and "
       "the distance has reached its minimum.")
new = ("Updates the oil change monitor (e2m OCM_*) while it is enabled (algorithm_enable_flags_12_cal mask 0x2000 = e2m "
       "106B OCM_Enable, and feature_selection_bits_cal mask 0x04). It accumulates three amounts since the last reset: "
       "the distance (e2m 8B50 OCM_Miles_Since_Last_Reset, 1/8000 mile counts); the injected fuel weighted by "
       "oil_change_monitor_severity_factor (e2m 8B53 OCM_Oil_Severity_Factor_Table over coolant temperature and engine "
       "speed; one count per 0.01 US gallon at a factor of 1.00); and the oil soot percentage (e2m 8B55 "
       "OCM_Soot_Percentage_Table over main_injection_end_timing, 'based on 250 operating hours': each pass adds table "
       "x 85048 / 900000, 0.2 s of the table's rate in 2.351589501e-8 % counts). It sets oil_change_monitor_change_due_flag "
       "(e2m 1094 OCM_Interval_Warning_Flag) when any amount exceeds its e2m 8B4E threshold and the distance has reached "
       "oil_change_monitor_minimum_distance_pulses_cal (2000 miles here).")
if new not in f:
    assert f.count(old) == 1
    f = f.replace(old, new)
old = "cm848_updateOilChangeMonitor reads the result as its engine_power_accumulator_increment input."
new = (f"cm848_updateOilChangeMonitor reads the result as the axis input of its oil soot table ({SOOT_TABLE}, e2m 8B54 "
       "OCM_Soot_Percentage_EOI_Axis / 8B55).")
if new not in f:
    assert f.count(old) == 1
    f = f.replace(old, new)
open(fp, "w").write(f)
with open(map_path, "w") as fh:
    fh.write("\n".join(mapping) + "\n")
print(f"{len(mapping) - 1} renames, 33 citations, 2 documentation rows, 0x408e94 reworded, 2 plates")
