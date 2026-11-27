"""Round 21 stage A (types): the engine protection channel records as structs, from their e2m blocks (each block's
records tile its whole size, and the sizes are the engine protection loops' strides):
- engine_protection_channel_configuration_t (36 bytes, e2m 112E, ROM 0x597b2; the loops step 0x12 words);
- engine_protection_channel_state_t (62 bytes, e2m 1152, RAM 0x40a734; the loops step 0x3e bytes);
- engine_protection_channel_history_t (30 bytes, e2m 1143, EEPROM mirror 0x3fdfbe, so the instance is _cal; the loops
  step 0xf words).
This build has one channel, the fuel temperature one (the e2m's 'Input_Source_0' records name the same fields).
Field types: the covered flat rows' types (asm-checked) where there is one, else the e2m size and sign; the pointer
fields' pointees from hpcr_initFuelTemperatureSensorChannel (the input and the three thresholds are words; the fault
log pointers point into EEPROM data, kept as pointer). The covered flat rows are removed; their comments move into the
fields. Also the five helpers' full prototypes (they see the records only as parameters).
usage: apply_r21a.py <repo> [--only configuration,state,history] [--no-prototypes] [--dry-run]"""
import json
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
dry = "--dry-run" in sys.argv
only = sys.argv[sys.argv.index("--only") + 1].split(",") if "--only" in sys.argv else None
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
E2M = os.path.join(repo, "e2m-analysis/CHR/CHR_CC_11.45.01.07.e2m")
STRUCTS = {
    "configuration": ("engine_protection_channel_configuration_t", 0x597b2, "fuel_temperature_engine_protection_configuration",
                      "112E", 36, [
        (0x00, "configuration_flags", "word"), (0x02, "fueling_derate_start_duration", "word"),
        (0x04, "engine_speed_derate_start_duration", "word"), (0x06, "fueling_ramp_rate", "word"),
        (0x08, "engine_speed_ramp_rate", "word"), (0x0A, "fueling_minimum_threshold", "word"),
        (0x0C, "fueling_maximum_threshold", "word"), (0x0E, "engine_speed_lower_limit_threshold", "short"),
        (0x10, "fueling_shutdown_duration_threshold", "word"), (0x12, "engine_speed_shutdown_duration_threshold", "word"),
        (0x14, "shutdown_delay", "word"), (0x16, "start_monitor_engine_speed", "word"),
        (0x18, "start_monitor_time", "word"), (0x1A, "fueling_fault_index", "word"),
        (0x1C, "engine_speed_fault_index", "word"), (0x1E, "shutdown_warning_time", "word"),
        (0x20, "fueling_shutdown_severity_threshold", "short"), (0x22, "engine_speed_shutdown_severity_threshold", "short")]),
    "state": ("engine_protection_channel_state_t", 0x40a734, "fuel_temperature_engine_protection_state", "1152", 62, [
        (0x00, "input_pointer", "word*"), (0x04, "input_mask", "word"), (0x06, "fueling_duration", "word"),
        (0x08, "engine_speed_duration", "word"), (0x0A, "minimum_threshold_pointer", "word*"),
        (0x0E, "maximum_threshold_pointer", "word*"), (0x12, "engine_speed_lower_limit_pointer", "word*"),
        (0x16, "errors_allowed", "word"), (0x18, "precrank_error", "word"),
        (0x1A, "fueling_shutdown_time_count", "word"), (0x1C, "engine_speed_shutdown_time_count", "word"),
        (0x1E, "fueling_start_warning_time", "word"), (0x20, "engine_speed_start_warning_time", "word"),
        (0x22, "errors_allowed_timer", "word"), (0x24, "errors_allowed_timer_running", "word"),
        (0x26, "fueling_fault_log_pointer", "pointer"), (0x2A, "engine_speed_fault_log_pointer", "pointer"),
        (0x2E, "fueling_fault_occurrence_time", "dword"), (0x32, "fueling_fault_log_value", "word"),
        (0x34, "fueling_fault_log_duration", "word"), (0x36, "engine_speed_fault_occurrence_time", "dword"),
        (0x3A, "engine_speed_fault_log_value", "word"), (0x3C, "engine_speed_fault_log_duration", "word")]),
    "history": ("engine_protection_channel_history_t", 0x3fdfbe, "fuel_temperature_engine_protection_history_cal",
                "1143", 30, [
        (0x00, "fueling_severity_index", "word"), (0x02, "engine_speed_severity_index", "word"),
        (0x04, "fueling_restart_severity_index", "word"), (0x06, "engine_speed_restart_severity_index", "word"),
        (0x08, "input_extremity", "short"), (0x0A, "input_extremity_time", "dword"),
        (0x0E, "fueling_fault_elapsed_time", "dword"), (0x12, "engine_speed_fault_elapsed_time", "dword"),
        (0x16, "fueling_fault_log_flag", "word"), (0x18, "fueling_fault_log_index", "word"),
        (0x1A, "engine_speed_fault_log_flag", "word"), (0x1C, "engine_speed_fault_log_index", "word")]),
}
SIZE = {"word": 2, "short": 2, "i16": 2, "dword": 4, "word*": 4, "pointer": 4}
CPP_TYPE = {}  # structure_definitions.csv writes pointer fields as word* (second_order_filter_state_t, ema_filter_state_t)
PROTOTYPES = [  # (address, function, [(index, name, type, comment)])
    ("0x00507d50", "threshold_adjustment_ramp", [
        ("return", "", "word", "The new severity index: + the ramp rate (capped at 0x100) while the duration is past the "
                               "derate start duration, else - the ramp rate (floored at 0)"),
        ("0", "configuration", "engine_protection_channel_configuration_t *", "The channel's configuration (r3)"),
        ("1", "state", "engine_protection_channel_state_t *", "The channel's state (r4)"),
        ("2", "history", "engine_protection_channel_history_t *", "The channel's history (r5)"),
        ("3", "is_engine_speed", "int", "0 = the fueling index, 1 = the engine speed index (r6)")]),
    ("0x00507ebc", "protection_threshold_check", [
        ("return", "", "sword", "1 when the input is past the selected threshold (or the switch input is active)"),
        ("0", "configuration", "engine_protection_channel_configuration_t *", "The channel's configuration (r3)"),
        ("1", "state", "engine_protection_channel_state_t *", "The channel's state (r4)"),
        ("2", "is_engine_speed", "int", "0 = the fueling thresholds, 1 = the engine speed thresholds (r5)"),
        ("3", "threshold_select", "int", "0 / 1 the minimum / maximum threshold pointer, 2 the shutdown duration "
                                         "threshold, 3 the shutdown severity threshold (r6)")]),
    ("0x0050832c", "protection_threshold_update", [
        ("return", "", "void", ""),
        ("0", "configuration", "engine_protection_channel_configuration_t *", "The channel's configuration (r3)"),
        ("1", "state", "engine_protection_channel_state_t *", "The channel's state (r4)"),
        ("2", "history", "engine_protection_channel_history_t *", "The channel's history (r5)")]),
    ("0x00508408", "protection_state_transition", [
        ("return", "", "void", ""),
        ("0", "channel_index", "int", "The channel number (r3); only channel 4 takes the restart limitation path"),
        ("1", "state", "engine_protection_channel_state_t *", "The channel's state (r4)"),
        ("2", "configuration", "engine_protection_channel_configuration_t *", "The channel's configuration (r5)")]),
    ("0x00508834", "protection_event_timestamp", [
        ("return", "", "void", ""),
        ("0", "configuration", "engine_protection_channel_configuration_t *", "The channel's configuration (r3)"),
        ("1", "state", "engine_protection_channel_state_t *", "The channel's state (r4)"),
        ("2", "is_engine_speed", "int", "0 = the fueling count, 1 = the engine speed count (r5)")]),
]

recs = {}
for line in open(E2M, errors="replace"):
    head, _, desc = line.rstrip("\n").partition(";")
    f = head.split(",")
    if len(f) > 18 and f[2] in ("112E", "1152", "1143"):
        recs.setdefault((f[2], int(f[3], 16)), []).append((f[0], f[1], int(f[7]), desc.strip().replace('"', "'")))
gp, sp, fp = (os.path.join(out, n) for n in ("global_variables.csv", "structure_definitions.csv",
                                             "function_definitions.csv"))
glines = open(gp).read().split("\n")
struct_text = open(sp).read()
mapping, problems = {}, []
new_struct_rows = []
for key, (stype, base, instance, block, total, fields) in STRUCTS.items():
    if only and key not in only:
        continue
    assert stype not in struct_text, stype
    offset = 0
    rows = [f"# {stype}: an engine protection channel's {key} record ({total} bytes, e2m {block}; PR #53 round 21). "
            f"This build has one channel, the fuel temperature one: {instance} @ 0x{base:x}"]
    for off, name, typ in fields:
        if off != offset:
            problems.append(f"{stype}: gap or overlap at +0x{off:x} (expected +0x{offset:x})")
        size = SIZE[typ]
        rec = recs.get((block, off), [])
        if not rec or any(r[2] != size for r in rec):
            problems.append(f"{stype}.{name}: e2m {block} +0x{off:x} size {[r[2] for r in rec]} != {size}")
        covered = [l for l in glines if l.startswith("0x") and int(l[:10], 16) == base + off]
        old = covered[0].split(",", 3) if covered else None
        if old and old[2] not in (typ, "pointer") and not (typ == "word*" and old[2] == "pointer"):
            problems.append(f"{stype}.{name}: the covered row is {old[2]}, the field {typ}")
        comment = "; ".join(f"+0x{off:x} e2m {r[0]} [{r[1]}] '{r[3][:100]}'" for r in rec)
        if old and old[1]:
            comment += f" (was the flat row {old[1]})"
            mapping[old[1]] = f"{instance}.{name}"
        if old and old[3].strip():
            comment += f" | earlier note: {old[3].strip()[:160]}"
        comment = comment.replace('"', "'")
        rows.append(f'{stype},,{name},{CPP_TYPE.get(typ, typ)},{size},"{comment}",,verified')
        offset += size
    if offset != total:
        problems.append(f"{stype}: fields sum to {offset}, the block is {total}")
    new_struct_rows.append("\n".join(rows))
    # the covered rows go; the base row becomes the instance
    keep = []
    base_row = None
    for l in glines:
        if l.startswith("0x") and base <= int(l[:10], 16) < base + total:
            if int(l[:10], 16) == base:
                base_row = l.split(",", 3)
            continue
        keep.append(l)
    assert base_row, stype
    note = (f"The fuel temperature engine protection channel's {key} record ({stype}, e2m {block}; PR #53 round 21: "
            f"was the flat rows {', '.join(sorted(n for n in mapping if mapping[n].startswith(instance + '.')))})")
    i = max(k for k, l in enumerate(keep) if l.startswith("0x") and int(l[:10], 16) < base)
    keep.insert(i + 1, f"0x{base:08x},{instance},{stype},{note}")
    glines = keep
if problems:
    print("\n".join(problems))
    sys.exit(1)
print(f"{len(new_struct_rows)} structs, {len(mapping)} flat names mapped")
if dry:
    sys.exit(0)
open(sp, "w").write(struct_text.rstrip("\n") + "\n" + "\n".join(new_struct_rows) + "\n")
open(gp, "w").write("\n".join(glines))
if "--no-prototypes" not in sys.argv:
    ft = open(fp).read().rstrip("\n").split("\n")
    for address, name, params in PROTOTYPES:
        assert not any(l.startswith(address + ",") for l in ft), name
        for index, pname, ptype, comment in params:
            ft.append(f"{address},{name},{index},{pname},{ptype},{comment}")
    open(fp, "w").write("\n".join(ft) + "\n")
json.dump(mapping, open(os.path.join(os.path.dirname(os.path.abspath(__file__)), "flat_to_field_r21a.json"), "w"),
          indent=1)
print("written")
