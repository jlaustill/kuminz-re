"""Wave 6 docs: CLAUDE.md summary, task 042 wave 6, todo 042."""
import json
import os
import sys

repo, d = sys.argv[1], sys.argv[2]
p = f"{repo}/firmware/CLAUDE.md"
t = open(p).read()
old_h = "### Rename waves 1-5 (2026-11-16, PR #50) - what the code turned out to be"
assert t.count(old_h) == 1
t = t.replace(old_h, "### Rename waves 1-6 (2026-11-16, PR #50) - what the code turned out to be")
anchor = "  duty controller (`wastegate_duty_controller_state_t`, was `rpm_governor_state_t`); the all-speed governor droop.\n"
assert t.count(anchor) == 1, "summary anchor"
t = t.replace(anchor, anchor + """- **Wave 6:** the "actuator E" loop is the VGT valve position servo itself (PID with setpoint prefilter, direction on
  logical output 71 + PWM on output channel entry 43, enable on output 72; H-bridge fault, driver over-current, motor
  thermal model and current estimate in Bank 2 - all `variable_geometry_turbocharger_*`); the `fuel_ema_coeff_*` /
  `injection_timing_compensation_*` words are the high speed governor's speed-error PID (`high_speed_governor_*`, dump:
  P 2062 + I 117 + D 0 = 2179); the engine speed limit chain (`cm848_selectEngineSpeedLimit`, the park / neutral exit
  limit, the fault derate limit) and a cruise vehicle speed limit (`cm848_calculateFaultCruiseSpeedLimit`); the
  combustion maps (20 `word[304]` grids reached through pointer words), the mass flows (`fuel_mass_flow`,
  `charge_mass_flow_filtered`, `egr_mass_flow_delayed_filtered`), `ambient_air_density`, `injection_quantity_oxygen_limit`.
""")
open(p, "w").write(t)
notes, uncertain = [], []
for g in ("injection_rail", "air_vgt", "governor", "combustion"):
    for line in open(os.path.join(d, f"aligned_W6_{g}.jsonl")):
        if not line.strip():
            continue
        r = json.loads(line)
        if r.get("kind") == "note":
            notes.append(f"- [W6 {g}] " + " ".join(r.get("text", "").split())[:360])
        elif r.get("verdict") == "uncertain":
            uncertain.append(f"- [W6 {g}] `{r.get('old')}` ({r.get('address')}): " + " ".join((r.get("evidence") or "").split())[:200])
p = f"{repo}/work/tasks/042-table-campaign-rename-leads.md"
open(p, "a").write("""
## Wave 6 (2026-11-16, PR #50)

Four agents worked the waves 4-5 leftovers: 52 function renames (+1 plate refresh), 399 global renames (10 of them named
rows that had no name), 6 struct fields, 44 new rows (20 `word[304]` combustion map grids). Conflicts resolved: 0x3fb046
(only the VGT loop uses it -> the VGT name), 0x405a0c / 0x405a0e (minimum / maximum, as the combustion limit family). Four
`<name>+2` sub-label rows were left alone. Proof: label-only with one-to-one goto labels, except the map-pointer setup (the
new grids are arrays, so `ptr = &DAT_x` renders `ptr = (undefined *)grid`) and one `SUB42(x, 0)` that became `(word)x`.
Open: the 0x3fb54c / 0x3fb54e label pair in the time-shared window renders swapped (the wave-4 governor note); the twin of
the VGT loop (`cm848_calculateFuelDemandLimits`, probably the EGR valve).

### Wave 6: left uncertain
""" + "\n".join(uncertain or ["- none"]) + """

### Wave 6: further notes
""" + "\n".join(notes) + "\n")
p = f"{repo}/work/todo.md"
t = open(p).read()
key = "wave 5 DONE (load-protection dispute resolved:"
assert t.count(key) == 1, "todo anchor"
i = t.index(key)
j = t.index(")", t.index("notes left", i)) + 1
t = t[:j] + f"; wave 6 DONE (52 functions, 399 globals, 6 struct fields, 44 new rows; {len(uncertain)} uncertain, {len(notes)} notes left)" + t[j:]
open(p, "w").write(t)
print(f"docs ok; wave 6: {len(uncertain)} uncertain, {len(notes)} notes")
