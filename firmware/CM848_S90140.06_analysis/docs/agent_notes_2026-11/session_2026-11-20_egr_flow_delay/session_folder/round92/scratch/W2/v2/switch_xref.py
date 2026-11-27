"""Cross-reference CM550's logical switches 0-31 (override enables = e2m 106B words 13 / 14) over three e2m blocks of
v64t6_s.e2m (read-only):
  106B +0x1C + 2 x (s / 16), mask 1 << (s % 16)   user override enable
  000E +(s / 8), mask 1 << (s % 8)                 debounced status      (S records carry the mask; N records do not)
  000E +0xA + (s / 8), mask 1 << (s % 8)           user supplied value
  12A8 +s                                          override priority byte
usage: switch_xref.py <e2m> [first] [last]"""
import collections
import sys

path = sys.argv[1]
first = int(sys.argv[2]) if len(sys.argv) > 2 else 0
last = int(sys.argv[3]) if len(sys.argv) > 3 else 31
recs = collections.defaultdict(list)  # (block, offset) -> [(type, mask or None, name, text)]
for raw in open(path, encoding="latin-1"):
    line = raw.rstrip("\r\n")
    data, _, comment = line.partition(";")
    c = data.split(",")
    if len(c) < 12:
        continue
    block = c[2].upper().lstrip("0") or "0"
    if block not in ("106B", "E", "12A8"):
        continue
    try:
        off = int(c[3], 16)
    except ValueError:
        continue
    mask = None
    if c[5] == "S":
        try:
            mask = int(c[10], 16)
        except ValueError:
            mask = None
    item = (c[5], mask, c[0].strip(), comment.strip())
    if item not in recs[(block, off)]:
        recs[(block, off)].append(item)


def show(block, off, mask, label, seen_unmasked):
    out = []
    for typ, m, name, text in recs.get((block, off), []):
        if typ == "S":
            if m == mask:
                out.append(f"      {label} {block}+{off:X} S {m:#06x} {name:9} {text}")
        elif typ in ("N", "B") and block == "12A8":
            out.append(f"      {label} {block}+{off:X} {typ} {'':6} {name:9} {text}")
    return out


for s in range(first, last + 1):
    print(f"logical switch {s:2}: enable word {13 + s // 16} bit {s % 16:2} (mask {1 << (s % 16):#06x}) | status byte "
          f"{s // 8} bit {s % 8} (0x{0x80bcce + s // 8:x} & {1 << (s % 8):#04x}) | value 0x{0x80bcd8 + s // 8:x} | "
          f"priority 0x{0x80bd4a + s:x}")
    for line in show("106B", 0x1C + 2 * (s // 16), 1 << (s % 16), "enable  ", None):
        print(line)
    for line in show("E", s // 8, 1 << (s % 8), "status  ", None):
        print(line)
    for line in show("E", 0xA + s // 8, 1 << (s % 8), "value   ", None):
        print(line)
    for line in show("12A8", s, None, "priority", None):
        print(line)
print()
print("N records of 000E +0..+9 and +A..+13 (no mask column; the bit is in the text):")
for off in list(range(0, 10)) + list(range(0xA, 0x14)):
    for typ, m, name, text in recs.get(("E", off), []):
        if typ != "S":
            print(f"   E+{off:X} {typ} {name:9} {text}")
