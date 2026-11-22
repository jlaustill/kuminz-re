"""Round 37: for each lookup cache word in an address range, every interpolator call that passes it (its function and
the call's table arguments), so the cache can be named <table>_cached_axis_offset.
usage: cache_users.py <cpp> <global_variables.csv> <start hex> <end hex>"""
import re
import sys

text = open(sys.argv[1], errors="replace").read()
start, end = int(sys.argv[3], 16), int(sys.argv[4], 16)
names = {}
for l in open(sys.argv[2], errors="replace"):
    p = l.split(",", 3)
    if len(p) >= 2 and p[0].startswith("0x") and p[1] and start <= int(p[0], 16) <= end:
        names[int(p[0], 16)] = p[1]
marks = [(m.start(), m.group(1)) for m in re.finditer(r"^// Function: (\S+) @", text, re.M)]


def func_at(pos):
    f = None
    for s, n in marks:
        if s > pos:
            break
        f = n
    return f


flat = text
CALL = re.compile(r"(lookupTableInterpolation|cm848_dualAxisTableInterpolation|cm848_interpolateTableWithoutCache)\s*"
                  r"\(\s*([^;]*?)\);", re.S)
for m in CALL.finditer(flat):
    args = re.sub(r"\s+", " ", m.group(2))
    first = args.split(",")[0].strip()
    a = None
    mm = re.match(r"&?DAT_(003f[0-9a-f]{4})$", first)
    if mm:
        a = int(mm.group(1), 16)
    else:
        nm = first.lstrip("&").split("[")[0]
        for addr, n in names.items():
            if n == nm:
                a = addr
    if a is not None and start <= a <= end:
        print(f"0x{a:06x} {names.get(a, '-'):45s} {func_at(m.start())}: {m.group(1)}({args[:150]})")
