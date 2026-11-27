"""Find the silent forms of the csv-module bug in global_variables.csv / function_renames.csv (whose importer splits
with split(",", 4 / 3), so the comment takes commas unquoted). For every row whose comment differs between two
revisions (keyed by address), flag it when the new comment ends with main's comment from its first comma on (a
leftover tail after row[3] was replaced) but does not contain main's whole comment, or when it has a quote main had not.
usage: csv_tail_check.py <repo> <rev_a> <rev_b>"""
import subprocess
import sys

repo, ra, rb = sys.argv[1:]
base = "firmware/CM848_S90140.06_analysis/output/"
for f, cols in [("global_variables.csv", 4), ("function_renames.csv", 3)]:
    def rows(rev):
        text = subprocess.run(["git", "-C", repo, "show", f"{rev}:{base}{f}"], capture_output=True, text=True).stdout
        d = {}
        for line in text.split("\n"):
            if line.startswith("0x"):
                parts = line.split(",", cols - 1)
                if len(parts) == cols:
                    d.setdefault(parts[0].lower(), parts[-1])
        return d
    a, b = rows(ra), rows(rb)
    flagged = 0
    for addr in sorted(set(a) & set(b)):
        m, h = a[addr], b[addr]
        if m == h:
            continue
        frags = m.split(",")
        tail = ",".join(frags[1:])
        if len(frags) > 1 and tail.strip() and h.endswith("," + tail) and m not in h:
            print(f"{f} {addr}: leftover tail ...{h[-120:]}")
            flagged += 1
        if '"' in h and '"' not in m:
            print(f"{f} {addr}: new quote: {h[:120]}")
            flagged += 1
    print(f"== {f}: {len(set(a) & set(b))} rows compared, {flagged} flagged")
