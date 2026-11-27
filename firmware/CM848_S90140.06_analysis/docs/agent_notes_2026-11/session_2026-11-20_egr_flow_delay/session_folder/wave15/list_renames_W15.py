"""Print the wave 15 renames of one bin compactly for review: address, old -> new, the e2m record, the quoted line.
usage: list_renames_W15.py <w15 dir> <bin number>"""
import json
import os
import sys

here, k = sys.argv[1], sys.argv[2]
items = {it["address"]: it for it in json.load(open(os.path.join(here, "bins", f"bin{k}.json")))}
for line in open(os.path.join(here, "results", f"result_W15_bin{k}.jsonl")):
    r = json.loads(line)
    if r["verdict"] != "confirmed":
        continue
    it = items.get(r["address"]) or items.get(f"0x{int(r['address'], 16):08x}") or {}
    print(f"{r['address']} {r['old']} -> {r['new']} [{it.get('block')} +{it.get('offset')} {it.get('record')} "
          f"{it.get('unit')} {it.get('current_row_type')}]")
    print(f"    Q: {r.get('code_quote', '')[:200]}")
