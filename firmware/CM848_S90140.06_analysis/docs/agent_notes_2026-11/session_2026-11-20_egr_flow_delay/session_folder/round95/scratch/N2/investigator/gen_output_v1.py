"""Read-only: assemble the globals[] entries (records + tables) from proposals.json, the RAM dumps and the e2m file.
Writes globals_out.json next to this script."""
import json
import re

D = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/scratch/N2/investigator/"
REPO = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay"
FW = REPO + "/firmware/CM550_J90350.00_analysis/firmware/"
E2M = REPO + "/e2m-analysis/originals/v64t6_s.e2m"
ram = open(FW + "J90350.00.ram.bin", "rb").read()
ext = open(FW + "J90350.00.extended_ram.bin", "rb").read()


def word(a):
    if 0x800000 <= a < 0x800000 + len(ram) - 1:
        return int.from_bytes(ram[a - 0x800000:a - 0x800000 + 2], "big")
    if 0x809242 <= a < 0x809242 + len(ext) - 1:
        return int.from_bytes(ext[a - 0x809242:a - 0x809242 + 2], "big")
    return None


e2m = {}
for line in open(E2M, errors="replace"):
    head = line.split(";")[0].split(",")
    if len(head) < 8:
        continue
    desc = line.split(";", 1)[1].strip() if ";" in line else ""
    e2m.setdefault(head[0], (head[1].strip(), head[2], head[3], head[5], desc.split("~")[0].strip().rstrip(".")))

d = json.load(open(D + "proposals.json"))
P = {int(r["address"], 16): r for r in d["records"]}
T = {int(t["address"], 16): t for t in d["tables"]}
by_record = {}
for t in d["tables"]:
    by_record.setdefault(t["record"], []).append(t)

# record -> (setup, use sentence, jsr evidence, confidence)
S = {
    0x80004a: ("cm550_rpmParameterPointerSetup (0xb614)", "cm550_rpm_system_state_controller (jsr at 0xb386) writes x_input = current_engine_rpm_filtered and stores the result in acceleration_noise_control_fuel_limit (e2m 10A4 +0 NZFLLM) while the ANC fuel limit conditions hold (algorithm_enable_flags_3_cal.acceleration_noise_control_fuel_limit_enable)", "high"),
    0x800058: ("cm550_dmaDescriptorSetup2 (0xb63e)", "cm550_FUN_0000b3d0 (jsr at 0xb4a0) writes x_input = current_engine_rpm_filtered and stores the result in acceleration_noise_control_timing_limit (10A4 +2 NZTALM) while the ANC timing limit conditions hold (algorithm_enable_flags_3_cal.acceleration_noise_control_timing_limit_enable)", "high"),
    0x800102: ("cm550_FUN_0000c880 (0xc880)", "cm550_dzgTimingAndPressureControlStateMachine (jsr at 0xc92c) writes x_input = the absolute difference between the rate-limited ASG reference and asg_filtered_reference_speed_0_4500 (0x800108); the result (0x800110, a 1/16384 weight) blends asg_filtered_reference_speed_0_4500 with asg_reference_speed_working (>> 14). CM848's counterpart cm848_calculateGovernorReferenceSpeedBlend reads the same tables", "high"),
    0x800118: ("cm550_interpolationTableSetup (0xd280)", "cm550_dualTableLookupSum (a3, jsr at 0xd268) writes x_input = asg_reference_speed_working (0x80a990) and adds the result to the coolant adjustment of all_speed_governor_coolant_fuel_adjustment_lookup into 0x8091de (e2m ASNLFL, the ASG no load fuel; row rpm_control_override_flag)", "high"),
    0x800126: ("cm550_interpolationTableSetup (0xd280)", "cm550_dualTableLookupSum (a2, jsr at 0xd25e) writes x_input = the filtered coolant temperature 0x80a336 and adds the result to all_speed_governor_friction_fuel_lookup's into 0x8091de (ASNLFL)", "high"),
    0x800136: ("cm550_fuelBlendTablePointerSetup (0xd59e)", "cm550_diagnosticMode10FuelController (jsr at 0xd444) uses it while asg_throttle_source_selector is 0: x_input = asg_reference_speed_working, result = asg_selected_droop_slope_0_30 (e2m 107A +E ASSLDP 'ASG SELECTED DROOP SLOPE'). all_speed_governor_droop_lookup serves selector 1. CM848 names these tables all_speed_governor_droop_blend_0_axis / _values (0x5974e / 0x5975e) but blends the two tables where CM550 selects one", "high"),
    0x800144: ("cm550_fuelBlendTablePointerSetup (0xd59e)", "cm550_diagnosticMode10FuelController (jsr at 0xd420) uses it while asg_throttle_source_selector is 1: x_input = asg_reference_speed_working, result = asg_selected_droop_slope_0_30 (ASSLDP). CM848 names these tables all_speed_governor_droop_blend_128_axis / _values (0x5976e / 0x5977e)", "high"),
    0x800184: ("cm550_throttleTablePointerSetup (0x100da)", "cm550_ioControlBasedFuelCalculator (a2, jsr at 0x10072) points y_values_pointer at the stage table of engine_brake_active_cylinder_count (1-6 cylinders: engine_retarder_torque_stage_1_values .. _stage_6_values, 0x60534 .. 0x60566), writes x_input = engine_rpm_primary and divides the result x 0x6400 by engine_retarder_reference_torque_lookup's result into jcomm_ind_retarder_torque_amount_of_torque_provided_by_retarde_0_125 (JCINRDTQ, at most 32000). CM848's single lookup of cm848_calculateEngineRetarderTorque uses engine_retarder_torque_cached_axis_offset the same way", "high"),
    0x800192: ("cm550_throttleTablePointerSetup (0x100da)", "cm550_ioControlBasedFuelCalculator (pea, jsr at 0x1009a) writes x_input = the last point of the engine speed axis (*(x_axis_pointer + 8)) and looks up the 6 cylinder stage table: the reference torque the active torque is divided by", "high"),
    0x8001ea: ("cm550_initLoadTrendingSystem (0x124d2)", "cm550_coldStartFuelControlSlowCycle40Coordinator (jsr at 0x11fe0) writes x_input = engine_rpm_primary in the cylinder pressure maintenance pass (algorithm_enable_flags_3_cal.cylinder_pressure_maintenance_enable). The result is the cylinder to compression pressure ratio per timing degree: with method 1 the timing correction is (desired - calculated_cylinder_pressure_1500_3000) x 0x4444 / (ratio x the compression pressure), and the start of injection advance scales the calculated pressure by it", "high"),
    0x80020e: ("cm550_initLoadTrendingSystem (0x124d2)", "cm550_coldStartFuelControlSlowCycle40Coordinator (jsr at 0x122c6) writes x_input = engine_rpm_primary; with method 2 (cylinder_pressure_calculation_method 2, the boost path faulted) the timing correction is the result x (intake manifold temperature - expected_intake_temperature_based_on_mass_fuel_rate_calcula_50_to_293) / 0x7800, limited to +-0xaa", "high"),
    0x80024e: ("vp44_FUN_000133fe (0x133fe)", "vp44_FUN_000127c2 (jsr at 0x13000) writes x_input = current_engine_rpm_filtered and stores the result in 0x809230 (e2m 823D +48 CBDFT 'CYLINDER BALANCING FFT THRESHOLD'), which it compares with 0x809232 / 0x809234 / 0x809236 (CBDFM1 ..) to pick the trim gains", "high"),
    0x80025c: ("vp44_FUN_000133fe (0x133fe)", "vp44_FUN_000127c2 (jsr at 0x129ca) writes x_input = current_engine_rpm_filtered and subtracts the result from the real component 0x80920e (CBDFRC2) + 10000 into 0x809276 (CBDARC2 'CYLINDER BALANCING ADJUSTED REAL COMP_2', limited to +-10000)", "high"),
    0x80026a: ("vp44_FUN_000133fe (0x133fe)", "vp44_FUN_000127c2 (jsr at 0x129e8) writes x_input = current_engine_rpm_filtered and subtracts the result from the imaginary component 0x809212 (CBDFIC2) + 10000 into 0x809278 (CBDAIC2 'ADJUSTED IMAG COMP_2', limited to +-10000)", "high"),
    0x800278: ("vp44_FUN_000133fe (0x134ea-0x134fc)", "No lookup of it in the dumped ROM: the set-up's two writes are its only absolute references and no decompiled call passes it (its reader may be in the undumped ROM above 0x40000). The x axis holds the indexes 0-6, so it maps a speed bin index to its engine speed breakpoint", "medium"),
    0x800286: ("vp44_FUN_000133fe (0x13506-0x13518)", "No lookup of it in the dumped ROM (the set-up writes are its only references); the x axis holds the indexes 0-5, so it maps an index to its delta fueling breakpoint", "medium"),
    0x800294: ("vp44_FUN_000133fe (0x13522-0x13534)", "No lookup of it in the dumped ROM (the set-up writes are its only references); the x axis holds the indexes 0-5, so it maps an index to its filtered fueling breakpoint", "medium"),
    0x80058e: ("cm550_initializeEngineWarmupProtection (0x1709e)", "cm550_runEngineWarmupProtection (jsr at 0x1702e) writes x_input = the filtered coolant temperature when the rifle to turbocharger delay starts and stores the result in engine_warmup_protection_rifle_to_turbocharger_delay_time (e2m 11EA +6 WPO2DY)", "high"),
    0x80059c: ("cm550_initializeEngineWarmupProtection (0x1709e)", "cm550_runEngineWarmupProtection (jsr at 0x1708a) writes x_input = engine_rpm_primary and stores the result in engine_warmup_protection_fuel_limit (11EA +14 WPTQLM)", "high"),
    0x8005b4: ("vp44_fuelLimitParameterPointerSetup (0x17f06-0x17f1c, with the crank 4D timing records 0x8005c2 / 0x8005d8)", "No lookup of it in the dumped ROM: the set-up writes are its only absolute references (0x17f08 / 0x17f20). The crank routine takes its wet stack timing from wet_stack_timing_base_value_0_120 (wet_stack_timing_by_intake_manifold_temperature_lookup / _by_coolant_temperature_lookup) instead. Same tables as wet_stack_timing_by_intake_manifold_temperature_lookup", "medium"),
    0x8005fe: ("cm550_FUN_000185f0 (0x185f0)", "cm550_FUN_000183cc (a4 = 0x34de0 at 0x183da, five jsr (a4)) writes x_input = torque_curve_speed_at_breakpoint_1_lsg_reference_0_5000 .. _5_0_5000 in turn and stores the five results in torque_curve_fueling_at_idle_speed_breakpoint_0_100 .. _point_5_ (copied, or kept as the minimum when the EPF J1939 breakpoint flags say so). CM848's counterpart cm848_applyFaultDerateToJ1939TorqueCurveFuelings looks up the same table with fault_derate_fuel_limit_by_engine_speed_cached_axis_offset_2. Same tables as fault_derate_fuel_limit_by_engine_speed_lookup", "high"),
    0x800632: ("cm550_initShutdownLimitVariables (0x19960)", "cm550_FUN_00019702 (jsr at 0x1990c) writes x_input = engine_rpm_primary while engine_protection_fueling_severity_filtered is nonzero; fault_derate_fuel_limit (e2m 10B1 +A EPFLLM) = result + (256 - severity) x (throttle_100_fueling - result) / 256. CM848's counterpart cm848_calculateFaultDerateFuelLimit uses fault_derate_fuel_limit_by_engine_speed_cached_axis_offset", "high"),
    0x8006aa: ("cm550_FUN_0001c7a8 (0x1c7a8)", "cm550_fuelDemandTableBlendCalculator (jsr at 0x1c6b2) writes x_input = final_fueling while 0x80d706 is 1 (only a cmpi.w #1 at 0x1c698 in the dumped ROM, no writer) and uses the result instead of final_fueling as the y input of the two 4D timing lookups. Note the code uses the FPW table (DPFPTB, e2m type Y) as the axis and the TVO table (DPTVOTB, e2m type X) as the values: the reverse of the e2m pairing", "high"),
    0x80071e: ("initializeHighSpeedGovernorGainSet (0x1d2e4)", "runHighSpeedGovernorPid (jsr at 0x1cfb8) writes x_input = |hsg_filtered_engine_speed_error| and scales hsg_derivative_gain_base by the result / 256 into hsg_adjusted_derivative_gain_0_5_120 (at most 0xffff). CM848's cache word is high_speed_governor_derivative_gain_adjustment_multiplier_cached_axis_offset", "high"),
    0x80072c: ("initializeHighSpeedGovernorGainSet (0x1d2e4)", "runHighSpeedGovernorPid (jsr at 0x1d02a) writes x_input = |hsg_filtered_engine_speed_error| and scales hsg_proportional_gain_base by the result / 256 into hsg_adjusted_proportional_gain_0_7_5000 (at most 0x1e00). CM848's cache word is high_speed_governor_proportional_gain_adjustment_multiplier_cached_axis_offset", "high"),
    0x80073a: ("initializeHighSpeedGovernorGainSet (0x1d2e4)", "runHighSpeedGovernorPid (jsr at 0x1d08a) writes x_input = |hsg_filtered_engine_speed_error| and scales hsg_integral_gain_base by the result / 256 into hsg_adjusted_integral_gain_0_6_0000 (at most 0x7ae). CM848's cache word is high_speed_governor_integral_gain_adjustment_multiplier_cached_axis_offset", "high"),
    0x801a3e: ("cm550_initLookupTablePointers1 (0x25926)", "cm550_epsTimingCalculationSlowCycle40Coordinator (a2 = 0x801a3e, jsr at 0x258fe) writes x_input = engine_rpm_primary and stores the result in low_oil_pressure_limit_as_calculated_for_present_engine_speed_0_100 (0x80dabe)", "high"),
    0x801a4c: ("cm550_initLookupTablePointers1 (0x25926)", "cm550_epsTimingCalculationSlowCycle40Coordinator (pea (0xe,a2) with a2 = 0x801a3e, jsr at 0x25912) writes x_input = engine_rpm_primary and stores the result in very_low_oil_pressure_is_calculated_for_present_engine_speed_0_100 (0x80dac0)", "high"),
    0x801c0e: ("initializePowerTakeOffGovernorFiltersAndGains (0x2db2a)", "cm550_runPowerTakeOffGovernor (jsr at 0x2d48e) and cm550_presetPowerTakeOffGovernorOnEngagement (jsr at 0x2da56) write x_input = closed_loop_rpm_snapshot while 0x8088ae (e2m 10AA +16 PTGM 'CONTROL THE GAIN ADJUSTMENT CALCULATION (0=CALCULATED 1=TABLE)') is nonzero; the result << 9, limited, becomes closed_loop_rpm_based_gain (0x801bfe). CM848's cache word is power_take_off_gain_adjustment_cached_axis_offset", "high"),
    0x801c1c: ("initializePowerTakeOffGovernorFiltersAndGains (0x2db2a)", "cm550_runPowerTakeOffGovernor (jsr at 0x2d584) writes x_input = the droop compensated error 0x80dc1c (e2m 10AB +1C PTDRER) + 16000 while 0x804012 (1268 +6 PTQDEN 'ENABLE/DISABLE FOR QUADRATIC D-GAIN ADJUSTMENT') is nonzero and stores the result in 0x80dc1e (10AB +1E PTAJDG 'ADJUSTMENT (MULTIPLICATION) OF THE GOVERNER D GAIN')", "high"),
    0x801c2a: ("initializePowerTakeOffGovernorFiltersAndGains (0x2db2a)", "cm550_runPowerTakeOffGovernor (jsr at 0x2d5b0) writes x_input = 0x80dc1c (PTDRER) + 16000 while 0x804014 (PTQIEN) is nonzero and stores the result in 0x80dc20 (PTAJIG, the I gain multiplication)", "high"),
    0x801c38: ("initializePowerTakeOffGovernorFiltersAndGains (0x2db2a)", "cm550_runPowerTakeOffGovernor (jsr at 0x2d5dc) writes x_input = 0x80dc1c (PTDRER) + 16000 while 0x804016 (PTQPEN) is nonzero and stores the result in 0x80dc22 (PTAJPG, the P gain multiplication), which scales the proportional term", "high"),
    0x801e30: ("cm550_FUN_0002faa4 (0x2faa4)", "j1939FormatMultiFrameResponse (0x2f632, jsr at 0x2f6bc) writes x_input = engine_rpm_primary and compares the result with the requested braking torque (jcomm_req_torque_braking_override_or_limit_value_0_125 x the reference torque / 100) to choose the stepped retarder level (0 / 0x11 ..); the 2-5 stage lookups follow. CM848's counterpart cm848_selectEngineRetarderStagePercent uses engine_retarder_torque_stage_1_cached_axis_offset", "high"),
    0x801e3e: ("cm550_FUN_0002faa4 (0x2faa4)", "j1939FormatMultiFrameResponse (jsr at 0x2f6f4) writes x_input = engine_rpm_primary; the second stage threshold of the stepped retarder level (0x11 / 0x21). CM848: engine_retarder_torque_stage_2_cached_axis_offset", "high"),
    0x801e4c: ("cm550_FUN_0002faa4 (0x2faa4)", "j1939FormatMultiFrameResponse (jsr at 0x2f72e) writes x_input = engine_rpm_primary; the third stage threshold (0x21 / 0x32). CM848: engine_retarder_torque_stage_3_cached_axis_offset", "high"),
    0x801e5a: ("cm550_FUN_0002faa4 (0x2faa4)", "j1939FormatMultiFrameResponse (jsr at 0x2f768) writes x_input = engine_rpm_primary; the fourth stage threshold (0x32 / 0x43). CM848: engine_retarder_torque_stage_4_cached_axis_offset", "high"),
    0x801e68: ("cm550_FUN_0002faa4 (0x2faa4)", "j1939FormatMultiFrameResponse (jsr at 0x2f7a2) writes x_input = engine_rpm_primary; the fifth stage threshold (0x43 / 0x53 / 100). CM848: engine_retarder_torque_stage_5_cached_axis_offset", "high"),
    0x8036c6: ("vp44_liftPumpFuelDeliveryController (0x34cc4) itself, on every call (x_axis_offset 2 each time)", "vp44_liftPumpFuelDeliveryController (a3, jsr at 0x34d22) writes x_input = the filtered intake manifold temperature; when the result is at least the coolant one it becomes wet_stack_timing_base_value_0_120 (WSADTA) with wet_stack_timing_state 1", "high"),
    0x8036d4: ("vp44_liftPumpFuelDeliveryController (0x34cc4) itself, on every call", "vp44_liftPumpFuelDeliveryController (a2, jsr at 0x34d2c) writes x_input = the filtered coolant temperature and stores the result in wet_stack_timing_base_value_0_120; it stays there with wet_stack_timing_state 13 when it exceeds the intake manifold one", "high"),
    0x80db20: ("cm550_FUN_0001ddb4 (0x1ddb4)", "Seven callers: cm550_FUN_00026b3a (jsr at 0x26b66, x_input = engine_rpm_primary; no_load_fuel_quantity = this + the coolant correction), cm550_FUN_00014348 (a4 = 0x34de0 at 0x14352, five jsr (a4) at lsg_breakpoint_speed and the four torque curve speeds -> frictional_load_*), cm550_fuelDemandPercentageCalculator (jsr at 0x14472) and selectEngineSpeedLimit (jsr at 0x1d7f8, at the HSG droop line no load point). CM848's cache word is friction_fuel_by_engine_speed_cached_axis_offset", "high"),
    0x80db2e: ("cm550_FUN_0001ddb4 (0x1ddb4)", "cm550_FUN_00026b3a (jsr at 0x26b5c), cm550_multiSpeedParameterInterpolation (jsr at 0x143d0, result 0x80052c) and selectEngineSpeedLimit (jsr at 0x1d7e8) write x_input = the filtered coolant temperature; the result is added to the friction fuel by engine speed (no_load_fuel_quantity, no_load_fueling_curve_value_at_hsg_active_no_load_rpm_0_100)", "high"),
}
AD = ["intake_manifold_temperature", "fuel_temperature", "coolant_level", "fuel_pressure", "oil_pressure",
      "boost_pressure", "coolant_temperature", "ambient_air_temperature", "power_steering_temperature",
      "exhaust_pressure", "sampled_throttle", "remote_throttle", "ambient_air_pressure", "battery_voltage",
      "engine_speed_sensor_supply_voltage", "throttle_position_sensor_supply_voltage",
      "vehicle_connector_sensor_supply_voltage", "engine_connector_sensor_supply_voltage",
      "frequency_throttle_input_supply_voltage", "cruise_control_switch_multiplexer", "water_in_fuel",
      "egr_current_feedback", "programming_pulse_supply_voltage", "high_side_gate_bias_supply_voltage",
      "operational_amplifier_and_comparator_supply_voltage"]
CM848_TABLE = {
    "speed_request_blend_weight_by_speed_difference_axis": "0x5c272", "speed_request_blend_weight_by_speed_difference_values": "0x5c27e",
    "all_speed_governor_coolant_fuel_adjustment_axis": "0x5c242", "all_speed_governor_coolant_fuel_adjustment_values": "0x5c25a",
    "engine_retarder_torque_engine_speed_axis": "0x5a426", "engine_retarder_torque_stage_1_values": "0x5a430",
    "engine_retarder_torque_stage_2_values": "0x5a43a", "engine_retarder_torque_stage_3_values": "0x5a444",
    "engine_retarder_torque_stage_4_values": "0x5a44e", "engine_retarder_torque_stage_5_values": "0x5a458",
    "engine_retarder_torque_stage_6_values": "0x5a462",
    "fault_derate_fuel_limit_by_engine_speed_axis": "0x597d6", "fault_derate_fuel_limit_by_engine_speed_values": "0x59808",
    "friction_fuel_by_engine_speed_axis": "0x5a77c", "friction_fuel_by_engine_speed_values": "0x5a790",
    "friction_fuel_correction_by_coolant_temperature_axis": "0x5a7a4", "friction_fuel_correction_by_coolant_temperature_values": "0x5a7bc",
    "high_speed_governor_derivative_gain_adjustment_error_axis": "0x406ff0", "high_speed_governor_proportional_gain_adjustment_error_axis": "0x407028",
    "high_speed_governor_integral_gain_adjustment_error_axis": "0x407060",
    "power_take_off_gain_adjustment_axis": "0x4071ac", "power_take_off_gain_adjustment_values": "0x4071c2",
}
CM848_OTHER = {  # same Calterm record, a CM848 name that this proposal does not take
    "all_speed_governor_alternate_droop_axis": "all_speed_governor_droop_blend_0_axis (0x5974e)",
    "all_speed_governor_alternate_droop_values": "all_speed_governor_droop_blend_0_values (0x5975e)",
    "all_speed_governor_droop_axis": "all_speed_governor_droop_blend_128_axis (0x5976e)",
    "all_speed_governor_droop_values": "all_speed_governor_droop_blend_128_values (0x5977e)",
    "all_speed_governor_friction_fuel_axis": "all_speed_governor_friction_fuel_blend_128_axis (0x5c21e)",
    "all_speed_governor_friction_fuel_values": "all_speed_governor_friction_fuel_blend_128_values (0x5c230)",
    "ambient_air_pressure_linearization_axis": "barometric_pressure_linearization_axis (0x592b2)",
    "sampled_throttle_linearization_axis": "accelerator_pedal_linearization_axis (0x595fe)",
    "remote_throttle_linearization_axis": "remote_accelerator_pedal_linearization_axis (0x595da)",
}
CM848_SAME_AD = {"intake_manifold_temperature_linearization_axis": "0x59536", "intake_manifold_temperature_linearization_values": "0x59566",
                 "coolant_temperature_linearization_axis": "0x593ee", "boost_pressure_linearization_axis": "0x5937a",
                 "oil_pressure_linearization_axis": "0x595a6", "battery_voltage_linearization_axis": "0x59346"}
CM848_AD_CACHE = {"intake_manifold_temperature": "intake_manifold_temperature", "coolant_temperature": "coolant_temperature",
                  "boost_pressure": "boost_pressure", "oil_pressure": "oil_pressure", "sampled_throttle": "accelerator_pedal",
                  "remote_throttle": "remote_accelerator_pedal", "ambient_air_pressure": "barometric_pressure",
                  "battery_voltage": "battery_voltage"}
NEXT = {}
for line in open(D + "check_tables_out.txt"):
    m = re.match(r"OK\s+(0x[0-9a-f]+) \S+ \S+ \(\d+ bytes\) next e2m (\S+) at (0x[0-9a-f]+)", line)
    if m:
        NEXT[int(m.group(1), 16)] = (m.group(2), m.group(3))
DESC_COUNT = {"NZFLLMYA": "1 X 9 VALUES", "NZTALMYA": "1 X 9 VALUES", "DPFPTB": "1 BY 6", "DPTVOTB": "1 BY 6",
              "EPO2LOTB": "2X6", "EPO2VLTB": "2X6"}


def was(cur, addr):
    return f"was {cur}" if cur else f"new row, was DAT_{addr:08x}"


out = []
for r in d["records"]:
    rec = int(r["address"], 16)
    name = r["name"]
    xp, vp = int(r["axis_pointer"], 16), int(r["values_pointer"], 16)
    xm = [k for k, v in e2m.items() if False]
    tabs = {int(t["address"], 16): t for t in d["tables"]}
    if 0x80a792 <= rec < 0x80a8f0:
        n = (rec - 0x80a792) // 14
        ch = AD[n]
        comment = (f"The 14-byte table_lookup_1d_arguments_t record of cm550_lookupTableInterpolation that linearizes A/D channel {n} ({ch.replace('_', ' ')}): "
                   f"descriptor {n} of the 25 at 0x80a792 + 14n. cm550_initializeAnalogSensorChannels (0xbcf0) writes x_axis_offset 2, x_axis_pointer {ch}_linearization_axis (0x{xp:x}) and y_values_pointer {ch}_linearization_values (0x{vp:x}); "
                   f"mc68k_processAnalogSensorChannels (jsr at 0xbbb4) walks the records in steps of 14 bytes, writes x_input = {ch}_sensor_state.adc_raw_value and stores the result in its unfiltered_value while fault_active_flag is 0. "
                   + (f"CM848 looks up the same e2m axis record with the cache word {CM848_AD_CACHE[ch]}_linearization_cached_axis_offset. " if ch in CM848_AD_CACHE else "")
                   + f"No rows lie inside. (new row, was DAT_{rec:08x}; PR #53 round 95)")
        evidence = (f"cm550_initializeAnalogSensorChannels: _DAT_{rec:08x} = 2 / _DAT_{rec + 2:08x} = axis / _DAT_{rec + 8:08x} = values; "
                    f"mc68k_processAnalogSensorChannels local_8 = 0x80a792, local_8->input_value = adc_raw_value, local_8 = &local_8[1].x_axis_ptr (+14). "
                    f"RAM dump: +0 {r['dump_offset']} / +2 0x{xp:x} / +6 {r['dump_input']} / +8 0x{vp:x} / +0xc 0. 25 x 14 bytes end at 0x80a8f0 (adjusted_user_fueling).")
        conf = "high"
    else:
        setup, use, conf = S[rec]
        axis_t = tabs.get(xp)
        val_t = tabs.get(vp)
        def tdesc(p, t):
            if t:
                mn = t["e2m"].split()[1]
                return f"{t['name']} (0x{p:x}, e2m {t['e2m']} '{e2m[mn][4]}')"
            # an existing row at the pointer
            return f"0x{p:x}"
        # existing values rows (named before this round)
        existing = {0x808084: "high_speed_governor_derivative_gain_adjustment_multiplier_values (e2m 12E2 HSDVCFYA)",
                    0x8080bc: "high_speed_governor_proportional_gain_adjustment_multiplier_values (12E4 HSPPCFYA)",
                    0x8080f4: "high_speed_governor_integral_gain_adjustment_multiplier_values (12E6 HSITCFYA)",
                    0x8088cc: "power_take_off_governor_derivative_gain_adjustment_values (13AD PTGNQDTB)",
                    0x808904: "power_take_off_governor_integral_gain_adjustment_values (13AF PTGNQITB)",
                    0x80893c: "power_take_off_governor_proportional_gain_adjustment_values (13B1 PTGNQPTB)",
                    0x80721e: "wet_stack_timing_by_coolant_temperature_values (12CC WSCLTATB)",
                    0x807176: None}
        xs = tdesc(xp, axis_t) if axis_t else ("engine_retarder_torque_engine_speed_axis (0x6052a, e2m 13D6 JCBCRPXA)" if xp == 0x6052a else
                                                "wet_stack_timing_by_intake_manifold_temperature_axis (0x8071e0, e2m 1075 WSIMAI)" if xp == 0x8071e0 else
                                                "fault_derate_fuel_limit_by_engine_speed_axis (0x807176, e2m 10BA EPFLVSAI)" if xp == 0x807176 else
                                                "engine_protection_oil_pressure_limit_axis (0x611d0, e2m 10BC EPO2VSAI)" if xp == 0x611d0 else
                                                "cylinder_balance_threshold_axis (0x8072f4, e2m 8226 CBDTT1)" if xp == 0x8072f4 else f"0x{xp:x}")
        vs = tdesc(vp, val_t) if val_t else (existing.get(vp) or
                                              ("engine_retarder_torque_stage_6_values (0x60566, e2m 13D5 JC6CTQYA; re-pointed per call)" if vp == 0x60566 else
                                               "wet_stack_timing_by_intake_manifold_temperature_values (0x8071f6, e2m 1076 WSTATB)" if vp == 0x8071f6 else
                                               "fault_derate_fuel_limit_by_engine_speed_values (0x8071a8, e2m 10BB EPFLTB)" if vp == 0x8071a8 else f"0x{vp:x}"))
        inside = r["inside"]
        inside_txt = ("The rows inside are removed (were " + " / ".join(inside) + ")." ) if inside else "No other rows lie inside."
        comment = (f"The 14-byte table_lookup_1d_arguments_t record of cm550_lookupTableInterpolation: x axis {xs}, y values {vs}; the RAM dump holds both pointers. "
                   f"{setup} writes x_axis_offset 2 and the two pointers (no_interpolation_flag stays 0). {use}. {inside_txt} ({was(r['current_row'], rec)}; PR #53 round 95)")
        if rec in (0x8005b4, 0x800278, 0x800286, 0x800294):
            evidence = (f"RAM dump: +0 {r['dump_offset']} / +2 0x{xp:x} / +6 {r['dump_input']} / +8 0x{vp:x} / +0xc 0 (the 1-D record layout); e2m_block_addresses.py --firmware cm550 --address on both pointers; "
                        f"abs_refs.py: only the set-up's move.w #2 / move.l writes reference it, none of the 44 references to 0x34de0 and none of the 52 decompiled calls passes it, no reference to its +6.")
        else:
            evidence = (f"RAM dump: +0 {r['dump_offset']} / +2 0x{xp:x} / +6 {r['dump_input']} / +8 0x{vp:x} / +0xc 0; e2m_block_addresses.py --firmware cm550 --address on both pointers; "
                        f"users: the set-up writes +0 = 2 / +2 / +8 and the caller writes +6 before the call (users.py); abs_refs.py: no write to +0xc.")
    out.append({"firmware": "CM550", "address": f"0x{rec:08x}", "current_name": r["current_row"], "proposed_name": name,
                "proposed_type": "table_lookup_1d_arguments_t", "comment": comment, "evidence": evidence, "confidence": conf})

for t in d["tables"]:
    a = int(t["address"], 16)
    mn = t["e2m"].split()[1]
    unit, block, off, typ, desc = e2m[mn]
    is_axis = t["name"].endswith("_axis")
    users = [r["name"] for r in d["records"] if int(r["axis_pointer" if is_axis else "values_pointer"], 16) == a]
    if t["name"].startswith("engine_retarder_torque_stage_") and not users:
        users = []
    role = "x axis" if is_axis else "y values"
    words = int(re.search(r"\[(\d+)\]", t["type"]).group(1))
    if t["dump_count"] is not None and a >= 0x800000:
        if mn in ("CBDDCT", "CBDI2DCT"):
            content = (f"16 values with no byte count word (all 10000 = 0 in the dump; minimum -10000, stored plus 10000); the next record starts 32 bytes on. "
                       f"vp44_FUN_000127c2 writes it at index 0x800320 (0x12b2e-0x12c1a) and resets it to 10000 from its first word (0x12c42). With the 16-point axis the lookup reads values + 2 .. + 32, so its last point reads the word after the table (a firmware quirk)")
        else:
            pts = [word(a + 2 + 2 * k) for k in range(t["dump_count"] // 2)]
            shown = " / ".join(str(p) for p in pts[:8]) + (" .." if len(pts) > 8 else "")
            content = f"the dump holds byte count {t['dump_count']} then {len(pts)} {unit or 'raw'} values ({shown})"
    else:
        nr = NEXT.get(a)
        content = (f"ROM beyond the 256 KB dump, so no value: word[{words}] from the e2m layout (the next record {nr[0]} starts at {nr[1]})" if nr else "ROM beyond the dump")
        if mn in DESC_COUNT:
            content += f", as its description says ('{DESC_COUNT[mn]}')"
    users_txt = (" / ".join(users)) if users else ""
    if t["name"] == "engine_retarder_torque_engine_speed_axis":
        users_txt = "engine_retarder_torque_lookup / engine_retarder_reference_torque_lookup / engine_retarder_torque_stage_1_lookup .. _stage_5_lookup"
    if t["name"].startswith("engine_retarder_torque_stage_") and t["name"] != "engine_retarder_torque_stage_6_values":
        n = t["name"].split("_")[4]
        users_txt = f"engine_retarder_torque_stage_{n}_lookup and of engine_retarder_torque_lookup when engine_brake_active_cylinder_count is {n}"
    if t["name"] == "engine_retarder_torque_stage_6_values":
        users_txt = "engine_retarder_reference_torque_lookup and of engine_retarder_torque_lookup with 6 active cylinders"
    if t["name"].startswith("fault_derate_fuel_limit_by_engine_speed"):
        users_txt = "fault_derate_fuel_limit_by_engine_speed_lookup and fault_derate_fuel_limit_at_torque_curve_points_lookup"
    if t["name"].startswith("wet_stack_timing_by_intake_manifold_temperature"):
        users_txt = "wet_stack_timing_by_intake_manifold_temperature_lookup (and the unread crank_wet_stack_timing_by_intake_manifold_temperature_lookup)"
    if t["name"] == "engine_protection_oil_pressure_limit_axis":
        users_txt = "engine_protection_low_oil_pressure_limit_lookup and engine_protection_very_low_oil_pressure_limit_lookup"
    if t["name"] == "cylinder_balance_threshold_axis":
        users_txt = "cylinder_balance_threshold_lookup / cylinder_balance_real_2_dynamics_compensation_lookup / cylinder_balance_imaginary_2_dynamics_compensation_lookup (the engine speed axis of all three)"
    cm848 = ""
    if t["name"] in CM848_TABLE:
        cm848 = f" CM848 names the same record {t['name']} ({CM848_TABLE[t['name']]})."
    elif t["name"] in CM848_SAME_AD:
        cm848 = f" CM848 names the same record {t['name']} ({CM848_SAME_AD[t['name']]})."
    elif t["name"] in CM848_OTHER:
        cm848 = f" CM848 names the same record {CM848_OTHER[t['name']]}."
    inside_txt = (" The rows inside are removed (were " + " / ".join(t["inside"]) + ").") if t["inside"] else ""
    cur = t["current_row"].split(" (")[0] if t["current_row"] else ""
    comment = (f"e2m {block} +{off} {mn} '{desc}' ({unit or 'no unit'}; e2m type {typ}): the {role} of {users_txt}; {content}.{cm848}{inside_txt} ({was(cur, a)}; PR #53 round 95)")
    if a >= 0x800000 and t["dump_count"] is not None and mn not in ("CBDDCT", "CBDI2DCT"):
        ev = f"RAM dump word at 0x{a:x} = {t['dump_count']} (byte count) -> word[{words}]; it ends at the next e2m record ({NEXT[a][0]} at {NEXT[a][1]}); the record pointer is 0x{a:x}; abs_refs.py: 0 references to the rows inside"
    elif mn in ("CBDDCT", "CBDI2DCT"):
        ev = f"e2m 823E CBDDCT at 0x809e9e and 823F CBDI2DCT at 0x809ebe are 32 bytes apart, the next record SSECTMEA at 0x809ede; writer 0x12b2e-0x12c1a movea.l #0x809e9e / #0x809ea0 / #0x809ebe / #0x809ec0 with index (0x800320).w*2; reset 0x12c42 move.w #0x2710,(a5)+ from 0x809e9e"
    else:
        ev = f"ROM 0x{a:x} is above the 0x40000 dump; next_record.py: the next e2m record {NEXT[a][0]} at {NEXT[a][1]} -> {2 * words} bytes = word[{words}]; the record pointer is 0x{a:x} in the RAM dump"
    conf = "high" if (a >= 0x800000 or mn in DESC_COUNT) else "medium"
    out.append({"firmware": "CM550", "address": f"0x{a:08x}", "current_name": cur, "proposed_name": t["name"],
                "proposed_type": t["type"], "comment": comment, "evidence": ev, "confidence": conf})
json.dump(out, open(D + "globals_out.json", "w"), indent=1)
print(len(out), "entries")
