"""True when each named function's lines in two .cpp copies are the same multiset (only their order differs: the
local declaration order the decompiler sometimes emits differently).  usage: order_only.py <old.cpp> <new.cpp> <fn>..."""
import re
import sys


def lines_of(path, name):
    t = open(path, errors="replace").read()
    m = re.search(r"^// Function: " + re.escape(name) + r" @.*?(?=^// Function: |\Z)", t, re.S | re.M)
    return m.group(0).splitlines()


for f in sys.argv[3:]:
    print(f, "order-only:", sorted(lines_of(sys.argv[1], f)) == sorted(lines_of(sys.argv[2], f)))
