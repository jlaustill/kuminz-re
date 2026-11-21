"""Append bin6 result lines for a range of bin indexes. usage: gen.py FIRST LAST   (inclusive indexes)
Keeps come from KEEPS (idx -> nothing extra), renames / drift / uncertain from SPECS."""
import json
import re
import sys

ROOT = '/home/linux/.claude/jobs/374b0424/tmp/w15/'
OUT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/output/'
BIN = json.load(open(ROOT + 'bins/bin6.json'))
RESULT = ROOT + 'results/result_W15_bin6.jsonl'

cpp = open(OUT + 'cm848_rom.ghidra.cpp', errors='replace').read().split('\n')
starts = []
for i, line in enumerate(cpp):
    m = re.match(r'^// Function: (\S+) @', line)
    if m:
        starts.append((i, m.group(1)))
fn_range = {name: (i, starts[k + 1][0] if k + 1 < len(starts) else len(cpp)) for k, (i, name) in enumerate(starts)}


def quote(fn, sub):
    s, e = fn_range[fn]
    body_start = next((k for k in range(s, e) if cpp[k] == '{'), s)      # skip the plate comment
    hits = [x.strip() for x in cpp[body_start:e] if sub in x and not x.strip().startswith(('/*', '//', '*'))]
    if not hits:
        raise SystemExit(f'quote not found: {fn}: {sub}')
    return f'{fn}: {hits[0]}'


def e2m_ref(r):
    off = format(int(r['offset'], 16), 'X')
    return f"e2m {r['block']} +{off} {r['record']}"


def keep_line(r):
    note = f"{e2m_ref(r)} '{r['description']}'"
    return {'kind': 'global', 'verdict': 'keep', 'address': r['address'], 'old': r['label_in_cpp'],
            'new': r['label_in_cpp'], 'e2m_note': note}


# idx -> dict(verdict=..., new, fn, sub, evidence, comment)   (rename)  /  drift / uncertain
exec(open(ROOT + 'agent_scratch/bin6/specs.py').read())

first, last = int(sys.argv[1]), int(sys.argv[2])
done = set()
try:
    for line in open(RESULT):
        line = line.strip()
        if line:
            done.add(json.loads(line)['address'])
except FileNotFoundError:
    pass

new_lines = []
for idx in range(first, last + 1):
    r = BIN[idx]
    if r['address'] in done:
        print('skip (already written)', idx, r['address'])
        continue
    spec = SPECS.get(idx)
    if spec is None:
        if idx in KEEP_NOTES:
            line = keep_line(r)
            if KEEP_NOTES[idx]:
                line['e2m_note'] = line['e2m_note']
        else:
            raise SystemExit(f'no verdict for idx {idx}')
    elif spec['verdict'] == 'rename':
        line = {'kind': 'global', 'verdict': 'confirmed', 'address': r['address'], 'old': r['label_in_cpp'],
                'new': spec['new'], 'evidence': spec['evidence'],
                'code_quote': quote(spec['fn'], spec['sub']), 'comment': spec['comment']}
    elif spec['verdict'] in ('drift', 'uncertain'):
        line = {'kind': 'global', 'verdict': spec['verdict'], 'address': r['address'], 'old': r['label_in_cpp'],
                'evidence': spec['evidence']}
    else:
        raise SystemExit('bad spec')
    new_lines.append(line)

with open(RESULT, 'a') as f:
    for line in new_lines:
        f.write(json.dumps(line, ensure_ascii=False) + '\n')
print('appended', len(new_lines), 'lines;', len(done), 'were already there')
for line in new_lines:
    print(line['address'], line['verdict'], line.get('new', ''), '|', line.get('code_quote', '')[:150])
