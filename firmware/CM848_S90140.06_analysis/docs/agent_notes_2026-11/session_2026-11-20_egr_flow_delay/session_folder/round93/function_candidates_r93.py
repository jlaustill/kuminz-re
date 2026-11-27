"""Round 93 (read-only): CM550's placeholder-named functions (<prefix>_FUN_<address>) with the evidence each body
holds: lines, named enable bits (algorithm_enable_flags_<n>_cal.<field>), enum members (FUELING_STATE_ / ENGINE_STATE_
...), named callees, callers (and whether they are named), and the share of globals in it that are still DAT_.
Also lists the extra functions given on the command line (flagged misnames). Writes a TSV sorted by address.
usage: function_candidates_r93.py <repo> <out.tsv> [<extra function name>...]"""
import collections
import csv
import os
import re
import sys

repo, out, extra = sys.argv[1], sys.argv[2], set(sys.argv[3:])
O = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
names = {}
for r in csv.reader(open(os.path.join(O, "function_renames.csv"), newline="")):
    if r and r[0].startswith("0x"):
        names[r[1]] = int(r[0], 16)
PLACEHOLDER = re.compile(r"^[a-z0-9]+_FUN_[0-9a-f]{8}$")
cpp = open(os.path.join(O, "J90350.00.ghidra.cpp"), errors="replace").read()
bodies = {}
for m in re.finditer(r"^// Function: (\w+) @ (0x[0-9a-f]+)\n(.*?)(?=^// Function: |\Z)", cpp, re.M | re.S):
    bodies[m.group(1)] = m.group(3)
callers = collections.defaultdict(set)
call_re = re.compile(r"\b(\w+)\s*\(")
for fn, body in bodies.items():
    code = "\n".join(l for l in body.split("\n") if not l.strip().startswith(("//", "/*", "*")))
    for callee in set(call_re.findall(code)):
        if callee in names and callee != fn:
            callers[callee].add(fn)
rows = []
for fn in sorted(names, key=names.get):
    if not (PLACEHOLDER.match(fn) or fn in extra) or fn not in bodies:
        continue
    body = bodies[fn]
    code = "\n".join(l for l in body.split("\n") if not l.strip().startswith(("//", "/*", "*")))
    enable = sorted(set(re.findall(r"algorithm_enable_flags_\d+_cal\.(\w+)", code)))
    enums = sorted(set(re.findall(r"\b((?:FUELING_STATE|ENGINE_STATE|RAM_REFRESH|J1939_[A-Z]+)_[A-Z0-9_]+)\b", code)))
    callees = sorted(c for c in set(call_re.findall(code)) if c in names and c != fn)
    named_callees = [c for c in callees if not PLACEHOLDER.match(c)]
    cs = sorted(callers.get(fn, ()))
    named_callers = [c for c in cs if not PLACEHOLDER.match(c)]
    dat = len(set(re.findall(r"\b_?DAT_[0-9a-f]{8}\b", code)))
    idents = len(set(re.findall(r"\b[a-z_][a-z0-9_]{6,}\b", code)))
    rows.append((f"0x{names[fn]:08x}", fn, len(code.split("\n")), len(enable), len(enums), len(named_callees),
                 len(callees), len(named_callers), len(cs), dat, idents, " ".join(enable[:6]), " ".join(enums[:6]),
                 " ".join(named_callers[:4])))
with open(out, "w") as fh:
    fh.write("address\tname\tlines\tenable_bits\tenum_members\tnamed_callees\tcallees\tnamed_callers\tcallers\tdat\tidents\t"
             "enable\tenums\tcallers_named\n")
    for r in rows:
        fh.write("\t".join(str(x) for x in r) + "\n")
strong = [r for r in rows if r[3] + r[4] > 0]
print(f"{len(rows)} functions; {len(strong)} with a named enable bit or enum member; "
      f"{sum(1 for r in rows if r[7] > 0)} with a named caller; {sum(1 for r in rows if r[2] <= 12)} of 12 lines or fewer; "
      f"total lines {sum(r[2] for r in rows)}")
