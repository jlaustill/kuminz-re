"""Round 8 stage G (label-only, the second review): the exhaust brake inhibit words get the word order of their e2m
records. RE_E_Brake_Inhibit_LU means the exhaust brake is inhibited (for the lockup), while 'exhaust_brake_lockup_inhibit'
read as a lockup inhibited by the exhaust brake, and the same function also sets a real lockup inhibit (condition_eval
bit 6) at the timeout. The flag byte takes its record name (8C19 +16 RE_Trans_EBrake 'Contains engine brake flags'); its
bit 2 is RE_Ebrake_Inhibit_Timeout_Flag ('E-Brake inhibit timeout flag'), which the code sets exactly when the inhibit
timer runs out."""

GLOBALS = [
    ("0x0040b0fe", "transmission_exhaust_brake_flags",
     "e2m 8C19 +16 RE_Trans_EBrake ('Contains engine brake flags'); 8C19 aligns at 0x40b0e8 (protection_condition_flags_t; "
     "checked by code use at +0..+3, +9, +A, +C and +16). The byte's bit records: RE_E_Brake_Inhibit_LU ('Flag set to "
     "inhibit Exhaust Brake to allow TCC lockup'), RE_Ebrake_Inhibit_Timeout_Flag ('E-Brake inhibit timeout flag'), "
     "RE_EB_Lockup_Aid_Flag, RE_EB_Delay_4_3_Flag and RE_E_Brake_Inhibit_LU_Flag. 23 accesses, all lbz / stb. Bit 0 = "
     "RE_E_Brake_Inhibit_LU: set at the rising edge of the converter clutch solenoid request, by the exhaust brake "
     "(engine_retarder_active_flag) as the gear is forced to 2nd and after a 4-3 downshift with it; cleared when "
     "transmission_speed_ratio is inside the gear's exhaust_brake_lockup_speed_ratio window (lock confirmed), in 1st, at "
     "the request's falling edge or under condition_eval bit 6; cm848_updateEngineRetarderEnableState reads it as the "
     "torque converter lockup disengaged input (algorithm_enable_flags_6_cal bit 2). Bit 2 = "
     "RE_Ebrake_Inhibit_Timeout_Flag: set with condition_eval bit 6 when exhaust_brake_inhibit_timer runs out, cleared "
     "when that bit clears. Bit 1: set with bit 0 as the gear is forced to 2nd with the exhaust brake active (once per "
     "entry); which of the other three records it is is not proved. Updated with | / & masks, so no bitfield"),
    ("0x0040b14c", "exhaust_brake_inhibit_timer",
     "e2m 8C17 +4A RE_E_Brake_Inhibit_Timer ('Used to time ebrake TCC inhibit timeout limit'): while bit 0 of "
     "transmission_exhaust_brake_flags (RE_E_Brake_Inhibit_LU) holds the exhaust brake off for a converter clutch "
     "lockup, it counts down from exhaust_brake_inhibit_timeout; at 0 it sets condition_eval bit 6 and bit 2 of the flags "
     "(RE_Ebrake_Inhibit_Timeout_Flag). 300 in the RAM dump (no inhibit pending)"),
    ("0x0040838a", "exhaust_brake_inhibit_timeout",
     "e2m 8C18 +96 RE_E_Brake_Inhibit_Timeout ('Limit for ebrake inhibit while waiting for TCC Lockup'): 300 = 3 s; "
     "reloads exhaust_brake_inhibit_timer"),
    ("0x003fb1cc", "exhaust_brake_inhibit_previous",
     "Last pass's transmission_exhaust_brake_flags bit 0 (RE_E_Brake_Inhibit_LU) as 0 / 1; "
     "cm848_updateExhaustBrakeInhibitForLockup clears the inhibit at the converter clutch request's falling edge only "
     "when it has not changed since"),
]
FUNCTIONS = [
    ("0x00034f4c", "cm848_updateExhaustBrakeInhibitForLockup",
     "The exhaust brake lockup aid (e2m RE_E_Brake_Inhibit_LU / RE_EB_Lockup_Range_* / RE_E_Brake_Inhibit_Timeout): the "
     "exhaust brake is held off until the converter locks. The rising edge of the converter clutch solenoid request "
     "(logical output 18) sets bit 0 of transmission_exhaust_brake_flags (cm848_updateEngineRetarderEnableState reads it "
     "as lockup disengaged). exhaust_brake_inhibit_timer counts down from exhaust_brake_inhibit_timeout (3 s). While the "
     "request is on and transmission_speed_ratio is inside the gear's window (exhaust_brake_lockup_speed_ratio_2nd / 3rd / "
     "4th_gear_minimum / _maximum, around the gear ratios), bits 0 and 2 clear: lock confirmed, the exhaust brake may "
     "apply. In 1st they clear too. If the timer runs out first, it sets condition_eval bit 6 (the converter lockup "
     "inhibit / unlock request) and bit 2 (RE_Ebrake_Inhibit_Timeout_Flag). Called at the end of "
     "cm848_selectGovernorPressureLockupBoost"),
]
