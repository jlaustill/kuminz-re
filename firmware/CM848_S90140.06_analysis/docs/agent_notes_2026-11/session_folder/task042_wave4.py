"""Append the wave-4 results to task 042 and update todo 042."""
import json
import os
import sys

repo, d = sys.argv[1], sys.argv[2]
notes, uncertain = [], []
for g in ("injection", "rail", "air", "governor"):
    for line in open(os.path.join(d, f"aligned_W4_{g}.jsonl")):
        if not line.strip():
            continue
        r = json.loads(line)
        if r.get("kind") == "note":
            notes.append(f"- [W4 {g}] " + " ".join(r.get("text", "").split())[:360])
        elif r.get("verdict") == "uncertain":
            uncertain.append(f"- [W4 {g}] `{r.get('old')}` ({r.get('address')}): " + " ".join((r.get("evidence") or "").split())[:220])
text = """
## Wave 4 (2026-11-16, PR #50)

Four read-only agents worked the wave-3 leftovers: 44 function renames (+7 plate refreshes), 4 new functions (the
alternator regulator state handlers at ROM 0x38338 / 0x38384 / 0x383f0 / 0x3844c, reached only through the pointer
table at ROM 0x57730 - their five thresholds at 0x4087a2-0x4087b0 now render), 219 global renames, 6 more
`fault_entry_t` fields, 12 new rows. Proof: with goto labels matched one-to-one, only two existing functions differ
beyond labels (the pointer table at 0x57730 now names the first handler; the export footer counts 1968 functions).

Highlights: `torque_limit_*` is an ENGINE SPEED limit family (every value rpm x 8, compared with current_rpm);
`cm848_checkFuelPressureSensorPlausibilityByFuelDemand` (P0191, 150-pass average at a warm stop); the retarder request
cluster is an exhaust brake chain (P0478 / P0477 exhaust pressure control valve) ending in ERC1 and logical output 11;
the old `cruise_speed_*` block is the dual accelerator pedal (slots 97 / 98: P2122 / P2123 / P2127 / P2128 / P2121);
the J1939 CAN receive / transmit queues; "actuator E" (`cm848_calculateActuatorESetpoint`, was
`cm848_calculateSpeedControlLimit`): a closed loop on the wastegate duty request with sensor channel 101 as feedback,
unassigned on this truck; `main_injection_timing_for_air_handling` (was `engine_load_normalized_prev`);
`injection_timing_main_base_command` (was `injection_timing_advance`); engine acceleration words.

- **CONFLICT with an earlier rename - review before building on it:** the 2026-06-27 "engine load protection" re-domain
  (commit 7c997eb, the 18 functions at 0x2e17c-0x2f6a0 and `ENGINE_LOAD_PROTECTION_STATE`) says the monitored quantity
  is `engine_load_percent`; the wave-4 air agent finds the code filters `protection_channel_filtered_output`
  (0x40bdb6), the value of ADC sensor channel 101 (0x65), and xref of `engine_load_percent` (0x40af24) shows none of
  those 18 functions (its old name was `protection_channel_load_raw`, the likely source of the mix-up). Sensor 101's
  identity is open; it is also the feedback of the actuator E loop.
- `engine_retarder_request_on_delay_counter` (0x3fb54c) is time-shared: the boot ROM's
  `mpc555_diagService25_executeFunction` calls the kernel-image function `cm848_validateDiagnosticRequestLengthAndAuthorization`
  at that RAM address, so the boot call renders with the application's name (as it did with the old name).

### Wave 4: left uncertain
""" + "\n".join(uncertain or ["- none"]) + """

### Wave 4: further notes
""" + "\n".join(notes) + "\n"
p = os.path.join(repo, "work/tasks/042-table-campaign-rename-leads.md")
open(p, "a").write(text)
p = os.path.join(repo, "work/todo.md")
t = open(p).read()
old = "still open: wave 3's 9 uncertain items and 49 notes in tasks/042-table-campaign-rename-leads.md"
new = ("wave 4 DONE too (44 functions + 4 new, 219 globals, 6 struct fields, 12 new rows); still open: wave 4's "
       f"{len(uncertain)} uncertain items and {len(notes)} notes, and the load-protection conflict (the 0x2e17c-0x2f6a0 "
       "cluster may monitor sensor channel 101, not engine load) in tasks/042-table-campaign-rename-leads.md")
assert t.count(old) == 1, "todo anchor"
open(p, "w").write(t.replace(old, new))
print(f"appended: {len(uncertain)} uncertain, {len(notes)} notes")
