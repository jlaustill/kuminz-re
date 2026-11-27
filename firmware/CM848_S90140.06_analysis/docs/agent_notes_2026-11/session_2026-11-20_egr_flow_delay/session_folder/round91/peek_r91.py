"""Round 91 (read-only): print the finished investigators' proposals (and the skeptics' verdict counts) from the
workflow journal. usage: peek_r91.py <journal.jsonl> [item]"""
import collections
import json
import sys

only = sys.argv[2] if len(sys.argv) > 2 else None
for line in open(sys.argv[1]):
    try:
        e = json.loads(line)
    except ValueError:
        continue
    if e.get("type") != "result":
        continue
    v = e.get("result") or e.get("value") or {}
    if not isinstance(v, dict):
        continue
    if only and v.get("item") != only:
        continue
    if "summary" in v:
        print(f"== {v.get('item')} | {v.get('summary', '')[:500]}")
        for s in v.get("structs") or []:
            print(f"  struct {s.get('firmware')} {s.get('struct_name')} size {s.get('size')}: "
                  + ", ".join(f"+{f['offset']} {f['name']} {f['type']}" for f in s.get("fields", [])))
        for g in v.get("globals") or []:
            print(f"  global {g.get('firmware')} {g.get('address')} {g.get('current_name')} -> {g.get('proposed_name')} "
                  f"{g.get('proposed_type')}")
        print(f"  remove {len(v.get('rows_to_remove') or [])}; locals {len(v.get('local_rows') or [])}")
        for f in v.get("functions") or []:
            print(f"  function {f.get('firmware')} {f.get('address')} {f.get('current_name')} -> {f.get('proposed_name')} "
                  f"({f.get('relation')} {f.get('other_firmware_address', '')})")
    elif "verdicts" in v:
        c = collections.Counter(x["verdict"] for x in v["verdicts"])
        print(f"== verdicts {v.get('item')}: {dict(c)} | {str(v.get('overall', ''))[:300]}")
