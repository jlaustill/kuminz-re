# J90350.00 Extraction Log

## Session: 2024-12-16

### Background

This was the **first successful firmware extraction from a live CM550 ECU**. The extraction used Service 0x4A (direct memory read), which bypasses the CLIP session management and returns data via J1939 Transport Protocol.

### Hardware Setup

- **ECU**: Cummins CM550 (physical unit)
- **CAN Adapter**: OBDLink EX (USB ID 0403:6015)
- **CAN Interface**: can0 via slcand
- **Bitrate**: 250kbps (J1939 standard)
- **Tool Address**: 0xF9

### Tool Used

```bash
# CAN interface setup
sudo ip link set can0 type can bitrate 250000
sudo ip link set can0 up

# Extraction commands
./kuminz-cli can0 --dump-eeprom /tmp/test_eeprom.bin  # 4KB, ~10 sec
./kuminz-cli can0 --dump-ram /tmp/test_ram.bin        # 37KB, ~2 min
./kuminz-cli can0 --dump-rom /tmp/test_rom.bin        # 256KB, ~15 min
```

### Extraction Timeline

| Time | Event |
|------|-------|
| 13:03 | EEPROM dump completed (4,096 bytes) |
| 13:04 | RAM dump completed (37,314 bytes) |
| 13:08 | ROM dump completed (262,144 bytes) |

### ECU Identification

Found in EEPROM strings:
```
ABCDEF
T03942860              <- Serial number
ENUU
060498                 <- Date code (June 4, 1998?)
JCMMNSISB 195          <- Engine: Cummins ISB 195hp
98502
J90350.00 100898231658 <- Firmware version + calibration
GENERIC
```

### Protocol Details

**Service 0x4A Request Format:**
```
Byte 0: 0x4A (service ID)
Bytes 1-4: 32-bit address (big-endian)
Byte 5: length (max 255)
Bytes 6-7: 0x00 (unused)
```

**Response via J1939 TP:**
1. ECU sends RTS (Request To Send) on PGN 60416 (0xEC)
2. Tool sends CTS (Clear To Send)
3. ECU sends TP.DT frames on PGN 60160 (0xEB)
4. Tool sends EOM acknowledgment

**Response Data Format:**
```
Byte 0: 0x4B (response service ID)
Bytes 1-4: Echo of requested address
Byte 5: Length of returned data
Bytes 6+: Actual data
```

### Key Insight

Unlike the CLIP protocol (which requires session establishment with OpenCommRequestMsg/GetSeedMsg/SendKeyMsg), Service 0x4A works **without any session setup**. This is likely a diagnostic backdoor for direct memory access.

### Files Produced

```
firmware/J90350.00_analysis/firmware/
├── J90350.00.rom.bin      # 262,144 bytes - Full ROM/Flash
├── J90350.00.ram.bin      # 37,314 bytes - RAM snapshot
└── J90350.00.eeprom.bin   # 4,096 bytes - EEPROM
```

### Significance

This extraction proves:
1. **Service 0x4A works** for CM550 memory reads
2. **kuminz-cli is functional** for real ECU interaction
3. **J90350.00 is a different calibration** than J90280.05 (the reference)
4. **All accessible memory regions can be dumped**

The J90280.05 analysis (with 100% function naming) can now be used as a reference to bootstrap analysis of this actual ECU firmware.
