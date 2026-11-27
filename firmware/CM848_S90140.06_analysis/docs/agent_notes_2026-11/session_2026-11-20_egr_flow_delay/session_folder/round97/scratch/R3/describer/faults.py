import sys
base='/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/'
ram = open(base+'J90350.00.ram.bin','rb').read()
def w(a): return int.from_bytes(ram[a-0x800000:a-0x800000+2],'big')
for word in (0,1,8,9):
    for bit in range(16):
        idx = word*16+bit
        a = 0x8067c4 + idx*6
        print('word %d bit %2d idx %3d @%#x code %5d flags %#06x spn %#06x' % (word,bit,idx,a,w(a),w(a+2),w(a+4)))
