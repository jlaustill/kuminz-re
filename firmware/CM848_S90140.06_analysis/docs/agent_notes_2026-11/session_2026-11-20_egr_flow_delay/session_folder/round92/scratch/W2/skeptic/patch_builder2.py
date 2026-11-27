"""Skeptic: second wording fix to build_verdict_W2.py (the old string must occur exactly once)."""
import os

HERE = os.path.dirname(os.path.abspath(__file__))
p = os.path.join(HERE, "build_verdict_W2.py")
s = open(p).read()
old = "The proposal does not mention the indexed site at 0x206e6: it is "
new = ("The notes count 15 indexed sites but describe only the protection loops and cm550_FUN_00020890; the fifteenth, "
       "at 0x206e6, is ")
assert s.count(old) == 1, s.count(old)
s = s.replace(old, new)
open(p, "w").write(s)
print("patched")
