"""Round 94 closing (from round 93's script): the counts in firmware/CM550_J90350.00_analysis/README.md ('Current Analysis State' and the
status line) were taken in round 89; this round removed 52 function rows and typed 1943 global rows. Recount from
the CSVs and rewrite the table and the status line. Keeps the file's line endings. Idempotent.
usage: update_cm550_readme_r93.py <repo>"""
import csv
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
A = os.path.join(repo, "firmware/CM550_J90350.00_analysis")
O = os.path.join(A, "output")
names = [l.split(",")[1] for l in open(os.path.join(O, "function_renames.csv"), newline="").read().split("\n") if l.startswith("0x")]
placeholders = [n for n in names if re.match(r"^[a-z0-9]+_FUN_[0-9a-f]{8}$", n)]
rows = [l.split(",", 3) for l in open(os.path.join(O, "global_variables.csv"), newline="").read().split("\n") if l.startswith("0x")]
ram = [r for r in rows if 0x800000 <= int(r[0], 16) < 0x1000000]
typed = [r for r in rows if len(r) > 2 and r[2] not in ("", "undefined")]
structs, fields = set(), 0
for r in csv.reader(open(os.path.join(O, "structure_definitions.csv"), newline="")):
    if r and not r[0].startswith("#") and r[0] != "struct_name" and len(r) > 2:
        structs.add(r[0])
        fields += 1 if r[2] else 0
cpp = os.path.getsize(os.path.join(O, "J90350.00.ghidra.cpp"))
p = os.path.join(A, "README.md")
t = open(p, newline="").read()
E = "\r\n" if "\r\n" in t else "\n"
table = E.join([
    "Counted from the CSVs for PR #53 round 94 (2026-11-25):", "",
    "| Metric | Count |", "|--------|-------|",
    f"| Function rows | {len(names)} ({len(names) - len(placeholders)} named, {len(placeholders)} placeholders) |",
    f"| Global variable rows | {len(rows):,} ({len(ram):,} in RAM and extended RAM; {len(typed):,} typed) |",
    f"| Structure types | {len(structs)} ({fields} fields) |",
    f"| Decompiled C code | {cpp / 1e6:.1f} MB |",
    "| Memory regions | 4 (ROM + RAM + EXT_RAM + EEPROM) |", ""])
m = re.search(r"Counted from the CSVs for PR #53 round \d+ \(\d{4}-\d\d-\d\d\):\r?\n\r?\n\| Metric \| Count \|\r?\n\|-+\|-+\|\r?\n(?:\|[^\r\n]*\|\r?\n)+", t)
assert m, "table not found"
t2 = t[:m.start()] + table + t[m.end():]
status = re.search(r"^\*\*Status: [^*]*\*\* - [^\r\n]*", t2, re.M)
assert status, "status line not found"
t2 = (t2[:status.start()] + f"**Status: analysis in progress** - {len(names) - len(placeholders)} named functions of {len(names)}, "
      f"{len(ram):,} RAM variable rows ({len(typed):,} global rows typed), full decompilation available." + t2[status.end():])
if t2 != t:
    open(p, "w", newline="").write(t2)
print(table.replace("\r", ""))
