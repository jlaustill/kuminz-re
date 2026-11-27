"""Round 94 tooling: apply_r94.py counts the new enums of overrides_r94.json ("new_enums") as known types, like the
new structs, so a global typed with one passes the unknown-type check (the enum rows come from the members).
Idempotent. usage: patch_apply_r94e.py <apply_r94.py>"""
import sys

p = sys.argv[1]
s = open(p).read()
old = '''    widths.update(((OVERRIDES.get("new_enums") or {}).get(fw)) or {})
    WIDTH[fw] = widths'''
new = '''    widths.update(((OVERRIDES.get("new_enums") or {}).get(fw)) or {})
    WIDTH[fw] = widths
    types[fw].update(((OVERRIDES.get("new_enums") or {}).get(fw)) or {})'''
if new not in s:
    assert s.count(old) == 1, s.count(old)
    assert s.index("types[fw] = known") < s.index(old), "types must be built before WIDTH"
    s = s.replace(old, new)
open(p, "w").write(s)
print("patched")
