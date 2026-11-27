"""For each proposed CM550 global (address, name, size in bytes): print the current row at that address and any other
row that lies inside [address, address + size), and say whether the proposed name already exists in the CSV."""
import csv
import sys

CSV = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/frozen/cm550/global_variables.csv"
rows = []
with open(CSV, newline="", errors="replace") as f:
    for r in csv.reader(f):
        if not r or not r[0].startswith("0x"):
            continue
        try:
            rows.append((int(r[0], 16), r[1], r[2] if len(r) > 2 else ""))
        except ValueError:
            pass
names = {r[1] for r in rows}

PROPOSALS = [l.split() for l in open(sys.argv[1]) if l.strip() and not l.startswith("#")]
for addr_s, name, size_s in PROPOSALS:
    a, size = int(addr_s, 16), int(size_s)
    here = [r for r in rows if r[0] == a]
    inside = [r for r in rows if a < r[0] < a + size and "[" not in r[1]]
    dup = name in names and not any(r[1] == name for r in here)
    print(f"0x{a:06x} {name:58s} size {size:4d} | current: {here[0][1] + ' (' + here[0][2] + ')' if here else '(no row)'}"
          + (f" | INSIDE: {', '.join(f'0x{r[0]:06x} {r[1]}' for r in inside)}" if inside else "")
          + (" | NAME EXISTS ELSEWHERE" if dup else ""))
