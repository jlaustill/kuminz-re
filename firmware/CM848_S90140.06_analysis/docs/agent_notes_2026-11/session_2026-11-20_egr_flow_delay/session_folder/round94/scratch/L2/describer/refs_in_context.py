"""For each address, find every absolute-long reference in the CM550 ROM, locate the enclosing function start
(from the .cpp function headers), disassemble that function with m68k.py and print the line that holds the address
plus the function name. usage: refs_in_context.py <addr hex>..."""
import bisect
import re
import subprocess
import sys

REPO = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay"
ROMP = REPO + "/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"
CPP = "/home/linux/.claude/jobs/374b0424/tmp/w15/r94/frozen/cm550/J90350.00.ghidra.cpp"
M68K = "/home/linux/.claude/jobs/374b0424/tmp/w15/r93/tools/m68k.py"
rom = open(ROMP, "rb").read()
funcs = sorted((int(a, 16), n) for n, a in re.findall(r"^// Function: (\S+) @ 0x([0-9a-f]+)", open(CPP).read(), flags=re.M))
starts = [f[0] for f in funcs]
cache = {}


def dis(start, end):
    key = (start, end)
    if key not in cache:
        out = subprocess.run(["python3", M68K, ROMP, f"{start:x}", f"{end:x}"], capture_output=True, text=True).stdout
        cache[key] = out.splitlines()
    return cache[key]


for arg in sys.argv[1:]:
    a = int(arg, 16)
    pat = a.to_bytes(4, "big")
    i = rom.find(pat)
    print(f"== 0x{a:x}")
    while i != -1:
        k = bisect.bisect_right(starts, i) - 1
        fs, fn = funcs[k]
        fe = starts[k + 1] if k + 1 < len(starts) else fs + 0x400
        lines = dis(fs, fe)
        best = None
        for line in lines:
            m = re.match(r"([0-9a-f]+):", line)
            if m:
                la = int(m.group(1), 16)
                if la <= i < la + 10 and f"{a:x}" in line:
                    best = line
        print(f"  ref 0x{i:x} in {fn} @0x{fs:x}: {best.strip() if best else '(not decoded)'}")
        i = rom.find(pat, i + 1)
