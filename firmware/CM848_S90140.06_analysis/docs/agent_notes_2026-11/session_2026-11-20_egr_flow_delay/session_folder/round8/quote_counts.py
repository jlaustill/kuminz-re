"""Count lines with a double quote per CM848 CSV on two git revisions, and list the keys of lines that are quoted only
in the second. usage: quote_counts.py <repo> <rev_a> <rev_b>"""
import subprocess
import sys

repo, ra, rb = sys.argv[1:]
base = "firmware/CM848_S90140.06_analysis/output/"
for f in ["global_variables.csv", "function_renames.csv", "arrays.csv", "local_variables.csv", "function_definitions.csv",
          "enums.csv", "labels.csv", "constants.csv", "structure_definitions.csv"]:
    def lines(rev):
        r = subprocess.run(["git", "-C", repo, "show", f"{rev}:{base}{f}"], capture_output=True, text=True)
        return [l for l in r.stdout.split("\n") if '"' in l]
    a, b = lines(ra), lines(rb)
    new = sorted(set(b) - set(a))
    print(f"{f}: {len(a)} -> {len(b)}; new quoted lines: {len(new)}")
    for l in new:
        print("   ", l[:150])
