"""Round 94: two fixes.
1. CM550 structure_definitions.csv: the field cm550_commanded_throttle_state_t +0xe had been renamed
   'commanded_throttle_state.alternate_throttle_priority' by refresh_other_csvs.py (the old row name
   alternate_throttle_priority is also the field's name); back to alternate_throttle_priority.
2. refresh_other_csvs.py (round 87's tool): it replaced old names in every column of the four CSVs; now it replaces
   them only in comment columns, in '#' lines, and in the function-name column (function renames). Struct field
   names, enum member names, parameter and local names, types and statuses are never touched.
Idempotent. usage: fix_refresh_other_r94.py <repo> <refresh_other_csvs.py>"""
import os
import sys

repo, tool = os.path.abspath(sys.argv[1]), sys.argv[2]
p = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/structure_definitions.csv")
t = open(p, newline="").read()
old = "cm550_commanded_throttle_state_t,,commanded_throttle_state.alternate_throttle_priority,word,"
new = "cm550_commanded_throttle_state_t,,alternate_throttle_priority,word,"
if old in t:
    open(p, "w", newline="").write(t.replace(old, new))
assert new in open(p, newline="").read()
s = open(tool).read()
old_block = '''        new = pattern.sub(sub, text)'''
new_block = '''        # only comment columns, '#' lines and (function renames) the function-name column (round 94: a global
        # rename's old name that equals a struct field name had renamed the field)
        COMMENT_COL = {"function_definitions.csv": 5, "enums.csv": 3, "structure_definitions.csv": 5, "local_variables.csv": 5}[name]
        NAME_COL = {"function_definitions.csv": 1, "local_variables.csv": 1}.get(name)
        out_lines = []
        for line in text.split("\\n"):
            body = line.rstrip("\\r")
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
                    cells[k] = value
                    changed = True
            if changed:
                buf = io.StringIO()
                csv.writer(buf, lineterminator="").writerow(cells)
                out_lines.append(buf.getvalue() + ("\\r" if line.endswith("\\r") else ""))
            else:
                out_lines.append(line)
        new = "\\n".join(out_lines)'''
if new_block not in s:
    assert s.count(old_block) == 1, s.count(old_block)
    s = s.replace(old_block, new_block)
    if "import io\n" not in s:
        s = s.replace("import csv\n", "import csv\nimport io\n", 1)
if "function_olds = set()" not in s:
    a = 'pairs = {"cm550": {}, "cm848": {}}\n'
    assert s.count(a) == 1
    s = s.replace(a, a + "function_olds = set()     # old labels of function renames: the only ones the function-name column follows\n")
    b = '            targets = ("cm550", "cm848") if r["address"] and is_function(fw, r["address"]) and not own_only else (fw,)\n'
    assert s.count(b) == 1
    s = s.replace(b, b + '            if r["address"] and is_function(fw, r["address"]):\n                function_olds.add(r["old_label"])\n')
open(tool, "w").write(s)
print("fixed")
