"""Round 9 docs: task 046, firmware/CLAUDE.md, work/todo.md, the PR body, the session README.
usage: docs_r9.py <repo> <pr_body.md> <stage D hash>"""
import os
import sys

repo, pr, hash_d = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]


def edit(path, pairs):
    s = open(path).read()
    for a, b in pairs:
        assert s.count(a) == 1, (path, a[:70], s.count(a))
        s = s.replace(a, b)
    open(path, "w").write(s)
    print(os.path.basename(path), len(pairs), "edits")


R9_TASK = f"""## Done, round 9 (2026-11-21, same PR; the user's next "keep going"): the 48RE tables in memory order

Scripts are in `session_folder/round9/`.
- **Method: e2m column 5 is the ROM layout.** Every ROM calibration block carries a sequential number in column 5,
  and RAM blocks have 0000. The blocks sit in memory in that order.
  - `walk_tables.py` walks a run of table blocks from a known address. It sizes each table from its byte-length word in
    the RAM dump: an X axis or Y curve is a length word plus data, a Z grid is nx x ny words with no header. It prints
    the CSV row at each address.
  - From round 8's anchor 0x407876 (0B43) every table through 0B98 lands on an existing `word[N]` row of exactly the
    walked size: 58 tables. After 8C18, 0B9E..0BA9 and 0BB5..0BC6 match the same way: 30 more.
  - Each table's users in the code are the mode its record names.
  - Where 11.46 differs from the 11.45 e2m:
    - grid boost axes sit inline before the grid;
    - the T tables (`RE_Gear_Ratio`, the shift lags) are elsewhere;
    - 8BBB stops at +14 (its tow / brake / exhaust brake 4-3 tail is not before 8BBC);
    - the manual 2nd curve sits after `RE_WOT_Curve`.
- **Stage A (0f4daf6, label-only):**
  - about 70 tables named;
  - 8BB5 at 0x408ae0, the governor pressure control calibration (38 words);
  - 8BBB at 0x4077f6 (+00..+14) and 8BBD at 0x40b0ae (+00..+38, which confirms round 8's code names);
  - the governor pressure solenoid controller, which was the `cm848_throttle*` family. Its offset limits had
    backwards names;
  - `cm848_selectGovernorPressureCruise` and the low range / normal lockup, unlock and shift functions.
- **Stage B (84be9af, label-only):**
  - the 30 tables after 8C18;
  - the exhaust brake tables: e2m 8CA6..8CC6, column 5 1010..1030, in that order at 0x4080b0..0x4082bf and 0x408606.
    Stage A had called them 11.46 tables;
  - `RE_Manual_2nd_Curve`;
  - `governor_pressure_exhaust_brake_curve`, the one table here with no 11.45 record.
- **Stage C (3301eb9): `TRANSMISSION_PRESSURE_STATE`.**
  - 24 members, every value proved by its store; the code compares only with 0x11 and 0x18. `check_enum_proof2.py`
    shows only enum substitutions.
  - Also the 27-word output speed ring and the `dword` fix that removes `_throttle_setpoint_limit_arg`.
- **Stage D ({hash_d}, label-only plus a field split): the 8C19 flag bytes.**
  - `transmission_control_flags_t` (0x40b0e8, +0..+9): `request_flags` (the 4-3 / 3-4 requests, the unlock request),
    `mode_flags` (cruise active, decel, low range), `state_flags`, `overdrive_flags`, `axle_ratio_learning_flags`,
    `limp_home_flags_1`..`4` and `low_range_boost_flags`.
  - `transmission_shift_strategy_flags_t` (0x40b0f2, +A..+11): `wide_open_throttle_flags`, `run_fuel_mode_flags`,
    `anti_hunt_flags` / `output_shaft_speed_flags` / `actuator_test_flags` (split from the 3-byte `flags`),
    `service_test_request_flags` and `limp_home_and_temperature_flags`.
- **Round 9 leads:**
  - Name the single bits of the limp-home and overdrive flag bytes. The e2m lists each byte's bit records, but not
    their positions.
  - The table lookup caches still named `protection_filter_stage_*_state` / `protection_rpm_limit_table_*_state` /
    `DAT_003fb1xx`: name each after its table.
  - The 11.45 T tables (`RE_One_Two_Lag` / `RE_Two_Three_Lag`) are the EEPROM adaptive shift lag tables (0x3fede2):
    name them.
  - 8BBB's tail (tow mode, brake 4-3, exhaust brake 4-3 command) is not in front of 8BBC in 11.46. Find it or show
    it is absent.
  - The other RE blocks: 8C33 / 8C34 (the converter clutch monitors), 8C55 (governor pressure rationality), 8C29 and
    8C49 (rock cycle torque management).

"""
edit(os.path.join(repo, "work", "tasks", "046-cm848-egr-flow-estimate.md"),
     [("## Leads (not in this PR)\n", R9_TASK + "## Leads (not in this PR)\n")])
edit(os.path.join(repo, "firmware", "CLAUDE.md"), [
    ("    it writes the row, and splits it when it reads one. Edit those rows with `line.split(\",\", 3)`. (Round 8\n"
     "    unquoted three comments that earlier scripts had written that way.)\n",
     "    it writes the row, and splits it when it reads one. Edit those rows with `line.split(\",\", 3)`. (Round 8\n"
     "    unquoted three comments that earlier scripts had written that way.)\n"
     "- **Round 9 (2026-11-21, PR #53): e2m column 5 is the ROM calibration layout.** The ROM blocks are numbered in\n"
     "  memory order; RAM blocks have 0000. So a run of table blocks can be walked from one known address, sizing each\n"
     "  table from its byte-length word in the dump (`round9/walk_tables.py`; a Z grid is nx x ny words with no header).\n"
     "  - The walk proved about 100 48RE tables: each lands on an existing `word[N]` row of exactly its size.\n"
     "  - It also places the scalar blocks 8BB5 (0x408ae0, the governor pressure controller), 8BBB (0x4077f6) and 8BBD\n"
     "    (0x40b0ae), and the exhaust brake tables (e2m 8CA6..8CC6, column 5 1010..1030).\n"
     "  - **Where 11.46 differs:** a grid's boost axis can sit inline before the grid, and some blocks moved or are\n"
     "    absent. Where the walk stops matching, stop, and check the code users.\n"
     "  - **The governor pressure modes** have one enum, `TRANSMISSION_PRESSURE_STATE` (24 members).\n"
     "  - **8C19** (0x40b0e8) is the RE flag block: `transmission_control_flags_t` and\n"
     "    `transmission_shift_strategy_flags_t`.\n"),
])
edit(os.path.join(repo, "work", "todo.md"), [
    ("the 48RE controller (the pressure state enum, the 8C19 flag bits, the 3-4 / 4-3 shift lines, blocks 8BB5 / 8BBB / "
     "8BBD), ",
     "the 48RE controller; round 9: the RE tables walked in e2m column-5 order (about 100 tables), 8BB5 / 8BBB / 8BBD, "
     "the governor pressure controller, TRANSMISSION_PRESSURE_STATE, the 8C19 flag structs - open: the flag bits, the "
     "lookup caches, the EEPROM shift lag tables, the remaining RE blocks (8C33 / 8C34 / 8C55 / 8C49), "),
])
R9_PR = f"""**Round 9 (another "keep going"): the 48RE tables in memory order, the governor pressure controller, the pressure
state enum, the flag bytes.**
- **The method:** e2m column 5 numbers every ROM calibration block in memory order (RAM blocks have 0000).
  `walk_tables.py` walks the tables from round 8's anchor, sizing each from its length word in the dump. About 100
  tables land on an existing `word[N]` row of exactly the walked size, and each one's users are the mode its record
  names.
- **Stage A (0f4daf6, label-only):**
  - the walked tables and the scalar blocks 8BB5 (the governor pressure controller's calibration), 8BBB and 8BBD;
  - the `cm848_throttle*` family, which is the governor pressure solenoid PID (its offset limits had backwards
    names);
  - `cm848_selectGovernorPressureCruise` and the low range / normal lockup, unlock and shift functions.
- **Stage B (84be9af, label-only):**
  - the tables after 8C18;
  - the exhaust brake tables, which are e2m 8CA6..8CC6 in their own column-5 range;
  - the manual 2nd curve.
- **Stage C (3301eb9):**
  - `TRANSMISSION_PRESSURE_STATE`, with 24 members, every value proved by its store and checked by
    `check_enum_proof2.py`;
  - the 27-word output speed ring;
  - a `dword` fix.
- **Stage D ({hash_d}):** the 8C19 flag bytes as `transmission_control_flags_t` / `transmission_shift_strategy_flags_t`.

"""
edit(pr, [("## Test plan\n", R9_PR + "## Test plan\n"),
          ("- [x] `./analyze.sh verify`: the two builds are byte-identical.",
           "- [x] Round 9:\n"
           "  - stages A, B and D are label-only (EQUIVALENT; D's 3-byte array split was read by hand);\n"
           "  - stage C passes `check_enum_proof2.py`, and its one other change is the ring array;\n"
           "  - the table walk matches about 100 existing rows by size and address.\n"
           "- [x] `./analyze.sh verify`: the two builds are byte-identical."),
          ("  - the rest of the 48RE controller (the pressure state enum, the 8C19 flag bits, the 3-4 / 4-3 shift lines, blocks\n"
           "    8BB5 / 8BBB / 8BBD);\n",
           "  - the rest of the 48RE controller (the single flag bits, the lookup caches, the EEPROM shift lag tables, blocks\n"
           "    8C33 / 8C34 / 8C55 / 8C49);\n")])
p = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "docs", "agent_notes_2026-11",
                 "session_2026-11-20_egr_flow_delay", "README.md")
s = open(p).read().rstrip("\n") + "\n\n" + """## Round 9: the 48RE tables in memory order (`session_folder/round9/`)

- **The table walk:** `walk_tables.py` walks e2m table blocks in column-5 order from a start address, sizing each from
  the dump. `walk_*.csv` are the walks from 0B43, 0B9E and 0BB5.
- **Stage A:** `worklist_r9a.py` and `apply_r9a_new.py`. The second adds label-only rows (empty type) for unnamed
  words.
- **Stage B:** `worklist_r9b.py` and `apply_r9b_fix.py`.
- **Stage C:** `apply_r9c_enum.py` and `apply_r9c_types.py`.
- **Stage D:** `apply_r9d_structs.py` (two structs, the field split), `worklist_r9d.py` and
  `refresh_qualified_r9d.py` (it refreshes `instance.field` mentions, which the generic refresh cannot do safely).
- **Commit messages:** `commit_r9*.txt`.
"""
open(p, "w").write(s)
print("README ok")
