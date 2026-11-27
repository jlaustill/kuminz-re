import sys, capstone
rom = open(sys.argv[1], 'rb').read()
start = int(sys.argv[2], 16); end = int(sys.argv[3], 16)
md = capstone.Cs(capstone.CS_ARCH_M68K, capstone.CS_MODE_BIG_ENDIAN | capstone.CS_MODE_M68K_040)
addr = start
while addr < end:
    for ins in md.disasm(rom[addr:end], addr):
        print("%06x: %-24s %s %s" % (ins.address, ins.bytes.hex(), ins.mnemonic, ins.op_str))
        addr = ins.address + ins.size
    if addr < end:
        print("%06x: %-24s ??? (undecoded word)" % (addr, rom[addr:addr+2].hex()))
        addr += 2
