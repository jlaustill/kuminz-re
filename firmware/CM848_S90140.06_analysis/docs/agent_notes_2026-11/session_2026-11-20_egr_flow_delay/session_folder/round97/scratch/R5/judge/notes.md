# R5 judge notes (round 97)
(started 2026-11-25; no earlier judge run found)

## Status
- read investigator + describer notes
## Verified so far
- e2m: all 50 listed rows resolve to the claimed blocks/offsets (e2m_rows.py); 10B1 +10 EPPKSO 0x80d28a, +16 EPRPDC 0x80d290, 10B3 +4 EPSOTF 0x8058d2 have no rows; 10DA logs resolve as claimed
- table code refs (range_refs.py): config 0x807032 base only (8 code refs), state 0x80d0dc base only (9), history base (5) + 0x8057c2 (0x190a2) + 0x80581a (0x19880); fault logs only from 0x1873e (0x8056c0 hits are false positives: andi.l #0x80 / sne d0)
- flat rows inside: config 158, state 153, history 99 (matches investigator)
- CM848 scheduler 0x507c44 tasks: 0 0x50802c, 1 0x508ee0 + 0x5084b4, 2 0x509540, 3 0x50860c + 0x509278, 4 0x508898; examine-before-cranking 0x508130 each enabled pass
- CM550 scheduler 0x18620: jump table 0x18646 (0x18a26 / 0x18cb6 / 0x19702 / 0x18e0c+0x1952c / 0x18fcc); disabled: no index advance
- 0x18a26 vs 0x50802c: same steps / masks 0x101 0x402 / 0xffff / selects; only table extent (9 vs 1) + state stride (46 vs 62) differ
- precedent: twin despite different table sizes (findTsc1SourceConfiguration 5 vs 10, registerJ1939ReceiveHandler 16 vs 17); shared struct name with per-firmware field types (tsc1_source_configuration_t data_link CONTROL_NETWORK vs word)
- RAM dump: state records hold exactly the init pointers (min/max/rpm ptr = config +0xa/+0xc/+0xe; ch3 0x80dabe/0/0x80dac0; logs as init); 0x80d290 = 0x1838 = 21200-15000 (span); task index 4; current ptrs at table ends
- 45 absorbed rows: field mapping (field_map.py) = investigator's paths, all correct
- 10B1 +0/+2/+10/+16 and 10B3 +4 CM848 names confirmed (e2m tool) -> reuse names (no _cal; 0x8058d2 outside EEPROM image)
- 0x80d28a refs: 0x18aca (a4) / or.w 0x1923c 0x19252; 0x80d290: 0x18f20 mulu / 0x18f80 write; 0x8058d2: cmpi 0x1926c / addq 0x19274; 0x800622/626/62a long only; 0x80060e word only
- 0x30b04: no 4-byte ref in ROM / RAM / extended RAM, no pc-relative ref (find_ref.py); 0x30b0e rts is referenced at 0x28776
- twins checked in asm: 0x186ae=0x507d50 (lhz+cmpw = unsigned), 0x18c1c=0x50832c, 0x3458c=0x42918 (7 selectors same order/args, both from runEvery4FramesTaskSetPhase1), 0x18a26=0x50802c, 0x18cb6=0x5084b4 (bit base 112 vs 128 = layout), 0x1952c=0x509278 (same steps; ENGRPM same mnemonic: CM550 100C+4 / CM848 819B+2C)
- counterparts confirmed: 0x18708 (CM848 in==min test + division helper), 0x18968 (CM848 signed lha/cmpw, select 1, switch special case), 0x18ac4 (CM848 CRANKING test, channel 4), 0x192f2 (CM848 compares sign-extended values), 0x19332/0x19436 (presets / arrays / entry copies), 0x18dae (ch 3 vs 4 + override), 0x192e0, 0x1873e, 0x18620, 0xc66a, 0xd5e6
- prototypes: stack offsets all match (0x18968 old rows had index 3 = sensor_value: wrong, it is threshold_select)
- e2m blocks (block_bases.py): all 27 blocks resolve to base + stride*n with identical offsets per channel -> layouts are uniform; config 18 words, state 17 fields (pointers at 0/a/e/12/26/2a), history 12 fields
- single callers confirmed (find_ref.py): 0x1873e@0x28732, 0x18ac4@0x28738, 0xd5e6@0x28786, 0xc66a@0x1b722, 0x3458c@0x1b578, 0x18620@0x1bb9a (frame 15: next frame #0x10)
- 117D words: only 0xd5e6 writes them (others are cmpi/tst/reads); 0x80a922 only written by 0xc66a
- ambient air pressure sensor config +20/+21 = faults 18/19 = 0x806002 bits 2/3 (altitude derate fallback)
- CM848 0x508130 checks engine_state==2 CRANKING first and channel != 4 -> counterpart; CM848 0x508f64 presets 0x7fff/0x8000, one array, copies entry; 0x5090fc needs registered bit, clears both arrays, copies entry
## Decisions so far
- functions: all 19 investigator names CONFIRMED (twins 0x186ae 0x18a26 0x18c1c 0x18cb6 0x1952c 0x3458c); 0x18cb6 plate: "every other channel" imprecise -> amend comment (recorded channel with bits clear is cleared too)
- 0x18dae keep round-96 name (accurate; oil pressure only stated in plate); describer's OilPressure variant drops the feature name
- borders.py: no row before/after any table overlaps it; engine_overspeed_log 0x80553a (10DA +0) ends at 0x805561
- ZVLMES = CM848 label Zero_Vss_Derate_RPM (supports "zero vehicle speed" in 0xd5e6 plate)
- 0x807410 dump 150 (30 s)
## Final verdict plan
- functions: 19 CONFIRMED except plate amendments 0x18cb6 (recorded channel with bits clear also cleared) and 0xc66a ("only call" not "first call")
- cm848_function: 6 twin rows CONFIRMED (0x507d50 0x50802c 0x50832c 0x5084b4 0x509278 0x42918)
- globals: 77 CONFIRMED; comment amendments 0x807410 (EPIMTPFT is read, has no writer; outside-dump is presumption), 0x80060e (index holds while EPEN clear)
- enum members 5 CONFIRMED (enum PROTECTION_STATE renamed ENGINE_PROTECTION_TASK); prototypes 13 CONFIRMED
## Status: all checks done (2026-11-25); writing StructuredOutput (120 verdicts: 19 functions, 6 cm848_function, 77 globals, 5 enum members, 13 prototypes)
- twin standard used: same steps/order/algorithm constants/call position; table extent, record stride and the per-product enable-bit base (112 vs 128, consistent +16 in every EPF loop) are layout -> do not break twin (precedent findTsc1SourceConfiguration 5 vs 10, registerJ1939ReceiveHandler 16 vs 17); the function's OWN compare signedness does (0x192f2, 0x18968 stay counterparts)
