"""Round 96 stage D (CM848): the seven ema_filter_state_t records that had no name (they rendered as Ghidra's default
labels ema_filter_state_t_<address>), their coefficient words (rendered WORD_<address>) and the two EGR orifice
temperature words around them. Names follow the repository's rule (<x>_filter_state / <x>_filter_coefficient, x = what
the filter filters), checked against each record's one user and, for the coefficients, the e2m record the ECU's
parameter ID table resolves at the address (e2m_block_addresses.py --address). None is EEPROM-backed (ROM, its RAM
copy 0x3feed0-0x40a048, or working RAM), so no _cal. Writes the map. Idempotent; keeps line endings.
usage: filter_states_r96.py <repo> <map out>"""
import os
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
R = "PR #53 round 96"
ROWS = {  # address: (name, type, comment)
    "0x003fa19c": ("wastegate_battery_voltage_filter_state", "ema_filter_state_t",
                   "EMA filter state of the battery voltage in cm848_calculateWastegateDutyRequest (cm848_initializeWastegateDutyController clears the accumulator and points the coefficient at wastegate_battery_voltage_filter_coefficient)"),
    "0x003ffcb4": ("wastegate_battery_voltage_filter_coefficient", "word",
                   "the coefficient of wastegate_battery_voltage_filter_state - e2m 16A1 +1C C_TGC_Battery_Voltage_Filter_Constant 'Time constant for the battery voltage filter for TGC upper limit' (EMA weight of the previous value in 1/65536; 0 = no filtering)"),
    "0x003fa70a": ("compressor_outlet_temperature_filter_state", "ema_filter_state_t",
                   "EMA filter state of the compressor outlet temperature estimate: cm848_estimateCompressorOutletTemperature filters the ratio x inlet temperature and returns the result (mpc555_initFuelFlowRateVariables initializes it)"),
    "0x004065c2": ("compressor_outlet_temperature_filter_coefficient", "word",
                   "the coefficient of compressor_outlet_temperature_filter_state - e2m 1760 +0 C_TPE_COT_Filter_Constant 'Digital filter constant for compressor outlet temperature'"),
    "0x003fb026": ("turbocharger_speed_estimate_engine_speed_filter_state", "ema_filter_state_t",
                   "EMA filter state of engine_speed_state.filtered_engine_speed in cm848_estimateTurbochargerSpeed (cm848_initializeTurbochargerSpeedEstimate initializes it)"),
    "0x004072a0": ("turbocharger_speed_estimate_engine_speed_filter_coefficient", "word",
                   "the coefficient of turbocharger_speed_estimate_engine_speed_filter_state - e2m 18CC +4 C_TSE_RPM_Filter_Constant 'Filter constant for engine spd used in turbo speed estimate'"),
    "0x003fbcea": ("exhaust_metal_temperature_filter_state", "ema_filter_state_t",
                   "EMA filter state that turns the exhaust temperature into the exhaust metal temperature in cm848_estimateExhaustTemperature (cm848_initialization_step_13 initializes it)"),
    "0x00406770": ("exhaust_metal_temperature_filter_coefficient", "word",
                   "the coefficient of exhaust_metal_temperature_filter_state - e2m 17A2 +8 C_TPE_Exhaust_Metal_Fil_Cnst 'Filter constant to convert Exhaust Temperature to Exhaust Metal Temperature'"),
    "0x003fbd2e": ("fault_derate_engine_speed_limit_filter_state", "ema_filter_state_t",
                   "EMA filter state of the fault derate engine speed limit in cm848_calculateFaultDerateEngineSpeedLimit (initializeFaultDerateEngineSpeedLimit starts the accumulator at engine_speed_limit_default_cal)"),
    "0x0005c2f2": ("fault_derate_engine_speed_limit_filter_coefficient", "word",
                   "the coefficient of fault_derate_engine_speed_limit_filter_state - e2m 10B5 +2 RPM_Limit_Filter_Time_Constant [EPRPFTTC] 'MAXIMUM RPM LIMIT FILTER TIME CONSTANT' (ROM)"),
    "0x003fbd00": ("egr_orifice_temperature_first_stage_filter_state", "ema_filter_state_t",
                   "the first of the two EMA stages in cm848_filterEgrOrificeTemperature: it filters egr_orifice_temperature_after_lead into egr_orifice_temperature_first_stage_filtered (its coefficient is egr_orifice_temperature_lead_time_constant_lookup)"),
    "0x003fbd08": ("egr_orifice_temperature_second_stage_filter_state", "ema_filter_state_t",
                   "the second EMA stage in cm848_filterEgrOrificeTemperature: it filters the first stage's output into egr_orifice_temperature_compensated"),
    "0x003fbcfc": ("egr_orifice_temperature_first_stage_filtered", "word",
                   "the first EMA stage's output in cm848_filterEgrOrificeTemperature (only stored)"),
    "0x003fbcf6": ("egr_orifice_temperature_compensated", "word",
                   "the EGR orifice temperature after the lead compensation and the two EMA stages (egr_orifice_temperature_after_lead when the compensation is off or the sensor is at fault); cm848_selectEgrOrificeTemperature copies it to egr_orifice_temperature"),
}
p = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/global_variables.csv")
t = open(p, newline="").read()
E = "\r\n" if "\r\n" in t else "\n"
lines = t.split(E)
names = {l.split(",", 2)[1] for l in lines if l.startswith("0x") and l.count(",") >= 2}
mapping = []
for address, (name, typ, comment) in ROWS.items():
    assert "," not in name
    idx = [i for i, l in enumerate(lines) if l.lower().startswith(address + ",")]
    if idx:
        parts = lines[idx[0]].split(",", 3)
        if parts[1] == name:
            continue
        assert parts[1] == "" and parts[2] == typ, lines[idx[0]]
        assert name not in names, name
        old = parts[3] if len(parts) > 3 else ""
        lines[idx[0]] = f"{address},{name},{typ},{comment} ({R})" + (f" | earlier note: {old}" if old else "")
        label = f"{typ}_{address[2:]}" if typ != "word" else f"WORD_{address[2:]}"
    else:
        assert name not in names, name
        k = next(k for k, l in enumerate(lines) if l.startswith("0x") and int(l.split(",", 1)[0], 16) > int(address, 16))
        lines.insert(k, f"{address},{name},{typ},{comment} ({R})")
        label = f"DAT_{address[2:]}"
    mapping.append((address, name, label))
open(p, "w", newline="").write(E.join(lines))
with open(map_path, "w") as f:
    f.write("address,name,old_label,kind,dims\n")
    for a, n, l in mapping:
        f.write(f"{a},{n},{l},symbol,1\n")
print(len(mapping), "rows named")
