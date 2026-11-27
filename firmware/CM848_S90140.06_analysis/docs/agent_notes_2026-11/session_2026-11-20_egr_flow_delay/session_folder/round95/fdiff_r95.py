"""Round 95 (read-only): unified diff of one function (by address) between two decompilations, plate comments left
out. usage: fdiff_r95.py <old.cpp> <new.cpp> <0xaddress> [context lines]"""
import difflib
import re
import sys

old_path, new_path, address = sys.argv[1], sys.argv[2], int(sys.argv[3], 16)
context = int(sys.argv[4]) if len(sys.argv) > 4 else 2
HEAD = re.compile(r"^// Function: (\S+) @ 0x([0-9a-fA-F]+)", re.M)


def body(path):
    text = open(path, errors="replace").read()
    marks = list(HEAD.finditer(text))
    for i, m in enumerate(marks):
        if int(m.group(2), 16) == address:
            chunk = text[m.start():marks[i + 1].start() if i + 1 < len(marks) else len(text)]
            chunk = re.sub(r"/\*.*?\*/", "", chunk, flags=re.S)
            return [l for l in chunk.split("\n") if l.strip()]
    return []


a, b = body(old_path), body(new_path)
print(f"{len(a)} -> {len(b)} lines")
for line in difflib.unified_diff(a, b, "old", "new", n=context, lineterm=""):
    print(line)
