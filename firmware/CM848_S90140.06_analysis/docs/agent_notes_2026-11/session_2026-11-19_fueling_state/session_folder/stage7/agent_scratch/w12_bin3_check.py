import json
import re
import collections

BASE = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/"
OUT = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/output/"
res = [json.loads(line) for line in open(BASE + "result_W12_bin3.jsonl")]
binr = json.load(open(BASE + "bins/bin3.json"))
print(len(res), len(binr))
assert [r["address"] for r in res] == [b["address"] for b in binr]
keys = {"kind", "verdict", "address", "new", "type", "evidence", "comment"}
for r in res:
    assert set(r) == keys, r
    assert r["verdict"] in ("confirmed", "uncertain", "rejected")
    assert r["type"] in ("byte", "word", "dword", "i16"), r["type"]
    assert "\n" not in r["evidence"]
print(collections.Counter(r["verdict"] for r in res))

csvnames = set()
for line in open(OUT + "global_variables.csv", errors="replace"):
    parts = line.split(",", 3)
    if len(parts) > 1:
        csvnames.add(parts[1])
cpp = open(OUT + "cm848_rom.ghidra.cpp", errors="replace").read()
names = [r["new"] for r in res if r["new"]]
print(len(names), len(set(names)))
for n in names:
    if n in csvnames or re.search(r"\b" + re.escape(n) + r"\b", cpp):
        print("COLLISION", n)

for r, b in zip(res, binr):
    size = int(b["size_bytes"])
    expected = {1: "byte", 2: "word", 4: "dword"}[size]
    if r["type"] == "i16":
        if not (b["signed"] == "S" and size == 2):
            print("I16 on a record that is not signed 2 byte", r["address"])
    elif r["type"] != expected:
        print("TYPE MISMATCH", r["address"], r["type"], expected)
for r, b in zip(res, binr):
    if b["signed"] == "S":
        print("signed record", b["address"], b["record"], r["type"])
    a = int(b["address"], 16)
    mirror = 0x3FD482 <= a <= 0x3FEEC1
    if r["new"]:
        if mirror and not r["new"].endswith("_cal"):
            print("MISSING _cal", r["address"], r["new"])
        if (not mirror) and r["new"].endswith("_cal"):
            print("UNEXPECTED _cal", r["address"], r["new"])
print("cal rule checked on", len(res), "records")

short = ["cnt", "ctr", "tmptr", "temp", "thd", "cmd", "amb", "ref", "avg", "frac", "adj", "lmt", "lim", "sw", "stat",
         "val", "pos", "filt", "diag", "ovr", "vlv", "pct", "cyl", "max", "min", "inj", "veh", "baro", "alt", "trq",
         "batt", "imt", "ct", "aps", "accel", "decel", "cot", "mcf", "cmf", "vgt", "pto", "cc", "eb", "jcomm", "el",
         "lsg", "hsg", "asg", "vsg", "aecd", "init", "hp", "pr", "rat", "rs", "bt", "tpe", "epf", "hpcr", "fs", "hw"]
for n in names:
    for token in n.split("_"):
        if token in short:
            print("ABBREV?", n, token)
for r in res:
    if r["new"] and ("protection" in r["new"].split("_")) and r["new"].split("_").count("protection") > 0:
        print("PROTECTION word:", r["new"])
print("max name length", max(len(n) for n in names))

# word-order permutation sweep: same multiset of tokens as an existing CSV name
by_tokens = collections.defaultdict(list)
for existing in csvnames:
    by_tokens[tuple(sorted(existing.split("_")))].append(existing)
for n in names:
    key = tuple(sorted(n.split("_")))
    if key in by_tokens:
        print("PERMUTATION of existing name:", n, by_tokens[key])
# near-permutation: every token of the new name appears in an existing name of the same length +-1 and vice versa
new_sets = {n: set(n.split("_")) for n in names}
for existing in csvnames:
    es = set(existing.split("_"))
    if len(es) < 5:
        continue
    for n, ns in new_sets.items():
        if es == ns:
            print("TOKEN SET equal:", n, existing)
        elif len(ns ^ es) <= 1 and len(es) >= 5:
            print("near token set:", n, existing)
