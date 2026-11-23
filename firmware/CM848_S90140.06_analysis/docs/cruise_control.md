# CM848 cruise control

This file covers what the S90140.06 firmware does for cruise control. It comes from a read-only review on 2026-11-22.

**Names and addresses follow PR #53 at `b1cd09ef` (round 67).** Most of these names exist only on that branch, so merge this file after PR #53. If a later round renames something, search for the address.

Evidence tags:

- **[code]**: read in `output/cm848_rom.ghidra.cpp` or `output/bank2_functions.cpp` during the review.
- **[round 26]**: PR #53 checked it in the code before it applied the round 26 renames.
- **[round 27]**, **[round 32]**, **[round 44]**, **[round 57]**: PR #53 checked it in the code in that round.
- **[review]**: a review agent read it in the code. Nobody has checked it a second time.
- **[notes]**: from `firmware/CLAUDE.md` or the PR #53 description only.

EEPROM values come from `eeprom_dumps/`. The before-HPT dump and both after-HPT dumps agree on every word in the calibration table below.

## Summary

- **Cruise sets the fuel itself.** While cruise is engaged, the cruise governor's fuel replaces the pedal's (`FUELING_STATE_CRUISE_CONTROL`). [code]
- **The vacuum servo follows the fuel.** It moves the throttle to the position that matches the cruise fuel, so the pedal sensor agrees with the fueling. One calibration bit turns it off. [code]
- **The buttons are one analog resistor ladder** on sensor channel 47, and no J1939 or PCI message reaches them. [code] for the ladder, [review] for the buses.
- **TSC1 speed control holds engine speed**, not road speed. [code]

## Signal path

| Step | Function or variable | What it does | Evidence |
|---|---|---|---|
| 1 | `cruise_switch_button_code` (0x40bb4e) | Holds the button code decoded from the ladder. It is element 47 of `sensor_channel_filtered_output` (0x40baf0). | [code] |
| 2 | `cm848_debounceCruiseSwitchRequest` (0x5129b0) | Debounces the button code. It reads nothing else. | [code] |
| 3 | `cm848_cruiseControlPeriodicUpdate` (0x512ff4) | Turns the debounced button into a cruise request. | [review] |
| 4 | `cm848_cruiseSpeedCommandStateMachine` (0x409b0) | Runs the cruise states and the set speed. | [review] |
| 5 | `cm848_updateCruiseControlDeniedStatus` (0x512a60) | Applies the deny checks. | [review] |
| 6 | `cm848_runCruiseAndRoadSpeedGovernor` (0x525504) | Runs the cruise PID, clamps the result and writes it to `adjusted_user_fueling`. | [code] |
| 7 | `cm848_calculateCruiseControlFueling` (0x40e4c) | Sets `cruise_control_fueling`, a droop limit from the speed error. | [code] |
| 8 | `cm848_selectCruiseOrUserFueling` (0x411b0) | Makes the lower of steps 6 and 7 the working fuel demand. | [code] |
| 9 | `cm848_arbitrateGovernedFueling` (0x4043c) | Leaves `adjusted_user_fueling` alone in the cruise and road speed governor states. | [code] |

The path from the working demand to final fueling is [notes].

## Buttons

The ladder bands are in ROM at 0x5ab94 / 0x5abbe [review]. The `CRUISE_SWITCH_REQUEST` enum marks all five labels "confirmed live 2026-06-12" [notes].

| 10-bit counts | Button |
|---|---|
| 269 or less | ON/OFF |
| 281 to 459 | CANCEL |
| 471 to 620 | COAST |
| 632 to 752 | SET |
| 764 to 871 | RESUME/ACCEL |
| 872 or more | no button |

Counts in the gaps between bands also read as no button.

- **Valid window:** 92 < counts < 976. Outside it, P0580 / P0581 set, checked only after learning. On a fault the channel defaults to code 1 (CANCEL). [review]
- **Learning:** `cm848_checkCruiseSwitchLearnCondition` (0x512e70) sets `cruise_control_switches_learned_flag_cal` on the first ON/OFF press inside the window, and cruise stays denied until then. [round 26]
  - The learned latch at EEPROM 0x197e reads 0 in `originals/` and in the before-HPT dump.
  - The after-HPT dumps can't show it, because HP Tuners clears that block. [review]
- **Pin:** `ecu_pinout.md` lists C2 pin 46, circuit V37, "S/C Switch No. 1 Signal". Nobody has tied that pin to channel 47 yet.

## States and controls [review]

The states run 0 to 8: OFF, SET, RESUME, COAST, ACCEL, BUMP_DOWN, BUMP_UP, HOLD, CANCEL. A press shorter than 13 passes (0.52 s) counts as a tap.

- **Tap SET** to set the current speed (35 mph minimum).
- **Hold SET or COAST** to coast. Holding COAST drops the target fast enough to act as a fuel cut.
- **Tap COAST** to drop 1 mph.
- **Tap RESUME** to resume, or to add 2 mph while engaged.
- **Hold RESUME** to accelerate at 15/256 mph per pass. That's about 1.5 mph/s at an inferred 40 ms pass.
- **Releasing COAST** sets the speed to the lower of the resume speed and road speed, and drops cruise below 35 mph. Releasing ACCEL sets it to the higher of the two.

The set range is 35 to 85 mph. The set speed is lost at power-off, because `algorithm_enable_flags_3_cal.cruise_save_set_speed_at_power_down_enable` (bit 15) is clear.

`cruise_set_accelerate_switch_select_cal` (EEPROM 0xae, e2m `Set_Accel_Switch_Select`) is 0 here, which the e2m describes as SET/COAST and RESUME/ACCEL. Its only reader is the ECM's own CCVS1 broadcast (`cm848_buildPgn65265CruiseControlVehicleSpeedMessage`, 0x24178). So it changes how the ECM reports the buttons on J1939, not how cruise responds to them. [code]

## Deny checks [review]

`cm848_updateCruiseControlDeniedStatus` (0x512a60) numbers its deny reasons as the e2m does:

1. Not enabled, not learned, or a fault reaction.
2. P0580 or P0581 (ladder out of range).
3. P0500 (vehicle speed sensor).
4. P0572 or P0573 (brake switch pair), or the servo's disabled latch.
5. The ON/OFF toggle is off. The toggle only works with the engine running.
6. The brake: switch 11, or the derived second brake signal (switch 2).
7. CANCEL.
8. Below 30 mph.
9. Engine speed outside 450 to 4000 rpm.
10. Manual transmission only: the gear check (an engine to road speed ratio window).
11. Manual transmission only: the clutch check (an engine to road speed ratio integrator).
12. Automatic transmission in park or neutral.

Checks 10 and 11 use the `cruise_engine_to_vehicle_speed_ratio_*` family (e2m 8A0E / 8A0F) [round 57]. The calibration is set for an automatic transmission, so they don't run [review].

Pressing the pedal past the cruise fuel overrides cruise (`cm848_selectCruiseOrUserFueling`). [code]

## Fueling [code]

- **The cruise PID's fuel.** `cm848_runCruiseAndRoadSpeedGovernor` (0x525504) clamps the cruise PID output (`cruise_governor_pid_fueling`) between its minimum and maximum, then writes it to `adjusted_user_fueling`.
- **The droop limit.** `cm848_calculateCruiseControlFueling` (0x40e4c) sets `cruise_control_fueling`.
  - If cruise was engaged on the previous pass (`cruise_control_engaged_previous_flag`), the value comes from the error between `cruise_speed_command` and `vehicle_speed_rise_limited`, through the top and bottom droop gains.
  - Otherwise it copies the operating mode governor's fuel demand.
- **The choice.** `cm848_selectCruiseOrUserFueling` (0x411b0) sets the working demand (`governor_fuel_demand_working`) to the lower of the two, with mode `FUELING_STATE_CRUISE_CONTROL`. It never tests the servo bit. It hands control back to the operating mode governor when any of these hold:
  - cruise isn't engaged;
  - the pedal's governor asks for more fuel than cruise, with the throttle above `cruise_throttle_transition_threshold` (e2m `Cruise_Throttle_Transition_Threshold`, 0 % in this calibration, so cruise takes over again only with the pedal fully released) [round 44];
  - a TSC1 speed or torque mode, mode 37 or 38, or a fixed fuel demand is active.

## Vacuum throttle servo

**The control loop: `cm848_controlCruiseVacuumServo` (0x3fc24).** [code]
- The enable bit is `algorithm_enable_flags_43_cal.vacuum_throttle_cruise_enable`: EEPROM 0x170 mask 0x10, e2m `Vac_Throttle_Cruise_Enable`.
- **Bit clear:** it clears logical outputs 19, 20 and 21 (vent, vacuum, supply) and returns.
- **Bit set:** it runs only while cruise is engaged.
  - The target `vacuum_throttle_target_position` is set to `all_speed_governor_equivalent_throttle`.
  - The error `vacuum_throttle_position_error` is that target minus `commanded_throttle_state.commanded_throttle`.
  - A PID turns the error into `vacuum_throttle_duty_cycle`. The vent and vacuum outputs run by software PWM (`vacuum_throttle_vent_pwm`, `vacuum_throttle_vacuum_pwm`). [review]

**The disabled latch: `vacuum_throttle_actuator_disabled_flag`.** [code]
- It latches on a pedal fault.
- It also latches when the error stays above `vacuum_throttle_disabled_error_threshold` with the brake off. That needs `vacuum_throttle_disabled_counter` to reach `vacuum_throttle_maximum_error_time`.
- Only boot init (`cm848_initCruiseServoControl`, 0x3fba4) clears it. [review]
- With `vacuum_throttle_cruise_actuator_disable_mode` = 1, the latch denies cruise (status 4). [round 26]

**Who reads the enable bit.** Three functions, all by field name. None of them gates cruise engagement. [code]
- the servo loop;
- `cm848_calculateAllSpeedGovernorEquivalentThrottle` (0x45ecc), which applies a throttle offset when the bit is set;
- `cm848_runOperatingModeSpeedGovernor` (0xea00). While cruise is engaged with the servo on, it lowers the all-speed governor's fuel by `vacuum_throttle_all_speed_governor_fueling_reduction` (e2m `Vac_Throttle_ASG_Delta`) [round 44]. The value is 44 counts, about 3 mm³ [review].

**Calibration.** EEPROM 0x170 = `0x11dc`, so the servo is on. [code]
- P 384, I 256, D 26.
- Deadband 2 %.
- Disabled after a 30 % error for 200 passes.
- Disable mode 1.
- All-speed governor cut 44 counts.

[review] for the list.

**Feedback.** `cm848_monitorDiscreteOutputReadBack` (0x538278) is the read-back check for 11 discrete outputs. It compares outputs 21, 19 and 20 with raw switches 28, 25 and 27 while the brake is off. Mismatches set P0596 / P0595, P0588 / P0587 and P0584 / P0583. [review]
- The supply output's faults are 146 and 147 (`cruise_servo_supply_driver_high_control_error`, `cruise_servo_supply_driver_low_control_error`). [round 32]
- The vent and vacuum codes need the disabled latch first; the supply code can set alone. [review]

**Service overrides.** `cm848_applyDiscreteOutputOverrides` (0x514108) lets a service tool force outputs 21, 20 and 19 on or off. It uses three `.enable` / `.value` pairs, one per output: `cruise_servo_supply_output_override`, `cruise_vacuum_output_override` and `cruise_vent_output_override`. In the e2m they're record 8C29: `Cruise_SC_Source_Driver_Override`, `Cruise_Vacuum_Driver_Override` and `Cruise_Vent_Driver_Override`, each with a matching user value row. [code]

## Second brake signal [code]

- **Where it comes from.** Switch 2 has no wire. `cm848_deriveSecondBrakeSwitchSignal` (0x511ed4) builds it when the key is on and both of these are set:
  - `algorithm_enable_flags_6_cal.not_brake_switch_diagnostic_enable` (EEPROM 0x126 mask 0x10);
  - `cruise_control_switches_learned_flag_cal`.
- **What drives it.** While logical output 21 (the servo supply request) is off, the raw sample of switch 28 drives it. While output 21 is on, the serial output driver status bits drive it.
- **The pair monitor.** `cm848_monitorBrakeSwitchPairAgreement` (0x512130) compares switch 11 with switch 2. The 16th disagreement sets P0573 (switch 11 only) or P0572 (switch 2 only).
  - It needs `algorithm_enable_flags_41_cal.brake_switch_diagnostic_enable` (EEPROM 0x16c mask 0x2).
  - Because switch 2 has no wire, it also needs the two conditions above.
- **Calibration.** EEPROM 0x126 = `0x801f` and 0x16c = `0x7ca6`, so both diagnostics are on.

## Equivalent throttle and EEC2

- **What EEC2 sends.** `cm848_buildPgn61443ElectronicEngineController2Message` (0x25b10) [code]:
  - SPN 91 (accelerator pedal position 1) is `all_speed_governor_equivalent_throttle` × 0.625;
  - SPN 558 (the low idle switch) comes from `commanded_throttle_state.accelerator_off_idle`.
- **The enable.** `algorithm_enable_flags_32_cal.equivalent_throttle_enable` (EEPROM 0x15a bit 2) turns the calculation on; with it clear, the equivalent throttle equals the pedal. EEPROM 0x15a = `0x0007`, so it's on. [code]
- **During cruise.** `cm848_calculateAllSpeedGovernorEquivalentThrottle` (0x45ecc) works out the throttle at which the all-speed governor would give the current fuel [review]. With the servo bit clear, it takes the larger of that and the pedal [code]. So the ECM reports a fuel-based throttle during cruise, with or without the servo. That conclusion rests on the [review] part.

## J1939

- **CCVS1 receive.**
  - `cm848_receivePgn65265CruiseControlVehicleSpeedMessage` (0x50bacc) unpacks the enable, set and resume bits. [review]
  - `cm848_evaluateJ1939InputSignalFault` (0x50a57c) routes each received input to the logical switch named in its `j1939_input_signal_descriptor_table` entry (Bank 2 0x53a278, field `logical_switch`). The cruise bits go to switch 31. [round 27]
  - No cruise code reads switch 31. [review]
  - The handler never reads the coast or accelerate bits, or the set-speed byte. [review]
- **CCVS1 brake.** The received brake bit can drive switch 11. [review]
  - It needs `algorithm_enable_flags_28_cal` bit 0x400 (EEPROM 0x152, now 0).
  - It also needs `switch_input_datalink_source_bits_cal` bit 11 (EEPROM 0x74d mask 0x08, now 0).
  - With both on, the ECM ignores the wired brake switch.
- **PGN 65264.** The handler skips the PTO set-speed bytes. [review]
- **TSC1.**
  - `cm848_selectTsc1SpeedControlMode` (0x503074) feeds the requested speed to the governor and compares it with filtered engine speed. [code]
  - The ECM accepts TSC1 from source addresses 0x03, 0x0B, 0x21, 0x4A and 0x4F, and caps the request at 3000 rpm. [review]
  - It ends a speed request after 600 counts, except from 0x03. [review]
  - Cruise yields while a TSC1 speed or torque mode is active. [code]

## Vehicle speed

- **The sensor.** `vehicle_speed` (0x40a272) comes from the sensor on TPU-B channel 2 at 8000 pulses per mile [notes]. `vehicle_speed_sensor_type_cal` = 1 (inductive) in every image [review].
- **Type 4 doesn't work.** `cm848_calculateVehicleSpeed` (0x3dfb8) runs unconditionally from `cm848_periodicTaskSet_canTx` (0xbb18) and never tests the sensor type [code]. So a type 4 speed (J1939 with gear ratio) never reaches the filtered `vehicle_speed` [round 26].
- **Road speed governor and PTO.** The road speed governor limits speed to 106 mph (EEPROM 0xaa). PTO is enabled and shares the ladder, but can't engage while EEPROM 0x480 = 0. [review]

## Calibration words

| EEPROM | Value | Meaning | Evidence |
|---|---|---|---|
| 0xae | `0x0000` | `cruise_set_accelerate_switch_select_cal`: SET/COAST and RESUME/ACCEL, read only by the CCVS1 broadcast | [code] |
| 0x120 | `0x00d0` | PTO, cruise and road speed governor on; set-speed save off | [review] |
| 0x126 | `0x801f` | Bit 0x10: the derived second brake signal and its diagnostic on | [code] |
| 0x152 | `0x0000` | J1939 input layer off | [review] |
| 0x15a | `0x0007` | Bit 2: equivalent throttle on | [code] |
| 0x16c | `0x7ca6` | Bit 0x2: brake switch pair diagnostic on | [code] |
| 0x170 | `0x11dc` | Bit 0x10: vacuum throttle servo on | [code] |
| 0x482 | `0x5e0e` | CRC of EEPROM 0x118 to 0x171 (`cm848_verifyCalibrationAndCodeCrc`, 0x524360). A mismatch sets P0602. The algorithm is in the note below. | [code] |

## Open questions

- Which ECM pin carries sensor channel 47.
- Which pins carry logical output 21 and raw switch 28. `ecu_pinout.md` lists circuit V32 on C2 pins 7 and 36 in the 2004 automatic wiring, but nobody has proven the mapping.
- What the firmware does with cruise engaged: nobody has captured data yet.
- How the working demand reaches final fueling, and how TSC1 ranks against cruise there.
- Whether a diagnostic memory write over J1939 could reach channel 47's override (`sensor_channel_diag_override[47]`). A function comment says it needs authentication [notes].
## Turning the servo off

These steps are untested:

1. Clear bit 0x10 of EEPROM word 0x170 (`0x11dc` to `0x11cc`). The word is big-endian, so only the byte at 0x171 changes (`0xdc` to `0xcc`).
2. Set the CRC word at 0x482 to the CRC of EEPROM 0x118 to 0x171. With only step 1's change to the dumps' contents, that's `0x5e0e` to `0x4e8f`. If anything else in that block differs on the truck, recompute it.

**The CRC algorithm.** CRC-16/KERMIT: reflected polynomial 0x8408, initial value 0, no final XOR.
- `cm848_verifyCalibrationAndCodeCrc` starts its accumulator at 0 and calls `cm848_calculateCrc16Simple` (0x55ea0). That function's ROM table at 0x5842e matches the reflected 0x8408 table on all 256 entries. [code]
- Over EEPROM 0x118 to 0x171, this CRC reproduces the stored `0x5e0e` in the before-HPT and after-HPT dumps. [code]

After that, cruise keeps fueling the engine, and the three servo outputs stay off.

The test plan for the truck (Allison LCT1000 swap, OCT bridge) is in [OCT: cruise without the vacuum servo](https://github.com/jlaustill/oct/blob/main/docs/cruise-without-servo.md).
