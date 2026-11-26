"""Round 96: the batch apply appends 'The twin of CM848 0x000XXXXX: one shared name.' (or CM550) to a twin's plate;
when the plate already says it is the twin of that same address (e.g. the judge wrote 'Twin of CM848 0x23188 ...:
one shared name.'), the appended sentence repeats it. Remove the appended sentence in that case only.
Prints each change; --write applies. Keeps line endings. usage: dedupe_twin_notes_r96.py <repo> [--write]"""
import os
import re
import sys

repo, write = os.path.abspath(sys.argv[1]), "--write" in sys.argv
APPENDED = re.compile(r" ?The twin of (CM550|CM848) 0x([0-9a-f]{8}): one shared name\.")
total = 0
for fw in ("CM550_J90350.00_analysis", "CM848_S90140.06_analysis"):
    p = os.path.join(repo, "firmware", fw, "output", "function_renames.csv")
    t = open(p, newline="").read()
    E = "\r\n" if "\r\n" in t else "\n"
    lines = t.split(E)
    n = 0
    for k, line in enumerate(lines):
        m = APPENDED.search(line)
        if not m:
            continue
        before = line[:m.start()]
        short = "0x" + m.group(2).lstrip("0")
        said = re.search(r"\btwin of %s (?:0x0*)?%s\b" % (m.group(1), short[2:]), before, re.I)
        if said:
            lines[k] = before + line[m.end():]
            n += 1
            print(f"{fw[:5]} line {k + 1}: {line.split(',', 2)[1]}: drops the repeated twin note for {m.group(1)} {short}")
    total += n
    if write and n:
        open(p, "w", newline="").write(E.join(lines))
    print(fw[:5], n, "repeated twin notes")
print("total", total, "(written)" if write else "(dry run)")
