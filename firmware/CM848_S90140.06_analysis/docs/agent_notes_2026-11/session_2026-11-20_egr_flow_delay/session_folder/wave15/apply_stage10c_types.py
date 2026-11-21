"""Stage 10c (shape): the types wave 15's reports and the main session's width census settle.
- low_speed_governor_gain_set_t {i16 proportional_gain, integral_gain, derivative_gain, jerk_gain} (e2m: the 4-word
  P / I / D / jerk sets of 10EC, 10EE +12, 10EA +C / +14, 10ED +C and 10EB; cm848_loadLowSpeedGovernorGainSet reads
  +0 / +2 / +4 / +6 through the gain set pointer); six instances; the member rows of the default and override sets go;
  the two pointers become low_speed_governor_gain_set_t *.
- 0x3ffcaa dword -> i16 (lha) and the word behind it named (e2m 16A1 +14 C_TGC_E_Brake_LLim, lha);
- 0x3ff69c dword -> word + 0x3ff69e word (e2m 107D +16 / +18, both lhz);
- 0x40a042 word -> byte and 0x40a043 byte named (e2m 11AE +A / +B, 1-byte records, lbz);
- 0x409530 word -> byte (e2m 801A +1A 1-byte record, lbz);
- 0x3fdd86 / 0x3faa88 word -> dword (the 4-byte encryption seed, lwz; they rendered _name);
- 0x40a1cc / 0x40a1d4 dword -> i32 (e2m 107C +22 / +2A signed 4-byte records).
Writes map_stage10d.csv for the label part (the new names of the formerly unnamed / placeholder rows).
usage: apply_stage10c_types.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
gv_path = os.path.join(out, "global_variables.csv")
lines = open(gv_path, newline="").read().split("\n")
index = {l.split(",", 1)[0]: i for i, l in enumerate(lines) if l.startswith("0x")}
T = "low_speed_governor_gain_set_t"


def row(address):
    i = index[address]
    return i, (lines[i].split(",", 3) + [""])[:4]


def set_row(address, name=None, typ=None, comment_add=None, comment=None):
    i, (a, n, t, c) = row(address)
    if comment is not None:
        c = comment
    if comment_add:
        c = f"{c} | {comment_add}" if c else comment_add
    lines[i] = ",".join([a, name if name is not None else n, typ if typ is not None else t, c])


renames = []
# the gain set instances
INSTANCES = {
    "0x004070e6": ("low_speed_governor_default_gain_set", None),
    "0x004070aa": ("low_speed_governor_aggressive_gain_set", None),
    "0x00408eda": ("low_speed_governor_middle_gear_gain_set", None),
    "0x00408ed2": ("low_speed_governor_high_gear_gain_set", None),
    "0x0040ae82": ("low_speed_governor_override_gain_set", "governor_j1939_speed_target"),
    "0x0005c4a6": ("j1939_low_speed_governor_gain_set", "j1939_low_speed_governor_proportional_gain"),
}
note = (f"typed {T} (proportional / integral / derivative / jerk gain, i16 each), stage 10c: "
        "cm848_loadLowSpeedGovernorGainSet loads the four words through low_speed_governor_gain_set_pointer")
for address, (name, old) in INSTANCES.items():
    i, (a, n, t, c) = row(address)
    if old:
        assert n == old, (address, n, old)
        renames.append((address, name, old))
        c = f"{c} (was {old})"
    else:
        assert n == name, (address, n, name)
    set_row(address, name=name, typ=T, comment=f"{c} | {note}" if c else note)
# the member rows the struct now covers
MEMBERS = ["0x004070e8", "0x004070ea", "0x004070ec", "0x0040ae84", "0x0040ae86", "0x0040ae88"]
removed = []
for address in MEMBERS:
    i, (a, n, t, c) = row(address)
    removed.append((address, n))
    lines[i] = None
for address in ("0x0040ae8c", "0x0040ae90"):
    set_row(address, typ=f"{T} *", comment_add=f"typed {T} * (stage 10c)")
# dword splits and width fixes
set_row("0x003ffcaa", typ="i16", comment_add="retyped dword -> i16 (stage 10c): the record is 2 bytes, the one load lha")
i, (a, n, t, c) = row("0x003ffcac")
assert n == "throttle_rate_pid_gain_cal+2", n
lines[i] = ",".join([a, "wastegate_duty_engine_brake_lower_limit", "i16",
                     "e2m 16A1 +14 C_TGC_E_Brake_LLim (lha): the wastegate duty floor while the engine retarder is "
                     "active, read by cm848_calculateWastegateDutyRequest; it rendered as the upper half of the dword "
                     "before 0x3ffcaa was typed i16 (stage 10c)"])
renames.append(("0x003ffcac", "wastegate_duty_engine_brake_lower_limit",
                "wastegate_duty_turbocharger_speed_derate_scale_gain._2_2_"))
i, (a, n, t, c) = row("0x003ff69c")
assert n == "fuel_demand_pilot_active_flag", n
lines[i] = ",".join([a, "all_speed_governor_deadband_compensation_flag", "word",
                     "e2m 107D +16 ASG_Deadband_Compensation_Flag 'Enables algorithm to eliminate LSG-ASG deadband' "
                     f"(lhz): retyped dword -> word, stage 10c (was fuel_demand_pilot_active_flag) | earlier note: {c}"])
renames.append(("0x003ff69c", "all_speed_governor_deadband_compensation_flag", "fuel_demand_pilot_active_flag"))
i, (a, n, t, c) = row("0x003ff69e")
assert n == "fuel_demand_pilot_active_flag+2", n
lines[i] = ",".join([a, "all_speed_governor_deadband_delta_decrement_rate", "word",
                     "e2m 107D +18 ASG_Deadband_Delta_Decrement_Rate 'Decrement rate per loop at 0 throttle' (MM3S, "
                     "lhz): it was the lower half of the dword at 0x3ff69c (stage 10c)"])
renames.append(("0x003ff69e", "all_speed_governor_deadband_delta_decrement_rate", "fuel_demand_pilot_active_flag._2_2_"))
set_row("0x0040a042", typ="byte", comment_add="retyped word -> byte (stage 10c): a 1-byte record, the one load lbz")
i, (a, n, t, c) = row("0x0040a043")
assert n == "j1939_timer_config_byte_c", n
lines[i] = ",".join([a, "supervisor_chip_overspeed_consecutive_occurrence_count", "byte",
                     "e2m 11AE +B 'Consecutive occurances of engine overspeed to cause a shutdown' (1 byte; 10 in the "
                     "dump, lbz): cm848_configureSupervisorChip programs it into the supervisor chip (stage 10c; was "
                     "j1939_timer_config_byte_c)"])
renames.append(("0x0040a043", "supervisor_chip_overspeed_consecutive_occurrence_count", "j1939_timer_config_byte_c"))
set_row("0x00409530", typ="byte", comment_add="retyped word -> byte (stage 10c): a 1-byte record (+1B is padding), lbz")
for address in ("0x003fdd86", "0x003faa88"):
    set_row(address, typ="dword", comment_add="retyped word -> dword (stage 10c): the seed is 4 bytes, lwz")
for address in ("0x0040a1cc", "0x0040a1d4"):
    set_row(address, typ="i32", comment_add="retyped dword -> i32 (stage 10c): the e2m record is signed 4 bytes")
open(gv_path, "w", newline="").write("\n".join(l for l in lines if l is not None))
# the struct type
sd_path = os.path.join(out, "structure_definitions.csv")
sd = open(sd_path, newline="").read().rstrip("\n").split("\n")
assert not any(l.startswith(T + ",") for l in sd)
fields = [("proportional_gain", "+0: e2m *_Proportional_Gain (MM3S/RPM)"),
          ("integral_gain", "+2: e2m *_Integral_Gain (MM3S/RPM/SEC)"),
          ("derivative_gain", "+4: e2m *_Derivative_Gain (MM3S*SEC/RPM)"),
          ("jerk_gain", "+6: e2m *_Jerk_Gain (MM3S*SEC/RPM)")]
for name, comment in fields:
    sd.append(f'{T},,{name},i16,2,"{comment}; cm848_loadLowSpeedGovernorGainSet copies it into the working '
              f'low_speed_governor_{name} (stage 10c)",,verified')
open(sd_path, "w", newline="").write("\n".join(sd) + "\n")
with open(os.path.join(os.path.dirname(os.path.abspath(__file__)), "map_stage10d.csv"), "w") as f:
    f.write("address,name,old_label,kind\n")
    for address, new, old in renames:
        f.write(f"{address},{new},{old},global\n")
print(f"instances {len(INSTANCES)}, member rows removed {removed}, renames {len(renames)}")
