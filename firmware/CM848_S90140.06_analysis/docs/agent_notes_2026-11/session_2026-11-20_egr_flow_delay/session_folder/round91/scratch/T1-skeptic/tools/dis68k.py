import sys
from capstone import Cs, CS_ARCH_M68K, CS_MODE_M68K_040, CS_MODE_BIG_ENDIAN
ROM = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin'
d = open(ROM, 'rb').read()
start = int(sys.argv[1], 16)
end = int(sys.argv[2], 16)
md = Cs(CS_ARCH_M68K, CS_MODE_M68K_040 + CS_MODE_BIG_ENDIAN)
pc = start
while pc < end:
    for ins in md.disasm(d[pc:end], pc):
        print("%06x: %-24s %s %s" % (ins.address, ins.bytes.hex(), ins.mnemonic, ins.op_str))
        pc = ins.address + ins.size
    if pc < end:
        print("%06x: %-24s ???" % (pc, d[pc:pc+2].hex()))
        pc += 2
