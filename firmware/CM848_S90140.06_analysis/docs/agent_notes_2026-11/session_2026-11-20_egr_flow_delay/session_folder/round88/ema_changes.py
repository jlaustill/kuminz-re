"""Round 88: the round 87 audit's filter library ('ema') group as a TSV - every change with its full proposed name,
type, fields, the skeptic's verdict / final name / final type, and the skeptic's problems (joined) - plus the
investigator's rejected leads. usage: ema_changes.py <audit_result_r87.json> <out.tsv> <out_problems.txt>"""
import json
import sys

group = [g for g in json.load(open(sys.argv[1]))["result"] if g["group"] == "ema"][0]
verdicts = list(group["verdicts"]["verdicts"])
rows, notes = [], []
for c in group["proposal"]["changes"]:
    key = c.get("address", "").lower().lstrip("0x").lstrip("0")
    v = next((v for v in verdicts if v.get("firmware") == c["firmware"]
              and v.get("address", "").lower().lstrip("0x").lstrip("0") == key
              and (v.get("current") == c["current"] or not key)), None)
    if v is None:
        raise SystemExit(f"no verdict for {c['kind']} {c.get('address')} {c['current']}")
    verdicts.remove(v)
    rows.append([c["kind"], c.get("address", ""), c["current"], c["proposed"], c.get("type", ""), c.get("fields", ""),
                 v["verdict"], v["final"], v.get("final_type", "") or "", c["confidence"],
                 " ".join(c["reason"].split())])
    notes.append(f"== {c['kind']} {c.get('address', '')} {c['current']} -> {v['final']} [{v['verdict']}]\n"
                 + "\n".join("  - " + " ".join(p.split()) for p in v["problems"]))
with open(sys.argv[2], "w") as fh:
    for r in rows:
        fh.write("\t".join(x.replace("\t", " ") for x in r) + "\n")
with open(sys.argv[3], "w") as fh:
    fh.write("\n".join(notes) + "\n\n== rejected leads\n")
    for r in group["proposal"].get("rejected_leads", []):
        fh.write("  - " + " ".join(r.split()) + "\n")
print(len(rows), "rows")
