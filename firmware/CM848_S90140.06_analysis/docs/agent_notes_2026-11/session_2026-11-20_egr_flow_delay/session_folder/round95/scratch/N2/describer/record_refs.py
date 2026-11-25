"""Every absolute-long reference in the CM550 ROM to any byte of a 14-byte record (rec+0 .. rec+13), with the
containing function and the instruction at the reference (decoded with m68k.py).
usage: record_refs.py [-n LEN] <record hex> ..."""
import bisect
import re
import subprocess
import sys

ROMP = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"
DIS = "/home/linux/.claude/jobs/374b0424/tmp/w15/r93/tools/m68k.py"
CPP = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/frozen/cm550/J90350.00.ghidra.cpp"
rom = open(ROMP, "rb").read()
starts = {}
for line in open(CPP):
    m = re.match(r"// Function: (\S+) @ 0x([0-9a-fA-F]+)", line)
    if m:
        starts[int(m.group(2), 16)] = m.group(1)
addrs = sorted(starts)
cache = {}


def func_lines(fstart, fend):
    if fstart not in cache:
        out = subprocess.run(["python3", DIS, ROMP, "%x" % fstart, "%x" % fend], capture_output=True, text=True).stdout
        cache[fstart] = out.splitlines()
    return cache[fstart]


def instr_at(ref):
    """The disassembled instruction that contains the operand at ref."""
    i = bisect.bisect_right(addrs, ref) - 1
    if i < 0:
        return "?", "?"
    fstart = addrs[i]
    fend = addrs[i + 1] if i + 1 < len(addrs) else fstart + 0x400
    best = None
    for l in func_lines(fstart, fend):
        m = re.match(r"([0-9a-f]{6}):", l)
        if not m:
            continue
        a = int(m.group(1), 16)
        if a <= ref:
            best = l
        else:
            break
    return starts[fstart], best


length = 14
args = sys.argv[1:]
if args and args[0] == "-n":
    length = int(args[1])
    args = args[2:]
for arg in args:
    rec = int(arg, 16)
    print("===== record 0x%x" % rec)
    for off in range(length):
        pat = (rec + off).to_bytes(4, "big")
        i = rom.find(pat)
        while i != -1:
            if i % 2 == 0:
                fn, ins = instr_at(i)
                print("  +%-2d ref@0x%x %-50s %s" % (off, i, fn, ins))
            i = rom.find(pat, i + 1)
