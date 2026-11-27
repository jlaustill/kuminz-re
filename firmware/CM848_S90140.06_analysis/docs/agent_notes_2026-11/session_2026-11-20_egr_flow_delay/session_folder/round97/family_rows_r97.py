"""Round 97: the CM550 global rows of each family batch (a word of the name is one of the family's words), written as
'0xADDR name type' lines to <out dir>/family_<id>.txt, with counts. Documentation rows (dotted / indexed names) are
left out. usage: family_rows_r97.py <repo> <out dir>"""
import os
import sys

repo, out = os.path.abspath(sys.argv[1]), sys.argv[2]
FAMILIES = {
    "R1": {"lsg"},
    "R2": {"hsg", "asg"},
    "R3": {"anc", "rsg", "afc", "pto", "accel", "decel"},
    "R4": {"eps", "pmm", "ess", "meas", "crk", "dzg"},
    "R5": {"epf", "prot"},
}
rows = []
for line in open(os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/global_variables.csv"), newline=""):
    p = line.rstrip("\r\n").split(",", 3)
    if len(p) > 2 and p[0].startswith("0x") and p[1] and "." not in p[1] and "[" not in p[1]:
        rows.append((p[0], p[1], p[2]))
taken = set()
for fid, words in FAMILIES.items():
    sel = [r for r in rows if set(r[1].lower().split("_")) & words and r[0] not in taken]
    taken.update(r[0] for r in sel)
    with open(os.path.join(out, f"family_{fid}.txt"), "w") as f:
        for a, n, t in sel:
            f.write(f"{a} {n} {t or '-'}\n")
    print(fid, len(sel))
