import struct,sys,subprocess
rom=open("/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin","rb").read()
t=int(sys.argv[1],16)
sites=[]
pat=bytes.fromhex("4eb9")+struct.pack(">I",t)
i=rom.find(pat)
while i!=-1:
    sites.append(("jsr.l",i)); i=rom.find(pat,i+1)
for i in range(0,len(rom)-4,2):
    op=struct.unpack(">H",rom[i:i+2])[0]
    if op==0x6100:
        d=struct.unpack(">h",rom[i+2:i+4])[0]
        if i+2+d==t: sites.append(("bsr.w",i))
    elif op==0x4eba:
        d=struct.unpack(">h",rom[i+2:i+4])[0]
        if i+2+d==t: sites.append(("jsr pc",i))
    elif op==0x61ff:
        d=struct.unpack(">i",rom[i+2:i+6])[0]
        if i+2+d==t: sites.append(("bsr.l",i))
pat=struct.pack(">I",t)
i=rom.find(pat)
raw=[]
while i!=-1:
    raw.append(i); i=rom.find(pat,i+1)
print("calls:",len(sites)," raw:",[hex(r) for r in raw])
for kind,s in sites:
    print("==",kind,hex(s))
    out=subprocess.run(["python3","/home/linux/.claude/jobs/374b0424/tmp/w15/r93/tools/m68k.py","/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin",hex(s-int(sys.argv[2] if len(sys.argv)>2 else "8"))[2:],hex(s+int(sys.argv[3] if len(sys.argv)>3 else "12"))[2:]],capture_output=True,text=True).stdout
    print(out.rstrip())
