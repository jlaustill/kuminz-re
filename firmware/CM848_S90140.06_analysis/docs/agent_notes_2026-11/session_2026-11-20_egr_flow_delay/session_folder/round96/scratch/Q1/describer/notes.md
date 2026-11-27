# Q1 describer notes (round 96) - periodic J1939 broadcast builders

Sources: frozen cpp/CSVs in /home/linux/.claude/jobs/374b0424/tmp/w15/r96/frozen/; Mongo j1939.pgns (J1939-71 docs
for 652xx are misaligned / missing for 65264, 65271, 65279 - used the J1939-71 layouts from memory for those).

## Schedule (verified from both init bodies)
CM550 mc68k_initializeJ1939Datalink: 19 scheduleJ1939PeriodicMessage calls (order: 65265, 61444, 61443, 65247, 65251,
61440(R), 65266, 65249(R), 65262, 65252, 65263, 65264, 65269, 65270, 65271, 65226, 65213, 61441, 65279).
CM848 cm848_j1939_system_init: 19 calls (65265, 61444, 61443(20 ms), 65247(50 ms), 65251, 61440(R), 65249(R), 65262,
65241(250 ms from 200), 65263, 65264, 65269, 65270, 65271, 65504(200 ms from 250), 65226, 65213, 61441, 65279).

## Builders run with no arguments
cm550_runJ1939PeriodicTransmitQueues calls (*entry->builder)() with no args. CM550 PGN-request responder table:
0x2f47e (no function row; FUN_0002f47e) adds (word PGN, long handler) to a 32-entry table of 6-byte entries at
0x801d5a, count byte 0x801e1a; returns 1 when full. The descriptor set-ups call it with the builder (e.g. 0x31f1c:
pea 0x31c84 / move.w #0xfef1 / jsr 0x2f47e; 0x330ae: pea 0x32e4c / 0xf003).

## 65265 CCVS1
CM550 0x31c84 j1939HandlePgn65265CruiseVehicleSpeed: fills the 8 bytes at 0x801ee2..0x801ee9 (descriptor 0x801ed4,
status 0x801eea), byte 1 0xf3 / 0xf7 (parking brake = 0x80bcd4 bit 6) + two-speed axle (0x80bcd0 bit 2) when word
0x803d48 = 1; bytes 2-3 = min(road speed 0x80a9d0, 0x9c00) x 103 >> 6 low byte first; byte 4 clutch (sw16 bit 2) / brake
(sw16 bit 3) / cruise enable (0x80bcd4 bit 4) / cruise active (0x80a9c4 = 1); byte 5 accelerate (bit 1) / resume
(bit 0) / coast (bit 3) / set (bit 2) of 0x80bcd4; byte 6 set speed = (word 0x80a9c6 x 103 >> 6) >> 8; byte 7 0x20 when
cruise active | 0x80dc2b; byte 8 0xc0 | 0x10 test (sw16 bit 7) | 4 decrement (bit 6) | 1 increment (bit 5); sends with
cm550_sendCanMessage. Registered for PGN 65265 requests by 0x31ed2 (pea 0x31c84 / 0xfef1 / jsr 0x2f47e).
CM848 0x24178: same 8-byte layout, but different code (two_speed_axle_switch_present_cal, datalink-source bits,
cruise enable flag gates, 0x19c scaling) -> COUNTERPART. Name: cm550_buildPgn65265CruiseControlVehicleSpeedMessage.

## 61443 EEC2
CM550 0x32e4c j1939HandlePgn61443Eec2: descriptor 0x8034b2 (5 bytes from 0x8034aa, status 0x8034c0; set up by 0x33064
which registers 0x32e4c for PGN 61443 requests). Byte 1 (0x8034aa) 0xf4/0xf0 kickdown (threshold word 0x80818e <
commanded_throttle) or 0xf8 on 4 pedal fault bits (word 4 bits 5/3/1/2), low-idle bits |3 when
algorithm_enable_flags_13_cal.idle_switch_override_enable, |2 on bits 3/4, |1 when accelerator_off_idle = 0;
byte 2 (0x8034ab) throttle x 0.625 (>>1 + >>3) / 0xff (sampled_throttle_override_enable) / 0xfe; cm550_param_lookup_3;
byte 3 (0x8034ac) = percent load word 0x80da1a >> 8 (0xfe when j1939_torque_and_load_not_available_flag = 1); byte 4
(0x8034ad) remote throttle x 0.625 / 0xff / 0xfe; bytes 5-8 (0x8034ae..b1) 0xff; send.
CM848 0x25b10: the same steps and constants, different inputs (all_speed_governor_equivalent_throttle, datalink-source
bit [0]&0x80 for the low idle gate, held-value bits 0x2000 / 0x100 for the overrides, named fault bits) and a
different helper (cm848_calculateEnginePercentLoadAtCurrentSpeed floors at -125%, CM550's at 0) -> COUNTERPART.
Name: cm550_buildPgn61443ElectronicEngineController2Message.

## 65247 EEC3
CM550 0x330c4 vp44_configParamCanBuilder: calls 0xf99c (nominal friction % x256 into 0x80da1c), byte 1 (0x8034c2) =
(0x80da1c >> 8) + 125, bytes 2-3 (0x8034c3/c4) = j1939_pgn65247_desired_operating_speed (0x80817e) low byte first,
byte 4 (0x8034c5) = byte 0x808181 (low byte of e2m 10E7 +2 JCEGOPRP word 0x808180); send 0x8034ca (4 bytes).
CM848 0x25de8: the identical 5 steps (friction calc, +125, low/high, asymmetry low byte, send).
Builder body = TWIN (the friction helpers 0xf99c / cm848_calculateNominalFrictionPercentTorque differ in their floor:
CM550 0, CM848 -125%). Shared name buildPgn65247ElectronicEngineController3Message (both rows) - judge's call.

## 65251 EC1 - TWIN confirmed (no rename)
Both: if (status & 0xf0) == 0 -> buildPgn65251EngineConfiguration1Payload(payload) + send. CM550 payload = 0x8034f2
(28 bytes, data_length 0x1c), previous copy 0x80350e (abs refs at 0x334f8 / 0x33510 / 0x33536 / 0x336a4); the CM550
rows 0x8034f8 can_message_buffer_start / 0x8034fa calibration_validation_buffer / 0x803500 / 0x803502
calibration_checksum_expected_1/2 sit inside it and have no absolute reference. CM848 = j1939_pgn65251_payload
(0x3fa7f8, j1939_pgn65251_payload_t) + _previous (0x3fa814). Lead: same struct in CM550.

## 61440 ERC1
CM550 0x338ea cm550_dutyCycleMonitorAltIsrHandler: byte 1 (0x80356a) = 0x40 when
algorithm_enable_flags_2_cal.j1939_retarder_shift_assist_enable (SPN 572 bits 7-8 = 01) else 0; |0x10 when word
0x80a9ca (e2m 117D +6 EBSWSS) != 0 (SPN 571 brake assist); SPN 900 from word 0x80a9cc (e2m 117D +8 EBCOAG 'EB CMD
SRC 0 NOT_COMM 1 J_COMM 2 CRUISE 3 SWITCH 4 JC_LIM' = CM848 engine_retarder_command_source): 1/4 -> 6/5/7/14 by
engine_retarder_j1939_control_device 1/3/2/else, 2 -> 2 (cruise), 3 -> 1 (operator). Byte 2 (0x80356b) 0xff when
word 0x8081fe (engine brake output driver count) = 0, else after cm550_ioControlBasedFuelCalculator 125 - (word
0x80aa14 >> 8) (SPN 520). Sends j1939_pgn61440_tx_message (2 bytes, retarder source address; set up by 0x339b0 cm550_cumminsProprietaryTSC_PGN_15728640_Builder).
0x80a9ca / 0x80a9cc have only these reads in the dumped ROM.
CM848 0x26238: different code (0xff when broadcast flag bit 3 clear, 0xc0 base = shift assist 'not available', the
command source through enum compares, output_level test) -> COUNTERPART.
Name: cm550_buildPgn61440ElectronicRetarderController1Message.

## References to the CM550 builders (find_refs.py, BE 4-byte address)
Each is pushed once by mc68k_initializeJ1939Datalink (0x28c5c..0x28e02, pea). Also registered as PGN-request
responders: 65265 (0x31f1e), 61443 (0x330b0), 65262 (0x338d8), 65252/65263/65264/65269/65270/65271 (0x2f588..0x2f5d0
in cm550_diagnosticDataDump 0x2f538, jsr (a2)); 65251's is a jsr from 0x33660. NOT registered (scheduled only):
61444, 65247, 61440, 65266, 65249, 65226 (0x3229a), 65213 (0x339fe), 61441 (0x32bbc), 65279 (0x34496).

## 65266 LFE - CM550 only (CM848 has no 0xfef2 anywhere)
CM550 0x33b40 cm550_fuelEconomyDataBuilder: bytes 1-2 (0x8035b4/b5) = fuel rate: word 0x80de62 scaled x 0x39c2c3 /
0x3840e, then x 3600 / 1e6, clamped 3212, x 20 (0.05 L/h per bit, SPN 183) low byte first; bytes 3-4 (0x8035b6/b7)
= word 0x804fb0 (e2m 117F +10 TIMP instantaneous MPG, 1/256 mpg) x 8502 / 10000 (1/512 km/L, SPN 184); bytes 5-6
(0x8035b8/b9) = word 0x804fb2 (117F +12 TIMPT3 average fuel economy since trip reset) x 0.8502 (SPN 185); sends
j1939_pgn65266_tx_message (6 bytes; set up by 0x33c28 with the priority word 0x803f74 = e2m 1254 +26 JCFEPZ).
Name: cm550_buildPgn65266FuelEconomyLiquidMessage. No rows for 0x8035b4..b9.

## 65252 SHUTDN - CM550 only; name cm550_buildPgn65252ShutdownMessage confirmed (round 95)
Bytes: 0x8035f6 (SPN 593/594/592/590 from idle_shutdown_state), 0x8035f7 (0x7f/0x3f SPN 591), 0x8035f8 (0xfd/0xfc
SPN 985 from 0x80bcd7 bit 0), 0x8035f9 (0xfd/0xfc SPN 1081 from 0x80bcf6 bit 0); 0x8035fa..fd 0xff from the set-up.
No rows for 0x8035f6..fd.

## 65262 / 65263 / 65264 / 65269 / 65270 - counterparts, names confirmed
CM550 versions have no fault-bit / enable gating and fewer fields (ET1 oil temp 0xffff; EFL/P1 only oil pressure;
AMB only baro; IC1 boost + IMT; PTO no enable gate, no datalink-source tests). CM848 ones gate on fault bits,
enable flags and datalink-source bits. Different code -> keep the prefixes; the current names are right.

## 65271 VEP1
CM550 0x342f0 cm550_retarderDataBuilder: word = battery_voltage_sensor_state.filtered_value x 5 >> 1 (0.125 V per
count -> 0.05 V/bit), byte-swapped (byteSwap16) into 0x80367e (bytes 5-6, SPN 168 battery potential / power
input 1); send j1939_pgn65271_tx_message (8 bytes from 0x80367a). The set-up 0x34334 (cm550_electronicBrakePGN_65527_Builder) puts 0xff in bytes 1-2
(0x80367a/7b: SPN 114 / 115), 0xffff in bytes 3-4 (0x80367c: SPN 167) and 7-8 (0x803680: SPN 158). Also the PGN
65271 request responder (0x2f5ce). Nothing retarder about it.
CM848 0x26cf0: the same 3 steps but x 0x14 >> 3 (equal value, different constants), cm848_reverseByteOrder16,
0x3faef2 -> COUNTERPART by the constants rule (same role). Names: cm550_buildPgn65271VehicleElectricalPower1Message /
cm848_buildPgn65271VehicleElectricalPower1Message (CM848 'Handle' is wrong: it handles no received message; it is
also the 59904 request responder via j1939_pgn_dispatch_table).
CM550 rows to fix: 0x80367a eeprom_calibration_write_state, 0x80367c eeprom_calibration_check_value_1, 0x80367e
loop_termination_flag, 0x803680 protection_flag_source_1 -> the VEP1 payload fields.

## 65249 RC
CM550 0x3407a vp44CanMessage100ResponseBuilder: only when (0x803652 status & 0xf0) == 0. Byte 1 (0x803630): 3 when
word 0x8081fe (EBNUOUDR engine brake output driver count) > 1; else 'move.w #1,(0x8081fe)' at 0x340b6 (a STORE: the
'= for ==' bug) then beq never taken -> 0x14; the 0xff branch at 0x340ca is unreachable and the count becomes 1.
Byte 2 (0x803631) from word 0x808200 (JCDR1NCY): 0 -> 0xff, 1 -> 6, 2 -> 3, 3 -> 2, 6 -> 1 (SPN 557 control method).
Bytes 3-18 from the 10FC records (idle speed 0x8089aa, 125 - (0x8089b2 >> 8), max speed 0x8089ba, 0x8089b4, point 3
0x8089ae / 0x8089b6, point 4 0x8089b0 / 0x8089b8, peak torque speed 0x8089ac, reference torque 0x8089a6). Byte 19
(0x803642) not written here: the set-up 0x341e6 stores 0xff once (CM550's 10FC block has no +0x16 JCRDP5TQ).
Sends j1939_pgn65249_tx_message via 0x104e8 (cm550_sendCanMessage) with the retarder source address, 19 bytes (TP).
CM848 0x26650: count == 1 test (0xff reachable), fills byte 19 from engine_retarder_configuration_peak_torque_percent
-> COUNTERPART. Name: cm550_buildPgn65249RetarderConfigurationMessage.
CM550 0x803630: 19-byte payload in CM848's j1939_pgn65249_payload_t layout (CM848 0x3fae50); row 0x803631
engine_brake_cylinders_per_step is its retarder_control_method byte.

## CORRECTION 65271 VEP1 = TWIN (instruction level)
Ghidra prints CM550 'x 5 >> 1' but the code at 0x342fa..0x34310 is move.w (0x80a3d0),(temp); d0 = x; d1 = x;
lsl #2; add d1; lsl #2 (= x 20); lsr #3; move.w d0,(temp); pea temp; jsr 0x218fe (byte swap); move.w d0,(0x80367e);
pea 0x80366c; jsr 0x104e8. CM848 0x26cf0: lhz battery; sth temp; mulli 20; srwi 3; sth temp; bl 0x50b58c (byte
swap of temp); sth 0x3faef2; bl 0x539fc (send). Same steps, same constants (x 20 >> 3), same temp-then-overwrite.
-> TWIN: shared name buildPgn65271VehicleElectricalPower1Message (CM550 0x342f0 + CM848 0x26cf0). Both are also the
PGN 65271 request responders (CM550 0x2f5ce in cm550_diagnosticDataDump, CM848 cm848_initJ1939ProtocolHandlers).

## 65247 EEC3 = TWIN (instruction level)
CM550 0x330c4: jsr 0xf99c; move.w 0x80da1c >> 8 -> move.b (a3); addi.b #0x7d,(a3); move.w 0x80817e -> temp;
bytes from temp+1 / temp; move.b 0x808181 -> +3; send. CM848 0x25de8: bl 0x20af0; lhz 0x40ad90 >> 8 -> stb +0;
addi 125 -> stb +0 again (same store-then-add); sth desired speed to a stack temp, lbz 9/8 -> +1/+2; lhz 0x5c384 ->
stb +3; bl send. -> TWIN, shared name buildPgn65247ElectronicEngineController3Message.

## 61443 EEC2 = counterpart (firm)
The pedal input differs: CM550 commanded_throttle_state.commanded_throttle, CM848 all_speed_governor_equivalent_throttle
(the ASG equivalent throttle, a CM848-only calculation); override gates are CM550 algorithm_enable_flags_5 bits 10/11
(ADSATHOD / ADROTHOD) and flags_13 bit 7 (DSIVSWUO) vs CM848 held-value bits 13/8 and datalink-source bit [0]&0x80.

## 65226 DM1 broadcast - CM550 0x3229a (NO FUNCTION ROW)
0x3229a tst.b (0x8058d4) [active_dtc_list[0] = count]; beq 0x322ac; clr.l -(a7); jsr 0x322ae
(j1939HandlePgn65226Dm1ActiveDtc, the DM1 sender; the pushed 0 is not read); addq.l #4,a7; 0x322ac rts.
Range 0x3229a..0x322ad (20 bytes), ends with the rts at 0x322ac; starts right after the rts at 0x32298 of
cm550_diagnosticDM11PGN_65234_Builder (0x32244), next function 0x322ae. Entries: only the pea at 0x28dbc
(mc68k_initializeJ1939Datalink); brute-force branch scan (entries_into.py) finds only its own beq.
CM848 cm848_processDm1FaultBroadcast 0x24d78: also sends once more when the count drops to 0 (pending flag) ->
COUNTERPART. CM550 sends nothing while no fault is active (no all-clear DM1). The PGN 65226 request responder is
0x322ae itself (registered by 0x323be). Name: cm550_processDm1FaultBroadcast (follows CM848) .

## 61441 EBC1 - CM550 0x32bbc (NO FUNCTION ROW)
0x32bbc..0x32c21, rts at 0x32c20; previous rts 0x32bba (vp44_diagnosticDM8PGN_65232_Builder 0x32b64), next 0x32c22
(cm550_initializePgn61441ElectronicBrakeController1Buffer). Entries: pea at 0x28de8 only; branches only internal
(0x32bde / 0x32be6 / 0x32c02). Body: a1 = 0x80347a payload, a0 = 0x80bcce switch bytes. Byte 4 (0x80347d) = 0x40
when 0x80bcd0 bit 3 (RMTHSW remote throttle switch = switch 20) -> SPN 969 remote accelerator enable switch bits 7-8
= 01, else 0; |1 when 0x80bccf bit 1 (DSACILSS accelerator interlock switch) -> SPN 972 bits 1-2 = 01; bits 3-6 = 00.
Byte 5 (0x80347e) = byte 0x80a9f1 = low byte of word 0x80a9f0 (e2m 117D +2C EBSWLV 'commanded brake level from
operator switches', % scale 1) copied unscaled as SPN 973 (0.4 %/bit, so 100 % reads as 40 %). Sends
j1939_pgn61441_tx_message (5 bytes). Byte 2 (0x80347b, SPN 521) is written by nobody (0 in the dump).
CM848 0x2567c cm848_j1939BuildEngineControlByte: all four switch fields with datalink-source / enable gates and byte 5
= engine_retarder_selection_percent x 5 >> 1 or 0xff -> COUNTERPART.
Names: cm550_buildPgn61441ElectronicBrakeController1Message / cm848_buildPgn61441ElectronicBrakeController1Message.
RAM dump 0x80347a: ff 00 ff 01 00.

## 65213 FD1 - CM550 0x339fe (NO FUNCTION ROW)
0x339fe..0x33a1d, rts at 0x33a1c; previous rts 0x339fc (cm550_cumminsProprietaryTSC_PGN_15728640_Builder 0x339b0),
next 0x33a1e (initializePgn65213FanDrive1Buffer). Straight-line code, no branch into it (brute-force scan: none);
pea at 0x28dd2 only. Body: byte 2 (0x803583) = byte 0x80a9f3 (low byte of word 0x80a9f2, e2m 117D +2E FCST 'combined
fan state', the record CM848 calls fan_drive_state_code) | 0xf0 (SPN 977 + reserved nibble); send
j1939_pgn65213_tx_message (2 bytes from 0x803582). Byte 1 (0x803582, SPN 975) is never written (0 in the dump).
CM848 0x2641c: writes byte 1 (fan percent x5 >> 9) and checks state < 16 -> COUNTERPART.
Name: cm550_buildPgn65213FanDrive1Message.

## 65279 WFI - CM550 0x34496 (NO FUNCTION ROW)
0x34496..0x344cd, rts at 0x344cc; previous rts 0x34494 (cm550_initializePgn65260VehicleIdentificationHandler 0x34440),
next 0x344ce (cm550_initializePgn65279WaterInFuelIndicatorBuffer). Branches only internal (0x344b4 / 0x344ba); pea
at 0x28e02 only. Body: j1939_pgn65279_water_in_fuel_indicator_byte (0x8036ac) = 1 when 0x80bcf6 bit 2 (e2m E +28
LCWFLP commanded water-in-fuel lamp) else 0; send j1939_pgn65279_tx_message (1 byte).
CM848 cm848_sendPgn65279WaterInFuelIndicatorMessage: 0xff / 0xfc / 0xfd from the enable bit and fault bit ->
COUNTERPART. Name: cm550_sendPgn65279WaterInFuelIndicatorMessage (CM848 uses send for this pair).

## CM848-only
65241 cm848_buildPgn65241AuxiliaryInputOutputStatus1Message (0x24028): name right; CM550 has no 0xfed9.
65504 cm848_j1939HandlePgn65504ProprietaryB (0x269f4): fills j1939_pgn65504_payload (engine speed byte-swapped, net
output torque + 0x7d7f byte-swapped, a TBL-derived scramble key and three scrambled injection timing bytes; all 0 at
0 rpm) and sends it; also the 65504 request responder. Not a handler of a received message ->
cm848_buildPgn65504ProprietaryBMessage. CM550: none.

## Payload globals (abs_refs: every byte below is touched only by its builder / set-up, through base registers)
CM550 CCVS1 0x801ee2..e9 (rows ccvs_message_byte_0/3/4 + DAT 0x801ee3/e4/e7/e8/e9): byte 1 SPN 69/70, bytes 2-3 SPN 84
(x 412 >> 8, Ghidra prints x 103 >> 6), byte 4 SPN 595-598, byte 5 SPN 599-602, byte 6 SPN 86, byte 7 SPN 976/527,
byte 8 SPN 968/967/966. Inputs: 0x803d48 = e2m 1180 +E VSRXRASP (EEPROM) = CM848 two_speed_axle_switch_present_cal;
0x80a9c6 = 117D +2 CRRF = CM848 cruise_speed_command; 0x80dc2a = 109E +6 PTDXSS = CM848 power_take_off_governor_j1939_state.
CM550 EEC2 0x8034aa..ae (5 bytes sent) + 0x8034af..b1 (0xff, never sent): wrong rows vp44_feedback_pulse_low/high_
fault_counter, lift_pump_timing_smoothed, derate_threshold_previous, fso_fault_previous_value.
CM550 EEC3 0x8034c2..c5 (rows fso_range_fault_high/clear_counter, vp44_timing_status_fault_counter,
vp44_timing_mode_3_high_counter) = CM848 j1939_eec3_* layout (twin). 0x808180 (JCEGOPRP) = CM848
j1939_pgn65247_desired_operating_speed_asymmetry_adjustment.
CM550 ERC1 0x80356a retarder_tsc_status_byte / 0x80356b; 0x80a9cc = EBCOAG = CM848 engine_retarder_command_source.
CM550 LFE 0x8035b4/b6/b8 (byte[2] each); 0x804fb0 TIMP / 0x804fb2 TIMPT3; 0x803f74 JCFEPZ priority (EEPROM).
CM550 RC 0x803630 (19 bytes) = j1939_pgn65249_payload_t; inputs 0x8089ac/ae/b0 (no rows; 10FC +6/+8/+A = CM848
engine_retarder_configuration_peak_torque_speed / point_3_speed / point_4_speed).
CM550 SHUTDN 0x8035f6..f9.
CM550/CM848 VEP1 (twin): CM550 0x80367a/7b/7c/7e/80, CM848 0x3faeee/ef/f0/f2/f4.
CM550 FD1 0x803582 (never written) / 0x803583; 0x80a9f2 = FCST = CM848 fan_drive_state_code.
CM550 EBC1 0x80347d (byte 4) / 0x80347e (byte 5); 0x80a9f0 = EBSWLV = CM848 engine_retarder_selection_percent;
0x803f90 JCEBDFPZ priority (EEPROM). CM848 EBC1 0x3fad7b j1939_status_byte_a (byte 4) / 0x3fad7c (byte 5).
CM550 EC1 0x8034f2 + 0x80350e = j1939_pgn65251_payload / _previous (j1939_pgn65251_payload_t).

## RAM dump spot checks (CM550 J90350.00.ram.bin)
EBC1 ff 00 ff 01 00; RC 14 06 40 1f 46 e0 60 19 a0 28 42 60 3b 2a e0 60 86 01 ff; VEP1 ff ff ff ff 09 01 ff ff (13.25 V);
EEC3 82 e0 2e 7d; ERC1 40 7d; LFE 00 00 00 00 5e 09; SHUTDN 00 3f fd fc ff ff ff ff; CCVS1 f3 00 00 50 00 68 00 c0;
FD1 00 f0; 0x8081fe = 1, 0x808200 = 1.

## VEP1 scale: CM848 reports twice the battery voltage (finding)
CM550 battery_voltage_sensor_state.filtered_value is 0.125 V per count (e2m ADBTVT scale 0.125): x 20 >> 3 = x 2.5 ->
0.05 V/bit correct (dump 106 counts -> 0x0109 = 13.25 V). CM848 battery_voltage_sensor_filtered is 1/16 V per count
(e2m ADBTVTYA 0.0625; dump 0x00c0 = 12.0 V) but the same x 20 >> 3 code -> CM848 RAM VEP1 bytes 5-6 = e0 01 = 480 =
24.0 V on the bus for a 12.0 V battery. The identical code across a scale change supports the twin; CM848's SPN 168 is
doubled. (cm848_ram.bin base 0x3fa000: 0x3faeee = ff ff ff ff e0 01 ff ff.)

## Linear-sweep cross-check (cm550_full_disasm.txt)
The only references to 0x3229a / 0x339fe / 0x32bbc / 0x34496 are the four peas at 0x28dba / 0x28dd0 / 0x28de6 /
0x28e00 in mc68k_initializeJ1939Datalink.

## Lead (other batch): CM550 0x2f47e has no function row (FUN_0002f47e, 23 callers): register a PGN-request
responder: 32 entries x 6 bytes at 0x801d5a (word PGN + long handler), count byte 0x801e1a, returns 1 when full
(moveq #1) else 0 - the same logic as CM848 cm848_j1939RegisterPgnHandler (0x23188).
Lead: the CM550 RC '=' bug also changes the other readers of 0x8081fe (0x1fcee diagnostic message 54 builder,
0x2f800 cm550_retarderControlModeHandler, 0x33974 the ERC1 builder) once the RC builder has run.

## FINAL NAMES
CM550 0x31c84 cm550_buildPgn65265CruiseControlVehicleSpeedMessage (counterpart)
CM550 0x32c76 / CM848 0x2588c sendPgn61444ElectronicEngineController1Message (twin, keep)
CM550 0x32e4c cm550_buildPgn61443ElectronicEngineController2Message (counterpart)
CM550 0x330c4 + CM848 0x25de8 buildPgn65247ElectronicEngineController3Message (TWIN)
CM550 0x3366a / CM848 0x1b730 sendPgn65251EngineConfiguration1Message (twin, keep)
CM550 0x338ea cm550_buildPgn61440ElectronicRetarderController1Message (counterpart)
CM550 0x33b40 cm550_buildPgn65266FuelEconomyLiquidMessage (none)
CM550 0x3407a cm550_buildPgn65249RetarderConfigurationMessage (counterpart)
CM550 0x337c4 / 0x33d38 / 0x33164 / 0x33f5a / 0x31bce / 0x33e58 round-95 names kept (counterparts / none)
CM550 0x342f0 + CM848 0x26cf0 buildPgn65271VehicleElectricalPower1Message (TWIN)
CM550 0x3229a (new row) cm550_processDm1FaultBroadcast (counterpart)
CM550 0x339fe (new row) cm550_buildPgn65213FanDrive1Message (counterpart)
CM550 0x32bbc (new row) cm550_buildPgn61441ElectronicBrakeController1Message (counterpart)
CM550 0x34496 (new row) cm550_sendPgn65279WaterInFuelIndicatorMessage (counterpart)
CM848 0x269f4 cm848_buildPgn65504ProprietaryBMessage (none)
CM848 0x2567c cm848_buildPgn61441ElectronicBrakeController1Message (counterpart)

## 61444 EEC1 shared name - the bodies are NOT identical (flag)
CM550 0x32c76: user fueling states 1/2/3/7/8/30/37 -> 0xfb (remote accelerator) when
commanded_throttle_state.selected_alternate_throttle_priority = 0x8089a4 (CTRMTHPZ remote throttle priority) else 0xf1;
derate states 13-21/28/29/31/33-36/38-41 -> 0xf8 directly. CM848 0x2588c: 0xf8 only when torque_derate_fuel_source_code
= final_fueling_state, no 0xfb case, the derate states otherwise 0xfe. Same order of the rest (two torque helpers, +125,
0xfe when j1939_torque_and_load_not_available_flag, speed low/high). By the identical-code rule: counterpart.
CM550 EEC1 payload 0x803492..96 (vp44_torque_speed_control_status / DAT 0x803493 / vp44_timing_expected_init /
DAT 0x803495-96): torque mode / SPN 512 / SPN 513 / SPN 190; only the builder and 0x32e08 touch them.
CM848 0x3fad90 j1939_engine_status_byte is the same SPN 899 torque mode byte.
