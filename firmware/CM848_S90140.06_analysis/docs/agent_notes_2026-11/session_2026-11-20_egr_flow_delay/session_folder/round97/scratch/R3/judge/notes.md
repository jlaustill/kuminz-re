# R3 judge notes (round 97)

Started 2026-11-25. No earlier run (scratch dir was empty).
74 investigator proposals (69 family rows + 5 new rows: 0x80003c, 0x80003e, 0x803d44, 0x80053c, 0x803af2), 6 skipped (0x8001a6, 0x80053e, 0x8087f0/f2/fa/fc).

## Findings
- check_unique.py: all 74 proposed names are unique in CM550 global_variables / function_renames and among the proposals.
- ANC fuel 0xb2aa / timing 0xb3d0 / speed 0xb4f2 disassembled: the three-step pattern holds (inhibit on ESFT01AC > NZxxACTR,
  conditions ASANENF / IH / speed or coolant / ESFT01AC <= ACTR / ESFT02AC >= FTTR, override ASANODFG, hold countdown,
  ramp out). fuel rpm test bcs (minimum), speed rpm test BHI 0xb564 (maximum, against its text), timing coolant bls.
  0x80003c/0x80003e/0x800042/0x800046 roles CONFIRMED (word, tst/subq/move.w). 0xb4ce writes 0x80a29e before the cap.
  0xb666 ASANENF=1, NZESLM=0x803f40. 0xb614/0xb63e lookup set-ups.
- 0xb210 calculateFilteredEngineAcceleration: ESFT01MN 0x807a48 (bge) / ESFT01MX 0x807a46 (ble) signed clamps; CM848 twin
  0x38760 uses engine_acceleration_first_stage_clamp_minimum / _maximum the same way -> CONFIRMED reuse.
- 0x807a4c extra refs 0x3c2e.. / 0x2ce22..: cmpa.l / movea.l bound of the RAM clear loop 0x800000-0x807a4b (clr.l (a1)+), not reads.
- find_range_refs 0x8079f0-0x807a60: only parameter_id_table entries (0x355cc-0x385c0) besides the ANC / filter code; no
  reader of 0x807a00 / 02 / 1c / 1e / 20 / 40. RAM dump: only 0x800066 / 0x80006e / 0x803af2 point into the area.
- 0x803af2: RAM {0x00807a1c, 0x80000000} = ema_filter_state_t {coefficient word*, accumulator dword} (8 bytes, no row
  0x803a00-0x803aff, next row 0x803b00); a second_order_filter_state_t would need a 2nd pointer at +4. No ROM pointer to
  it (find_range_refs 0x803a80-0x803b0a: only 0x803b08). CONFIRM (medium).
- aux driver read-back: 0x800168 (bit 1, 0xdbae btst #1,(1,a5) -> word 0x806010 bit 0x2000 recovery, a4 = 0x807c02),
  0x800170 (bit 6, 0xe336 btst #6 -> 0x806012 bit 0x20), 0x800172 (bit 3, 0xe500 btst #3 -> 0x806012 bit 0x80); all
  5 byte accesses, reset on mismatch and in 0xe780. e2m 000E +35: bit1 DRR2FB/DSCD01FB, bit3 DRR7FB/DSACFB, bit6 DRR4FB;
  driver group 26 has DRCD01DR (cold start aid 1) for bit 1 but only DREA07 (relay 7) for bit 3 -> the investigator's
  cold_start_aid_1 / relay_4 / relay_7 split is principled; high_recovery = commanded-on, as sibling 0x80016a. CONFIRM.
- sync pulse 0x1025c: one caller (0x1a988, arg 0 = main), before the period store at 0x1a9e8, so *0x8001ac = previous
  period; 0x1011c slot 0 = period under test - *pointer; 0x101b8 reads pointer-4 / pointer-8. 0x8001a4 main threshold
  (move.l 0x102c4 / 0x1035e / 0x103a8), 0x8001a0 backup (0x10306 / 0x10370 / 0x103b2): all long. Existing sibling name
  main_engine_position_sensor_period (0x80d04a) -> investigator's main_/backup_engine_position_sensor_* fit. 0x8001a6: no
  reference (low word of dword 0x8001a4) -> keep skipped, delete the row. Pointer type spelled "dword *" like "word *".
- switch sampler 0x14fca (a4 = 0x80bcce, a5 = 0x80bcd4): 0x803d44 tst.w 0x1538a / beq.w 0x15870 gates the PTO + cruise
  decode (0x152e6 tst has no branch); 0x80bcdf move.b x3 under flags_16 bits 12/10/8; 0x80053e clr 0x1543c / =1 when
  0x80aa02 == 3 (0x15442, its only ref; 117D +3E has no v64t6_s record, other e2m families put unrelated records there)
  -> keep skipped; 0x80053c tst.b 0x15460 / move.b 0x15494 = PTO on bit of the previous pass (edge) -> CONFIRM, but the
  comment says "sampled_road_speed" (no such row; 0x80a9d0 is sampled_road_speed_after_it_has_been_filtered_0_255_9961)
  -> amend the comment; 0x800544 / 0x800546 +1 per pass, cap 25, at 25 set -> coast (CRSEACSW 0) / accelerate; resume ->
  accelerate / coast -> hold counters CONFIRM; 0x803d42 13 tst.w, 0 = set/coast resume/accelerate as the record FALSE.
- AFC / alpha: 0xc1a8 AFFLMAN -> air_fuel_control_fuel_limit under flags_12 bit 0x8; 0xc2be: final_fueling_state == 16
  (FUELING_STATE_AIR_FUEL_CONTROL_DERATE) -> 0x80de68 = AFICTA, 0x80a906 = 1, else 0x80de68 = 0; 0xc2ee adds 0x80de68
  ext.l (signed) floor 0 -> i16 CONFIRM; 0xc504 identical to CM848 twin body (alpha_air_fuel_control_timer /
  _timer_active_flag / _state_detected_flag / air_fuel_control_alpha_timeout); 0xc342-0xc36e preset at engine_state 1/2/6;
  0xc658 clears both latches; 0x1dd18 clr 0x80a912. All CONFIRM (CM848 rows 0x5be60 / 0x3fa0dc / 0x40a176 / 0x40a180 /
  0x3feff2 exist with these names).
- RAM values: rows >= 0x8091c2 are in extended_ram.bin (offset addr-0x809242): 0x80a290 21200, 0x80a29e 495, 0x80a2a8 1,
  0x80a912 1, 0x80a914 19500, 0x80aa3e 742, 0x80aa58 742, 0x80aa60 1325, 0x80dc82 25600, 0x80dc84 25600, 0x80dc32 6.
- 0x807f6a: 0x1acb0 move.w zero-extended, rate ext.l > it -> timer 0x80d2b0 up to 0x807f68 else clr -> CONFIRM.
- no-code blocks (find_range_refs): 1186 0x807c60-0x807ca0, 106D 0x808020-0x808050 (HSG gains only, not 0x80802e), 109D,
  818B, 1187 0x80aa30-0x80aa64, 106C, 1197: only parameter_id_table entries -> record names; CM848 rows for the same
  block/offset/description exist (e2m_block_addresses) -> CONFIRM all reuses.
- 0x80dc82: CM848 8B89 (not in its dumped table) lines up at three offsets: +0 0x40b5bc road_speed_governor_reference_speed,
  +6 Gear_Down_Active 0x40b5c2 drivetrain_gear_range, +8 RSG_HPCR_Leak_Reference_Speed 0x40b5c4 fault_vehicle_speed_limit;
  CRMXVSRF text identical to 8B89 +0 -> CONFIRM reuse (medium).
- 0x80dc30: selector 0x2dcb0 writes it 5x (fuel_demand_selected 0x80ded2 or closed_loop_fuel_demand_output 0x80dc00),
  0xf84a copies it to JCDRIDFL 0x80da36 when power_take_off_or_user_fueling_state (a5 = 0x80dc32) is 6 or 4. CM550
  pairs are <x>_fueling / <x>_fueling_state (final_fueling, requested_fueling, adjusted_user_fueling) -> AMEND to
  power_take_off_or_user_fueling (unique).
- 0x807a00 / 0x807a02: no code; CM848's A/C clutch cutout family is air_conditioning_<trigger>_cutout_* (0x40869a,
  0x4086ba, 0x4086bc); "air_conditioning_disable_vehicle_acceleration_threshold" misparses as disabling vehicle
  acceleration -> AMEND to air_conditioning_vehicle_acceleration_cutout_threshold / _cutout_duration (unique).
- 0x8087f0/f2/fa/fc: PPCVTB Z table 0x8086f2-0x808895 (X byte count 20 at 0x8086b0, Y byte count 42 at 0x8086c6, 10 x 21
  = 210 words, next 12D4 at 0x808896, runs of equal words), only parameter_id_table refs -> keep skipped.
- 0x80053c comment says "sampled_road_speed" = prefix of the real row name; not an error -> CONFIRM unchanged.
- FINAL: 71 CONFIRMED, 3 AMENDED (0x807a00, 0x807a02, 0x80dc30); all 6 skips stay (0x8001a6 must be deleted when 0x8001a4
  becomes dword).
