"""Describer D1 scratch: list every ROM site that touches a fault status word with an immediate mask.
Finds (a) ori.w / andi.w / btst #imm,(abs).l on the word and (b) move.w (abs).l,d0 followed by andi.w #mask,d0.
usage: fault_bit_users.py 0xADDR [mask hex]"""
import sys

ROM = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"
rom = open(ROM, "rb").read()
addr = int(sys.argv[1], 16)
want = int(sys.argv[2], 16) if len(sys.argv) > 2 else None
pat = addr.to_bytes(4, "big")
i = rom.find(pat)
while i != -1:
    if i % 2 == 0:
        w4 = int.from_bytes(rom[i - 4:i - 2], "big")
        imm = int.from_bytes(rom[i - 2:i], "big")
        w2 = int.from_bytes(rom[i - 2:i], "big")
        desc = None
        if w4 == 0x0079:
            desc = f"ori.w #0x{imm:04x},(abs).l (SET)"
            m = imm
        elif w4 == 0x0279:
            desc = f"andi.w #0x{imm:04x},(abs).l (CLEAR 0x{(~imm) & 0xffff:04x})"
            m = (~imm) & 0xffff
        elif (w2 & 0xf1ff) == 0x3039:  # move.w (abs).l,dN
            nxt = int.from_bytes(rom[i + 4:i + 6], "big")
            if (nxt & 0xfff8) == 0x0240:  # andi.w #imm,dN
                m = int.from_bytes(rom[i + 6:i + 8], "big")
                desc = f"move.w (abs).l,d{(w2 >> 9) & 7}; andi.w #0x{m:04x} (TEST)"
            elif (nxt & 0xfff8) == 0x0280:  # andi.l #imm,dN
                m = int.from_bytes(rom[i + 6:i + 10], "big")
                desc = f"move.w (abs).l,d{(w2 >> 9) & 7}; andi.l #0x{m:x} (TEST)"
            else:
                m = None
                desc = f"move.w (abs).l,d{(w2 >> 9) & 7}; next word {nxt:04x}"
        else:
            m = None
            desc = f"other: prev words {rom[i - 6:i].hex(' ')}"
        if want is None or m is None or (m & want):
            print(f"  0x{i - 2:05x}: {desc}")
    i = rom.find(pat, i + 1)
