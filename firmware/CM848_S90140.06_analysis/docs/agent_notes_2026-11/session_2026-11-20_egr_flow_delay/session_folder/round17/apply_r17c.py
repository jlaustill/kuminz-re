"""Round 17 stage C (types):
- engine_retarder_brake_type_t, a word bitfield on 0x408ec2 (e2m 1071 +28 EB_Brake_Type '0=NONE, 1=EXHAUST, 2=VG,
  3=BOTH'): cm848_driveEngineRetarderOutput only tests it with & 1 / & 2 (a ROM word, no read-modify-write), so the
  bits render without pieces. 1 (exhaust brake only) in the dump.
- engine_retarder_immediate_brake_flag (0x40a35c): dword -> word. Its stores are one sth each (0x41908 and the
  initializer), which rendered as ._0_2_ pieces of the dword; e2m 1070 +A is 2 bytes and +C EB_Rate_Timer (0x40a35e)
  has no access.
usage: apply_r17c.py <repo>"""
import os
import sys

out = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output")
STRUCT = """# engine_retarder_brake_type_t: e2m 1071 +28 EB_Brake_Type (0 NONE / 1 EXHAUST / 2 VG / 3 BOTH), which
# cm848_driveEngineRetarderOutput reads as bits (PR #53 round 17); one instance, engine_retarder_brake_type (ROM 0x408ec2)
engine_retarder_brake_type_t,,exhaust_brake,bitfield:1@0,2,"Bit 0 (e2m 1 = EXHAUST): drive the exhaust brake output (logical output 11); set on this truck",,verified
engine_retarder_brake_type_t,,variable_geometry_turbocharger_brake,bitfield:1@1,0,"Bit 1 (e2m 2 = VG): brake with the VGT (variable_geometry_turbocharger_brake_active_flag); clear on this truck",,verified
"""
sp = os.path.join(out, "structure_definitions.csv")
t = open(sp).read()
assert "engine_retarder_brake_type_t" not in t
anchor = t.index("ema_filter_state_t,,coefficient,")
start = t.rfind("\n", 0, anchor) + 1
open(sp, "w").write(t[:start] + STRUCT + t[start:])
gp = os.path.join(out, "global_variables.csv")
lines = open(gp).read().split("\n")
RETYPE = {"0x00408ec2": ("word", "engine_retarder_brake_type_t"), "0x0040a35c": ("dword", "word")}
done = 0
for i, line in enumerate(lines):
    a = line[:10]
    if a in RETYPE:
        addr, name, typ, comment = (line.split(",", 3) + [""])[:4]
        old, new = RETYPE[a]
        assert typ == old, (a, typ)
        lines[i] = ",".join([addr, name, new, comment + f" | typed {new} in PR #53 round 17 (was {old})"])
        done += 1
assert done == 2
open(gp, "w").write("\n".join(lines))
print("1 struct type, 2 rows retyped")
