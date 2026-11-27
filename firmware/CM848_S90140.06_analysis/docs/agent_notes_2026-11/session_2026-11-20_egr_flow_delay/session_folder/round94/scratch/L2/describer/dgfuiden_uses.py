"""Read-only: every instruction in the CM550 ROM that touches the DGFUIDEN record 0x806abc-0x806ae1, either by
absolute address or through an address register loaded with an address inside it (movea.l #addr,aN), up to the next
load of that register or the function end. Prints the instruction and whether it reads or writes.
usage: dgfuiden_uses.py"""
import bisect
import re
import subprocess

REPO = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay"
ROMP = REPO + "/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"
CPP = "/home/linux/.claude/jobs/374b0424/tmp/w15/r94/frozen/cm550/J90350.00.ghidra.cpp"
M68K = "/home/linux/.claude/jobs/374b0424/tmp/w15/r93/tools/m68k.py"
LO, HI = 0x806abc, 0x806ae2
rom = open(ROMP, "rb").read()
funcs = sorted((int(a, 16), n) for n, a in re.findall(r"^// Function: (\S+) @ 0x([0-9a-f]+)", open(CPP).read(), flags=re.M))
starts = [f[0] for f in funcs]
seen = set()
for i in range(0, len(rom) - 3, 2):
    v = int.from_bytes(rom[i:i + 4], "big")
    if LO <= v < HI:
        k = bisect.bisect_right(starts, i) - 1
        if k in seen:
            continue
        seen.add(k)
        fs, fn = funcs[k]
        fe = starts[k + 1] if k + 1 < len(starts) else fs + 0x400
        out = subprocess.run(["python3", M68K, ROMP, f"{fs:x}", f"{fe:x}"], capture_output=True, text=True).stdout.splitlines()
        regs = {}
        print(f"== {fn} @0x{fs:x}")
        for line in out:
            m = re.match(r"([0-9a-f]+):\s+\S+\s+(.*)", line)
            if not m:
                continue
            ins = m.group(2)
            ml = re.match(r"(movea\.l|lea) #?\(?0x([0-9a-f]+)\)?(?:\.l)?,(a\d)", ins)
            hit_abs = re.search(r"0x(80[0-9a-f]{4})", ins)
            if ml:
                addr = int(ml.group(2), 16)
                if LO <= addr < HI:
                    regs[ml.group(3)] = addr
                    print(f"   {m.group(1)}: {ins}    [load {ml.group(3)} = word {(addr - LO) // 2}]")
                    continue
                regs.pop(ml.group(3), None)
                continue
            mm = re.match(r"movea\.l (a\d),(a\d)", ins)
            if mm and mm.group(1) in regs:
                regs[mm.group(2)] = regs[mm.group(1)]
                print(f"   {m.group(1)}: {ins}    [copy -> {mm.group(2)}]")
                continue
            ma = re.match(r"addq\.l #(\d+),(a\d)", ins)
            if ma and ma.group(2) in regs:
                regs[ma.group(2)] += int(ma.group(1))
                print(f"   {m.group(1)}: {ins}    [{ma.group(2)} = word {(regs[ma.group(2)] - LO) // 2}]")
                continue
            if hit_abs and LO <= int(hit_abs.group(1), 16) < HI:
                print(f"   {m.group(1)}: {ins}    [abs word {(int(hit_abs.group(1), 16) - LO) // 2}]")
                continue
            for r, addr in regs.items():
                if f"({r})" in ins or f",{r})" in ins or re.search(rf"\(0x[0-9a-f]+,{r}", ins) or f"({r}," in ins:
                    # destination if the register operand is after the comma
                    parts = ins.split(" ", 1)[1] if " " in ins else ""
                    dest = parts.split(",")[-1] if "," in parts else parts
                    kind = "WRITE?" if r in dest and not ins.startswith(("cmp", "tst", "btst", "move.w (", "move.b (", "move.l (")) else "read"
                    if ins.startswith(("move.w (", "move.b (", "move.l (")) and r in dest:
                        kind = "WRITE?"
                    print(f"   {m.group(1)}: {ins}    [{r} = word {(addr - LO) // 2}; {kind}]")
