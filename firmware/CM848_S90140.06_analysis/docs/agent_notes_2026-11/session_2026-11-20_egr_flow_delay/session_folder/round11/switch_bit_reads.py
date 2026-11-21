"""For switch_input_state_bits[N] & mask, list each tested switch with its e2m 1612 record and the functions that
test it, and the bytes written with | / & (read-modify-write). usage: switch_bit_reads.py <cpp> <e2m>"""
import collections
import re
import sys

cpp, e2m = sys.argv[1:3]
text = open(cpp).read()
starts = [(m.start(), m.group(1)) for m in re.finditer(r"^// Function: (\S+) @", text, re.M)]


def func_of(pos):
    name = None
    for s, f in starts:
        if s > pos:
            break
        name = f
    return name


names = {}
for line in open(e2m, errors="replace"):
    f = line.split(";")[0].split(",")
    if len(f) > 10 and f[2] == "1612" and f[5] == "S":
        names[(int(f[3], 16), int(f[10], 16))] = f[0]
tests = collections.defaultdict(collections.Counter)
for m in re.finditer(r"switch_input_state_bits\[(\d)\]\s*&\s*(0x[0-9a-f]+|\d+)", text):
    byte, mask = int(m.group(1)), int(m.group(2), 0)
    tests[(byte, mask)][func_of(m.start())] += 1
for (byte, mask), fs in sorted(tests.items()):
    bits = [b for b in range(8) if mask >> b & 1]
    recs = [names.get((byte, 1 << b), "no record") for b in bits] if len(bits) <= 2 else ["(multi-bit)"]
    print(f"switch byte {byte} mask 0x{mask:02x} switches {[byte * 8 + b for b in bits]} {recs}: "
          f"{sum(fs.values())} uses in {len(fs)} functions")
rmw = collections.Counter()
for m in re.finditer(r"switch_input_state_bits\[(\d)\] = switch_input_state_bits\[\1\] [|&] (0x[0-9a-f]+|\d+)", text):
    rmw[(int(m.group(1)), func_of(m.start()))] += 1
print("read-modify-write sites:", dict(rmw))
