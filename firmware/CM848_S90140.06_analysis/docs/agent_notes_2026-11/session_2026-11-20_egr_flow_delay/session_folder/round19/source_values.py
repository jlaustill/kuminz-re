"""For each source word, list the literal values the .cpp stores into it or compares it with, and its other uses
(copies, arithmetic). usage: source_values.py <cpp> <name>..."""
import re
import sys

cpp = open(sys.argv[1]).read()
for name in sys.argv[2:]:
    lits, other = set(), []
    for m in re.finditer(rf"(?<![A-Za-z0-9_.]){re.escape(name)}(?![A-Za-z0-9_])\s*(==|!=|<=|>=|<|>|=)\s*([^;,)]+)", cpp):
        op, rhs = m.group(1), m.group(2).strip()
        if re.fullmatch(r"-?(0x[0-9a-fA-F]+|\d+)", rhs):
            lits.add(f"{op}{int(rhs, 0)}")
        else:
            other.append(f"{op} {rhs[:40]}")
    for m in re.finditer(rf"(==|!=|<=|>=|<|>)\s*{re.escape(name)}(?![A-Za-z0-9_])", cpp):
        other.append(f"(rhs of {m.group(1)})")
    refs = len(re.findall(rf"(?<![A-Za-z0-9_]){re.escape(name)}(?![A-Za-z0-9_])", cpp))
    print(f"{name}: {refs} refs; literals {sorted(lits)}; other {sorted(set(other))[:6]}")
