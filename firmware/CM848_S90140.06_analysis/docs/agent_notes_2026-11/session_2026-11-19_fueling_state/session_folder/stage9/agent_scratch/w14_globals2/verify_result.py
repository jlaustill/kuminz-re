"""Independent re-check of the written result file against the bin, the CSV and the .cpp."""
import json
import re

STAGE9 = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9"
OUT = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/output"
bin_items = json.load(open(f"{STAGE9}/bins/globals2.json"))
lines = [json.loads(l) for l in open(f"{STAGE9}/result_W14_globals2.jsonl") if l.strip()]
assert len(lines) == len(bin_items) == 63, (len(lines), len(bin_items))
csv_name = {}
for l in open(f"{OUT}/global_variables.csv", errors="replace"):
    if l.startswith("0x"):
        p = l.split(",", 3)
        csv_name[int(p[0], 16)] = p[1]
cpp = [x.strip() for x in open(f"{OUT}/cm848_rom.ghidra.cpp", errors="replace").read().split("\n")]
cppset = set(cpp)
seen = set()
counts = {}
for b, r in zip(bin_items, lines):
    assert r["address"] == b["address"], (r["address"], b["address"])
    assert r["kind"] == "global"
    assert r["old"] == b["current_name"] == csv_name[int(r["address"], 16)], r["address"]
    counts[r["verdict"]] = counts.get(r["verdict"], 0) + 1
    if r["verdict"] == "confirmed":
        assert r["new"] and r["new"] != r["old"] and r["new"] not in seen
        seen.add(r["new"])
        for key in ("evidence", "code_quote", "comment"):
            assert r.get(key), (r["address"], key)
        q = r["code_quote"]
        assert any(q in l for l in cpp), (r["address"], q)
        assert "\n" not in r["evidence"] and "\n" not in r["comment"]
        assert len(r["comment"]) <= 400, (r["address"], len(r["comment"]))
    elif r["verdict"] == "keep":
        assert r["new"] == r["old"] and r.get("e2m_note")
    print(f'{r["address"]} {r["verdict"][:4]} {r["old"]} -> {r.get("new")}' + (" [type_note]" if r.get("type_note") else "") + (" [old_comment_wrong]" if r.get("old_comment_wrong") else "") + (" [cal_note]" if r.get("cal_note") else ""))
print(counts)
