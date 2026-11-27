"""Round 93 (read-only): a second reference scan for the function rows removed this round (deleted_functions.csv
entries of PR #53 round 93) and for every row still without an entry: PC-relative references, which the first scan
did not cover - jsr (d16,pc) 4eba, jmp (d16,pc) 4efa, lea (d16,pc),An 41fa..4ffa, pea (d16,pc) 487a - and 16-bit
absolute-short forms (jsr abs.w 4eb8, jmp abs.w 4ef8; they reach only 0x0000-0x7fff).
usage: pc_relative_refs_r93.py <repo>"""
import csv
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
O = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
rom = open(os.path.join(repo, "firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"), "rb").read()
targets = {}
for i in range(0, len(rom) - 4, 2):
    w = int.from_bytes(rom[i:i + 2], "big")
    d = int.from_bytes(rom[i + 2:i + 4], "big", signed=True)
    if w in (0x4eba, 0x4efa, 0x487a) or (w & 0xf1ff) == 0x41fa:
        kind = {0x4eba: "jsr(pc)", 0x4efa: "jmp(pc)", 0x487a: "pea(pc)"}.get(w, "lea(pc)")
        targets.setdefault(i + 2 + d, []).append(f"{kind}@0x{i:x}")
    elif w in (0x4eb8, 0x4ef8):
        targets.setdefault(int.from_bytes(rom[i + 2:i + 4], "big"), []).append(f"{'jsr' if w == 0x4eb8 else 'jmp'}.w@0x{i:x}")
removed = []
for line in open(os.path.join(O, "deleted_functions.csv")):
    if "PR #53 round 93" in line:
        removed.append((int(line.split(",")[0], 16), re.search(r"\(was (\w+);", line).group(1)))
hit = 0
for a, name in removed:
    if a in targets:
        hit += 1
        print(f"REMOVED ROW HAS A PC-RELATIVE REFERENCE: 0x{a:x} {name}: {targets[a][:4]}")
print(f"{len(removed)} rows removed this round; {hit} have a PC-relative or short absolute reference")
rows = {int(r[0], 16): r[1] for r in csv.reader(open(os.path.join(O, "function_renames.csv"), newline="")) if r and r[0].startswith("0x")}
found = [(a, rows[a], targets[a]) for a in sorted(rows) if a in targets]
print(f"{len(found)} current function rows are reached PC-relatively: " + "; ".join(f"0x{a:x} {n} ({len(t)})" for a, n, t in found)[:1500])
