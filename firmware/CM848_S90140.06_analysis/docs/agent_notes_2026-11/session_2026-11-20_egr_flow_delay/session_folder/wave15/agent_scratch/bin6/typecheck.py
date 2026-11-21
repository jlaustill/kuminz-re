import json, ast
d = json.load(open('/home/linux/.claude/jobs/374b0424/tmp/w15/bins/bin6.json'))
for i, r in enumerate(d):
    t = r['current_row_type']
    raw = r['access_widths'] or '{}'
    acc = ast.literal_eval(raw.split(' -> ')[0]) if isinstance(raw, str) else raw
    kinds = set(acc.keys())
    signed = r['signed']
    size = r['size_bytes']
    notes = []
    if kinds:
        if 'lha' in kinds and t == 'word':
            notes.append('word but lha load (signed)')
        if 'lhz' in kinds and t == 'i16':
            notes.append('i16 but lhz load (unsigned)')
        if signed == 'S' and t == 'word':
            notes.append('e2m signed, row word')
        if signed == 'U' and t == 'i16':
            notes.append('e2m unsigned, row i16')
        if size == 2 and ('lbz' in kinds or 'stb' in kinds):
            notes.append('2-byte record but byte access')
        if size == 1 and ('lhz' in kinds or 'lha' in kinds):
            notes.append('1-byte record but half access')
    else:
        if signed == 'S' and t == 'word':
            notes.append('e2m signed, row word (no direct access)')
    if size == 2 and t in ('byte',):
        notes.append('2-byte record, byte row')
    if size == 1 and t in ('word', 'i16'):
        notes.append('1-byte record, word row')
    if size == 4 and t in ('word', 'i16', 'byte'):
        notes.append('4-byte record, smaller row')
    if notes:
        print(i, r['address'], r['label_in_cpp'], t, 'e2m', signed, size, acc, notes)
