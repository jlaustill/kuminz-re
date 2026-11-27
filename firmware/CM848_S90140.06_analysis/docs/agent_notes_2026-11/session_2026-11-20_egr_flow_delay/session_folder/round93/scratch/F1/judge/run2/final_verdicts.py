"""Judge F1 run 2: the final verdict list. Starts from run 1's verdicts_f1.json (re-checked in run 2, see notes.md),
applies the run 2 corrections and checks that every proposed element has exactly one verdict."""
import json

R = "/home/linux/.claude/jobs/374b0424/tmp/w15/r93"
P = json.load(open("/home/linux/.claude/jobs/374b0424/tmp/w15/r94/batch_F1.json"))["proposal"]
V = json.load(open(f"{R}/scratch/F1/judge/verdicts_f1.json"))
by = {(v["kind"], v["address"]): v for v in V}

RUN2 = " Run 2 re-check: disassembly re-read (run2/disasm_*.txt), single caller confirmed by a jsr / bsr / pointer scan (run2/callers.py)."

# ---------------------------------------------------------------- function comment fixes (keep the 'was' notes)
by[("function", "0x0001ca54")]["final_comment"] = (
    "Commands the fuel shutoff driver (e2m 000E +2D DRFSEA bit 5 - enable = FSO on): clears the bit when the key switch "
    "(000E +0 bit 0 DSKYSWSS) is off - or the fuel system asks for shutoff (1091 +0 FSAPFSCO) - or engine_retarder_active_flag "
    "is set with algorithm_enable_flags_0_cal bit 0x40 (EBODEN) - or engine_state is OVERSPEED with overspeed_fuel_shutoff_enable "
    "(EPOSFSO); sets it otherwise. It writes only while fuel_shutoff_driver_override_priority (12A7 +2D DRFSPZ - the same slot is "
    "VPENPZ 'VP44 pump enable') is 0. Its one caller is the executive frame task set at 0x1b612 (jsr at 0x1b63c). CM848 has no "
    "counterpart (was cm550_fuelDemandLimitSelector11)")
by[("function", "0x0002658c")]["final_comment"] = (
    "Start-up initializer of the low speed governor idle adjustment (called once from mc68k_applicationMain): with "
    "idle_speed_save_enable (LSISSVEN) set it restores the working operator idle adjustment 0x801a82 from the saved 1073 +0 "
    "LSICBKRF (RPM added to LSG reference) - otherwise it zeroes both. It clears 1049 +6 LSCIOD (cold idle override flag) and "
    "writes two EEPROM mirror words: it raises the trim 131E +2 LSMNRFTN to at least 1066 +8 LSMNRF and lowers 131E +4 LSMXRFTN "
    "to at most 1066 +A LSMXRF. The run-time partner is the idle increment / decrement switch handler 0x26474. No CM848 "
    "counterpart (was cm550_fuelDemandLimitSource2Selector)")

# ---------------------------------------------------------------- global comment fixes
by[("global", "0x0080dc26")]["final_comment"] = (
    "e2m 109E +2 PTSS 'status of the PTO algorithm based on switch activation' (1 = active): the guard of "
    "applyPowerTakeOffTorqueLimit and of the power take-off fueling selection. cm550_runPowerTakeOffGovernor runs while it is 1 "
    "and copies it into its previous-pass word 0x801c0c (move.w at 0x2d994 - PTSS is the source); no instruction in the dumped "
    "ROM stores to it by its address (0 in the RAM dump). The same record and name as CM848 0x40af4e (was "
    "closed_loop_governor_active_flag)")
by[("global", "0x008000d6")]["final_comment"] = (
    "The AFC timing increment status word that cm550_addAirFuelControlTimingAdvance ORs into bit 2 of "
    "timing_control_status_flags: 4 while final_fueling_state is FUELING_STATE_AIR_FUEL_CONTROL_DERATE (the AFC timing "
    "advance is being added) - else 0 (0xc2be). No e2m record; the counterpart of cylinder_pressure_maintenance_status "
    "(0x80021c - 0 or 8). A word by its accesses (move.w / clr.w / or.w); left untyped while the unreferenced row at 0x8000d7 "
    "sits inside it (was diagnostic_message_alternation_counter)")

# ---------------------------------------------------------------- reasons: append the run 2 confirmation
EXTRA_F = {
    "0x0001ca54": " The remark 'the row at 0x1ca5c is the same body entered two instructions late' is true of the frozen CSV, "
                  "but the LIVE deleted_functions.csv already lists 0x1ca5c (PR #53 round 93), so the applied comment drops it "
                  "and keeps the 'was' note.",
    "0x0002658c": " The remark about the row at 0x2659a is dropped for the same reason (0x2659a is in the LIVE "
                  "deleted_functions.csv); the 'was' note is kept.",
    "0x00026af0": " The remark about the row at 0x26b00 is dropped for the same reason (0x26b00 is in the LIVE "
                  "deleted_functions.csv). Also checked: 0x26ab8 looks the limit up (move.w d0,(0x80a26e) at 0x26ae6 under "
                  "flags word 32 bit 0), and cm848_calculateMainInjectionTiming raises injection_timing_demand to "
                  "injection_timing_main_misfire_limit with MAIN_INJECTION_TIMING_SOURCE_MISFIRE_LIMIT inline.",
    "0x0001c152": " CM848's two functions read in the decompilation: cm848_arbitrateRequestedFueling (override 13 / chain + "
                  "conversion, requested fueling, master-slave and group 2 arbitration, fold, the LSG-under-TSC1 case) and "
                  "cm848_selectFinalFueling (26 / 41 / 27 / 25 / 23 / 24 / 22, clamp, LSG latch, previous state).",
    "0x00034512": " Executive phase 0 re-read in both: CM550 0x1b95e jsr (a5), five bsr task sets, jsr 0x34512, timing "
                  "pointer = 0x809ef2, phase = 1; CM848 case 0 the same shape with cm848_advanceHourMeters last.",
    "0x00030b34": " Its caller 0x30b62 then picks the final timing and its state by final_fueling_state (27 -> 10, 25 -> 9, "
                  "26 -> 8, the override timing with 7, else TSOI with the intermediate state).",
    "0x00034dba": " 0x34cc4 chooses state 1 when the ADIMTPFT (intake manifold temperature) table gives the larger advance "
                  "and 13 when the ADCLTPFT (coolant temperature) table does, as the plate comment says.",
    "0x00017120": " The oil pressure / drain-back records behind 0x16dd4 resolve to 11EB +0..+8 WPO2TDCN / WPO2TMCN / "
                  "WPMXTMCN / WPFUTMCN / WPRYTMCN (run 2).",
}
for v in V:
    if v["kind"] == "function":
        v["reason"] = v["reason"] + RUN2 + EXTRA_F.get(v["address"], "")

EXTRA_G = {
    "0x0080dc26": " Run 2: the m68k decode of 0x2d994 is move.w (0x80dc26).l,(0x801c0c).l; abs_refs lists 8 references to "
                  "0x80dc26, seven compares / tests and this read. The rest of the comment stands; the 'was' note is kept.",
    "0x008000d6": " Run 2: the 0x8000d7 row is still in the LIVE CSV too; delete it (no ROM reference) and 'word' applies.",
    "0x0080aaa4": " Run 2: TSAJ4DTA is the only signed (S) record among the 43; the live CSV follows the Calterm sign for "
                  "mixed or neutral code (round 94 sign rule).",
    "0x00801a82": " Run 2: ext.l d1 at 0x264e6 and 0x26524 before cmp.l with (trim - base idle speed); the RAM dump holds 600 "
                  "= 0x805f0a.",
    "0x0080ccb2": " The comment leaves out one set: 0x16e76 re-arms it (= 1) after the engine has been stopped for the oil "
                  "drain-back time WPRYTMCN - an omission, not an error.",
    "0x0080800a": " Run 2: the LIVE CSV row is 'word' (round 94 sign rule: Calterm FSMNFL unsigned), the same as proposed.",
    "0x0080da62": " Run 2: the LIVE CSV row is 'word' (round 94 sign rule: Calterm JCTQLMFL unsigned), the same as proposed.",
}
for v in V:
    if v["kind"] == "global":
        v["reason"] = v["reason"] + " Run 2: record, width and users re-checked (e2m_block_addresses.py, abs_refs.py, RAM " \
                                    "dump at the declared width)." + EXTRA_G.get(v["address"], "")

EXTRA_E = {
    "FUELING_STATE:18": " Run 2: TIT3DQTM read in all 64 e2m files - 32 cut it at 'ENGINE PROTECTIO', 4 at 'ENGINE PROTECTION "
                        "SINCE LAS'; RAM dump 0. 'Engine protection' is the firmware's own words for this state (the "
                        "counter's record), and the state is the whole engine protection feature (no channel), so the "
                        "name is not a bare 'protection'.",
    "FUELING_STATE:37": " Run 2: CM848 decompilation re-read (cm848_runOperatingModeSpeedGovernor gate 7 / 2 / 30 / 37; "
                        "cm848_selectPowerTakeOffOrUserFueling passes 1 / 2 / 37 / 38 through); CM550 EEC1 table 0x32d04 "
                        "(index = state - 1) puts 37 at 0x32d5c with 1 2 3 7 8 30.",
    "FUELING_STATE:38": " Run 2: CM550 EEC1 table 0x32d04 puts 38 at 0x32d88 (0xF8) with 13-21 28 29 31 33-36 39-41.",
    "FUELING_STATE:3": " Run 2: reg_targets.py - the move.w #3 through address registers go to the alpha state, engine_state, "
                       "JCEGMD, TIEGST and others, none to a fueling state word.",
    "FUELING_STATE:36": " Run 2: the strongest lead is the e2m group name PTP_07 'powertrain protection' with 12B4 +0 TCFL "
                        "'POWERTRAIN PROTECTION FUELING' (abs_refs: only the parameter table 0x3693c), but no code shows the "
                        "state - keep.",
}
for v in V:
    if v["kind"] == "enum_member":
        v["reason"] = v["reason"] + EXTRA_E.get(v["address"], "")

# ---------------------------------------------------------------- own_role (functions) kept from run 1, re-derived in run 2
# ---------------------------------------------------------------- completeness
want = {("function", f["address"]) for f in P["functions"]} | {("global", g["address"]) for g in P["globals"]} | \
       {("enum_member", f"FUELING_STATE:{int(e['value'])}") for e in P["enum_members"]}
have = {(v["kind"], v["address"]) for v in V}
assert want == have and len(V) == len(want), (want ^ have)
for v in V:
    if v["kind"] != "function":
        v.pop("final_relation", None)
        v.pop("final_cm848_address", None)
        v.pop("own_role", None)
    if v["kind"] != "global":
        v["final_type"] = ""
json.dump(V, open(f"{R}/scratch/F1/judge/run2/final_verdicts.json", "w"), indent=1)
from collections import Counter
print(len(V), Counter((v["kind"], v["verdict"]) for v in V))
