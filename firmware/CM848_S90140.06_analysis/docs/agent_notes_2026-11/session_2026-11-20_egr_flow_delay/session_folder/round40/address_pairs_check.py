"""Round 40 stage B proof for cm848_sciLookupEepromSettingAddress: each statement the typed local changed swaps a raw
address for a symbol. Pair the -/+ lines of statement_diff.py's output and check the symbol's address (the global's
row address + the field's offset from structure_definitions.csv, fields laid out in file order) equals the raw
constant.  usage: address_pairs_check.py <repo> <sci_diff.txt>"""
import os
import re
import sys

repo, diff = os.path.abspath(sys.argv[1]), sys.argv[2]
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
glob = {}
for l in open(os.path.join(out, "global_variables.csv"), errors="replace"):
    p = l.split(",", 3)
    if len(p) >= 3 and p[0].startswith("0x"):
        glob.setdefault(p[1], (int(p[0], 16), p[2]))
SIZE = {"byte": 1, "word": 2, "dword": 4, "i16": 2}
fields = {}
for l in open(os.path.join(out, "structure_definitions.csv"), errors="replace"):
    p = l.split(",")
    if len(p) > 4 and p[0] == "end_of_line_test_settings_t" and p[2]:
        off = sum(SIZE[t] for _, t in fields.get(p[0], []))
        fields.setdefault(p[0], []).append((p[2], p[3]))
offsets = {}
o = 0
for name, t in fields["end_of_line_test_settings_t"]:
    offsets[name] = o
    o += SIZE[t]
lines = [l.rstrip("\n") for l in open(diff)]
minus = [l for l in lines if l.startswith("-") and "return" not in l]
plus = [l for l in lines if l.startswith("+") and "return" not in l]
ok = bad = 0
for m, p in zip(minus, plus):
    old = int(re.findall(r"0x[0-9a-f]+", m)[-1], 16)
    f = re.search(r"&end_of_line_test_settings_cal\.(\w+)", p)
    if f:
        new = glob["end_of_line_test_settings_cal"][0] + offsets[f.group(1)]
    else:
        g = re.search(r"&(\w+) \+ (\d+)\)", p)
        new = glob[g.group(1)][0] + int(g.group(2))
    good = new == old
    ok += good
    bad += not good
    print(("ok  " if good else "BAD ") + f"{old:#x} = {p[1:].split('= ', 1)[1]}")
print(f"{ok} pairs match, {bad} do not")
