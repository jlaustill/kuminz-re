"""Boot-ROM user scan (code below 0x7F60): any load / store / addi / ori / addis whose 16-bit immediate equals
the low halfword of an address, and any aligned 32-bit word equal to the address.  Usage: w9ct_bootscan.py 0xADDR ..."""
import sys
sys.path.insert(0, '/home/linux/.claude/jobs/d55ae3c6/tmp/renames')
import w9ct_mem as M

OPS = {12: 'addic', 13: 'addic.', 14: 'addi', 15: 'addis', 24: 'ori', 25: 'oris', 32: 'lwz', 33: 'lwzu', 34: 'lbz', 35: 'lbzu',
       36: 'stw', 37: 'stwu', 38: 'stb', 39: 'stbu', 40: 'lhz', 41: 'lhzu', 42: 'lha', 43: 'lhau', 44: 'sth', 45: 'sthu',
       46: 'lmw', 47: 'stmw'}
LIMIT = 0x7F60


def scan(addr):
    hits = []
    lo = addr & 0xFFFF
    hi = (addr >> 16) & 0xFFFF
    for off in range(0, LIMIT, 4):
        w = int.from_bytes(M.rom[off:off + 4], 'big')
        op = w >> 26
        imm = w & 0xFFFF
        if op in OPS and imm == lo:
            hits.append((off, OPS[op], 'imm=0x%04x' % imm))
        elif op in OPS and imm == ((lo - 0x10000) & 0xFFFF) and False:
            pass
        if w == addr:
            hits.append((off, 'const32', hex(w)))
    return hits


if __name__ == '__main__':
    for a in sys.argv[1:]:
        ad = int(a, 16)
        h = scan(ad)
        print(hex(ad), 'boot-ROM hits:', len(h), [('0x%x' % o, n, d) for o, n, d in h][:8])
