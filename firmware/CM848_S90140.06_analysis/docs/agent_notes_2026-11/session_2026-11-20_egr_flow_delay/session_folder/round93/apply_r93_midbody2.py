"""Round 93 (CM550): remove the other function rows that sit in the middle of a function (the executive frame task
set layer was done by apply_r93_midbody.py). A row is removed only when all of this holds, checked here from the ROM:
- the dumped ROM never enters its address: no aligned 4-byte occurrence of the address (jsr / jmp operands and
  pointers) and no bsr / bra / Bcc displacement that lands on it;
- a linear disassembly from the function row before it reaches the address exactly on an instruction boundary;
- the instruction before it does not leave (not rts / rte / rtd / jmp / bra), so the code runs into it;
- no function_definitions.csv / local_variables.csv row hangs on it.
Such a row cuts a function in two: the .cpp shows the tail a second time as a function with a name of its own (often
the whole function again, 4 bytes after its real entry, without its stack frame).
The rows are removed and recorded in deleted_functions.csv with the function that holds each one; the refresh map
sends each removed name to that function. Idempotent. usage: apply_r93_midbody2.py <repo> <m68k.py> <map.csv>"""
import csv
import os
import subprocess
import sys

repo, tool, map_out = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]
R = "PR #53 round 93"
O = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
rom_path = os.path.join(repo, "firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin")
rom = open(rom_path, "rb").read()
P = os.path.join(O, "function_renames.csv")
text = open(P, newline="").read()
rows = sorted((int(l.split(",")[0], 16), l.split(",")[1]) for l in text.split("\n")
              if l.startswith("0x") and int(l.split(",")[0], 16) < len(rom))
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


defs = open(os.path.join(O, "function_definitions.csv")).read().lower()
locs = open(os.path.join(O, "local_variables.csv")).read().lower()
remove = []          # (address, name, instruction before it)
for k, (a, name) in enumerate(rows):
    if k == 0 or referenced(a):
        continue
    prev = rows[k - 1][0]
    out = subprocess.run([sys.executable, tool, rom_path, f"{prev:x}", f"{a + 2:x}"], capture_output=True, text=True, check=True).stdout
    lines = [l for l in out.splitlines() if ":" in l[:8]]
    addresses = [int(l.split(":")[0], 16) for l in lines]
    if a not in addresses or addresses.index(a) == 0:
        continue                                    # not on an instruction boundary of the code before it
    before = " ".join(lines[addresses.index(a) - 1].split()[2:])
    if before.startswith(("rts", "rte", "rtd", "jmp", "bra")) or before.startswith(".word"):
        continue                                    # an entry after a leave (called from the undumped ROM, or dead)
    key = f"0x{a:08x}"
    assert f"\n{key}," not in defs and f"\n{key}," not in locs, f"{key} {name} has prototype / local rows"
    remove.append((a, name, before))
gone = {a for a, _, _ in remove}
survivors = [(a, n) for a, n in rows if a not in gone]
D = os.path.join(O, "deleted_functions.csv")
deleted = open(D, newline="").read()
lines = text.split("\n")
pairs = []
for a, name, before in remove:
    key = f"0x{a:08x}"
    container = max((x for x in survivors if x[0] < a), key=lambda x: x[0])
    idx = [i for i, l in enumerate(lines) if l.lower().startswith(key + ",")]
    assert len(idx) == 1, key
    del lines[idx[0]]
    reason = (f"mid-function row: {a - container[0]} bytes into {container[1]} (0x{container[0]:x}), after "
              f"'{before}'; no call / branch / pointer in the dumped ROM reaches it (was {name}; {R})")
    if f"\n{key}," not in deleted:
        deleted = deleted.rstrip("\n") + f"\n{key},{reason}\n"
    if name not in {n for _, n in survivors}:
        pairs.append((key, container[1], name))
if remove:
    open(P, "w", newline="").write("\n".join(lines))
    open(D, "w", newline="").write(deleted)
    with open(map_out, "w") as fh:
        fh.write("address,name,old_label,kind,dims\n")
        for key, new, old in pairs:
            fh.write(f"{key},{new},{old},symbol,1\n")
print(f"{len(rows)} function rows; {len(remove)} mid-function rows removed")
for a, name, before in remove:
    container = max((x for x in survivors if x[0] < a), key=lambda x: x[0])
    print(f"  0x{a:05x} {name} -> inside {container[1]} (0x{container[0]:x}) +{a - container[0]}, after '{before}'")
