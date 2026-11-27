"""For every proposed record, the frozen row at its dumped y pointer (and x pointer): name, type, and whether the
type's word count matches the dump's byte count word. usage: python3 existing_values.py"""
import csv
import json
import re
import struct

J = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/scratch/N2/judge/"
F = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/frozen/cm550/"
REPO = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay"
ram = open(REPO + "/firmware/CM550_J90350.00_analysis/firmware/J90350.00.ram.bin", "rb").read()
xram = open(REPO + "/firmware/CM550_J90350.00_analysis/firmware/J90350.00.extended_ram.bin", "rb").read()


def w(a):
    if 0x800000 <= a < 0x8091c2:
        return struct.unpack(">H", ram[a - 0x800000:a - 0x7ffffe])[0]
    if a >= 0x8092c2:
        return struct.unpack(">H", xram[a - 0x809242:a - 0x809240])[0]
    return None


def l(a):
    return (w(a) << 16) | w(a + 2)


rows = {}
for r in csv.reader(open(F + "global_variables.csv")):
    if r and r[0].startswith("0x"):
        rows[int(r[0], 16)] = (r[1], r[2])
props = json.load(open(J + "proposals_globals.json"))
proposed_at = {int(e["address"], 16): e["proposed_name"] for e in props}
for e in props:
    if e["proposed_type"] != "table_lookup_1d_arguments_t":
        continue
    a = int(e["address"], 16)
    for off, role in ((2, "x"), (8, "y")):
        p = l(a + off)
        if p in proposed_at:
            continue
        row = rows.get(p)
        cnt = w(p) if p >= 0x800000 else None
        m = re.match(r"word\[(\d+)\]", row[1]) if row else None
        ok = (m and cnt is not None and int(m.group(1)) == cnt // 2 + 1)
        print(f"{e['proposed_name']} {role} 0x{p:x}: existing row {row} dump count {cnt} {'OK' if ok else ('ROM (no dump)' if cnt is None else 'MISMATCH')}  cited-in-comment={row[0] in e['comment'] if row else None}")
