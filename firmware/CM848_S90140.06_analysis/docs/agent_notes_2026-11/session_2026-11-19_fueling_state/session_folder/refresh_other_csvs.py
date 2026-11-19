"""refresh_references.py covers the comment columns of global_variables / function_renames / ... but not enums.csv or
structure_definitions.csv. Replace old names there too (word boundaries), keeping history: a name right after
'was ' / '(was ' / 'were ' stays. Only comment text changes: no enum member or struct field is named like a function
or global. usage: refresh_other_csvs.py <mapping.csv> <csv>..."""
import csv
import re
import sys

pairs = [(r["old_label"], r["name"]) for r in csv.DictReader(open(sys.argv[1]))]
pattern = re.compile(r"\b(" + "|".join(re.escape(old) for old, _ in pairs) + r")\b")
new_of = dict(pairs)
HISTORY = re.compile(r"(\bwas|\bwere|\(was)\s*`?$")
for path in sys.argv[2:]:
    text = open(path, newline="").read()
    count = 0

    def sub(m):
        global count
        if HISTORY.search(text[max(0, m.start() - 14):m.start()]):
            return m.group(0)
        count += 1
        return new_of[m.group(0)]

    out = pattern.sub(sub, text)
    open(path, "w", newline="").write(out)
    print(f"{path}: {count} references refreshed")
