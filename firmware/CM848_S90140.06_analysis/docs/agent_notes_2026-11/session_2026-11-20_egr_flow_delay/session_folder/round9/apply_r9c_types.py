"""Round 9 stage C types (string edits; global_variables.csv takes commas unquoted):
- 0x3fcf12: throttle_setpoint_limit_arg (word, rendered _throttle_setpoint_limit_arg) -> governor_pressure_controller_
  output_unclamped, dword: its one access is a 32-bit store (stw r31,-12526(r12) @ 0x51c9d0) and the next row is
  0x3fcf1b.
- 0x3fb192: the 27-word output speed ring of cm848_calculateOutputShaftAcceleration's method 1 (indexed
  (&DAT_003fb192)[transmission_output_speed_history_index], mod 27), between two named rows (0x3fb190 / 0x3fb1c8).
usage: apply_r9c_types.py <repo> <map.csv>"""
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
p = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output", "global_variables.csv")
lines = open(p).read().split("\n")
done = 0
for i, l in enumerate(lines):
    if l.startswith("0x003fcf12,throttle_setpoint_limit_arg,word,"):
        old_comment = l.split(",", 3)[3]
        lines[i] = ",".join(["0x003fcf12", "governor_pressure_controller_output_unclamped", "dword",
                             "governor_pressure_controller_output + a P / I / D term (signed), before "
                             "cm848_limitGovernorPressureSolenoidDuty clamps it: a dword, its one access is a 32-bit "
                             "store (stw @ 0x51c9d0), so the word row rendered _throttle_setpoint_limit_arg (was "
                             f"throttle_setpoint_limit_arg) | earlier note: {old_comment}"])
        done += 1
assert done == 1
assert not any(l.startswith("0x003fb192,") for l in lines)
row = ",".join(["0x003fb192", "transmission_output_speed_history", "word[27]",
                "Method 1's ring of the last 27 output speeds (cm848_calculateOutputShaftAcceleration): written at "
                "transmission_output_speed_history_index (mod 27); the acceleration is the speed now minus the one 27 "
                "passes ago. The ring length is fixed in the code (27), not taken from "
                "transmission_output_shaft_acceleration_sample_period"])
k = next(i for i, l in enumerate(lines) if re.match(r"^0x[0-9a-f]{8},", l) and int(l[:10], 16) > 0x3fb192)
lines.insert(k, row)
open(p, "w").write("\n".join(lines))
with open(map_path, "a") as f:
    f.write("0x003fcf12,governor_pressure_controller_output_unclamped,_throttle_setpoint_limit_arg,global\n")
    f.write("0x003fb192,transmission_output_speed_history,DAT_003fb192,global\n")
print("retyped 1, added 1")
