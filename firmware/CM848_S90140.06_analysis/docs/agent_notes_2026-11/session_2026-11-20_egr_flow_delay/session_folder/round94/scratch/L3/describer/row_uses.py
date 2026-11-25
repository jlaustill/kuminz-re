"""For each live row inside a record (or axis table), list the functions in the frozen .cpp whose body mentions the
row's name (whole word, with or without a leading underscore) or its DAT_ address form.
usage: row_uses.py start:size [...]"""
import csv
import re
import sys

CPP = "/home/linux/.claude/jobs/374b0424/tmp/w15/r94/frozen/cm550/J90350.00.ghidra.cpp"
GV = "/home/linux/.claude/jobs/374b0424/tmp/w15/r94/frozen/cm550/global_variables.csv"
text = open(CPP, errors="replace").read()
funcs = re.split(r"^// Function: ", text, flags=re.M)[1:]
bodies = []
for f in funcs:
    head, _, body = f.partition("\n")
    bodies.append((head.strip(), body))
rows = []
with open(GV, newline="") as f:
    for r in csv.reader(f):
        if r and r[0].startswith("0x"):
            try:
                rows.append((int(r[0], 16), r[1]))
            except ValueError:
                pass
for arg in sys.argv[1:]:
    s, n = arg.split(":")
    s, n = int(s, 16), int(n, 0)
    print(f"== 0x{s:x}..0x{s + n - 1:x}")
    names = [(a, nm) for a, nm in rows if s <= a < s + n]
    for a in range(s, s + n):
        pats = [f"DAT_{a:08x}"]
        pats += [nm for aa, nm in names if aa == a and nm]
        for p in pats:
            rx = re.compile(r"(?<![A-Za-z0-9_])_?" + re.escape(p) + r"(?![A-Za-z0-9_])")
            users = [h for h, b in bodies if rx.search(b)]
            if users:
                print(f"   0x{a:x} {p}: {', '.join(users)}")
