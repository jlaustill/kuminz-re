"""Stage 6a (PR #52): the cm848_signedFirstOrderFilter records typed as the existing ema_filter_state_t.

cm848_signedFirstOrderFilter (0x5644c) reads its record exactly like exponentialMovingAverage reads an
ema_filter_state_t: [0] a pointer to the 16-bit coefficient (read as *(short *); 0 = no filtering), [1] the Q16.16
accumulator (written whole). It moves the accumulator (65536 - coefficient) / 65536 of the way to the sample and returns
the integer part, signed. Two records (egr_valve_delta_pressure_filter_state / egr_valve_derivative_filter_state) and
the sensor channels' records were already ema_filter_state_t.
- every global record passed to it becomes an ema_filter_state_t instance, named after what it filters (the call's
  output, or its input when the output is a local); the +4 accumulator rows go (the narrow ones rendered `_name`
  because the code stores a dword there);
- the coefficients it points at become words (the filter reads 16 bits; 12 of 13 were typed byte), misleading names fixed,
  the ROM-copy `_cal` dropped, ten unnamed coefficients get rows;
- full prototypes for cm848_signedFirstOrderFilter and cm848_conditionalFirstOrderFilter (the value param int32_t, the return sword:
  in ApplyFunctionDefinitions `int` maps to an unsigned dword, and a locked 32-bit return put a temp and a cast at
  every call; the filter returns a sign-extended 16-bit value, and `sword` resolves by name to Ghidra's signed word).
Writes map_stage6a.csv (the renames, for refresh_references.py).
usage: apply_stage6a_filter_records.py <CM848 output dir>"""
import os
import sys

OUT = sys.argv[1]
here = os.path.dirname(os.path.abspath(__file__))
TYPE = "ema_filter_state_t"
FILTER = "cm848_signedFirstOrderFilter"

RECORDS = [  # (address, old name ('' = unnamed), new name ('' = type only), function, what it filters)
    ("0x003fa138", "", "charge_flow_turbocharger_speed_derate_offset_filter",
     "cm848_calculateChargeFlowTurbochargerSpeedDerate", "produces charge_flow_turbocharger_speed_derate_offset"),
    ("0x003fa140", "", "charge_flow_compressor_outlet_temperature_derate_offset_filter",
     "cm848_calculateChargeFlowCompressorOutletTemperatureDerate",
     "produces charge_flow_compressor_outlet_temperature_derate_offset"),
    ("0x003fa148", "", "charge_flow_delta_pressure_derate_offset_filter",
     "cm848_calculateChargeFlowDeltaPressureDerate", "produces charge_flow_delta_pressure_derate_offset"),
    ("0x003fa5c2", "throttle_filter_coeff_table_b_pointer", "egr_mass_flow_delayed_filter",
     "cm848_throttleBasedFuelCalculation", "produces egr_mass_flow_delayed_filtered from the circular-buffer-delayed sample"),
    ("0x003fa5ca", "throttle_filter_coeff_data_pointer", "egr_valve_position_filter",
     "cm848_calculateLoadBasedFuelTrim", "smooths egr_valve_position (into x_input)"),
    ("0x003fa5ea", "", "predicted_intake_manifold_temperature_filter",
     "cm848_calculatePredictedIntakeManifoldTemperature", "produces predicted_intake_manifold_temperature"),
    ("0x003fa60e", "", "fuel_demand_boost_offset_filter",
     "cm848_processBoostProtectionMode", "produces fuel_demand_boost_offset_filtered"),
    ("0x003fa624", "", "pressure_correction_first_filter", "cm848_calculatePressureSensorFiltered",
     "the first of two cascaded filters: pressure_correction_raw into pressure_correction_filter1_working"),
    ("0x003fa62c", "", "pressure_correction_second_filter", "cm848_calculatePressureSensorFiltered",
     "the second cascaded filter, on pressure_correction_filter1_working; same coefficient as the first"),
    ("0x003fa6f4", "throttle_fuel_pgn_handler_pointer", "fuel_demand_delta_filter",
     "cm848_fuelDemandFinalCalculation", "produces fuel_demand_control delta_filtered from its delta"),
    ("0x0040a8d3", "high_speed_governor_error_filter_coefficient_pointer", "high_speed_governor_error_filter",
     "runHighSpeedGovernorPid", "the speed error filter of the high speed governor PID (its coefficient is computed)"),
    ("0x003faf56", "governor_speed_filter_state_ptr", "governor_speed_filter",
     "cm848_runLowSpeedGovernor", "produces governor_speed_filter_output"),
    ("0x003faf66", "governor_bank2_cal_ptr", "governor_speed_error_delta_filter",
     "cm848_calculateSpeedRateLimiting",
     "produces governor_speed_error_delta; the code presets the accumulator to the clamped value << 16"),
    ("0x003fafb2", "protection_filter_state_ptr", "power_take_off_speed_error_filter",
     "cm848_calculatePowerTakeOffGovernorSpeedError",
     "produces power_take_off_governor_filtered_speed_error; the accumulator is preset to the clamped value << 16 and "
     "zeroed at initialization and on engagement"),
    ("0x003fb01e", "", "turbocharger_speed_estimate_boost_lead_term_filter", "cm848_estimateTurbochargerSpeed",
     "produces turbocharger_speed_estimate_boost_lead_term from turbocharger_speed_estimate_boost_lead_term_unfiltered"),
    ("0x003fb03e", "variable_geometry_turbocharger_derivative_filter_coefficient_pointer",
     "variable_geometry_turbocharger_derivative_filter", "cm848_calculateVariableGeometryTurbochargerPidDuty",
     "the derivative term filter of the variable geometry turbocharger PID"),
    ("0x003fb0d2", "variable_geometry_turbocharger_closed_position_filter_coefficient_pointer",
     "variable_geometry_turbocharger_closed_position_filter", "cm848_filterVariableGeometryTurbochargerClosedPosition",
     "smooths the variable geometry turbocharger closed position"),
    ("0x003fb1ce", "protection_load_filter_state_b_ptr", "transmission_output_speed_change_filter",
     "cm848_filterProtectionLoadValue", "produces transmission_output_speed_change from protection_load_rate_delta"),
    ("0x003fb1d6", "protection_load_scaled_filter_state_ptr", "protection_load_scaled_input_filter",
     "cm848_updateTransmissionConditionFlags",
     "produces protection_load_scaled_input from half of engine_acceleration_unfiltered"),
    ("0x003fb3b0", "engine_acceleration_first_stage_filter_state", "engine_acceleration_first_stage_filter_state",
     "cm848_processEngineRpmDerivative", "the first of the two engine acceleration filters"),
    ("0x003fb3b8", "engine_acceleration_second_stage_filter_state", "engine_acceleration_second_stage_filter_state",
     "cm848_processEngineRpmDerivative", "the second of the two engine acceleration filters"),
    ("0x003fb414", "coolant_temp_filter_state_ptr", "pci_coolant_temperature_filter",
     "cm848_buildPciTransmitMessage14VoltageOilPressureTemperatures",
     "produces coolant_temp_filtered from coolant_temperature_in_use for PCI message 14"),
    ("0x003fb687", "cam_sync_speed_filter_ptr", "fuel_metering_feedback_filter", "cm848_calculateFuelMeteringCommand",
     "smooths fuel_metering_feedback_input; fuel_metering_feedback_error = fuel_metering_reference_filter's output "
     "minus this one's"),
    ("0x003fb68f", "cam_sync_fault_filter_ptr", "fuel_metering_reference_filter", "cm848_calculateFuelMeteringCommand",
     "smooths the reference looked up from cam_sync_ref_output_axis_cal / cam_sync_ref_output_values_cal"),
    ("0x003fb69f", "cam_sync_filter_state_pointer", "fuel_pressure_sensor_filter", "cm848_calculateFuelMeteringCommand",
     "smooths fuel_pressure_sensor for the fuel pressure governor; before each call the code points the coefficient at "
     "a value it computes on the stack (cm848_resetEngineSyncState starts it at engine_sync_scale_factor_cal)"),
    ("0x003fb6a7", "cam_sync_fuel_filter_state_pointer", "fuel_pressure_governor_accelerator_feed_forward_filter",
     "cm848_calculateFuelMeteringCommand", "produces fuel_pressure_governor_accelerator_feed_forward"),
    ("0x003fb6af", "cam_sync_rate_filter_state_pointer", "fuel_metering_command_filter",
     "cm848_calculateFuelMeteringCommand", "smooths engine_sync_state fuel_metering_command (into cam_speed_rate)"),
    ("0x003fb6f3", "fuel_pressure_feedback_filter_pointer", "fuel_pressure_feedback_filter",
     "cm848_filterFuelPressureFeedback", "produces fuel_pressure_feedback_filtered from fuel_pressure_at_injection_scheduling"),
    ("0x003fb9e2", "", "", "hpcr_fuelFinal_exponentialAverage",
     "smooths ambient_air_temperature_selected minus boost_fuel_timing_target - left unnamed because those two names "
     "look suspect"),
    ("0x0040b2d4", "cooling_fan_speed_feedback_filter", "cooling_fan_speed_feedback_filter", "cm848_runCoolingFanSpeedPid",
     "produces cooling_fan_speed_feedback_filtered"),
    ("0x0040b2dc", "cooling_fan_proportional_derivative_filter", "cooling_fan_proportional_derivative_filter",
     "cm848_runCoolingFanSpeedPid", "produces cooling_fan_proportional_derivative_term"),
    ("0x0040b2e4", "cooling_fan_coolant_temperature_filter", "cooling_fan_coolant_temperature_filter",
     "cm848_selectCoolingFanSpeedTarget", "smooths the coolant temperature for the fan speed target"),
    ("0x0040b2ec", "cooling_fan_intake_temperature_filter", "cooling_fan_intake_temperature_filter",
     "cm848_selectCoolingFanSpeedTarget", "smooths the intake temperature for the fan speed target"),
]
COEFFICIENTS = [  # (address, old name, new name, dump value) - retyped to word
    ("0x004002f0", "throttle_filter_coeff_data_cal", "egr_valve_position_filter_coefficient", 32768),
    ("0x004002e2", "throttle_filter_coefficient", "egr_mass_flow_delayed_filter_coefficient", 59638),
    ("0x004070e4", "governor_speed_filter_state_cal", "governor_speed_filter_coefficient", 32706),
    ("0x00407720", "variable_geometry_turbocharger_derivative_filter_coefficient",
     "variable_geometry_turbocharger_derivative_filter_coefficient", 32768),
    ("0x0040834a", "protection_load_scaled_filter_state_cal", "protection_load_scaled_input_filter_coefficient", 60293),
    ("0x00408362", "protection_load_filter_state_b_cal", "transmission_output_speed_change_filter_coefficient", 64225),
    ("0x00408808", "engine_acceleration_first_stage_filter_coefficient",
     "engine_acceleration_first_stage_filter_coefficient", 0),
    ("0x0040880a", "engine_acceleration_second_stage_filter_coefficient",
     "engine_acceleration_second_stage_filter_coefficient", 57671),
    ("0x0040912e", "cam_sync_fuel_filter_state_cal", "fuel_pressure_governor_accelerator_feed_forward_filter_coefficient",
     58982),
    ("0x00409128", "cam_sync_fault_filter_state_cal", "fuel_metering_reference_filter_coefficient", 0),
    ("0x00409126", "cam_sync_speed_error_filter_state_cal", "fuel_metering_feedback_filter_coefficient", 59297),
    ("0x0040914e", "cam_sync_rate_filter_state_cal", "fuel_metering_command_filter_coefficient", 16384),
    ("0x004095a2", "fuel_pressure_feedback_filter_constants", "fuel_pressure_feedback_filter_coefficient", 0),
]
NEW_COEFFICIENTS = [  # (address, name, dump value, where the value comes from)
    ("0x003ff71c", "charge_flow_compressor_outlet_temperature_derate_offset_filter_coefficient", 0, "RAM dump"),
    ("0x003ff724", "charge_flow_delta_pressure_derate_offset_filter_coefficient", 64684, "RAM dump"),
    ("0x003ff72c", "charge_flow_turbocharger_speed_derate_offset_filter_coefficient", 0, "RAM dump"),
    ("0x004009d6", "predicted_intake_manifold_temperature_filter_coefficient", 53738, "RAM dump"),
    ("0x00405200", "fuel_demand_boost_offset_filter_coefficient", 65404, "RAM dump"),
    ("0x00405206", "pressure_correction_filter_coefficient", 62966, "RAM dump"),
    ("0x0005c2aa", "fuel_demand_delta_filter_coefficient", 32768, "flash"),
    ("0x0005c4ae", "governor_speed_error_delta_filter_coefficient", 0, "flash"),
    ("0x0040729e", "turbocharger_speed_estimate_boost_lead_term_filter_coefficient", 63896, "RAM dump"),
    ("0x00408972", "pci_coolant_temperature_filter_coefficient", 57672, "RAM dump"),
]
PROTOTYPES = [
    "0x0005644c,cm848_signedFirstOrderFilter,return,,sword,Filtered value: the integer part of the updated accumulator "
    "(signed)",
    "0x0005644c,cm848_signedFirstOrderFilter,0,value,int32_t,New sample (r3) - signed",
    "0x0005644c,cm848_signedFirstOrderFilter,1,filter_state,ema_filter_state_t *,Filter state (r4) - coefficient "
    "pointer and Q16.16 accumulator - updated in place; coefficient 0 = no filtering (the signed twin of "
    "exponentialMovingAverage)",
    "0x000185cc,cm848_conditionalFirstOrderFilter,return,,sword,The filtered value - or with update_enable 0 the "
    "integer part of the accumulator unchanged",
    "0x000185cc,cm848_conditionalFirstOrderFilter,0,value,int32_t,New sample (r3)",
    "0x000185cc,cm848_conditionalFirstOrderFilter,1,update_enable,int32_t,0 = only read the filter output (r4)",
    "0x000185cc,cm848_conditionalFirstOrderFilter,2,filter_state,ema_filter_state_t *,Filter state (r5) passed to "
    "cm848_signedFirstOrderFilter",
]


def value_text(v):
    return f"{v} = {v / 65536:.3f}"


path = os.path.join(OUT, "global_variables.csv")
lines = open(path, newline="").read().split("\n")


def find(address):
    hits = [i for i, line in enumerate(lines) if line.split(",", 1)[0] == address]
    assert len(hits) == 1, (address, len(hits))
    return hits[0]


renames, removed = [], []
for address, old, new, function, what in RECORDS:
    i = find(address)
    a, name, typ, comment = (lines[i].split(",", 3) + [""])[:4]
    assert name == old, (address, name, old)
    base = int(address, 16)
    inside = [k for k, line in enumerate(lines) if line.startswith("0x")
              and base < int(line.split(",", 1)[0], 16) < base + 8]
    was = []
    for k in sorted(inside, reverse=True):
        a2, name2, typ2 = lines[k].split(",", 3)[:3]
        removed.append((a2, name2, typ2))
        was.append(f"+{int(a2, 16) - base} {name2 or 'unnamed'} {typ2}")
        del lines[k]
    i = find(address)
    history = []
    if old and old != new:
        history.append(f"was {old}")
    if was:
        history.append("the accumulator rows " + " / ".join(reversed(was)))
    note = f" ({'; '.join(history)})" if history else ""
    keep = f" | earlier note: {comment}" if comment and old == new else ""
    lines[i] = ",".join([a, new, TYPE,
                         f"{FILTER} record ({TYPE}: coefficient pointer + Q16.16 accumulator) - {function}: {what}"
                         f"{note}{keep}"])
    if old and old != new:
        renames.append((address, new, old))
    elif not old and new:
        renames.append((address, new, f"PTR_DAT_{base:08x}"))

for address, old, new, value in COEFFICIENTS:
    i = find(address)
    a, name, typ, comment = (lines[i].split(",", 3) + [""])[:4]
    assert name == old, (address, name, old)
    history = f" (was {old}, typed {typ})" if old != new else f" (was typed {typ})"
    lines[i] = ",".join([a, new, "word", f"Coefficient of a {FILTER} record, read through its coefficient pointer as a "
                                         f"16-bit word: the weight of the previous value in 1/65536 ({value_text(value)} "
                                         f"in the RAM dump; 0 = no filtering) - ROM copy, no _cal{history}"])
    if old != new:
        renames.append((address, new, old))

for address, name, value, source in NEW_COEFFICIENTS:
    base = int(address, 16)
    assert not any(line.split(",", 1)[0] == address for line in lines), address
    after = max(k for k, line in enumerate(lines) if line.startswith("0x") and int(line.split(",", 1)[0], 16) < base
                and abs(int(line.split(",", 1)[0], 16) - base) < 0x100)
    lines.insert(after + 1, ",".join([address, name, "word",
                                      f"Coefficient of a {FILTER} record (read through its coefficient pointer as a "
                                      f"16-bit word): the weight of the previous value in 1/65536 - {value_text(value)} "
                                      f"in the {source}; 0 = no filtering (new row 2026-11-19)"]))
    renames.append((address, name, f"DAT_{base:08x}"))
open(path, "w", newline="").write("\n".join(lines))

path = os.path.join(OUT, "function_definitions.csv")
text = open(path, newline="").read()
assert "0x0005644c," not in text and "0x000185cc," not in text
anchor = "0x00056594,exponentialMovingAverage,1,filter_state,ema_filter_state_t *,"
k = text.index(anchor)
end = text.index("\n", k) + 1
text = text[:end] + "\n".join(PROTOTYPES) + "\n" + text[end:]
open(path, "w", newline="").write(text)

with open(os.path.join(here, "map_stage6a.csv"), "w") as f:
    f.write("address,name,old_label,kind\n")
    for address, new, old in renames:
        f.write(f"{address},{new},{old},global\n")
with open(os.path.join(here, "stage6a_removed_rows.txt"), "w") as f:
    f.write("\n".join(",".join(r) for r in removed) + "\n")
print(f"{len(RECORDS)} records, {len(removed)} accumulator rows removed, {len(COEFFICIENTS)} coefficients retyped, "
      f"{len(NEW_COEFFICIENTS)} new coefficient rows, {len(renames)} renames in the map")
