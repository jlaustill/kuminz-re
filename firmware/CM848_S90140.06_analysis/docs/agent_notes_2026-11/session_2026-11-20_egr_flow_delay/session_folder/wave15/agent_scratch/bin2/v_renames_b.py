"""Renames, part B: wastegate user override, injector driver reference levels, all speed governor equivalent throttle,
net torque fuel limit table output."""

V = [
    # ---------------- 16A3 wastegate duty controller (EEPROM mirror)
    {'address': '0x003fd7dc', 'verdict': 'rename',
     'new': 'wastegate_duty_user_override_enable_cal',
     'evidence': "e2m 16A3 +0 T_TGC_User_Override ('user override enable for turbocharger control'): in cm848_calculateWastegateDutyRequest "
                 "exactly 1 makes the request the feedforward base alone, and wastegate_duty_override_value (e2m 16A1 +E C_TGC_Override_Value "
                 "'override value for turbocharger position demand') is copied into that feedforward term every pass, so the flag enables the "
                 "user override; any non-zero value also presets the integrator to minus the proportional term; the old name kept only "
                 "that side effect; dump 0",
     'code_quote': "cm848_calculateWastegateDutyRequest: if (wastegate_duty_integrator_preset_flag_cal != 1) {",
     'comment': "e2m 16A3 +0 T_TGC_User_Override 'User override enable for turbocharger control' (UNITLESS, 0..65535; EEPROM 0x35a; 0 in "
                "the dump). cm848_calculateWastegateDutyRequest: exactly 1 makes the wastegate duty request the override value alone "
                "(wastegate_duty_override_value, e2m 16A1 +E C_TGC_Override_Value, which the function copies into the feedforward term "
                "wastegate_duty_feedforward_term every pass) clamped between the floor and the ceiling; any non-zero value also presets the "
                "integrator to minus the rate-limited proportional term every pass. 0x3fd7dc is in the EEPROM mirror, so it takes _cal. "
                "Time-shared window: xref_addr.py shows 2 reads, both in cm848_calculateWastegateDutyRequest, nothing below 0x7F60; the "
                "byte scan of ROM 0x0-0x7f60 finds none either. Earlier name: throttle_rate_integrator_reset_flag."},

    # ---------------- 8041 injector driver reference levels (MIOS PWM submodules 16-19)
    {'address': '0x004090ac', 'verdict': 'rename',
     'new': 'injector_driver_booster_voltage_level',
     'evidence': "e2m 8041 +C HPCR_UCBOOS_Voltage (VOLT, 0.00402344, max 102.85 = 25600 counts = 100 % duty): cm848_tpuMiosOutput_loadCalibration "
                 "passes it to cm848_miosPwm16SetDuty (1/256 % per count) beside the other e2m 8041 injector driver values (pull-in / decay / "
                 "delay / recharge durations), so the PWM 16 duty is the booster voltage control level (dump 8003 = 31 % = 32.2 V); the old "
                 "name ended in _ref (banned abbreviation)",
     'code_quote': "cm848_tpuMiosOutput_loadCalibration: cm848_miosPwm16SetDuty(mios_pwm16_duty_ref);",
     'comment': "e2m 8041 +C HPCR_UCBOOS_Voltage 'Voltage level for booter voltage' (VOLT, 0.00402344 V per count, 1..102.85; 8003 = 32.2 V in "
                "the dump): the injector driver's booster voltage level, produced as the duty of MIOS PWM submodule 16 (1/256 % per count, "
                "25600 = 100 % = 103 V, the record maximum is 102.85; the period is e2m 8041 +A HPCR_UCBOOS_Period 'Period duration for booter "
                "voltage control PWM signal', 0x4090aa). Passed to cm848_miosPwm16SetDuty by cm848_tpuMiosOutput_loadCalibration / "
                "cm848_tpu_interrupt_flag_init; no direct store found (displacement scan). Earlier name: mios_timer16_scale_percent_ref."},

    {'address': '0x004090b0', 'verdict': 'rename',
     'new': 'injector_driver_recharge_voltage_level',
     'evidence': "e2m 8041 +10 HPCR_URCHG_Voltage (VOLT, 0.004023442, max 102.84 = 25600 counts = 100 % duty): cm848_tpuMiosOutput_loadCalibration "
                 "passes it to cm848_miosPwm17SetDuty (1/256 % per count) beside the other e2m 8041 injector driver values, so the PWM 17 duty is "
                 "the recharge voltage control level (dump 19923 = 78 % = 80.2 V); the old name ended in _ref (banned abbreviation)",
     'code_quote': "cm848_tpuMiosOutput_loadCalibration: cm848_miosPwm17SetDuty(mios_pwm17_duty_ref);",
     'comment': "e2m 8041 +10 HPCR_URCHG_Voltage 'Voltage level for recharge voltage' (VOLT, 0.004023442 V per count, 0..102.84; 19923 = 80.2 V "
                "in the dump): the injector driver's recharge voltage level, produced as the duty of MIOS PWM submodule 17 (1/256 % per count, "
                "25600 = 100 % = 103 V, the record maximum is 102.84; the period is e2m 8041 +E HPCR_URCHG_Period, 0x4090ae). Passed to "
                "cm848_miosPwm17SetDuty by cm848_tpuMiosOutput_loadCalibration / cm848_tpu_interrupt_flag_init; no direct store found "
                "(displacement scan). Earlier name: mios_timer17_scale_percent_ref."},

    {'address': '0x004090b4', 'verdict': 'rename',
     'new': 'injector_driver_hold_current_level',
     'evidence': "e2m 8041 +14 HPCR_ISOLLH_Current (AMP, 0.00214844, max 54.99 = 25600 counts = 100 % duty): cm848_tpuMiosOutput_loadCalibration "
                 "passes it to cm848_miosPwm18SetDuty (1/256 % per count) beside the other e2m 8041 injector driver values, so the PWM 18 duty is "
                 "the injector hold current control level (dump 6284 = 25 % = 13.5 A); the old name ended in _ref (banned abbreviation)",
     'code_quote': "cm848_tpuMiosOutput_loadCalibration: cm848_miosPwm18SetDuty(mios_pwm18_duty_ref);",
     'comment': "e2m 8041 +14 HPCR_ISOLLH_Current 'Injector Hold Current Level' (AMP, 0.00214844 A per count, 0..54.99; 6284 = 13.5 A in the "
                "dump): the injector driver's hold current level, produced as the duty of MIOS PWM submodule 18 (1/256 % per count, 25600 = "
                "100 % = 55 A, the record maximum is 54.99; the period is e2m 8041 +18 HPCR_ISOLLH_Period, 0x4090b8). Passed to "
                "cm848_miosPwm18SetDuty by cm848_tpuMiosOutput_loadCalibration / cm848_tpu_interrupt_flag_init; no direct store found "
                "(displacement scan). Earlier name: mios_timer18_scale_percent_ref."},

    {'address': '0x004090b6', 'verdict': 'rename',
     'new': 'injector_driver_pull_in_current_level',
     'evidence': "e2m 8041 +16 HPCR_ISOLLA_Current (AMP, 0.00214844, max 54.99 = 25600 counts = 100 % duty): cm848_tpuMiosOutput_loadCalibration "
                 "passes it to cm848_miosPwm19SetDuty (1/256 % per count) beside the other e2m 8041 injector driver values, so the PWM 19 duty is "
                 "the injector pull-in current control level (dump 8611 = 34 % = 18.5 A); the old name ended in _ref (banned abbreviation)",
     'code_quote': "cm848_tpuMiosOutput_loadCalibration: cm848_miosPwm19SetDuty(mios_pwm19_duty_ref);",
     'comment': "e2m 8041 +16 HPCR_ISOLLA_Current 'Injector Pullin Current Level' (AMP, 0.00214844 A per count, 0..54.99; 8611 = 18.5 A in the "
                "dump): the injector driver's pull-in current level, produced as the duty of MIOS PWM submodule 19 (1/256 % per count, 25600 = "
                "100 % = 55 A, the record maximum is 54.99; the period is e2m 8041 +1A HPCR_ISOLLA_Period, 0x4090ba). Passed to "
                "cm848_miosPwm19SetDuty by cm848_tpuMiosOutput_loadCalibration / cm848_tpu_interrupt_flag_init; no direct store found "
                "(displacement scan). Earlier name: mios_timer19_scale_percent_ref."},

    # ---------------- 81AA all speed governor equivalent throttle
    {'address': '0x0040b812', 'verdict': 'rename',
     'new': 'all_speed_governor_equivalent_throttle',
     'evidence': "e2m 81AA +0 ASG_Equivalent_Throttle (%THROTTLE, 0.25 % per count, 0..100): written by cm848_calculateFuelDemandWithConditions "
                 "from the all speed governor / cruise / power take-off terms (equivalent_throttle_* and all_speed_governor_* words) and clamped "
                 "to 400 = 100 %; the EEC2 builder sends it x 0.625 as the accelerator pedal position (400 x 0.625 = 250 = 100 % at 0.4 % per bit); "
                 "the old name said fuel demand governor output",
     'code_quote': "cm848_calculateFuelDemandWithConditions: fuel_demand_governor_output = (word)uVar8;",
     'comment': "e2m 81AA +0 ASG_Equivalent_Throttle 'ASG Equivalent Throttle' (%THROTTLE, 0.25 % per count, 0..100: 400 = 100 %; 0 in the "
                "engine-off dump): the throttle position that the all speed governor's demand is equivalent to. "
                "cm848_calculateFuelDemandWithConditions (the all speed governor / cruise / power take-off equivalent throttle calculation, "
                "clamped to 400) writes it; it equals fuel_demand_control_t.calculated while governor_fuel_feature_flags mask 0x4 is clear. "
                "Readers: cm848_buildPgn61443ElectronicEngineController2Message sends it x 0.625 (0xFF in J1939-pedal mode) as the EEC2 "
                "accelerator pedal position and compares it with the kickdown threshold; cm848_controlCruiseVacuumServo takes it as its feed "
                "forward; cm848_checkFuelPressureSensorPlausibilityByFuelDemand requires it to be at or below "
                "fuel_pressure_sensor_plausibility_maximum_governor_output."},

    # ---------------- 8C69 net torque fueling limit table output
    {'address': '0x0040b53e', 'verdict': 'rename',
     'new': 'net_torque_fuel_limit_table_output',
     'evidence': "e2m 8C69 +2 Net_Torque_Fueling_Table_Limit (MM3S, 0.0679, 'net torque fueling limit output from the net torque fueling limit "
                 "table'): cm848_calculateNetTorqueFuelLimit stores the cm848_interpolateAlphaChiValue blend of the three fuel_demand_table_base_cal "
                 "engine speed lookups here, then adds the air conditioning clutch / radiator fan friction fuel and clamps it into net_torque_fuel_limit "
                 "(e2m 8C69 +0); dump 1672 = 113.6 mm3; the old name said governor integral accumulator",
     'code_quote': "cm848_calculateNetTorqueFuelLimit: uVar2 = (uint)governor_integral_accumulator +",
     'comment': "e2m 8C69 +2 Net_Torque_Fueling_Table_Limit 'Net Torque fueling limit output from the Net Torque Fueling Limit Table' (MM3S, "
                "0.0679 mm3 per count; 1672 = 113.6 mm3 in the dump): the table value of the net torque fuel limit. "
                "cm848_calculateNetTorqueFuelLimit stores here the cm848_interpolateAlphaChiValue blend of the base / chi lower map / chi upper "
                "map engine speed lookups of fuel_demand_table_base_cal, then adds friction_fuel_adjustment_for_air_conditioning_clutch and "
                "friction_fuel_adjustment_for_radiator_fan (and fuel_demand_offset_correction while fuel_feature_control_flags bit 0x100 is set), "
                "clamps the sum to 0..5888 and rate limits it into net_torque_fuel_limit (e2m 8C69 +0 Net_Torque_Fueling_Limit). xref: word (1 write, "
                "sth)."},
]
