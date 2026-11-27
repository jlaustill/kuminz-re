import struct, sys
# usage: mkelf.py rom.bin start end out.elf
rom, start, end, out = sys.argv[1], int(sys.argv[2], 0), int(sys.argv[3], 0), sys.argv[4]
data = open(rom, 'rb').read()[start:end]
shstr = b'\x00.text\x00.shstrtab\x00'
ehsize = 52
shentsize = 40
text_off = ehsize
shstr_off = text_off + len(data)
sh_off = shstr_off + len(shstr)
sh_off = (sh_off + 3) & ~3
pad = sh_off - (shstr_off + len(shstr))
e_ident = b'\x7fELF' + bytes([1, 2, 1, 0]) + b'\x00' * 8
hdr = e_ident + struct.pack('>HHIIIIIHHHHHH', 1, 4, 1, 0, 0, sh_off, 0, ehsize, 0, 0, shentsize, 3, 2)
sh_null = b'\x00' * 40
sh_text = struct.pack('>IIIIIIIIII', 1, 1, 6, start, text_off, len(data), 0, 0, 2, 0)
sh_shstr = struct.pack('>IIIIIIIIII', 7, 3, 0, 0, shstr_off, len(shstr), 0, 0, 1, 0)
open(out, 'wb').write(hdr + data + shstr + b'\x00' * pad + sh_null + sh_text + sh_shstr)
