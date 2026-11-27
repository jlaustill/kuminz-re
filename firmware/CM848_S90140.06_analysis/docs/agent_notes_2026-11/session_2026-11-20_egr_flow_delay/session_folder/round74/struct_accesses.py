"""List every distinct access to the j1708_transmit_buffer_2_32_ddc6 struct instance in the CM550 .cpp, with its absolute
address and width: whole fields, byte-array elements ([n]) and pieces (._N_M_ = M bytes at N inside the field).
usage: struct_accesses.py <structure_definitions.csv> <J90350.00.ghidra.cpp> <global_variables.csv>"""
import collections
import csv
import re
import sys

BASE = 0x80ddc6
off, fields = 0, {}
for r in csv.reader(open(sys.argv[1], newline="")):
    if r and r[0] == "j1708_multipacket_msg_t" and r[1] == "" and r[2]:
        size = int(r[4])
        fields[r[2]] = (off, r[3], size)
        off += size
cpp = open(sys.argv[2], errors="replace").read()
acc = collections.Counter()
PAT = re.compile(r"j1708_transmit_buffer_2_32_ddc6\.([a-z_0-9]+)(\[(0x[0-9a-f]+|\d+)\])?(\._(\d+)_(\d+)_)?")
for m in PAT.finditer(cpp):
    name = m.group(1)
    if name not in fields:
        continue
    o, typ, size = fields[name]
    elem = int(m.group(3), 0) if m.group(3) else None
    if m.group(4):  # a piece
        a = BASE + o + (elem or 0) + int(m.group(5))
        w = int(m.group(6))
        kind = "piece"
    elif elem is not None:
        a, w, kind = BASE + o + elem, 1, "element"
    else:
        a, w, kind = BASE + o, size, "field"
    acc[(a, w, kind, m.group(0))] += 1
rows = {}
for r in csv.reader(open(sys.argv[3])):
    if r and r[0].startswith("0x"):
        rows[int(r[0], 16)] = r[1]
for (a, w, kind, text), n in sorted(acc.items()):
    print(f"+{a - BASE:3d} {a:#x} w{w} {kind:7s} x{n:3d}  {text:50s} row: {rows.get(a, '')[:50]}")
