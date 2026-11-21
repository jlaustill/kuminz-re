"""Sharper check for the csv-module leftover-tail bug in global_variables.csv / function_renames.csv. For a row whose
comment M (on rev_a) became H (on rev_b): if H ends with ',' + (M after its first comma) and the part of H before
that tail shares little with M's first fragment (a replaced head, not a name refresh), flag it. Also flag new quotes.
usage: csv_tail_check2.py <repo> <rev_a> <rev_b> [ratio, default 0.6]"""
import difflib
import subprocess
import sys

repo, ra, rb = sys.argv[1:4]
limit = float(sys.argv[4]) if len(sys.argv) > 4 else 0.6
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
        if '"' in h and '"' not in m:
            print(f"{f} {addr}: new quote: {h[:110]}")
            flagged += 1
            continue
        if "," not in m:
            continue
        head_m, tail = m.split(",", 1)
        if not h.endswith("," + tail) or len(tail) < 8:
            continue
        head_h = h[: -len(tail) - 1]
        if head_m in head_h:
            continue
        r = difflib.SequenceMatcher(None, head_m, head_h).ratio()
        if r < limit:
            print(f"{f} {addr}: ratio {r:.2f} head_now: {head_h[:90]} || tail: {tail[:60]}")
            flagged += 1
    print(f"== {f}: {flagged} flagged")
