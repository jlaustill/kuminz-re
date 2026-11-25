"""Scan the CM550 RAM dumps for 22-byte blocks shaped like a cm550_tableLookup2D argument record
(table_lookup_2d_arguments_t): small even cached offsets at +0 / +8, plausible table pointers at +2 / +0xa / +0x10,
a 0/1 flag at +0x14. Prints each hit (and the 1D 12-byte shape table_interp_args_t separately)."""
import struct

FW = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/'
ram = open(FW + 'J90350.00.ram.bin', 'rb').read()
ext = open(FW + 'J90350.00.extended_ram.bin', 'rb').read()


def plausible_pointer(p):
    return (0x40000 <= p < 0x80000) or (0x800000 <= p < 0x810000) or (0x1000 <= p < 0x40000)


def scan(buf, base, label):
    for o in range(0, len(buf) - 22, 2):
        xo, xp, xi, yo, yp, yi, zp, ni = struct.unpack('>HIHHIHIH', buf[o:o + 22])
        if xo % 2 or yo % 2 or xo == 0 or yo == 0 or xo > 0x80 or yo > 0x80:
            continue
        if not (plausible_pointer(xp) and plausible_pointer(yp) and plausible_pointer(zp)):
            continue
        if ni > 1:
            continue
        print(f'{label} 2D 0x{base + o:x}: x off {xo} x ptr 0x{xp:x} x in {xi} y off {yo} y ptr 0x{yp:x} y in {yi} '
              f'z ptr 0x{zp:x} flag {ni}')


scan(ram, 0x800000, 'ram')
scan(ext, 0x809242, 'ext')
