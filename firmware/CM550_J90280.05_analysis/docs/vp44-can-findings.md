# VP44 CAN Search Results

**ASSEMBLY ANALYSIS ONLY - NO INTERPRETATION**

---

## **Memory Patterns Found in Firmware**

### **Pattern at 0x0423**
```
Raw bytes: 02 00 05 65 dc 33 fc 00
```
- Location: 0x0423 in cm550_binary.bin
- Context: Near other bit manipulation operations

### **Pattern at 0x0936** 
```
Raw bytes: 02 40 00 40
```
- Location: 0x0936 in cm550_binary.bin  
- Context: Found during CAN interrupt analysis (confirmed 0x712 handler)

### **Pattern at 0x0C47**
```
Raw bytes: 02 00 08 21 7c 00 80 73
```
- Location: 0x0C47 in cm550_binary.bin
- Context: Near fault control bit parsing code

---

## **Function Call Locations**

JSR (Jump to Subroutine) calls found to these addresses:
- 0x357E4 - Multiple references
- 0x357F6 - Multiple references  
- 0x35560 - Multiple references
- 0x356F8 - Multiple references

**Note**: Purpose of these functions unknown without further analysis.

---

## **Gaps in Analysis**

1. **No confirmed CAN ID patterns** - Raw bytes found but not verified as CAN IDs
2. **Function purposes unknown** - JSR targets need disassembly analysis
3. **Memory context unclear** - Need to analyze surrounding code
4. **No message construction found** - Haven't located actual CAN message building

---

## **Required Next Steps**

1. Disassemble each function at JSR target addresses
2. Analyze assembly context around each pattern  
3. Search for actual CAN controller register access
4. Find message buffer construction code

**NO ASSUMPTIONS ABOUT MESSAGE IDS OR PURPOSES**