"""Round 75 stage A as a whole (CM550): every function whose body differs between the round's first and last build after
the round's renames (labels only); the type changes are expected in the schedule's two functions and the address stores.
usage: prove_r75a_total_cm550.py <old.cpp> <new.cpp>"""
import sys

sys.path.insert(0, "/home/linux/.claude/jobs/374b0424/tmp/w15/r75")
import prove_r75b as base  # noqa: E402

base.PAIRS[:] = [
    ('BYTE_0080ddfe', 'insite_parameter_schedule_tick'),
    ('DAT_0080de00', 'insite_parameter_next_due_ticks'),
    ('DAT_000612ee', 'insite_parameter_schedule_table'),
    ('mc68k_tpuTransmissionTrigger', 'mc68k_startJ1708Transmission'),
    ('mc68k_FUN_00029130', 'mc68k_initializeJ1708Datalink'),
    ('mc68k_epsPositionSensorIsrHandler', 'mc68k_j1708SciInterruptHandler'),
    ('Ram00fffc08', 'QSM_SCCR0'),
    ('Ram00fffc0a', 'QSM_SCCR1'),
    ('Ram00fffc0c', 'QSM_SCSR'),
    ('Ram00fffc0e', 'QSM_SCDR'),
]
old_b, new_b = base.bodies(sys.argv[1], True), base.bodies(sys.argv[2], False)
diff = [f for f in old_b if old_b[f] != new_b.get(f)]
print(f"functions {len(old_b)}; differing after the renames: {len(diff)}")
for f in diff:
    print(" ", f)
