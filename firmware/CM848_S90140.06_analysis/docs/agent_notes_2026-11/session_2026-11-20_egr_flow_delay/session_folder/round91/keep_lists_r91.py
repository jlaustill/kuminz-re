"""Round 91 (read-only): per firmware, the refresh map's old labels that are Calterm record names (v64t6_s.e2m) - a
comment citing one names the Calterm parameter, so the refresh keeps them - and a map without them for
refresh_other_csvs.py (which has no --keep). usage: keep_lists_r91.py <repo> <dir>"""
import csv
import os
import sys

repo, d = sys.argv[1], sys.argv[2]
calterm = {l.split(",")[0] for l in open(os.path.join(repo, "e2m-analysis/originals/v64t6_s.e2m"), encoding="latin-1")
           if l.count(",") > 5}
for fw in ("cm550", "cm848"):
    rows = list(csv.reader(open(os.path.join(d, f"map_r91_{fw}.csv"))))
    keep = sorted({r[2] for r in rows[1:] if r[2] in calterm})
    open(os.path.join(d, f"keep_r91_{fw}.txt"), "w").write(",".join(keep))
    csv.writer(open(os.path.join(d, f"map_r91_{fw}_nokeep.csv"), "w", newline="")).writerows(
        [rows[0]] + [r for r in rows[1:] if r[2] not in calterm])
    print(fw, len(rows) - 1, "map rows;", len(keep), "Calterm names kept:", keep[:8])
