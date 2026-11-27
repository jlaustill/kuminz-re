"""Round 76 stage A2 (CM550): three TPU parameter pairs that the code only ever reaches with one 32-bit access become
one dword each (as SRAM_RAMBAH_RAMBAL), so the access renders by name; the channel 15 low-byte row goes, because its
byte data cleared the TPU_CH15_PARAM6 word under it (the stage applies rows in order). Idempotent.
usage: apply_r76a2.py <repo>"""
import os
import sys

p = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM550_J90350.00_analysis/output/global_variables.csv")
s = open(p, newline="").read()
R = "PR #53 round 76"
for address, old_name, new_name, first, second in (("ffff08", "TPU_CH0_PARAM4", "TPU_CH0_PARAM4_5", 4, 0),
                                                   ("ffff34", "TPU_CH3_PARAM2", "TPU_CH3_PARAM2_3", 2, 3),
                                                   ("ffffc4", "TPU_CH12_PARAM2", "TPU_CH12_PARAM2_3", 2, 3)):
    channel = old_name.split("_")[1][2:]
    old = f"0x00{address},{old_name},word,"
    if f"0x00{address},{new_name}," in s:
        continue
    lines = [l for l in s.split("\n") if l.startswith(old)]
    assert len(lines) == 1, (old, len(lines))
    pair = f"{first} and {first + 1}"
    new = (f"0x00{address},{new_name},dword,MC68336 TPU parameter RAM channel {channel} parameters {pair}: the code's only "
           f"access is one 32-bit access of both (MC68336/376 UM App. D; {R})")
    s = s.replace(lines[0], new)
lines = [l for l in s.split("\n") if l.startswith("0x00fffffd,TPU_CH15_PARAM6_LOW_BYTE,")]
if lines:
    s = s.replace(lines[0] + "\n", "")
open(p, "w", newline="").write(s)
print("round 76 stage A2 applied")
