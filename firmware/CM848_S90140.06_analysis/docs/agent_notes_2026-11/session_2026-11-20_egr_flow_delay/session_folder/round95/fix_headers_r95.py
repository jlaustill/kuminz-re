"""Round 95 stage A: the comment texts that name CM848's executive task sets by their old names (each old text must
occur exactly once; idempotent; keeps line endings):
- CM848 function_renames.csv header: the cross-firmware scheduler map (by position, with guessed role names on both
  sides) becomes the slot rule (both firmwares name their task sets by slot since rounds 93 / 95), and the ROM-to-RAM
  note no longer claims the image runs from RAM for speed (it is the boot reflash kernel: firmware/CLAUDE.md, PR #46);
- CM550 function_renames.csv header: its two 'CM848 equivalent' lines;
- firmware/feature_comparison.csv: the io_control row names CM848's every-frame task set;
- CM848 docs/j1939_broadcast_investigation.md: a call tree line.
usage: fix_headers_r95.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])


def patch(rel, pairs):
    path = os.path.join(repo, rel)
    text = open(path, newline="").read()
    E = "\r\n" if "\r\n" in text else "\n"
    for old, new in pairs:
        old, new = old.replace("\n", E), new.replace("\n", E)
        if new in text:
            continue
        assert text.count(old) == 1, (rel, old[:60], text.count(old))
        text = text.replace(old, new)
    open(path, "w", newline="").write(text)
    print("patched", rel)


patch("firmware/CM848_S90140.06_analysis/output/function_renames.csv", [
    ("# These ~50 functions execute from RAM for MPC555 performance (RAM faster than flash).\n",
     "# The image is the boot reflash kernel: it runs from RAM so flash can be programmed under it (firmware/CLAUDE.md, PR #46).\n"),
    ("""# Both use identical 40-phase cooperative scheduler. Task groups map by position:
#   CM848D phase_common_processing     ↔ CM550 ioDriverStrobeHandlerWrapper
#   CM848D phase_group_a_processing    ↔ CM550 evenPhaseSchedulerTaskSet
#   CM848D phase_group_b_processing    ↔ CM550 oddPhaseSchedulerTaskSet
#   CM848D periodicTaskSet_fuelFinal      ↔ CM550 fuel_delivery_controller + fuel_limit_arbitrator
#   CM848D periodicTaskSet_sensorProcessing ↔ CM550 engine_speed_governor
#   CM848D periodicTaskSet_timing         ↔ CM550 periodicTaskSet_fuelTiming
#   CM848D periodicTaskSet_monitoring     ↔ CM550 slowCycle10Coordinator
#   CM848D periodicTaskSet_communication  ↔ CM550 diagnosticCommunicationSlowCycle10Coordinator
#   CM848D periodicTaskSet_protection     ↔ CM550 periodicTaskSet_governorProtection
#   CM848D periodicTaskSet_fuelDemand     ↔ CM550 periodicTaskSet_fuelDemand
""",
     """# Both run a 40-frame executive schedule (5 ms frames) and name each task set by its slot (CM550 PR #53 round 93,
# CM848 rounds 94 / 95): cm848_runEveryFrameTaskSet / cm848_runEvery<N>FramesTaskSetPhase<P> (N = 2 / 4 / 8 / 10 / 20)
# <-> the cm550_ task set of the same slot. Their calls differ; each plate comment lists them. (The old map paired
# the slots by guessed role names, such as periodicTaskSet_canTx, which runs the vehicle speed updates.)
"""),
])
patch("firmware/CM550_J90350.00_analysis/output/function_renames.csv", [
    ("# CM848 equivalent: phase_common_processing\n", "# CM848 equivalent: cm848_runEveryFrameTaskSet\n"),
    ("# Periodic task sets - CM848 equivalent: periodicTaskGroup*\n",
     "# Periodic task sets - CM848 equivalent: the cm848_ task set of the same slot (cm848_runEvery<N>FramesTaskSetPhase<P>)\n"),
])
patch("firmware/feature_comparison.csv", [
    ("IO control - phase_common_processing in CM848D", "IO control - cm848_runEveryFrameTaskSet (was phase_common_processing) in CM848D"),
])
patch("firmware/CM848_S90140.06_analysis/docs/j1939_broadcast_investigation.md", [
    ("  └─ cm848_phase_group_b_processing @ ROM[0xB854]", "  └─ cm848_runEvery2FramesTaskSetPhase1 @ ROM[0xB854] (was cm848_phase_group_b_processing)"),
])
