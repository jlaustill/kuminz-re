"""Write the campaign's provenance: one row per table (named or left unnamed) with the lookup, the agent's
confidence and evidence, or the skip reason. Usage: campaign_provenance.py <tables_dir> <globals.csv> <out.csv> <result>..."""
import csv
import json
import os
import sys

tables, globals_csv, out, results = sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4:]
lookups = {lk["id"]: lk for lk in json.load(open(os.path.join(tables, "lookups.json")))}
bins = {}
for f in os.listdir(tables):
    if f.startswith("bin_") and f.endswith(".json"):
        b = json.load(open(os.path.join(tables, f)))
        for a in b["assigned_tables"]:
            bins[a] = b["bin"]
names = {}
for line in open(globals_csv):
    p = line.split(",", 3)
    if p[0].startswith("0x") and len(p) > 1:
        names[int(p[0], 16)] = p[1]
by_lookup, by_table = {}, {}
for path in results:
    for line in open(path):
        line = line.strip()
        if line:
            r = json.loads(line)
            if "lookup" in r:
                by_lookup[r["lookup"]] = r
            elif "table" in r:
                by_table[int(r["table"], 16)] = r
clip = lambda s, n: " ".join(str(s or "").split())[:n]
rows = {}
for k, r in by_lookup.items():
    for t in lookups[k]["tables"]:
        if not t.get("to_name") or t["address"] not in bins:
            continue
        a = int(t["address"], 16)
        name = names.get(a, "")
        src = by_table.get(a, r)
        if name:
            row = [f"0x{a:08x}", name, "named", k, bins[t["address"]], src.get("confidence", r.get("confidence", "")),
                   clip(r.get("input"), 160), clip(r.get("output"), 160), clip(src.get("evidence"), 300)]
        else:
            row = [f"0x{a:08x}", "", "unnamed", k, bins[t["address"]], "", clip(r.get("input"), 160),
                   clip(r.get("output"), 160), clip(r.get("reason") or "skipped", 300)]
        if a not in rows or row[2] == "named":
            rows[a] = row
with open(out, "w", newline="") as f:
    w = csv.writer(f)
    f.write("# CM848 lookup-table naming campaign 2026-11-16 (PR #50) - one row per table the campaign covered. "
            "status named = the name it got (with the agent confidence and evidence); unnamed = left WORD_ARRAY_ "
            "with the reason. Evidence is the agent summary; input and output are its traces - they quote names as "
            "they were during the campaign (the later todo 042 renames are in the global_variables.csv / "
            "function_renames.csv comments as '(was ...)'); the name column is current.\n")
    w.writerow(["address", "name", "status", "lookup", "bin", "confidence", "input", "output", "evidence_or_reason"])
    for a in sorted(rows):
        w.writerow(rows[a])
named = sum(1 for r in rows.values() if r[2] == "named")
medium = sum(1 for r in rows.values() if r[2] == "named" and r[5] == "medium")
print(f"rows {len(rows)}  named {named} (medium {medium} = {100 * medium / max(named, 1):.0f} %)  unnamed {len(rows) - named}")
