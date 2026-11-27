"""Round 67 closing: task 046, PR body, README, todo, memory. Idempotent (each edit skips when its new text is
already there).  usage: apply_r67_closing.py <repo> <pr_body.md> <hash A> <count> <proof text file>"""
import os
import re
import sys

repo, pr, ha, count, proof_file = os.path.abspath(sys.argv[1]), *sys.argv[2:6]
proof = open(proof_file).read().strip()


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = f"""## Done, round 67 (2026-11-23, same PR): the boot kernel's reflash state machine

A peer relay started the round; the scripts are in `session_folder/round67/`.
- **Stage A ({ha}):**
  - **ECM_STATUS** (was `EEPROM_MAGIC`, applied nowhere) on `eeprom_header_t.ecm_status` (was `magic`): e2m 000B +0
    ECM_Status, EEPROM word 0, "Indicator as to the calibration status of the ECM". 0x600d `CALIBRATION_VALID`
    (the boot ROM runs the operational code only with it), 0x1d0a `REFLASH_IN_PROGRESS` (the application's serial
    reflash request writes it while its image is intact; `mpc555_beginReflash` before the erase), 0x2b16
    `CALIBRATION_DOWNLOADED_NOT_VERIFIED` (`cm848_finishSerialReflash`; no J1939 writer found in the firmware).
    The old 0x2b16 name, "needs programming", had the meaning backwards.
  - **The reflash functions, renamed from their bodies** (no CM550 twins; "reflash" is the CSVs' existing word):
    `mpc555_beginReflash` (was `mpc555_initEepromTransfer`: it erases the internal flash but block 0 and the Bank 2
    chip), `mpc555_verifyDownloadedCalibration` (was `mpc555_loadEepromCalibration`: it sums the image header's
    checksum regions and checks the block list), `cm848_sendBootResultToJ1939Requester`, the service 2 / 7 handlers
    and members (`BEGIN_REFLASH` / `VERIFY_DOWNLOADED_CALIBRATION`), and the serial path's begin / finish / dispatch
    / reset functions.
  - **BOOT_REQUEST_CHANNEL** (2 J1939 / 3 serial) on the five functions that carry the channel, with full
    prototypes.
  - **BOOT_DIAGNOSTIC_RESULT:** 0x15 `DOWNLOAD_INVALID` (was `DOWNLOAD_BLOCK_LIST_FULL`: the verifier sends it too),
    0xfe `RESPONSE_PENDING` added.
  - **Globals:** the serial busy / erase-pending flags; EEPROM 0x50 / 0x52 / 0x54 as the serial reflash flags /
    success count / attempt count; `begin_reflash_request` and `crc_ccitt_table` (was one `eeprom_param_t` over
    both); `download_block_list` (10 x `download_block_range_t` at 0x3028b3, filled by both paths). Four stale flat
    rows inside `eeprom_block_tracking` became field rows. `eeprom_param_t`, the orphan
    `can_tx_status.callback_param` row and the duplicate `DIAGNOSTIC_SERVICE` enum are gone.
  - **Two retypes dropped after the first build:** `cm848_sendDiagServiceResponse`'s result stays `dword` (its body
    reuses the variable: 0x0c rendered as `UNKNOWN_PARAMETER_ID|CANNOT_COMPLY`), and
    `cm848_writeBootDiagnosticMemory` keeps its inferred return (its variable also holds the region type).
- **Corrections to round 66:**
  - The round 66 lead "0xfe has no CM848 producer" was wrong: `cm848_sendDiagResponsePending` sends it.
  - The 0x14 comment and c48cc435's message said CM550's `DIAG_RESPONSE_CODE`; the enum is CM550's
    `J1939_DIAGNOSTIC_RESULT`. c48cc435's message stays as it is.
  - c48cc435's "the write worker passes these up" holds: the J1939 worker returns the tracker's status (asm
    0x5710). For a while this round I misread the worker as dropping it, because my declaration filter
    (`[a-z]* [a-z]Var[0-9]*;`) also hid every `return xVarN;` line.
- **Proof:** {proof}
- **{ha}'s message ends with a `PROOF_LINE` placeholder** instead of the proof above. The command that filled it in
  was refused, and the commit and push sent beside it ran anyway. The pushed commit stays as it is (no force-push).
- **firmware/CLAUDE.md:** no edit.
- **Leads:**
  - **The time-shared header fields at 0x3fee18-0x3fee22.** The boot kernel reads EEPROM 0x50 / 0x52 / 0x54 into
    0x3fee1e / 20 / 22 (`eeprom_status_flags` / `cal_word2` / `cal_word3`). The application's EEPROM mirror holds
    other words there, and e2m names them: 8A24 +0 / +2 (`Fuel_Lvl_In_Range_Filtered` / `_Percent_Tank_Full_Avg`,
    now `calibration_block1`), 8A36 +0 / +2 (`IAH_Inhibit_Postheat_Counter` / `IAH_Redundant_Preheat_Req`), and 8C36
    +0 / +2 (`Chry_Dat42_Previous` / `_Stuck_Times`, read by `cm848_latchAndCheckEngineOffTime`). One type per
    address: about 13 application functions against 3 boot ones, so the application's names should probably win,
    or the struct should end at 0x3fee17.
  - **The boot kernel's `eeprom_*` download vocabulary:** `eeprom_xfer_state`, `eeprom_block_tracking`,
    `eeprom_service_mode_flags` (bit 7 is set by `mpc555_beginReflash` and cleared by the verifier; the low nibble
    gates the ROM handlers), `eeprom_write_request_type` (a serial request byte that other handlers read as a
    word) and `mpc555_processDiagnosticAndEepromRequests`.
  - **The image header at ROM 0x8100:** the checksum region table pointer (0x8104), and the expected block count
    (0x8116) and addresses (0x811a onward), as a struct once the asm settles the layout.
  - **A memory region type enum** (0 RAM / 2 Bank 2 / 3 registers / 4 main flash / 5 EEPROM / 9 not accepted) on
    `cm848_lookupBootMemoryRegionType` and `memory_region_t.region_type`. The worker's variable mixes it with the
    result, so check the render.
  - **The serial response codes** (0x22 / 0x40 / 0x73-0x78 with 0x7f) of `cm848_diagSendResponseCode` /
    `mpc555_sciSendServiceResponse`, once their protocol is read. Channel value 1 is tested but never passed.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 67.**\n"
     f"- **Stage A ({ha}):** the boot kernel's reflash state machine. EEPROM word 0 is typed `ECM_STATUS` (e2m 000B\n"
     "  ECM_Status: valid / reflash in progress / downloaded, not verified). The reflash functions are renamed from\n"
     "  their bodies (begin = mark + erase, verify = checksum the image). `BOOT_REQUEST_CHANNEL` types the channel;\n"
     "  `download_block_list` and `crc_ccitt_table` are typed, and `eeprom_param_t` / a duplicate enum are removed.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 66:", f"- [x] Round 67: {proof}\n- [x] Round 66:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 67: the boot kernel's reflash state machine (`session_folder/round67/`)\n\n"
       "- **Stage A:** `apply_r67a.py` then `fix_r67a2.py` (two retypes dropped after the first build), `map_r67a.csv`,\n"
       "  `params_r67a.csv`. **Proof:** `prove_r67.sh` (renames enum members as text too), `list_differing.py` (all\n"
       "  canonically differing functions; prove_caches.py prints 12). **Closing:** `apply_r67_closing.py`,\n"
       "  `update_large_tar_r67.sh`.\n")
if "## Round 67:" not in t:
    i = t.index("## Round 66:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md",
     "round 66: BOOT_DIAGNOSTIC_RESULT and the coolant friction torque term - open: the task 046 leads",
     "round 66: BOOT_DIAGNOSTIC_RESULT and the coolant friction torque term; round 67: the boot kernel's reflash "
     "state machine (ECM_STATUS) - open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "+ round 66 (BOOT_DIAGNOSTIC_RESULT, the coolant friction torque term); task 046 leads"
new = ("+ round 66 (BOOT_DIAGNOSTIC_RESULT, the coolant friction torque term) + round 67 (the boot reflash state "
       "machine: ECM_STATUS from e2m 000B, the reflash functions, BOOT_REQUEST_CHANNEL, download_block_list, "
       "crc_ccitt_table; time-shared header fields = lead); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
print("round 67 closing applied")
