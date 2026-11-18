"""Acceptance checks for a wave-11 shape batch: pattern census per shape (before -> after), bit-order spot checks,
changed functions below 0x7F60 (boot ROM / kernel image), underscore warnings, importer type stats and the thunk log.
Usage: accept_shapes.py <pre.cpp> <post.cpp> <build.log> <baseline build.log>"""
import re
import sys

pre_path, post_path, log_path, base_log_path = sys.argv[1:5]
pre, post = open(pre_path).read(), open(post_path).read()
PATTERNS = [r"\(&qadc_channel_dispatch_table\)\[", r"\(&pci_transmit_message_table\)\[", r"\(&pci_receive_message_table\)\[",
            r"\(&sci_buffer\)\[", r"\(&fault_handled_bitmap\)\[", r"\(&logical_output_request_priority\)\[",
            r"\(&fault_enable_bitmask_array\)\[", r"\(&j1939_dm13_requester_slot_0\)\[", r"\bgovernor_output_t_0040aec2\.\w+\._\d+_\d+_",
            r"\bprotection_timer_state_t_0040b100\.\w+\._\d+_\d+_", r"\bengine_rpm_state_t_0040b7ac\.\w+\._\d+_\d+_",
            r"\bconverter_clutch_transition_state\._\d+_\d+_", r"\bprotection_condition_state\._\d+_\d+_",
            r"\blogical_output_request_bits_16_to_23\._\d+_\d+_", r"\bgovernor_rpm_reference_ramped\._\d+_\d+_",
            r"\btransmission_output_speed_change\._\d+_\d+_", r"\bgovernor_fuel_demand_command\._\d+_\d+_",
            r"\bfault_auto_clear_warm_up_cycle_count_cal\._\d+_\d+_", r"\binjection_fuel_quantity_snapshot_previous\._\d+_\d+_",
            r"\bstatus_flags\._\d+_\d+_", r"\(&fault_definition_table\)\[", r"\(&fault_entry_flags\)\[",
            # batch B
            r"\(&(previously_)?active_dtc_count\)\[", r"\(&(previously_)?active_dtc_list_cal\.count\)\[",
            r"\(&fault_(timer_array|entry_status_array|entry_debounce_array)\)\[", r"\bfault_timestamp_array\b",
            r"\(&fault_entry_t_003fe674\)\[", r"\bfault_freeze_frame_data_buf\b", r"\(&sensor_channel_type_table\)\[",
            r"\(&sensor_channel_enable_flags\)\[", r"\(&fuel_demand_feature_flags\)\[", r"\(&adc_forced_reading_enable_bits_0_to_15_cal\)\[",
            r"\(&(engine_overspeed_log_cal|fault_pending_counter_array|emission_fault_count|lifetime_distance_8_mile_record)\)\[",
            r"\(&(protection_event_spn_history|protection_event_count_history|qspi_device_slot_table|qspi_job_queues)\)\[",
            r"\balgorithm_enable_flags_(12|18|41)_cal & 0x", r"\balgorithm_enable_flags_(12|18|41)_cal\.\w+",
            r"\bpci_controller_command_word\._\d+_\d+_", r"\bdata_transfer_state_t_003fec82\.\w+\._\d+_\d+_",
            r"\bdiag_session_state_t_003fecbe\._\d+_\d+_", r"\bend_of_line_test_settings_cal\.\w*\.?_\d+_\d+_",
            r"\b(active_dtc_list_cal|previously_active_dtc_list_cal|fault_state_records_cal|fault_freeze_frame_entries_cal|sensor_channel_\w+_cal|adc_forced_reading_enable_bits_cal|end_of_line_test_settings_cal)\b[^;\n]*?\._\d+_\d+_",
            r"\(\w+ \*\)\(&?(fault_state_records_cal|fault_freeze_frame_entries_cal|end_of_line_test_settings_cal)"]
print("pattern census (pre -> post):")
for p in PATTERNS:
    a, b = len(re.findall(p, pre)), len(re.findall(p, post))
    if a or b:
        print(f"  {p}: {a} -> {b}")
print("bit-order spot checks:")
for p in [r"monitor_enabling_conditions_met\.\w+", r"monitor_battery_voltage_error_latch\.\w+",
          r"logical_output_request_bits_16_to_23\.\w+"]:
    seen = sorted(set(re.findall(p, post)))
    print(f"  {p}: {len(seen)} distinct: {', '.join(s.split('.')[1] for s in seen[:12])}")


def chunks(text):
    out = {}
    for chunk in re.split(r"(?m)^(?=// Function: )", text):
        m = re.match(r"// Function: (\S+) @ 0x([0-9a-f]+)", chunk)
        if m:
            body = re.sub(r"/\*.*?\*/", "", chunk, flags=re.S)
            out[int(m.group(2), 16)] = (m.group(1), body)
    return out


a, b = chunks(pre), chunks(post)
changed = [(addr, b[addr][0]) for addr in b if addr in a and a[addr][1] != b[addr][1]]
boot = [(hex(x), n) for x, n in changed if x < 0x7f60]
print(f"changed functions: {len(changed)}; below 0x7F60: {boot}")
print("underscore warnings:", pre.count("Globals starting with '_'"), "->", post.count("Globals starting with '_'"))
for path in (base_log_path, log_path):
    log = open(path).read()
    stats = re.findall(r"Type stats: .*?(?=\(GhidraScript\))", log)[-1:]
    thunks = re.findall(r"ROM-TO-RAM THUNKS: .*?(?=\(GhidraScript\))", log)
    covering = re.findall(r"data (\S+) \(covering\) kept", log)
    errors = re.findall(r"(?:Error|ERROR|Failed to|FAILED)[^\n]{0,140}", log)
    print(f"{path.rsplit('/', 1)[-1]}: {stats} {thunks} covering={covering} errors={len(errors)}")
    for e in errors[:8]:
        print("   ", e)
