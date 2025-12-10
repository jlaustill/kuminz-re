# VP44 Bus Protocol Analysis Status

**FACTS ONLY - NO ASSUMPTIONS**

---

## **Confirmed Findings from Assembly Analysis**

### **0x712 - Fault Control Message**
**DG Parameter**: DG0112CB = 1810 (0x712) - CONFIRMED in parameter table  
**Assembly handlers**: 
- `cm550_binary.bin:0x936` - CAN message detection ISR
- `cm550_binary.bin:0x0c47` - Fault control bit parsing  
- `cm550_binary.bin:0x0c6a` - Fault storage operations

**Memory locations**:
- 0x809a34, 0x809a32 - Fault accumulator registers
- 0x805df2 - CAN controller status register

**Bit operations confirmed**:
- 0x21 mask (bits 0,5) for fault control extraction
- 0x40 mask (bit 6) for CAN RX buffer check

### **0x512 Reception Handler** 
**DG Parameter**: DG0101CB = 1192 (0x4A8) - CONFIRMED  
**Assembly handler**: `cm550_binary.bin:0x3624` - CAN interrupt handler  
**Key discovery**: VP44 transmits 0x512, CM550 receives on 0x4A8

**Memory locations**:
- 0x805e14, 0x805e54 - CAN controller registers
- 0x8034a8 - Message reception status flag

### **0x112 Temperature Data**
**Assembly evidence**: Data processing at `cm550_binary.bin:0x6b33`, `0x8e23`, `0x983b`  
**Temperature confirmed**: Bytes 6-7 = Kelvin × 16 (validated against warm pump)  
**Power-on log pattern**: `0C XX 00 00 00 00 YY ZZ` where YY ZZ = temperature

---

## **Gaps Requiring Further Analysis**

### **Missing Message IDs**:
- 0x100, 0x500, 0x700, 0x0 - No confirmed assembly handlers found
- Need to locate actual CM550 message IDs for fuel/timing commands

### **Unknown Message Structures**:
- 0x500 message data: `F8 02 00 00 16 01 42 01` - purpose unknown
- 0x100 message data: `00 00 00 00 AA 01 00 00` - purpose unknown  
- 0x700 message data: `AB FC 00 00 00 00 00 00` - purpose unknown

### **Parameter Verification Needed**:
- DG0100CB, DG0105CB, DG0107CB - Parameters exist but handlers not confirmed
- Need assembly analysis to verify which messages these control

---

## **Power-On Sequence (CONFIRMED DATA)**

From actual SavvyCAN capture:
```
0x112: 0C 48 00 00 00 00 30 13  (VP44 → ECU, fuel temp ~34°C)
0x712: 00 00 00 00 00 00 00 00  (Direction unknown)
0x100: 00 00 00 00 AA 01 00 00  (Direction unknown) 
0x500: F8 02 00 00 16 01 42 01  (Direction unknown)
0x700: AB FC 00 00 00 00 00 00  (Direction unknown)
0x512: 00 00 00 00 00 00 A8 02  (VP44 → ECU, alternating byte 6)
```

---

## **Next Steps (NO ASSUMPTIONS)**

1. **Search for 0x100, 0x500, 0x700, 0x0 handlers** in assembly code
2. **Verify DG parameter to handler mapping** through cross-reference analysis  
3. **Analyze message construction code** to understand data formatting
4. **Test with running engine** to gather additional message data

**NO CONFIDENCE ASSESSMENTS - ONLY FACTS CONFIRMED THROUGH ASSEMBLY ANALYSIS**