"""Read-only scratch helper: walk the flash2 block-id -> address table (6-byte records: id16 + addr32, big endian)
around the record that maps 0x198e -> 0x0040a5b4.  usage: block_table.py <flash2 image> [id ...]   (ids in hex)"""
import sys

data = open(sys.argv[1], "rb").read()
base = 0x500000
anchor = 0x53D7D0 - base          # record [198e][0040a5b4]


def record(off):
    return int.from_bytes(data[off:off + 2], "big"), int.from_bytes(data[off + 2:off + 6], "big")


def plausible(off):
    block_id, address = record(off)
    return 0x0100 <= block_id <= 0xFFFF and 0x0 < address < 0x01004000 and (address < 0x00700000 or address >= 0x01000000)


start = anchor
while plausible(start - 6):
    start -= 6
end = anchor
while plausible(end + 6):
    end += 6
print(f"table from {hex(base + start)} to {hex(base + end + 6)} : {(end - start) // 6 + 1} records")
table = {}
for off in range(start, end + 6, 6):
    block_id, address = record(off)
    table.setdefault(block_id, []).append((hex(base + off), hex(address)))
want = [int(a, 16) for a in sys.argv[2:]]
for block_id in want:
    print(hex(block_id), table.get(block_id))
