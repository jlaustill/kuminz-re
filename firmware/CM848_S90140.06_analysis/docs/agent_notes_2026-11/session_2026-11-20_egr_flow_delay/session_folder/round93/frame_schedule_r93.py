"""Round 93 (read-only): the schedule of CM550's executive frame handler (0x1b876) from the ROM: the switch on the
phase index (move.w (table,pc,d0.l*2) / jmp), each case's calls (bsr.w / jsr abs.l) up to its branch to the common
exit, and per called function the phases that call it - its period (40 / calls when the phases are evenly spaced)
and first phase. Prints the per-function table and writes it as TSV.
usage: frame_schedule_r93.py <repo> <out.tsv>"""
import csv
import os
import sys

repo, out = os.path.abspath(sys.argv[1]), sys.argv[2]
rom = open(os.path.join(repo, "firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"), "rb").read()
rows = {int(r[0], 16): r[1] for r in csv.reader(open(os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/function_renames.csv"), newline=""))
        if r and r[0].startswith("0x")}
HANDLER, END = 0x1b876, 0x1bf90


def word(a):
    return int.from_bytes(rom[a:a + 2], "big")


# the switch: 'jmp (2,pc,d0.w)' = 4efb 0002 with the table right after it
j = rom.find(b"\x4e\xfb\x00\x02", HANDLER, END)
assert j != -1
table = j + 4
count = None
for k in range(j - 6, j - 20, -2):
    w = word(k)
    if (w & 0xf100) == 0x7000:
        count = (w & 0xff) + 1
        break
assert count, "no bound"
cases = [table + int.from_bytes(rom[table + 2 * n:table + 2 * n + 2], "big", signed=True) for n in range(count)]
starts = sorted(set(cases))
calls = {}
order = {}
for n, start in enumerate(cases):
    a = start
    limit = min([s for s in starts if s > start] + [END])
    seq = []
    while a < limit:
        w = word(a)
        if w == 0x6100:                                   # bsr.w
            seq.append(a + 2 + int.from_bytes(rom[a + 2:a + 4], "big", signed=True))
            a += 4
        elif w == 0x4eb9:                                 # jsr abs.l
            seq.append(int.from_bytes(rom[a + 2:a + 6], "big"))
            a += 6
        elif w == 0x4e95:                                 # jsr (a5): a5 = 0x1b4d0, the strobe wrapper
            seq.append(0x1b4d0)
            a += 2
        elif (w & 0xff00) == 0x6000:                      # bra: the case ends
            break
        else:
            a += 2
    order[n] = seq
    for t in seq:
        calls.setdefault(t, []).append(n)
print(f"switch at 0x{j:x}: {count} phases")
table_rows = []
for t in sorted(calls):
    phases = calls[t]
    n = len(phases)
    period = count // n if count % n == 0 else None
    even = period is not None and all(p == phases[0] + i * period for i, p in enumerate(phases))
    column = sorted({order[p].index(t) for p in phases})
    table_rows.append((t, rows.get(t, "(undumped)" if t >= 0x40000 else "(no row)"), n, period if even else "irregular", phases[0], column, phases))
with open(out, "w") as fh:
    fh.write("address\tname\tcalls\tperiod\tfirst_phase\tposition_in_phase\tphases\n")
    for t, name, n, period, first, column, phases in table_rows:
        fh.write(f"0x{t:05x}\t{name}\t{n}\t{period}\t{first}\t{column}\t{phases}\n")
        print(f"0x{t:05x} {name:58} calls {n:2} period {str(period):9} first phase {first:2} position {column}")
print("per phase, the number of calls:", [len(order[n]) for n in range(count)])
