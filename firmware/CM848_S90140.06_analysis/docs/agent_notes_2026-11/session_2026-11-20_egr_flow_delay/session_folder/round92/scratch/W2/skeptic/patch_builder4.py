"""Skeptic: delivery fixes to build_verdict_W2.py - no double quotes inside any verdict string, replace fragments
that occur exactly once, the 106 / 14 split asserted, two wording fixes (each old block must occur exactly once)."""
import os

HERE = os.path.dirname(os.path.abspath(__file__))
p = os.path.join(HERE, "build_verdict_W2.py")
s = open(p).read()


def rep(old, new):
    global s
    assert s.count(old) == 1, (s.count(old), old[:90])
    s = s.replace(old, new)


# word 12 bit 9: single-quoted fragments for the differences follow-on
rep('''d1 = "Bits 0 / 2-9 / 11-13 have CM848's positions and meanings (the same Calterm records), so CM848's field names are reused."
d2 = "Three bits differ, so the type is cm550_."''',
    '''d1 = "field names are reused."
d2 = "Three bits differ"''')
rep('''    "own detector - nothing proves that detector for J90350.00)'. Follow-on in differences_from_cm848: replace \\"" + d1 +
    "\\" with \\"Bits 0 / 2-9 / 11-13 have CM848's positions and meanings (the same Calterm records); CM848's field "
    "names are reused for bits 0 / 2-8 / 11-13 and bit 9 keeps the e2m wording because CM848's name describes its own "
    "detector.\\" and replace \\"" + d2 + "\\" with \\"Three bits differ in meaning (10 / 14 / 15) and bit 9 in name "
    "only, so the type is cm550_.\\"")''',
    '''    "own detector - nothing proves that detector for J90350.00)'. Follow-on in differences_from_cm848: replace '" + d1 +
    "' with 'field names are reused for bits 0 / 2-8 / 11-13; bit 9 is the same record but keeps the e2m wording "
    "because the CM848 name describes the CM848 detector.' and replace '" + d2 + "' with 'Three bits differ in "
    "meaning (10 / 14 / 15) and bit 9 in name only'.")''')
# word 12 bit 14
rep('''old = "(13 other e2m files go on '- BIT 14')"''', '''old = "13 other e2m files"''')
rep('''    "Comment only; name and bit unchanged. Replace \\"" + old + "\\" with \\"(9 other e2m files go on '- BIT 14')\\".")''',
    '''    "Comment only; name and bit unchanged. Replace '" + old + "' with '9 other e2m files'.")''')
# word 13 bit 0: no line counts
rep('''"(000E +0 DSKYSWSS S mask 0x1; cm550_updateEngineState tests it 11 times, mc68k_runPowerDownSequence 3). The "''',
    '''"(000E +0 DSKYSWSS S mask 0x1; cm550_updateEngineState and mc68k_runPowerDownSequence read it as the key). The "''')
# overall
rep("Words 12 bits 7 / 8 / ", "Word 12 bits 7 / 8 / ")
# checks: exactly one occurrence, no double quotes, the split the overall text states
rep('''for what, old, text in checks:
    assert old in text, f"not a literal substring: {what}: {old}"''',
    '''for what, old, text in checks:
    assert text.count(old) == 1, f"not exactly one occurrence ({text.count(old)}): {what}: {old}"''')
rep('''    assert (v["verdict"] == "AMENDED") == ("amendment" in v), v["element"]''',
    '''    assert (v["verdict"] == "AMENDED") == ("amendment" in v), v["element"]
    for key in ("element", "reason", "amendment"):
        assert '"' not in v.get(key, "") and "\\\\" not in v.get(key, "") and "\\n" not in v.get(key, ""), (v["element"], key)
assert sum(v["verdict"] == "CONFIRMED" for v in verdicts) == 106
assert sum(v["verdict"] == "AMENDED" for v in verdicts) == 14''')
open(p, "w").write(s)
print("patched")
