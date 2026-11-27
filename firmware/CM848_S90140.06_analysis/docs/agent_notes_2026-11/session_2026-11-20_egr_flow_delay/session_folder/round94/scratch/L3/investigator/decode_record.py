"""Decode a 22-byte cm550_tableLookup2D argument record from the CM550 RAM dumps, and list the global rows in it
(and any row that starts before it and spans into it)."""
import csv
import re
import struct
import subprocess
import sys

FW = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/'
ram = open(FW + 'J90350.00.ram.bin', 'rb').read()
ext = open(FW + 'J90350.00.extended_ram.bin', 'rb').read()
rom = open(FW + 'J90350.00.rom.bin', 'rb').read()
FROZEN = '/home/linux/.claude/jobs/374b0424/tmp/w15/r94/frozen/cm550/'
BASIC = {'byte': 1, 'sbyte': 1, 'char': 1, 'undefined': 1, 'undefined1': 1, 'bool': 1, 'word': 2, 'short': 2,
         'ushort': 2, 'undefined2': 2, 'dword': 4, 'sdword': 4, 'int': 4, 'uint': 4, 'undefined4': 4, 'pointer': 4,
         'float': 4, 'long': 4, 'ulong': 4}
struct_size = {}
for line in open(FROZEN + 'structure_definitions.csv'):
    if line.startswith('#') or line.startswith('struct_name'):
        continue
    p = next(csv.reader([line]))
    if len(p) < 5:
        continue
    try:
        struct_size[p[0]] = struct_size.get(p[0], 0) + int(p[4])
    except ValueError:
        pass
enum_size = {}
for line in open(FROZEN + 'enums.csv'):
    if line.startswith('#'):
        continue
    p = next(csv.reader([line]))
    if len(p) >= 5:
        try:
            enum_size[p[0]] = int(p[4])
        except ValueError:
            pass


def type_size(t):
    t = t.strip()
    m = re.match(r'(.*)\[(\d+)\]$', t)
    if m:
        return type_size(m.group(1)) * int(m.group(2))
    if t.endswith('*'):
        return 4
    if t in BASIC:
        return BASIC[t]
    if t in struct_size:
        return struct_size[t]
    if t in enum_size:
        return enum_size[t]
    return 1


rows = []
for line in open(FROZEN + 'global_variables.csv'):
    if line.startswith('#') or line.startswith('address'):
        continue
    p = next(csv.reader([line]))
    if len(p) < 3:
        continue
    try:
        rows.append((int(p[0], 16), p[1], p[2], p[3] if len(p) > 3 else ''))
    except ValueError:
        pass


def rd(addr, n):
    if 0x800000 <= addr < 0x800000 + len(ram):
        o = addr - 0x800000
        return ram[o:o + n]
    if 0x809242 <= addr < 0x809242 + len(ext):
        o = addr - 0x809242
        return ext[o:o + n]
    if addr < len(rom):
        return rom[addr:addr + n]
    return None


def axis(p):
    b = rd(p, 2)
    if b is None:
        return f'0x{p:x}: not dumped'
    count = struct.unpack('>H', b)[0]
    n = count // 2
    vals = rd(p + 2, 2 * n)
    if vals is None or len(vals) < 2 * n or n > 64:
        return f'0x{p:x}: count {count}, values not dumped / implausible'
    v = struct.unpack(f'>{n}H', vals)
    return f'0x{p:x}: byte count {count} -> {n} points {list(v)}'


def e2m(a):
    out = subprocess.run(['python3', '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/scripts/e2m_block_addresses.py',
                          '--firmware', 'cm550', '--address', hex(a)], capture_output=True, text=True,
                         cwd='/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware').stdout.strip()
    return out


def rows_in(r, n):
    out = []
    for a, name, t, c in rows:
        s = type_size(t)
        if r <= a < r + n:
            out.append(f'  INSIDE 0x{a:x} {name} {t} ({s} B) | {c[:120]}')
        elif a < r < a + s:
            out.append(f'  SPANS INTO 0x{a:x} {name} {t} ({s} B) | {c[:120]}')
    return out


if __name__ == '__main__':
    args = sys.argv[1:]
    if args and args[0] == '--rows':
        r, n = int(args[1], 16), int(args[2], 0)
        print('\n'.join(rows_in(r, n)))
        sys.exit(0)
    for arg in args:
        r = int(arg, 16)
        b = rd(r, 22)
        print(f'=== record 0x{r:x} (ends 0x{r + 21:x})')
        if b is None:
            print('  not dumped')
            continue
        xo, xp, xi, yo, yp, yi, zp, ni = struct.unpack('>HIHHIHIH', b)
        print(f'  x_axis_offset {xo} x_axis_pointer 0x{xp:x} x_input {xi} y_axis_offset {yo} y_axis_pointer 0x{yp:x} '
              f'y_input {yi} z_values_pointer 0x{zp:x} no_interpolation_flag {ni}')
        print('  x axis', axis(xp))
        print('  y axis', axis(yp))
        for name, p in (('x', xp), ('y', yp), ('z', zp)):
            print(f'  e2m {name}:', e2m(p))
        print('\n'.join(rows_in(r, 22)))
