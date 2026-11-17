import re
import subprocess
import sys

ROOT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/'
ROM = ROOT + 'firmware/CM848_S90140.06_analysis/originals/cm848_rom.bin'
text = subprocess.run(['powerpc-linux-gnu-objdump', '-D', '-b', 'binary', '-m', 'powerpc', '-EB', '--start-address=0', '--stop-address=0x7f60', ROM],
                      capture_output=True, text=True).stdout
lines = [l for l in text.splitlines() if re.match(r'^\s+[0-9a-f]+:\t', l)]
for arg in sys.argv[1:]:
    value = int(arg, 16)
    signed = value - 0x400000
    unsigned = value & 0xffff
    pattern = re.compile(r'(?:,|\s)(%d|%d)(?:\(|$)' % (signed, unsigned))
    hits = [l for l in lines if pattern.search(l.split('\t', 2)[-1])]
    print(arg, 'signed', signed, 'unsigned', unsigned, 'hits', len(hits))
    for hit in hits[:4]:
        print('   ', hit.strip())
