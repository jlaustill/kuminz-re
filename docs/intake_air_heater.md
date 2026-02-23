# Intake Air Heater (IAH) System

This document describes the Intake Air Heater (IAH) system across Cummins ECU generations.
The IAH system controls the grid heater, preheat circuits, and related warning lights.

## Overview

The Intake Air Heater (IAH) system is Cummins' terminology for the grid heater system
used to warm intake air during cold starts. This system is present across multiple ECU
generations with varying levels of complexity.

### Terminology

| Term | Description |
|------|-------------|
| **Grid Heater** | Physical heating element in intake manifold |
| **IAH** | Intake Air Heater - Cummins' system name |
| **Glow Plug** | Cylinder-based preheat (NOT used in these ECUs) |
| **Preheat** | Heating phase before engine cranking |
| **Postheat** | Heating phase after engine starts |

---

## CM848 (S90140.06 - PowerPC MPC555)

### IAH Feature Status: HARDWARE PRESENT, STATE MACHINE STUB EMPTY

**The ECU hardware supports IAH** — ECU connector pins 5 and 6 drive IAH relay
1 and relay 2 respectively (confirmed by wiring diagram). However, the IAH state
machine code slot in the S90140.06 Bank 2 flash is empty.

**Hardware evidence:**
- ECU pin 5 = Intake Air Heater Relay No. 2 (confirmed by Dodge Ram wiring diagram)
- ECU pin 6 = Intake Air Heater Relay No. 1 (confirmed by Dodge Ram wiring diagram)
- E2M parameters define `Cold_Start_Aid_1_Driver_Map` (0x01157956) and
  `Cold_Start_Aid_2_Driver_Map` (0x01157958) — hardware resource assignments
  for the relay output channels
- E2M alias: `Cold_Start_Aid_1_Driver` = `Fuel_Heater_Driver` (same virtual
  address 0x01157705) — "Cold Start Aid" is Cummins' alternate name for IAH

**Firmware evidence (empty stub):**
- `emptyStub_phaseGroupA` (0x0050aec0) in Bank 2 flash decompiles to `return;`
  — this is the main loop slot where the IAH state machine would execute
- No function in the ROM or Bank 2 flash contains a 6-state switch/case matching
  the IAH phase model (key_on/setup/preheat/crank/postheat/off)
- No J1850/SCI2 communication code exists in this ROM (SCI2 registers at
  0x305020-0x305026 are never accessed despite being defined)
- The output driver infrastructure supports IAH (channel dispatch tables,
  function pointer tables for TPU/MIOS drivers) but no code activates the
  IAH-specific channels
- Bank 2 has three other empty stub functions that are similarly reserved:
  - `emptyStub_reserved513200` (0x00513200) — called in main loop phase 5
  - `emptyStub_reserved510d04` (0x00510d04) — called in main loop phase 9
  - `emptyStub_reserved50dd40` (0x0050dd40) — called in main loop phase 8

**E2M Chrysler-specific references (informational, NOT proof of delegation):**
- `IAH_Postheat_Temp_Flag` description mentions "Battery Temp **(for Chrysler)**"
- `Battery_Voltage_When_IAH_Grids_On` describes "J1850 $C0 message when IAH active"
- These indicate IAH was DESIGNED for Chrysler platforms, but do not prove
  another controller handles IAH in this specific build

**Open questions:**
- Whether a different calibration version fills the IAH stub with actual code
- Whether the TIPM/body controller sends commands to the ECU to toggle relays
- Whether the IAH relay outputs function at all in this specific calibration

### IAH Configuration Parameters (from e2m file)

The e2m file (S90140.12) defines 68 IAH configuration parameters. These define
the complete IAH control system for the CM848 platform — the state machine code
that uses them would execute from `emptyStub_phaseGroupA` if compiled in.

### IAH Control Variables

| Parameter | Address | Type | Description |
|-----------|---------|------|-------------|
| `IAH_Control_Status` | 0x018A3500 | u16 | Current IAH phase (0=key_on/1=setup/2=preheat/3=crank/4=postheat/5=off) |
| `IAH_Control_Enable` | 0x01106B42 | u16 | IAH algorithm enable flag |
| `IAH_Phase` | 0x018A3502 | u16 | Current IAH control phase |
| `IAH_Preheat_Timer` | 0x01162B06 | u16 | Preheat countdown timer (0.1s units) |
| `IAH_Postheat_Schedule` | 0x018A3504 | u16 | Postheat schedule selection (0-4) |
| `IAH_Relay_Driver_Select` | 0x018A3506 | u16 | Relay driver selection |
| `Fuel_Heater_Driver` | 0x01157705 | u8 | Desired state of fuel heater output driver |
| `IAH_Monitor_State` | 0x01162B08 | u16 | IAH monitor state (OBDII compliance) |
| `IAH_Error_Status` | 0x018A350A | u16 | Error flags (0=success/1=complete/2=VS/3=BT/4=longcrank/5=2hot/6=posthigh/7=Inhbit/8=Fuel) |
| `IAH_Override` | 0x018A3508 | u16 | Override values (0=ignore/1=ON/OFF/2=OFF/ON/3=ON/ON/4=OFF/OFF) |
| `IAH_Preheat_Status` | 0x018A350E | u16 | 1st Preheat cycle complete flag |

### IAH Configuration Parameters

#### Base Parameters
| Parameter | Address | Scale | Description |
|-----------|---------|-------|-------------|
| `IAH_24V_Enable` | 0x01106B42 | 10 | Intake Air Heater 24V Control Algorithm Enable |
| `IAH_Crank_Time_Limit` | 0x018A2B00 | 0.1s | Disable IAH if cranking longer than this time |
| `IAH_Default_IMT` | 0x018A3700 | 0.015625°F | Default intake manifold temp if IMT sensor fails |
| `IAH_Override_Time_Limit` | 0x018A2B06 | 0.1s | Max time IAH relays can be overridden |
| `IAH_Overvoltage_Limit` | 0x018A2B08 | 0.0625V | Disable control if battery voltage exceeds |
| `IAH_Vehicle_Speed_Threshold` | 0x018A2B12 | 0.00390625 MPH | Terminate IAH if vehicle speed exceeds |

#### Cranking Parameters
| Parameter | Address | Scale | Description |
|-----------|---------|-------|-------------|
| `IAH_Crank_Temp` | 0x018A4100 | 0.015625°F | Enable heaters during crank if IMT below |
| `IAH_Crank_On_RPM` | 0x018A2B22 | 0.125 RPM | Turn grids on during crank if RPM > |
| `IAH_Crank_Off_RPM` | 0x018A2B20 | 0.125 RPM | Turn grids off during crank if RPM < |
| `IAH_Crank_Low_Time` | 0x018A2B1E | 0.1s | Turn grids off if RPM < threshold for time |
| `IAH_Crank_Heat_Time` | 0x018A2B1C | 0.1s | Grid heat on time limit during crank |
| `IAH_Crank_Heat_Subtraction` | 0x018A2B1A | 1.0 | Subtract crank heat from postheat if enabled |

#### Preheat Parameters
| Parameter | Address | Scale | Description |
|-----------|---------|-------|-------------|
| `IAH_Preheat_Time_X` | 0x018A3100 | 0.015625°F | X vector: IMT (DEGF) |
| `IAH_Preheat_Time_Y` | 0x018A3200 | 0.0159 IN_HG | Y vector: preheat time |
| `IAH_Preheat_Time_Z` | 0x018A3900 | 0.1s | Z vector: preheat time |
| `IAH_Redundant_Preheat_Time` | 0x018A2B18 | 0.1s | Redundant preheat time |
| `IAH_Redundant_Preheat_Req` | 0x018A3602 | 1 | 1 = preheat without cranking saved at powerdown |

#### Postheat Parameters
| Parameter | Address | Scale | Description |
|-----------|---------|-------|-------------|
| `IAH_Postheat_RPM` | 0x018A2B0A | 0.125 RPM | Transition to postheat when N > or engine run |
| `IAH_Postheat_Schedule_X` | 0x018A2C00 | 0.015625°F | X vector: IMT (DEGF) |
| `IAH_Postheat_Schedule_Y` | 0x018A2D00 | 1 | Y vector: Postheat Schedule (0-4) |
| `IAH_Postheat_Time_X` | 0x018A2E00 | 1 | X vector: Postheat Schedule |
| `IAH_Postheat_Time_Y` | 0x018A2F00 | 1 | Y vector: Postheat Stage |
| `IAH_Postheat_Time_Z` | 0x018A3000 | 0.1s | Z matrix: Postheat time |
| `IAH_Postheat_DC_X` | 0x018A3300 | 1 | X vector: postheat stage |
| `IAH_Postheat_DC_Y` | 0x018A3400 | 1 | Y vector: % duty cycle |
| `IAH_Postheat_Coolant_Temp_Limit` | 0x018A2B14 | 0.015625°F | Disable postheat if coolant > |
| `IAH_Postheat_Input_Temp_Limit` | 0x018A2B16 | 0.015625°F | Disable postheat if postheat temp > |
| `IAH_Postheat_Temp_Flag` | 0x018A350C | 1 | Temp signal: 0=IMT, 1=Battery Temp (Chrysler) |
| `IAH_Postheat_Temp_Select_Delta` | 0x018A2B10 | 0.015625°F | Temperature selection hysteresis |

#### Monitor Parameters (OBDII)
| Parameter | Address | Scale | Description |
|-----------|---------|-------|-------------|
| `IAH_Monitor_Enable` | 0x01106B54 | 200 | Monitor enable setting |
| `IAH_Monitor_State` | 0x01162B08 | 1 | Monitor state |
| `IAH_Monitor_Min_Battery_Voltage` | 0x01162A12 | 0.0625V | Min battery voltage to run monitor |
| `IAH_Monitor_Max_Battery_Voltage` | 0x01162A10 | 0.0625V | Max battery voltage to run monitor |
| `IAH_Minimum_Manifold_Temperature` | 0x01162A0E | 0.015625°F | Min IMT for monitor operation |
| `IAH_Voltage_Reading_Delay_Time` | 0x01164A08 | 0.1s | Delay between grid-on and voltage read |
| `IAH_Initial_Voltage_Check_Delay` | 0x01162A08 | 0.1s | Delay between key-on and first sample |
| `IAH_Grid_On_Voltage_Check_Delay` | 0x01162A06 | 0.1s | Delay between grid-on and sample |
| `IAH_Grid_Off_Voltage_Check_Delay` | 0x01162A04 | 0.1s | Delay between grid-off and sample |
| `IAH_Band_Check_Delay` | 0x01162A00 | 0.1s | Delay between grid-on and band check |
| `IAH_Band_Check_Stop_Time` | 0x01162A02 | 0.1s | Stop band check at this timer value |
| `IAH_Inhibit_Postheat_Counter` | 0x018A3600 | 1 | Inhibit postheat for X engine starts |

#### Voltage Monitoring Parameters
| Parameter | Address | Scale | Description |
|-----------|---------|-------|-------------|
| `IAH_Delta_Counts_Threshold` | 0x01162B00 | 1 | Delta threshold within valid band |
| `IAH_Delta_Counts_X` | 0x01162C00 | 0.015625°F | X vector: battery cnts threshold |
| `IAH_Delta_Counts_Y` | 0x01162D00 | 1 | Y vector: battery cnts threshold |
| `IAH_Upper_Battery_Counts_Band_Limit` | 0x01162A14 | 1 | Allowable positive delta from initial |
| `IAH_Lower_Battery_Counts_Band_Limit` | 0x01162A0A | 1 | Allowable negative delta from initial |
| `IAH_Max_Delta_Counts_Difference` | 0x01162A0C | 1 | Max delta between grid-on and grid-off |
| `IAH_Grid_On_Delta_Voltage_Counts` | 0x01162B04 | 1 | Delta counts when grids come on |
| `IAH_Grid_Off_Delta_Voltage_Counts` | 0x01162B02 | 1 | Delta counts when grids go off |
| `IAH_Minimum_Delta_Voltage_Threshold` | 0x01164A0A | 0.0625V | Delta below which error is set |

#### Temperature Input Parameters
| Parameter | Address | Scale | Description |
|-----------|---------|-------|-------------|
| `IAH_Temperature_Input0` | 0x018A3800 | 0.015625°F | IMT at key-on if valid |
| `IAH_Temperature_Input1` | 0x018A3802 | 0.015625°F | Battery temp for Chrysler |
| `IAH_Max_Start_Delta_Temperature` | 0x01162A16 | 0.015625°F | Max IMT-battery temp difference |

#### Fuel-Based Termination Parameters
| Parameter | Address | Scale | Description |
|-----------|---------|-------|-------------|
| `IAH_Fuel_Threshold` | 0x018A2B02 | 0.067934784 mm³/s | Postheat terminates if fuel > |
| `IAH_Fuel_Time` | 0x018A2B04 | 0.1s | Postheat terminates if fuel > threshold for time |

### IAH Control Phases

```
0. KEY_ON      - Initial state after ignition on
1. SETUP       - Configure preheat parameters
2. PREHEAT     - Grids on before cranking
3. CRANK       - Grids on during cranking
4. POSTHEAT    - Grids on after engine starts
5. OFF         - System disabled
```

### IAH Status Bits (IAH_Control_Status)

| Bit | Value | Description |
|-----|-------|-------------|
| 0 | 0x0001 | No Op |
| 1 | 0x0002 | PR Active (Preheat Active) |
| 2 | 0x0004 | PR Abrt (Preheat Abort) |
| 3 | 0x0008 | PR Comp (Preheat Complete) |
| 4 | 0x0010 | Wait 4 Run (Waiting for engine run) |
| 5 | 0x0020 | PH Act (Postheat Active) |
| 6 | 0x0040 | PH Abrt (Postheat Abort) |
| 7 | 0x0080 | PH Comp (Postheat Complete) |

---

## CM550 (J90350.00 - MC68336)

### IAH Feature Status: EXCLUDED (#ifdef'd out)

**The IAH state machine is NOT compiled into J90350.00.** The grid heater control
code was excluded via preprocessor `#ifdef` at build time. Evidence:

- The lamp driver output bitmask (`lamp_driver_output_bitmask` at 0x0080daac) has
  bit 3 = Wait to Start lamp, but **no function in the entire ROM ever sets bit 3**
- `iahDisableWaitToStartLamp` (0x24812) unconditionally clears the WTS lamp on every call
- `lampDriverOutputDispatcher` (0x23a90) reads bit 3 to drive the WTS lamp, but it
  is always 0 since nothing sets it
- IAH calibration parameters (IHPHTPDL, IHPHSDXA, IHPHTMZA, IHPSDCXA) exist in
  global_variables.csv at 0x80785c-0x80792c but are never referenced by ROM code
- The e2m file defines IAH parameters for the CM550 platform, but this specific
  build (ISB 195hp, April 1998) was compiled without IAH support

This is consistent with the `#ifdef` preprocessor pattern documented in
`docs/cross-firmware-analysis.md` — the same source code compiled with different
flags produces different feature sets.

### Lamp Driver Architecture (discovered during IAH investigation)

The CM550 uses a bitmask at `lamp_driver_output_bitmask` (0x0080daac) to control
output drivers. The dispatcher function `lampDriverOutputDispatcher` (0x23a90)
reads this bitmask and sets/clears individual lamp driver enable bits:

| Bit | Mask | Lamp | Driver Variable |
|-----|------|------|-----------------|
| 0 | 0x01 | Stop Engine | `stop_engine_lamp` |
| 1 | 0x02 | Warning | `warning_lamp` |
| 2 | 0x04 | Check Engine | `check_engine_lamp` |
| 3 | 0x08 | **Wait to Start** | `wait_to_start_lamp_state` (0x0080169a) |
| 4 | 0x10 | Water in Fuel | Set by `vp44FaultRegisterBit2Monitor` |
| 5 | 0x20 | Retarder 1 | `retarder_driver_1` |
| 6 | 0x40 | Retarder 2 | `retarder_driver_2` |

### IAH Parameter Addresses (from e2m files)

These parameters are defined in e2m calibration files but are **not referenced**
by the J90350.00 ROM code (IAH feature excluded):

| Parameter | Address | Scale | Description |
|-----------|---------|-------|-------------|
| `IAHEAT` | 0x81xx | - | Intake Air Heater group |
| `IHCKTM` | 0x81B8 | 0.1s | Disable IAH if cranking > 15s |
| `IHDFTP` | 0x81B3 | 0.0078125°F | Default IMT if error |
| `IHFLTD` | 0x81AD | 0.016983696 %FU | **Postheat fuel threshold** (same as CM848 IAH_Fuel_Threshold) |
| `IHFLTM` | 0x81AD | 0.1s | Postheat fuel time (same as CM848 IAH_Fuel_Time) |
| `IHPHES` | 0x81B8 | 0.125 RPM | Transition to postheat at RPM |
| `IHPHIC` | 0x81B8 | 1 | Inhibit postheat for X starts |
| `IHRPHTM` | 0x81B8 | 0.1s | Redundant preheat time |
| `IHUOTM` | 0x81B8 | 0.1s | Max override time |
| `IHVSTD` | 0x81B8 | 0.00390625 MPH | Terminate at speed |

### Cross-Firmware Parameter Mapping

The CM550 and CM848 IAH parameters map as follows:

| CM550 Parameter | CM848 Parameter | Notes |
|-----------------|-----------------|-------|
| `IHFLTD` | `IAH_Fuel_Threshold` | Same function, different scale (VP44 % vs HPCR mm³/s) |
| `IHFLTM` | `IAH_Fuel_Time` | Identical (0.1s scale) |
| `IHUOTM` | `IAH_Override_Time_Limit` | Identical (0.1s scale) |
| `IHVSTD` | `IAH_Vehicle_Speed_Threshold` | Identical (0.00390625 MPH scale) |
| `IHRPHTM` | `IAH_Redundant_Preheat_Time` | Identical (0.1s scale) |

**Scale Factor Note:** The fuel threshold (IHFLTD vs IAH_Fuel_Threshold) has a 4x ratio:
- CM550 (VP44): 0.016983696 %FU
- CM848 (HPCR): 0.067934784 MM3S

This reflects the different fuel delivery systems - HPCR injects more fuel per stroke than VP44.

---

## Grid/Light Control

Warning lights are controlled through discrete output drivers:

### CM848 Warning Light Parameters

| Parameter | Address | Description |
|-----------|---------|-------------|
| `OCM_Warning_While_Running` | 0x0100086E | Enables warning light during run state |
| `Chry_MIL_Check_Flash_Time` | 0x018B1C04 | MIL light flash duration |
| `Cluster_Check_Gauges_Lamp` | 0x018B2E02 | Check gauges lamp control |
| `Transmission_Over_Temp_Light` | 0x018C173A | Trans overtemp light command |
| `RE_T_Over_Temp_Light_On` | 0x018C184C | Trans overtemp light on threshold |
| `RE_T_Over_Temp_Light_Off` | 0x018C184A | Trans overtemp light off threshold |
| `OPG_Check_Gauges` | 0x018A7F00 | Check gauges lamp when OPG low |

### Fuel Heater Driver (CM848)

| Parameter | Address | Type | Description |
|-----------|---------|------|-------------|
| `Fuel_Heater_Driver` | 0x01157705 | u8 | Desired state of fuel heater output |
| `Fuel_Heater_Driver_Inversion` | 0x01157805 | u8 | Activation is inverted logic |
| `Fuel_Heater_Driver_Map` | 0x0115795A | u16 | Hardware resource assignment |
| `Fuel_Heater_Driver_Previous_Command` | 0x01157A05 | u8 | Previous ON/OFF command |
| `Fuel_Heater_Driver_Priority` | 0x0112A72D | u8 | Current override priority |

---

## J1939 Status Report (JCGPSS)

The fault handler reports IAH status via J1939:

| Parameter | Address | Description |
|-----------|---------|-------------|
| `JCGPSS` | Internal | Status from fault handler indicating OBDII definition of monitor status |

This parameter maps to the J1939 DTC-related status for IAH system monitoring.

---

## IAH Code Status Across Firmwares

| Firmware | ECU | Module ID | IAH Status | Reason |
|----------|-----|-----------|------------|--------|
| J90350.00 | CM550 | EN | **EXCLUDED** | ISB 195hp build, #ifdef'd out |
| S90140.06 | CM848D | CC | **STUB EMPTY** | Hardware present (ECU pins 5/6 drive IAH relays), state machine slot empty |

CM550 J90350.00 has IAH excluded at compile time (#ifdef). CM848 S90140.06 has
the IAH slot present (`emptyStub_phaseGroupA`) but containing only `return;` —
the hardware supports IAH and e2m defines full calibration, but the state machine
code is absent from this specific Bank 2 flash build.

### CM848 Empty Stub Function Slots

Several Bank 2 function slots contain only `return;` — reserved for optional features:

| Stub Address | Called From | Potential Feature |
|-------------|-------------|-------------------|
| 0x0050aec0 | `phase_group_a_processing()` (every A-phase) | **IAH likely candidate** — high-frequency slot for state machine |
| 0x00513200 | Main loop phase 5 | Unknown excluded feature |
| 0x00510d04 | Main loop phase 9 | Unknown excluded feature |
| 0x0050dd40 | Main loop phase 8 | Unknown excluded feature |

### CM550 Named Functions (from IAH investigation)

| Address | Function | Purpose |
|---------|----------|---------|
| 0x00023a90 | `lampDriverOutputDispatcher` | Reads lamp bitmask, drives output enable flags |
| 0x00024812 | `iahDisableWaitToStartLamp` | Unconditionally clears WTS lamp (IAH disabled) |

### Key Findings

- **E2M files are universal**: Both CM550 and CM848 e2m files define IAH
  parameters for ALL possible configurations, not just the compiled ROM
- **#ifdef pattern confirmed** (CM550): Same as documented in `docs/cross-firmware-analysis.md`
- **Hardware supports IAH** (CM848): ECU pins 5/6 are wired to IAH relay 1 and 2
  per the Dodge Ram wiring diagram — the physical circuit is present
- **Cold Start Aid = IAH**: `Cold_Start_Aid_1_Driver` and `Fuel_Heater_Driver`
  are aliases at the same virtual address (0x01157705) in the e2m parameter system
- **J1850/SCI2 absent**: No SCI2 register accesses exist in the CM848 ROM despite
  registers being defined — J1850 communication is not compiled in
- **Open question**: Whether a different calibration version populates
  `emptyStub_phaseGroupA` with IAH state machine code, or whether the TIPM/body
  controller commands the ECU to toggle relays externally

---

## Related Documentation

- `firmware/CM848_S90140.06_analysis/output/e2m_parameters.csv` - Full CM848 IAH parameter list
- `firmware/CM848_S90140.06_analysis/output/e2m_variables.csv` - CM848 variable mappings
- `firmware/CM550_J90350.00_analysis/output/` - CM550 analysis output (function renames, variables, etc.)

---

*Last updated: 2026-02-22*
