#!/usr/bin/env python3
"""Regression tests for disasm_func / xref_addr against known CM848 ground-truth cases.

Run: python3 test_disasm_tools.py   (needs the CM848 binaries + powerpc objdump; exits non-zero on fail)

These pin the behavior the extracted find_accesses() must keep: each of the four addressing forms,
and the read-only (NEVER WRITTEN) detector in xref_addr.
"""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import disasm_func as D
from xref_addr import referencing_functions


def widths_and_hits(func_or_addr, data):
    funcs = D.function_table()
    start, _ = D.resolve(func_or_addr, funcs)
    s, stop = D.func_window(start, funcs)
    lines, _ = D.objdump(s, stop)
    hits, _ = D.find_accesses(lines, data)
    return sorted({w for _, _, w in hits}), hits


CASES = [
    # (func, data_addr, expected_widths, must_have_kind, note)
    ("fuel_demandSource_modeSelect", 0x0040afd8, ["word"], "store", "displacement sth"),
    ("governorCruiseTimerManagement", 0x0040b788, ["dword"], "load", "displacement lwz"),
    ("tpu_rpm_measurement_initialize", 0x0040b2f8, ["dword"], "store", "displacement stw"),
    ("cm848_initJ1939Stack", 0x0040af0c, ["byte"], "load", "INDEXED lbzx (the fix)"),
]


def main():
    fails = 0
    for func, data, exp, kind, note in CASES:
        ws, hits = widths_and_hits(func, data)
        ok = ws == exp and any(k == kind for k, _, _ in hits)
        print(f"[{'PASS' if ok else 'FAIL'}] {func} @ {hex(data)} ({note}): widths={ws} expected={exp}")
        fails += not ok

    # read-only detector: 0x00408dfc must show zero writes across all referencing functions
    funcs = D.function_table()
    _, refs = referencing_functions(0x00408dfc)
    writes = 0
    for start, _ in refs:
        s, stop = D.func_window(start, funcs)
        lines, _ = D.objdump(s, stop)
        hits, _ = D.find_accesses(lines, 0x00408dfc)
        writes += sum(1 for k, _, _ in hits if k == "store")
    ro_ok = writes == 0 and len(refs) > 0
    print(f"[{'PASS' if ro_ok else 'FAIL'}] xref 0x00408dfc read-only: {writes} writes / {len(refs)} fns")
    fails += not ro_ok

    print(f"\n{'ALL PASS' if fails == 0 else str(fails) + ' FAILED'}")
    sys.exit(1 if fails else 0)


if __name__ == "__main__":
    main()
