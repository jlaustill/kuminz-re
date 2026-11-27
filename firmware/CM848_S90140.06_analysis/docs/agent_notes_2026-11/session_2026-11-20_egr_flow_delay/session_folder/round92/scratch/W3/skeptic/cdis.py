"""Capstone m68k disassembly of a CM550 ROM range (read-only use of an existing capstone install; nothing is installed).
usage: cdis.py <start hex> <end hex>
Linear sweep; on an undecodable word prints .word and advances 2 bytes."""
import sys

sys.path.insert(0, '/home/linux/.claude/jobs/374b0424/tmp/w15/r91/scratch/S1/skeptic/venv/lib/python3.12/site-packages')
import capstone  # noqa: E402

ROM = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin'
rom = open(ROM, 'rb').read()
md = capstone.Cs(capstone.CS_ARCH_M68K, capstone.CS_MODE_M68K_020 | capstone.CS_MODE_BIG_ENDIAN)


def sweep(start, end):
    a = start
    while a < end:
        got = False
        for i in md.disasm(rom[a:a + 16], a, 1):
            yield i.address, i.bytes, i.mnemonic, i.op_str
            a += len(i.bytes)
            got = True
        if not got:
            yield a, rom[a:a + 2], '.word', '0x%04x' % int.from_bytes(rom[a:a + 2], 'big')
            a += 2


if __name__ == '__main__':
    s, e = int(sys.argv[1], 16), int(sys.argv[2], 16)
    for addr, raw, mn, ops in sweep(s, e):
        print('%06x: %-24s %s %s' % (addr, raw.hex(), mn, ops))
