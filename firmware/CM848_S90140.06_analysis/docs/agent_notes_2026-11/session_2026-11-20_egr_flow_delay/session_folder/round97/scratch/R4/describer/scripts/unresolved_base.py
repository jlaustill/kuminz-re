"""Count (d16,An) operands per address register whose base the function never loaded (movea/lea/move to An) before
the use: a global base register (a4/a5/a6 set once at start-up) would show up as many unresolved uses.
usage: unresolved_base.py"""
import collections
import re
import sys

sys.path.insert(0, "/home/linux/.claude/jobs/374b0424/tmp/w15/r93/tools")
import m68k  # noqa: E402

CPP = "/home/linux/.claude/jobs/374b0424/tmp/w15/r97/frozen/cm550/J90350.00.ghidra.cpp"
ROM = ("/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/"
       "firmware/J90350.00.rom.bin")
text = open(CPP, errors="replace").read()
funcs = sorted((int(m.group(2), 16), m.group(1))
               for m in re.finditer(r"^// Function: (\S+) @ (?:0x)?([0-9a-fA-F]+)", text, flags=re.M))
rom = open(ROM, "rb").read()
counts = collections.Counter()
examples = collections.defaultdict(list)
for idx, (start, name) in enumerate(funcs):
    end = funcs[idx + 1][0] if idx + 1 < len(funcs) else start + 0x400
    end = min(end, start + 0x4000, len(rom))
    written = set()
    try:
        lines = m68k.disassemble(rom, start, end)
    except Exception:  # noqa: BLE001
        continue
    for addr, raw, ins in lines:
        for om in re.finditer(r"\((-?)0x([0-9a-f]+),a(\d)\)", ins):
            r = int(om.group(3))
            if r != 7 and r not in written:
                counts[r] += 1
                if len(examples[r]) < 6:
                    examples[r].append(f"{name}@0x{addr:x}: {ins}")
        dm = re.search(r",a(\d)$", ins)
        if dm:
            written.add(int(dm.group(1)))
        if ins.startswith("link"):
            written.add(int(ins.split()[1][1]))
for r in sorted(counts):
    print(f"a{r}: {counts[r]} unresolved (d16,a{r}) uses")
    for e in examples[r]:
        print("    " + e)
