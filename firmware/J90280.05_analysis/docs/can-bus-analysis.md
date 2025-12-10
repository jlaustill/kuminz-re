# CM550 CAN Bus Analysis - VP44 Pump Communication

**CORRECTED ANALYSIS** - VP44 pump is controlled via CAN bus messages, not direct electrical control.

## Key Findings from Calterm Documentation

### 🎯 **VP44 Pump System Confirmed**
The documentation clearly shows this is a **VP44 high pressure injection pump** system:
- **Config path**: `CM550 VP44\64c6.e2m` (in header)
- **VP44 parameters**: `VPGVWDEN`, `EPFLTPDF`, `EPFTFG`
- **VP44 communication**: CAN Hi/Lo (pins 13/4) + shield (pin 3)

### 🔌 **VP44 Physical Connections**
Based on user correction, VP44 connections are:
- **Pin 3**: CAN shield
- **Pin 4**: CAN Lo  
- **Pin 6**: Pump disable (electrical)
- **Pin 7**: Engine position reference (electrical)
- **Pin 13**: CAN Hi
- **Pin 16**: Low idle select (electrical)

---

## **J1939 CAN Bus Configuration**

### **Primary ECM Addresses**
| Parameter | Value | Description |
|-----------|-------|-------------|
| **JCDFEGSA** | 0 | Default J1939 network address for ECM as ENGINE node |
| **JCDFRDSA** | 41 | Default J1939 network address for ECM as RETARDER node |

### **Device Source Addresses**
| Parameter | Value | Description |
|-----------|-------|-------------|
| **JCSA1** | 3 | J1939 source address for device 1 |
| **JCSA2** | 11 | J1939 source address for device 2 |
| **JCSA3** | 33 | J1939 source address for device 3 |
| **JCTRSA** | 3 | Transmission source address |

### **CAN Bus Settings**
| Parameter | Value | Description |
|-----------|-------|-------------|
| **JCCNEXMK** | 0x1FFFF800 | CAN extended mask for message filtering |
| **SSC1B0RG** | 1 | CAN 1 bit timing register 0 |
| **SSC1B1RG** | 28 | CAN 1 bit timing register 1 |
| **SSC1CGRG** | 74 | CAN 1 bus configuration register |

---

## **J1939 Message Priorities (Key for VP44 Communication)**

### **Engine Control Messages**
| Message | Priority | PGN | Description |
|---------|----------|-----|-------------|
| **EEC1** | 3 | F004 | Engine control #1 (fuel/timing demands) |
| **EEC2** | 3 | F003 | Engine control #2 (additional parameters) |
| **EEC3** | 6 | FEDF | Engine control #3 (diagnostic data) |

### **Engine Status Messages**
| Message | Priority | PGN | Description |
|---------|----------|-----|-------------|
| **Engine Temperature** | 6 | FEEE | Engine temperature parameters |
| **Engine Fluid** | 6 | FEFC | Engine fluid levels/pressures |
| **Engine Configuration** | 6 | FEEB | Engine configuration data |
| **Engine Hours** | 6 | FEE5 | Engine operating hours |

### **Fuel System Messages**
| Message | Priority | PGN | Description |
|---------|----------|-----|-------------|
| **Fuel Consumption** | 6 | FEE9 | Fuel consumption data |
| **Inlet/Exhaust** | 6 | FEF5 | Inlet/exhaust conditions |

---

## **VP44 Pump Command Analysis**

### **Fuel and Timing Demand Parameters**
| Parameter | Units | Description |
|-----------|-------|-------------|
| **FSMNFL** | MM3S | Minimum fueling value (0-100 mm³/s) |
| **FSMXFL** | MM3S | Maximum fueling value (0-100 mm³/s) |
| **TSMXTA** | DADV | Maximum timing advance (0-120 degrees) |
| **CWTAGN** | - | Conversion factor from core timing to position ATDC |
| **CWTAOF** | DEG | Offset for retarded timing commands (-120 to 120°) |

### **Pump Control Timing**
| Parameter | Value | Description |
|-----------|-------|-------------|
| **CWPUCODC** | - | Min time between pump commands (0-10 MSEC) |
| **CWPUCOTM** | 29.99982 | Angular duration to hold pump valve closed |
| **CWPUSEPI** | 1178.01559 | Tooth advance needed to change pump command |

---

## **🎯 Critical VP44 CAN Communication**

### **How VP44 Receives Commands**
1. **ECM calculates fuel demand** based on throttle, load, RPM
2. **ECM calculates timing advance** based on Mode 0 cam sensor input
3. **Commands sent via J1939 CAN** (likely EEC1/EEC2 messages)
4. **VP44 receives CAN messages** with fuel quantity and timing demands
5. **Engine position reference** (pin 7) provides synchronization timing

### **Key Message Flow**
```
Mode 0 Timing → Fuel/Timing Calculation → J1939 CAN Messages → VP44 Pump
     ↑                                                            ↓
60-2 Cam Sensor ← Engine Position Reference (Pin 7) ←───────────┘
```

### **VP44 Control Integration**
- **CAN messages**: Fuel quantity and timing advance demands
- **Position reference**: Synchronization signal for injection timing
- **Status feedback**: VP44 reports status back via CAN
- **Engine protection**: Pump disable via pin 6 for safety

---

## **🔍 Likely CAN Message IDs for VP44**

Based on J1939 standards and priorities found:

### **Primary Control Messages**
- **EEC1 (PGN F004)**: Engine speed, torque, fuel quantity
- **EEC2 (PGN F003)**: Timing advance, governor information  
- **Custom VP44 PGN**: Specific fuel injection parameters

### **Status Messages**
- **Engine diagnostic status** from ECM address 0
- **Fuel system status** and fault codes
- **VP44 response messages** with pump status

---

## **🎯 Impact on Your 60-2 Cam Sensor Project**

### **Excellent News for Your Setup**
1. **Mode 0 timing** feeds directly into CAN message generation
2. **Your 60-2 cam sensor** provides timing reference for message content
3. **VP44 gets precise timing demands** via CAN messages
4. **Engine position reference** (pin 7) synchronizes injection events

### **Integration Points**
- **Mode 0 timing calculations** → **CAN message fuel/timing values**
- **60-2 cam sensor** → **Engine position reference** → **VP44 timing sync**
- **Parameter changes we identified** → **Affects CAN message content**

The VP44 pump **receives its fuel and timing demands via CAN bus messages**, perfectly integrating with your Mode 0 timing method and 60-2 cam sensor configuration! 🎯