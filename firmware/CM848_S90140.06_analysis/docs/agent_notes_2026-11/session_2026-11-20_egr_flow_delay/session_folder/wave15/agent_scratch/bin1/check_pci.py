"""Cross-check every 8A13 record of bin1 against the PCI descriptor tables of the ROM image:
the record's address must be the status pointer (Err*) or timer pointer (Act*) of the table entry whose header carries
the record's message id; the current name's TX[n] / RX[n] index must equal that entry's index."""
import json
import re
import struct

rom = open('/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/'
           'originals/cm848_rom.bin', 'rb').read()
entries = {}
for tag, base, count in (('RX', 0x5774b, 15), ('TX', 0x578ef, 25)):
    for i in range(count):
        b = rom[base + 28 * i: base + 28 * (i + 1)]
        hdr = b[0:4].hex()
        timer = struct.unpack('>I', b[14:18])[0]
        status = struct.unpack('>I', b[24:28])[0]
        entries[(tag, i)] = (hdr, timer, status)
by_status = {v[2]: (k, v) for k, v in entries.items()}
by_timer = {v[1]: (k, v) for k, v in entries.items()}

bin1 = json.load(open('/home/linux/.claude/jobs/374b0424/tmp/w15/bins/bin1.json'))
for r in bin1:
    if r['block'] != '8A13':
        continue
    addr = int(r['address'], 16)
    rec = r['record']
    kind = 'status' if ('Err' in rec) else 'timer'
    table = by_status if kind == 'status' else by_timer
    hit = table.get(addr)
    cur = r['label_in_cpp']
    m = re.match(r'pci_(transmit|receive)_message_(\d+)_(status|timer)', cur)
    if not hit:
        print('NO TABLE ENTRY', r['offset'], rec, cur, hex(addr))
        continue
    (tag, idx), (hdr, timer, status) = hit
    ok = bool(m) and m.group(3) == kind and (m.group(1) == 'transmit') == (tag == 'TX') and int(m.group(2)) == idx
    print('%-4s %-14s %-12s -> %s[%2d] hdr=%-8s | cur=%s | %s' % (r['offset'], rec, kind, tag, idx, hdr, cur,
                                                                   'OK' if ok else 'MISMATCH'))
