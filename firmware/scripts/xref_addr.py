#!/usr/bin/env python3
"""Whole-binary cross-reference for a CM848 data address: every function that accesses it,
each access's read/write + width across BOTH banks, and a reads/writes summary — answers
"who touches this, and is it ever written?" in one shot. Built on disasm_func's access detector.

Usage:
    python3 xref_addr.py <0xDATA_ADDR>

Resolves the symbol name from global_variables.csv (falls back to Ghidra DAT_/_DAT_/PTR_DAT_),
greps cm848_rom.ghidra.cpp to find every referencing function, then runs the disasm width-check
on each. A "NEVER WRITTEN" banner flags read-only addresses (ROM/EEPROM-loaded constants) — the
read-only detector several naming agents asked for. CM848 / PowerPC big-endian only.
"""
import csv
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import disasm_func as D


def symbol_name(addr):
    """Curated name for addr from global_variables.csv, or None if unnamed."""
    want = f"0x{addr:08x}"
    path = os.path.join(D.FW, "output", "global_variables.csv")
    try:
        for row in csv.reader(open(path)):
            if row and row[0].strip().lower() == want:
                return row[1].strip()
    except FileNotFoundError:
        pass
    return None


def referencing_functions(addr):
    """(name, [(start, fname)]) — functions whose .cpp body references the symbol at addr."""
    name = symbol_name(addr)
    a8 = f"{addr:08x}"
    toks = {f"DAT_{a8}", f"_DAT_{a8}", f"PTR_DAT_{a8}"}
    if name:
        toks.add(name)
    tokpat = re.compile(r"(?<![\w])(" + "|".join(re.escape(t) for t in toks) + r")(?![\w])")
    fpat = re.compile(r"^// Function: (\S+) @ 0x([0-9a-fA-F]+)")
    cur, refs = None, set()
    for line in open(D.CPP, errors="replace"):
        m = fpat.match(line)
        if m:
            cur = (int(m.group(2), 16), m.group(1))
        elif cur and tokpat.search(line):
            refs.add(cur)
    return name, sorted(refs)


def main():
    if len(sys.argv) < 2:
        print(__doc__); sys.exit(0)
    addr = int(sys.argv[1], 16)
    name, refs = referencing_functions(addr)
    funcs = D.function_table()
    print(f"# xref 0x{addr:08x}  ({name or 'unnamed DAT_'})  — {len(refs)} referencing function(s)")

    total_r = total_w = 0
    widths = set()
    rows = []
    for start, fname in refs:
        s, stop = D.func_window(start, funcs)
        lines, _ = D.objdump(s, stop)
        hits, _ = D.find_accesses(lines, addr)
        r = sum(1 for k, _, _ in hits if k == "load")
        w = sum(1 for k, _, _ in hits if k == "store")
        total_r += r
        total_w += w
        widths |= {ww for _, _, ww in hits}
        rows.append((fname, r, w, hits))

    wv = "/".join(sorted(widths)) or "-"
    print(f"# total: {total_r} read(s), {total_w} write(s)   width(s): {wv}"
          + ("   <-- MIXED, inspect!" if len(widths) > 1 else ""))
    if refs and total_w == 0:
        print("# >> NEVER WRITTEN in any referencing function -> ROM/EEPROM-loaded constant "
              "(or reached only via a pointer)")

    for fname, r, w, hits in sorted(rows, key=lambda x: -(x[1] + x[2])):
        print(f"\n{fname}: {r}r/{w}w")
        for k, ln, ww in hits:
            print(f"  [{k:5}] {ww:5}  {ln}")
        if not hits:
            print("  (referenced in .cpp but no direct access in window — pointer-passed &sym, "
                  "or built into a register we lost track of)")


if __name__ == "__main__":
    main()
