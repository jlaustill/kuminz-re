import sys
rom = open('/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin','rb').read()
for a in sys.argv[1:]:
    v = int(a,16)
    pats = [(v.to_bytes(4,'big'),'long')]
    # also the low word for (d16,An)-style or short absolute when base is 0x800000? skip
    for p,kind in pats:
        i = rom.find(p)
        hits=[]
        while i!=-1:
            hits.append(i)
            i = rom.find(p,i+1)
        print(a, kind, ' '.join(hex(h) for h in hits))
