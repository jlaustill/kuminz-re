import json
import re

s = open("/tmp/w13b6/make_results.py").read()
new = {
    34: "e2m 1921 +6 Ambient_Air_Tmptr 'Ambient Air Temperature' (DEG_F): the ambient air temperature of the air handling "
        "models, reference twin of ambient_air_temperature_selected: hpcr_fuelFinal_exponentialAverage stores an override, the "
        "default (source state 2) or the filtered ambient_air_temperature_selected minus compressor_inlet_temperature_rise; "
        "cm848_blendBoostAndThrottleFuelDemand takes the water saturation vapor pressure at it. dump 1620.",
    30: "e2m 1781 +2 CHP_Pumping_Torque_Adj 'Used by CBR in determination of gross fuel from net torque cmd' (FT*LB): the "
        "pumping torque adjustment between net and gross torque: cm848_calculateBoostPressureOffset turns the nominal delta-P "
        "minus egr_delta_pressure_negated into torque (plus an offset, clamped); cm848_calculateNetCombustionTorque subtracts "
        "it from the combustion torque, cm848_applyProtectionRpmCorrectionFilter adds it to the friction torque.",
    31: "e2m 17A1 +0 Temperature_Delta 'Difference between IMT and exhaust temperature' (DEG_F, 0.5 per count): the exhaust "
        "temperature model's rise over the intake manifold temperature: cm848_calculateCombustionTemperatureRise stores "
        "boost_target_load_rpm_output << 8 / charge_fuel_ratio (floor 128) capped at 3000 (1500 F); "
        "cm848_auxiliaryControl_exponentialAverage passes it on (0 while the model is invalid).",
    19: "e2m 107C +5A Decel_Rate_I_Term 'Integral term of rpm decel limit control' (MM3S): first word of the dword "
        "(proportional term = second word, e2m +5C): cm848_runOperatingModeSpeedGovernor adds fuel_demand_integrator_gain_a_cal "
        "x (engine_rpm_delta minus an offset) >> 8 per pass, clamped 0..fuel_demand_integrator_b_limit, zero below "
        "rpm_drop_fuel_minimum_manifold_pressure; it floors the governor output with the proportional term.",
}
for key, text in new.items():
    pat = re.compile(r'(?m)^    %d: "e2m.*?(?=^    \d+: "|^\}\n)' % key, re.S)
    m = pat.search(s)
    assert m, key
    s = s[:m.start()] + "    %d: %s,\n" % (key, json.dumps(text)) + s[m.end():]
open("/tmp/w13b6/make_results.py", "w").write(s)
print("patched", sorted(new))
