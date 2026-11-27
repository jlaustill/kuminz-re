"""Round 76 stage A proof (CM550): rename each register's old render (Ram00<address> / DAT_00<address> / uRam00<address>)
in the old .cpp to its new name, drop casts and the declarations of decompiler temporaries, renumber the remaining
temporaries in order of appearance, and compare every function body. Then list the register names that render with an
underscore prefix or as pieces, and any Ram00fff / DAT_00fff render left.
usage: prove_r76a_cm550.py <old.cpp> <new.cpp> <global_variables.csv>"""
import re
import sys

old_path, new_path, gv = sys.argv[1:4]
names = {}
for line in open(gv, newline=""):
    parts = line.rstrip("\r\n").split(",", 3)
    if len(parts) > 2 and parts[0].startswith("0x00fff") and parts[1]:
        names[parts[0][4:]] = parts[1]
OLD = re.compile(r"\b_?(?:Ram|DAT_|uRam|bRam|cRam|sRam|iRam)00(fff[0-9a-f]{3})\b")
CAST = re.compile(r"\((?:short|ushort|int|uint|word|dword|undefined1|undefined2|undefined4|char|uchar|byte|longlong|"
                  r"ulonglong)\s*\**\)")
TEMP = re.compile(r"\b(?:[a-z]Var|pu?[a-z]?Var|pu?Var|in_|unaff_|extraout_)[A-Za-z0-9_]*\b")
DECL = re.compile(r"^\s*[A-Za-z_][A-Za-z0-9_ ]*\**\s+\**(?:[a-z]Var\d+|p[a-z]?Var\d+|pu?Var\d+)(?:\s*\[\d+\])?;\s*$", re.M)


def bodies(path, rename):
    t = open(path, errors="replace").read()
    parts = re.split(r"^// Function: (\S+) @[^\n]*\n", t, flags=re.M)
    out = {}
    for i in range(1, len(parts), 2):
        b = re.sub(r"/\*.*?\*/", "", parts[i + 1], flags=re.S)
        if rename:
            b = OLD.sub(lambda m: names.get(m.group(1), m.group(0)), b)
        b = DECL.sub("", b)
        b = CAST.sub("", b).replace("'\\0'", "0").replace("'\\x01'", "1")
        order = {}
        b = TEMP.sub(lambda m: order.setdefault(m.group(0), f"T{len(order)}"), b)
        out[parts[i]] = re.sub(r"\s+", "", b)
    return out


old_b, new_b = bodies(old_path, True), bodies(new_path, False)
diff = [f for f in old_b if old_b[f] != new_b.get(f)]
print(f"functions {len(old_b)}; differing after the register renames (temporaries normalized): {len(diff)}")
for f in diff:
    print(" ", f)
new_text = open(new_path, errors="replace").read()
left = sorted(set(re.findall(r"\b_?(?:Ram|DAT_|uRam)00fff[0-9a-f]{3}\b", new_text)))
print("old-style register renders left:", left)
pattern = "|".join(re.escape(n) for n in names.values())
underscored = sorted(set(re.findall(r"(?<![A-Za-z0-9])_(" + pattern + r")\b", new_text)))
pieces = sorted(set(re.findall(r"\b(" + pattern + r")\._\d+_\d+_", new_text)))
print("underscore-prefixed register renders:", underscored)
print("register piece renders:", pieces)
