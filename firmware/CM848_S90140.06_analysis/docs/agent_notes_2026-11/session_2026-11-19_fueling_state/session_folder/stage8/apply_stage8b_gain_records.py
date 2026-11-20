"""Stage 8b: the fuel pressure governor / fuel metering gain records as structs.
cm848_applyPiecewiseLinearGain and cm848_integrateWithZoneGain read a 16-byte record (three dword gains at +0 / +4 / +8,
the signed window widths at +12 / +14); cm848_calculateFilteredDerivative reads an 18-byte one (a word filter
coefficient, then the same five fields). The ECU's parameter ID table resolves e2m 8014 / 8015 / 8016 / 8017 / 8018
(16 bytes each) and 80EF / 80F2 (18 bytes) to the seven records, and the dump reads in range at those field widths
(read_gain_blocks.py). Before this the records were flat word / dword / byte rows, some of them wrong (the 80EF dword
gains as word rows over their high halves plus `_lo_cal` rows over the low halves; 8016-8018 / 80F2 as byte rows).
Edits: the two struct types (structure_definitions.csv), the seven instances (the first row of each edited in place,
16 interior rows deleted), the three consumers' full prototypes (function_definitions.csv), and the 80B9 short to
ground / short to battery caveat on six rows. Writes map_stage8b.csv (address,name,old_label,kind).
usage: apply_stage8b_gain_records.py <stage8 dir> <CM848 output dir>"""
import os
import sys

here, out = sys.argv[1:3]

STRUCT_ROWS = [
    "# piecewise_linear_gain_t / derivative_gain_t: the gain records of the fuel pressure governor and the fuel metering"
    " current compensation (e2m 8014-8018 / 80EF / 80F2), read by cm848_applyPiecewiseLinearGain,"
    " cm848_integrateWithZoneGain and cm848_calculateFilteredDerivative (stage 8b, PR #52)",
    'piecewise_linear_gain_t,,small_signal_gain,dword,4,"Gain while the input is inside the window (Q16: output = gain'
    ' x input >> 16; units per instance)",,verified',
    'piecewise_linear_gain_t,,positive_large_signal_gain,dword,4,"Gain above positive_window_width: the proportional'
    ' step applies it to the part above; the integral step uses it for the whole error",,verified',
    'piecewise_linear_gain_t,,negative_large_signal_gain,dword,4,"Gain below negative_window_width (the same way as the'
    ' positive one)",,verified',
    'piecewise_linear_gain_t,,positive_window_width,short,2,"Upper breakpoint of the window (>= 0; in the input\'s'
    ' units)",,verified',
    'piecewise_linear_gain_t,,negative_window_width,short,2,"Lower breakpoint of the window (<= 0)",,verified',
    'derivative_gain_t,,filter_coefficient,word,2,"Weight of the previous state in 1/65536 (e2m Derivative_Gain_Constant):'
    ' the state moves toward gain x input by 1 - coefficient / 65536 per call",,verified',
    'derivative_gain_t,,small_signal_gain,dword,4,"Gain while the input is inside the window",,verified',
    'derivative_gain_t,,positive_large_signal_gain,dword,4,"Gain while the input is above positive_window_width",,verified',
    'derivative_gain_t,,negative_large_signal_gain,dword,4,"Gain while the input is below negative_window_width",,verified',
    'derivative_gain_t,,positive_window_width,short,2,"Upper breakpoint of the window (>= 0)",,verified',
    'derivative_gain_t,,negative_window_width,short,2,"Lower breakpoint of the window",,verified',
]

COPY = ("cm848_calculateFuelMeteringCommand copies the P / I / D records to the stack (each gain and coefficient scaled by"
        " its own lookup table while cam_timing_alt_mode_enable_cal is 0; the window widths unscaled)")
# address: (old first-row name, old type, new name, new type, comment, interior rows {address: old name})
INSTANCES = {
    "0x004094a2": ("fuel_pressure_governor_proportional_gain_small_signal", "dword",
                   "fuel_pressure_governor_proportional_gains", "piecewise_linear_gain_t",
                   "e2m 8014 HPCR_Propgain_* 'Fuel pressure governor P-component' (addresses from the ECU's parameter ID"
                   " table): small / positive large / negative large signal gains (%/MPa, 7.6293e-6 per count; 65537 /"
                   " 13107 / 78644 here = 0.5 / 0.1 / 0.6) and the window widths (MPa, 0.0488 per count; 205 / -204 here ="
                   " +10.0 / -10.0). " + COPY + "; cm848_applyPiecewiseLinearGain applies it to the pressure error"
                   " (fuel_pressure_setpoint - fuel_pressure_feedback_filtered) for fuel_pressure_governor_proportional_term.",
                   {"0x004094a6": "fuel_pressure_governor_proportional_gain_positive_large_signal",
                    "0x004094aa": "fuel_pressure_governor_proportional_gain_negative_large_signal",
                    "0x004094ae": "engine_sync_prot_scale_a_cal", "0x004094b0": "engine_sync_prot_scale_a_cal+2"}),
    "0x004094b2": ("fuel_pressure_governor_integral_gain_small_signal", "dword",
                   "fuel_pressure_governor_integral_gains", "piecewise_linear_gain_t",
                   "e2m 8015 HPCR_Integral_Gain_* 'Fuel pressure governor Integral-component': small / positive large /"
                   " negative large signal gains (%/MPa/SEC, 0.00011641 per count; 8590 / 5154 / 8590 here = 1.0 / 0.6 /"
                   " 1.0) and the window widths (MPa, 0.0488 per count; 205 / -204 here). After the stack copy (see"
                   " fuel_pressure_governor_proportional_gains) cm848_integrateWithZoneGain integrates the pressure error"
                   " into fuel_pressure_governor_integrator (step 10000) for fuel_pressure_governor_integral_term.",
                   {"0x004094b6": "fuel_pressure_governor_integral_gain_positive_large_signal",
                    "0x004094ba": "fuel_pressure_governor_integral_gain_negative_large_signal",
                    "0x004094be": "engine_sync_prot_scale_b_cal", "0x004094c0": "engine_sync_prot_scale_b_cal+2"}),
    "0x004094c2": ("engine_sync_prot_gain_cal", "word", "fuel_pressure_governor_derivative_gains", "derivative_gain_t",
                   "e2m 80EF HPCR_Derivative_Gain_* 'Fuel pressure governor D-Component': the filter coefficient"
                   " (Derivative_Gain_Constant, 1/65536; 43713 here = 0.667), small / positive large / negative large"
                   " signal gains (%/MPa/SEC, 7.6293e-8 per count; 65537 / 262147 / 262147 here = 0.005 / 0.02 / 0.02) and"
                   " the window widths (MPa, 0.0488 per count; 205 / -204 here). After the stack copy (see"
                   " fuel_pressure_governor_proportional_gains) cm848_calculateFilteredDerivative computes"
                   " fuel_pressure_governor_derivative_term from the setpoint minus the filtered sensor, with"
                   " fuel_pressure_governor_derivative_filter as its state. The 4-byte gains used to be word rows over"
                   " their high halves plus `_lo_cal` rows over the low halves.",
                   {"0x004094c4": "fuel_pressure_governor_derivative_gain_small_signal",
                    "0x004094c6": "injection_timing_scale_cyl4_lo_cal",
                    "0x004094c8": "fuel_pressure_governor_derivative_gain_positive_large_signal",
                    "0x004094ca": "injection_timing_scale_cyl5_lo_cal",
                    "0x004094cc": "fuel_pressure_governor_derivative_gain_negative_large_signal",
                    "0x004094ce": "injection_timing_scale_cyl6_lo_cal",
                    "0x004094d0": "engine_sync_prot_limit_cal", "0x004094d2": "engine_sync_prot_gain_b_cal"}),
    "0x004094d4": ("cam_sync_speed_error_prot_state_cal", "byte",
                   "fuel_metering_current_compensation_proportional_gains", "piecewise_linear_gain_t",
                   "e2m 8016 HPCR_Currentcomp_Propgain_* 'Current compensation governor P-component': small / positive"
                   " large / negative large signal gains (CNTS/mA, 3.0517e-9 per count; all 0 here, so the proportional"
                   " part of the current compensation is off) and the window widths (mA, 1.2218 per count; 409 / 0 here ="
                   " +500 / 0 mA). cm848_calculateFuelMeteringCommand applies it with cm848_applyPiecewiseLinearGain to"
                   " fuel_metering_feedback_error (commanded minus measured current, mA) while"
                   " fuel_metering_feedback_fault_code is 0.", {}),
    "0x004094e4": ("cam_sync_speed_error_prot_mode_cal", "byte",
                   "fuel_metering_current_compensation_integral_gains", "piecewise_linear_gain_t",
                   "e2m 8017 HPCR_Currentcomp_Integral_* 'Current compensation governor Integral-component': small /"
                   " positive large / negative large signal gains (CNTS/mA/SEC, 4.6566e-8 per count; 21475 / 2147 / 2147"
                   " here = 0.001 / 0.0001 / 0.0001) and the window widths (mA, 1.2218 per count; 3274 / -3272 here = +4000"
                   " / -3998 mA). cm848_integrateWithZoneGain integrates fuel_metering_feedback_error into"
                   " fuel_metering_feedback_trim_integrator (step 10000).", {}),
    "0x004094f4": ("cam_sync_ref_prot_state_cal", "byte",
                   "fuel_metering_uncompensated_duty_cycle_proportional_gains", "piecewise_linear_gain_t",
                   "e2m 8018 HPCR_Propcomp_Dutycycle_* 'gain for P-component non compensated duty cycle': small / positive"
                   " large / negative large signal gains (%/mA, 3.05175e-7 per count; 95027 / 52429 / 83231 here = 0.029 /"
                   " 0.016 / 0.0254) and the window widths (mA, 1.2218 per count; 3274 / -3272 here). "
                   "cm848_calculateFuelMeteringCommand applies it with cm848_applyPiecewiseLinearGain to the commanded"
                   " current (mA, the output of the cam_sync_ref_output_values_cal table) for the uncompensated duty"
                   " cycle.", {}),
    "0x00409504": ("cam_sync_ref_prot_handler_state_cal", "byte",
                   "fuel_metering_current_compensation_derivative_gains", "derivative_gain_t",
                   "e2m 80F2 HPCR_Current_Comp_Derivative_Gain_* / HPCR_Curr_Comp_Der_Gain_* 'Current compensation"
                   " derivative': the filter coefficient (1/65536), small / positive large / negative large signal gains"
                   " (%/SEC, 1.52587e-5 per count) and the window widths (%, 0.0244 per count); every field is 0 here, so"
                   " this derivative term is off. cm848_calculateFilteredDerivative applies it to the uncompensated duty"
                   " cycle for fuel_metering_base_command_derivative_term (state"
                   " fuel_metering_base_command_derivative_filter).", {}),
}

PROTOTYPES = [
    "0x00047838,cm848_applyPiecewiseLinearGain,return,,sword,Gain x input >> 16 - the large-signal gains apply to the part"
    " past the window - clamped to +/-4095",
    "0x00047838,cm848_applyPiecewiseLinearGain,0,gain,piecewise_linear_gain_t *,Gain record (r3)",
    "0x00047838,cm848_applyPiecewiseLinearGain,1,input,int32_t,Signed input (r4): an error or a command",
    "0x00047978,cm848_integrateWithZoneGain,return,,sword,Integer part of the accumulator after the step - clamped to"
    " +/-4095",
    "0x00047978,cm848_integrateWithZoneGain,0,gain,piecewise_linear_gain_t *,Gain record (r3): the error's zone picks the"
    " gain",
    "0x00047978,cm848_integrateWithZoneGain,1,accumulator,q16_fixed_point_t *,Q16.16 integrator (r4) - updated in place",
    "0x00047978,cm848_integrateWithZoneGain,2,error,int32_t,Signed error (r5)",
    "0x00047978,cm848_integrateWithZoneGain,3,step,uint,Step factor (r6) - its low 16 bits are used (10000 at both calls)",
    "0x00047a88,cm848_calculateFilteredDerivative,return,,sword,Integer part of gain x input minus the state - clamped to"
    " +/-4095",
    "0x00047a88,cm848_calculateFilteredDerivative,0,gain,derivative_gain_t *,Derivative gain record (r3)",
    "0x00047a88,cm848_calculateFilteredDerivative,1,filter_state,q16_fixed_point_t *,Q16.16 filter state (r4) - updated in"
    " place",
    "0x00047a88,cm848_calculateFilteredDerivative,2,input,int32_t,Signed input (r5)",
]

CAVEAT = (" The code treats the short to ground and short to battery bytes alike, so the e2m byte order (+2 Short_Ground /"
          " +3 Short_Vbatt) is the only evidence for which is which (wave 13 bin 3).")
CAVEAT_ROWS = {"0x0040b8ce": "injector_diagnostic_bits_short_to_ground",
               "0x0040b8cf": "injector_diagnostic_bits_short_to_battery",
               "0x003fb700": "injector_diagnostic_bits_short_to_ground_debounce_count",
               "0x003fb6fe": "injector_diagnostic_bits_short_to_battery_debounce_count",
               "0x00409a8e": "injector_diagnostic_bits_short_to_ground_debounce_limit",
               "0x00409a90": "injector_diagnostic_bits_short_to_battery_debounce_limit"}

# global_variables.csv
path = os.path.join(out, "global_variables.csv")
lines = open(path, newline="").read().split("\n")
index = {l.split(",", 1)[0]: i for i, l in enumerate(lines) if l.startswith("0x")}
delete, mapping = set(), []
for address, (old, old_type, new, new_type, comment, interior) in INSTANCES.items():
    i = index[address]
    a, name, typ, _ = (lines[i].split(",", 3) + [""])[:4]
    assert (name, typ) == (old, old_type), (address, name, typ)
    olds = [old] + [n for n in interior.values() if "+" not in n]
    lines[i] = ",".join([a, new, new_type, f"{comment} (was {', '.join(olds)})"])
    mapping.append((address, new, old))
    for inner, inner_old in interior.items():
        j = index[inner]
        assert lines[j].split(",")[1] == inner_old, (inner, lines[j][:60])
        delete.add(j)
for address, name in CAVEAT_ROWS.items():
    i = index[address]
    assert lines[i].split(",")[1] == name and CAVEAT not in lines[i], address
    at = lines[i].find(" (was ")
    assert at > 0, address
    lines[i] = lines[i][:at] + CAVEAT + lines[i][at:]
lines = [l for i, l in enumerate(lines) if i not in delete]
open(path, "w", newline="").write("\n".join(lines))

# structure_definitions.csv
path = os.path.join(out, "structure_definitions.csv")
text = open(path, newline="").read()
assert "piecewise_linear_gain_t" not in text and "derivative_gain_t," not in text
open(path, "w", newline="").write(text.rstrip("\n") + "\n" + "\n".join(STRUCT_ROWS) + "\n")

# function_definitions.csv
path = os.path.join(out, "function_definitions.csv")
text = open(path, newline="").read()
for address in ("0x00047838", "0x00047978", "0x00047a88"):
    assert f"\n{address}," not in text, address
open(path, "w", newline="").write(text.rstrip("\n") + "\n" + "\n".join(PROTOTYPES) + "\n")

with open(os.path.join(here, "map_stage8b.csv"), "w") as f:
    f.write("address,name,old_label,kind\n")
    for address, new, old in mapping:
        f.write(f"{address},{new},{old},global\n")
print(f"{len(INSTANCES)} instances, {len(delete)} interior rows deleted, {len(STRUCT_ROWS) - 1} struct rows,"
      f" {len(PROTOTYPES)} prototype rows, {len(CAVEAT_ROWS)} caveats")
