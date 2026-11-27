"""Round 29: evidence for the fault_<n> bits the code references: each bit's setters (constant-mask sets, flat
pieces and named-bit stores), its DTC (ROM 0x5985a slot -> obd_dtc_code_table 0x5b57c) and the readers.
usage: fault_n_evidence.py <cpp> <rom.bin> <fault_fields.tsv>"""
import re
import struct
import sys
from collections import defaultdict

cpp, rom_path, tsv = sys.argv[1:4]
rom = open(rom_path, "rb").read()
u16 = lambda a: struct.unpack(">H", rom[a:a + 2])[0]


def dtc(f):
    s = u16(0x5985a + 2 * f)
    if s >= 170:
        return "-"
    v = u16(0x5b57c + 2 * s)
    return "PCBU"[v >> 14] + f"{v & 0x3fff:04X}"


name_of = {}
for line in open(tsv):
    fault, word, bit, field, comment = line.rstrip("\n").split("\t")
    name_of[int(fault)] = field
text = open(cpp, errors="replace").read()
marks = list(re.finditer(r"^// Function: (\S+) @ 0x([0-9a-fA-F]+)", text, re.M))
setters, readers = defaultdict(set), defaultdict(set)
for i, m in enumerate(marks):
    body = text[m.end(): marks[i + 1].start() if i + 1 < len(marks) else len(text)]
    body = re.sub(r"/\*.*?\*/", "", body, flags=re.S)
    flat = re.sub(r"\s+", " ", body)
    for s in re.finditer(r"fault_detected_cal\._(\d+)_2_ = fault_detected_cal\._\1_2_ \| (0x[0-9a-f]+|\d+)", flat):
        w, mask = int(s.group(1)) // 2, int(s.group(2), 0)
        for b in range(16):
            if mask >> b & 1:
                setters[16 * w + b].add(m.group(1))
    for s in re.finditer(r"fault_detected_cal\.fault_(\d+) = 1", flat):
        setters[int(s.group(1))].add(m.group(1))
    for s in re.finditer(r"fault_(?:detected|registered|previous_pass)_cal\.fault_(\d+)(?! = )", flat):
        readers[int(s.group(1))].add(m.group(1))
for f in map(int, re.findall(r"\d+", " ".join(sys.argv[4:]))) if sys.argv[4:] else sorted(readers):
    print(f"{f} {name_of.get(f)} {dtc(f)} set by [{', '.join(sorted(setters[f])) or '-'}] read by "
          f"[{', '.join(sorted(readers[f]))}]")
