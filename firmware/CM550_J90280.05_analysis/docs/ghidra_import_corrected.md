# Ghidra Import - CORRECTED Settings

## 🔧 **Correct Import Settings**

### **Architecture Selection**
In Ghidra's language selection, choose:
- **Language**: `68000:BE:32:default` (68000 Big-Endian **32-bit**)
- **NOT** `68000:BE:16:default` (this doesn't exist)

The CM550 ECU uses a 32-bit Motorola 68000-series processor, even though it may process 16-bit data.

---

## 📋 **Corrected Import Steps**

### **Method 1: Intel HEX Import (Recommended)**

1. **File → Import File**
2. **Select**: `firmware/J90280.05`
3. **Format**: Intel Hex
4. **Language**: `68000:BE:32:default`
5. **Options**:
   - ✅ Create Block For Each Address Range
   - ✅ Include Non-Loaded Address Ranges
   - Base Address: `0x00000000`

### **Method 2: Binary Import (Alternative)**

1. **Use the full binary**: `firmware/J90280.05.full.bin`
2. **Format**: Raw Binary
3. **Language**: `68000:BE:32:default`
4. **Base Address**: `0x00000000`
5. **Block Name**: `MAIN`
6. **Length**: Use file size (262144 bytes)

---

## 🎯 **VP44 Function Verification**

After import, navigate to these addresses to verify:

| Address | Expected Assembly | Status |
|---------|-------------------|---------|
| `0x00006b33` | Should see data/code | Create function manually |
| `0x00008e23` | Should see valid code | ✅ Should work |
| `0x0000983b` | Should see valid code | ✅ Should work |

---

## 🛠 **Post-Import Actions**

### **1. Check Memory Map**
`Window → Memory Map` - Verify blocks are loaded correctly

### **2. Create Missing Functions**
For addresses in memory gaps:
```
1. Navigate to address (G key)
2. Press 'D' to disassemble if needed
3. Press 'F' to create function
4. Press 'L' to rename function
```

### **3. Apply VP44 Names**
- `0x6b33` → `fuel_temp_processor`
- `0x8e23` → `fuel_temp_calc`
- `0x983b` → `fuel_temp_bit_ops`

### **4. Run Auto-Analysis**
`Analysis → Auto Analyze` (select all analyzers)

---

## 🔍 **Architecture Notes**

### **Why 32-bit?**
- Motorola 68000 family processors are 32-bit internally
- They can process 16-bit and 8-bit data efficiently
- Address space is 32-bit (24-bit external addressing)
- Ghidra's 68000 support is designed for 32-bit mode

### **Data Processing**
- The fuel temperature data is still 16-bit values
- Assembly instructions like `move.w` operate on 16-bit words
- But the processor architecture itself is 32-bit

---

## ✅ **Working Solution**

Use objdump for complete firmware analysis:

```bash
# Use the proven working2 method
./scripts/objdump_dump.sh
```

This generates complete, accurate disassembly with real VP44 function addresses.

---

## 🎯 **Summary**

**Correct Ghidra Settings:**
- **Language**: `68000:BE:32:default` ✅
- **Base Address**: `0x00000000` ✅
- **Format**: Intel HEX or Raw Binary ✅

This should resolve the import issue and allow you to successfully analyze the CM550 firmware with proper memory address mapping!