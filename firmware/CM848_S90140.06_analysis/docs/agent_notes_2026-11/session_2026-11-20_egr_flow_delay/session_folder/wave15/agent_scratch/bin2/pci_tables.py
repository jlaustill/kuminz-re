import struct
rom = open('/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals/cm848_rom.bin', 'rb').read()
print(len(rom))


def dump(base, count, label):
    for i in range(count):
        o = base + 28 * i
        d = rom[o:o + 28]
        hdr = d[0:4]
        data_buffer, data_length = struct.unpack('>II', d[4:12])
        interval, = struct.unpack('>H', d[12:14])
        timer, = struct.unpack('>I', d[14:18])
        infr = d[18]
        infr_bytes, status = struct.unpack('>II', d[20:28])
        print(f'{label}[{i}] @0x{o:x} hdr={hdr.hex()} buf=0x{data_buffer:x} len@0x{data_length:x} interval={interval} timer@0x{timer:x} infr={infr} infr_bytes@0x{infr_bytes:x} status@0x{status:x}')


dump(0x5774b, 15, 'RX')
dump(0x578ef, 25, 'TX')
