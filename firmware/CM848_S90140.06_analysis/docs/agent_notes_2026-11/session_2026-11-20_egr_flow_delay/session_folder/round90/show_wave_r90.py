"""Round 90 (read-only): show the naming wave's amended verdicts, or every final name of a batch.
usage: show_wave_r90.py <result.json> amended | <batch>"""
import json
import sys

d = json.load(open(sys.argv[1]))
what = sys.argv[2]
for r in d["results"]:
    props = {p["address"].lower(): p for p in r["proposals"]["proposals"]}
    for v in r["verdicts"]["verdicts"]:
        p = props.get(v["address"].lower(), {})
        if what == "amended" and v["verdict"] == "AMENDED":
            print(f"{r['batch']} {v['address']} {p.get('current_label')}: {p.get('proposed_name')} {p.get('proposed_type')} "
                  f"-> {v.get('final_name')} {v.get('final_type')}")
            print("     ", (v.get("reason") or "")[:300])
        elif what == r["batch"]:
            print(f"{v['address']} {p.get('current_label')} -> {v.get('final_name') or p.get('proposed_name')} "
                  f"{v.get('final_type') or p.get('proposed_type')} [{v['verdict']}]")
