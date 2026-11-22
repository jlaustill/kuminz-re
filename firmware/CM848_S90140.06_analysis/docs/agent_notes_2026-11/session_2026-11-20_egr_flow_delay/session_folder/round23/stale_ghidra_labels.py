"""Round 23 stage C: comments in the CSVs that still name a word by a Ghidra label (DAT_ / WORD_ / DWORD_ / BYTE_ /
PTR_<x>_ / WORD_ARRAY_ / <type>_ + address) although the address now has a named row - the stale-name sweeps skip these
labels by design (round 23: the plate of cm848_calculateAmbientAndCompressorInletConditions said DAT_0040a1a6, named
barometric_altitude_source in round 19). Only exact address matches are replaced; '(was <label>)' notes are kept.
usage: stale_ghidra_labels.py <repo> [--apply]"""
import collections
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
apply = "--apply" in sys.argv
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
names = {}
for l in open(os.path.join(out, "global_variables.csv")):
    if l.startswith("0x"):
        a, n = l.split(",", 2)[:2]
        if n:
            names[int(a, 16)] = n
LABEL = re.compile(r"\b(?:DAT|WORD|DWORD|BYTE|WORD_ARRAY|DWORD_ARRAY|BYTE_ARRAY|PTR_[A-Za-z0-9_]+?|[a-z_0-9]+_t)_00([0-9a-f]{6})\b")
total = collections.Counter()
for name in ("global_variables.csv", "function_renames.csv", "structure_definitions.csv", "enums.csv", "arrays.csv"):
    p = os.path.join(out, name)
    if not os.path.exists(p):
        continue
    text = open(p).read()

    def repl(m):
        a = int(m.group(1), 16)
        if a in names:
            before = text[max(0, m.start() - 5):m.start()]
            if before.endswith("(was "):
                return m.group(0)
            total[name] += 1
            print(f"{name}: {m.group(0)} -> {names[a]}")
            return names[a]
        return m.group(0)

    new = LABEL.sub(repl, text)
    if apply and new != text:
        open(p, "w").write(new)
print(dict(total))
