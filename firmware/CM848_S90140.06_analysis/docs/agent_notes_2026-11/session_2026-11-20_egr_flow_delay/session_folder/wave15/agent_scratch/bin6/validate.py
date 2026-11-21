"""Validate the bin6 result file against the brief's gate. usage: validate.py [--final]"""
import csv
import json
import re
import sys
from collections import Counter

ROOT = '/home/linux/.claude/jobs/374b0424/tmp/w15/'
OUT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/output/'
BIN = json.load(open(ROOT + 'bins/bin6.json'))
RESULT = ROOT + 'results/result_W15_bin6.jsonl'
FINAL = '--final' in sys.argv

BANNED = {"temp", "tmp", "press", "pos", "corr", "coef", "coeff", "thresh", "thr", "inj", "qty", "ctrl", "cfg",
          "cmd", "val", "vals", "idx", "cnt", "num", "ref", "spd", "eng", "prot", "lim", "mult", "comp", "adj", "trq",
          "tbl", "lkp", "sw", "calc", "accel", "decel", "pct", "freq", "volt", "amp", "deg", "sec", "diag", "cond", "req",
          "resp", "init", "tmr", "buf", "aux", "arb", "iat", "imt", "proc", "mgr", "util", "info", "stat", "msg",
          "tmptr", "thd", "amb", "avg", "frac", "filt", "ovr", "vlv", "cyl", "est", "hyst", "veh", "baro", "alt",
          "batt", "ict", "ccs", "mcf", "cmf", "vga"}
ALLOWED = {"rpm", "j1939", "pgn", "spn", "dtc", "obd", "ecm", "egr", "nox", "id", "adc", "pwm", "can", "pid", "tpu",
           "qadc", "vin", "tsc1", "vss"}
EEPROM = (0x3fd482, 0x3feec1)
RECENT_PREFIXES = ('exhaust_pressure', 'charge_pressure_estimate', 'engine_speed_state', 'average_engine_speed',
                   'main_engine_speed', 'backup_engine_speed', 'egr_valve_delta_pressure', 'engine_delta_pressure',
                   'pumping_torque_', 'nominal_engine_delta_pressure')

cpp_lines = open(OUT + 'cm848_rom.ghidra.cpp', errors='replace').read().split('\n')
cpp_text = '\n'.join(cpp_lines)
# function ranges
starts = []
for i, line in enumerate(cpp_lines):
    m = re.match(r'^// Function: (\S+) @', line)
    if m:
        starts.append((i, m.group(1)))
fn_range = {}
for k, (i, name) in enumerate(starts):
    fn_range[name] = (i, starts[k + 1][0] if k + 1 < len(starts) else len(cpp_lines))

used = set()
for fn in ('global_variables.csv', 'function_renames.csv', 'arrays.csv'):
    for l in open(OUT + fn, errors='replace'):
        p = l.split(',')
        if p[0].startswith('0x') and len(p) > 1:
            used.add(p[1])

binmap = {int(r['address'], 16): r for r in BIN}


def words(name):
    return [w.lower() for w in re.split(r'_', name) if w]


problems = []
seen_addr = {}
seen_new = {}
counts = Counter()
rows = []
for n, line in enumerate(open(RESULT), 1):
    line = line.strip()
    if not line:
        continue
    try:
        r = json.loads(line)
    except json.JSONDecodeError as e:
        problems.append(f'line {n}: bad json {e}')
        continue
    rows.append(r)
    a = int(r['address'], 16)
    tag = f"line {n} 0x{a:08x} {r.get('old')}"
    counts[r.get('verdict')] += 1
    if a not in binmap:
        problems.append(f'{tag}: address not in bin')
        continue
    b = binmap[a]
    if a in seen_addr:
        problems.append(f'{tag}: duplicate address (line {seen_addr[a]})')
    seen_addr[a] = n
    if r.get('old') != b['label_in_cpp']:
        problems.append(f"{tag}: old != label_in_cpp {b['label_in_cpp']}")
    if r.get('kind') != 'global':
        problems.append(f'{tag}: kind')
    v = r.get('verdict')
    if v == 'confirmed':
        new = r.get('new', '')
        for key in ('evidence', 'code_quote', 'comment'):
            if not r.get(key):
                problems.append(f'{tag}: missing {key}')
        if not re.fullmatch(r'[a-z][a-z0-9]*(_[a-z0-9]+)*', new):
            problems.append(f'{tag}: name format {new}')
        if new == r['old']:
            problems.append(f'{tag}: new == old')
        bad = sorted((set(words(new)) & BANNED) - ALLOWED)
        if bad:
            problems.append(f'{tag}: banned words {bad} in {new}')
        if re.search(r'(?<![a-z])0x|_[0-9a-f]*[a-f][0-9a-f]*\d[0-9a-f]*(_|$)', new):
            problems.append(f'{tag}: hex-looking part in {new}')
        in_eeprom = EEPROM[0] <= a <= EEPROM[1]
        if new.endswith('_cal') and not in_eeprom:
            problems.append(f'{tag}: _cal outside EEPROM mirror')
        if in_eeprom and not new.endswith('_cal'):
            problems.append(f'{tag}: EEPROM mirror name without _cal')
        if words(new)[-1] == 'protection' or new.endswith('_protection'):
            problems.append(f'{tag}: bare protection')
        if 'protection' in words(new):
            problems.append(f'{tag}: contains protection (check it says of what)')
        if new in used:
            problems.append(f'{tag}: new name already in a CSV: {new}')
        if re.search(r'\b' + re.escape(new) + r'\b', cpp_text):
            problems.append(f'{tag}: new name already in the .cpp: {new}')
        if new in seen_new:
            problems.append(f'{tag}: new name also used on 0x{seen_new[new]:08x}')
        seen_new[new] = a
        if new.startswith(RECENT_PREFIXES):
            problems.append(f'{tag}: recent prefix')
        if '(was' in r.get('comment', ''):
            problems.append(f'{tag}: comment has (was ...)')
        cq = r.get('code_quote', '')
        if ': ' not in cq:
            problems.append(f'{tag}: code_quote format')
        else:
            fn, _, ln = cq.partition(': ')
            if fn not in fn_range:
                problems.append(f'{tag}: code_quote function {fn} not found')
            else:
                s, e = fn_range[fn]
                body = [x.strip() for x in cpp_lines[s:e]]
                if ln.strip() not in body:
                    problems.append(f'{tag}: code_quote line not verbatim in {fn}')
                elif old_ref := r['old']:
                    pass
        # the quote should use the row: old name or new name should occur in the line? (checked by eye)
        ln = r.get('code_quote', '').partition(': ')[2]
        if r['old'] not in ln and new not in ln:
            problems.append(f"{tag}: note - code_quote line does not contain the old name ({r['old']})")
    elif v == 'keep':
        if r.get('new') != r.get('old'):
            problems.append(f'{tag}: keep with a different new')
        if not r.get('e2m_note'):
            problems.append(f'{tag}: keep without e2m_note')
        # a keep that breaks a rule
        in_eeprom = EEPROM[0] <= a <= EEPROM[1]
        o = r['old']
        if o.endswith('_cal') and not in_eeprom:
            problems.append(f'{tag}: KEEP but _cal outside the EEPROM mirror')
        if in_eeprom and not o.endswith('_cal'):
            problems.append(f'{tag}: KEEP but EEPROM mirror name lacks _cal')
        bad = sorted((set(words(o)) & BANNED) - ALLOWED)
        if bad:
            problems.append(f'{tag}: KEEP but banned words {bad}')
    elif v in ('drift', 'uncertain'):
        if not r.get('evidence'):
            problems.append(f'{tag}: missing evidence')
    else:
        problems.append(f'{tag}: unknown verdict {v}')

print('rows', len(rows), 'verdicts', dict(counts))
if FINAL:
    missing = [r['address'] for r in BIN if int(r['address'], 16) not in seen_addr]
    print('missing addresses', missing)
for p in problems:
    print('PROBLEM', p)
