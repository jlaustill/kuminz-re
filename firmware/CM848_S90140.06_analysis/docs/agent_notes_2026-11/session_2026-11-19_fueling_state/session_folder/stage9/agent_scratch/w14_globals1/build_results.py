import json
import re
import sys
import os

sys.path.insert(0, '/tmp/w14_globals1')
import content_a
import content_b
import names

BIN = '/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/bins/globals1.json'
OUTFILE = '/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/result_W14_globals1.jsonl'
CPP = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp'

d = json.load(open(BIN))
content = {}
content.update(content_a.A)
content.update(content_b.B)

cpp_lines = [l.strip() for l in open(CPP, errors='replace').read().split('\n')]
cpp_set = set(cpp_lines)
cpp_text = '\n'.join(cpp_lines)

# dump values read directly from originals/cm848_ram.bin at the row width for rows without an e2m record
VERIFIED = {10: 500, 11: 113703, 12: 113703}
problems = []
lines = []
for i, x in enumerate(d):
    c = content.get(i)
    if c is None:
        problems.append('no content for %d %s' % (i, x['current_name']))
        continue
    base = {"kind": "global", "address": x['address'], "old": x['current_name']}
    if c.get('keep'):
        rec = dict(base, verdict='keep', new=x['current_name'], e2m_note=c['e2m_note'])
        rec = {k: rec[k] for k in ("kind", "verdict", "address", "old", "new", "e2m_note")}
        lines.append(rec)
        continue
    if c.get('drift'):
        rec = {"kind": "global", "verdict": "drift", "address": x['address'], "old": x['current_name'], "evidence": c['evidence']}
        lines.append(rec)
        continue
    new = c['new']
    if names.NEW.get(i) != new:
        problems.append('name mismatch for %d: content %s vs names %s' % (i, new, names.NEW.get(i)))
    quote = c['quote']
    if quote not in cpp_set:
        # fragment of 20+ chars inside one line?
        if len(quote) >= 20 and any(quote in l for l in cpp_lines):
            pass
        else:
            problems.append('quote not found for %d: %s' % (i, quote))
    if x['current_name'] not in quote and new not in quote:
        problems.append('quote has no row name for %d (%s): %s' % (i, x['current_name'], quote))
    rec = {"kind": "global", "verdict": "confirmed", "address": x['address'], "old": x['current_name'], "new": new,
           "evidence": c['evidence'], "code_quote": quote, "comment": c['comment']}
    if c.get('type_note'):
        rec['type_note'] = c['type_note']
    if c.get('split'):
        rec['split'] = c['split']
        sn = names.SPLIT_NAMES[i]
        for s, (a, n) in zip(c['split'], sn):
            if s['address'] != a or s['name'] != n:
                problems.append('split mismatch %d %s %s' % (i, s['address'], s['name']))
    if c.get('old_comment_wrong'):
        rec['old_comment_wrong'] = True
    lines.append(rec)

# dump-value check: numbers quoted as "N in the dump" must match dump_raw (raw at the row width) where the bin has one
for i, (x, rec) in enumerate(zip(d, lines)):
    if rec['verdict'] != 'confirmed':
        continue
    txt = rec['comment']
    m = re.findall(r"(-?\d+) in the dump", txt)
    raw = x.get('dump_raw', '')
    if raw == '' and i in VERIFIED:
        raw = str(VERIFIED[i])
    if m:
        if raw == '':
            problems.append('%d %s quotes a dump value but the bin has none: %s' % (i, x['current_name'], m))
        elif not any(int(q) == int(raw) for q in m):
            # allow the main row's comment to quote the second record's value as well; require the first quote to match
            problems.append('%d %s dump_raw %s vs quoted %s' % (i, x['current_name'], raw, m))
    if re.search(r"\bdump\b", rec['evidence']):
        m2 = re.findall(r"(-?\d+) in the dump", rec['evidence'])
        if m2 and raw != '' and not any(int(q) == int(raw) for q in m2):
            problems.append('%d evidence dump_raw %s vs quoted %s' % (i, raw, m2))

if len(lines) != len(d):
    problems.append('line count %d vs bin %d' % (len(lines), len(d)))
for p in problems:
    print('PROBLEM', p)
if not problems or '--force' in sys.argv:
    with open(OUTFILE, 'w') as f:
        for rec in lines:
            f.write(json.dumps(rec, ensure_ascii=True) + '\n')
    print('wrote', len(lines), 'lines to', OUTFILE)
else:
    print('not written')
