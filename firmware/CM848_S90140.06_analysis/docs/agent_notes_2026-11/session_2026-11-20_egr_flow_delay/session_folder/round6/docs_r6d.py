"""Round 6 closing 2: the docs (task 046 / 022, todo 046, firmware/CLAUDE.md) and the PR body.
usage: docs_r6d.py <repo> <pr_body.md>"""
import os
import sys

repo, pr = os.path.abspath(sys.argv[1]), sys.argv[2]


def edit(path, pairs):
    s = open(path).read()
    for a, b in pairs:
        assert s.count(a) == 1, (path, a[:70], s.count(a))
        s = s.replace(a, b)
    open(path, "w").write(s)
    print(os.path.basename(path), len(pairs), "edits")


TABLE_MD = """- **The TSC1 source table, read from the ROM image** (`originals/cm848_rom.bin` at 0x5c3b4, at word width):
  - **Senders:** entries 0-4 are J1939 (data link 1) with the source addresses 0x03 (the transmission), 0x0B, 0x21, 0x4A
    and 0x4F, which is task 022's whitelist. Entries 5-9 hold 0xFE (the J1939 null address) and are unused, so no
    wildcard is configured.
  - **Request timeouts:** 5 counts. The 10E7 MSEC cals count 10 ms, so that is 50 ms, J1939-71's TSC1 timeout. The
    transmission's mode 3 is 80 ms and the retarder's 250 ms.
  - **Time limits:** speed control is 0xFFFF for 0x03; the `+ 1` wraps it to 0, so the timer never fires and there is
    no limit. It is 600 = 6 s for the other four. Torque control is 6 s for all five, and the retarder has none.
  - **For task 022:** a TSC1 speed control request from 0x0B / 0x21 / 0x4A / 0x4F ends after 6 s, and the sender is
    then ignored until it sends override disabled. Only the transmission's address holds speed control indefinitely.
- **The arbitration, by branch (the plate is fixed):**
  - With no override active, any sender with an entry is accepted.
  - While a J1939 request is active, the controlling sender is always accepted. Another sender needs a higher
    priority, or at the same priority an active mode 3 request and a request that is not mode 3 or has a lower torque
    limit.
  - While a J1922 request is active, a J1939 sender needs an entry at the same or an earlier position.
- **The unused enums `GOVERNOR_MODE` / `RETARDER_MODE_STATE`** contradicted e2m 10E8 / 10E6 and are deleted. They were
  never applied, and the closing build proves a no-op.
- **Corrections:**
  - 0x5c38c and the table are in ROM (the main flash), not Bank 2. The `_cal` verdict (none) stands.
  - 4ae5f79 quotes `lha` only for `engine_net_output_torque` (0x40ae1c). The torque command's `short` rests on its e2m
    S record and on the render (the `(short)` casts it removed).
"""
p46 = os.path.join(repo, "work", "tasks", "046-cm848-egr-flow-estimate.md")
edit(p46, [("- **Round 6 leads:**\n", TABLE_MD + "- **Round 6 leads:**\n")])
p22 = os.path.join(repo, "work", "tasks", "022-j1939-dbw-investigation.md")
s = open(p22).read()
s = s.rstrip("\n") + "\n\n" + """## TSC1 time limits (PR #53 round 6, 2026-11-21)

`tsc1_source_configuration_table` (0x5c3b4, read from the ROM image) is the SA whitelist: 0x03 / 0x0B / 0x21 / 0x4A /
0x4F on J1939, with entries 5-9 unused (0xFE, no wildcard). Each entry also gives the TSC1 request timeouts and time
limits, in 10 ms counts:
- **The message timeout** is 50 ms in every mode (J1939-71). The transmission's mode 3 is 80 ms.
- **Speed control (mode 1) time limit:** none for SA 0x03 (0xFFFF), 6 s for 0x0B / 0x21 / 0x4A / 0x4F. At the limit
  the sender goes into the ignored request list and stays there until it sends override disabled (mode 0); then
  `cm848_runTsc1LostManagement` takes over.
- **Torque control (mode 2):** 6 s for all five.
- **Speed / torque limit control (mode 3):** no time limit.

So a TSC1 drive-by-wire that holds speed control longer than 6 s must send from 0x03, or drop to override disabled
and back within the limit. The names: `processEngineTsc1Request`, `j1939_powertrain_control_state` (e2m 10E8
"Jcomm") and `TSC1_OVERRIDE_MODE`.
"""
open(p22, "w").write(s)
print("022 appended")
ptodo = os.path.join(repo, "work", "todo.md")
edit(ptodo, [(" - open: the engine speed module's functions, the sweep's 35 has-lhz and 104 no-load rows, the wave 15 "
              "leads in task 046 (ASG 9-word gain set struct, fault derate words, cruise PID functions ...), the pool above "
              "0.2 overlap",
              "; round 5 (2026-11-21): J1939 builders vs their PGNs (DM8 / EBC1 / water in fuel / EC1), "
              "all_speed_governor_gain_set_t, drivetrain_type = vehicle_speed_sensor_type_cal, INTAKE_AIR_HEATER_PHASE, the "
              "cruise governor and A/C words; round 6: the TSC1 / ETC1 / Jcomm vocabulary (e2m 10E8 / 10E6 = "
              "j1939_powertrain_control_state, processEngineTsc1Request shared with CM550, three enums, the TSC1 source "
              "table and its time limits) - open: the J1939 monitor session record (e2m 10FE / 10FF / 1100), the engine "
              "speed module's functions, the sweep's 35 has-lhz and 104 no-load rows, the fault derate words, the 11D5 "
              "rows, the pool above 0.2 overlap")])
pcl = os.path.join(repo, "firmware", "CLAUDE.md")
edit(pcl, [("retarder's to `cm848_processEngineRetarderTsc1Request`. The SA whitelist is `tsc1_source_configuration_table`\n"
            "    (0x5c3b4, 10 entries: data link, source address, per-mode request timeouts / time limits).\n",
            "retarder's to `cm848_processEngineRetarderTsc1Request`. The SA whitelist is `tsc1_source_configuration_table`\n"
            "    (0x5c3b4 in ROM, 10 entries: data link, source address, per-mode request timeouts / time limits). Read\n"
            "    from the ROM image: 0x03 / 0x0B / 0x21 / 0x4A / 0x4F (entries 5-9 unused); 50 ms timeouts; speed control\n"
            "    unlimited only for 0x03, 6 s for the others (task 022).\n")])
edit(pr, [("  - **Also:** 0x5c39a is the high idle override speed.\n",
           "  - **Also:** 0x5c39a is the high idle override speed.\n"
           "  - **The TSC1 source table, read from the ROM image:** the whitelist is 0x03 / 0x0B / 0x21 / 0x4A / 0x4F,\n"
           "    with 50 ms request timeouts. Speed control is unlimited only from 0x03 (0xFFFF wraps to 0) and lasts 6 s\n"
           "    from the other four, after which the sender is ignored until it sends override disabled. That matters for\n"
           "    task 022's TSC1 work.\n"),
          ("- [x] `./analyze.sh verify`: the two builds are byte-identical.",
           "- [x] Round 6 closing: the arbitration prose is fixed by branch, and \"Bank 2\" for 0x5c38c / 0x5c3b4 is\n"
           "  corrected to ROM. The two unused enums that contradicted e2m are deleted, proved a no-op (comments only,\n"
           "  0 functions).\n"
           "- [x] `./analyze.sh verify`: the two builds are byte-identical.")])
