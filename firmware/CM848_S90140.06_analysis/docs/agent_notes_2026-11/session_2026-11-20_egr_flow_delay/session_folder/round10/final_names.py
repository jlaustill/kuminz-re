"""Chain the round 10 maps (in order) and print old -> final name for the given old names.
usage: final_names.py <map1.csv> [<map2.csv> ...] -- <old name> ..."""
import csv
import sys

args = sys.argv[1:]
sep = args.index("--")
maps, names = args[:sep], args[sep + 1:]
chain = {}
for m in maps:
    for r in csv.DictReader(open(m)):
        old, new = r["old_label"], r["name"]
        # anything that already ended at old continues to new
        for k, v in list(chain.items()):
            if v == old:
                chain[k] = new
        chain.setdefault(old, new)
for n in names:
    print(f"{n} -> {chain.get(n, '(not renamed)')}")
