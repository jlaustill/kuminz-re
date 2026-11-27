# R2 judge notes (round 97)

Started 2026-11-25. No earlier judge run found (directory was empty).

## Plan
- 100 family rows + 24 new CM550 rows + 1 CM848 row (0x3fa8a4).
- Re-derive from disassembly of runHighSpeedGovernorPid 0x1ce7c, presetHighSpeedGovernorIntegrator 0x1d252,
  initializeHighSpeedGovernorGainSet, selectHighSpeedGovernorGainSet, selectEngineSpeedLimit 0x1d5a0,
  initializeEngineSpeedLimitDefaults 0x1d94e, ASG 0xc962.. 0xd5xx, torque curve 0xfb26 / 0xfaa6.

## Findings
### runHighSpeedGovernorPid 0x1ce7c (my disassembly dis_1ce7c.txt) - all HSG 1060 / 1061 rows CONFIRMED
- 0x1ce98 copies (a2)=0x80d626 to 0x80071c BEFORE the update -> 0x80071c = filtered error previous (i16: ext.l at 0x1d138).
- error = a5(zero-ext 0x80d646 - zero-ext 0x80d60a, ext.l 0x80803e, 0x200) (0x35076 = a*b/c) -> 0x80803e i16 gain ok.
- 0x808040 cmp.w + ble / 0x808042 cmp.w + bge: signed clamps of 0x80d626; accumulator 0x80d63a reload. i16 ok.
- reset: (zero-ext 0x80d646 + ext.l 0x80804a) < zero-ext 0x80ccf6 AND 0x80a8f0 < 0x80804c (bcc unsigned) AND 0x80a8f2 == 12
  -> move.w 0x808048 -> 0x800716 (HIGH word), clr.w 0x800718, clr.w 0x80d626, 0x80d63a = 0x80000000, rts.
- 0x808058 / 0x80805a / 0x80805c tst.w enables of derivative / proportional / integral adjust (caps 0xffff / 0x1e00 / 0x7ae).
- 0x1d004 move.w (a4)=0x80d63e -> 0x80071a BEFORE the proportional adjustment -> previous adjusted gain (word, zero-ext 0x1d1a2).
- P = a5(ext 0x80d626, zext 0x80d63e, 0x3c0) clamp 0x808062 (ble) / 0x808064 (bge) -> 0x80d628. i16.
- D = a5(ext err - ext 0x80071c, zext 0x80d640, 0xf0) clamp 0x80805e / 0x808060 -> 0x80d62a (ext.l read 0x1d1fa). i16.
- I: (ext err << 16) * zext 0x80d642 / 0x3c00 >> 16 added (add.l) to (a3)=0x800716; minus a5(err, 0x80d63e-0x80071a, 0x3c0);
  clamp ext.l 0x808044 (bgt) / 0x808046 (ble): signed long -> i32 ok; low word (2,a3) -> 0x80d62c.
- sum ext 0x80d628 + ext 0x80d62a + ext 0x80d62c, clamp zext 0x808052 (ble) / zext 0x808054 (bge) -> 0x80d624 (word ok).
- CM848 twin body (cm848_hsg_pid.txt) has the same steps with the CM848 names used by the proposals.
### preset / initialize / selectHighSpeedGovernorGainSet (dis_1d252.txt) - CONFIRMED
- preset: skip when final_fueling_state (0x80d330) == 12; integ = zext final_fueling - max(P,0) (+ min(P, 0x808066) when P>0,
  cmp.w + bge signed); clamp ext.l (a0)=0x808050 (bge) max / ext.l (a1)=0x80804e (ble) min; low word -> 0x80d62c; 0x80d626 -> 0x80071c.
- initialize: 0x80d62e=0x808036, 0x80d630=0x80803a, 0x80d632=0x808038, 0x80d634=0x80803c, 0x80d61a=16, 0x80d62c=0x808044.
- select: gated by algorithm_enable_flags_18_cal bit 0 (else rts, no base copy); 0x80074a = 0x800748*20; transient when
  final_fueling_state_prev (0x80d33c) != 12 and ext.l 0x80a296 > zext 0x808118 (signed cmp.l) and code != 17:
  0x80d62e=0x808136, Ki=0x808134, Kd=0x808130, filter=0x808132, code 17, counter cleared.
  Else when timer > 0x80811a (bls): timer = 0x80811a; alternate set 0x80d61c/1e/20/22 = low (0x80d658 < 0x808126 bcc) /
  high (> 0x80811c bls) / base; then working set if 0x80d614 != 0 (0x80d618 Kp, 0x80d616 Ki, 0x80d610 Kd, 0x80d612 filter,
  code = 0x80d614) else low code 18 / high code 19 / base code 16 into the active set. Counter++ each enabled call.
  Gain set layout +0 Kd, +2 filter, +4 Ki, +6 Kp for 0x80811e / 0x808128 / 0x808130 (= CM848 high_speed_governor_gain_set_t).
### selectEngineSpeedLimit / initializeEngineSpeedLimitDefaults (dis_1d5a0.txt) - CONFIRMED
- a2=0x80d648 lowest, a3=0x80d644 source, a4=0x80d654 ramped, a5=0x80d646 applied.
- high idle override (0x80da54==1): applied = 0x8081fa, source 8, droop flag 0, jump to 0x1d92e (no 0x80d658 copy).
- sources: 5 fault derate 0x80d288, 6 reference 0x80d64e (= *(0x80d666)), 9 datalink speed limit 0x80da5a (mode 3),
  4 0x80a9d8, 3 0x80a290, 2 0x80a9d6 (mode 0x803f42 0/1), droop cap 0x80d65a <- 0x80a9d6 (mode 2/3, code 2 in 0x80d65e),
  7 0x80d64c, 11 power take-off 0x80dc2c, 10 0x80d65c (clears slope). cap 0x808144 max; floor 0x808142 (bcc) unless source 9
  (then LSG breakpoint + 0x807a54).
- ramp: ramped += 0x808138 while below; follows decreases at once.
- source 9 on J1939 (0x80da68==1) or 11: applied = ramped, droop flag 0, skip cap.
- else droop flag 1; slope recomputed when 0x80074c / 0x80a9e0 / alpha change: 0x80d36e = 100% fuel at the reference (0x1cb76),
  0x80db1e = friction(0x80d650) + coolant correction; slope = clampedDivide((0x80d650-0x80d64e)*0x1111, 0x80d36e-0x80db1e, 0x7fd6, 0x8000)
  -> 0x80d652; tst.w + ble -> slope 0, applied = ramped, flag 0. Droop fuel = 0x80d62c clamped 0x80813e (bls) / 0x808140 (bcc);
  0x80d64a = min(0xffff, ramped + slope*(0x80d36c - fuel)/0x1111); applied = max(0x80d64a, ramped); then cap 0x80d65a (bls)
  (in both the droop and the slope<=0 branch). End: 0x80d658 = (a2); (a2) = 0x803f40; 0x80d660 = cap; cap = 0xffff; 0x80d664 = source.
- initialize: 0x80d666 = #0x803ba0, 0x80d654 = *0x803ba0, 0x80d644 = 6, 0x80d664 = 6, 0x80d650 = 0x803f46, ...
### ASG (dis_c962.txt, dis_d0e2.txt) - CONFIRMED (names = CM848 names of the same records; CM848 body cm848_asg.txt has the same steps)
- preset on state change: (0x400 - zext 0x80a992) * (final_fueling - 0x8091de) << 7 / ((Ki1+Ki2) * zext 0x80a994) + rpm -> 0x80a972;
  0x80a988 = 0x80a972 << 16 (EMA accumulator). Else EMA of 0x80a990 (0x34f8a, state 0x80a984); state 7 -> bsr 0xc8a0 (blend).
- X1 0x80a978 = (0x80a972 - rpm) clamp +-32000; previous X1 in d3.
- external reset (0x80a9a0 == 1): 0x80a974=1, d3=0x80a932, 0x8000fa=0x80a934 (low word 0), 0x8000f4=0x80a936, d4=0x80a938, d2=0x80a93a, d5=0x80a93c.
- normal (0x800100 == final_fueling and same state): d4/d2/d5 = 0x80a97c/7e/80, 0x80a974 = 0; else reseed + 0x80a974 = 1.
- 0x80a970 = rpm - 0x8000f4 (+-8000); 0x80a96e = X1 - d3 (+-32000, signed); PI sum (Kp1+Ki1)*0x80a96e + (Ki1+Ki2)*d3 - Kp2*0x80a970 >> 9.
- derivative (Kd1*0x80a96e - Kd2*0x80a970) >> 13, dead band 0x807abe, limit 0x807ac2 -> 0x80a96c (ext.l read).
- X4 0x80a97c = ext 0x80a96c * zext 0x80a994 >> 10 + d4 * 0x807ac0 >> 10 (+-0x1700); integrator update uses zext 0x80a992;
  X2 0x80a97a = high word 0x8000fa; X5 0x80a97e = X2 + X4 (+-0x1700 signed); X6 0x80a980 = (X5 c1 - d2 c2 + d5 c3) >> 8.
- fueling 0x800100 = X6 + 0x800112 clamp 0x80a99c (blt) / 0x80a99e (bgt) signed -> 0x80a976.
- 0xd0e2: gate 0x80a93e != 0 and 0x80a98e == 0: state 30; 0x80a940->0x80a990, 0x80a942->0x80a992, 0x80a944->0x80a994, gain set 0x80a95a,
  filter coef 0x80a946, 0x80a94e..58 -> 0x80a932..3c, 0x80a94c -> 0x80a9a0, 0x80a948 -> 0x80a99c, 0x80a94a -> 0x80a99e.
- 0xd1a4 (TSC1 speed mode): 0x80a9a0 = 0, gains 0x400 / 0x400, limits from 0x807b8e / 0x807b90.
- 0xd2be: 0x80a9a2 rewritten only when 0x803d5a < 2, no-load + 0x807ac8 > final_fueling and throttle 0x80aa82 == 0:
  flags27 bit 3 set -> default; else switch 0x80bcd1 bit 1 on -> NOT default (0->1, 1->0), off -> default. Otherwise keeps its value.
  0 -> set 1 pointers 0x80a9ac/b0, 1 -> set 2 0x80a9b4/b8 into 0x80a9a4/a6; 0x80a98c = min + (max-min)*throttle/400.
- 0xd3e6: droop 0x80a99a = lookup 0x800144 (select 1) / 0x800136 (select 0) at 0x80a990; u = (Ki1+Ki2 of 0x807be0)*droop;
  0x80a996 = 0 if u >= 0x2655879 else ((K-u)>>1)/((K+u)>>11); 0x80a998 = (g1+0x400)>>1; copied to 0x80a992 / 0x80a994.
- 0xd4ae: throttle mode (state 7) limits 0x807bdc / 0x807bde, 0x80a9a0 = 0. 0xd584: 0x80a990 = 0x80a98c, state 7.
### Torque curve (dis_faa6.txt, dis_fb26.txt) - 0x800182 / CM848 0x3fa8a4 CONFIRMED name, comment amended
- 0xfb26: 0x800182 = 0x80d648 if source 2/4/5/1 else 0x80d64e; cmp.w 0x808174 (JCT0P5IN 'WHEN DERATE_SPEED < THIS POINT') + bcc
  -> 0xfaa6 with point 4 fueling 0x80816c, else point 5 fueling 0x80816e. 0xfaa6: slope == 0 -> point 2 speed 0x80da3a = 0x800182.
- CM848 0x20d10 / 0x20c64 same; sth 0x20e14 / lhz 0x20c7c (word). JCT0P5IN calls the value DERATE_SPEED -> investigator's name better
  than the describer's '..._governor_breakpoint_speed'. 0x800182 comment cites the OLD CM848 name -> amend to the new one.
### Dump values (dump_values.py) all match the comments (e.g. 0x800716 = 0x0000019b, 0x80d624 = 1776, 0x80d65a = 24000).
### e2m records: every proposal's block / offset / mnemonic checked with e2m_block_addresses.py (CM550 and CM848 blocks 1060 1061 1062 1063
  1290 128F 13AB 13B4 109C 107A 107C 1170 12EA 1262 1281 000E 1387); CM848 names exist at the cited addresses.
### Verdict summary (judge)
- 124 CM550 rows + CM848 0x3fa8a4: all names CONFIRMED (unique: investigator check_proposals.py re-run + my grep against function
  names / struct names); types CONFIRMED (i32 0x800716, word 0x80a996 / 0x80a942, i16 0x80d652; 0x80d62c stays word - split evidence:
  ext.l in the PID sum vs unsigned cmp.w in selectEngineSpeedLimit, round 94 chose word).
- AMENDED comments: 0x800182 (cited the CM848 counterpart by its old name torque_limit_working_reference, renamed in this batch);
  0x80a9a2 ('toggles it' is imprecise: 0xd2be writes the opposite of the default while the switch is on, the default while it is off,
  only when default < 2, throttle 0 and final_fueling < no-load + offset; otherwise the value is kept).
- Describer differences settled: 0x800182 derate (JCT0P5IN says DERATE_SPEED) over breakpoint; spare words _0/_1 follow SWHSG_00/_01;
  0x808506 record-only name accepted (no CM848 record); 0x80a9a2 _select (precedent both spellings); flat rows for 0x80d644 / 0x80d646 /
  0x808120 / 0x80812a / 0x808132 (CM550 lacks engine_speed_limit_arbitration_t / high_speed_governor_gain_set_t: struct follow-up).
- Stale mentions (stale_mentions.py): the investigator's 28 CM550 rows + 3 functions, PLUS CM848 0x5c356 / 0x5c358 and function 0x20c64
  (mention torque_limit_working_reference), and CM550 all_speed_governor_gain_set_t field comments (asg_error_difference /
  asg_feedback_difference_term / asg_droop_gain_2, short forms).
- CM550 selectHighSpeedGovernorGainSet: with scheduling disabled it returns; CM848 copies the base set (verified) - twin differs in a branch.
- FINAL: 123 CONFIRMED + 2 AMENDED (0x800182 comment, 0x80a9a2 comment) of 125 global verdicts (124 CM550 + CM848 0x3fa8a4). No REFUTED.
