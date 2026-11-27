"""Compare the fix design's proposed CM550 prototype rows with the current function_definitions.csv: for each proposed
function, the current rows and the proposed rows side by side, the proposal's 'name to review' marks, and current rows
of that function the proposal does not mention.  usage: compare_rows.py <proposed_rows.csv> <function_definitions.csv>"""
import collections
import csv
import sys


def rows(path):
    out = collections.defaultdict(list)
    with open(path, newline="") as fh:
        for r in csv.reader(l for l in fh if l.strip() and not l.startswith("#")):
            if r and r[0].startswith("0x"):
                out[r[0].lower()].append(r)
    return out


proposed, current = rows(sys.argv[1]), rows(sys.argv[2])
for address in sorted(proposed):
    print(f"== {address}")
    for r in current.get(address, []):
        print("   now:", ",".join(r[1:5]), "|", (r[5] if len(r) > 5 else "")[:90])
    for r in proposed[address]:
        mark = " [NAME TO REVIEW]" if len(r) > 5 and "name to review" in r[5].lower() else ""
        print("   new:", ",".join(r[1:5]) + mark, "|", (r[5] if len(r) > 5 else "")[:140])
