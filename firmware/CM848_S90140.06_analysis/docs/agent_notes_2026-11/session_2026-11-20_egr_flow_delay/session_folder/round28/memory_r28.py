"""Round 28: MEMORY.md (the PR #53 line) and the typing focus note."""
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
p = M + "MEMORY.md"
t = open(p).read()
t = t.replace("(cm848/egr-flow-delay-model, 158 commits)", "(cm848/egr-flow-delay-model, 161 commits)")
old = "the sensor channel layer's inverted names fixed); task 046 leads"
new = ("the sensor channel layer's inverted names fixed) + round 28 (e2m sensor-present flags, one read backwards; the "
       "boot CAN ring state struct + its full flags; mailbox writer prototypes restore a hidden frame argument); task "
       "046 leads")
if new not in t:
    assert t.count(old) == 1, t.count(old)
    t = t.replace(old, new)
open(p, "w").write(t)
f = M + "typing_focus_2026_11.md"
note = ("  - Round 28 (2026-11-22, a peer relay; the round 25-27 leads): 0ec3474 absolute_boost_pressure_sensor_present_flag "
        "(was boost_is_gauge_pressure_flag - read backwards; e2m 11D5 +4) / barometric_pressure_sensor_present_flag / "
        "two_speed_axle_switch_present_cal, cm848_writeBootKernelCanTxMailbox (the kernel's copy, not a CAN 2), "
        "can_ring_state_t / boot_can_ring_state (boot-only CAN rings); c65bdd0 its _pad16 -> transmit / receive ring full "
        "flags, and 3-parameter prototypes for both mailbox writers (two call sites had hidden the frame argument). "
        "Scan idea that worked: e2m '*_Present' records whose row name lost 'present'. Open: the kernel transport's "
        "message parameter (needs the 6 cm848_sendDiagServiceResponse callers read).\n")
if "Round 28 (2026-11-22" not in open(f).read():
    open(f, "a").write(note)
print("memory updated")
