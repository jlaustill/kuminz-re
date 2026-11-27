"""Patch apply_r74a.py: an unnamed typed row renders with its type's default label (BYTE_ / WORD_ / DWORD_), as the stage
A build showed - not DAT_. Idempotent.  usage: patch_r74a_render.py <apply_r74a.py>"""
import sys

p = sys.argv[1]
s = open(p).read()
old = ('    render = name or f"DAT_{a:08x}"\n'
       '    if typ.startswith("byte[") and not name:\n'
       '        render = f"BYTE_ARRAY_{a:08x}"  # an unnamed array (checked against the build)\n')
new = ('    # an unnamed typed row renders with its type\'s default label (BYTE_ / WORD_ / DWORD_ - seen in the build)\n'
       '    render = name or {"byte": "BYTE", "word": "WORD", "dword": "DWORD"}[typ] + f"_{a:08x}"\n')
if new not in s:
    assert s.count(old) == 1
    open(p, "w").write(s.replace(old, new))
print("patched")
