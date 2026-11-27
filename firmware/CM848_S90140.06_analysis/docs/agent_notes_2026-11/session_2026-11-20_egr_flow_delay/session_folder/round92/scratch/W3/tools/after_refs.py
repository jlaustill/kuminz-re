"""For each absolute reference to an address in the CM550 ROM, print the opcode before it and the next instruction
words after it, decoding the common mask tests (andi.w #imm,Dn / btst #imm,Dn / and.w #imm / move.w + ext).
usage: after_refs.py <rom> <address hex>..."""
import re
import sys

rom = open(sys.argv[1], 'rb').read()


def word(o):
    return int.from_bytes(rom[o:o + 2], 'big')


for a in sys.argv[2:]:
    addr = int(a, 16)
    for m in re.finditer(re.escape(addr.to_bytes(4, 'big')), rom):
        h = m.start()
        op = word(h - 2)
        nxt = [word(h + 4 + 2 * i) for i in range(4)]
        dec = ''
        if (nxt[0] & 0xfff8) == 0x0240:
            dec = f'andi.w #0x{nxt[1]:04x},d{nxt[0] & 7}'
        elif (nxt[0] & 0xfff8) == 0x0800:
            dec = f'btst #{nxt[1]},d{nxt[0] & 7} (mask 0x{1 << (nxt[1] & 31):04x})'
        elif (nxt[0] & 0xf1f8) == 0xc078 or (nxt[0] & 0xf1ff) == 0xc07c:
            dec = f'and.w #0x{nxt[1]:04x}'
        print(f"0x{addr:06x} @0x{h - 2:05x} op=0x{op:04x} next={' '.join('%04x' % x for x in nxt)} {dec}")
