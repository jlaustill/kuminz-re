# CM848 cruise control

This file covers what the S90140.06 firmware does for cruise control. It comes from a read-only review on 2026-11-22. A second pass on 2026-11-26 re-read every [review] claim in the code; the ones it confirmed are now [code].

**Names and addresses follow `main` at `deeb3dcf`, the merge of PR #53 (through round 98).** If a later change renames something, search for the address.

Evidence tags:

- **[code]**: read in `output/cm848_rom.ghidra.cpp` or `output/bank2_functions.cpp` during the review or the second pass.
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
| 3 | `cm848_cruiseControlPeriodicUpdate` (0x512ff4) | Turns the debounced button into a cruise state and the CCVS1 state. | [code] |
| 4 | `cm848_cruiseSpeedCommandStateMachine` (0x409b0) | Runs the cruise states and the set speed. | [code] |
| 5 | `cm848_updateCruiseControlDeniedStatus` (0x512a60) | Applies the deny checks. | [code] |
| 6 | `cm848_runCruiseAndRoadSpeedGovernor` (0x525504) | Runs the cruise PID, clamps the result and writes it to `adjusted_user_fueling`. | [code] |
| 7 | `cm848_calculateCruiseControlFueling` (0x40e4c) | Sets `cruise_control_fueling`, a droop limit from the speed error. | [code] |
| 8 | `cm848_selectCruiseOrUserFueling` (0x411b0) | Makes the lower of steps 6 and 7 the working fuel demand. | [code] |
| 9 | `cm848_arbitrateGovernedFueling` (0x4043c) | Takes the lowest of the working demand, the high speed governor and the road speed governor, then the low speed governor as a floor. | [code] |
| 10 | `cm848_controlCruiseVacuumServo` (0x3fc24) | Drives the vacuum servo toward the equivalent throttle. | [code] |

See [Fueling rank](#fueling-rank-code) for what can beat cruise.

## Timing [code]

The executive runs a 40-frame cycle of 5 ms frames. The cruise chain runs in this order:

| Frame | Task set | Rate | What runs |
|---|---|---|---|
| 0, 8, ... | `cm848_runEvery8FramesTaskSetPhase0` (0xbb18) | 40 ms | `cm848_calculateVehicleSpeed` |
| 1, 3, 5, ... | `cm848_runEvery2FramesTaskSetPhase1` (0xb854) | 10 ms | `cm848_controlCruiseVacuumServo` (servo PID and software PWM) |
| 2, 10, ... | `cm848_runEvery8FramesTaskSetPhase2` (0xbb68) | 40 ms | `cm848_cruiseControlPeriodicUpdate`: debounce, ON/OFF, deny checks, the cruise state, CCVS1 state |
| 3, 11, ... | `cm848_runEvery8FramesTaskSetPhase3` (0xbb90) | 40 ms | `cm848_cruiseSpeedCommandStateMachine`: the set speed and resume speed |
| 4, 12, ... | `cm848_runEvery8FramesTaskSetPhase4` (0xbbb8) | 40 ms | `cm848_runCruiseAndRoadSpeedGovernor`: the cruise PID |
| 2, 6, 10, ... | `cm848_runEvery4FramesTaskSetPhase2` (0xba08) | 20 ms | `cm848_arbitrateGovernedFueling`: cruise fuel, road speed governor fuel and the governed fuel choice |

- **Button to fuel.** A press must read the same on two 40 ms passes (the debounce), so the state changes 40 to 80 ms after the press. The set speed moves 5 ms later and the cruise PID runs 5 ms after that.
- **Units.** Every "per pass" in [States and controls](#states-and-controls-code) is per 40 ms. The servo's PID, its 200-pass error timer and its 12-pass PWM period are per 10 ms.

## Buttons

The ladder bands are in ROM at 0x5ab94 / 0x5abbe (`cruise_switch_adc_band_table_x` / `cruise_switch_button_code_table_y`) [code]. The `CRUISE_SWITCH_REQUEST` enum marks all five labels "confirmed live 2026-06-12" [notes].

| 10-bit counts | Button |
|---|---|
| 269 or less | ON/OFF |
| 281 to 459 | CANCEL |
| 471 to 620 | COAST |
| 632 to 752 | SET |
| 764 to 871 | RESUME/ACCEL |
| 872 or more | no button |

Counts in the gaps between bands also read as no button.

- **Valid window:** 92 < counts < 976, the `low_threshold` / `high_threshold` of `cruise_switch_sensor_config` (0x5ab84). Outside it, P0580 / P0581 set, checked only after learning. The channel's fault value (`default_value`) is 1, CANCEL's code. [code]
- **Debounce:** `cruise_switch_request_debounce_count_maximum` = 2, so a code must read the same on two passes (40 ms apart) before it counts. Until then the request is 5 (no button). [code]
- **Learning:** `cm848_checkCruiseSwitchLearnCondition` (0x512e70) sets `cruise_control_switches_learned_flag_cal` on the first ON/OFF press inside the window, and cruise stays denied until then. [round 26]
  - The learned latch at EEPROM 0x197e (RAM 0x3fee00) reads 0 in all four images: `originals/`, the before-HPT dump and both after-HPT dumps. [code]
  - A review said HP Tuners clears that block, so the after-HPT dumps can't show it. [review]
  - While it reads 0, cruise is denied with status 1. The first ON/OFF press inside the window sets it.
- **Pin:** `ecu_pinout.md` lists C2 pin 46, circuit V37, "S/C Switch No. 1 Signal". Nobody has tied that pin to channel 47 yet.

## States and controls [code]

The states run 0 to 8: OFF, SET, RESUME, COAST, ACCEL, BUMP_DOWN, BUMP_UP, HOLD, CANCEL. Each pass is 40 ms (see [Timing](#timing-code)). A press shorter than `cruise_coast_accelerate_hold_time` = 13 passes (0.52 s) counts as a tap; e2m `Coast_Accel_Timer` scales it at 0.04 s per count, which confirms the 40 ms pass.

- **ON/OFF** toggles `cruise_control_on_toggle_state` on each new press. The toggle is forced off whenever the engine isn't running or a ladder, vehicle speed or fault-reaction fault is present, so a stall or key-off turns cruise off.
- **Tap SET** to set the current speed (`cruise_minimum_set_speed`, 35 mph minimum). The set speed is the lower of road speed and `cruise_maximum_road_speed_cal` (85 mph).
- **Hold SET or COAST** to coast: the target drops `cruise_coast_ramp` = 1000/256 mph (3.9 mph) per pass, about 98 mph/s, so it acts as a fuel cut.
- **Tap COAST** to drop `cruise_bump_down_step` = 1 mph.
- **Tap RESUME** to resume, or to add `cruise_bump_up_step` = 2 mph while engaged. The bump only applies while the target is below road speed + 2 mph and cruise (or a governor it may hand to) owns the fuel.
- **Hold RESUME** to accelerate at `cruise_accelerate_ramp` = 15/256 mph per pass, 1.46 mph/s.
- **Releasing COAST** sets the target to the lower of the resume speed and road speed. If road speed is below 35 mph, cruise disengages.
- **Releasing ACCEL** sets the target to the higher of the resume speed and road speed (capped at 85 mph). The ramped target is dropped, so the truck holds the speed it reached.
- **HOLD** copies the target into `cruise_resume_speed`. The resume speed is valid only between 35 and 85 mph.
- **A cancel keeps the resume speed; OFF loses it.** `cm848_selectDeniedCruiseState` (0x512f18) picks CANCEL for the brake, CANCEL, low speed, rpm, gear, clutch and park/neutral checks. It picks OFF (resume speed lost) for deny checks 1 to 5. [code]

The values are from the RAM dump (`originals/cm848_ram.bin`).

The set range is 35 to 85 mph. The set speed is lost at power-off, because `algorithm_enable_flags_3_cal.cruise_save_set_speed_at_power_down_enable` (bit 15) is clear.

`cruise_set_accelerate_switch_select_cal` (EEPROM 0xae, e2m `Set_Accel_Switch_Select`) is 0 here, which the e2m describes as SET/COAST and RESUME/ACCEL. Its only reader is the ECM's own CCVS1 broadcast (`cm848_buildPgn65265CruiseControlVehicleSpeedMessage`, 0x24178). So it changes how the ECM reports the buttons on J1939, not how cruise responds to them. [code]

## Deny checks [code]

`cm848_updateCruiseControlDeniedStatus` (0x512a60) numbers its deny reasons as the e2m does:

1. Not enabled, not learned, or a fault reaction.
2. P0580 or P0581 (ladder out of range).
3. P0500 (vehicle speed sensor).
4. P0572 or P0573 (brake switch pair), or the servo's disabled latch.
5. The ON/OFF toggle is off. The toggle only works with the engine running.
6. The brake: switch 11, or the derived second brake signal (switch 2).
7. CANCEL.
8. Below `cruise_speed_low_limit` (ROM 0x5c28a) = 30 mph.
9. Engine speed outside `cruise_minimum_engine_speed` to `cruise_maximum_engine_speed`, 450 to 4000 rpm.
10. Manual transmission only: the gear check (an engine to road speed ratio window).
11. Manual transmission only: the clutch check (an engine to road speed ratio integrator).
12. Automatic transmission in park or neutral.

Checks 10 and 11 use the `cruise_engine_to_vehicle_speed_ratio_*` family (e2m 8A0E / 8A0F) [round 57]. They run only while `transmission_type_cal` (EEPROM 0x4b2) is 0 or less. It is 3 (automatic), so they don't run and check 12 does. [code]

The result each pass is in `cruise_control_denied_status` (0x40b20c): 0 ready, 13 engaged, else the reason. While cruise is engaged, the reason that ends it is also stored in `cruise_control_last_cutout_reason` (0x40b20a). [code]

Pressing the pedal past the cruise fuel overrides cruise (`cm848_selectCruiseOrUserFueling`). [code]

## Fueling [code]

- **The cruise PID's fuel.** `cm848_runCruiseAndRoadSpeedGovernor` (0x525504) clamps the cruise PID output (`cruise_governor_pid_fueling`) between its minimum and maximum, then writes it to `adjusted_user_fueling`.
- **The droop limit.** `cm848_calculateCruiseControlFueling` (0x40e4c) sets `cruise_control_fueling`.
  - If cruise was engaged on the previous pass (`cruise_control_engaged_previous_flag`), the value comes from the error between `cruise_speed_command` and `vehicle_speed_rise_limited`, through the top and bottom droop gains.
  - Otherwise it copies the operating mode governor's fuel demand.
- **The choice.** `cm848_selectCruiseOrUserFueling` (0x411b0) sets the working demand (`governor_fuel_demand_working`) to the lower of the two, with mode `FUELING_STATE_CRUISE_CONTROL`. It never tests the servo bit. It hands control back to the operating mode governor when any of these hold:
  - cruise isn't engaged;
  - the pedal's governor asks for more fuel than cruise, with the throttle above `cruise_throttle_transition_threshold` (e2m `Cruise_Throttle_Transition_Threshold`, 0 % in this calibration, so cruise takes over again only with the pedal fully released) [round 44];
  - a TSC1 speed or torque mode, a Top2 transmission speed or torque mode (`FUELING_STATE_TOP2_TRANSMISSION_SPEED_CONTROL` / `_TORQUE_CONTROL`, 37 / 38), or a fixed fuel demand is active.

## Fueling rank [code]

How the cruise fuel reaches the injectors, and what can beat it:

1. **The user fueling state.** `selectUserFuelingState` (0x42918) clears `user_fueling_state`, then gives it to the first of: the all-speed governor application mode, TSC1 torque control, TSC1 speed control, user commanded fueling, the pedal fault mode, the variable speed governor, and the four-dimensional fueling default. Cruise isn't on this list; it works one level down.
2. **Cruise or user.** `cm848_selectCruiseOrUserFueling` takes the cruise fuel unless one of the hand-back conditions under [Fueling](#fueling-code) holds. So a TSC1 speed or torque request (`FUELING_STATE_TSC1_SPEED_CONTROL` 2 / `_TORQUE_CONTROL` 1), a Top2 transmission mode (37 / 38) or a fixed fuel demand beats cruise outright.
3. **The derate cap.** The working demand is then capped at `torque_derate_fuel_quantity` + 0x3a. A TSC1 speed / torque limit request (mode 3, `applyTsc1TorqueLimit`, 0x427cc) lowers that derate, so it caps cruise without taking over.
4. **The governors.** `cm848_arbitrateGovernedFueling` takes the lowest of the working demand, the high speed governor (state 12) and the road speed governor (state 10, 106 mph). At or below the low speed governor's speed, the low speed governor (state 11) is a floor; its throttle-off band is skipped while cruise is engaged. On the first pass in cruise (9) or the road speed governor (10), it presets the cruise / road speed governor.
5. **Final fueling.** `cm848_selectFinalFueling` (0x1e22c) can still override it all with the engine state (stopped, shutdown, overspeed, engine brake, cranking, fuel override, immobilizer).

The CCVS1 state reports 6 (override) when cruise is active but `cruise_governor_fueling` is below `all_speed_governor_fueling` and the governed state isn't cruise (9).

## Vacuum throttle servo

**The control loop: `cm848_controlCruiseVacuumServo` (0x3fc24).** [code]
- The enable bit is `algorithm_enable_flags_43_cal.vacuum_throttle_cruise_enable`: EEPROM 0x170 mask 0x10, e2m `Vac_Throttle_Cruise_Enable`.
- **Bit clear:** it clears logical outputs 19, 20 and 21 (vent, vacuum, supply) and returns.
- **Bit set:** it runs only while cruise is engaged.
  - The target `vacuum_throttle_target_position` is set to `all_speed_governor_equivalent_throttle`.
  - The error `vacuum_throttle_position_error` is that target minus `commanded_throttle_state.commanded_throttle`.
  - A PID turns the error into `vacuum_throttle_duty_cycle`, ±25600 = ±100 %. Each term is gain × error / 4; the integral is clamped to the same ±100 %. Errors inside the deadband reset the error, the integral and the previous error.
  - Positive duty: vent on 100 %, vacuum on for the duty. Negative duty: vacuum off, vent on for 100 % + duty. The supply (21) stays on unless the duty is −100 %.
  - The vent and vacuum outputs run by software PWM (`vacuum_throttle_vent_pwm`, `vacuum_throttle_vacuum_pwm`) over `vacuum_throttle_pwm_period` = 12 passes, 120 ms at the loop's 10 ms rate.
  - A service position override (`vacuum_throttle_position_override_enable` / `_value`) runs the loop without cruise, and a duty override (`vacuum_throttle_duty_cycle_override_enable` / `_value`) skips the PID. [code]

**The disabled latch: `vacuum_throttle_actuator_disabled_flag`.** [code]
- It latches on a pedal fault (`final_fueling_state` = `FUELING_STATE_ACCELERATOR_PEDAL_FAULT`).
- It also latches when the error stays above `vacuum_throttle_disabled_error_threshold` with the brake off. That needs `vacuum_throttle_disabled_counter` to reach `vacuum_throttle_maximum_error_time`.
- Only the boot-time initialization (`cm848_initializeCruiseServoControl`, 0x3fba4, called once from `cm848_applicationMain`) clears it. [code]
- With `vacuum_throttle_cruise_actuator_disable_mode` = 1, the latch denies cruise (status 4). [round 26]

**Who reads the enable bit.** Three functions, all by field name. None of them gates cruise engagement. [code]
- the servo loop;
- `cm848_calculateAllSpeedGovernorEquivalentThrottle` (0x45ecc), which applies a throttle offset when the bit is set;
- `cm848_runOperatingModeSpeedGovernor` (0xea00). While cruise is engaged with the servo on, it lowers the all-speed governor's fuel by `vacuum_throttle_all_speed_governor_fueling_reduction` (e2m `Vac_Throttle_ASG_Delta`) [round 44]. The value is 44 counts, about 3 mm³ [review].

**Calibration.** EEPROM 0x170 = `0x11dc`, so the servo is on. [code]
- P 384, I 256, D 26.
- Deadband 8 counts, 2 % of throttle.
- Disabled after an error above 120 counts (30 %) for 200 passes, 2 s at 10 ms.
- Disable mode 1.
- All-speed governor cut 44 counts.

[code] for the list (RAM dump); the 3 mm³ conversion is [review].

**Feedback.** `cm848_monitorDiscreteOutputReadBack` (0x538278) is the read-back check for 11 discrete outputs. It runs every fifth pass with the key on, and checks the three cruise outputs only while the brake is off and the switches are learned [code]. It compares outputs 21, 19 and 20 with raw switches 28, 25 and 27. Mismatches set P0596 / P0595, P0588 / P0587 and P0584 / P0583. [review]
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
- **During cruise.** `cm848_calculateAllSpeedGovernorEquivalentThrottle` (0x45ecc) works out the throttle at which the all-speed governor would give the current fuel: a PI tracker (`equivalent_throttle_tracking_proportional_gain` / `_integral_gain`) moves the governor's speed input until its fuel matches `final_fueling` [code]. With the servo bit clear, it takes the larger of that and the pedal [code]. So the ECM reports a fuel-based throttle during cruise, with or without the servo.

## J1939

- **CCVS1 receive.**
  - `receivePgn65265CruiseControlVehicleSpeedMessage` (0x50bacc) unpacks the clutch, brake, cruise enable, resume and set bits, plus the idle increment / decrement and diagnostic test switches. [code] It carries no firmware prefix because the CM550's twin handler shares the name.
  - `cm848_evaluateJ1939InputSignalFault` (0x50a57c) routes each received input to the logical switch named in its `j1939_input_signal_descriptor_table` entry (Bank 2 0x53a278, field `logical_switch`). The cruise bits go to switch 31. [round 27]
  - No cruise code reads switch 31. [review]
  - The handler never reads the coast or accelerate bits, or the set-speed byte. [code]
- **CCVS1 brake.** The received brake bit can drive switch 11. [review]
  - It needs `algorithm_enable_flags_28_cal` bit 0x400 (EEPROM 0x152, now 0).
  - It also needs `switch_input_datalink_source_bits_cal` bit 11 (EEPROM 0x74d mask 0x08, now 0).
  - With both on, the ECM ignores the wired brake switch.
- **PGN 65264.** `receivePgn65264PowerTakeoffInformationMessage` (0x50b9d8) reads only the remote PTO, PTO on, resume and set switches, and skips the PTO set-speed bytes. [code]
- **TSC1.**
  - `cm848_selectTsc1SpeedControlMode` (0x503074) feeds the requested speed to the governor and compares it with filtered engine speed. [code]
  - `processEngineTsc1Request` (0x22d60) accepts TSC1 only from senders in `tsc1_source_configuration_table` (ROM 0x5c3b4): 0x03, 0x0B, 0x21, 0x4A and 0x4F. It caps a speed request at 3000 rpm. [code]
  - A speed request has a time limit of 600 counts, except from 0x03 (none). Torque requests have 600 from every sender. [code]
  - Cruise yields while a TSC1 speed or torque mode is active. [code]

## Cruise status outputs [code]

- **CCVS1 (PGN 65265) state.** `ccvs1_cruise_control_state` (0x40a2bc): 0 off or cancel, 1 hold, 2 accelerate or bump up, 3 coast or bump down, 4 resume (or hold while resuming), 5 set, 6 override.
- **PCI to the cluster.** `cm848_buildPciTransmitMessage2CruiseControlAndStatusBits` (0x3c2f0) builds PCI message 0x35. It carries speed control on (`cruise_control_on_flag`), a cutout bit (`cruise_control_last_cutout_reason` not 0 or 13) and engaged (the cutout reason is 13). Until the switches are learned, those three bits copy PCI RX[3] 0x1A instead. The message also carries the brake, park / neutral and manual bits, and is resent at once on a change. Which bit lights the cluster's cruise lamp is a truck test.
- **SCI.** `cm848_encodeCruiseControlStatusByte` (0x51ef20) packs the deny status or the state (hold 9, accelerate 10, coast 11) into the low nibble and the cutout reason into the high nibble.

## Maximum road speed [code]

`cm848_calculateMaximumRoadSpeeds` (0x3e42c) sets both limits each pass:

- The road speed governor's reference is `maximum_road_speed_trim_cal` (106 mph). During a fault reaction it ramps down from the speed at the fault to `fault_vehicle_speed_limit_floor`.
- `cruise_maximum_road_speed_cal` is `cruise_maximum_road_speed_trim_cal` (85 mph). Because `cruise_maximum_road_speed_clamp_enable` (e2m `Cruise_Limit_To_RSG_Reference`) is 1, it drops to the road speed governor's reference whenever that is lower.

## Vehicle speed

- **The sensor.** `vehicle_speed` (0x40a272) comes from the sensor on TPU-B channel 2 at 8000 pulses per mile [notes]. `vehicle_speed_sensor_type_cal` = 1 (inductive) [code].
- **Type 4 doesn't work.** `cm848_calculateVehicleSpeed` (0x3dfb8) runs unconditionally from `cm848_runEvery8FramesTaskSetPhase0` (0xbb18), every 40 ms, and never tests the sensor type [code]. So a type 4 speed (J1939 with gear ratio) never reaches the filtered `vehicle_speed` [round 26].
- **Road speed governor and PTO.** The road speed governor limits speed to 106 mph (EEPROM 0xaa = `0x6a00`). PTO is enabled (EEPROM 0x120 bit 4) but can't engage, because `feature_selection_bits_cal` (EEPROM 0x480, cab PTO bit 0, remote PTO bit 1) is 0. [code]

## Calibration words

| EEPROM | Value | Meaning | Evidence |
|---|---|---|---|
| 0xae | `0x0000` | `cruise_set_accelerate_switch_select_cal`: SET/COAST and RESUME/ACCEL, read only by the CCVS1 broadcast | [code] |
| 0x120 | `0x00d0` | `algorithm_enable_flags_3_cal`: bits 4, 6, 7 (PTO, cruise, road speed governor) on; bit 15 (set-speed save) off | [code] |
| 0x126 | `0x801f` | Bit 0x10: the derived second brake signal and its diagnostic on | [code] |
| 0x152 | `0x0000` | J1939 input layer off | [review] |
| 0x15a | `0x0007` | Bit 2: equivalent throttle on | [code] |
| 0x16c | `0x7ca6` | Bit 0x2: brake switch pair diagnostic on | [code] |
| 0x170 | `0x11dc` | Bit 0x10: vacuum throttle servo on | [code] |
| 0x482 | `0x5e0e` | CRC of EEPROM 0x118 to 0x171 (`cm848_verifyCalibrationAndCodeCrc`, 0x524360). A mismatch sets P0602. The algorithm is in the note below. | [code] |

## Open questions

- Which ECM pin carries sensor channel 47.
- Which pins carry logical output 21 and raw switch 28. `ecu_pinout.md` lists circuit V32 on C2 pins 7 and 36 in the 2004 automatic wiring, but nobody has proven the mapping.
- What the firmware does with cruise engaged: nobody has captured data yet. See [Truck tests](#truck-tests).
- Whether a service tool can supply the security key that a write to channel 47's override needs (see below).

## Truck tests

The code can't answer these. Each needs the truck, a CLIP 0x4A reader (`kuminz-cli can0 --read-addr <addr> 2`) and, for some, a meter. Addresses are RAM; words are big-endian. Speeds are mph × 256, engine speed is rpm × 8, fuel is 0.0679 mm³ per count.

**What to log**

| Address | Name | Read as |
|---|---|---|
| 0x40be08 | `cruise_switch_value` | raw ladder counts (channel 47) |
| 0x40bb4e | `cruise_switch_button_code` | 0 ON/OFF, 1 CANCEL, 2 COAST, 3 SET, 4 RESUME, 5 none |
| 0x3fcda2 | `cruise_switch_request` | the debounced code |
| 0x3fee00 | `cruise_control_switches_learned_flag_cal` | 1 once learned (EEPROM 0x197e) |
| 0x3fcd9e | `cruise_control_on_toggle_state` | ON/OFF toggle |
| 0x40b68e | `cruise_control_state` | 0 to 8, as in [States and controls](#states-and-controls-code) |
| 0x40a268 | `cruise_control_engaged_flag` | 1 engaged |
| 0x40b20c | `cruise_control_denied_status` | 0 ready, 13 engaged, else the deny reason |
| 0x40b20a | `cruise_control_last_cutout_reason` | why cruise last ended |
| 0x40a2bc | `ccvs1_cruise_control_state` | 0 to 6 |
| 0x40a26a / 0x40b6e4 | `cruise_speed_command` / `cruise_resume_speed` | mph × 256 |
| 0x40b6e0 / 0x40a272 | `vehicle_speed_rise_limited` / `vehicle_speed` | mph × 256 |
| 0x40b7ba | engine speed | rpm × 8 |
| 0x40b676 / 0x40b6c4 | `cruise_control_fueling` / `cruise_governor_fueling` | fuel |
| 0x40b678 / 0x40b67c | `governor_fuel_demand_working` / `_mode` | fuel / state (9 = cruise) |
| 0x40a152 / 0x40a154 | `adjusted_user_fueling` / `_state` | fuel / state |
| 0x40a2ce / 0x40a2d0 | `final_fueling` / `final_fueling_state` | fuel / state |
| 0x40a57a | `commanded_throttle_state.commanded_throttle` | pedal |
| 0x40b812 | `all_speed_governor_equivalent_throttle` | what EEC2 sends |
| 0x40b652 | `vacuum_throttle_duty_cycle` (4 bytes) | ±25600 = ±100 % |
| 0x40b65a / 0x40b658 | `vacuum_throttle_target_position` / `_position_error` | throttle counts |
| 0x40b65e / 0x40b65c | `vacuum_throttle_vent_pwm` / `_vacuum_pwm` | 0x6400 = 100 % |
| 0x40b660 | `vacuum_throttle_actuator_disabled_flag` | 1 = latched |
| 0x40c050 | `switch_input_state_bits` | byte 0 mask 0x04 = switch 2, byte 1 mask 0x08 = switch 11 (brake) |
| 0x40c082 | `logical_output_request_bits_16_to_23` | masks 0x08 / 0x10 / 0x20 = outputs 19 / 20 / 21 |

**Tests, key on and engine off**

1. **Channel 47's pin.** Back-probe C2 pin 46 (circuit V37) and press each button. If its voltage follows `cruise_switch_value` and every button lands in its band (see [Buttons](#buttons)), the pin is channel 47.
2. **The learned latch.** Read 0x3fee00. If it is 0, start the engine, press ON/OFF once, and read it again after a key cycle. If it never sets, cruise is always denied with status 1.
3. **The brake signals.** Press and release the pedal. Switch 11 should follow it, and switch 2 should do the opposite.

**Tests, driving (an empty road, a second person reading)**

4. **Engagement.** At 40 mph or more: ON/OFF, then tap SET. Expect the state to go 1 (SET), then 7 (HOLD), engaged 1, deny status 13, CCVS1 state 5 then 1, and `governor_fuel_demand_working_mode` 9.
5. **The controls.** Tap COAST (−1 mph), tap RESUME (+2 mph), hold RESUME (+1.46 mph/s), hold COAST (fuel cut). Check each change in `cruise_speed_command`.
6. **The cutouts.** Brake (cutout 6), CANCEL (7) and slowing below 30 mph (8) should keep the resume speed; then RESUME should return to it. ON/OFF (5) should lose it.
7. **Park / neutral.** The calibration says 48RE (`transmission_type_cal` = 3), but the truck has an Allison LCT1000. Check that `transmission_park_or_neutral_flag` (0x40af54) is 0 in drive; if it reads 1, cruise is denied with status 12.
8. **The pedal override.** Press the pedal past cruise. Expect `governor_fuel_demand_working_mode` to leave 9 and CCVS1 state 6, and cruise to take over again only with the pedal fully released.
9. **The servo.** With cruise engaged, log the duty, the vent / vacuum PWM, the error and output bits 19 to 21. If the error stays above 30 % for 2 s with the brake off, the latch sets and P0596 / P0595 can follow. Meter output 21 at C2 pins 7 and 36 to confirm its pin.
10. **The cluster.** Watch the cluster's cruise lamp against PCI message 0x35 (speed control on and engaged).
11. **J1939.** Log PGN 65265 (CCVS1) and 61443 (EEC2) with `candump` and compare them with the internal state and the equivalent throttle.

**After the servo is turned off** (see [Turning the servo off](#turning-the-servo-off))

12. Repeat tests 4 to 8. Expect the three servo outputs to stay off, cruise to hold speed by fuel alone, and no servo or P0602 codes.

## Channel 47's diagnostic override [code]

- **The override.** `cm848_checkCruiseSwitchLearnCondition` reads `cruise_switch_adc_override` (0x40bcde, element 47 of `sensor_channel_diag_override`) instead of the QADC result when `adc_forced_reading_enable_bits_cal[2]` bit 0x8000 is set. EEPROM 0x6f6 to 0x705 (the enable bits) is all zero in every dump, so the override is off.
- **Writing it over J1939.** `writeJ1939DiagnosticMemory` (0x50af58) takes its region from `application_memory_region_table`. RAM 0x3fa000 to 0x40c26e is `MEMORY_REGION_TYPE_AUTHORIZATION_REQUIRED`, so both RAM words need the 10-byte key (`validateSecurityKey`) unless `calibration_download_security_key_cal` (EEPROM 0x8e) is 0xff. It is `0x0000` in every dump.
- **The enable bits are also refused while RAM refresh is on.** Their RAM copy (0x3fdb7c) sits in the protected window above 0x3fd480 and below `sensor_channel_ram_start` (0x40a046), so the write answers 10 unless `ram_refresh_enable` is off (development mode). The override word (0x40bcde) is outside that window.

## Turning the servo off

These steps are untested:

1. Clear bit 0x10 of EEPROM word 0x170 (`0x11dc` to `0x11cc`). The word is big-endian, so only the byte at 0x171 changes (`0xdc` to `0xcc`).
2. Set the CRC word at 0x482 to the CRC of EEPROM 0x118 to 0x171. With only step 1's change to the dumps' contents, that's `0x5e0e` to `0x4e8f`. If anything else in that block differs on the truck, recompute it.

**The CRC algorithm.** CRC-16/KERMIT: reflected polynomial 0x8408, initial value 0, no final XOR.
- `cm848_verifyCalibrationAndCodeCrc` starts its accumulator at 0 and calls `cm848_calculateCrc16Simple` (0x55ea0). That function's ROM table at 0x5842e matches the reflected 0x8408 table on all 256 entries. [code]
- Over EEPROM 0x118 to 0x171, this CRC reproduces the stored `0x5e0e` in the before-HPT and after-HPT dumps. [code]

After that, cruise keeps fueling the engine, and the three servo outputs stay off.

The test plan for the truck (Allison LCT1000 swap, OCT bridge) is in [OCT: cruise without the vacuum servo](https://github.com/jlaustill/oct/blob/main/docs/cruise-without-servo.md).
