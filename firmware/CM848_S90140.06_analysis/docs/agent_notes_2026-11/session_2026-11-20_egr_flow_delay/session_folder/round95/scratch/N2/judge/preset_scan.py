"""Every 'move.w #2,(abs).l' (33fc 0002 <addr>) in the CM550 ROM whose target is in RAM, classified: inside a
proposed N2 1-D record, inside a typed table_lookup_2d_arguments_t record, or other (with the frozen row there).
usage: python3 preset_scan.py"""
import csv
import json

J = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/scratch/N2/judge/"
F = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/frozen/cm550/"
REPO = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay"
rom = open(REPO + "/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin", "rb").read()
props = json.load(open(J + "proposals_globals.json"))
rec1 = [int(e["address"], 16) for e in props if e["proposed_type"] == "table_lookup_1d_arguments_t"]
rows = {}
rec2 = []
for r in csv.reader(open(F + "global_variables.csv")):
    if r and r[0].startswith("0x"):
        a = int(r[0], 16)
        rows[a] = (r[1], r[2])
        if r[2] == "table_lookup_2d_arguments_t":
            rec2.append(a)
for i in range(0, len(rom) - 8, 2):
    if rom[i:i + 4] == b"\x33\xfc\x00\x02":
        t = int.from_bytes(rom[i + 4:i + 8], "big")
        if not 0x800000 <= t < 0x810000:
            continue
        kind = "other"
        if any(r <= t < r + 14 for r in rec1):
            kind = "1d"
        elif any(r <= t < r + 22 for r in rec2):
            kind = "2d"
        if kind == "other":
            print(f"0x{i:x}: move.w #2,(0x{t:x}).l  row {rows.get(t)}")
