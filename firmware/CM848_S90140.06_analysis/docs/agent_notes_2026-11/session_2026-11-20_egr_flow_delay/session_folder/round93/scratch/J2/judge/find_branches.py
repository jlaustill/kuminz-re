"""find_branches.py <rom> <target hex> [...]: list bsr.w / bra.w / jsr abs.l / jmp abs.l / pea abs.l / bsr.l sites that reach a target."""
import struct
import sys

rom = open(sys.argv[1], 'rb').read()
for t in sys.argv[2:]:
    target = int(t, 16)
    hits = []
    for pc in range(0, len(rom) - 6, 2):
        op = struct.unpack('>H', rom[pc:pc + 2])[0]
        if op in (0x6100, 0x6000):  # bsr.w / bra.w
            disp = struct.unpack('>h', rom[pc + 2:pc + 4])[0]
            if pc + 2 + disp == target:
                hits.append((pc, 'bsr.w' if op == 0x6100 else 'bra.w'))
        elif op in (0x61ff, 0x60ff):  # bsr.l / bra.l (CPU32)
            disp = struct.unpack('>i', rom[pc + 2:pc + 6])[0]
            if pc + 2 + disp == target:
                hits.append((pc, 'bsr.l' if op == 0x61ff else 'bra.l'))
        elif op in (0x4eb9, 0x4ef9, 0x4879):  # jsr abs.l / jmp abs.l / pea abs.l
            a = struct.unpack('>I', rom[pc + 2:pc + 6])[0]
            if a == target:
                hits.append((pc, {0x4eb9: 'jsr', 0x4ef9: 'jmp', 0x4879: 'pea'}[op]))
        elif (op & 0xff00) == 0x6100 and (op & 0xff) not in (0, 0xff):  # bsr.s
            disp = op & 0xff
            if disp >= 0x80:
                disp -= 0x100
            if pc + 2 + disp == target:
                hits.append((pc, 'bsr.s'))
    # raw 4-byte occurrences
    raw = []
    needle = struct.pack('>I', target)
    i = rom.find(needle)
    while i != -1:
        raw.append(i)
        i = rom.find(needle, i + 1)
    print(f"0x{target:x}: {len(hits)} branch sites: {', '.join(f'{k}@0x{p:x}' for p, k in hits)}")
    print(f"   raw 4-byte occurrences: {', '.join(f'0x{r:x}' for r in raw)}")
