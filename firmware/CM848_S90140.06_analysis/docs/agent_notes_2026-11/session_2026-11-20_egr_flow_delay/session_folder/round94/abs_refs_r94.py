"""Round 94 (read-only): every even ROM offset whose 4 bytes equal each given CM550 address (a 68k absolute long
operand or a pointer constant), with the function that holds it. usage: abs_refs_r94.py <repo> <hex address>..."""
import bisect
import csv
import os
import sys

repo = os.path.abspath(sys.argv[1])
base = os.path.join(repo, "firmware/CM550_J90350.00_analysis")
rom = open(os.path.join(base, "firmware/J90350.00.rom.bin"), "rb").read()
rows = sorted((int(r[0], 16), r[1]) for r in csv.reader(open(os.path.join(base, "output/function_renames.csv")))
              if r and r[0].startswith("0x"))
starts = [r[0] for r in rows]
for text in sys.argv[2:]:
    address = int(text, 16)
    pattern = address.to_bytes(4, "big")
    hits = []
    i = rom.find(pattern)
    while i != -1:
        if i % 2 == 0:
            k = bisect.bisect_right(starts, i) - 1
            holder = rows[k][1] if k >= 0 else "?"
            hits.append(f"0x{i:x} (op 0x{int.from_bytes(rom[i-2:i], 'big'):04x}) in {holder}")
        i = rom.find(pattern, i + 1)
    print(f"0x{address:x}: {len(hits)} absolute references")
    for h in hits:
        print("   ", h)
