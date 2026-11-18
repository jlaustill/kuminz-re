"""Apply a batch of wave-11 shape decisions (structs / arrays / bitfields / type fixes) to the CM848 CSVs.

The agents' proposals (result_W11_*.jsonl) give the layouts; this script carries the reviewer's decisions: which
shapes, the field lists (merged with commit-2 field renames), demoted guessed bits (reserved_bit_N, the guess kept
in the comment), and the type splits. Rows inside a new shape are found by address from the CURRENT CSVs (the
agents' drop lists predate commits 1-2). Every new name goes through the rename gate's rules; overlaps fail.

Usage: apply_shapes.py <output dir> <result dir> <batch: A|B> [--apply]"""
import glob
import json
import os
import re
import sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__))))
out_dir, result_dir, batch = sys.argv[1:4]
APPLY = "--apply" in sys.argv
GV = os.path.join(out_dir, "global_variables.csv")
SD = os.path.join(out_dir, "structure_definitions.csv")
BANNED = {"temp", "tmp", "press", "pos", "corr", "coef", "coeff", "thresh", "thr", "inj", "qty", "ctrl", "cfg",
          "cmd", "val", "vals", "idx", "cnt", "num", "ref", "spd", "eng", "prot", "lim", "mult", "comp", "adj", "trq",
          "tbl", "lkp", "sw", "calc", "accel", "decel", "pct", "freq", "volt", "amp", "deg", "sec", "diag", "cond", "req",
          "resp", "init", "tmr", "buf", "aux", "arb", "iat", "imt", "proc", "mgr", "util", "info", "stat", "msg"}
EEPROM = (0x3fd482, 0x3feec1)
SIZE = {"byte": 1, "word": 2, "dword": 4, "short": 2, "i16": 2, "pointer": 4, "word*": 4, "byte*": 4, "dword*": 4}

proposals = {}
for path in glob.glob(os.path.join(result_dir, "result_W11_*.jsonl")):
    for line in open(path):
        if line.strip():
            r = json.loads(line)
            if r["kind"] == "bitfield_proposal":
                proposals[("bits", r["address"])] = r


def bits_of(address, demote=()):
    """[(bit, name, comment)] for all bits of a bitfield proposal, guessed bits demoted to reserved_bit_N."""
    r = proposals[("bits", address)]
    out = []
    for b in sorted(r["bits"], key=lambda b: b["bit"]):
        name, ev = b["name"], " ".join(b.get("evidence", "").split())
        if b["bit"] in demote:
            ev = f"guess (not proven, so reserved): {name} - {ev}"
            name = f"reserved_bit_{b['bit']}"
        out.append((b["bit"], name, ev))
    return out


def words(name):
    out = []
    for p in name.split("_"):
        out += [w.lower() for w in re.findall(r"[A-Z]?[a-z]+|[A-Z]+(?![a-z])|\d+", p)]
    return out


problems = []


def gate(name, address=None):
    bad = sorted(set(words(name)) & BANNED)
    if bad:
        problems.append(f"{name}: banned {bad}")
    if address is not None and not name.startswith("reserved"):
        in_eeprom = EEPROM[0] <= address <= EEPROM[1]
        if in_eeprom != name.endswith("_cal"):
            problems.append(f"{name} @0x{address:06x}: _cal rule (EEPROM mirror={in_eeprom})")


def q(text):
    text = " ".join(text.split())
    return f'"{text}"' if ("," in text or '"' in text) else text


# ---------------- the batch ----------------
STRUCTS = []     # (type, address or "", [(field, type, size, comment)], replace_existing)
GLOBALS = []     # (address, name, type, span_bytes, comment)
if batch == "A":
    STRUCTS += [
        ("governor_output_t", "0x0040aec2", [
            ("idle_reference_speed", "word", 2, "Low speed governor idle reference speed in 1/8 rpm (6000 = 750 rpm in the RAM dump) - the high word of the old integrator dword"),
            ("fuel_feed_forward_quantity", "short", 2, "Signed fuel feed-forward quantity (lha @ 0x28060) - the low word of the old integrator dword"),
            ("governor_output", "word", 2, "Idle-speed candidate number 0-12 (name kept; see the wave-11 note)"),
            ("idle_speed_barometric_ramped", "dword", 4, "Barometric-ramped idle speed (lwz / stw @ 0x2931c / 0x29440) - the old word field governor_output_high covered only its high half")], True),
        ("protection_timer_state_t", "0x0040b100", [
            ("status_code", "word", 2, "Status code 1-0x18 (sth / lha / lhz) - the high word of the old status_code dword"),
            ("status_code_hold_timer", "word", 2, "Countdown loaded from protection_timer_status_code_b_cal and decremented in cm848_decrementProtectionTimers"),
            ("timeout_counter", "word", 2, "Timeout counter"),
            ("state1_timer", "word", 2, "State 1 timer"),
            ("state2_timer", "word", 2, "State 2 timer")], True),
        ("engine_rpm_state_t", "0x0040b7ac", [
            ("filtered_rpm", "word", 2, "Moving average of engine_rpm_measured (1/8 rpm)"),
            ("crank_capture_period_sum", "dword", 4, "Crank capture period sum (lwz / stw) - averaged by the vehicle speed interrupt"),
            ("crank_tooth_period_sum", "dword", 4, "Crank tooth period sum (lwz / stw)"),
            ("crank_capture_period_sample_count", "word", 2, "Samples in crank_capture_period_sum"),
            ("crank_tooth_period_sample_count", "word", 2, "Samples in crank_tooth_period_sum"),
            ("current_rpm", "word", 2, "Written with the same value as filtered_rpm by the same three writers")], True),
        ("protection_status_flags_t", "0x0040b0f2",
            [(n if bit == 7 else n, f"bitfield:1@{bit}", 1 if i == 0 else 0, c)
             for i, (bit, n, c) in enumerate(sorted(bits_of("0x0040b0f2", demote={3, 4}), reverse=True))]
            + [("reserved_01", "byte", 1, "Pad byte of the old status_flags word (no access)"),
               ("flags", "byte", 3, "Flags (3 bytes as before)"),
               ("output_flags", "byte", 1, "Output flags"),
               ("reserved_06", "byte", 1, "Reserved"),
               ("rate_limit_flags", "byte", 1, "Rate limit flags")], True),
        ("monitor_condition_bits_t", "",
            [(n, f"bitfield:1@{bit}", 4 if i == 0 else 0, c) for i, (bit, n, c) in enumerate(bits_of("0x0040b9d0"))], False),
        ("logical_output_request_bits_16_to_23_t", "",
            [(n, f"bitfield:1@{bit}", 1 if i == 0 else 0, c) for i, (bit, n, c) in enumerate(bits_of("0x0040c082", demote={0}))], False),
        ("qadc_channel_dispatch_entry_t", "", [
            ("result_register", "word*", 4, "Points at the QADC result register of this channel slot"),
            ("shared_zero_word_pointer", "pointer", 4, "0x57dd0 in all 129 records")], False),
        ("fault_definition_t", "", [
            ("cummins_fault_code", "word", 2, "Cummins fault code of the slot (cross-checked against obd_dtc_code_table for slots 1-13)"),
            ("definition_flags", "word", 2, "Definition flags"),
            ("entry_flags", "byte", 1, "Entry flags"),
            ("aging_flags", "byte", 1, "Aging flags")], False),
        ("fault_monitor_group_t", "", [
            ("fault_slots", "byte", 16, "The fault slots of one OBD monitor group (lbzx @ 0x53469c)")], False),
        ("monitor_calibrated_condition_t", "", [
            ("disabled_monitor_mask", "dword", 4, "Monitors this condition disables"),
            ("parameter_id", "word", 2, "Parameter ID of the value it tests"),
            ("parameter_byte_offset", "word", 2, "Byte offset added to the parameter's address"),
            ("comparison_type", "word", 2, "Comparison type"),
            ("comparison_value", "word", 2, "Comparison value")], False),
    ]
    # protection_condition_flags_t: only its fault_state_flags byte (+8) becomes a bitfield; the other rows stay
    GLOBALS += [
        ("0x00057dd2", "qadc_channel_dispatch_table", "qadc_channel_dispatch_entry_t[129]", 129 * 8, "QADC channel dispatch table: one record per channel slot (result register pointer + a shared zero-word pointer); the analog read is *qadc_channel_dispatch_table[qadc_channel_index_table[k]].result_register. Typed as a record array 2026-11-18"),
        ("0x00059e9a", "fault_definition_table", "fault_definition_t[170]", 170 * 6, "One record per fault slot (lis / addi = 0x59e9a @ 0x5349f4): Cummins fault code / definition flags / entry flags / aging flags. Typed 2026-11-18"),
        ("0x0005b6e6", "fault_monitor_group_table", "fault_monitor_group_t[32]", 32 * 16, "32 OBD monitor groups of 16 fault slots each (lbzx @ 0x53469c; ends at 0x5b8e6). Typed 2026-11-18"),
        ("0x00409efc", "monitor_calibrated_condition_table", "monitor_calibrated_condition_t[10]", 10 * 12, "10 calibrated monitor-disable conditions scanned by cm848_evaluateCalibratedMonitorDisableConditions (all zero in the RAM dump). Typed 2026-11-18"),
        ("0x0006430e", "monitor_enabling_condition_masks", "word[32]", 64, "ROM: per-monitor mask over the 16-bit condition word built by cm848_updateMonitorEnablingConditions (new row 2026-11-18)"),
        ("0x0006434e", "monitor_battery_voltage_latch_masks", "word[32]", 64, "ROM: per-monitor mask of the battery-voltage latch conditions (new row 2026-11-18)"),
        ("0x0006438e", "monitor_enabling_condition_expected_values", "word[32]", 64, "ROM: per-monitor expected value of the masked condition word (new row 2026-11-18)"),
        ("0x000643ce", "monitor_battery_voltage_latch_expected_values", "word[32]", 64, "ROM: per-monitor expected value for the battery-voltage latch (new row 2026-11-18)"),
        ("0x0040b9d0", "monitor_enabling_conditions_met", "monitor_condition_bits_t", 4, None),
        ("0x0040b9d4", "monitor_battery_voltage_error_latch", "monitor_condition_bits_t", 4, None),
        ("0x0040c082", "logical_output_request_bits_16_to_23", "logical_output_request_bits_16_to_23_t", 1, None),
        ("0x0040b0fe", "converter_clutch_transition_state", "byte", 1, "Converter clutch transition flags byte (23 accesses - all lbz / stb): bit 0 transition / bit 1 retarder forced gear 2 / bit 2 transition timeout are the wave-11 agent's medium-confidence readings, so no bitfield yet (was protection_condition_state, a word)"),
        ("0x0005774b", "pci_receive_message_table", "pci_message_descriptor_t[15]", 15 * 28, None),
        ("0x000578ef", "pci_transmit_message_table", "pci_message_descriptor_t[25]", 25 * 28, None),
        ("0x0040addc", "j1939_dm13_requester_slots", "j1939_dm13_requester_slot_t[3]", 18, "DM13 stop / start broadcast requester slots (loop bound 3). Typed as an array 2026-11-18 (was j1939_dm13_requester_slot_0 with flat rows for slots 1-2)"),
        ("0x0040b5e2", "sci_buffer", "byte[32]", 32, None),
        ("0x0040af0c", "fault_handled_bitmap", "byte[22]", 22, None),
        ("0x0040c094", "logical_output_request_priority", "byte[80]", 80, None),
        ("0x0040a817", "fault_enable_bitmask_array", "word[50]", 100, None),
        # the type splits
        ("0x0040a164", "fuel_boost_mode_state", "i16", 2, None),
        ("0x00408d4a", "transmission_temperature_rationality_cold_soak_maximum_temperature", "i16", 2, None),
        ("0x00408d52", "transmission_temperature_rationality_minimum_swing", "i16", 2, None),
        ("0x003fafda", "governor_rpm_reference_ramped", "word", 2, None),
        ("0x003fafdc", "governor_rpm_reference_target", "word", 2, None),
        ("0x0040b12a", "transmission_output_speed_change", "i16", 2, None),
        ("0x0040b12c", "converter_clutch_apply_delay_countdown", "word", 2, None),
        ("0x0040af28", "governor_fuel_demand_command", "word", 2, None),
        ("0x0040af2a", "governor_speed_error_term", "i16", 2, "Signed speed error term - the low word of the old governor_integrator_state_b dword (lha) (new row 2026-11-18)"),
        ("0x003fed91", "fault_auto_clear_warm_up_cycle_count_cal", "byte", 1, None),
        ("0x003fed92", "fault_entry_pointer_queue_count_cal", "byte", 1, "Count of fault_entry_ptr_queue (byte) - freed by narrowing 0x3fed91 to a byte (new row 2026-11-18)"),
        ("0x003fb5ae", "injection_fuel_quantity_snapshot_previous", "word", 2, None),
        ("0x003fb5b0", "crank_period_timeout_count", "word", 2, None),
    ]
if batch == "B":
    def bits16(address, demote=()):
        return [(n, f"bitfield:1@{bit}", 2 if i == 0 else 0, c) for i, (bit, n, c) in enumerate(bits_of(address, demote))]
    STRUCTS += [
        ("engine_overspeed_event_t", "", [
            ("start_key_on_hour_meter", "dword", 4, "Key-on hour meter when the overspeed started (lwz / stw)"),
            ("engine_speed_at_detection", "word", 2, "Engine speed at detection (1/8 rpm)"),
            ("duration", "word", 2, "Duration of the overspeed")], False),
        ("dtc_list_t", "", [
            ("count", "byte", 1, "Number of codes in the list (the loops are 1-based from this byte)"),
            ("slots", "byte", 31, "The listed fault slots")], False),
        ("fault_state_t", "", [
            ("timestamp", "dword", 4, "Key-on hour meter stamp of the fault (was fault_timestamp_array)"),
            ("debounce_count", "byte", 1, "Debounce count (was fault_entry_debounce_array)"),
            ("status", "byte", 1, "Status (was fault_entry_status_array)"),
            ("timer", "byte", 1, "Timer (was fault_timer_array)")], False),
        ("pci_controller_command_word_t", "", [
            ("data_byte", "byte", 1, "Data byte of the command word sent to the external J1850 controller"),
            ("command_code", "byte", 1, "Command code (the low byte; written bytewise - read once with lhz @ 0x39f14)")], False),
        ("end_of_line_test_settings_t", "", [
            ("test_results_1", "byte", 1, "Chrysler in-plant test results 1 (SCI id 0x77)"),
            ("test_results_3", "byte", 1, "Test results 3"),
            ("final_test_results_1", "byte", 1, "Final test results 1"),
            ("final_test_results_2", "byte", 1, "Final test results 2"),
            ("field_mode_register", "word", 2, "e2m Field Mode register (0xFFFF in the dumps)"),
            ("test_flags_1", "byte", 1, "Test flags 1"),
            ("test_flags_2", "byte", 1, "Test flags 2"),
            ("test_flags_3", "byte", 1, "Test flags 3"),
            ("test_flags_4", "byte", 1, "Test flags 4"),
            ("test_flags_5", "byte", 1, "Test flags 5 (bit 0x10 holds the end-of-line misfire test)"),
            ("final_test_reserved_1", "byte", 1, "Final test reserved byte"),
            ("maximum_miles", "byte", 1, "Max miles for the in-plant mode (32 in the dumps)"),
            ("reserved_13", "byte", 1, "Reserved"),
            ("misfire_test_timeout_seconds", "byte", 1, "Misfire test timeout (30 s in the dumps)"),
            ("misfire_test_warm_up_seconds", "byte", 1, "Misfire test warm-up (18 s in the dumps)")], False),
        ("algorithm_enable_flags_12_t", "", bits16("0x003fd5b4"), False),
        ("algorithm_enable_flags_18_t", "", bits16("0x003fd5c0", demote={3, 13, 14}), False),
        ("algorithm_enable_flags_41_t", "", bits16("0x003fd5ee", demote={11, 12, 13}), False),
        ("data_transfer_state_t", "0x003fec82", [
            ("byte_count", "word", 2, "Byte count"),
            ("buffer_write_enabled_flag", "word", 2, "Buffer write enabled flag"),
            ("largest_write_length", "word", 2, "Largest write length"),
            ("reserved_06", "word", 2, "Reserved"),
            ("pending_write_transport", "byte", 1, "1 = CAN / 2 = serial (was the high byte of the state word)"),
            ("finish_requested_flag", "byte", 1, "Finish requested (was the low byte of the state word)"),
            ("flash_program_step", "byte", 1, "Step 1-5 of cm848_runFlashProgramStateMachine (was the high byte of the status word)"),
            ("flash2_erase_state", "byte", 1, "Medium confidence: 1 programmed / 2 erasing / 3 erased (was the low byte of the status word)")], True),
        ("diag_session_state_t", "0x003fecbe", [
            ("session_flags", "byte", 1, "Session flags"),
            ("response_write_index", "byte", 1, "Response write index"),
            ("response_cursor_pointer", "pointer", 4, "Cursor into diag_serial_buffer (stw r9,-4928(r10) @ 0x6788 stores 0x3fecf0) - the decompiler showed it as four byte stores")], True),
    ]
    GLOBALS += [
        ("0x003fdfde", "engine_overspeed_log_cal", "engine_overspeed_event_t[5]", 40, None),
        ("0x003fe05a", "active_dtc_list_cal", "dtc_list_t", 32, "Active DTC list: a count byte + 31 fault slots (1-based loops from the count) (was active_dtc_count)"),
        ("0x003fe07a", "previously_active_dtc_list_cal", "dtc_list_t", 32, "Previously active DTC list (same layout) (was previously_active_dtc_count)"),
        ("0x003fe09a", "fault_pending_counter_array", "word[32]", 64, None),
        ("0x003fe0da", "previously_active_dtc_cummins_fault_codes_cal", "word[32]", 64, "Cummins fault codes of the previously active DTC list (was emission_fault_count)"),
        ("0x003fee50", "lifetime_distance_8_mile_record", "word[4]", 8, None),
        ("0x003fedbc", "protection_event_spn_history", "word[8]", 16, None),
        ("0x003fedce", "protection_event_count_history", "word[8]", 16, None),
        ("0x003fda48", "sensor_channel_enable_bits_cal", "word[8]", 16, "Per-sensor-channel enable bitmap (channel n = word n/16 bit n%16) (was sensor_channel_enable_flags)"),
        ("0x003fda68", "sensor_channel_held_value_enable_bits_cal", "word[8]", 16, "Per-channel bitmap: bit n makes sensor channel n output its held value (channel 13 = the J1939 accelerator pedal path) (was fuel_demand_feature_flags)"),
        ("0x003fd948", "sensor_channel_ratiometric_reference_channel_cal", "word[128]", 256, "Per sensor channel: the number of ANOTHER channel whose filtered value divides this reading (ratiometric; dump: entry 1 = 28 / entry 3 = 42) (was sensor_channel_type_table)"),
        ("0x003fdb78", "adc_forced_reading_enable_bits_cal", "word[8]", 16, "Per-ADC forced-reading enable bitmap (was adc_forced_reading_enable_bits_0_to_15_cal with flat rows for the other words)"),
        ("0x003fb434", "qspi_device_slot_table", "qspi_device_slot_t[4]", 16, None),
        ("0x003fb446", "qspi_job_queues", "qspi_job_queue_t[2]", 134, None),
        ("0x003fd5b4", "algorithm_enable_flags_12_cal", "algorithm_enable_flags_12_t", 2, None),
        ("0x003fd5c0", "algorithm_enable_flags_18_cal", "algorithm_enable_flags_18_t", 2, None),
        ("0x003fd5ee", "algorithm_enable_flags_41_cal", "algorithm_enable_flags_41_t", 2, None),
        ("0x003fb3c8", "pci_controller_command_word", "pci_controller_command_word_t", 2, None),
        ("0x003fd938", "end_of_line_test_settings_cal", "end_of_line_test_settings_t", 16, "Chrysler in-plant / end-of-line test settings (EEPROM 0x4b6): the SCI by-id lookup maps ids 0x77 / 0x79 / 0x7c / 0x7d / 0x7f / 0xcc-0xd0 / 0xd2 to these bytes; the e2m CHRY_In_Plant_* order matches (was protection_timer_dispatch_config)"),
        ("0x003fe674", "fault_freeze_frame_entries_cal", "fault_entry_t[16]", 768, "16 fault freeze-frame records (records 8-15 are the shadow the DM4 builder indexes as one array; ends at 0x3fe974) (was the auto-named instance fault_entry_t_003fe674)"),
        ("0x003fe1ce", "fault_state_records_cal", "fault_state_t[170]", 1190, "One 7-byte state record per fault slot: timestamp / debounce count / status / timer (were four parallel arrays fault_timestamp_array / fault_entry_debounce_array / fault_entry_status_array / fault_timer_array)"),
    ]
# ---------------- apply ----------------
gv = open(GV).read().split("\n")
sd = open(SD).read().split("\n")


def gv_rows():
    out = {}
    for i, l in enumerate(gv):
        p = l.split(",", 3)
        if p[0].startswith("0x"):
            out.setdefault(int(p[0], 16), []).append(i)
    return out


existing_names = {l.split(",", 3)[1] for l in gv if l.startswith("0x") and l.count(",") >= 1}
drop, set_rows, report = set(), {}, []
rows = gv_rows()
for address_text, name, typ, span, comment in GLOBALS:
    a = int(address_text, 16)
    base = rows.get(a, [])
    if not base or gv[base[0]].split(",", 3)[1] != name:
        gate(name, a)                      # only names this batch gives; kept names are not re-gated
    inside = [i for b in range(a + 1, a + span) for i in rows.get(b, [])]
    for i in inside:
        p = gv[i].split(",", 3)
        report.append(f"  drop 0x{int(p[0], 16):06x} {p[1]} ({p[2] if len(p) > 2 else ''}) inside {name}")
    drop.update(inside)
    old = gv[base[0]].split(",", 3) if base else None
    old_comment = (old[3] if old and len(old) > 3 else "").strip()
    if comment is None:
        comment = old_comment + (f" | retyped {old[2]} -> {typ} 2026-11-18" if old and old[2] != typ else "")
    elif old and old[1] != name:
        comment = f"{comment} (was {old[1]})" + (f" | earlier note: {old_comment}" if old_comment else "")
    elif old_comment:
        comment = f"{comment} | earlier note: {old_comment}"
    if old and old[1] != name and name in existing_names:
        problems.append(f"{name}: already a name elsewhere")
    set_rows[a] = (base, f"0x{a:08x},{name},{typ},{comment}")
    drop.update(base[1:])
# overlap check between the new rows
spans = sorted((int(t[0], 16), int(t[0], 16) + t[3], t[1]) for t in GLOBALS)
for (a1, e1, n1), (a2, e2, n2) in zip(spans, spans[1:]):
    if a2 < e1:
        problems.append(f"overlap {n1} 0x{a1:06x}-0x{e1:06x} / {n2} 0x{a2:06x}")
for t, addr, fields, replace in STRUCTS:
    for f in fields:
        if not f[0].startswith("reserved"):
            gate(f[0])

print(f"batch {batch}: {len(STRUCTS)} struct types, {len(GLOBALS)} global rows, {len(drop)} rows dropped")
print("\n".join(report))
for p in problems:
    print("PROBLEM", p)
if not APPLY or problems:
    sys.exit(1 if problems else 0)

# global_variables.csv
new_gv = []
for i, l in enumerate(gv):
    if i in drop:
        continue
    new_gv.append(l)
for a, (base, text) in sorted(set_rows.items()):
    if base:
        idx = new_gv.index(gv[base[0]])
        new_gv[idx] = text
    else:
        for k, l in enumerate(new_gv):
            p = l.split(",", 1)
            if p[0].startswith("0x") and int(p[0], 16) > a:
                new_gv.insert(k, text)
                break
        else:
            new_gv.append(text)
open(GV, "w").write("\n".join(new_gv))

# structure_definitions.csv
for t, addr, fields, replace in STRUCTS:
    rows_t = [i for i, l in enumerate(sd) if l.startswith(t + ",")]
    new_rows = [f"{t},{addr},{f},{ty},{size},{q(c)},,verified" for f, ty, size, c in fields]
    if rows_t and not replace:
        raise SystemExit(f"{t} already exists")
    if rows_t:
        at = rows_t[0]
        sd = [l for i, l in enumerate(sd) if i not in rows_t]
        sd[at:at] = new_rows
    else:
        sd += [f"# {t}: wave 11 shape (2026-11-18)"] + new_rows
# protection_condition_flags_t.fault_state_flags (+8) -> 8 bitfield members
if batch == "A":
    i = next(i for i, l in enumerate(sd) if l.startswith("protection_condition_flags_t,0x0040b0e8,fault_state_flags,"))
    bits = [(f"protection_condition_flags_t,0x0040b0e8,{n if n != 'reserved_bit_0' or True else n},bitfield:1@{bit},{1 if k == 0 else 0},{q(c)},,verified")
            for k, (bit, n, c) in enumerate(bits_of("0x0040b0f0"))]
    sd[i:i + 1] = bits
    # j1939_dm13_requester_slot_t / pci_message_descriptor_t: their instances are arrays now -> template rows
    sd = [re.sub(r"^(j1939_dm13_requester_slot_t),0x0040addc,", r"\1,,", l) for l in sd]
    # the PCI tables: field rows become a template, the per-record instance markers go
    sd = [l for l in sd if not re.match(r"^pci_message_descriptor_t,0x[0-9a-f]+,,", l)]
    sd = [re.sub(r"^(pci_message_descriptor_t),0x0005774b,", r"\1,,", l) for l in sd]
if batch == "B":
    # instance-bound types whose instances are now arrays: field rows become templates, the markers go
    for t, base_addr in (("fault_entry_t", "0x003fe674"), ("qspi_device_slot_t", "0x003fb434"), ("qspi_job_queue_t", "0x003fb446")):
        sd = [l for l in sd if not re.match(rf"^{t},0x[0-9a-f]+,,", l)]
        sd = [re.sub(rf"^({t}),{base_addr},", r"\1,,", l) for l in sd]
    # qadc_channel_index_table stays word[92] (copy-window edge): 128 would cover the boot kernel's
    # diagnostic_service_dispatch_table (0x3fdb30) and the named slot transmission_temperature_qadc_channel_cal [103]
open(SD, "w").write("\n".join(sd))
print("applied")
