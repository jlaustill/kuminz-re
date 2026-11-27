# Judge: read CM848 RAM dump words / bytes / dwords at their declared width.
# cm848_ram.bin starts at 0x3FA000; it misses 0x40c200-0x40c27f, so 0x40c280 and up sit at address - 0x80.
# usage: ramdump.py <b|w|d|ws> 0xADDR [0xADDR ...]   (ws = signed word)
import struct, sys
RAM = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals/cm848_ram.bin'
ROM = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals/cm848_rom.bin'
EEP = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals/cm848_eeprom.bin'
ram = open(RAM, 'rb').read()
rom = open(ROM, 'rb').read()


def off(a):
    if 0x40c200 <= a < 0x40c280:
        return None
    o = a - 0x3fa000
    if a >= 0x40c280:
        o -= 0x80
    return o


width = sys.argv[1]
size = {'b': 1, 'w': 2, 'ws': 2, 'd': 4}[width]
fmt = {'b': '>B', 'w': '>H', 'ws': '>h', 'd': '>I'}[width]
for t in sys.argv[2:]:
    a = int(t, 16)
    if a < 0x70000:
        v = struct.unpack(fmt, rom[a:a + size])[0]
        print('%s ROM %s = %d (0x%x)' % (hex(a), width, v, v & 0xffffffff))
        continue
    o = off(a)
    if o is None or o + size > len(ram):
        print('%s: not in the dump' % hex(a))
        continue
    v = struct.unpack(fmt, ram[o:o + size])[0]
    print('%s RAM %s = %d (0x%x)' % (hex(a), width, v, v & 0xffffffff))
