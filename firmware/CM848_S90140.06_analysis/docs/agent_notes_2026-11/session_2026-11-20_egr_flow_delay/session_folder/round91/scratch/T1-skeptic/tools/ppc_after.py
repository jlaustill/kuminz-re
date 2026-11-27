"""Print the load/store instructions in the 40 words after a CM848 address (ROM below 0x500000,
flash2 at and above it), with their base register and displacement."""
import sys, struct
FW = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals/'
rom = open(FW + 'cm848_rom.bin', 'rb').read()
fl2 = open(FW + 'cm848_flash2_live.bin', 'rb').read()
NAMES = {32: 'lwz', 34: 'lbz', 36: 'stw', 38: 'stb', 40: 'lhz', 42: 'lha', 44: 'sth', 14: 'addi', 15: 'addis'}
for arg in sys.argv[1:]:
    addr = int(arg, 16)
    img, base = (fl2, 0x500000) if addr >= 0x500000 else (rom, 0)
    print('after 0x%06x:' % addr)
    for a in range(addr, addr + 4 * 40, 4):
        w = struct.unpack('>I', img[a - base:a - base + 4])[0]
        op = w >> 26
        if op in NAMES:
            disp = w & 0xffff
            disp = disp - 0x10000 if disp >= 0x8000 else disp
            print('   0x%06x %s r%d,%d(r%d)' % (a, NAMES[op], (w >> 21) & 31, disp, (w >> 16) & 31))
        if w == 0x4e800020:
            print('   0x%06x blr' % a)
            break
