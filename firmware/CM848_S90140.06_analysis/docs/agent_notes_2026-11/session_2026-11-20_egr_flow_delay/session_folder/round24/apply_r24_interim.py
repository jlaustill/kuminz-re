"""Round 24 interim closing (stages A-D): task 046, the PR body, the README, the todo line. Idempotent.
usage: apply_r24_interim.py <repo> <pr_body.md>"""
import os
import sys

repo, pr = os.path.abspath(sys.argv[1]), sys.argv[2]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = """## Done, round 24 (2026-11-22, same PR; the relayed "keep going" again): the struct instances named after their Ghidra labels

Scripts are in `session_folder/round24/`. `apply_struct_renames.py` renames struct types, fields and the dotted alias
rows, with round 6's checks.
- **Stage A (1d84f6c, comments):** round 23's lead. 73 present-tense Ghidra labels in CSV comments became the names
  their addresses now have (`classify_labels.py`, `apply_r24a.py`). History mentions stay: 'was', 'rendered',
  'earlier note:', '#' lines and rename arrows. The proof: the `.cpp` without its comments is identical, and every
  changed CSV line differs in its comment column only.
- **Stage B (8de3cf6, label-only): the commanded throttle record.**
  - e2m 1047 lines up with the 14 words at 0x40a57a: `commanded_throttle_state_t` / `commanded_throttle_state` (was
    `fuel_demand_control_t`). Its fields are now:
    - `commanded_throttle` (was `calculated`);
    - `throttle_transition_state` (was `rate_limiter_state`; there is no rate limiter);
    - `throttle_minimum` and its confidence counter (were `throttle_based` / `rate_delta`);
    - `calculated_commanded_throttle` (was `rate_limited`);
    - the alternate throttle trio and the delta.
  - The `cm848_fuelDemand*` functions at 0x1702c-0x17af4 are the throttle validation and selection
    (`cm848_selectCommandedThrottle` ...).
  - e2m 1048 names four ROM words, and the autozero learning's three working words are renamed.
  - `governor_torque_output` (sensor channel 8) is the remote accelerator pedal (EEC2 SPN 974; task 042's lead), with
    its hand-over latch `cm848_verifyRemoteThrottleTransition`. `governor_speed_demand_limit(_prev)` are the dual
    channel pedal's demand.
  - `cm848_lookupFaultIndexByDtcCode`: the table holds P-codes, not SPNs.
  - 0x64428 is IAH_Grid_Off_Voltage_Check_Delay, and e2m 1966 names the fuel level and ECM internal temperature
    outputs.
- **Stage C (44578ee, label-only): the cam / crank sync record.**
  - e2m 819C at 0x40b80a: `cam_crank_sync_state_t` (was `engine_crank_state_t`) with `cam_sync_error_count` /
    `cam_sync_state` / `crank_sync_error_count` / `crank_sync_state`.
  - The TPU-A channel 0 handler is `mpc555_updateCrankSyncState`, and its eight state setters are named by the state
    they enter.
  - The e2m value labels (0-3) do not match the code's 0-4, so no enum. This is task 045's and round 3's lead.
- **Stage D (26dd083, label-only):**
  - `j1587_fault_count_data_cal` (e2m 1097 +C0: the active / previously active fault counts);
  - `active_dtc_cummins_fault_codes_cal` (was `fault_pending_counter_array`);
  - `boot_sci_session_state` and `reflash_transfer_state`;
  - `boot_j1939_transport_transmit_session`, with 12 fields named from the TP code (`_pad5` is the frame queue
    status);
  - `qsmcm_recram` and `system_initialization_flags`.

  The two boot structs get no `_cal`, though they sit in the mirror's range: only boot / kernel code uses them
  (`NOT_CAL` in `worklist_r24d.py`).
- **Still to do in round 24:**
  - E: the three fault bit arrays as one `fault_bit_words_t`;
  - F: the shapes of `sensor_readings_t`, `diag_clear_flags_t`, `throttle_fuel_enable_flag` and the executive timing
    records;
  - G: the sensor channel blocks;
  - H: the TouCAN A module registers;
  - I: the kernel's two response messages.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 24 (the relayed \"keep going\" again): struct instances still named after their Ghidra labels.**\n"
     "- **Stage A (1d84f6c, comments):** 73 present-tense Ghidra labels in CSV comments refreshed (round 23's lead).\n"
     "- **Stage B (8de3cf6, label-only):** the commanded throttle record (e2m 1047 / 1048), the remote and dual channel\n"
     "  pedals, the DTC code lookup.\n"
     "- **Stage C (44578ee, label-only):** the cam / crank sync record (e2m 819C) and its state setters.\n"
     "- **Stage D (26dd083, label-only):** the J1587 fault counts, the boot SCI / reflash / J1939 transport sessions,\n"
     "  two more instances.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 23: stage A is EQUIVALENT",
     "- [x] Round 24: stages B, C and D are EQUIVALENT; stage A (comments) leaves the code without comments identical.\n"
     "- [x] Round 23: stage A is EQUIVALENT")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 24: the Ghidra-label struct instances (`session_folder/round24/`)\n\n"
       "- **Stage A:** `classify_labels.py`, `apply_r24a.py`, `prove_r24a.py`. The proof is comments-only: the code "
       "without comments is identical, and the CSV changes are in comment columns only.\n"
       "- **Stages B-D:**\n"
       "  - `worklist_r24b.py` / `_c` / `_d`, run through `apply_hand_worklist.py` (the snapshot here has the "
       "`NOT_CAL` exemption);\n"
       "  - `spec_r24b.py` / `_c` / `_d`, run through `apply_struct_renames.py` (struct types, fields, dotted alias "
       "rows, qualified references);\n"
       "  - `apply_r24b2.py` (new rows) and `apply_r24b_docs.py`;\n"
       "  - the checks: `instance_users.py`, `fault_bit_names.py` (the e2m 1036 fault bit names), "
       "`definition_flag_2000.py`, `byte_enum_renders.py`.\n"
       "- **Closing:** `apply_r24_interim.py` (interim, after stage D).\n")
if "## Round 24:" not in t:
    i = t.index("## Round 23:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 23: the ambient module and the PGN 65269 payload named, SENSOR_VALUE_SOURCE on ten more source "
     "words - open: the task 046 leads",
     "round 23: the ambient module and the PGN 65269 payload named, SENSOR_VALUE_SOURCE on ten more source "
     "words; round 24: the struct instances named after their Ghidra labels (the commanded throttle record e2m 1047, "
     "the cam / crank sync record e2m 819C, the J1587 fault counts, the boot J1939 transport / SCI / reflash "
     "sessions), the fault bit arrays and four struct shapes in progress - open: the task 046 leads")
print("interim closing applied")
