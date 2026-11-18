import json
import re
import subprocess

ROOT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/'
ROM = ROOT + 'firmware/CM848_S90140.06_analysis/originals/cm848_rom.bin'
RESULT = '/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W4_governor.jsonl'

text = subprocess.run(['powerpc-linux-gnu-objdump', '-D', '-b', 'binary', '-m', 'powerpc', '-EB', '--start-address=0', '--stop-address=0x7f60', ROM],
                      capture_output=True, text=True).stdout
lines = [l for l in text.splitlines() if re.match(r'^\s+[0-9a-f]+:\t', l)]
print('boot instructions disassembled:', len(lines))
addresses = []
for raw in open(RESULT):
    row = json.loads(raw)
    if row['kind'] in ('global', 'new_global') and 'address' in row:
        value = int(row['address'], 16)
        if 0x3f9800 <= value <= 0x3fdb30 or 0x3fee08 <= value <= 0x3fee3d:
            addresses.append((value, row.get('old') or row.get('new')))
print('window rows:', len(addresses))
for value, name in sorted(set(addresses)):
    signed = value - 0x400000
    unsigned = value & 0xffff
    pattern = re.compile(r'(?:,|\s)(%d|%d)(?:\(|$)' % (signed, unsigned))
    hits = [l.split(':')[0].strip() for l in lines if pattern.search(l.split('\t', 1)[-1] if '\t' in l else l) and ('lis' not in l.split('\t')[-1][:4])]
    print('0x%x %-60s %s' % (value, name, ('HITS ' + ','.join(hits[:6])) if hits else 'none'))
