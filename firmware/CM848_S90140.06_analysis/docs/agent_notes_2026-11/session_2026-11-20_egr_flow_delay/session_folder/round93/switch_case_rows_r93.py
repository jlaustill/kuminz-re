"""Round 93 (read-only; a lead for the next round): CM550 function rows that are a case of a switch. The compiler's
switch is 'move.w (table,pc,dn.l*2),d0' + 'jmp (table,pc,d0.w)' (bytes 303b xx06 4efb 0002) followed by the table of
word offsets from the table's own address. This lists every such table with its case targets and marks the targets
that have a function row - a case is not a function entry, so such a row cuts the switch's function.
usage: switch_case_rows_r93.py <repo>"""
import csv
import os
import sys

repo = os.path.abspath(sys.argv[1])
rom = open(os.path.join(repo, "firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"), "rb").read()
rows = {int(r[0], 16): r[1] for r in csv.reader(open(os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/function_renames.csv"), newline=""))
        if r and r[0].startswith("0x")}
ordered = sorted(rows)
tables = hits = 0
i = rom.find(b"\x4e\xfb\x00\x02")
while i != -1:
    if i % 2 == 0 and rom[i - 4:i - 2] == b"\x30\x3b" and rom[i - 1] == 0x06:
        table = i + 4
        # the bound is in 'moveq #n,d1; cmp.l d1,d0; bhi' just before: find the moveq within 12 bytes
        count = None
        for k in range(i - 6, i - 16, -2):
            w = int.from_bytes(rom[k:k + 2], "big")
            if (w & 0xf100) == 0x7000:           # moveq #n,dx
                count = (w & 0xff) + 1
                break
        if count is None:
            count = 0
            while table + 2 * count < len(rom) and 0 < int.from_bytes(rom[table + 2 * count:table + 2 * count + 2], "big") < 0x1000:
                count += 1
        cases = sorted({table + int.from_bytes(rom[table + 2 * n:table + 2 * n + 2], "big", signed=True) for n in range(count)})
        holder = max((a for a in ordered if a <= i), default=0)
        tables += 1
        named = [(c, rows[c]) for c in cases if c in rows and c != holder]
        if named:
            hits += len(named)
            print(f"switch at 0x{i - 4:x} in {rows.get(holder)} (0x{holder:x}), {count} cases: rows on cases: "
                  + ", ".join(f"0x{c:x} {n}" for c, n in named))
    i = rom.find(b"\x4e\xfb\x00\x02", i + 1)
print(f"{tables} switch tables; {hits} function rows sit on a case")
