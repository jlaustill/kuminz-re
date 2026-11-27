"""Round 62 stage A: the J1939 registration functions and a few vague Bank 2 helpers named from their code; the DM7 test
identifier; the J1939 input fault start delay; one more combustion torque cache; the validator plate's key test
(none of the old names is in CM550 or either CLAUDE.md). Idempotent.  usage: apply_r62a.py <repo> <map.csv>"""
import os
import re
import sys

sys.path.insert(0, "/home/linux/.claude/jobs/374b0424/tmp/w15/r53")
from e2m_cite import Records, Rows  # noqa: E402

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
O = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 62"
fp = os.path.join(O, "function_renames.csv")
fr = open(fp).read()
if "cm848_registerJ1939MemoryWriteServices," in fr:
    print("already applied")
    sys.exit(0)
rec = Records(repo)
g = Rows(repo, R)
g.rename(rec, "0x003fa97a", "j1939_dm1_request_mode_byte", "j1939_dm7_test_identifier", None, None,
         "The DM7 request's Test Identifier (PGN 58112 Command Non-continuously Monitored Test - its first byte - SPN "
         "1224): cm848_j1939HandlePgn58112Dm7 answers 0 with the intake air heater monitor result and 1 with the misfire "
         "monitor result (DM8 - PGN 65232) when supported_non_continuous_monitors_bits marks the monitor; 0 / 1 without "
         "it get a NACK and other values no answer.")
g.rename(rec, "0x0040aaa4", "governor_table_check_startup_delay", "j1939_input_fault_start_delay", None, None,
         "Set to 1000 by cm848_registerJ1939InputMessageHandlers; cm848_tickJ1939InputSupervision counts it down while "
         "the J1939 multiplex layer is enabled. While it is nonzero cm848_processJ1939AcceleratorInputs / "
         "cm848_processJ1939SwitchAndRequestInputs clear the J1939 input data error and timeout faults instead of "
         "setting them. Nothing about a governor table.")
p = g.row("0x003fcbdc")
assert p[1] == "" and p[2] == "ema_filter_state_t", p
g.check("pedal_fault_mode_engine_speed_filter_state")
g.g[g.idx["0x003fcbdc"]] = ("0x003fcbdc,pedal_fault_mode_engine_speed_filter_state,ema_filter_state_t,The EMA filter of "
                            "engine_speed_state.engine_speed in cm848_calculatePedalFaultModeFuelDemandAndSpeedLimit: "
                            "cm848_initDroopModeStateVariables points its coefficient at "
                            "pedal_fault_mode_engine_speed_filter_coefficient and cm848_presetPedalFaultModeFuelDemand "
                            f"loads the accumulator with the current speed (was ema_filter_state_t_003fcbdc - a type-only "
                            f"row; {R}) | earlier note: {p[3]}")
g.mapping.append("0x003fcbdc,pedal_fault_mode_engine_speed_filter_state,ema_filter_state_t_003fcbdc,global,1")
p = g.row("0x0005c48e")
assert p[1] == "" and p[2] == "word", p
g.check("pedal_fault_mode_engine_speed_filter_coefficient")
g.g[g.idx["0x0005c48e"]] = ("0x0005c48e,pedal_fault_mode_engine_speed_filter_coefficient,word,The weight of the previous "
                            "value (1/65536) of pedal_fault_mode_engine_speed_filter_state - a ROM word (was WORD_0005c48e "
                            f"- a type-only row; {R}) | earlier note: {p[3]}")
g.mapping.append("0x0005c48e,pedal_fault_mode_engine_speed_filter_coefficient,WORD_0005c48e,global,1")
g.add_text("0x003fba0c", "combustion_torque_by_fuel_quantity_timing_adjusted_cached_axis_offsets", "word[2]",
           "The x / y cache of cm848_calculateNetCombustionTorque's combustion_torque_by_fuel_quantity lookup with "
           "total_injection_quantity_timing_adjusted (its other lookup of the grid keeps "
           "combustion_torque_by_fuel_quantity_cached_axis_offsets); cm848_initializeTorqueLookupCaches sets both words "
           "to 2", None)
g.mapping.append("0x003fba0c,combustion_torque_by_fuel_quantity_timing_adjusted_cached_axis_offsets,DAT_003fba0c,global,2")
g.save(map_path)

FUNCS = [
    ("j1939_diag_request_batch_init", "cm848_registerJ1939ParameterAndBroadcastServices",
     "From cm848_j1939_system_init: registers the PGN 61184 diagnostic services 0x0f / 0x10 (get parameters by ID - "
     "j1939_diagService15And16Handler) and 4 / 5 (disable / enable broadcast) in j1939_diagnostic_service_table"),
    ("j1939_diag_request_batch_44to49", "cm848_registerJ1939MemoryWriteServices",
     "From cm848_j1939_system_init: registers the PGN 61184 memory write services 0x44 / 0x45 / 0x4b / 0x4d / 0x47 / "
     "0x49 (the j1939_diagService68-77 write handlers) in j1939_diagnostic_service_table"),
    ("j1939_diag_request_batch_43to48", "cm848_registerJ1939MemoryReadServices",
     "From cm848_j1939_system_init: registers the PGN 61184 memory read services 0x43 / 0x4a / 0x4c / 0x46 / 0x48 (the "
     "j1939_diagService67-76 read handlers) in j1939_diagnostic_service_table"),
    ("j1939_diag_request_41_handler", "cm848_registerJ1939GetAddressByParameterIdService",
     "From cm848_j1939_system_init: registers the PGN 61184 service 0x41 (get address by parameter ID - "
     "j1939_diagService65_getAddressByParameterId) in j1939_diagnostic_service_table"),
    ("j1939_pgn_handler_init_batch", "cm848_registerJ1939InputMessageHandlers",
     "From cm848_j1939_system_init: registers the J1939 input layer's receive handlers (PGN 57344 / 61441 EBC1 / 61443 "
     "EEC2 / 65252 / 65264 / 65265 CCVS1 - the j1939_receivePgn<N>Handler functions) and starts "
     "j1939_input_fault_start_delay at 1000"),
    ("cm848_initJ1939Dm1RequestHandler", "cm848_registerJ1939Dm7Handler",
     "From cm848_j1939_system_init: registers cm848_j1939HandlePgn58112Dm7 for PGN 58112 (DM7 - command a "
     "non-continuously monitored test). Nothing about DM1"),
    ("fuel_boostTrim_ramVars_init", "cm848_initializeTorqueLookupCaches",
     "From cm848_initialization_step_4: sets the lookup caches injection_timing_torque_to_fuel_gain_cached_axis_offsets "
     "and combustion_torque_by_fuel_quantity_timing_adjusted_cached_axis_offsets to 2 (both words). Nothing about boost "
     "trim"),
    ("fuel_demandLimit_calPtrs_init", "cm848_initializeOxygenLimitLookupCaches",
     "From cm848_initialization_step_4: sets the lookup caches oxygen_limit_equivalence_ratio_cached_axis_offsets (both "
     "words) and oxygen_limit_ambient_pressure_gain_cached_axis_offset to 2"),
    ("governor_speedRatio_etcFuelCorrection_calc", "cm848_calculateFrictionTorquePercentAndNetOutputTorque",
     "From cm848_runEmissionManager: the indicated friction torque percent x 256 = (friction_fueling + "
     "friction_fuel_adjustment_for_coolant_temperature - zero_torque_fueling) x 25600 / (j1939_reference_engine_fueling "
     "- zero_torque_fueling) - 0 when either difference is not positive - capped at 32000 (125 %); then "
     "j1939_powertrain_control_state.engine_net_output_torque (e2m 10E8 +28) = (actual percent torque - friction "
     "percent) x reference_engine_torque_working / 0x43ca / 2"),
    ("fuel_demand_periodSnapshot_save", "cm848_presetPedalFaultModeFuelDemand",
     "From cm848_transitionEngineOperatingMode: presets the pedal fault mode - pedal_fault_mode_fuel_demand_ramp and "
     "pedal_fault_mode_fuel_demand_limit_previous take final_fueling and pedal_fault_mode_engine_speed_filter_state's "
     "accumulator takes the current engine speed"),
]
original = fr
mapping = []
for cur, new, plate in FUNCS:
    m = re.search(rf"^(0x[0-9a-f]{{8}}),{cur}(,[^\n]*)?$", fr, re.M)
    assert m, cur
    assert re.fullmatch(r"cm848_[a-z][A-Za-z0-9]*", new) and not re.search(rf"\b{new}\b", original), new
    assert "," not in plate, (cur, plate[:60])
    old_plate = (m.group(2) or ",")[1:].strip()
    text = f"{plate} (was {cur}; {R})" + (f" | earlier note: {old_plate}" if old_plate else "")
    fr = fr[:m.start()] + f"{m.group(1)},{new},{text}" + fr[m.end():]
    mapping.append(f"{m.group(1)},{new},{cur},function,1")
old = "calibration_download_security_key_cal is set the request must carry the key"
assert fr.count(old) == 1
fr = fr.replace(old, "calibration_download_security_key_cal is not 0xff the request must carry the key")
open(fp, "w").write(fr)
with open(map_path, "a") as fh:
    fh.write("\n".join(mapping) + "\n")
print(f"4 globals, 1 cache row, {len(FUNCS)} functions, the validator plate")
