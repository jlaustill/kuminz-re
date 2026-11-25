"""Scan the CM550 ROM for 'move.w #2,(abs).l' (33fc 0002 <addr>) into RAM: the start-up value of a lookup record's
cached offset. Print the addresses that are not one of the known 1-D records or a typed 2-D record."""
import csv
import re
import struct

rom = open("/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/"
           "firmware/J90350.00.rom.bin", "rb").read()
known1d = {0x80004a, 0x800058, 0x800102, 0x800118, 0x800126, 0x800136, 0x800144, 0x800184, 0x800192, 0x8001ea,
           0x80020e, 0x80024e, 0x80025c, 0x80026a, 0x80db20, 0x80db2e, 0x80058e, 0x80059c, 0x8005fe, 0x800632,
           0x8006aa, 0x80071e, 0x80072c, 0x80073a, 0x801a3e, 0x801a4c, 0x801c0e, 0x801c1c, 0x801c2a, 0x801c38,
           0x801e30, 0x801e3e, 0x801e4c, 0x801e5a, 0x801e68, 0x8036c6, 0x8036d4, 0x8005b4}
for k in range(25):
    known1d.add(0x80a792 + 14 * k)
rows = {}
for line in open("/home/linux/.claude/jobs/374b0424/tmp/w15/r95/frozen/cm550/global_variables.csv"):
    if line.startswith("0x"):
        p = next(csv.reader([line]))
        rows[int(p[0], 16)] = (p[1], p[2])
two_d = set()
for a, (n, t) in rows.items():
    if t.startswith("table_lookup_2d_arguments_t"):
        two_d.add(a)
        two_d.add(a + 8)  # the y axis offset word is also preset to 2
hits = {}
for m in re.finditer(re.escape(bytes.fromhex("33fc0002")), rom):
    i = m.start()
    if i % 2:
        continue
    a = struct.unpack(">I", rom[i + 4:i + 8])[0]
    if 0x800000 <= a < 0x810000:
        hits.setdefault(a, []).append(i)
for a in sorted(hits):
    if a in known1d:
        tag = "1D"
    elif a in two_d:
        tag = "2D"
    else:
        tag = "??"
    if tag == "??":
        print("0x%x %s at %s  row=%s" % (a, tag, [hex(x) for x in hits[a]], rows.get(a)))
print("known 1-D with an init store:", sorted(hex(a) for a in hits if a in known1d))
print("known 1-D without an init store:", sorted(hex(a) for a in known1d if a not in hits))
