# N1 judge notes (round 95)

Started 2026-11-25. No earlier judge notes existed.

## 0x30498 (engine brake time) - CONFIRMED cm550_countEngineBrakeTime
- m68k 0x30498-0x304f2: 0x80bcf7 bit0 (EBDR1 000E +29 mask 01) or 5x 0x80bcf9 bit6 -> addq.l 0x80615e (TIT3EBTM) + 0x806176 (TIT2EBTM). Same 6 tests as cm550_ioControlBasedFuelCalculator (driver 1..6 cylinder counts JCDR1NCY..6). Only caller bsr.w 0x30a3c in 0x306ca (not in state 0).
- describer name cm550_accumulateEngineBrakeOnTime ~ same meaning; proposal ok.

## 0x306ca trip task - CONFIRMED cm550_updateTripInformation (counterpart cm848_updateTripAndLifetimeCounters)
- jsr 0x1b868 (Phase19 100 ms). gate 0x803c9a & 0x200. TIRF 0x80de66==1 -> clr, 0x80de50=1, 25 clr.l from 0x8060c2, clears ... 0x80614e, 0x80615e, 0x806162, 0x80617e ..., 0x804fa4.
- state: rpm 0x80ccf4==0 ->0; 0x80dc26==1 ->2; (0x80a9d0==0 && 0x80a9ee==1) or (0x80d330==11 && 0x80a9ee!=1) ->1; else 3.
- state 0: clr rates, clr fault timer 0x801e7a, bra 0x30a54 -> only histogram 0x304f4 (no brake / ESP counting).
- run time: 0x80613a (+0x10 overflow), 0x806162 (+0x400); 0x804fc0 = 0x80613a + 0x80401e (sat 0xffffffff).
- fuel: 0x808a56==1 -> TIFU = 0x80d354 * 0x5000000/0x39c2c30; ==0 -> (0x80619a-0x801e82)*0x800000/0x808a6a (0 divisor -> 0xffffffff).
- 0x80de53 -> 0x80de52 (byte); nonzero -> fault timer 0x801e7a vs 0x808a54 -> ori 1|0x40 into 0x80614e.
- 0x303d4(frac,whole) adds TIFU with 2^20 carry: lifetime fuel 0x80612a/0x80617a (ovf 0x20), trip 0x80612e/0x806142 (ovf 0x800). copies 0x804fa0/0x804fa4.
- per state: 3 -> 0x303d4(0x806126,0x80613e); 1 -> 0x30414; 2 -> 0x30454; then 0x30498; 0x80d2b4 !=0 -> 0x80617e/0x806182 ++; then 0x304f4.

## 0x30a5e power-down - CONFIRMED cm550_flagTripInformationPowerDownDataLoss
- first call (jsr 0x27fb0) of mc68k_runPowerDownSequence. gate trip enable; 0x803fdc -> 0x2|0x80; 0x806000&0x800 && 0x806abc&0x800 -> 0x8|0x200; &0x1000 both -> 0x1000|0x2000. Setters in cm550_loadParameterBlockAndUpdatePowerDownCounts verified (0x800: consecutive incomplete > limit; 0x1000: no block uploaded).
- CM848 0x523760: one test of power_down_data_lost_error -> |= 0x208. Counterpart.

## 0x30b0e - CONFIRMED cm550_emptyStubFunction11 (comment amended)
- 4e75 only; one jsr 0x28774 in mc68k_applicationMain after mc68k_scheduler_init (0x1bf54), before func 0x42ad4.
- The "progress word 0x877a" in the proposal plate is Ghidra's rendering of the jsr's return-address push (_DAT_00810ffa = 2; _DAT_00810ffc = 0x877a = return address 0x2877a) - not a progress store. Drop it from the comment.
- CM550 stub names existing: cm550_emptyStubFunction4/7/10 (no 1/11); 11 unique. describer's cm550_emptyStartupStub would be ambiguous with cm550_emptyPlaceholderInit 0x1ffd0 (also an empty start-up call).

## Trending
- 0x31496 CONFIRMED cm550_evaluateTrendingTriggers: jsr 0x1b7b0 first call of Phase5 (100 ms); gates 0x803cb8&0x10, engine_state!=1, 0x804a04==1; windows min < x <= max: rpm 0x80ccf4 (TRESMX 0x808a80 / TRESMN 0x808a82), load 0x80db5e (0x808a84/86), IMT = intake_manifold_temperature_sensor_state.filtered_value 0x80a2b2 (0x808a88/8a), coolant = coolant_temperature_sensor_state.filtered_value 0x80a336 (0x808a8c/8e); flags 0x801e98/9a/9c/9e; all -> 0x804a08=1, timer 0x804a00 ++ until == 10*0x808a7e -> 0x804a02=1; else clear all three.
- 0x315be CONFIRMED cm550_runTrendingIntervalAndStoreSamples: jsr 0x1b9ea frame-3 case (once per 40-frame cycle = 200 ms) / 300 -> once a minute. Record writes x14 bytes at 0x804a1a... Two record paths: (a) window open and TRTRCDTR -> oil/boost/coolant written and the record finished at once (fuel, load, time stamp), interval restarted; (b) window falling edge (0x804a04 0 and 0x804a06 1) without (a): oil written only if flags speed set, LOAD CLEAR, IMT set, coolant set (else 0), boost/coolant cleared, record finished. Fault (status 1/3 in 125 x 10-byte entries 0x805a24): at the window falling edge a zero record + time stamp. Plate comment wording "When the window closes, it adds..." is imprecise; amend.
- RAM dump: TRNOSATN 24 = TRSAIN 24; TRITTR 100; TRITTM 6000; TRITWNLM 600; TRITWNTM 357; TRNOSARB 100 (!) TRRBTMST 0; records 0-23 decode (35.5/70.4/107.6 h, then ~100 h apart 10427-12460 h), records 2 and 24 have zero sensors (path b) -> layout confirmed.
- 0x31a68 CONFIRMED cm550_restartTrendingAfterEngineRebuild: jsr 0x287f8 after cm550_initializeTripInformation; sole reader of 0x8049ea.

## J1939
- order of descriptor set-ups in mc68k_initializeJ1939Datalink matches cm848_j1939_system_init 1..12, then CM848 has 56320 anti-theft (13) where CM550 has none, CM550 has SHUTDN 65252 (15) where CM848 has none; WIF = 19th in both. Schedule constants identical (listed).
- request registrar 0x2f47e: 32 entries x 6 bytes at 0x801d5a, count 0x801e1a; dispatcher 0x2f4be registered for 0xea00 (59904).
- naming precedent: "...Buffer" = descriptor only (initializePgn65251EngineConfiguration1Buffer, cm550_initializePgn65252ShutdownBuffer, CM848 ...Buffer); "...Handler" = descriptor + request registration (cm550_initializePgn65229Dm4Handler, cm848_initializePgn65234Dm10Handler). -> 0x31ed2 / 0x33754 / 0x34440 register a responder -> AMEND to ...Handler.
- 0x31bce CONFIRMED cm550_buildPgn65269AmbientConditionsMessage: (x*2&0xffff)*6906/1000>>7 into 0x801eca (byte 1), send 0x801ebc. Schedule (0,65269,1000,170), request 0x2f5b6. CM848 0x23e8c same formula + 0xfe faults + ambient temp -> counterpart.
- 0x31ed2 AMEND -> cm550_initializePgn65265CruiseControlVehicleSpeedHandler: CM848 0x24664 same stores + ccvs1_cruise_control_state = 7 -> counterpart (not twin).
- 0x32052 CONFIRMED cm550_buildPgn65259ComponentIdentificationMessage: 5/17/4/10 + '*' at +5/+0x17/+0x1c/+0x27, 40 bytes (DLC 0x28).
- 0x32c22 CONFIRMED cm550_initializePgn61441ElectronicBrakeController1Buffer: CM848 0x25824 one more stb (payload +1) -> counterpart.
- 0x33164 CONFIRMED cm550_buildPgn65263EngineFluidLevelPressure1Message; comment fix: the set-up 0x331ae seeds bytes 1, 2, 5-6, 8 (not 3 and 7).
- 0x333d6 / 0x33460 CONFIRMED cm550_hasWordIncreasedOrDroppedToZero / cm550_hasByteIncreasedOrDroppedToZero (hand-traced: prev in d3 = first arg (0xc,a7), new d2).
- 0x334ec twin CM848 0x1b778: same 28-byte copy, rebuild, 12 compares (0,2,3,5,6,8,9,11,12,14,15,27) same order -> send. CONFIRMED sendPgn65251EngineConfiguration1OnChange.
- 0x3366a twin CM848 0x1b730 (& 0xf0, build, send; schedule (0,65251,5000,110)). CONFIRMED sendPgn65251EngineConfiguration1Message.
- 0x33a1e twin CM848 0x26480 (six stores, 9th set-up, FD1 schedule (0,65213,1000,50)). CONFIRMED initializePgn65213FanDrive1Buffer.
- 0x33716 CONFIRMED name cm550_buildPgn65253EngineHoursRevolutionsMessage (x20/36000 of 0x804fc0, swap, 0x803548); plate must cite the amended set-up name ...Handler.
- 0x33754 AMEND -> cm550_initializePgn65253EngineHoursRevolutionsHandler (registers 0x33716 for 0xfee5).
- 0x337c4 CONFIRMED cm550_buildPgn65262EngineTemperature1Message (schedule (0,65262,1000,430) same as CM848; CM848 has faults + oil temp -> counterpart).
- 0x33a62 CONFIRMED cm550_buildPgn65257FuelConsumptionMessage (registered by 0x33aea; CM848 has no 0xfee9).
- 0x33e58 CONFIRMED cm550_buildPgn65270InletExhaustConditions1Message.
- 0x33f5a CONFIRMED cm550_buildPgn65264PowerTakeOffInformationMessage (CM848 gates on power_take_off_enable; its byte 6 0xdc source is remote_power_take_off_switch = CM550 0x80bcd0 bit 4 DSRXSWSS/DS21SWSS).
- 0x341e6 CONFIRMED cm550_initializePgn65249RetarderConfigurationBuffer (CM848 0x2682c no payload store; RC builder 0x3407a fills +0..+0x11).
- 0x34232 CONFIRMED cm550_buildPgn65248VehicleDistanceMessage; 0x34394 CONFIRMED cm550_buildPgn65255VehicleHoursMessage.
- 0x34440 AMEND -> cm550_initializePgn65260VehicleIdentificationHandler (registers 0x34430 for 0xfeec).
- 0x344ce CONFIRMED cm550_initializePgn65279WaterInFuelIndicatorBuffer (CM848 0x26efc +7 stores).
- 0x34d52 CONFIRMED cm550_calculateWetStackTimingAdvance; plate: CM848 has the crank record CKWSTA (e2m only) -> soften "no wet stack timing algorithm".

## Globals
- uniqueness: no CM550 collisions (unique.py); CM848 same-name hits are the same records/fields (fine).
- trending table 0x804a1a: 36 rows inside (not 35): list in judge notes / comment. 0x804a18 inside TRFLUSSR dword; 0x803698 inside 0x803696 dword; part_number_list 0x803ec2 inside the unit number byte[10] (text starts 0x803ec5). None has an absolute ROM ref; only 0x804a1c / 0x804a20 appear in the cpp, as the table's field bases.
- AMEND 0x808a7a -> trending_requested_sample_count (record_count is ambiguous with trending_total_sample_count_cal TRNOSATN; TRNOSARQ = samples requested).
- AMEND 0x801e98/9a/9c/9e -> trending_<input>_trigger_satisfied_flag (e2m term 'trigger is satisfied'; "window" collides with the interval window names).
- AMEND 0x803e7f type byte[20] (the only access: DLC 0x14 descriptor); comment cites ...Handler.
- RAM dump: EFL bytes 3 and 7 = 00 (never written); TIFUSS = 0x208 (system error 11 bits) ; lifetime run time 12567 h.
- enum TRIP_INFORMATION_ENGINE_STATE new (no TRIP enum exists); stores/compares only in 0x306ca + clr in 0x30ade; full e2m label "ENG_OFF, IDLE, PTO".

## Verdict summary (final)
- Functions: 21 CONFIRMED; AMENDED names 0x31ed2 / 0x33754 / 0x34440 (...Handler); AMENDED comments only 0x30b0e (no progress word), 0x315be (three record paths), 0x33164 (bytes 3 and 7 never written), 0x33716 (cites ...Handler), 0x34d52 (CM848 has crank CKWSTA record).
- CM848: 3 CONFIRMED (0x1b730, 0x1b778, 0x26480).
- Globals: AMENDED 0x808a7a (trending_requested_sample_count), 0x801e98/9a/9c/9e (..._trigger_satisfied_flag), 0x803e7f (byte[20]), 0x804a1a (comment: 36 rows, struct layout); rest CONFIRMED.
- Enum: 4 CONFIRMED.
- Applier notes: delete 36 rows in the table + 0x804a18 + 0x803698; move part_number_list 0x803ec2 -> 0x803ec5; new struct trending_sample_record_t; new enum TRIP_INFORMATION_ENGINE_STATE (size 2); rename function_definitions rows of 0x333d6 / 0x33460; refresh comments that quote placeholder names (descriptor rows, task-set plates, bitfield comments, cm550_initializeTripInformation plate, CM848 0x1b3a0 / j1939_pgn65251_* / j1939_pgn65213_priority_cal).
- Leads: 0x803614 derate_percentage_active = IC1 byte 7; 0x8034e8 vp44_fso_rpm_fault_counter = EFL/P1 byte 1; 0x2f538 cm550_diagnosticDataDump = request-responder registration list; 0x2f47e registrar / 0x2f4be PGN 59904 dispatcher have no rows.
