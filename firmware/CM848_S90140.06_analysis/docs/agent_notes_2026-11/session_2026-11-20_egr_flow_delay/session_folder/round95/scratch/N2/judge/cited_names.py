"""Check every identifier cited in the N2 proposal comments against the frozen CM550 CSVs (function names, global
names, struct field names, the proposals themselves) and every 'name (0xADDR)' function citation against its address.
usage: python3 cited_names.py"""
import csv
import json
import re

J = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/scratch/N2/judge/"
F = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/frozen/cm550/"
funcs = {}
for r in csv.reader(open(F + "function_renames.csv")):
    if r and r[0].startswith("0x"):
        funcs[r[1]] = int(r[0], 16)
gnames = {}
for r in csv.reader(open(F + "global_variables.csv")):
    if r and r[0].startswith("0x"):
        gnames.setdefault(r[1], []).append(int(r[0], 16))
fields = set()
structs = set()
for r in csv.reader(open(F + "structure_definitions.csv")):
    if r and not r[0].startswith("#") and len(r) > 2:
        structs.add(r[0])
        fields.add(r[2])
enums = set()
for r in csv.reader(open(F + "enums.csv")):
    if r and not r[0].startswith("#") and len(r) > 2:
        enums.add(r[0])
        enums.add(r[2])
props = json.load(open(J + "proposals_globals.json"))
pnames = {e["proposed_name"] for e in props}
known_words = set()
unknown = {}
bad_addr = []
for e in props:
    c = e["comment"]
    for m in re.finditer(r"\b([a-z][a-z0-9]*(?:_[a-z0-9]+)+|[a-z]+[A-Z][A-Za-z0-9_]*)\b(?:\.([a-z_0-9]+))?", c):
        nm, fld = m.group(1), m.group(2)
        if nm in pnames or nm in gnames or nm in funcs or nm in structs or nm in fields or nm in enums:
            if fld and fld not in fields:
                unknown.setdefault(nm + "." + fld, set()).add(e["address"])
            continue
        unknown.setdefault(nm, set()).add(e["address"])
    for m in re.finditer(r"\b([A-Za-z_][A-Za-z0-9_]*) \((?:jsr at |a\d, jsr at |pea, jsr at |)?(0x[0-9a-f]+)", c):
        nm, ad = m.group(1), int(m.group(2), 16)
        if nm in funcs and not (funcs[nm] <= ad < funcs[nm] + 0x1000):
            bad_addr.append((e["address"], nm, hex(funcs[nm]), hex(ad)))
print("UNKNOWN identifiers (not a function, global, struct, field, enum or proposal):")
for k, v in sorted(unknown.items()):
    print(f"  {k}: {sorted(v)[:4]}{' ...' if len(v) > 4 else ''}")
print("FUNCTION citations whose address is not at / just after the function's entry:")
for b in bad_addr:
    print("  ", b)
