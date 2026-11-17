import csv
import struct
import sys

# usage: retry_dump_peek.py name_or_0xaddr [...]   -> reads each value from the CM848 RAM dump (base 0x3FA000) at its declared width
ROOT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/'
ram = open(ROOT + 'originals/cm848_ram.bin', 'rb').read()
BASE = 0x3FA000

rows = {}
with open(ROOT + 'output/global_variables.csv') as handle:
    for row in csv.reader(handle):
        if len(row) >= 3 and row[0].startswith('0x'):
            rows[row[1]] = (int(row[0], 16), row[2])

for arg in sys.argv[1:]:
    if arg.startswith('0x'):
        address, kind = int(arg, 16), 'word'
        name = arg
    elif arg in rows:
        address, kind = rows[arg]
        name = arg
    else:
        print(arg, 'NOT FOUND')
        continue
    offset = address - BASE
    if offset < 0 or offset >= len(ram):
        print(name, hex(address), 'outside the RAM dump')
        continue
    if kind == 'byte':
        value = ram[offset]
        signed = value - 256 if value > 127 else value
        print('%-60s %s byte  unsigned=%d signed=%d' % (name, hex(address), value, signed))
    elif kind == 'dword':
        value = struct.unpack('>I', ram[offset:offset + 4])[0]
        signed = struct.unpack('>i', ram[offset:offset + 4])[0]
        print('%-60s %s dword unsigned=%d signed=%d' % (name, hex(address), value, signed))
    else:
        value = struct.unpack('>H', ram[offset:offset + 2])[0]
        signed = struct.unpack('>h', ram[offset:offset + 2])[0]
        print('%-60s %s word  unsigned=%d signed=%d' % (name, hex(address), value, signed))
