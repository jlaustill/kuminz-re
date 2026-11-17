"""PR #50 body: the rename wave (todo 042)."""
import sys

p = sys.argv[1]
t = open(p).read()
anchor = "## Finding for task 022: the J1939 pedal reaches fueling"
add = (
    "14. **The code around the tables, renamed: 27 functions and 237 globals (482038a, todo 042).**\n"
    "    - **Method:** five read-only agents checked each lead from the table campaign against the code, with RAM-dump reproductions where possible. Every lead held. They also found the chains around each function: the timing / quantity / on-time paths of all three injection events, the rail-pressure setpoint and its monitors, wastegate duty and its monitor, the charging regulator, the intake air heater test, the J1939 retarder, and an oil-change monitor.\n"
    "    - **Injection:** there are three events per cylinder (TPU-A channel 5 slots 4 / 8 / 12, in crank order pilot → main → auxiliary).\n"
    "      - Timing: `cm848_calculateMainInjectionTiming` (was `cm848_calculateEngineTimingData`), `cm848_calculatePilotInjectionTiming(Offset)`, `cm848_calculateAuxiliaryInjectionTiming` (was `cm848_auxiliary_boundary_condition_eval`).\n"
    "      - Quantity: `cm848_calculatePilotInjectionQuantity` (was `cm848_torque_limit_state_update`) and `cm848_calculateAuxiliaryInjectionQuantity` (was `cm848_calculateGovernorOutput`).\n"
    "      - On-time: `cm848_calculate{Pilot,Main,Auxiliary}InjectionPulseWidth`.\n"
    "      - Variables: the headline values are `main_injection_timing` (was `torque_limit_fault_snapshot`), `pilot_injection_quantity` and `main_injection_pulse_width` (was `fuel_quantity_active`), and the component families follow the tables (`injection_timing_main_*`, `injection_quantity_pilot_*`, ...).\n"
    "    - **Rail pressure:** `cm848_calculateFuelPressureSetpoint` (was `cm848_sensor_channel_state_load`), plus monitors for P1223 / P0088 / P1222 and the rail-pressure-shortfall fuel limiter.\n"
    "    - **Air and electrical:** `cm848_calculateWastegateDutyRequest` (was `cm848_boostCompensatedRpmGovernor`), the wastegate monitor, the charging-voltage target and regulator, and the P2609 heater test. Also `barometric_pressure_reference` / `barometric_altitude_feet` (were `fuel_pressure_sensor_reference` / `governor_adjustment_input`).\n"
    "    - **Governor / J1939:** the retarder stage selection and torque, the governor PID gains, the no-load fuel, the reference-speed blend, and `cm848_updateOilChangeMonitor`. The oil-change identity rests on e2m names matching its block layout.\n"
    "    - **Recorded with the renames:** each renamed global's comment now starts with its evidence and `(was <old>)`, and the function plates are rewritten. The two duplicate global names are fixed. Four leads stayed uncertain and are listed in task 042 with the agents' 49 further notes.\n"
    "    - **Proof:** mapping every new name back to its old one gives back the previous `.cpp`, plate comments aside; three functions only reorder their declarations. One new row is `i16`: typing it `word` added casts, which the proof caught. `verify` is deterministic.\n\n")
assert t.count(anchor) == 1
open(p, "w").write(t.replace(anchor, add + anchor))
print("ok")
