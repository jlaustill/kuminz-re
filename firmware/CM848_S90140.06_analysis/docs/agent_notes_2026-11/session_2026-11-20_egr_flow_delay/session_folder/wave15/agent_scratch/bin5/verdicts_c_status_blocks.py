from helpers import keep, rename

ENTRIES = [
    # ---- block 117D (shared status words) --------------------------------------------------------------------
    rename(
        "0x0040a280", "torque_limit_init_flag", "programmable_power_active_selection",
        "e2m 117D +18 PP_Active_Selection (0-15, 'Current torque curve as specified by the Programmable Power feature'): "
        "initializeEngineSpeedLimitDefaults (shared with CM550 0x1d94e) is the only access and stores 0; the CM550 twin "
        "word 0x80a9e0 is the torque curve index (calculateAlphaFuelRateResult indexes with it, the droop slope is "
        "recomputed when it changes), so it is a selection, not an init flag; the old name had init",
        "initializeEngineSpeedLimitDefaults: torque_limit_init_flag = 0;",
        "e2m 117D +18 PP_Active_Selection '[PPAESE] Current torque curve as specified by the Programmable Power feature' "
        "(UNITLESS, 0-15; 0 in the dump): the selected torque curve of the programmable power feature (PP). Its only access "
        "in CM848 is the final store of initializeEngineSpeedLimitDefaults (sth 0; that function is shared with CM550 "
        "0x1d94e, where the twin word 0x80a9e0 indexes the alpha fuel rate tables and forces a droop slope recompute when "
        "it changes); nothing reads it here because algorithm_enable_flags_18_cal.programmable_power_enable is off"),
    rename(
        "0x0040a2b0", "protection_transition_block_flag", "power_take_off_disable_flag",
        "e2m 117D +48 PTO_Disable_Flag (HEX, 'Disables PTO when requested by another algorithm'): in the WAIT state "
        "cm848_runPowerTakeOffGovernorStateMachine can neither go to REMOTE_COUNT nor to NORMAL while it is nonzero, and "
        "the end of every pass clears it (the only store; nothing in this build sets it); 'protection transition block' "
        "is a bare protection name for a power take-off request",
        "cm848_runPowerTakeOffGovernorStateMachine: protection_transition_block_flag = 0;",
        "e2m 117D +48 PTO_Disable_Flag '[PTDSFG] Disables PTO when requested by another algorithm.' (HEX; 0 in the dump): "
        "a request that keeps the power take-off governor from engaging. While it is nonzero "
        "cm848_runPowerTakeOffGovernorStateMachine cannot leave POWER_TAKE_OFF_GOVERNOR_STATE_WAIT (neither for "
        "REMOTE_COUNT nor for NORMAL), and the end of every pass clears it, so a requester has to set it every pass. "
        "Nothing in this build sets it"),
    rename(
        "0x0040a2c4", "governor_startup_threshold", "electronic_smart_power_tau",
        "e2m 117D +5C ESP_Tau (UNITLESS, 1/16384, 0-1; 0 in the dump): its only reader calculateAlpha compares it with "
        "0x4000 (= 1.0) and, with bit 0x8000 of governor_feature_config_flags, takes alpha source 5 (ESP, "
        "fuel_blend_coefficient_run_cal); alpha_state's comment already reads it as e2m ESP_Tau; no governor start-up "
        "threshold exists",
        "calculateAlpha: if (((governor_feature_config_flags & 0x8000) == 0) || (governor_startup_threshold != 0x4000)) {",
        "e2m 117D +5C ESP_Tau '[SPTU] VALUE WHICH DETERMINES ALTERNATE HP RATINGS' (UNITLESS, 1/16384 per count, 0-1; 0 in "
        "the dump): the tau of the electronic smart power (ESP) feature, 0 = the low horsepower rating (Tau 0 curves), 1.0 "
        "(0x4000) = the high rating (Tau 1 curves). calculateAlpha is the only reader: with bit 0x8000 of "
        "governor_feature_config_flags set and this word at 0x4000 it selects alpha source 5 (ESP, "
        "electronic_smart_power_override_alpha_cal). Its source is e2m 117D +5E ESP_Tau_State = cruise_speed_offset_mode"),
    # ---- block 117F (trip / J1939 anti-theft / tire status) -----------------------------------------------------
    rename(
        "0x003fdd70", "protection_freq_divisor_working", "trip_distance_cal",
        "e2m 117F +4 Trip_Distance (MI, 1/64 mile per count): the only reader, cm848_j1939HandlePgn65248VehicleDistance, "
        "scales it by 0xc47400 / 64000000 = 0.20117 per count (1/64 mile x 1.609344 km / 0.125 km per bit) into the PGN "
        "65248 trip distance field; it is loaded with the EEPROM 0x8ea block (0x8ee) and never written; the old name has "
        "no connection; in the EEPROM mirror so _cal",
        "cm848_j1939HandlePgn65248VehicleDistance: protection_freq_divisor_working * 0xc47400) / 64000000);",
        "EEPROM 0x8ee (mirror): e2m 117F +4 Trip_Distance '[TIT3MI] The distance traveled since the last reset of trip' (MI, "
        "1/64 mile per count, dword; 0 in the dump): the trip distance field of J1939 PGN 65248. "
        "cm848_j1939HandlePgn65248VehicleDistance (the on-request responder) sends it x 0xc47400 / 64000000 = x 0.2012 (1/64 "
        "mile in 0.125 km bits). It is loaded with the EEPROM block that starts at lifetime_distance_pulses (EEPROM 0x8ea) "
        "and nothing writes it, so a J1939 reader always sees a trip distance of 0; the firmware's own trip distance (in "
        "speed sensor pulses) is the EEPROM 0x19a6 dword at 0x3fee28"),
    rename(
        "0x003fdd8a", "governor_prop_status_bits_0", "j1939_anti_theft_encryption_seed_present_cal",
        "e2m 117F +1E Jcomm_AT_Encryption_Seed_Present (0 / 1): cm848_sendJ1939ProprietaryStatus packs it as bits 1-0 of the "
        "status byte of PGN 56360, with password valid in bits 3-2, component status (+14) in bits 5-4 and status of request "
        "(+24) in bits 7-6, exactly the four e2m Jcomm_AT_* status fields; the AT siblings already carry "
        "j1939_anti_theft_*_cal; 'prop' is an abbreviation and 'governor' is wrong",
        "cm848_sendJ1939ProprietaryStatus: (char)governor_prop_status_bits_2 << 2 | (byte)governor_prop_status_bits_0;",
        "EEPROM 0x908 (mirror): e2m 117F +1E Jcomm_AT_Encryption_Seed_Present '[JCATSDPR] indicates via DL if VAT encryption "
        "seed is present' (UNITLESS, 0 / 1; 0 in the dump): bits 1-0 of the status byte that "
        "cm848_sendJ1939ProprietaryStatus builds for the J1939 anti-theft status message (PGN 56360; sent when the pending "
        "flag e2m +22 Jcomm_AT_Send_Status_Report is set, governor_system_config_flags bit 0x800 is set and "
        "j1939_prop_status_tx_state is 2). Bits 3-2 are "
        "j1939_anti_theft_password_valid_cal, bits 5-4 the component status (e2m +14) and bits 7-6 the status of the request "
        "(e2m +24). Read-only here"),
    rename(
        "0x003fdd8c", "governor_prop_status_bits_2", "j1939_anti_theft_password_valid_cal",
        "e2m 117F +20 Jcomm_AT_Password_Valid (0 / 1): cm848_sendJ1939ProprietaryStatus packs it as bits 3-2 of the status "
        "byte of PGN 56360 between the seed present bits (1-0) and the component status bits (5-4); the AT siblings already "
        "carry j1939_anti_theft_*_cal; 'prop' is an abbreviation and 'governor' is wrong",
        "cm848_sendJ1939ProprietaryStatus: (char)governor_prop_status_bits_2 << 2 | (byte)governor_prop_status_bits_0;",
        "EEPROM 0x90a (mirror): e2m 117F +20 Jcomm_AT_Password_Valid '[JCATPWVD] indicates via DL if VAT password entered is "
        "valid' (UNITLESS, 0 / 1; 0 in the dump): bits 3-2 of the status byte that cm848_sendJ1939ProprietaryStatus builds "
        "for the J1939 anti-theft status message (PGN 56360). Bits 1-0 are j1939_anti_theft_encryption_seed_present_cal, bits "
        "5-4 the component status (e2m +14) and bits 7-6 the status of the request (e2m +24). Read-only here"),
    rename(
        "0x003fdd92", "ascii_zero_detect_flag", "new_tires_installed_flag_cal",
        "e2m 117F +26 TW_New_Tires_Installed_Flag (0 / 1): the only access is cm848_j1939HandleProprietaryCommand (PGN 56832) "
        "storing 1 for command byte 0x30; the same handler stores e2m 1094 +4 OCM_Reset_Flag (oil change monitor manual reset, "
        "j1939_feature_enable_cmd_flag) for 0x20, so both are service reset commands; no reader of the tire flag was found; "
        "'ascii zero detect' names the 0x30 trigger, not the meaning; in the EEPROM mirror so _cal",
        "cm848_j1939HandleProprietaryCommand: ascii_zero_detect_flag = 1;",
        "EEPROM 0x910 (mirror): e2m 117F +26 TW_New_Tires_Installed_Flag '[TWNWTIFG] Indicates new tires have been installed.' "
        "(UNITLESS, 0 / 1; 1 in the dump): set to 1 by cm848_j1939HandleProprietaryCommand when the J1939 proprietary "
        "command (PGN 56832, gated by j1939_feature_enable_flags_cal bit 0x40) carries 0x30 in byte 1. Byte 1 = 0x20 sets "
        "j1939_feature_enable_cmd_flag = e2m 1094 +4 OCM_Reset_Flag (the oil change monitor manual reset) the same way. "
        "No reader of this flag was found; the e2m TW_Total_Miles_On_Tires (+28) has no row here"),
    # ---- block 1187 (cruise / road speed governor droop) ---------------------------------------------------
    rename(
        "0x0040b6b4", "cruise_speed_setpoint_c", "vehicle_speed_limit_fueling_bottom_droop_offset",
        "e2m 1187 +1E RSG_BDO (MM3S, 353 = 24.0 mm3): governorCruiseStateMachine stores it next to "
        "cruise_control_fueling_bottom_droop_offset (Cruise_BDO) and vehicle_speed_limit_fueling_bottom_droop_gain "
        "(RSG_BDG), and cm848_calculateVehicleSpeedLimitFueling uses it as the offset of the bottom droop line "
        "(cruise_speed_deviation = it - the speed excess / gain), the twin of vehicle_speed_limit_fueling_top_droop_offset "
        "(RSG_TDO); no cruise speed setpoint is involved",
        "cm848_calculateVehicleSpeedLimitFueling: cruise_speed_deviation = cruise_speed_setpoint_c - uVar1;",
        "e2m 1187 +1E RSG_BDO 'RSG BOTTOM DROOP OFFSET PASSED TO THE DESIRED_RS FUELING PROCEDURE.' (MM3S, 0.0679 mm3 per "
        "count; 353 in the dump = 24.0 mm3): the fueling at the limit speed on the bottom droop line of the road speed "
        "governor (RSG = the vehicle speed limit). governorCruiseStateMachine sets it to governor_cruise_fuel_demand_setpoint "
        "(the same value as cruise_control_fueling_bottom_droop_offset); with the vehicle speed above the limit "
        "cm848_calculateVehicleSpeedLimitFueling forms vehicle_speed_limit_fueling = this - the speed excess / "
        "vehicle_speed_limit_fueling_bottom_droop_gain (the top droop twin is vehicle_speed_limit_fueling_top_droop_offset)"),
    # ---- block 11C1 (TSC lost management) --------------------------------------------------------------------
    rename(
        "0x003feb90", "etc1_fuel_demand_high_limit", "tsc1_lost_management_maximum_accelerator_pedal_cal",
        "e2m 11C1 +4 TSC_Lost_Max_Throttle_Disable (%THROTTLE, 0.25 per count): cm848_runTsc1LostManagement ramps the "
        "limits only while the pedal (fuel_demand_control_t.calculated, 400 = 100 percent) is below it and resets above it; "
        "twin of tsc1_lost_management_minimum_accelerator_pedal (10E7 +28 TSC_Lost_Min_Throttle_Disable); the address is in "
        "the EEPROM mirror, so the name needs _cal",
        "cm848_runTsc1LostManagement: if ((etc1_fuel_demand_high_limit <= fuel_demand_control_t_0040a57a.calculated) &&",
        "EEPROM 0x170e (mirror): e2m 11C1 +4 TSC_Lost_Max_Throttle_Disable 'Throttle % above which TSC lost management is "
        "disabled.' (%THROTTLE, 0.25 percent per count; 0 in the dump): the upper accelerator pedal limit "
        "(fuel_demand_control_t.calculated, 400 = 100 percent) of the J1939 TSC1 lost management. "
        "cm848_runTsc1LostManagement ramps the speed and torque limits (governor mode 3) only while the pedal is above "
        "tsc1_lost_management_minimum_accelerator_pedal and below this; at or above it the mode 3 torque limit is 0xffff (no "
        "limit) and the management resets. 0 in the dump, so the ramp branch is never taken"),
    # ---- block 1260 (alpha overrides) ------------------------------------------------------------------------
    rename(
        "0x003fd514", "fuel_blend_coefficient_startup_cal", "user_override_alpha_cal",
        "e2m 1260 +0 User_Override_Alpha (alpha, 1/16384): calculateAlpha loads it into combustion_alpha_input as alpha source 1 "
        "(alpha_state 1, user, while bit 0 of governor_feature_flags is set); alpha_state's comment already calls source 1 "
        "user; 'fuel blend coefficient startup' is an old guess (the fuel_blend_* words were the alpha / chi terms)",
        "calculateAlpha: combustion_alpha_input = fuel_blend_coefficient_startup_cal;",
        "EEPROM 0x92 (mirror): e2m 1260 +0 User_Override_Alpha '[APUOAP] Value of alpha desired by engineering applications' "
        "(UNITLESS, 1/16384 per count, 0-1; 0 in the dump): the alpha that calculateAlpha outputs as combustion_alpha_input "
        "(alpha_state 1, user) while bit 0 of governor_feature_flags is set (alpha 0 = urban, 16384 = 1.0 = open road). Same "
        "alpha chain as altitude_derate_alpha / engine_protection_alpha (e2m 104B). Read-only"),
    rename(
        "0x003fd516", "fuel_blend_coefficient_run_cal", "electronic_smart_power_override_alpha_cal",
        "e2m 1260 +2 ESP_Override_Alpha (alpha, 1/16384, 'if Smart Power is limiting fuel'): calculateAlpha loads it into "
        "combustion_alpha_input as alpha source 5 (alpha_state 5, esp: bit 0x8000 of governor_feature_config_flags with "
        "electronic_smart_power_tau at 0x4000); 'fuel blend coefficient run' is an old guess",
        "calculateAlpha: combustion_alpha_input = fuel_blend_coefficient_run_cal;",
        "EEPROM 0x94 (mirror): e2m 1260 +2 ESP_Override_Alpha 'Value of Alpha to be output if Smart Power is limiting fuel.' "
        "(UNITLESS, 1/16384 per count, 0-1; 0 in the dump): the alpha that calculateAlpha outputs as combustion_alpha_input "
        "(alpha_state 5, esp) when bit 0x8000 of governor_feature_config_flags is set and electronic_smart_power_tau is "
        "0x4000 (ESP = electronic smart power). Twin of user_override_alpha_cal. Read-only"),
    # ---- block 1262 / 1387: synonyms, kept ---------------------------------------------------------------------
    keep(
        "0x003fd816", "engine_speed_limit_source_2_mode_cal",
        "e2m 1262 +2 HSG_Modified_Speed_Type 'Type ind. 0,1=Ref 2,3=Isoc. 1,3=add offset'"),
    keep(
        "0x003fd526", "governor_tuning_set_default_blend_weight_cal",
        "e2m 1387 +8 ASG_Droop_Flag_Trim 'Trim for ASG droop selection flag; select droop source'"),
]
