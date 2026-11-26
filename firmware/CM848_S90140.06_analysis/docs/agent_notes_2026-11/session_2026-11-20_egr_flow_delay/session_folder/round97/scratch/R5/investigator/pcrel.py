import sys, struct
rom = open('/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin','rb').read()
for t in [int(x,16) for x in sys.argv[1:]]:
    hits=[]
    for a in range(0,len(rom)-4,2):
        w=struct.unpack('>H',rom[a:a+2])[0]
        # lea (d16,pc),An : 0100 aaa1 1111 1010 -> 0x41fa | (An<<9)
        if (w & 0xf1ff)==0x41fa or w==0x487a:
            disp=struct.unpack('>h',rom[a+2:a+4])[0]
            if a+2+disp==t: hits.append((hex(a),hex(w)))
    # also 16-bit absolute short / word tables containing low half
    print(hex(t),hits)
