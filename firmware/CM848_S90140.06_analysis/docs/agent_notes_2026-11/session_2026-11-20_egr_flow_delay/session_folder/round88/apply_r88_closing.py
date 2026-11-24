"""Round 88 closing: task 046, PR body, session README, todo, the memory round log. Idempotent (an edit is skipped
when its new text is already there). usage: apply_r88_closing.py <repo> <pr_body.md> <count>"""
import os
import re
import sys

repo, pr, count = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = """## Done, round 88 (2026-11-24, same PR): the filter library; 6 more twins; ENGINE_STATE; the shifted dumps

Peer relays started and continued the round (10:19, 10:50, 11:20, 11:50). The scripts are in `session_folder/round88/`,
with both audit workflows' proposals and verdicts (`audit_result_r88.json`, `audit2_result_r88.json`).
- **Stage A (ecb02353), the filter library (round 87's verified fifth group):** the shared name
  `exponentialMovingAverage` paired CM550's signed filter (0x34e9a) with CM848's unsigned one (0x56594); the two
  pairs use different formulations, so all four are prefixed: `cm550_signedFirstOrderFilter`,
  `cm550_exponentialMovingAverage` (was `cm550_coreTableInterpolation`), `cm550_secondOrderFilter`,
  `cm550_secondOrderFilterUnsigned` (0x34fe0, new) and `cm848_exponentialMovingAverage`. CM550 gains
  `ema_filter_state_t` / `second_order_filter_state_t`, 38 filter records (13 filters and the 25 A/D channel records)
  and 40 coefficient words (37 named `<record>_filter_coefficient`); two local rows type the A/D loops' record pointer
  `sensor_debounce_state_t *`.
  - **Proof:** CM550 verify DETERMINISTIC; 1 function added (0x34fe0), 0 removed; the 38 changed functions are the
    filters, the A/D loops and the record users; caller artifacts in_ 8 -> 4, CONCAT 10 -> 6; no existing local row
    moved. CM848 label-only (22 lines re-wrapped). Headers 0 errors; _cal HARD 0.
- **Stage C (c964a479), clip-core:** `ECUReader::readMemoryService4ALarge` skipped a failed 128-byte chunk without
  padding (and could loop on an empty reply), which is why `cm848_ram.bin` misses 0x40c200-0x40c27f and CM550's
  extended RAM dump reads at address - 0x80. The new `readInChunks` (clip/ChunkedRead.h) retries, pads with 0xFF,
  records gaps (`<dump>.gaps.txt`) and stops after 5 failed chunks in a row; 8 unit tests (clip-core-tests / ctest),
  9 of whose checks fail against the old skip behaviour.
- **Stage D (46b9036e), the loaders:** `ScriptUtils.imageFromDumpWithGaps` (5 JUnit tests; 109 in all) puts the two
  shifted dumps' bytes at their addresses: CM848 RAM 0x3FA000-0x43FFFF with the chunk at 0x40c200 left 0, CM550
  EXT_RAM 0x8091C2-0x80FFFF with the file's bytes from offset 0x80 at 0x8092C2. Both .cpp outputs stayed
  byte-identical (the decompilations do not read these RAM bytes).
- **Stage B (abe06453), the misname audit (4 investigators, 4 skeptics; 179 changes):** 6 new twins
  (`registerJ1939DiagnosticHandlers`, `registerJ1939DiagnosticService`, `commandEngineShutdown`,
  `inhibitKeyOffShutdown`, `initializeEngineState`, `handleJ1939CanTransmitInterrupt`); the shared
  `commitEepromMirrorToEeprom` split into counterparts; CM550's power-down bookkeeping, engine state machine
  (`cm550_updateEngineState`, an `ENGINE_STATE` enum), RAM refresh and overspeed log; 37 J1939 transmit descriptors
  as `j1939_tx_msg_t` (CM848's type; `j1939_header_t` became `j1939_msg_hdr_t`); the J1939 service table; CM848's
  register save / restore helpers (two were named as table lookups). Two CM550 stub rows (rts tails of other
  functions) moved to deleted_functions.csv. `clearWorkingRam`'s locals in both twins.
  - **Proof:** CM550 verify DETERMINISTIC; 2 functions removed on purpose, 0 added; the non-label changes are the
    struct fields, the ENGINE_STATE members, removed casts and the CAN ID source-address CONCAT31 (as CM848 renders
    it); no existing local row moved. CM848 label-only apart from `clearWorkingRam`. Headers 0 errors; _cal HARD 0.
- **firmware/CLAUDE.md:** stage A refreshed three lines to `cm848_exponentialMovingAverage`; stage C added the cause of
  the CM848 RAM dump gap; stage D added the loader lines and changed the test count to 109 (full lines in the commits).
- **Leads (round 89):**
  - The second audit (`audit2_result_r88.json`, verified, not applied): the filter records' users and initializers
    (twins `calculateFilteredEngineAcceleration`, `initializeEngineAccelerationFilters`,
    `smoothPowerTakeOffReferenceEngineSpeed`, `initializePowerTakeOffGovernorFiltersAndGains`,
    `initializePowerTakeOffReferenceFilter`, `presetPowerTakeOffSmoothedReferenceEngineSpeed`,
    `initializeFaultDerateEngineSpeedLimit`, `initializePedalFaultModeEngineSpeedFilter`,
    `presetPedalFaultModeFuelDemand`; CM550 `cm550_runLowSpeedGovernor`, `cm550_runAllSpeedGovernor`,
    `cm550_calculateEngineSpeed`, `mc68k_processAnalogSensorChannels` ...) and the 24-byte A/D channel config record
    (`sensor_config_t`, 25 instances, 4 rows with no user removed).
  - Follow-ups the skeptics listed: CM848's DM8 payload words (0x3fad6f / 0x3fad72 / 0x3fad74) take SPN names; CM550
    enums DIAG_SECURED_SUBFUNC / DIAG_SERVICE_3_CMD 0x42 / 0x52 / 0x54 are wrong for J1708 commands 66 / 82 / 84; the
    legacy descriptor rows at 0x801ab6-0x801b0d; `cm550_peakTorqueFuelCorrection` (0x17ca6, sets
    crank_reentry_speed); `cm550_j1939TorqueControlMode*` (0x1ffd6 / 0x200a4 / 0x200b4) are services 4 / 5 (disable /
    enable broadcast); `cm848_mathMultiplyDivide32` runs on into the routine at 0x573dc; 0x80ddd3 has no reader.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "\n**Round 88.**\n"
     "- **Stage A (ecb02353):** the filter library. `exponentialMovingAverage` paired CM550's signed filter with\n"
     "  CM848's unsigned one; all four filters take prefixed names. CM550's `ema_filter_state_t` and 38 filter records,\n"
     "  37 coefficient words named after CM848's convention.\n"
     "- **Stage C (c964a479):** clip-core keeps chunked dumps aligned (`readInChunks`: retry, pad, list the gaps; unit\n"
     "  tests). The old reader skipped a failed chunk, which shifted CM848's RAM dump and CM550's extended RAM dump.\n"
     "- **Stage D (46b9036e):** the Ghidra loaders put those two dumps' bytes at their addresses\n"
     "  (`ScriptUtils.imageFromDumpWithGaps`).\n"
     "- **Stage B (abe06453):** a second audit workflow: 6 more twins, the split `commitEepromMirrorToEeprom`, CM550's\n"
     "  `ENGINE_STATE` enum, 37 J1939 transmit descriptors as `j1939_tx_msg_t`, the power-down bookkeeping, CM848's\n"
     "  register save / restore helpers.\n"
     "\n## Test plan\n")
edit(pr, "- **Beyond CM848 (rounds 72-87):**", "- **Beyond CM848 (rounds 72-88):**")
edit(pr, "- [x] Round 87: C: ",
     "- [x] Round 88: B: CM550 verify DETERMINISTIC (2 rts-tail functions deleted on purpose; the non-label changes are struct fields, ENGINE_STATE members, removed casts and the CAN ID source-address CONCAT31); CM848 label-only apart from clearWorkingRam; no existing local row moved; headers 0 g++ errors; _cal HARD 0.\n"
     "- [x] Round 88: D: CM550 and CM848 verify DETERMINISTIC with the new RAM blocks; both .cpp byte-identical to stage A's; 109 JUnit tests pass.\n"
     "- [x] Round 88: C: clip-core builds; ctest 1/1 (8 tests; 9 checks fail against the old skip behaviour); kuminz-cli builds.\n"
     "- [x] Round 88: A: CM550 verify DETERMINISTIC (1 function added, 0 removed; caller artifacts down; no local row moved); CM848 label-only; headers 0 g++ errors; _cal HARD 0.\n"
     "- [x] Round 87: C: ")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 88: the filter library, 6 more twins, ENGINE_STATE, the shifted dumps (`session_folder/round88/`)\n\n"
       "- **The audits:** `audit_result_r88.json` / `audit_summary_r88.txt` (the misname audit) and `audit2_result_r88.json`\n"
       "  (the filter callers and the A/D config record, for round 89); `audit_changes.py` (accepted / amended changes as a\n"
       "  TSV, with the skeptics' notes).\n"
       "- **Stage A:** `ema_changes.py`, `precheck_r88a.py`, `apply_r88a.py`, `fix_replaces_notes.py` (refresh_references\n"
       "  rewrites a \"replaces\" note; \"were\" is protected), `apply_r88a2.py` (the A/D loops' record pointer).\n"
       "- **Stage C:** the clip-core change is in the commit; `to_crlf.py` (clip-core is CRLF), `apply_r88c_docs.py`.\n"
       "- **Stage D:** `apply_r88d_loaders.py`, `apply_r88d_docs.py`.\n"
       "- **Stage B:** `precheck_r88b.py`, `apply_r88b0_clear.py` (clearWorkingRam's locals), `apply_r88b.py`,\n"
       "  `quote_enum_comments.py` (enums.csv parses quote-aware), `split_maps.py` / `add_own_only.py` /\n"
       "  `refresh_other_csvs.py` (per-firmware refresh for an old name the two rename differently).\n"
       "- **Closing:** `apply_r88_closing.py`, `update_large_tar_r88.sh`, `verdicts.py`.\n")
if "## Round 88:" not in t:
    i = t.index("## Round 87:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 87: the round 85-86 leads audit (8 twins share one name, the working RAM end marker) - open:",
     "round 87: the round 85-86 leads audit (8 twins share one name, the working RAM end marker); round 88: the filter "
     "library, 6 more twins, ENGINE_STATE, the dump chunk-skip fix - open:")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
for name, pat, rep in (("MEMORY.md", r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)"),
                       ("pr53_egr_flow_delay_rounds.md", r"is still OPEN on 2026-11-24\n\(\d+ commits\)",
                        f"is still OPEN on 2026-11-24\n({count} commits)")):
    p = M + name
    s = open(p).read()
    s2 = re.sub(pat, rep, s)
    assert f"{count} commits" in s2, name
    open(p, "w").write(s2)
log = M + "pr53_egr_flow_delay_rounds.md"
s = open(log).read()
note = ("- Round 88 (the filter library: exponentialMovingAverage paired CM550's signed filter with CM848's unsigned one, "
        "all four prefixed; 6 more twins + ENGINE_STATE + 37 j1939_tx_msg_t descriptors from a second audit; clip-core's "
        "ECUReader skipped failed 0x80 chunks - the cause of both shifted dumps - now readInChunks pads + lists gaps, and "
        "the Ghidra loaders put the bytes back; round 89 = the verified second audit (filter callers, sensor_config_t))\n")
if "- Round 88 (" not in s:
    open(log, "w").write(s.rstrip("\n") + "\n" + note)
print("round 88 closing applied")
