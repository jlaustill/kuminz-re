"""Round 7 closing 2: the docs for the final review's fixes. usage: docs_r7e.py <repo> <pr_body.md>"""
import os
import sys

repo, pr = os.path.abspath(sys.argv[1]), sys.argv[2]


def edit(path, pairs):
    s = open(path).read()
    for a, b in pairs:
        assert s.count(a) == 1, (path, a[:60], s.count(a))
        s = s.replace(a, b)
    open(path, "w").write(s)
    print(os.path.basename(path), len(pairs), "edits")


edit(os.path.join(repo, "work", "tasks", "046-cm848-egr-flow-estimate.md"), [
    ("    - `retarder_tsc1_speed_control_flag`: always 0, because speed control is rejected;\n",
     "    - `retarder_tsc1_speed_control_flag`: always 0, because speed control is rejected. Its role as the retarder\n"
     "      twin of `tsc1_speed_control_flag` is inferred, since no e2m record covers 0x40ae20-0x40ae4c;\n"),
    ("  - Range codes 2 and 3 are never tested apart; the readers only test 1 against everything else.\n",
     "  - Range codes 2 and 3 are never tested apart; the readers only test 1 against everything else.\n"
     "  - e2m 1185 +A calls Top_Gear_Ratio the ratio above which the transmission is in top gear, but the code sets top\n"
     "    gear below the threshold. The period formula makes the ratio engine speed / vehicle speed, lowest in top gear,\n"
     "    so the code holds. The 0.8 / 1.0 ratios are not checked against the truck's gearing.\n"
     "  - The session record length words have no direct load or store in the disassembly; e2m gives these type T\n"
     "    records no size.\n"),
])
edit(os.path.join(repo, "firmware", "CLAUDE.md"), [
    ("  - **The importer:** a `function_definitions` / `local_variables` type `int` becomes `dword`; use\n"
     "    `int32_t` for a signed int.\n",
     "  - **The importer:** the two session functions' `session_kind` needed `int32_t` (see the \"Prototype / local type\n"
     "    keywords\" rule above).\n"),
])
edit(pr, [("- **Stage B (types):**\n  - **`j1939_control_session_t`,** the j1939mon record",
           "- **Stage B (8b1c0f3, types):**\n  - **`j1939_control_session_t`,** the j1939mon record")])
