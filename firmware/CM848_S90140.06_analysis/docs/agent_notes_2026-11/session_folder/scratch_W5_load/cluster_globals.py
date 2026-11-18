import csv, re, sys
FW = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/'
OUT = FW + 'output/'
ORIG = FW + 'originals/'
ram = open(ORIG + 'cm848_ram.bin', 'rb').read()
rom = open(ORIG + 'cm848_rom.bin', 'rb').read()
eep = open(ORIG + 'cm848_eeprom.bin', 'rb').read()
g = {}
byaddr = {}
for r in csv.reader(open(OUT + 'global_variables.csv')):
    if not r or r[0].startswith('#'):
        continue
    try:
        a = int(r[0], 16)
    except Exception:
        continue
    name = r[1].strip()
    row = (a, r[2] if len(r) > 2 else '', r[3] if len(r) > 3 else '')
    if name:
        g[name] = row
    byaddr[a] = (name,) + row[1:]

WIDTH = {'byte': 1, 'word': 2, 'dword': 4, 'i8': 1, 'i16': 2, 'i32': 4, 'u8': 1, 'u16': 2, 'u32': 4,
         'short': 2, 'ushort': 2, 'uint': 4, 'int': 4, 'ubyte': 1}


def peek(a, typ, width=None):
    w = width or WIDTH.get(typ, 2)
    if 0x3FA000 <= a < 0x3FA000 + len(ram):
        b = ram[a - 0x3FA000:a - 0x3FA000 + w]
        src = 'RAM'
    elif a < len(rom):
        b = rom[a:a + w]
        src = 'ROM'
    else:
        return None
    v = int.from_bytes(b, 'big')
    sv = v - (1 << (8 * w)) if v >= (1 << (8 * w - 1)) else v
    return v, sv, src, w


if __name__ == '__main__':
    lines = open(OUT + 'cm848_rom.ghidra.cpp').read().split('\n')
    start, end = int(sys.argv[1]), int(sys.argv[2])
    text = '\n'.join(lines[start - 1:end])
    ids = set(re.findall(r'\b[A-Za-z_][A-Za-z0-9_]*\b', text))
    rows = []
    for n in ids:
        if n in g:
            a, t, c = g[n]
            rows.append((a, n, t, c))
    rows.sort()
    for a, n, t, c in rows:
        pk = peek(a, t)
        pks = f'{pk[0]} (0x{pk[0]:x}) s={pk[1]} {pk[2]}' if pk else 'n/a'
        print(f'0x{a:08x} {n:55s} {t:6s} {pks}')
