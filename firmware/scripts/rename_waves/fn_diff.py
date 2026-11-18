"""Unified diff of one function between two .cpp builds. Usage: fn_diff.py old.cpp new.cpp name [context]"""
import difflib
import re
import sys

old_path, new_path, name = sys.argv[1:4]
ctx = int(sys.argv[4]) if len(sys.argv) > 4 else 2
HEADER = re.compile(r"^// Function: (\S+) @ (0x[0-9a-f]+)$", re.M)


def body(path):
    parts = HEADER.split(open(path).read())
    for i in range(1, len(parts), 3):
        if parts[i] == name:
            return parts[i + 2].split("\n")
    return []


for line in difflib.unified_diff(body(old_path), body(new_path), "old", "new", n=ctx, lineterm=""):
    print(line[:170])
