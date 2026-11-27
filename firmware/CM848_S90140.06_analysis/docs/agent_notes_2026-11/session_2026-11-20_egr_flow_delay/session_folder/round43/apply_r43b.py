"""Round 43 stage B: remove the untyped junk rows named '<name>+<N>' (an old export's labels for interior addresses of
another row's data). None renders in the .cpp or the headers. The one typed row of the kind
(fuel_demand_enable_sync_flag_shadow+2, undefined2) stays as a lead. Writes the removed rows to a file. Idempotent.
usage: apply_r43b.py <repo> <removed.txt>"""
import os
import re
import sys

repo, removed = os.path.abspath(sys.argv[1]), sys.argv[2]
gp = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/global_variables.csv")
g = open(gp).read().split("\n")
keep, gone = [], []
for l in g:
    p = l.split(",", 3)
    if l.startswith("0x") and len(p) >= 3 and re.fullmatch(r"[a-z_0-9]+\+\d+", p[1]) and p[2] == "":
        gone.append(l)
    else:
        keep.append(l)
if gone:
    open(gp, "w").write("\n".join(keep))
    with open(removed, "w") as fh:
        fh.write("\n".join(gone) + "\n")
print(f"{len(gone)} junk rows removed")
