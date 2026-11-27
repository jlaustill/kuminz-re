"""Round 93 (CM550): remove function rows that sit on a case of a switch. The compiler's switch is
'move.w (table,pc,dn.l*2),d0' + 'jmp (table,pc,d0.w)' (bytes 303b xx06 4efb 0002) followed by a table of word
offsets from the table's own address; the case count is the 'moveq #n,d1' of the bound check before it. A case is
reached only through that jmp, so a function row on a case cuts the switch's function and shows the case a second
time as a function of its own. A row is removed when it is a case target of a table, is not the function that holds
the switch, and nothing else in the dumped ROM reaches it (no aligned 4-byte occurrence of its address, no bsr / bra /
Bcc displacement). Recorded in deleted_functions.csv. Idempotent.
usage: apply_r93_switchcase.py <repo> <map.csv>"""
import csv
import os
import sys

repo, map_out = os.path.abspath(sys.argv[1]), sys.argv[2]
R = "PR #53 round 93"
O = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
rom = open(os.path.join(repo, "firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"), "rb").read()
P = os.path.join(O, "function_renames.csv")
text = open(P, newline="").read()
rows = {int(l.split(",")[0], 16): l.split(",")[1] for l in text.split("\n") if l.startswith("0x")}
ordered = sorted(rows)
relative = set()
for i in range(0, len(rom) - 4, 2):
    w = int.from_bytes(rom[i:i + 2], "big")
    if (w & 0xf000) == 0x6000:
        d8 = w & 0xff
        if d8 == 0:
            relative.add(i + 2 + int.from_bytes(rom[i + 2:i + 4], "big", signed=True))
        elif d8 != 0xff:
            relative.add(i + 2 + (d8 - 256 if d8 & 0x80 else d8))


def referenced(a):
    if a in relative:
        return True
    i = rom.find(a.to_bytes(4, "big"))
    while i != -1:
        if i % 2 == 0:
            return True
        i = rom.find(a.to_bytes(4, "big"), i + 1)
    return False


remove = []
i = rom.find(b"\x4e\xfb\x00\x02")
while i != -1:
    if i % 2 == 0 and rom[i - 4:i - 2] == b"\x30\x3b" and rom[i - 1] == 0x06:
        table = i + 4
        count = None
        for k in range(i - 6, i - 16, -2):
            w = int.from_bytes(rom[k:k + 2], "big")
            if (w & 0xf100) == 0x7000:
                count = (w & 0xff) + 1
                break
        if count:
            holder = max(a for a in ordered if a <= i)
            for n in range(count):
                case = table + int.from_bytes(rom[table + 2 * n:table + 2 * n + 2], "big", signed=True)
                if case in rows and case != holder and not referenced(case):
                    remove.append((case, rows[case], holder, n, i - 4))
    i = rom.find(b"\x4e\xfb\x00\x02", i + 1)
defs = open(os.path.join(O, "function_definitions.csv")).read().lower()
locs = open(os.path.join(O, "local_variables.csv")).read().lower()
D = os.path.join(O, "deleted_functions.csv")
deleted = open(D, newline="").read()
lines = text.split("\n")
pairs = []
for a, name, holder, n, at in remove:
    key = f"0x{a:08x}"
    assert f"\n{key}," not in defs and f"\n{key}," not in locs, f"{key} {name} has prototype / local rows"
    idx = [k for k, l in enumerate(lines) if l.lower().startswith(key + ",")]
    assert len(idx) == 1, key
    del lines[idx[0]]
    reason = (f"switch case row: case {n} of the switch at 0x{at:x} in {rows[holder]} (0x{holder:x}); reached only "
              f"through that jump table (was {name}; {R})")
    if f"\n{key}," not in deleted:
        deleted = deleted.rstrip("\n") + f"\n{key},{reason}\n"
    pairs.append((key, rows[holder], name))
if remove:
    open(P, "w", newline="").write("\n".join(lines))
    open(D, "w", newline="").write(deleted)
    with open(map_out, "w") as fh:
        fh.write("address,name,old_label,kind,dims\n")
        for key, new, old in pairs:
            fh.write(f"{key},{new},{old},symbol,1\n")
print(f"{len(remove)} switch case rows removed" + "".join(f"\n  0x{a:05x} {name}: case {n} of the switch at 0x{at:x} in {rows[h]}" for a, name, h, n, at in remove))
