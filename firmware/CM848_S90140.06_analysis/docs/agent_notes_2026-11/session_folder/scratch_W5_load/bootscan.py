import re, subprocess, sys
REPO = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays'
addrs = [int(a, 16) for a in sys.argv[1:]]
for a in addrs:
    out = subprocess.run(['python3', REPO + '/firmware/scripts/xref_addr.py', hex(a)], capture_output=True, text=True, cwd=REPO).stdout
    head = out.split('\n')[0]
    tot = re.search(r'# total: (\d+) read\(s\), (\d+) write\(s\)', out)
    boot = []
    fnames = []
    cur = None
    for line in out.split('\n'):
        m = re.match(r'^(\S+): (\d+)r/(\d+)w', line)
        if m:
            cur = m.group(1)
            fnames.append(cur)
        m2 = re.match(r'\s+\[(load|store)\s*\]\s+\S+\s+([0-9a-f]+):', line)
        if m2 and int(m2.group(2), 16) < 0x7F60:
            boot.append((cur, m2.group(2)))
    print(f'0x{a:08x} {head[:110]} | funcs={len(fnames)} {tot.groups() if tot else ""} BOOT={boot}')
