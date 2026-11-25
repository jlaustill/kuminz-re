import sys, capstone
from capstone import m68k as M
ROM = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin'
d = open(ROM, 'rb').read()


def brief_ext_notes(ins):
    """Decode every brief extension word of an instruction by hand (capstone drops the scale for .l indexes)."""
    notes = []
    b = ins.bytes
    # opcode word
    op = int.from_bytes(b[0:2], 'big')
    # look for modes 6 (d8,An,Xn) and PC-relative index 7/3 in the source / destination EA fields
    # We simply report any 16-bit word after the opcode whose bit 8 is 0 when the instruction's text has '(' and ','
    return notes


def ea_ext_words(ins):
    b = ins.bytes
    words = [int.from_bytes(b[i:i + 2], 'big') for i in range(0, len(b), 2)]
    return words


def decode_brief(w):
    da = 'a' if w & 0x8000 else 'd'
    reg = (w >> 12) & 7
    wl = 'l' if w & 0x0800 else 'w'
    scale = 1 << ((w >> 9) & 3)
    disp = w & 0xff
    if disp & 0x80:
        disp -= 0x100
    full = (w >> 8) & 1
    return '%s%d.%s*%d disp=%d%s' % (da, reg, wl, scale, disp, ' FULL' if full else '')


def main():
    start = int(sys.argv[1], 16)
    end = int(sys.argv[2], 16)
    md = capstone.Cs(capstone.CS_ARCH_M68K, capstone.CS_MODE_BIG_ENDIAN | capstone.CS_MODE_M68K_020)
    md.detail = True
    pc = start
    while pc < end:
        for ins in md.disasm(d[pc:end], pc):
            extra = ''
            try:
                for o in ins.operands:
                    if o.type == M.M68K_OP_MEM and o.address_mode in (M.M68K_AM_AREGI_INDEX_8_BIT_DISP, M.M68K_AM_PCI_INDEX_8_BIT_DISP):
                        extra += ' [idx scale=%d disp=%d idxsize=%s]' % (o.mem.scale, o.mem.disp, 'l' if o.mem.index_size else 'w')
            except Exception as e:
                extra += ' [detail err %s]' % e
            print('%06x: %-24s %s %s%s' % (ins.address, ins.bytes.hex(), ins.mnemonic, ins.op_str, extra))
            pc = ins.address + ins.size
        if pc < end:
            print('%06x: %s ???' % (pc, d[pc:pc + 2].hex()))
            pc += 2


main()
