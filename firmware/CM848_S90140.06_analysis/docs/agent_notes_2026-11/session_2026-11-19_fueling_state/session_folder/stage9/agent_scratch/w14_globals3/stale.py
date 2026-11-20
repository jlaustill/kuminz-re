"""Stale-name sweep: old -> new map from every result_W14_globals*.jsonl (mine included); report every old name used as a whole token in
my comment / split comment / type_note texts. Also lists dump values quoted by other bins for addresses affected by the dump gap."""
import glob
import json
import re

STAGE9 = '/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/'
MINE = STAGE9 + 'result_W14_globals3.jsonl'
old_to_new = {}
for path in sorted(glob.glob(STAGE9 + 'result_W14_globals*.jsonl')):
    for line in open(path):
        if line.strip():
            r = json.loads(line)
            if r['verdict'] == 'confirmed' and r.get('new') and r['new'] != r['old']:
                old_to_new[r['old']] = (r['new'], path.split('result_W14_')[1])
print(len(old_to_new), 'renames in all globals result files')
hits = 0
for n, line in enumerate(open(MINE), 1):
    r = json.loads(line)
    texts = {'comment': r.get('comment', ''), 'type_note': r.get('type_note', '')}
    for i, s in enumerate(r.get('split', [])):
        texts[f'split{i}.comment'] = s.get('comment', '')
    for field, text in texts.items():
        for old, (new, src) in old_to_new.items():
            if r.get('old') == old:
                continue            # a row's own old name is fine only where it is not in the comment; checked below
            if re.search(r'(?<![A-Za-z0-9_])' + re.escape(old) + r'(?![A-Za-z0-9_])', text):
                hits += 1
                print(f"line {n} {r['address']} {field}: cites old name {old} -> {new} ({src})")
    # the row's own old name in its comment
    for field, text in texts.items():
        if r.get('old') and re.search(r'(?<![A-Za-z0-9_])' + re.escape(r['old']) + r'(?![A-Za-z0-9_])', text):
            print(f"line {n} {r['address']} {field}: cites its own old name {r['old']}")
print(hits, 'stale citations of other rows')
# rows in other bins in the dump gap
print('--- other bins: rows at 0x40c200-0x40c2ff and their dump wording')
for path in sorted(glob.glob(STAGE9 + 'result_W14_globals*.jsonl')):
    for line in open(path):
        if line.strip():
            r = json.loads(line)
            a = int(r['address'], 16)
            if 0x40c200 <= a < 0x40c300:
                text = (r.get('comment') or r.get('evidence') or '')
                print(path.split('result_W14_')[1], r['address'], r['verdict'], r.get('old'), '->', r.get('new'),
                      '| dump wording:', re.findall(r'[^.;(]*(?:dump)[^.;)]*', text)[:3])
