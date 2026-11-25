"""Every PowerPC I-form branch (b / bl / ba / bla) and B-form conditional branch whose target is the given address,
and every aligned 4-byte value equal to it, in the CM848 images.
usage: ppc_reach.py <0xADDR>..."""
import sys

BASE = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals/"
IMAGES = ((BASE + "cm848_rom.bin", 0), (BASE + "cm848_flash2_live.bin", 0x500000))
for arg in sys.argv[1:]:
    target = int(arg, 16)
    print(f"== 0x{target:x}")
    for path, base in IMAGES:
        data = open(path, "rb").read()
        for i in range(0, len(data) - 3, 4):
            word = int.from_bytes(data[i:i + 4], "big")
            address = base + i
            opcode = word >> 26
            if opcode == 18:
                offset = word & 0x03FFFFFC
                if offset & 0x02000000:
                    offset -= 0x04000000
                absolute = (word >> 1) & 1
                destination = offset if absolute else address + offset
                if destination == target:
                    print(f"  I-form branch at 0x{address:x} (word {word:08x})")
            elif opcode == 16:
                offset = word & 0xFFFC
                if offset & 0x8000:
                    offset -= 0x10000
                absolute = (word >> 1) & 1
                destination = offset if absolute else address + offset
                if destination == target:
                    print(f"  B-form branch at 0x{address:x} (word {word:08x})")
            if word == target:
                print(f"  4-byte value at 0x{address:x}")
        # also halfword pairs: lis rX,hi / addi or ori rX,lo building the address
        hi = (target >> 16) & 0xFFFF
        lo = target & 0xFFFF
        for i in range(0, len(data) - 7, 4):
            w1 = int.from_bytes(data[i:i + 4], "big")
            if (w1 >> 26) == 15 and ((w1 >> 16) & 0x1F) == 0:
                imm_hi = w1 & 0xFFFF
                for j in range(i + 4, min(i + 24, len(data) - 3), 4):
                    w2 = int.from_bytes(data[j:j + 4], "big")
                    op2 = w2 >> 26
                    if op2 == 14 and ((w2 >> 16) & 0x1F) == ((w1 >> 21) & 0x1F):
                        value = ((imm_hi << 16) + (w2 & 0xFFFF if w2 & 0x8000 == 0 else (w2 & 0xFFFF) - 0x10000)) & 0xFFFFFFFF
                        if value == target:
                            print(f"  lis/addi pair at 0x{base + i:x}")
                    if op2 == 24 and ((w2 >> 21) & 0x1F) == ((w1 >> 21) & 0x1F):
                        value = (imm_hi << 16) | (w2 & 0xFFFF)
                        if value == target:
                            print(f"  lis/ori pair at 0x{base + i:x}")
