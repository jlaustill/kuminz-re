"""List every branch / call in a linear sweep of the ROM whose target is one of the given addresses."""
import sys, re, capstone
rom = open(sys.argv[1], 'rb').read()
targets = {int(t, 16) for t in sys.argv[2:]}
md = capstone.Cs(capstone.CS_ARCH_M68K, capstone.CS_MODE_BIG_ENDIAN | capstone.CS_MODE_M68K_040)
addr, end = 0, len(rom)
while addr < end:
    win_end = min(end, addr + 0x1000)
    last = addr
    for ins in md.disasm(rom[addr:win_end], addr):
        last = ins.address + ins.size
        if ins.mnemonic.startswith(('b', 'j', 'db')):
            for m in re.finditer(r'\$([0-9a-f]+)', ins.op_str):
                if int(m.group(1), 16) in targets:
                    print('%06x: %s %s' % (ins.address, ins.mnemonic, ins.op_str))
    if last == addr:
        addr += 2
    else:
        addr = last if last >= win_end - 10 else last + 2
