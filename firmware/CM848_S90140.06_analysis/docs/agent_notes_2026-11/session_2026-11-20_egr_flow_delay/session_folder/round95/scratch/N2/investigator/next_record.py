"""Read-only: address of every CM550 e2m record (base of its block from e2m_table.csv + offset) and, for each
address given, the record there and the next record above it (to size tables beyond the ROM dump).
usage: next_record.py 0xADDR [...]"""
import csv
import sys

E2M = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/e2m-analysis/originals/v64t6_s.e2m"
TABLE = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/scratch/N2/investigator/e2m_table.csv"
base = {}
for row in csv.DictReader(open(TABLE)):
    base[int(row["param_id"])] = int(row["address"])
recs = []
for line in open(E2M, errors="replace"):
    head = line.split(";")[0]
    cols = head.split(",")
    if len(cols) < 8:
        continue
    try:
        block, off = int(cols[2], 16), int(cols[3], 16)
    except ValueError:
        continue
    if block not in base or cols[5] == "G":
        continue
    desc = line.split(";", 1)[1].strip() if ";" in line else ""
    recs.append((base[block] + off, cols[0], cols[5], cols[2], cols[3], desc[:90]))
recs.sort()
for arg in sys.argv[1:]:
    a = int(arg, 16)
    here = [r for r in recs if r[0] == a]
    nxt = next((r for r in recs if r[0] > a), None)
    print(f"0x{a:x}: here {[(r[1], r[2]) for r in here]} | next 0x{nxt[0]:x} {nxt[1]} ({nxt[2]}) {nxt[3]} +{nxt[4]} -> "
          f"{(nxt[0] - a)} bytes = word[{(nxt[0] - a) // 2}] | {here[0][5] if here else ''}")
