# Q1 investigator notes (round 96) - periodic J1939 broadcast builders

## Call lists (verified from both .cpp)
CM550 mc68k_initializeJ1939Datalink 19 calls: 65265,61444,61443,65247,65251,61440(R),65266,65249(R),65262,65252,65263,65264,65269,65270,65271,65226,65213,61441,65279
CM848 cm848_j1939_system_init 19 calls: 65265,61444,61443(20ms),65247(50ms),65251,61440(R),65249(R),65262,65241(250ms,200),65263,65264,65269,65270,65271,65504(200,250),65226,65213,61441,65279
Mongo j1939 connected (connection name j1939).

## Reachability (CM550): every builder's entry is pea'd once by mc68k_initializeJ1939Datalink at 0x28c5c..0x28e02 (schedule calls).
 Extra refs: 0x31c84 also pea at 0x31f1e (65265 init registers it with the request registrar 0x2f47e); 0x32e4c at 0x330b0 (EEC2 init);
 0x337c4 at 0x338d8 (ET1 init); 0x33d38/0x33164/0x33f5a/0x31bce/0x33e58/0x342f0 at 0x2f588..0x2f5d0 (cm550_diagnosticDataDump registers them with 0x2f47e
 for PGN 65252/65263/65264/65269/65270/65271 = request responders via cm550_FUN_0002f4be the PGN 59904 dispatcher).
 The 4 LAB blocks: 0x3229a / 0x339fe / 0x32bbc / 0x34496 each referenced ONLY by the one pea (raw 4-byte search + PC-relative branch scan: only internal branches).

## 65265 CCVS - CM550 0x31c84 (j1939HandlePgn65265CruiseVehicleSpeed) vs CM848 cm848_buildPgn65265CruiseControlVehicleSpeedMessage: COUNTERPART
 CM550 payload 0x801ee2 (8 bytes, descriptor j1939_pgn65265_tx_message 0x801ed4):
  0x801ee2 byte1: 0xf3 / 0xf7 (bits 3-4 parking brake SPN 70 from 0x80bcd4 bit 6), then &0xfc/&0xfd (two-speed axle SPN 69 from 0x80bcd0 bit 2) only when word 0x803d48 (e2m 1180+E VSRXRASP axle switch present) == 1
  0x801ee3/4 bytes 2-3 (two move.b, low first): wheel-based vehicle speed SPN 84 = min(0x80a9d0, 0x9c00) * 412 >> 8 (mph/256 -> km/h/256)
  0x801ee5 byte4: 0x40 clutch (0x80bccf bit2) | 0x10 brake (0x80bccf bit3) | 4 cruise enable (0x80bcd4 bit4) | 1 cruise active (0x80a9c4 == 1)
  0x801ee6 byte5: 0x40 accelerate (0x80bcd4 bit1) | 0x10 resume (bit0) | 4 coast (bit3) | 1 set (bit2)
  0x801ee7 byte6: cruise set speed SPN 86 = high byte of (0x80a9c6 CRRF cruise reference speed * 412 >> 8)
  0x801ee8 byte7: 0x20 (cruise state 1 hold) when cruise active | byte 0x80dc2b (low byte of 109E+6 PTDXSS J1939 PTO state SPN 976)
  0x801ee9 byte8: 0xc0/0xd0 (test mode SPN 966 from 0x80bccf bit7) | 0xc4 (idle decrement 967, bit6) | 0xc1 (idle increment 968, bit5)
  then cm550_sendCanMessage(&j1939_pgn65265_tx_message). CM848 differs (datalink source bits, cal gates, 0xff n/a forms, pto enable) -> counterpart.
## 61444 EEC1 - CM550 0x32c76 / CM848 0x2588c sendPgn61444ElectronicEngineController1Message (shared already): KEEP the shared name
 Same 6 steps in the same order: TSC1 override (0x80da50 / 0x40adf8) with final_fueling_state in {2,1,20}: indicator 1->0xf6 3->0xf5 2->0xf7 else 0xfe;
 else torque mode by fueling state (0xf0 LSG / 0xf1 / 0xf2 cruise / 0xf3 PTO / 0xf4 RSG / 0xf8 / 0xf9 HSG / 0xfa brake / 0xfe);
 driver demand call (0xf796 / 0x20860) high+125 byte2; actual torque call (0xf8c6 / 0x209e8) high+125 byte3, 0xfe when 0x80d358 / 0x40a336 == 1; engine speed low/high bytes 4-5; send.
 Differences only inside the torque-mode switch: CM550 lists the derate states (-> 0xf8) and has 0xfb (remote accelerator when the selected alternate
 throttle priority 0x80aa94 == 0x8089a4); CM848 picks 0xf8 by torque_derate_fuel_source_code == final_fueling_state and has no 0xfb. (method versioning; stage 9b twin)
 CM550 payload 0x803492 (5 bytes): 0x803492 byte1 torque mode (row vp44_torque_speed_control_status WRONG), 0x803493 byte2 driver demand (DAT), 0x803494 byte3 actual torque (row vp44_timing_expected_init WRONG), 0x803495/6 engine speed (DAT).
 RAM dump: fe 7d fe 00 00.

## 61443 EEC2 - CM550 0x32e4c j1939HandlePgn61443Eec2 vs CM848 0x25b10 cm848_buildPgn61443ElectronicEngineController2Message: TWIN (step for step)
 Both: 4 throttle fault tests -> 0xf8 else 0xf4 (throttle > kickdown threshold) / 0xf0; override bit -> |3 else switch high/low fault -> |2 else accelerator_off_idle==0 -> |1;
 same 4 faults -> byte2 0xfe else override -> 0xff else throttle>>1 + throttle>>3; percent load call (0xf930 / 0x20a58) high byte -> byte3, 0xfe when not-available flag;
 remote: !remote_throttle_enable || override -> 0xff, remote fault pair -> 0xfe, else remote>>1+>>3 -> byte4; bytes 5-8 = 0xff (data_length 5 in both!); send.
 Inputs are each firmware's own fault / override words (CM550 status word & fault_processing_enable mask pairs; CM848 fault_detected_cal bits).
 Both initializers (0x33064 / cm848_initPgn61443Eec2Handler) set length 5, call a stub (0xf99a / cm848_emptyStubFunction7) and register the builder for 0xf003 (0x2f47e / cm848_j1939RegisterPgnHandler).
 CM550 payload 0x8034aa: byte1 0x8034aa (vp44_feedback_pulse_low_fault_counter WRONG), byte2 0x8034ab (vp44_feedback_pulse_high_fault_counter WRONG), byte3 0x8034ac (lift_pump_timing_smoothed WRONG),
  byte4 0x8034ad (DAT), byte5 0x8034ae (derate_threshold_previous WRONG), 0x8034af DAT, 0x8034b0 (fso_fault_previous_value WRONG), 0x8034b1 DAT. RAM: f9 fe fe 00 ff ff ff ff.

## 65271 VEP1 - CM550 0x342f0 cm550_retarderDataBuilder vs CM848 0x26cf0 cm848_j1939HandlePgn65271VehicleElectrical: TWIN
 asm CM550: battery (0x80a3d0) -> x*4+x=5x, <<2 = 20x, >>3 (Ghidra printed *5>>1) ; CM848 x*0x14>>3: SAME constants. byteSwap16 / cm848_reverseByteOrder16 into payload +4 (bytes 5-6 SPN 168), send.
 Same payload layout from both inits: +0 0xff, +1 0xff, +2 0xffff, +4 battery, +6 0xffff. Both 15th schedule call (1000 ms from 210 ms) and both PGN 59904 request responders.
 CM550 payload 0x80367a: eeprom_calibration_write_state(+0) / eeprom_calibration_check_value_1(+2) / loop_termination_flag(+4) / protection_flag_source_1(+6) all WRONG names.
 CM848 payload 0x3faeee: DAT +0/+1, j1939_pgn65271_field1_init_word(+2), j1939_pgn65271_voltage_tx_word(+4), j1939_pgn65271_field2_init_word(+6).

## 65249 RC - CM550 0x3407a vp44CanMessage100ResponseBuilder vs CM848 cm848_buildPgn65249RetarderConfigurationMessage: COUNTERPART
 CM550 bug: count (0x8081fe) <= 1 -> move.w #1,(0x8081fe) (writes 1 to the driver count, an '=' for '==') then beq never taken -> byte1 0x14; CM848 tests ==1 -> 0x14 else 0xff.
 CM550 never writes byte 19 (0x803642, 0xff from the init at 0x341e6 move.b #0xff,(0x12,a0)); CM848 writes percent_torque_at_peak_torque_point_5.
 Otherwise the same 18 bytes (cyl count map 0->0xff 1->6 2->3 3->2 6->1, speeds low/high, 125 - torque high bytes).
## 65247 EEC3 - CM550 0x330c4 vp44_configParamCanBuilder vs CM848 0x25de8 cm848_buildPgn65247ElectronicEngineController3Message: TWIN (identical)
 Both: call friction calc (0xf99c / 0x20af0); store high byte of friction x256 (0x80da1c / 0x40ad90) into byte1 then add 125 in place (both store twice!);
 bytes 2-3 = desired operating speed word (0x80817e / 0x5c382) low then high; byte4 = low byte of asymmetry word (0x808181 = low of 0x808180 JCEGOPRP / 0x5c384); send (0x8034ca / 0x3fadc8).
 CM550 payload 0x8034c2 (4 bytes): fso_range_fault_high_counter(+0) fso_range_fault_clear_counter(+1) vp44_timing_status_fault_counter(+2) vp44_timing_mode_3_high_counter(+3): WRONG names, used only here and by the init data pointer.
 RAM: 82 e0 2e 7d (5 % friction, 1500 rpm, 125).

## 61440 ERC1 (retarder queue) - CM550 0x338ea cm550_dutyCycleMonitorAltIsrHandler vs CM848 0x26238: COUNTERPART
 CM550 byte1 0x80356a: 0x40 when algorithm_enable_flags_2_cal.j1939_retarder_shift_assist_enable (bits 7-8 SPN 572) | 0x10 when word 0x80a9ca (e2m 117D+6 EBSWSS) != 0 (bits 5-6 SPN 571) |
  torque mode SPN 900 by word 0x80a9cc (117D+8 EBCOAG cmd source): 1/4 J1939 -> device 0x80a9da 1->6 3->5 2->7 else 14; 2 cruise -> 2; 3 switch -> 1.
 byte2 0x80356b: 0xff when engine brake driver count 0 else cm550_ioControlBasedFuelCalculator then 125 - high(retarder torque) (SPN 520). send j1939_pgn61440_tx_message (2 bytes).
 CM848 adds the datalink_broadcast_enable_flags bit 3 gate (0xff), 0xc0/0xd0 forms (shift assist n/a), output level / command source test -> different steps.

## 65266 LFE (CM550 only, CM848 schedules 65241 there) - 0x33b40 cm550_fuelEconomyDataBuilder: STANDALONE
 rate = cm550_scaleByRatio(cm550_scaleByRatio(fuel rate,0x39c2c3,0x3840e),3600,1000000) clamp 3212 L/h, x20 -> bytes 1-2 (0.05 L/h SPN 183);
 bytes 3-4 = TIMP (117F+10, mpg/256) x 8502 / 10000 (SPN 184, 1/512 km/L); bytes 5-6 = TIMPT3 (117F+12 trip average mpg/256) x 8502/10000 (SPN 185); send (6 bytes).
 payload 0x8035b4..b9 all DAT (no rows).

## 65252 SHUTDN (CM550 only) - 0x33d38 cm550_buildPgn65252ShutdownMessage: name right, STANDALONE (CM848 only receives 65252)
 byte1 0x8035f6 by idle_shutdown_state RESET 0 / COUNT 0x40 (timer active) / WARNING 0x44 (+driver alert) / OVERRIDE 0x10 / SHUTDOWN 1; byte2 0x8035f7 = 0x7f enabled / 0x3f (SPN 591 bits 7-8);
 byte3 0x8035f8 0xfd/0xfc from air_conditioner_pressure_switch_state bit0 (SPN 985); byte4 0x8035f9 0xfd/0xfc from 0x80bcf6 bit0 (wait to start lamp, SPN 1081). bytes 5-8 0xff from init 0x33dfa.

## 65226 DM1 periodic - CM550 0x3229a (no function) vs CM848 0x24d78 cm848_processDm1FaultBroadcast: COUNTERPART
 CM550 0x3229a..0x322ac rts: tst.b active_dtc_list (0x8058d4 count) ; beq ; clr.l -(a7) ; jsr j1939HandlePgn65226Dm1ActiveDtc (0x322ae) ; addq ; rts. Only ref = pea at 0x28dbc.
 CM848: count != 0 -> send + j1939_dm1_broadcast_pending_flag = 1; count == 0 -> send once more if the flag was set, flag = 0 (one empty DM1 after the list empties).

## 65213 FD1 - CM550 0x339fe (no function) vs CM848 0x2641c cm848_buildPgn65213FanDrive1Message: COUNTERPART
 CM550 0x339fe..0x33a1c rts: byte2 0x803583 = byte 0x80a9f3 (low byte of word 0x80a9f2 = e2m 117D+2E FCST combined fan state 1-10) | 0xf0; send 0x80358a. Byte1 0x803582 never written (0 in dump). Only ref pea 0x28dd2.
 CM848 writes byte1 (speed x5>>9) too and 0xfe when the state > 15.

## 61441 EBC1 - CM550 0x32bbc (no function) vs CM848 0x2567c cm848_j1939BuildEngineControlByte: COUNTERPART
 CM550 0x32bbc..0x32c20 rts: byte4 0x80347d = 0x40 when 0x80bcd0 bit3 (e2m E+2 DS20SWSS switch 20) [SPN 969 remote accelerator enable bits 7-8] else 0, |1 when 0x80bccf bit1 (E+1 DSACILSS accelerator interlock) [SPN 972 bits 1-2];
 byte5 0x80347e = byte 0x80a9f1 (low byte of 117D+2C EBSWLV 0-100 %, sent raw - no 0.4 %/bit scaling) [SPN 973]; send 0x803482 (5 bytes). Only ref pea 0x28de8.
 CM848: byte4 from switch 31 / throttle interlock with datalink-source and enable gates (0xc0/0x30/0xc/3 not available), byte5 = selection% x5>>1 or 0xff.

## 65279 WFI - CM550 0x34496 (no function) vs CM848 0x26e90 cm848_sendPgn65279WaterInFuelIndicatorMessage: COUNTERPART
 CM550 0x34496..0x344cc rts: byte1 0x8036ac = 1 when 0x80bcf6 bit2 (LCWFLP water in fuel lamp command) else 0 (bits 3-8 = 0); send 0x8036b4. Only ref pea 0x28e02.
 CM848: 0xff when water_in_fuel_enable clear, else 0xfd fault / 0xfc.
