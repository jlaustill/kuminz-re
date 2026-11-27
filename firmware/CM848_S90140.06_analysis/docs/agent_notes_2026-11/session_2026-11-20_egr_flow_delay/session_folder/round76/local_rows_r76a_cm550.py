"""Round 76 stage A: does each local_variables.csv row still land on the same statements? For every row, the lines that
name its new_name in the old .cpp (register renders renamed) and in the new one are compared, with the decompiler
temporaries renumbered. Prints the rows whose lines differ.
usage: local_rows_r76a_cm550.py <old.cpp> <new.cpp> <global_variables.csv> <local_variables.csv>"""
import csv
import re
import sys

old_path, new_path, gv, lv = sys.argv[1:5]
names = {}
for line in open(gv, newline=""):
    parts = line.rstrip("\r\n").split(",", 3)
    if len(parts) > 2 and parts[0].startswith("0x00fff") and parts[1]:
        names[parts[0][4:]] = parts[1]
OLD = re.compile(r"\b_?(?:Ram|DAT_|uRam|bRam|cRam|sRam|iRam)00(fff[0-9a-f]{3})\b")
TEMP = re.compile(r"\b(?:[a-z]Var|p[a-z]?Var|in_|unaff_|extraout_)[A-Za-z0-9_]*\b")
CAST = re.compile(r"\((?:short|ushort|int|uint|word|dword|undefined1|undefined2|undefined4|char|uchar|byte)\s*\**\)")


def functions(path, rename):
    t = open(path, errors="replace").read()
    parts = re.split(r"^// Function: \S+ @ 0x([0-9a-f]+)[^\n]*\n", t, flags=re.M)
    out = {}
    for i in range(1, len(parts), 2):
        b = re.sub(r"/\*.*?\*/", "", parts[i + 1], flags=re.S)
        if rename:
            b = OLD.sub(lambda m: names.get(m.group(1), m.group(0)), b)
        out[int(parts[i], 16)] = b
    return out


old_f, new_f = functions(old_path, True), functions(new_path, False)
moved = 0
rows = [r for r in csv.reader(open(lv, newline="")) if r and r[0].startswith("0x")]
for r in rows:
    address, name = int(r[0], 16), r[3]
    if address not in old_f or not name:
        continue

    def lines(body):
        out = []
        for line in body.split("\n"):
            if re.search(rf"\b{re.escape(name)}\b", line) and not re.match(r"^\s*\w[\w\s\*]*\s+\**" + re.escape(name)
                                                                          + r"\s*;", line):
                out.append(re.sub(r"\s+", "", CAST.sub("", TEMP.sub("T", line))))
        return out

    a, b = lines(old_f[address]), lines(new_f.get(address, ""))
    if a != b:
        moved += 1
        print(f"{r[0]} {r[1]} {r[2]} -> {name}: old {len(a)} lines, new {len(b)} lines")
        for x in sorted(set(a) ^ set(b))[:6]:
            print("    ", ("old " if x in a else "new ") + x[:120])
print(f"rows checked {len(rows)}; rows whose lines changed: {moved}")
