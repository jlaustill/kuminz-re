"""For each ROM reference to a table base, decode the referencing instruction and the next one.

llvm-mc's m68k disassembler cannot decode CPU32 scaled-index modes, so this decodes the
small set of instruction forms the fault table code uses by hand and falls back to hex.
"""
import subprocess
import sys

ROM = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin'
data = open(ROM, 'rb').read()


def word(offset):
    return int.from_bytes(data[offset:offset + 2], 'big')


def long(offset):
    return int.from_bytes(data[offset:offset + 4], 'big')


SIZE = {1: 'b', 3: 'w', 2: 'l'}


def extension(offset, register):
    """Brief extension word: (d8,An,Xn.size*scale)."""
    ext = word(offset)
    index_kind = 'a' if ext & 0x8000 else 'd'
    index_register = (ext >> 12) & 7
    index_size = 'l' if ext & 0x800 else 'w'
    scale = 1 << ((ext >> 9) & 3)
    displacement = ext & 0xff
    if displacement & 0x80:
        displacement -= 0x100
    if ext & 0x100:
        return '(full-extension 0x%04x)' % ext, 2
    return '(%d,a%d,%s%d.%s*%d)' % (displacement, register, index_kind, index_register, index_size, scale), 2


def effective_address(mode, register, offset, size):
    """Return (text, extra bytes) for a 6-bit effective address."""
    if mode == 0:
        return 'd%d' % register, 0
    if mode == 1:
        return 'a%d' % register, 0
    if mode == 2:
        return '(a%d)' % register, 0
    if mode == 3:
        return '(a%d)+' % register, 0
    if mode == 4:
        return '-(a%d)' % register, 0
    if mode == 5:
        displacement = word(offset)
        if displacement & 0x8000:
            displacement -= 0x10000
        return '(%d,a%d)' % (displacement, register), 2
    if mode == 6:
        return extension(offset, register)
    if mode == 7:
        if register == 0:
            return '(0x%04x).w' % word(offset), 2
        if register == 1:
            return '(0x%08x).l' % long(offset), 4
        if register == 2:
            return '(pc-relative %d)' % word(offset), 2
        if register == 3:
            return '(pc-indexed)', 2
        if register == 4:
            if size == 'l':
                return '#0x%08x' % long(offset), 4
            return '#0x%04x' % word(offset), 2
    return '?', 0


CONDITIONS = ('ra', 'sr', 'hi', 'ls', 'cc', 'cs', 'ne', 'eq', 'vc', 'vs', 'pl', 'mi', 'ge', 'lt', 'gt', 'le')


def decode(offset):
    """Decode a few common forms; return (text, length) or (None, 0)."""
    opcode = word(offset)
    top = opcode >> 12
    # Bcc / BRA / BSR
    if top == 6:
        condition = CONDITIONS[(opcode >> 8) & 0xf]
        displacement = opcode & 0xff
        if displacement == 0:
            displacement = int.from_bytes(data[offset + 2:offset + 4], 'big', signed=True)
            return 'b%s.w 0x%x' % (condition, offset + 2 + displacement), 4
        if displacement == 0xff:
            displacement = int.from_bytes(data[offset + 2:offset + 6], 'big', signed=True)
            return 'b%s.l 0x%x' % (condition, offset + 2 + displacement), 6
        if displacement & 0x80:
            displacement -= 0x100
        return 'b%s.s 0x%x' % (condition, offset + 2 + displacement), 2
    # MOVEQ
    if opcode & 0xf100 == 0x7000:
        value = opcode & 0xff
        if value & 0x80:
            value -= 0x100
        return 'moveq #%d,d%d' % (value, (opcode >> 9) & 7), 2
    # Shifts on a data register (immediate count)
    if opcode & 0xf000 == 0xe000 and (opcode >> 6) & 3 != 3:
        kinds = ('as', 'ls', 'rox', 'ro')
        kind = kinds[(opcode >> 3) & 3]
        direction = 'l' if opcode & 0x100 else 'r'
        count = (opcode >> 9) & 7 or 8
        size = 'bwl'[(opcode >> 6) & 3]
        if opcode & 0x20:
            return '%s%s.%s d%d,d%d' % (kind, direction, size, (opcode >> 9) & 7, opcode & 7), 2
        return '%s%s.%s #%d,d%d' % (kind, direction, size, count, opcode & 7), 2
    # MULU.W / MULS.W
    if opcode & 0xf1c0 in (0xc0c0, 0xc1c0):
        name = 'muls' if opcode & 0x100 else 'mulu'
        source, source_length = effective_address((opcode >> 3) & 7, opcode & 7, offset + 2, 'w')
        return '%s.w %s,d%d' % (name, source, (opcode >> 9) & 7), 2 + source_length
    # MOVEM
    if opcode & 0xfb80 == 0x4880:
        return 'movem 0x%04x' % word(offset + 2), 4 + (effective_address((opcode >> 3) & 7, opcode & 7, offset + 4, 'l')[1])
    # RTS / UNLK / LINK / JSR abs
    if opcode == 0x4e75:
        return 'rts', 2
    if opcode == 0x4eb9:
        return 'jsr 0x%x' % long(offset + 2), 6
    if opcode & 0xfff8 == 0x4fef or opcode == 0x4fef:
        return 'lea (%d,sp),sp' % int.from_bytes(data[offset + 2:offset + 4], 'big', signed=True), 4
    if opcode & 0xf1f8 == 0x5088 or opcode & 0xf1f8 == 0x508f:
        pass
    # MOVE / MOVEA
    if top in (1, 2, 3):
        size = SIZE[top]
        source_mode = (opcode >> 3) & 7
        source_register = opcode & 7
        destination_register = (opcode >> 9) & 7
        destination_mode = (opcode >> 6) & 7
        source, source_length = effective_address(source_mode, source_register, offset + 2, size)
        destination, destination_length = effective_address(destination_mode, destination_register,
                                                             offset + 2 + source_length, size)
        name = 'movea' if destination_mode == 1 else 'move'
        return '%s.%s %s,%s' % (name, size, source, destination), 2 + source_length + destination_length
    # LEA
    if opcode & 0xf1c0 == 0x41c0:
        source, source_length = effective_address((opcode >> 3) & 7, opcode & 7, offset + 2, 'l')
        return 'lea %s,a%d' % (source, (opcode >> 9) & 7), 2 + source_length
    # TST / CLR / NOT / NEG
    for base, name in ((0x4a00, 'tst'), (0x4200, 'clr'), (0x4600, 'not'), (0x4400, 'neg')):
        if opcode & 0xff00 == base and (opcode >> 6) & 3 != 3:
            size = 'bwl'[(opcode >> 6) & 3]
            source, source_length = effective_address((opcode >> 3) & 7, opcode & 7, offset + 2, size)
            return '%s.%s %s' % (name, size, source), 2 + source_length
    # ADDQ / SUBQ
    if opcode & 0xf000 == 0x5000 and (opcode >> 6) & 3 != 3:
        size = 'bwl'[(opcode >> 6) & 3]
        quick = (opcode >> 9) & 7 or 8
        name = 'subq' if opcode & 0x100 else 'addq'
        source, source_length = effective_address((opcode >> 3) & 7, opcode & 7, offset + 2, size)
        return '%s.%s #%d,%s' % (name, size, quick, source), 2 + source_length
    # CMPI / ANDI / ORI / SUBI / ADDI
    for base, name in ((0x0c00, 'cmpi'), (0x0200, 'andi'), (0x0000, 'ori'), (0x0400, 'subi'), (0x0600, 'addi')):
        if opcode & 0xff00 == base and (opcode >> 6) & 3 != 3:
            size = 'bwl'[(opcode >> 6) & 3]
            immediate_length = 4 if size == 'l' else 2
            immediate = long(offset + 2) if size == 'l' else word(offset + 2)
            if size == 'b':
                immediate &= 0xff
            source, source_length = effective_address((opcode >> 3) & 7, opcode & 7, offset + 2 + immediate_length, size)
            return '%s.%s #0x%x,%s' % (name, size, immediate, source), 2 + immediate_length + source_length
    # BTST/BSET/BCLR/BCHG static
    if opcode & 0xff00 == 0x0800:
        kind = ('btst', 'bchg', 'bclr', 'bset')[(opcode >> 6) & 3]
        bit = word(offset + 2) & 0xff
        source, source_length = effective_address((opcode >> 3) & 7, opcode & 7, offset + 4, 'b')
        return '%s #%d,%s' % (kind, bit, source), 4 + source_length
    # CMP / CMPA / ADD / SUB / AND / OR  <ea>,Dn  and Dn,<ea>
    groups = {0xb: 'cmp', 0xd: 'add', 0x9: 'sub', 0xc: 'and', 0x8: 'or'}
    if top in groups:
        operation_mode = (opcode >> 6) & 7
        register = (opcode >> 9) & 7
        name = groups[top]
        if operation_mode in (3, 7):
            size = 'w' if operation_mode == 3 else 'l'
            source, source_length = effective_address((opcode >> 3) & 7, opcode & 7, offset + 2, size)
            return '%sa.%s %s,a%d' % (name, size, source, register), 2 + source_length
        size = 'bwl'[operation_mode & 3]
        source, source_length = effective_address((opcode >> 3) & 7, opcode & 7, offset + 2, size)
        if operation_mode < 3:
            return '%s.%s %s,d%d' % (name, size, source, register), 2 + source_length
        return '%s.%s d%d,%s' % (name if top != 0xb else 'eor', size, register, source), 2 + source_length
    return None, 0


def show(start, count):
    offset = start
    for _ in range(count):
        text, length = decode(offset)
        if text is None:
            print('  %06x  %s   (not decoded)' % (offset, data[offset:offset + 6].hex()))
            return
        print('  %06x  %-50s %s' % (offset, text, data[offset:offset + length].hex()))
        offset += length


if __name__ == '__main__':
    for argument in sys.argv[1:]:
        start, count = argument.split(':')
        show(int(start, 16), int(count))
        print()
