"""One line per proposed table: e2m record, gap to the next record, dump count, first..last point, rows inside."""
import re
J = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/scratch/N2/judge/"
txt = open(J + 'check_all_out.txt').read().split('=== ')[1:]
for blk in txt:
    head = blk.split('\n')[0]
    if 'word[' not in head:
        continue
    m = re.search(r"e2m at address: \[\('(0x[0-9a-f]+)', '\+0', '([^']+)', '([^']+)', '([^']+)'", blk)
    g = re.search(r"next e2m record: (0x[0-9a-f]+) \['([^']*)'.*?gap (\d+) bytes = word\[(\d+)\]", blk)
    d = re.search(r"dump byte count (\d+) -> word\[(\d+)\]; points \[([^\]]*)\]", blk)
    ins = re.search(r"rows inside \[[^)]*\): (\[.*\])", blk)
    pts = d.group(3).split(', ') if d else []
    print(head.split(' (')[0][:100], '|', (m.group(2) + ' ' + m.group(3) + ' ' + m.group(4)) if m else 'NO E2M',
          '| gap', g.group(3) if g else '?', g.group(2) if g else '',
          '| dump', (d.group(1) + ' pts ' + pts[0] + '..' + pts[-1]) if d else '-',
          '| inside', len(eval(ins.group(1))) if ins else '?', '| !!' if '!!' in blk else '')
