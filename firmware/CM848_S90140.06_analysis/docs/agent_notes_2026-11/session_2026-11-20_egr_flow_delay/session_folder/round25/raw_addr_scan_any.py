"""Raw scan of the ROM and flash2 images for PowerPC D-form instructions (loads, stores, addi) whose 16-bit
displacement lands in an address range when the base is lis 0x41 (0x410000 + signed displacement), plus any 32-bit
pointer to the range. Prints each candidate whose nearest preceding lis of the base register (within 8 instructions) has that
high half (round 22 fix: it used to accept any lis in the window).
usage: raw_addr_scan.py <rom.bin> <flash2.bin> <first hex> <last hex> [--permissive]"""
import sys

rom_path, flash_path, first, last = sys.argv[1], sys.argv[2], int(sys.argv[3], 16), int(sys.argv[4], 16)
# --permissive: the round 19 rule (any lis of the base register in the window). It over-reports, but it cannot
# miss an access whose base comes from two paths with different lis values, so use it for "no access" claims;
# the default (the nearest lis decides) is for counting real accesses.
PERMISSIVE = "--permissive" in sys.argv
DFORM = {14: "addi", 32: "lwz", 34: "lbz", 36: "stw", 38: "stb", 40: "lhz", 42: "lha", 44: "sth", 33: "lwzu", 35: "lbzu",
         41: "lhzu", 43: "lhau", 45: "sthu", 37: "stwu", 39: "stbu"}
hits = 0
for path, base_addr in ((rom_path, 0), (flash_path, 0x500000)):
    d = open(path, "rb").read()
    words = [int.from_bytes(d[i:i + 4], "big") for i in range(0, len(d) - 3, 4)]
    for k, w in enumerate(words):
        if (first <= w <= last):
            print(f"pointer @ {base_addr + 4 * k:#x}: {w:#x}")
            hits += 1
        op = w >> 26
        if op not in DFORM:
            continue
        disp = w & 0xffff
        disp = disp - 0x10000 if disp & 0x8000 else disp
        ra = (w >> 16) & 31
        for hi in sorted({(first + 0x8000) >> 16, (last + 0x8000) >> 16, 0x41, 0x40}):
            target = (hi << 16) + disp
            if first <= target <= last:
                # the NEAREST lis of the base register decides (round 22: an older lis r12,0x40 matched although
                # lis r12,0x41 overwrote r12 in between - a false hit at 0x51f884)
                for j in range(k - 1, max(-1, k - 9), -1):
                    p = words[j]
                    # lis rD,v = addis rD,0,v: rD in bits 21-25, rA (bits 16-20) = 0
                    if p >> 26 == 15 and ((p >> 21) & 31) == ra and ((p >> 16) & 31) == 0:
                        if (p & 0xffff) == hi:
                            print(f"{DFORM[op]} @ {base_addr + 4 * k:#x} -> {target:#x}")
                            hits += 1
                            break
                        if not PERMISSIVE:
                            break
print("hits", hits)
