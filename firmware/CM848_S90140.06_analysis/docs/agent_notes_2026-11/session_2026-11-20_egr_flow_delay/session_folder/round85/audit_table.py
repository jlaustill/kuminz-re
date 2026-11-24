"""Print the prefix audit workflow's result as one line per function: address, current name, the investigator's proposal
and change, the skeptic's verdict and final name, and the skeptic's problems (shortened).
usage: audit_table.py <workflow output file> [--full <address>]"""
import json
import sys

data = json.load(open(sys.argv[1]))["result"]
full = sys.argv[3] if len(sys.argv) > 3 and sys.argv[2] == "--full" else None
rows = []
for group in data:
    verdicts = {v["address"]: v for v in group["verdicts"]["verdicts"]}
    for f in group["proposals"]["functions"]:
        v = verdicts.get(f["address"], {})
        rows.append((group["group"], f, v))
        if full and f["address"].endswith(full.replace("0x", "")):
            print(json.dumps({"proposal": f, "verdict": v}, indent=1))
if not full:
    for g, f, v in rows:
        print(f"{g:8} {f['address']} {f['current_name']:42} {f['change']:11} -> {f['proposed_name']:52} | "
              f"{v.get('verdict', '?'):6} {v.get('final_name', '?')}")
        for p in v.get("problems", [])[:2]:
            print(f"{'':20}- {p[:230]}")
    print(len(rows), "functions")
