import struct
import sys

# usage: fault.py <fault bit number>...   (fault bit n -> slot via ROM 0x5985a[n] -> code via ROM 0x5b57c[slot])
ROM = open('/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/originals/cm848_rom.bin', 'rb').read()


def word(address):
    return struct.unpack('>H', ROM[address:address + 2])[0]


for arg in sys.argv[1:]:
    bit = int(arg)
    slot = word(0x5985a + 2 * bit)
    code = word(0x5b57c + 2 * slot) if slot < 170 else None
    print('fault', bit, 'slot', slot, 'code', ('P%04X' % code) if code is not None else '-')
