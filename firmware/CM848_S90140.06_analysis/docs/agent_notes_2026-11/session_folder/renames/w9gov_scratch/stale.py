"""List identifier-shaped tokens in the comments of selected CSV rows that no CSV defines (stale names).
usage: stale.py globals LO HI   |  stale.py funcs ADDR [ADDR...]
Skips '(was ...)' history. Prints the row address, name and the unknown tokens."""
import csv
import re
import sys

OUT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output'


def known_names():
    known = set()
    for name, cols in (("global_variables.csv", (1, 2)), ("function_renames.csv", (1,)), ("deleted_functions.csv", (1,)),
                       ("structure_definitions.csv", (0, 2)), ("enums.csv", (0, 2)), ("arrays.csv", (1,)),
                       ("local_variables.csv", (3,)), ("function_definitions.csv", (3,))):
        try:
            rows = list(csv.reader(open(f"{OUT}/{name}")))
        except FileNotFoundError:
            continue
        for row in rows:
            for c in cols:
                if len(row) > c and row[c]:
                    known.add(re.sub(r"\[\d+\]$", "", row[c]))
    return known


token = re.compile(r"\b(?:[a-z][a-z0-9]*(?:_[a-z0-9]+){2,}|(?:cm848|mpc555|hpcr|vp44|mc68k|cm550)_[A-Za-z0-9_]+|(?:DAT|FUN|WORD|BYTE|DWORD|PTR|LAB)_[0-9a-fA-F]+)\b")
history = re.compile(r"\((?:was|were) [^)]*\)", re.I)


def unknown_tokens(text, known):
    text = history.sub("", text)
    bad = []
    for m in token.finditer(text):
        t = m.group(0)
        if t in known or re.sub(r"_(?:cal|[0-9]+)$", "", t) in known:
            continue
        # prefix of a family?
        bad.append(t)
    return bad


def main():
    known = known_names()
    mode = sys.argv[1]
    if mode == 'globals':
        lo = int(sys.argv[2], 16)
        hi = int(sys.argv[3], 16)
        for row in csv.reader(open(f"{OUT}/global_variables.csv")):
            if len(row) < 4 or not row[0].startswith('0x'):
                continue
            a = int(row[0], 16)
            if lo <= a <= hi:
                bad = unknown_tokens(row[3], known)
                if bad:
                    print(row[0], row[1], '->', sorted(set(bad)))
    else:
        want = {int(x, 16) for x in sys.argv[2:]}
        for row in csv.reader(open(f"{OUT}/function_renames.csv")):
            if len(row) < 3 or not row[0].startswith('0x'):
                continue
            if int(row[0], 16) in want:
                bad = unknown_tokens(row[2], known)
                print(row[0], row[1], '->', sorted(set(bad)))


main()
