#!/usr/bin/env python3
"""Print a function's flow-reached instructions with the sp offset before each.
usage: disasm.py <rom> <all_functions.json> <entry hex> [<from hex> <to hex>]"""
import json
import sys

sys.path.insert(0, __file__.rsplit('/', 1)[0])
from analyze import analyze_function  # noqa: E402

rom = open(sys.argv[1], 'rb').read()
allf = json.load(open(sys.argv[2]))
entries = {f['address']: f['name'] for f in allf}
entry = int(sys.argv[3], 16)
lo = int(sys.argv[4], 16) if len(sys.argv) > 4 else 0
hi = int(sys.argv[5], 16) if len(sys.argv) > 5 else 1 << 32
r = analyze_function(rom, entry, entries)
print('# %s @ 0x%x  issues=%s' % (entries.get(entry, '?'), entry, r['issues']))
for pc in sorted(r['insns']):
    if not (lo <= pc < hi):
        continue
    ins = r['insns'][pc]
    tgt = ''
    if ins.target is not None and ins.flow == 'call':
        tgt = '  -> %s' % entries.get(ins.target, hex(ins.target))
    print('%06x sp=%+4d  %-30s %s%s' % (pc, r['sp_at'][pc], ins.hexbytes(), ins.text(), tgt))
