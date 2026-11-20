"""Read-only scratch helper: parse the flash2 block-id -> address table (6-byte records) over a fixed window and
look up ids.  usage: block_table2.py <flash2 image> <first record address hex> <end hex> [id ...]"""
import sys

data = open(sys.argv[1], "rb").read()
base = 0x500000
first, end = int(sys.argv[2], 16), int(sys.argv[3], 16)
table = {}
order = []
for address in range(first, end, 6):
    off = address - base
    block_id = int.from_bytes(data[off:off + 2], "big")
    target = int.from_bytes(data[off + 2:off + 6], "big")
    table.setdefault(block_id, []).append((hex(address), hex(target)))
    order.append((address, block_id, target))
print(f"{len(order)} records; first {hex(order[0][1])} -> {hex(order[0][2])}; last {hex(order[-1][1])} -> {hex(order[-1][2])}")
for arg in sys.argv[4:]:
    block_id = int(arg, 16)
    print(hex(block_id), table.get(block_id))
