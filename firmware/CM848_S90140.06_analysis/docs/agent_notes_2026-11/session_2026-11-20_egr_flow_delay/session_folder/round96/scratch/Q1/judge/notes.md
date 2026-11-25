# Q1 judge notes (round 96)

Started 2026-11-25. Directory was empty at start: fresh run.

## Schedules: both 19 calls verified from the frozen cpps (same PGN/interval/offset table as the task).

## 65265 CCVS CM550 0x31c84 -> cm550_buildPgn65265CruiseControlVehicleSpeedMessage: CONFIRMED (counterpart)
- asm 0x31c84-0x31ed0 matches the investigator byte for byte (a3=0x801ee2, a4=0x80bcce); 0xf3/0xf7 from 0x80bcd4 bit 6
  (no e2m record for bit 6 - J1939 SPN 70 is the field meaning); speed x412>>8 low byte first; send 0x801ed4.
- CM848 0x24178 gates on cal flags / datalink-source bits / 0xff forms: different code. Name unique.

## 61443 EEC2 CM550 0x32e4c: twin claim REJECTED -> counterpart cm550_buildPgn61443ElectronicEngineController2Message
- Same step order + constants, but the PEDAL SIGNAL differs: CM550 0x80aa82 = e2m 1047 +0 THROTTLE (commanded throttle);
  CM848 0x40b812 = e2m 81AA +0 ASG_Equivalent_Throttle (CM848 has its own 1047 record at 0x40a57a and does not use it).
- Gates differ in calibration word too: CM550 algorithm_enable_flags_13 bit 7 (DSIVSWUO user override), flags_5 bits 10/11
  (ADSATHOD / ADROTHOD) vs CM848 switch_input_datalink_source_bits_cal[0]&0x80, sensor_channel_held_value_enable_bits_cal[0]
  &0x2000 / &0x100 (no e2m record in CM848). Not identical code -> counterpart (describer agrees). CM848 keeps its name.

## 65247 EEC3 CM550 0x330c4 / CM848 0x25de8: TWIN confirmed
- asm identical: call friction (0xf99c / 0x20af0), (1102+6 >>8) store then +125 store again, 10E7+0 via stack temp
  low/high to +1/+2, low byte of 10E7+2 to +3, send. Same e2m records (1102 +6 / 10E7 +0 / 10E7 +2) in both.

## 61444 EEC1 (keep proposal): bodies differ (CM550 0xfb remote accelerator case + derate states listed -> 0xf8;
   CM848 0xf8 from torque_derate_fuel_source_code == final_fueling_state, no 0xfb). Stage 9b shared name.
## 65271 VEP1 CM550 0x342f0 / CM848 0x26cf0: TWIN confirmed (x*4+x, <<2, >>3 = x20>>3 vs mulli 20 / srwi 3; byte swap; +4; send)
## 61440 ERC1 CM550 0x338ea: counterpart, cm550_buildPgn61440ElectronicRetarderController1Message CONFIRMED (jump table 0x33936 decoded by hand)
## 65266 LFE CM550 0x33b40: standalone (no 0xfef2 in CM848), cm550_buildPgn65266FuelEconomyLiquidMessage CONFIRMED (Mongo name 'Fuel Economy (Liquid)')
## 65249 RC CM550 0x3407a: counterpart; 0x340b6 is move.w #1 (0x33fc), a store -> beq never taken; byte 19 init only. CONFIRMED
## Four new CM550 rows (entries.py: one abs ref each = pea in mc68k_initializeJ1939Datalink, no PC-relative entry):
   0x3229a-0x322ad (rts 0x322ac) / 0x32bbc-0x32c21 (rts 0x32c20) / 0x339fe-0x33a1d (rts 0x33a1c) / 0x34496-0x344cd (rts 0x344cc)
## Mongo: EBC1 4.1 972 / 4.3 971 / 4.5 970 / 4.7 969 / 5 973; EEC2 5 = SPN 29; IC1 (doc mislabelled 65270 'AMB') 6-7 = SPN 173;
   SHUTDN order 593 594 592 590 / 591 / 985 875 605 / 1081; AUXIO1 1.1 704 / 1.3 703 / 1.5 702 / 1.7 701.
## e2m CM550: E+2 bit 4 = DSRXSWSS remote PTO switch; E+2 bit 3 = DS20SWSS; E+28 bit 0 = LCWTSRLP; bit 2 = LCWFLP;
   E+1 bit 1 DSACILSS, bit 2 DSCHSWSS clutch, bit 3 DSBRSWSS brake, bits 5/6/7 idle inc / dec / test.
## Users of every payload byte (cpp owner scan + abs_refs): only each builder and its descriptor set-up, both firmwares.
## No e2m record at any proposed CM550 payload address.
## Decisions so far
- EEC2 0x32e4c: AMENDED -> cm550_buildPgn61443ElectronicEngineController2Message, counterpart (pedal signal 1047 vs 81AA).
  CM550 EEC2 global comments + CM848 0x3fada9 / 0x3fadac comments must name the prefixed builders.
- EEC1 0x32c76: keep the stage 9b shared name; AMEND the comment only (TSC1 'otherwise' imprecision; method versioning, not same steps).
- RC 0x3407a: name CONFIRMED, comment AMENDED (point 5's percent torque = byte 19, never written; the plate said each point is followed by it).
- EFL/P1 0x33164: comment AMENDED (bytes 3 and 7 written by no code; proposal said 'other bytes keep initializer values').
- EBC1 0x32bbc: comment AMENDED (counterpart name = cm848_buildPgn61441ElectronicBrakeController1Message, renamed in this batch).
- DM1 0x3229a: name CONFIRMED; comment AMENDED (CM848 counterpart renamed to cm848_broadcastPgn65226Dm1UntilFaultsClear).
- CM848 0x24d78 rename CONFIRMED (states PGN + gate; plate explains the final no-code DM1).
- CM848 VEP1 0x3faef2: comment AMENDED with the doubled-voltage finding (1/16 V input; RAM 0x00c0 = 12.0 V -> e0 01 = 24.0 V).
- RC struct 0x803630: CONFIRMED type j1939_pgn65249_payload_t (needs CM848's 19 rows copied to CM550 structure_definitions);
  0x803631 field row form (CM848 form; scripts skip dotted names for typing).
## Final tally (before output)
- Functions: 19 CM550 (AMENDED: 0x32c76 comment, 0x32e4c name+relation+comment, 0x3407a comment, 0x33164 comment, 0x3229a comment,
  0x32bbc comment; rest CONFIRMED). CM848: 0x2567c / 0x269f4 / 0x24d78 / 0x24028 CONFIRMED.
- Globals: 62; AMENDED comments: CM550 0x8034aa-0x8034b0 (7), 0x803630, 0x803631; CM848 0x3fada9, 0x3fadac, 0x3faef2. Rest CONFIRMED.
- skipped[] empty. No prototypes / enum members proposed.
