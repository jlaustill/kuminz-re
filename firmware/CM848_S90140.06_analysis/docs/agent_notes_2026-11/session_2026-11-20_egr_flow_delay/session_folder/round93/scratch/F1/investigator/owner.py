"""Round 93 F1 (read-only): which function row (frozen function_renames.csv) contains an address.
usage: owner.py <cm550|cm848> <hex address> [...]"""
import csv
import sys

fw = sys.argv[1]
path = f"/home/linux/.claude/jobs/374b0424/tmp/w15/r93/frozen/{fw}/function_renames.csv"
rows = []
for row in csv.reader(open(path, errors="replace")):
    if not row or not row[0].startswith("0x"):
        continue
    try:
        rows.append((int(row[0], 16), row[1]))
    except ValueError:
        pass
rows.sort()
for arg in sys.argv[2:]:
    a = int(arg, 16)
    best = None
    for addr, name in rows:
        if addr <= a:
            best = (addr, name)
        else:
            break
    print(f"0x{a:x}: in 0x{best[0]:x} {best[1]}" if best else f"0x{a:x}: none")
