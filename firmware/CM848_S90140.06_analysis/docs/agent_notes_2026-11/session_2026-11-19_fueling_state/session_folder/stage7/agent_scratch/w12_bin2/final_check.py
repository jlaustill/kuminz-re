"""Independent check of the result file: JSON shape, the apply_extras stage 2 assertions, address coverage."""
import json
import re

OUTFILE = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/result_W12_bin2.jsonl"
BIN = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/bins/bin2.json"
GV = ("/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/output/"
      "global_variables.csv")

rows = [json.loads(line) for line in open(OUTFILE)]
bin_items = json.load(open(BIN))
assert len(rows) == len(bin_items) == 67
assert [r["address"] for r in rows] == [b["address"] for b in bin_items], "order / address mismatch"
gv_lines = open(GV).read().split("\n")
addresses = {int(line.split(",")[0], 16) for line in gv_lines if line.startswith("0x")}
names = {line.split(",")[1] for line in gv_lines if line.startswith("0x") and len(line.split(",")) > 1}
keys = {"kind", "verdict", "address", "new", "type", "evidence", "comment"}
seen = set()
counts = {}
for r in rows:
    assert set(r) == keys, (r["address"], set(r) ^ keys)
    assert r["kind"] == "new_global"
    counts[r["verdict"]] = counts.get(r["verdict"], 0) + 1
    a = int(r["address"], 16)
    assert a not in addresses, f"{r['address']} already has a global_variables.csv row"
    assert "\n" not in r["evidence"] and "\n" not in r["comment"]
    assert r["evidence"] and r["comment"]
    assert re.fullmatch(r"(byte|word|dword|i8|i16|i32|word\[\d+\]|byte\[\d+\])", r["type"]), r["type"]
    if r["verdict"] == "rejected":
        assert r["new"] == ""
        continue
    assert r["new"] not in names, r["new"]
    assert r["new"] not in seen, r["new"]
    seen.add(r["new"])
    assert "{" not in r["evidence"] + r["comment"], "unformatted placeholder"
print("ok", len(rows), counts, "names", len(seen))
for t in ("word", "dword", "i16"):
    print(t, sum(1 for r in rows if r["type"] == t and r["verdict"] != "rejected"))
print("cal names:", [r["new"] for r in rows if r["new"].endswith("_cal")])
