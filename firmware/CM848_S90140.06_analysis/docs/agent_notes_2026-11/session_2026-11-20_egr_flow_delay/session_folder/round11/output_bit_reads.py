"""For each logical output request byte row, list the masks the code tests and the functions that test them, with
the e2m 1577 record of each bit (output N = byte N / 8, mask 1 << N % 8). usage: output_bit_reads.py <cpp> <e2m>"""
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


ROWS = {"logical_output_request_bits": 0, "logical_output_request_bits_8_to_15": 1, "air_conditioning_clutch_request_byte": 4,
        "logical_output_request_bits_40_to_47": 5, "logical_output_request_bits_48_to_55": 6,
        "logical_output_request_bits_64_to_71": 8, "logical_output_request_bits_72_to_79": 9}
names = {}
for line in open(e2m, errors="replace"):
    f = line.split(";")[0].split(",")
    if len(f) > 10 and f[2] == "1577" and f[5] == "S":
        names[(int(f[3], 16), int(f[10], 16))] = f[0]
reads = collections.defaultdict(lambda: collections.Counter())
for row, byte in ROWS.items():
    for m in re.finditer(r"(?<![A-Za-z0-9_.&])" + re.escape(row) + r"\s*&\s*(0x[0-9a-f]+|\d+)", text):
        reads[(byte, int(m.group(1), 0))][func_of(m.start())] += 1
    plain = len(re.findall(r"(?<![A-Za-z0-9_.&])" + re.escape(row) + r"(?![A-Za-z0-9_])(?!\s*&)", text))
    print(f"byte {byte} {row}: {plain} other mentions")
for (byte, mask), fs in sorted(reads.items()):
    bits = [b for b in range(8) if mask >> b & 1]
    recs = [names.get((byte, 1 << b), "?") for b in bits]
    print(f"byte {byte} mask 0x{mask:02x} (outputs {[byte * 8 + b for b in bits]}) {recs}: {dict(fs)}")
