"""How many times each name appears (whole word) in CM550's output CSVs and .cpp.  usage: cm550_names.py <repo> <name>..."""
import os
import re
import sys

repo, names = os.path.abspath(sys.argv[1]), sys.argv[2:]
O5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
text = "".join(open(os.path.join(O5, n), errors="replace").read() for n in os.listdir(O5) if n.endswith((".csv", ".cpp")))
for name in names:
    print(f"{name}: {len(re.findall(rf'\b{re.escape(name)}\b', text))}")
