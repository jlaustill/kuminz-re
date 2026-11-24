#!/usr/bin/env python3
"""For a target address, find every 4-byte big-endian occurrence in a ROM byte range and
try to decode the instruction that contains it (starts at occ-2 .. occ-8)."""
import subprocess, sys
rom = open('/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin','rb').read()
def decode(start, n=14):
    data = rom[start:start+n]
    txt = ' '.join('0x%02x' % b for b in data)
    p = subprocess.run(['llvm-mc-18','--disassemble','--triple=m68k','--show-encoding'], input=txt, capture_output=True, text=True)
    lines = [l for l in p.stdout.split('\n') if 'encoding' in l]
    if not lines:
        return None, 0
    first = lines[0]
    enc = first.split('encoding: [')[1].rstrip(']').split(',')
    # check the first instruction decoded at byte 0 (llvm may skip invalid bytes)
    first_err = None
    for l in p.stderr.split('\n'):
        if 'invalid instruction encoding' in l:
            col = int(l.split(':')[2])
            first_err = (col-1)//5
            break
    if first_err == 0:
        return None, 0
    return first.split(';')[0].strip(), len(enc)
def main():
    target = int(sys.argv[1], 16)
    lo = int(sys.argv[2], 16); hi = int(sys.argv[3], 16)
    pat = target.to_bytes(4, 'big')
    i = lo
    found = False
    while True:
        j = rom.find(pat, i, hi)
        if j < 0: break
        found = True
        ctx = ' '.join('%02x' % b for b in rom[j-8:j+8])
        print('occurrence at 0x%05x  bytes[-8..+8]: %s' % (j, ctx))
        for k in (2, 4, 6, 8):
            s = j - k
            if s % 2: continue
            ins, ln = decode(s)
            if ins and ln >= k + 4:
                print('   @0x%05x (len %d): %s' % (s, ln, ins))
        i = j + 1
    if not found:
        print('no absolute occurrence of 0x%08x in 0x%x-0x%x' % (target, lo, hi))
main()
