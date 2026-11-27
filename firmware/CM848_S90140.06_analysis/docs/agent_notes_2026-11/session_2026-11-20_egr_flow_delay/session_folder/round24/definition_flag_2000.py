"""Which fault slots carry fault_definition_t.definition_flags bit 0x2000? Prints the DTC (obd_dtc_code_table) and the
Cummins fault code per slot, split by the bit. usage: definition_flag_2000.py <cm848_rom.bin>"""
import struct
import sys

r = open(sys.argv[1], "rb").read()
dtc = struct.unpack(">170H", r[0x5b57c:0x5b57c + 340])
flagged, clear = [], []
for slot in range(170):
    code, flags, entry, aging = struct.unpack(">HHBB", r[0x59e9a + slot * 6:0x59e9a + slot * 6 + 6])
    item = f"{slot}:P{dtc[slot]:04x}/c{code}"
    (flagged if flags & 0x2000 else clear).append(item)
print(len(flagged), "slots with 0x2000:", " ".join(flagged[:40]))
print(len(clear), "slots without:", " ".join(clear[:40]))
