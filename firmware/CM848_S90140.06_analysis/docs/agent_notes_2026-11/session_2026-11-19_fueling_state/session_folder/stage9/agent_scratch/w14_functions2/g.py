"""usage: g.py name_or_addr ...   prints the global_variables.csv rows (full comment) whose name or address match exactly;
a trailing * means prefix match (name or address)."""
import sys

OUT = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/output/"
rows = []
for line in open(OUT + "global_variables.csv", errors="replace"):
    line = line.rstrip("\r\n")
    if line.startswith("#") or not line.strip():
        continue
    p = line.split(",", 3)
    p += [""] * (4 - len(p))
    rows.append(p)


def same_address(a, q):
    try:
        return int(a, 16) == int(q, 16)
    except ValueError:
        return False


for q in sys.argv[1:]:
    pref = q.endswith("*")
    qq = q.rstrip("*")
    hit = 0
    for r in rows:
        a, n = r[0], r[1]
        if pref:
            ok = n.startswith(qq) or a.lower().startswith(qq.lower())
        else:
            ok = n == qq or (qq.lower().startswith("0x") and same_address(a, qq))
        if ok:
            print(f"{r[0]} | {r[1]} | {r[2]} | {r[3]}")
            hit += 1
    if not hit:
        print(f"-- no row for {q}")
