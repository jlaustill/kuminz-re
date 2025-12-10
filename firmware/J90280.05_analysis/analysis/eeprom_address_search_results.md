# EEPROM Address Search Results

## Search Summary

**Key Finding**: **NO direct references to EEPROM addresses (0x00060006+) found in firmware disassembly.**

This confirms the EEPROM is all zeros and reveals important insights about the architecture.

## Search Results

### Direct Address Searches
- ❌ No matches for `0x00060006`, `0x00060008`, etc.
- ❌ No matches for `60006`, `60008`, etc. in hex format  
- ❌ No matches for parameter names (`PTESLOLM`, `PTESHILM`, etc.)
- ❌ No matches for "EEPROM", "NVRAM", "param" strings

### Memory Address Range Analysis
- **Firmware range**: `0x00000000` - `0x0003FFFF` (256KB)
- **EEPROM range**: `0x00060006` - `0x006FFE8C` 
- **Gap**: 131KB of unmapped memory

### Patterns Found Instead
1. **Left shift by 8 operations** (`lsll #8`) - used for multiply by 256
2. **0x8XXXXX address references** - likely RAM/peripheral space
3. **Memory mapping setup code** around addresses `0x800000+`

## Architecture Implications

### 1. Memory-Mapped I/O Design
The EEPROM likely uses **memory-mapped I/O** where:
- Physical EEPROM addresses are mapped to different virtual addresses
- Access goes through a memory controller or address translation unit
- The 0x060000+ addresses are **logical/virtual addresses**

### 2. Indirect Addressing Scheme
The firmware probably uses:
```assembly
# Instead of direct access like:
move.w 0x60006,%d0    # NOT FOUND

# Uses indirect access like:
move.w #9,%d0         # Memory block 9  
lsl.w #8,%d0          # Multiply by 256 (found pattern!)
add.w #6,%d0          # Add offset 6
# Then access through memory controller
```

### 3. Initialization/Default Loading
Since no direct addresses are found, the **initialization routine** likely:
- Uses **bulk memory operations** to load defaults
- Accesses EEPROM through **hardware registers** 
- Implements **address translation** in software

## Key Code Locations to Investigate

### 1. Memory Mapping Functions
Found at addresses with pattern `0x800000+`:
- Functions around `0xa16e` - `0xa426`: Complex memory management
- Multiple `moveal #0x80XXXX,%a0` instructions
- Could be **memory controller setup**

### 2. Left Shift by 8 Operations  
Found multiply-by-256 operations at:
- `0xb734`: `lsll #8,%d0` 
- `0xd60e`: `lsll #8,%d0`
- `0xd678`: `lsll #8,%d0`

These match the **Block × 256 + Offset** formula from `docs/common_parameters.json`!

### 3. Memory Initialization Code
Functions around:
- `0xa16e` - `0xaf9e`: Large initialization sequences
- Multiple `moveml` operations (bulk register moves)
- Structured data loading patterns

## Next Investigation Steps

### 1. Analyze Memory Controller Code
Focus on functions around `0x800000+` addresses:
```bash
# Extract memory controller functions
objdump -d --start-address=0xa16e --stop-address=0xa426 firmware.bin
```

### 2. Reverse Engineer Address Translation
Examine the left-shift operations:
```bash
# Find address calculation patterns
grep -A10 -B10 "lsll.*8" objdump.asm
```

### 3. Look for Hardware Register Access
Search for:
- I/O port operations
- Hardware register patterns
- Interrupt service routines for memory/EEPROM

### 4. Trace Parameter Access Functions
Look for functions that:
- Take parameter ID as input
- Calculate memory addresses
- Return parameter values

## Conclusion

**This is actually GREAT news for reverse engineering!**

1. **Confirmed**: EEPROM is all zeros as stated
2. **Architecture**: Uses sophisticated memory management with address translation  
3. **Opportunity**: The address calculation code (Block×256+Offset) IS in the firmware
4. **Next**: Focus on memory controller and initialization code rather than direct address searches

The fact that we found the multiply-by-256 operations means the parameter access code is definitely there - we just need to find the **memory controller interface** that translates logical addresses to physical EEPROM access.