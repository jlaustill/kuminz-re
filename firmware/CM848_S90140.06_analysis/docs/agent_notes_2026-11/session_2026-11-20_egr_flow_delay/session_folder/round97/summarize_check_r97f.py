"""Round 97 stage F: summarize the statement-count check workflow (wf_d98cbafa-77a) - one line per function, the
issues of every non-equivalent one and the skeptics' rulings. usage: summarize_check_r97f.py <output file>"""
import json
import sys

text = open(sys.argv[1]).read()
data = json.loads(text)["result"]
pass
json.dump(data, open("/home/linux/.claude/jobs/374b0424/tmp/w15/r97/statement_check_r97f.json", "w"), indent=1)
for g in data:
    print("==", g["group"])
    for f in g["functions"]:
        print(f"  {f['address']} {f.get('name', '')}: {f['verdict']}")
        if f["verdict"] != "equivalent" or f["issues"]:
            for i in f["issues"]:
                print("     issue:", i[:400])
    for v in g.get("verified") or []:
        print(f"  SKEPTIC {v['address']}: issue_is_real={v['issue_is_real']}: {v['explanation'][:700]}")
