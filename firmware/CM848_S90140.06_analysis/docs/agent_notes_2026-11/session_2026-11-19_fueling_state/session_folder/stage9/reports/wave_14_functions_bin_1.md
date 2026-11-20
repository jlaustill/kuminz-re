W14 functions1: result file written, 31 lines in bin order.
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/result_W14_functions1.jsonl

CHECKS
- The repo gate `apply_renames.py` dry run (no --apply) passes: 31 functions, 0 problems.
- Every `code_quote` is an exact substring of one physical line of that function's body in the current .cpp.
- All 31 new names are distinct and absent from all CSVs, the .cpp and the .hpp. They are also distinct from the result files present at the time (functions3, globals1, globals2); re-run the collision check once all bins are in.
- The repo worktree is clean (git status 0 lines).
- Plates cite other symbols by their CURRENT names, so the reference refresh keeps them right if a rename is held.

COUNTS
- 31 confirmed renames, 0 keep, 0 uncertain, 0 drift (drift applies to globals; none in this bin).
- None of the 31 current names was accurate. Several were swapped or wrong-domain:
  - 0xe164 `calculateSensorEma` is the alpha fuel rate result, and 0xe218 `checkFuelRateCondition` is the on-governor condition.
  - `cm848_calculateBoostPressureOffset` is the pumping torque.
  - `cm848_calculatePressureSensorFiltered` is the intake manifold temperature.

FAMILIES RENAMED
- **Alpha (e2m 104A / 104B), 9 functions.**
  - The five condition functions all take the shape `cm848_calculateAlpha<Condition>Result`, mirroring the `alpha_*_result` words:
    - 0xe164 `...AlphaFuelRateResult`
    - 0xe218 `...AlphaOnGovernorResult`
    - 0xe248 `...AlphaLowSpeedGovernorResult`
    - 0xe2cc `...AlphaAirFuelControlResult`
    - 0xe360 `...AlphaLowAmbientAirPressureResult`
  - 0xe0f4 `...AlphaAltitudeDerateLatch`, 0xe3a4 `...AlphaBase` (the ramp), 0xe518 `cm848_calculateAlpha` (the source selector; read from the disassembly because the decompile garbles it), 0xe748 `cm848_initializeAlpha`.
- **EGR mass flow models (e2m 177E / 177F), 3 functions.**
  - 0x1242c `cm848_calculateDownstreamEgrMassFlow` and 0x125f4 `cm848_calculateUpstreamEgrMassFlow`.
  - 0x127bc `cm848_calculateEgrMassFlowBeforeDelay` (e2m CHP_EGR_Flow_Before_Delay; it selects the model, clamps and zeroes on a closed valve).
  - Direction is proven by the `rpm_fuel_trim_select_cal == 0` branch plus e2m 177E +A (0 = upstream).
  - That selector is separate from 177E +8 (hot / cold side), which 0x17f50 and 0x507028 use.
- **Charge model (e2m 177C / 177D / 191B / 1781 / 1A2C / 1A2D), 4 functions.**
  - 0x12ad4 `cm848_calculateVolumetricEfficiency`, 0x12cf4 `cm848_calculateChargeMassFlow`.
  - 0x130dc `cm848_calculatePumpingTorqueAdjustment`.
  - 0x1359c `cm848_updateChargePressureInRangeFaultCount`. Fault 527 has no P-code (slot 170); none is claimed.
- **Intake manifold and EGR orifice temperature chains (twins, e2m 18D9 / 19CA), 5 functions.**
  - Lead compensation: 0x13d14 `cm848_calculateIntakeManifoldTemperatureLeadCompensation` and 0x506f88 `cm848_calculateEgrOrificeTemperatureLeadCompensation`.
  - 0x13dc8 `cm848_filterAndSelectIntakeManifoldTemperature`: it filters and also picks primary / backup / default. For the orifice this is split into 0x507028 `cm848_filterEgrOrificeTemperature` and 0x50716c `cm848_selectEgrOrificeTemperature`.
  - Channel 9 is the intake manifold temperature; channel 108 is the EGR orifice temperature.
- **0x17f50** `cm848_calculateEgrDeltaPressures` (e2m 1A19).
- **Pedal and fueling, 4 functions.**
  - 0x173a8 `cm848_learnAcceleratorPedalAutozero`.
  - 0x1e830 `cm848_updateFourDimensionalFueling`.
  - 0x1eae8 `cm848_filterCommandedThrottle`.
  - 0x1f17c `cm848_calculateThrottle100Fuelings` (it stores all five e2m 105A values, not one).
- **No load fuel and torques, 2 functions.** 0x50dba8 `cm848_calculateNoLoadFuel`; 0x50eaa8 `cm848_calculateFrictionNoLoadAndNetMachineTorque` (all six e2m 175C words).
- **Ambient, exhaust, water vapor, 3 functions.**
  - 0x502b6c `cm848_calculateAmbientAndCompressorInletConditions` (all of e2m 1921).
  - 0x506e28 `cm848_estimateExhaustTemperature` (verb follows `cm848_estimateCompressorOutletTemperature`).
  - 0x50e7f4 `cm848_calculateWaterVaporAndSaturationTemperatures` (it also computes the partial pressures and dew points).

SHARED-NAME HOLDS
- 0xe3a4: CM550 0xc582 has the same name and is the same alpha ramp. Hold for both firmwares.
- 0xe518: the cross_firmware_matches.csv row to CM550 0x1abb2 (review) is a FALSE match. `cm550_FUN_0001abb2` is an ESP / throttle fueling function. The real CM550 twin is `vp44RpmBasedFaultDetector` @ 0xc326, which writes `_APAPST` / `_APAPBA` and calls the alpha ramp. Hold.
- 0xe164: its map row to CM550 0xc404 (`calculateSensorEma`) is a TRUE twin that the precomputed `shared_with_cm550` flag missed. Hold.
- False bare-name map rows, so no hold needed:
  - 0x12cf4 -> CM550 0x1a8a4 (`vp44_FUN_0001a8a4`, a VP44 ISR routine)
  - 0x1359c -> CM550 0x1645e (`cm550_safeDivideWithClamp`)
  - 0x1f17c -> CM550 0x13cc8 (`cm550_FUN_00013cc8`, a buffer reset)
  - These three rows should leave the map.
- CM550 helper twins (rename leads for CM550): 0xc496 (on governor), 0xc4b2 (low speed governor), 0xc504 `cm550_fuelModeTransitionCountdownHandler` (air fuel control), 0xc556 (low ambient pressure), plus 0xc404 (fuel rate).

FOR THE MAIN SESSION
- Global-side reconcile: my 0xe218 name uses "OnGovernor", while the wave-13 lead for 0x40a172 was `alpha_governor_result`. Pick one. I suggest `alpha_on_governor_result`; the other four result words (0x40a16e, 0x40a170, 0x40a174, 0x40a17a) should mirror the same shape.
- Stale prototypes: function_definitions.csv declares two parameters each for 0x12ad4 (boost_denominator, base_fueling) and 0x130dc (manifold_pressure, rpm). The disassembly overwrites r3 and r4 before any read, so both functions take no arguments. The plates say so.
- Callers: the bin's `callers` list is name-grep, so it includes plate-comment mentions.
  - 0x50eaa8: the real caller is only `cm848_periodicTaskSet_sensorProcessing`.
  - 0x506e28: the real caller is only `cm848_periodicTaskSet_auxiliaryControl`.
  - 0x1f17c: the real caller is only `cm848_periodicTaskSet_controlLoop`.
- e2m text note: 18D9 +0 TPE_IMT_After_Lead says "before limits", but the code clamps to C_TPE_Min_IMT / Max_IMT inside 0x13d14.

NEW LEADS OUTSIDE MY BIN (proposed names are untested ideas, not gate-checked)
- 0x12724 `cm848_checkFuelSystemFaultFlags`: e2m 177F +18 EGR_Flow_Source for the downstream model. It is 0 only when the valve position, orifice delta pressure, charge pressure and orifice temperature sources are all 0. Idea: `cm848_calculateDownstreamEgrMassFlowSource`.
- 0x12778 `cm848_checkEngineFaultConditions`: the same for the upstream model (valve position, Exhaust_Press_Source = `fuel_demand_droop_state` 0x40a7d2, `exhaust_temperature_source`). Idea: `cm848_calculateUpstreamEgrMassFlowSource`.
- 0x128a0 `cm848_throttleBasedFuelCalculation`: delays and filters the EGR flow (final_trim, delay = load_adjusted) into `egr_mass_flow_delayed_filtered`, and divides by `charge_mass_flow_filtered` into `egr_fraction_actual`. It also does the O2 delay. Idea: `cm848_calculateEgrFractionAndFlowDelay`.
- 0x12dc4 `cm848_fuelDemandWithLoadCompensation`: stores `load_input` = intake manifold temperature + 0x7300 (degrees Rankine, e2m 177D +2), calls the efficiency and charge flow functions, and sets Charge_Flow_Source. Idea: `cm848_calculateChargeMassFlowModel`.
- 0x13564 `cm848_checkBoostControlCondition`: Charge_Press_IR_Enable (1A2D +8) = 1 when `map_sensor_fault_status` and `boost_fuel_weight_snapshot` are 0. Idea: `cm848_calculateChargePressureInRangeEnable`.
- 0x13774 `cm848_processBoostProtectionConditions`: the in-range monitor. Charge_Press_IR_Cond = |`boost_pressure_target` - `boost_pressure_sensor_value` - `boost_fuel_threshold_offset`| > `boost_fuel_threshold_limit`. Idea: `cm848_updateChargePressureInRangeMonitor`.
- 0x1ec70 `cm848_calculateDualAxisFuelLimit`: computes Four_D_Fueling (e2m 1053 +0), an alpha blend of two engine speed x throttle grids. The repo says "dual axis" (enum member and function name) while the e2m and wave 13 say "four dimensional". Reconcile the vocabulary.
- 0x5071b8 `cm848_phase_groupB_calculation_2`: the wrapper that filters then selects the EGR orifice temperature. Idea: `cm848_calculateEgrOrificeTemperature`.
- Globals, as likely already covered by the globals bins:
  - 0x405208 `pressure_sensor_lower_limit_cal` and 0x40520a `injection_timing_offset_floor_cal` are e2m 18D6 +2 / +4 C_TPE_Min_IMT / C_TPE_Max_IMT. The second is the maximum, so "floor" reads backwards, and `_cal` is wrong outside the EEPROM mirror.
  - `boost_pressure_state_t.load_input` (0x40a406) is the intake manifold temperature in degrees Rankine (e2m 177D +2).
  - 0x40aeec `fuel_demand_base_offset` is e2m 109C +0 No_Load_Fuel.
  - 0x40a456 `injection_enable_mode_byte` is e2m 1A1B +4 Charge_Tmptr_EStat; 0x40a452 `fuel_demand_boost_offset_filtered` is 1A1B +0 Charge_Tmptr_Est.
  - 0x40a60a `fuel_demand_state_b` is e2m 1A0C +2 Compressor_Inlet_Tmptr_Source.
  - The `throttle_fuel_trim_t` fields are the e2m 177F EGR flow words: `rpm_based_trim` = CHP_Upstream_EGR_Flow, `load_based_trim` = CHP_Downstream_EGR_Flow, `final_trim` = CHP_EGR_Flow_Before_Delay; `engine_fuel_fault_status` (0x40a402) = EGR_Flow_Source.

Scratch folder to archive: /tmp/w14_functions1 (`build.py` generates and validates the result file; plus lookup helpers).