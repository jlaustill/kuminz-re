"""Every call / pointer to CM550 addresses: absolute 4-byte big-endian occurrences (with the 2 opcode bytes before),
bsr/bra .s/.w/.l and pc-relative lea/pea/jsr/jmp d16(pc).
usage: callers.py <addr hex> [...]"""
import struct
import sys

rom = open('/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin', 'rb').read()


def find_calls(target):
    res = []
    pat = target.to_bytes(4, 'big')
    i = rom.find(pat)
    while i != -1:
        res.append(('abs', hex(i - 2), rom[i - 2:i].hex()))
        i = rom.find(pat, i + 1)
    for pc in range(0, len(rom) - 4, 2):
        w = struct.unpack_from('>H', rom, pc)[0]
        if w in (0x6100, 0x6000, 0x4eba, 0x4efa, 0x41fa, 0x43fa, 0x45fa, 0x47fa, 0x49fa, 0x4bfa, 0x4dfa, 0x4ffa, 0x487a):
            d = struct.unpack_from('>h', rom, pc + 2)[0]
            if pc + 2 + d == target:
                res.append(('pcrel16', hex(pc), hex(w)))
        elif (w & 0xf000) == 0x6000 and (w & 0xff) not in (0, 0xff):
            d = w & 0xff
            if d >= 0x80:
                d -= 0x100
            if pc + 2 + d == target:
                res.append(('b?.s', hex(pc), hex(w)))
        elif (w & 0xf0ff) == 0x60ff:
            d = struct.unpack_from('>i', rom, pc + 2)[0]
            if pc + 2 + d == target:
                res.append(('pcrel32', hex(pc), hex(w)))
    return res


for a in sys.argv[1:]:
    t = int(a, 16)
    print(hex(t), find_calls(t))
