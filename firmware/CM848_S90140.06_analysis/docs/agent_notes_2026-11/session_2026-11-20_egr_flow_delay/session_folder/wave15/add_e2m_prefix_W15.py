"""Repair for 10b: apply_hand_worklist.py looked the e2m records up from the wrong directory (a relative repo path),
so the hand-renamed globals got no leading e2m record. For every global row of the given maps whose address has an
e2m record (the ECU's parameter table) and whose comment does not start with "e2m ", prepend
"e2m <block> +<offset> <record> '<description>' (<unit>): ". Comments do not render in the .cpp.
usage: add_e2m_prefix_W15.py <repo> <map.csv>..."""
import csv
import os
import re
import subprocess
import sys

repo = os.path.abspath(sys.argv[1])
fw = os.path.join(repo, "firmware")
path = os.path.join(fw, "CM848_S90140.06_analysis", "output", "global_variables.csv")
lines = open(path, newline="").read().split("\n")
index = {l.split(",", 1)[0]: i for i, l in enumerate(lines) if l.startswith("0x")}
fixed = skipped = 0
for mapping in sys.argv[2:]:
    for r in csv.DictReader(open(mapping)):
        if r["kind"] != "global":
            continue
        address = f"0x{int(r['address'], 16):08x}"
        out = subprocess.run([sys.executable, os.path.join(fw, "scripts", "e2m_block_addresses.py"), "--address", address],
                             capture_output=True, text=True, cwd=fw).stdout.strip().split("\n")[0]
        m = re.match(r"(\S+) \+(\S+) (\S+) \[([^\]]*)\] -> .*?; ?(.*)", out)
        a, name, typ, comment = (lines[index[address]].split(",", 3) + [""])[:4]
        if not m or comment.startswith("e2m "):
            skipped += 1
            continue
        block, offset, record, unit, description = m.groups()
        description = re.sub(r"^\[[A-Z0-9]+\] ?", "", description).strip().rstrip(".").replace(",", ";")
        prefix = f"e2m {block} +{offset.lstrip('0') or '0'} {record} '{description}' ({unit}): "
        lines[index[address]] = ",".join([a, name, typ, prefix + comment])
        fixed += 1
open(path, "w", newline="").write("\n".join(lines))
print(f"e2m prefix added to {fixed} rows; {skipped} without a record or already led by one")
