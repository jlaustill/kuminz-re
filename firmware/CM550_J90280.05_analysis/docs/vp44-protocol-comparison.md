# VP44 CAN Message Observations

**RAW DATA FROM POWER-ON SEQUENCE ONLY**

---

## **Observed Messages During Power-On**

From SavvyCAN capture during VP44 power-on sequence:

### **Messages Present**
- **0x112**: VP44 → ECU (confirmed direction from assembly analysis)
- **0x512**: VP44 → ECU (confirmed direction from assembly analysis)  
- **0x712**: Direction unknown
- **0x100**: Direction unknown
- **0x500**: Direction unknown
- **0x700**: Direction unknown

### **Messages NOT Observed**
- No other CAN IDs detected during power-on sequence

---

## **Message Data Patterns (RAW ONLY)**

### **0x112 Messages**
```
0C 48 00 00 00 00 30 13  (startup)
0C 40 00 00 00 00 30 13  (repeating)
0C 00 00 00 00 00 30 13  (steady state)
0C 00 00 00 00 00 34 13  (temperature change)
```
**Confirmed**: Bytes 6-7 = temperature data (Kelvin × 16)

### **0x512 Messages**  
```
00 00 00 00 00 00 A8 02  (most common)
00 00 00 00 00 00 AC 02  (alternating)
00 00 00 00 00 00 6C 02  (single occurrence)
```
**Pattern**: Only bytes 6-7 vary, rest are zeros

### **0x712 Messages**
```
00 00 00 00 00 00 00 00  (all zero during power-on)
```

### **0x100 Messages**
```
00 00 00 00 AA 01 00 00  (constant pattern)
```

### **0x500 Messages**
```
F8 02 00 00 16 01 42 01  (constant pattern)
```

### **0x700 Messages**
```
AB FC 00 00 00 00 00 00  (single occurrence)
```

---

## **Assembly Analysis Results**

### **Confirmed Handlers**
- **0x712**: Handler at 0x936, 0x0c47, 0x0c6a (ISR and processing)
- **0x512**: Reception handler at 0x3624 (receives on 0x4A8 due to DG0101CB)
- **0x112**: Processing at 0x6b33, 0x8e23, 0x983b

### **Missing Handlers**
- **0x100, 0x500, 0x700, 0x0**: No confirmed assembly handlers located yet

---

## **Gaps in Data**

1. **Engine-running data missing**: Only power-on/bench data available
2. **Message directions unclear**: Except for 0x112 and 0x512 (confirmed from assembly)
3. **Handler verification needed**: For 0x100, 0x500, 0x700 messages
4. **Dynamic content unknown**: All data is from static power-on state

---

## **Next Required Data**

1. **Engine running capture**: To see dynamic message content
2. **Throttle input capture**: To identify command messages
3. **Assembly analysis**: For missing message handlers
4. **DG parameter verification**: To confirm message ID mappings

**NO SPECULATION ABOUT PROTOCOL DIFFERENCES OR COMPATIBILITY**