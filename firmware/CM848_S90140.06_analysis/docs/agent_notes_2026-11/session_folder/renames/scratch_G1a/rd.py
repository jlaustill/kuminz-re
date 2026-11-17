import sys,struct
B='/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/originals/'
ram=open(B+'cm848_ram.bin','rb').read()
rom=open(B+'cm848_rom.bin','rb').read()
def r(addr,w=2,signed=True):
    if addr>=0x3FA000:
        buf=ram; off=addr-0x3FA000
    else:
        buf=rom; off=addr
    fmt={1:'b',2:'h',4:'i'}[w] if signed else {1:'B',2:'H',4:'I'}[w]
    return struct.unpack('>'+fmt,buf[off:off+w])[0]
if __name__=='__main__':
    # usage: rd.py addr width [count]
    a=int(sys.argv[1],16); w=int(sys.argv[2]); n=int(sys.argv[3]) if len(sys.argv)>3 else 1
    for i in range(n):
        v=r(a+i*w,w)
        print(hex(a+i*w), v, hex(v&((1<<(8*w))-1)))
