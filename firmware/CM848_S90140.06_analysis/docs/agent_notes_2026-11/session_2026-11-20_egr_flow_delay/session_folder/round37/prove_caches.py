"""Round 37: prove the lookup cache naming. Both .cpp files go to one canonical form and every function body is
compared (whitespace and comments dropped):
- old: 1-D &DAT_a / DAT_a -> &NAME / NAME; 2-D &DAT_a -> @NAME, DAT_a -> NAME[0], DAT_(a+2) -> NAME[1]
  (0x3fd134's old name the same way);
- new: a 2-D NAME used bare (an array argument) -> @NAME, &NAME[0] -> @NAME.
Also counts pieces of the new names.  usage: prove_caches.py <old cpp> <new cpp> <map.csv>"""
import csv
import re
import sys

old_t, new_t = open(sys.argv[1], errors="replace").read(), open(sys.argv[2], errors="replace").read()
rows = list(csv.DictReader(open(sys.argv[3])))


def bodies(t):
    parts = re.split(r"^// Function: (\S+) @[^\n]*\n", t, flags=re.M)
    out = {}
    for i in range(1, len(parts), 2):
        b = re.sub(r"/\*.*?\*/", "", parts[i + 1], flags=re.S)
        out[parts[i]] = re.sub(r"\s+", "", b)
    return out


old_b, new_b = bodies(old_t), bodies(new_t)
subs_old, two_d = [], []
for r in rows:
    a, name, old = int(r["address"], 16), r["name"], r["old_label"]
    if r["dims"] == "2":
        two_d.append(name)
        subs_old += [(rf"&{re.escape(old)}\b", f"@{name}"), (rf"(?<![\w.]){re.escape(old)}\b", f"{name}[0]")]
        subs_old.append((rf"(?<![\w.])DAT_{a + 2:08x}\b", f"{name}[1]"))
    else:
        subs_old += [(rf"(?<![\w.]){re.escape(old)}\b", name)]
diff = []
pieces = 0
for f, ob in old_b.items():
    nb = new_b.get(f)
    if nb is None:
        diff.append((f, "missing"))
        continue
    for pat, rep in subs_old:
        ob = re.sub(pat, rep, ob)
    for name in two_d:
        nb = re.sub(rf"&{re.escape(name)}\[0\]", f"@{name}", nb)
        nb = re.sub(rf"(?<![\w.&@]){re.escape(name)}(?!\[|\w)", f"@{name}", nb)
    for r in rows:
        pieces += len(re.findall(rf"{re.escape(r['name'])}\._\d+_\d+_", nb))
    if ob != nb:
        diff.append((f, ob, nb))
print(f"functions {len(old_b)}; differing after canonicalization: {len(diff)}; pieces of new names: {pieces}")
for d in diff[:12]:
    if len(d) == 2:
        print("==", d[0], d[1])
        continue
    f, ob, nb = d
    i = next((k for k in range(min(len(ob), len(nb))) if ob[k] != nb[k]), min(len(ob), len(nb)))
    print("==", f, "\n   old ..." + ob[max(0, i - 90):i + 110] + "\n   new ..." + nb[max(0, i - 90):i + 110])
