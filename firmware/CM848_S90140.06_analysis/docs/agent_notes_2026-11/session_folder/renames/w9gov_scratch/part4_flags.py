ROWS = []

ROWS.append({
    "kind": "global", "address": "0x003fbd52", "old": "fuel_demand_active_sensor_valid_bits", "verdict": "confirmed",
    "new": "egr_system_failure_validation_bit",
    "evidence": (
        "Bit 0x100 of the sensor validation word. CODE: cm848_updateSensorValidationFlags (0x509a7c) stores 0x100 when egr_system_failure_flag is "
        "nonzero, else 0, and ORs it into fuel_demand_sensor_validation_flags (only while governor_feature_config_flags mask 0x40 is set; EEPROM "
        "0x144 = 8 here, so the validation word is 0); from there it becomes mask 0x100 of combustion_status_flags (an EGR-off request). The old name "
        "claimed 'valid bits' of a fuel demand state that does not exist. Time-shared window: rename only, no type change."),
})

ROWS.append({
    "kind": "note",
    "text": (
        "COMBUSTION STATUS BITS (lead 4), what the code settles now. Producers: fuel_modeStatusFlags_update (0x50530c; word = calibration DAT_00406568 "
        "when DAT_003fd7ea (EEPROM 0x368) is nonzero, else the OR below | DAT_0040656a), cm848_updateSensorValidationFlags (0x509a7c), "
        "fuel_modeStatusBits_pack (0x505260, the word before it). 0x04 = DAT_0040a43e != 0 -> DAT_003fbd58 = 4; 0x08 = DAT_0040a43c != 0 -> "
        "DAT_003fbd56 = 8; BOTH SOURCE WORDS HAVE NO WRITER in either bank (xref: 0 stores), so these two bits are structurally 0; mask 0x04 has no "
        "reader at all, mask 0x08 selects the fixed protection chi (source 14). 0x10 = DAT_003fbd54 | DAT_003fbd50, only cleared by "
        "cm848_initFlowControlStateVariables and never set (their bit values are unknowable, no store of a nonzero constant exists): the bit is "
        "unreachable in code; mask 0x10 selects source 14. 0x100 = egr_system_failure_flag != 0 (SETTLED: the producer is the renamed "
        "egr_system_failure_validation_bit, an EGR-off request). 0x200: no producer except the two calibration words; selects source 14. 0x400 and above: "
        "calibration words only, both 0x400 in the dump (and EEPROM-independent: DAT_00406568 / DAT_0040656a are ROM words), never tested. The whole "
        "validation word (0x40a8a9) is gated by governor_feature_config_flags mask 0x40 (0 here), so on this truck bits 0x04 / 0x08 / 0x10 / 0x100 "
        "cannot occur whatever the producers do. SO THE LEFTOVER BITS ARE NOT 'UNSETTLED': 0x04 / 0x08 / 0x10 / 0x200 are spare hooks with no code "
        "producer (the e2m has no parameter for them either), 0x400+ is a calibration-only bit with no consumer. Do not name the bits. IDENTITY "
        "(medium confidence, e2m by relative offset only): the packed word before it, DAT_0040a5ec (fuel_modeStatusBits_pack: blend mode active, cold "
        "start boost override, condensation protection active, timing temperature check, phase 3 count met, phase 2.6, sensor validation, "
        "DAT_003fba36 in bits 0-7) is e2m EMM_AECD_State (0x0119B500, 'EMM AECD state') and combustion_status_flags 0x40a5ee is the next word, e2m "
        "EMM_Protection_State (0x0119B502, 'EMM protection state'; EMM = the emission management block with EMM_Cap_EL_Cmd 'Emission level cap after "
        "AECDs'); the e2m description of CBR_Protection_Chi_Flag 'EMM_Protection_State bit is set; protection chi chosen over base' is exactly "
        "what masks 0x08 / 0x10 / 0x200 do in cm848_selectChiAndAlpha. A rename to an emission management protection state name is possible but "
        "EMM is not spelled out in the e2m, so none is proposed. EXACT REPLACEMENT ROW (global_variables.csv 0x0040a5ee): "
        "0x0040a5ee,combustion_status_flags,word,CODE: written by fuel_modeStatusFlags_update (the calibration word DAT_00406568 when DAT_003fd7ea "
        "(EEPROM 0x368) is nonzero, else the OR of the sensor validation word / the temperature component check flags / the cold start bits / "
        "DAT_0040656a) and cleared by cm848_initialization_step_7; sole reader cm848_selectChiAndAlpha (masks 1 / 2 / 8 / 0x10 / 0x20 / 0x40 / 0x80 / "
        "0x100 / 0x200). Bits: 0x01 cold start phase 2.6 fuel mode (EGR off); 0x02 outside cold start phases 2.6 and 3 (EGR off; why EGR is "
        "requested off on this truck); 0x04 sensor validation input DAT_0040a43e (no writer; no reader of the bit); 0x08 DAT_0040a43c (no writer; "
        "selects the fixed protection chi, source 14); 0x10 no code producer (selects source 14); 0x20 / 0x40 intake / coolant temperature check "
        "bits of injection_timing_temperature_component_check_flags (EGR off at or below the calibrated limits); 0x80 cold start phase 3 count met "
        "or condensation protection active (EGR off); 0x100 egr_system_failure_flag through the validation word (EGR off; the word is 0 unless "
        "governor_feature_config_flags mask 0x40); 0x200 no code producer (selects source 14); 0x400 and above the calibration words only (0x400 in "
        "the dump, never tested). Follows the pack DAT_0040a5ec (e2m EMM_AECD_State) like e2m EMM_Protection_State. Dump 0x402. (was fuel_mode_status_flags)"
    ),
})
