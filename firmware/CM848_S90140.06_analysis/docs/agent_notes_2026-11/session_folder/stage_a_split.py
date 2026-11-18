"""Write aligned_<wave>_<group>_A.jsonl copies without the given stage-B new rows; print the row kinds per group.
usage: stage_a_split.py <dir> <wave> <groups,comma> <stage-B address,...>"""
import collections
import json
import os
import sys

d, wave, groups, b = sys.argv[1], sys.argv[2], sys.argv[3].split(","), sys.argv[4]
stage_b = {int(a, 16) for a in b.split(",") if a}
for g in groups:
    rows = [json.loads(l) for l in open(os.path.join(d, f"aligned_{wave}_{g}.jsonl")) if l.strip()]
    keep = [r for r in rows if not (r.get("kind") == "new_global" and int(r["address"], 16) in stage_b)]
    open(os.path.join(d, f"aligned_{wave}_{g}_A.jsonl"), "w").write("".join(json.dumps(r) + "\n" for r in keep))
    kinds = collections.Counter(r.get("kind") for r in rows)
    extra = sum(1 for r in rows if r.get("new_type")), sum(1 for r in rows if r.get("kind") == "note" and r.get("text", "").startswith("DELETE "))
    print(f"{g}: {len(rows)} -> {len(keep)} {dict(kinds)} new_type {extra[0]} DELETE notes {extra[1]}")
