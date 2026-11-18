"""Wave 7 docs: CLAUDE.md summary + thunk note, task 042 wave 7, todo."""
import json
import os
import sys

repo, d = sys.argv[1], sys.argv[2]
p = f"{repo}/firmware/CLAUDE.md"
t = open(p).read()
old_h = "### Rename waves 1-6 (2026-11-16, PR #50) - what the code turned out to be"
assert t.count(old_h) == 1
t = t.replace(old_h, "### Rename waves 1-7 (2026-11-16/17, PR #50) - what the code turned out to be")
anchor = "  `charge_mass_flow_filtered`, `egr_mass_flow_delayed_filtered`), `ambient_air_density`, `injection_quantity_oxygen_limit`.\n"
assert t.count(anchor) == 1, "summary anchor"
t = t.replace(anchor, anchor + """- **Wave 7:** the VGT loop's twin is the EGR valve position servo (`egr_valve_*`): feedback = sensor channel 75 (the
  unidentified 0.5-4.5 V channel) through a learned zero offset (fault 718), direction on logical output 68 + PWM on
  output channel entry 39, enable on output 67, setpoint = the EGR fraction PI command - compiled in and running, but not
  fitted on this truck (no output assigned; its faults have no DTC slot). `battery_voltage_selected` /
  `battery_voltage_nominal` / `coolant_temperature_selected` (the fault-substituted channel values); the pedal fault
  engine operating mode (mode 6); the driver demand percent torque for EEC1 (SPN 512); the charge flow command chain
  (`mass_charge_flow_*_command`); the all-speed governor restore record (`engine_operating_mode_restore_*`).
- **Known renderer limit (ROM-to-RAM thunks):** the `romramthunks` build stage (`ApplyRomToRamThunks.java`) puts a
  4-byte thunk on every kernel-image address the boot ROM calls; where the application also keeps data there, the thunk
  takes the data row's name and swallows the next word's row (e.g. 0x3fb54c / 0x3fb54e prints the lockup state with the
  on-delay counter's name; also 0x3fd1d8/da, 0x3fae3c/3e, 0x3fb528/2a, 0x3fd070, 0x3fd1ac, 0x3fd284, 0x3fd298). The rows
  are right; the fix belongs in the thunk stage (todo 043).
""")
open(p, "w").write(t)
notes, uncertain = [], []
for g in ("injection_rail", "vgt_egr", "governor_combustion"):
    for line in open(os.path.join(d, f"aligned_W7_{g}.jsonl")):
        if not line.strip():
            continue
        r = json.loads(line)
        if r.get("kind") == "note":
            notes.append(f"- [W7 {g}] " + " ".join(r.get("text", "").split())[:360])
        elif r.get("verdict") == "uncertain":
            uncertain.append(f"- [W7 {g}] `{r.get('old')}` ({r.get('address')}): " + " ".join((r.get("evidence") or "").split())[:200])
p = f"{repo}/work/tasks/042-table-campaign-rename-leads.md"
open(p, "a").write("""
## Wave 7 (2026-11-17, PR #50)

Three agents worked the wave-6 leftovers: 59 function renames, 308 global renames, 1 struct field, 23 new rows. The VGT
loop's twin is the EGR valve position servo (`egr_valve_*`; the agent proposed the spelled-out
`exhaust_gas_recirculation_valve_*`, swapped to the existing `egr_*` family's prefix). Conflicts resolved: 0x40a61c /
0x40bd88 / 0x40bdae (the `*_selected` / `*_sensor_value` patterns). Proof: label-only with one-to-one goto labels; the
differences are struct / word default labels of rows that had no name, a local declaration order in
`cm848_validateWriteAuth`, and casts in the sensor channel 75 functions.

- **Thunk-stage label crossing (todo 043):** `ApplyRomToRamThunks.java` puts a 4-byte thunk over 0x3fb54c-0x3fb54f (the
  boot-kernel image of cm848_validateDiagnosticRequestLengthAndAuthorization, which the boot ROM calls); the thunk takes
  the entry label's name and swallows the 0x3fb54e row. Proof: the .cpp before the thunk stage (62b6cf1) prints both rows
  right; 8a72628 (the stage) is the first with crossed names. Same at 0x3fd1d8/da, 0x3fae3c/3e, 0x3fb528/2a, 0x3fd070,
  0x3fd1ac, 0x3fd284, 0x3fd298. Proposed fix (not applied): skip / shorten the thunk where named data rows own the
  addresses, and check what the boot calls then render as.

### Wave 7: left uncertain
""" + "\n".join(uncertain or ["- none"]) + """

### Wave 7: further notes
""" + "\n".join(notes) + "\n")
p = f"{repo}/work/todo.md"
t = open(p).read()
line042 = next(l for l in t.split("\n") if l.startswith("042 "))
new_line = line042 + f"; wave 7 DONE (59 functions, 308 globals, 23 new rows - the EGR valve servo; {len(uncertain)} uncertain, {len(notes)} notes left)"
entry043 = ("043 [ ] [firmware] CM848D ROM-to-RAM thunk stage crosses data labels: ApplyRomToRamThunks.java puts a 4-byte thunk on "
            "kernel-image addresses the boot ROM calls; where the application keeps data there the thunk takes the data row's name "
            "and swallows the next word's row (0x3fb54c / 0x3fb54e and ~8 more, listed in tasks/042 wave 7) - fix the stage "
            "(skip or shorten the thunk where named data rows own the bytes) and check the boot calls' rendering")
assert "\n043 " not in t
t = t.replace(line042, new_line + "\n" + entry043)
open(p, "w").write(t)
print(f"docs ok; wave 7: {len(uncertain)} uncertain, {len(notes)} notes")
