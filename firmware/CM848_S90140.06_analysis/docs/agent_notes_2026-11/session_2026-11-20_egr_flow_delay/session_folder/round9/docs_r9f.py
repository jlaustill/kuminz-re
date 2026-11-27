"""Round 9 stage F docs (the review's corrections): counts, the size-is-not-proof note, stage F, the leads, the stale
CLAUDE.md mentions, the PR test plan wording. usage: docs_r9f.py <repo> <pr_body.md> <stage F hash>"""
import os
import sys

repo, pr, hash_f = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]


def edit(path, pairs):
    s = open(path).read()
    for a, b in pairs:
        assert s.count(a) == 1, (path, a[:70], s.count(a))
        s = s.replace(a, b)
    open(path, "w").write(s)
    print(os.path.basename(path), len(pairs), "edits")


T046 = os.path.join(repo, "work", "tasks", "046-cm848-egr-flow-estimate.md")
edit(T046, [
    ("  - From round 8's anchor 0x407876 (0B43) every table through 0B98 lands on an existing `word[N]` row of exactly the\n"
     "    walked size: 58 tables. After 8C18, 0B9E..0BA9 and 0BB5..0BC6 match the same way: 30 more.\n",
     "  - From round 8's anchor 0x407876 (0B43) every table through 0B98 lands on an existing `word[N]` row of exactly the\n"
     "    walked size: 88 tables (86 blocks and 2 inline axes). After 8C18, 0B9E..0BA9 and 0BB5..0BC6 match the same\n"
     "    way: 30 more blocks.\n"
     "  - Two more groups sit by the walk's order and the code: the 2nd gear closed-throttle unlock pair, and the exhaust\n"
     "    brake tables. The exhaust brake tables are 32 (blocks 8CA6..8CC6 with two boost axes).\n"
     "  - A size match alone is not proof. 0B99 / 0B9A matched by size, but in 11.46 they are the manual 2nd pair, so\n"
     "    the code users decide.\n"),
    ("- **Round 9 leads:**\n",
     f"- **Stage F ({hash_f}, label-only, after a review):** the review fixes.\n"
     "  - **e2m 8BB6** aligns at 0x40b58c, the controller's RAM block (`RE_Deriv_Term` ... `RE_VFS_PWM_On_Time`). It\n"
     "    confirms stage A's controller names. `governor_pressure_derivative_term` and `governor_pressure_error_slope` get\n"
     "    their record names, and the proportional term at 0x40b59e is new. The old 8C34 `TCC_Function_Timer` note on\n"
     "    0x40b58c was wrong.\n"
     "  - **Old field names:** stage D's bare old field names in 48RE comments and plates (25 rows, 8 plates) now use the\n"
     "    new names. The P0720 monitor's plate names `limp_home_flags_4`: its bit 5 is `RE_OSS_Limp`, which confirms the\n"
     "    +8 alignment. `state_flags` bit 5 (service lockup) is an inference from its readers.\n"
     "  - **Other renames:** `governor_pressure_normal_curve` (was `_base_curve`, matching `RE_Normal_Curve` and the\n"
     "    enum's `NORMAL_CURVE`) and `overdrive_switch_power_on_delay_counter`.\n"
     "  - **Checked by code use:** the cruise resume words and the O/D switch power-on delay of 8BBB.\n"
     "- **Round 9 leads:**\n"
     "  - The 43 new label-only rows (8BB5 / 8BBB) have no type yet. Typing them is a cast-normalized stage.\n"
     "  - 8BB1-8BB4 (`RE_Axle_Ratio_Factor_*`, the axle ratio learning) and 8BB9 / 8BBA (`RE_Governor_Comp`, the\n"
     "    governor pressure compensation table before 8BBB).\n"
     "  - The limp-home bits: read each one from its fault setter, then the DTC, then the e2m record (as the P0720 bit\n"
     "    did).\n"
     "  - Signedness: the RE records carry the sign (column 10); deferred since round 8.\n"),
])
edit(os.path.join(repo, "firmware", "CLAUDE.md"), [
    ("converter clutch lockup (`cm848_applyConverterLockupSchedule`, the `fourth_gear_tcc_lockup_*` tables)",
     "converter clutch lockup (`cm848_applyConverterLockupSchedule`, the `transmission_4th_gear_lockup_maximum_throttle_*` "
     "and `transmission_cruise_lockup_maximum_throttle_*` grids, were `fourth_gear_tcc_lockup_*`)"),
    ("`LockupBoost` (e2m `RE_Lockup_Boost`, pressure state 0x10).\n",
     "`LockupBoost` (e2m `RE_Lockup_Boost`, pressure state 0x10), plus `Cruise` (round 9).\n"),
    ("  - The walk proved about 100 48RE tables: each lands on an existing `word[N]` row of exactly its size.\n",
     "  - The walk proved 118 48RE tables: each lands on an existing `word[N]` row of exactly its size. About 40 more\n"
     "    are placed by the walk's order and their code users.\n"
     "  - A size match alone is not proof. 0B99 / 0B9A matched by size, but 11.46 has the manual 2nd curve there, so\n"
     "    check each table's code users.\n"),
])
edit(pr, [
    ("sizing each from its length word in the dump. About 100\n  tables land", "sizing each from its length word in the dump. 118\n  tables land"),
    ("tables land on an existing `word[N]` row of exactly the walked size, and each one's users are the mode its record\n"
     "  names.\n",
     "tables land on an existing `word[N]` row of exactly the walked size, and each one's users are the mode its record\n"
     "  names. That is 88 + 30 walked, plus the exhaust brake set and a few placed by order and code, about 156 in all.\n"
     "  A size match alone is not proof: the code users decide.\n"),
    ("- **Stage D (f63a28b):** the 8C19 flag bytes as `transmission_control_flags_t` / `transmission_shift_strategy_flags_t`.\n",
     "- **Stage D (f63a28b):** the 8C19 flag bytes as `transmission_control_flags_t` / `transmission_shift_strategy_flags_t`.\n"
     f"- **Stage F ({hash_f}, label-only, after a review):**\n"
     "  - e2m 8BB6 confirms the controller's RAM names; the derivative term, error slope and proportional term get their\n"
     "    record names.\n"
     "  - Stage D's bare old field names in 48RE comments and plates are replaced.\n"
     "  - The P0720 monitor's bit is `limp_home_flags_4` bit 5 = `RE_OSS_Limp`.\n"
     "  - `governor_pressure_normal_curve`.\n"),
    ("  - stages A, B and D are label-only (EQUIVALENT; D's 3-byte array split was read by hand);\n",
     "  - stages A, B, D and F are label-only (EQUIVALENT; for D, the 3-byte array split normalized back to\n"
     "    `flags[0..2]` gives 0 differences);\n"),
    ("  - the table walk matches about 100 existing rows by size and address.\n",
     "  - the table walk matches 118 existing rows by size and address (88 + 30), and each table's users agree with its\n"
     "    record.\n"),
])
p = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "docs", "agent_notes_2026-11",
                 "session_2026-11-20_egr_flow_delay", "README.md")
s = open(p).read()
a = "- **Commit messages:** `commit_r9*.txt`.\n"
assert s.count(a) == 1
s = s.replace(a, "- **Stage F (the review fixes):** `worklist_r9f.py` and `apply_r9f_fix.py` (the 8BB6 records, the proportional "
                 "term row, the bare old field names in 48RE comments and plates). `csv_tail_check*.py` audits the CSVs for "
                 "the csv-module bug; `close_r9.py` writes the resolved notes.\n" + a)
open(p, "w").write(s)
print("README ok")
