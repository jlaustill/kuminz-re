"""Every absolute-long ROM reference that lands inside a proposed N2 global (record or table), with the offset
inside it and the opcode words before the operand. Read-only.
usage: python3 inner_refs.py > inner_refs_out.txt"""
import json
import re

J = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/scratch/N2/judge/"
REPO = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay"
rom = open(REPO + "/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin", "rb").read()
props = json.load(open(J + "proposals_globals.json"))
ranges = []
for e in props:
    a = int(e["address"], 16)
    t = e["proposed_type"]
    size = 14 if t == "table_lookup_1d_arguments_t" else 2 * int(re.match(r"word\[(\d+)\]", t).group(1))
    ranges.append((a, a + size, e["proposed_name"]))
ranges.sort()
hits = {}
for i in range(0, len(rom) - 4, 2):
    v = int.from_bytes(rom[i:i + 4], "big")
    for lo, hi, name in ranges:
        if lo <= v < hi:
            hits.setdefault(name, []).append((v - lo, i, rom[i - 6:i].hex(" ")))
for lo, hi, name in ranges:
    hs = hits.get(name, [])
    print(f"=== 0x{lo:x} {name} size {hi - lo}: {len(hs)} refs")
    for off, loc, prev in hs:
        print(f"   +{off:#x} at 0x{loc:x} prev {prev}")
