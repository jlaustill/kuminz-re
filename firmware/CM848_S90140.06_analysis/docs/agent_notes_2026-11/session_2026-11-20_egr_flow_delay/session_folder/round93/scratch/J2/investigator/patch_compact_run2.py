"""J2 investigator run 2: second tightening of compact.py (short summary / notes, per-entry caps by batch membership)."""
import os

p = os.path.join(os.path.dirname(os.path.abspath(__file__)), "compact.py")
t = open(p).read()
if "LISTED" not in t:
    old = '''out = dict(batch=full["batch"], summary=full["summary"], functions=[], skipped=full["skipped"], globals=[],
           enum_members=[], notes=full["notes"])'''
    new = '''import summary_notes_compact  # noqa: E402
LISTED = {"0x1fdc0", "0x1ff38", "0x212b2", "0x2142c", "0x216c6", "0x21778", "0x21872", "0x21920", "0x21f4e", "0x21fac",
          "0x22070", "0x231da", "0x23244", "0x23216", "0x21642", "0x238ac", "0x238ec"}
out = dict(batch=full["batch"], summary=summary_notes_compact.summary_compact, functions=[], skipped=full["skipped"],
           globals=[], enum_members=[], notes=summary_notes_compact.notes_compact)'''
    assert t.count(old) == 1
    t = t.replace(old, new)
    old = '''    f["plate_comment"] = plate if plate.endswith((".", ")")) else plate + "."
    f["role"] = ROLES.get(a, f["role"])
    f["discriminator"] = sentences(f["discriminator"].replace(OUTSIDE, ""), 200)
    f["evidence"] = cut(f["evidence"], 240)'''
    new = '''    plate = plate if plate.endswith((".", ")")) else plate + "."
    listed = a in LISTED
    f["plate_comment"] = sentences(plate, 470 if listed else 300)
    f["role"] = ROLES.get(a, f["role"])
    f["discriminator"] = sentences(f["discriminator"].replace(OUTSIDE, ""), 150)
    f["evidence"] = cut(f["evidence"], 170 if listed else 110)'''
    assert t.count(old) == 1
    t = t.replace(old, new)
    assert t.count('g["evidence"] = cut(g["evidence"], 80)') == 1
    t = t.replace('g["evidence"] = cut(g["evidence"], 80)', 'g["evidence"] = cut(g["evidence"], 55)')
    open(p, "w").write(t)
    print("compact.py patched")
else:
    print("already patched")
