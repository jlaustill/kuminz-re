"""For each call site of 0x34de0, disassemble the containing function from its start and print the
instructions before the call (context) plus a few after.
usage: callsites.py [-b N] [-a N] <site hex> ...   (site = address of the 4-byte operand, as abs_refs prints)"""
import bisect
import re
import subprocess
import sys

ROM = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"
DIS = "/home/linux/.claude/jobs/374b0424/tmp/w15/r93/tools/m68k.py"
CPP = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/frozen/cm550/J90350.00.ghidra.cpp"

starts = {}
for line in open(CPP):
    m = re.match(r"// Function: (\S+) @ 0x([0-9a-fA-F]+)", line)
    if m:
        starts[int(m.group(2), 16)] = m.group(1)
addrs = sorted(starts)

args = sys.argv[1:]
before = 14
after = 4
while args and args[0] in ("-b", "-a"):
    if args[0] == "-b":
        before = int(args[1])
    else:
        after = int(args[1])
    args = args[2:]
sites = [int(a, 16) for a in args]
cache = {}
for s in sites:
    i = bisect.bisect_right(addrs, s) - 1
    fstart = addrs[i]
    fend = addrs[i + 1] if i + 1 < len(addrs) else fstart + 0x400
    if fstart not in cache:
        out = subprocess.run(["python3", DIS, ROM, "%x" % fstart, "%x" % fend], capture_output=True, text=True).stdout
        cache[fstart] = out.splitlines()
    lines = cache[fstart]
    idx = None
    for j, l in enumerate(lines):
        if l.startswith("%06x:" % (s - 2)) or l.startswith("%06x:" % s):
            idx = j
            break
    print("===== site 0x%x in %s @ 0x%x" % (s, starts[fstart], fstart))
    if idx is None:
        print("   (call site not on an instruction boundary in disassembly)")
        continue
    for l in lines[max(0, idx - before): idx + after + 1]:
        print("   " + l)
