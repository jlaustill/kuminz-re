"""For each record address given, list every absolute-long reference in the CM550 ROM to any byte of the 22-byte
record (offset within the record, the reference site, the enclosing function and the instruction decoded by m68k.py).
usage: record_refs.py 0xRECORD [0xRECORD ...] [--size N]"""
import subprocess
import sys

ROM_PATH = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin'
M68K = '/home/linux/.claude/jobs/374b0424/tmp/w15/r93/tools/m68k.py'
rom = open(ROM_PATH, 'rb').read()
starts = []
for line in open('/home/linux/.claude/jobs/374b0424/tmp/w15/r94/scratch/L3/investigator/func_starts.txt'):
    a, n = line.split()
    starts.append((int(a, 16), n))
starts.sort()


def enclosing(x):
    best = (0, '?')
    for a, n in starts:
        if a <= x:
            best = (a, n)
    return best


def decode_at(func_start, site):
    """Disassemble from the function start to just past the site, return the line that contains the site."""
    out = subprocess.run(['python3', M68K, ROM_PATH, hex(func_start), hex(site + 8)], capture_output=True,
                         text=True).stdout.splitlines()
    best = None
    for line in out:
        try:
            a = int(line.split(':')[0], 16)
        except ValueError:
            continue
        if a <= site:
            best = line
    return best


args = sys.argv[1:]
size = 22
if '--size' in args:
    i = args.index('--size')
    size = int(args[i + 1], 0)
    args = args[:i] + args[i + 2:]
for arg in args:
    r = int(arg, 16)
    print(f'=== record 0x{r:x} .. 0x{r + size - 1:x}')
    for i in range(0, len(rom) - 4, 2):
        v = int.from_bytes(rom[i:i + 4], 'big')
        if r <= v < r + size:
            fs, fn = enclosing(i)
            line = decode_at(fs, i) if fs else None
            print(f'  +0x{v - r:02x} site 0x{i:x} in {fn} (0x{fs:x}): {line}')
