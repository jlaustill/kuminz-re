"""Round 97 stage F: the removal set against R5's absorbed_rows.txt (addresses on each line) and R7's seven rows."""
import json
import re
W = '/home/linux/.claude/jobs/374b0424/tmp/w15/r97'
o = json.load(open(f'{W}/overrides_r97.json'))
rem = {int(k, 16) for k in o['remove_globals']['CM550']}
listed = set()
for line in open(f'{W}/scratch/R5/investigator/absorbed_rows.txt'):
    m = re.match(r'^\s*(0x[0-9a-fA-F]+)', line)
    if m:
        listed.add(int(m.group(1), 16))
r7 = {0x8002b0, 0x8002b2, 0x8002b6, 0x8002b8, 0x8002bc, 0x8002be, 0x8002c0}
junk = {0x805670, 0x805676}
print('listed by the investigator', len(listed), '| removals', len(rem))
print('listed, not removed:', sorted(hex(a) for a in listed - rem))
print('removed, not listed (and not R7 / junk):', sorted(hex(a) for a in rem - listed - r7 - junk))
print('R7 rows removed', len(r7 & rem), '| junk removed', len(junk & rem))
