"""Diff one function between the proof's canonical files (old_stripped.cpp / new_stripped.cpp in the round folder).
usage: diff_stripped.py <round folder> <function name>"""
import difflib
import os
import re
import sys

folder, name = sys.argv[1], sys.argv[2]


def block(path):
    text = open(os.path.join(folder, path), errors="replace").read()
    m = re.search(rf"^// Function: {re.escape(name)} @.*?(?=^// Function: |\Z)", text, re.M | re.S)
    return m.group(0).split("\n") if m else ["(missing)"]


for line in difflib.unified_diff(block("old_stripped.cpp"), block("new_stripped.cpp"), lineterm="", n=1):
    print(line[:200])
