import sys, capstone
rom = open(sys.argv[1], 'rb').read()
lo = int(sys.argv[2], 16); hi = int(sys.argv[3], 16)   # inclusive range of 32-bit values to look for
md = capstone.Cs(capstone.CS_ARCH_M68K, capstone.CS_MODE_BIG_ENDIAN | capstone.CS_MODE_M68K_040)
for off in range(0, len(rom) - 3):
    v = int.from_bytes(rom[off:off+4], 'big')
    if lo <= v <= hi:
        # try to find the instruction that holds this constant: decode starting 2..8 bytes earlier
        found = []
        for back in (2, 4, 6, 8):
            s = off - back
            if s < 0 or s % 2:
                continue
            for ins in md.disasm(rom[s:s+16], s):
                if ins.address <= off < ins.address + ins.size:
                    found.append("%06x: %s %s" % (ins.address, ins.mnemonic, ins.op_str))
                break
        print("%06x value %08x | %s" % (off, v, " || ".join(sorted(set(found))) if found else "(no instruction decodes over it)"))
