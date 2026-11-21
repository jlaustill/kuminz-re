"""Proof for a type-only change: per function, compare two .cpp builds after removing comments, local declarations
and casts, folding auto-named locals to one token and reducing every integer literal to its value mod 2^16. Lists the
functions that still differ (to inspect) and the changed functions that have local_variables.csv rows (whose
auto-name matches can move when temporaries renumber).
Usage: cast_normalized_diff.py <old.cpp> <new.cpp> <local_variables.csv> [max_shown]"""
import csv
import difflib
import re
import sys

old_path, new_path, locals_path = sys.argv[1:4]
max_shown = int(sys.argv[4]) if len(sys.argv) > 4 else 8
CAST = re.compile(r"\((?:short|int|uint|word|sword|ushort|dword|sdword|undefined[124]?|longlong|ulonglong|char|byte|"
                  r"bool|long|ulong)\)")
AUTO = re.compile(r"\b(?:[a-z]{1,2}Var\d+|[a-z]{1,2}Stack_\w+|local_\w+|in_stack_\w+|extraout_\w+|unaff_\w+)\b")
DECL = re.compile(r"(?m)^\s+(?!goto\b|return\b|break\b|continue\b)[A-Za-z_][\w ]*\s\**[A-Za-z_]\w*(\[\d+\])?;\s*$")
ARRAY = re.compile(r"\(&([A-Za-z_]\w*)\)\[")
LIT = re.compile(r"(?<![\w.])(-?)(0x[0-9a-fA-F]+|\d+)\b")


def lit(m):
    v = int(m.group(2), 0) * (-1 if m.group(1) else 1)
    return str(v & 0xffff) if -0x10000 < v < 0x10000 else str(v)


def chunks(path):
    text = open(path).read()
    out = {}
    for c in re.split(r"(?m)^(?=// Function: )", text):
        m = re.match(r"// Function: (\S+) @ (0x[0-9a-f]+)", c)
        if not m:
            continue
        body = re.sub(r"/\*.*?\*/", "", c, flags=re.S)
        body = re.sub(r"//[^\n]*", "", body)
        raw = body
        body = DECL.sub("", body)
        body = ARRAY.sub(r"\1[", body)
        body = CAST.sub("", body)
        body = AUTO.sub("V", body)
        body = LIT.sub(lit, body)
        out[m.group(2)] = (m.group(1), re.sub(r"\s+", "", body), raw)
    return out


a, b = chunks(old_path), chunks(new_path)
with_locals = {r["function_address"].lower() for r in csv.DictReader(open(locals_path))}
changed_raw = [k for k in a if k in b and re.sub(r"\s+", "", a[k][2]) != re.sub(r"\s+", "", b[k][2])]
still = [k for k in changed_raw if a[k][1] != b[k][1]]
print(f"functions: {len(a)}; changed: {len(changed_raw)}; still different after normalizing casts / literals / "
      f"auto-names: {len(still)}")
risky = sorted(b[k][0] for k in changed_raw if f"0x{int(k, 16):08x}" in with_locals)
print(f"changed functions with local_variables.csv rows ({len(risky)}): {', '.join(risky)}")
for k in still[:max_shown]:
    x, y = a[k][1], b[k][1]
    sm = difflib.SequenceMatcher(None, x, y, autojunk=False)
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag != "equal":
            print(f"## {b[k][0]}\n   old ...{x[max(0, i1 - 70):i2 + 30]}\n   new ...{y[max(0, j1 - 70):j2 + 30]}")
            break
if len(still) > max_shown:
    print("... and", ", ".join(b[k][0] for k in still[max_shown:]))
