"""Round 57 follow-up (from the advisor's closing checks). Idempotent.  usage: fix_r57c.py <repo>
- fuel_pressure_fault_active_flag: its row said fault 59 (fuel_pressure_decay_below_model_error) was P1222 too. The
  ROM says otherwise: fault 59 -> slot 158 (0x5985a) -> P0000 in obd_dtc_code_table, no DTC. Faults 57 / 58 / 60 are
  P1221 / P1222 / P1223.
- warning_chime_count_fuel_pressure_fault: the six CHR_B2 e2m releases (11.61-11.72) put
  Catalyst_Warning_Chime_Count at 8B2D +A, this word. The truck's CC-family code chimes it for the fuel pressure
  faults, so the name stands; the row now says so.
- cm848_initializeCruiseControl's plate: "nothing reads" 0x3fcd90 -> "no reader found by name" (a name grep, in the
  time-shared ROM-to-RAM window).
- task 046 (the stage B line) and the memory note (a return-only prototype re-renders the caller's locals)."""
import os
import sys

repo = os.path.abspath(sys.argv[1])
O = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")


def edit(path, old, new):
    t = open(path).read()
    if new in t:
        return
    assert t.count(old) == 1, (path, old[:70], t.count(old))
    open(path, "w").write(t.replace(old, new))


G = os.path.join(O, "global_variables.csv")
edit(G, "1 while any of fault_detected_cal.fuel_pressure_governed_speed_check_error (P1221) / "
        ".fuel_pressure_governor_demand_above_limit_error / .fuel_pressure_decay_below_model_error (P1222) / "
        ".fuel_metering_feedback_low_error (P1223) is set - fault word 3 bits 9-12 - else 0",
     "1 while any of fault_detected_cal.fuel_pressure_governed_speed_check_error (fault 57 - P1221) / "
     ".fuel_pressure_governor_demand_above_limit_error (fault 58 - P1222) / .fuel_pressure_decay_below_model_error "
     "(fault 59 - slot 158 holds P0000: no DTC) / .fuel_metering_feedback_low_error (fault 60 - P1223) is set - fault "
     "word 3 bits 9-12 - else 0 (P-codes from ROM 0x5985a -> obd_dtc_code_table; round 57 first read fault 59 as P1222)")
edit(G, "8B2D ends at +9, so no e2m record covers it. (was warning_chime_count_fault_latch",
     "8B2D ends at +9 in the 11.45 CC e2m. The six CHR_B2 releases (11.61-11.72) put Catalyst_Warning_Chime_Count at "
     "8B2D +A, this word; the truck's CC-family code chimes it for the fuel pressure faults. "
     "(was warning_chime_count_fault_latch")
F = os.path.join(O, "function_renames.csv")
edit(F, "It also zeroes the word at 0x3fcd90 which nothing reads",
     "It also zeroes the word at 0x3fcd90 (no reader found by name - it sits in the time-shared ROM-to-RAM window)")
T = os.path.join(repo, "work/tasks/046-cm848-egr-flow-estimate.md")
edit(T, "  - `fuel_pressure_fault_active_flag` (was `protection_fault_latch_flag`): any of the P1221 / P1222 / P1223 rail\n"
        "    pressure and fuel metering faults; PCI 0x35 bit 6.",
     "  - `fuel_pressure_fault_active_flag` (was `protection_fault_latch_flag`): any of four rail pressure and fuel\n"
     "    metering faults, 57-60 = P1221 / P1222 / no DTC (fault 59's slot holds P0000) / P1223; PCI 0x35 bit 6. The\n"
     "    stage B commit message says \"P1222 twice\"; the follow-up corrected the row.\n"
     "  - Its chime count `warning_chime_count_fuel_pressure_fault` is 8B2D +A. The CHR_B2 e2m releases (11.61-11.72)\n"
     "    name that word Catalyst_Warning_Chime_Count, but the truck's code chimes it for these faults.")
edit(T, "  - 8A0F +A Filtered_Cruise_N_V_Ratio (0x40b20e) has no code use under its address.",
     "  - 8A0F +A Filtered_Cruise_N_V_Ratio (0x40b20e) has no code use under its address.\n"
     "  - The 0x3fcd90 word that `cm848_initializeCruiseControl` zeroes has no reader found by name; it sits in the\n"
     "    time-shared ROM-to-RAM window, so a pointer or boot-side reader is not ruled out.")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
edit(M + "typing_focus_2026_11.md",
     "a return-only prototype on a no-parameter getter is free (no call-site casts, unlike committed parameters)",
     "a return-only prototype on a no-parameter getter added no call-site casts (unlike committed parameters), but the "
     "caller re-rendered with renumbered locals - check local_variables.csv rows on such callers")
mm = open(M + "MEMORY.md").read()
mm = mm.replace("(cm848/egr-flow-delay-model, 251 commits)", "(cm848/egr-flow-delay-model, 252 commits)")
open(M + "MEMORY.md", "w").write(mm)
print("round 57 follow-up applied")
