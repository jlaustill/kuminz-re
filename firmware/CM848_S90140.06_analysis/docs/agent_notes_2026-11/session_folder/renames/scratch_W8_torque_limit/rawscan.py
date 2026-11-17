"""Raw scan of ROM + flash2 for instructions whose 16-bit immediate/displacement equals the low half of an address.
usage: rawscan.py 0x3fdb84 [0x...]   -> lists aligned words (opcode, rD, rA, imm) and nearby 'lis' context."""
import struct
import sys

FW = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/originals/'
ROM = open(FW + 'cm848_rom.bin', 'rb').read()
F2 = open(FW + 'cm848_flash2_live.bin', 'rb').read()
OPN = {14: 'addi', 15: 'addis', 24: 'ori', 25: 'oris', 32: 'lwz', 33: 'lwzu', 34: 'lbz', 35: 'lbzu', 36: 'stw', 37: 'stwu',
       38: 'stb', 39: 'stbu', 40: 'lhz', 41: 'lhzu', 42: 'lha', 43: 'lhau', 44: 'sth', 45: 'sthu', 28: 'andi.', 12: 'addic',
       11: 'cmpi', 10: 'cmpli'}


def scan(addr, window=0):
    lo = addr & 0xFFFF
    hits = []
    for name, buf, base in (('ROM', ROM, 0), ('FLASH2', F2, 0x500000)):
        for off in range(0, len(buf) - 3, 4):
            w = struct.unpack('>I', buf[off:off + 4])[0]
            imm = w & 0xFFFF
            if imm == lo or (window and abs(((imm ^ 0x8000) - 0x8000) - (((lo) ^ 0x8000) - 0x8000)) <= window):
                op = w >> 26
                if op in OPN:
                    hits.append((name, base + off, OPN[op], (w >> 21) & 31, (w >> 16) & 31, imm))
    return hits


if __name__ == '__main__':
    for a in sys.argv[1:]:
        addr = int(a, 16)
        hs = scan(addr)
        print('==', hex(addr), len(hs), 'hits (low half 0x%04x)' % (addr & 0xFFFF))
        for h in hs:
            print('  ', h[0], hex(h[1]), h[2], 'rD/rS=%d rA=%d imm=0x%04x' % (h[3], h[4], h[5]))
