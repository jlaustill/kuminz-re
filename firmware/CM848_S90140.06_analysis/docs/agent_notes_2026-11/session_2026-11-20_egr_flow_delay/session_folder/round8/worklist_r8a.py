"""Round 8 stage A (main session, label-only): the 48RE anti-hunt governor pressure mode and its post-shift
acceleration prediction (all were `protection_*` names).
Read in full: 0x3257c, 0x32250, 0x320e0, 0x3241c. The Chrysler e2m names the vocabulary:
- 8BBC (ROM; not in the ECU's parameter ID table). Base 0x40780c is proved by +2..+8 = the four anti-hunt timer
  limits loaded where the code uses them, +A / +E / +12 / +14 = the available torque floor, the inertia learning
  throttle gate and the inertia limits, and +10 RE_Inertia_Default = 53 = the learned inertia in the RAM dump.
- 8C17 (RAM; not in the table). Base 0x40b102 is proved by +0..+6 = the anti-hunt timers after the e2m 8C53 pressure
  state at 0x40b100 (table-resolved), and by +28 RE_OSS_Accel = 0x40b12a, the output shaft acceleration word.
- The tables: RE_AH_Boost_Curve_1_2 / 2_3 (pressure vs output speed 'to force' the upshift), RE_Hold_Curve_1 / 2
  (pressure vs throttle 'to prevent' it), RE_PSA_Max_1_2 / 2_3 / 3_4 ('Min acceptable post-shift accel vs TPS to
  allow' the upshift), RE_TPS_3DSCL / RE_Turbine_3DSCL / RE_Torque_Input (the turbine torque estimate).
- The gear ratio table at 0x40786a (x 32, index gear + 1: 78 / 46 / 32 / 20 = 2.44 / 1.44 / 1.00 / 0.63) proves the
  model's index: gear + 1 is the current gear, gear + 2 the next."""
A = "the anti-hunt governor pressure mode (cm848_selectGovernorPressureAntiHunt)"
GLOBALS = [
    ("0x0040780c", "transmission_third_gear_lockup_enable",
     "e2m 8BBC +0 RE_3rd_Gear_Lockup ('Indicates if lockup should be allowed in 3rd gear'; 1 in the RAM dump); tested by "
     "cm848_applyConverterLockupSchedule and cm848_processOverdriveSwitchAndShift. Block 8BBC is not in the parameter "
     "ID table: its base is proved by the anti-hunt words that follow"),
    ("0x0040780e", "transmission_anti_hunt_boost_limit_time",
     f"e2m 8BBC +2 RE_AH_Boost_Limit_Timer_Max ('Anti-hunt timer boost limit'; 10 ms counts, 11 = 110 ms): reloads "
     f"transmission_pressure_state.anti_hunt_boost_limit_timer in {A}"),
    ("0x00407810", "transmission_anti_hunt_delay_time",
     "e2m 8BBC +4 RE_AH_Delay_Timer_Max ('1-2 AH upshift delay to allow time for OSS accel calc'; 60 = 600 ms): "
     "reloads transmission_pressure_state.anti_hunt_delay_timer after a forced upshift completes"),
    ("0x00407812", "transmission_anti_hunt_1_2_boost_time",
     "e2m 8BBC +6 RE_AH_Timer_1_2_Max ('Time boost press held after 2nd gear is identified'; 100 = 1 s)"),
    ("0x00407814", "transmission_anti_hunt_2_3_boost_time",
     "e2m 8BBC +8 RE_AH_Timer_2_3_Max ('Time boost press held after 3rd gear is identified'; 200 = 2 s)"),
    ("0x00407816", "transmission_available_torque_minimum",
     "e2m 8BBC +A RE_Available_Torque_Min ('Minimum calculated available torque for post_shift accel calc'; 0): a "
     "smaller transmission_next_gear_available_torque counts as 0"),
    ("0x00407818", "transmission_3_4_unlock_engine_speed_drop",
     "e2m 8BBC +C RE_Delta_RPM_To_Unlock ('Engine speed drop from 3rd gear to unlock for 3-4 shift'; 368 = 46 rpm); "
     "compared in cm848_applyConverterUnlockConditions"),
    ("0x0040781a", "transmission_vehicle_inertia_learning_minimum_throttle",
     "e2m 8BBC +E RE_Inertia_Calc_Min ('Minimum throttle opening to allow vehicle inertia calc'; 120 = 30 %): "
     "cm848_learnVehicleInertia runs only above it"),
    ("0x0040781e", "transmission_vehicle_inertia_maximum",
     "e2m 8BBC +12 RE_Inertia_Max (x 0.32164 slug ft2; 221 = 71): the largest measurement cm848_learnVehicleInertia "
     "accepts"),
    ("0x00407820", "transmission_vehicle_inertia_minimum",
     "e2m 8BBC +14 RE_Inertia_Min: the smallest measurement cm848_learnVehicleInertia accepts"),
    ("0x00407850", "transmission_vehicle_inertia_learning_minimum_acceleration_change",
     "e2m 8BBC +44 RE_Min_Accel_Inertia_Calc ('Min absolute OSS accel to allow inertia update'; 0 in the RAM dump): "
     "cm848_learnVehicleInertia keeps a measurement only when the acceleration change is larger"),
    ("0x0040b100", "transmission_pressure_state",
     "the RE transmission pressure state block: e2m 8C53 +0 RE_Trans_Pressure_State (table-resolved to this address) "
     "followed by the e2m 8C17 anti-hunt timers (transmission_pressure_state_t)"),
    ("0x0040b12a", "transmission_output_shaft_acceleration",
     "e2m 8C17 +28 RE_OSS_Accel ('Transmission output shaft acceleration'). Block 8C17 is not in the parameter ID table; "
     "its base 0x40b102 is proved by +0..+6 = the anti-hunt timers of transmission_pressure_state and by this word"),
    ("0x0040b0b0", "transmission_vehicle_inertia",
     "the learned vehicle inertia (e2m RE_Inertia, x 0.32164 slug ft2; 53 = RE_Inertia_Default in the RAM dump): "
     "cm848_learnVehicleInertia stores a measurement within the minimum / maximum, cm848_predictPostShiftAcceleration "
     "divides by it"),
    ("0x0040b0da", "transmission_vehicle_inertia_measurement",
     "transmission_shift_torque_change x 64 / transmission_shift_acceleration_change across the last forced upshift "
     "(cm848_learnVehicleInertia, 0-0xffff); stored as transmission_vehicle_inertia when inside the limits and the "
     "acceleration change is large enough"),
    ("0x0040b0b8", "transmission_predicted_post_shift_acceleration",
     "cm848_predictPostShiftAcceleration: transmission_next_gear_available_torque x 64 / transmission_vehicle_inertia "
     f"(at most 0x7fff); {A} forces the upshift once it is above transmission_post_shift_acceleration_minimum"),
    ("0x0040b0c2", "transmission_inertia_torque",
     "transmission_output_shaft_acceleration x transmission_vehicle_inertia / 64 (clamped +-10000): the torque that "
     "accelerates the vehicle now"),
    ("0x0040b0c4", "transmission_next_gear_available_torque",
     "transmission_output_torque_next_gear - transmission_road_load_torque (0-5000; 0 below "
     "transmission_available_torque_minimum): the torque left to accelerate after the upshift"),
    ("0x0040b0ba", "transmission_road_load_torque",
     "transmission_output_torque_current_gear - transmission_inertia_torque (clamped +-5000)"),
    ("0x0040b0ae", "transmission_output_torque_current_gear",
     "cm848_calculateTransmissionOutputTorqueInGear for the current gear (index gear + 1)"),
    ("0x0040b0b4", "transmission_output_torque_next_gear",
     "cm848_calculateTransmissionOutputTorqueInGear for the next gear (index gear + 2; in 4th gear the current gear again)"),
    ("0x0040b0b2", "transmission_output_torque_at_shift_command",
     f"the current gear's output torque when {A} forced the 1-2 upshift; cm848_learnVehicleInertia subtracts the new "
     "gear's torque"),
    ("0x0040b0b6", "transmission_output_shaft_acceleration_at_shift_command",
     "transmission_output_shaft_acceleration when the 1-2 upshift was forced"),
    ("0x0040b0c6", "transmission_shift_acceleration_change",
     "the output shaft acceleration change across the forced upshift (e2m RE_OSS_Accel_Change_1_2)"),
    ("0x0040b0c8", "transmission_shift_torque_change",
     "the output torque change across the forced upshift (e2m RE_Torque_Change_1_2)"),
    ("0x0040b0ca", "transmission_output_torque_gear_index",
     "the gear index last passed to cm848_calculateTransmissionOutputTorqueInGear (gear + 1 = the current gear)"),
    ("0x0040b0bc", "transmission_turbine_speed_in_gear",
     "transmission_output_speed_in_use x the gear's transmission_gear_ratio_table value >> 5 (at most 0xffff)"),
    ("0x0040b0cc", "transmission_turbine_speed_prescaled",
     "the turbine speed through transmission_turbine_speed_prescale_values (e2m RE_Turbine_3DSCL: 'pre-scale turbine "
     "spd for use in trans turbine torque calc')"),
    ("0x0040b0ce", "transmission_throttle_prescaled",
     "the accelerator (fuel_demand_control_t.calculated, 400 = 100 %) through transmission_throttle_prescale_values "
     "(e2m RE_TPS_3DSCL)"),
    ("0x0040b0d4", "transmission_turbine_torque",
     "transmission_turbine_torque_grid at the two prescaled inputs (e2m RE_Torque_Input: 'estimate trans turbine torque "
     "vs scaled TPS and turbine spd'; ft lb)"),
    ("0x0040b0d0", "transmission_output_torque_in_gear",
     "transmission_turbine_torque x the gear's ratio >> 5: what cm848_calculateTransmissionOutputTorqueInGear returns"),
    ("0x0040b0c0", "transmission_post_shift_acceleration_minimum",
     "the e2m RE_PSA_Max_1_2 / _2_3 / _3_4 value at the current throttle ('Min acceptable post-shift accel vs TPS to "
     "allow ... upshift')"),
    ("0x0040786a", "transmission_gear_ratio_table",
     "the gear ratios x 32, indexed gear + 1: [2] 78 = 2.44 (1st), [3] 46 = 1.44, [4] 32 = 1.00, [5] 20 = 0.63 (4th), "
     "[6] 14 unused; [0] 10 and [1] 512 unexplained (RAM dump). Typed byte, read as words"),
    ("0x00407876", "transmission_anti_hunt_1_2_boost_pressure_axis",
     "e2m RE_AH_Boost_Curve_1_2_OSS_Axis: the output shaft speed axis (1/8 rpm)"),
    ("0x00407886", "transmission_anti_hunt_1_2_boost_pressure_values",
     "e2m RE_AH_Boost_Curve_1_2 ('Governor press vs oss to force 1-2 shift under anti-hunt conditions'; 1/128 psi): "
     "pressure state 0x12"),
    ("0x00407896", "transmission_anti_hunt_2_3_boost_pressure_axis",
     "e2m RE_AH_Boost_Curve_2_3_OSS_Axis: the output shaft speed axis"),
    ("0x004078a6", "transmission_anti_hunt_2_3_boost_pressure_values",
     "e2m RE_AH_Boost_Curve_2_3 ('... to force 2-3 shift under anti-hunt conditions'): pressure state 0x13"),
    ("0x004079c6", "transmission_anti_hunt_1_2_hold_pressure_axis",
     "e2m RE_Hold_Curve_1_Throttle_Axis: the accelerator axis (400 = 100 %)"),
    ("0x004079d8", "transmission_anti_hunt_1_2_hold_pressure_values",
     "e2m RE_Hold_Curve_1 ('Governor Press vs TPS to prevent 1-2 upshift in anti-hunt conditions'): pressure state 0x14"),
    ("0x004079ea", "transmission_anti_hunt_2_3_hold_pressure_axis", "e2m RE_Hold_Curve_2_Throttle_Axis"),
    ("0x004079fc", "transmission_anti_hunt_2_3_hold_pressure_values",
     "e2m RE_Hold_Curve_2 ('... to prevent 2-3 upshift in anti-hunt conditions'): pressure state 0x15"),
    ("0x00407cce", "transmission_1_2_upshift_minimum_post_shift_acceleration_axis",
     "e2m RE_PSA_Max_1_2_Throttle_Axis: the accelerator axis"),
    ("0x00407cdc", "transmission_1_2_upshift_minimum_post_shift_acceleration_values",
     "e2m RE_PSA_Max_1_2 ('Min acceptable post-shift accel vs TPS to allow 1-2 upshift'; signed)"),
    ("0x00407cea", "transmission_2_3_upshift_minimum_post_shift_acceleration_axis", "e2m RE_PSA_Max_2_3_Throttle_Axis"),
    ("0x00407cf8", "transmission_2_3_upshift_minimum_post_shift_acceleration_values", "e2m RE_PSA_Max_2_3"),
    ("0x00407d06", "transmission_3_4_upshift_minimum_post_shift_acceleration_axis", "e2m RE_PSA_Max_3_4_Throttle_Axis"),
    ("0x00407d14", "transmission_3_4_upshift_minimum_post_shift_acceleration_values",
     "e2m RE_PSA_Max_3_4; in 3rd gear a predicted acceleration above it sets bit 2 of "
     "protection_condition_flags_t_0040b0e8.condition_eval"),
    ("0x00407c96", "governor_pressure_base_curve_axis",
     "the output shaft speed axis of the base governor pressure curve (pressure state 1; also in "
     "cm848_selectGovernorPressureBaseCurve)"),
    ("0x00407cb2", "governor_pressure_base_curve_values", "the base governor pressure curve (pressure state 1)"),
    ("0x00407e12", "transmission_turbine_speed_prescale_axis",
     "e2m RE_Turbine_3DSCL_Speed_Axis (9 points here, 8 in the 11.45 e2m)"),
    ("0x00407e26", "transmission_turbine_speed_prescale_values", "e2m RE_Turbine_3DSCL"),
    ("0x00407dca", "transmission_throttle_prescale_axis",
     "e2m RE_TPS_3DSCL_Throttle_Axis (17 points here, 8 in the 11.45 e2m)"),
    ("0x00407dee", "transmission_throttle_prescale_values", "e2m RE_TPS_3DSCL"),
    ("0x00407f46", "transmission_turbine_torque_x_axis", "e2m RE_Torque_Input_TPS_Axis: the prescaled throttle (17)"),
    ("0x00407f6a", "transmission_turbine_torque_y_axis",
     "e2m RE_Torque_Input_Turbine_Axis: the prescaled turbine speed (9)"),
    ("0x00407f7e", "transmission_turbine_torque_grid",
     "e2m RE_Torque_Input ('Table to estimate trans turbine torque vs scaled TPS and turbine spd'; ft lb): 17 x 9 here, "
     "5 x 5 in the 11.45 e2m"),
    ("0x003fb0ee", "governor_pressure_base_curve_interp_state", "lookup cache of governor_pressure_base_curve_*"),
    ("0x003fb0f0", "transmission_anti_hunt_1_2_boost_pressure_interp_state",
     "lookup cache of transmission_anti_hunt_1_2_boost_pressure_*"),
    ("0x003fb0f2", "transmission_anti_hunt_2_3_boost_pressure_interp_state",
     "lookup cache of transmission_anti_hunt_2_3_boost_pressure_*"),
]
FUNCTIONS = [
    ("0x0003257c", "cm848_selectGovernorPressureAntiHunt",
     "The 48RE anti-hunt governor pressure mode (e2m RE_AH_* / RE_Hold_Curve_* / RE_PSA_Max_*). In 1st / 2nd gear it "
     "holds the governor pressure on the hold curve against the throttle, which prevents the upshift (pressure states "
     "0x14 / 0x15). When the predicted post-shift acceleration is above the minimum for the throttle "
     "(cm848_predictPostShiftAcceleration) and the anti-hunt delay has run out, it forces the upshift with the boost "
     "curve against the output shaft speed (0x12 / 0x13) and keeps it for the boost time after the new gear is "
     "identified. After a forced 1-2 upshift it learns the vehicle inertia (cm848_learnVehicleInertia). In 3rd gear a "
     "high enough prediction sets bit 2 of protection_condition_flags_t_0040b0e8.condition_eval (the 3-4 upshift is "
     "the overdrive solenoid's)"),
    ("0x00032250", "cm848_predictPostShiftAcceleration",
     "Predicts the output shaft acceleration after an upshift: the road load (current gear torque - inertia x "
     "acceleration) taken from the next gear's torque, divided by the learned vehicle inertia "
     "(transmission_predicted_post_shift_acceleration). Runs only while the output shaft is not decelerating"),
    ("0x000320e0", "cm848_calculateTransmissionOutputTorqueInGear",
     "The transmission output torque in a gear (the parameter: gear + 1 = the current gear) at the current output "
     "speed and throttle: turbine speed = output speed x the gear ratio, the turbine torque from the prescaled throttle "
     "and turbine speed (e2m RE_TPS_3DSCL / RE_Turbine_3DSCL / RE_Torque_Input), times the gear ratio"),
    ("0x0003241c", "cm848_learnVehicleInertia",
     "After a forced 1-2 upshift, above transmission_vehicle_inertia_learning_minimum_throttle: measures the vehicle "
     "inertia as the output torque change x 64 / the output shaft acceleration change across the shift, and keeps it "
     "as transmission_vehicle_inertia when the change is large enough and the value is within the minimum / maximum "
     "(e2m RE_Inertia)"),
]
