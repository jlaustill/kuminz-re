"""Wave 7 fix-ups: the EGR integral enable flag row the agent named only in a plate, its plate, the arbiter field comment."""
import csv
import sys

out = sys.argv[1]
tmp = sys.argv[2]


def edit(path, fn):
    lines = open(path).read().split("\n")
    n = 0
    for i, line in enumerate(lines):
        new = fn(line)
        if new != line:
            lines[i] = new
            n += 1
    assert n == 1, (path, n)
    open(path, "w").write("\n".join(lines))


def global_row(line):
    if line == "0x003fa798,governor_speed_range_active_flag,word,":
        return ("0x003fa798,egr_valve_integral_enable_flag,word,EGR valve loop integral enable: "
                "cm848_updateEgrValveIntegralEnable clears it while the battery compensated duty is at its upper "
                "working limit (anti-windup) and cm848_calculateEgrValvePidDuty reads it (was governor_speed_range_active_flag)")
    return line


def plate(line):
    old = "exhaust_gas_recirculation_valve_integral_enable_flag (governor_speed_range_active_flag)"
    return line.replace(old, "egr_valve_integral_enable_flag") if line.startswith("0x00019ac0,") else line


def field(line):
    if line.startswith("torque_limit_arb_t,0x0040a2f6,main_injection_timing_source_code,"):
        return line.replace(",Limit source priority ranking,",
                            ",Winning source code of the main injection timing (codes 5 / 8 / 18-22 / 29 / 30 written by "
                            "cm848_calculateMainInjectionTiming) - not part of the engine speed limit arbitration (was source_priority),")
    return line


edit(f"{out}/global_variables.csv", global_row)
edit(f"{out}/function_renames.csv", plate)
edit(f"{out}/structure_definitions.csv", field)
row = ["0x003fa798", "egr_valve_integral_enable_flag", "governor_speed_range_active_flag", "global"]
with open(f"{tmp}/renames/mapping_w7_all.csv", "a", newline="") as f:
    csv.writer(f).writerow(row)
with open(f"{tmp}/renames/mapping_w7_refresh_b.csv", "w", newline="") as f:
    w = csv.writer(f)
    w.writerow(["address", "name", "old_label", "kind"])
    w.writerow(row)
print("fix-ups ok")
