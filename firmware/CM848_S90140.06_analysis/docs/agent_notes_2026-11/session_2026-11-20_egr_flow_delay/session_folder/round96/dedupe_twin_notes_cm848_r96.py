"""Round 96: in a CM848 plate whose text already names its CM550 twin address, drop the repeat inside the history note
('; the twin of CM550 0x<addr>: one shared name' before the closing parenthesis). Keeps line endings.
usage: dedupe_twin_notes_cm848_r96.py <repo>"""
import os
import re
import sys

p = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output/function_renames.csv")
t = open(p, newline="").read()
E = "\r\n" if "\r\n" in t else "\n"
lines = t.split(E)
n = 0
REPEAT = re.compile(r"; the twin of CM550 0x([0-9a-f]+): one shared name(?=\))")
for k, line in enumerate(lines):
    for m in reversed(list(REPEAT.finditer(line))):
        before = line[:m.start()]
        if re.search(r"\btwin of CM550 (?:0x)?0*%s\b" % m.group(1).lstrip("0"), before, re.I):
            line = before + line[m.end():]
            n += 1
            print(k + 1, line.split(",", 2)[1], "0x" + m.group(1))
    lines[k] = line
open(p, "w", newline="").write(E.join(lines))
print(n, "repeats removed")
