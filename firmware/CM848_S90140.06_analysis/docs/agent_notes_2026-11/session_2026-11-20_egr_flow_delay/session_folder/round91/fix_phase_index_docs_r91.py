"""Round 91 (S2's amendment): 0x800358 main_loop_phase_index was a stale scheduler claim (it is inside
datalogger_trigger_parameter_addresses; CM550's scheduler switches on scheduler_phase_index 0x80068c in
executiveFrameInterruptHandler, CM848's on executive_frame_phase 0x3fa008). Fix the three places that still cite it.
Idempotent; keeps line endings. usage: fix_phase_index_docs_r91.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
R = "PR #53 round 91"
EDITS = [
    ("docs/cross_firmware_variable_map.csv",
     "0x00800358,0x003fa008,main_loop_phase_index,confirmed,Both: 40-phase cooperative scheduler index (0x00-0x27)",
     "0x0080068c,0x003fa008,scheduler_phase_index / executive_frame_phase,confirmed,Both: 40-phase cooperative scheduler "
     f"index (0x00-0x27); 0x800358 was a stale CM550 address (it is inside datalogger_trigger_parameter_addresses; {R})"),
    ("docs/cross-firmware-analysis.md",
     "| Phase index variable | `_main_loop_phase_index` | `main_loop_phase_index` |",
     "| Phase index variable | `scheduler_phase_index` (0x80068c) | `executive_frame_phase` (0x3fa008) |"),
    ("firmware/CM550_J90350.00_analysis/output/enums.csv",
     "# Main Loop Phase Index - main_loop_phase_index in scheduler switch (40 phases 0x00-0x27)",
     "# Main Loop Phase Index - scheduler_phase_index in the scheduler switch (40 phases 0x00-0x27; the comment named "
     f"main_loop_phase_index, a stale row at 0x800358 - {R})"),
]
for rel, old, new in EDITS:
    p = os.path.join(repo, rel)
    t = open(p, newline="").read()
    if new in t:
        continue
    assert t.count(old) == 1, (rel, t.count(old))
    open(p, "w", newline="").write(t.replace(old, new))
    print("fixed", rel)
