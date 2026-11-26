"""Which global rows cover an address range? cover.py <cm550|cm848> 0xSTART [0xEND_exclusive] [...]
Sizes: byte/char/undefined/bool = 1, word/ushort/short/i16/u16 = 2, dword/i32/u32/pointer/* = 4, arrays, structs
(from structure_definitions.csv field offsets + sizes), enums (enums.csv size column)."""
import csv
import re
import sys

F = "/home/linux/.claude/jobs/374b0424/tmp/w15/r97/frozen/"
fw = sys.argv[1]
BASIC = {'byte': 1, 'char': 1, 'undefined': 1, 'bool': 1, 'undefined1': 1, 'uchar': 1, 'u8': 1, 'i8': 1,
         'word': 2, 'ushort': 2, 'short': 2, 'i16': 2, 'u16': 2, 'undefined2': 2,
         'dword': 4, 'i32': 4, 'u32': 4, 'pointer': 4, 'uint': 4, 'int': 4, 'undefined4': 4, 'float': 4,
         'qword': 8, '': 1}
structs = {}
for r in csv.reader(open(F + fw + "/structure_definitions.csv", errors="replace")):
    if len(r) < 5 or r[0].startswith('#') or r[0] == 'struct_name':
        continue
    try:
        off = int(r[1], 0)
        size = int(r[4], 0)
    except ValueError:
        continue
    if off < 0x10000:
        structs[r[0]] = max(structs.get(r[0], 0), off + size)
enums = {}
for r in csv.reader(open(F + fw + "/enums.csv", errors="replace")):
    if len(r) >= 5 and not r[0].startswith('#'):
        try:
            enums[r[0]] = int(r[4])
        except ValueError:
            pass


def size_of(t):
    t = t.strip()
    if t.endswith('*'):
        return 4
    m = re.match(r'^(.*)\[(\d+)\]$', t)
    if m:
        e = size_of(m.group(1))
        return None if e is None else e * int(m.group(2))
    if t in BASIC:
        return BASIC[t]
    if t in structs:
        return structs[t]
    if t in enums:
        return enums[t]
    return None


rows = []
for r in csv.reader(open(F + fw + "/global_variables.csv", errors="replace")):
    if r and r[0].startswith('0x'):
        a = int(r[0], 16)
        s = size_of(r[2]) if len(r) > 2 else 1
        rows.append((a, r[1], r[2] if len(r) > 2 else '', s))
args = sys.argv[2:]
i = 0
while i < len(args):
    start = int(args[i], 16)
    end = start + 1
    if i + 1 < len(args) and not args[i + 1].startswith('-') and int(args[i + 1], 16) > start and int(args[i + 1], 16) - start < 0x400:
        end = int(args[i + 1], 16)
        i += 1
    i += 1
    print(f"== 0x{start:x}-0x{end - 1:x}")
    for a, n, t, s in rows:
        ss = s if s is not None else 1
        if a < end and a + ss > start:
            print(f"  0x{a:x} {n} {t} size={s}")
