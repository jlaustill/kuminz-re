"""Wave 8 docs: firmware/CLAUDE.md summary, task 042 wave 8, todo 042; copy wave 8 results / brief / mappings to the notes."""
import csv
import json
import os
import shutil
import sys

repo, d = sys.argv[1], sys.argv[2]
p = f"{repo}/firmware/CLAUDE.md"
t = open(p).read()
old_h = "### Rename waves 1-7 (2026-11-16/17, PR #50) - what the code turned out to be"
assert t.count(old_h) == 1
t = t.replace(old_h, "### Rename waves 1-8 (2026-11-16/17, PR #50) - what the code turned out to be")
anchor = "- **ROM-to-RAM thunks and application data (fixed 2026-11-17, todo 043):**"
assert t.count(anchor) == 1
t = t.replace(anchor, """- **Wave 8:** the engine speed limit droop block (e2m HSG: `engine_speed_limit_droop_*`; the 6-byte
  `engine_speed_limit_arbitration_t` is split from the `main_injection_timing_source_code` word, and the old
  `torque_limit_error_integrator` dword is the `i16` droop slope + `engine_speed_limit_ramped`); the auxiliary injection
  quantity correction / scale maps (`auxiliary_quantity_main_correction_*` / `_scale_*`, e2m HPCR_Aux_*); the main
  injection timing lookup caches (were `torque_limit_init_state_N`); the EGR delta pressure sensor autozero (channel 105,
  fault 719), the EGR cooler fouling monitor (off in this calibration) and condensation model, the charge manager
  (limiters, charge system errors, EGR / assist controller); the all-speed governor override record (e2m ASG); enums:
  `ENGINE_OPERATING_MODE` corrected from every store of 0x40b000 (0 not selected / 1 TSC1 torque / 2 TSC1 speed / 5 / 6
  pedal fault / 7 variable speed governor / 8 dual-axis fuel table / 30 restore - the old MODE_CRANK / MODE_RUN /
  MODE_SHUTDOWN contradicted the code), `EGR_VALVE_CONTROL_STATE`, `COMBUSTION_CHI_SOURCE`; `selectHighSpeedGovernorGainSet`
  is shared with CM550 0x1d392 (the same function).
""" + anchor)
open(p, "w").write(t)

counts = {}
for name in ("mapping_w8_renames.csv", "mapping_w8_newrows.csv", "mapping_w8_newrows_b.csv"):
    for r in csv.DictReader(open(os.path.join(d, name))):
        counts[r["kind"]] = counts.get(r["kind"], 0) + 1
notes, uncertain = [], []
for g in ("torque_limit", "egr_charge", "governor_combustion"):
    for line in open(os.path.join(d, f"aligned_W8_{g}.jsonl")):
        r = json.loads(line) if line.strip() else {}
        if r.get("kind") == "note":
            notes.append(f"- [W8 {g}] " + " ".join(r.get("text", "").split())[:360])
        elif r.get("verdict") == "uncertain":
            uncertain.append(f"- [W8 {g}] `{r.get('old')}` ({r.get('address')}): " + " ".join((r.get("evidence") or "").split())[:200])
p = f"{repo}/work/tasks/042-table-campaign-rename-leads.md"
t = open(p).read()
old = ("- **CM550 shared-name check (waves 6-7, 2026-11-17):** one link broke. Wave 6 renamed CM848's shared (unprefixed)\n")
assert t.count(old) == 1
t = t.replace(old, "- **CM550 shared-name check (waves 6-7, 2026-11-17; DONE in wave 8: both are `selectHighSpeedGovernorGainSet`):** one link broke. Wave 6 renamed CM848's shared (unprefixed)\n")
t += f"""
## Wave 8 (2026-11-17, PR #50)

Three agents worked the wave-7 leftovers, applied in two stages:
- **Stage A (labels):** {counts.get('function', 0)} function and {counts.get('global', 0)} global renames, {counts.get('new row', 0)} new rows
  (5 of them mine: the pre-start rail pressure sample counters 0x3fd1d8 / 0x3fd1da and their four thresholds, which the
  thunk fix uncovered), and the CM848 half of the shared name `selectHighSpeedGovernorGainSet`. Proof: label-only with
  one-to-one goto labels (differences: default labels of rows that had no name, local declaration order, and casts from
  three new condensation words - typed `i16` in stage B).
- **Stage B (types):** the `engine_speed_limit_arbitration_t` split / rename and `operating_mode_governor_output_t`
  (was `governor_pid_t`), the droop slope / ramped limit split, 46 retypes (17 EGR words incl. three
  `ema_filter_state_t`, 24 signed all-speed governor and condensation words, the three enum-typed words, the two
  split words), 7 `+N` / accumulator rows deleted, 6 new words in the split dwords, three enums (`ENGINE_OPERATING_MODE`
  corrected; `EGR_VALVE_CONTROL_STATE` and `COMBUSTION_CHI_SOURCE` new), 4 prototypes and 4 locals. Reviewed diff
  (79 functions): enum members for numbers, split words named for `._0_2_` / `._2_2_` pieces, the struct renames,
  casts (32 removed / 31 added) and temporaries. The engine-mode selectors' parameter is `int32_t` (typing it with the
  2-byte enum rendered `CONCAT22(in_register_...)`: the parameter is the sign-extended register); the chi source
  function's parameters are `int32_t` for the same reason (`ushort` made the callee concatenate).
- **CM550:** 0x1d392 `selectSensorRawChannels` -> `selectHighSpeedGovernorGainSet`; proof EQUIVALENT (0 functions differ).
- **Left for later:** 0x3fdb84's name does not render under the kernel's `diagnostic_service_dispatch_table` byte[100]
  overlay (cutting it needs the kernel users checked); the CSE / EAC / CHL table arrays need their `arrays.csv` rows
  renamed with them; 0x3fae3c (a type-only byte row the CAN setup writes as a word - name and retype it); the
  engine-mode selectors compare the previous mode numerically (6 / 7 / 2).

### Wave 8: left uncertain
""" + "\n".join(uncertain or ["- none"]) + """

### Wave 8: further notes
""" + "\n".join(notes) + "\n"
open(p, "w").write(t)
p = f"{repo}/work/todo.md"
t = open(p).read()
line = next(l for l in t.split("\n") if l.startswith("042 "))
t = t.replace(line, line + f"; wave 8 DONE (labels + types: three enums, two struct changes, 46 retypes; CM550 shared name; "
              f"{len(uncertain)} uncertain, {len(notes)} notes left)")
open(p, "w").write(t)
notes_dir = f"{repo}/firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/rename_waves"
for g in ("torque_limit", "egr_charge", "governor_combustion"):
    shutil.copy2(os.path.join(d, f"result_W8_{g}.jsonl"), f"{notes_dir}/results/")
shutil.copy2(os.path.join(d, "aligned_W8_manual.jsonl"), f"{notes_dir}/results/manual_W8.jsonl")
shutil.copy2(os.path.join(d, "brief_wave8.md"), f"{notes_dir}/briefs/")
for name in ("mapping_w8_renames.csv", "mapping_w8_newrows.csv", "mapping_w8_newrows_b.csv", "mapping_w8_all.csv", "mapping_cm550_w8.csv"):
    shutil.copy2(os.path.join(d, name), f"{notes_dir}/mappings/")
readme = f"{repo}/firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/README.md"
t = open(readme).read()
o = "| 7 | 4c39da3 | `result_W7_*` | `mapping_w7_*` |\n"
assert t.count(o) == 1
open(readme, "w").write(t.replace(o, o + "| 8 | (wave 8 commit) | `result_W8_*`, `manual_W8.jsonl` | `mapping_w8_*`, `mapping_cm550_w8.csv` (CM550) |\n"))
print(f"docs ok; wave 8: {counts}; {len(uncertain)} uncertain, {len(notes)} notes")
