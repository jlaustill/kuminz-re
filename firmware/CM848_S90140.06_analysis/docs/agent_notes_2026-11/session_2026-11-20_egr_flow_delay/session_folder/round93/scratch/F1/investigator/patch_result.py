"""Round 93 F1: rewording of the CM848 'no block' claims in build_result.py after the mnemonic grep of the labelled
CM848 e2m (the e2m tool is silent for a block number the CHR family renumbered, so silence proved nothing)."""
P = "/home/linux/.claude/jobs/374b0424/tmp/w15/r93/scratch/F1/investigator/build_result.py"
s = open(P).read()
EDITS = [
    ("CM848: no 11EA block in its parameter table, no member 33, no chain step. RAM dump: WPLMFG 1, WPTQLM 5888.",
     "CM848: the labelled e2m (CHR_CC_11.45.01.07) has no record with mnemonic WPTQLM / WPLMFG / WPSSFG, the enum has no member 33 and the runner 0x4280c has no such step. RAM dump: WPLMFG 1, WPTQLM 5888."),
    ("'SUM OF 4D, AFC, USER AND COOLANT ADVANCES'. CM848's parameter table has no 1090 block.",
     "'SUM OF 4D, AFC, USER AND COOLANT ADVANCES'. The labelled CM848 e2m has no record with mnemonic CPTAIC / TSAJ4DTA."),
    ("CHR timing state labels 01=WETSTACK, 0D=WTSTCOOL. CM848's parameter table has no 1077 block. RAM dump: 0x8036e2 = 1.",
     "CHR timing state labels 01=WETSTACK, 0D=WTSTCOOL. The labelled CM848 e2m has no record with mnemonic WSTA / TSBEWSTA. RAM dump: 0x8036e2 = 1."),
    ("into 0x806188 / 0x806186 and then refresh the copies. CM848's parameter table has no 1215 / 1216 blocks.",
     "into 0x806188 / 0x806186 and then refresh the copies. CM848's trip information is a different module (cm848_updateTripAndLifetimeCounters 0x523148 - e2m blocks 8B6B-8B6D): its previous fuel copy injected_fuel_total_previous 0x3fcfc0 and its Trip_Info_State word 0x40b644 are referenced only inside that function - there is no start-up initializer - and the labelled CM848 e2m has no record with mnemonic TIEGAVLD / TIAVLD."),
    ("(integrated fuel delivered) - 0x801e92 = 1216 +60 TIEGAVLD (lifetime average load) - 0x801e94 = 1216 +62 TIAVLD (trip average load). No CM848 counterpart.\"",
     "(integrated fuel delivered) - 0x801e92 = 1216 +60 TIEGAVLD (lifetime average load) - 0x801e94 = 1216 +62 TIAVLD (trip average load). CM848's trip information task has no such initializer.\""),
    ("rejected; CM848's overspeed_fuel_shutoff_enable bit has no reader in either bank. RAM dump: 0x80bcfb = 0x20 (on), priority 0.",
     "rejected. CM848: overspeed_fuel_shutoff_enable has no reader in either bank, no code tests mask 0x40 of algorithm_enable_flags_0_cal (the tests use 2 / 0x100 / 0x400 / 0x800 / 0x1000 / 0x2000 / 0x8000) and the labelled e2m has no FSAPFSCO record; it lists an FSO_Command output ([DRFSEA] 1577 +3 mask 0x40) but that block is outside the dumped parameter table - no counterpart found. RAM dump: 0x80bcfb = 0x20 (on), priority 0."),
    ("CM848: no instruction references ANC_Timing 0x40a04a or SOI_Before_ANC_Timing 0x40a056 (scan of both images);",
     "CM848: no instruction references ANC_Timing 0x40a04a or SOI_Before_ANC_Timing 0x40a056 (scan of both images, and neither address appears in the decompilation);"),
    ("CM848 has the record (AFC_Timing_Increment 0x40a2e4) but no instruction references it in either image.",
     "CM848 has the record (AFC_Timing_Increment 0x40a2e4) but no instruction references it in either image and the address does not appear in the decompilation."),
    ("CM848: no instruction references Maximum_Timing_Advance 0x5c676 or SOI_Before_Max_Limit 0x40a2ea in either image. RAM dump: TSMXTA 631, TSOI 495.",
     "CM848: no instruction references Maximum_Timing_Advance 0x5c676 or SOI_Before_Max_Limit 0x40a2ea in either image and neither address appears in the decompilation. RAM dump: TSMXTA 631, TSOI 495."),
    ("- no step here, no NZFLLM record in its 10A4 block, no member 17. RAM dump: NZFLLM 5888 (no limit).",
     "- no step here, no record with mnemonic NZFLLM in the labelled CM848 e2m, no member 17. RAM dump: NZFLLM 5888 (no limit)."),
    ("CM848: idle_speed_save_enable has no reader in either bank and its e2m has no LSICBKRF / LSMNRFTN / LSCIOD records.",
     "CM848: idle_speed_save_enable has no reader in either bank and the labelled CM848 e2m has no record with mnemonic LSICBKRF / LSMNRFTN / LSCIOD."),
    ("\"SCORED CANDIDATES: 0x1ce58 -> 0x1f318",
     "\"COMMENT WORDING. The plate comments and the enum comments use the proposed global names, some of them at medium confidence (fault_derate_fuel_limit, datalink_engine_control_mode, datalink_torque_limit_fueling, fuel_system_derate_fuel_limit, wet_stack_timing_state, the trip and idle adjustment copies): if a rename is rejected its name in those comments must be put back. The CM848 absence claims were checked by mnemonic in the labelled e2m CHR_CC_11.45.01.07 (the block numbers differ between the two e2m families, so a silent block lookup proves nothing) and by address in both images and the decompilation. \"\n         \"SCORED CANDIDATES: 0x1ce58 -> 0x1f318"),
]
for old, new in EDITS:
    assert s.count(old) == 1, (s.count(old), old[:70])
    s = s.replace(old, new)
open(P, "w").write(s)
print("patched", len(EDITS))
