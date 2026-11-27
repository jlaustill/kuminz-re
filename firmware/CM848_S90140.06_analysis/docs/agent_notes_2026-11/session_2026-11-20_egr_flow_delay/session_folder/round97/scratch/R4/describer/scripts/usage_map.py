"""For each family global: functions whose decompiled body names it, and the ROM absolute-long references mapped to
their containing function (function starts from the .cpp '// Function: name @ addr' lines).
usage: usage_map.py [<family file>] [extra 0xADDR ...]"""
import bisect
import re
import sys

CPP = "/home/linux/.claude/jobs/374b0424/tmp/w15/r97/frozen/cm550/J90350.00.ghidra.cpp"
ROM = ("/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/"
       "firmware/J90350.00.rom.bin")
GLOBALS = "/home/linux/.claude/jobs/374b0424/tmp/w15/r97/frozen/cm550/global_variables.csv"
FAM = sys.argv[1] if len(sys.argv) > 1 and not sys.argv[1].startswith("0x") else \
    "/home/linux/.claude/jobs/374b0424/tmp/w15/r97/family_R4.txt"
extra = [x for x in sys.argv[1:] if x.startswith("0x")]

text = open(CPP, errors="replace").read()
funcs = []
for m in re.finditer(r"^// Function: (\S+) @ (?:0x)?([0-9a-fA-F]+)", text, flags=re.M):
    funcs.append((int(m.group(2), 16), m.group(1), m.start()))
spans = sorted(funcs, key=lambda f: f[2])
bodies = {}
for i, (a, n, s) in enumerate(spans):
    e = spans[i + 1][2] if i + 1 < len(spans) else len(text)
    bodies[n] = text[s:e]
funcs.sort()
starts = [f[0] for f in funcs]
rom = open(ROM, "rb").read()


def containing(addr):
    i = bisect.bisect_right(starts, addr) - 1
    return funcs[i][1] if i >= 0 else "?"


names = {}
for line in open(GLOBALS, errors="replace"):
    parts = line.split(",")
    if len(parts) > 1 and parts[0].startswith("0x"):
        names[int(parts[0], 16)] = parts[1]

targets = []
if not extra:
    for line in open(FAM):
        if line.strip():
            targets.append(int(line.split()[0], 16))
targets += [int(x, 16) for x in extra]
for addr in targets:
    n = names.get(addr, "")
    users = sorted({fn for fn, b in bodies.items() if n and re.search(rf"\b_?{re.escape(n)}\b", b)})
    pat = addr.to_bytes(4, "big")
    refs = []
    i = rom.find(pat)
    while i != -1:
        refs.append(f"0x{i:x}:{containing(i)}")
        i = rom.find(pat, i + 1)
    print(f"0x{addr:08x} {n}\n   cpp: {', '.join(users) or '-'}\n   rom: {' '.join(refs) or '-'}")
