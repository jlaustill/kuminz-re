"""Stage F patch of apply_r20d.py: --only N[,N] (type word 11 alone; skip the cache row), SAME_ENABLE (word 19 bit 7's
two records are one enable under two names, so its comment must not say the reader rules one out), word 11's names.
usage: patch_r20d_for_f.py <apply_r20d.py>"""
import sys

p = sys.argv[1]
t = open(p).read()
pairs = [
    ('dry = "--dry-run" in sys.argv\n',
     'dry = "--dry-run" in sys.argv\n'
     '# --only N[,N]: stage F typed word 11 alone (its reader was an unnamed DAT_ that stage C found)\n'
     'ONLY = [int(x) for x in sys.argv[sys.argv.index("--only") + 1].split(",")] if "--only" in sys.argv else None\n'),
    ('# two records on one mask: the reader picks\n',
     '# two records on one mask: the reader picks (SAME_ENABLE: the two records are one enable under two names)\n'
     'SAME_ENABLE = {(19, 7)}\n'),
    ('            parts.append("; ".join(f"e2m {r[0]} (0x{mask:x}): \'{r[1][:110]}\'" for r in shown) +\n'
     '                         (f" (the reader rules out the other record on this bit, {\', \'.join(others)})" if others else ""))\n',
     '            if (word, bit) in SAME_ENABLE:\n'
     '                note = f" (the e2m also names this enable {\', \'.join(others)})"\n'
     '            else:\n'
     '                note = f" (the reader rules out the other record on this bit, {\', \'.join(others)})" if others else ""\n'
     '            parts.append("; ".join(f"e2m {r[0]} (0x{mask:x}): \'{r[1][:110]}\'" for r in shown) + note)\n'),
    ('for word, names in NAMES.items():\n    off = 2 + 2 * word\n',
     'if ONLY:\n    NAMES = {w: NAMES[w] for w in ONLY}\nfor word, names in NAMES.items():\n    off = 2 + 2 * word\n'),
    ('assert not any(l.startswith("0x003fb35c,") for l in lines)\n',
     'if ONLY:\n    open(gp, "w").write("\\n".join(lines))\n    print("written (--only: no cache row)")\n    sys.exit(0)\n'
     'assert not any(l.startswith("0x003fb35c,") for l in lines)\n'),
    ('    13: {0: "engine_retarder_switch_level_override",',
     '    11: {0: "proprietary_communication_enable", 1: "j1587_communication_enable", 2: "j1922_communication_enable",\n'
     '         3: "j1939_communication_enable"},\n'
     '    13: {0: "engine_retarder_switch_level_override",'),
]
for old, new in pairs:
    assert t.count(old) == 1, old[:60]
    t = t.replace(old, new)
open(p, "w").write(t)
print("generator: --only, SAME_ENABLE, word 11 names")
