#!/usr/bin/env python3
"""Disassemble a CM848 function by name or address, and (optionally) pinpoint how it
accesses a target data address + the load/store WIDTH — the asm width-check, automated.

Replaces the manual dance: find the function's `// Function: @ 0x..` comment, find the NEXT
function for the stop address, pick binary+VMA by region, compute the low-16 byte pattern, grep,
then fall back to the lis+addi register-built form. This script does all of that.

Usage:
    python3 disasm_func.py <func_name|0xADDR> [0xDATA_ADDR]

  - no DATA_ADDR  -> prints the full disassembly of the function.
  - with DATA_ADDR -> tracks register contents through the function (lis/addi/ori/li/mr) and prints
    every load/store whose base+displacement == DATA_ADDR, with a WIDTH verdict (byte/word/dword) to
    paste into an investigate-firmware-symbol report. Handles all three addressing forms uniformly:
    displacement `lhz rX,<disp>(rY)`, register-built exact `lis;addi rN,..;l/st 0(rN)`, and
    struct/buffer member `<offset>(base)` where base = DATA_ADDR - offset.

Window + binary are resolved from cm848_rom.ghidra.cpp's `// Function: <name> @ 0x<addr>` comments
(covers FUN_ too) and the Bank1/Bank2 split at 0x500000. CM848 / PowerPC big-endian only.
"""
import re
import subprocess
import sys
import os

FW = os.path.join(os.path.dirname(__file__), "..", "CM848_S90140.06_analysis")
CPP = os.path.join(FW, "output", "cm848_rom.ghidra.cpp")
ROM = os.path.join(FW, "originals", "cm848_rom.bin")
FLASH2 = os.path.join(FW, "originals", "cm848_flash2_live.bin")
WIDTH = {"lbz": "byte", "stb": "byte", "lhz": "word", "lha": "word", "sth": "word",
         "lwz": "dword", "stw": "dword"}
LDST = re.compile(r"\b(lbz|lha|lhz|lwz|stb|sth|stw)\b")


def function_table():
    """[(addr, name)] sorted by addr, from the // Function: comments."""
    pat = re.compile(r"^// Function: (\S+) @ 0x([0-9a-fA-F]+)")
    out = []
    for line in open(CPP, errors="replace"):
        m = pat.match(line)
        if m:
            out.append((int(m.group(2), 16), m.group(1)))
    return sorted(set(out))


def resolve(target, funcs):
    if target.lower().startswith("0x") or re.fullmatch(r"[0-9a-fA-F]+", target):
        addr = int(target, 16)
        # snap to the function containing addr
        cand = [f for f in funcs if f[0] <= addr]
        return cand[-1] if cand else (addr, "?")
    for a, n in funcs:
        if n == target:
            return (a, n)
    sys.exit(f"function not found: {target}")


def objdump(start, stop):
    binary, vma = (FLASH2, 0x00500000) if start >= 0x500000 else (ROM, 0x0)
    cmd = ["powerpc-linux-gnu-objdump", "-D", "-b", "binary", "-m", "powerpc", "-EB",
           f"--adjust-vma={hex(vma)}", f"--start-address={hex(start)}",
           f"--stop-address={hex(stop)}", binary]
    return subprocess.run(cmd, capture_output=True, text=True).stdout.splitlines(), binary


def main():
    if len(sys.argv) < 2:
        print(__doc__); sys.exit(0)
    funcs = function_table()
    start, name = resolve(sys.argv[1], funcs)
    later = [a for a, _ in funcs if a > start]
    stop = min(later) if later else start + 0x800
    lines, binary = objdump(start, stop)
    print(f"# {name} @ {hex(start)}..{hex(stop)}  ({os.path.basename(binary)})")

    if len(sys.argv) < 3:
        print("\n".join(lines)); return

    data = int(sys.argv[2], 16)
    # Register-content tracking: follow lis/addi/ori/li/mr to know each GPR's value, then flag any
    # load/store whose base+displacement == data. Handles all three addressing forms uniformly
    # (displacement, lis+addi exact, and struct-member <offset>(base) where base = data - offset).
    asm_re = re.compile(r"^\s*[0-9a-f]+:\t[0-9a-f ]+\t\s*(\S+)\s*(.*)$")
    ld_st = re.compile(r"^r(\d+),(-?\d+)\(r(\d+)\)$")           # rD,disp(rA)
    mask32 = 0xffffffff

    def base(idx):                       # r0 reads as literal 0 in addr context
        return 0 if idx == 0 else regs.get(idx)

    regs = {0: 0}
    hits, off_seen = [], {}
    for ln in lines:
        m = asm_re.match(ln)
        if not m:
            continue
        mnem, ops = m.group(1), m.group(2).replace(" ", "")
        op = ops.split(",")
        w = WIDTH.get(mnem)
        if w:                                                  # a load or store
            lm = ld_st.match(ops)
            if lm:
                rd, disp, ra = int(lm.group(1)), int(lm.group(2)), int(lm.group(3))
                b = base(ra)
                if b is not None and ((b + disp) & mask32) == data:
                    kind = "store" if mnem.startswith("st") else "load"
                    hits.append((kind, ln.strip(), w))
                    off_seen[disp] = off_seen.get(disp, 0) + 1
                if not mnem.startswith("st"):                  # load writes rD
                    regs.pop(rd, None)
            continue
        # address-building ops
        if mnem == "lis" and len(op) == 2:
            regs[int(op[0][1:])] = (int(op[1], 0) & 0xffff) << 16
        elif mnem in ("addi", "addic") and len(op) == 3:
            b = base(int(op[1][1:]))
            regs[int(op[0][1:])] = None if b is None else (b + int(op[2])) & mask32
        elif mnem == "li" and len(op) == 2:
            regs[int(op[0][1:])] = int(op[1]) & mask32
        elif mnem == "ori" and len(op) == 3:
            b = base(int(op[1][1:]))
            regs[int(op[0][1:])] = None if b is None else (b | (int(op[2], 0) & 0xffff))
        elif mnem == "mr" and len(op) == 2:
            regs[int(op[0][1:])] = base(int(op[1][1:]))
        elif op and re.fullmatch(r"r\d+", op[0]):              # any other op clobbers its dest GPR
            regs.pop(int(op[0][1:]), None)

    if not hits:
        print(f"\n!! no access to {hex(data)} found in this window. Widen with a bigger function, "
              f"or the address may be reached via a pointer loaded from memory (untrackable).")
        return
    widths = sorted({w for _, _, w in hits})
    print(f"\nACCESSES to {hex(data)} ({len(hits)} found):")
    for kind, ln, w in hits:
        print(f"  [{kind:5}] {w:5}  {ln}")
    if any(k != 0 for k in off_seen):
        print(f"  (nonzero displacements {sorted(off_seen)}: reached via base+offset — could be a "
              f"struct/buffer member OR just a shared base register for a nearby global; verify)")
    print(f"\nWIDTH verdict: {'/'.join(widths)}"
          + ("   <-- MIXED, inspect!" if len(widths) > 1 else ""))


if __name__ == "__main__":
    main()
