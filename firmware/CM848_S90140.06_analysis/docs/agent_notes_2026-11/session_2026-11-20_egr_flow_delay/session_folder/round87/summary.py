"""Summarize the round 87 audit workflow: each proposed change with its skeptic verdict and final name / type, the
problems (shortened), and the investigators' rejected leads. Verdicts are matched to changes by firmware + address
(+ current name for type-only rows). usage: summary.py <workflow output file> [--problems]"""
import json
import sys

data = json.load(open(sys.argv[1]))["result"]
show_problems = "--problems" in sys.argv
for group in data:
    print(f"===== {group['group']}")
    verdicts = group["verdicts"]["verdicts"]
    used = set()
    for c in group["proposal"]["changes"]:
        match = None
        for i, v in enumerate(verdicts):
            if i in used:
                continue
            if v.get("firmware") == c["firmware"] and (v.get("address", "").lower().lstrip("0x").lstrip("0") ==
                                                        c.get("address", "").lower().lstrip("0x").lstrip("0")) and \
                    (v.get("current") == c["current"] or not c.get("address")):
                match = (i, v)
                break
        v = match[1] if match else {}
        if match:
            used.add(match[0])
        t = f" type={c.get('type')}" if c.get("type") else ""
        vt = f" type={v.get('final_type')}" if v.get("final_type") else ""
        print(f"{c['firmware']} {c['kind']:15} {c.get('address',''):11} {c['current'][:44]:44} -> {c['proposed'][:48]}{t} "
              f"[{c['confidence']}] | {v.get('verdict','NO VERDICT')} {v.get('final','')[:48]}{vt}")
        if show_problems:
            for p in v.get("problems", [])[:2]:
                print(f"{'':6}- {p[:260]}")
    extra = [v for i, v in enumerate(verdicts) if i not in used]
    for v in extra:
        print(f"   (verdict without a matching change) {v.get('firmware')} {v.get('address')} {v.get('current')} -> "
              f"{v.get('verdict')} {v.get('final')}")
    for r in group["proposal"].get("rejected_leads", []):
        print(f"   rejected lead: {r[:200]}")
