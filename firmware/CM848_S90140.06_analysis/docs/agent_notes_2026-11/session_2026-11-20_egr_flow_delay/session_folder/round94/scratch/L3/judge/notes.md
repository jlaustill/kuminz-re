# L3 judge notes (round 94)

Started fresh (judge folder was empty). Frozen CSVs: /home/linux/.claude/jobs/374b0424/tmp/w15/r94/frozen/
struct table_lookup_2d_arguments_t exists in frozen cm550 structure_definitions.csv (rows 924-932, 22 bytes).

## Call census (verified myself)
- abs_refs 0x35088: 27 refs (25 jsr abs.l + movea.l #0x35088,a5 at 0x1c674 / 0x1de6a). pcrel_scan.py: no bsr/bra/jsr(d16,pc)/lea(pc) to 0x35088, no copy of 0x00035088 in RAM / ext RAM / EEPROM dumps.
- a5 not reloaded between the jsr (a5) calls in 0x1c65e (4 calls) and 0x1de58 (6 calls): 35 calls, 19 records (4 typed).
## Sites disassembled (m68k.py) - all match both reports
- 0x8000aa: +6 <- 0x80ccf6, +0xe <- 0x80a320, -> (a5)=0x80a8f6 unless 0x803cac&8 (then 0x807a5a). init 0xc24c..0xc270 x 0x6010c y 0x600ee z 0x60138
- 0x8000c0: +6 <- 0x80a336, +0xe <- 0x80ccf6, add.w d2,(a5) 0x80a8f6 when 0x803cd4&0x4000 and none of bits 2/1/0x10 set in both 0x806004 and 0x806ac0. init 0xc246.. x 0x6124a y 0x6125e z 0x6126a
- 0x8000da: +6 <- (a4)=0x80ccf6, +0xe <- 0x80a3ba, -> (a2)=0x80a922. gate 0x803c96&0x20, 0x80d0c8==3, bits 4/8 of 0x806002 & 0x806abe (fault: 0x807abc or 0x808004 by rpm vs 0x807aba). init 0xc714 x 0x60384 y 0x603b0 z 0x603ba
- 0x8001d4: +6 0x8001da <- rpm 0x80ccf6, +0xe 0x8001e2 <- 0x80d32e; result d2 = desired; |d2 - calc (0x80aaa0)| vs 0x807cfa -> correction limited +-0xaa. init 0x124d6.. x 0x60678 y 0x60694 z 0x606a4
- 0x8001f8: +6 0x8001fe <- rpm, +0xe 0x800206 <- 0x80021e (0x80a320 + 0x80a3ba, or 0x80a320 if 0x807d12 != 0); d3 -> scaleByRatio(0x80021e, d3, 0x400) -> 0x80aaa0 capped 0xbb80. init x 0x605ce y 0x605ea z 0x605f2
- 0x800222: +6 0x800228 <- 0x80ccf4, +0xe 0x800230 <- 0x8091e8; clamp 0..100 -> 0x8092e2; 0x80922e = 1 if gain < 100 (or other conditions). init 0x1348e.. x 0x80734c y 0x807352 z 0x807358
- 0x800238: +6 0x80023e <- 0x80ccf4, +0xe 0x800246 <- 0x8091e8; result - 10000 -> 0x8092e0; 0x809218 - that -> 0x80927a. init 0x134bc.. x 0x807338 y 0x80733e z 0x807344
- 0x80d372: init 0x1ddbe.. x 0x6086e y 0x6089a z 0x608a4; users 0x142dc (x=arg, y=400), 0x1cb92 (x=arg1, y=arg2), 0x1de58 (x=rpm, y=0x80aa82|0x608a0, 0, 400), 0x2597c (x=0x80daee, y=400)
- 0x80d388: x 0x6094c y 0x60978 z 0x60982; users 0x1cb8c, 0x1df44.., 0x259b0 (x=0x80daee y=400) gated by 0x80d340 < 0x4000
- 0x8005c2 / 0x8005d8: 0x178b0: x=0x80d0ac, y=0x807ef4+(0x80d0b6); -> (a4)=0x80d09c; alpha 0x80a8f8 (0x4000 steady only / 0 transient only). init 0x17ef8: 0x8005c2 = 0x60a2a/0x60a52/0x60a74; 0x8005d8 = 0x60cd4/0x60cfc/0x60d1e
- 0x8006b8 / 0x8006ce: 0x1c65e: skip if 0x803c9c&0x100 ((a2)=0x80d344 <- 0x803f3e); y = 0x80d32e or 1-D 0x8006aa(0x80d32e) when 0x80d706 == 1; x = 0x80ccf6; alpha blend -> 0x80d344. init 0x1c7a8 same pointers as crank pair.
- 0x8006ea: init 0x1cdf8 x 0x6086e y 0x6089a z 0x608a4, +0xe = 400 (0x1ce14). 0x1cc72: lookup at 0x1cd5e (-> 0x80d36a, only when 0x803cb8&0x200 clear) and at 0x1cdbc (-> 0x80d370, when 0x803cac&0x10 set, regardless of 0x803cb8). TWO outputs.
- 0x800700: init 0x1cdfe x 0x6124a y 0x6125e z 0x6126a; 0x1cc72: when 0x803cb8&0x200 clear and 0x803cd4&0x8000 and no faults: +6 <- 0x80a336, +0xe <- rpm; d2 added to 0x80d36c, 0x80d368, 0x80d36a.
## Dump + e2m + rows (records.py) - all 15 match both reports
- pointer values in the dumps = the initializer constants; e2m at each pointer = the records both name (AFFLLM 104E/104D/104F, FLCD 81EE/81EF/81F0, AT 10A1/10A2/10A3, CPDS 1088/1089/108A, CPCS02 11D0/11D1/11D2, CBDSC 822B/822C/822D, CBDC 8228/8229/822A, 4DTA01 103D/103C/103E, 4DTA00 1040/103F/1041, 5DFL01 1055/1054/1056, 5DFL00 1058/1057/1059)
- rows inside: exactly the investigator's lists (0x8000aa 8 rows incl base; 0x8000c0 14; 0x8000da 8; 0x8001d4 8; 0x8001f8 8; 0x800222 8 (no base row); 0x800238 7; 0x80d372 2; 0x80d388 2; 0x8005c2/0x8005d8/0x8006b8/0x8006ce/0x8006ea/0x800700 none). Edges: 0x8006e6 torque_curve_feature_bitmask and 0x800716 hsg_integrator_fuel_output lie outside.
- all enable bit names in comments verified in structure_definitions (flags_12 bit3/bit4, flags_32 bit14/15, flags_1 bit5, flags_3 bit11, flags_4 bit8, flags_18 bit9). ENGINE_STATE 3 = RUNNING.
- 5DFL01ZA/5DFL00ZA scale .0679348 offset -800 (11776 counts): cm550_subtractAndClampValue adds 0xd200 and clamps 0..0x1700 -> "stored plus 800" right. CBDCAT offset -10000 -> addi #0xd8f0 right.
- cylinder pressure correction -> increment_timing_value_output_by_cylinder_pressure_maintenanc_20_20 (timing). scaleByRatio = a*b/c.
## Reference sweeps (range_refs.py) - clean
- every ROM ref into each of the 15 records = its initializer + its lookup sites (+6 / +0xe / base). 0x8000da: the 0x227b8 / 0x22828 / 0x228ca / 0x2293a hits are ori.l #0xec0000 / #0xeb0000 J1939 IDs (PGN 60416 / 60160), not addresses.
- base registers (a2..a5) hold the records only for (0x6,aN) / (0xe,aN) / move.l aN,-(a7): checked tails of 0x142d4 / 0x178b0 / 0x1de58 / 0x2595a.
- removed rows' names: only in global_variables.csv (+ cpp); function_definitions 0x142d4 parameter comment names fuel_table_primary_descriptor (text to update); DCMNLDTB in function_renames.csv is the Calterm mnemonic in a plate comment (fine).
## Duty cycle axes - PROVEN
- CM550 dump 0x807d1e: 18, 0, 8000 .. 22400 (9) ; 0x807d32: 14, 0 .. 10000 (7); 0x807d42 = 10DF JCFCLD06. Readers only 0xae5c (8 compares, d2 1..8), 0xae90 (6 compares), 0xadd2 (7th load value -> duty_cycle_monitor_load_ratio when duty_cycle_monitor_full_throttle_fueling == no_load_fuel_quantity). Other hits 0x35c7c.. = parameter_id_table block starts (2 equal copies per entry).
- CM848 ROM 0x5c2c0: 18 + 9 speeds (0..28800) word[10]; 0x5c2d4: 22 + 11 loads (0..10000) word[12]; next row 0x5c2ec (10B4). cpp 65814 / 65828 / 65791 only.
## Cylinder balancing RAM tables - PROVEN (sizes from dump counts + block starts at ROM 0x388a4..)
- 0x807338 (4,3200,15200) / 0x80733e (4,0,7009) / 0x807344 (10000 x4) / 0x80734c (4,7600,16000) / 0x807352 (4,421,1122) / 0x807358 (100,0,0,0); 0x807360 = 822E. Refs only init 0x13496..0x134e0.
- CM848 81B1/81B2/81B3: different block numbers, y scale 0.0679348 (CM550 0.0713), grid scale 1/128 (CM550 0.01) -> "This is CM848's ..." is loose; amend wording.
## Leads 0x8036e4 / 0x8036fe / 0x803896 / 0x8038ac / 0x8039ae: no ROM reference at all -> correctly not proposed.
## Names (uniqueness grep: all 0 hits in CM550 globals/functions; CM848 only the 3 stop compensation table names = the cited counterparts)
- CM848 uses the same blocks/mnemonics for 104D/104E/104F (air_fuel_control_fuel_limit_*), 1056/1059 (four_dimensional_fueling_*), 103D/103E/1040/1041 (four_dimensional_injection_timing_map_a/_b_*), 105A +2 FST0MXFL = Tau_0_Throttle_100_Fueling (= low hp curve), 105A +8 FSMTFLNP = Throttle_100_Fueling_No_PP (ESP tau 0), 111D/111E (same scale).
- 0x8006ea: both outputs are tau 0 / low hp curve 100 percent fuelings -> investigator's name holds (CONFIRM); describer's alternative also valid but not needed.
- 0x8001f8: investigator's compression_ratio_raised_to_polytropic_exponent_lookup clearer than describer's -> CONFIRM.
- 0x800700: full_fueling_* parallels its enable bit full_fueling_coolant_temperature_adjustment_enable -> CONFIRM.
- Decompile: 35 cm550_tableLookup2D calls on the 19 records (lines 544-554, 1735 .. 26448, 27513, 27591).
- AMEND comments only: 0x80734c / 0x807352 / 0x807358 ("This is CM848's ..." -> same Calterm table, CM848 block 81B1-81B3, y 0.0679 vs 0.0713, grid 1/128 vs 0.01).
## More checks
- cm550_tableLookup2D (0x35088..0x35222) writes only (a2) +0 and (0x8,a2) +8 -> 0x8006ea's y input 400 is written only by its initializer.
- cylinder pressure: calculated = scaleByRatio(p, CR^n, 0x400) [<=48000], then if fss_offset_corrected_soi.. (0x80aaa6) > 0: x (1 + fss x CPCS01 / 0x4444) (1-D record 0x8001ea = 108B / 108C 'ratio of cyl. press. to compression press. per degree'), <=48000 again -> investigator's formula is only step 1 -> amend sentence.
- 0x8000da gate: lookup when neither bit 2 nor bit 3 is (set in 0x806002 and set in 0x806abe); proposal wording "not both set and confirmed" ambiguous -> amend sentence.
- no other CSV anchors an address inside any new row (CM550 function_definitions rows 122 / 188 are parameter comments; CM848 none).
## VERDICTS
CONFIRMED: 0x8000aa 0x8000c0 0x8001d4 0x800222 0x800238 0x80d372 0x80d388 0x8005c2 0x8005d8 0x8006b8 0x8006ce 0x8006ea 0x800700 0x807d1e 0x807d32 CM848 0x5c2c0 0x5c2d4, 0x807338 0x80733e 0x807344 0x80734c
AMENDED (comment only): 0x8000da (gate wording), 0x8001f8 (pressure formula), 0x807352 / 0x807358 (CM848 scales differ)
REFUTED: none. skipped[] empty; 5 unreferenced record-shaped blocks stay out.
