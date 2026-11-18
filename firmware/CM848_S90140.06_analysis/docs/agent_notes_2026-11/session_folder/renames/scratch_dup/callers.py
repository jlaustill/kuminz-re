import struct,sys
base='/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/originals/'
rom=open(base+'cm848_rom.bin','rb').read()
try:
    fl2=open(base+'cm848_flash2_live.bin','rb').read()
except Exception as e:
    fl2=b''
print('rom',len(rom),'flash2',len(fl2),file=sys.stderr)
targets=[int(t,16) for t in sys.argv[1:]]
def scan(data,vma,label):
    for off in range(0,len(data)-3,4):
        w=struct.unpack('>I',data[off:off+4])[0]
        if (w>>26)==18 and (w&1)==1:   # bl / bla
            li=(w>>2)&0xFFFFFF
            if li&0x800000: li-=0x1000000
            li<<=2
            aa=(w>>1)&1
            tgt = li if aa else vma+off+li
            tgt&=0xFFFFFFFF
            if tgt in targets:
                print(f'{label} call at 0x{vma+off:x} -> 0x{tgt:x}')
scan(rom,0,'rom')
scan(fl2,0x500000,'flash2')
