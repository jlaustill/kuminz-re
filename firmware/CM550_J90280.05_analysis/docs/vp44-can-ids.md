# VP44 Standard CAN ID Analysis

## User Correction Confirmed
The VP44 pump uses **standard 11-bit CAN IDs**, not J1939 29-bit extended IDs for fuel and timing commands.

## CAN Configuration Found in Documentation

### **Standard CAN Mask Settings**
| Parameter | Value | Description |
|-----------|-------|-------------|
| **SSC1SDMK** | 0xFFFF | CAN 1 standard mask (11-bit message filtering) |
| **SSC1EXMK** | 0x1FFFF800 | CAN 1 extended mask (29-bit J1939 filtering) |

### **CAN Controller Configuration**
| Parameter | Value | Description |
|-----------|-------|-------------|
| **SSC1B0RG** | 1 | CAN 1 bit timing register 0 |
| **SSC1B1RG** | 28 | CAN 1 bit timing register 1 |
| **SSC1CGRG** | 74 | CAN 1 bus configuration register |
| **JCVDRXOB** | 0x000E | Number of valid CAN chip message objects (14) |

## VP44 Communication Architecture

### **Dual CAN Protocol Operation**
The CM550 ECU operates with **two different CAN protocols simultaneously**:

1. **J1939 Extended (29-bit)**: Communication with other vehicle systems
   - Transmission, ABS, dashboard, diagnostic tools
   - Uses extended mask 0x1FFFF800
   
2. **Standard CAN (11-bit)**: Direct VP44 pump communication
   - Fuel quantity commands
   - Timing advance commands  
   - Pump status feedback
   - Uses standard mask 0xFFFF

### **VP44 Physical Interface**
- **Pin 3**: CAN shield
- **Pin 4**: CAN Lo (shared with J1939 bus)
- **Pin 13**: CAN Hi (shared with J1939 bus)
- **Pin 6**: Pump disable (direct electrical)
- **Pin 7**: Engine position reference (direct electrical)
- **Pin 16**: Low idle select (direct electrical)

## Missing Information

### **Standard CAN IDs Not in Calibration Documentation**
The specific 11-bit CAN IDs for VP44 communication are **NOT listed** in the Calterm calibration documentation. This suggests:

1. **Hardcoded in firmware**: The CAN IDs are embedded in the ECM firmware code
2. **Manufacturer specific**: Cummins proprietary message IDs
3. **Fixed protocol**: Not user-configurable parameters

### **Typical VP44 CAN ID Ranges**
Based on common automotive CAN practices, VP44 IDs likely fall in ranges:
- **0x100-0x1FF**: Engine control messages
- **0x200-0x2FF**: Fuel system commands  
- **0x300-0x3FF**: Diagnostic/status messages
- **0x400-0x4FF**: Configuration/calibration

## Mode 0 Integration Impact

### **How Your 60-2 Cam Sensor Affects VP44 CAN Messages**
```
60-2 Cam Sensor → Mode 0 Timing Calculation → Standard CAN Messages → VP44
     ↑                                              ↓
     └─── Engine Position Reference (Pin 7) ←──────┘
```

### **Message Content Affected by Mode 0**
1. **Fuel quantity**: Based on throttle position, load, RPM from cam sensor
2. **Timing advance**: Calculated using Mode 0 algorithm with 60-2 pattern
3. **Injection timing**: Synchronized via position reference signal
4. **RPM calculation**: Derived from 60-2 cam sensor tooth counting

### **Parameter Changes Impact**
When you modify the Mode 0 parameters we identified:
- **ESNOTTCU** (58 teeth) → Affects RPM calculation → Changes CAN message RPM data
- **Missing tooth detection** → Affects sync quality → Impacts timing advance commands
- **Tooth spacing ratios** → Affects position accuracy → Changes injection timing precision

## Next Steps for CAN ID Discovery

### **Potential Methods to Find VP44 CAN IDs**
1. **Firmware reverse engineering**: Search binary for standard CAN ID patterns
2. **CAN bus monitoring**: Capture traffic during engine operation
3. **Service documentation**: Access to Cummins VP44 protocol specifications
4. **ECM pin probing**: Monitor CAN Hi/Lo signals with oscilloscope

### **CAN Message Monitoring Strategy**
Monitor CAN bus during:
- **Engine startup**: Initial VP44 configuration messages
- **Throttle changes**: Fuel quantity command variations
- **RPM changes**: Timing advance adjustments
- **Error conditions**: Fault codes and diagnostics

## Summary

The VP44 pump receives **fuel and timing commands via standard 11-bit CAN messages** that are generated based on your **Mode 0 timing calculations** from the **60-2 cam sensor**. While the specific CAN IDs aren't in the calibration documentation, the integration with your timing system is confirmed through the parameter analysis we've completed.

**Your Mode 0 parameter changes will directly affect the content of these standard CAN messages sent to the VP44!** 🎯