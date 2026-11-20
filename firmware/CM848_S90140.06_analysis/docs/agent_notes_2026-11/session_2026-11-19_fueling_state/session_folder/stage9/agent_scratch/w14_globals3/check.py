"""Self-check of result_W14_globals3.jsonl: the same checks apply_W14.py makes (address in bin, old = current CSV name, name format,
unique names, quote in the .cpp with the old name), plus _cal by region, dump values quoted in the comments, and name clashes with any
other result_W14_*.jsonl file."""
import glob
import json
import os
import re
import sys

STAGE9 = '/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/'
REPO = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/'
OUT = REPO + 'firmware/CM848_S90140.06_analysis/output/'
ORIG = REPO + 'firmware/CM848_S90140.06_analysis/originals/'
RESULT = STAGE9 + 'result_W14_globals3.jsonl'
EEPROM = (0x3fd482, 0x3feec1)
BANNED = {"temp", "tmp", "press", "pos", "corr", "coef", "coeff", "thresh", "thr", "inj", "qty", "ctrl", "cfg",
          "cmd", "val", "vals", "idx", "cnt", "num", "ref", "spd", "eng", "prot", "lim", "mult", "comp", "adj", "trq",
          "tbl", "lkp", "sw", "calc", "accel", "decel", "pct", "freq", "volt", "amp", "deg", "sec", "diag", "cond", "req",
          "resp", "init", "tmr", "buf", "aux", "arb", "iat", "imt", "proc", "mgr", "util", "info", "stat", "msg"}
norm = lambda t: re.sub(r'\s+', '', t)


def words(name):
    out = []
    for p in name.split('_'):
        out += [w.lower() for w in re.findall(r"[A-Z]?[a-z]+|[A-Z]+(?![a-z])|\d+", p)]
    return out


bin_items = json.load(open(STAGE9 + 'bins/globals3.json'))
cpp_lines = open(OUT + 'cm848_rom.ghidra.cpp', errors='replace').read().split('\n')
cpp_norm = norm('\n'.join(cpp_lines))
norm_lines = [norm(l) for l in cpp_lines]
gv = {}
for l in open(OUT + 'global_variables.csv', errors='replace'):
    if l.startswith('0x'):
        p = (l.rstrip('\n').split(',', 3) + [''])[:4]
        gv[int(p[0], 16)] = p
gv_names = {v[1] for v in gv.values()}
fr_names = set()
for l in open(OUT + 'function_renames.csv', errors='replace'):
    if l.startswith('0x'):
        fr_names.add(l.split(',')[1])
rom = open(ORIG + 'cm848_rom.bin', 'rb').read()
ram = open(ORIG + 'cm848_ram.bin', 'rb').read()
other_names = {}
for path in glob.glob(STAGE9 + 'result_W14_*.jsonl'):
    if os.path.abspath(path) == os.path.abspath(RESULT):
        continue
    for line in open(path):
        if line.strip():
            r = json.loads(line)
            if r.get('new'):
                other_names[r['new']] = os.path.basename(path)

lines = [json.loads(l) for l in open(RESULT) if l.strip()]
problems, notes = [], []
if len(lines) != len(bin_items):
    problems.append(f'{len(lines)} lines for {len(bin_items)} items')
seen = {}
counts = {}
for n, (r, it) in enumerate(zip(lines, bin_items), 1):
    tag = f"line {n} {it['address']}"
    a = int(it['address'], 16)
    if r['address'] != it['address']:
        problems.append(f"{tag}: address {r['address']} not in bin order")
    if r['old'] != it['current_name'] or r['old'] != gv[a][1]:
        problems.append(f"{tag}: old {r['old']} != bin {it['current_name']} / csv {gv[a][1]}")
    if r['kind'] != 'global' or r['verdict'] not in ('confirmed', 'keep', 'drift', 'uncertain'):
        problems.append(f"{tag}: bad kind / verdict")
    counts[r['verdict']] = counts.get(r['verdict'], 0) + 1
    if r['verdict'] == 'keep':
        if r.get('new') != r['old'] or len(r.get('e2m_note', '').split()) < 5 or r['e2m_note'].split()[0] != 'e2m':
            problems.append(f'{tag}: keep fields')
    if r['verdict'] == 'drift' and not r.get('evidence'):
        problems.append(f'{tag}: drift without evidence')
    if r['verdict'] != 'confirmed':
        continue
    new = r['new']
    if new == r['old']:
        problems.append(f'{tag}: rename to the same name')
    if not re.match(r'^[a-z][a-z0-9_]*[a-z0-9]$', new) or '__' in new or not re.fullmatch(r"[a-z][a-z0-9]*(_[a-z0-9]+)*", new):
        problems.append(f'{tag}: name format {new}')
    if new in gv_names or new in fr_names:
        problems.append(f'{tag}: name exists in the CSVs {new}')
    if new in seen:
        problems.append(f'{tag}: duplicate of {seen[new]} {new}')
    seen[new] = it['address']
    if new in other_names:
        problems.append(f'{tag}: {new} also in {other_names[new]}')
    bad = sorted(set(words(new)) & BANNED)
    if bad:
        problems.append(f'{tag}: banned words {bad} in {new}')
    if re.search(r"(?<![a-z])0x|_[0-9a-f]*[a-f][0-9a-f]*\d[0-9a-f]*(_|$)", new):
        problems.append(f'{tag}: hex-looking part in {new}')
    if new.split('_')[-1] == 'protection':
        problems.append(f'{tag}: bare protection')
    in_eeprom = EEPROM[0] <= a <= EEPROM[1]
    if new.endswith('_cal') != in_eeprom:
        problems.append(f'{tag}: _cal rule (eeprom={in_eeprom}) for {new}')
    if re.search(r'\b(init|calc)\b', new):
        problems.append(f'{tag}: init/calc in {new}')
    # name appears in the .cpp / headers?
    for path in glob.glob(OUT + '*.cpp') + glob.glob(OUT + '*.hpp'):
        if re.search(r'(?<![A-Za-z0-9_])' + re.escape(new) + r'(?![A-Za-z0-9_])', open(path, errors='replace').read()):
            problems.append(f'{tag}: {new} occurs in {os.path.basename(path)}')
    q = r.get('code_quote', '')
    if len(norm(q)) < 12 or norm(q) not in cpp_norm or r['old'] not in q:
        problems.append(f'{tag}: code_quote not found with the old name: {q[:70]}')
    elif not any(norm(q) in nl for nl in norm_lines):
        notes.append(f'{tag}: quote spans wrapped lines')
    comment = r.get('comment', '')
    if not comment or not r.get('evidence'):
        problems.append(f'{tag}: comment / evidence missing')
    if '(was' in comment:
        problems.append(f'{tag}: comment carries (was ...)')
    if len(comment) > 760:
        notes.append(f'{tag}: comment {len(comment)} chars')
    if re.search(r'[^\x20-\x7e]', comment + r.get('evidence', '')):
        problems.append(f'{tag}: non-ascii text')
    # quoted dump values: "N in the dump" at the row width
    width = it['row_width_bytes'] if it['current_type'] in ('byte', 'word', 'dword', 'i16', 'pointer') else 0
    if a < 0x3f0000:
        data, off = rom, a
    else:
        data, off = ram, a - 0x3FA000
    if width and off + width <= len(data) and a < 0x40c200:
        raw = int.from_bytes(data[off:off + width], 'big')
        signed = int.from_bytes(data[off:off + width], 'big', signed=True)
        if r.get('split'):
            raw = int.from_bytes(data[off:off + 2], 'big')
            signed = int.from_bytes(data[off:off + 2], 'big', signed=True)
        for q2 in re.findall(r'(-?\d+) in the dump', comment):
            if int(q2) not in (raw, signed):
                problems.append(f'{tag}: comment quotes {q2} in the dump, the row reads {raw} / {signed}')
    elif a >= 0x40c200:
        if re.search(r'\d in the dump', comment) or 'dump_raw' in comment:
            problems.append(f'{tag}: dump value quoted for an address the dump does not cover')
print('verdicts:', counts)
print('\n'.join('PROBLEM ' + p for p in problems) if problems else 'checks: no problems')
print('\n'.join('note: ' + n for n in notes))
sys.exit(1 if problems else 0)
