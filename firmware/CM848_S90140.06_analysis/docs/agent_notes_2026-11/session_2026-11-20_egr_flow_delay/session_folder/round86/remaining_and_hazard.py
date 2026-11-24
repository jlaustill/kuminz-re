"""Two closing checks for the stack parameter layout.
1. The functions still to do: a parameter piece (param_N._x_y_) or a stack read (in_stack_0000000N) and no
   function_definitions.csv rows, from the current .cpp.
2. The storage hazard: a local_variables.csv row that retypes a PARAMETER of a function with rows would resize its custom
   storage (HighFunctionDBUtil.updateDBVariable). List rows whose old name is param_N or one of that function's
   parameter names.  usage: remaining_and_hazard.py <cpp> <function_definitions.csv> <local_variables.csv>"""
import collections
import re
import sys

text = re.sub(r"/\*.*?\*/", "", open(sys.argv[1], errors="replace").read(), flags=re.S)
parts = re.split(r"^// Function: (\S+) @ (0x[0-9a-f]+)[^\n]*\n", text, flags=re.M)
funcs = {int(parts[i + 1], 16): (parts[i], parts[i + 2]) for i in range(1, len(parts), 3)}
params = collections.defaultdict(set)
for line in open(sys.argv[2], newline=""):
    p = line.rstrip("\r\n").split(",")
    if p[0].startswith("0x") and len(p) > 3 and p[2] != "return":
        params[int(p[0], 16)].add(p[3])
TOKEN = re.compile(r"\bparam_\d+\._\d+_\d+_|\bin_stack_000000(?:0[4-9a-f]|[1-9a-f][0-9a-f])\b")
left = [(a, n, len(TOKEN.findall(b))) for a, (n, b) in sorted(funcs.items()) if a not in params and TOKEN.search(b)]
print(f"1. {len(left)} functions with no rows still show a parameter piece or a stack read "
      f"({sum(c for *_, c in left)} tokens)")
for a, n, c in left[:12]:
    print(f"   0x{a:05x} {n}: {c}")
hazards = []
for line in open(sys.argv[3], newline=""):
    p = line.rstrip("\r\n").split(",")
    if p[0].startswith("0x") and len(p) > 2:
        a = int(p[0], 16)
        if a in params and (re.fullmatch(r"param_\d+", p[2]) or p[2] in params[a]):
            hazards.append(line.strip()[:140])
print(f"2. {len(hazards)} local_variables.csv rows retype a parameter of a function with rows")
for h in hazards:
    print("  ", h)
