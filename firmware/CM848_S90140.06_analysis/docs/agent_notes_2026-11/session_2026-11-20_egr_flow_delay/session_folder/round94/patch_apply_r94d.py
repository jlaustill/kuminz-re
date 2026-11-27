"""Round 94 tooling: apply_r94.py gives the new enums of overrides_r94.json ("new_enums": {fw: {ENUM_NAME: size}})
their width before the globals pass, so a global typed with a new enum of its own width takes it (the enum rows are
written later, by the enum members). Idempotent. usage: patch_apply_r94d.py <apply_r94.py>"""
import sys

p = sys.argv[1]
s = open(p).read()
assert s.index("OVERRIDES =") < s.index("WIDTH = {}"), "OVERRIDES must be loaded before WIDTH"
old = '''    widths.update(sizes)
    WIDTH[fw] = widths'''
new = '''    widths.update(sizes)
    widths.update(((OVERRIDES.get("new_enums") or {}).get(fw)) or {})
    WIDTH[fw] = widths'''
if new not in s:
    assert s.count(old) == 1, s.count(old)
    s = s.replace(old, new)
open(p, "w").write(s)
print("patched")
