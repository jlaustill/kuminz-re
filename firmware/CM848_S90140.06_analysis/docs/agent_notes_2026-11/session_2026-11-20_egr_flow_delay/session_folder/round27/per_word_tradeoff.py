"""Round 27 stage B: per fault word (1-49) in the flat layout: e2m-named bits, named accesses (bit names that are not
fault_<n> / fault_<n> names), and piece tokens. Code only.
usage: per_word_tradeoff.py <flat cpp> <fault_fields.tsv>"""
import re
import sys
from collections import Counter

cpp, tsv = sys.argv[1:3]
t = open(cpp, errors="replace").read()
t = re.sub(r"/\*.*?\*/", "", t, flags=re.S)
t = "\n".join(l for l in t.split("\n") if not l.lstrip().startswith("//"))
word_of, e2m_named = {}, Counter()
for line in open(tsv):
    fault, word, bit, field, comment = line.rstrip("\n").split("\t")
    word_of[field] = int(word)
    if not re.fullmatch(r"fault_\d+", field):
        e2m_named[int(word)] += 1
named, numbered, pieces = Counter(), Counter(), Counter()
for m in re.finditer(r"fault_(?:detected|registered|previous_pass)_cal\.([a-z][a-z0-9_]*)", t):
    f = m.group(1)
    if f in word_of:
        (numbered if re.fullmatch(r"fault_\d+", f) else named)[word_of[f]] += 1
for m in re.finditer(r"fault_(?:detected|registered|previous_pass)_cal\._(\d+)_2_", t):
    pieces[int(m.group(1)) // 2] += 1
print("word  e2m-named-bits  named  fault_<n>  pieces")
tot = Counter()
for w in range(1, 50):
    print(f"{w:4} {e2m_named[w]:6} {named[w]:12} {numbered[w]:9} {pieces[w]:7}")
    key = "with e2m names" if e2m_named[w] else "without e2m names"
    tot[(key, "named")] += named[w]
    tot[(key, "numbered")] += numbered[w]
    tot[(key, "pieces")] += pieces[w]
    tot[(key, "words")] += 1
for key in ("with e2m names", "without e2m names"):
    print(f"{key}: {tot[(key, 'words')]} words, named {tot[(key, 'named')]}, fault_<n> {tot[(key, 'numbered')]}, "
          f"pieces {tot[(key, 'pieces')]}")
