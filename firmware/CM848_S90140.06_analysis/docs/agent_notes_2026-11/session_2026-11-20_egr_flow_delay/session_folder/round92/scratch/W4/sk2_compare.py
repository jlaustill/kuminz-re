"""Skeptic pass 2 (read-only): compare the W4 proposal's field names with CM848's algorithm_enable_flags_<n>_t types and
scan the proposed names for abbreviations.
usage: sk2_compare.py <batch json> <cm848 structure_definitions.csv>"""
import csv
import json
import re
import sys

j = json.load(open(sys.argv[1]))["proposal"]
rows = [r for r in csv.reader(open(sys.argv[2], newline="")) if r]
cm848 = {}
for r in rows:
    m = re.match(r"algorithm_enable_flags_(\d+)_t$", r[0])
    if m and r[3].startswith("bitfield:1@"):
        cm848.setdefault(int(m.group(1)), {})[int(r[3].split("@")[1])] = r[2]
for w in j["words"]:
    n = w["word"]
    f = {x["bit"]: x["name"] for x in w["fields"]}
    assert sorted(f) == list(range(16)), (n, sorted(f))
    print("word", n, w["proposed_type"], "shared" if w["shared_with_cm848"] else "")
    c = cm848.get(n, {})
    for b in range(16):
        same = (c.get(b) == f[b]) if c else None
        print("   bit %2d %-62s cm848=%-55s %s" % (b, f[b], c.get(b, "-"), "SAME" if same else ("" if same is None else "DIFF")))
bad = re.compile(r"(^|_)(pto|ecm|egr|vss|afc|lsg|asg|rsg|hsg|vgt|wg|ac|imt|eb|ptp|stcg|tas|iim|iah|mux|cal|cfg|en|sw|temp|pres|"
                 r"spd|ctrl|ovrd|diag|dl|ref|init|max|min)(_|$)")
for w in j["words"]:
    for x in w["fields"]:
        if bad.search(x["name"]) or not re.fullmatch(r"[a-z0-9_]+", x["name"]):
            print("NAME CHECK:", w["word"], x["bit"], x["name"])
print("words:", [w["word"] for w in j["words"]], "renames:", j.get("cm848_field_renames"))
