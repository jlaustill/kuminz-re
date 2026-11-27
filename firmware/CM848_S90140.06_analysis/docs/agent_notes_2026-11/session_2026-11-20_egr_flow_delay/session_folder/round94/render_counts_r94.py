"""Round 94 (read-only): how often each name renders in a .cpp, plain and with Ghidra's leading underscore (the access
is wider than the row's type). usage: render_counts_r94.py <cpp> <name>..."""
import re
import sys

cpp = open(sys.argv[1], errors="replace").read()
for n in sys.argv[2:]:
    plain = len(re.findall(rf"(?<![A-Za-z0-9_]){re.escape(n)}(?![A-Za-z0-9_])", cpp))
    under = len(re.findall(rf"(?<![A-Za-z0-9_])_{re.escape(n)}(?![A-Za-z0-9_])", cpp))
    print(f"{n}: {plain} plain, {under} underscore")
