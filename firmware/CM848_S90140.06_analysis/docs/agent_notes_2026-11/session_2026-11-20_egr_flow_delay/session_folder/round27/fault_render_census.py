"""Round 27 stage B: how the fault words render before and after the bitfields (code only, comments stripped).
Old: per word, constant-mask tests ('<inst>.faults_A_to_B & K'), writes ('<inst>.faults_A_to_B ='), indexed bases.
New: named bitfield accesses (reads 'x.<bit> ==/!= ' and writes 'x.<bit> = '), pieces ('<inst>._<2w>_2_' and any
other '_N_M_' piece of the three instances), placeholders ('field_0x').
usage: fault_render_census.py <old cpp> <new cpp> <fault_fields.tsv> [words...]"""
import re
import sys
from collections import Counter

old_cpp, new_cpp, tsv = sys.argv[1:4]
want = {int(w) for w in sys.argv[4:]} or set(range(50))
INST = r"fault_(?:detected|registered|previous_pass)_cal"
fields = {}
for line in open(tsv):
    fault, word, bit, field, comment = line.rstrip("\n").split("\t")
    fields[field] = int(word)


def code(path):
    t = open(path, errors="replace").read()
    t = re.sub(r"/\*.*?\*/", "", t, flags=re.S)
    return "\n".join(l for l in t.split("\n") if not l.lstrip().startswith("//"))


old, new = code(old_cpp), code(new_cpp)
o = Counter()
for m in re.finditer(INST + r"\.faults_(\d+)_to_\d+( & (?:0x[0-9a-f]+|\d+)| =(?!=))?", old):
    w = int(m.group(1)) // 16
    if w in want:
        o[(w, "test" if m.group(2) and "&" in m.group(2) else "write" if m.group(2) else "other")] += 1
o_indexed = len(re.findall(r"\(&" + INST + r"\.faults_0_to_15\)", old))
n = Counter()
for m in re.finditer(INST + r"\.([a-z][a-z0-9_]*)( [=!]= | = )?", new):
    f = m.group(1)
    if f in fields and fields[f] in want:
        n[(fields[f], "read" if m.group(2) and "==" in m.group(2) or (m.group(2) or "").strip() == "!=" else
           "write" if m.group(2) == " = " else "other")] += 1
pieces = Counter()
for m in re.finditer(INST + r"\._(\d+)_(\d+)_", new):
    w = int(m.group(1)) // 2
    pieces[w] += 1
placeholders = len(re.findall(INST + r"\.field_0x[0-9a-f]+", new))
n_indexed = len(re.findall(r"\(&" + INST + r"\.faults_0_to_15\)", new))
tot = lambda c, k: sum(v for (w, kind), v in c.items() if kind == k)
print(f"old: tests {tot(o, 'test')} writes {tot(o, 'write')} other {tot(o, 'other')}; indexed bases {o_indexed}")
print(f"new: named reads {tot(n, 'read')} writes {tot(n, 'write')} other {tot(n, 'other')}; pieces "
      f"{sum(v for w, v in pieces.items() if w in want)} (all words {sum(pieces.values())}); placeholders "
      f"{placeholders}; indexed bases {n_indexed}")
worst = sorted(((v, w) for w, v in pieces.items()), reverse=True)[:8]
print("most pieces by word:", ", ".join(f"word {w}: {v}" for v, w in worst))
