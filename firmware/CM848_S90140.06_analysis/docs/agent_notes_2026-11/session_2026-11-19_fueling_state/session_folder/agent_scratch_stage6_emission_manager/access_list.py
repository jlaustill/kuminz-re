"""Read-only scratch helper: list every load / store instruction (address + mnemonic) that reaches each given data address,
following `lis rN,hi` + displacement and `lis rN,hi; addi rN,rN,lo` + 0(rN) forms.
usage: access_list.py <all.dis> <0xaddress>..."""
import re
import sys

lines = open(sys.argv[1]).read().split("\n")
INS = re.compile(r"^\s*([0-9a-f]+):\s+(?:[0-9a-f]{2} ){4}\s*(\S+)\s+(\S+)")
MEM = re.compile(r"^r(\d+),(-?\d+)\(r(\d+)\)$")
W = {"lbz": 1, "lbzu": 1, "stb": 1, "stbu": 1, "lhz": 2, "lhzu": 2, "lha": 2, "lhau": 2, "sth": 2, "sthu": 2,
     "lwz": 4, "lwzu": 4, "stw": 4, "stwu": 4}
targets = {int(a, 16) for a in sys.argv[2:]}
parsed = [INS.match(line) for line in lines]
hits = {t: [] for t in targets}
for i, m in enumerate(parsed):
    if not m or m.group(2) not in W:
        continue
    mm = MEM.match(m.group(3))
    if not mm:
        continue
    disp, base = int(mm.group(2)), mm.group(3)
    for j in range(i - 1, max(i - 40, -1), -1):
        p = parsed[j]
        if p and p.group(2) == "lis" and p.group(3).startswith(f"r{base},"):
            a = (int(p.group(3).split(",")[1]) << 16) + disp
            if a in hits:
                hits[a].append((int(m.group(1), 16), m.group(2)))
            break
        if p and p.group(2) == "addi" and p.group(3).startswith(f"r{base},r{base},"):
            lo = int(p.group(3).split(",")[2])
            for k in range(j - 1, max(j - 6, -1), -1):
                q = parsed[k]
                if q and q.group(2) == "lis" and q.group(3).startswith(f"r{base},"):
                    a = (int(q.group(3).split(",")[1]) << 16) + lo + disp
                    if a in hits:
                        hits[a].append((int(m.group(1), 16), m.group(2) + "(addi)"))
                    break
            break
        if p and re.match(rf"^r{base},", p.group(3)) and p.group(2) not in ("cmpw", "cmpwi", "cmplw", "cmplwi"):
            break
for t in sorted(hits):
    print(hex(t), [(hex(a), op) for a, op in hits[t]])
