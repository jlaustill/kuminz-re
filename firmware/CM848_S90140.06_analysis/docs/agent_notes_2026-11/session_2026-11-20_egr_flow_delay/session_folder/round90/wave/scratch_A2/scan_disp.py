BASE = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/'
rom = open(BASE + 'firmware/J90350.00.rom.bin', 'rb').read()
# (function start, end guess, base register)
targets = [(0x27f9c, 0x284e8, 4, 'mc68k_runPowerDownSequence'),
           (0x284e8, 0x28a00, 2, 'mc68k_applicationMain')]
for start, end, reg, name in targets:
    print('==', name, 'a%d' % reg)
    for a in range(start, end - 3, 2):
        w = int.from_bytes(rom[a:a + 2], 'big')
        d = int.from_bytes(rom[a + 2:a + 4], 'big')
        ea = w & 0x3f
        if ea == (0x28 | reg) and d < 0x40:
            print('   %05x %04x %04x  (d16=%d,a%d) op-hi %04x' % (a, w, d, d, reg, w & 0xffc0))
        # lea (d16,An),Am : 0100 mmm 111 101 rrr
        if (w & 0xf1f8) == 0x41e8 and (w & 7) == reg and d < 0x40:
            print('   %05x lea (%d,a%d),a%d' % (a, d, reg, (w >> 9) & 7))
        # move.b Dn/imm to (d16,An): dest field mode 5 reg -> bits 8-6 = 101, bits 11-9 = reg
        if (w & 0xf000) == 0x1000 and ((w >> 6) & 7) == 5 and ((w >> 9) & 7) == reg:
            print('   %05x move.b -> (d16,a%d) word %04x next %s' % (a, reg, w, rom[a + 2:a + 6].hex()))
