"""Wave 5 docs: a rename-waves summary in firmware/CLAUDE.md, task 042 wave 5, todo 042."""
import json
import os
import sys

repo, d = sys.argv[1], sys.argv[2]
p = f"{repo}/firmware/CLAUDE.md"
t = open(p).read()
anchor = "### Naming wave 2 (2026-11-13, PR #47)"
assert t.count(anchor) == 1
summary = """### Rename waves 1-5 (2026-11-16, PR #50) - what the code turned out to be
Read-only agents verified each lead against the code (RAM-dump reproductions, decoded DTCs; e2m parameter blocks only
as corroboration by relative offset); every rename was proven label-only. Leads and leftovers: `work/tasks/042-*.md`.
- **Injection:** three events per cylinder on TPU-A channel 5 (pilot / main / auxiliary), with timing, quantity and
  on-time chains (`cm848_calculate{Main,Pilot,Auxiliary}InjectionTiming`, `...InjectionQuantity(Limit)`,
  `...InjectionPulseWidth`); `main_injection_timing` was `torque_limit_fault_snapshot`.
- **Combustion manager (Cummins CBR / CBO / CBL / CBP):** `cm848_runCombustionReference` / `cm848_runOffNominalCompensation`
  / `cm848_runCombustionLimits`; `cm848_interpolateAlphaChiValue` (was `cm848_filterInputValue`, 18 users) blends the
  alpha / chi maps (`combustion_chi_lower_map_number` / `_upper_map_number`; the dump selects chi 4, the EGR-off map); the
  cylinder oxygen balance, net combustion torque and ambient air density in Bank 2. The old `fuel_demand_*` / `engine_load_*`
  / `fuel_blend_*` / `load_rate_cap` words there were these terms (the "load rate cap" is the mass charge flow limit).
- **Variable geometry turbocharger position servo (was "engine load protection", 2026-06-27, commit 7c997eb):** sensor
  channel 101 is the position feedback of a two-direction valve servo; the 0x2e17c-0x2f6a0 cluster is its key-on stop
  seek and position learning (faults 670 / 671 adjustment, 682 / 683 sensor), and wave 4's "actuator E" loop drives it
  from the boost controller's duty request. The code proves the servo; the turbocharger label is from the e2m VGT group.
  Not fitted on this truck (output unassigned, sensor at its floor).
- **Rail pressure:** `cm848_calculateFuelPressureSetpoint`, the P1223 / P0088 / P1222 / P0148 / P1221 / P0191 monitors,
  the rail-pressure-shortfall fuel limiter, per-injector diagnostic bitmaps (P0201-P0206, P2146 / P2149).
- **Others:** `torque_limit_*` = engine SPEED limits (rpm x 8); `engine_speed_limp_home_active_flag` (was
  `crank_position_valid_flag`, polarity reversed; P0336); the exhaust-brake request chain (P0478 / P0477) and the
  ERC1 / TSC1 / PGN 65213 / 65249 messages; the dual accelerator pedal (was the `cruise_speed_*` block); the charging
  regulator (P2504 / P2503) with its four state handlers (created from the pointer table at ROM 0x57730); the wastegate
  duty controller (`wastegate_duty_controller_state_t`, was `rpm_governor_state_t`); the all-speed governor droop.

"""
t = t.replace(anchor, summary + anchor)
open(p, "w").write(t)
notes, uncertain = [], []
for g in ("load", "combustion_rom", "combustion_flash2"):
    for line in open(os.path.join(d, f"aligned_W5_{g}.jsonl")):
        if not line.strip():
            continue
        r = json.loads(line)
        if r.get("kind") == "note":
            notes.append(f"- [W5 {g}] " + " ".join(r.get("text", "").split())[:360])
        elif r.get("verdict") == "uncertain":
            uncertain.append(f"- [W5 {g}] `{r.get('old')}` ({r.get('address')}): " + " ".join((r.get("evidence") or "").split())[:200])
p = f"{repo}/work/tasks/042-table-campaign-rename-leads.md"
open(p, "a").write("""
## Wave 5 (2026-11-16, PR #50)

Three agents: the load-protection dispute and the combustion-manager cluster. 64 function renames, 191 global renames,
1 enum type + 2 members (`VARIABLE_GEOMETRY_TURBOCHARGER_SPAN_ADJUSTMENT_STATE`, was `ENGINE_LOAD_PROTECTION_STATE`), 11 struct
fields + 2 struct types (`combustion_reference_state_t`, was `fuel_blend_state_t`; `combustion_chi_maximum_fuel_points_t`, was
`protection_threshold_set_t`), 12 new rows. Proof: label-only with one-to-one goto labels except two oxygen-model functions
whose stores now cast to the new rows' `word` type. **The 2026-06-27 load-protection reading is resolved: wrong - the cluster
is the variable geometry turbocharger position servo (see firmware/CLAUDE.md "Rename waves 1-5").**

### Wave 5: left uncertain
""" + "\n".join(uncertain or ["- none"]) + """

### Wave 5: further notes
""" + "\n".join(notes) + "\n")
p = f"{repo}/work/todo.md"
t = open(p).read()
old = "and the load-protection conflict (the 0x2e17c-0x2f6a0 cluster may monitor sensor channel 101, not engine load) in tasks/042-table-campaign-rename-leads.md"
new = ("in tasks/042-table-campaign-rename-leads.md; wave 5 DONE (load-protection dispute resolved: the cluster is the variable "
       f"geometry turbocharger position servo; the combustion manager re-domained; {len(uncertain)} uncertain, {len(notes)} notes left)")
assert t.count(old) == 1, "todo anchor"
open(p, "w").write(t.replace(old, new))
print(f"docs ok; wave 5: {len(uncertain)} uncertain, {len(notes)} notes")
