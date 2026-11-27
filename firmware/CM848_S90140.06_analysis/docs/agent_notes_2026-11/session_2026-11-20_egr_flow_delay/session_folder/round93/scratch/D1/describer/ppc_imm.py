"""Describer D1 scratch: scan the CM848 images for a 16-bit value used as an immediate (addi / li, ori, cmplwi, cmpwi)
and as an aligned data word (with context bytes).
usage: ppc_imm.py 0xVALUE [...]"""
import sys

FW = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals"
IMAGES = [("rom", 0x0, open(f"{FW}/cm848_rom.bin", "rb").read()),
          ("flash2", 0x500000, open(f"{FW}/cm848_flash2_live.bin", "rb").read())]
NAMES = {14: "addi/li", 24: "ori", 10: "cmplwi", 11: "cmpwi", 12: "addic", 13: "addic."}

for arg in sys.argv[1:]:
    value = int(arg, 16) & 0xffff
    print(f"== 0x{value:04x}")
    pat = value.to_bytes(2, "big")
    for label, base, img in IMAGES:
        for i in range(0, len(img) - 4, 4):
            w = int.from_bytes(img[i:i + 4], "big")
            if (w & 0xffff) == value and (w >> 26) in NAMES:
                print(f"  code {label} 0x{base + i:06x}: {NAMES[w >> 26]} {w:08x}")
        count = 0
        for i in range(0, len(img) - 2, 2):
            if img[i:i + 2] == pat:
                count += 1
                if count <= 30:
                    print(f"  word {label} 0x{base + i:06x}: {img[max(0, i - 6):i].hex()} [{pat.hex()}] {img[i + 2:i + 10].hex()}")
        print(f"  {label}: {count} aligned words")
