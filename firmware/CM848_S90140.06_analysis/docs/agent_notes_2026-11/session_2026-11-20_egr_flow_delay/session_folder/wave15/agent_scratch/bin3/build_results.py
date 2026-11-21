"""Rebuild the whole result file from the per-block data modules, in bin order (so a re-run never duplicates lines).
usage: build_results.py"""
import json
import sys

sys.path.insert(0, "/home/linux/.claude/jobs/374b0424/tmp/w15/agent_scratch/bin3")
import d_1254  # noqa: E402
import d_a  # noqa: E402
import d_b  # noqa: E402
import d_c  # noqa: E402

BIN = "/home/linux/.claude/jobs/374b0424/tmp/w15/bins/bin3.json"
OUT = "/home/linux/.claude/jobs/374b0424/tmp/w15/results/result_W15_bin3.jsonl"

records = json.load(open(BIN))
merged = {}
for module in (d_a, d_1254, d_b, d_c):
    for address, row in module.ROWS.items():
        if address in merged:
            raise SystemExit(f"duplicate data for {address}")
        merged[address] = row

bin_addresses = [r["address"] for r in records]
extra = sorted(set(merged) - set(bin_addresses))
if extra:
    raise SystemExit(f"data for addresses not in the bin: {extra}")

lines = []
missing = []
for record in records:
    address = record["address"]
    old = record["label_in_cpp"]
    row = merged.get(address)
    if row is None:
        missing.append(address)
        continue
    if row["verdict"] == "keep":
        out = {"kind": "global", "verdict": "keep", "address": address, "old": old, "new": old, "e2m_note": row["e2m_note"]}
    elif row["verdict"] == "confirmed":
        out = {
            "kind": "global",
            "verdict": "confirmed",
            "address": address,
            "old": old,
            "new": row["new"],
            "evidence": row["evidence"],
            "code_quote": row["code_quote"],
            "comment": row["comment"],
        }
    elif row["verdict"] == "drift":
        out = {"kind": "global", "verdict": "drift", "address": address, "old": old, "evidence": row["evidence"]}
    else:
        out = {"kind": "global", "verdict": "uncertain", "address": address, "old": old, "evidence": row["evidence"]}
    lines.append(json.dumps(out, ensure_ascii=True))

with open(OUT, "w") as handle:
    handle.write("\n".join(lines) + ("\n" if lines else ""))
print(f"wrote {len(lines)} lines to {OUT}; missing {len(missing)}: {missing}")
