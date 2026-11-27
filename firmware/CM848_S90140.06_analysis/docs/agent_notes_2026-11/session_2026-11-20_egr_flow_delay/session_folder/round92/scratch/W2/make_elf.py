"""Wrap a raw big-endian m68k ROM image into a minimal ELF32 (EM_68K) with one .text section at VMA 0,
so llvm-objdump-18 can disassemble it with addresses. usage: make_elf.py <rom.bin> <out.elf>"""
import struct, sys
rom = open(sys.argv[1], 'rb').read()
shstr = b'\0.text\0.shstrtab\0'
ehsize, shentsize = 52, 40
text_off = ehsize
shstr_off = text_off + len(rom)
sh_off = (shstr_off + len(shstr) + 3) & ~3
ident = b'\x7fELF' + bytes([1, 2, 1, 0]) + bytes(8)
eh = ident + struct.pack('>HHIIIIIHHHHHH', 2, 4, 1, 0, 0, sh_off, 0, ehsize, 0, 0, shentsize, 3, 2)
def sh(name, typ, flags, addr, off, size, align):
    return struct.pack('>IIIIIIIIII', name, typ, flags, addr, off, size, 0, 0, align, 0)
sections = sh(0, 0, 0, 0, 0, 0, 0) + sh(1, 1, 6, 0, text_off, len(rom), 2) + sh(7, 3, 0, 0, shstr_off, len(shstr), 1)
out = eh + rom + shstr
out += bytes(sh_off - len(out)) + sections
open(sys.argv[2], 'wb').write(out)
