"""Describer D1 scratch: list each real wrapper entry in 0x1b4d0-0x1b876 with its jsr targets and their names."""
import re

R = "/home/linux/.claude/jobs/374b0424/tmp/w15/r93"
ROM = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"
rom = open(ROM, "rb").read()
names = {}
for line in open(f"{R}/frozen/cm550/function_renames.csv"):
    p = line.rstrip("\n").split(",")
    if p[0].startswith("0x"):
        names[int(p[0], 16)] = p[1].strip()
PERIOD = {}
entries = []
a = 0x1b4d0
start = a
cur = []
while a < 0x1b876:
    w = int.from_bytes(rom[a:a + 2], "big")
    if w == 0x4eb9:
        t = int.from_bytes(rom[a + 2:a + 6], "big")
        cur.append((a, t))
        a += 6
    elif w == 0x4e75:
        entries.append((start, cur, a))
        a += 2
        start = a
        cur = []
    elif w == 0x4267 or w == 0x548f:
        a += 2
    else:
        print("unknown word %04x at %x" % (w, a))
        a += 2
for start, cur, end in entries:
    print(f"0x{start:05x} {names.get(start, '?')}  (rts at 0x{end:x})")
    for at, t in cur:
        mid = names.get(at) if at != start else None
        tn = names.get(t, "(undumped)" if t >= 0x40000 else "(no row)")
        print(f"      0x{at:05x}: jsr 0x{t:05x} {tn}" + (f"    <-- row '{mid}' sits on this jsr" if mid else ""))
    if end in names and end != start:
        print(f"      0x{end:05x}: rts    <-- row '{names[end]}' sits on this rts")
