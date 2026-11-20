# Merged into apply_fueling_state_stage4.py (exec'd there): the power take-off governor, from the read-only agent's
# report, with these claims checked in this session: the CCVS1 builder ORs protection_event_code into
# j1939_ccvs1_pto_and_cruise_state_byte (SPN 976 PTO governor state; 0x1F when j1939_governor_feature_cal bit 0x10 is
# clear); OBD-II PID 0x1E = switch 3 | governor_fuel_active_flag; protection_eval_state stores 0-3 and the e2m PTST
# description (CHR_CC_11.45.01.07) reads 0=REMOTE_COUNT 1=REMOTE_RUN 2=WAIT 3=NORMAL, matching the transitions;
# all six words are lhz / lha / sth words; 0x3fd89a / 0x3fd89c are two lhz words.

MEMBERS[4] = (None, "operating_mode_governor_output.mode_code only (cm848_selectPowerTakeOffOrUserFueling): "
                    "power_take_off_governor_fuel_demand replaces the user fueling while power_take_off_governor_active_flag "
                    "is 1 and j1939_governor_feature_cal bit 0x10 is set (modes 5 / 6 always; 7 / 8 / 30 unless the user "
                    "fuel is larger and governor_feature_config_word bit 0x2000 lets the throttle override). Code-proven: "
                    "the governor's state goes out as J1939 SPN 976 (CCVS1) and OBD-II PID 0x1E")
MEMBERS[34] = ("POWER_TAKE_OFF_DERATE", "power_take_off_torque_limit_state (cm848_applyPowerTakeOffTorqueLimit): "
                    "power_take_off_maximum_torque_cal lowers power_take_off_torque_limit while "
                    "power_take_off_governor_active_flag is 1")

FUNCTIONS.update({
    "0x0002a4b0": ("cm848_calculateProtectionLoadCompensation", "cm848_runPowerTakeOffGovernorPid",
                   "The power take-off governor PID: the proportional / derivative / droop / integral terms on the speed "
                   "error into power_take_off_governor_fuel_demand (was cm848_calculateProtectionLoadCompensation)"),
    "0x0002a2d0": ("cm848_calculateProtectionRpmFilter", "cm848_calculatePowerTakeOffGovernorSpeedError",
                   "The power take-off governor speed error: power_take_off_governor_reference_engine_speed minus engine "
                   "speed, clamped to +-1000 rpm and filtered (was cm848_calculateProtectionRpmFilter)"),
    "0x0002ab2c": ("cm848_processProtectionParamDelta", "cm848_runPowerTakeOffGovernor",
                   "Runs the power take-off governor: fuel demand 0 while inactive, the engagement preset on the first "
                   "active pass, else the speed error and the PID (was cm848_processProtectionParamDelta)"),
    "0x0002a960": ("initProtectionParamCalculation", "cm848_presetPowerTakeOffGovernorOnEngagement",
                   "Presets the power take-off governor when it engages: the reference to the engine speed and the fuel "
                   "demand to fuel_demand_computed (was initProtectionParamCalculation)"),
    "0x0002a918": ("cm848_checkProtectionParamLimit", "cm848_applyPowerTakeOffTorqueLimit",
                   "While power_take_off_governor_active_flag is 1 lowers power_take_off_torque_limit to "
                   "power_take_off_maximum_torque_cal with FUELING_STATE_POWER_TAKE_OFF_DERATE (was "
                   "cm848_checkProtectionParamLimit)"),
    "0x0002afd0": ("cm848_processProtectionControlStateMachine", "cm848_runPowerTakeOffGovernorStateMachine",
                   "The power take-off governor state machine (POWER_TAKE_OFF_GOVERNOR_STATE): remote switch press "
                   "counting / remote preset speed / wait / cab control from the enable and remote switches (3 / 19), "
                   "brake and clutch cancel, the vehicle speed and engine speed windows and the set / resume / "
                   "accelerate / coast requests; sets power_take_off_governor_active_flag (was "
                   "cm848_processProtectionControlStateMachine)"),
    "0x0002ad68": ("cm848_evaluateProtectionCondition", "cm848_updatePowerTakeOffGovernorJ1939State",
                   "Sets power_take_off_governor_j1939_state, the J1939 SPN 976 PTO governor state the CCVS1 builder "
                   "sends (was cm848_evaluateProtectionCondition)"),
    "0x0002ac44": ("cm848_smoothProtectionParamTransition", "cm848_smoothPowerTakeOffReferenceEngineSpeed",
                   "Smooths power_take_off_governor_reference_engine_speed toward its target (minimum step + EMA) (was "
                   "cm848_smoothProtectionParamTransition)"),
    "0x0002ba7c": ("cm848_updateProtectionPreviousParam", "cm848_rampPowerTakeOffReferenceEngineSpeed",
                   "Ramps the power take-off reference engine speed per pass (was cm848_updateProtectionPreviousParam)"),
    "0x0002bb24": ("cm848_initProtectionEvalState", "cm848_initializePowerTakeOffGovernorState",
                   "Starts the power take-off governor in WAIT and inactive and clears its counters (was "
                   "cm848_initProtectionEvalState)"),
    "0x0002bbe8": ("cm848_selectPowerTakeOffOrUserFueling", "cm848_selectPowerTakeOffOrUserFueling",
                   "Sets operating_mode_governor_output: the user fueling (engine_operating_mode_fuel_demand with "
                   "engine_operating_mode) or, while power_take_off_governor_active_flag is 1 and j1939_governor_feature_cal "
                   "bit 0x10 is set, power_take_off_governor_fuel_demand with FUELING_STATE_POWER_TAKE_OFF (modes 5 / 6 "
                   "always; 7 / 8 / 30 unless the user fuel is larger and governor_feature_config_word bit 0x2000 lets the "
                   "throttle override - then power_take_off_throttle_override_flag and its engine speed limit "
                   "power_take_off_throttle_override_maximum_engine_speed_cal are set) (was "
                   "cm848_updateGovernorFromProtection)"),
})
GLOBALS.update({
    "0x0040af28": ("governor_fuel_demand_command", "power_take_off_governor_fuel_demand", None,
                   "The power take-off governor fuel demand (cm848_runPowerTakeOffGovernorPid; preset to "
                   "fuel_demand_computed on engagement, 0 while inactive); only cm848_selectPowerTakeOffOrUserFueling "
                   "reads it. All 6 accesses are lhz / sth words (was governor_fuel_demand_command)"),
    "0x0040af4e": ("governor_fuel_active_flag", "power_take_off_governor_active_flag", None,
                   "1 while the power take-off governor runs (POWER_TAKE_OFF_GOVERNOR_STATE 1 / 3; 0 in 2); OBD-II PID "
                   "0x1E sends it with switch 3. RAM dump: 0 (was governor_fuel_active_flag)"),
    "0x0040af4c": ("protection_rpm_reference", "power_take_off_governor_reference_engine_speed", None,
                   "The power take-off governor's ramped engine speed target (rpm x 8); the engine speed while inactive; "
                   "PGN 65264 bytes 4-5 (was protection_rpm_reference)"),
    "0x0040af50": ("protection_eval_state", "power_take_off_governor_state", "POWER_TAKE_OFF_GOVERNOR_STATE",
                   "The power take-off governor state (e2m PTST): cm848_runPowerTakeOffGovernorStateMachine. RAM dump: 2 "
                   "WAIT (was protection_eval_state)"),
    "0x0040af52": ("protection_event_code", "power_take_off_governor_j1939_state", "POWER_TAKE_OFF_GOVERNOR_J1939_STATE",
                   "The J1939 SPN 976 PTO governor state of cm848_updatePowerTakeOffGovernorJ1939State, sent in CCVS1 "
                   "byte 7 bits 1-5 (was protection_event_code)"),
    "0x003fd89e": ("governor_fuel_limit_override", "power_take_off_maximum_torque_cal", None,
                   "EEPROM 0x41c: the power take-off maximum torque (10000 = none) that "
                   "cm848_applyPowerTakeOffTorqueLimit applies while the governor is active (was "
                   "governor_fuel_limit_override)"),
    "0x0040a2d8": ("governor_fuel_limit_cap", "power_take_off_torque_limit", None,
                   "0xffff (no limit) or power_take_off_maximum_torque_cal while the power take-off governor is active; "
                   "scales the cm848_calculateProtectionRateLimited limit (was governor_fuel_limit_cap)"),
    "0x0040a2da": ("governor_fuel_limit_cap_state", "power_take_off_torque_limit_state", None,
                   "The code cm848_calculateProtectionRateLimited gives its limit in torque_derate_fuel_source_code: "
                   "FUELING_STATE_NO_DERATE - or FUELING_STATE_POWER_TAKE_OFF_DERATE while "
                   "cm848_applyPowerTakeOffTorqueLimit lowers power_take_off_torque_limit (was "
                   "governor_fuel_limit_cap_state, governor_fuel_mode_command_cached)"),
    "0x003fd89a": ("protection_override_active_flag", "power_take_off_remote_switch_mode_cal", "word",
                   "EEPROM 0x418 (0 here): 0 lets the remote switch (19) take over from cab control in "
                   "cm848_runPowerTakeOffGovernorStateMachine - the meaning of the other values is not proved (was the "
                   "first word of the dword protection_override_active_flag)"),
    "0x003fd89c": ("protection_override_active_flag+2", "power_take_off_throttle_override_maximum_engine_speed_cal",
                   "word",
                   "EEPROM 0x41a (28000 = 3500 rpm): power_take_off_throttle_override_engine_speed_limit while the "
                   "throttle overrides the power take-off fuel (was the second word of protection_override_active_flag)"),
})
NEW_ENUMS += [
    "",
    "# Power take-off governor state (power_take_off_governor_state 0x40af50; e2m PTST 0=REMOTE_COUNT 1=REMOTE_RUN 2=WAIT "
    "3=NORMAL in CHR_CC_11.45.01.07 - the transitions of cm848_runPowerTakeOffGovernorStateMachine agree)",
    "POWER_TAKE_OFF_GOVERNOR_STATE,0,POWER_TAKE_OFF_GOVERNOR_STATE_REMOTE_COUNT,Counting presses of the remote switch "
    "(j1939_governor_feature_byte bit 1) - the count picks a preset speed,2",
    "POWER_TAKE_OFF_GOVERNOR_STATE,1,POWER_TAKE_OFF_GOVERNOR_STATE_REMOTE_RUN,Running at the remote preset speed until the "
    "switch opens or a cancel condition,2",
    "POWER_TAKE_OFF_GOVERNOR_STATE,2,POWER_TAKE_OFF_GOVERNOR_STATE_WAIT,Waiting: vehicle speed / engine speed window / "
    "faults / engine stopped / brake or clutch cancel. RAM dump: 2,2",
    "POWER_TAKE_OFF_GOVERNOR_STATE,3,POWER_TAKE_OFF_GOVERNOR_STATE_NORMAL,Running under cab control from the set / resume "
    "speeds (j1939_governor_feature_byte bit 0),2",
    "",
    "# Power take-off governor J1939 state (power_take_off_governor_j1939_state 0x40af52): SAE J1939-71 SPN 976 PTO "
    "Governor State (CCVS1 byte 7 bits 1-5). Stored here: 0 1 2 6 8 9 10-17",
] + [f"POWER_TAKE_OFF_GOVERNOR_J1939_STATE,{v},POWER_TAKE_OFF_GOVERNOR_J1939_STATE_{n},SPN 976 value {v}{c},2"
     for v, n, c in [(0, "OFF_OR_DISABLED", ""), (1, "HOLD", ""), (2, "REMOTE_HOLD", ""), (3, "STANDBY", " - not stored"),
                     (4, "REMOTE_STANDBY", " - not stored"), (5, "SET", " - not stored"),
                     (6, "DECELERATE_OR_COAST", ""), (7, "RESUME", " - not stored"), (8, "ACCELERATE", ""),
                     (9, "ACCELERATOR_OVERRIDE", "")]
                    + [(9 + k, f"PREPROGRAMMED_SET_SPEED_{k}", "") for k in range(1, 9)]
                    + [(31, "NOT_AVAILABLE", " - sent as 0x1F while the power take-off feature is off")]]
