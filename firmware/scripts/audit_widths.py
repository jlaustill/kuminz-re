#!/usr/bin/env python3
"""Lint CM848 global_variables.csv for declared-type vs machine-access-width mismatches —
catches Ghidra pointer/dword mistypes (the PTR_DAT_ class) before they cause `_`-prefix artifacts.

Usage:
    python3 audit_widths.py [declared_type] [addr_prefix]
      declared_type : byte | word | dword | pointer   (default: pointer)
      addr_prefix   : optional hex filter, e.g. 0040  (default: all addresses)

For each matching row, runs the disasm width-check across every referencing function and flags
rows whose observed load/store width is NARROWER than the declared type (e.g. a 'pointer' actually
accessed with sth = word). Read-only. CM848 / PowerPC big-endian only.
"""
import csv
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import disasm_func as D
from xref_addr import referencing_functions

EXPECT = {"byte": 1, "word": 2, "dword": 4, "pointer": 4}
ORDER = {"byte": 1, "word": 2, "dword": 4}


def observed_widths(addr, funcs):
    _, refs = referencing_functions(addr)
    ws = set()
    for start, _ in refs:
        s, stop = D.func_window(start, funcs)
        lines, _ = D.objdump(s, stop)
        hits, _ = D.find_accesses(lines, addr)
        ws |= {w for _, _, w in hits}
    return ws


def main():
    want_type = sys.argv[1] if len(sys.argv) > 1 else "pointer"
    prefix = sys.argv[2].lower() if len(sys.argv) > 2 else ""
    exp = EXPECT.get(want_type)
    if exp is None:
        sys.exit(f"unknown type {want_type}; use byte/word/dword/pointer")

    path = os.path.join(D.FW, "output", "global_variables.csv")
    rows = []
    for r in csv.reader(open(path)):
        if (r and r[0].strip().lower().startswith("0x") and len(r) >= 3
                and r[2].strip() == want_type
                and r[0].strip().lower().replace("0x", "").startswith(prefix)):
            rows.append((int(r[0], 16), r[1].strip()))
    print(f"# auditing {len(rows)} '{want_type}'-typed globals"
          f"{' @ 0x' + prefix if prefix else ''} (expect width {exp}B)\n")

    funcs = D.function_table()
    flagged = skipped = 0
    for addr, name in rows:
        ws = observed_widths(addr, funcs)
        if not ws:
            skipped += 1                       # pointer-fed / unreferenced — can't judge from asm
            continue
        narrowest = min(ORDER[w] for w in ws)
        if narrowest < exp:
            flagged += 1
            print(f"MISMATCH 0x{addr:08x} {name}: declared {want_type}({exp}B) but accessed as "
                  f"{'/'.join(sorted(ws))} (narrowest {narrowest}B)")
    print(f"\n# {flagged} mismatch(es), {skipped} unjudgeable (no direct asm access), "
          f"of {len(rows)} '{want_type}' rows")


if __name__ == "__main__":
    main()
