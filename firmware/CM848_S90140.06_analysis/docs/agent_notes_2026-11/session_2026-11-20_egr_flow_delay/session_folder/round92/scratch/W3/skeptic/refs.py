"""Find every 4-byte big-endian occurrence of an address (range) in the CM550 ROM at an even offset and decode the
instruction that contains it with capstone, trying instruction starts 2..8 bytes before the hit.
usage: refs.py <first hex> [<last hex>]"""
import sys

sys.path.insert(0, '/home/linux/.claude/jobs/374b0424/tmp/w15/r91/scratch/S1/skeptic/venv/lib/python3.12/site-packages')
import capstone  # noqa: E402

ROM = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin'
rom = open(ROM, 'rb').read()
md = capstone.Cs(capstone.CS_ARCH_M68K, capstone.CS_MODE_M68K_020 | capstone.CS_MODE_BIG_ENDIAN)
first = int(sys.argv[1], 16)
last = int(sys.argv[2], 16) if len(sys.argv) > 2 else first


def containing(hit):
    """Return the decoded instruction(s) whose bytes include the 4-byte operand at hit."""
    out = []
    for back in (2, 4, 6, 8):
        s = hit - back
        for i in md.disasm(rom[s:s + 16], s, 1):
            if i.address + len(i.bytes) >= hit + 4:
                out.append((back, i))
    return out


for a in range(first, last + 1):
    pat = a.to_bytes(4, 'big')
    pos = 0
    while True:
        h = rom.find(pat, pos)
        if h < 0:
            break
        pos = h + 1
        if h % 2:
            print('0x%06x odd-offset hit at 0x%05x (ignored: not an instruction operand)' % (a, h))
            continue
        cands = containing(h)
        if not cands:
            print('0x%06x hit at 0x%05x: no decodable instruction (data?) prev=%s' % (a, h, rom[h - 4:h].hex()))
            continue
        txt = ' || '.join('-%d: %06x %s %s' % (b, i.address, i.mnemonic, i.op_str) for b, i in cands)
        print('0x%06x hit at 0x%05x: %s' % (a, h, txt))
