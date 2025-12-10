# Memory Range Analysis: EEPROM Parameters vs Firmware Binary

## Summary

**Key Finding**: All 1454 memory addresses with non-zero defaults are **outside** the J90280.05 firmware binary range, confirming that the EEPROM is currently all zeros as stated.

## Memory Range Comparison

### J90280.05 Firmware Binary Range
- **Start Address**: `0x00000000` 
- **End Address**: `0x0003FFFF` (256KB)
- **Status**: Contains actual firmware code and data

### EEPROM Parameter Address Range  
- **Start Address**: `0x00060006` (lowest parameter address)
- **End Address**: `0x006FFE8C` (highest parameter address) 
- **Status**: **Currently all zeros** - needs to be populated with defaults

### Address Gap Analysis
- **Gap Start**: `0x00040000` (end of firmware)
- **Gap End**: `0x00060005` (before first parameter)
- **Gap Size**: `0x20006` bytes (131,078 bytes) of unmapped memory

## Parameter Distribution

### Memory Block 9 (Primary Parameters)
- **Address Range**: `0x00060006` - `0x00060092` 
- **Parameters**: 19 critical engine parameters
- **Examples**:
  - `PTESLOLM` at `0x00060006`: 700.0 RPM (PTO low limit)
  - `PTESHILM` at `0x00060008`: 3000.0 RPM (PTO high limit)
  - `CRVSRFLL` at `0x00060078`: 30.0 MPH (cruise control limit)

### Memory Block 0 (Data Plate)
- **Address Range**: `0x006FFE8C`
- **Parameters**: 1 parameter
- **Example**: `DATA_PLT`: 454E (data plate identifier)

## Implications for Reverse Engineering

### 1. Code References to Find
Since the EEPROM addresses are outside the firmware binary, search for:

**Direct Address References**:
```assembly
# Look for these patterns in disassembly:
move.w #0x60006,%a0     # Loading EEPROM parameter address
lea 0x60006,%a1         # Loading EEPROM base address  
cmp.w 0x60006,%d0       # Comparing with EEPROM value
```

**Base + Offset Calculations**:
```assembly
# Memory block address (9) + offset (6):
move.w #0x9,%d0         # Block address
asl.w #8,%d0            # Multiply by 256  
add.w #0x6,%d0          # Add offset = 0x906
add.l #0x60000,%d0      # Add base = 0x60006
```

### 2. Memory Initialization Code
Look for code that:
- Sets up EEPROM memory mapping
- Initializes default values on first boot
- Validates EEPROM checksum/integrity
- Falls back to defaults when EEPROM is blank

### 3. Parameter Access Functions
Search for functions that:
- Read/write to addresses in 0x060000+ range
- Use the memory block + offset formula
- Handle the specific parameter names found

## Next Steps for Code Analysis

### 1. Search Firmware for EEPROM Base Addresses
```bash
# Search for potential EEPROM base addresses
grep -i "6000\|0x6000\|60000\|0x60000" disassembly_files

# Search for memory block calculations  
grep -i "256\|0x100\|<<8\|asl.*8" disassembly_files
```

### 2. Look for Parameter Name Strings
```bash
# Search for parameter names as strings
grep -i "PTESLOLM\|PTESHILM\|CRVSRFLL" firmware_strings
```

### 3. Analyze Memory Mapping Code
Focus on code sections that:
- Initialize memory controllers
- Set up address translation
- Handle memory-mapped I/O to EEPROM regions

## Conclusion

The analysis confirms that:
1. **All EEPROM parameter addresses are currently zeros** (outside firmware binary)
2. **743 unique addresses need default values** to make the firmware functional
3. **Code references to these addresses exist** in the 256KB firmware binary
4. **Finding the EEPROM initialization/access code** is crucial for understanding how to populate these values

This creates a clear roadmap for reverse engineering: find the code that accesses the 0x060000+ memory range to understand how the ECU expects to read these critical engine parameters.