"""Round 93 J1 describer (read-only): which CM550 functions touch bit 0 of the system error status word 0 (0x806000)
or of the first-occurrence word 0 (0x806040) with an immediate ori.w / andi.w / btst."""
import bisect
import csv

REPO = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay"
FROZEN = "/home/linux/.claude/jobs/374b0424/tmp/w15/r93/frozen"
rom = open(REPO + "/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin", "rb").read()
rows = sorted((int(r[0], 16), r[1]) for r in csv.reader(open(FROZEN + "/cm550/function_renames.csv")) if r and r[0].startswith("0x"))
addrs = [a for a, _ in rows]


def owner(pc):
    k = bisect.bisect_right(addrs, pc) - 1
    return f"{rows[k][1]}@0x{rows[k][0]:x}"


for label, pat in (
    ("ori.w #1,(0x806000)", bytes.fromhex("0079000100806000")),
    ("andi.w #0xfffe,(0x806000)", bytes.fromhex("0279fffe00806000")),
    ("ori.w #1,(0x806040)", bytes.fromhex("0079000100806040")),
    ("andi.w #0xfffe,(0x806040)", bytes.fromhex("0279fffe00806040")),
):
    i = rom.find(pat)
    while i != -1:
        if i % 2 == 0:
            print(f"0x{i:05x} {label:28s} {owner(i)}")
        i = rom.find(pat, i + 2)
