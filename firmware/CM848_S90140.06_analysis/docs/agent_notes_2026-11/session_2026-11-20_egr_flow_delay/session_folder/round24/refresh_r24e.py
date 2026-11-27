"""Round 24 stage E: refresh the old fault array names in comments (after apply_r24e.py).
Tokens: apply_r24e.py's map (instance-qualified struct fields, flat word names, the two _array bases) plus the bare old
field names of words 0-20 (fault_detected_bits_A_to_B), the old instance label and type. Qualified forms first, then
bare ones, longest first; a name right after 'was' / '(was' stays (history). Files: the comment columns of every
CM848 CSV and firmware/CLAUDE.md. usage: refresh_r24e.py <repo> <map.json> [--dry-run]"""
import csv
import io
import json
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
dry = "--dry-run" in sys.argv
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
tokens = json.load(open(map_path))
for w in range(21):
    tokens.setdefault(f"fault_detected_bits_{16 * w}_to_{16 * w + 15}", f"fault_detected_cal.faults_{16 * w}_to_{16 * w + 15}")
for k, v in list(tokens.items()):     # type-qualified mentions: system_status_flags_t.<old field>
    if k.startswith("system_status_flags_t_003fe974."):
        tokens["system_status_flags_t." + k.split(".", 1)[1]] = "fault_bit_words_t." + v.split(".", 1)[1]
tokens["system_status_flags_t_003fe974"] = "fault_detected_cal"
tokens["system_status_flags_t"] = "fault_bit_words_t"
HISTORY = re.compile(r"(\bwas|\bwere|formerly|old name|\(was)\s*`?$")
order = sorted(tokens, key=lambda k: ("." not in k, -len(k)))
pats = [(re.compile(r"(?<![A-Za-z0-9_.])" + re.escape(k) + r"(?![A-Za-z0-9_])"), tokens[k]) for k in order]


def refresh(text):
    for pat, rep in pats:
        def sub(m, rep=rep, text=text):
            return m.group(0) if HISTORY.search(text[max(0, m.start() - 12):m.start()]) else rep
        text = pat.sub(sub, text)
    return text


def write_csv_row(row):
    s = io.StringIO()
    csv.writer(s, lineterminator="").writerow(row)
    return s.getvalue()


changed = {}
for name, col, n in [("global_variables.csv", 3, 4), ("function_renames.csv", 2, 3), ("arrays.csv", 4, 5),
                     ("labels.csv", 2, 3), ("constants.csv", 3, 4), ("deleted_functions.csv", 1, 2)]:
    p = os.path.join(out, name)
    if not os.path.exists(p):
        continue
    lines, new = open(p).read().split("\n"), []
    for line in lines:
        if not line or line.startswith("#"):
            new.append(refresh(line) if line.startswith("#") else line)
            continue
        parts = line.split(",", n - 1)
        if len(parts) > col:
            parts[col] = refresh(parts[col])
        new.append(",".join(parts))
    changed[p] = new
for name, col in [("structure_definitions.csv", 5), ("enums.csv", 3)]:
    p = os.path.join(out, name)
    lines, new = open(p).read().split("\n"), []
    for line in lines:
        if not line or line.startswith("#") or line.startswith(("struct_name,", "enum_name,")):
            new.append(refresh(line) if line.startswith("#") else line)
            continue
        row = next(csv.reader([line]))
        before = list(row)
        if len(row) > col:
            row[col] = refresh(row[col])
        new.append(write_csv_row(row) if row != before else line)
    changed[p] = new
cl = os.path.join(repo, "firmware/CLAUDE.md")
changed[cl] = [refresh(l) for l in open(cl).read().split("\n")]
for p, new in changed.items():
    old = open(p).read().split("\n")
    n = sum(1 for a, b in zip(old, new) if a != b)
    if n:
        print(f"{os.path.relpath(p, repo)}: {n} lines")
    if not dry and new != old:
        open(p, "w").write("\n".join(new))
