"""Round 6 closing 2 (the final review): the TSC1 source table read from the ROM image, the arbitration prose fixed
by branch, "Bank 2" -> ROM for 0x5c38c / 0x5c3b4, the two unused enums whose members contradict e2m 10E8 / 10E6
deleted, the docs.
The ROM image (originals/cm848_rom.bin, 0x70000 bytes) at 0x5c3b4, ten 20-byte entries, words:
  entries 0-4: data_link 1, source address 0x03 / 0x0B / 0x21 / 0x4A / 0x4F (high byte 0), request timeouts 5 / 5 / 5
  (entry 0 mode 3: 8), retarder request timeouts 0x19, retarder time limit 0; speed control time limit 0xFFFF for
  0x03 and 0x258 (600) for the other four; torque control time limit 0x258 for all five.
  entries 5-9: data_link 1, source address 0xFE (the J1939 null address: unused), time limits 0.
  The 10E7 MSEC cals the same timer function counts scale 10 ms per count (Jcomm_Recovery_Time: 10.0), so 5 = 50 ms
  (J1939-71's TSC1 timeout), 600 = 6 s, 150 (0x5c38c) = 1.5 s; 0xFFFF + 1 wraps to 0, a timer that never reaches 1.
  0x5c39a = 27600 = 3450 rpm.
usage: fix_r6d.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
TABLE = ("ROM image: entries 0-4 are data link 1 (J1939) with the source addresses 0x03 (the transmission) / 0x0B / "
         "0x21 / 0x4A / 0x4F (high byte 0); entries 5-9 hold 0xFE (the J1939 null address) and are unused, so there is "
         "no wildcard. Request timeouts 5 counts of 10 ms = 50 ms (entry 0 mode 3: 80 ms; the retarder's 250 ms). Time "
         "limits: speed control 0xFFFF for 0x03 (+ 1 wraps to 0: no limit) and 600 = 6 s for the other four; torque "
         "control 6 s for all five; the retarder's 0")
EDITS = {
    "global_variables.csv": [
        ("Bank 2 flash, so no _cal (was etc1_torque_mode_timeout_cal)",
         "ROM, so no _cal. 150 in the ROM image = 1.5 s (the 10E7 MSEC cals count 10 ms) (was etc1_torque_mode_timeout_cal)"),
        ("cm848_findTsc1SourceConfiguration walks it; a sender without an entry is rejected. No e2m record. The "
         "instance covers the first entry only",
         "cm848_findTsc1SourceConfiguration walks it; a sender without an entry is rejected. No e2m record. " + TABLE),
        ("533 maximum momentary engine override speed). Word (lhz @ 0x1b544 / 0x1fea4)",
         "533 maximum momentary engine override speed). Word (lhz @ 0x1b544 / 0x1fea4). 27600 in the ROM image = 3450 rpm"),
    ],
    "function_renames.csv": [
        ("A sender takes over an active request only with an entry at the same or an earlier position and an equal or "
         "higher priority (in mode 3 at the same priority: a lower torque or speed).",
         "With no override active any sender with an entry is accepted. While a J1939 request is active the controlling "
         "sender is always accepted; another sender needs a higher priority (a lower value), or at the same priority an "
         "active mode 3 request and either a request that is not mode 3 or a lower torque limit (the same torque with a "
         "lower speed limit). While a J1922 request is active a J1939 sender needs an entry at the same or an earlier "
         "position."),
    ],
    "structure_definitions.csv": [
        ("a new sender needs an equal or higher priority (a value not above this) (was priority_byte)",
         "while a J1939 request is active another sender needs a higher priority (a lower value); at the same priority "
         "only an active mode 3 request can be taken over (was priority_byte)"),
        ("a new sender takes over only with an entry at the same or an earlier position",
         "while a J1922 request is active a J1939 sender takes over only with an entry at the same or an earlier "
         "position"),
        ("(tsc1_source_configuration_table at 0x5c3b4: 10 entries x 20 bytes, Bank 2\n#   flash; round 6:",
         "(tsc1_source_configuration_table at 0x5c3b4 in ROM: 10 entries x 20 bytes;\n#   round 6:"),
        ("Low byte = J1939 SA to match (0xFF=wildcard); high byte = priority filter",
         "Low byte = the J1939 source address (0xff would match any J1939 sender; the ROM image lists 0x03 / 0x0B / "
         "0x21 / 0x4A / 0x4F and 0xFE = the null address in the five unused entries); the high byte is 0 in every "
         "entry (a priority filter role is not verified)"),
    ],
    "enums.csv": [
        ("# Governor Mode States\n# Internal governor state machine values\n"
         "GOVERNOR_MODE,0,GOV_DISABLED,Governor control disabled - pedal/throttle control,1\n"
         "GOVERNOR_MODE,1,GOV_DRIVELINE_DISENGAGED,Speed control mode - maintain target RPM,1\n"
         "GOVERNOR_MODE,2,GOV_DRIVELINE_ENGAGED,Torque control mode - limit engine torque,1\n"
         "GOVERNOR_MODE,3,GOV_SPEED_TORQUE,Combined speed and torque control mode,1\n", ""),
        ("# Retarder Mode State Machine\n"
         "RETARDER_MODE_STATE,0,RETARDER_DISABLED,Retarder control disabled,1\n"
         "RETARDER_MODE_STATE,1,RETARDER_SPEED_SYNC,Speed synchronization mode,1\n"
         "RETARDER_MODE_STATE,2,RETARDER_LOAD_BASED,Load-based retard mode,1\n"
         "RETARDER_MODE_STATE,3,RETARDER_PROPORTIONAL,Proportional control mode,1\n", ""),
    ],
}
for name, pairs in EDITS.items():
    p = os.path.join(out, name)
    s = open(p).read()
    for a, b in pairs:
        assert s.count(a) == 1, (name, a[:70], s.count(a))
        s = s.replace(a, b)
    open(p, "w").write(s)
    print(name, len(pairs), "edits")
