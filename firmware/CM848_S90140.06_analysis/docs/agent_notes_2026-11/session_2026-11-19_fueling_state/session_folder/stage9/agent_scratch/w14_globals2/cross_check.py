"""Cross-check my result against the other wave-14 result files that exist now:
1. function renames whose OLD name is cited in my comments or evidence;
2. global renames at the addresses of my cross-bin pairs, and any new-name clash."""
import glob
import json
import os
import re

STAGE9 = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9"
mine = [json.loads(l) for l in open(f"{STAGE9}/result_W14_globals2.jsonl") if l.strip()]
text_comment = " ".join(r.get("comment", "") for r in mine)
text_all = text_comment + " " + " ".join(r.get("evidence", "") + " " + r.get("type_note", "") for r in mine)
my_new = {r["new"] for r in mine if r["verdict"] == "confirmed"}
my_addr = {r["address"] for r in mine}
PAIRS = {"0x0005be66", "0x0040a17e", "0x0040a180", "0x00406a46", "0x00406a52", "0x0040a430", "0x0040a432", "0x0040a434",
         "0x0040a436", "0x00408f2c", "0x00408f2e", "0x00408f30", "0x0040a891", "0x0040a182", "0x004070e0", "0x004070e2",
         "0x004070e4", "0x0040b744", "0x0040b756"}
for path in sorted(glob.glob(f"{STAGE9}/result_W14_*.jsonl")):
    name = os.path.basename(path)
    if name.endswith("globals2.jsonl"):
        continue
    for line in open(path):
        line = line.strip()
        if not line:
            continue
        try:
            r = json.loads(line)
        except ValueError:
            continue
        kind, verdict = r.get("kind"), r.get("verdict")
        if kind == "function" and verdict == "confirmed" and r.get("new") != r.get("old"):
            old = r["old"]
            in_comment = re.search(rf"(?<![A-Za-z0-9_]){re.escape(old)}(?![A-Za-z0-9_])", text_comment)
            in_other = re.search(rf"(?<![A-Za-z0-9_]){re.escape(old)}(?![A-Za-z0-9_])", text_all)
            if in_other:
                print(f"FUNCTION RENAME cited by me ({'comment' if in_comment else 'evidence only'}): {old} -> {r['new']} [{name}]")
        if kind == "global":
            if r.get("address") in PAIRS:
                print(f"PAIR {name}: {r.get('address')} {r.get('old')} -> {r.get('new')} ({verdict})")
            if r.get("new") in my_new and r.get("address") not in my_addr:
                print(f"CLASH {name}: {r.get('address')} -> {r.get('new')}")
            if r.get("address") in my_addr:
                print(f"DUPLICATE ADDRESS {name}: {r.get('address')}")
            for token in (r.get("new") or "", r.get("old") or ""):
                pass
