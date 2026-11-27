from helpers import keep, rename

ENTRIES = [
    # ---- block 1760 (TPE compressor outlet temperature default) ---------------------------------------------
    rename(
        "0x004065c4", "fuel_flow_rate_default_cal", "compressor_outlet_temperature_default",
        "e2m 1760 +2 C_TPE_COT_Global_Default 'Default value for compressor outlet temperature.': "
        "cm848_selectCompressorOutletTemperature (the only reader) copies it into compressor_outlet_temperature, with source 2 "
        "(DEFAULT, e2m 175F +A), when the estimation is off (bit 0x80 of feature_enable_flags_cal clear) or both source "
        "states are defaults; the fuel flow rate family was the compressor outlet temperature chain; _cal is wrong outside "
        "the EEPROM mirror; unit: 1/32 F per count as the e2m says - cm848_estimateCompressorOutletTemperature outputs 1/32 F "
        "(the 1/2048 table ratio x the 1/64 F Rankine ambient >> 12; its floor 0xc680 = -460 x 32), so 3200 = 100 F",
        "cm848_selectCompressorOutletTemperature: compressor_outlet_temperature = fuel_flow_rate_default_cal;",
        "e2m 1760 +2 C_TPE_COT_Global_Default 'Default value for compressor outlet temperature.' (DEG_F, 1/32 F per "
        "count, 0-2045; 3200 in the dump = 100 F; the estimate cm848_estimateCompressorOutletTemperature produces is in "
        "the same 1/32 F: its 1/2048 table ratio x the 1/64 F Rankine ambient >> 12, floor 0xc680 = -460 x 32): "
        "read-only; the calibrated default compressor outlet temperature. cm848_selectCompressorOutletTemperature stores it "
        "in compressor_outlet_temperature, with compressor_outlet_temperature_source 2 (DEFAULT), when the estimation is off "
        "(bit 0x80 of feature_enable_flags_cal clear) or the compressor inlet pressure and ambient temperature sources are both "
        "defaults; otherwise cm848_estimateCompressorOutletTemperature gives the value"),
    # ---- block 805E: the packed wakeup record (odd addresses are its natural layout) --------------------------------
    keep(
        "0x0040b87d", "auxiliary_injection_start_angle",
        "e2m 805E +11 HPCR_Stored_Aux_Begin_Angle 'Aux begin angle stored at static wakeup'"),
    # ---- block 806B: fuel metering (CP3) read-back retest ---------------------------------------------------------
    keep(
        "0x00409550", "fuel_metering_retest_off_passes",
        "e2m 806B +0 CP3_Driver_Inhibit_Off_Time 'CP3 duty cycle off cycle time when open or short circuit'"),
    keep(
        "0x00409552", "fuel_metering_retest_fault_confirm_passes",
        "e2m 806B +2 CP3_Driver_Inhibit_Timer_Offset 'CP3 duty cycle off cycle time when open or short circuit'"),
]
