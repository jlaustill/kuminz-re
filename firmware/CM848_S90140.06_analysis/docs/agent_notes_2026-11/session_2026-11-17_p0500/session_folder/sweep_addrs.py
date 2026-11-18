"""Linear sweep of both CM848 banks (disasm_func.find_accesses) for exact accesses to the given addresses.

Usage: python3 sweep_addrs.py <firmware/scripts dir> <0xA,0xB,...> <bank1.dis> [<bank2.dis> ...]
Register state carries across function boundaries in a linear sweep, so verify each hit in context.
"""
import sys

sys.path.insert(0, sys.argv[1])
import disasm_func as D  # noqa: E402

addrs = [int(a, 16) for a in sys.argv[2].split(',')]
for dis in sys.argv[3:]:
    lines = open(dis).read().splitlines()
    for a in addrs:
        for kind, ln, w in D.find_accesses(lines, a)[0]:
            print(f"0x{a:06x} {kind:5} {w:5} {ln}")
