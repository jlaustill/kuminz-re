"""Dump the CM848 PCI RX / TX descriptor tables (28-byte records) from the ROM image.
layout: hdr0..3 (4), data_buffer ptr (4), data_length ptr (4), interval (2), timer ptr (4), in_frame_enabled (1),
reserved (1), in_frame_bytes ptr (4), status ptr (4) = 28 bytes; check offsets below."""
import struct

rom = open('/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/'
           'originals/cm848_rom.bin', 'rb').read()


def rec(base, i):
    b = rom[base + 28 * i: base + 28 * (i + 1)]
    hdr = b[0:4]
    data_buf, data_len = struct.unpack('>II', b[4:12])
    interval = struct.unpack('>H', b[12:14])[0]
    timer = struct.unpack('>I', b[14:18])[0] if False else None
    return b


def parse(base, count, tag):
    for i in range(count):
        b = rom[base + 28 * i: base + 28 * (i + 1)]
        hdr = b[0:4]
        data_buf, data_len = struct.unpack('>II', b[4:12])
        interval = struct.unpack('>H', b[12:14])[0]
        # offsets after interval: timer ptr is 4-byte aligned? try 14..18 (unaligned) vs 16..20
        timer_a = struct.unpack('>I', b[14:18])[0]
        timer_b = struct.unpack('>I', b[16:20])[0]
        print('%s[%2d] hdr=%s buf=%08x len=%08x interval=%5d  raw=%s' % (
            tag, i, hdr.hex(), data_buf, data_len, interval, b[12:].hex()))


parse(0x5774b, 15, 'RX')
parse(0x578ef, 25, 'TX')
