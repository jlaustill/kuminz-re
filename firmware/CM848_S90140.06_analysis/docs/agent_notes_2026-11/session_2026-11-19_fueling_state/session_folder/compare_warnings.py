"""Compare the WARNING lines of a baseline build log with a verify log (two builds): each warning must occur in the
verify log exactly twice as often as in the baseline.
usage: compare_warnings.py <baseline build.log> <verify.log>"""
import collections
import re
import sys


def warnings(path):
    counts = collections.Counter()
    for line in open(path, errors="replace"):
        if "warning" in line.lower():
            counts[re.sub(r"^[^>]*>", "", line).strip()] += 1
    return counts


base, verify = warnings(sys.argv[1]), warnings(sys.argv[2])
problems = []
for text in sorted(set(base) | set(verify)):
    if verify[text] != 2 * base[text]:
        problems.append(f"baseline {base[text]} x, verify {verify[text]} x: {text[:150]}")
print(f"{sum(base.values())} baseline warning lines, {sum(verify.values())} in the verify log (two builds)")
print("\n".join(problems) if problems else "warnings identical (each exactly twice in the verify log)")
sys.exit(1 if problems else 0)
