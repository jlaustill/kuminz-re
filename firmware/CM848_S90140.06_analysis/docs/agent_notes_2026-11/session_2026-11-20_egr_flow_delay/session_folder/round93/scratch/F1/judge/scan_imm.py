"""Judge F1: independent raw scan of the CM550 ROM for word immediates N stored or compared anywhere:
  33fc 00NN aaaaaaaa   move.w #N,(abs).l
  3?bc 00NN            move.w #N,(An)          (0x30bc 0x32bc ... 0x3ebc: dest mode 010)
  3?7c 00NN dddd       move.w #N,(d16,An)      (0x317c ... dest mode 101)
  0c79 00NN aaaaaaaa   cmpi.w #N,(abs).l
  0c5? 00NN            cmpi.w #N,(An)
  0c6? 00NN dddd       cmpi.w #N,(d16,An)
  0c4? 00NN            cmpi.w #N,Dn
  7?NN                 moveq #N,Dn   (listed only; the use must be read)
usage: scan_imm.py N [N ...]   (decimal)"""
import struct
import sys

ROM = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"
rom = open(ROM, "rb").read()
END = 0x40000


def w(o):
    return struct.unpack(">H", rom[o:o + 2])[0]


def l(o):
    return struct.unpack(">I", rom[o:o + 4])[0]


for arg in sys.argv[1:]:
    n = int(arg)
    print(f"===== {n} (0x{n:x})")
    for o in range(0, END - 8, 2):
        op, imm = w(o), w(o + 2)
        if imm != n:
            if (op & 0xf100) == 0x7000 and (op & 0xff) == n and n < 128:
                print(f"  0x{o:05x}: moveq #{n},d{(op >> 9) & 7}   next: {rom[o + 2:o + 10].hex(' ')}")
            continue
        if op == 0x33fc:
            print(f"  0x{o:05x}: move.w #{n},(0x{l(o + 4):x}).l")
        elif (op & 0xf1ff) == 0x30bc:
            print(f"  0x{o:05x}: move.w #{n},(a{(op >> 9) & 7})")
        elif (op & 0xf1ff) == 0x317c:
            print(f"  0x{o:05x}: move.w #{n},(0x{w(o + 4):x},a{(op >> 9) & 7})")
        elif (op & 0xf1ff) == 0x303c:
            print(f"  0x{o:05x}: move.w #{n},d{(op >> 9) & 7}   next: {rom[o + 4:o + 12].hex(' ')}")
        elif op == 0x0c79:
            print(f"  0x{o:05x}: cmpi.w #{n},(0x{l(o + 4):x}).l")
        elif (op & 0xfff8) == 0x0c50:
            print(f"  0x{o:05x}: cmpi.w #{n},(a{op & 7})")
        elif (op & 0xfff8) == 0x0c68:
            print(f"  0x{o:05x}: cmpi.w #{n},(0x{w(o + 4):x},a{op & 7})")
        elif (op & 0xfff8) == 0x0c40:
            print(f"  0x{o:05x}: cmpi.w #{n},d{op & 7}")
        if (op & 0xf100) == 0x7000 and (op & 0xff) == n and n < 128:
            print(f"  0x{o:05x}: moveq #{n},d{(op >> 9) & 7}   next: {rom[o + 2:o + 10].hex(' ')}")
