"""Round 59 stage A: delete 29 struct types that nothing in CM848 uses (orphan_struct_types.py: no address row, no field /
dependency, no CSV, .cpp, script, test, CLAUDE.md or skill names them). Most came with the 2026-01-30 port of 26
generic CM550 structures and never applied here; CM550's own copies are untouched.
- SUPERSEDED (a live CM848 type has the layout): ad_sensor_config_t / sensor_fault_config_t -> sensor_channel_config_t,
  sensor_debounce_state_t -> sensor_channel_state_t, address_range_entry_t -> memory_region_t (memory_region_table).
- NO CM848 HOME (speculative, or CM550-only): the other 25.
- KEPT as leads (a CM848 table without a type yet): param_id_entry_t (the parameter ID table at 0x53be38),
  diag_dispatch_entry_t / ef00_dispatch_entry_t (the 6-byte dispatch tables at 0x539508 / 0x53a9a0).
Each deleted type's own '#' title lines go with it; the removed text is archived verbatim with its pile.
Idempotent.  usage: apply_r59a.py <repo> <archive.txt>"""
import os
import sys

repo, archive = os.path.abspath(sys.argv[1]), sys.argv[2]
SUPERSEDED = {"ad_sensor_config_t": "sensor_channel_config_t", "sensor_fault_config_t": "sensor_channel_config_t",
              "sensor_debounce_state_t": "sensor_channel_state_t", "address_range_entry_t": "memory_region_t"}
NO_HOME = {
    "parameter_response_t": "speculative (not in CM550)", "calterm_protocol_t": "speculative (not in CM550)",
    "insite_protocol_t": "speculative (not in CM550)", "dma_descriptor_t": "CM550 template, unused there too",
    "memory_patch_entry_t": "speculative (not in CM550)", "param_lookup_args_t": "CM550 template, unused there too",
    "can_param_msg_t": "speculative (not in CM550)", "scheduler_phase_slot_t": "CM550 template, unused there too",
    "cummins_data_plate_t": "CM550 applies it at EEPROM 0x2C0; CM848's EEPROM 0x2C0 holds ASCII '0' characters, "
                            "no plate there",
    "memory_operation_request_t": "CM550 template, unused there too",
    "j1939_source_addresses_t": "speculative (5 entries; CM848's whitelist j1939_receive_source_address_whitelist is "
                                "byte[4])",
    "network_type_switches_t": "speculative (not in CM550)", "diag_transfer_state_t": "CM550 template, unused there too",
    "diag_service_request_t": "CM550 template, unused there too", "circular_buffer_t": "speculative (not in CM550)",
    "fuel_limit_arbitration_t": "CM550 applies it at 0x0080CC4E; no CM848 layout",
    "engine_control_flags_t": "speculative (not in CM550); its protection_system field was a guess",
    "high_rpm_protection_t": "CM550 template, unused there too",
    "oil_pressure_protection_t": "CM550-only (one render there)",
    "fault_persistence_counters_t": "CM550 template, unused there too",
    "fault_status_registers_t": "CM550 template, unused there too",
    "fault_latch_registers_t": "speculative (not in CM550)",
    "engine_operating_mode_t": "CM550 template, unused there too (CM848 has the ENGINE_STATE enum)",
    "rpm_fuel_protection_t": "CM550 template, unused there too",
    "timing_mode_control_t": "CM550 template, unused there too; its protection_blend_ramp / protection_counter_1 / "
                             "_2 fields were guesses"}
DELETE = {**{k: f"SUPERSEDED by {v}" for k, v in SUPERSEDED.items()}, **{k: f"NO CM848 HOME: {v}" for k, v in NO_HOME.items()}}
assert len(DELETE) == 29
p = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/structure_definitions.csv")
lines = open(p).read().split("\n")
present = {l.split(",", 1)[0] for l in lines if l and not l.startswith("#")}
if not present & set(DELETE):
    print("already applied")
    sys.exit(0)
assert set(DELETE) <= present, set(DELETE) - present
out, removed, i = [], [], 0
first = {}
for k, l in enumerate(lines):
    name = l.split(",", 1)[0] if l and not l.startswith("#") else None
    if name in DELETE and name not in first:
        first[name] = k
drop = set()
for name, k in first.items():
    rows = [j for j, l in enumerate(lines) if l.split(",", 1)[0] == name and not l.startswith("#")]
    assert rows == list(range(rows[0], rows[-1] + 1)), (name, "rows not contiguous")
    top = rows[0]
    while top - 1 >= 0 and lines[top - 1].startswith("#"):
        top -= 1
    block = list(range(top, rows[-1] + 1))
    if rows[-1] + 1 < len(lines) and lines[rows[-1] + 1] == "" and top - 1 >= 0 and lines[top - 1] == "":
        block.append(rows[-1] + 1)
    drop.update(block)
    removed.append(f"=== {name}: {DELETE[name]}\n" + "\n".join(lines[j] for j in block if lines[j]))
open(p, "w").write("\n".join(l for k, l in enumerate(lines) if k not in drop))
with open(archive, "w") as fh:
    fh.write("Round 59 stage A: struct types removed from CM848's structure_definitions.csv (verbatim, with their '#' "
             "title lines), each with its pile.\n\n" + "\n\n".join(removed) + "\n")
print(f"{len(first)} types deleted, {len(drop)} lines removed")
