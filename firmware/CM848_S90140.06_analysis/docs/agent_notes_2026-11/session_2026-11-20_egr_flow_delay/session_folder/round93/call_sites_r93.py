"""Round 93 (read-only): for every CM550 function row in an address range, the ways the dumped ROM reaches it:
jsr / jmp with an absolute long operand, bsr.w / bsr.b / bra.w / bra.b / Bcc with a relative displacement, and any
other aligned occurrence of its 4-byte address (a pointer). A row nothing reaches is printed with NO ENTRY, and
whether the instruction before it falls through into it (not rts / rte / jmp / bra).
usage: call_sites_r93.py <repo> <start hex> <end hex>"""
import csv
import os
import sys

repo, lo, hi = sys.argv[1], int(sys.argv[2], 16), int(sys.argv[3], 16)
rom = open(os.path.join(repo, "firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"), "rb").read()
rows = []
for r in csv.reader(open(os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/function_renames.csv"), newline="")):
    if r and r[0].startswith("0x") and lo <= int(r[0], 16) < hi:
        rows.append((int(r[0], 16), r[1]))
relative = {}
for i in range(0, len(rom) - 4, 2):
    w = int.from_bytes(rom[i:i + 2], "big")
    if (w & 0xf000) == 0x6000:          # bra / bsr / Bcc
        kind = "bra" if (w & 0xff00) == 0x6000 else "bsr" if (w & 0xff00) == 0x6100 else "bcc"
        d8 = w & 0xff
        if d8 == 0:
            target = i + 2 + int.from_bytes(rom[i + 2:i + 4], "big", signed=True)
            relative.setdefault(target, []).append(f"{kind}.w@0x{i:x}")
        elif d8 != 0xff:
            target = i + 2 + (d8 - 256 if d8 & 0x80 else d8)
            relative.setdefault(target, []).append(f"{kind}.b@0x{i:x}")
no_entry = 0
for a, name in rows:
    pat = a.to_bytes(4, "big")
    absolute, pointers = [], []
    i = rom.find(pat)
    while i != -1:
        if i % 2 == 0:
            op = int.from_bytes(rom[i - 2:i], "big")
            (absolute if op in (0x4eb9, 0x4ef9) else pointers).append(f"{'jsr' if op == 0x4eb9 else 'jmp' if op == 0x4ef9 else 'ptr'}@0x{i - 2 if op in (0x4eb9, 0x4ef9) else i:x}")
        i = rom.find(pat, i + 1)
    rel = [s for s in relative.get(a, []) if not s.startswith("bcc") or True]
    before = int.from_bytes(rom[a - 2:a], "big")
    falls = before not in (0x4e75, 0x4e73, 0x4e74) and int.from_bytes(rom[a - 6:a - 4], "big") != 0x4ef9
    total = len(absolute) + len(rel) + len(pointers)
    flag = ""
    if total == 0:
        no_entry += 1
        flag = "  <== NO ENTRY" + (" (the code before it falls through into it)" if falls else " (after a return)")
    print(f"0x{a:05x} {name:58} abs {len(absolute):2} rel {len(rel):2} ptr {len(pointers):2} {' '.join((absolute + rel + pointers)[:4])[:80]}{flag}")
print(f"{len(rows)} rows; {no_entry} with no entry")
