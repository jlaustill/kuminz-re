# CM848 ECU Pinout

Sources are labeled by model year. Verify before assuming identical between years —
Cummins revised connector assignments between the 2003–2007 5.9L applications.

2004 column key:  ✓ = identical to 2005 | — = absent in 2004 | ≠ = different (see notes below)

## C1 — 60-Way Connector

| Pin | Circuit | Wire                   | Function                             | 2005 | 2004 |
|-----|---------|------------------------|--------------------------------------|------|------|
| 1   | K139    | 18db                   | Wastegate Solenoid Control           | ✓    | —    |
| 2   | —       | —                      | —                                    |      |      |
| 3   | —       | —                      | —                                    |      |      |
| 4   | D72     | 18wt/lb                | CCD Bus (+)                          | ✓    | ✓    |
| 5   | D71     | 18wt/db                | CCD Bus (−)                          | ✓    | ✓    |
| 6   | K65     | 18br/lb                | Fuel Pump Relay Return               | ✓    | ✓    |
| 7   | K20     | 18br/gy                | Generator Field Control              | ✓    | ✓    |
| 8   | K314    | 18tn/yl                | (A/T) TTVA Motor (+)                 | ✓    | —    |
| 9   | —       | —                      | —                                    |      |      |
| 10  | —       | —                      | —                                    |      |      |
| 11  | K2      | 18tn/bk(A/T)vt/or(M/T) | ECT Signal                           | ✓    | ✓    |
| 12  | K181    | 18br/yl                | Fuel Rail Sensor Signal              | ✓    | ✓    |
| 13  | —       | —                      | —                                    |      |      |
| 14  | —       | —                      | —                                    |      | ≠    |
| 15  | K21     | 18db/lg                | Intake Air Temperature Sensor Signal | ✓    | ✓    |
| 16  | —       | —                      | —                                    |      | ≠    |
| 17  | —       | —                      | —                                    |      |      |
| 18  | —       | —                      | —                                    |      |      |
| 19  | K31     | 18br                   | Fuel Pump Relay Control              | ✓    | ✓    |
| 20  | K315    | 18tn/or                | (A/T) TTVA Motor (−)                 | ✓    | —    |
| 21  | —       | —                      | —                                    |      |      |
| 22  | K24     | 18lb/br                | CKP Signal                           | ✓    | ✓    |
| 23  | K914    | 18rd/wt                | Sensor Ground                        | ✓    | ✓    |
| 24  | K44     | 18db/gy                | CMP Signal                           | ✓    | ✓    |
| 25  | K668    | 18lg                   | 5 Volt Supply                        | ✓    | ≠    |
| 26  | C918    | 18bk/lb                | A/C Pressure Signal                  | ✓    | ✓    |
| 27  | K853    | 18db/br                | 5 Volt Supply                        | ✓    | ✓    |
| 28  | K29     | 18wt/br                | APPS No. 2 Signal                    | ✓    | —    |
| 29  | K690    | 18dg/yl                | Sensor Ground                        | ✓    | ≠    |
| 30  | K11     | 16wt/db                | Injector Control No. 1               | ✓    | ✓    |
| 31  | G123    | 18vt/lg                | Water in Fuel Sensor Signal          | ✓    | ✓    |
| 32  | K916    | 18br/or                | Sensor Ground                        | ✓    | ✓    |
| 33  | K167    | 18br/yl                | APPS No. 1 Return                    | ✓    | ≠    |
| 34  | —       | —                      | —                                    |      | ≠    |
| 35  | K312    | 18or                   | (A/T) TTVA Position Sensor Signal    | ✓    | —    |
| 36  | K14     | 16br/tn                | Injector Control No. 4               | ✓    | ✓    |
| 37  | —       | —                      | —                                    |      |      |
| 38  | —       | —                      | —                                    |      |      |
| 39  | —       | —                      | —                                    |      |      |
| 40  | K13     | 16tn                   | Injector Control No. 3               | ✓    | ✓    |
| 41  | —       | —                      | —                                    |      |      |
| 42  | K852    | 18br/vt                | 5 Volt Supply                        | ✓    | ≠    |
| 43  | K37     | 18lb                   | Boost Pressure Sensor Signal         | ✓    | ✓    |
| 44  | —       | —                      | —                                    |      | ≠    |
| 45  | —       | —                      | —                                    |      | ≠    |
| 46  | K58     | 16br/vt                | Injector Control No. 6               | ✓    | ✓    |
| 47  | —       | —                      | —                                    |      |      |
| 48  | —       | —                      | —                                    |      |      |
| 49  | —       | —                      | —                                    |      |      |
| 50  | K12     | 16br/db                | Injector Control No. 2               | ✓    | ✓    |
| 51  | —       | —                      | —                                    |      |      |
| 52  | K975    | 18br/or                | Sensor Ground                        | ✓    | ≠    |
| 53  | K915    | 18vt/rd                | Fuel Rail Sensor Return              | ✓    | ✓    |
| 54  | F855    | 18pk/yl                | 5 Volt Supply                        | ✓    | ✓    |
| 55  | —       | —                      | —                                    |      |      |
| 56  | K38     | 16gy                   | Injector Control No. 5               | ✓    | ✓    |
| 57  | K229    | 16tn/pk                | Injector High Side Driver — Bank 2   | ✓    | ✓    |
| 58  | —       | —                      | —                                    |      |      |
| 59  | K227    | 16br/lg                | Injector High Side Driver — Bank 1   | ✓    | ✓    |
| 60  | —       | —                      | —                                    |      |      |

## C2 — 50-Way Connector

| Pin | Circuit | Wire    | Function                                       | 2005 | Notes                                                           | 2004 |
|-----|---------|---------|------------------------------------------------|------|-----------------------------------------------------------------|------|
| 1   | —       | —       | —                                              |      |                                                                 |      |
| 2   | —       | —       | —                                              |      |                                                                 |      |
| 3   | K615    | 18vt/wt | Inlet Air Temperature Sense                    | ✓    | **Suspected oil temp input (MPC555 AN1); unconnected on Dodge** | ≠    |
| 4   | —       | —       | —                                              |      |                                                                 | ≠    |
| 5   | K176    | 18br/or | Intake Air Heater No. 2 Relay Control          | ✓    |                                                                 | ✓    |
| 6   | K174    | 18br/yl | Intake Air Heater No. 1 Relay Control          | ✓    |                                                                 | ✓    |
| 7   | K31     | 18br    | Fuel Pump Relay Control                        | ✓    |                                                                 | ≠    |
| 8   | —       | —       | —                                              |      |                                                                 |      |
| 9   | T41     | 18yl/db | (A/T) Park/Neutral Position Switch Sense       | ✓    |                                                                 | ✓    |
| 10  | K161    | 18br/lb | Fan Speed Sensor                               | ✓    |                                                                 | ✓    |
| 11  | B22     | 18dg/yl | Vehicle Speed Signal No. 1                     | ✓    |                                                                 | ✓    |
| 12  | G6      | 18vt/gy | Oil Pressure Signal                            | ✓    |                                                                 | ✓    |
| 13  | T6      | 18dg    | (A/T) Tow/Haul Overdrive Off Switch Sense      | ✓    |                                                                 | ✓    |
| 14  | T118    | 18dg    | (A/T) Governor Pressure Solenoid Control       | ✓    |                                                                 | ✓    |
| 15  | T9      | 18dg/tn | (A/T) 3-4 Solenoid Control                     | ✓    |                                                                 | ✓    |
| 16  | D21     | 18wt/br | SCI Transmit (ECM)                             | ✓    |                                                                 | ≠    |
| 17  | —       | —       | —                                              |      |                                                                 |      |
| 18  | T38     | 18yl/br | (A/T) Governor Pressure Sensor Signal          | ✓    |                                                                 | ✓    |
| 19  | D20     | 18wt/lg | SCI Receive (ECM)                              | ✓    |                                                                 | ✓    |
| 20  | A209    | 16rd    | Fused B(+)                                     | ✓    |                                                                 | ✓    |
| 21  | Z902    | 16bk    | Ground                                         | ✓    |                                                                 | ✓    |
| 22  | —       | —       | —                                              |      |                                                                 |      |
| 23  | F856    | 18yl/pk | (A/T) 5 Volt Supply                            | ✓    |                                                                 | ✓    |
| 24  | K900    | 18db/dg | Sensor Ground                                  | ✓    | **Ground for C2-3 oil temp sensor**                             | ✓    |
| 25  | T75     | 18yl/lb | (A/T) Torque Converter Clutch Solenoid Control | ✓    |                                                                 | ✓    |
| 26  | N4      | 18db/wt | Fuel Level Sensor Signal                       | ✓    |                                                                 | ✓    |
| 27  | —       | —       | —                                              |      |                                                                 |      |
| 28  | D25     | 18wt/vt | PCI Bus                                        | ✓    |                                                                 | ✓    |
| 29  | T54     | 18dg/or | (A/T) Transmission Temperature Sensor Signal   | ✓    |                                                                 | ✓    |
| 30  | A209    | 16rd    | Fused B(+)                                     | ✓    |                                                                 | ✓    |
| 31  | T515    | 18yl/db | (A/T) Transmission Control Relay Control       | ✓    |                                                                 | ✓    |
| 32  | F202    | 18pk/gy | Fused Ignition Switch Output (Run-Start)       | ✓    |                                                                 | ✓    |
| 33  | K854    | 18vt/br | 5 Volt Supply                                  | ✓    |                                                                 | ≠    |
| 34  | —       | —       | —                                              |      |                                                                 | ≠    |
| 35  | K616    | 18br/yl | Inlet Air Pressure Sense                       | ✓    |                                                                 | ✓    |
| 36  | V32     | 18vt/yl | Brake Switch No. 2 Signal                      | ✓    |                                                                 | ≠    |
| 37  | B29     | 18dg/wt | Brake Switch No. 1 Signal                      | ✓    |                                                                 | ✓    |
| 38  | —       | —       | —                                              |      |                                                                 |      |
| 39  | —       | —       | —                                              |      |                                                                 |      |
| 40  | A209    | 16rd    | Fused B(+)                                     | ✓    |                                                                 | ✓    |
| 41  | C13     | 18lb/or | A/C Clutch Relay Control                       | ✓    |                                                                 | ✓    |
| 42  | —       | —       | —                                              |      |                                                                 |      |
| 43  | K160    | 18br/or | Fan Clutch Control                             | ✓    |                                                                 | ≠    |
| 44  | T14     | 18dg/br | (A/T) Output Speed Sensor Signal               | ✓    |                                                                 | ✓    |
| 45  | T13     | 18dg/vt | (A/T) Speed Sensor Ground                      | ✓    |                                                                 | ✓    |
| 46  | V37     | 18vt    | S/C Switch No. 1 Signal                        | ✓    |                                                                 | ✓    |
| 47  | K25     | 18db/vt | Battery Temperature Signal                     | ✓    |                                                                 | ✓    |
| 48  | K400    | 18br/vt | APPS No. 2 Return                              | ✓    |                                                                 | ✓    |
| 49  | Z902    | 16bk    | Ground                                         | ✓    |                                                                 | ✓    |
| 50  | Z902    | 16bk    | Ground                                         | ✓    |                                                                 | ✓    |

## Analysis Notes

### Oil Temperature Sensor (firmware-confirmed, hardware unverified)

From firmware reverse engineering of CM848 S90140.06:
- **Firmware has explicit sensor-present vs. fallback logic** in `oilTemp_sensorSource_select()`
- MPC555 QADC64A **CCW slot 9 = AN1** is read by `cm848_sensorChannel10_oilTempInit/Process`
- NTC thermistor curve: −40°C (ADC≈945) to +130°C (ADC≈15), valid range ADC 12–1002
- Fallback when no sensor: uses coolant-derived proxy (`protection_oilTemp_proxy`)
- **Best candidate: C2-3 (K615)** — passive NTC thermistor signal, uses C2-24 (K900) as sensor ground
- Cummins ISBe heavy-duty variants likely have this pin populated with a real oil temp sensor

To add oil temp monitoring: connect a standard Cummins NTC thermistor (same part as IAT/ECT)
between C2-3 (signal) and C2-24 (sensor ground). Verify MPC555 AN1 → C2-3 mapping against
hardware schematic before committing.

### Unconnected Pins (Dodge-specific gaps)

Pins shown as empty on 2005 Dodge 5.9L that may be active on other CM848 applications:
- C1-2, C1-3, C1-9, C1-10, C1-13, C1-14, C1-16, C1-17, C1-21, C1-34, C1-37–39, C1-41, C1-44–45, C1-47–49, C1-51, C1-55, C1-58, C1-60
- C2-1, C2-2, C2-4, C2-8, C2-17, C2-22, C2-27, C2-34, C2-38–39, C2-42

**Note:** Transmission type unknown — A/T-prefixed circuits (T9, T14, T38, T41, T54, T75, T118, T515) may or may not be connected depending on the specific vehicle.

### 2004 vs 2005 C1 Differences (from 8W-80 service manual)

Many 2004 entries have A/T and M/T variants on the same pin. Where noted, A/T = automatic transmission, M/T = manual transmission.

| Pin | 2004 Circuit | 2004 Wire | 2004 Function | Notes |
|-----|-------------|-----------|---------------|-------|
| 1   | — | — | — | **Absent in 2004.** 2005: K139/Wastegate Solenoid Control |
| 8   | — | — | — | **Absent in 2004.** 2005: K314/(A/T) TTVA Motor (+) |
| 14  | K22 (A/T) / K23 (M/T) | 18br/wt (A/T) / 18db/wt (M/T) | TP Signal (A/T) / APPS No. 1 Signal (M/T) | **Populated in 2004, empty in 2005.** A/T uses ETC; M/T routes APPS No. 1 here |
| 16  | K29 (M/T only) | 18wt/br | APPS No. 2 Signal | **Populated in M/T 2004, empty in 2005.** M/T routes APPS No. 2 here instead of C1-28 |
| 20  | — | — | — | **Absent in 2004.** 2005: K315/(A/T) TTVA Motor (−) |
| 25  | K686 (M/T) | 18br | Supply Voltage | M/T uses K686 in 2004; A/T same K668. 2005 uses K668 for both |
| 28  | — | — | — | **Absent in 2004.** 2005: K29/APPS No. 2 Signal — moved to C1-16 (M/T) in 2004 |
| 29  | K690 (A/T) / K690 (M/T) | 18dg/yl (A/T) / 18br/yl (M/T) | Inlet Air Temp/Pressure Return | **Different function in 2004.** 2005 labels K690 as "Sensor Ground" |
| 33  | K922 (A/T) / K167 (M/T) | 18lg/or (A/T) / 18br/yl (M/T) | TTPS Return (A/T) / APPS No. 1 Return (M/T) | A/T uses K922 throttle position sensor return in 2004; M/T same as 2005 |
| 34  | K565 | 18or | Idle Switch | **Populated in 2004, empty in 2005** |
| 35  | — | — | — | **Absent in 2004.** 2005: K312/(A/T) TTVA Position Sensor Signal |
| 42  | K851 (A/T) / K852 (M/T) | 18vt/pk (A/T) / 18br/vt (M/T) | 5-Volt Supply | A/T uses K851 in 2004; M/T same K852 as 2005 |
| 44  | K556 | 18or/br | Not Idle Switch | **Populated in 2004, empty in 2005** |
| 45  | N2 | 18db/yl | Lift Pump Feed | **Populated in 2004, empty in 2005** |
| 52  | K975 (A/T) / K975 (M/T) | 18br/bk (A/T) / 18br/or (M/T) | Sensor Ground | A/T wire color differs: 18br/bk vs 18br/or in 2005 |

### 2004 vs 2005 C2 Differences (from 8W-80 service manual)

| Pin | 2004 Circuit | 2004 Wire | 2004 Function | Notes |
|-----|-------------|-----------|---------------|-------|
| 3   | K615 (M/T) | 18br/wt | Inlet Air Temperature Sense | M/T wire color differs: 18br/wt vs 18vt/wt in 2005 |
| 4   | V35 (A/T) | 18vt/or | S/C Vent Control | **Populated A/T 2004, empty in 2005** |
| 7   | V32 (A/T) | 18vt/yl | Speed Control Supply | **Different circuit in A/T 2004.** 2005: K31/Fuel Pump Relay Control |
| 16  | D21 (M/T) | 18pk | SCI Transmit | M/T wire differs: 18pk vs 18wt/br in 2005 |
| 33  | K854 (M/T only) | 18vt/br | 5 Volt Supply | A/T pin 33 appears unused in 2004; M/T same as 2005 |
| 34  | V36 (A/T) | 18vt/yl | S/C Vacuum Control | **Populated A/T 2004, empty in 2005** |
| 36  | V32 | 18vt/yl | Speed Control Supply | **Different function label in 2004.** Same circuit V32/18vt/yl but 2005 calls it "Brake Switch No. 2 Signal" |
| 43  | K160 | 18br/or | Park Lockout Solenoid Control | **Different function in 2004.** 2005: "Fan Clutch Control" — same K160 circuit |
