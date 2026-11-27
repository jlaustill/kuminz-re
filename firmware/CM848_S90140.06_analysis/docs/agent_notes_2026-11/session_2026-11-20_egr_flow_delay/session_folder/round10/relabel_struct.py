"""Proof helper for a new struct over old labels: in the new .cpp, replace each `<instance>.<field>` with the label
the field's address had before (and a bare `&<instance>` with the first field's old label), so the result can be
compared with the old .cpp by the usual proofs. usage: relabel_struct.py <new.cpp> <out.cpp> <instance> <map.txt>
map.txt: '<field> <old label>' per line."""
import re
import sys

new_path, out_path, instance, map_path = sys.argv[1:5]
pairs = [l.split() for l in open(map_path) if l.strip()]
text = open(new_path).read()
counts = {}
for field, old in pairs:
    pattern = re.compile(r"(?<![A-Za-z0-9_])" + re.escape(instance) + r"\." + re.escape(field) + r"(?![A-Za-z0-9_])")
    text, n = pattern.subn(old, text)
    counts[field] = n
first_old = pairs[0][1]
text, bare = re.subn(r"&" + re.escape(instance) + r"(?![A-Za-z0-9_.])", "&" + first_old, text)
open(out_path, "w").write(text)
left = len(re.findall(r"(?<![A-Za-z0-9_])" + re.escape(instance) + r"(?![A-Za-z0-9_])", text))
print("replaced:", counts, "| bare &instance:", bare, "| left:", left)
