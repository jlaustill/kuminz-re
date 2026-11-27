"""Brute-force search (every even offset, no disassembly sync) for 68k control transfers into an address range:
Bcc / BRA / BSR with an 8-bit, 16-bit or 32-bit displacement, JSR / JMP abs.w / abs.l, and JSR / JMP (d16,PC).
Reports each candidate with its own address, so the caller can check whether it sits in real code.
usage: entries_into.py <rom.bin> <start hex> <end hex (exclusive)> [<start> <end> ...]"""
import struct
import sys

rom = open(sys.argv[1], "rb").read()
ranges = [(int(sys.argv[i], 16), int(sys.argv[i + 1], 16)) for i in range(2, len(sys.argv), 2)]


def word(offset):
    return struct.unpack_from(">H", rom, offset)[0]


def inside(target):
    for start, end in ranges:
        if start <= target < end:
            return (start, end)
    return None


for pc in range(0, len(rom) - 6, 2):
    op = word(pc)
    found = []
    if op & 0xF000 == 0x6000:
        displacement = op & 0xFF
        if displacement == 0:
            d = struct.unpack_from(">h", rom, pc + 2)[0]
            found.append(("b16", pc + 2 + d))
        elif displacement == 0xFF:
            d = struct.unpack_from(">i", rom, pc + 2)[0]
            found.append(("b32", pc + 2 + d))
        else:
            d = displacement - 256 if displacement & 0x80 else displacement
            found.append(("b8", pc + 2 + d))
    if op in (0x4EB9, 0x4EF9):
        found.append(("abs.l", struct.unpack_from(">I", rom, pc + 2)[0]))
    if op in (0x4EB8, 0x4EF8):
        found.append(("abs.w", struct.unpack_from(">h", rom, pc + 2)[0] & 0xFFFFFFFF))
    if op in (0x4EBA, 0x4EFA):
        found.append(("pc16", pc + 2 + struct.unpack_from(">h", rom, pc + 2)[0]))
    for kind, target in found:
        hit = inside(target)
        if hit:
            print(f"{pc:#07x} {op:04x} {kind} -> {target:#07x} (range {hit[0]:#x}-{hit[1]:#x})")
