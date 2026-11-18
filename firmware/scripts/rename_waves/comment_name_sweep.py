"""List identifier-shaped tokens in added diff lines (CSV comments and plates, firmware/CLAUDE.md) that are no
current name: a proposed name with no row, a name cut short, a retired name, the default label of a row that now
has a name. History is skipped: '(was ...)' / '(were ...)', 'was' / 'were' lists, 'renamed ... from X' (any case).
Usage: comment_name_sweep.py <repo> <base> [<head>] [--firmware DIR]   (no head: the working tree)
A token that starts a current name is marked [prefix of N names]: a family mention (battery_voltage_linearization
for its _axis / _values rows) or a name cut short - read those. --firmware defaults to CM848_S90140.06_analysis."""
import csv
import re
import subprocess
import sys


def parse(argv):
    positional, firmware, it = [], "CM848_S90140.06_analysis", iter(argv)
    for a in it:
        if a == "--firmware":
            firmware = next(it)
        else:
            positional.append(a)
    return positional, firmware


def known_names(out):
    known = set()
    for name, cols in (("global_variables.csv", (1, 2)), ("function_renames.csv", (1,)), ("deleted_functions.csv", (1,)),
                       ("structure_definitions.csv", (0, 2)), ("enums.csv", (0, 2)), ("arrays.csv", (1,)),
                       ("local_variables.csv", (3,)), ("function_definitions.csv", (3,))):
        try:
            rows = list(csv.reader(open(f"{out}/{name}")))
        except FileNotFoundError:
            continue
        for row in rows:
            for c in cols:
                if len(row) > c and row[c]:
                    known.add(re.sub(r"\[\d+\]$", "", row[c]))
    return known


def main():
    args, firmware = parse(sys.argv[1:])
    repo, base = args[0], args[1]
    head = args[2:3]
    out = f"{repo}/firmware/{firmware}/output"
    files = [f"firmware/{firmware}/output/{n}" for n in ("global_variables.csv", "function_renames.csv",
                                                          "structure_definitions.csv")] + ["firmware/CLAUDE.md"]
    diff = subprocess.run(["git", "-C", repo, "diff", "-U0", base, *head, "--"] + files,
                          capture_output=True, text=True, check=True).stdout
    known = known_names(out)
    token = re.compile(r"\b(?:[a-z][a-z0-9]*(?:_[a-z0-9]+){2,}|(?:cm848|mpc555|hpcr|vp44|mc68k|cm550)_[A-Za-z0-9_]+)\b")
    history = re.compile(r"\((?:was|were) [^)]*\)", re.I)
    history_before = re.compile(r"\b(?:was|were)\b[^);.]*$|\brenamed\b.*\bfrom\s*$", re.I)
    hits = {}
    for line in diff.split("\n"):
        if not line.startswith("+") or line.startswith("+++"):
            continue
        text = history.sub("", line)
        for m in token.finditer(text):
            t = m.group(0)
            if t in known or re.sub(r"_(?:cal|[0-9]+)$", "", t) in known:
                continue
            if history_before.search(text[max(0, m.start() - 60):m.start()]):
                continue
            hits.setdefault(t, [0, text[max(0, m.start() - 70):m.end() + 30]])[0] += 1
    for t, (n, ctx) in sorted(hits.items()):
        prefix = sum(1 for k in known if k.startswith(t))
        mark = f" [prefix of {prefix} names]" if prefix else ""
        print(f"{t} x{n}{mark} | {ctx}")
    print(f"-- {len(hits)} unknown tokens")


if __name__ == "__main__":
    main()
