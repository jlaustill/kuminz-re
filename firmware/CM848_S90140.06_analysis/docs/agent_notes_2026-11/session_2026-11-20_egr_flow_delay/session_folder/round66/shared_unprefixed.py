"""Every CM848 function name without a cm848_ / hpcr_ / mpc555_ prefix, with its CM550 address when CM550 has the same
name and the first words of the CM848 plate.  usage: shared_unprefixed.py <repo>"""
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])


def rows(fw):
    out = {}
    for line in open(os.path.join(repo, f"firmware/{fw}/output/function_renames.csv"), errors="replace"):
        p = line.rstrip("\n").split(",", 2)
        if p[0].startswith("0x") and len(p) > 1:
            out[p[1].strip()] = (p[0], p[2] if len(p) > 2 else "")
    return out


cm848, cm550 = rows("CM848_S90140.06_analysis"), rows("CM550_J90350.00_analysis")
names = sorted(n for n in cm848 if not re.match(r"(cm848|hpcr|mpc555)_", n))
for n in names:
    a, plate = cm848[n]
    other = cm550.get(n, ("-", ""))[0]
    print(f"{a} {n:55} CM550 {other:11} | {plate[:70]}")
print(len(names), "unprefixed;", sum(1 for n in names if n not in cm550), "not in CM550")
