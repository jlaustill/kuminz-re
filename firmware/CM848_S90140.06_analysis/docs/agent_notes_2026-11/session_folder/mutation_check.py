"""The audit must flag the pre-PR CSV state (main's global_variables.csv) as untyped."""
import csv
import os
import sys
from collections import Counter

sys.path.insert(0, sys.argv[1])
import lookup_tables as L

out = os.path.join(sys.argv[1], "..", "CM848_S90140.06_analysis", "output")
current = L.CsvState.load()
main_state = L.CsvState(open(sys.argv[2]).readlines(), open(os.path.join(out, "arrays.csv")).readlines(),
                        list(csv.reader(open(os.path.join(out, "structure_definitions.csv")))),
                        open(os.path.join(out, "function_renames.csv")).readlines())
tables, problems, casts = L.collect(current, L.MemoryImage())
print("main state:", Counter(f.kind for f in L.audit(tables, main_state, casts)))
print("current   :", Counter(f.kind for f in L.audit(tables, current, casts)))
