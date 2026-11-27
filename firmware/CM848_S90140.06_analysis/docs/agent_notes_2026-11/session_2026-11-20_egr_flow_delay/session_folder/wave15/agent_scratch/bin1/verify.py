"""Verify the bin1 result file: one valid line per bin record, code quotes found verbatim in the named function of the
.cpp, new names free and unique and rule-clean, keep notes in the agreed form."""
import collections
import json
import re
import sys

BIN = '/home/linux/.claude/jobs/374b0424/tmp/w15/bins/bin1.json'
RESULT = '/home/linux/.claude/jobs/374b0424/tmp/w15/results/result_W15_bin1.jsonl'
OUT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/output/'

bin_records = {r['address']: r for r in json.load(open(BIN))}
lines = [l for l in open(RESULT).read().split('\n') if l.strip()]
results = []
for i, l in enumerate(lines, 1):
    try:
        results.append(json.loads(l))
    except json.JSONDecodeError as e:
        print('line %d: invalid JSON: %s' % (i, e))
        sys.exit(1)
print('lines:', len(results), '(bin records: %d)' % len(bin_records))
addresses = [r['address'] for r in results]
dup = [a for a, c in collections.Counter(addresses).items() if c > 1]
print('duplicate addresses:', dup)
print('bin records without a line:', sorted(set(bin_records) - set(addresses)))
print('lines for addresses not in the bin:', sorted(set(addresses) - set(bin_records)))

cpp_text = open(OUT + 'cm848_rom.ghidra.cpp', errors='replace').read().split('\n')
starts = [(i, m.group(1)) for i, l in enumerate(cpp_text) if (m := re.match(r'^// Function: (\S+) @', l))]
body = {}
for k, (i, name) in enumerate(starts):
    end = starts[k + 1][0] if k + 1 < len(starts) else len(cpp_text)
    body[name] = [t.strip() for t in cpp_text[i:end]]

csv_text = ''.join(open(OUT + f, errors='replace').read() for f in
                   ('global_variables.csv', 'function_renames.csv', 'enums.csv', 'structure_definitions.csv',
                    'arrays.csv'))
cpp_joined = '\n'.join(cpp_text)
allowed = {'rpm', 'j1939', 'pgn', 'spn', 'dtc', 'obd', 'ecm', 'egr', 'nox', 'id', 'adc', 'pwm', 'can', 'pid', 'tpu',
           'qadc', 'vin', 'tsc1', 'vss'}
banned = {'temp', 'cnt', 'ref', 'val', 'calc', 'init', 'cfg', 'coef', 'tmptr', 'thd', 'cmd', 'amb', 'avg', 'frac', 'adj',
          'lmt', 'lim', 'sw', 'pos', 'filt', 'diag', 'ovr', 'vlv', 'pct', 'cyl', 'est', 'press', 'spd', 'accel',
          'hyst', 'inj', 'veh', 'baro', 'alt', 'trq', 'batt', 'imt', 'ct', 'aps', 'icp', 'cot', 'mcf', 'cmf', 'vgt',
          'pto', 'cc', 'eb', 'jcomm', 'el', 'tpe', 'chp', 'lsg', 'hsg', 'asg', 'vsg', 'accum', 'hi', 'lo'}
counts = collections.Counter(r['verdict'] for r in results)
print('verdicts:', dict(counts))
new_names = collections.Counter()
problems = 0
for r in results:
    a = r['address']
    rec = bin_records.get(a)
    if rec is None:
        continue
    if r['old'] != rec['label_in_cpp']:
        print('OLD NAME MISMATCH', a, r['old'], rec['label_in_cpp'])
        problems += 1
    v = r['verdict']
    if v == 'confirmed':
        new = r['new']
        new_names[new] += 1
        for key in ('evidence', 'code_quote', 'comment', 'new'):
            if not r.get(key):
                print('MISSING', key, a)
                problems += 1
        if not re.fullmatch(r'[a-z][a-z0-9_]*', new) or '__' in new or new.endswith('_'):
            print('BAD NAME SHAPE', a, new)
            problems += 1
        words = new.split('_')
        bad = [w for w in words if w in banned and w not in allowed]
        if bad:
            print('BANNED WORD', a, new, bad)
            problems += 1
        region_cal = rec['region'].startswith('EEPROM')
        if new.endswith('_cal') != region_cal:
            print('_cal RULE', a, new, rec['region'])
            problems += 1
        if re.search(r'(?<![A-Za-z0-9_])' + re.escape(new) + r'(?![A-Za-z0-9_])', csv_text + cpp_joined):
            print('NAME ALREADY EXISTS', a, new)
            problems += 1
        # code quote
        fn, _, line = r['code_quote'].partition(': ')
        if fn not in body:
            print('FUNCTION NOT FOUND', a, fn)
            problems += 1
        elif line.strip() not in body[fn]:
            print('QUOTE NOT FOUND', a, fn, '|', line)
            problems += 1
        elif r['old'] not in line:
            print('note: quote does not contain the old name', a, '|', line)
        if '(was ' in r['comment']:
            print('COMMENT HAS (was', a)
            problems += 1
        if ',' not in r['comment'] and False:
            pass
    elif v == 'keep':
        if r['new'] != r['old']:
            print('KEEP NEW != OLD', a)
            problems += 1
        if not re.fullmatch(r"e2m [0-9A-F]{4} \+[0-9A-F]+ \S+ '.*'", r.get('e2m_note', '')):
            print('BAD E2M NOTE', a, r.get('e2m_note'))
            problems += 1
    elif v in ('drift', 'uncertain'):
        if not r.get('evidence'):
            print('MISSING evidence', a)
            problems += 1
    else:
        print('UNKNOWN VERDICT', a, v)
        problems += 1
dups = [n for n, c in new_names.items() if c > 1]
print('duplicate new names:', dups)
print('problems:', problems)
