"""Round 46 stage A: the oil pressure gauge state, the warning chime and the TSC1-lost flag, from the default e2m
CHR_CC_11.45.01.07 (full records read, no truncation).
  8A7F (10 bytes) 0x40b532-0x40b53b  tiled: fills the gap between 8D38 and 8C69
  8A7C (12 bytes) 0x40b1ee-0x40b1f9  tiled: fills the gap between 8A26 and 8C54 (+8 / +A belong to stage B)
  8B2D (10 bytes) 0x408732-0x40873b  field match: five chime records on the five alert rows, same widths; the
                                     countdown formula multiplies a count by Cluster_Warning_Chime_Duration
Idempotent.  usage: apply_r46a.py <repo> <map.csv>"""
import ast
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
CM = os.path.join(repo, "firmware/CM848_S90140.06_analysis")
gp, fp = os.path.join(CM, "output/global_variables.csv"), os.path.join(CM, "output/function_renames.csv")
src = open("/home/linux/.claude/jobs/374b0424/tmp/w15/apply_hand_worklist.py").read()
BANNED = ast.literal_eval(re.search(r"BANNED = (\{.*?\})", src, re.S).group(1))
R = "PR #53 round 46"
ram = open(os.path.join(CM, "originals/cm848_ram.bin"), "rb").read()
recs = {}
for line in open(os.path.join(repo, "e2m-analysis/CHR/CHR_CC_11.45.01.07.e2m"), errors="replace"):
    head, _, desc = line.strip().partition(";")
    f = head.split(",")
    if len(f) > 11 and re.fullmatch(r"[0-9A-Fa-f]{4}", f[2]) and re.fullmatch(r"[0-9A-Fa-f]{1,4}", f[3]):
        recs.setdefault((int(f[2], 16), int(f[3], 16)), (f[0], f[1], f[7], f[9], f[10], desc.strip()))


def cite(block, off, a, extra=""):
    name, unit, size, sign, scale, desc = recs[(block, off)]
    v = int.from_bytes(ram[a - 0x3FA000:a - 0x3FA000 + int(size)], "big")
    unit = f"{unit}, " if unit.upper() not in ("NONE", "UNITLESS", "") else ""
    try:
        s = float(scale)
    except ValueError:  # an enumerated record (scale 'FF'): no engineering value
        return f"e2m {block:04X} +{off:X} {name} '{desc}' ({unit}enumerated; {v} in the dump){extra}."
    return f"e2m {block:04X} +{off:X} {name} '{desc}' ({unit}{s:g} per count; {v} = {v * s:.6g} in the dump){extra}."


g = open(gp).read().split("\n")
idx = {l[:10]: k for k, l in enumerate(g) if l.startswith("0x")}
names = {l.split(",")[1] for l in g if l.startswith("0x") and len(l.split(",")) > 1}
if "warning_chime_countdown" in names:
    print("already applied")
    sys.exit(0)
mapping = ["address,name,old_label,kind,dims"]


def row(a):
    p = g[idx[a]].split(",", 3)
    return p + [""] * (4 - len(p))


def prefix(a, cur, text):
    p = row(a)
    assert p[1] == cur, (a, p[1], cur)
    g[idx[a]] = f"{a},{p[1]},{p[2]},{text} {p[3]}".rstrip()


def rename(a, cur, new, text):
    p = row(a)
    assert p[1] == cur, (a, p[1], cur)
    assert new not in names and not any(t in BANNED for t in new.split("_")), new
    g[idx[a]] = f"{a},{new},{p[2]},{text} (was {cur}; {R})" + (f" | earlier note: {p[3]}" if p[3] else "")
    names.add(new)
    mapping.append(f"{a},{new},{cur},global,1")


TILE = " - the block fills the gap between dumped-table blocks {} and {} exactly"
# --- 8A7F: the oil pressure gauge state
prefix("0x0040b532", "low_oil_pressure_active_flag", cite(0x8A7F, 0, 0x40b532, TILE.format("8D38", "8C69")))
rename("0x0040b534", "low_oil_pressure_derate_flag", "low_oil_pressure_chime_flag",
       cite(0x8A7F, 2, 0x40b534) + " Set with low_oil_pressure_active_flag; its only consumer, "
       "cm848_updateEngineWarningFlags, starts warning_chime_countdown on its rising edge (the old name read it as a "
       "derate)")
prefix("0x0040b536", "low_oil_pressure_debounce_limit", cite(0x8A7F, 4, 0x40b536))
prefix("0x0040b538", "engine_oil_pressure", cite(0x8A7F, 6, 0x40b538))
prefix("0x0040b53a", "oil_pressure_model_unfiltered",
       cite(0x8A7F, 8, 0x40b53a) + " The name stays: this firmware uses the table (e2m 8A82 OPG_Threshold_Table) only "
       "as the switch-only pressure model behind engine_oil_pressure, never as a threshold.")
rename("0x003fcdb6", "low_oil_pressure_derate_flag_previous", "low_oil_pressure_chime_flag_previous",
       "low_oil_pressure_chime_flag at the end of the previous cm848_updateEngineWarningFlags pass (its rising-edge "
       "detector)")
# --- 8A7C: the transmission state; +0 is the TSC1-lost backup powertrain protection flag
rename("0x0040b1ee", "fuel_demand_timing_enable_flag", "tsc1_lost_management_active_flag",
       cite(0x8A7C, 0, 0x40b1ee, TILE.format("8A26", "8C54")) + " cm848_updateParkNeutralFlagAndTsc1Activity sets it "
       "when the TSC1 activity counter shows a timing fault (it also sets fault 356, e2m Jcomm_TSC_Lost_Fault, and "
       "ignores TSC1 from the transmission / ASR / ABS source addresses) and clears it when the counter returns to 0. "
       "While it is 1, cm848_runTsc1LostManagement ramps the TSC1 torque limit and "
       "cm848_evaluateTorqueManagementRequired requires torque management for automatics. In the dump it is 1 and "
       "fault 356 is detected")
prefix("0x0040b1f0", "transmission_output_speed_in_use", cite(0x8A7C, 2, 0x40b1f0))
prefix("0x0040b1f2", "transmission_temperature_in_use", cite(0x8A7C, 4, 0x40b1f2))
prefix("0x0040b1f4", "transmission_current_gear", cite(0x8A7C, 6, 0x40b1f4))
# --- 8B2D: the warning chime (cm848_updateEngineWarningFlags; cm848_buildPciTransmitMessage5EngineWarningBits sends
#     the request as PCI header 0x53 byte 1 bit 5)
FIELD = " - field match: 8B2D lies past the dumped table, and its five chime records land on these rows with their widths"
rename("0x00408732", "engine_warning_alert_duration_coolant_overheat", "warning_chime_count_coolant_overheat",
       cite(0x8B2D, 0, 0x408732, FIELD))
rename("0x00408734", "engine_warning_alert_duration_low_oil_pressure", "warning_chime_count_low_oil_pressure",
       cite(0x8B2D, 2, 0x408734))
rename("0x00408736", "engine_warning_alert_duration_scale", "warning_chime_duration",
       cite(0x8B2D, 4, 0x408736) + " warning_chime_countdown = a chime count x this x 5 / 10, in 200 ms passes")
rename("0x00408738", "engine_warning_alert_duration_coolant_class_b", "warning_chime_count_coolant_class_b",
       cite(0x8B2D, 6, 0x408738) + " Paired with protection_coolant_classb_active_flag")
rename("0x0040873a", "engine_warning_alert_duration_water_in_fuel", "warning_chime_count_water_in_fuel",
       cite(0x8B2D, 8, 0x40873a))
rename("0x0040873c", "engine_warning_alert_duration_fault_latch", "warning_chime_count_fault_latch",
       "The chime count for protection_fault_latch_flag. Named by family membership: 8B2D ends at +9, so no e2m "
       "record covers it")
rename("0x003fcdb0", "engine_warning_alert_countdown", "warning_chime_countdown",
       "The warning chime's remaining time in 200 ms passes: a rising edge of one of the five warning inputs loads "
       "its chime count x warning_chime_duration x 5 / 10 (e2m 8B2D); warning_chime_request_flag is 1 while it runs")
rename("0x0040b210", "engine_warning_alert_flag", "warning_chime_request_flag",
       "1 while warning_chime_countdown runs (cm848_updateEngineWarningFlags); "
       "cm848_buildPciTransmitMessage5EngineWarningBits sends it to the cluster as PCI header 0x53 byte 1 bit 5")
rename("0x003fb404", "engine_warning_alert_flag_previous", "warning_chime_request_flag_previous",
       "warning_chime_request_flag as cm848_buildPciTransmitMessage5EngineWarningBits last sent it")
open(gp, "w").write("\n".join(g))
f = open(fp).read()
old = "edge of one of five inputs loads engine_warning_alert_countdown that drives\n   engine_warning_alert_flag"
if old not in f:
    old = "edge of one of five inputs loads engine_warning_alert_countdown that drives engine_warning_alert_flag"
new_tail = (" (the warning chime: e2m 8B2D chime counts x Cluster_Warning_Chime_Duration)")
if new_tail not in f:
    i = f.find("engine_warning_alert_countdown that drives")
    assert i != -1
    j = f.find("engine_warning_alert_flag", i + 40)
    k = j + len("engine_warning_alert_flag")
    f = f[:k] + new_tail + f[k:]
    open(fp, "w").write(f)
with open(map_path, "w") as fh:
    fh.write("\n".join(mapping) + "\n")
print(f"{len(mapping) - 1} renames; citations on 7 rows; 1 plate")
