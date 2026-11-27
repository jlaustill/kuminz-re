import sys
ROM = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin'
rom = open(ROM, 'rb').read()
checks = [
    (0x159f6, '267c0080bd1a'),
    (0x15aaa, '4a2b0009660a422b0009'),
    (0x15ac4, '4a2b0009660a422b0009'),
    (0x15af0, '4a2b000a660a422b000a022c00fb0001'),
    (0x15b0a, '204b700ad1c024484a1066084212002c00040001'),
    (0x15b3a, '4a2b000d660a422b000d'),
    (0x15b54, '4a2b000d660a422b000d'),
    (0x23b92, '4a2b0006661a422b000600140040'),
    (0x23ba2, '204b5c8824484a106606421202 1400bf'.replace(' ', '')),
    (0x23ae0, '4a2b0004661a422b000400140010'),
    (0x23af0, '204b588824484a1066064212021400ef'),
    (0x23bbe, '4a2b0002661e422b000200140004'),
    (0x23bd2, '204b548824484a1066064212021400fb'),
    (0x15f08, '4a2b002d660a422b002d002c00200005'),
    (0x1caae, '4a2a002d661e422a002d002900200005'),
    (0x1ca56, '247c0080bd1a'),
    (0x23a94, None),
    (0x15e06, None),
    (0x1cac2, None),
    (0x1ca54, None),
    (0x15df0, None),
    (0x23a90, None),
]
for a, exp in checks:
    n = len(exp) // 2 if exp else 24
    got = rom[a:a + n].hex()
    if not exp:
        verdict = '--'
    elif got == exp:
        verdict = 'OK'
    else:
        verdict = 'MISMATCH exp ' + exp
    print(hex(a), got, verdict)
