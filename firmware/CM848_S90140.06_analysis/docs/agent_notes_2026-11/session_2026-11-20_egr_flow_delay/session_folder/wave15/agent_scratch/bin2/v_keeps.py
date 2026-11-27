"""Keeps and drift for the non-8A12 blocks of bin 2."""

V = [
    # ---- 169A charge flow derate filter constants
    {'address': '0x003ff724', 'verdict': 'keep',
     'e2m_note': "e2m 169A +8 C_CHL_Delta_P_Drt_Fil_Cnst 'Filter constant for Delta_p derate of charge flow' "
                 "(filter constant = filter coefficient; the record scale 1/65536 matches the dump 64684 = 0.987; "
                 "the derate offset it filters is the charge_flow_delta_pressure_derate_* family)"},
    {'address': '0x003ff72c', 'verdict': 'keep',
     'e2m_note': "e2m 169A +10 C_CHL_Turbo_Drt_Fil_Cnst 'Filter constant for turbo speed derate of charge flow' "
                 "(turbo = turbocharger, filter constant = filter coefficient; scale 1/65536, 0 in the dump = no filtering)"},

    # ---- 16A3 wastegate duty controller mode flags (EEPROM mirror, _cal is right)
    {'address': '0x003fd7e0', 'verdict': 'keep',
     'e2m_note': "e2m 16A3 +4 T_TCG_Variable_ULim_Mode '1 variable ULim; 0 for C_TGC_ULim' "
                 "(ULim = the ceiling: 1 takes it from the engine speed x load grid, 0 from the fixed "
                 "battery-voltage-scaled wastegate_duty_ceiling_fixed; the code in cm848_calculateWastegateDutyRequest agrees)"},
    {'address': '0x003fd7e2', 'verdict': 'keep',
     'e2m_note': "e2m 16A3 +6 T_TCG_Variable_LLim_Mode '1 variable LLim; 0 for C_TGC_LLim' "
                 "(LLim = the floor: 1 takes it from the wastegate_duty_floor_* grid, 0 uses wastegate_duty_floor_fixed; "
                 "the code in cm848_calculateWastegateDutyRequest agrees)"},
    {'address': '0x003fd7e6', 'verdict': 'keep',
     'e2m_note': "e2m 16A3 +A T_TGC_COT_Drt_Mode '1 for closed-loop COT limiting; 0 for COT derate function' "
                 "(the second error loop of cm848_calculateWastegateDutyRequest is the compressor outlet temperature one: "
                 "non-zero limits the control term to wastegate_duty_compressor_outlet_temperature_derate_error_term = "
                 "closed-loop COT limiting; dump 1)"},

    # ---- 18F0 rail pressure cusum monitor
    {'address': '0x0040ba66', 'verdict': 'keep',
     'e2m_note': "e2m 18F0 +4 HPCR_Cusum_Leak_Delta 'HPCR rail pressure deviation from set point used for leak detection' "
                 "(the same quantity: cm848_monitorFuelPressureSetpointNotReached adds this signed per-pass deviation "
                 "(setpoint - feedback) / divisor to its clamped-at-0 accumulator = e2m +0 HPCR_Cusum_Leak_Pos; the code name "
                 "describes the symptom, the e2m the cause; i16 matches the record)"},

    # ---- 1982 water vapor partial pressures
    {'address': '0x0040af6e', 'verdict': 'keep',
     'e2m_note': "e2m 1982 +6 Charge_H2O_PP 'Partial-pressure of water in charge air' "
                 "(H2O = water vapor; the record scale 4.97e-4 inHg per count is the x 4 count of the 0.001988 inHg unit "
                 "of the saturation tables, which is what the name says)"},
    {'address': '0x0040af70', 'verdict': 'keep',
     'e2m_note': "e2m 1982 +8 Exhaust_H2O_PP 'Partial-pressure of water in exhaust gas' "
                 "(H2O = water vapor; scale 4.97e-4 inHg per count: dump 37168 = 18.5 inHg, the x 4 count the name says)"},

    # ---- 8022 rail pressure setpoint
    {'address': '0x00409a71', 'verdict': 'keep',
     'e2m_note': "e2m 8022 +7 HPCR_Fuelpr_Selection_Switch_N 'Fuel press setpoint selection switch (0=increment,1=MIN WINS)' "
                 "(the same switch: 0 sums the terms, 1 takes the lower of the map and the limit terms; 1 in the dump)"},
    {'address': '0x00409a80', 'verdict': 'keep',
     'e2m_note': "e2m 8022 +16 HPCR_Fuelpr_Hyst_Fueling_Threshold 'Setpoint rail hyst applied only below this fueling value' "
                 "(hysteresis = deadband, threshold = limit; cm848_calculateFuelPressureSetpoint applies the dead band only "
                 "while final_fueling is below it)"},
    {'address': '0x00409a82', 'verdict': 'keep',
     'e2m_note': "e2m 8022 +18 HPCR_Fuelpr_Hyst_RPM_Threshold 'Setpoint rail hyst applied only below this engine speed' "
                 "(hysteresis = deadband, threshold = limit; cm848_calculateFuelPressureSetpoint applies the dead band only "
                 "while average_engine_speed is below it)"},

    # ---- 8041 injector driver: the open circuit offset
    {'address': '0x004090c4', 'verdict': 'keep',
     'e2m_note': "e2m 8041 +24 HPCR_Open_Injector_Recharge_Offset 'Offset value for injector offset during an open circuit failure' "
                 "(engine_injectionAngle_selectCylinderInjector shifts the injector output index by it, mod the cylinder count, "
                 "when the cylinder's open circuit or fast decay diagnostic bit is set; dump 4 in the record range 0..12)"},

    # ---- 8C50 / 8C5E
    {'address': '0x0040871b', 'verdict': 'keep',
     'e2m_note': "e2m 8C50 +3 Alt_Not_Brake_Output_Inversion 'Calibration to invert Alt_Not_Brake_Switch 1=invert 0=no-invert.' "
                 "(Alt_Not_Brake_Switch = the second brake switch, DRB NOT BRAKE SWITCH; cm848_deriveSecondBrakeSwitchSignal "
                 "inverts the idle trigger when it is non-zero)"},
    {'address': '0x00408dce', 'verdict': 'keep',
     'e2m_note': "e2m 8C5E +4 CWG_Duty_Cycle_Overide_Value 'Value entered by diagnostic tool' "
                 "(the override duty: cm848_applyWastegateSolenoidDuty uses it instead of the request while "
                 "wastegate_solenoid_fixed_duty_enable (e2m 8C5E +0 CWG_Duty_Cycle_Overide) is set; 1/256 % per count matches the record scale)"},
    {'address': '0x00408dd6', 'verdict': 'keep',
     'e2m_note': "e2m 8C5E +C Wastegate_Pres_Control_Driver_Inhibit_Timer_Offset 'Wastegate duty cycle Off cycle time when open or short circuit' "
                 "(the e2m description repeats the +A record's; the code role stays: in cm848_applyWastegateSolenoidDuty a read-back fault "
                 "lasting this many passes restarts the retest, and the 100 % phase of the retest lasts twice this after the "
                 "+A off passes; 25 passes x 0.02 s in the dump)"},

    # ---- drift
    {'address': '0x00409fea', 'verdict': 'drift',
     'evidence': "e2m 1B2E +A CWG_Driver_In_Use_Ratio_Duty_Cycle_Threshold (%, U, 1/256, 0..100): this ROM has no such scalar here; "
                 "0x409fea is the byte-length word of the 4-breakpoint axis wastegate_monitor_fail_high_boost_pressure_axis "
                 "(dump 8 = 4 x 2 bytes, x 0.0039 = 0.03 %, not a threshold) followed by the barometric breakpoints 1194 1446 1697 1886 "
                 "read by lookupTableInterpolation in cm848_monitorWastegateBoostPressure, so e2m +C CWG_On_Max_Time would land on the "
                 "first breakpoint; the 11.45 e2m has two extra scalars after +8 that the truck's 11.46.06 table layout lacks; keep the table name"},
]
