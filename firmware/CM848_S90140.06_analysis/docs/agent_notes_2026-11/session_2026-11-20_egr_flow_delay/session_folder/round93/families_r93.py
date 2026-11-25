"""Round 93 (read-only): the call-graph family of each seed function (the placeholder-named CM550 functions whose body
shows a named enable bit / enum member, plus the flagged misnames given on the command line): its callers and callees
by name in the decompilation, with the placeholders among them (those join the family), and for a function nothing
calls by name, where its big-endian address occurs in the ROM (a pointer table / registration).
Prints one block per seed and the union of placeholder relatives that are not seeds.
usage: families_r93.py <repo> <candidates.tsv> [<extra seed>...]"""
import collections
import csv
import os
import re
import sys

repo, tsv, extra = sys.argv[1], sys.argv[2], set(sys.argv[3:])
O = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
rom = open(os.path.join(repo, "firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"), "rb").read()
names = {}
for r in csv.reader(open(os.path.join(O, "function_renames.csv"), newline="")):
    if r and r[0].startswith("0x"):
        names[r[1]] = int(r[0], 16)
PLACEHOLDER = re.compile(r"^[a-z0-9]+_FUN_[0-9a-f]{8}$")
cpp = open(os.path.join(O, "J90350.00.ghidra.cpp"), errors="replace").read()
bodies = {m.group(1): m.group(3) for m in re.finditer(r"^// Function: (\w+) @ (0x[0-9a-f]+)\n(.*?)(?=^// Function: |\Z)", cpp, re.M | re.S)}
call_re = re.compile(r"\b(\w+)\b")
callees, callers = collections.defaultdict(set), collections.defaultdict(set)
for fn, body in bodies.items():
    code = "\n".join(l for l in body.split("\n") if not l.strip().startswith(("//", "/*", "*")))
    for other in set(call_re.findall(code)):
        if other in names and other != fn:
            callees[fn].add(other)
            callers[other].add(fn)
seeds = []
for row in csv.DictReader(open(tsv), delimiter="\t"):
    if int(row["enable_bits"]) + int(row["enum_members"]) > 0 or row["name"] in extra:
        seeds.append(row["name"])
relatives = collections.Counter()
for s in seeds:
    cs, ce = sorted(callers[s], key=names.get), sorted(callees[s], key=names.get)
    refs = []
    if not cs:
        pat = names[s].to_bytes(4, "big")
        i = rom.find(pat)
        while i != -1:
            refs.append(f"0x{i:x}")
            i = rom.find(pat, i + 1)
    print(f"0x{names[s]:05x} {s}")
    print("    callers:", " ".join(f"{c}@{names[c]:x}" for c in cs) or f"(none by name; ROM pointer at {' '.join(refs) or 'nowhere'})")
    print("    callees:", " ".join(f"{c}@{names[c]:x}" for c in ce) or "(none)")
    for c in cs + ce:
        if PLACEHOLDER.match(c) and c not in seeds:
            relatives[c] += 1
print(f"\n{len(seeds)} seeds; {len(relatives)} placeholder relatives that are not seeds:")
for c in sorted(relatives, key=names.get):
    body = bodies.get(c, "")
    print(f"  0x{names[c]:05x} {c} lines {len(body.splitlines())} (touches {relatives[c]} seeds; callers {len(callers[c])})")
