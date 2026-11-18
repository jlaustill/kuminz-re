"""Replace old identifiers with their new names in comment columns (and text files), keeping history: a name right
after 'was' / 'were' / 'formerly' / 'old name' / '(was', or inside a 'were a / b / c' list, stays as it is.
Usage: refresh_references.py <repo> <mapping.csv> [--keep NAME,...] [--text REL_PATH]... [--firmware DIR]

mapping.csv: address,name,old_label,kind (old_label -> name). Never refreshed: DAT_ labels (addresses cited on
purpose), an old label that is still the current name of a global or function (it may mean that one), and --keep.
Text files: firmware/CLAUDE.md and firmware/scripts/test_disasm_tools.py unless --text is given (missing ones are
skipped). --firmware defaults to CM848_S90140.06_analysis."""
import csv
import os
import re
import sys

HISTORY = re.compile(r"(\bwas|\bwere|formerly|old name|\(was)\s*`?$")
COLUMN_FILES = [("global_variables.csv", 3), ("function_renames.csv", 2), ("deleted_functions.csv", 1),
                ("arrays.csv", 4), ("labels.csv", 2), ("constants.csv", 3)]


def parse(argv):
    positional, keep, texts, firmware, it = [], set(), [], "CM848_S90140.06_analysis", iter(argv)
    for a in it:
        if a == "--keep":
            keep |= set(next(it).split(","))
        elif a == "--text":
            texts.append(next(it))
        elif a == "--firmware":
            firmware = next(it)
        else:
            positional.append(a)
    return positional, keep, texts or ["firmware/CLAUDE.md", "firmware/scripts/test_disasm_tools.py"], firmware


def current_names(out):
    names = set()
    for name in ("global_variables.csv", "function_renames.csv"):
        for row in csv.reader(open(os.path.join(out, name))):
            if len(row) > 1 and row[0].startswith("0x") and row[1]:
                names.add(row[1])
    return names


def main():
    (repo, mapping), keep, texts, firmware = parse(sys.argv[1:])
    out = os.path.join(repo, "firmware", firmware, "output")
    current = current_names(out)
    pairs = sorted(((r["old_label"], r["name"]) for r in csv.DictReader(open(mapping))
                    if r["old_label"] and r["name"] and r["old_label"] != r["name"]
                    and not r["old_label"].startswith("DAT_") and r["old_label"] not in keep
                    and r["old_label"] not in current),
                   key=lambda p: -len(p[0]))
    if not pairs:
        print("nothing to refresh")
        return
    table = dict(pairs)
    pattern = re.compile(r"\b(" + "|".join(re.escape(o) for o, _ in pairs) + r")\b")

    def refresh(text):
        count = 0

        def sub(m):
            nonlocal count
            before = text[max(0, m.start() - 120):m.start()]
            if HISTORY.search(before[-14:]):
                return m.group(0)
            hist = max(before.rfind("was "), before.rfind("were "), before.rfind("(was"))
            if hist >= 0 and not re.search(r"[);]|->|\.\s", before[hist:]):     # inside a 'were a / b / c' list
                return m.group(0)
            count += 1
            return table[m.group(1)]
        return pattern.sub(sub, text), count

    for name, col in COLUMN_FILES:
        path = os.path.join(out, name)
        if not os.path.exists(path):
            continue
        lines = open(path).read().split("\n")
        total = 0
        for i, l in enumerate(lines):
            p = l.split(",", col)
            if p[0].startswith("0x") and len(p) > col:
                p[col], n = refresh(p[col])
                if n:
                    total += n
                    lines[i] = ",".join(p)
        open(path, "w").write("\n".join(lines))
        print(f"{name}: {total} references refreshed")
    for rel in texts:
        path = os.path.join(repo, rel)
        if not os.path.exists(path):
            continue
        t, n = refresh(open(path).read())
        open(path, "w").write(t)
        print(f"{rel}: {n} references refreshed")


if __name__ == "__main__":
    main()
