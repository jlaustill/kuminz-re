"""Round 87 closing: task 046, PR body, session README, todo, the memory round log. Idempotent.
usage: apply_r87_closing.py <repo> <pr_body.md> <hash A> <hash B> <count> <proof A file> <proof B file>"""
import os
import re
import sys

repo, pr, ha, hb, count, pa_file, pb_file = os.path.abspath(sys.argv[1]), *sys.argv[2:8]
proof_a, proof_b = open(pa_file).read().strip(), open(pb_file).read().strip()


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = f"""## Done, round 87 (2026-11-24, same PR): the round 85-86 leads audit; 8 twins share one name

Peer relays started and continued the round (07:50, 08:20, 08:50, 09:20). The scripts are in `session_folder/round87/`,
with the audit's proposals and verdicts (`audit_result_r87.json`, `audit_summary_r87.txt`).
- **Stage A ({ha}), the audit:** a workflow of 5 read-only investigators and 5 skeptics checked round 85-86's leads in
  five groups (twins, the chip select 5 CAN functions, speed sensing, the restart routine, the filter library). Four
  groups are applied here; the filter library is round 88's.
  - 8 cross-firmware twins now share one unprefixed name: `restartOnKeyOnDuringPowerDown`,
    `copyCalibrationFromRomToRam`, `clearWorkingRam`, `getJ1939DiagnosticResponseEchoLength`,
    `executiveFrameInterruptHandler` (both were `main_loop`: the periodic interrupt timer's handler, one frame of the
    40-phase executive per interrupt), `restartThroughBootRom`, `handleJ1939RestartService` and
    `ignoreCanTransmitInterrupt` (the skeptic found its CM848 half, 0x26f78). `runPowerDownSequence` was rejected:
    the two are counterparts.
  - CM550: the chip select 5 CAN receive dispatcher and its two interrupt branches (`vp44_`; there is no "mode"), the
    engine speed sync pulse functions, the PWM 3 / 4 start-up test, the discrete output set-up, the restart entries,
    and 13 globals placed by CM550's own parameter ID table: `engine_state` (was `smoke_limiter_output_value`), the
    parameter blocks' save start / complete counts and checksums, `power_down_start_flag`,
    `power_down_refresh_enable`, `parameter_block_uploaded`, `flash_write_failure_flag_cal` (its old name had the
    polarity backwards) and the DM8 test identifier / value.
  - CM848: `cm848_copyROMCalibrationToRAM` -> `cm848_loadDefaultJ1939NamesAndSourceAddresses` (it copies the default
    J1939 NAMEs and source addresses).
  - **Proof:** {proof_a}
- **Stage B ({hb}), the skeptics' apply notes and two finds:**
  - Plate fixes: the call position, J1708 message type 3 then command 67, the block number, the erase-or-program
    failure, the two power-down waits, one 4-byte store per step, the `ram_refresh_enable` wait; the parameter block
    saver plates in the new vocabulary.
  - Old names refreshed in `function_definitions.csv` / `enums.csv` / `structure_definitions.csv` /
    `local_variables.csv`, which `refresh_references.py` does not cover (`refresh_other_csvs.py`, newline-preserving:
    its `--text` mode would rewrite a CRLF file with LF).
  - CM550: 0x15dd0 `cm550_initializeDiscreteInputs` (was `vp44_initVP44StatusMonitoring`); service 0x0B's enum member
    takes CM848's name; the 0x803b15 `ecu_serial_number` row is removed (the low byte of the block 2 checksum, with no
    access of its own).
  - CM848: the working RAM end marker. `cm848_writeWorkingRamEndMarker` (was `cm848_timer_state_preservation`) writes
    0xC0DAC0DA to `working_ram_end_marker` (0x41428e, the end of the RAM that `clearWorkingRam` clears) at start-up;
    `cm848_checkWorkingRamEndMarker` (was `cm848_main_loop_initialization`) sets fault 462
    (`working_ram_end_marker_error`, no DTC slot) when it is gone. `executive_frame_phase` (was
    `main_loop_scheduler_phase`).
  - **Proof:** {proof_b}
- **firmware/CLAUDE.md:** stage A renamed the CM848 functions in three lines; stage B corrected the ROM-to-RAM line (the
  copy is `cm848_copyBootKernelToRam`, 0x340, not `copyCalibrationToRam()`). Old and new lines are in the commits.
- **Leads (round 88):**
  - The filter library group, verified and not applied. 0x34e9a is the signed (offset binary) first-order filter, and
    CM848's `exponentialMovingAverage` (0x56594) is the unsigned one, so their shared name pairs the wrong functions.
    By role 0x34e9a pairs with `cm848_signedFirstOrderFilter` and 0x34f8a with CM848's unsigned filter; the
    formulations differ (a rounded multiply against a truncated step), so they are counterparts. Proposed:
    `cm550_signedFirstOrderFilter`, `cm550_exponentialMovingAverage` (0x34f8a, was `cm550_coreTableInterpolation`),
    `cm550_secondOrderFilter` (0x34f00), `cm550_secondOrderFilterUnsigned` (0x34fe0, not yet a function), CM848
    `cm848_exponentialMovingAverage`; CM550's `ema_filter_state_t` / `second_order_filter_state_t` with 38 instances
    and 30 coefficient words.
  - Misnames the agents saw in passing (not verified): `vp44_validateRedundantSensors` (0x114d4, the start-up block
    selection and power-cycle bookkeeping), `_vp44_reset_count` (0x803fec = `completed_power_down_count_cal`),
    `cm550_activateHighRpmShutdownFlag` (0x118fc, service 6 engine shutdown), `cm550_FUN_00011a68` (service 24,
    inhibit key-off shutdown), `cm550_systemFunction8xMaximum` / `cm550_coreSystemFunction` (the J1939 diagnostic
    service registrar), `vp44TimingFaultMonitor` (0x17f7c, the engine state update), `cm550_canMemoryPointerTableInit`
    / `cm550_canMessageMemorySyncController` (the RAM refresh), 0x80bcf8 (an output request byte),
    `mc68k_FUN_00003abe` (the boot block's warm restart entry), 0x803fda (Poweroff_Command_Ignored).
  - `cm550_serialNodeAddressChecker` (0x1e056) matches CM848's `cm848_handleCanMailboxTransmitComplete` step for
    step: a twin lead.
  - Struct and enum leads: the DM8 transmit descriptor 0x803462-0x803478; `engine_state` wants CM848's `ENGINE_STATE`.
  - CM848 0x4bd00's body labels `sensor_channel_cal_block_start` (0x3feed0) / `sensor_channel_ram_start` are the
    calibration RAM image's ends.
  - `clearWorkingRam` in both twins: `dword *` local rows would drop the pointer casts that the marker's dword type
    brought into CM848's loop, and CM550's twin still ends at a raw 0x80def4.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "\n**Round 87.**\n"
     f"- **Stage A ({ha}):** an audit workflow (5 investigators, 5 skeptics) of round 85-86's leads. 8 cross-firmware\n"
     "  twins now share one name (`executiveFrameInterruptHandler` was `main_loop` in both; `restartThroughBootRom`,\n"
     "  `clearWorkingRam`, `copyCalibrationFromRomToRam`, ...); CM550's chip select 5 CAN, speed sensing and restart\n"
     "  functions; 13 CM550 globals placed by its own parameter ID table.\n"
     f"- **Stage B ({hb}):** the skeptics' plate fixes, old names refreshed in four more CSVs,\n"
     "  `cm550_initializeDiscreteInputs`, and CM848's working RAM end marker (`cm848_writeWorkingRamEndMarker` /\n"
     "  `cm848_checkWorkingRamEndMarker`, fault 462).\n"
     "\n## Test plan\n")
edit(pr, "- **Beyond CM848 (rounds 72-86):**", "- **Beyond CM848 (rounds 72-87):**")
edit(pr, "- [x] Round 86: D: ", f"- [x] Round 87: B: {proof_b}\n- [x] Round 87: A: {proof_a}\n- [x] Round 86: D: ")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 87: the round 85-86 leads audit; 8 twins share one name (`session_folder/round87/`)\n\n"
       "- **The audit:** `audit_result_r87.json` (the workflow's proposals and verdicts), `audit_summary_r87.txt`,\n"
       "  `summary.py`, `final_changes.py` / `final_changes.tsv` (the accepted and amended changes).\n"
       "- **Stage A:** `precheck.py`, `apply_r87a.py`, `apply_r87a2.py` (comment tidy; the CM848 J1939 defaults copy),\n"
       "  `old_name_sweep.py`, `token_diff.py` (a per-function token diff that ignores line wrapping), `fix_map_header.py`,\n"
       "  the maps and the proof outputs.\n"
       "- **Stage B:** `apply_r87b.py`, `refresh_other_csvs.py` (old names in the four CSVs refresh_references.py does not\n"
       "  cover), `fault_pcode.py` (fault number -> OBD P-code).\n"
       "- **Closing:** `apply_r87_closing.py`, `update_large_tar_r87.sh`.\n")
if "## Round 87:" not in t:
    i = t.index("## Round 86:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 86: CM550's stack parameters in 2-byte slots (custom storage, 120 placed prototypes) - open:",
     "round 86: CM550's stack parameters in 2-byte slots (custom storage, 120 placed prototypes); round 87: the round "
     "85-86 leads audit (8 twins share one name, the working RAM end marker) - open:")
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
note = ("- Round 87 (an audit workflow of round 85-86's leads: 8 twins share one unprefixed name, executiveFrameInterruptHandler "
        "was main_loop in both; refresh_references.py skips function_definitions / enums / structure_definitions / "
        "local_variables and its --text mode turns CRLF into LF - use r87/refresh_other_csvs.py; the CM848 working RAM "
        "end marker (fault 462); round 88 = the verified filter library group: exponentialMovingAverage pairs CM550's "
        "signed filter with CM848's unsigned one)\n")
if "- Round 87 (" not in s:
    open(log, "w").write(s.rstrip("\n") + "\n" + note)
print("round 87 closing applied")
