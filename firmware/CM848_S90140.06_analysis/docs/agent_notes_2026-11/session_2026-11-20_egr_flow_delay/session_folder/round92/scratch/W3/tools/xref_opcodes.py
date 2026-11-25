"""List every absolute 32-bit reference to an address range in the CM550 ROM, with the opcode word(s) before it,
to tell data loads (move/and/btst/tst) from address loads (lea/pea/movea #imm/move.l #imm).
usage: xref_opcodes.py <rom> <first address hex> <last address hex>"""
import re
import sys

rom = open(sys.argv[1], 'rb').read()
first, last = int(sys.argv[2], 16), int(sys.argv[3], 16)
ADDRESS_LOADS = {0x41f9: 'lea a0', 0x43f9: 'lea a1', 0x45f9: 'lea a2', 0x47f9: 'lea a3', 0x49f9: 'lea a4',
                 0x4bf9: 'lea a5', 0x4df9: 'lea a6', 0x4879: 'pea', 0x207c: 'movea.l #,a0', 0x227c: 'movea.l #,a1',
                 0x247c: 'movea.l #,a2', 0x267c: 'movea.l #,a3', 0x287c: 'movea.l #,a4', 0x2a7c: 'movea.l #,a5',
                 0x2c7c: 'movea.l #,a6', 0x2f3c: 'move.l #,-(sp)', 0x203c: 'move.l #,d0', 0x223c: 'move.l #,d1',
                 0x243c: 'move.l #,d2', 0x263c: 'move.l #,d3', 0x283c: 'move.l #,d4', 0x2a3c: 'move.l #,d5'}
for a in range(first, last + 1):
    pat = a.to_bytes(4, 'big')
    for m in re.finditer(re.escape(pat), rom):
        h = m.start()
        op = int.from_bytes(rom[h - 2:h], 'big')
        op4 = int.from_bytes(rom[h - 4:h - 2], 'big')
        kind = ADDRESS_LOADS.get(op, '')
        print(f"0x{a:06x} at 0x{h:05x}: op-2=0x{op:04x} op-4=0x{op4:04x} {kind}")
