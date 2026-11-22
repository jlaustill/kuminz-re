"""Round 20 orientation: for every algorithm enable flags word (e2m 106B, RAM 0x3fd59a + offset), classify its uses in
the .cpp - masked tests (name & mask), whole-value uses (anything else: compares, copies, arguments, writes) - and map
each tested mask to its e2m record. usage: flag_word_uses.py <repo>"""
import collections
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
BASE = 0x3fd59a
recs = collections.defaultdict(dict)
for line in open(os.path.join(repo, "e2m-analysis/CHR/CHR_CC_11.45.01.07.e2m"), errors="replace"):
    f = line.split(";")[0].split(",")
    if len(f) > 10 and f[2] == "106B":
        recs[int(f[3], 16)][int(f[10], 16)] = f[0]
rows = {}
for l in open(os.path.join(out, "global_variables.csv")):
    if l.startswith("0x"):
        a = int(l[:10], 16)
        if BASE <= a < BASE + 0x60:
            p = l.split(",", 3)
            rows[a] = (p[1], p[2])
cpp = open(os.path.join(out, "cm848_rom.ghidra.cpp")).read().split("\n")
func_of = []
cur = "?"
for line in cpp:
    if line.startswith("// Function: "):
        cur = line.split()[2]
    func_of.append(cur)
dump = open(os.path.join(repo, "firmware/CM848_S90140.06_analysis/originals/cm848_ram.bin"), "rb").read()
for a in sorted(rows):
    name, typ = rows[a]
    if not name:
        continue
    off = a - BASE
    pat = re.compile(rf"\b{re.escape(name)}\b(\.\w+)?")
    masked = collections.Counter()
    fields = collections.Counter()
    other = []
    for i, line in enumerate(cpp):
        if line.lstrip().startswith("//") or name not in line:
            continue
        for m in pat.finditer(line):
            if m.group(1):
                fields[m.group(1)[1:]] += 1
                continue
            tail = line[m.end():m.end() + 12]
            mm = re.match(r"\s*&\s*(0x[0-9a-fA-F]+|\d+)\)", tail)
            if mm:
                masked[int(mm.group(1), 0)] += 1
            else:
                other.append(f"{func_of[i]}: {line.strip()[:90]}")
    value = int.from_bytes(dump[a - 0x3fa000:a - 0x3fa000 + 2], "big")
    print(f"word {(off - 2) // 2:2d} {a:#x} {name} [{typ}] dump {value:#06x}")
    for mask, n in sorted(masked.items()):
        print(f"    & {mask:#06x} x{n}: {recs[off].get(mask, '(no e2m record)')}")
    for fl, n in sorted(fields.items()):
        print(f"    .{fl} x{n}")
    for o in other[:6]:
        print(f"    OTHER {o}")
    if len(other) > 6:
        print(f"    OTHER ... {len(other) - 6} more")
