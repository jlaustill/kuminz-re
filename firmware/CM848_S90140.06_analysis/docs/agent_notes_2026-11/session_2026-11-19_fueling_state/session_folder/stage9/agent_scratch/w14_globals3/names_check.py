"""usage: names_check.py NAME [NAME ...]  (or --file FILE with one name per line)
Reports where each candidate name already occurs as a whole token: output/*.csv, the .cpp, the .hpp headers, the
CM550 CSVs. Also applies the rename gate's name rules (banned words, format, hex-looking part, _cal by region)."""
import glob
import os
import re
import sys

OUT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/output/'
CM550 = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM550_J90350.00_analysis/output/'
BANNED = {"temp", "tmp", "press", "pos", "corr", "coef", "coeff", "thresh", "thr", "inj", "qty", "ctrl", "cfg",
          "cmd", "val", "vals", "idx", "cnt", "num", "ref", "spd", "eng", "prot", "lim", "mult", "comp", "adj", "trq",
          "tbl", "lkp", "sw", "calc", "accel", "decel", "pct", "freq", "volt", "amp", "deg", "sec", "diag", "cond", "req",
          "resp", "init", "tmr", "buf", "aux", "arb", "iat", "imt", "proc", "mgr", "util", "info", "stat", "msg"}


def words(name):
    out = []
    for p in name.split('_'):
        out += [w.lower() for w in re.findall(r"[A-Z]?[a-z]+|[A-Z]+(?![a-z])|\d+", p)]
    return out


args = sys.argv[1:]
if args and args[0] == '--file':
    args = [l.strip() for l in open(args[1]) if l.strip()]
texts = {}
for p in glob.glob(OUT + '*.csv') + glob.glob(OUT + '*.cpp') + glob.glob(OUT + '*.hpp') + glob.glob(CM550 + '*.csv'):
    texts[p] = open(p, errors='replace').read()
seen = {}
for name in args:
    problems = []
    if not re.fullmatch(r"[a-z][a-z0-9]*(_[a-z0-9]+)*", name):
        problems.append('format')
    bad = sorted(set(words(name)) & BANNED)
    if bad:
        problems.append(f'banned {bad}')
    if re.search(r"(?<![a-z])0x|_[0-9a-f]*[a-f][0-9a-f]*\d[0-9a-f]*(_|$)", name):
        problems.append('hex-looking part')
    if name.split('_')[-1] == 'protection':
        problems.append('bare protection')
    pat = re.compile(r'(?<![A-Za-z0-9_])' + re.escape(name) + r'(?![A-Za-z0-9_])')
    hits = [os.path.basename(p) for p, t in texts.items() if pat.search(t)]
    if hits:
        problems.append(f'already present in {hits}')
    if name in seen:
        problems.append('duplicate in this list')
    seen[name] = True
    print(('OK   ' if not problems else 'FAIL ') + name + ('  ' + '; '.join(problems) if problems else ''))
