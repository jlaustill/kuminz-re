"""Write the round 8 old names (globals / functions / types / struct instances; not DAT_ / FUN_ defaults, not the
generic struct field names) for grep_old_names.py.
usage: old_names_r8.py <out.txt> <map.csv>..."""
import csv
import sys

out, *maps = sys.argv[1:]
names = set()
for m in maps:
    for r in csv.DictReader(open(m)):
        old = r["old_label"]
        if not old or r["kind"] == "field" or old.startswith(("DAT_", "FUN_", "func_0x", "WORD_ARRAY_")):
            continue
        if old != r["name"]:
            names.add(old)
open(out, "w").write("\n".join(sorted(names)) + "\n")
print(len(names), "old names")
