"""Classify the functions a build changed: ones with function_definitions.csv rows, callers of those, and the rest
(unexpected). usage: classify_changes.py <function_set_check output> <post cpp> <function_definitions.csv>"""
import re
import sys

changed = [l.split()[0] for l in open(sys.argv[1]) if re.match(r"^  0x[0-9a-f]+ ", l)]
text = re.sub(r"/\*.*?\*/", "", open(sys.argv[2], errors="replace").read(), flags=re.S)
parts = re.split(r"^// Function: (\S+) @ (0x[0-9a-f]+)[^\n]*\n", text, flags=re.M)
by_address = {parts[i + 1]: (parts[i], parts[i + 2]) for i in range(1, len(parts), 3)}
rows = {l.split(",")[0].lower() for l in open(sys.argv[3]) if l.startswith("0x")}
row_names = {by_address[a][0] for a in by_address if a in rows}
own, callers, other = [], [], []
for address in changed:
    name, body = by_address[address]
    if address in rows:
        own.append(name)
    elif any(re.search(rf"\b{re.escape(n)}\s*\(", body) for n in row_names if n != name):
        callers.append(name)
    else:
        other.append(f"{address} {name}")
print(f"{len(changed)} changed: {len(own)} with rows, {len(callers)} callers of a function with rows, {len(other)} other")
for o in other:
    print("  OTHER:", o)
