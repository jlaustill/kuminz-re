"""Map ROM addresses to the CM550 function that contains them (by the nearest lower function start).
usage: which_function.py <functions_sorted.txt> <address hex>..."""
import bisect
import sys

starts, names = [], []
for line in open(sys.argv[1]):
    parts = line.split()
    starts.append(int(parts[0]))
    names.append(' '.join(parts[1:]))
for a in sys.argv[2:]:
    x = int(a, 16)
    i = bisect.bisect_right(starts, x) - 1
    print(f"{a}: {names[i] if i >= 0 else '?'}")
