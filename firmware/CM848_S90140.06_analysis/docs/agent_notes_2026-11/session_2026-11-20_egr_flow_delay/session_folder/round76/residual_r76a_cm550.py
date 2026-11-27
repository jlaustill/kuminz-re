"""Round 76 stage A: the changed lines that remain in the differing functions after the register renames, with the
decompiler temporaries renumbered per line and the local declarations dropped - the residue the proof has to explain.
usage: residual_r76a_cm550.py <old.cpp> <new.cpp> <global_variables.csv>"""
import collections
import difflib
import re
import sys

sys.path.insert(0, "/home/linux/.claude/jobs/374b0424/tmp/w15/r76")
old_path, new_path, gv = sys.argv[1:4]
names = {}
for line in open(gv, newline=""):
    parts = line.rstrip("\r\n").split(",", 3)
    if len(parts) > 2 and parts[0].startswith("0x00fff") and parts[1]:
        names[parts[0][4:]] = parts[1]
OLD = re.compile(r"\b_?(?:Ram|DAT_|uRam|bRam|cRam|sRam|iRam)00(fff[0-9a-f]{3})\b")
TEMP = re.compile(r"\b(?:[a-z]Var|p[a-z]?Var|in_|unaff_|extraout_)[A-Za-z0-9_]*\b")
DECL = re.compile(r"^\s*[A-Za-z_][A-Za-z0-9_ ]*\**\s+\**[A-Za-z_][A-Za-z0-9_]*(?:\s*\[\w+\])?;\s*$")


def bodies(path, rename):
    t = open(path, errors="replace").read()
    parts = re.split(r"^// Function: (\S+) @[^\n]*\n", t, flags=re.M)
    out = {}
    for i in range(1, len(parts), 2):
        b = re.sub(r"/\*.*?\*/", "", parts[i + 1], flags=re.S)
        if rename:
            b = OLD.sub(lambda m: names.get(m.group(1), m.group(0)), b)
        lines = []
        for line in b.split("\n"):
            if not line.strip() or DECL.match(line):
                continue
            lines.append(TEMP.sub("T", line.strip()))
        out[parts[i]] = lines
    return out


old_b, new_b = bodies(old_path, True), bodies(new_path, False)
kinds = collections.Counter()
examples = {}
changed = 0
for f in old_b:
    if old_b[f] == new_b.get(f):
        continue
    changed += 1
    for line in difflib.unified_diff(old_b[f], new_b.get(f, []), lineterm="", n=0):
        if line.startswith(("---", "+++", "@@")):
            continue
        key = re.sub(r"0x[0-9a-f]+|\b\d+\b", "N", line)
        kinds[key] += 1
        examples.setdefault(key, f)
print(f"functions differing after the renames, temporaries and declarations normalized: {changed}")
for key, n in kinds.most_common():
    print(f"{n:4} {key[:120]}   [{examples[key]}]")
