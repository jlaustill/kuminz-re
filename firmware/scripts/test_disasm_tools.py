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
    # (function address, data_addr, expected_widths, must_have_kind, note). Functions are given by address, not
    # name, so renames don't break the test (two cases had gone stale: tpu_rpm_measurement_initialize is now
    # cm848_initRadiatorFanSpeedMeasurement and cm848_initJ1939Stack is now cm848_clearMilForHealedFaults).
    ("0x0050ecc4", 0x0040afd8, ["word"], "store", "cm848_selectTurbochargerSpeedSource: displacement sth"),
    ("0x0051a878", 0x0040b788, ["dword"], "load", "cm848_updateOilChangeMonitor: displacement lwz"),
    ("0x005161c0", 0x0040b2f8, ["dword"], "store", "cm848_initRadiatorFanSpeedMeasurement: displacement stw"),
    ("0x0053473c", 0x0040af0c, ["byte"], "load", "cm848_clearMilForHealedFaults: INDEXED lbzx (the fix)"),
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

    # data typed by a type-only row (no name) renders with Ghidra's default label - WORD_ARRAY_<addr> for a word[N]
    # table, WORD_<addr> for a word - not DAT_<addr>. The row is picked from the CSV (the first type-only word[N] row
    # whose label is in the .cpp, else the first type-only word row), because the naming campaigns keep naming the
    # examples: 0x5fe88 was named on 2026-11-16, and PR #53 round 54 named the last unnamed table.
    output = os.path.join(D.FW, "output")
    cpp = open(os.path.join(output, "cm848_rom.ghidra.cpp")).read()
    rows = [line.rstrip("\n").split(",") for line in open(os.path.join(output, "global_variables.csv"))]
    rows = [p for p in rows if p[0].startswith("0x") and len(p) > 2 and not p[1]]
    unnamed, label = None, ""
    for kind, wanted in (("WORD_ARRAY_", lambda t: t.startswith("word[")), ("WORD_", lambda t: t == "word")):
        for p in rows:
            if wanted(p[2]) and f"{kind}{int(p[0], 16):08x}" in cpp:
                unnamed, label = int(p[0], 16), f"{kind}{int(p[0], 16):08x}"
                break
        if unnamed is not None:
            break
    name, refs = referencing_functions(unnamed) if unnamed is not None else ("", [])
    table_ok = unnamed is not None and not name and len(refs) > 0
    print(f"[{'PASS' if table_ok else 'FAIL'}] xref {hex(unnamed or 0)} unnamed type-only row ({label}): "
          f"{len(refs)} fns")
    fails += not table_ok

    print(f"\n{'ALL PASS' if fails == 0 else str(fails) + ' FAILED'}")
    sys.exit(1 if fails else 0)


if __name__ == "__main__":
    main()
