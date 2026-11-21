import subprocess, sys
base = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/scripts/xref_addr.py'
addrs = list(range(0x40a20a, 0x40a24a, 2))
for a in addrs:
    out = subprocess.run(['python3', base, hex(a)], capture_output=True, text=True).stdout
    lines = out.split('\n')
    head = lines[0] if lines else ''
    total = [l for l in lines if l.startswith('# total')]
    funcs = [l for l in lines if l and not l.startswith('#') and not l.startswith(' ')]
    print(hex(a), head[:80].replace('# xref ', ''), '|', total[0] if total else '', '|', '; '.join(funcs))
