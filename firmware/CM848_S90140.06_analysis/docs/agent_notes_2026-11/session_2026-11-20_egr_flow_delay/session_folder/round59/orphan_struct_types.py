"""Round 59: list the CM848 struct types that nothing uses. A type counts as used when any of these name it (whole
word): an address row of its own in structure_definitions.csv; another type's field type or dependency column; any
other CSV in output/ (globals, arrays, prototypes, locals, labels, constants, enums, registers, call fixups ...); the
.cpp; firmware/scripts/ (Java stages, Python tools, tests); firmware/script_tests/; both CLAUDE.md files;
.claude/skills/. Fields of types in `--ignore` (the ones being removed) do not count, so rerun until the list is
stable.  usage: orphan_struct_types.py <repo> [--ignore T1,T2,...]"""
import csv
import glob
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
ignore = set(sys.argv[3].split(",")) if len(sys.argv) > 3 and sys.argv[2] == "--ignore" else set()
O = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
rows = [r for r in csv.reader(open(os.path.join(O, "structure_definitions.csv"))) if r and not r[0].startswith("#")]
types = {}
for r in rows[1:]:
    types.setdefault(r[0], []).append(r)
own_address = {n for n, rs in types.items() if any(len(r) > 1 and r[1].strip() for r in rs)}
field_text = " ".join(" ".join(r[3:4] + r[6:7]) for r in rows[1:] if r[0] not in ignore)
others = []
for path in glob.glob(os.path.join(O, "*.csv")):
    if not path.endswith("structure_definitions.csv"):
        others.append((os.path.basename(path), open(path, errors="replace").read()))
others.append(("cm848_rom.ghidra.cpp", open(os.path.join(O, "cm848_rom.ghidra.cpp"), errors="replace").read()))
for pattern in ("firmware/scripts/**/*", "firmware/script_tests/**/*", ".claude/skills/**/*"):
    for path in glob.glob(os.path.join(repo, pattern), recursive=True):
        if os.path.isfile(path) and os.path.getsize(path) < 5_000_000:
            others.append((os.path.relpath(path, repo), open(path, errors="replace").read()))
for name in ("CLAUDE.md", "firmware/CLAUDE.md"):
    others.append((name, open(os.path.join(repo, name)).read()))
orphans, used_by = [], {}
for name in types:
    pat = re.compile(rf"(?<![\w]){re.escape(name)}(?![\w])")
    hits = [f for f, t in others if pat.search(t)]
    if name in own_address:
        hits.append("own address row")
    if pat.search(field_text):
        hits.append("another type's field / dependency")
    if hits:
        used_by[name] = hits
    else:
        orphans.append(name)
print(f"{len(types)} struct types, {len(orphans)} with no use:")
for n in orphans:
    fields = [r[2] for r in types[n] if len(r) > 2 and r[2]]
    print(f"  {n} ({len(fields)} fields): {', '.join(fields[:8])}{' ...' if len(fields) > 8 else ''}")
