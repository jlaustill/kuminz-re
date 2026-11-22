"""Round 40: for each MISSING row that is not a documentation row, the functions that use the name in the .cpp and
their side: boot (ROM below 0x7f60: the boot ROM and the kernel image's ROM copies) or application (0x7f60 and up,
Bank2 included). Also the gate's banned words and whether name + '_cal' is taken.
usage: missing_users.py <repo> <missing.tsv> <out.tsv>"""
import ast
import os
import re
import sys

repo, tsv, out = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]
fw = os.path.join(repo, "firmware")
src = open("/home/linux/.claude/jobs/374b0424/tmp/w15/apply_hand_worklist.py").read()
BANNED = ast.literal_eval(re.search(r"BANNED = (\{.*?\})", src, re.S).group(1))
cpp = open(os.path.join(fw, "CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp"), errors="replace").read()
names = set()
for l in open(os.path.join(fw, "CM848_S90140.06_analysis/output/global_variables.csv"), errors="replace"):
    p = l.split(",", 3)
    if len(p) >= 2 and p[0].startswith("0x"):
        names.add(p[1])
marks = [(m.start(), m.group(1), int(m.group(2), 16)) for m in
         re.finditer(r"^// Function: (\S+) @ 0x([0-9a-f]+)", cpp, re.M)]


def users(name):
    found = {}
    for m in re.finditer(r"\b" + re.escape(name) + r"\b", cpp):
        ls = cpp.rfind("\n", 0, m.start()) + 1
        if cpp[ls:m.start()].lstrip().startswith(("/*", "*", "//")):
            continue
        f = None
        for s, n, a in marks:
            if s > m.start():
                break
            f = (n, a)
        if f:
            found[f[0]] = f[1]
    return found


with open(out, "w") as fh:
    for l in open(tsv):
        a, g, typ, name, refs, shared, comment = (l.rstrip("\n").split("\t") + [""] * 7)[:7]
        if g == "documentation":
            continue
        u = users(name)
        boot = sorted(n for n, x in u.items() if x < 0x7f60)
        app = sorted(n for n, x in u.items() if x >= 0x7f60)
        side = "app" if app and not boot else "boot" if boot and not app else "both" if u else "none"
        bad = [t for t in name.split("_") if t in BANNED]
        taken = (name + "_cal") in names
        fh.write("\t".join([a, g, typ, name, side, str(len(boot)), str(len(app)), ",".join(bad),
                            "TAKEN" if taken else "", shared, ";".join(app[:3])]) + "\n")
print("done")
