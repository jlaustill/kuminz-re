import re
import subprocess
import sys

ROOT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays'


def x(a):
    return subprocess.run(['python3', '-I', ROOT + '/firmware/scripts/xref_addr.py', hex(a)], capture_output=True,
                          text=True, cwd=ROOT).stdout.splitlines()


addrs = []
for t in sys.argv[1:]:
    if '-' in t:
        lo, hi = t.split('-')
        addrs += list(range(int(lo, 16), int(hi, 16) + 1, 2))
    else:
        addrs.append(int(t, 16))
for a in addrs:
    out = x(a)
    hdr = out[0] if out else ''
    nm = re.search(r'\((.*?)\)', hdr)
    tot = [l for l in out[:3] if l.startswith('# total')]
    print('## %s %s | %s' % (hex(a), (nm.group(1) if nm else 'unnamed'), (tot[0][2:] if tot else 'no total')))
    cur = None
    for l in out:
        m = re.match(r'^(\S+): (\d+r/\d+w)', l)
        if m:
            cur = m.group(1)
            print('   %s %s' % (m.group(1), m.group(2)), end='')
            ws = []
            continue
        m = re.match(r'\s+\[(load |store)\]\s+(\w+)\s+([0-9a-f]+):', l)
        if m:
            addr = int(m.group(3), 16)
            if addr < 0x7f60:
                print('  <BOOT %s %s>' % (m.group(1).strip(), m.group(3)), end='')
        elif l.strip() == '' and cur:
            print()
            cur = None
    print()
