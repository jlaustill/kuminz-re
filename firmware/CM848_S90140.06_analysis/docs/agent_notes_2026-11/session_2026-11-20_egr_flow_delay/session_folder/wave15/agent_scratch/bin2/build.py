"""Validate the verdict modules v_*.py in this folder and write the result file.
usage: python3 build.py            (writes the result jsonl from every verdict found, in bin order)
Each v_*.py defines V = [ {...}, ... ] with: address, verdict, and the verdict's fields.
"""
import csv
import glob
import importlib.util
import json
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
BIN = '/home/linux/.claude/jobs/374b0424/tmp/w15/bins/bin2.json'
OUT = '/home/linux/.claude/jobs/374b0424/tmp/w15/results/result_W15_bin2.jsonl'
REPO = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/output'
CPP = os.path.join(REPO, 'cm848_rom.ghidra.cpp')
CSV = os.path.join(REPO, 'global_variables.csv')
RESULTS_DIR = '/home/linux/.claude/jobs/374b0424/tmp/w15/results'

bin_items = json.load(open(BIN))
by_addr = {int(r['address'], 16): r for r in bin_items}
order = {int(r['address'], 16): i for i, r in enumerate(bin_items)}

cpp_text = open(CPP).read()
cpp_lines = cpp_text.split('\n')
starts = [(i, m.group(1)) for i, line in enumerate(cpp_lines) if (m := re.match(r'^// Function: (\S+) @', line))]
func_range = {name: (i, starts[k + 1][0] if k + 1 < len(starts) else len(cpp_lines)) for k, (i, name) in enumerate(starts)}

csv_names = set()
with open(CSV, newline='') as fh:
    for row in csv.reader(fh):
        if len(row) >= 2:
            csv_names.add(row[1])


def name_in_cpp(name):
    return re.search(r'(?<![A-Za-z0-9_])' + re.escape(name) + r'(?![A-Za-z0-9_])', cpp_text) is not None


def code_lines_of(func):
    """Return the code lines (not comment text) of a function body: (line number, stripped text)."""
    s, e = func_range[func]
    out = []
    in_comment = False
    for n in range(s, e):
        raw = cpp_lines[n]
        line = raw.strip()
        if not line:
            continue
        if in_comment:
            if '*/' in line:
                in_comment = False
            continue
        if line.startswith('//'):
            continue
        if line.startswith('/*'):
            if '*/' not in line:
                in_comment = True
            continue
        out.append((n + 1, line))
    return out


def check_quote(q):
    if ': ' not in q:
        return 'code_quote needs "<function>: <line>"'
    func, line = q.split(': ', 1)
    line = line.strip()
    if func not in func_range:
        return f'function {func} not found in the cpp'
    for n, text in code_lines_of(func):
        if line in text:
            return None
    # maybe the quote is a comment line
    s, e = func_range[func]
    for n in range(s, e):
        if line in cpp_lines[n]:
            return f'quote found in {func} only inside a comment / header line {n + 1}'
    return f'quote not found in {func}: {line!r}'


entries = {}
for path in sorted(glob.glob(os.path.join(HERE, 'v_*.py'))):
    spec = importlib.util.spec_from_file_location(os.path.basename(path)[:-3], path)
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    for e in mod.V:
        a = int(e['address'], 16)
        if a in entries:
            print(f'DUPLICATE verdict for {e["address"]} (in {os.path.basename(path)})')
            sys.exit(1)
        e = dict(e)
        e['_src'] = os.path.basename(path)
        entries[a] = e

errors = []
news = {}
out_lines = []
for a in sorted(entries, key=lambda x: order.get(x, 9999)):
    e = entries[a]
    if a not in by_addr:
        errors.append(f'{e["address"]}: not in bin')
        continue
    rec = by_addr[a]
    old = rec['label_in_cpp']
    v = e['verdict']
    addr = rec['address']
    if e['address'] != addr:
        errors.append(f'{e["address"]}: address spelling differs from the bin ({addr})')
    if e.get('old', old) != old:
        errors.append(f'{addr}: old {e.get("old")!r} != bin label {old!r}')
    line = {'kind': 'global', 'verdict': v, 'address': addr, 'old': old}
    in_mirror = rec['region'].startswith('EEPROM')
    if v == 'rename':
        new = e['new']
        if not re.fullmatch(r'[a-z][a-z0-9]*(_[a-z0-9]+)*', new):
            errors.append(f'{addr}: new name {new!r} is not snake_case')
        if new == old:
            errors.append(f'{addr}: rename to the same name')
        if in_mirror and not new.endswith('_cal'):
            errors.append(f'{addr}: EEPROM mirror row must end _cal: {new}')
        if (not in_mirror) and new.endswith('_cal'):
            errors.append(f'{addr}: _cal outside the EEPROM mirror: {new}')
        if new in csv_names:
            errors.append(f'{addr}: new name {new} already in global_variables.csv')
        if name_in_cpp(new):
            errors.append(f'{addr}: new name {new} already appears in the cpp')
        if new in news:
            errors.append(f'{addr}: new name {new} also used at {news[new]}')
        news[new] = addr
        for w in ('init', 'cfg', 'cnt', 'tmp', 'temp', 'ref', 'val', 'calc', 'coef', 'avg', 'lim', 'pos', 'cmd', 'thd'):
            if re.search(r'(^|_)' + w + r'(_|$)', new):
                errors.append(f'{addr}: banned abbreviation {w!r} in {new}')
        for k in ('evidence', 'code_quote', 'comment'):
            if not e.get(k):
                errors.append(f'{addr}: rename needs {k}')
        err = check_quote(e.get('code_quote', ''))
        if err:
            errors.append(f'{addr}: {err}')
        if '(was ' in e.get('comment', ''):
            errors.append(f'{addr}: comment must not contain "(was"')
        if '\n' in e.get('evidence', ''):
            errors.append(f'{addr}: evidence must be one line')
        line.update({'verdict': 'confirmed', 'new': new, 'evidence': e['evidence'], 'code_quote': e['code_quote'],
                     'comment': e['comment']})
    elif v == 'keep':
        note = e.get('e2m_note', '')
        exp = f"e2m {rec['block']} +{rec['offset'].lstrip('0') or '0'} {rec['record']} '"
        if not note.startswith(exp) or note.count("'") < 2:
            errors.append(f'{addr}: e2m_note must start with {exp!r} and hold the quoted description; got {note!r}')
        if in_mirror and not old.endswith('_cal'):
            errors.append(f'{addr}: kept name in the EEPROM mirror lacks _cal')
        if (not in_mirror) and old.endswith('_cal'):
            errors.append(f'{addr}: kept name ends _cal outside the mirror')
        line.update({'new': old, 'e2m_note': note})
    elif v in ('drift', 'uncertain'):
        if not e.get('evidence'):
            errors.append(f'{addr}: {v} needs evidence')
        if '\n' in e.get('evidence', ''):
            errors.append(f'{addr}: evidence must be one line')
        line.update({'evidence': e['evidence']})
    else:
        errors.append(f'{addr}: unknown verdict {v}')
        continue
    out_lines.append(json.dumps(line, ensure_ascii=False))

missing = [r['address'] for r in bin_items if int(r['address'], 16) not in entries]
print(f'{len(entries)} verdicts, {len(missing)} bin records still without one')
if errors:
    print('ERRORS:')
    for er in errors:
        print('  ', er)
    sys.exit(2)

with open(OUT, 'w') as fh:
    fh.write('\n'.join(out_lines) + '\n')
print(f'wrote {len(out_lines)} lines to {OUT}')

# cross-agent collision check on new names
others = {}
for p in glob.glob(os.path.join(RESULTS_DIR, 'result_W15_bin*.jsonl')):
    if p.endswith('bin2.jsonl'):
        continue
    for ln in open(p):
        ln = ln.strip()
        if ln.startswith('{'):
            try:
                j = json.loads(ln)
            except Exception:
                continue
            if j.get('verdict') == 'confirmed' and j.get('new'):
                others[j['new']] = (os.path.basename(p), j['address'])
for n, a in news.items():
    if n in others:
        print(f'COLLISION with another bin: {n} ({a}) also in {others[n]}')
if len(sys.argv) > 1 and sys.argv[1] == 'missing':
    print('missing:', ' '.join(missing))
