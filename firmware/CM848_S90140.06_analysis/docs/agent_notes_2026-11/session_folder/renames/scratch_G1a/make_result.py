import json

OUT = '/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_G1a.jsonl'
recs = []


def fn(address, old, new, plate, evidence, verdict='confirmed'):
    recs.append({'kind': 'function', 'address': address, 'old': old, 'verdict': verdict,
                 'new': new, 'plate_comment': plate, 'evidence': evidence})


def gl(address, old, new, evidence, verdict='confirmed'):
    recs.append({'kind': 'global', 'address': address, 'old': old, 'verdict': verdict,
                 'new': new, 'evidence': evidence})


def note(text):
    recs.append({'kind': 'note', 'text': text})


# ---------------------------------------------------------------- functions
fn('0x005279d8', 'cm848_auxiliary_boundary_condition_eval', 'cm848_calculateAuxiliaryInjectionTiming',
   'Computes the timing of the auxiliary (third) injection event as a retard after the main injection '
   '(the highest or lowest, by a ROM mode word, of a 4-map blend and boost, ambient and coolant terms, in counts of '
   '0.1171875 degree) and stores main injection timing - retard in injection_timing_aux_offset. '
   'cm848_fuel_demand_state_capture snapshots that value and engine_injectionAngle_tpuChannel6EventHandler turns it (x -5) into the '
   'TPU-A channel 5 slot 12 angle; when the ROM override flag at 0x409090 is set it only copies the override value to 0x40b842 and sets the source byte to 7 '
   '(was cm848_auxiliary_boundary_condition_eval).',
   'injection_timing_aux_offset (only reader cm848_fuel_demand_state_capture) -> injection_timing_aux_offset_snapshot -> cam_sync_period_reference_b -> x -5 -> '
   'DAT_0040b87d -> engine_injectionAngle_writeTpuEvent slot 12 (words 0x30415c / 0x30415e of TPU-A channel 5; the channel 6 interrupt handler only schedules it), '
   'and cm848_calculateEngineFaultTiming gives the third event an on-time only if it starts after the main event; the RAM dump has main 162 - retard 0 = 162 = aux_offset.')

fn('0x0004ae20', 'cm848_calculateEngineTimingData', 'cm848_calculateMainInjectionTiming',
   'Computes the main injection timing (counts of 0.1171875 degree, larger = earlier) into torque_limit_fault_snapshot: the cold-start rpm x coolant map while '
   'cold_start_phase is CSP_ABOVE_RPM_TRIGGER / CSP_ABOVE_RPM_VIA_EVENTS / CSP_SETPOINT_UNDERRUN, otherwise the sum, highest or lowest '
   '(injection_timing_select_mode_cal 0 / 1 / other) of the coolant, intake temperature, barometric pressure and boost components '
   '(each an rpm x fuel_demand_computed angle map x a Q12 factor / 4096), injection_timing_advance and a constant, then the floor, governor-limit minimum and working minimum; '
   'in delivery mode 3 it adds injection_timing_offset_cal and DAT_0005a48a. The winning source goes to torque_limit_arb_t.source_priority, and the result is sent in PGN 65504 '
   'and is the angle of TPU-A channel 5 slot 8 (was cm848_calculateEngineTimingData).',
   'RAM dump: coolant angle 213 x coolant factor 3128 / 4096 = 162 = injection_timing_demand_cyl3 = injection_timing_demand = torque_limit_fault_snapshot (mode word 1 = highest). '
   'The PGN 65504 builder sends ((snapshot + DAT_0005a48a) x 120 >> 10) + 125 (0.1171875 deg per count) and, via injection_load_snapshot -> injection_period_capture_a -> x -5, '
   'it is the slot 8 angle whose on-time is fuel_quantity_active.')

fn('0x0052c780', 'engine_injectionTiming_arbitration_calc', 'cm848_calculatePilotInjectionTimingOffset',
   'Computes how far the pilot (first) injection is advanced ahead of the main injection, in counts of 0.1171875 degree: the cold-start rpm x coolant map while cold_start_phase is '
   'CSP_ABOVE_RPM_TRIGGER / CSP_ABOVE_RPM_VIA_EVENTS / CSP_SETPOINT_UNDERRUN, otherwise the sum, highest, lowest or main-timing-winner choice (ROM mode word 0x409e74) of a 4-map blend, coolant, '
   'intake temperature, barometric pressure and boost components (each an rpm x engine_timing_reference angle map x a Q12 factor / 4096) and a constant (512 normally, 85 under an engine sync fault). '
   'While the governor holds a target speed (governor_mode_code 11 or 4) the maps are read at that speed and the result is scaled by measured / target rpm; cm848_pressure_control_state_load adds it to '
   'torque_limit_fault_snapshot to get the pilot timing for TPU-A channel 5 slot 4 (was engine_injectionTiming_arbitration_calc).',
   'Its only consumer cm848_pressure_control_state_load adds injection_timing_offset_rpm_corrected to the main timing (87 + 162 = 249 in the dump) and caps it at the earliest schedulable angle; the sum '
   '(injection_timing_demand_pressure_calc, only reader cm848_fuel_demand_state_capture) goes via cam_sync_period_reference_a x -5 to the slot 4 angle, the event before main (offset tables 81..490 counts, positive = earlier) '
   'whose on-time fuel_quantity_trim comes from pilot_injection_pulse_width_grid; the dump (mode word 2 = lowest) picks the coolant component 87.')

# ---------------------------------------------------------------- main timing chain
gl('0x0040a2e6', 'torque_limit_fault_snapshot', 'main_injection_timing',
   'Written only by cm848_calculateEngineTimingData (and = injection_timing_offset_cal in fixed delivery mode 2 by cm848_updateEngineStatusFlags); dump 213 x 3128 / 4096 = 162. '
   'Read by the PGN 65504 builder as (x + DAT_0005a48a) x 120 / 1024 and, via injection_load_snapshot -> injection_period_capture_a x -5, it is the TPU-A channel 5 slot 8 (main event) angle; the pilot and auxiliary timings are derived from it.')
gl('0x0040b91e', 'injection_timing_factor_cyl3_a', 'injection_timing_main_coolant_angle',
   'Output of the rpm x fuel_demand_computed table injection_timing_main_coolant_angle_grid (dump 213 counts), multiplied by the coolant factor into injection_timing_demand_cyl3 (162); an angle, not a factor, and not cylinder 3.')
gl('0x0040b91c', 'injection_timing_factor_cyl3_b', 'injection_timing_main_coolant_factor',
   'Q12 output of the coolant x intake manifold temperature grid injection_timing_main_coolant_factor_grid (dump 3128 = 0.764).')
gl('0x0040b91a', 'injection_timing_demand_cyl3', 'injection_timing_main_coolant_component',
   '(coolant angle x coolant factor) / 4096 rounded toward zero = 162 in the dump = the main timing; one candidate of the sum / highest / lowest combination.')
gl('0x0040b918', 'injection_timing_factor_cyl2_a', 'injection_timing_main_intake_temperature_angle',
   'Output of rpm x fuel_demand_computed table injection_timing_main_intake_temperature_angle_grid (dump 222), multiplied by the intake manifold temperature factor into injection_timing_demand_cyl2.')
gl('0x0040b916', 'injection_timing_factor_cyl2_b', 'injection_timing_main_intake_temperature_factor',
   'Q12 output of the 1-D table injection_timing_main_intake_temperature_factor_values keyed by timing_intake_manifold_temperature_snapshot (0 in the dump).')
gl('0x0040b914', 'injection_timing_demand_cyl2', 'injection_timing_main_intake_temperature_component',
   '(intake temperature angle x factor) / 4096; 0 in the dump because its factor table is all zero.')
gl('0x0040b912', 'injection_timing_factor_base_a', 'injection_timing_main_barometric_pressure_angle',
   'Output of rpm x fuel_demand_computed table injection_timing_main_barometric_pressure_angle_grid (flat 43 counts = 5 deg in the dump), multiplied by the barometric factor into injection_timing_demand_calc.')
gl('0x0040b910', 'injection_timing_factor_base_b', 'injection_timing_main_barometric_pressure_factor',
   'Q12 output of the 1-D table injection_timing_main_barometric_pressure_factor_values keyed by timing_barometric_pressure_snapshot (0 at this altitude in the dump).')
gl('0x0040b90e', 'injection_timing_demand_calc', 'injection_timing_main_barometric_pressure_component',
   '(barometric angle x factor) / 4096; 0 in the dump. The old name says nothing; the code multiplies the base_a / base_b pair, which are the barometric tables.')
gl('0x0040b92c', 'injection_timing_factor_cyl4_a', 'injection_timing_main_boost_angle',
   'Output of rpm x fuel_demand_computed table injection_timing_main_boost_angle_grid (dump 85 counts), multiplied by the boost factor into injection_timing_demand_cyl4.')
gl('0x0040b92a', 'injection_timing_factor_cyl4_b', 'injection_timing_main_boost_factor',
   'Q12 output of the rpm x cm848_calculateBoostPressure() grid injection_timing_main_boost_factor_grid (0 at rpm 0 in the dump).')
gl('0x0040b928', 'injection_timing_demand_cyl4', 'injection_timing_main_boost_component',
   '(boost angle x boost factor) / 4096; 0 in the dump.')
gl('0x0040b936', 'injection_timing_demand_cyl5', 'injection_timing_main_constant_component',
   'Calibration constant injection_timing_cyl5_normal (0), or injection_timing_cyl5_fault (213) while engine_sync_fault_active_flag is set; a fifth candidate of the same sum / highest / lowest combination, not a cylinder 5 value.')
gl('0x00409e42', 'injection_timing_select_mode_cal', 'injection_timing_main_combination_mode',
   'cm848_calculateEngineTimingData: 0 = sum (clamped +/-1024), 1 = highest, other = lowest of the components (1 in the dump, so highest); the address is outside the EEPROM range 0x3fd482-0x3feec1, so no _cal.')
gl('0x00409e44', 'injection_timing_demand_lower_limit_cal', 'injection_timing_main_governor_limit_minimum',
   'The main timing is raised to this (68 counts = 8 deg, source 23) while governor_speed_limit_active_flag is set, and cm848_pressure_control_state_load tests main timing = this to switch the pilot offset to its governor-limit floor; the address is outside the EEPROM range, so no _cal.')

# ---------------------------------------------------------------- auxiliary timing chain
gl('0x0040b84a', 'injection_timing_aux_rpm_factor', 'injection_timing_auxiliary_coolant_angle',
   'Output of rpm x fuel_demand_computed table injection_timing_auxiliary_coolant_angle_grid (85..145 counts = 10..17 deg at 600..1800 rpm and up to 40 mm3, else 0), multiplied by injection_timing_aux_coolant_factor / 4096 into injection_timing_aux_combined_clamp; an angle, not a factor.')
gl('0x0040b848', 'injection_timing_aux_coolant_factor', 'injection_timing_auxiliary_coolant_factor',
   'Role is right (Q12 factor from the coolant x intake manifold temperature grid, 4096 in the dump); only the abbreviation aux is spelled out to match injection_timing_auxiliary_coolant_factor_grid.')
gl('0x0040b84c', 'injection_timing_aux_combined_clamp', 'injection_timing_auxiliary_coolant_component',
   '(coolant angle x coolant factor) / 4096 clamped to +/-1024, the coolant candidate; it is combined with the other candidates by highest / lowest, so neither an additive correction nor a clamp on the output.')
gl('0x0040b844', 'injection_timing_aux_load_limit', 'injection_timing_auxiliary_ambient_component',
   '(ambient angle from rpm x fuel_demand_computed table injection_timing_auxiliary_ambient_angle_grid) x (factor from intake manifold temperature x barometric pressure grid) / 4096 clamped +/-1024; no engine load or limit input.')
gl('0x0040b850', 'injection_timing_auxiliary_fuel_demand_factor', 'injection_timing_auxiliary_boost_angle',
   'Output of rpm x fuel_demand_computed table injection_timing_auxiliary_boost_angle_grid (all 0 in this calibration), multiplied by injection_timing_auxiliary_boost_factor / 4096 into injection_timing_auxiliary_boost_component; an angle, with fuel demand as its input.')
gl('0x0040b838', 'injection_timing_aux_boost_blend', 'injection_timing_auxiliary_map_blend',
   'cm848_filterInputValue over injection_timing_auxiliary_map_1..4_grid (lower / upper map number and blend weight, base map as the mode-0 value), inputs rpm x fuel_demand_computed; it has no boost input (the boost term is injection_timing_auxiliary_boost_component).')
gl('0x0040b840', 'injection_timing_aux_output', 'auxiliary_injection_timing_retard',
   'Highest (ROM mode word 0x409094 other than 2; 1 in the dump) or lowest (= 2) of the map blend, boost, ambient and coolant candidates (blend values 0..143 counts = up to 16.8 deg); injection_timing_aux_offset = main timing - this, so it is how far the third event follows the main injection (from its end in the calibration mode that adds the main on-time angle in the TPU writer).')
gl('0x0040b830', 'injection_timing_aux_offset', 'auxiliary_injection_timing',
   '= torque_limit_fault_snapshot - retard (dump 162 - 0), or -(DAT_0005a48a + retard) when ROM flag 0x409096 is set; only reader cm848_fuel_demand_state_capture -> cam_sync_period_reference_b -> x -5 -> slot 12 of TPU-A channel 5, the third event, in the same advance-count convention as the main timing.')
gl('0x003fd0aa', 'aux_boundary_boost_blend_interp_state', 'injection_timing_auxiliary_map_blend_interpolation_state',
   'Lookup cache word of the injection_timing_auxiliary_map_1..4_grid lookups inside the auxiliary timing function; the grids are blended maps, not boost (set to 2 by cm848_initialization_auxiliary_state).')

# ---------------------------------------------------------------- blend map numbers
gl('0x0040a4a6', 'boost_map_index_current', 'fuel_blend_lower_map_number',
   'Only writer cm848_calculateFuelBlendModeSelection clamps it to 1..4; 17 other functions read it to pick the *_map_1..4 table and pass it to cm848_filterInputValue, which interpolates from the value of this map to the value of the other map as fuel_blend_state_t.blend_weight (100..400) runs from this number x 100 to the other number x 100; no boost pressure is involved. The fuel_blend prefix follows the writer function and the fuel_blend_* family and is not otherwise verified.')
gl('0x0040a4a8', 'boost_map_index_target', 'fuel_blend_upper_map_number',
   'Same writer and clamp (1..4); second map number argument of cm848_filterInputValue (end of the interpolation, written as lower <= upper); both are 4 in the dump, i.e. pure map 4.')

# ---------------------------------------------------------------- pilot offset chain
gl('0x0040b974', 'injection_timing_coolant_trim_rpm_factor', 'pilot_injection_timing_offset_coolant_angle',
   'Output of rpm x engine_timing_reference table injection_timing_offset_coolant_angle_grid, multiplied by the unnamed Q12 coolant factor at 0x40b972 / 4096 into injection_timing_offset_coolant_trim; an angle, not an rpm factor.')
gl('0x0040b970', 'injection_timing_offset_coolant_trim', 'pilot_injection_timing_offset_coolant_component',
   '(angle x coolant factor) / 4096; 87 in the dump, the lowest candidate under mode word 2, winner code 2; a candidate in the combination, not a trim.')
gl('0x0040b96c', 'injection_timing_arb_comp3_rpm_factor', 'pilot_injection_timing_offset_intake_temperature_angle',
   'Output of rpm x engine_timing_reference table injection_timing_offset_intake_temperature_angle_grid, multiplied by the unnamed Q12 factor at 0x40b96a (1-D table of the intake manifold temperature copy 0x3fd16c) / 4096 into component 3.')
gl('0x0040b968', 'injection_timing_arb_component_3', 'pilot_injection_timing_offset_intake_temperature_component',
   'Intake temperature angle x intake manifold temperature factor / 4096 (512 in the dump); winner code 3.')
gl('0x0040b966', 'injection_timing_arb_comp4_rpm_factor', 'pilot_injection_timing_offset_barometric_pressure_angle',
   'Output of rpm x engine_timing_reference table injection_timing_offset_barometric_pressure_angle_grid, multiplied by the unnamed Q12 factor at 0x40b964 (1-D table of the barometric pressure copy 0x3fd168) / 4096 into component 4.')
gl('0x0040b962', 'injection_timing_arb_component_4', 'pilot_injection_timing_offset_barometric_pressure_component',
   'Barometric angle x barometric factor / 4096 (759 in the dump); winner code 4.')
gl('0x0040b982', 'injection_timing_arb_comp5_rpm_factor_a', 'pilot_injection_timing_offset_boost_angle',
   'Output of rpm x engine_timing_reference table injection_timing_offset_boost_angle_grid, multiplied by the unnamed Q12 factor at 0x40b980 (rpm x cm848_calculateBoostPressure() grid) / 4096 into component 5.')
gl('0x0040b97e', 'injection_timing_arb_component_5', 'pilot_injection_timing_offset_boost_component',
   'Boost angle x rpm-by-boost factor / 4096 (266 in the dump); winner code 5.')
gl('0x0040b96e', 'injection_timing_offset_boost_blended', 'pilot_injection_timing_offset_map_blend',
   'cm848_filterInputValue over injection_timing_offset_map_1..4_grid with injection_timing_offset_base_map_grid as the mode-0 value (111 = grid corner in the dump); the maps are rpm x engine_timing_reference, no boost input (winner code 1).')
gl('0x0040b99a', 'injection_timing_offset_sync_fault_addend', 'pilot_injection_timing_offset_constant_component',
   'DAT_00409e7e (512 = 60 deg) normally and DAT_00409e7c (85 = 10 deg) while engine_sync_fault_active_flag is set; it takes part in every combination, so the sync fault wording describes only one of its two values.')
gl('0x0040b984', 'injection_timing_offset_arbitrated', 'pilot_injection_timing_offset_arbitrated',
   'Combined offset before the speed correction (87 in the dump); prefix change only, because injection_timing_offset_* is also the name of the EEPROM value injection_timing_offset_cal, a different quantity (main timing offset).')
gl('0x0040b986', 'injection_timing_offset_rpm_corrected', 'pilot_injection_timing_offset_rpm_corrected',
   'Offset after the measured / target rpm scaling (equal to the arbitrated value unless injection_timing_rpm_snap_active_flag is set); its only reader cm848_pressure_control_state_load adds the main timing to it.')
gl('0x0040b992', 'injection_timing_offset_arb_lower_limit', 'pilot_injection_timing_uncapped',
   '= rpm-corrected offset + torque_limit_fault_snapshot (87 + 162 = 249 in the dump; the offset alone if ROM flag 0x409e72 is set; the governor-limit floor variant while the main timing sits at its governor limit minimum); cm848_pressure_control_state_load takes the smaller of this and the earliest schedulable angle, so it is the pilot timing before that cap, not a lower limit.')
gl('0x0040b960', 'injection_timing_demand_pressure_calc', 'pilot_injection_timing',
   'min(earliest schedulable angle, main timing + pilot offset) = 249 counts = 29.2 deg in the dump versus 162 for main; only reader cm848_fuel_demand_state_capture -> injection_timing_pressure_snapshot -> cam_sync_period_reference_a -> x -5 -> slot 4 angle; no pressure is involved.')
gl('0x003fd164', 'injection_timing_arb_boost_blend_interp_state', 'pilot_injection_timing_offset_map_blend_interpolation_state',
   'Lookup cache word of the injection_timing_offset_map_1..4_grid lookups (set to 2 by cm848_initialization_pressure_state); the grids are blended maps, not boost.')

# ---------------------------------------------------------------- notes
note('Extra function verified as the consumer of lead 3: cm848_pressure_control_state_load (0x0052d140) calls engine_injectionTiming_arbitration_calc (or, if ROM flag 0x409e6e is set, takes the override DAT_00409e70 with source 7), '
     'adds the offset to torque_limit_fault_snapshot unless ROM flag 0x409e72 is set, and caps the sum at the earliest schedulable angle (DAT_0005fbb2 / 5 - tooth base offset - an rpm-proportional latency angle - DAT_00409e7a; '
     'source 9 and injection_timing_floor_underrun_count++ when it caps). Its result injection_timing_demand_pressure_calc is the pilot injection timing; suggested name cm848_calculatePilotInjectionTiming (free). '
     'Not given a function record because it was not in my lead list.')
note('Slot facts for firmware/CLAUDE.md and the TPU-channel wording: the three event angles are written by engine_injectionAngle_writeTpuEvent into TPU-A channel 5 parameter RAM (angle words 0x304154 / 0x304158 / 0x30415c = slots 4 / 8 / 12, on-time words +2); '
     'the channel 6 interrupt handler engine_injectionAngle_tpuChannel6EventHandler only schedules them. The angle argument is timing counts x -5: 0.1171875 deg / 5 = 0.0234375 deg per TPU count, so the 0x7800 wrap = 30720 counts = 720 deg.')
note('Event order is now backed by the code and not only by sign inference: slot 4 timing = main + offset (pilot offset tables 81..490 counts, positive = earlier), slot 8 = main, slot 12 = main - retard (retard base map 0..143 counts). '
     'cm848_calculateEngineFaultTiming gives the third event an on-time only when it starts after the main event. Whether Cummins calls it a post injection is still open, so auxiliary stays. '
     'Caution: the writer adds the main on-time angle to the third event according to injection_timing_timing_mode_cal (0x4090f6, 1 here), and the two handler states test it the opposite way (state 2 at 0x5296d0 adds it for mode != 0, state 4 at 0x529878 for mode == 0); I did not resolve why.')
note('Table family: the injection_timing_offset_* tables (bin 01: base_map, map_1..4, coolant / intake_temperature / barometric_pressure / boost angle and factor, cold_start) feed only the pilot injection timing offset, so they should be renamed pilot_injection_timing_offset_* together with the variables above if these are accepted. '
     'Not to be confused with injection_timing_offset_cal (0x3fd808, EEPROM range, correct _cal), the fixed main timing in delivery mode 2 and an added offset in mode 3.')
note('Struct and source-code notes (no struct rename proposed): torque_limit_arb_t_0040a2f6.source_priority is the winning-source code of the main injection timing (5 cold-start map, 7 fixed, 11 floor, 18 injection_timing_advance, 19 intake temperature, 20 coolant, 21 barometric, 22 boost, 23 governor-limit minimum, 24 working minimum, 29 / 30 mode variants, 31 constant); the other torque_limit_arb_t fields were not checked. '
     'engine_timing_arb_byte_24_31 is the winning-source code of the pilot offset (1 map blend, 2 coolant, 3 intake temperature, 4 barometric, 5 boost, 15 constant, 7 override, 8 governor limit, 9 capped by the earliest angle, 10 cold-start map, 11 sum, 12 follows the main winner) and engine_timing_arb_status_packed packs four such codes. '
     'injection_timing_source_byte_2 (0x40b846) is the auxiliary timing source byte (only ever set, to 7, by its override branch) packed into injection_timing_arb_source_packed (0x40b82c) by cm848_calculateGovernorOutput. injection_timing_advance (0x40a46e, written once by cm848_selectFuelLimitOverride) is a further candidate of the main timing combination (source 18); its role was not checked.')
note('Combination mode words (decimal): main timing injection_timing_select_mode_cal 0 = sum, 1 = highest, other = lowest (1 here); pilot offset mode word 0x409e74: 0 = sum, 1 = highest, 2 = lowest, 3 = the component of the same kind as the main timing winner (2 here); auxiliary mode word 0x409094: 2 = lowest, otherwise highest (1 here). '
     'The terms are candidates, not corrections, in the highest / lowest modes.')
note('Observation: in the auxiliary timing function the override branch (ROM flag 0x409090) writes DAT_0040b842 (no reader found by xref_addr) and the source byte 7 and returns before writing injection_timing_aux_offset, so by the xrefs the override does not move the third event angle, whereas the auxiliary quantity function (cm848_calculateGovernorOutput) overrides its real output crank_sync_threshold.')
note('Constants without rows: DAT_0005a48a (ROM word -171 = -20.04 deg) is a fixed timing reference used in the PGN 65504 byte, in delivery mode 3 and as the reference of the auxiliary timing when ROM flag 0x409096 is set. '
     'The unnamed pilot-chain factor words (0x40b972 coolant, 0x40b96a intake temperature, 0x40b964 barometric, 0x40b980 boost) and the input copies 0x3fd16a (coolant temperature), 0x3fd16c (intake manifold temperature), 0x3fd168 (barometric pressure) have no rows in global_variables.csv, so I proposed nothing for them.')
note('Checked and kept: injection_timing_auxiliary_boost_factor (0x40b84e, Q12 factor from the rpm x boost grid) and injection_timing_auxiliary_boost_component (0x40b852, boost angle x boost factor / 4096 clamped +/-1024) already say what they hold; '
     'injection_timing_rpm_axis (0x40b98a) and injection_timing_rpm_snap_active_flag (0x40b988) in the pilot offset function are also right.')
note('Same wrong-domain names sit in the auxiliary QUANTITY chain in cm848_calculateGovernorOutput (not my lead, read from the code only): injection_timing_factor_cyl6_a (0x40b818) is the Q12 factor of injection_quantity_auxiliary_coolant_factor_grid, injection_timing_factor_cyl6_b (0x40b81c) the output of injection_quantity_auxiliary_coolant_limit_grid, '
     'injection_timing_demand_cyl6 (0x40b81a) their product / 4096, and injection_timing_boost_blend (0x40b814) the blend of injection_quantity_auxiliary_map_1..4; they are quantities, not timing and not cylinder 6. '
     'injection_timing_timing_mode_cal (0x4090f6) is a _cal name at a non-EEPROM address as well.')

with open(OUT, 'w') as fh:
    for r in recs:
        fh.write(json.dumps(r, ensure_ascii=True) + '\n')
print(len(recs), 'records written')
