"""Second pass: cut bodies whose names a later refresh changed (so they are no longer exactly 400 chars).
A segment `{body} (was X)` / `{body} (new row D)` whose body is 330-470 chars long and ends with an
identifier-shaped token that is no current name is re-cut before that token and marked ` ...`.
usage: comment_fixups_b.py <output dir> [--apply]"""
import csv
import re
import sys

out = sys.argv[1]
apply = "--apply" in sys.argv
known = set()
for name, cols in (("global_variables.csv", (1,)), ("function_renames.csv", (1,)), ("deleted_functions.csv", (1,)),
                   ("structure_definitions.csv", (0, 2)), ("enums.csv", (0, 2)), ("arrays.csv", (1,))):
    for row in csv.reader(open(f"{out}/{name}")):
        for c in cols:
            if len(row) > c:
                known.add(row[c])
SEGMENT = re.compile(r"^(.+?) (\((?:was [^)]*|new row [0-9-]+)\))(.*)$", re.S)
IDENT = re.compile(r"(?:[A-Za-z0-9]*_[A-Za-z0-9_]*|[a-z]+[A-Z][A-Za-z0-9]*)$")
fixed = []
path = f"{out}/global_variables.csv"
lines = open(path).read().split("\n")
for i, line in enumerate(lines):
    p = line.split(",", 3)
    if len(p) < 4 or not p[0].startswith("0x"):
        continue
    segs = p[3].split(" | earlier note: ")
    changed = False
    for j, seg in enumerate(segs):
        m = SEGMENT.match(seg)
        if not m or not 330 <= len(m.group(1)) <= 470 or m.group(1).endswith("..."):
            continue
        body = m.group(1)
        last = body.rsplit(" ", 1)[-1]
        token = IDENT.search(last)
        if not token or token.group(0) in known or len(token.group(0)) < 4:
            continue
        frag = token.group(0)
        completions = [k for k in known if k.startswith(frag)] if len(frag) >= 6 else []
        if frag == "_cal":
            new_body = body + " ..."
        elif len(completions) == 1:
            new_body = body[: len(body) - len(frag)] + completions[0] + " ..."
            last = f"{frag}->{completions[0]}"
        else:
            new_body = body[: len(body) - len(last)].rstrip(" ,;:(-/") + " ..."
        segs[j] = f"{new_body} {m.group(2)}{m.group(3)}"
        fixed.append((p[0], last))
        changed = True
    if changed:
        p[3] = " | earlier note: ".join(segs)
        lines[i] = ",".join(p)
print(f"re-cut {len(fixed)} bodies:", " ".join(f"{a}:{t}" for a, t in fixed)[:1500])
if apply:
    open(path, "w").write("\n".join(lines))
