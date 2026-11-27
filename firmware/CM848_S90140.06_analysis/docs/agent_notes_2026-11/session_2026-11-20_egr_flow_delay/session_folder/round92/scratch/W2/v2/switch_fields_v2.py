"""Batch W2: the field lists of CM550 algorithm enable words 13 / 14 (the user override enables of logical switches
0-31). Logical switch s: enable = table bit 0xd0 + s (word 13 + s / 16, bit s % 16); status byte 0x80bcce + s / 8;
user value 0x80bcd8 + s / 8; priority e2m 12A8 + s; default e2m 12FC and inversion e2m 1234 mask 1 << s."""
J1939 = {1: (6, "j1939_received_cruise_control_resume_switch"), 2: (7, "j1939_received_cruise_control_set_switch"),
         3: (5, "j1939_received_cruise_control_enable_switch"), 9: (1, "j1939_received_accelerator_interlock_switch"),
         10: (4, "j1939_received_clutch_switch"), 11: (3, "j1939_received_brake_switch"),
         13: (9, "j1939_received_engine_idle_increment_switch"),
         14: (8, "j1939_received_engine_idle_decrement_switch"),
         15: (15, "j1939_received_engine_diagnostic_test_mode_switch"),
         19: (14, "j1939_received_remote_accelerator_enable_switch"),
         20: (13, "j1939_received_remote_power_take_off_switch")}


def switch_field(s, name, records, identity, extra=None):
    """One override enable bit of logical switch s."""
    byte = s // 8
    mask_index = 2 * (byte // 2) + (1 - byte % 2)
    code = [f"mask byte [{mask_index}] bit {s % 8} over status 0x{0x80bcce + byte:x}"]
    if s in J1939:
        entry, signal = J1939[s]
        code.append(f"table bit {0xd0 + s} tested by cm550_FUN_00020890 for J1939 entry {entry} ({signal})")
    if extra:
        code.append(extra)
    parts = [records, f"logical switch {s}: {identity}", "code: " + " / ".join(code), "clear in the dumps"]
    return {"bit": s % 16, "name": name, "comment": "; ".join(parts)}


w13_fields = [
    switch_field(0, "key_switch_override_enable",
                 "no 106B record",
                 "status e2m 000E +0 DSKYSWSS 'BIT 0 OF BYTE 0 STATUS OF THE VEHICLE KEY SWITCH - DEBOUNCED' "
                 "(cm550_updateEngineState and mc68k_runPowerDownSequence read that bit as the key); named from the "
                 "code and the status record",
                 "set = the key switch state comes from user value 0x80bcd8 bit 0"),
    switch_field(1, "cruise_control_resume_switch_override_enable",
                 "DSCRRUUO S mask 0x2 'BIT 1 USER OVERRIDE ENABLE FLAG FOR THE CRUISE CONTROL( RESUME SWITCH)' / "
                 "DS01SWUO 'SWITCH 1'",
                 "status DSRUSWSS 'STATUS OF CRUISE RESUME/ACCEL SWITCH INPUT' / priority 12A8 +1 DSPZCRRU"),
    switch_field(2, "cruise_control_set_switch_override_enable",
                 "DSCRSEUO S mask 0x4 'BIT 2 USER OVERRIDE ENABLE FLAG FOR THE CRUISE CONTROL( SWITCH SET "
                 "ACTIVATION)' / DS02SWUO 'SWITCH 2'",
                 "status DSSESWSS 'STATUS OF CRUISE SET/COAST SWITCH INPUT' / priority 12A8 +2 DSPZCRSE"),
    switch_field(3, "cruise_control_on_off_switch_override_enable",
                 "DSCRONUO S mask 0x8 'BIT 3 USER OVERRIDE ENABLE FLAG FOR THE CC/PTO ON/OFF S(WITCH)' / DS03SWUO "
                 "'SWITCH 3'",
                 "the cruise control and power take-off on/off switch - status DSCRSWSS 'STATUS OF CRUISE ON SWITCH "
                 "INPUT' / priority 12A8 +3 DSPZCRON"),
    switch_field(4, "manual_fan_switch_override_enable",
                 "DSMNFNUO S mask 0x10 'BIT 4 USER OVERRIDE ENABLE FLAG FOR THE MANUAL FAN INPU(T SWITCH)' / "
                 "DSFACLUO 'USER OVERRIDE ENABLE FLAG FOR FAN CLUTCH SWITCH' / DS05SWUO 'SWITCH 5'",
                 "status DSFMSW 'STATUS OF THE MANUAL FAN INPUT SWITCH - DEBOUNCED VALUE' / priority 12A8 +4 "
                 "DSPZFMIP"),
    switch_field(5, "powertrain_protection_switch_override_enable",
                 "DSPPSWUO S mask 0x20 'USER OVERRIDE ENABLE FLAG FOR PTP SWITCHED INPUT SWITCH' (PTP = powertrain "
                 "protection: e2m group PTP_07) / DS06SWUO 'SWITCH 6'",
                 "status PTSWINSW 'DEBOUNCED VALUE OF THE PTP SWITCHED INPUT SWIT(CH)' / priority 12A8 +5 DSP2PTSW "
                 "(12A8 and 12FC also keep the older alias PTO_VALIDATE)"),
    switch_field(6, "high_speed_governor_droop_select_switch_override_enable",
                 "DSHSDPUO S mask 0x40 'USER OVERRIDE ENABLE FLAG FOR HSG DROOP SELECT SWITCH' / DS07SWUO 'SWITCH 7'",
                 "status HSDRSLSW 'DEBOUNCED VALUE FOR THE HSG DROOOP SELECT SWIT(CH)' / priority 12A8 +6 DSPZHGSW"),
    switch_field(7, "idle_switch_override_enable",
                 "DSIVSWUO S mask 0x80 'BIT 7 USER OVERRIDE ENABLE FLAG FOR THE RAW IDLE SWITCH( INPUT)' / DS08SWUO "
                 "'SWITCH 8'",
                 "status DSIVSWSS 'DEBOUNCED VALUE OF IDLE VALIDATION 1 SWITCH' / priority 12A8 +7 DSPZISSW "
                 "IDLE_SWITCH",
                 "direct tests andi #0x80 at 0x204e6 (cm550_outputControlState1Handler: the J1939 low idle switch "
                 "writes the override value) - 0x20cbe (cm550_FUN_00020c98: the J1939 accelerator pedal position "
                 "becomes the throttle override) - 0x20e5a (cm550_FUN_00020e14: the idle switch pair values) - "
                 "0x32ed4 (j1939HandlePgn61443Eec2 sends the EEC2 low idle switch as 3 while set)"),
    switch_field(8, "not_idle_switch_override_enable",
                 "DSNTIVUO S mask 0x100 'BIT 8 USER OVERRIDE ENABLE FLAG FOR THE RAW NOT IDLE SW(ITCH INPUT)' / "
                 "DS09SWUO 'SWITCH 9'",
                 "status DSIVNTSW 'DEBOUNCED VALUE OF IDLE VALIDATION 2 SWITCH' / priority 12A8 +8 DSPZNTIS "
                 "NOT_IDLE_SWITCH"),
    switch_field(9, "accelerator_interlock_switch_override_enable",
                 "DSOVAISW S mask 0x200 'WORD 13 BIT 9 OF BITS 0-15 STATUS OF OVERRIDE FLAG TO' (cut) / DS10SWUO "
                 "'SWITCH 10'",
                 "priority 12A8 +9 DSPZAISW 'PRIORITY OF CLIENT CURRENTLY OVERRIDING ACCELERATOR INTERLOCK "
                 "SWI(TCH)' / default 12FC DSGDAISW / status DSACILSS"),
    switch_field(10, "clutch_switch_override_enable",
                 "DSCHSWUO S mask 0x400 'BIT A USER OVERRIDE ENABLE FLAG FOR THE CLUTCH SWITCH' / DS11SWUO 'SWITCH "
                 "11'",
                 "status DSCHSWSS 'DEBOUNCED VALUE OF CLUTCH SWITCH INPUT' / priority 12A8 +A DSPZCHSW"),
    switch_field(11, "brake_switch_override_enable",
                 "DSBRSWUO S mask 0x800 'BIT B USER OVERRIDE ENABLE FLAG FOR THE BRAKE SWITCH' / DS12SWUO 'SWITCH "
                 "12'",
                 "status DSBRSWSS 'DEBOUNCED VALUE OF SERVICE BRAKE SWITCH INPU(T)' / priority 12A8 +B DSPZBRSW"),
    switch_field(12, "engine_brake_select_1_switch_override_enable",
                 "DSEBUO01 S mask 0x1000 'BIT C USER OVERRIDE ENABLE ENGINE BRAKE SELECT 1' / DSOVEBSW 'USER "
                 "OVERRIDE ENABLE FOR ENGINE_BRAKE_SWITCH' / DS13SWUO 'SWITCH 13'",
                 "status DSEBS1 'DEBOUNCED VALUE OF ENGINE BRAKE SELECT 1 SWITCH INPUT' / priority 12A8 +C DSPZEBS1 "
                 "(CM848 names its switch 12 from the same Engine_Brake_Select_1)"),
    switch_field(13, "idle_increment_switch_override_enable",
                 "DSICSWUO S mask 0x2000 'BIT D USER OVERRIDE ENABLE FLAG FOR THE IDLE ADJUST INC(REMENT SWITCH)' / "
                 "DS14SWUO 'SWITCH 14'",
                 "status DSICSWSS 'DEBOUNCED VALUE OF IDLE INCREMENT SWITCH INP(UT)' / priority 12A8 +D DSPZICSW",
                 "direct test andi.w #0x2000 at 0x15830 (mc68k_sampleAndDebounceDiscreteInputs: after the "
                 "increment / decrement decode from the cruise switches it takes status 0x80bccf bit 5 from "
                 "switch_9_to_16_override_values again)"),
    switch_field(14, "idle_decrement_switch_override_enable",
                 "DSDTSWUO S mask 0x4000 'BIT E USER OVERRIDE ENABLE FLAG FOR THE IDLE ADJUST DEC(REMENT SWITCH)' / "
                 "DS15SWUO 'SWITCH 15'",
                 "status DSDTSWSS 'DEBOUNCED VALUE OF IDLE DECREMENT SWITCH INP(UT)' / priority 12A8 +E DSPZDTSW",
                 "direct test andi.w #0x4000 at 0x15850 (mc68k_sampleAndDebounceDiscreteInputs: status 0x80bccf "
                 "bit 6 from switch_9_to_16_override_values after the cruise switch decode)"),
    switch_field(15, "diagnostic_test_switch_override_enable",
                 "DSTESWUO S mask 0x8000 'BIT F USER OVERRIDE ENABLE FLAG FOR THE DIAGNOSTIC TEST( AND FAULT FLASH "
                 "OUT)' / DS16SWUO 'SWITCH 16'",
                 "status DSTESWSS 'DEBOUNCED VALUE OF THE DIAGNOSTIC/TEST SWITC(H)' / priority 12A8 +F DSPZTESW"),
]

w14_fields = [
    switch_field(16, "switch_17_override_enable",
                 "DS17SWUO S mask 0x1 'BIT 0 SWITCH 17 USER OVERRIDE ENABLE FLAG' is the only record",
                 "no function name in 106B / 000E / 12A8 / 12FC / 1234 and no reader of the status bit"),
    switch_field(17, "air_conditioning_pressure_turnkey_switch_override_enable",
                 "DSAKTKUO S mask 0x2 'WORD 14 BIT 1 OF BITS 0-15 STATUS OF OVERRIDE FLAG TO' (cut) / DS18SWUO "
                 "'SWITCH 18'",
                 "default 12FC DSDFACTK 'DEFAULT/INITIALIZATION VALUE FOR THE AC PRESSURE TURNKEY SWITCH' / "
                 "priority 12A8 +11 DSPZACPT / inversion 1234 DSINACPT",
                 "the debouncer copies status 0x80bcd0 bit 1 into 0x80bcd7 bit 0 (e2m 000E +9 DSAKPRSW 'SOFTWARE "
                 "VALUE OF AIR CONDITIONER PRESSURE S(WITCH)')"),
    switch_field(18, "rear_axle_ratio_switch_override_enable",
                 "DSRARSUO S mask 0x4 'USER OVERRIDE ENABLE FLAG FOR REAR AXLE RATIO SWITCH' / DS19SWUO 'SWITCH 19'",
                 "status DSRARASW 'DEBOUNCED VALUE FOR REAR_AXLE_RATIO_SWITCH' (j1939HandlePgn65265CruiseVehicleSpeed "
                 "reads it) / priority 12A8 +12 DSPZRARA"),
    switch_field(19, "remote_throttle_switch_override_enable",
                 "DSRMTHUO S mask 0x8 'BIT 3 USER OVERRIDE ENABLE FLAG FOR THE REMOTE THROTTLE( SWITCH)' / DS20SWUO "
                 "'SWITCH 20'",
                 "status RMTHSW 'DEBOUNCED VALUE OF REMOTE THROTTLE SWITCH INPU(T)' / priority 12A8 +13 DSPZRTSW",
                 "direct test andi.l #0x8 at 0x207d0 (cm550_FUN_00020784: with word 18 bit 12 it lets the J1939 "
                 "remote accelerator pedal position into analog_sensor_override_values[11])"),
    switch_field(20, "remote_power_take_off_switch_override_enable",
                 "DSRXSWUO S mask 0x10 'BIT 4 USER OVERRIDE ENABLE FLAG FOR THE REMOTE PTO SWIT(CH)' / DS21SWUO "
                 "'SWITCH 21'",
                 "status DSRXSWSS 'DEBOUNCED VALUE OF REMOTE PTO SWITCH INPUT' / priority 12A8 +14 DSPZRXSW"),
    switch_field(21, "coolant_level_low_switch_override_enable",
                 "DSCLLOUO S mask 0x20 'USER OVERRIDE ENABLE FLAG FOR COOLANT LEVEL LOW SWITCH' / DS22SWUO 'SWITCH "
                 "22'",
                 "status DSCLLOSW 'STATUS OF THE SWITCH (COOLANT LEVEL LOW)' (the debouncer's coolant level switch "
                 "pair check reads it) / priority 12A8 +15 DSPZCLLO"),
    switch_field(22, "user_datalogger_switch_override_enable",
                 "DSUSDLUO and DSORUDSW S mask 0x40 'USER OVERRIDE ENABLE FLAG FOR USER DATALOGGER SWITCH' / "
                 "DS26SWUO 'BIT 6 SWITCH 26'",
                 "status DSILSSSW 'STATUS OF THE DEBOUNCED SWITCH USER_DATALOGGER_SWITCH' "
                 "(cm550_updateDataloggerTriggers reads it) / priority 12A8 +16 DSPZININ (12A8 and 12FC also keep "
                 "the alias PTO1)"),
    switch_field(23, "parking_brake_switch_override_enable",
                 "DSPRBRUO S mask 0x80 (its text 'USER OVERRIDE ENABLE FLAG MANUAL FAN INPUT SWITCH' is the manual "
                 "fan record's - the mnemonic says parking brake) / DS24SWUO 'BIT 7 SWITCH 24'",
                 "value 000E +C DSPRBRUC 'USER VALUE OF THE PARKING BRAKE SWITCH' / priority 12A8 +17 DSPZPRBR "
                 "'PARKING_BRAKE_SW(ITCH)' / inversion 1234 DSPRBRIV - no reader of the status bit"),
    switch_field(24, "coolant_level_high_switch_override_enable",
                 "DSCLHIUO S mask 0x100 'USER OVERRIDE ENABLE FLAG FOR COOLANT LEVEL HIGH SWITCH' / DS25SWUO 'BIT 8 "
                 "SWITCH 25'",
                 "status DSCLHISW 'STATUS OF THE SWITCH (COOLANT LEVEL HIGH)' (the coolant level switch pair check "
                 "reads it) / priority 12A8 +18 DSPZCLHI"),
    switch_field(25, "switched_throttle_control_or_all_speed_governor_droop_switch_override_enable",
                 "DSSTCNUO S mask 0x200 'USER OVERRIDE ENABLE FLAG FOR STCG ASG DROOP SWITCH' (STCG = switched "
                 "throttle control governor per STCGASDS - ASG = all speed governor) / DS04SWUO 'BIT 9 SWITCH 4'",
                 "status SLTHCNSW 'DEBOUNCED VALUE OF THE STCG ASG DROOP SWITCH' "
                 "(cm550_acceleratorThrottleFaultDetector and cm550_FUN_0000d4ae read it with word 27 bit 3) / "
                 "priority 12A8 +19 DSPZSTCN"),
    switch_field(26, "switch_27_override_enable",
                 "DS27SWUO S mask 0x400 'BIT A SWITCH 27 USER OVERRIDE ENABLE FLAG' is the only 106B record",
                 "guess an air conditioning pressure switch (12A8 +1A DSPZAKPR 'AIR CONDITIONER' / 12FC DSDFAKPR "
                 "'AIR_CONDITIONER_PRESSURE_SWITC(H)' / 1234 DSINACHP 'AC HIGH PRESSURE SWIT(CH)') - but this ROM "
                 "keeps the air conditioning pressure switch at logical switch 72 (J1939 entry 0) and nothing reads "
                 "the status bit"),
    switch_field(27, "switch_28_override_enable",
                 "DS28SWUO S mask 0x800 'BIT B SWITCH 28 USER OVERRIDE ENABLE FLAG' plus two function records that "
                 "disagree: DSAKHIUO 'WORD 14 BIT 11 OF BITS 0-15 STATUS OF OVERRIDE FLAG T' (cut - the AC high "
                 "pressure switch: 12A8 +1B DSPZACHP / 12FC DSDFACHP) and DSTHILUO 'USER OVERRIDE ENABLE FLAG FOR "
                 "THE ACCELERATOR INTERLOCK' (the throttle interlock: DSTHILSS / DSPZTHIL / DSDFTHIL)",
                 "undecided - this ROM routes the J1939 accelerator interlock to logical switch 9 (word 13 bit 9) "
                 "so the interlock alias looks stale and nothing reads the status bit"),
    switch_field(28, "switch_23_override_enable",
                 "DS23SWUO S mask 0x1000 'BIT C SWITCH 23 USER OVERRIDE ENABLE FLAG' is the only 106B record",
                 "guess engine brake select 2 (12FC DSDFEBS2 'DEFAULT/INITIALIZATION VALUE FOR "
                 "ENGINE_BRAKE_SELECT_2' / 12A8 +1C DSPZEBS2) - no reader of the status bit"),
    switch_field(29, "air_conditioning_cycle_switch_override_enable",
                 "DSAKCYUO S mask 0x2000 'WORD 14 BIT 13 OF BITS 0-15 STATUS OF OVERRIDE FLAG T' (cut) / DS29SWUO "
                 "'SWITCH 29'",
                 "default 12FC DSDFACCY 'DEFAULT/INITIALIZATION VALUE FOR THE AC CYCLE SWITCH' / inversion 1234 "
                 "DSACCYIV / priority 12A8 +1D DSPZACCY (12A8 and 12FC also keep the alias PTO2) - no reader of the "
                 "status bit"),
    switch_field(30, "air_conditioning_on_off_switch_override_enable",
                 "DSAKONUO S mask 0x4000 (its text 'BIT 6 OF 0-7 STATUS OF THE SWITCH' is the status record's) / "
                 "DS30SWUO 'SWITCH 30'",
                 "value 000E +D DSAKONUC 'USER SUPPLIED VALUE FOR AC_ON_OFF_SWITCH' / priority 12A8 +1E DSPZACOO "
                 "'AC ON OFF SWITCH' / default 12FC DSDFACOO - no reader of the status bit"),
    switch_field(31, "switch_31_override_enable",
                 "DS31SWUO S mask 0x8000 'BIT F SWITCH 31 USER OVERRIDE ENABLE FLAG' is the only record",
                 "no function name in 106B / 000E / 12A8 / 12FC / 1234 and no reader of the status bit"),
]
