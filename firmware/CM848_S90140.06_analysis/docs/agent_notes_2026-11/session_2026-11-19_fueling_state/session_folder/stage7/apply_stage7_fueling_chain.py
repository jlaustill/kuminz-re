"""Stage 7 (PR #52), hand part: the fueling chain's e2m names (blocks 1045 / 1051), resolved with the ECU's parameter
ID table and checked against their writers.
- 1045 is the governed (LSG / HSG) fueling: [FSGVFL] / [FSGVFLST];
- 1051 is the final / requested fueling, the master-slave flag, the torque derate limit and the values before the
  combustion reference.
Also renames the freeze-frame field fault_entry_t.fuel_demand_computed (a copy of the final fueling at the fault).
Appends to map_stage7.csv.
usage: apply_stage7_fueling_chain.py <CM848 output dir> <map.csv>"""
import os
import sys

OUT, MAP = sys.argv[1:3]
T = " (address from the ECU's parameter ID table)"
RENAMES = [  # (address, old, new, e2m note put in front of the existing comment)
    ("0x0040a152", "governor_fuel_demand_value", "adjusted_user_fueling",
     "e2m 1045 +0 Adjusted_User_Fueling [FSGVFL] 'Fueling as limited by limiting governors (LSG, HSG)'" + T + "."),
    ("0x0040a154", "governor_fuel_demand_mode", "adjusted_user_fueling_state",
     "e2m 1045 +2 Adjusted_User_Fueling_State [FSGVFLST] 'Indicator as to which algorithm is in control of fueling "
     "after it is governed'" + T + "; the symbol this PR started from."),
    ("0x0040a2ce", "fuel_demand_computed", "final_fueling",
     "e2m 1051 +0 Final_Fueling [FSFNFL] 'Final fueling value'" + T + "; set by cm848_selectFinalFueling and copied "
     "into each fault freeze frame (fault_entry_t.final_fueling)."),
    ("0x0040a2d2", "fuel_demand_arbitration_working", "requested_fueling",
     "e2m 1051 +4 Requested_Fueling [FSLMDSFL] 'Desired engine fueling after derate without Air Handl. derate'" + T +
     "; cm848_arbitrateRequestedFueling sets it to adjusted_user_fueling or torque_derate_fuel_quantity."),
    ("0x0040a2d6", "fuel_limit_secondary_flag", "master_slave_control_flag",
     "e2m 1051 +8 MS_Control_Flag [MSCNFG] 'Flag in MASTER/SLAVE identifying fueling and timing override in SLAVE'" +
     T + "; nothing stores it in this build."),
    ("0x0040a2d8", "power_take_off_torque_limit", "torque_derate_torque_limit",
     "e2m 1051 +A Torque_Derate_Torque [TQDQTQ] 'min torque limit in foot-pounds'" + T + ": the power take-off "
     "maximum torque is one source of it, not the only meaning."),
    ("0x0040a2da", "power_take_off_torque_limit_state", "torque_derate_torque_limit_state",
     "e2m 1051 +C Torque_Derate_Torque_State [TQDQTQST] 'indicates origin of TQDQTA value'" + T + "."),
    ("0x0040a2dc", "governor_torque_speed_mode_flag", "torque_control_indication_flag",
     "e2m 1051 +E Torque_Control_Indication 'Set to 1 if torque control fuel or speed limit active'" + T +
     "; set 1 / 0 by cm848_selectFinalFueling."),
    ("0x0040a2e0", "fuel_demand_arbitrated_snapshot", "final_fueling_before_combustion_reference",
     "e2m 1051 +12 Final_Fueling_Before_CBR 'Final fueling value before combustion reference'" + T + "."),
    ("0x0040a2e2", "fuel_demand_arbitrated_state_snapshot", "final_fueling_state_before_combustion_reference",
     "e2m 1051 +14 Fueling_Control_State_Before_CBR 'Final fueling state before combustion manager'" + T + "."),
]
path = os.path.join(OUT, "global_variables.csv")
lines = open(path, newline="").read().split("\n")
for address, old, new, note in RENAMES:
    hits = [i for i, l in enumerate(lines) if l.split(",", 1)[0] == address]
    assert len(hits) == 1, address
    a, name, typ, comment = (lines[hits[0]].split(",", 3) + [""])[:4]
    assert name == old, (address, name, old)
    lines[hits[0]] = ",".join([a, new, typ, f"{note} {comment} (was {old})".replace("  ", " ")])
open(path, "w", newline="").write("\n".join(lines))

path = os.path.join(OUT, "structure_definitions.csv")
text = open(path, newline="").read()
old_row = "fault_entry_t,,fuel_demand_computed,word,2,Processed load/throttle value,,verified"
assert text.count(old_row) == 1
text = text.replace(old_row, "fault_entry_t,,final_fueling,word,2,final_fueling (e2m Final_Fueling) when the fault was "
                             "recorded (was fuel_demand_computed: Processed load/throttle value),,verified")
open(path, "w", newline="").write(text)

new_file = not os.path.exists(MAP)
with open(MAP, "a") as f:
    if new_file:
        f.write("address,name,old_label,kind\n")
    for address, old, new, _ in RENAMES:
        f.write(f"{address},{new},{old},global\n")
    f.write(",final_fueling,fuel_demand_computed,struct field\n")
print(f"{len(RENAMES)} fueling chain renames + 1 struct field")
