"""For each row name in the Q5 range, list the functions of the frozen CM848 decompile that mention it (with
the function address, BOOT < 0x7f60 <= APP) and one sample line per function."""
import re
import sys

CPP = "/home/linux/.claude/jobs/374b0424/tmp/w15/r96/frozen/cm848/cm848_rom.ghidra.cpp"
names = sys.argv[1:]
pat = re.compile(r"^// Function: (\S+) @ 0x([0-9a-fA-F]+)")
cur = ("?", 0)
hits = {n: {} for n in names}
regs = {n: re.compile(r"(?<![A-Za-z0-9_])_?" + re.escape(n) + r"(?![A-Za-z0-9_])") for n in names}
for line in open(CPP, errors="replace"):
    m = pat.match(line)
    if m:
        cur = (m.group(1), int(m.group(2), 16))
        continue
    if line.lstrip().startswith("//") or line.lstrip().startswith("/*"):
        continue
    for n in names:
        if n in line and regs[n].search(line):
            d = hits[n]
            if cur not in d:
                d[cur] = line.strip()[:150]
for n in names:
    print(f"== {n}: {len(hits[n])} functions")
    for (f, a), s in sorted(hits[n].items(), key=lambda x: x[0][1]):
        side = "BOOT" if a < 0x7f60 else "APP "
        print(f"   {side} {f} @0x{a:x}: {s}")
