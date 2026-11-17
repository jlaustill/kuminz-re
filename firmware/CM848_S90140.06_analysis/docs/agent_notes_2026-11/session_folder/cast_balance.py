"""Count cast-token changes between two canonical .cpp files (removed vs added) and show a few samples.
usage: cast_balance.py old_canon.cpp new_canon.cpp"""
import difflib
import re
import sys

HEADER = re.compile(r"^// Function: (\S+) @ (0x[0-9a-f]+)$", re.M)
TOKEN = re.compile(r"[A-Za-z_][A-Za-z0-9_]*|0x[0-9a-fA-F]+|\d+|->|[^\sA-Za-z0-9_]")
CASTY = {"(", ")", "short", "word", "sword", "int", "uint", "ushort", "dword", "byte", "char", "undefined2", "undefined4", "*"}


def split(path):
    parts = HEADER.split(open(path).read())
    return {parts[i + 1]: (parts[i], TOKEN.findall(parts[i + 2])) for i in range(1, len(parts), 3)}


o, n = split(sys.argv[1]), split(sys.argv[2])
added = removed = 0
samples = []
for a in n:
    if a not in o or o[a][1] == n[a][1]:
        continue
    ta, tb = o[a][1], n[a][1]
    for tag, i1, i2, j1, j2 in difflib.SequenceMatcher(None, ta, tb, autojunk=False).get_opcodes():
        if tag != "equal" and set(ta[i1:i2] + tb[j1:j2]) <= CASTY:
            removed += i2 - i1
            added += j2 - j1
            if len(samples) < 8:
                samples.append(f"{n[a][0]}: ...{' '.join(ta[max(0, i1 - 3):i2 + 3])}  =>  {' '.join(tb[max(0, j1 - 3):j2 + 3])}")
print(f"cast tokens removed {removed}, added {added}")
for s in samples:
    print("  ", s[:200])
