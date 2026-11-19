"""Replace references refresh_references.py leaves alone: default labels (DAT_<addr> / WORD_ARRAY_<addr>) of rows that
now have names, and any mapped old name in the comment column of function_definitions.csv. Whole tokens only, never
inside a '(was ...)' / '(were ...)' note.
usage: refresh_default_labels.py <CM848 output dir> <map.csv>"""
import csv
import os
import re
import sys

out, map_path = sys.argv[1:3]
mapping = {}
for row in csv.DictReader(open(map_path)):
    if row["old_label"].startswith(("DAT_", "WORD_ARRAY_")):
        mapping[row["old_label"]] = row["name"]
definitions_mapping = {row["old_label"]: row["name"] for row in csv.DictReader(open(map_path))}
HISTORY = re.compile(r"\((?:was|were) [^)]*\)")


def replace(text, table):
    if not table:
        return text, 0
    pattern = re.compile(r"(?<![A-Za-z0-9_])(" + "|".join(map(re.escape, table)) + r")(?![A-Za-z0-9_])")
    pieces, last, count = [], 0, 0
    for m in HISTORY.finditer(text):
        part, n = pattern.subn(lambda x: table[x.group(1)], text[last:m.start()])
        pieces += [part, m.group(0)]
        count += n
        last = m.end()
    part, n = pattern.subn(lambda x: table[x.group(1)], text[last:])
    pieces.append(part)
    return "".join(pieces), count + n


total = {}
for name in ("global_variables.csv", "function_renames.csv", "structure_definitions.csv", "enums.csv",
             "local_variables.csv", "function_definitions.csv"):
    path = os.path.join(out, name)
    lines = open(path, newline="").read().split("\n")
    count = 0
    for i, line in enumerate(lines):
        if not line or line.startswith("#"):
            continue
        keep = {"global_variables.csv": 3, "function_renames.csv": 2, "structure_definitions.csv": 5, "enums.csv": 3,
                "local_variables.csv": 5, "function_definitions.csv": 5}[name]
        parts = line.split(",", keep)
        if len(parts) <= keep:
            continue
        table = dict(mapping)
        if name == "function_definitions.csv":
            table.update(definitions_mapping)
        parts[keep], n = replace(parts[keep], table)
        if n:
            lines[i] = ",".join(parts)
            count += n
    open(path, "w", newline="").write("\n".join(lines))
    total[name] = count
print(total)
