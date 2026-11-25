"""Skeptic: keep angle brackets and ampersands out of the verdict strings (safe to paste into a tool call), and
say what the replace check really asserts (each old block must occur exactly once)."""
import os

HERE = os.path.dirname(os.path.abspath(__file__))
p = os.path.join(HERE, "build_verdict_W2.py")
s = open(p).read()


def rep(old, new):
    global s
    assert s.count(old) == 1, (s.count(old), old[:90])
    s = s.replace(old, new)


rep('word = bit >> 4 from 0x803c94, mask = "\n    "1 << (bit & 15), 9 channels',
    'word = bit / 16 from 0x803c94, mask = "\n    "1 shifted left by bit mod 16, 9 channels')
rep('"set and 0x80062e < 0x807f34 it writes 0x100', '"set and 0x80062e is below 0x807f34 it writes 0x100')
rep("with word = bit >> 4 and mask = 1 << (bit \"\n    \"& 15).", "with word = bit / 16 and mask = 1 shifted left by \"\n    \"bit mod 16.")
rep("(120 elements, \"\n    \"each quoted 'replace' string is a literal substring of the proposal)",
    "(120 elements, \"\n    \"each quoted 'replace' string occurs exactly once in the proposal text it amends)")
rep('''        assert '"' not in v.get(key, "")''', '''        assert not set('"<>&') & set(v.get(key, ""))''')
open(p, "w").write(s)
print("patched")
