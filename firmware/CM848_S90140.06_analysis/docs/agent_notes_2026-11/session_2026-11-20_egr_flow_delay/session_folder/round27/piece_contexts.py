"""Round 27 stage B: where the flat layout's word pieces (<inst>._<2w>_2_) sit: set / clear writes
(x._N_2_ = x._N_2_ & / | K), other writes, single-bit tests that did not fold into a name, multi-bit tests, and
other reads. Code only.
usage: piece_contexts.py <cpp>"""
import re
import sys
from collections import Counter

t = open(sys.argv[1], errors="replace").read()
t = re.sub(r"/\*.*?\*/", "", t, flags=re.S)
t = "\n".join(l for l in t.split("\n") if not l.lstrip().startswith("//"))
flat = re.sub(r"\s+", " ", t)
P = r"fault_(?:detected|registered|previous_pass)_cal\._\d+_2_"
c = Counter()
for m in re.finditer(r"(" + P + r") = \1 ([&|]) (0x[0-9a-f]+|\d+)", flat):
    v = int(m.group(3), 0)
    bits = bin(v if m.group(2) == "|" else 0xffff ^ v).count("1")
    c["set/clear write, one bit" if bits == 1 else "set/clear write, several bits"] += 2
rest = re.sub(r"(" + P + r") = \1 [&|] (?:0x[0-9a-f]+|\d+)", "", flat)
for m in re.finditer(P + r"( = | & (0x[0-9a-f]+|\d+)|)", rest):
    if m.group(1) == " = ":
        c["other write"] += 1
    elif m.group(2):
        c["single-bit test" if bin(int(m.group(2), 0)).count("1") == 1 else "multi-bit test"] += 1
    else:
        c["other read (whole word)"] += 1
for k, v in c.most_common():
    print(f"{v:5} {k}")
print(f"{sum(c.values()):5} total")
