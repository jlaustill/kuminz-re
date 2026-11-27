# N2 judge notes (round 95)

## 0x34de0 lookupTableInterpolation (CM550) - disassembly read by the judge (m68k.py 0x34de0-0x34e98)
- one stack arg: movea.l (0xc,a7),a2 after 2 pushes. +2 long axis (0x34de8), axis word0 = byte count -> a1 = last point (0x34dec/ee),
  +0 word cached offset movea.w (sign-ext) (0x34df0), +6 word input (0x34df4), cmp.w (a3) / bcc = unsigned (0x34df8).
- below cache: cmp first point (0x2,a0) bcs -> low clamp a3=axis+2, d1=*a3 then up loop (skips dup first points).
- else search down subq #2 loop (0x34e06). above cache: cmp last (a1) bcc -> high clamp offset=byte count (0x34e3c/3e).
- up loop 0x34e24/26. write-back move.w a1,(a2) at 0x34e30 and 0x34e3e (ONLY field written).
- exact point -> y[off] (adda.l (0x8,a2),a1 = +8 long values pointer). else +0xc word (0x34e4a) nonzero -> y[off] step.
- interp: rising (bcs at 0x34e68 selects) mulu/divu 0x34e6e/76 + y[i]; falling 0x34e84/8c y[i]-delta. return d0.w.
- => 14-byte record: +0 word, +2 ptr, +6 word, +8 ptr, +0xc word. CONFIRMED investigator + describer.

## Calls (judge re-derived)
- abs refs 0x34de0: 42 jsr (0x34de0).l + 2 movea.l #0x34de0,a4 (0x14352 / 0x183da, 5 jsr (a4) each) = 52 calls; no bsr / pc-rel.
  Decompiled: 53 text hits = 52 calls + 1 plate-comment line (cm550_initializeEngineWarmupProtection). Investigator's "52" correct.
- every pea / register record of the 52 calls matches the investigator's record list (disassembled each site).
- A/D loop mc68k_processAnalogSensorChannels 0xb7bc: (-4,a6)=0x80a792 +14 per channel, sensor_state a3 0x80a2aa +22 until 0x80a4d0 (25);
  x_input = state+0x10 adc_raw_value, result -> +0xa unfiltered_value, only when +0xe fault_active_flag == 0. Sensor states are 25
  separate sensor_state_t rows -> 25 separate lookup rows follow the precedent (describer's array alternative not needed).

## Checks (check_all.py / table_summary.py / inner_refs.py / cited_names.py / cm848_cited.py)
- all 66 records: dumped +2 / +8 pointers = the cited e2m tables; rows-inside lists in the comments = the frozen rows exactly.
- all 89 tables: e2m record at the address = the cited one; size = gap to next e2m record = dump byte count (RAM tables).
  CBDDCT / CBDI2DCT header-less (first word 10000), word[16] by the 32-byte gap: OK.
- inner refs: 0x80004a+0xc (0xc7e6), 0x806ffe+2 (0x261aa, 0x2d8d0) = false positives (operand bytes). 0x806d3c read by
  cm550_processJ1939WetTankPressure (axis[1] as the raw override default) - fine. 0x6055a / 0x6056e = stage_4/6_values[4].
- every CM848 name cited exists at the cited address (frozen CM848 CSVs).

## Name findings
- 0x800192: AMEND -> engine_retarder_full_scale_torque_lookup. Lookup = JC6 table at the axis's LAST point = CM848's
  engine_retarder_full_scale_torque (stage_6_values[4]); CM550 also has JCRFRDTQ 'JCOMM REFERENCE RETARDER TORQUE' (0x8089a6,
  jcomm_reference_retarder_torque_...), a different calibration value -> "reference torque" would mislead.
- 0x80020e / 0x60640 / 0x6065c (CPCS03): AMEND. cm550_scaleByRatioSigned(a,b,c) = a*b/c; correction = ratio x (IMT - expected)/0x7800;
  units: CPCS03YA C/F at 1/2048, IMT 1/128 F, timing counts 0.1171875 deg: 2048*128*0.1171875 = 30720 = 0x7800 exactly, clamp +-170 = +-20 deg.
  => table = timing degrees per intake temperature degree, the inverse of "temperature_per_timing_degree".
- CPCS01 / CPCS03 x_input = engine_rpm_primary (0x11ec4-0x11ed6). cm550_initLoadTrendingSystem 0x124d2 also sets up 0x8001d4 / 0x8001f8 (lead).

## More checks
- CM848 0x55ef4 (disasm_func.py): r3 cache ptr / r4 input / r5 x / r6 y / r7 flags (bit0 signed x 0x55f18, bit1 signed y 0x56120, bit3 step 0x56108);
  first point first (0x55f28 / 0x56010) + dup skip (0x55f4c / 0x5602c), last point (0x55f64 / 0x5604c), cache with 0->1 guard (0x55f80 / 0x56078),
  one signed mullw / divw (0x5615c / 0x56168). CM550: cache point first, unsigned only, 2 slope paths, record arg. => COUNTERPART (cm550_ prefix). CONFIRMED.
- precedents: cm550_/cm848_secondOrderFilter, cm550_/cm848_exponentialMovingAverage exist. cm550_lookupTableInterpolation unused.
- prototype: one 4-byte arg (stack +4); every caller pushes one long, pops 4 (lea 0x14 after 5 calls). return d0.w. "type *" parses (ScriptUtils strips).
- local_variables_actual.csv: NOT read by any build script (grep scripts/*.sh *.java analyze.sh) -> cosmetic only.
- all set-up / caller functions named in the record comments = the functions holding the refs (ref_functions.py).
- all 29 existing values rows at the y pointers exist, sizes = dump counts (existing_values.py).
- every reused CM848 table = same Calterm block in CM848's e2m (1326/1327, 1324/1325, 13D0-13D6, 10BA/10BB, 1098-109B, 12E1/3/5, 13B2/3, A/D).
- 0x807176 = loop end of the 18-byte protection records (6 loops) + param-ID entry 10BA: renders with the table name (accepted CM848 quirk), was &load_breakpoint_table.
- preset_scan.py: no other move.w #2,(abs) record outside the proposals / typed 2-D records. Leads (0x8037c4 / 0x803984 / 0x803992 / 0x8039a0 / 0x803a68; 2-D halves 0x803896 / 0x8038ac / 0x8039ae) have no ROM ref -> rightly not proposed.
- uniqueness.py: final names (with amendments) unique; no abbreviations; none in the EEPROM window.

## DECISIONS (verdicts)
- 0x34de0 cm550_lookupTableInterpolation: AMENDED (comment only: "cached byte offset of the last point" ambiguous with the axis's last point).
- prototype: CONFIRMED.
- AMEND names: 0x800192 engine_retarder_full_scale_torque_lookup; 0x80020e / 0x60640 / 0x6065c cylinder_pressure_maintenance_timing_per_temperature_degree_*;
  0x8072f4 cylinder_balance_engine_speed_axis; 0x611d0 engine_protection_oil_pressure_limit_engine_speed_axis (shared axes named for their input, the repo's table grammar).
- AMEND comments only: 0x800102 ((0x800108) placement), 0x800184 / 0x6052a / 0x60566 / 0x801e30 (full scale torque), 0x80024e / 0x80025c / 0x80026a (axis name), 0x801a3e / 0x801a4c (axis name).
- all other 136 globals CONFIRMED.

## OUTPUT: verdicts.json (157: 140 CONFIRMED / 17 AMENDED) from make_verdicts.py; overall.txt. STATUS: ready to submit.
