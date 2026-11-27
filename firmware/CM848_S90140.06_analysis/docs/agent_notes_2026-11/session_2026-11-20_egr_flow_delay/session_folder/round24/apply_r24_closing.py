"""Round 24 closing: stages E and F, the leads, the CLAUDE.md fact. Idempotent. usage: apply_r24_closing.py <repo> <pr>"""
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


T46_OLD = """- **Still to do in round 24:**
  - E: the three fault bit arrays as one `fault_bit_words_t`;
  - F: the shapes of `sensor_readings_t`, `diag_clear_flags_t`, `throttle_fuel_enable_flag` and the executive timing
    records;
  - G: the sensor channel blocks;
  - H: the TouCAN A module registers;
  - I: the kernel's two response messages.
"""
T46_NEW = """- **Stage E (a735961, types): the three 50-word fault bit arrays.**
  - In each array, fault n is bit n % 16 of word n / 16:
    - 0x3fe974: detected, e2m 1036 System_Error_Status_00..49;
    - 0x3fe9d8: registered;
    - 0x3fea3c: previous pass.
  - `cm848_clearDiagnosticState` clears 0x32 words of all three.
  - They are one `fault_bit_words_t` now (`faults_0_to_15` .. `faults_784_to_799`), with three `_cal` instances:
    `fault_detected_cal` / `fault_registered_cal` / `fault_previous_pass_cal`. They had been a 21-word struct named
    `system_status_flags_t` plus flat rows.
  - Each field comment names every bit from e2m 1036 (337 bits; the mask is column 11 of the labelled e2m), with its
    DTC.
  - The flat rows became dotted documentation rows. About 2100 renders now use one form.
  - The proof normalizes every fault word reference to an address token: 0 functions differ, pieces 500 -> 500.
- **Stage F (9ed041a, types):**
  - `sensor_readings_t` (slots 1-4 of `sensor_channel_filtered_output`) became four flat `<channel>_sensor_filtered`
    words like the other slots, and one cast went.
  - `throttle_fuel_enable_flag` (a dword) became `throttle_sensor_fault_flag` + `commanded_throttle_previous`, so
    pieces fell 500 -> 492.
- **A fix to stage B:** fault bits 306 / 307 (sensor channel 26) have no DTC slot. The stage B comment had read the
  ROM 0x5985a slot table as bytes; it holds u16 entries.
- **Round 24 leads:**
  - Named fault bits: e2m 1036 names 337 of the 800 bits, so `fault_bit_words_t` could hold bitfields. The monitors
    set and clear the words with `|=` / `&=` masks, which Ghidra 12.1 prints as pieces, so this is the user's call
    (as `switch_input_state_t` was).
  - `diag_clear_flags_t` (0x3fedfc, EEPROM mirror) is time-shared:
    - The application's word at +0 is the A/C pressure sensor learned flag. `cm848_controlAirConditioningClutchForDrTruck`
      sets it to 1 after `air_conditioning_pressure_learn_time` passes of channel 71 inside the learn window, and it
      gates channel 71's processing.
    - The kernel's byte at +0 is the SCI receive count, and +2 is the learned output speed / vehicle speed ratio.
    - A word typed for the application moves the pieces into the kernel's SCI code, so choose the representation
      first.
  - The executive timing records at 0x40be6a are an array of 12-byte `scheduler_task_stat_t`: `main_loop` clears them
    up to `ram_refresh_enable` and walks `scheduler_task_stat_ptr_b` by 12 a pass. To do: type the array and the two
    walking pointers, and spell out `min_time` / `max_time`.
  - The sensor channel blocks: most channel calls still pass Ghidra labels for their config / state / cache / filter
    / status. Channel 26 (ECM internal temperature) and 68 (fuel level) are identified.
  - The TouCAN A map is wrong. `mpc555_initCanController` shows that 0x307080-0x3070a7 are the module registers
    (TCNMCR 0x5000, CANCTRL0-2, PRESDIV 9, RXGMSK / RX14MSK dwords, IMASK, IFLAG), and the message buffers start at
    0x307100. The repo models 0x307080 / 90 / a0 as message buffers.
  - The kernel's response messages: `cm848_allocateDiagnosticResponseBuffer` returns 0x303056 / 0x303047, two 14-byte
    message records. Their last dword points at a status byte, not a data end, so check the type before using
    `j1939_tx_msg_t`.
  - `j1939_can_ring_buf._pad16` byte 0 is the CAN transmit queue's full flag (`mpc555_canTransmitQueuePush` returns 4
    on it).
  - e2m 1036's two records at +0x64 (EGA / VGA valve over-temperature) fall on the registered array's word 0 here.
    This is 11.45-vs-11.46 drift, or registered bits.
  - `fault_definition_t.definition_flags` bit 0x2000 is clear in every slot, and the J1587 counts are its only test.
  - The editing-firmware-csvs skill says byte enums do not render. They do: `END_OF_LINE_OUTPUT_TEST_STATE` renders 19
    times. The skill text is left for the user.
"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", T46_OLD, T46_NEW)
edit(pr, "- **Stage D (26dd083, label-only):** the J1587 fault counts, the boot SCI / reflash / J1939 transport sessions,\n"
     "  two more instances.\n",
     "- **Stage D (26dd083, label-only):** the J1587 fault counts, the boot SCI / reflash / J1939 transport sessions,\n"
     "  two more instances.\n"
     "- **Stage E (a735961, types):** the three 50-word fault bit arrays (e2m 1036) as one `fault_bit_words_t` with three\n"
     "  `_cal` instances; every bit's e2m name and DTC in the field comments.\n"
     "- **Stage F (9ed041a, types):** sensor channels 1-4 flat like their neighbours; the throttle dword split.\n"
     "- Open after round 24: named fault bits (the user's call), `diag_clear_flags_t`, the executive timing records,\n"
     "  the sensor channel blocks, the TouCAN A register map, the kernel's response messages (task 046).\n")
edit(pr, "- [x] Round 24: stages B, C and D are EQUIVALENT; stage A (comments) leaves the code without comments identical.",
     "- [x] Round 24: stages B, C and D are EQUIVALENT; stage A (comments) leaves the code without comments identical;\n"
     "  stages E and F pass an address-token normalization (0 functions differ; pieces 500 -> 500 -> 492).")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
edit(README, "- **Closing:** `apply_r24_interim.py` (interim, after stage D).\n",
     "- **Stage E:** `fault_bit_names.py` (the e2m 1036 bit table), `apply_r24e.py`, `refresh_r24e.py`, `prove_r24e.py`\n"
     "  (each fault word reference mapped to an address token). **Stage F:** `apply_r24f.py`, `refresh_r24f.py`,\n"
     "  `prove_tokens.py` (a general token-normalized gate for type changes).\n"
     "- **Closing:** `apply_r24_interim.py` (interim, after stage D) and `apply_r24_closing.py`.\n")
edit("work/todo.md", "sessions), the fault bit arrays and four struct shapes in progress - open: the task 046 leads",
     "sessions), the three fault bit arrays as one struct (e2m 1036), sensor channels 1-4 flat, the throttle dword "
     "split - open: the task 046 leads")
edit("firmware/CLAUDE.md",
     "| `_pad2`, `_pad5`, `_pad16` | Structure padding fields — Ghidra internal, not fixable via CSV |",
     "| `_pad2`, `_pad16` | Struct fields whose `structure_definitions.csv` name starts with `_`: naming the field "
     "clears the warning once its use is known. `_pad5` was the boot J1939 transport session's frame queue status "
     "(`frame_queue_status`, PR #53 round 24); `j1939_can_ring_buf._pad16` byte 0 is read as the CAN transmit queue's "
     "full flag |")
print("closing applied")
