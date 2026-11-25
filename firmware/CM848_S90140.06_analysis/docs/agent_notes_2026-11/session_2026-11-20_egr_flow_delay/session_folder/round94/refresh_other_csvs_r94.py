"""Round 87: refresh old names in the CSVs that refresh_references.py does not cover (function_definitions, enums,
structure_definitions, local_variables), with its history rule (a name after 'was' / 'were' / 'formerly' /
'old name' / '(was', or inside a 'were a / b / c' list, stays) and its skips (DAT_ labels; an old label that is still
a current name in that firmware). Keeps line endings (CM550 has CRLF files). Function renames apply to both firmwares'
files (comments cite the other firmware); global renames only to their own firmware.
usage: refresh_other_csvs.py <repo> [--own-only] --cm550 <map>... --cm848 <map>...
--own-only (round 88): apply every map to its own firmware only - for an old name that two firmwares rename differently."""
import csv
import io
import os
import re
import sys

HISTORY = re.compile(r"(\bwas|\bwere|formerly|old name|\(was)\s*`?$")
FILES = ("function_definitions.csv", "enums.csv", "structure_definitions.csv", "local_variables.csv")
DIRS = {"cm550": "firmware/CM550_J90350.00_analysis/output", "cm848": "firmware/CM848_S90140.06_analysis/output"}
repo, maps, current_fw = sys.argv[1], {"cm550": [], "cm848": []}, None
own_only = False
for a in sys.argv[2:]:
    if a == "--own-only":
        own_only = True
    elif a in ("--cm550", "--cm848"):
        current_fw = a[2:]
    else:
        maps[current_fw].append(a)


def is_function(fw, address):
    a = int(address, 16)
    return a < 0x800000 if fw == "cm550" else (a < 0x70000 or 0x500000 <= a < 0x540000)


pairs = {"cm550": {}, "cm848": {}}
function_olds = set()     # old labels of function renames: the only ones the function-name column follows
for fw, paths in maps.items():
    for path in paths:
        for r in csv.DictReader(open(path)):
            if not r["old_label"] or r["old_label"] == r["name"] or r["old_label"].startswith("DAT_"):
                continue
            targets = ("cm550", "cm848") if r["address"] and is_function(fw, r["address"]) and not own_only else (fw,)
            if r["address"] and is_function(fw, r["address"]):
                function_olds.add(r["old_label"])
            for t in targets:
                pairs[t][r["old_label"]] = r["name"]


def current_names(out):
    names = set()
    for name in ("global_variables.csv", "function_renames.csv"):
        for row in csv.reader(open(os.path.join(out, name), newline="")):
            if len(row) > 1 and row[0].startswith("0x") and row[1]:
                names.add(row[1])
    return names


for fw, rel in DIRS.items():
    out = os.path.join(repo, rel)
    current = current_names(out)
    table = {o: n for o, n in pairs[fw].items() if o not in current}
    if not table:
        continue
    pattern = re.compile(r"\b(" + "|".join(re.escape(o) for o in sorted(table, key=len, reverse=True)) + r")\b")
    for name in FILES:
        path = os.path.join(out, name)
        if not os.path.exists(path):
            continue
        text = open(path, newline="").read()
        count = 0

        def sub(m):
            global count
            before = text[:m.start()]  # the whole prefix: a long were-list stays history (round 91)
            if HISTORY.search(before[-14:]):
                return m.group(0)
            hist = max(before.rfind("was "), before.rfind("were "), before.rfind("(was"))
            if hist >= 0 and not re.search(r"[);]|->|\.\s", before[hist:]):
                return m.group(0)
            count += 1
            return table[m.group(1)]

        # only comment columns, '#' lines and (function renames) the function-name column (round 94: a global
        # rename's old name that equals a struct field name had renamed the field)
        COMMENT_COL = {"function_definitions.csv": 5, "enums.csv": 3, "structure_definitions.csv": 5, "local_variables.csv": 5}[name]
        NAME_COL = {"function_definitions.csv": 1, "local_variables.csv": 1}.get(name)
        out_lines = []
        for line in text.split("\n"):
            body = line.rstrip("\r")
            if not body or body.startswith("#"):
                out_lines.append(pattern.sub(sub, line))
                continue
            cells = next(csv.reader([body]))
            if len(cells) <= COMMENT_COL and NAME_COL is None:
                out_lines.append(line)
                continue
            changed = False
            for k in [c for c in (COMMENT_COL, NAME_COL) if c is not None and c < len(cells)]:
                if k == NAME_COL and cells[k] not in function_olds:
                    continue
                value = pattern.sub(sub, cells[k]) if k == COMMENT_COL else table.get(cells[k], cells[k])
                if value != cells[k]:
                    if k != COMMENT_COL:
                        count += 1          # sub() counts the comment replacements; this one is a function-name cell
                    cells[k] = value
                    changed = True
            if changed:
                buf = io.StringIO()
                csv.writer(buf, lineterminator="").writerow(cells)
                out_lines.append(buf.getvalue() + ("\r" if line.endswith("\r") else ""))
            else:
                out_lines.append(line)
        new = "\n".join(out_lines)
        if count:
            open(path, "w", newline="").write(new)
        print(f"{fw} {name}: {count} references refreshed")
