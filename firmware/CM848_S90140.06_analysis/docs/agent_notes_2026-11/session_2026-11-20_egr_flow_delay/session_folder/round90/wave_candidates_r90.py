"""Round 90 (read-only): the CM550 naming wave's candidates.
A: e2m scalar records with no row (or an unnamed row) that the .cpp references (e2m_name_audit.py --firmware cm550).
B: rows with a placeholder name (unnamed_data_<address>) - the e2m records inside / at them.
C: rows named with a bare Calterm mnemonic (all capitals, 4-10 characters, or <mnemonic>_param) that the .cpp references.
Writes one TSV per group with the e2m records and the reference counts. usage: wave_candidates_r90.py <repo> <audit.csv> <outdir>"""
import collections
import csv
import os
import re
import sys

repo, audit, outdir = sys.argv[1], sys.argv[2], sys.argv[3]
O = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
cpp = open(os.path.join(O, "J90350.00.ghidra.cpp"), errors="replace").read()
code = "\n".join(l for l in cpp.split("\n") if not l.strip().startswith(("//", "/*", "*")))
refs = collections.Counter(re.findall(r"\b[A-Za-z_]\w*\b", code))
rows = {int(r[0], 16): r for r in csv.reader(open(os.path.join(O, "global_variables.csv"), newline="")) if r and r[0].startswith("0x")}
records = list(csv.DictReader(open(audit, newline="")))
by_address = collections.defaultdict(list)
for r in records:
    by_address[int(r["address"], 16)].append(r)
A = [r for r in records if r["status"] in ("none", "unnamed") and int(r["references"]) > 0]
MNEMONIC = re.compile(r"^([A-Z][A-Z0-9]{3,9}|[a-z][a-z0-9]{3,9}_param)$")
B, C = [], []
for a, r in sorted(rows.items()):
    name = r[1]
    label_refs = refs.get(name, 0) + refs.get("_" + name, 0)
    if re.match(r"^unnamed_data_[0-9a-f]+$", name):
        inside = [x for x in records if a <= int(x["address"], 16) < a + 64]
        B.append((r[0], name, r[2], label_refs, " | ".join(f"{x['address']} {x['record']} {x['size']}B: {x['description'][:60]}" for x in inside[:6])))
    elif MNEMONIC.match(name) and label_refs:
        here = by_address.get(a, [])
        C.append((r[0], name, r[2], label_refs, " | ".join(f"{x['record']} {x['size']}B: {x['description'][:70]}" for x in here[:3])))
os.makedirs(outdir, exist_ok=True)
with open(os.path.join(outdir, "candidates_A.tsv"), "w") as fh:
    fh.write("address\tlabel\treferences\tblock\toffset\trecord\tsize\tsigned\tscale\tdump_raw\tdescription\n")
    for r in A:
        fh.write("\t".join([r["address"], r["label"], r["references"], r["block"], r["offset"], r["record"], str(r["size"]),
                            r["signed"], r["scale"], str(r["dump_raw"]), r["description"]]) + "\n")
for name, group in (("candidates_B.tsv", B), ("candidates_C.tsv", C)):
    with open(os.path.join(outdir, name), "w") as fh:
        fh.write("address\tname\ttype\treferences\te2m\n")
        for g in group:
            fh.write("\t".join(str(x) for x in g) + "\n")
print(f"A {len(A)} (referenced, no row), B {len(B)} (unnamed_data_ rows), C {len(C)} (referenced mnemonic names)")
