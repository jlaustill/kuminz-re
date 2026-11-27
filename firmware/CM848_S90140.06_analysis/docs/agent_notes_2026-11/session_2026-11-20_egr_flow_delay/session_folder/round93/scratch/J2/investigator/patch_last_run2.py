"""J2 investigator run 2: the last small corrections (found in the final re-read against abs_refs):
- 0x80da60 has nine more clr.w sites, not ten; the 0x80aa12 base load is the instruction at 0x1ffde;
- the blocking table bound is a5 = 0x80d9e4 (cmpa.l a5,a2 at 0x21368);
- of the rows inside the engine ignored request list, 0x8019b8 HAS an absolute reference: 0x2398e loads it as the
  retarder list base - 4.
It appends the replacements to patch_part2_run2.py's list (that script rebuilds part 2 from the run 1 copy) and fixes
the two notes files in place."""
import os

here = os.path.dirname(os.path.abspath(__file__))
p = os.path.join(here, "patch_part2_run2.py")
t = open(p).read()
extra = '''    ("clr.w (0x80da60) at 0x231f4 and at ten more sites in the request handlers",
     "clr.w (0x80da60) at 0x231f4 and at nine more sites in the request handlers", 1),
    ("base load at 0x1ffe0 (service 4 / 5 worker)", "base load at 0x1ffde (service 4 / 5 worker)", 1),
    ("bound cmpa.l #0x80d9e4 at 0x21368", "bound a5 = 0x80d9e4 (cmpa.l a5,a2 at 0x21368)", 1),
    ("(no absolute reference to any of them)",
     "(no absolute reference to any of them but 0x8019b8, which 0x2398e loads as the retarder list base - 4)", 1),
]
for old, new, count in REPLACEMENTS:'''
marker = ''']
for old, new, count in REPLACEMENTS:'''
if "nine more sites" not in t:
    assert t.count(marker) == 1
    t = t.replace(marker, extra)
    open(p, "w").write(t)
for name, old, new in (
        ("summary_notes_compact.py", "(no absolute reference to any). ",
         "(no absolute reference to any but 0x8019b8, which 0x2398e loads as the retarder list base - 4). "),
        ("summary_notes.py", "0x8019b2, 0x8019b4, 0x8019b6, 0x8019b8. ",
         "0x8019b2, 0x8019b4, 0x8019b6, 0x8019b8 (the last one is referenced only at 0x2398e, as the retarder list base - 4). ")):
    q = os.path.join(here, name)
    s = open(q).read()
    if new not in s:
        assert s.count(old) == 1, (name, s.count(old))
        open(q, "w").write(s.replace(old, new))
print("done")
