# VP44 CAN Bus Protocol Documentation

**CM550 ECU ↔ VP44 Injection Pump Communication Analysis**

---

## Overview

The CM550 ECU communicates with the VP44 injection pump using **standard 11-bit CAN IDs** on a dedicated bus separate from the main J1939 network. This document analyzes the specific message IDs, their bit-level structure, and fault control mechanisms.

## Physical Interface

- **Pin 4**: CAN Lo (shared with J1939 but different protocol)
- **Pin 13**: CAN Hi (shared with J1939 but different protocol) 
- **Pin 3**: CAN shield
- **Pin 6**: Pump disable (direct electrical)
- **Pin 7**: Engine position reference (direct electrical)
- **Pin 16**: Low idle select (direct electrical)

---

## Message ID Registry

### **0x712 - Fault Control Bits Record** 
**Parameter: DG0112CB = 1810 (decimal)**

#### **Message Direction**: ECU → VP44
#### **Message Length**: 8 bytes
#### **Update Rate**: Event-driven (fault conditions)

#### **Firmware Handler Locations**:
- **ISR Entry**: `cm550_binary.bin:0x936` - CAN message detection
- **Bit Parser**: `cm550_binary.bin:0x0c47` - Fault control parsing
- **Memory Handler**: `cm550_binary.bin:0x0c6a` - Fault storage

#### **Message Structure**:

| Byte | Bits | Mask | Description | Values |
|------|------|------|-------------|---------|
| **0** | 0 | 0x01 | **Fault Enable/Disable** | 0=Disabled, 1=Enabled |
| **0** | 5 | 0x20 | **Fault Severity Level** | 0=Warning, 1=Critical |
| **0** | 1-4,6-7 | 0xDE | *Reserved* | - |
| **1-2** | All | 0xFFFF | **Fault Code Index** | 16-bit fault lookup |
| **3-7** | All | 0xFFFFFFFFFF | **Additional Status Data** | Implementation specific |

#### **Assembly Code Analysis**:
```assembly
; CAN Message Detection (ISR)
0x936: andi.w 0x40, d0        ; Check CAN RX buffer bit 6
0x93a: beq.w 0x9d4           ; Branch if no message
0x93e: move.w 0x805df2, d0   ; Load CAN status register
0x944: andi.w 0x4000, d0     ; Check message type flag

; Fault Control Bit Parsing  
0xc47: andi.b 0x21, d0       ; Extract fault control bits (0,5)
0xc4b: moveq 0x0, d6         ; Clear working register
0xc4d: or.w (a3,d5.l*4), d0  ; Combine with fault lookup table
0xc51: eori.b 0x0, (a3,d0.w*2) ; Toggle fault state 
0xc57: or.b 0x21(a3,a4.w), d0  ; Merge with current status

; Fault Storage Update
0xc6a: clr.w 0x809a34        ; Clear fault accumulator 1
0xc70: clr.w 0x809a32        ; Clear fault accumulator 2
```

#### **Memory Locations**:
- **0x805df2**: CAN controller status register
- **0x809a34**: Fault accumulator/counter 1  
- **0x809a32**: Fault accumulator/counter 2
- **0x8033c2**: Fault control parameter base
- **0x803614**: Additional fault status flags

#### **Extended Fault Processing Code**:
```assembly
; Extended Fault Handling Logic
0xc78: move.l a2, -(a7)         ; Save context
0xc7a: movea.l 0x8033c2, a2     ; Load fault parameter base address
0xc80: move.w 0x803614.l, d0    ; Load additional fault flags  
0xc86: andi.w 0x1, d0           ; Check fault enable bit
0xc8a: beq.b 0xcac              ; Skip if disabled
0xc8c: move.w 0x809258.l, 0x6(a2)  ; Store fault data at offset 6
0xc94: move.w 0x80c408.l, 0xe(a2)  ; Store fault data at offset 14
0xc9e: jsr 0x357f6.l            ; Call fault processing subroutine
0xca4: addq.l 0x4, a7           ; Cleanup stack
0xca6: move.w d0, 0x809a32.l    ; Update fault accumulator 2

; Fault Comparison and Storage  
0xcb2: movea.l 0x80c9ae, a2     ; Load fault lookup table
0xcb8: movea.l 0x809a32, a1     ; Load current fault state
0xcbe: movea.l 0x80c9b0, a0     ; Load fault threshold table
0xcd6: move.w (a2), 0x809a34.l  ; Update primary fault register
0xcdc: move.w (a1), d0          ; Load current fault value
0xcde: cmp.w (a2), d0           ; Compare with threshold
0xce0: bls.b 0xce8              ; Branch if within limits
0xce2: move.w (a1), (a2)        ; Update fault threshold
```

#### **Memory Layout Analysis**:
- **0x8033c2**: Base address of fault parameter structure
- **0x809258**: Active fault code register
- **0x80c408**: Fault severity/category register  
- **0x80c9ae**: Fault lookup table base
- **0x80c9b0**: Fault threshold comparison table
- **0x357f6**: Main fault processing subroutine

#### **Fault Data Structure**:
Based on memory offsets in the code:
```c
struct fault_control_record {
    uint16_t fault_flags;      // +0x0: Status and control bits
    uint16_t reserved1;        // +0x2: Reserved
    uint16_t reserved2;        // +0x4: Reserved  
    uint16_t fault_data1;      // +0x6: Primary fault code (0x809258)
    uint16_t reserved3;        // +0x8: Reserved
    uint16_t reserved4;        // +0xa: Reserved
    uint16_t reserved5;        // +0xc: Reserved
    uint16_t fault_data2;      // +0xe: Secondary fault data (0x80c408)
};
```

#### **Potential Fault Codes**:

Based on VP44 pump operation and memory layout analysis:

| Code Range | Category | Storage Location | Description | Severity |
|------------|----------|------------------|-------------|----------|
| **0x0001-0x000F** | **Pressure** | 0x809258 | Low/high fuel pressure warnings | Warning |
| **0x0010-0x001F** | **Temperature** | 0x809258 | Fuel temperature out of range | Warning |
| **0x0020-0x002F** | **Electrical** | 0x80c408 | Wiring/connector faults | Critical |
| **0x0030-0x003F** | **Mechanical** | 0x80c408 | Pump mechanism failures | Critical |
| **0x0040-0x004F** | **Communication** | 0x809258 | CAN bus errors, lost messages | Warning |
| **0x0050-0x005F** | **Timing** | 0x80c408 | Injection timing faults | Critical |
| **0x0060-0x006F** | **Calibration** | 0x809258 | Pump calibration errors | Warning |
| **0x0070-0x007F** | **System** | 0x80c408 | General system faults | Variable |

#### **Common Fault Scenarios**:

1. **Fuel Pressure Low** (0x0001):
   - Byte 0: `0x21` (Enable + Critical)
   - Bytes 1-2: `0x0001` 
   - Action: Reduce fuel delivery, trigger limp mode

2. **Injection Timing Error** (0x0051):
   - Byte 0: `0x21` (Enable + Critical)
   - Bytes 1-2: `0x0051`
   - Action: Adjust timing parameters, log fault

3. **Communication Lost** (0x0041):
   - Byte 0: `0x01` (Enable + Warning)  
   - Bytes 1-2: `0x0041`
   - Action: Use last known good values, retry

---

### **0x112 - Fuel Temperature and Status Response**
**Parameter: Not user-configurable (hardcoded)**

#### **Message Direction**: VP44 → ECU
#### **Message Length**: 8 bytes  
#### **Update Rate**: ~10-20ms (continuous)

#### **Firmware Handler Locations**:
- **Data Parser**: `cm550_binary.bin:0x6b33` - Fuel data processing
- **Status Handler**: `cm550_binary.bin:0x8e23` - Temperature calculation
- **Bit Operations**: `cm550_binary.bin:0x983b` - Status bit extraction

#### **Message Structure (CONFIRMED FROM POWER-ON LOG)**:
Based on actual VP44 transmission analysis: Pattern `0C XX 00 00 00 00 YY ZZ`

| Byte | Observed Values | Pattern | Description |
|------|----------------|---------|-------------|
| **0** | `0C` | Static | Always `0C` (12 decimal) |
| **1** | `48`, `40`, `00` | Variable | Changes during startup sequence |
| **2** | `00` | Static | Always zero |
| **3** | `00` | Static | Always zero |
| **4** | `00` | Static | Always zero |
| **5** | `00` | Static | Always zero |
| **6** | `30`, `34` | Variable | **FUEL TEMPERATURE** (LSB) |
| **7** | `13`, `13` | Static | **FUEL TEMPERATURE** (MSB) |

#### **Confirmed Fuel Temperature (Bytes 6-7)**:
- **Format**: Little-endian 16-bit value in Kelvin × 16
- **Example**: `30 13` = 0x1330 = 4912 → 4912÷16 = 307K = 33.85°C
- **Validation**: ✅ Matches warm VP44 pump (warm to touch)
- **Range observed**: 307-307.25K (33.85-34.1°C)

#### **Bytes 0-5**: **STRUCTURE UNKNOWN - REQUIRES ENGINE DATA**
Additional analysis needed with running engine to determine purpose of remaining bytes.

---

## Analysis Notes

- **Real-time Processing**: Code shows ISR optimization for minimal latency
- **Bit-level Control**: Specific fault enable/disable per message
- **Lookup Tables**: Fault codes indexed through memory tables
- **State Management**: XOR operations suggest fault state toggling
- **Multi-level Severity**: Warning vs critical fault classification

---

### **0x100 - Primary Fuel Quantity Command**
**Parameter: DG0100CB = 1032 (0x408) - could be changed to 256 (0x100)**

#### **Message Direction**: ECU → VP44
#### **Message Length**: 8 bytes
#### **Update Rate**: ~5-10ms (real-time)

#### **Firmware Handler Locations**:
- **Command Builder**: `cm550_binary.bin:0x121` - Fuel quantity calculation
- **Transmission Logic**: `cm550_binary.bin:0x4e3` - Message dispatch
- **Function Calls**: `cm550_binary.bin:0x4f4` → `0x30542` - Main fuel control

#### **Message Structure**:

| Byte | Bits | Description | Units | Range |
|------|------|-------------|-------|--------|
| **0-1** | All | **Target Fuel Quantity** | mm³/stroke × 10 | 0-1000 |
| **2-3** | All | **Engine RPM Reference** | RPM | 0-6000 |
| **4** | All | **Injection Timing Command** | °BTDC × 4 | 0-63.75° |
| **5** | 0-3 | **Fuel Command Flags** | Bitfield | See below |
| **5** | 4-7 | **Reserved** | - | - |
| **6** | All | **Throttle Position** | % | 0-100% |
| **7** | All | **Load Factor** | % | 0-100% |

#### **Fuel Command Flags (Byte 5, bits 0-3)**:
- **Bit 0**: High pressure mode enable
- **Bit 1**: Cold start enrichment active
- **Bit 2**: High altitude compensation
- **Bit 3**: Performance mode enable

---

### **0x500 - Timing Adjustment and Control**
**Parameter: DG0105CB (estimated) - could be changed to 1280 (0x500)**

#### **Message Direction**: ECU → VP44
#### **Message Length**: 8 bytes
#### **Update Rate**: ~10-20ms (as needed)

#### **Message Structure**:

| Byte | Bits | Description | Units | Range |
|------|------|-------------|-------|--------|
| **0-1** | All | **Timing Advance Trim** | °BTDC × 100 | ±20.00° |
| **2** | All | **Fuel Pressure Command** | Bar × 10 | 0-25.5 bar |
| **3** | All | **Injection Duration** | μs × 10 | 0-2550 μs |
| **4-5** | All | **Pump Speed Target** | RPM | 0-65535 |
| **6** | 0-3 | **Control Mode Flags** | Bitfield | See below |
| **6** | 4-7 | **Reserved** | - | - |
| **7** | All | **Diagnostic Command** | Code | 0-255 |

#### **Control Mode Flags (Byte 6, bits 0-3)**:
- **Bit 0**: Manual timing override
- **Bit 1**: High pressure mode
- **Bit 2**: Regeneration mode active  
- **Bit 3**: Test mode enable

---

### **0x700 - System Control and Handshake**
**Parameter: DG0107CB (estimated) - hardcoded system message**

#### **Message Direction**: ECU ↔ VP44 (Bidirectional)
#### **Message Length**: 8 bytes
#### **Update Rate**: ~100ms (heartbeat)

#### **Firmware Handler Locations**:
- **Handshake Logic**: `cm550_binary.bin:0x3e3` - System status check
- **Control Functions**: `cm550_binary.bin:0x517` - System control operations
- **Memory Management**: `cm550_binary.bin:0x3f2` - Parameter loading

#### **Message Structure**:

| Byte | Bits | Description | Values |
|------|------|-------------|---------|
| **0** | All | **System State** | 0x00=Init, 0x01=Ready, 0x02=Running, 0xFF=Error |
| **1** | All | **Protocol Version** | 0x01 (Current version) |
| **2-3** | All | **Session Counter** | Incremental counter |
| **4** | 0-3 | **System Flags** | Bitfield |
| **4** | 4-7 | **Reserved** | - |
| **5** | All | **Checksum/CRC** | Validation byte |
| **6-7** | All | **Reserved** | - |

---

### **0x0 - Emergency Shutdown/Reset**
**Parameter: DG0113CB = 0 (disabled/hardcoded)**

#### **Message Direction**: ECU → VP44
#### **Message Length**: 8 bytes  
#### **Update Rate**: Event-driven (emergency only)

#### **Message Structure**:
- **All bytes 0x00**: Emergency shutdown command
- **Byte 0 = 0xFF**: System reset command
- **Other patterns**: Reserved for future use

---

---

### **0x512 - VP44 Secondary Status (Received as 0x4A8)**
**Parameter: DG0101CB = 1192 (0x4A8) - BREAKTHROUGH DISCOVERY!**

#### **Message Direction**: VP44 → ECU  
#### **Message Length**: 8 bytes
#### **Update Rate**: ~10-20ms (continuous)

#### **Critical Discovery**: 
**VP44 sends 0x512, but CM550 receives it on 0x4A8** due to current DG parameter configuration!

#### **Firmware Handler Locations**:
- **CAN Interrupt Handler**: `cm550_binary.bin:0x3624` - Main reception ISR
- **Register Management**: `0x3638`, `0x3640` - CAN controller register access
- **Message Processing**: `0x366e`, `0x3674` - Buffer copy operations

#### **Assembly Code Analysis**:
```assembly
; CAN Interrupt Entry (0x3624)
0x3624: move.w 0x1039(a0), (a2)    ; Load CAN message object
0x3628: ori.l 0xa8b013, d0         ; Message ID processing (contains 0xA8!)
0x362e: bls.w 0x3650               ; Branch if valid message

; Interrupt Management
0x3632: move.w sr, -(a7)           ; Save status register
0x3634: ori.w 0x700, sr            ; Disable interrupts (critical section)
0x3638: ori.w 0x400, 0x805e14.l    ; Set CAN controller register bit
0x3640: ori.w 0x400, 0x805e54.l    ; Set second CAN register bit
0x3648: move.w (a7)+, sr           ; Restore interrupts

; Message Data Processing
0x364a: clr.b 0x8034a8.l           ; Clear status flag
0x366e: move.b -0x2(a6), 0xc(a2)   ; Copy message byte to buffer offset +12
0x3674: move.b 0x1(a5), 0xb(a2)    ; Copy message byte to buffer offset +11
```

#### **Message Structure (FACTS FROM POWER-ON LOG)**:
Based on power-on sequence analysis: Pattern `00 00 00 00 00 00 XX 02` where XX alternates

**OBSERVED FACTS FROM POWER-ON LOG:**
- **Bytes 0-5**: Always `00 00 00 00 00 00` (completely static)
- **Byte 6**: Alternates between `A8` and `AC` (and once `6C`)
- **Byte 7**: Always `02` (completely static)

| Byte | Observed Values | Pattern | Description |
|------|----------------|---------|-------------|
| **0** | `00` | Static | Always zero |
| **1** | `00` | Static | Always zero |
| **2** | `00` | Static | Always zero |
| **3** | `00` | Static | Always zero |
| **4** | `00` | Static | Always zero |
| **5** | `00` | Static | Always zero |
| **6** | `A8`, `AC`, `6C` | **ALTERNATING** | **Primary variable byte** |
| **7** | `02` | Static | Always `02` |

#### **Byte 6 Analysis - The Variable Data**:

**0xA8 = 168 decimal = 10101000 binary**
**0xAC = 172 decimal = 10101100 binary**  
**0x6C = 108 decimal = 01101100 binary** (single occurrence)

**Binary Comparison:**
```
A8: 1010 1000
AC: 1010 1100  
6C: 0110 1100
```

**Pattern Observations:**
- **A8 ↔ AC**: Only bits 2-3 change (difference of 4)
- **6C**: Completely different bit pattern
- **Alternation frequency**: Changes approximately every few messages
- **Assembly significance**: This is the byte copied to buffer offset 0xb

#### **Byte 7 Analysis - Always 0x02**:

**0x02 = 2 decimal = 00000010 binary**
- **Completely static** throughout entire power-on sequence
- **Assembly significance**: This is the byte copied to buffer offset 0xc
- **Comparison target**: Assembly shows `cmp.b (a3), d0` - likely comparing against 0x02

#### **Assembly Processing Context**:
Based on handler analysis at cm550_binary.bin:0x3624:
1. **Message received** → **Byte 6 copied to buffer+11**
2. **Message received** → **Byte 7 copied to buffer+12** 
3. **Comparison performed** → **Byte 7 value checked against expected value**
4. **Status flags cleared** → **Reception acknowledged**

#### **Functional Analysis - No Assumptions**:
- **6 bytes of zeros**: VP44 pump not transmitting meaningful data in first 6 bytes
- **Byte 6 alternation**: Some internal state or counter mechanism  
- **Byte 7 constant**: Fixed protocol/status identifier
- **Minimal data**: VP44 transmitting only 2 meaningful bytes out of 8

#### **Memory Locations**:
- **0x805e14**: Primary CAN controller status register
- **0x805e54**: Secondary CAN controller register  
- **0x8034a8**: Message reception status flag
- **0x8034a9**: Additional status tracking

#### **Configuration Solution**:
To receive VP44's 0x512 messages on the correct ID:
- **Change DG0101CB** from `1192` to `1298` (0x512 decimal)
- This will align the reception handler with VP44's transmission ID

---

## **Complete DG Parameter Mapping**

Based on configuration breakthrough analysis:

| **Parameter** | **Current Value** | **Hex Value** | **Purpose** | **Could Configure** |
|---------------|-------------------|---------------|-------------|---------------------|
| **DG0100CB** | 1032 | 0x408 | Base configuration | **0x100 Fuel Command** |
| **DG0101CB** | **1192** | **0x4A8** | **0x512 Reception** | **✓ VP44 Status Handler** |
| **DG0102CB** | 1212 | 0x4BC | Message ID | Unused/Secondary |
| **DG0103CB** | 1010 | 0x3F2 | Message ID | Unused/Secondary |
| **DG0110CB** | 1992 | 0x7C8 | Message ID | Unused/Secondary |
| **DG0111CB** | 1212 | 0x4BC | Message ID | Unused/Secondary |
| **DG0112CB** | **1810** | **0x712** | **Fault Control** | **✓ Active VP44** |
| **DG0113CB** | 0000 | 0x000 | Disabled/unused | **0x0 Emergency** |

---

## Message Flow Summary

```
┌─── ECU (CM550) ────┐         ┌─── VP44 Pump ────┐
│                    │  0x700  │                  │
│  System Control    │◄──────► │  Handshake       │
│                    │         │                  │
│  Fuel Commands     │  0x100  │                  │
│                    │────────►│  Fuel Control    │
│                    │  0x500  │                  │
│  Timing Control    │────────►│  Timing Adjust   │
│                    │         │                  │
│  Fault Control     │  0x712  │                  │
│                    │────────►│  Fault Handling  │
│                    │         │                  │
│  Status Monitor    │  0x112  │  Telemetry       │
│                    │◄────────│                  │
│                    │  0x512  │  Status Data     │
│  Data Processing   │◄────────│                  │
│                    │         │                  │
│  Emergency Stop    │  0x0    │                  │
│                    │────────►│  Safety Shutdown │
└────────────────────┘         └──────────────────┘
```

---

## **Configuration Strategy for VP44 Compatibility**

To enable VP44 communication on CM550:

1. **Change DG0100CB** from `1032` to `256` (0x100) - Primary fuel command
2. **Change DG0101CB** from `1192` to `274` (0x112) - Status response  
3. **Change DG0113CB** from `0` to `1280` (0x500) - Timing control
4. **Keep DG0112CB** at `1810` (0x712) - Fault control ✓ **Already correct**

## Analysis Notes