"""Wave 9 docs: firmware/CLAUDE.md (summary + local_variables gotcha), task 042 wave 9, todo 042; notes copies; one stale label.
usage: wave9_docs.py <repo> <renames dir>"""
import csv
import json
import os
import shutil
import sys

repo, d = sys.argv[1:3]
out = f"{repo}/firmware/CM848_S90140.06_analysis/output"
p = f"{out}/global_variables.csv"
t = open(p).read()
o = "ema_filter_state_t_003fcc08.coefficient points here"
assert t.count(o) == 1
open(p, "w").write(t.replace(o, "turbocharger_speed_filter_state.coefficient points here"))

p = f"{repo}/firmware/CLAUDE.md"
t = open(p).read()
old_h = "### Rename waves 1-8 (2026-11-16/17, PR #50) - what the code turned out to be"
assert t.count(old_h) == 1
t = t.replace(old_h, "### Rename waves 1-9 (2026-11-16/17, PR #50) - what the code turned out to be")
anchor = "- **ROM-to-RAM thunks and application data (fixed 2026-11-17, todo 043):**"
assert t.count(anchor) == 1
t = t.replace(anchor, """- **Wave 9:** torque management (e2m `Torque_Mgmt_*`, off in this calibration - was read as a gear-down / thermal
  cluster); the turbocharger speed limiter (engine speed limit source 16) and the turbocharger speed chain (TPU-B channel 1
  sensor - not fitted on this truck - plus an estimate, chosen by `cm848_selectTurbochargerSpeedSource`; P2579 / P2580 /
  P2581); the charge manager tables (limiter derates, the charge system transform angle and cosine, the EGR / assist
  controller gains); the condensation protection model (the intake twin of the EGR cooler model, the dew points); the
  all-speed governor droop gains and negative reference slew limiter; enums `INJECTION_TIMING_INTERMEDIATE_SOURCE` and
  `MAIN_INJECTION_TIMING_SOURCE`. The whole high speed governor block is shared with CM550 (`runHighSpeedGovernorPid`,
  `presetHighSpeedGovernorIntegrator`, `initializeHighSpeedGovernorGainSet`, `selectHighSpeedGovernorGainSet`,
  `selectEngineSpeedLimit`, `initializeEngineSpeedLimitDefaults`). The boot kernel's `diagnostic_service_dispatch_table`
  (`arrays.csv`) is cut from byte[100] to byte[10]: the kernel indexes it at run time, and the application's EEPROM-mirror
  words share that RAM (`switch_input_polarity_bits_cal`, `switch_input_hardware_line_cal` and the ADC forced-reading enable
  words used to print as `diagnostic_service_dispatch_table + ...`).
""" + anchor)
old = "- **Name locals via `local_variables.csv`** (`addr,fn,old_name,new_name,type,comment`); don't reuse a global's name for a local"
assert t.count(old) == 1
t = t.replace(old, "- **Name locals via `local_variables.csv`** (`addr,fn,old_name,new_name,type,comment`). Rows match the decompiler's AUTO-names (`iVar7`), so a change that renumbers a function's temporaries (a retype, a cut array) makes them land on the wrong variables WITHOUT a warning for most rows (wave 9: the Type B sensor-channel rows put `low_fault_word_index` on `channel_index >> 4`). After a type change, re-check the functions with local rows: build once without their rows to read the new auto-names. Don't reuse a global's name for a local")
open(p, "w").write(t)

counts = {}
for name in ("mapping_w9_renames.csv", "mapping_w9_newrows.csv", "mapping_w9_newrows_b.csv"):
    for r in csv.DictReader(open(os.path.join(d, name))):
        counts[r["kind"]] = counts.get(r["kind"], 0) + 1
notes, uncertain = [], []
for g in ("gear_down", "charge_turbo", "governor"):
    for line in open(os.path.join(d, f"aligned_W9_{g}.jsonl")):
        r = json.loads(line) if line.strip() else {}
        if r.get("kind") == "note":
            notes.append(f"- [W9 {g}] " + " ".join(r.get("text", "").split())[:360])
        elif r.get("verdict") == "uncertain":
            uncertain.append(f"- [W9 {g}] `{r.get('old')}` ({r.get('address')}): " + " ".join((r.get("evidence") or "").split())[:200])
p = f"{repo}/work/tasks/042-table-campaign-rename-leads.md"
t = open(p).read()
t += f"""
## Wave 9 (2026-11-17, PR #50)

Three agents worked the wave-8 leftovers, applied in two stages.
- **Stage A (labels):** {counts.get('function', 0)} function and {counts.get('global', 0)} global renames and
  {counts.get('new row', 0) - 6} new rows; proof label-only with one-to-one goto labels (differences: default labels of rows
  that had no name, local declaration order, store casts of new rows). The five CM848 halves of the shared high speed
  governor names are in it (`torque_management_transmission_type_2_gear_ratio_threshold` uses the code-proven transmission
  type 2, not the agent's inferred "47RE").
- **Stage B (types):** `diagnostic_service_dispatch_table` byte[100] -> byte[10] (the boot kernel registers 14 packed
  5-byte entries and indexes them at run time; the application's EEPROM-mirror words share the RAM), 6 new words (four ADC
  forced-reading enable words, two split words replacing `+2` label rows), retypes (0x3fae3c byte -> word, 0x40a280 /
  0x40a688 / 0x40a68e dword -> word / i16), two enums (`INJECTION_TIMING_INTERMEDIATE_SOURCE`, `MAIN_INJECTION_TIMING_SOURCE`)
  with three typed words, the high speed governor prose rows, the combustion status bit comment, the droop gain plate.
  Reviewed diff (43 functions): enum members for numbers, the kernel table's `+ 0x48` / `+ 0x5e` / `+ 0x5a` expressions
  now the enable words / switch line and polarity arrays, casts, temporaries; no boot function changed.
  **Caught:** the cut renumbered the temporaries of `sensorChannelTypeB_update` / `_configInit`, so their 20
  `local_variables.csv` rows landed on the wrong variables (`low_fault_word_index = channel_index >> 4`); remapped to the
  new auto-names from a build without the rows.
- **CM550:** 0x1ce7c / 0x1d252 / 0x1d2e4 / 0x1d5a0 / 0x1d94e take the shared names (tier A same body, tier B the same
  function revised - the `selectHighSpeedGovernorGainSet` precedent); proof EQUIVALENT.

### Wave 9: left uncertain
""" + "\n".join(uncertain or ["- none"]) + """

### Wave 9: further notes
""" + "\n".join(notes) + "\n"
open(p, "w").write(t)
p = f"{repo}/work/todo.md"
t = open(p).read()
line = next(l for l in t.split("\n") if l.startswith("042 "))
t = t.replace(line, line + f"; wave 9 DONE (torque management, turbocharger speed chain, charge manager tables, condensation "
              f"model, two enums, kernel table cut, five CM550 shared names; {len(uncertain)} uncertain, {len(notes)} notes left)")
open(p, "w").write(t)
nd = f"{repo}/firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/rename_waves"
for g in ("gear_down", "charge_turbo", "governor"):
    shutil.copy2(os.path.join(d, f"result_W9_{g}.jsonl"), f"{nd}/results/")
shutil.copy2(os.path.join(d, "brief_wave9.md"), f"{nd}/briefs/")
for name in ("mapping_w9_renames.csv", "mapping_w9_newrows.csv", "mapping_w9_newrows_b.csv", "mapping_w9_all.csv", "mapping_cm550_w9.csv"):
    shutil.copy2(os.path.join(d, name), f"{nd}/mappings/")
readme = f"{repo}/firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/README.md"
t = open(readme).read()
o = "| 8 | b66e3a7 |"
assert t.count(o) == 1
i = t.index(o)
j = t.index("\n", i) + 1
t = t[:j] + "| 9 | (wave 9 commit) | `result_W9_*` | `mapping_w9_*` (`_newrows_b` = stage B), `mapping_cm550_w9.csv` (CM550) |\n" + t[j:]
t = t.replace("`brief_wave3.md` to `brief_wave6.md` and `brief_wave8.md` are", "`brief_wave3.md` to `brief_wave6.md`, `brief_wave8.md` and `brief_wave9.md` are")
open(readme, "w").write(t)
print(f"docs ok; wave 9: {counts}; {len(uncertain)} uncertain, {len(notes)} notes")
