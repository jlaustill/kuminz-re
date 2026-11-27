"""Wrap the raw big-endian CM550 ROM into a minimal ELF32 (EM_68K) at address 0 so llvm-objdump prints real addresses."""
import struct
import sys

src, dst = sys.argv[1], sys.argv[2]
data = open(src, 'rb').read()
shstr = b'\0.text\0.shstrtab\0'
text_off = 0x1000
shstr_off = text_off + len(data)
sh_off = (shstr_off + len(shstr) + 3) & ~3
e_ident = b'\x7fELF' + bytes([1, 2, 1, 0]) + b'\0' * 8
eh = e_ident + struct.pack('>HHIIIIIHHHHHH', 2, 4, 1, 0, 0, sh_off, 0, 52, 0, 0, 40, 3, 2)
sh_text = struct.pack('>IIIIIIIIII', 1, 1, 6, 0, text_off, len(data), 0, 0, 2, 0)
sh_shstr = struct.pack('>IIIIIIIIII', 7, 3, 0, 0, shstr_off, len(shstr), 0, 0, 1, 0)
out = eh + b'\0' * (text_off - len(eh)) + data + shstr
out += b'\0' * (sh_off - len(out))
out += b'\0' * 40 + sh_text + sh_shstr
open(dst, 'wb').write(out)
