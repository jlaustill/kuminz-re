"""Skeptic: disassemble around a ROM offset. Sweeps from the containing function's start (function list from the
.cpp's '// Function: name @ 0x...' lines) and prints the instructions from SITE - BEFORE to SITE + AFTER.
usage: site.py SITE [BEFORE [AFTER]]   (hex)"""
import re
import sys

sys.path.insert(0, "/home/linux/.claude/jobs/374b0424/tmp/w15/r92/scratch/W1/skeptic")
import m68k  # noqa: E402

CPP = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/output/J90350.00.ghidra.cpp"
funcs = []
for line in open(CPP, errors="replace"):
    m = re.match(r"^// Function: (\S+) @ 0x([0-9a-fA-F]+)", line)
    if m:
        funcs.append((int(m.group(2), 16), m.group(1)))
funcs.sort()


def func_of(a):
    best = None
    for fa, fn in funcs:
        if fa <= a:
            best = (fa, fn)
        else:
            break
    return best


def show(site, before=0x30, after=0x40):
    f = func_of(site)
    start = f[0] if f else site
    rows = m68k.disassemble(start, site + after)
    starts = {r[0] for r in rows}
    aligned = site in starts
    print("== site 0x%x in %s @0x%x%s" % (site, f[1] if f else "?", start, "" if aligned else "  (SWEEP NOT ALIGNED AT SITE - resweeping from site)"))
    if not aligned:
        rows = m68k.disassemble(site, site + after)
    for pc, raw, text in rows:
        if site - before <= pc < site + after:
            print("%s%06x  %-20s %s" % (">" if pc == site else " ", pc, raw, text))


if __name__ == "__main__":
    site = int(sys.argv[1], 16)
    before = int(sys.argv[2], 16) if len(sys.argv) > 2 else 0x30
    after = int(sys.argv[3], 16) if len(sys.argv) > 3 else 0x40
    show(site, before, after)
