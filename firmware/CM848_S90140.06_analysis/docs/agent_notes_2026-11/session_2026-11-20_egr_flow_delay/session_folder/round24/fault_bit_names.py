"""The e2m names of the fault bits: block 1036 records with a single-bit mask (column 11) at offset 2 x word. Prints
word -> [(bit, fault number, name)] and writes a JSON {word: {bit: [names]}}. Several names on one bit are product
variants (EGA / VGA ...). usage: fault_bit_names.py <labelled e2m> <out.json>"""
import json
import sys
from collections import defaultdict

e2m, out = sys.argv[1:3]
words = defaultdict(lambda: defaultdict(list))
status = {}
for line in open(e2m, errors="replace"):
    parts = line.split(",")
    if len(parts) < 12 or parts[2] != "1036":
        continue
    name, offset, mask = parts[0], int(parts[3], 16), parts[10]
    word = offset // 2
    if name.startswith("System_Error_Status_"):
        status[word] = name
        continue
    try:
        m = int(mask, 16)
    except ValueError:
        continue
    if m and m & (m - 1) == 0 and offset % 2 == 0:
        bit = m.bit_length() - 1
        words[word][bit].append(name)
total = 0
for w in sorted(words):
    bits = words[w]
    total += len(bits)
    print(f"word {w:2} ({status.get(w, '-')}): " + "; ".join(
        f"{b}={'/'.join(bits[b])}" for b in sorted(bits)))
print(total, "named bits in", len(words), "words;", len(status), "status words")
json.dump({w: {b: n for b, n in v.items()} for w, v in words.items()}, open(out, "w"), indent=1)
