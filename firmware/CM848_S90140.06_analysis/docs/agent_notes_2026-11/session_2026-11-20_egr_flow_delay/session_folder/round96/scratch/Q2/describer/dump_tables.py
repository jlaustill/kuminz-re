import struct, sys

RAM_PATH = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.ram.bin'
RENAMES = '/home/linux/.claude/jobs/374b0424/tmp/w15/r96/frozen/cm550/function_renames.csv'

names = {}
with open(RENAMES) as handle:
    for line in handle:
        if line.startswith('#') or not line.strip():
            continue
        parts = line.rstrip('\n').split(',', 2)
        try:
            names[int(parts[0], 16)] = parts[1]
        except ValueError:
            pass

ram = open(RAM_PATH, 'rb').read()


def read(address, size):
    offset = address - 0x800000
    return ram[offset:offset + size]


def dump_table(label, table_address, count_address, entries, key_size):
    count = read(count_address, 1)[0]
    print(f"== {label}: table {table_address:#x}, count byte {count_address:#x} = {count}")
    for index in range(entries):
        entry = read(table_address + 6 * index, 6)
        if key_size == 2:
            key = struct.unpack('>H', entry[0:2])[0]
        else:
            key = entry[0]
        handler = struct.unpack('>I', entry[2:6])[0]
        marker = '' if index < count else '   (beyond count)'
        print(f"  [{index:2d}] key {key:#06x} ({key}) handler {handler:#010x} {names.get(handler, '?')}{marker}")


dump_table('PGN 59904 request responders', 0x801d5a, 0x801e1a, 32, 2)
dump_table('J1939 diagnostic services', 0x801c7a, 0x801d3a, 32, 1)
print('bytes 0x801d3a..0x801d5a:', read(0x801d3a, 0x20).hex())
print('bytes 0x801e1a..0x801e40:', read(0x801e1a, 0x26).hex())
