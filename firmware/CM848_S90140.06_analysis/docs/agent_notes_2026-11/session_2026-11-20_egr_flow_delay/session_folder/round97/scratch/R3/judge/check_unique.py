"""For each proposal: does the name already exist in CM550's global_variables.csv / function_renames.csv
(at another address), or among the other proposals? Also print the current row at the address.
usage: check_unique.py <proposals.txt>"""
import csv
import sys

F = "/home/linux/.claude/jobs/374b0424/tmp/w15/r97/frozen/cm550/"
gv = list(csv.reader(open(F + "global_variables.csv")))[1:]
fr = list(csv.reader(open(F + "function_renames.csv")))[1:]
by_name = {}
for r in gv:
    by_name.setdefault(r[1], []).append(r[0])
fnames = {r[1]: r[0] for r in fr if len(r) > 1}
props = [line.split() for line in open(sys.argv[1]) if line.strip()]
seen = {}
for addr, name, typ in props:
    a = int(addr, 16)
    cur = [r for r in gv if int(r[0], 16) == a]
    clash = [x for x in by_name.get(name, []) if int(x, 16) != a]
    msg = []
    if clash:
        msg.append("GLOBAL CLASH " + ",".join(clash))
    if name in fnames:
        msg.append("FUNCTION CLASH " + fnames[name])
    if name in seen:
        msg.append("PROPOSAL CLASH " + seen[name])
    seen[name] = addr
    curtxt = (cur[0][1] + ":" + cur[0][2]) if cur else "(no row)"
    print(f"{addr} {name:82s} cur={curtxt} {' '.join(msg)}")
