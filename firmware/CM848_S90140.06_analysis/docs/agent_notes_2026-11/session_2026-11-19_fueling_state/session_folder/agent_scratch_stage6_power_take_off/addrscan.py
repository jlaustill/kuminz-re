"""Scan all.dis for every instruction that touches a data address, with register-value tracking.
Forms handled: lis+d(rN) load/store, lis+addi/ori address construction (reported as 'addr-of'), and the
constructed register used as 0(rB) / d(rB) afterwards.  Reports mnemonic, instruction address and the containing function.
usage: addrscan.py <0xADDR>...        (data addresses; one per arg)"""
import bisect
import re
import sys

DIS = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/all.dis"
CPP = "/tmp/pto_research/snap.cpp"

funcs = []
for line in open(CPP, errors="replace"):
    m = re.match(r"^// Function: (\S+) @ 0x([0-9a-fA-F]+)", line)
    if m:
        funcs.append((int(m.group(2), 16), m.group(1)))
funcs.sort()
starts = [a for a, _ in funcs]


def owner(addr):
    i = bisect.bisect_right(starts, addr) - 1
    return funcs[i][1] if i >= 0 else "?"


INS = re.compile(r"^\s*([0-9a-f]+):\s+(?:[0-9a-f]{2} ){4}\s*(\S+)\s*(\S*)")
MEM = re.compile(r"^r(\d+),(-?\d+)\(r(\d+)\)$")
LOADS = {"lbz", "lbzu", "lhz", "lhzu", "lha", "lhau", "lwz", "lwzu"}
STORES = {"stb", "stbu", "sth", "sthu", "stw", "stwu"}
targets = {int(a, 16): a for a in sys.argv[1:]}
parsed = []
for line in open(DIS, errors="replace"):
    m = INS.match(line)
    if m:
        parsed.append((int(m.group(1), 16), m.group(2), m.group(3)))
vals = {}       # reg -> (value, last_index)
hits = {a: [] for a in targets}
for idx, (addr, op, args) in enumerate(parsed):
    ops = args.split(",") if args else []
    # expire stale register values (window of 60 instructions)
    for r in [r for r, (v, i) in vals.items() if idx - i > 60]:
        del vals[r]
    if op in ("blr", "bctr", "b", "bl", "bctrl", "blrl"):
        if op in ("blr", "bctr", "b"):
            vals.clear()
        continue
    mm = MEM.match(args) if args else None
    if op in LOADS | STORES and mm:
        rd, disp, ra = int(mm.group(1)), int(mm.group(2)), int(mm.group(3))
        if ra in vals:
            ea = vals[ra][0] + disp
            if ea in targets:
                hits[ea].append((addr, op, "disp"))
        if op in LOADS and rd in vals and rd != ra:
            del vals[rd]
        elif op in LOADS and rd == ra:
            vals.pop(rd, None)
        continue
    if op == "lis" and len(ops) == 2:
        try:
            vals[int(ops[0][1:])] = ((int(ops[1], 0) & 0xFFFF) << 16, idx)
        except ValueError:
            pass
        continue
    if op in ("addi", "addic") and len(ops) == 3 and ops[0].startswith("r") and ops[1].startswith("r"):
        rd, ra = int(ops[0][1:]), int(ops[1][1:])
        try:
            imm = int(ops[2], 0)
        except ValueError:
            continue
        if ra in vals:
            v = vals[ra][0] + imm
            vals[rd] = (v, idx)
            if v in targets:
                hits[v].append((addr, "addr-of(addi)", ""))
        else:
            vals.pop(rd, None)
        continue
    if op == "ori" and len(ops) == 3 and ops[0].startswith("r") and ops[1].startswith("r"):
        rd, ra = int(ops[0][1:]), int(ops[1][1:])
        try:
            imm = int(ops[2], 0)
        except ValueError:
            continue
        if ra in vals:
            v = vals[ra][0] | imm
            vals[rd] = (v, idx)
            if v in targets:
                hits[v].append((addr, "addr-of(ori)", ""))
        else:
            vals.pop(rd, None)
        continue
    # any other instruction overwrites its first-operand register
    if ops and ops[0].startswith("r") and ops[0][1:].isdigit() and op not in ("cmpw", "cmpwi", "cmplw", "cmplwi", "mtctr", "mtlr", "mtspr"):
        vals.pop(int(ops[0][1:]), None)
for a, label in targets.items():
    print(f"== {label}: {len(hits[a])} hits")
    for addr, op, kind in hits[a]:
        print(f"   0x{addr:x} {op:14s} {kind:5s} in {owner(addr)}")
