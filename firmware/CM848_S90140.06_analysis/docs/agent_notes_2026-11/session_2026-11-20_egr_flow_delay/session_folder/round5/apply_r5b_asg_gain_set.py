"""Round 5 stage b (shape): all_speed_governor_gain_set_t, the 9-word ASG gain set (proportional 1 / 2, integral 1 / 2,
derivative 1 / 2, compensation filter coefficients 1-3; all_speed_governor_gain_set_pointer points at one and
cm848_runOperatingModeSpeedGovernor reads +0..+0x10). Three places hold sets:
- the throttle-mode set (e2m 107B +A..+1A) at 0x3ff6da, loaded by cm848_selectVariableSpeedGovernorMode;
- the application set (e2m 1170 +28..+38) at 0x40a232, loaded by cm848_selectAllSpeedGovernorApplicationMode;
- a ROM table of 4 sets at 0x5c1d6 (0x5c1d6 + 4 x 18 = 0x5c21e, the next row), one per TSC1 requested speed control
  condition, indexed by j1939_tsc1_override_state.etc1_speed_control_mode x 0x12 in cm848_selectTsc1SpeedControlMode.
The member rows of the two RAM / ROM-copied sets go (their e2m records move into the instance comments).
usage: apply_r5b_asg_gain_set.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
T = "all_speed_governor_gain_set_t"
FIELDS = ["proportional_gain_1", "proportional_gain_2", "integral_gain_1", "integral_gain_2", "derivative_gain_1",
          "derivative_gain_2", "compensation_filter_coefficient_1", "compensation_filter_coefficient_2",
          "compensation_filter_coefficient_3"]
path = os.path.join(out, "global_variables.csv")
lines = open(path, newline="").read().split("\n")
index = {l.split(",", 1)[0]: i for i, l in enumerate(lines) if l.startswith("0x")}


def row(address):
    return (lines[index[address]].split(",", 3) + [""])[:4]


renames, removed = [], []
SETS = [("0x003ff6da", "all_speed_governor_throttle_mode_", "all_speed_governor_throttle_mode_gain_set",
         "e2m 107B +A..+1A: the variable speed governor (throttle mode) gain set; cm848_selectVariableSpeedGovernorMode "
         "points all_speed_governor_gain_set_pointer at it and copies it into the *_selected words"),
        ("0x0040a232", "all_speed_governor_application_", "all_speed_governor_application_gain_set",
         "e2m 1170 +28..+38 'ASG application specific' gains: cm848_selectAllSpeedGovernorApplicationMode points "
         "all_speed_governor_gain_set_pointer at it (nothing in this build writes it)")]
for base, prefix, name, comment in SETS:
    a0 = int(base, 16)
    member_notes = []
    for k, field in enumerate(FIELDS):
        address = f"0x{a0 + 2 * k:08x}"
        a, n, t, c = row(address)
        assert n == prefix + field, (address, n, prefix + field)
        member_notes.append(f"+{2 * k:#x} {field} (was {n}: {c[:160]})")
        if k == 0:
            continue
        lines[index[address]] = None
        removed.append((address, n, f"{name}.{field}"))
    a, n, t, c = row(base)
    lines[index[base]] = ",".join([base, name, T, f"{comment}; typed {T} (round 5, was the 9 rows "
                                                  f"{prefix}*) | fields: " + " ; ".join(member_notes)])
    renames.append((base, name, prefix + FIELDS[0]))
# the TSC1 table: a new row (the bytes were unnamed)
assert "0x0005c1d6" not in index
anchor = index["0x0005c1d4"]
lines.insert(anchor + 1, ",".join(["0x0005c1d6", "j1939_tsc1_speed_control_condition_gain_sets", f"{T}[4]",
                                   "the four ASG gain sets of TSC1 speed control, one per requested speed control "
                                   "condition (J1939 SPN 695, 2 bits); cm848_selectTsc1SpeedControlMode indexes them "
                                   "by j1939_tsc1_override_state.etc1_speed_control_mode x 0x12 (round 5)"]))
p = os.path.join(out, "global_variables.csv")
i = [k for k, l in enumerate(lines) if l and l.startswith("0x0040a1fc,")][0]
a, n, t, c = (lines[i].split(",", 3) + [""])[:4]
assert n == "all_speed_governor_gain_set_pointer", n
lines[i] = ",".join([a, n, f"{T} *", f"{c} | typed {T} * (round 5)"])
open(p, "w", newline="").write("\n".join(l for l in lines if l is not None))
sd_path = os.path.join(out, "structure_definitions.csv")
sd = open(sd_path, newline="").read().rstrip("\n").split("\n")
assert not any(l.startswith(T + ",") for l in sd)
words = {"proportional_gain": "MM3S/RPM", "integral_gain": "MM3S/RPM/SEC", "derivative_gain": "MM3S*SEC/RPM",
         "compensation_filter_coefficient": "UNITLESS"}
for k, field in enumerate(FIELDS):
    unit = words[field.rsplit("_", 1)[0]]
    sd.append(f'{T},,{field},short,2,"+{2 * k:#x}: e2m ASG_{field.title().replace("_", "_")} ({unit}); '
              f'cm848_runOperatingModeSpeedGovernor reads it through all_speed_governor_gain_set_pointer (round 5)",,'
              f'verified')
open(sd_path, "w", newline="").write("\n".join(sd) + "\n")
here = os.path.dirname(os.path.abspath(__file__))
with open(os.path.join(here, "map_r5b.csv"), "w") as f:
    f.write("address,name,old_label,kind\n")
    for address, new, old in renames:
        f.write(f"{address},{new},{old},global\n")
with open(os.path.join(here, "removed_r5b.csv"), "w") as f:
    f.write("address,old_name,now\n")
    for address, old, now in removed:
        f.write(f"{address},{old},{now}\n")
print(f"struct {T}: {len(FIELDS)} fields; instances 3 (one [4] table); member rows removed {len(removed)}")
