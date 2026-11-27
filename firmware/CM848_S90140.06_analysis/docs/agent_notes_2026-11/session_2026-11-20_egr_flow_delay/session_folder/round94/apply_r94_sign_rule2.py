"""Round 94 (CM550): correct the sign stage with the both-views evidence. A row typed unsigned shows its signed uses
as signed casts and its unsigned uses plain; typed signed, the reverse - so a row's uses need both renders. The first
sign stage judged from one view: four of its word -> i16 rows show unsigned compares once typed i16
(minimum_fueling_value_0_100: 2 signed and 7 unsigned), and one round 93 cast-signed row is mixed
(active_fault_list_count: 4 signed, 2 unsigned). Mixed rows take Calterm's flag (U for the four; the fault list
count has only a block record, so the fallback, unsigned). Idempotent. usage: apply_r94_sign_rule2.py <repo>"""
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
R = "PR #53 round 94"
G = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/global_variables.csv")
REVERT = {  # address: evidence
    0x0080800a: "2 signed and 7 unsigned uses (compares); Calterm FSMNFL is unsigned",
    0x0080da38: "2 signed (< 0 tests) and 3 unsigned uses; Calterm JCTQRPP1 is unsigned",
    0x0080da62: "3 signed (< 0 tests) and 1 unsigned use; Calterm JCTQLMFL is unsigned",
    0x0080dee4: "1 signed and 1 unsigned compare; Calterm WSTA is unsigned",
    0x00805994: "4 signed and 2 unsigned uses; only a block record (JCFUCUDA), so unsigned",
}
lines = open(G, newline="").read().split("\n")
done = 0
for i, line in enumerate(lines):
    if not line.startswith("0x"):
        continue
    a = int(line.split(",")[0], 16)
    if a not in REVERT:
        continue
    parts = line.split(",", 3)
    if parts[2] == "word":
        continue
    assert parts[2] == "i16", (hex(a), parts[2])
    comment = parts[3] if len(parts) > 3 else ""
    comment = re.sub(r" \| typed i16 by the code's own use: [^|]*?\(PR #53 round 94\)", "", comment)
    note = f"signedness: mixed in the code - {REVERT[a]} -> word ({R})"
    lines[i] = f"{parts[0]},{parts[1]},word,{comment} | {note}"
    done += 1
if done:
    open(G, "w", newline="").write("\n".join(lines))
print(done, "rows set to word")
