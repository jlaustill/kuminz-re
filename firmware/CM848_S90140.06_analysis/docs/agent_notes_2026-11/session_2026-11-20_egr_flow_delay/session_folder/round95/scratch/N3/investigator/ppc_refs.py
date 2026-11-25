import struct,sys
rom=open("/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals/cm848_rom.bin","rb").read()
fl=open("/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals/cm848_flash2_live.bin","rb").read()
t=int(sys.argv[1],16)
for name,img,base in (("rom",rom,0),("flash2",fl,0x500000)):
    for i in range(0,len(img)-4,4):
        w=struct.unpack(">I",img[i:i+4])[0]
        pc=base+i
        op=w>>26
        if op==18: # b/bl
            li=w&0x03fffffc
            if li&0x02000000: li-=0x04000000
            tgt=li if (w&2) else pc+li
            if tgt==t: print(name,hex(pc),"branch",hex(w))
        elif op==16: # bc
            bd=w&0xfffc
            if bd&0x8000: bd-=0x10000
            tgt=bd if (w&2) else pc+bd
            if tgt==t: print(name,hex(pc),"bc",hex(w))
        if w==t: print(name,hex(pc),"word")
    # lis/addi or lis/ori pairs
    hi_a=(t+0x8000)>>16; lo_a=t&0xffff
    hi_o=t>>16
    for i in range(0,len(img)-8,4):
        w=struct.unpack(">I",img[i:i+4])[0]
        if (w>>26)==15 and ((w>>16)&31)==0: # lis rD
            rd=(w>>21)&31; imm=w&0xffff
            for j in range(1,12):
                if i+4*j+4>len(img): break
                w2=struct.unpack(">I",img[i+4*j:i+4*j+4])[0]
                op2=w2>>26
                if op2 in (14,24) and ((w2>>16)&31)==rd:
                    lo=w2&0xffff
                    val=(imm<<16)+(lo-0x10000 if (op2==14 and lo&0x8000) else lo)
                    if (val&0xffffffff)==t: print(name,hex(base+i),"lis+",("addi" if op2==14 else "ori"),hex(val))
                    break
