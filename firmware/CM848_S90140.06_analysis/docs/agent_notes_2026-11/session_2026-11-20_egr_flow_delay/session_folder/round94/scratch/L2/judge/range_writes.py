#!/usr/bin/env python3
"""Read-only. For a RAM range [LO, HI) of CM550, disassemble every function (frozen .cpp boundaries) that holds a
32-bit operand inside the range or inside [LO-0x40, HI+0x40) (base +/- displacement), track address registers loaded
with such an address (movea.l #x,aN / lea x,aN / movea.l aM,aN copies / addq/subq/lea (d,aN),aN adjust), and print every
instruction that touches the range, marked READ or WRITE (destination operand / read-modify-write / bit change).
usage: range_writes.py LO HI"""
import bisect, re, subprocess, sys
REPO = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay"
ROMP = REPO + "/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"
CPP = "/home/linux/.claude/jobs/374b0424/tmp/w15/r94/frozen/cm550/J90350.00.ghidra.cpp"
M68K = "/home/linux/.claude/jobs/374b0424/tmp/w15/r93/tools/m68k.py"
LO, HI = int(sys.argv[1], 16), int(sys.argv[2], 16)
SLACK = 0x80
rom = open(ROMP, "rb").read()
funcs = sorted(set((int(a, 16), n) for n, a in re.findall(r"^// Function: (\S+) @ 0x([0-9a-f]+)", open(CPP).read(), flags=re.M)))
starts = [f[0] for f in funcs]
hits = set()
for i in range(0, len(rom) - 3, 2):
    v = int.from_bytes(rom[i:i + 4], "big")
    if LO - SLACK <= v < HI + SLACK:
        k = bisect.bisect_right(starts, i) - 1
        if k >= 0:
            hits.add(k)
NOWRITE = ("cmp", "tst", "btst", "chk", "pea", "lea", "jsr", "jmp", "movea", "adda", "suba", "cmpa")
ONEOP_WRITE = ("clr", "not", "neg", "negx", "st", "sf", "tas", "nbcd", "s")
def split_ops(s):
    out, depth, cur = [], 0, ""
    for ch in s:
        if ch == "(":
            depth += 1
        elif ch == ")":
            depth -= 1
        if ch == "," and depth == 0:
            out.append(cur); cur = ""
        else:
            cur += ch
    if cur:
        out.append(cur)
    return [o.strip() for o in out]
def ea_addr(op, regs):
    """address an operand designates, if it is inside [LO,HI) (None if unknown / outside)"""
    m = re.fullmatch(r"\(0x([0-9a-f]+)\)(?:\.[lw])?", op)
    if m:
        a = int(m.group(1), 16)
        return a if LO <= a < HI else None
    m = re.fullmatch(r"\((?:(-?0x[0-9a-f]+|-?\d+),)?(a\d)(?:,([ad]\d)\.[wl](?:\*\d)?)?\)\+?", op) or re.fullmatch(r"-\((a\d)\)", op)
    if m:
        if op.startswith("-("):
            r = m.group(1); d = 0; idx = None
        else:
            d = int(m.group(1), 16) if m.group(1) and "0x" in m.group(1) else (int(m.group(1)) if m.group(1) else 0)
            r = m.group(2); idx = m.group(3)
        if r in regs:
            a = regs[r] + d
            if idx:
                return ("indexed", a)
            return a if LO <= a < HI else ("near", a)
    return None
for k in sorted(hits):
    fs, fn = funcs[k]
    fe = starts[k + 1] if k + 1 < len(starts) else fs + 0x400
    out = subprocess.run(["python3", M68K, ROMP, f"{fs:x}", f"{fe:x}"], capture_output=True, text=True).stdout.splitlines()
    regs = {}
    lines = []
    for line in out:
        m = re.match(r"([0-9a-f]+):\s+[0-9a-f]+\s+(\S+)\s*(.*)$", line)
        if not m:
            continue
        addr, mn, opstr = m.group(1), m.group(2), m.group(3)
        ops = split_ops(opstr)
        base = mn.split(".")[0]
        # register loads
        if base in ("movea", "lea") and len(ops) == 2 and re.fullmatch(r"a\d", ops[1]):
            src = ops[0]
            mi = re.fullmatch(r"#0x([0-9a-f]+)", src) or re.fullmatch(r"\(0x([0-9a-f]+)\)(?:\.[lw])?", src) if base == "lea" or src.startswith("#") else None
            if base == "movea" and src.startswith("#"):
                v = int(src[3:], 16) if src.startswith("#0x") else None
                if v is not None and LO - SLACK <= v < HI + SLACK:
                    regs[ops[1]] = v
                    lines.append(f"   {addr}: {mn} {opstr}    [LOAD {ops[1]}=0x{v:x}]")
                else:
                    regs.pop(ops[1], None)
                continue
            if base == "lea":
                ml = re.fullmatch(r"\(0x([0-9a-f]+)\)(?:\.[lw])?", src)
                md = re.fullmatch(r"\((-?0x[0-9a-f]+),(a\d)\)", src)
                if ml:
                    v = int(ml.group(1), 16)
                    if LO - SLACK <= v < HI + SLACK:
                        regs[ops[1]] = v; lines.append(f"   {addr}: {mn} {opstr}    [LOAD {ops[1]}=0x{v:x}]")
                    else:
                        regs.pop(ops[1], None)
                    continue
                if md and md.group(2) in regs:
                    regs[ops[1]] = regs[md.group(2)] + int(md.group(1), 16); lines.append(f"   {addr}: {mn} {opstr}    [ADJ {ops[1]}=0x{regs[ops[1]]:x}]"); continue
                regs.pop(ops[1], None); continue
            if base == "movea" and re.fullmatch(r"a\d", src):
                if src in regs:
                    regs[ops[1]] = regs[src]; lines.append(f"   {addr}: {mn} {opstr}    [COPY {ops[1]}=0x{regs[src]:x}]")
                else:
                    regs.pop(ops[1], None)
                continue
            regs.pop(ops[1], None)
            continue
        if base in ("addq", "subq", "adda", "suba") and len(ops) == 2 and ops[1] in regs:
            mi = re.fullmatch(r"#(0x[0-9a-f]+|\d+)", ops[0])
            if mi:
                v = int(mi.group(1), 0)
                regs[ops[1]] += v if base in ("addq", "adda") else -v
                lines.append(f"   {addr}: {mn} {opstr}    [ADJ {ops[1]}=0x{regs[ops[1]]:x}]")
            else:
                lines.append(f"   {addr}: {mn} {opstr}    [ADJ {ops[1]} by register - lost]"); regs.pop(ops[1], None)
            continue
        if base in ("jsr", "bsr", "rts"):
            pass
        touched = []
        for idx, op in enumerate(ops):
            a = ea_addr(op, regs)
            if a is not None:
                touched.append((idx, op, a))
        if not touched:
            continue
        for idx, op, a in touched:
            is_dest = (idx == len(ops) - 1)
            if len(ops) == 1:
                write = base in ONEOP_WRITE or (base.startswith("s") and base not in ("sub", "subq", "suba", "subx", "swap"))
            else:
                write = is_dest and not base.startswith(NOWRITE)
            if base == "movem" and idx == len(ops) - 1:
                write = True
            tag = "WRITE" if write else "read"
            lines.append(f"   {addr}: {mn} {opstr}    [{tag} {a if isinstance(a, tuple) else hex(a)}]")
    if any("read" in l or "WRITE" in l for l in lines):
        print(f"== {fn} @0x{fs:x}")
        for l in lines:
            print(l)
