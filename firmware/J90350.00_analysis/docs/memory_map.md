# CM550 MC68336 Memory Map

## Overview

The CM550 ECU uses a Motorola MC68336 microcontroller with external memory expansion.

## Extractable Memory Regions

| Region | Address Range | Size | Status | Contents |
|--------|---------------|------|--------|----------|
| **ROM** | 0x000000-0x03FFFF | 256KB | Extracted | Firmware code, lookup tables |
| **RAM** | 0x800000-0x8091C1 | 37KB | Extracted | Working variables, buffers |
| **EXT_RAM** | 0x8091C2-0x80FF7F | 28KB | Extracted | Scheduler, J1708, diagnostics |
| **EEPROM** | 0x1000000-0x1000FFF | 4KB | Extracted | Module ID, calibration config |

**Total Extracted:** 325KB (100% of data memory)

## Non-Extractable Regions

### MC68336 Internal Module Base (0xFFD000-0xFFFFFF)

These are memory-mapped hardware registers, not data storage. Reading them returns current hardware state.

| Module | Address Range | Purpose |
|--------|---------------|---------|
| SIM | 0xFFFA00-0xFFFA7F | System Integration Module |
| COP | 0xFFFA27 | Watchdog service register |
| QSM | 0xFFC800-0xFFC8FF | Queued Serial Module |
| QSM | 0xFFD800-0xFFD8FF | QSM additional registers |
| RSIM | 0xFFD000-0xFFD00F | Reset/config registers |
| GPT | 0xFFE000-0xFFE0FF | General Purpose Timer |
| GPIO | 0xFFF200-0xFFF23F | Port F, E data/direction |
| SIM CS | 0xFFF400-0xFFF4FF | Chip select configuration |
| TPU | 0xFFFC00-0xFFFC1F | Time Processing Unit |
| QADC | 0xFFFD00-0xFFFD7F | Queued ADC |
| TPU RAM | 0xFFFE00-0xFFFF7F | TPU parameter RAM |

### Virtual Address Space

| Region | Address Range | Notes |
|--------|---------------|-------|
| CalTerm Virtual | 0x060000-0x06FFFF | Not real ECU memory - CalTerm internal |

## Memory Map Diagram

```
0x00000000 +-----------------+
           |                 |
           |      ROM        | 256KB (Firmware)
           |                 |
0x0003FFFF +-----------------+
           |                 |
           |   (unmapped)    |
           |                 |
0x00060000 +-----------------+
           | CalTerm Virtual | Not real ECU memory
0x0006FFFF +-----------------+
           |                 |
           |   (unmapped)    |
           |                 |
0x00800000 +-----------------+
           |      RAM        | 37KB (Working memory)
0x008091C1 +-----------------+
           |    EXT_RAM      | 28KB (Extended)
0x0080FF7F +-----------------+
           |                 |
           |   (unmapped)    |
           |                 |
0x00FFD000 +-----------------+
           |   Peripherals   | MC68336 internal modules
0x00FFFFFF +-----------------+
           |                 |
           |   (unmapped)    |
           |                 |
0x01000000 +-----------------+
           |     EEPROM      | 4KB (Configuration)
0x01000FFF +-----------------+
```

## Firmware Files

| File | Region | Size | MD5 |
|------|--------|------|-----|
| J90350.00.rom.bin | ROM | 262,144 | - |
| J90350.00.ram.bin | RAM | 37,314 | - |
| J90350.00.extended_ram.bin | EXT_RAM | 28,094 | - |
| J90350.00.eeprom.bin | EEPROM | 4,096 | - |

## Extraction Commands

```bash
# Using kuminz-cli
./kuminz-cli can0 --dump-rom J90350.00.rom.bin
./kuminz-cli can0 --dump-ram J90350.00.ram.bin
./kuminz-cli can0 --dump-extended-ram J90350.00.extended_ram.bin
./kuminz-cli can0 --dump-eeprom J90350.00.eeprom.bin

# Or all at once
./kuminz-cli can0 --dump-all ./firmware/
```

## Ghidra Memory Map Setup

The `SetupMemoryMap.java` script configures all regions:

```java
private static final long RAM_BASE = 0x800000L;
private static final long EXTENDED_RAM_BASE = 0x8091C2L;
private static final long EEPROM_BASE = 0x1000000L;
```

## Region Contents

### ROM (0x000000-0x03FFFF)
- Reset vectors and exception handlers
- Boot code (Huffman decompression)
- Main firmware code
- Lookup tables (fuel maps, timing tables)
- Compressed data sections

### RAM (0x800000-0x8091C1)
- Engine RPM history buffers
- VP44 message state
- CAN TX/RX buffers
- Diagnostic mode buffers
- Parameter circular buffers
- QADC result storage

### EXT_RAM (0x8091C2-0x80FF7F)
- Scheduler phase tables
- J1708 protocol buffers
- Diagnostic response buffers
- Data collector buffers
- Extended parameter storage

### EEPROM (0x1000000-0x1000FFF)
- Module ID ("EN" + variant A/B/C)
- Serial number
- Data plate information
- Calibration configuration
- Persistent fault codes

## MC68336 Peripheral Usage

Firmware references found in decompiled code:

| Register | Address | Usage |
|----------|---------|-------|
| COP Service | 0xFFFA27 | Watchdog refresh (0xAA) |
| RSIM Control | 0xFFD00F | Reset control |
| Port F Data | 0xFFF206 | GPIO output |
| Port F DDR | 0xFFF208 | GPIO direction |
| TPU MCR | 0xFFFC18 | TPU config |
| QADC Control | 0xFFFD20 | ADC setup |
| QADC Result | 0xFFFD04-06 | ADC readings |
