"""List the absolute-long data addresses a CM550 code range references, with the e2m record and the current row.
usage: func_refs.py <start hex> <end hex>"""
import csv, re, subprocess, sys
ROM='/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin'
GV='/home/linux/.claude/jobs/374b0424/tmp/w15/r96/frozen/cm550/global_variables.csv'
rows={}
for line in open(GV, errors='replace'):
    p=line.split(',')
    if p and p[0].startswith('0x'):
        try: rows[int(p[0],16)]=(p[1],p[2])
        except ValueError: pass
start=int(sys.argv[1],16); end=int(sys.argv[2],16)
out=subprocess.run(['python3','/home/linux/.claude/jobs/374b0424/tmp/w15/r93/tools/m68k.py',ROM,sys.argv[1],sys.argv[2]],capture_output=True,text=True).stdout
addrs={}
for line in out.splitlines():
    for m in re.finditer(r'\(0x(8[0-9a-f]{5})\)\.l|#0x(8[0-9a-f]{5})\b', line):
        a=int(m.group(1) or m.group(2),16)
        addrs.setdefault(a,[]).append(line.split(':')[0])
for a in sorted(addrs):
    e2m=subprocess.run(['python3','/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/scripts/e2m_block_addresses.py','--firmware','cm550','--address',hex(a)],capture_output=True,text=True).stdout.strip().split('\n')[0]
    print(f'0x{a:x} row={rows.get(a)} n={len(addrs[a])} | {e2m[:150]}')
