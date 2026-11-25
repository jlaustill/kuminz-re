"""Decode CM550's j1939_input_signal_descriptor_table (ROM 0x20108, 17 x 10 bytes: signal pointer, timeout slot,
reserved, logical switch) and show the override-enable bit each record tests (bit 0xd0 + logical switch of the
algorithm enable table = word 13 + s / 16, bit s % 16). usage: j1939_inputs.py <rom> <globals.csv>"""
import csv
import sys
rom = open(sys.argv[1], 'rb').read()
rows = {int(r[0], 16): r[1] for r in csv.reader(open(sys.argv[2], newline='')) if r and r[0].startswith('0x')}
for i in range(17):
    o = 0x20108 + 10 * i
    ptr = int.from_bytes(rom[o:o + 4], 'big')
    slot = rom[o + 4]
    s = int.from_bytes(rom[o + 6:o + 10], 'big')
    bit = 0xd0 + s
    print(f'{i:2} signal 0x{ptr:06x} {rows.get(ptr, "?"):55} slot {slot:2} logical switch {s:2} -> word {bit // 16} bit {bit % 16}'
          f' priority byte 0x{0x80bd4a + s:x} {rows.get(0x80bd4a + s, "?")}')
