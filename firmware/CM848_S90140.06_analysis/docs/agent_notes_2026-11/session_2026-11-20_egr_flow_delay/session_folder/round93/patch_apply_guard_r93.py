"""Round 93 tooling: give apply_r93.py a guard against instruction-like comment texts (round 91 wrote a proposal's
'APPEND to the current comment: ...' in place of seven plate comments) and add the case to test_apply_r93.sh.
Idempotent. usage: patch_apply_guard_r93.py <dir>"""
import os
import sys

d = sys.argv[1]
p = os.path.join(d, "apply_r93.py")
s = open(p).read()
edits = [
    ('''def csv_field(text):''',
     '''INSTRUCTION = re.compile(r"^\\s*(append|prepend|keep|add to|replace|insert|same as|unchanged|see above)\\b|current comment|existing comment", re.I)


def checked_comment(text, label):
    """A comment must be the comment itself. Round 91 wrote a proposal's 'APPEND to the current comment: ...' in
    place of seven plate comments; such a text refuses the apply."""
    if INSTRUCTION.search(text or ""):
        problems.append(f"{label}: the comment reads like an instruction, not a comment: {text[:80]!r}")
    return text


def csv_field(text):'''),
    ('''        plate = ov.get("comment") or clean(v.get("final_comment")) or clean(f.get("plate_comment"))
''',
     '''        plate = checked_comment(ov.get("comment") or clean(v.get("final_comment")) or clean(f.get("plate_comment")), f"{b} function {a}")
'''),
    ('''        comment = ov.get("comment") or clean(v.get("final_comment")) or clean(g.get("comment"))
        if not re.match(r"^[a-z][a-z0-9_]*$", new):''',
     '''        comment = checked_comment(ov.get("comment") or clean(v.get("final_comment")) or clean(g.get("comment")), f"{b} global {fw} {a}")
        if not re.match(r"^[a-z][a-z0-9_]*$", new):'''),
    ('''        comment = ov.get("comment") or clean(v.get("final_comment")) or clean(e.get("comment"))
        which =''',
     '''        comment = checked_comment(ov.get("comment") or clean(v.get("final_comment")) or clean(e.get("comment")), f"{b} enum {e['enum_name']} {value}")
        which ='''),
]
for old, new in edits:
    if new in s:
        continue
    assert s.count(old) == 1, old[:60]
    s = s.replace(old, new)
assert s.index("report, problems, maps = [], [], {") < s.index("for path in batches:")
open(p, "w").write(s)
p = os.path.join(d, "test_apply_r93.sh")
s = open(p).read()
old = '''def no_prefix(d): d["verdict"]["verdicts"][0]["final_name"] = "clearTestBitTwo"
for n, f in (("twin with a prefix", twin_prefix), ("duplicate function name", duplicate), ("_cal outside the mirror", bad_cal), ("unknown type", bad_type), ("counterpart without a prefix", no_prefix)):'''
new = '''def no_prefix(d): d["verdict"]["verdicts"][0]["final_name"] = "clearTestBitTwo"
def instruction(d): d["verdict"]["verdicts"][1]["final_comment"] = "APPEND to the current comment: | the twin"
for n, f in (("twin with a prefix", twin_prefix), ("duplicate function name", duplicate), ("_cal outside the mirror", bad_cal), ("unknown type", bad_type), ("counterpart without a prefix", no_prefix), ("an instruction as a comment", instruction)):'''
if new not in s:
    assert s.count(old) == 1
    open(p, "w").write(s.replace(old, new))
print("guard added")
