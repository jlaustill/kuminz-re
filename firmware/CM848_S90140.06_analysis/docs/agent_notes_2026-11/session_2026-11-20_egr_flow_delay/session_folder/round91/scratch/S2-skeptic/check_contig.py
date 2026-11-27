import re, sys
prev_end = None
for line in open(sys.argv[1]):
    if line.startswith('===='):
        print(line.strip())
        prev_end = None
        continue
    m = re.match(r'^([0-9a-f]{8})\s+([0-9a-f]+)\s+(.*)$', line.rstrip('\n'))
    if not m:
        print('NONINSN', line.rstrip()[:100])
        continue
    addr = int(m.group(1), 16)
    ln = len(m.group(2)) // 2
    if prev_end is not None and addr != prev_end:
        print('GAP', hex(prev_end), '->', hex(addr))
    prev_end = addr + ln
