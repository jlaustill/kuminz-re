"""Write the round 87 audit's accepted / amended changes for the twin, CAN chip select 5, speed and restart groups as a
TSV (group, firmware, kind, address, current, final, final type, verdict, reason), from the skeptics' verdicts.
usage: final_changes.py <workflow output file> <out.tsv>"""
import json
import sys

data = json.load(open(sys.argv[1]))["result"]
rows = []
for group in data:
    if group["group"] == "ema":
        continue
    verdicts = list(group["verdicts"]["verdicts"])
    for c in group["proposal"]["changes"]:
        key = c.get("address", "").lower().lstrip("0x").lstrip("0")
        match = next((v for v in verdicts if v.get("firmware") == c["firmware"] and
                      v.get("address", "").lower().lstrip("0x").lstrip("0") == key and v.get("current") == c["current"]), None)
        if match is None:
            print("NO VERDICT:", c["firmware"], c.get("address"), c["current"])
            continue
        verdicts.remove(match)
        if match["verdict"] == "reject":
            continue
        reason = " ".join(c["reason"].split())
        rows.append([group["group"], c["firmware"], c["kind"], c.get("address", ""), c["current"], match["final"],
                     match.get("final_type") or c.get("type") or "", match["verdict"], reason])
with open(sys.argv[2], "w") as fh:
    for r in rows:
        fh.write("\t".join(r) + "\n")
print(len(rows), "changes")
for r in rows:
    print(f"{r[0]:8} {r[1]} {r[2]:8} {r[3]:11} {r[4]} -> {r[5]} {r[6]} [{r[7]}]")
