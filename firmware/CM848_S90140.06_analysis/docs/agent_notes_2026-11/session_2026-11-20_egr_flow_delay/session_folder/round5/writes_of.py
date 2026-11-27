"""The globals (and fields) a function writes, with counts, and the functions it calls - a quick profile for naming.
usage: writes_of.py <cpp> <function>..."""
import collections
import re
import sys

cpp = open(sys.argv[1], errors="replace").read()
chunks = {m.group(1): c for c in re.split(r"(?m)^(?=// Function: )", cpp)
          for m in [re.match(r"// Function: (\S+)", c)] if m}
for name in sys.argv[2:]:
    body = chunks.get(name, "")
    code = "\n".join(l for l in body.split("\n") if not l.strip().startswith(("//", "/*", "*")))
    writes = collections.Counter(m.group(1) for m in re.finditer(r"^\s*([a-z_][A-Za-z0-9_.]*)\s*=[^=]", code, re.M)
                                 if not re.match(r"^[a-z]Var\d+$|^[a-z]Stack|^local_|^param_", m.group(1)))
    calls = collections.Counter(m.group(1) for m in re.finditer(r"\b((?:cm848|mpc555|hpcr)_[A-Za-z0-9_]+|[a-z]+[A-Z][A-Za-z0-9_]*)\(", code)
                                if m.group(1) != name)
    states = sorted(set(re.findall(r"FUELING_STATE_[A-Z0-9_]+", code)))
    print(f"== {name} ({len(code.splitlines())} lines)\n  writes: {', '.join(f'{w}x{n}' if n > 1 else w for w, n in writes.most_common(30))}")
    print(f"  calls: {', '.join(c for c, n in calls.most_common(15))}")
    if states:
        print(f"  states: {', '.join(states)}")
