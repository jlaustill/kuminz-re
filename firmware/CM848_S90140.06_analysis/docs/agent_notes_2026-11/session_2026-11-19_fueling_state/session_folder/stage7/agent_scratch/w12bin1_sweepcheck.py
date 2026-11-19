import csv
import json
import re

OUT = '/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/result_W12_bin1.jsonl'
FW = 'firmware/CM848_S90140.06_analysis/output'


def known_names(out):
    known = set()
    for name, cols in (("global_variables.csv", (1, 2)), ("function_renames.csv", (1,)), ("deleted_functions.csv", (1,)),
                       ("structure_definitions.csv", (0, 2)), ("enums.csv", (0, 2)), ("arrays.csv", (1,)),
                       ("local_variables.csv", (3,)), ("function_definitions.csv", (3,))):
        try:
            rows = list(csv.reader(open(f"{out}/{name}")))
        except FileNotFoundError:
            continue
        for row in rows:
            for c in cols:
                if len(row) > c and row[c]:
                    known.add(re.sub(r"\[\d+\]$", "", row[c]))
    return known


rows = [json.loads(l) for l in open(OUT)]
known = known_names(FW) | {r['new'] for r in rows}
token = re.compile(r"\b(?:[a-z][a-z0-9]*(?:_[a-z0-9]+){2,}|(?:cm848|mpc555|hpcr|vp44|mc68k|cm550)_[A-Za-z0-9_]+)\b")
bad = {}
for r in rows:
    text = r['comment']
    for m in token.finditer(text):
        t = m.group(0)
        if t in known or re.sub(r"_(?:cal|[0-9]+)$", "", t) in known:
            continue
        bad.setdefault(t, []).append(r['address'])
for t, w in sorted(bad.items()):
    print(t, w[:4])
print("tokens the sweep would flag:", len(bad))
