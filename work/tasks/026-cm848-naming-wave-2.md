# 026 — CM848 naming wave 2

**Status:** in progress. **Branch:** `cm848/naming-wave-2` → PR #47. **Source:** the follow-up candidates captured in
`025-cm848-naming-wave-followups.md` from wave 1 (PR #46). Same method: one read-only investigator per unit, two
independent skeptics re-check every proposal, accept only where no skeptic rejects, then reconcile → apply → build →
`./analyze.sh verify` → commit.

## Units
1. **output-speed-chain** — the 48RE output-speed sensor chain still under `fuel_flow_*` names (period, numerator 5217391, EMA).
2. **fault-bit-arrays** — the three fault bitmaps at 0x3fe974 (detected) / 0x3fe9d8 (registered) / 0x3fea3c, named by fault-bit range through the slot map (ROM 0x5985a → `obd_dtc_code_table`).
3. **governor-pressure-modes** — the four 48RE governor-pressure curve handlers (cold / standstill / normal / WOT) + state.
4. **cruise-encoder-timeouts** — `cm848_encodeGovernorFuelModeStatus`, the ETC2 selected-gear / gear-ratio timeouts, remaining cruise state.
5. **fault-healing** — `cm848_initUdsServer` (fault healing) / `cm848_initJ1939Stack` (occurrence counts) / the `diag_faultRing_*` family.
6. **cold-start-temp-rationality** — the `engine_camSync_*` key-on temperature rationality test + the per-sensor stuck check; sensor slot 15 (water in fuel).
7. **cruise-servo-outputs** — logical output requests 19/20/21 → output lines → MIOS PWM channels: the open cruise vent/vacuum/servo driver lead.
8. **intake-air-heater** — finish the grid-heater family (`diag_iat_protection*`, `iat_solenoid_*`).

## Log
- 2026-11-13: branch cut from merged main (4ed0948); wave-2 workflow launched (run wf_3b947338-e2f, 8 units × 1 investigator + 2 skeptics).
- 2026-11-13: workflow returned 197 accepted / 0 disputed; reconciled to 196 targets (143 globals / 36 functions / 17 struct fields), 0 cross-unit conflicts; applied, built, `verify` byte-identical. Open questions + skeptic misses captured in `027-cm848-naming-wave-2-followups.md`.
