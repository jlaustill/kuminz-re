# N2 investigator notes (round 95) - CM550 lookupTableInterpolation 0x34de0 records

## 0x34de0 lookupTableInterpolation - code walk (m68k.py 34de0-34e98)
- a2 = (0xc,a7) = the record (one stack argument; 2 saved regs + return address).
- +0 word: movea.w (a2),a3 at 0x34df0 (sign-extended byte offset), adda x axis -> start point of the search.
  Written back: move.w a1,(a2) at 0x34e30 (found point) and 0x34e3e (clamped to last point = byte count).
- +2 dword: movea.l (0x2,a2),a0 at 0x34de8 = x axis pointer. (a0) = byte count (movea.w (a0),a1 0x34dec; a1 = last point).
  first point at (0x2,a0) (0x34dfe).
- +6 word: move.w (0x6,a2),d1 at 0x34df4 = input. Compares are unsigned (bcc/bcs).
- +8 dword: adda.l (0x8,a2),a1 at 0x34e40/0x34e52/0x34e5e = values pointer; value read at values + same byte offset
  (so the values table also starts with a byte count word that the lookup never reads; first value at +2).
- +0xc word: move.w (0xc,a2),d0 at 0x34e4a; nonzero -> return values[offset] (no interpolation), 0x34e52.
  The decompiler shows this as args[1].current_index: the 12-byte table_interp_args_t misses it.
- RECORD = 14 bytes (0xe), not 12.
- Below the first point: a3 = x+2, d1 = first point (0x34e10-0x34e14) -> returns the first value (clamp).
  At / above the last point (0x34e1a cmp (a1)): offset = byte count, returns the last value (clamp).
- Interpolation: unsigned. d1 = input - x[i]; if values[i+1] >= values[i] (0x34e66 bcs): values[i] + (values[i+1]-values[i])*(in-x[i]) / (x[i+1]-x[i]) (mulu.w/divu.w)
  else values[i] - (values[i]-values[i+1])*(in-x[i])/(x[i+1]-x[i]). Return d0 word.

## Calls (calls.py / abs_refs.py / pcrel.py)
- abs_refs: 44 absolute refs to 0x34de0 = 42 `jsr (0x34de0).l` + 2 `movea.l #0x34de0,a4` (0x14352 in cm550_FUN_00014348, 0x183da in cm550_FUN_000183cc) that make 5 a4-indirect calls each.
- No bsr / jsr (d16,pc) / lea (d16,pc) to 0x34de0 (pcrel.py). Decompiled: 52 calls (55 text hits = 52 + header + signature + 1 plate comment).
- records_out.txt = RAM-dump contents of each record + e2m of the pointers.

## CM848 lookupTableInterpolation 0x55ef4 = COUNTERPART, not twin
- 5 register arguments (r3 cached offset pointer, r4 input, r5 x axis, r6 y data, r7 flags) vs one record pointer on the stack.
- flags bit 0 signed x (lha/cmpw path at 0x55f24), bit 1 signed y (lhax 0x56130), bit 3 step (0x56108) - CM550 is unsigned only, step = record +0xc word.
- Order: CM848 checks input <= first point FIRST (0x55f28 / 0x56010) and skips repeated first points (0x55f4c loop), then >= last point (0x55f64 / 0x5604c), then the cache with a 0 -> 1 guard (0x55f80); CM550 compares with the cached point first (0x34df8) and has no repeat skip and no 0 guard.
- Interpolation: CM848 one signed path (subf / mullw / divw at 0x56150-0x56168); CM550 two unsigned paths by slope sign (mulu.w / divu.w at 0x34e6e / 0x34e84).
- Counterpart pairs in the repo are prefixed on both sides (cm550_/cm848_secondOrderFilter, cm550_/cm848_exponentialMovingAverage).

## A/D linearization descriptors 0x80a792 + 14n (n = 0..24) - records_ad_out.txt
- mc68k_processAnalogSensorChannels walks them: local_8 = 0x80a792, input = channel_record->adc_raw_value (+6), result -> unfiltered_value,
  step local_8 = &local_8[1].x_axis_ptr = +14 (proves the 14-byte stride). cm550_initializeAnalogSensorChannels writes +0 = 2, +2 axis, +8 values.
- 25 x 14 = 350 bytes: 0x80a792..0x80a8ef; next row adjusted_user_fueling 0x80a8f0. No rows inside now.
- axes = e2m ADxxXA records (counts 0..1023), values = ADxxYA records; channels 3-24 values rows exist (<channel>_linearization_values).

## Record set-up + input (users_out.txt; each set-up writes +0 = 2, +2 axis, +8 values; none writes +0xc -> 0)
- 0x80004a: setup cm550_rpmParameterPointerSetup 0xb614 (NZFLLMXA 0x6009e / NZFLLMYA 0x600b2); cm550_rpm_system_state_controller: input = current_engine_rpm_filtered -> acceleration_noise_control_fuel_limit
- 0x800058: setup cm550_dmaDescriptorSetup2 0xb63e (NZTALMXA 0x600c6 / NZTALMYA 0x600da); cm550_FUN_0000b3d0: input current_engine_rpm_filtered -> acceleration_noise_control_timing_limit
- 0x800102: setup cm550_FUN_0000c880 (ASTHPFXA 0x807acc / ASTHPFYA 0x807ad8); cm550_dzgTimingAndPressureControlStateMachine
- 0x800118: setup cm550_interpolationTableSetup 0xd280 (ASNLFLXA 0x807230 / ASNLFLYA 0x807242); cm550_dualTableLookupSum input asg_reference_speed_working
- 0x800126: setup cm550_interpolationTableSetup (ASCLNLXA 0x807254 / ASCLNLYA 0x807268); cm550_dualTableLookupSum input coolant filtered
- 0x800136: setup cm550_fuelBlendTablePointerSetup 0xd59e (ASALDPXA 0x60462 / ASALDPYA 0x60472); cm550_diagnosticMode10FuelController input asg_reference_speed_working -> asg_selected_droop_slope_0_30
- 0x800144: same setup (ASDPTBXA 0x60482 / ASDPTBYA 0x60492); same caller, same input
- 0x800184 / 0x800192: setup cm550_throttleTablePointerSetup 0x100da (JCBCRPXA 0x6052a / JC6CTQYA 0x60566); cm550_ioControlBasedFuelCalculator re-points +8 at JC1..JC6CTQYA
- 0x8001ea: cm550_initLoadTrendingSystem 0x124d2 (CPCS01XA 0x60596 / CPCS01YA 0x605b2); input engine_rpm_primary
- 0x80020e: same setup (CPCS03XA 0x60640 / CPCS03YA 0x6065c); input engine_rpm_primary
- 0x80024e / 0x80025c / 0x80026a: vp44_FUN_000133fe (CBDTT1 0x8072f4 axis; values CBDTT2 0x807316 / CBDDCT 0x809e9e / CBDI2DCT 0x809ebe); vp44_FUN_000127c2 input current_engine_rpm_filtered
- 0x80058e / 0x80059c: cm550_initializeEngineWarmupProtection (WPCQXA/WPDYTMYA; WPESXA/WPFLDQYA); cm550_runEngineWarmupProtection inputs coolant filtered / engine_rpm_primary
- 0x8005fe: cm550_FUN_000185f0 (EPFLVSAI 0x807176 / EPFLTB 0x8071a8); cm550_FUN_000183cc 5 torque curve breakpoint speeds
- 0x800632: cm550_initShutdownLimitVariables 0x19960 (same EPFLVSAI / EPFLTB); cm550_FUN_00019702 input engine_rpm_primary
- 0x8006aa: cm550_FUN_0001c7a8 (DPFPTB 0x607d6 / DPTVOTB 0x607e4); cm550_fuelDemandTableBlendCalculator input final_fueling
- 0x80071e / 0x80072c / 0x80073a: initializeHighSpeedGovernorGainSet 0x1d2e4 (HSDVCF / HSPPCF / HSITCF); runHighSpeedGovernorPid input |hsg_filtered_engine_speed_error|
- 0x801a3e / 0x801a4c: cm550_initLookupTablePointers1 0x25926 (EPO2VSAI 0x611d0; EPO2LOTB 0x611de / EPO2VLTB 0x611ec); cm550_epsTimingCalculationSlowCycle40Coordinator input engine_rpm_primary
- 0x801c0e: initializePowerTakeOffGovernorFiltersAndGains 0x2db2a (PTSPAX 0x808958 / PTGNTB 0x80896e); input closed_loop_rpm_snapshot
- 0x801c1c / 0x801c2a / 0x801c38: same setup (PTERQDAX/PTGNQDTB, PTERQIAX/PTGNQITB, PTERQPAX/PTGNQPTB); input 0x80dc1c + 16000
- 0x801e30..0x801e68 (5): cm550_FUN_0002faa4 (JCBCRPXA; JC1..JC5CTQYA); j1939FormatMultiFrameResponse input engine_rpm_primary
- 0x8036c6 / 0x8036d4: set up in vp44_liftPumpFuelDeliveryController itself (WSIMAI/WSTATB; WSCLAI/WSCLTATB); inputs intake manifold temp / coolant filtered
- 0x80db20: cm550_FUN_0001ddb4 (NLFCFLXA 0x611fa / NLFCFLYA 0x6120e); several callers
- 0x80db2e: cm550_FUN_0001ddb4 (ADCLFLBP 0x61222 / NLCLFLYA 0x61236); input coolant filtered

## Caller roles (read)
- 0x800102 ASG throttle prefilter: input +6 (0x800108) = |rate-limited reference - asg_filtered_reference_speed_0_4500|; result 0x800110 = coefficient (1/16384) blending asg_filtered_reference_speed with asg_reference_speed_working (>> 14). (cm550_dzgTimingAndPressureControlStateMachine 0xc8a0)
- 0x800118 + 0x800126: cm550_dualTableLookupSum: no load fuel(asg_reference_speed_working) + coolant adjustment(coolant filtered) -> rpm_control_override_flag (a wrong name: ASG no load fuel).
- 0x800144 (ASDPTB) when asg_throttle_source_selector == 1, 0x800136 (ASALDP alternate) when 0; input asg_reference_speed_working -> asg_selected_droop_slope_0_30 (cm550_diagnosticMode10FuelController 0xd3e6)
- 0x800184: cm550_ioControlBasedFuelCalculator: values = JC<n>CTQYA by engine_brake_active_cylinder_count (1..6), input engine_rpm_primary -> braking torque; 0x800192: JC6CTQYA at input *(axis+8) (axis 4th point) -> reference;
  jcomm_ind_retarder_torque_amount_of_torque_provided_by_retarde_0_125 = t * 0x6400 / reference (<= 32000).
- 0x801e30..0x801e68: j1939FormatMultiFrameResponse 0x2f632 (wrong name): requested braking torque x reference (JC4 or JC6 4th point 0x6055a/0x6056e) / 100 compared with 1..5-cylinder braking torque at engine_rpm_primary -> _retarder_torque_level_stepped (0, 0x11, 0x21, 0x32, 0x43, 0x53, 100). Setup cm550_FUN_0002faa4.
- 0x8001ea (CPCS01): timing correction = scaleByRatioSigned(desired - calculated pressure, 0x4444, ratio x compression pressure) (method 1)
- 0x80020e (CPCS03): method 2 (boost path faulted): correction = ratio x (measured - expected intake temperature) / 0x7800, +-0xaa.
- 0x80024e (CBDTT1/CBDTT2) -> 0x809230 CBDFT 'FFT threshold' compared with 0x809232.. (CBDFM1..); 0x80025c (CBDDCT) subtracted from 0x80920e CBDFRC2 (+10000) -> 0x809276; 0x80026a (CBDI2DCT) from 0x809212 CBDFIC2 -> 0x809278 (vp44_FUN_000127c2).
- CBDDCT 0x809e9e / CBDI2DCT 0x809ebe: header-less word[16] each (writer 0x12b2e-0x12c1a indexes from +0 with bin 0x800320 and idx+1; reset loop 0x12c42 writes 10000 from 0x809e9e); next record SSECTMEA 0x809ede.
  The lookup reads values+2..+32 with the 16-point CBDTT1 axis -> its last point reads one word past each table (firmware quirk).
- 0x80db20 (NLFC) + 0x80db2e (NLCL): cm550_FUN_00026b3a no_load_fuel_quantity = NLFC(engine_rpm_primary) + NLCL(coolant); 0x80db20 also at the torque curve breakpoint speeds (cm550_FUN_00014348 -> frictional_load_*), cm550_fuelDemandPercentageCalculator, selectEngineSpeedLimit.
- 0x80058e -> engine_warmup_protection_rifle_to_turbocharger_delay_time (coolant); 0x80059c -> engine_warmup_protection_fuel_limit (engine_rpm_primary).
- 0x800632 (cm550_FUN_00019702): fault_derate_fuel_limit = T(rpm) + (256 - engine_protection_fueling_severity_filtered) x (throttle_100_fueling - T) / 256 (EPFLTB).
- 0x8005fe (cm550_FUN_000183cc): EPFLTB at torque_curve_speed_at_breakpoint_1..5 -> torque_curve_fueling_at_*_speed_breakpoint (minimum or copy by the EPF J1939 flags).
- 0x8006aa: when 0x80d706 == 1 (only a cmpi.w at 0x1c698 in the dumped ROM, no writer) final_fueling -> DPFPTB (axis, MM3S) -> DPTVOTB (values, %FU) = the 4D timing y input. The e2m says the reverse (DPTVOTB 1085 is type X, DPFPTB 1084 type Y group 1085); the code uses DPFPTB as the axis. DP = double pulsing (e2m group of DPSS 'SINGLE / DOUBLE PULSING STATUS').
- 0x80071e / 0x80072c / 0x80073a: runHighSpeedGovernorPid |hsg_filtered_engine_speed_error| -> multiplier x hsg_<derivative|proportional|integral>_gain_base / 256.
- 0x801a3e -> 0x80dabe low_oil_pressure_limit_as_calculated_for_present_engine_speed_0_100; 0x801a4c (addressed (0xe,a2) at 0x2590e) -> 0x80dac0 very_low_oil_pressure_is_calculated_for_present_engine_speed_0_100.
- 0x801c0e: PTO gain by closed_loop_rpm_snapshot when 0x8088ae != 0 -> (x << 9) -> closed_loop_rpm_based_gain; 0x801c1c / 2a / 38: input 0x80dc1c + 16000 -> 0x80dc1e / 0x80dc20 / 0x80dc22, each when 0x804012 / 0x804014 / 0x804016 != 0.
- 0x8036c6 / 0x8036d4: vp44_liftPumpFuelDeliveryController (wrong name: wet stack timing) sets both records each call (+0 = 2), max of WSTATB(intake manifold temp) and WSCLTATB(coolant) -> wet_stack_timing_base_value_0_120, state 1 / 0xd.
- e2m of outputs: 0x80dc1c PTDRER 'DROOP COMPENSATED ERROR TERM'; 0x80dc1e/20/22 PTAJDG/PTAJIG/PTAJPG (D/I/P gain multiplication); 0x8088ae PTGM (0 calculated / 1 table); 0x804012/14/16 PTQDEN/PTQIEN/PTQPEN;
  0x809276 CBDARC2 'ADJUSTED REAL COMP_2', 0x809278 CBDAIC2 'ADJUSTED IMAG COMP_2'; 0x8091de = ASNLFL (row rpm_control_override_flag); 0x80a99a ASSLDP 'ASG SELECTED DROOP SLOPE'.
- JC brake maps: axis JCBCRPXA word[5] (4 points); *(axis+8) = the LAST point; 0x6055a / 0x6056e = the last value of JC4 / JC6.

## Records set up but never looked up in the dumped ROM (abs refs = the set-up only)
- 0x8005b4 (vp44_fuelLimitParameterPointerSetup 0x17f06-0x17f1c: WSIMAI / WSTATB) - the crank routine reads wet_stack_timing_base_value_0_120 instead.
- 0x800278 / 0x800286 / 0x800294 (vp44_FUN_000133fe 0x134ea-0x13534: CBDESBV/CBDESBT, CBDDFBV/CBDDFBT, CBDFFBV/CBDFFBT index -> breakpoint tables).
## Unreferenced record-shaped RAM (leads only, no code in the dump): 0x8037c4 (CRGNADXA/YA cruise-RSG error adjust), 0x803896 / 0x8038ac (2-D, 4D fueling tables),
   0x803984 (IHPHSDXA/YA intake air heater postheat schedule), 0x803992 (IHPRTMXA/YA preheat time, offset 6, input 6400), 0x8039a0 (IHPSDCXA/YA), 0x8039ae? (2-D IHPHTM X/Y/Z), 0x803a68 (OCSGMLAI / OCSGTB oil change severity).

## ROM tables beyond the dump: sizes from the next e2m record (next_record.py), matching the descriptions (1 X 9 -> word[10], 1 BY 6 / 2X6 -> word[7]).

## DECISIONS
### struct table_lookup_1d_arguments_t (14 bytes) - replaces table_interp_args_t (12 bytes; header 'used by FUN_00035088 (2D lookup)' wrong; misses +0xc)
  +0 x_axis_offset word 2 / +2 x_axis_pointer word* 4 / +6 x_input word 2 / +8 y_values_pointer word* 4 / +0xc no_interpolation_flag word 2
  Other rows to re-point: function_definitions.csv 0x34de0 param 0 (table_interp_args_t*) and local_variables_actual.csv 0xb7bc local_8 (table_interp_args_t *).
  No record in the dump has a nonzero flag and nothing in the ROM writes +0xc (0xc7e6 hit = move.b #0x80,(0x56,a0), a false positive).
### 0x34de0 -> cm550_lookupTableInterpolation (counterpart of CM848 lookupTableInterpolation 0x55ef4); suggested prototype: param 0 arguments table_lookup_1d_arguments_t *, return word.
### CM848-aligned table names (same Calterm blocks, CM848 rows exist): speed_request_blend_weight_by_speed_difference (1326/1327), all_speed_governor_coolant_fuel_adjustment (1324/1325),
  engine_retarder_torque_engine_speed_axis + _stage_1..6_values (13D6, 13D0-13D5), fault_derate_fuel_limit_by_engine_speed (10BA/10BB), friction_fuel_by_engine_speed (1098/1099),
  friction_fuel_correction_by_coolant_temperature (109A/109B), high_speed_governor_*_gain_adjustment_error_axis (12E1/12E3/12E5), power_take_off_gain_adjustment_axis / _values (13B2/13B3).
  NOT taken: CM848 all_speed_governor_droop_blend_0/128 and _friction_fuel_blend_128 (CM848 blends two tables; CM550 selects by asg_throttle_source_selector / has one table).
  Record names = <table base>_lookup (CM848's cache words are <base>_cached_axis_offset).
### checks: proposals.py (no duplicate / no existing-name clash), check_tables.py (all 89 tables end exactly at the next e2m record; 0 absolute refs to any row inside a table), check_fields.py.

## FINAL STRUCT TEXT (structure_definitions.csv)
# table_lookup_1d_arguments_t (14 bytes; PR #53 round 95)
table_lookup_1d_arguments_t,,x_axis_offset,word,2,"the byte offset of the last x axis point found (2 = the first point); the search starts there; cached, written back by cm550_lookupTableInterpolation",,verified
table_lookup_1d_arguments_t,,x_axis_pointer,word*,4,the x axis table (its first word is the byte count of the points that follow; compared unsigned),,verified
table_lookup_1d_arguments_t,,x_input,word,2,the x input value (compared unsigned),,verified
table_lookup_1d_arguments_t,,y_values_pointer,word*,4,"the y values: the value of the x point at byte offset n is read at y_values_pointer + n, so the word at +0 (the byte count of a Calterm table) is never read",,verified
table_lookup_1d_arguments_t,,no_interpolation_flag,word,2,nonzero: the lookup returns the value of the point at or below the input without interpolating (0 in every record of the dump),,verified

## LEADS (function names that the record work shows wrong; not in this batch)
- 0xb2aa cm550_rpm_system_state_controller = ANC fuel limit; 0xb3d0 cm550_FUN_0000b3d0 = ANC timing limit; 0xb614 / 0xb63e their record set-ups.
- 0x2f632 j1939FormatMultiFrameResponse = select the engine retarder stage (CM848 cm848_selectEngineRetarderStagePercent); 0xff6c cm550_ioControlBasedFuelCalculator = engine retarder torque (CM848 cm848_calculateEngineRetarderTorque); 0x2faa4 / 0x100da set-ups.
- 0x183cc cm550_FUN_000183cc ~ CM848 cm848_applyFaultDerateToJ1939TorqueCurveFuelings; 0x19702 cm550_FUN_00019702 ~ cm848_calculateFaultDerateFuelLimit.
- 0x34cc4 vp44_liftPumpFuelDeliveryController = wet stack timing; 0xc8a0 cm550_dzgTimingAndPressureControlStateMachine = ASG reference speed blend (CM848 cm848_calculateGovernorReferenceSpeedBlend);
  0xd23c cm550_dualTableLookupSum = ASG friction fuel (0x8091de ASNLFL, row rpm_control_override_flag is wrong); 0xd3e6 cm550_diagnosticMode10FuelController = ASG droop slope + gains; 0x258e8 = oil pressure limits.
- Old rows to retype: 0x800110 fuel_blend_table_5_ptr (the ASG blend weight), 0x80a99a asg_selected_droop_slope_0_30 undefined, 0x80dabe / 0x80dac0 undefined.
- local_variables_actual.csv 0xb7bc local_8 table_interp_args_t * -> table_lookup_1d_arguments_t *; function_definitions.csv 0x34de0 row -> cm550_lookupTableInterpolation param arguments table_lookup_1d_arguments_t * + a return row word.
- CM848's lookupTableInterpolation 0x55ef4 then has no CM550 twin; by the prefix rule it could be cm848_lookupTableInterpolation (300+ calls and many comments name it: a separate decision).

## OUTPUT
- globals_out.json (155 entries: 66 records + 89 tables) built by gen_output.py from proposals.json (proposals.py), check_tables_out.txt, the RAM dumps and the e2m file.
- functions[]: 0x34de0 lookupTableInterpolation -> cm550_lookupTableInterpolation (counterpart of CM848 0x55ef4). prototype: arguments table_lookup_1d_arguments_t *, return word.
- Corrections to the task text: 44 absolute references = 42 jsr + 2 movea.l #0x34de0,a4 (0x14352, 0x183da); 52 decompiled calls (not 53).
STATUS: complete (round 95 N2 investigator).
