"""Wave 3 vocabulary pass: write renames/aligned_W3_*.jsonl (names fixed, and the same fixes in plate / evidence text)."""
import json
import os
import re
import sys

d = sys.argv[1]
SUFFIX = [("_axis_offset_cache", "_cached_axis_offset"), ("_lookup_cached_offset", "_cached_axis_offset"),
          ("_interpolation_state", "_cached_axis_offset")]
EXACT = {"j1939_fd1_estimated_fan_speed_byte": "j1939_fan_drive_1_estimated_fan_speed_byte"}


def fix(name):
    for o, n in SUFFIX:
        if name.endswith(o):
            name = name[: -len(o)] + n
    name = re.sub(r"^cm848_init(?=[A-Z])", "cm848_initialize", name)
    return EXACT.get(name, name)


groups = ("injection", "rail", "air", "governor")
records = {}
text_map = {}
for g in groups:
    src = os.path.join(d, f"result_W4_{g}.jsonl")
    if not os.path.exists(src):
        print("missing", src)
        continue
    records[g] = [json.loads(l) for l in open(src) if l.strip()]
    for r in records[g]:
        if r.get("new") and r.get("kind") in ("function", "global", "new_global"):
            n = fix(r["new"])
            if n != r["new"]:
                text_map[r["new"]] = n
pattern = re.compile(r"\b(" + "|".join(re.escape(k) for k in sorted(text_map, key=len, reverse=True)) + r")\b") if text_map else None
for g, recs in records.items():
    out = []
    for r in recs:
        if r.get("new") in text_map:
            r["new"] = text_map[r["new"]]
        for k in ("plate_comment", "evidence", "text"):
            if r.get(k) and pattern:
                r[k] = pattern.sub(lambda m: text_map[m.group(1)], r[k])
        out.append(json.dumps(r))
    open(os.path.join(d, f"aligned_W4_{g}.jsonl"), "w").write("\n".join(out) + "\n")
print("names changed:", len(text_map), sorted(text_map.values())[:8])
