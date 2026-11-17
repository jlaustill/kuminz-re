import re
import subprocess
import sys
sys.path.insert(0, '/home/linux/.claude/jobs/d55ae3c6/tmp/renames')
import w9ct_mem as M
import w9ct_bootscan as B

REPO = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays'


def dtc(code):
    letter = 'PCBU'[(code >> 14) & 3]
    return '%s%d%03X' % (letter, (code >> 12) & 3, code & 0xFFF)


def slot(f):
    v = M.romw(0x5985a + 2 * f)
    return v - 65536 if v >= 32768 else v


def fault_dtc(f):
    s = slot(f)
    if s < 0 or s >= 170:
        return None
    return dtc(M.romw(0x5b57c + 2 * s))


print('word 32 (faults 512-527) with letters:', [(f, fault_dtc(f)) for f in range(512, 528) if fault_dtc(f)])
for f in (64, 611, 613, 618, 619, 620, 729, 778):
    print(f, fault_dtc(f), 'slot', slot(f), 'raw 0x%04x' % M.romw(0x5b57c + 2 * slot(f)))
print('ROM 0x526c words:', ['%04x' % M.romw(0x526c + 2 * i) for i in range(6)])
for a in (0x3ff85c, 0x3ff85e, 0x3ff860, 0x3ff856, 0x3ff858, 0x3ff85a):
    print(hex(a), M.w(a))
for a in (0x3fae38, 0x3fae3a, 0x3fae3c, 0x3fae3e, 0x3fae40, 0x3fae42, 0x3fae44, 0x3fae46):
    h = B.scan(a)
    print('boot scan', hex(a), len(h), h[:3])
addrs = ['0x40afe8', '0x40afea', '0x40aff0', '0x40aff2', '0x40aff4', '0x40aff8', '0x40affc', '0x40be36', '0x40afe2', '0x40afc2',
         '0x40afc8', '0x40afcc', '0x40afce', '0x40afd0', '0x40afd2', '0x40afd4', '0x3ff6f8', '0x3ff6fc', '0x3ff6fe', '0x3ff700',
         '0x3ff706', '0x3ff716', '0x40afd6', '0x40afd8', '0x40afc4', '0x40afc6', '0x40bdc4', '0x40bdc6']
for a in addrs:
    out = subprocess.run(['python3', REPO + '/firmware/scripts/xref_addr.py', a], capture_output=True, text=True, cwd=REPO).stdout
    funcs = re.findall(r'^([A-Za-z_0-9]+): (\d+r/\d+w)', out, re.M)
    print(a, [f + ' ' + rw for f, rw in funcs])
