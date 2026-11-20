import json
import re

PATH = "/tmp/w13b6/make_results.py"
s = open(PATH).read()
split = s.index("COMMENTS = {")
head, tail = s[:split], s[split:]

evidence = {
    19: "e2m 107C +5A Decel_Rate_I_Term: first word of the dword; cm848_runOperatingModeSpeedGovernor adds gain x "
        "(engine_rpm_delta - offset) >> 8 per pass, clamped 0..fuel_demand_integrator_b_limit, zero below "
        "rpm_drop_fuel_minimum_manifold_pressure; type note: the dword covers two words (I term here, P term at 0x40a206 = "
        "e2m +5C Decel_Rate_P_Term, so the row needs splitting)",
    30: "e2m 1781 +2 CHP_Pumping_Torque_Adj: cm848_calculateBoostPressureOffset turns nominal delta-P minus "
        "egr_delta_pressure_negated into torque and clamps it; cm848_calculateNetCombustionTorque subtracts it from the "
        "combustion torque (net = gross - it), cm848_applyProtectionRpmCorrectionFilter adds it to the friction torque; type "
        "note: lha, e2m signed (row is word)",
    31: "e2m 17A1 +0 Temperature_Delta (DEG_F 0.5, 0..1500): cm848_calculateCombustionTemperatureRise stores "
        "(boost_target_load_rpm_output << 8) / charge_fuel_ratio capped at 3000 = 1500 F; "
        "cm848_auxiliaryControl_exponentialAverage copies it to exhaust_temperature_rise_over_intake_manifold_temperature and "
        "adds it to 2 x the intake manifold temperature for exhaust_temperature; not a boost target",
    34: "e2m 1921 +6 Ambient_Air_Tmptr (DEG_F 1/64): hpcr_fuelFinal_exponentialAverage stores the override, the default (source "
        "state 2) or the filtered ambient_air_temperature_selected minus compressor_inlet_temperature_rise; "
        "cm848_blendBoostAndThrottleFuelDemand looks up the water saturation vapor pressure with it (cap 90 F); the old name "
        "says boost fuel demand blend; type note: lha, e2m signed (row is word)",
}
comments = {
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


def replace_entry(text, key, value):
    pat = re.compile(r'(?m)^    %d: "e2m.*?(?=^    \d+: "|^\}\n|^for i, text)' % key, re.S)
    m = pat.search(text)
    assert m, key
    return text[:m.start()] + "    %d: %s,\n" % (key, json.dumps(value)) + text[m.end():]


for key, value in evidence.items():
    head = replace_entry(head, key, value)
for key, value in comments.items():
    tail = replace_entry(tail, key, value)
open(PATH, "w").write(head + tail)
print("fixed")
