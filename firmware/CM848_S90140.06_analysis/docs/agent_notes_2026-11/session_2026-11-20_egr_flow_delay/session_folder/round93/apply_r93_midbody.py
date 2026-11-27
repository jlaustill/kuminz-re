"""Round 93 (CM550): remove the function rows that sit in the middle of the executive frame task sets.
executiveFrameInterruptHandler (0x1b876) runs 40 phases; each phase calls a few task sets with bsr.w, and a task set
is a straight list of jsr instructions ending in rts. 21 function_renames.csv rows name an address inside such a
list (the 4th jsr of 0x1b4d8, a list's own rts, ...). Nothing in the dumped ROM reaches them - no jsr / jmp with
their address, no bsr / bra / Bcc displacement, no pointer (call_sites_r93.py) - and the instruction before each one
runs into it. Each row forces Ghidra to cut a function there, so the .cpp repeats the list's tail under a name of
its own; one of them (0x1b62a) carries the name of the task set at 0x1b4d8, vp44_evenPhaseSchedulerTaskSet.

This script checks each row again from the ROM (the same scan, and that the address is inside the list of the entry
before it), removes the rows (function_definitions.csv / local_variables.csv rows of those addresses too) and
records the addresses in deleted_functions.csv. It writes a refresh map: each removed name -> the task set that
holds it (not for the repeated name). Idempotent. usage: apply_r93_midbody.py <repo> <map.csv>"""
import csv
import os
import re
import sys

repo, map_out = os.path.abspath(sys.argv[1]), sys.argv[2]
R = "PR #53 round 93"
O = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
rom = open(os.path.join(repo, "firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"), "rb").read()
LAYER = (0x1b4d0, 0x1b876)          # cm550_ioDriverStrobeHandlerWrapper .. executiveFrameInterruptHandler
RTS, JSR, JMP = 0x4e75, 0x4eb9, 0x4ef9


def word(a):
    return int.from_bytes(rom[a:a + 2], "big")


def reached(a):
    """Every way the dumped ROM can enter address a."""
    hits = []
    pat = a.to_bytes(4, "big")
    i = rom.find(pat)
    while i != -1:
        if i % 2 == 0:
            hits.append(f"0x{i:x}")
        i = rom.find(pat, i + 1)
    for i in range(0, len(rom) - 4, 2):
        w = word(i)
        if (w & 0xf000) == 0x6000:
            d8 = w & 0xff
            if d8 == 0:
                target = i + 2 + int.from_bytes(rom[i + 2:i + 4], "big", signed=True)
            elif d8 != 0xff:
                target = i + 2 + (d8 - 256 if d8 & 0x80 else d8)
            else:
                continue
            if target == a:
                hits.append(f"0x{i:x}")
    return hits


# The layer as lists: an entry, then jsr (6 bytes) / clr.w -(a7) / addq.l #2,a7 (2 bytes) until rts.
lists, a = [], LAYER[0]
while a < LAYER[1]:
    start, body = a, []
    while True:
        w = word(a)
        body.append(a)
        if w == RTS:
            a += 2
            break
        assert w in (JSR, 0x4267, 0x548f), f"0x{a:x}: unexpected opcode {w:04x} in the task set layer"
        a += 6 if w == JSR else 2
    lists.append((start, body))
entries = {s for s, _ in lists}
holder = {x: s for s, body in lists for x in body}

P = os.path.join(O, "function_renames.csv")
text = open(P, newline="").read()
names = {}
for line in text.split("\n"):
    parts = line.split(",", 2)
    if len(parts) > 1 and parts[0].startswith("0x"):
        names.setdefault(int(parts[0], 16), parts[1])
remove = []
for addr in sorted(names):
    if LAYER[0] <= addr < LAYER[1] and addr not in entries:
        assert addr in holder, f"0x{addr:x} is not on an instruction boundary of a task set"
        hits = reached(addr)
        assert not hits, f"0x{addr:x} {names[addr]} is reached from {hits}"
        remove.append(addr)
for s in sorted(entries):
    if s in names and s != LAYER[0]:
        assert reached(s), f"task set 0x{s:x} {names[s]} has no caller"
D = os.path.join(O, "deleted_functions.csv")
deleted = open(D, newline="").read()
lines = text.split("\n")
pairs = []
for addr in remove:
    key = f"0x{addr:08x}"
    idx = [i for i, l in enumerate(lines) if l.lower().startswith(key + ",")]
    assert len(idx) == 1, key
    name = lines[idx[0]].split(",")[1]
    del lines[idx[0]]
    container = holder[addr]
    what = "its rts" if word(addr) == RTS else f"the jsr at 0x{addr:x}"
    reason = (f"mid-body row of the executive frame task set {names[container]} (0x{container:x}): {what} of that "
              f"straight jsr list; no call / branch / pointer in the dumped ROM reaches it (was {name}; {R})")
    if f"\n{key}," not in deleted:
        deleted = deleted.rstrip("\n") + f"\n{key},{reason}\n"
    if name not in {n for a, n in names.items() if a not in remove}:      # not the name another function keeps
        pairs.append((key, names[container], name))
for k in ("function_definitions.csv", "local_variables.csv"):
    p = os.path.join(O, k)
    t = open(p, newline="").read()
    keep = [l for l in t.split("\n") if not any(l.lower().startswith(f"0x{a:08x},") for a in remove)]
    if "\n".join(keep) != t:
        open(p, "w", newline="").write("\n".join(keep))
if remove:
    open(P, "w", newline="").write("\n".join(lines))
    open(D, "w", newline="").write(deleted)
    with open(map_out, "w") as fh:
        fh.write("address,name,old_label,kind,dims\n")
        for key, new, old in pairs:
            fh.write(f"{key},{new},{old},symbol,1\n")
print(f"{len(lists)} task sets in 0x{LAYER[0]:x}-0x{LAYER[1]:x}; {len(remove)} mid-body rows removed"
      + (": " + " ".join(f"{a:x}" for a in remove) if remove else ""))
