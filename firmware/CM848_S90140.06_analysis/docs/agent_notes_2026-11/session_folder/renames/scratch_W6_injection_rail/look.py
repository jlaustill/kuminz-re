import csv, sys, re

OUT = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/"


def rows(fn):
    with open(OUT + fn, newline="") as f:
        for r in csv.reader(f):
            if not r or r[0].startswith("#"):
                continue
            yield r


G = list(rows("global_variables.csv"))
F = list(rows("function_renames.csv"))
A = list(rows("arrays.csv"))


def norm(a):
    a = a.lower()
    if a.startswith("0x"):
        return "0x%08x" % int(a, 16)
    return a


maxc = 700
for q in sys.argv[1:]:
    full = q.startswith("0x")
    qq = norm(q) if full else q.lower()
    print("=== ", q)
    for tag, tab in (("G", G), ("F", F), ("A", A)):
        for r in tab:
            if full:
                if r[0].lower() == qq:
                    print(tag, "|", " | ".join(x[:maxc] for x in r))
            else:
                if len(r) > 1 and (qq in r[1].lower() or (len(r) > 3 and qq in r[3].lower()) or (tag == "F" and len(r) > 2 and qq in r[2].lower())):
                    print(tag, "|", " | ".join(x[:maxc] for x in r))
