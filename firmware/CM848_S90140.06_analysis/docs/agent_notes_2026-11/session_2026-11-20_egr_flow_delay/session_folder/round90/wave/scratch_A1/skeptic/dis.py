#!/usr/bin/env python3
"""Disassemble a CM550 ROM byte range with llvm-mc-18 (m68k), printing each
instruction with its address. Usage: dis.py START END [rom]

llvm-mc cannot decode some CPU32 encodings (pea abs.l, for one); when it
skips a word the address tracking would drift, so this decodes one
instruction at a time: it feeds the bytes from the current offset, takes the
first decoded instruction and its encoding length, and on a decode failure
prints the raw word and steps 2 bytes.
"""
import subprocess
import sys

ROM = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin'


def decode_one(chunk):
    text = ' '.join('0x%02x' % b for b in chunk)
    out = subprocess.run(['llvm-mc-18', '--disassemble', '--triple=m68k', '--show-encoding'],
                         input=text, capture_output=True, text=True)
    # the first instruction line has "# encoding: [...]"
    for line in out.stdout.splitlines():
        if '; encoding:' in line:
            ins, enc = line.split('; encoding:')
            n = enc.count('0x')
            return ins.strip(), n
        # stop if a warning came first (the first word failed)
    return None, 0


def main():
    start = int(sys.argv[1], 0)
    end = int(sys.argv[2], 0)
    rom = sys.argv[3] if len(sys.argv) > 3 else ROM
    data = open(rom, 'rb').read()
    pc = start
    while pc < end:
        chunk = data[pc:pc + 10]
        ins, n = decode_one(chunk)
        # make sure the decoded instruction really started at the first byte:
        # llvm-mc skips undecodable words and then reports the next one, so
        # verify by checking the warning-free case with a 2-byte prefix test
        text = ' '.join('0x%02x' % b for b in chunk)
        out = subprocess.run(['llvm-mc-18', '--disassemble', '--triple=m68k', '--show-encoding'],
                             input=text, capture_output=True, text=True)
        first_warn = None
        for line in out.stderr.splitlines():
            if 'invalid instruction encoding' in line:
                # column of the failing byte: "<stdin>:1:COL:"
                try:
                    first_warn = int(line.split(':')[2])
                except (IndexError, ValueError):
                    first_warn = 0
                break
        if first_warn == 1 or ins is None:
            w = data[pc:pc + 2]
            print('%06x:  %-28s %s' % (pc, ' '.join('%02x' % b for b in w), '(undecoded word)'))
            pc += 2
            continue
        raw = ' '.join('%02x' % b for b in data[pc:pc + n])
        print('%06x:  %-28s %s' % (pc, raw, ins))
        pc += n


if __name__ == '__main__':
    main()
