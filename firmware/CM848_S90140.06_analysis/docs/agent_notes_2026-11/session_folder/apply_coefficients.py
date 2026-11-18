"""Type every EMA filter coefficient target as a word, named after its filter when that is named."""
import re
import sys
from collections import defaultdict

sys.path.insert(0, sys.argv[1])
import lookup_tables as L
import disasm_func as D

state = L.CsvState.load()
text = open(D.CPP).read()
assign = re.compile(r"([A-Za-z_][A-Za-z0-9_]*)(?:\.|->)coefficient = \(word \*\)&([A-Za-z_][A-Za-z0-9_]*);")
filters_of = defaultdict(set)
for f, y in assign.findall(text):
    filters_of[y].add(f)

changes, log = {}, []
for y, filters in sorted(filters_of.items()):
    a = state.addresses[y][0] if y in state.addresses else int(y[-8:], 16)
    named = sorted(f for f in filters if not f.startswith("ema_filter_state_t_") and f.endswith("_filter_state"))
    if len(filters) == 1 and named:
        name = named[0][: -len("_filter_state")] + "_filter_coefficient"
    else:
        name = ""
    users = " / ".join(sorted(filters))
    comment = f"EMA filter coefficient: the weight of the previous value in 1/65536 (0 = no filtering) - {users}.coefficient points here"
    old = state.rows.get(a, ("", "", ""))[0]
    if old and not L.JUNK_NAME.match(old):
        comment += f" (was {old})"
        if not name:
            name = old
    taken = state.addresses.get(name, [])
    if name and taken and taken[0] != a:
        name = ""                                     # never collide; leave it unnamed
    changes[a] = (name, "word", comment)
    log.append((hex(a), old, name or "(type-only)", users))
edited, inserted = L.write_rows(f"{sys.argv[1]}/../CM848_S90140.06_analysis/output/global_variables.csv", changes)
for row in log:
    print("  ", *row)
print(f"retyped {edited}, added {inserted}")
