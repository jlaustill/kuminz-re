import struct, sys
src, dst, machine = sys.argv[1], sys.argv[2], int(sys.argv[3])
data = open(src, 'rb').read()
shstr = b'\x00.text\x00.shstrtab\x00'
ehsize = 52
text_off = 0x100
shstr_off = text_off + len(data)
sh_off = (shstr_off + len(shstr) + 3) & ~3
def sh(name, typ, flags, addr, off, size, link=0, info=0, align=1, entsize=0):
    return struct.pack('>IIIIIIIIII', name, typ, flags, addr, off, size, link, info, align, entsize)
shdrs = sh(0,0,0,0,0,0) + sh(1,1,6,0,text_off,len(data),align=2) + sh(7,3,0,0,shstr_off,len(shstr))
ident = b'\x7fELF' + bytes([1,2,1]) + b'\x00'*9
hdr = ident + struct.pack('>HHIIIIIHHHHHH', 1, machine, 1, 0, 0, sh_off, 0, ehsize, 0, 0, 40, 3, 2)
out = bytearray(hdr)
out += b'\x00'*(text_off-len(out))
out += data
out += shstr
out += b'\x00'*(sh_off-len(out))
out += shdrs
open(dst,'wb').write(out)
