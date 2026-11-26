import sys, struct
rom = open('/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin','rb').read()
targets = [int(x,16) for x in sys.argv[1:]]
for t in targets:
    hits=[]
    pat = struct.pack('>I', t)
    i = rom.find(pat)
    while i != -1:
        kind='ptr'
        if i>=2 and rom[i-2:i]==b'\x4e\xb9': kind='jsr'
        elif i>=2 and rom[i-2:i]==b'\x4e\xf9': kind='jmp'
        hits.append((i-2 if kind in('jsr','jmp') else i, kind))
        i = rom.find(pat, i+1)
    # bsr.w : 0x6100 disp16 ; bsr.b 0x61xx; bsr.l 0x61ff
    for a in range(0, len(rom)-4, 2):
        op = rom[a]
        if op == 0x61:
            d8 = rom[a+1]
            if d8 == 0:
                disp = struct.unpack('>h', rom[a+2:a+4])[0]
                if a+2+disp == t: hits.append((a,'bsr.w'))
            elif d8 == 0xff:
                disp = struct.unpack('>i', rom[a+2:a+6])[0]
                if a+2+disp == t: hits.append((a,'bsr.l'))
            else:
                disp = d8 - 256 if d8 > 127 else d8
                if a+2+disp == t: hits.append((a,'bsr.b'))
        elif op == 0x60 or op==0x67 or op==0x66:
            pass
    print(hex(t), [(hex(a),k) for a,k in sorted(hits)])
