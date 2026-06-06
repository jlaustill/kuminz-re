#!/usr/bin/env python3
"""Disassemble a CM848 function by name or address, and (optionally) pinpoint how it
accesses a target data address + the load/store WIDTH — the asm width-check, automated.

Replaces the manual dance: find the function's `// Function: @ 0x..` comment, find the NEXT
function for the stop address, pick binary+VMA by region, compute the low-16 byte pattern, grep,
then fall back to the lis+addi register-built form. This script does all of that.

Usage:
    python3 disasm_func.py <func_name|0xADDR> [0xDATA_ADDR]

  - no DATA_ADDR  -> prints the full disassembly of the function.
  - with DATA_ADDR -> prints ONLY the instructions that reference that address (both the
    displacement form `lhz rX,<disp>(rY)` and the register-built form `lis;addi rN,..;l/st 0(rN)`),
    and a WIDTH verdict (byte/word/dword) you can paste into an investigate-firmware-symbol report.

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
    lo16 = data & 0xffff
    bytepat = f"{lo16 >> 8:02x} {lo16 & 0xff:02x}"   # the addr low-16, byte-spaced
    addi = re.compile(r"\b(addi|addic|ori)\s+r(\d+),r\d+,")
    regs_built = {}          # reg -> addr-building instruction line
    hits = []
    for i, ln in enumerate(lines):
        has_pat = bytepat in ln
        m = LDST.search(ln)
        # displacement form: the load/store itself carries the low-16 in its raw bytes
        if m and has_pat:
            hits.append(("disp", ln, WIDTH[m.group(1)]))
        # register-built form: addi/ori finishes the address in some reg
        am = addi.search(ln)
        if am and has_pat:
            regs_built[am.group(2)] = ln
            # scan forward for the 0(rN) access before rN is reused
            zero = re.compile(rf"\b(lbz|lha|lhz|lwz|stb|sth|stw)\s+r\d+,0\(r{am.group(2)}\)")
            redef = re.compile(rf"\b(addi|addic|ori|lis|li|mr)\s+r{am.group(2)},")
            for ln2 in lines[i + 1:i + 40]:
                zm = zero.search(ln2)
                if zm:
                    hits.append(("reg", f"{am.group(0).strip()} ; {ln2.strip()}", WIDTH[zm.group(1)]))
                elif redef.search(ln2):
                    break

    if not hits:
        print(f"\n!! no access to {hex(data)} found (low-16 pattern '{bytepat}'). "
              f"Check the address is really touched here, or widen the window.")
        return
    widths = sorted({w for _, _, w in hits})
    print(f"\nACCESSES to {hex(data)} (low-16 '{bytepat}'):")
    for kind, ln, w in hits:
        print(f"  [{kind:4}] {w:5}  {ln.strip()}")
    print(f"\nWIDTH verdict: {'/'.join(widths)}"
          + ("   <-- MIXED, inspect!" if len(widths) > 1 else ""))


if __name__ == "__main__":
    main()
