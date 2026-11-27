"""Map the auxiliary driver fault blocks of updateEngineSyncStatus (0xd610-0xe77a).

Each block compares one feedback bit with one command bit; when they differ it counts
an error counter (feedback on / command off, or feedback off / command on) and sets a
fault bit; when they agree it counts a recovery counter while the fault bit is set.
This script prints, per block, the feedback byte/bit, the command byte/bit and every
absolute byte counter (0x800150-0x800180) with the fault word/bit next to it.
"""
import re
import subprocess
import sys

TOOL = '/home/linux/.claude/jobs/374b0424/tmp/w15/r93/tools/m68k.py'
ROM = ('/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/'
       'CM550_J90350.00_analysis/firmware/J90350.00.rom.bin')

start = int(sys.argv[1], 16) if len(sys.argv) > 1 else 0xd610
end = int(sys.argv[2], 16) if len(sys.argv) > 2 else 0xe77a
out = subprocess.run(['python3', TOOL, ROM, hex(start), hex(end)],
                     capture_output=True, text=True).stdout.splitlines()

counter_re = re.compile(r'\((0x8001[5-7][0-9a-f])\)\.l')
fault_set_re = re.compile(r'ori\.w #(0x[0-9a-f]+),\((0x8060[0-9a-f]+)\)\.l')
fault_clr_re = re.compile(r'andi\.w #(0x[0-9a-f]+),\((0x8060[0-9a-f]+)\)\.l')
feedback_re = re.compile(r'move\.b \((0x80bd0[0-9a-f])\)\.l,d0')
mask_re = re.compile(r'andi\.l #(0x[0-9a-f]+),d0')
mask1_re = re.compile(r'andi\.l #(0x[0-9a-f]+),d1')
cmd_re = re.compile(r'move\.b \((0x[0-9a-f]+),(a[0-9])\),d1')

lines = []
for line in out:
    parts = line.split(None, 2)
    if len(parts) < 3:
        continue
    lines.append((int(parts[0].rstrip(':'), 16), parts[2]))

blocks = []
current = None
for index, (address, text) in enumerate(lines):
    m = feedback_re.search(text)
    if m and index + 1 < len(lines) and mask_re.search(lines[index + 1][1]):
        mask = mask_re.search(lines[index + 1][1]).group(1)
        # a block starts with: move.b feedback,d0 / andi.l mask,d0 / sne / andi / move.b (n,aX),d1
        lookahead = ' '.join(t for _, t in lines[index:index + 6])
        c = cmd_re.search(lookahead)
        if c:
            current = {'start': address, 'feedback': m.group(1), 'mask': mask,
                       'command': '(%s,%s)' % (c.group(1), c.group(2)), 'events': []}
            blocks.append(current)
            continue
    if current is None:
        continue
    for cm in counter_re.finditer(text):
        op = text.split()[0]
        current['events'].append((address, op, cm.group(1)))
    fs = fault_set_re.search(text)
    if fs:
        current['events'].append((address, 'FAULT_SET', fs.group(2) + ' ' + fs.group(1)))
    fc = fault_clr_re.search(text)
    if fc:
        current['events'].append((address, 'FAULT_CLEAR', fc.group(2) + ' ' + fc.group(1)))

for block in blocks:
    print('block @%#x feedback %s mask %s command %s' % (
        block['start'], block['feedback'], block['mask'], block['command']))
    for address, op, what in block['events']:
        print('    %#07x %-12s %s' % (address, op, what))
