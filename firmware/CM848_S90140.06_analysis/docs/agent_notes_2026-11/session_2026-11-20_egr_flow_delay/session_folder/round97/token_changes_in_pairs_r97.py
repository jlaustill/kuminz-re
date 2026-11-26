"""Round 97: from a file of '<file>: -line' / '<file>: +line' pairs (review_stage_a_diff output), print each changed
span with 50 characters of context, so history-note rewrites can be spotted. usage: token_changes_in_pairs_r97.py <pairs>"""
import difflib
import sys

lines = [l.rstrip("\n") for l in open(sys.argv[1])]
minus = [l for l in lines if ": -" in l]
plus = [l for l in lines if ": +" in l]
for a, b in zip(minus, plus):
    fa, ta = a.split(": -", 1)
    fb, tb = b.split(": +", 1)
    sm = difflib.SequenceMatcher(None, ta, tb, autojunk=False)
    for op, i1, i2, j1, j2 in sm.get_opcodes():
        if op != "equal":
            print(f"{fa}: ...{ta[max(0, i1 - 50):i2 + 5]!r} -> {tb[j1:j2]!r}")
