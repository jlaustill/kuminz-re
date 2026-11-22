"""Round 17 stage B (types): the engine retarder enums from their e2m value lists.
- ENGINE_RETARDER_COMMAND_SOURCE (117D +8 E_Brake_Command_Source labels '6=NOOVERDE:5=NOT_SET:4=JCOMMLMT:3=SWITCH:
  2=CRUISE:1=JCOMMOVD:0=NONE'; 1070 +2 / +16 list 1-6 the same): the three source words. The code stores 6 / 1 (the
  override), 2 / 3 / 4 (the non-override sources), 5 (power-up) and 0 (no command), and compares them whole (the ERC1
  builder's SPN 900 mapping too).
- ENGINE_RETARDER_ALLOWED_STATE (1070 +14 EB_Allowed_State '0=NONE,1=OVERRIDE,2=OVER_OR_NON'): stores 0 / 1 / 2.
- J1939_CONTROL_DEVICE (round 6) on engine_retarder_j1939_control_device (117D +14 labels '4=UNKNOWN:3=ASR:2=ABS:
  1=TRANSMIS:0=NODEVICE'): stores 0 and copies engine_retarder_control_device_indicator, which already has the type.
usage: apply_r17b_enums.py <repo>"""
import os
import sys

out = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output")
L1 = "e2m 117D +8 E_Brake_Command_Source label"
ENUMS = """# ENGINE_RETARDER_COMMAND_SOURCE: the source of an engine retarder command (PR #53 round 17) - e2m 117D +8
# E_Brake_Command_Source value labels (1070 +2 EB_Override_Command_Source and +16 EB_Non_Override_Command_Source list
# 1-6 the same); on engine_retarder_override_command_source / _non_override_command_source / engine_retarder_command_source
ENGINE_RETARDER_COMMAND_SOURCE,0,ENGINE_RETARDER_COMMAND_SOURCE_NONE,No command (e2m NONE / NOT_COMM): cm848_selectEngineRetarderCommand with the allowed state NONE or no override in OVERRIDE_ONLY,2
ENGINE_RETARDER_COMMAND_SOURCE,1,ENGINE_RETARDER_COMMAND_SOURCE_J1939_OVERRIDE,A TSC1 torque control request (e2m JCOMMOVD / JC_OVRD): the override command,2
ENGINE_RETARDER_COMMAND_SOURCE,2,ENGINE_RETARDER_COMMAND_SOURCE_CRUISE,The cruise permission (e2m CRUISE): cm848_limitEngineRetarderPercentToCruisePermission,2
ENGINE_RETARDER_COMMAND_SOURCE,3,ENGINE_RETARDER_COMMAND_SOURCE_SWITCH,The operator selection (e2m SWITCH): cm848_limitEngineRetarderPercentToOperatorSelection,2
ENGINE_RETARDER_COMMAND_SOURCE,4,ENGINE_RETARDER_COMMAND_SOURCE_J1939_LIMIT,A TSC1 torque limit (e2m JCOMMLMT / JC_LIM): cm848_applyEngineRetarderTsc1Request,2
ENGINE_RETARDER_COMMAND_SOURCE,5,ENGINE_RETARDER_COMMAND_SOURCE_NOT_SET,Not set (e2m NOT_SET): the power-up value of the override and command sources,2
ENGINE_RETARDER_COMMAND_SOURCE,6,ENGINE_RETARDER_COMMAND_SOURCE_NO_OVERRIDE,No override (e2m NOOVERDE / NO_OVRD): the override source without a TSC1 torque control request,2
# ENGINE_RETARDER_ALLOWED_STATE: which commands may brake (PR #53 round 17) - e2m 1070 +14 EB_Allowed_State
# '0=NONE / 1=OVERRIDE / 2=OVER_OR_NON'; set by cm848_updateEngineRetarderAllowedState on engine_retarder_allowed_state
ENGINE_RETARDER_ALLOWED_STATE,0,ENGINE_RETARDER_ALLOWED_NONE,No command may brake: the brake is not wanted or an exit condition holds,2
ENGINE_RETARDER_ALLOWED_STATE,1,ENGINE_RETARDER_ALLOWED_OVERRIDE_ONLY,Only the override command (TSC1) may brake: the driver conditions (pedal / clutch / service brake) hold the rest off,2
ENGINE_RETARDER_ALLOWED_STATE,2,ENGINE_RETARDER_ALLOWED_OVERRIDE_OR_NON_OVERRIDE,The override or the non-override command may brake (the non-override command restarts at 101),2
"""
TYPES = {
    "0x0040a354": "ENGINE_RETARDER_COMMAND_SOURCE",
    "0x0040a368": "ENGINE_RETARDER_COMMAND_SOURCE",
    "0x0040a270": "ENGINE_RETARDER_COMMAND_SOURCE",
    "0x0040a366": "ENGINE_RETARDER_ALLOWED_STATE",
    "0x0040a27c": "J1939_CONTROL_DEVICE",
}
ep = os.path.join(out, "enums.csv")
t = open(ep).read()
assert "ENGINE_RETARDER_COMMAND_SOURCE" not in t and "ENGINE_RETARDER_ALLOWED_STATE" not in t
open(ep, "w").write(t.rstrip("\n") + "\n" + ENUMS)
gp = os.path.join(out, "global_variables.csv")
lines = open(gp).read().split("\n")
done = 0
for i, line in enumerate(lines):
    a = line[:10]
    if a in TYPES:
        addr, name, typ, comment = (line.split(",", 3) + [""])[:4]
        assert typ == "word", (a, typ)
        lines[i] = ",".join([addr, name, TYPES[a], comment + f" | typed {TYPES[a]} in PR #53 round 17 (was word)"])
        done += 1
assert done == len(TYPES), done
open(gp, "w").write("\n".join(lines))
print("2 enums, 5 rows typed")
