"""Round 80 stage A (CM550). Idempotent. usage: apply_r80a.py <repo>
- 0xFFD00F CS2_WATCHDOG_SERVICE: every watchdog service writes SIM_SWSR = 0x55 / 0xaa and then the same pair here (64
  + 64 writes). This is the device on chip select 2 (SIM_CSBAR2 = 0xffd0), an output driver: its 0xFFD004 / 0xFFD006
  take the warning lamp driver enable bit and the commanded driver state. Its other registers stay unnamed (part not
  identified).
- The EEPROM log: cm550_parameterCircularBufferWrite stores entry i in a word array at 0x80BDA8 and a byte array at
  0x80C7A8 (i % 0x500); the QSPI path sends entry [read index] through QSM_TR4 / QSM_TR5 and advances the read index.
  The read index 0x80CCA8 (new row), the write index 0x80CCAA and the pending count 0x80CCAC are words (move.w /
  addq.w / tst.w).
- The two 82527s' bit timing in the RAM dump: CPU interface 0x41 (DSC 1: SCLK = XTAL / 2), BTR0 0x01 (BRP 1), BTR1 0x1c
  (TSEG1 12 / TSEG2 1) on both - XTAL / 64, 250 kbit/s with a 16 MHz crystal."""
import os
import sys

p = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM550_J90350.00_analysis/output/global_variables.csv")
s = open(p, newline="").read()
R = "PR #53 round 80"
TIMING = ("RAM dump: CPU interface 0x41 (DSC 1) / BTR0 0x01 (BRP 1) / BTR1 0x1c (TSEG1 12 / TSEG2 1) on both 82527s - "
          f"XTAL / 64 = 250 kbit/s with a 16 MHz crystal; {R}")
edits = [
    ("0x0080ccaa,eeprom_circular_buffer_write_index,undefined,",
     "0x0080ccaa,eeprom_circular_buffer_write_index,word,The EEPROM log's write index: cm550_parameterCircularBufferWrite "
     f"stores entry i at 0x80BDA8 + 2 i (word) and 0x80C7A8 + i (byte) and advances it modulo 0x500 (typed word; {R})"),
    ("0x0080ccac,circular_buffer_byte_count,undefined,",
     "0x0080ccac,circular_buffer_byte_count,word,The EEPROM log's pending entry count: +1 per write - -1 per entry sent "
     f"(addq.w / move.w / tst.w; typed word; {R})"),
]
for old, new in edits:
    if new not in s:
        assert s.count(old) == 1, (old, s.count(old))
        s = s.replace(old, new)
for reg in ("CAN_CS5_BIT_TIMING_0", "CAN_CS5_BIT_TIMING_1", "CAN_CS4_BIT_TIMING_0", "CAN_CS4_BIT_TIMING_1"):
    lines = [l for l in s.split("\n") if f",{reg},byte," in l]
    assert len(lines) == 1, reg
    if R not in lines[0]:
        s = s.replace(lines[0], lines[0][:-1] + f"; {TIMING})" if lines[0].endswith(")") else lines[0] + f" ({TIMING})")
new_rows = [
    ("0x0080cca8", "0x0080cca8,eeprom_circular_buffer_read_index,word,The EEPROM log's read index: the QSPI path sends "
     "entry [index] through QSM_TR4 (the word at 0x80BDA8) and QSM_TR5 (the byte at 0x80C7A8) and advances it modulo "
     f"0x500 (move.w / addq.w; {R})"),
    ("0x00ffd00f", "0x00ffd00f,CS2_WATCHDOG_SERVICE,byte,The watchdog service register of the device on chip select 2 "
     "(SIM_CSBAR2 = 0xffd0 - an output driver): every watchdog service writes 0x55 then 0xaa here right after SIM_SWSR "
     f"(64 + 64 writes) ({R})"),
]
lines = s.split("\n")
for address, row in new_rows:
    if any(l.startswith(address + ",") for l in lines):
        continue
    for i, l in enumerate(lines):
        if l.startswith("0x") and int(l.split(",")[0], 16) > int(address, 16):
            lines.insert(i, row)
            break
    else:
        lines.insert(len(lines) - 1 if lines[-1] == "" else len(lines), row)
s = "\n".join(lines)
open(p, "w", newline="").write(s)
print("round 80 stage A applied")
