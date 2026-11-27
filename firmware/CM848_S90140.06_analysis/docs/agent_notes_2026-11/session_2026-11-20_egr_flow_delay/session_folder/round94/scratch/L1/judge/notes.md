# L1 judge notes (round 94)

Started 2026-11-25. No earlier judge run found.

## 0x3452a hour meter loader -> CONFIRMED twin loadHourMetersFromEeprom (CM848 0x5067bc)
- CM550 0x3452a: move.l 0x803b3e->0x80bda4 (key_on_hour_meter); move.l 0x803b50->0x80ccee (engine_hour_meter); rts.
- CM848 0x5067bc: lwz 0x3fd4b2 -> stw 0x40a64c (key_on); lwz 0x3fd4c4 -> stw 0x40a794 (engine); blr. Same order.
- Both directly after twin advanceHourMeters (0x34512 / 0x506780); both called once at start-up right after the
  analog channel initializers (CM550 0x2870e after cm550_initializeAnalogSensorChannels + mc68k_initializeDiscreteOutputDrivers;
  CM848 after cm848_initializeAmbientAirTemperatureChannel). EEPROM offsets 0x34/0x46 vs 0x30/0x42 (0x12 spacing).
- EEPROM dump 0x34 = 227512040 = RAM 0x803b3e; 0x46 = 226203089 = 0x803b50 = engine_hour_meter.
- 0x803b3e / 0x803b50 refs: long only (0x3452a, restartThroughBootRom 0x11978/0x1199a/0x119be/0x119e0,
  mc68k_runPowerDownSequence 0x280f2/0x28164/0x28180/0x281f6 through cm550_parameterCircularBufferWrite 0x16c3c + wait loop).
  Next rows 0x803b44 / 0x803b88: dword does not overlap. Inside EEPROM image -> _cal OK. Names unique.

## 0x16dd4 / 0x1709e warmup protection: disassembly matches both reports (see judge reading 0x16dd4-0x1711e)
- e2m 11EA/11EB/11EC-11EF records resolve exactly as both say. Dump: WPRYTM 3600=WPRYTMCN, WPLMFG 1, WPSSFG 0, WPACFT 1, LSLOFG 1, limit 5888.
- All 11EA/11EB/LSLOFG globals: abs refs only inside 0x16dd4-0x1711e (+ parameter ID table 0x362ec..). 0x80a8f4 has no base-register reader
  (no lea/movea of 0x80a8f0; 0xf79a movea #0x80a8f2 only uses (a2)).
## 0x1c0d4 -> CONFIRMED counterpart cm550_convertTorqueDerateTorqueLimitToFuelLimit (CM848 0x1e4e8 keeps its name here)
- CM550: max torque 0x80db1a <1 -> 1; scaleByRatioSigned(limit 0x80d338, 0x80d370 - noload 0x80db1c, maxtorque) (muls.l/divs.l = a1*a2/a3);
  + noload; floor 0 (bge); if < 0x80dec8 -> store + state 0x80d33a -> 0x80deca; THEN 0x80d338 = 0xffff, 0x80d33a = 0x28 (40).
- CM848 0x1e4e8: same 1-4 (0x40aee6 0->1; (0x40a89f - 0x40aeec) * 0x40a2d8 / 0x40aee6 via 0x570f0; + noload; floor; min 0x40afac + 0x40a2da->0x40afae), no reset.
  Reset 0xffff/NO_DERATE sits in caller cm848_arbitrateRequestedFueling BEFORE cm848_processProtectionLimits (cpp 20741).
- Extra step in CM550 -> not a twin (counterpart). Only caller bsr @0x1c190 in cm550_selectFinalFueling after jsr cm550_runFuelLimitChains.
## 0x1c308 -> CONFIRMED cm550_initializeTorqueDerateTorqueLimit (standalone)
- move.w #0xffff,0x80d338; move.w #0x28,0x80d33a; rts. Called once in mc68k_applicationMain (after cm550_FUN_00026a2e).
- CM848 torque_derate_torque_limit writers: only arbitrateRequestedFueling (per pass) + applyPowerTakeOffTorqueLimit -> no start-up twin.
## 0x1cc72 -> CONFIRMED counterpart cm550_calculateThrottle100Fuelings (CM848 0x1f17c)
- asm 0x1cc72-0x1cdf6 matches both: prog power (0x803cb8 & 0x200) skips +0/+2/+4; cold term = 2D lookup 0x800700 (81EE-81F0)
  gated by 0x803cd4 & 0x8000 and status word 2 bits 2/1/0x10 with latch 0x806ac0; +0 blended(rpm,400); +4 blended(0x80d654,400)+cold floor;
  +2 = lookup 0x8006ea (1054-1056 5DFL01) + subtractAndClamp + cold, floor; ESP 0x803cac & 0x10: +8 = 0x8006ea lookup+clamp (no cold), else blended(rpm,400); floor.
- CM848: cold_delta_fuel (flags_41 bit 0x1000), writes +6 too, chiMaxFuel for +4/+6, ESP forces interp factor 0. Different steps -> counterpart.
- 0x80d36c readers: 0xfaca calculateGovernorDroopSpeed, 0x18572 cm550_FUN_000184c6 (fault-derate torque curve points, MISSING from the
  investigator's comment), 0x1d884 selectEngineSpeedLimit, 0x26d96/0x26dc4 calculateEngineLoadPercentages.
- 0x80d654 = 1063 +10 HSRFBFDP; selectEngineSpeedLimit (twin) a4=0x80d654: +step 0x808138 while below (a2)=0x80d648, clamp down at once;
  initializeEngineSpeedLimitDefaults (twin) copies 0x803ba0 engine_speed_limit_reference_default_cal. = CM848 engine_speed_limit_ramped 0x40a308 (same record).
- 0x80db1a = 1461 +0 MTMPRPFL; writers cm550_FUN_000269f2 (lookup + 0->1) / cm550_FUN_00026a2e (=1 at start-up); CM848 0x40aee6 same role
  (0x29c98 maximum torque map at engine speed blended by chi/alpha, 0->1; 0x29de0 =1). CHR e2m 1461 +0 MT_Max_Torque_At_RPM_Ftlb (not in dumped table).
## Callers (own scan, jsr/bsr/bra/pea): each batch function has exactly one caller
- 0x1c0d4 bsr.w @0x1c190; 0x1c308 jsr @0x28970; 0x1cc72 jsr @0x1b5c6; 0x16dd4 jsr @0x1b6c0 (then rts); 0x1709e jsr @0x28810; 0x3452a jsr @0x2870e.
## Enums HIGH_RPM_PROTECTION_STATE / _FLAGS: no user in either firmware (only enums.csv + generated firmware_types.hpp).
- CM550 rows 407-412 (comment + FLAGS), 531-537 (2 comments + STATE); CM848 720-725 (comment + STATE), 727-732 (comment + FLAGS). Frozen = repo.
- FLAGS masks = J1587 PID 71 byte built in d2 at CM550 0xefa2-0xf004 (0x80 timer 0x80d676 nonzero and < 0x803c02; 0x08 0x803c9a&2;
  0x04 0x80d672 && 0x803c9a&4; 0x02 0x80d28c && timer 0; 0x01 0x80d67a), then written through the shared response pointer (0xf028-0xf032).
  No row can carry it -> delete both enums in both firmwares (CM848 has no idle shutdown code at all). STATE superseded by IDLE_SHUTDOWN_STATE 0-5.
## Comment errors found
- 0x80d654: step 0x808138 is e2m 1062 +0 HSRFRMRT (not 1063).
- 0x80d36c: reader list misses 0x18572 in cm550_FUN_000184c6 (fault derate J1939 torque curve speed points).
- 0x80a8f4: not cleared on the WPSTFG end while stopped (0x16ea0-0x16ea6); cleared on off path / time-outs / delay end.
- 0x16dd4 plate: 'completed with the engine running' is really 'completed while not STOPPED'; table limit only in states 2/3/6/7
  (stopped -> fuel_demand_maximum; 4/5/8 unchanged); oil pressure timer must EXCEED WPO2TMCN.
## Cross-batch: L2 and L4 investigators propose the same name maximum_torque_at_current_engine_speed for 0x80db1a / 0x40aee6; L4 names
  CM848 0x1e4e8 cm848_convertTorqueDerateTorqueLimitToFuelLimit (same stem). No conflict.
## 0x1cc72 'coolant fault' gating: CM848 counterpart cm848_calculateColdDeltaFuel zeroes the cold term on the three coolant temperature faults
  (high/low/in range) -> CM550's three word-2 bits 0x2/0x1/0x10 gating the same cold term are the coolant faults by analogy. Keep.
## VERDICTS (final)
- functions: 0x16dd4 AMENDED (name kept cm550_runEngineWarmupProtection, plate corrected); 0x1709e / 0x1c0d4 / 0x1c308 / 0x1cc72 CONFIRMED;
  0x3452a CONFIRMED twin (both, CM848 0x5067bc).
- globals: all CONFIRMED except 0x80d36c / 0x80d654 / 0x80a8f4 AMENDED (comments only). CM848 0x40aee6 CONFIRMED.
- %FU on FSMTFLNP = 100 / 5888 per count = same count as MM3S (0.0679 = 400 / 5888): the investigator's unit is right.
- enums: delete both in both firmwares (rows above); skipped[] empty.
