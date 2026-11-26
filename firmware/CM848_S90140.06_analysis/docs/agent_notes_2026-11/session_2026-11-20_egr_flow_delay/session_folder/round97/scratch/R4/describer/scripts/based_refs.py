"""Linear sweep of every CM550 function (starts from the .cpp '// Function:' lines, end = next start) with the r93 m68k
decoder. Tracks address registers loaded by 'movea.l #imm,An' / 'lea (imm).l,An' (cleared at every other write to An,
at jsr/bsr and at labels we cannot follow) and resolves (An), (An)+, -(An), (d16,An) and (abs).l operands.
Prints every access that hits one of the given [lo, hi] ranges with the instruction text.
usage: based_refs.py 0xLO 0xHI [0xLO 0xHI ...]"""
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
args = [int(x, 16) for x in sys.argv[1:]]
ranges = list(zip(args[0::2], args[1::2]))


def hit(a):
    return any(lo <= a <= hi for lo, hi in ranges)


load_re = re.compile(r"^(?:movea\.l #0x([0-9a-f]+)|lea \(0x([0-9a-f]+)\)\.l),a(\d)$")
op_re = re.compile(r"\((-?)0x([0-9a-f]+),a(\d)\)|\(a(\d)\)\+?|-\(a(\d)\)|\(0x([0-9a-f]+)\)\.l")
for idx, (start, name) in enumerate(funcs):
    end = funcs[idx + 1][0] if idx + 1 < len(funcs) else min(start + 0x2000, len(rom))
    if end - start > 0x4000 or start >= len(rom):
        end = min(start + 0x4000, len(rom))
    regs = {}
    try:
        lines = m68k.disassemble(rom, start, end)
    except Exception:  # noqa: BLE001
        continue
    for addr, raw, ins in lines:
        m = load_re.match(ins)
        if m:
            regs[int(m.group(3))] = int(m.group(1) or m.group(2), 16)
            continue
        for om in op_re.finditer(ins):
            if om.group(3) is not None:
                r = int(om.group(3))
                if r in regs:
                    d = int(om.group(2), 16) * (-1 if om.group(1) else 1)
                    a = regs[r] + d
                    if hit(a):
                        print(f"0x{a:x} <- {name} @0x{addr:x}: {ins}   [a{r}=0x{regs[r]:x}]")
            elif om.group(4) is not None or om.group(5) is not None:
                r = int(om.group(4) or om.group(5))
                if r in regs and hit(regs[r]):
                    print(f"0x{regs[r]:x} <- {name} @0x{addr:x}: {ins}   [a{r}]")
            elif om.group(6) is not None:
                a = int(om.group(6), 16)
                if hit(a):
                    print(f"0x{a:x} <- {name} @0x{addr:x}: {ins}")
        # invalidate address registers written by this instruction (destination a<n>, or post/pre-modified)
        dm = re.search(r",a(\d)$", ins)
        if dm and not load_re.match(ins):
            regs.pop(int(dm.group(1)), None)
        for pm in re.finditer(r"\(a(\d)\)\+|-\(a(\d)\)", ins):
            r = int(pm.group(1) or pm.group(2))
            # keep tracking the moving pointer: post-increment by access size
            if r in regs:
                size = {"b": 1, "w": 2, "l": 4}.get(ins.split()[0].split(".")[-1], 2)
                regs[r] += size if pm.group(1) else -size
        if ins.startswith(("jsr", "bsr", "rts", "rte", "movem.l (a7)+")):
            if ins.startswith(("jsr", "bsr")):
                for r in (0, 1):
                    regs.pop(r, None)
