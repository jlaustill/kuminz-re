import re
import subprocess
import sys

# usage: xs.py <name-or-0xaddress>...
# compact xref: one line per symbol, per-function read/write counts, width, and a BOOT flag when any
# access instruction sits below 0x7F60 (boot ROM 0x0-0x3C2F or its kernel-image copy 0x3C30-0x7F60).
ROOT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/'
OUT = ROOT + 'firmware/CM848_S90140.06_analysis/output/'
by_name = {}
by_addr = {}
with open(OUT + 'global_variables.csv') as handle:
    for line in handle:
        if line.startswith('#'):
            continue
        parts = line.rstrip('\n').split(',', 3)
        if len(parts) < 3 or not parts[0].startswith('0x'):
            continue
        by_name.setdefault(parts[1], []).append((parts[0], parts[2]))
        by_addr[int(parts[0], 16)] = (parts[1], parts[2])

for arg in sys.argv[1:]:
    if arg.startswith('0x'):
        addr = int(arg, 16)
        name, kind = by_addr.get(addr, ('?', '?'))
    else:
        if arg not in by_name:
            print('NO ROW', arg)
            continue
        addr = int(by_name[arg][0][0], 16)
        name, kind = arg, by_name[arg][0][1]
    proc = subprocess.run(['python3', ROOT + 'firmware/scripts/xref_addr.py', hex(addr)], capture_output=True, text=True, cwd=ROOT)
    funcs = []
    boot = []
    widths = ''
    total = ''
    for text in proc.stdout.splitlines():
        match = re.match(r'^# total: (.*)$', text)
        if match:
            total = match.group(1)
        match = re.match(r'^(\S+): (\d+)r/(\d+)w', text)
        if match:
            funcs.append(match.group(1) + ' ' + match.group(2) + 'r/' + match.group(3) + 'w')
        match = re.match(r'^\s+\[(load |store)\]\s+(\w+)\s+([0-9a-f]+):', text)
        if match:
            ins = int(match.group(3), 16)
            if ins < 0x7F60:
                boot.append(hex(ins))
    print('0x%08x %s [%s] | %s | %s | %s' % (addr, name, kind, total.replace('read(s)', 'r').replace('write(s)', 'w'), '; '.join(funcs), ('BOOT-USERS ' + ','.join(boot)) if boot else 'no boot users'))
