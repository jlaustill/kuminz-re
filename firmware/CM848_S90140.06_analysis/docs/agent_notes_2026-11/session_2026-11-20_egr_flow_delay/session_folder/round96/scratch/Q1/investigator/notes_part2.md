# Q1 investigator notes part 2 (continues notes.md)

## asm details
- 65271: CM550 0x342f0 move.w battery (0x80a3d0); d0 = x; lsl #2; add x (5x); lsl #2 (20x); lsr #3. Same as CM848 mulli 20 / srwi 3. byteSwap16 (0x218fe) then move.w to 0x80367e (payload +4).
- 65266: 0x80de62 rate, scaleByRatio(x, 0x39c2c3, 0x3840e), scaleByRatio(result, 3600, 1000000), clamp 0xc8c, x20; TIMP / TIMPT3 x 8502 (shift chain) / 10000 (divu.l).
- 65252: jump table on idle_shutdown_state 0..5: 0 gives 0, 1 gives 0x40, 2 gives 0x44, 3 (DELAY) unchanged, 4 gives 0x10, 5 gives 1. Byte 2 from 0x803c9a bit 1 (idle_shutdown_enable).

## Decisions
- Twins (shared unprefixed name, both rows): 61444 (keep), 65251 (keep), 61443 (new buildPgn61443ElectronicEngineController2Message), 65247 (new buildPgn65247ElectronicEngineController3Message), 65271 (new buildPgn65271VehicleElectricalPower1Message).
- Counterparts (prefixed): 65265, 61440, 65249, 65262, 65263, 65264, 65269, 65270, 65226, 65213, 61441, 65279.
- Standalone: CM550 65266, 65252; CM848 65241, 65504.
- New CM550 function rows: 0x3229a (rts 0x322ac), 0x339fe (rts 0x33a1c), 0x32bbc (rts 0x32c20), 0x34496 (rts 0x344cc).

## Leads (not this batch)
- CM550 0xf99a (stub) and 0xf99c (friction calc) match CM848 cm848_emptyStubFunction7 (0x20aec) and cm848_calculateNominalFrictionPercentTorque (0x20af0): the same call slots in the EEC2 initializer and the EEC3 builder.
- CM550 0xf796 cm550_paramSystemModeController matches cm848_calculateDriverDemandPercentTorque; 0xf8c6 cm550_param_lookup_1 matches cm848_calculateActualEnginePercentTorque; 0xf930 cm550_param_lookup_3 matches cm848_calculateEnginePercentLoadAtCurrentSpeed; 0xff6c cm550_ioControlBasedFuelCalculator matches cm848_calculateEngineRetarderTorque (call slots in EEC1 / EEC2 / ERC1).
- CM550 0x2f47e (FUN_, no row) is the PGN 59904 request responder registrar (pea handler, move.w pgn), the counterpart of cm848_j1939RegisterPgnHandler; cm550_FUN_0002f4be is the request dispatcher (table 0x801d5a, count 0x801e1a).
- CM550 inputs with no row: 0x80a9c6 CRRF cruise reference speed (mph/256); 0x803d48 VSRXRASP two-speed axle switch present (EEPROM window, so _cal; CM848 two_speed_axle_switch_present_cal); 0x80dc2a PTDXSS J1939 PTO state; 0x80a9ca EBSWSS; 0x80a9cc EBCOAG engine brake command source (CM848 enum ENGINE_RETARDER_COMMAND_SOURCE); 0x80a9f0 EBSWLV; 0x80a9f2 FCST.
- CM550 0x80bcd4 switch_status_cruise_coast_switch_bit_3_on_off is the whole cruise switch byte (e2m E +6: bit 0 resume, 1 accelerate, 2 set, 3 coast, 4 on, 5 set/resume; bit 6 is read as the CCVS parking brake).
- CM550 vp44CanMessage100ResponseBuilder (0x3407a) decompiles with in_D0 and a uint return; the callers (the queue runner jsr (a0) and the request dispatcher) ignore d0, so a void(void) prototype would clean it.
- CM550 65249 assignment bug at 0x340b6: move.w #1,(0x8081fe) inside the driver count test.
- CM550 descriptor initializers still carry old names (an initializer batch): vp44Command0x100Builder (EEC1 0x32e08), vp44_cumminsProprietaryDM_983_Builder (EEC2 0x33064), vp44_secondaryParamPGN_65247_Builder (EEC3 0x33120), cm550_cumminsProprietaryTSC_PGN_15728640_Builder (ERC1 0x339b0, header 0xf00000), cm550_fuelEconomyPGN_65266_Builder (LFE 0x33c28), cm550_j1939MessageSetup_PGN_65265 (AMB 65269 0x31c1a), vp44_engineFluidLevelPGN_65263_Builder (0x331ae), cm550_intakeManifoldPGN_65526_Builder (IC1 0x33eee), cm550_cruiseControlPGN_65264_Builder (PTO 0x3401a), cm550_electronicBrakePGN_65527_Builder (VEP1 0x34334), cm550_engineCoolantPGN_65226_Builder (DM1 0x323be), cm550_engineTemperaturePGN_65262_Builder (ET1 0x33880).
- CM848 ET1 payload: j1939_et1_coolant_temp_byte / j1939_et1_fuel_temp_byte use the banned short form temp; j1939_pgn65262_field1_init_word (0x3fae02) is SPN 176 turbocharger oil temperature (0xffff from cm848_initPgn65262EngineTempHandler); CM550 0x803564 / 0x803566 / 0x803567 (bytes 5-6 / 7 / 8 = 0xffff / 0xff / 0xff from 0x33880) have no rows.
- CM550 DM1 sender j1939HandlePgn65226Dm1ActiveDtc (0x322ae) never reads the long its callers push (movem of 7 registers, no stack read).

## EEC1 state to torque mode table (CM550 jump table 0x32d04, index = state - 1, 41 entries)
- 1 2 3 7 8 30 37: 0xf1 (0xfb when 0x80aa94 == 0x8089a4); 4: 0xf3; 9: 0xf2; 10: 0xf4; 11: 0xf0; 12: 0xf9; 24: 0xfa; 13-21 28 29 31 33-36 38-41: 0xf8; 5 6 22 23 25-27 32 and 0 / above 41: 0xfe.
- CM848 table (0..37): the same f1 / f3 / f2 / f4 / f0 / f9 / fa states, the rest 0xfe; 0xf8 comes first from torque_derate_fuel_source_code == final_fueling_state. So the same map plus two refinements: twin kept.

## Function names chosen (all checked unique in both function_renames.csv)
- CM550: cm550_buildPgn65265CruiseControlVehicleSpeedMessage, cm550_buildPgn61440ElectronicRetarderController1Message, cm550_buildPgn65266FuelEconomyLiquidMessage, cm550_buildPgn65249RetarderConfigurationMessage, cm550_broadcastPgn65226Dm1WhileFaultsActive (0x3229a), cm550_buildPgn65213FanDrive1Message (0x339fe), cm550_buildPgn61441ElectronicBrakeController1Message (0x32bbc), cm550_sendPgn65279WaterInFuelIndicatorMessage (0x34496).
- Shared twins: buildPgn61443ElectronicEngineController2Message (0x32e4c / 0x25b10), buildPgn65247ElectronicEngineController3Message (0x330c4 / 0x25de8), buildPgn65271VehicleElectricalPower1Message (0x342f0 / 0x26cf0); kept sendPgn61444ElectronicEngineController1Message, sendPgn65251EngineConfiguration1Message.
- CM848: cm848_buildPgn61441ElectronicBrakeController1Message (0x2567c), cm848_buildPgn65504ProprietaryBMessage (0x269f4), cm848_broadcastPgn65226Dm1UntilFaultsClear (0x24d78); kept cm848_buildPgn65241AuxiliaryInputOutputStatus1Message.

## Globals chosen (checked unique with check_names.py, no collisions in either firmware)
- CM550 flat j1939_pgn<N>_<field> rows (the round 95 style) for 65265 / 61444 / 61443 / 65247 (payload_ prefix there: the input word is j1939_pgn65247_desired_operating_speed) / 61440 / 65266 / 65252 / 65263 byte 1 / 65270 byte 7 / 65271 / 65213 / 61441.
- CM550 65249: j1939_pgn65249_payload typed j1939_pgn65249_payload_t (copy CM848's 19 struct rows) at 0x803630; the row 0x803631 becomes the field row j1939_pgn65249_payload.retarder_control_method.
- CM848: EEC1 byte 1, EEC2 bytes 2 and 5-8, EBC1 bytes 1-5, VEP1 bytes 1-8.
