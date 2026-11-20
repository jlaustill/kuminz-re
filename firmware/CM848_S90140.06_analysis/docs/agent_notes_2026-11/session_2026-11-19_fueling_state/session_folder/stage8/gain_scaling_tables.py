"""For the scaled branch of cm848_calculateFuelMeteringCommand's gain copy: the lookup table (axis / values) whose result
multiplies each working gain field, and the e2m block each table resolves to.
usage: gain_scaling_tables.py <.cpp> <repo>"""
import re
import subprocess
import sys

cpp, repo = sys.argv[1:3]
text = open(cpp, errors="replace").read()
start = text.index("// Function: cm848_calculateFuelMeteringCommand @")
body = text[start:text.index("// Function:", start + 10)]
body = body[:body.index("else {", body.index("working_proportional_gains.small_signal_gain ="))]
LOOKUP = re.compile(r"lookupTableInterpolation\s*\(\s*&?[A-Za-z_0-9]+\s*,\s*[A-Za-z_0-9]+\s*,\s*([A-Za-z_0-9]+)\s*,\s*"
                    r"([A-Za-z_0-9]+)\s*,")
STORE = re.compile(r"(working_[a-z]+_gains\.[a-z_]+)(?:\._[0-9]_[0-9]_)?\s*=|(awStack_68\[0\])\s*=")
events = sorted([(m.start(), "lookup", m.group(1), m.group(2)) for m in LOOKUP.finditer(body)] +
                [(m.start(), "store", m.group(1) or m.group(2), None) for m in STORE.finditer(body)])
names = {}
for line in open(f"{repo}/firmware/CM848_S90140.06_analysis/output/global_variables.csv", errors="replace"):
    if line.startswith("0x"):
        names[line.split(",")[1]] = line.split(",")[0]
last, seen = None, set()
for _, kind, a, b in events:
    if kind == "lookup":
        last = (a, b)
    elif last and a not in seen:
        seen.add(a)
        blocks = []
        for table in last:
            out = subprocess.run([sys.executable, f"{repo}/firmware/scripts/e2m_block_addresses.py", "--address",
                                  names.get(table, "0x0")], capture_output=True, text=True).stdout.split("\n")[0]
            blocks.append(" ".join(out.split()[:3]))
        print(f"{a}: {last[0]} / {last[1]} | {' | '.join(blocks)}")
