"""Token-level differences of one function between two .cpp files. Usage: token_diff.py old new name [max]"""
import difflib
import re
import sys

old_path, new_path, name = sys.argv[1:4]
mx = int(sys.argv[4]) if len(sys.argv) > 4 else 12
HEADER = re.compile(r"^// Function: (\S+) @ (0x[0-9a-f]+)$", re.M)


def body(path):
    parts = HEADER.split(open(path).read())
    for i in range(1, len(parts), 3):
        if parts[i] == name:
            return re.findall(r"\w+|[^\w\s]", parts[i + 2])
    return []


a, b = body(old_path), body(new_path)
shown = 0
for tag, i1, i2, j1, j2 in difflib.SequenceMatcher(None, a, b, autojunk=False).get_opcodes():
    if tag != "equal" and shown < mx:
        print(f"{tag}: [{' '.join(a[i1:i2])}] -> [{' '.join(b[j1:j2])}]   ctx: {' '.join(a[max(0, i1 - 6):i1])}")
        shown += 1
