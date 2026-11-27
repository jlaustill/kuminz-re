"""List every CM550 registration through the PGN 59904 request registrar 0x2f47e and through
registerJ1939ReceiveHandler 0x21272: the pea (handler).l / move.w #pgn,-(a7) / jsr sequences
(or jsr (a2) with a2 = 0x2f47e in 0x2f538)."""
import bisect
import csv

rom = open("/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin", "rb").read()
names = {}
for row in csv.reader(open("/home/linux/.claude/jobs/374b0424/tmp/w15/r96/frozen/cm550/function_renames.csv")):
    if row and row[0].startswith("0x"):
        names[int(row[0], 16)] = row[1]
starts = sorted(names)


def owner(a):
    i = bisect.bisect_right(starts, a) - 1
    return f"{names[starts[i]]}@0x{starts[i]:x}" if i >= 0 else "?"


out = []
for i in range(0, len(rom) - 16, 2):
    w = int.from_bytes(rom[i:i + 2], "big")
    if w == 0x4879 and int.from_bytes(rom[i + 6:i + 8], "big") == 0x3f3c:
        handler = int.from_bytes(rom[i + 2:i + 6], "big")
        pgn = int.from_bytes(rom[i + 8:i + 10], "big")
        nxt = rom[i + 10:i + 16]
        if nxt == bytes.fromhex("4eb90002f47e") or (nxt[:2] == bytes.fromhex("4e92") and owner(i).endswith("0x2f538")):
            out.append((i, pgn, handler, "request registrar 0x2f47e"))
        elif nxt == bytes.fromhex("4eb900021272"):
            out.append((i, pgn, handler, "registerJ1939ReceiveHandler"))
    # clr.w -(a7) (PGN 0) form
    if w == 0x4879 and int.from_bytes(rom[i + 6:i + 8], "big") == 0x4267:
        handler = int.from_bytes(rom[i + 2:i + 6], "big")
        nxt = rom[i + 8:i + 14]
        if nxt == bytes.fromhex("4eb90002f47e"):
            out.append((i, 0, handler, "request registrar 0x2f47e"))
        elif nxt == bytes.fromhex("4eb900021272"):
            out.append((i, 0, handler, "registerJ1939ReceiveHandler"))
for i, pgn, handler, via in out:
    print(f"site 0x{i:x} in {owner(i)}: PGN {pgn} (0x{pgn:04x}) -> 0x{handler:x} {names.get(handler, '(no row)')}  [{via}]")
