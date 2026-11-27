"""Round 88: the misname audit's accepted / amended changes as a TSV (one row per firmware + kind + address, first
occurrence wins; duplicates across groups are reported), plus each verdict's problems in a notes file.
TSV columns: group, firmware, kind, address, current, final, final_type, fields, verdict, confidence, reason.
usage: audit_changes.py <audit_result.json> <out.tsv> <out_notes.txt>"""
import json
import sys

data = json.load(open(sys.argv[1]))["result"]
rows, notes, seen = [], [], {}
for g in data:
    verdicts = list(g["verdicts"]["verdicts"])
    for c in g["proposal"]["changes"]:
        key = c.get("address", "").lower().lstrip("0x").lstrip("0")
        v = next((v for v in verdicts if v.get("firmware") == c["firmware"]
                  and v.get("address", "").lower().lstrip("0x").lstrip("0") == key
                  and (v.get("current") == c["current"] or not key)), None)
        if v is None:
            print("NO VERDICT", g["group"], c["firmware"], c.get("address"), c["current"])
            continue
        verdicts.remove(v)
        notes.append(f"== [{g['group']}] {c['firmware']} {c['kind']} {c.get('address', '')} {c['current']} -> "
                     f"{v['final']} [{v['verdict']}]\n" + "\n".join("  - " + " ".join(p.split()) for p in v["problems"]))
        if v["verdict"] == "reject":
            continue
        ident = (c["firmware"], c["kind"], c.get("address", "").lower() or c["current"])
        if ident in seen:
            prev = seen[ident]
            if prev[5] != v["final"]:
                print("CONFLICT", ident, prev[5], v["final"])
            continue
        row = [g["group"], c["firmware"], c["kind"], c.get("address", ""), c["current"], v["final"],
               v.get("final_type") or c.get("type") or "", c.get("fields", ""), v["verdict"], c["confidence"],
               " ".join(c["reason"].split())]
        seen[ident] = row
        rows.append(row)
with open(sys.argv[2], "w") as fh:
    for r in rows:
        fh.write("\t".join(x.replace("\t", " ") for x in r) + "\n")
with open(sys.argv[3], "w") as fh:
    fh.write("\n".join(notes) + "\n\n== rejected leads\n")
    for g in data:
        for r in g["proposal"].get("rejected_leads", []):
            fh.write(f"  - [{g['group']}] " + " ".join(r.split()) + "\n")
print(len(rows), "unique accepted / amended changes")
