"""Round 81 stage A (CM550): four functions whose names claim hardware they do not touch (hardware_name_check.py),
renamed for what they drive; and round 80's 'EEPROM log' corrected to what the driver shows - a serial EEPROM write
queue. Idempotent. usage: apply_r81a.py <repo> <map.csv>"""
import os
import sys

repo, map5 = os.path.abspath(sys.argv[1]), sys.argv[2]
O5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
R = "PR #53 round 81"


def edit(p, old, new):
    s = open(p, newline="").read()
    if new in s:
        return
    assert s.count(old) == 1, (os.path.basename(p), old[:90], s.count(old))
    open(p, "w", newline="").write(s.replace(old, new))


F5, G5 = os.path.join(O5, "function_renames.csv"), os.path.join(O5, "global_variables.csv")
RENAMES = [
    ("0x000039a8", "mc68k_tpuAndQadcVerification", "mc68k_checkSerialEepromSignature",
     "Reads the serial EEPROM's first word over the QSPI and checks it: sets up the QSPI (QSM_SPCR0-2 / QSM_PQSPAR / "
     "QSM_DDRQS) - queues READ (command 3) at address 0 and 14 clock bytes - waits for QSM_SPSR - returns 0x6000 when the "
     "received QSM_RR2:QSM_RR3 is 0x600d (CM848's ECM_STATUS_CALIBRATION_VALID) and 1 otherwise. No TPU or QADC register "
     "is involved"),
    ("0x000266da", "mc68k_qadcDataCollectionStateMachine", "mc68k_runSerialEepromWriteQueue",
     "The serial EEPROM driver over the QSPI: issues the SPI EEPROM commands 5 (read status - tests the write-in-progress "
     "bit in QSM_RR3) / 6 (write enable) / 2 (write) / 3 (read). Each write sends the next queue entry: the address "
     "word at 0x80BDA8 + 2 x eeprom_circular_buffer_read_index (QSM_TR4) and the data byte at 0x80C7A8 + index (QSM_TR5). "
     "No QADC register is involved"),
    ("0x0001e52e", "serialTransmitHandler", "mc68k_canCs4TransmitNextFrame",
     "Sends the next frame on the 82527 CAN controller on chip select 4: writes a message object's control register "
     "through _can_control_register_pointer - copies the next 14-byte entry of the CAN transmit ring (0x80D896-0x80D9A0) "
     "with cm550_canFrameDataCopy(&CAN_CS4_CONTROL) and advances the ring pointer. No serial port is involved"),
    ("0x0001e0fa", "cm550_FUN_0001e0fa", "mc68k_canCs4InterruptHandler",
     "The interrupt handler of the 82527 CAN controller on chip select 4: loops while CAN_CS4_INTERRUPT is non-zero - "
     "on a status change it reads CAN_CS4_STATUS and resets the controller (CAN_CS4_CONTROL = 1 / waits for "
     "CAN_CS4_CPU_INTERFACE bit 7 / restores the control bits) - and passes message object interrupts to "
     "cm550_serialNodeAddressForwarder / cm550_serialNodeAddressChecker"),
]
for address, old, new, plate in RENAMES:
    s = open(F5, newline="").read()
    line = [l for l in s.split("\n") if l.startswith(f"{address},")]
    assert len(line) == 1, address
    if f"{address},{new}," in s:
        continue
    assert line[0].split(",")[1] == old, (address, line[0][:60])
    edit(F5, line[0], f"{address},{new},{plate} (was {old}; {R})")
QUEUE = [
    ("0x0080cca8,eeprom_circular_buffer_read_index,word,The EEPROM log's read index:",
     "0x0080cca8,eeprom_circular_buffer_read_index,word,The serial EEPROM write queue's read index (each entry = an "
     f"EEPROM address word at 0x80BDA8 + 2 i and a data byte at 0x80C7A8 + i; {R}):"),
    ("0x0080ccaa,eeprom_circular_buffer_write_index,word,The EEPROM log's write index:",
     "0x0080ccaa,eeprom_circular_buffer_write_index,word,The serial EEPROM write queue's write index (an entry = an "
     f"EEPROM address word and a data byte; {R}):"),
    ("0x0080ccac,circular_buffer_byte_count,word,The EEPROM log's pending entry count:",
     f"0x0080ccac,circular_buffer_byte_count,word,The serial EEPROM write queue's pending entry count ({R}):"),
]
for old, new in QUEUE:
    edit(G5, old, new)
with open(map5, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n")
    for address, old, new, _ in RENAMES:
        fh.write(f"{address},{new},{old},function,1\n")
print("round 81 stage A applied")
