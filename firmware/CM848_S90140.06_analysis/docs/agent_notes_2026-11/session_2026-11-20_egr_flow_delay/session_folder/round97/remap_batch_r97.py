"""Round 97: rewrite the names that rounds 97 A-D changed (parameters / locals / fields, enum types and members, function
names, struct types) inside a collected workflow batch JSON, so the apply sees the current names and types. Every string
of the JSON is rewritten word-bounded; the generic old tokens msg / hi / lo are left alone. Writes the batch in place
and keeps a copy as <batch>.before_remap.json. usage: remap_batch_r97.py <batch.json>..."""
import csv
import json
import os
import re
import shutil
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
mapping = {}
for f in ("map_r97a_cm550.csv", "map_r97a_cm848.csv", "map_r97b_cm550.csv", "map_r97b_cm848.csv", "map_r97c_cm550.csv",
          "map_r97c_cm848.csv", "map_r97d_types.csv"):
    p = os.path.join(HERE, f)
    if os.path.exists(p):
        for r in csv.DictReader(open(p)):
            if r["old_label"] not in ("msg", "hi", "lo") and r["old_label"] != r["name"]:
                mapping[r["old_label"]] = r["name"]
pattern = re.compile(r"(?<![A-Za-z0-9_])(" + "|".join(map(re.escape, sorted(mapping, key=len, reverse=True))) + r")(?![A-Za-z0-9_])")
count = 0


def walk(x):
    global count
    if isinstance(x, str):
        new, n = pattern.subn(lambda m: mapping[m.group(1)], x)
        count += n
        return new
    if isinstance(x, list):
        return [walk(v) for v in x]
    if isinstance(x, dict):
        return {k: walk(v) for k, v in x.items()}
    return x


for p in sys.argv[1:]:
    count = 0
    shutil.copy(p, p.replace(".json", ".before_remap.json"))
    d = json.load(open(p))
    json.dump(walk(d), open(p, "w"), indent=1)
    print(os.path.basename(p), count, "tokens remapped")
