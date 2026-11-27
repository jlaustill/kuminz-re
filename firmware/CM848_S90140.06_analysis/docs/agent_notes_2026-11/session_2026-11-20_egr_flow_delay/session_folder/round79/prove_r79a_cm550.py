"""Round 79 stage A proof (CM550): rename each CAN controller register's old render (DAT_00<address> / _DAT_00<address> /
Ram00<address>) to its new name in the old .cpp, then compare every function statement by statement (temporaries
renumbered, casts dropped, declarations ignored) and list what still differs; also list any old-style render left at
a named address. usage: prove_r79a_cm550.py <old.cpp> <new.cpp> <global_variables.csv>"""
import collections
import re
import sys

old_path, new_path, gv = sys.argv[1:4]
names = {}
for line in open(gv, newline=""):
    parts = line.rstrip("\r\n").split(",", 3)
    if len(parts) > 2 and parts[1].startswith("CAN_CS"):
        names[parts[0][4:].lower()] = parts[1]
OLD = re.compile(r"\b_?(?:Ram|DAT_|uRam)00(ff[cd]8[0-9a-f]{2})\b")
TEMP = re.compile(r"\b(?:[a-z]Var|p[a-z]?Var|in_|unaff_|extraout_)[A-Za-z0-9_]*\b")
CAST = re.compile(r"\((?:short|ushort|int|uint|word|dword|undefined1|undefined2|undefined4|char|uchar|byte)\s*\**\)")
DECL = re.compile(r"^[A-Za-z_][A-Za-z0-9_ ]*\**\s+\**[A-Za-z_][A-Za-z0-9_]*(\[\w+\])?$")


def statements(path, rename):
    t = open(path, errors="replace").read()
    parts = re.split(r"^// Function: (\S+) @[^\n]*\n", t, flags=re.M)
    out = {}
    for i in range(1, len(parts), 2):
        b = re.sub(r"/\*.*?\*/", "", parts[i + 1], flags=re.S)
        if rename:
            b = OLD.sub(lambda m: names.get(m.group(1), m.group(0)), b)
        b = re.sub(r"\s+", "", CAST.sub("", TEMP.sub("T", b)))
        out[parts[i]] = collections.Counter(s for s in re.split(r"[;{}]", b) if s and not DECL.match(s))
    return out


old_s, new_s = statements(old_path, True), statements(new_path, False)
changed = [f for f in old_s if old_s[f] != new_s.get(f)]
print(f"functions {len(old_s)}; differing at statement level after the renames: {len(changed)}")
for f in changed:
    gone = old_s[f] - new_s.get(f, collections.Counter())
    came = new_s.get(f, collections.Counter()) - old_s[f]
    print(f"== {f}")
    for s in gone:
        print("   - " + s[:150])
    for s in came:
        print("   + " + s[:150])
text = open(new_path, errors="replace").read()
left = sorted({m.group(0) for m in OLD.finditer(text) if m.group(1) in names})
print("old-style renders left at named addresses:", left)
print("named registers rendered:", sum(1 for n in names.values() if re.search(rf"\b{n}\b", text)), "of", len(names))
