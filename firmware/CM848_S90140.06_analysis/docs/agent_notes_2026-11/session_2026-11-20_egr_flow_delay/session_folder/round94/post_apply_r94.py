"""Round 94: the hand fixes after applying the judged batches F1 / J1 / J2 / D1 (each old text must occur exactly once
in its row or file; idempotent):
- the comment refresh had replaced e2m mnemonic DCMNLGMP (the old name of row 0x80546c) inside two e2m citations,
  and the old row names inside D1's removal notes: the citations get DCMNLGMP back and the notes become 'were ...'
  history (which later refreshes leave alone);
- J1: analog_sensor_override_values has writers (elements [10] / [11]); 0x206a8's prototype takes
  (logical_input, output_number) under its current name (move.l (0x14,a7),d2 / move.l (0x18,a7),d3 after a 16-byte
  movem; d2 + 208 is the override enable bit, d3 / 8 and d3 & 7 index the bit array at 0x80bcf6);
- F1: CM848's FUELING_STATE header lists (49 50) as the unidentified members now;
- D1: the can_buffer_setup_t type is removed with its instance (0x801a8a is the serial EEPROM driver's state);
- docs: advanceHourMeters (the CM848 twin rename) in two CM848 files, and a correction note in clip-protocol-spec.md
  (0x801998 / 0x8019b8 are fields of engine_tsc1_ignored_request_entries, not dispatch pointers / counters).
usage: post_apply_r94.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
R = "PR #53 round 94"
C5 = "firmware/CM550_J90350.00_analysis/output"
C8 = "firmware/CM848_S90140.06_analysis/output"
done = []


def read(rel):
    return open(os.path.join(repo, rel), newline="").read()


def write(rel, text):
    open(os.path.join(repo, rel), "w", newline="").write(text)


def edit_row(rel, key, pairs):
    """Replace text inside the one line that starts with key + ','."""
    text = read(rel)
    lines = text.split("\n")
    idx = [i for i, l in enumerate(lines) if l.startswith(key + ",")]
    assert len(idx) == 1, (rel, key, len(idx))
    line = lines[idx[0]]
    for old, new in pairs:
        if new in line and old not in line:
            continue
        assert line.count(old) == 1, (rel, key, old[:60], line.count(old))
        line = line.replace(old, new)
    lines[idx[0]] = line
    write(rel, "\n".join(lines))
    done.append(f"{rel} {key}")


def edit_file(rel, pairs):
    text = read(rel)
    for old, new in pairs:
        if new in text and old not in text:
            continue
        assert text.count(old) == 1, (rel, old[:60], text.count(old))
        text = text.replace(old, new)
    write(rel, text)
    done.append(rel)


G = f"{C5}/global_variables.csv"
edit_row(G, "0x0080546c", [("e2m 1125 +0 duty_cycle_monitor_long_term_map_byte_count ", "e2m 1125 +0 DCMNLGMP ")])
edit_row(G, "0x0080546e", [
    ("(e2m 1125 duty_cycle_monitor_long_term_map_byte_count, 0.1 s per count)", "(e2m 1125 DCMNLGMP, 0.1 s per count)"),
    ("Eight live rows lie inside and should go (undefined type, no ROM reference): 0x8054a6 j1939_message_type_total_counter, "
     "0x8054a8 vp44_sensor_diag_counter, 0x8054ac rpm_histogram_bin_1_counter, 0x8054ae loop_counter_snapshot_0, "
     "0x8054b2 rpm_histogram_bin_2_counter, 0x8054b4 loop_counter_snapshot_1, 0x8054b8 rpm_histogram_overflow_counter, "
     "0x8054ba loop_counter_snapshot_2.",
     "The eight rows inside it are removed (undefined type, no ROM reference; were 0x8054a6 j1939_message_type_total_counter, "
     "0x8054a8 vp44_sensor_diag_counter, 0x8054ac rpm_histogram_bin_1_counter, 0x8054ae loop_counter_snapshot_0, "
     "0x8054b2 rpm_histogram_bin_2_counter, 0x8054b4 loop_counter_snapshot_1, 0x8054b8 rpm_histogram_overflow_counter "
     "and 0x8054ba loop_counter_snapshot_2)."),
])
edit_row(G, "0x00800000", [
    ("The row 0x800002 duty_cycle_monitor_load_ratio._2_2_ (typed word in the live CSV) is that low word and should go.",
     "The row at 0x800002 is removed: it was that low word (was rpm_control_timer_1, typed word)."),
])
edit_row(G, "0x00800006", [
    ("The row 0x800008 rpm_control_timer_previous (no ROM reference) is its low word and should go.",
     "The row at 0x800008 is removed: it was its low word, with no ROM reference (was rpm_control_timer_previous)."),
])
edit_row(G, "0x00800010", [
    ("table_lookup_2d_arguments_t is a NEW struct (layout in the notes).",
     "table_lookup_2d_arguments_t is the 22-byte argument record of cm550_tableLookup2D (structure_definitions.csv)."),
    ("The live rows 0x800012 (unnamed dword), 0x800014 rpm_state_lookup_input, 0x800016 duty_cycle_monitor_steady_state_fueling_lookup.x_input, "
     "0x80001a duty_cycle_monitor_steady_state_fueling_lookup.y_axis_pointer, 0x80001c dma_desc2_source_ptr, "
     "0x800020 duty_cycle_monitor_steady_state_fueling_lookup.z_values_pointer and 0x800022 dma_desc2_dest_ptr lie inside it.",
     "The rows inside it are removed (were 0x800012 an unnamed dword, 0x800014 rpm_state_lookup_input, 0x800016 dma_desc1_dest_ptr, "
     "0x80001a dma_descriptor_base2, 0x80001c dma_desc2_source_ptr, 0x800020 high_rpm_lookup_input and 0x800022 dma_desc2_dest_ptr)."),
])
edit_row(G, "0x00800026", [
    ("The live rows 0x80002a dma_control_flags1, 0x80002e duty_cycle_monitor_transient_fueling_lookup.y_axis_offset, "
     "0x800032 dma_control_flags2 and 0x800036 duty_cycle_monitor_transient_fueling_lookup.z_values_pointer lie inside it.",
     "The rows inside it are removed (were 0x80002a dma_control_flags1, 0x80002e dma_descriptor_ptr2, 0x800032 dma_control_flags2 "
     "and 0x800036 sensor_fault_debounce_counter_base)."),
])
edit_row(G, "0x00801a8a", [
    ("It is not a CAN buffer: the can_buffer_setup_t instance at 0x801a8a should go, with its member rows 0x801a8c can_buffer_setup1_data_ptr, "
     "0x801a90 can_buffer_setup1_unused_ptr and 0x801a94-0x801a9c (can_buffer_setup1_data, can_buffer_1_reserved_0-3, "
     "diag_can_response_data_0-2, .data[6]); 0x801a94 starts a 2D lookup record of cm550_FUN_000269f2.",
     "It is not a CAN buffer: the can_buffer_setup_t type and its instance here are removed, with the rows 0x801a8c / 0x801a90 "
     "inside the driver's words (were can_buffer_setup1_data_ptr / can_buffer_setup1_unused_ptr). 0x801a94 starts a 2D lookup "
     "record of cm550_FUN_000269f2."),
])
edit_row(G, "0x0080a72e", [
    ("no writer in the dumped ROM (a service-tool value)",
     "cm550_processJ1939AcceleratorPedalPosition writes element [10] (0x80a742) and cm550_processJ1939RemoteAcceleratorPedalPosition "
     f"element [11] (0x80a744); the other elements have no writer in the dumped ROM (service-tool values; {R})"),
])
F = f"{C5}/function_definitions.csv"
edit_file(F, [
    ("0x000206a8,ptpSwitchedInputDebouncer,0,input_state,uint,Current raw input state",
     "0x000206a8,cm550_copyOutputBitToSwitchOverrideValue,0,logical_input,uint,the logical input number - its override "
     f"enable is bit input + 208 of the algorithm enable words (move.l (0x14 a7) to d2; {R})"),
    ("0x000206a8,ptpSwitchedInputDebouncer,1,debounce_mask,uint,Debounce configuration mask",
     "0x000206a8,cm550_copyOutputBitToSwitchOverrideValue,1,output_number,uint,the output whose bit is copied - bit "
     f"output mod 8 of byte output / 8 at 0x80bcf6 (move.l (0x18 a7) to d3; {R})"),
])
edit_file(f"{C8}/enums.csv", [("FUELING_STATE_UNIDENTIFIED_<n> (37 38 49 50)", "FUELING_STATE_UNIDENTIFIED_<n> (49 50)")])
S = f"{C5}/structure_definitions.csv"
text = read(S)
E = "\r\n" if "\r\n" in text else "\n"
block_start = text.find(f"# -----------------------------------------------------------------------------{E}# CAN Buffer Setup Structures @ RAM 0x801A8A")
marker = "can_buffer_setup_t,0x00801A8A,,,,can_buffer_setup_t_00801a8a - CAN buffer setup instance (instance marker),,verified"
if block_start >= 0:
    block_end = text.index(marker, block_start) + len(marker)
    block = text[block_start:block_end]
    assert block.count("can_buffer_setup_t,") == 5, block.count("can_buffer_setup_t,")
    text = (text[:block_start]
            + f"# (can_buffer_setup_t @ 0x801A8A removed in {R}: the words there are the serial EEPROM driver's state -"
              f" eeprom_byte_write_state / eeprom_mirror_base_pointer / eeprom_mirror_loaded_flag in global_variables.csv)"
            + text[block_end:])
    write(S, text)
    done.append(f"{S} can_buffer_setup_t removed")
assert "can_buffer_setup_t," not in read(S)
edit_file("firmware/CM848_S90140.06_analysis/docs/engine_hours_and_odometer.md", [
    ("`cm848_advanceHourMeters` (flash2 0x506780, was `cm848_mainLoop_step_4`)",
     "`advanceHourMeters` (flash2 0x506780, was `cm848_advanceHourMeters` / `cm848_mainLoop_step_4`)"),
])
edit_file("firmware/CM848_S90140.06_analysis/tools/read_engine_hours.sh", [
    ("#   cm848_advanceHourMeters (flash2 0x506780) runs", "#   advanceHourMeters (flash2 0x506780) runs"),
])
NOTE = ("> **Correction (PR #53 round 94):** 0x801994-0x8019bb is `engine_tsc1_ignored_request_entries` (five 8-byte "
        "`engine_tsc1_ignored_request_t` records: data link / source address / control mode / countdown), not a dispatch "
        "table. 0x8019B8 (`diag_service_pgn_dispatch_ptr` here) is the control mode of entry 4, and 0x801998 "
        "(`diagnostic_service_state_counter`) is the control mode of entry 0: the TSC1 code indexes both as entry fields. "
        "The dispatch loops below are an older reading of the decompilation.")
SPEC = "work/docs/clip-protocol-spec.md"
NL = "\r\n" if "\r\n" in read(SPEC) else "\n"
edit_file(SPEC, [
    ("| 0x008018D8 | `diagnostic_service_dispatch_ptr` | Service byte routing | `diagnostic_service_state_counter` |" + NL,
     "| 0x008018D8 | `diagnostic_service_dispatch_ptr` | Service byte routing | `diagnostic_service_state_counter` |" + NL + NL + NOTE + NL),
])
print("\n".join(done))
