"""Find every mtspr to SPRG0-3 (SPR 272-275) in the CM848 ROM / live flash2 and show, for each, the nearest earlier
mfspr into the same register (which SPR's value is being saved).  usage: find_sprg_writers.py <originals dir>"""
import os
import sys

SPR = {1: "XER", 8: "LR", 9: "CTR", 18: "DSISR", 19: "DAR", 22: "DEC", 26: "SRR0", 27: "SRR1", 80: "EIE", 81: "EID",
       82: "NRI", 272: "SPRG0", 273: "SPRG1", 274: "SPRG2", 275: "SPRG3", 287: "PVR", 1022: "ECR?"}


def spr_of(w):
    return ((w >> 16) & 0x1F) | (((w >> 11) & 0x1F) << 5)


d = sys.argv[1]
for name, base in (("cm848_rom.bin", 0), ("cm848_flash2_live.bin", 0x500000)):
    data = open(os.path.join(d, name), "rb").read()
    words = [int.from_bytes(data[i:i + 4], "big") for i in range(0, len(data) - 3, 4)]
    for k, w in enumerate(words):
        if w >> 26 == 31 and (w >> 1) & 0x3FF == 467 and 272 <= spr_of(w) <= 275:
            rs = (w >> 21) & 31
            source = "?"
            for j in range(k - 1, max(-1, k - 12), -1):
                p = words[j]
                if p >> 26 == 31 and (p >> 1) & 0x3FF == 339 and (p >> 21) & 31 == rs:
                    source = SPR.get(spr_of(p), str(spr_of(p)))
                    break
                if (p >> 21) & 31 == rs and p >> 26 in (14, 15, 32, 34, 40, 42, 24, 31):
                    source = f"other ({p:08x})"
                    break
            print(f"{name} {base + 4 * k:#08x}: mtspr {SPR[spr_of(w)]}, r{rs}   <- {source}")
