"""Record the stale-r29 quirk: plate comment, firmware/CLAUDE.md, todo 039."""
import sys

root = sys.argv[1]
NOTE = ("Quirk (disassembly): only governor mode 1 (OPEN_LOOP_START) sets r29 - the start temperature chosen by "
        "engine_sync_state_b; modes 2 / 4 and the fixed-command modes 8 / 16 / 32 / 64 jump past it, so the "
        "integrator-preset lookup at 0x48ba8 (taken while engine_rpm_measured is 0) reads the caller's r29 "
        "(the unaff_r29 argument). Likely harmless: it only runs with the engine stopped and mode 1 recomputes "
        "the preset before a start.")

p = f"{root}/firmware/CM848_S90140.06_analysis/output/function_renames.csv"
lines = open(p).read().split("\n")
for i, l in enumerate(lines):
    if l.startswith("0x00047bd0,cm848_calculateFuelMeteringCommand,"):
        head, sep, tail = l.partition(" | review-function-readability")
        lines[i] = head + " " + NOTE + sep + tail
        break
else:
    raise SystemExit("plate row not found")
open(p, "w").write("\n".join(lines))

p = f"{root}/firmware/CLAUDE.md"
t = open(p).read()
anchor = "  - **State:** four Q16.16 states, typed as `q16_fixed_point_t` globals"
assert t.count(anchor) == 1
t = t.replace(anchor, "  - **Stale-register quirk (confirmed 2026-11-16):** " + NOTE.split("Quirk (disassembly): ", 1)[1] + "\n" + anchor)
open(p, "w").write(t)

p = f"{root}/work/todo.md"
t = open(p).read()
old = ("STILL OPEN: in cm848_calculateFuelMeteringCommand the integrator-preset table input (r29, unaff_r29) is set only on "
       "the governor-mode-1 path, so other paths use a stale register value (a firmware quirk worth confirming in the disassembly)")
new = ("DONE (PR #50): the stale-r29 quirk is confirmed in the disassembly - only governor mode 1 sets r29; modes 2 / 4 / "
       "8 / 16 / 32 / 64 reach the integrator-preset lookup at 0x48ba8 (engine stopped) with the caller's r29 - likely "
       "harmless, documented in the plate comment and firmware/CLAUDE.md")
assert t.count(old) == 1, "todo anchor"
t = t.replace(old, new).replace("039 [>] [firmware] CM848D table-lookup follow-ups", "039 [X] [firmware] CM848D table-lookup follow-ups")
open(p, "w").write(t)
print("ok")
