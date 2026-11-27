import json

_bin = json.load(open('/home/linux/.claude/jobs/374b0424/tmp/w15/bins/bin2.json'))

# extra text per address (everything else is a plain keep: the name's PCI table entry and the e2m message id agree)
_extra = {
    '0x0040b3fa': " (the e2m says ECM Rx; the PCI tables list header 3A as TX[6], status byte at this address)",
    '0x0040b3fb': " (the e2m says ECM Rx; the PCI tables list header 3A as TX[6], age timer at this address)",
    '0x0040b40c': " (the e2m says ECM Rx; the PCI tables list header 98 as TX[12], status byte at this address)",
    '0x0040b41c': " (the e2m says ECM Rx; the PCI tables list header EA as TX[18], status byte at this address)",
    '0x0040b41d': " (the e2m says ECM Rx; the PCI tables list header EA as TX[18], age timer at this address)",
    '0x0040b423': " (the e2m says ECM Rx and header $TBD; the PCI tables list header 1E as TX[1], status byte at this address)",
    '0x0040b424': " (the e2m says ECM Rx and header $TBD; the PCI tables list header 1E as TX[1], age timer at this address)",
    '0x0040b431': " (the e2m says ECM Tx; the PCI tables list header 1A as RX[3] with receive timeout 348, status byte at this address)",
    '0x0040b432': " (the e2m says ECM Tx; the PCI tables list header 1A as RX[3] with receive timeout 348, age timer at this address)",
    '0x0040b410': " (2-byte e2m record: this byte, payload byte 2 of RX[8] header 6C, and pci_receive_message_8_byte_3 together are the transmission DTC; the code tests the two bytes for zero together; this row is typed byte)",
    '0x0040b412': " (a second e2m record, Store_Freeze_Frame_Now 'Bit indicating Freeze Frame to be stored now', sits on bit 7 of this byte; the code uses bit 7 only as the MIL request pci_received_mil_request_flag, which feeds the 0xB0 MIL lamp message, and bits 0-6 as the fault count)",
}

V = []
for r in _bin:
    if r['block'] != '8A12':
        continue
    off = r['offset'].lstrip('0') or '0'
    note = f"e2m {r['block']} +{off} {r['record']} '{r['description']}'" + _extra.get(r['address'], '')
    V.append({'address': r['address'], 'verdict': 'keep', 'e2m_note': note})
