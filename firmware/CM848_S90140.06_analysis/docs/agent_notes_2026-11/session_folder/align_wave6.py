"""Wave 6 vocabulary / encoding pass: write renames/aligned_W6_*.jsonl.
- cm848_init* -> cm848_initialize*; *_axis_offset_cache / *_lookup_cached_offset -> *_cached_axis_offset (names and text)
- a confirmed function row with a plate but no `new` keeps its name (plate-only refresh)
- `<name>+N` sub-label rows are left out (not identifiers); listed"""
import json
import os
import re
import sys

d = sys.argv[1]
groups = ("injection_rail", "air_vgt", "governor", "combustion")
SUFFIX = [("_axis_offset_cache", "_cached_axis_offset"), ("_lookup_cached_offset", "_cached_axis_offset")]


def fix(name):
    for o, n in SUFFIX:
        if name.endswith(o):
            name = name[: -len(o)] + n
    return re.sub(r"^cm848_init(?=[A-Z])", "cm848_initialize", name)


recs, text_map, dropped = {}, {}, []
for g in groups:
    recs[g] = [json.loads(l) for l in open(os.path.join(d, f"result_W6_{g}.jsonl")) if l.strip()]
    for r in recs[g]:
        if r.get("kind") == "function" and r.get("verdict") == "confirmed" and not r.get("new") and r.get("plate_comment"):
            r["new"] = r["old"]
        if r.get("new") and r.get("kind") in ("function", "global", "new_global"):
            n = fix(r["new"])
            if n != r["new"]:
                text_map[r["new"]] = n
pattern = re.compile(r"\b(" + "|".join(re.escape(k) for k in sorted(text_map, key=len, reverse=True)) + r")\b") if text_map else None
for g, rs in recs.items():
    out = []
    for r in rs:
        if r.get("kind") == "global" and ("+" in (r.get("old") or "") or "+" in (r.get("new") or "")):
            dropped.append(f"{g}: {r.get('address')} {r.get('old')} -> {r.get('new')}")
            continue
        if r.get("new") in text_map:
            r["new"] = text_map[r["new"]]
        for k in ("plate_comment", "evidence", "text", "comment"):
            if r.get(k) and pattern:
                r[k] = pattern.sub(lambda m: text_map[m.group(1)], r[k])
        out.append(json.dumps(r))
    open(os.path.join(d, f"aligned_W6_{g}.jsonl"), "w").write("\n".join(out) + "\n")
print("names changed:", len(text_map), "| sub-label rows left out:", len(dropped))
for x in dropped:
    print("  ", x)
