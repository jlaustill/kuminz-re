"""Apply a refresh map's old -> new names to the comment columns of structure_definitions.csv and enums.csv (which
refresh_references.py skips). Word-bounded; a name right after 'was' / 'were' / '(was' stays (history).
usage: refresh_struct_comments.py <repo> <map.csv>"""
import csv
import io
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
pairs = [(r["old_label"], r["name"]) for r in csv.DictReader(open(map_path))
         if r["old_label"] and r["name"] and r["old_label"] != r["name"] and not r["old_label"].startswith("DAT_")]
pairs.sort(key=lambda p: -len(p[0]))
HISTORY = re.compile(r"(\bwas|\bwere|formerly|\(was)\s*`?$")


def refresh(text):
    n = 0
    for old, new in pairs:
        pat = re.compile(r"(?<![A-Za-z0-9_])" + re.escape(old) + r"(?![A-Za-z0-9_])")

        def sub(m):
            nonlocal n
            if HISTORY.search(text[max(0, m.start() - 12):m.start()]):
                return m.group(0)
            n += 1
            return new
        text = pat.sub(sub, text)
    return text, n


for name, col in [("structure_definitions.csv", 5), ("enums.csv", 3)]:
    p = os.path.join(out, name)
    lines, total = open(p).read().split("\n"), 0
    for i, line in enumerate(lines):
        if not line or line.startswith("#"):
            if line.startswith("#"):
                new, k = refresh(line)
                lines[i], total = new, total + k
            continue
        row = next(csv.reader([line]))
        if len(row) > col:
            new, k = refresh(row[col])
            if k:
                row[col] = new
                s = io.StringIO()
                csv.writer(s, lineterminator="").writerow(row)
                lines[i] = s.getvalue()
                total += k
    open(p, "w").write("\n".join(lines))
    print(f"{name}: {total} references refreshed")
