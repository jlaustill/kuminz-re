"""Build and check the batch W2 result (CM550 algorithm enable words 7 8 9 11 12 13 14) as JSON.
usage: build_result.py <out.json>"""
import json
import re
import sys

DUMP = "J90350.00.ram.bin = J90350.00.eeprom.bin"


def channel_word(channels, first_bit):
    """Four channels x (fueling limiting / rpm limiting / shutdown / restart prevention) -> 16 fields."""
    kinds = (("fueling_limiting_enable", "FL", "fuel limit loop cm550_FUN_00019702 (k 0)"),
             ("rpm_limiting_enable", "RP", "speed limit loop cm550_calculateFaultDerateEngineSpeedLimit (k 1)"),
             ("shutdown_enable", "SO", "shutdown loop processDiagnosticLimitStatus (k 2) and the restart checks"),
             ("restart_prevention_enable", "RY",
              "restart checks cm550_diagnosticProtectionEvaluator / cm550_protectionState1DiagnosticValidator (k 3)"))
    fields = []
    for c, (prefix, mnemonic, text, n) in enumerate(channels):
        for k, (suffix, code, reader) in enumerate(kinds):
            bit = 4 * c + k
            fields.append((bit, f"{prefix}_{suffix}", f"{text[k]}; e2m {mnemonic}{code}EN; read as table bit "
                                                     f"{first_bit + bit} = 0x70 + 4 x {n} + {k} of channel {n} by the "
                                                     f"{reader}"))
    return fields


W7_CHANNELS = (
    ("coolant_level", "EPCV", ("BIT 0 OF 0-15 ENABLE PARAMETER FOR FUEL LIMITING DUE TO COOLANT LEVEL",
                               "BIT 1 OF 0-15 ENABLE PARAMETER FOR RPM LIMITING DUE TO COOLANT LEVEL",
                               "BIT 2 OF 0-15 ENABLE SHUTDOWN ON COOLANT LEVEL ERRORS",
                               "B3 PREVENTS RESTART AT POWERUP WHEN SHUTDN CNT > MAX SHUTDN CNT (CM848 e2m "
                               "Coolant_Level_Restart_Enable 0x8)"), 0),
    ("coolant_temperature", "EPCQ", ("BIT 4 OF 0-15 ENABLE PARAMETER FOR FUEL LIMITING DUE TO COOLANT TEMPERATURE",
                                     "BIT 5 OF 5-15 EPF COOLANT TEMPERATURE RPM LIMITING ENABLE",
                                     "BIT 6 OF 0-15 ENABLE SHUTDOWN ON COOLANT TEMPERATURE ERRORS",
                                     "BIT 7 OF 0-15 PREVENTS RESTART AT POWERUP WHEN SHUTDN CNT > MAX"), 1),
    ("intake_manifold_temperature", "EPIM", ("BIT 8 OF 0-15 ENABLE FOR TVO (fueling) LIMITING DUE TO INTAKE MANIFOLD "
                                             "TEMP",
                                             "BIT 9 OF 0-15 ENABLE PARAMETER FOR RPM LIMITING DUE TO IMT",
                                             "BIT 10 OF 0-15 ENABLE SHUTDOWN ON INTAKE MANIFOLD TEMPERATURE ERRORS",
                                             "BIT 11 OF 0-15 PREVENTS RESTART AT POWERUP WHEN SHUTDN CNT > MAX"), 2),
    ("oil_pressure", "EPO2", ("BIT 12 OF 0-15 ENABLE PARAMETER FOR FUEL LIMITING DUE TO OIL PRESSURE; also tested "
                              "directly by cm550_FUN_00019702 at 0x1983e (andi.w #0x1000) to run the oil pressure "
                              "power-up inhibit timer",
                              "BIT 13 OF 0-15 EPF OIL PRESSURE FAULT ENABLE PARAMETER (CM848 e2m "
                              "Oil_Pressure_RPM_Limiting_Enable 0x2000)",
                              "BIT 14 OF 0-15 ENABLE SHUTDOWN ON OIL PRESSURE ERRORS",
                              "BIT 15 OF 0-15 PREVENTS RESTART AT POWERUP WHEN SHUTDN CNT > MAX"), 3),
)

W8_CHANNELS = (
    ("water_in_fuel", "EPWF", ("S record mask 0x01 ENABLE PARAMETER FOR FAULT (fuel) LIMITING DUE TO WATER IN FUEL",
                               "S record mask 0x02 ENABLE PARAMETER FOR FAULT RPM LIMITING DUE TO WATER IN FUEL",
                               "S record mask 0x04 ENABLE SHUTDOWN ON WATER IN FUEL ERRORS",
                               "S record mask 0x08 PREVENTS RESTRT AT PWR UP WHEN SHUTDN CNT>MAX"), 4),
    ("boost_pressure", "EPBS", ("S record mask 0x10 (its text says ENG SYNC - copied from EPFPFLEN; the mnemonic and "
                                "the three sibling records say boost)",
                                "S record mask 0x20 ENABLE PARAMETER FOR FAULT RPM LIMITING DUE TO BOOST",
                                "S record mask 0x40 ENABLE SHUTDOWN ON BOOST PRESSURE ERRORS",
                                "S record mask 0x80 PREVENTS RESTRT AT PWR UP WHEN SHUTDN CNT>MAX"), 5),
    ("engine_sync_fuel_pressure", "EPFP", ("S record mask 0x100 ENABLE PARAMETER FOR FAULT LIMITING DUE TO ENG SYNC "
                                           "(fuel pressure)",
                                           "S record mask 0x200 ENABLE PARAMETER FOR FAULT RPM LIMITING DUE TO ENG "
                                           "(sync fuel pressure)",
                                           "S record mask 0x400 ENABLE SHUTDOWN ON ENGINE SYNC FUEL PRESSURE ERRORS",
                                           "S record mask 0x800 PREVENTS RESTRT AT PWR UP WHEN SHUTDN CNT>MAX"), 6),
    ("fuel_temperature", "EPFT", ("BIT 12 OF 0-15 ENABLES FUEL LIMITING DUE TO FUEL TEMPERATURE; also tested directly "
                                  "by vp44_FUN_0001cad6 at 0x1caec (andi.l #0x1000): with bit 13 and the engine "
                                  "protection enable (word 2 bit 4) it computes vp44_fuel_temperature_value",
                                  "BIT 13 OF 0-15 ENABLES RPM LIMITING DUE TO FUEL TEMPERATURE; also tested directly "
                                  "by vp44_FUN_0001cad6 at 0x1cafa (andi.l #0x2000)",
                                  "BIT 14 OF 0-14 ENABLES SHUTDOWN ON FUEL TEMPERATURE",
                                  "BIT 15 OF 0-15 PREVENTS RESTART AT POWERUP WHEN SHUTDN CNT > MAX"), 7),
)

w7 = channel_word(W7_CHANNELS, 112)
w8 = channel_word(W8_CHANNELS, 128)

w9 = channel_word((("ambient_air_pressure", "EPAA", ("S record mask 0x01 ENABLE PARAMETER FOR FAULT (fuel) LIMITING "
                                                     "DUE TO AMBIENT AIR PRESSURE",
                                                     "S record mask 0x02 ENABLE PARAMETER FOR FAULT RPM LIMITING DUE "
                                                     "TO AMBIENT AIR PRESSURE",
                                                     "S record mask 0x04 ENABLE SHUTDOWN ON AMBIENT AIR PRESSURE ERRORS",
                                                     "S record mask 0x08 PREVENTS RESTRT AT PWR UP WHEN SHUTDN "
                                                     "CNT>MAX"), 8),), 144)
for bit in range(4, 16):
    w9.append((bit, f"reserved_bit_{bit}",
               f"no e2m record (mask 0x{1 << bit:x}); no reader: the protection loops run 9 channels "
               f"(engine_protection_config_table_base to load_breakpoint_table in 36-byte steps) so table bit "
               f"{144 + bit} is never reached; clear in the dump (guess: a channel slot this calibration does not "
               f"have)"))

w11 = [
    (0, "proprietary_communication_enable",
     "datalink protocol enable for the proprietary J1708 messages; e2m JCJPEA (N record with no bit in its text: "
     "PARAMETER INDICATING WHETHER DATALINK PROTOCOLS ARE TURNED ON; CM848's labelled copy "
     "Proprietary_Communication_Enable has mask 0x1); the bit comes from the code: mc68k_dispatchJ1708ReceivedMessages "
     "at 0x15fe8 (andi.w #1) handles message IDs below 8 (3 security key and development commands / 4 control "
     "commands / 5 memory read and write and multipacket / 6 abort) only while set; set in the dump (0x000b)"),
    (1, "j1587_communication_enable",
     "e2m JC87CZEA BIT 1 OF 0-15 INDICATES WHETHER J1587 COMMUNICATION IS ENABLED; "
     "cm550_diagnosticMessageTransmissionManager at 0xebe0 (andi.w #2: the parameter broadcast through "
     "vp44_insiteParameterTableIterator) and mc68k_dispatchJ1708ReceivedMessages at 0x16396 (andi.w #2: message IDs "
     "0x80 and up); set in the dump"),
    (2, "j1922_communication_enable",
     "e2m JC22CZEA BIT 2 OF 0-15 INDICATES WHETHER J1922 COMMUNICATION IS ENABLED; "
     "cm550_diagnosticMessageTransmissionManager at 0xebac (andi.w #4: the message 45 and 53 builders) and "
     "mc68k_dispatchJ1708ReceivedMessages at 0x163be (andi.w #4: message IDs 0x45-0x56); clear in the dump"),
    (3, "j1939_communication_enable",
     "e2m JC39CZEA BIT 3 OF 0-15 INDICATES WHETHER J1939 COMMUNICATION IS ENABLED; "
     "cm550_engineRunTimeHistogramAccumulator at 0x1ff4e (andi.w #8: it runs the J1939 periodic transmit tables "
     "0x80096e and 0x800a36 - the twin of CM848 cm848_runJ1939PeriodicTransmitQueues) and mc68k_FUN_000212b2 at "
     "0x212c0 (andi.w #8: the J1939 receive dispatch through j1939_receive_handler_table - the twin of CM848 "
     "cm848_dispatchJ1939ReceivedMessages); set in the dump"),
]
for bit in range(4, 16):
    w11.append((bit, f"reserved_bit_{bit}", f"no e2m record (mask 0x{1 << bit:x}); no reader; clear in the dump"
                                            f" (0x000b)"))

w12 = [
    (0, "idle_speed_save_enable",
     "e2m LSISSVEN BIT 0 OF 0 - 15 ENABLES SAVE OF LAST IDLE SPEED AT SHUTDOWN (CM848 field of the same name); "
     "the operator idle adjust code keeps the offset in rpm_added_to_lsg_reference only while set: "
     "cm550_engineModeTimingAdjuster / vp44_rpm_derate_monitor at 0x26546 and the start-up clear in "
     "cm550_fuelDemandLimitSource2Selector / vp44_initVP44StatusFlags at 0x265a0 (andi.w #1); set in the dump"),
    (1, "overspeed_fuel_shutoff_enable",
     "e2m EPOSFSO IF T FSO CLOSES WHEN OVRSPD DETECTED BY MAIN MICRO (the CM550 text is cut before the bit; CM848's "
     "labelled copy Overspeed_FSO_Override has mask 0x2 and says Bit 1 of 0 - 15 of Word C); "
     "cm550_fuelDemandLimitSelector11 / vp44_canPinVp44StatusController at 0x1ca9a (andi.l #2): in "
     "ENGINE_STATE_OVERSPEED with this bit set they clear the fuel shutoff driver bit 0x20 of "
     "fuel_system_output_driver_control; set in the dump"),
    (2, "water_in_fuel_enable",
     "e2m WFAGEN BIT 2 ENABLE FLAG USED FOR WATER_IN_FUEL ALGORITHM (CM848 field of the same name); "
     "vp44FaultRegisterBit2Monitor at 0x34c3e (andi.w #4): while set a water in fuel sensor reading of 1 lights "
     "lamp bit 0x10 and sets fault word 4 bit 0x2000; clear in the dump"),
    (3, "air_fuel_control_override_enable",
     "e2m AFENMAN BIT 3 OF 0-15 IN WORD C (CM848 field of the same name); cm550_fuelTimingTransitionStateMachine at "
     "0xc19c (andi.w #8): while set the air fuel control derate takes "
     "afc_fueling_derate_value_when_afc_override_is_enabled instead of the rpm by boost table; clear in the dump"),
    (4, "electronic_smart_power_enable",
     "e2m SPAGEN 0 - DISABLE 1 - ENABLE ESP ALGORITHM BIT 4 OF 0 - 15 (CM848 field of the same name); "
     "cm550_updateElectronicSmartPowerTau runs only while set (0x1abcc andi.w #0x10); calculateAlpha (0xc3ea) and "
     "cm550_FUN_0001cc72 (0x1cd96) also read it; clear in the dump"),
    (5, "reverse_electronic_smart_power_enable",
     "e2m SPRVEN 0 - DISABLE 1 - ENABLE ESP LAUNCH APPLICATION ALGORITHM (no bit in the CM550 text; CM848's labelled "
     "copy Reverse_ESP_Enable has mask 0x20; CM848 field of the same name); cm550_updateElectronicSmartPowerTau at "
     "0x1ad52 (andi.l #0x20): while set the high horsepower mode can enter state 1; clear in the dump"),
    (6, "low_speed_governor_droop_enable",
     "e2m LSDPEN LSG DROOP ENABLE BIT 6 OF 0 - 15 IN WORD C (CM848 field of the same name); "
     "vp44State2TransitionHandler at 0xfa1c and cm550_FUN_000184c6 at 0x1850e (andi.l #0x40): while set the torque "
     "curve breakpoint 1 speed is lsg_breakpoint_speed minus a fueling x 0x80daf4 / 0xa7 droop term; clear in the "
     "dump"),
    (7, "accelerator_interlock_enable",
     "e2m ANEN BIT 7 OF 0-15 IN WORD C ACCELERATOR INTERLOCK ENABLE BIT (CM848 field of the same name); no reader "
     "in this build; set in the dump"),
    (8, "vehicle_speed_sensor_signal_loss_enable",
     "e2m VSMVEN BIT 8 WORD C ENABLES VSS SENSOR LOST WHILE MOVING (CM848 field of the same name); no reader in "
     "this build; set in the dump"),
    (9, "vehicle_speed_sensor_zero_under_load_enable",
     "e2m VSSTEN BIT 9 WORD C ENABLES VSS SENSOR LOST WHILE STOPPED (CM848 field of the same name); no reader in "
     "this build; set in the dump"),
    (10, "reserved_bit_10",
     "no e2m record in CM550 and no reader; clear in the dump (guess: CM848 has OBD_Fault_Handler_Enable DGOBFUHN "
     "here and this calibration has no such record)"),
    (11, "power_take_off_brake_override_enable",
     "e2m PTBRODEN WHEN ENABLED IT ALLOWS THE BRAKE TO CANCEL CAB PTO WORD C BIT (the CM550 text is cut before the "
     "bit; CM848's labelled copy PTO_Brake_Override_Enable has mask 0x800 Word C bit B; CM848 field of the same "
     "name); no reader in this build (e2m-only); set in the dump"),
    (12, "power_take_off_clutch_override_enable",
     "e2m PTCHODEN WHEN ENABLED IT ALLOWS THE CLUTCH TO CANCEL CAB PTO WORD C BIT (cut before the bit; CM848's "
     "labelled copy PTO_Clutch_Override_Enable has mask 0x1000 Word C bit C; CM848 field of the same name); no "
     "reader in this build (e2m-only); set in the dump"),
    (13, "oil_change_monitor_enable",
     "e2m OCEA ENABLES OIL CHANGE MONITOR FEATURE BIT 13 OF 0-15 OF WORD C (CM848 field of the same name); no "
     "reader in this build; set in the dump"),
    (14, "low_speed_governor_cold_idle_override_enable",
     "e2m LSCIIHEN ENABLE FOR OVERRIDING THE COLD IDLE ADJUST IN THE LSG (no bit in the text); cm550_FUN_00026616 "
     "at 0x26646 (andi.w #0x4000): while set and the operator has adjusted the idle (0x80db08 non-zero) the cold "
     "idle speed adder no longer raises operator_adjusted_lsg_breakpoint_speed; clear in the dump; CM848 has no "
     "record here (reserved_bit_14)"),
    (15, "engine_data_files_enable",
     "e2m EDEN BIT 15 OF 0 - 15 ENABLES/DISABLES EDF FEATURE (EDF = engine data files: e2m group 12C ENDTFL07 "
     "ENGINE DATA FILES ENABLE AND POWER-DOWNS); no reader in this build; set in the dump; CM848 has no record "
     "here (reserved_bit_15)"),
]

S13 = ("override enable of logical switch {s} (switch status byte 0x80bcce bit {b} for 0-7 / 0x80bccf bit {b} for "
       "8-15; the debouncer and mc68k_ioDriverStrobeHandler apply this mask bit bytewise through "
       "discrete_input_override_mask_ptr)")
w13 = [
    (0, "reserved_bit_0",
     "no e2m 106B record; logical switch 0 is the vehicle key switch (e2m 000E DSKYSWSS byte 0 bit 0) and the "
     "debouncer would apply this bit bytewise like the others (guess: key switch override enable); clear in the "
     "dump"),
    (1, "cruise_control_resume_switch_override_enable",
     "e2m DS01SWUO BIT 1 SWITCH 1 USER OVERRIDE ENABLE FLAG and DSCRRUUO (cruise control resume); J1939 input 6 "
     "(cruise control resume switch) tests table bit 0xd0 + 1 in cm550_FUN_00020890; 12A8 priority byte 0x80bd4b"),
    (2, "cruise_control_set_switch_override_enable",
     "e2m DS02SWUO BIT 2 SWITCH 2 and DSCRSEUO (cruise control set); J1939 input 7 (cruise control set switch) "
     "tests table bit 0xd0 + 2 in cm550_FUN_00020890"),
    (3, "cruise_control_on_off_switch_override_enable",
     "e2m DS03SWUO BIT 3 SWITCH 3 and DSCRONUO CC/PTO ON/OFF SWITCH; J1939 input 5 (cruise control enable switch) "
     "tests table bit 0xd0 + 3 in cm550_FUN_00020890"),
    (4, "manual_fan_switch_override_enable",
     "e2m DS05SWUO BIT 4 SWITCH 5 and DSMNFNUO MANUAL FAN INPUT (alias DSFACLUO FAN CLUTCH SWITCH); 000E DSFMSW "
     "manual fan input switch; applied bytewise only"),
    (5, "powertrain_protection_switch_override_enable",
     "e2m DS06SWUO BIT 5 SWITCH 6 and DSPPSWUO PTP SWITCHED INPUT SWITCH (PTP = powertrain protection: e2m group "
     "PTP_07); applied bytewise only"),
    (6, "high_speed_governor_droop_select_switch_override_enable",
     "e2m DS07SWUO BIT 6 SWITCH 7 and DSHSDPUO HSG DROOP SELECT SWITCH; applied bytewise only"),
    (7, "idle_switch_override_enable",
     "e2m DS08SWUO BIT 7 SWITCH 8 and DSIVSWUO RAW IDLE SWITCH (000E: idle validation 1 switch); direct tests "
     "(andi #0x80): cm550_outputControlState1Handler at 0x204e6 and cm550_FUN_00020e14 at 0x20e5a let the J1939 "
     "accelerator pedal low idle switch override it; cm550_FUN_00020c98 at 0x20cbe gates the J1939 accelerator "
     "pedal position override; j1939HandlePgn61443Eec2 at 0x32ed4 reports the switch as not available while set"),
    (8, "not_idle_switch_override_enable",
     "e2m DS09SWUO BIT 8 SWITCH 9 and DSNTIVUO RAW NOT IDLE SWITCH (000E: idle validation 2 switch); applied "
     "bytewise only"),
    (9, "accelerator_interlock_switch_override_enable",
     "e2m DS10SWUO BIT 9 SWITCH 10 and DSOVAISW WORD 13 BIT 9 STATUS OF OVERRIDE FLAG (000E DSACILSS); J1939 input "
     "1 (accelerator interlock switch) tests table bit 0xd0 + 9 in cm550_FUN_00020890"),
    (10, "clutch_switch_override_enable",
     "e2m DS11SWUO BIT A SWITCH 11 and DSCHSWUO CLUTCH SWITCH; J1939 input 4 (clutch switch) tests table bit "
     "0xd0 + 10 in cm550_FUN_00020890"),
    (11, "brake_switch_override_enable",
     "e2m DS12SWUO BIT B SWITCH 12 and DSBRSWUO BRAKE SWITCH; J1939 input 3 (brake switch) tests table bit "
     "0xd0 + 11 in cm550_FUN_00020890"),
    (12, "engine_brake_select_1_switch_override_enable",
     "e2m DS13SWUO BIT C SWITCH 13 and DSEBUO01 ENGINE BRAKE SELECT 1 (alias DSOVEBSW ENGINE_BRAKE_SWITCH; 000E "
     "DSEBS1); applied bytewise only"),
    (13, "idle_increment_switch_override_enable",
     "e2m DS14SWUO BIT D SWITCH 14 and DSICSWUO IDLE ADJUST INCREMENT; mc68k_sampleAndDebounceDiscreteInputs at "
     "0x15830 (andi.w #0x2000) takes bit 0x20 of switch_9_to_16_override_values into the switch 8-15 byte while "
     "set; J1939 input 9 (engine idle increment switch) tests table bit 0xd0 + 13"),
    (14, "idle_decrement_switch_override_enable",
     "e2m DS15SWUO BIT E SWITCH 15 and DSDTSWUO IDLE ADJUST DECREMENT; mc68k_sampleAndDebounceDiscreteInputs at "
     "0x15850 (andi.w #0x4000) takes bit 0x40 of switch_9_to_16_override_values while set; J1939 input 8 (engine "
     "idle decrement switch) tests table bit 0xd0 + 14"),
    (15, "diagnostic_test_switch_override_enable",
     "e2m DS16SWUO BIT F SWITCH 16 and DSTESWUO DIAGNOSTIC TEST SWITCH; J1939 input 15 (engine diagnostic test "
     "mode switch) tests table bit 0xd0 + 15 in cm550_FUN_00020890"),
]

w14 = [
    (0, "switch_17_override_enable",
     "e2m DS17SWUO BIT 0 SWITCH 17 USER OVERRIDE ENABLE FLAG (no functional record); logical switch 16; applied "
     "bytewise only"),
    (1, "air_conditioner_pressure_turnkey_switch_override_enable",
     "e2m DS18SWUO BIT 1 SWITCH 18 and DSAKTKUO WORD 14 BIT 1 STATUS OF OVERRIDE FLAG (AK = air conditioner as in "
     "DSAKONUC; 12A8 +0x11 DSPZACPT AC PRESSURE TURNKEY SWITCH); logical switch 17; applied bytewise only"),
    (2, "rear_axle_ratio_switch_override_enable",
     "e2m DS19SWUO BIT 2 SWITCH 19 and DSRARSUO REAR AXLE RATIO SWITCH; logical switch 18 (its status bit is read "
     "by j1939HandlePgn65265CruiseVehicleSpeed); applied bytewise only"),
    (3, "remote_throttle_switch_override_enable",
     "e2m DS20SWUO BIT 3 SWITCH 20 and DSRMTHUO REMOTE THROTTLE; logical switch 19; cm550_FUN_00020784 at 0x207d0 "
     "(andi.l #8) with feature_enable_flags_word bit 0x1000 lets the J1939 remote accelerator pedal position "
     "override the remote throttle; J1939 input 14 (remote accelerator enable switch) tests table bit 0xd0 + 19"),
    (4, "remote_power_take_off_switch_override_enable",
     "e2m DS21SWUO BIT 4 SWITCH 21 and DSRXSWUO REMOTE PTO SWITCH; logical switch 20; J1939 input 13 (remote power "
     "take off switch) tests table bit 0xd0 + 20 in cm550_FUN_00020890"),
    (5, "coolant_level_low_switch_override_enable",
     "e2m DS22SWUO BIT 5 SWITCH 22 and DSCLLOUO COOLANT LEVEL LOW SWITCH; logical switch 21; applied bytewise only"),
    (6, "user_datalogger_switch_override_enable",
     "e2m DS26SWUO BIT 6 SWITCH 26 and DSORUDSW / DSUSDLUO USER DATALOGGER SWITCH (12A8 alias DSPZPT01 PTO1); "
     "logical switch 22 (its status bit is read by cm550_updateDataloggerTriggers); applied bytewise only"),
    (7, "parking_brake_switch_override_enable",
     "e2m DS24SWUO BIT 7 SWITCH 24 and DSPRBRUO (its text says manual fan input switch - copied; DSPRBRUC / "
     "DSPRBRIV / 12A8 DSPZPRBR all say parking brake); logical switch 23; applied bytewise only"),
    (8, "coolant_level_high_switch_override_enable",
     "e2m DS25SWUO BIT 8 SWITCH 25 and DSCLHIUO COOLANT LEVEL HIGH SWITCH; logical switch 24; applied bytewise "
     "only"),
    (9, "switched_throttle_control_governor_droop_switch_override_enable",
     "e2m DS04SWUO BIT 9 SWITCH 4 and DSSTCNUO STCG ASG DROOP SWITCH (STCG = switched throttle control governor per "
     "STCGASDS; ASG = all speed governor); logical switch 25 (its status bit is read by "
     "cm550_acceleratorThrottleFaultDetector with STCGASDS); applied bytewise only"),
    (10, "switch_27_override_enable",
     "e2m DS27SWUO BIT A SWITCH 27 USER OVERRIDE ENABLE FLAG (no functional record); logical switch 26; applied "
     "bytewise only"),
    (11, "switch_28_override_enable",
     "e2m DS28SWUO BIT B SWITCH 28 plus two conflicting functional records: DSAKHIUO (air conditioner high pressure "
     "switch) and DSTHILUO (accelerator interlock); 000E and 12A8 carry the same two aliases; no reader tells them "
     "apart (the J1939 accelerator interlock input uses word 13 bit 9); logical switch 27; applied bytewise only"),
    (12, "switch_23_override_enable",
     "e2m DS23SWUO BIT C SWITCH 23 USER OVERRIDE ENABLE FLAG (no functional 106B record; 12A8 +0x1C DSPZEBS2 names "
     "engine brake select 2); logical switch 28; applied bytewise only"),
    (13, "air_conditioner_cycle_switch_override_enable",
     "e2m DS29SWUO BIT D SWITCH 29 and DSAKCYUO WORD 14 BIT 13 STATUS OF OVERRIDE FLAG (000E DSAKCYSW; 12A8 "
     "DSPZACCY AC CYCLE SWITCH; 12A8 alias DSPZPTO2 PTO2); logical switch 29; applied bytewise only"),
    (14, "air_conditioner_on_off_switch_override_enable",
     "e2m DS30SWUO BIT E SWITCH 30 and DSAKONUO (its text BIT 6 OF 0-7 is the status byte's; DSAKONUC USER "
     "SUPPLIED VALUE FOR AC_ON_OFF_SWITCH; 12A8 DSPZACOO); logical switch 30; applied bytewise only"),
    (15, "switch_31_override_enable",
     "e2m DS31SWUO BIT F SWITCH 31 USER OVERRIDE ENABLE FLAG (no functional record); logical switch 31; applied "
     "bytewise only"),
]

words = [
    dict(word=7, address="0x803ca2",  proposed_name="algorithm_enable_flags_7_cal",
         proposed_type="algorithm_enable_flags_7_t", shared_with_cm848=True, fields=w7,
         row_comment="Algorithm enable flags word 7 (EEPROM 0x198; e2m 106B +0x10): the engine protection channel "
                     "enables of channels 0-3 (coolant level / coolant temperature / intake manifold temperature / "
                     "oil pressure) x (fueling limiting / rpm limiting / shutdown / restart prevention). The "
                     "protection loops read table bit 0x70 + 4n + k from word 0 and cm550_FUN_00019702 tests bit 12 "
                     "directly; 0xffff in the dump. Same layout as CM848 word 7 (0x3fd5aa)",
         code_tests="direct: cm550_FUN_00019702 0x1983e move.w 0x803ca2 + andi.w #0x1000 (bit 12 oil pressure "
                    "fueling limiting: the oil pressure power-up inhibit). Indexed from word 0 (movea.l #0x803c94 + "
                    "move.w (0 a0 dN.w); bit 0x70 + 4n + k; channels 0-3 land in this word; addresses of the movea.l "
                    "#0x803c94): k 0 cm550_FUN_00019702 0x19746; k 1 cm550_calculateFaultDerateEngineSpeedLimit "
                    "0x18e50; k 2 processDiagnosticLimitStatus 0x1906e and cm550_diagnosticProtectionEvaluator 0x18b80 "
                    "and cm550_protectionState1DiagnosticValidator 0x18d2e; k 3 cm550_diagnosticProtectionEvaluator "
                    "0x18bae and cm550_protectionState1DiagnosticValidator 0x18d5a. .cpp census: 1 pure test",
         writes="none (the one absolute reference is a move.w read; the indexed accesses are move.w reads)",
         differences_from_cm848="CM848 has no algorithm_enable_flags_7_t rows today: create the type in both CSVs "
                                "(CM848's row may keep word or take it with no render change) or fall back to "
                                "cm550_algorithm_enable_flags_7_t with the same fields. The bits do not differ: CM848 "
                                "word 7 (0x3fd5aa) has the same 16 e2m records at the same masks (Coolant_Level_* / "
                                "Coolant_Temperature_* / IMT_* / Oil_Pressure_* Fueling / RPM / Shutdown / Restart). "
                                "CM848 keeps it a plain word because its protection loops start at bit 128 and it has "
                                "no direct reader. In CM550 the loops start at bit 112 (0x70) and cover the whole word"),
    dict(word=8, address="0x803ca4",  proposed_name="algorithm_enable_flags_8_cal",
         proposed_type="cm550_algorithm_enable_flags_8_t", shared_with_cm848=False, fields=w8,
         row_comment="Algorithm enable flags word 8 (EEPROM 0x19a; e2m 106B +0x12): the engine protection channel "
                     "enables of channels 4-7 (water in fuel / boost pressure / engine sync fuel pressure / fuel "
                     "temperature) x (fueling limiting / rpm limiting / shutdown / restart prevention). The "
                     "protection loops read table bit 0x70 + 4n + k from word 0 and vp44_FUN_0001cad6 tests bits 12 "
                     "and 13 directly; 0x0000 in the dump",
         code_tests="direct: vp44_FUN_0001cad6 0x1caec move.w 0x803ca4 + andi.l #0x1000 (bit 12) and 0x1cafa andi.l "
                    "#0x2000 (bit 13): fuel temperature fueling or rpm limiting enabled -> compute "
                    "vp44_fuel_temperature_value. Indexed from word 0 (bit 0x70 + 4n + k; channels 4-7): the same "
                    "five loop functions as word 7. .cpp census: 2 tests and both also flow into the returned value "
                    "(uVar1 = _DAT_00803ca4 & 0x1000)",
         writes="none",
         differences_from_cm848="different channels: CM848 word 8 bits 0-3 fuel temperature / 4-7 C_Out (compressor "
                                "outlet) temperature / 8-11 T_In (turbine inlet) temperature / 12-15 none; CM550 bits "
                                "0-3 water in fuel / 4-7 boost pressure / 8-11 engine sync fuel pressure / 12-15 fuel "
                                "temperature (fuel temperature is at 12-15 here and 0-3 in CM848). CM848 keeps it a "
                                "plain word (no direct reader)"),
    dict(word=9, address="0x803ca6",  proposed_name="algorithm_enable_flags_9_cal",
         proposed_type="word", shared_with_cm848=False, fields=w9,
         row_comment="Algorithm enable flags word 9 (EEPROM 0x19c; e2m 106B +0x14): bits 0-3 = engine protection "
                     "channel 8 (ambient air pressure) 0x1 fueling limiting EPAAFLEN / 0x2 rpm limiting EPAARPEN / "
                     "0x4 shutdown EPAASOEN / 0x8 restart prevention EPAARYEN; bits 4-15 no e2m record. Plain word: "
                     "its only readers are the protection loops (table bit 0x70 + 4 x 8 + k from word 0); 0x0000 in "
                     "the dump",
         code_tests="no absolute reference; reached only as channel 8 (table bits 144-147) of the indexed protection "
                    "loops (cm550_FUN_00019702 / cm550_calculateFaultDerateEngineSpeedLimit / "
                    "processDiagnosticLimitStatus / cm550_diagnosticProtectionEvaluator / "
                    "cm550_protectionState1DiagnosticValidator)",
         writes="none",
         differences_from_cm848="CM848 has no e2m record and no row for word 9 (0x3fd5ae); CM550's channel 8 (ambient "
                                "air pressure) is CM550-only"),
    dict(word=11, address="0x803caa", current_name="diagnostic_subsystem_enable_flags",
         proposed_name="algorithm_enable_flags_11_cal", proposed_type="algorithm_enable_flags_11_t",
         shared_with_cm848=True, fields=w11,
         row_comment="Algorithm enable flags word 11 (EEPROM 0x1a0; e2m 106B +0x18): the datalink protocol enables "
                     "0x1 proprietary (J1708 messages below 8) / 0x2 J1587 / 0x4 J1922 / 0x8 J1939 (the J1939 "
                     "transmit schedule and receive dispatch); 0x000b in the dump (proprietary + J1587 + J1939 - the "
                     "value CM848's truck has too) (was diagnostic_subsystem_enable_flags)",
         code_tests="7 reads (move.w + andi.w): 0xebac #4 and 0xebe0 #2 cm550_diagnosticMessageTransmissionManager; "
                    "0x15fe8 #1 and 0x16396 #2 and 0x163be #4 mc68k_dispatchJ1708ReceivedMessages; 0x1ff4e #8 "
                    "cm550_engineRunTimeHistogramAccumulator; 0x212c0 #8 mc68k_FUN_000212b2. .cpp census: 7 tests "
                    "and 3 CONCAT22(..word..) & 0xffff00NN value forms (4036 / 21549 / 22656) that may print as "
                    "pieces once typed",
         writes="none",
         differences_from_cm848="none: CM848 algorithm_enable_flags_11_t has the same four named bits (0 "
                                "proprietary / 1 J1587 / 2 J1922 / 3 J1939) and reserved 4-15; CM848 field names "
                                "taken verbatim"),
    dict(word=12, address="0x803cac", current_name="calibration_feature_enable_flags_word_9",
         proposed_name="algorithm_enable_flags_12_cal", proposed_type="cm550_algorithm_enable_flags_12_t",
         shared_with_cm848=False, fields=w12,
         row_comment="Algorithm enable flags word 12 (EEPROM 0x1a2; e2m 106B +0x1A whose records say WORD C): idle "
                     "speed save / overspeed fuel shutoff / water in fuel / air fuel control override / Electronic "
                     "Smart Power and its launch mode / low speed governor droop / accelerator interlock / vehicle "
                     "speed sensor monitors / power take off brake and clutch override / oil change monitor / cold "
                     "idle override / engine data files; 0xbb87 in the dump (was calibration_feature_enable_flags_"
                     "word_9: the e2m records number it word C = 12)",
         code_tests="12 absolute reads (move.w + andi; the .cpp shows 15 tests because three pairs of overlapping function entries share code): bit 0 0x26546 and 0x265a0 (each shared by two overlapping function "
                    "entries); bit 1 0x1ca9a (shared); bit 2 0x34c3e; bit 3 0xc19c; bit 4 0xc3ea 0x1abcc 0x1cd96; bit 5 0x1ad52; "
                    "bit 6 0xfa1c 0x1850e; bit 14 0x26646. .cpp census: 15 tests + 5 masked values assigned or "
                    "returned (1888 / 4956 / 18161 / 18198 / 37592) + 1 CONCAT22 form (15315)",
         writes="none",
         differences_from_cm848="bits 0 and 2-9 and 11-13 match CM848 (same mnemonics and positions; CM848 field names "
                                "reused); bit 1 EPOSFSO is reserved_bit_1 in CM848 (rename proposed); bit 10 is "
                                "OBD_Fault_Handler_Enable in CM848 but has no CM550 record; bit 14 LSCIIHEN and bit 15 "
                                "EDEN are CM550-only (CM848 reserved_bit_14 / reserved_bit_15 with no CM848 record) -> "
                                "not shareable"),
    dict(word=13, address="0x803cae", current_name="switch_override_configuration",
         proposed_name="algorithm_enable_flags_13_cal", proposed_type="cm550_algorithm_enable_flags_13_t",
         shared_with_cm848=False, fields=w13,
         row_comment="Algorithm enable flags word 13 (EEPROM 0x1a4; e2m 106B +0x1C): the user override enables of "
                     "logical switches 0-15 (bit s = switch s; the e2m SWITCH n number is not the bit). First word of "
                     "the 10-byte DSSWUO block (words 13-17) that cm550_initializeDiscreteInputs points "
                     "discrete_input_override_mask_ptr at; the debouncer and mc68k_ioDriverStrobeHandler apply its "
                     "bytes to the switch images and cm550_FUN_00020890 tests table bit 0xd0 + s for each J1939 "
                     "switch input; 0x0000 in the dump (was switch_override_configuration)",
         code_tests="direct reads: 0x15830 #0x2000 and 0x15850 #0x4000 mc68k_sampleAndDebounceDiscreteInputs; 0x204e6 "
                    "#0x80 cm550_outputControlState1Handler; 0x20cbe #0x80 cm550_FUN_00020c98; 0x20e5a #0x80 "
                    "cm550_FUN_00020e14; 0x32ed4 #0x80 j1939HandlePgn61443Eec2; address taken at 0x15dd2 (move.l "
                    "#0x803cae into discrete_input_override_mask_ptr 0x80054c). Bytewise through the pointer: [0] "
                    "and [1] in the debouncer and mc68k_ioDriverStrobeHandler. Indexed from word 0: bit 0xd0 + s "
                    "(cm550_FUN_00020890 for J1939 inputs 1 3 4 5 6 7 8 9 15). .cpp census: 6 tests (2 also flow "
                    "into the returned value) + 1 CONCAT22 form (21959) + the address-of",
         writes="none (no store to the word; the pointer users only read it)",
         differences_from_cm848="unrelated: CM848 word 13 is EB_Switch_Level_Override / "
                                "Active_Driver_Demand_With_Jcomm / Net_Torque_Derate_Enable / "
                                "Fuel_Press_Idle_Diag_Enable; the Chrysler e2m has no switch user override records"),
    dict(word=14, address="0x803cb0",  proposed_name="algorithm_enable_flags_14_cal",
         proposed_type="cm550_algorithm_enable_flags_14_t", shared_with_cm848=False, fields=w14,
         row_comment="Algorithm enable flags word 14 (EEPROM 0x1a6; e2m 106B +0x1E): the user override enables of "
                     "logical switches 16-31 (bit s - 16; the e2m SWITCH n number is not the bit); second word of the "
                     "DSSWUO block: the debouncer and mc68k_ioDriverStrobeHandler apply its low byte to the switch "
                     "16-23 byte 0x80bcd0 and its high byte to the switch 24-31 byte 0x80bcd1; 0x0000 in the dump",
         code_tests="direct read: 0x207d0 cm550_FUN_00020784 (move.w + andi.l #8: the remote throttle J1939 "
                    "override). Bytewise through discrete_input_override_mask_ptr [2] and [3]. Indexed from word 0: "
                    "bit 0xd0 + 19 / 20 (cm550_FUN_00020890 for J1939 inputs 14 and 13). .cpp census: 1 test that "
                    "also flows into the returned value",
         writes="none",
         differences_from_cm848="CM848 has no e2m record and no row for word 14 (0x3fd5b8)"),
]

banned = {"pto", "afc", "vss", "esp", "lsg", "hsg", "fso", "imt", "ac", "ptp", "stcg", "asg", "ocm", "edf", "init"}
problems = []
out_words = []
for w in words:
    bits = sorted(b for b, _, _ in w["fields"])
    names = [n for _, n, _ in w["fields"]]
    if bits != list(range(16)):
        problems.append(f"word {w['word']}: bits {bits}")
    if len(set(names)) != 16:
        problems.append(f"word {w['word']}: duplicate names")
    for b, n, c in w["fields"]:
        if "," in c:
            problems.append(f"word {w['word']} bit {b}: comma in comment")
        if not re.fullmatch(r"[a-z0-9_]+", n):
            problems.append(f"word {w['word']} bit {b}: bad name {n}")
        if set(n.split("_")) & banned:
            problems.append(f"word {w['word']} bit {b}: banned token in {n}")
    for key in ("row_comment", "code_tests", "writes", "differences_from_cm848"):
        if "," in w[key]:
            problems.append(f"word {w['word']} {key}: comma")
    if set(w["proposed_name"].split("_")) & banned or set(w["proposed_type"].split("_")) & banned:
        problems.append(f"word {w['word']}: banned token in the row or type name")
    d = dict(w)
    d["fields"] = [dict(bit=b, name=n, comment=c) for b, n, c in sorted(w["fields"])]
    out_words.append(d)

renames = [dict(type_name="algorithm_enable_flags_12_t", bit=1, current_field="reserved_bit_1",
                proposed_field="overspeed_fuel_shutoff_enable",
                evidence="CM848's own e2m 106B +001A Overspeed_FSO_Override mask 0x2: [EPOSFSO] If T FSO closes when "
                         "ovrspd detected by main micro. Bit 1 of 0 - 15 of Word C (its current comment already says "
                         "so); CM550 names the same bit from the same record and its code proves it "
                         "(cm550_fuelDemandLimitSelector11 / vp44_canPinVp44StatusController 0x1ca9a: in overspeed "
                         "with the bit set the fuel shutoff driver bit 0x20 is cleared). CM848 has no reader (set in "
                         "its calibration 0x2e06); the CM550 field of word 12 bit 1 uses the same name")]
for r in renames:
    if "," in r["evidence"]:
        problems.append("rename evidence: comma")

result = dict(batch="W2", words=out_words, cm848_field_renames=renames, notes=open(sys.argv[2]).read().strip())
if "," in result["notes"]:
    pass
print("\n".join(problems) or "checks passed")
json.dump(result, open(sys.argv[1], "w"), indent=1)
