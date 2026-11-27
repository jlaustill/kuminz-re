"""Linear-sweep m68k disassembly of the CM550 ROM with llvm-mc-18, one instruction per call.
usage: python3 disasm.py <start_hex> <end_hex> [target_hex ...]
Prints every instruction; lines mentioning a target address are marked with '>>'.
Use '-q' as the first arg to print only marked lines (plus 2 lines of context)."""
import subprocess, sys, re
ROM = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin'
data = open(ROM, 'rb').read()
args = sys.argv[1:]
quiet = False
if args and args[0] == '-q':
    quiet = True
    args = args[1:]
start = int(args[0], 16)
end = int(args[1], 16)
targets = [int(t, 16) for t in args[2:]]
tstr = ['%x' % t for t in targets]

enc_re = re.compile(r'^\s*(\S.*?)\s*; encoding: \[(.*)\]')


def decode(pos):
    chunk = data[pos:pos + 22]
    inp = ' '.join('0x%02x' % b for b in chunk)
    p = subprocess.run(['llvm-mc-18', '--disassemble', '--triple=m68k', '-show-encoding'],
                       input=inp, capture_output=True, text=True)
    first_bad = None
    for m in re.finditer(r'<stdin>:1:(\d+): warning', p.stderr):
        col = int(m.group(1))
        first_bad = (col - 1) // 5
        break
    for line in p.stdout.split('\n'):
        m = enc_re.match(line)
        if m:
            n = len(m.group(2).split(','))
            if first_bad == 0:
                return None, 2
            return m.group(1), n
    return None, 2


out = []
pos = start
while pos < end:
    text, n = decode(pos)
    raw = data[pos:pos + n].hex()
    if text is None:
        text = '<undecoded %s>' % raw
    mark = any(t in text for t in tstr) if tstr else False
    out.append(('>>' if mark else '  ', pos, text, raw))
    pos += n
if quiet:
    keep = set()
    for i, (m, *_rest) in enumerate(out):
        if m == '>>':
            keep.update(range(max(0, i - 2), min(len(out), i + 3)))
    for i in sorted(keep):
        m, p, t, r = out[i]
        print('%s %05x: %-48s %s' % (m, p, t, r))
else:
    for m, p, t, r in out:
        print('%s %05x: %-48s %s' % (m, p, t, r))
