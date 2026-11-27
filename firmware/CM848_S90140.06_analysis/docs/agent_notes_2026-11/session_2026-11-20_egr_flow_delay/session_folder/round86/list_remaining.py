"""Write the functions that still need prototype rows: a parameter piece (param_N._x_y_) or a stack read
(in_stack_0000000N) in the body and no function_definitions.csv rows. usage: list_remaining.py <cpp> <function_definitions.csv> <out>"""
import re
import sys

text = re.sub(r"/\*.*?\*/", "", open(sys.argv[1], errors="replace").read(), flags=re.S)
parts = re.split(r"^// Function: (\S+) @ (0x[0-9a-f]+)[^\n]*\n", text, flags=re.M)
funcs = {int(parts[i + 1], 16): (parts[i], parts[i + 2]) for i in range(1, len(parts), 3)}
rows = {int(l.split(",")[0], 16) for l in open(sys.argv[2]) if l.startswith("0x")}
TOKEN = re.compile(r"\bparam_\d+\._\d+_\d+_|\bin_stack_000000(?:0[4-9a-f]|[1-9a-f][0-9a-f])\b")
out = [f"0x{a:05x} {n}" for a, (n, b) in sorted(funcs.items()) if a not in rows and TOKEN.search(b)]
open(sys.argv[3], "w").write("\n".join(out) + "\n")
print(len(out), "functions")
