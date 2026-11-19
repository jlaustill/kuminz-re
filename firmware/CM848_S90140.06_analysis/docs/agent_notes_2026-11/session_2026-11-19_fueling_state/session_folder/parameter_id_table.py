"""Parse the CM848 flash2 parameter ID table (the subagent's claim: 6-byte records [id u16][address u32], big-endian,
at 0x53be38-0x53ea6c, read by cm848_lookupParameterIdAddress 0x539768) and print the address of each requested e2m
block id. Flash2 file offset = address - 0x500000.
usage: parameter_id_table.py <cm848_flash2.bin> <block id hex>..."""
import struct
import sys

path, ids = sys.argv[1], sys.argv[2:]
data = open(path, "rb").read()
start, end = 0x53be38 - 0x500000, 0x53ea6c - 0x500000
table = {}
for offset in range(start, min(end, len(data) - 5), 6):
    block, address = struct.unpack(">HI", data[offset:offset + 6])
    if block or address:
        table.setdefault(block, address)
print(f"{len(table)} filled records of {(end - start) // 6}")
for block in ids:
    address = table.get(int(block, 16))
    print(f"{block}: {'none' if address is None else hex(address)}")
