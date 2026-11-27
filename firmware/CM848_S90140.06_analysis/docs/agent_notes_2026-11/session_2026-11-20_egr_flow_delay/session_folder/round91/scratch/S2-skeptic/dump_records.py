import struct
base = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/'
ram = open(base + 'J90350.00.ram.bin', 'rb').read()
eep = open(base + 'J90350.00.eeprom.bin', 'rb').read()
ext = open(base + 'J90350.00.extended_ram.bin', 'rb').read()


def r(addr, n):
    if 0x800000 <= addr < 0x800000 + len(ram):
        return ram[addr - 0x800000: addr - 0x800000 + n]
    if addr >= 0x8092c2:
        return ext[addr - 0x809242: addr - 0x809242 + n]
    raise ValueError(hex(addr))


print('RAM 0x803d64..0x803dca:', r(0x803d64, 0x66).hex())
print('EEP 0x25a..0x2c0     :', eep[0x25a:0x25a + 0x66].hex())
print('mirror equal (0x803d64..0x803dc9):', r(0x803d64, 0x66) == eep[0x25a:0x25a + 0x66])
for i in range(4):
    b = r(0x803d64 + 16 * i, 16)
    vl, dis, fc, md, pid, off, thr, sg = struct.unpack('>BBHHHHIH', b)
    print('trigger %d: len=%d disable=%d fault=%d mode=%d id=0x%04x off=0x%x thr=0x%x signed=%d' % (i + 1, vl, dis, fc, md, pid, off, thr, sg))
for i in range(5):
    b = r(0x803da4 + 6 * i, 6)
    vl, pid, off = struct.unpack('>HHH', b)
    print('data %d: len=%d id=0x%04x off=0x%x' % (i + 1, vl, pid, off))
print('UDADSZ 0x803dc2 =', struct.unpack('>H', r(0x803dc2, 2))[0])
print('UDSART 0x803dc4 =', struct.unpack('>H', r(0x803dc4, 2))[0])
print('UDTRMD 0x803dc6 =', struct.unpack('>H', r(0x803dc6, 2))[0])
print('UDPRCU 0x803dc8 =', struct.unpack('>H', r(0x803dc8, 2))[0])
print('words 0x803dca..', r(0x803dca, 8).hex())
print('0x80bac4..0x80bacc:', r(0x80bac4, 8).hex())
print('0x800350..0x800374:', r(0x800350, 0x24).hex())
print('trigger addr dwords 0x800356:', [hex(x) for x in struct.unpack('>4I', r(0x800356, 16))])
print('fault index 0x800366:', r(0x800366, 4).hex(), ' satisfied 0x80036a:', r(0x80036a, 4).hex(), ' prev status 0x80036e:', r(0x80036e, 4).hex(), ' 0x800372:', r(0x800372, 2).hex())
print('write ptr 0x800504:', hex(struct.unpack('>I', r(0x800504, 4))[0]))
print('data addr dwords 0x800508:', [hex(x) for x in struct.unpack('>5I', r(0x800508, 20))])
print('0x80051c..0x80052c:', r(0x80051c, 16).hex())
ring = r(0x800374, 400)
print('ring first 40:', ring[:40].hex())
print('ring distinct 10-byte chunks:', len(set(ring[i:i + 10] for i in range(0, 400, 10))))
print('0x804fca first 40 :', r(0x804fca, 40).hex())
print('0x80515a first 40 :', r(0x80515a, 40).hex())
print('0x8052ea..0x8052fe:', r(0x8052ea, 20).hex())
print('key_on_hour_meter 0x80bda4:', r(0x80bda4, 4).hex())
print('0x80bcd0:', r(0x80bcd0, 2).hex())
print('0x803cb8 feature word:', r(0x803cb8, 2).hex())
print('0x80d0c8 engine_state:', r(0x80d0c8, 2).hex())
