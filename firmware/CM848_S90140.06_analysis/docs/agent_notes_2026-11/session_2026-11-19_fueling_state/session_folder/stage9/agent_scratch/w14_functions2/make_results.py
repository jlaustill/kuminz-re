"""Writes the W14 functions2 result file (one JSON object per line, bin order) from items_a.py / items_b.py."""
import json
import os
import sys

sys.path.insert(0, "/tmp/w14_functions2")
from items_a import ITEMS_A  # noqa: E402
from items_b import ITEMS_B  # noqa: E402

BIN = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/bins/functions2.json"
OUT = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/result_W14_functions2.jsonl"

bin_items = json.load(open(BIN))["functions"]
by_address = {it["address"]: it for it in ITEMS_A + ITEMS_B}
assert len(by_address) == len(ITEMS_A) + len(ITEMS_B), "duplicate address in the item lists"
lines = []
for entry in bin_items:
    item = by_address.pop(entry["address"])
    assert item["old"] == entry["current"], (entry["address"], item["old"], entry["current"])
    record = {"kind": "function", "verdict": "confirmed", "address": entry["address"], "old": item["old"],
              "new": item["new"], "evidence": " ".join(item["evidence"].split()), "code_quote": item["code_quote"],
              "plate_comment": " ".join(item["plate_comment"].split())}
    lines.append(json.dumps(record, ensure_ascii=True))
assert not by_address, f"items not in the bin: {sorted(by_address)}"
with open(OUT, "w") as handle:
    handle.write("\n".join(lines) + "\n")
print(f"wrote {len(lines)} lines to {OUT}")
