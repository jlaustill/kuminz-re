"""Build the global verdict entries from proposed_globals.tsv + globals_check.txt, with the judge's amendments."""
import json
import re

base = "/home/linux/.claude/jobs/374b0424/tmp/w15/r96/scratch/Q3/judge/"
check = open(base + "globals_check.txt").read()
blocks = {}
for blk in check.split("=== ")[1:]:
    head, _, rest = blk.partition("\n")
    addr = head.split()[0]
    blocks[addr] = rest

amend = {
    "0x8002aa": {
        "final_name": "cylinder_balance_segment_period_count",
        "final_comment": "Periods summed into the current cylinder segment (0..4) in mc68k_fillCylinderBalanceSpeedBuffers: "
                         "one per primary speed interrupt, i.e. per period measurement (3 teeth per period in this dump, ESTTIP), "
                         "cleared at the start tooth and after each stored segment.",
        "reason": "AMENDED name: the word counts calls of mc68k_fillCylinderBalanceSpeedBuffers (addq.w #1 at 0x126ca, one per TPU "
                  "channel 10 interrupt = one period of ESTTIP = 3 teeth), compared with 4 at 0x126d0; the proposal's own comment "
                  "says periods, so tooth_count is wrong. Refs 0x126b4 clr.w / 0x126ca addq.w / 0x126d0 cmpi.w / 0x1275e clr.w, "
                  "all word, all in 0x1266e; no e2m record. New name unique in CM550.",
    },
    "0x8002a6": {
        "final_comment": "The running sum of main_engine_position_sensor_period over the current cylinder segment (4 periods) in "
                         "mc68k_fillCylinderBalanceSpeedBuffers. The undefined row 0x8002a8 (fuel_timing_blend_rpm_input_1) lies "
                         "inside this dword and has no reference (no absolute reference, no decompiler use, no pointer in the RAM "
                         "dumps): drop it.",
        "reason": "Role and dword width CONFIRMED (clr.l 0x126ae / add.l 0x126c4 / move.l 0x12700, 0x12718 / clr.l 0x12764, all "
                  "in 0x1266e), but the dword swallows the named row 0x8002a8 fuel_timing_blend_rpm_input_1, which the comment "
                  "did not list: AMENDED comment says to drop it (0 refs).",
    },
    "0x80d340": {
        "final_comment": "e2m 1053 +2 FLINML 'interpolation factor for 4-D fueling, max fueling calculation' (the alpha, Q14: "
                         "0x4000 = steady state table, 0 = transient): written by calculateAlpha, by "
                         "cm550_updateElectronicSmartPowerTau (0x4000 minus its tau value while electronic smart power is "
                         "enabled, move.w at 0x1addc) and at start-up by "
                         "cm550_initializeFourDimensionalFuelingInterpolationFactor; read by the 4D fueling, "
                         "cm550_calculateBlendedTableValue, vp44_fuelLimitExceedanceStatisticsAccumulator and the governors "
                         "(selectEngineSpeedLimit, cm550_governorFuelPidController). A fueling factor, not a timing one. The "
                         "same record and name as CM848 0x40a889.",
        "reason": "Name and word type CONFIRMED (e2m 1053 +2 FLINML, 10 word refs; CM848 0x40a889 same name). AMENDED comment: "
                  "the proposal listed calculateAlpha and the start-up init as the writers, but cm550_updateElectronicSmartPowerTau "
                  "also writes it (0x1addc move.w d0,(0x80d340): timing_alpha_blend_factor = 0x4000 - tau).",
    },
    "0x80da38": {
        "final_comment": "e2m 1102 +22 JCTQRPP1 'torque curve speed at breakpoint 1 (LSG reference)': written by the torque curve "
                         "requesters cm550_calculateFaultDerateJ1939TorqueCurveSpeedPoints and "
                         "cm550_setThrottle100J1939TorqueCurveSpeedPoints and by vp44State2TransitionHandler (0xfa06: the LSG "
                         "reference less the droop term at the idle fueling), a helper (directly and through 0xfa68) of the torque "
                         "curve update vp44_fuelLimitExceedanceStatisticsAccumulator (0xfb26, the second call of "
                         "buildPgn65251EngineConfiguration1Payload); those vp44_ names are old automatic names, not evidence of "
                         "VP44 code. The same record and name as CM848 0x40adac.",
        "reason": "Name and word type CONFIRMED (e2m 1102 +22, 11 word refs; CM848 0x40adac same name). AMENDED comment: 'the VP44 "
                  "derate code' rests on current names only; the writers at 0xfa0c-0xfefe are vp44State2TransitionHandler / "
                  "0xfa68 / cm550_calculateGovernorDroopSpeed, all called only by vp44_fuelLimitExceedanceStatisticsAccumulator, "
                  "which buildPgn65251EngineConfiguration1Payload calls right after the fault derate step (the place of CM848's "
                  "cm848_updateJ1939EngineConfigurationTorqueCurve).",
    },
}

manual_reason = {
    "0x807ce4": "e2m 1048 +6 CTHISATH, no row; 4 move.w reads (0x10a50 / 0x10c76 / 0x10c94 in vp44_derateThresholdMonitorAndFaultController, 0x10e06); CM848 0x5c294 same record and name; not EEPROM.",
    "0x80052c": "No e2m record; only refs 0x143d6 move.w write (0x143b6, the coolant correction lookup result) and 0x1430a add.w read (0x142d4); word. CM848 keeps the value in throttle_demand_offset_cal_working.",
    "0x80061e": "Refs 0x192e0 move.w write and 0x1927e cmp.w only (word); copy of engine_protection_active_fault_index (i16); CM848 0x3fbd3a same name i16.",
    "0x80a1ac": "No e2m record (801A +38 FLTADC ends at 0x80a1ab); 6 move.w writes 0x13340-0x133d6 + clear loop base 0x133e2; values FLFLAJCn (i16) + signed trim; no named row inside; no reader in the dumped ROM.",
    "0x804158": "e2m 8241 CBDDFTO1-6 (2 bytes S each) at 0x804158-0x804163, inside the EEPROM image 0x803b0a-0x804f93 (round 94) so _cal; indexed word accesses in 0x127c2 and 0x133fe; no named row inside.",
    "0x800322": "dword[7] 0x800322-0x80033d: indexed store base 0x126fc, copy loop base 0x12722 (7 x move.l), slot 6 movea 0x12712, slot 0 store 0x12750; inner rows 0x80032a / 0x800332 / 0x80033a have no other reference (listed for dropping).",
    "0x8002d4": "i16[6] 0x8002d4-0x8002df: copy loop base 0x13542 (0x133fe) and restore loop base 0x13236 (0x127c2); the 7 inner rows have no reference (listed for dropping).",
    "0x8002e0": "word[16] 0x8002e0-0x8002ff (16-pass loop in 0x133fe), bin / bin+1 bases in the learning code; the 11 inner rows: only 0x8002e2 is referenced, as the bin+1 base (listed); none in the RAM dumps.",
    "0x800300": "word[16] 0x800300-0x80031f, same pattern; 0x800302 is the bin+1 base; inner rows 0x800304 / 0x800306 unreferenced (listed).",
    "0x8002d0": "word: tst / neg / move.w pair at 0x12f28-0x12f48 and cmp.w 0x12f50; the byte row 0x8002d1 inside has no reference (listed for dropping).",
}

out = []
for line in open(base + "proposed_globals.tsv"):
    a, n, t = line.rstrip("\n").split("\t")
    blk = blocks.get(a, "")
    e2m = re.findall(r"e2m: (\S+ \S+)", blk)
    refs = re.search(r"refs \((\d+)\)", blk)
    nref = refs.group(1) if refs else "?"
    cur = re.search(r"current: (.*)", blk).group(1).split(" | ")[0]
    v = {"kind": "global", "firmware": "CM550", "address": a, "verdict": "CONFIRMED", "final_name": n, "final_type": t}
    if a in amend:
        v.update({k: amend[a][k] for k in amend[a] if k in ("final_name", "final_comment")})
        v["verdict"] = "AMENDED"
        v["reason"] = amend[a]["reason"]
    else:
        r = manual_reason.get(a)
        if r is None:
            sign = re.search(r"len/sign/type=\('(\d+)', '(\w)'", blk)
            signnote = ""
            if sign:
                signnote = f" (e2m {sign.group(1)} bytes {'signed' if sign.group(2) == 'S' else 'unsigned'})"
            if a == "0x808010":
                signnote = " (e2m range -3600..3600; the only read sign-extends it, ext.l at 0x1c858)"
            r = (f"{'e2m ' + e2m[0] if e2m else 'no e2m record'}{signnote}; {nref} absolute refs, all at the width of {t}; "
                 f"name unique in CM550; {('replaces ' + chr(39) + cur + chr(39)) if cur != '(no row)' else 'new row'}.")
        v["reason"] = r
    out.append(v)
json.dump(out, open(base + "global_verdicts.json", "w"), indent=1)
print(len(out))
