#!/usr/bin/env python3
"""usage: dis.py START END [grep-substring...]  - disassemble CM550 ROM [START,END) with addresses."""
import subprocess, sys, re
ROM='/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin'
s=int(sys.argv[1],0); e=int(sys.argv[2],0)
d=open(ROM,'rb').read()
pc=s
out=[]

def ea_str(pc, mode, reg, size):
    """return (extra_bytes, text) for an effective address starting at pc (extension words at pc)."""
    if mode==0: return 0,'%%d%d'%reg
    if mode==1: return 0,'%%a%d'%reg
    if mode==2: return 0,'(%%a%d)'%reg
    if mode==3: return 0,'(%%a%d)+'%reg
    if mode==4: return 0,'-(%%a%d)'%reg
    if mode==5:
        dd=int.from_bytes(d[pc:pc+2],'big',signed=True); return 2,'%d(%%a%d)'%(dd,reg)
    if mode==6:
        ext=int.from_bytes(d[pc:pc+2],'big'); xr=('%%a%d' if ext&0x8000 else '%%d%d')%((ext>>12)&7); xs='.l' if ext&0x800 else '.w'
        dd=ext&0xff; dd=dd-256 if dd>127 else dd
        return 2,'%d(%%a%d,%s%s)'%(dd,reg,xr,xs)
    if mode==7 and reg==0:
        a=int.from_bytes(d[pc:pc+2],'big',signed=True); return 2,'$%x.w'%(a&0xffffffff)
    if mode==7 and reg==1:
        a=int.from_bytes(d[pc:pc+4],'big'); return 4,'$%x'%a
    if mode==7 and reg==2:
        dd=int.from_bytes(d[pc:pc+2],'big',signed=True); return 2,'pc+%d'%dd
    if mode==7 and reg==4:
        n={0:2,1:2,2:4}[size]; v=int.from_bytes(d[pc+(1 if size==0 else 0):pc+n],'big'); return n,'#%d'%v
    return 0,'ea?%d/%d'%(mode,reg)

def manual(pc):
    w=(d[pc]<<8)|d[pc+1]
    if (w&0xf100)==0x7000:
        v=w&0xff; v=v-256 if v>127 else v
        return 2,'moveq\t#%d, %%d%d   [manual]'%(v,(w>>9)&7)
    if (w&0xf000)==0x5000 and (w&0xc0)!=0xc0:
        q=(w>>9)&7 or 8; sz='bwl'[(w>>6)&3]; op='subq' if w&0x100 else 'addq'
        mode=(w>>3)&7; reg=w&7
        ea={0:'%%d%d'%reg,1:'%%a%d'%reg,2:'(%%a%d)'%reg,3:'(%%a%d)+'%reg,4:'-(%%a%d)'%reg}.get(mode,'ea%d/%d'%(mode,reg))
        if mode==7 and reg==1:
            a=int.from_bytes(d[pc+2:pc+6],'big'); return 6,'%s.%s\t#%d, $%x   [manual]'%(op,sz,q,a)
        if mode==7 and reg==0:
            a=int.from_bytes(d[pc+2:pc+4],'big'); return 4,'%s.%s\t#%d, $%x.w   [manual]'%(op,sz,q,a)
        if mode==5:
            dd=int.from_bytes(d[pc+2:pc+4],'big',signed=True); return 4,'%s.%s\t#%d, %d(%%a%d)   [manual]'%(op,sz,q,dd,reg)
        return 2,'%s.%s\t#%d, %s   [manual]'%(op,sz,q,ea)
    if w==0x4879:
        a=int.from_bytes(d[pc+2:pc+6],'big'); return 6,'pea\t$%x   [manual]'%a
    if w==0x4878:
        a=int.from_bytes(d[pc+2:pc+4],'big',signed=True); return 4,'pea\t$%x.w   [manual]'%(a&0xffffff)
    if (w&0xf1c0) in (0xc0c0,0xc1c0):
        op='mulu.w' if (w&0x1c0)==0x0c0 else 'muls.w'
        mode=(w>>3)&7; reg=w&7; dn=(w>>9)&7
        if mode==7 and reg==1:
            a=int.from_bytes(d[pc+2:pc+6],'big'); return 6,'%s\t$%x, %%d%d   [manual]'%(op,a,dn)
        if mode==7 and reg==4:
            a=int.from_bytes(d[pc+2:pc+4],'big'); return 4,'%s\t#%d, %%d%d   [manual]'%(op,a,dn)
        ea={0:'%%d%d'%reg,2:'(%%a%d)'%reg}.get(mode,'ea%d/%d'%(mode,reg))
        if mode==5:
            dd=int.from_bytes(d[pc+2:pc+4],'big',signed=True); return 4,'%s\t%d(%%a%d), %%d%d   [manual]'%(op,dd,reg,dn)
        return 2,'%s\t%s, %%d%d   [manual]'%(op,ea,dn)

    op4=w>>12
    mode=(w>>3)&7; reg=w&7
    if op4==0xb:
        dn=(w>>9)&7; om=(w>>6)&7
        if om in (0,1,2):
            n,t=ea_str(pc+2,mode,reg,om); return 2+n,'cmp.%s\t%s, %%d%d   [manual]'%('bwl'[om],t,dn)
        if om in (3,7):
            n,t=ea_str(pc+2,mode,reg,1 if om==3 else 2); return 2+n,'cmpa.%s\t%s, %%a%d   [manual]'%('w' if om==3 else 'l',t,dn)
    if (w&0xff00)==0x4a00 and (w&0xc0)!=0xc0:
        sz=(w>>6)&3; n,t=ea_str(pc+2,mode,reg,sz); return 2+n,'tst.%s\t%s   [manual]'%('bwl'[sz],t)
    if (w&0xff00)==0x4200 and (w&0xc0)!=0xc0:
        sz=(w>>6)&3; n,t=ea_str(pc+2,mode,reg,sz); return 2+n,'clr.%s\t%s   [manual]'%('bwl'[sz],t)
    if (w&0xf100)==0x0000 and (w>>9)&7 in (0,1,2,3,5,6) and (w&0xc0)!=0xc0:
        nm={0:'ori',1:'andi',2:'subi',3:'addi',5:'eori',6:'cmpi'}[(w>>9)&7]; sz=(w>>6)&3
        ni={0:2,1:2,2:4}[sz]; iv=int.from_bytes(d[pc+2+(1 if sz==0 else 0):pc+2+ni],'big')
        n,t=ea_str(pc+2+ni,mode,reg,sz); return 2+ni+n,'%s.%s\t#%d, %s   [manual]'%(nm,'bwl'[sz],iv,t)
    return 2,'.word 0x%04x  (undecodable)'%w

while pc<e:
    chunk=' '.join('0x%02x'%b for b in d[pc:e])
    r=subprocess.run(['llvm-mc-18','--disassemble','--triple=m68k','--show-encoding'],input=chunk,capture_output=True,text=True)
    lines=[l for l in r.stdout.splitlines() if 'encoding:' in l]
    if not lines:
        n,txt=manual(pc); out.append('%06x: %s'%(pc,txt)); pc+=n; continue
    # take instructions until the first failure point; llvm-mc skips bad bytes silently-ish, so recompute by encoding length
    progressed=False
    for l in lines:
        m=re.search(r'encoding: \[(.*?)\]',l)
        enc=[int(x,16) for x in m.group(1).split(',')]
        if list(d[pc:pc+len(enc)])!=enc:
            break
        out.append('%06x: %s'%(pc,l.split(';')[0].strip()))
        pc+=len(enc); progressed=True
    if not progressed:
        n,txt=manual(pc); out.append('%06x: %s'%(pc,txt)); pc+=n
for l in out: print(l)
