"""Scan ROM (all) and FLASH2 for (a) bl/b instructions targeting given functions, (b) load/store/addi/ori instructions whose 16-bit
immediate falls inside [lo, hi] (as raw unsigned) - below a code limit.  usage: kernscan.py"""
import struct
import sys

FW = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/originals/'
ROM = open(FW + 'cm848_rom.bin', 'rb').read()
F2 = open(FW + 'cm848_flash2_live.bin', 'rb').read()
OPN = {14: 'addi', 15: 'addis', 24: 'ori', 25: 'oris', 32: 'lwz', 33: 'lwzu', 34: 'lbz', 35: 'lbzu', 36: 'stw', 37: 'stwu',
       38: 'stb', 39: 'stbu', 40: 'lhz', 41: 'lhzu', 42: 'lha', 43: 'lhau', 44: 'sth', 45: 'sthu', 28: 'andi.', 12: 'addic',
       11: 'cmpi', 10: 'cmpli'}


def branch_targets(buf, base):
    for off in range(0, len(buf) - 3, 4):
        w = struct.unpack('>I', buf[off:off + 4])[0]
        if (w >> 26) == 18:
            li = w & 0x03FFFFFC
            if li & 0x02000000:
                li -= 0x04000000
            aa = (w >> 1) & 1
            lk = w & 1
            tgt = li if aa else base + off + li
            yield base + off, tgt & 0xFFFFFFFF, lk


def main():
    targets = {0x2c94: 'cm848_registerDiagnosticService', 0x6d24: 'cm848_dispatchDiagnosticService'}
    for name, buf, base in (('ROM', ROM, 0), ('FLASH2', F2, 0x500000)):
        for pc, tgt, lk in branch_targets(buf, base):
            if tgt in targets:
                print('CALL', name, hex(pc), '->', targets[tgt], 'lk=%d' % lk)
    # immediates inside the table window, code below 0x7f60 only
    lo, hi = 0xdb30, 0xdb94
    print('--- immediates 0x%04x-0x%04x in ROM below 0x7f60' % (lo, hi))
    for off in range(0, 0x7f60, 4):
        w = struct.unpack('>I', ROM[off:off + 4])[0]
        op = w >> 26
        imm = w & 0xFFFF
        if op in OPN and lo <= imm <= hi:
            print(hex(off), OPN[op], 'rD/rS=%d rA=%d imm=0x%04x' % ((w >> 21) & 31, (w >> 16) & 31, imm))


main()
