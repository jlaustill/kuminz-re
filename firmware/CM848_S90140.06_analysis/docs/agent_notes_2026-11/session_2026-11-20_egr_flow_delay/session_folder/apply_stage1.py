"""Stage 1 (label-only): the EGR transport delay stage at 0x128a0 and the e2m 177F struct.

Run after rename_struct_types.py has renamed the type and the instance:
  rename_struct_types.py <out> map_struct.csv throttle_fuel_trim_t=egr_flow_estimate_terms_t@0x0040a3ea=egr_flow_estimate_terms
Usage: apply_stage1.py <firmware output dir> <scratch dir>
Writes <scratch>/map_stage1.csv (proof mapping, fields + functions + globals) and
<scratch>/map_refresh_stage1.csv (old -> new pairs for refresh_references.py)."""
import csv
import os
import sys

out, scratch = sys.argv[1:3]
INSTANCE, TYPE = "egr_flow_estimate_terms", "egr_flow_estimate_terms_t"
OLD_INSTANCE, OLD_TYPE = "throttle_fuel_trim_t_0040a3ea", "throttle_fuel_trim_t"

# offset, old field, new field, comment (quoted in the CSV; no double quotes inside)
FIELDS = [
    (0x00, "residual_oxygen_fraction_delayed_filtered", "egr_oxygen_fraction",
     "e2m 177F +0 CHP_O2_Frac_EGR 'Oxygen fraction in EGR' (1/8192; 8192 = 1.0 in the RAM dump with the engine "
     "stopped): residual_oxygen_fraction_before_delay delayed by oxygen_flow_delay_milliseconds and filtered in "
     "cm848_calculateDelayedEgrFlowAndFraction; read by cm848_calculateCylinderOxygenMasses "
     "(was residual_oxygen_fraction_delayed_filtered)"),
    (0x02, "egr_fraction_actual", "egr_fraction_actual",
     "e2m 177F +2 EGR_Fraction (1/8192; capped at 8192 = 1.0): egr_mass_flow_delayed_filtered x 8192 / "
     "charge_mass_flow_filtered in cm848_calculateDelayedEgrFlowAndFraction (0 while the charge flow is 64 counts "
     "= 0.5 lb/min or less). The e2m text says 'Charge Mgr demanded EGR fraction after limiters' but the code "
     "computes the delayed flow ratio. Readers: cm848_calculateChargeSystemErrors / "
     "cm848_calculateAirFuelRatioAndIntakeOxygenFraction / cm848_calculateWaterVaporAndSaturationTemperatures"),
    (0x04, "final_trim", "egr_mass_flow_before_delay",
     "e2m 177F +4 CHP_EGR_Flow_Before_Delay 'EGR flow before delay is imposed' (signed lb/min x 128): "
     "cm848_calculateEgrMassFlowBeforeDelay limits the selected model (upstream_egr_mass_flow or "
     "downstream_egr_mass_flow) to egr_mass_flow_estimate_minimum .. egr_mass_flow_estimate_maximum and forces 0 "
     "while egr_valve_closed_flag is set (was final_trim)"),
    (0x06, "load_adjusted", "egr_flow_delay_milliseconds",
     "e2m 177F +6 CHP_EGR_Flow_Delay 'Delay between air passing EGR valve and when that air reaches the intake "
     "valve' (0.001 s per count): oxygen_flow_delay_milliseconds x egr_flow_delay_fraction / 32767; its tenth is "
     "the EGR mass flow delay in 10 ms samples (was load_adjusted)"),
    (0x08, "load_based_trim", "downstream_egr_mass_flow",
     "e2m 177F +8 CHP_Downstream_EGR_Flow 'Model of incompressible flow across fixed orifice' (signed lb/min x 128): "
     "downstream_egr_corrected_flow x charge_pressure / egr_orifice_temperature_rankine_square_root saturated at "
     "+-25600 in cm848_calculateDownstreamEgrMassFlow (was load_based_trim)"),
    (0x0A, "rpm_based_trim", "upstream_egr_mass_flow",
     "e2m 177F +A CHP_Upstream_EGR_Flow 'Empirical model relating lift and hot side dP to Flow' (signed lb/min x "
     "128): upstream_egr_corrected_flow x boost_pressure_current_raw (e2m 1A5D +0 Exhaust_Press) / "
     "exhaust_temperature_rankine_square_root saturated at +-25600 in cm848_calculateUpstreamEgrMassFlow "
     "(was rpm_based_trim)"),
    (0x0C, "reserved_0c", "downstream_egr_corrected_flow",
     "e2m 177F +C CHP_Downstream_Corrected_Flow 'Table output for downstream EGR corrected flow 3D Table': "
     "cm848_dualAxisTableInterpolation of the filtered egr_valve_position and downstream_egr_pressure_ratio in "
     "cm848_calculateDownstreamEgrMassFlow (was reserved_0c)"),
    (0x0E, "rpm_conversion", "downstream_egr_pressure_ratio",
     "e2m 177F +E CHP_Downstream_Pratio 'EGR dP/P pressure ratio' (Q15): egr_orifice_delta_pressure x 32767 / "
     "charge_pressure limited to +-32440 (+-0.99) in cm848_calculateDownstreamEgrMassFlow (was rpm_conversion)"),
    (0x10, "reserved_10", "exhaust_temperature_rankine_square_root",
     "e2m 177F +10 CHP_Sqrt_Texhaust_R 'Output of SQRT(Texhaust) Table for EGR flow Calculation' (SQRT(DEG_R)): "
     "lookupTableInterpolation of exhaust_temperature in cm848_calculateUpstreamEgrMassFlow (was reserved_10)"),
    (0x12, "reserved_12", "upstream_egr_corrected_flow",
     "e2m 177F +12 CHP_Upstream_Corrected_Flow 'table output for upstream EGR flow 3D Table': "
     "cm848_dualAxisTableInterpolation of egr_valve_position and charge_flow_estimate_terms.pressure_ratio in "
     "cm848_calculateUpstreamEgrMassFlow (was reserved_12)"),
    (0x14, "throttle_conversion", "oxygen_flow_delay_milliseconds",
     "e2m 177F +14 CHP_O2_Flow_Delay 'Delay between exhaust man calculated O2 and when that O2 reaches intake "
     "valve' (0.001 s per count): oxygen_flow_delay_volume_fraction x 120 x 1000 / (engine_volumetric_efficiency x "
     "engine speed) in cm848_calculateDelayedEgrFlowAndFraction; 40959 in the RAM dump (engine stopped: the 0xffff "
     "sentinel for a fraction above 1.0 over the 1600-count floor) (was throttle_conversion)"),
    (0x16, "reserved_16", "egr_orifice_temperature_rankine_square_root",
     "e2m 177F +16 CHP_Sqrt_Torifice_R 'Output of SQRT(Torifice) Table for CHP_Downstream_EGR_Flow calculation' "
     "(SQRT(DEG_R); 2951 in the RAM dump): lookupTableInterpolation of egr_orifice_temperature in "
     "cm848_calculateDownstreamEgrMassFlow (was reserved_16)"),
]

FUNCTIONS = {
    0x000128a0: ("cm848_throttleBasedFuelCalculation", "cm848_calculateDelayedEgrFlowAndFraction",
        "EGR transport delay stage of the charge properties model (e2m 177F, resolved by the ECU's parameter ID "
        "table): it carries the EGR mass flow and the exhaust oxygen fraction from where they are computed to the "
        "intake valve, then forms the EGR fraction. Runs every 10 ms (called by cm848_fuelControlMainCalculation, "
        "which cm848_phase_group_a_processing runs in the 20 even phases of the 40-phase main loop). "
        "(1) cm848_calculateEgrMassFlowBeforeDelay sets egr_flow_estimate_terms.egr_mass_flow_before_delay "
        "(+4 CHP_EGR_Flow_Before_Delay). "
        "(2) oxygen_flow_delay_milliseconds (+14 CHP_O2_Flow_Delay, 0.001 s per count) = "
        "oxygen_flow_delay_volume_fraction (e2m 177E +6 C_CHP_Volume_Fraction) x 120 x 1000 / "
        "(engine_volumetric_efficiency x engine speed): the time the engine takes to draw in that fraction of its "
        "displacement (one displacement per two revolutions). Volumetric efficiency x speed is limited to 1600 "
        "(200 rpm at 1.0) .. 0xffff counts, and a fraction above 8192 (1.0) is replaced by 0xffff. "
        "(3) residual_oxygen_fraction_before_delay goes into the 256-sample delay line at 0x3fa1b6 "
        "(cm848_delayUnsignedSample); the sample from delay / 10 passes back is filtered by exponentialMovingAverage "
        "(egr_oxygen_fraction_filter, coefficient egr_mass_flow_delayed_filter_coefficient = e2m 177E +0 "
        "C_CHP_EGR_Flow_Fil_Cnst) into egr_oxygen_fraction (+0 CHP_O2_Frac_EGR). "
        "(4) egr_flow_delay_milliseconds (+6 CHP_EGR_Flow_Delay) = the oxygen delay x egr_flow_delay_fraction "
        "(e2m 177E +C; 0 in the dump) / 32767. "
        "(5) egr_mass_flow_before_delay goes into the delay line at 0x3fa3b8 (cm848_delaySignedSample); the sample "
        "from delay / 10 passes back is filtered by cm848_signedFirstOrderFilter (egr_mass_flow_delayed_filter) "
        "into egr_mass_flow_delayed_filtered. "
        "(6) egr_fraction_actual (+2 EGR_Fraction) = egr_mass_flow_delayed_filtered x 8192 / "
        "charge_mass_flow_filtered, capped at 8192 (1.0); 0 while the charge flow is 64 counts (0.5 lb/min) or less. "
        "The read-back position wraps modulo 256 samples. Readers: egr_fraction_actual in "
        "cm848_calculateChargeSystemErrors / cm848_calculateAirFuelRatioAndIntakeOxygenFraction / "
        "cm848_calculateWaterVaporAndSaturationTemperatures; egr_oxygen_fraction in "
        "cm848_calculateCylinderOxygenMasses; egr_mass_flow_delayed_filtered in cm848_fuelDemandErrorCalculation "
        "(fresh air flow = charge - EGR) and the cylinder masses. (was cm848_throttleBasedFuelCalculation) | "
        "review-function-readability reviewed 2026-11-20 - Readability Medium Accuracy Confidence High"),
    0x000123dc: ("cm848_circularBufferWriteUnsigned", "cm848_delayUnsignedSample",
        "Delay line write and delayed read, unsigned: stores the sample at the line's write index (the byte at "
        "+0x200, after a ring of 256 words), advances the index and returns the word written delay_samples calls "
        "earlier (position (index - delay_samples) mod 256; 0 returns the sample just written; lhzx, zero-extended). "
        "Only caller cm848_calculateDelayedEgrFlowAndFraction (the residual oxygen fraction, delay line at "
        "0x3fa1b6). (was cm848_circularBufferWriteUnsigned)"),
    0x00012404: ("cm848_circularBufferWriteSigned", "cm848_delaySignedSample",
        "Signed twin of cm848_delayUnsignedSample: the same 256-word delay line write and delayed read, with the "
        "result sign-extended (lhax). Only caller cm848_calculateDelayedEgrFlowAndFraction (the EGR mass flow "
        "before delay, delay line at 0x3fa3b8). (was cm848_circularBufferWriteSigned)"),
}

GLOBALS = {
    0x0040a3ea: (INSTANCE, TYPE,
        "The EGR flow estimate terms, e2m 177F +0 .. +16 (table-resolved; +18 EGR_Flow_Source is egr_flow_source): "
        "the upstream and downstream EGR mass flow models with their table outputs, the EGR flow before the "
        "transport delay, the oxygen and EGR transport delays, the oxygen fraction in the EGR and the EGR fraction. "
        "Written by cm848_calculateUpstreamEgrMassFlow / cm848_calculateDownstreamEgrMassFlow / "
        "cm848_calculateEgrMassFlowBeforeDelay / cm848_calculateDelayedEgrFlowAndFraction. RAM dump (key on, engine "
        "stopped): egr_oxygen_fraction 8192, oxygen_flow_delay_milliseconds 40959, "
        "egr_orifice_temperature_rankine_square_root 2951, the rest 0. The EGR twin of charge_flow_estimate_terms "
        "(e2m 177D). (was throttle_fuel_trim_t_0040a3ea; its throttle / fuel trim / rpm / load field names were "
        "guesses)", None),
    0x0040a402: ("egr_flow_source", "word",
        "e2m 177F +18 EGR_Flow_Source (0 = PRIMARY / 1 = BACKUP; 1 in the RAM dump): "
        "cm848_calculateEgrMassFlowBeforeDelay stores the source of the selected EGR flow model every pass "
        "(cm848_checkEngineFaultConditions for the upstream model / cm848_checkFuelSystemFaultFlags for the "
        "downstream model). Readers: cm848_fuelDemandErrorCalculation (the fresh air flow source is primary only "
        "when this word and charge_flow_estimate_terms.charge_flow_source are 0) and "
        "cm848_calculateEgrCoolerEfficiency. sth, word. (was engine_fuel_fault_status)", "engine_fuel_fault_status"),
    0x003fa5ba: ("egr_oxygen_fraction_filter", "ema_filter_state_t",
        "exponentialMovingAverage record (ema_filter_state_t: coefficient pointer + Q16.16 accumulator) of the "
        "delayed residual oxygen fraction in cm848_calculateDelayedEgrFlowAndFraction; its output is "
        "egr_flow_estimate_terms.egr_oxygen_fraction (e2m 177F +0 CHP_O2_Frac_EGR). cm848_initFilterCoefficients "
        "clears the accumulator and points the coefficient at egr_mass_flow_delayed_filter_coefficient (e2m 177E +0 "
        "C_CHP_EGR_Flow_Fil_Cnst), the same constant as egr_mass_flow_delayed_filter. (was throttle_filter_state, "
        "earlier throttle_filter_coeff_table_pointer)", "throttle_filter_state"),
}


def rewrite(path, fn):
    lines = open(path).read().split("\n")
    changed = 0
    for i, line in enumerate(lines):
        new = fn(line)
        if new != line:
            lines[i] = new
            changed += 1
    open(path, "w").write("\n".join(lines))
    return changed


# structure_definitions.csv: field names, comments, status, section header
field_by_old = {old: (new, comment) for _, old, new, comment in FIELDS}


def struct_row(line):
    if line.startswith("# Throttle Fuel Trim State"):
        return "# EGR flow estimate terms (e2m 177F +0 .. +16) - the EGR mass flow models and the transport delays"
    if line.startswith("# Used by calculateFuelDemandValue and throttle processing"):
        return ("# Used by cm848_calculateUpstreamEgrMassFlow / cm848_calculateDownstreamEgrMassFlow / "
                "cm848_calculateEgrMassFlowBeforeDelay / cm848_calculateDelayedEgrFlowAndFraction")
    if not line.startswith(TYPE + ",0x0040a3ea,"):
        return line
    row = next(csv.reader([line]))
    new, comment = field_by_old[row[2]]
    row[2], row[5], row[7] = new, comment, "verified"
    return ",".join(row[:5]) + ',"' + comment + '",' + ",".join(row[6:])


n_struct = rewrite(os.path.join(out, "structure_definitions.csv"), struct_row)

# global_variables.csv: member-label rows, the instance comment, two globals
label_by_address = {0x0040a3ea + off: f"{INSTANCE}.{new}" for off, _, new, _ in FIELDS if off}


def global_row(line):
    p = line.split(",", 3)
    if not p[0].startswith("0x"):
        return line
    a = int(p[0], 16)
    if a in GLOBALS:
        name, typ, comment, _ = GLOBALS[a]
        assert p[2] == typ, (hex(a), p)
        return f"{p[0]},{name},{typ},{comment}"
    if a in label_by_address:
        assert p[1].startswith(INSTANCE + "."), (hex(a), p)
        return f"{p[0]},{label_by_address[a]},,"
    return line


n_global = rewrite(os.path.join(out, "global_variables.csv"), global_row)


def function_row(line):
    p = line.split(",", 2)
    if not p[0].startswith("0x") or int(p[0], 16) not in FUNCTIONS:
        return line
    old, new, plate = FUNCTIONS[int(p[0], 16)]
    assert p[1] == old, p
    return f"{p[0]},{new},{plate}"


n_function = rewrite(os.path.join(out, "function_renames.csv"), function_row)
print(f"structure rows {n_struct}, global rows {n_global}, function rows {n_function}")

# proof mapping (reverse_names.py) and refresh mapping (refresh_references.py)
with open(os.path.join(scratch, "map_stage1.csv"), "w", newline="") as f:
    w = csv.writer(f)
    w.writerow(["address", "name", "old_label", "kind"])
    for _, old, new, _ in FIELDS:
        if old != new:
            w.writerow(["", new, old, "field"])
    for a, (old, new, _) in FUNCTIONS.items():
        w.writerow([f"0x{a:08x}", new, old, "function"])
    for a, (name, _, _, old) in GLOBALS.items():
        if old:
            w.writerow([f"0x{a:08x}", name, old, "global"])
with open(os.path.join(scratch, "map_refresh_stage1.csv"), "w", newline="") as f:
    w = csv.writer(f)
    w.writerow(["address", "name", "old_label", "kind"])
    for _, old, new, _ in FIELDS:
        w.writerow(["", f"{INSTANCE}.{new}", f"{OLD_INSTANCE}.{old}", "token"])
        w.writerow(["", f"{TYPE}.{new}", f"{OLD_TYPE}.{old}", "token"])
    w.writerow(["", INSTANCE, OLD_INSTANCE, "token"])
    w.writerow(["", TYPE, OLD_TYPE, "token"])
    for a, (old, new, _) in FUNCTIONS.items():
        w.writerow([f"0x{a:08x}", new, old, "function"])
    for a, (name, _, _, old) in GLOBALS.items():
        if old:
            w.writerow([f"0x{a:08x}", name, old, "global"])
