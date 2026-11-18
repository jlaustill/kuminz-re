"""List the functions that differ between two canonical .cpp files whose entry is below 0x7F60 (boot ROM / kernel image).
usage: changed_boot_functions.py old_canon.cpp new_canon.cpp"""
import re
import sys

HEADER = re.compile(r"^// Function: (\S+) @ (0x[0-9a-f]+)$", re.M)


def split(path):
    parts = HEADER.split(open(path).read())
    return {int(parts[i + 1], 16): (parts[i], re.sub(r"\s+", "", parts[i + 2])) for i in range(1, len(parts), 3)}


o, n = split(sys.argv[1]), split(sys.argv[2])
changed = sorted(a for a in n if a in o and o[a][1] != n[a][1])
boot = [a for a in changed if a < 0x7F60]
print(f"{len(changed)} changed functions; below 0x7F60: {len(boot)}")
for a in boot:
    print(f"   0x{a:05x} {n[a][0]}")
