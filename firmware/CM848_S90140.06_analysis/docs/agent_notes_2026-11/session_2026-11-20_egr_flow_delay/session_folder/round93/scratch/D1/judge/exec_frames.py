import re,sys
rom=open('/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin','rb').read()
tbl=0x1b90e
starts=[tbl+int.from_bytes(rom[tbl+2*i:tbl+2*i+2],'big') for i in range(40)]
lines=open(sys.argv[1]).read().splitlines()
ins=[]
for l in lines:
    m=re.match(r'^([0-9a-f]{6}): (\S+)\s+(.*)$',l)
    if m: ins.append((int(m.group(1),16),m.group(3)))
for f,s in enumerate(starts):
    e=starts[f+1] if f+1<40 else 0x1be86+0x200
    # find end: sorted next start
    nxt=sorted(x for x in starts if x> s)
    e=nxt[0] if nxt else 0x1bf40
    calls=[]
    for a,t in ins:
        if s<=a<e and (t.startswith('bsr') or t.startswith('jsr')):
            calls.append(t.split()[-1])
    print(f, hex(s), ' '.join(calls))
