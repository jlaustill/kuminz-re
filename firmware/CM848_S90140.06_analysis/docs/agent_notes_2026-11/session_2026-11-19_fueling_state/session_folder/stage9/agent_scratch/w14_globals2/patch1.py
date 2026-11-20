import sys

sys.path.insert(0, "/tmp/w14_globals2")
import spec_data_a as a  # noqa: E402
import spec_data_b as b  # noqa: E402

newc = {
    "0x003fa86c": "Working copy of total_fueling (e2m 120C +A Total_Fueling, 0x40a33a) in cm848_selectFinalFueling: starts as injection_quantity_combustion_command, is replaced by the engine state source (engine_overspeed_fueling, engine_brake_fueling, crank_fuel or the fuel override value), is clamped to fuel_demand_minimum..fuel_demand_maximum, then copied to total_fueling. A fueling quantity, not a timing.",
    "0x003fa880": "Throttle filter constant looked up from the throttle error |fuel_demand_control_t_0040a57a.calculated - commanded_throttle_filtered|: cm848_calculateFuelDemandChangeRate copies it into commanded_throttle_filter_coefficient (e2m 1053 +6 Active_Throttle_Filter_Constant) unless the throttle transient flag (e2m 1053 +A) holds a smaller value. 65535 after cm848_initFuelDemandTracking. No e2m record here.",
    "0x003feaa2": "Freeze frame in the EEPROM mirror (EEPROM 0x1620): cm848_selectFinalFueling copies total_fueling_previous_pass here on the first pass where final_fueling_state is SHUTDOWN or the excess injection monitor fault (fault_detected_bits_384_to_399 mask 0x10, fault 388) is set, once until cm848_clearFuelDemandFlag re-arms it. The previous final_fueling_state goes to the twin at 0x3feaa0. Never read.",
    "0x0040a406": "Record of the charge flow model terms (8 words): e2m 177D +2 CHP_Intake_Manifold_Tmptr_R (degrees Rankine = intake_manifold_temperature_filtered + 460 F; 32042 in the dump), +4 CHP_Veff_Mach, +6 CHP_Veff_Sqrt, +8 CHP_Flow_Area_Constant, +A CHP_Pratio, +C Charge_Flow_Source, then e2m 177B +0 Fresh_Air_Flow and +2 Fresh_Air_Flow_Source. Written by cm848_boostBasedFuelModifier.",
    "0x004002ec": "e2m 177E +A C_CHP_Venturi_Vrt_Sensor_Active 'Select Upstream (0) or Downstream (1) EGR Flow Model' (UNITLESS 0..1; 1 in the dump): cm848_selectFuelTrimMode runs the upstream flow model (valve lift and hot side delta pressure, cm848_calculateRpmBasedFuelTrim) when it is 0, else the downstream orifice model (cm848_calculateLoadBasedFuelTrim). Sibling of egr_flow_cold_side_algorithm_select (+8).",
    "0x004086c6": "e2m 8A2A +0 APC_Initial_Scaling_Factor 'Multiplier used to scale Boost_Pressure for initial Ambient_Air reading' (UNITLESS, 0.01 per count, 0.5..1.5; 107 in the dump = 1.07): cm848_processSensorTemperatureData scales the barometric pressure by it / 100 into the ambient pressure input (20..29 inHg y axis) of the intake air heater preheat table. e2m 8A14 +2C resolves here too: drift.",
}
for fname, lst in (("/tmp/w14_globals2/spec_data_a.py", a.A), ("/tmp/w14_globals2/spec_data_b.py", b.B)):
    src = open(fname).read()
    for s in lst:
        if s["addr"] in newc:
            assert s["comment"] in src, s["addr"]
            src = src.replace(s["comment"], newc[s["addr"]])
    open(fname, "w").write(src)

src = open("/tmp/w14_globals2/spec_data_a.py").read()
old = "(e2m 12BD +A Throttle_100_Priority, 7 in the dump -> 128), ORs it into j1939_pgn65251_speed_points_request_flags (e2m 12BB +0 Active_Speed_Points_State, 128 in the dump) while"
new = "(e2m 12BD +A Throttle_100_Priority; its flash word at 0x5c33e is 7, so 128, which is what the flags word 0x40a732 reads), ORs it into j1939_pgn65251_speed_points_request_flags (e2m 12BB +0 Active_Speed_Points_State) while"
assert old in src
src = src.replace(old, new)
open("/tmp/w14_globals2/spec_data_a.py", "w").write(src)
print("patched")
