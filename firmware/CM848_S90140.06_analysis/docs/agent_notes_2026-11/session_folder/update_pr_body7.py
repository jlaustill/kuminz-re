"""PR #50 body: the dword fix and rename wave 3."""
import sys

p = sys.argv[1]
t = open(p).read()
anchor = "## Finding for task 022: the J1939 pedal reaches fueling"
add = (
    "15. **Rename wave 3 (2c83cea, cfd889a, 3f64709).** Six read-only agents checked the first wave's further leads, retried the skipped tables and resolved every duplicate name.\n"
    "    - **Renamed:** 53 functions (plus 5 plate refreshes), 183 globals and 16 struct fields. `rpm_governor_state_t` becomes `wastegate_duty_controller_state_t`, with every field in half-duty counts; the `fault_entry_t` freeze-frame fields are renamed too.\n"
    "    - **Duplicates and junk:** all 21 duplicate names now have distinct names, 31 junk rows are deleted (27 `switchD`, 4 USIU), and 5 more tables are named (524 of 564).\n"
    "    - **New rows:** 113 rows for unnamed words, typed from their access widths. The two Q16 slew accumulators and 0x3fd108 are now dwords, which removes their underscores.\n"
    "    - **Highlights:** `crank_position_valid_flag` was the speed-limp-home flag read backwards (now `engine_speed_limp_home_active_flag`, with `cm848_enter/exitSpeedLimpHome`). Also the ERC1 / TSC1 retarder chain and the PGN 65213 / 65249 messages, the charging-regulator chain (P2504 / P2503), the P0148 / P1221 rail-pressure monitors, the per-injector diagnostic bitmaps (P0201–P0206 / P2146 / P2149), and `all_speed_governor_droop`.\n"
    "    - **Proof:**\n"
    "      - The renames map back exactly, comments aside. Goto-target labels are normalised for the deleted `switchD` rows, since Ghidra now names its own switch defaults.\n"
    "      - The new rows changed 13 functions beyond whitespace, and every change is a typing improvement: `0` instead of `'\\0'`, dropped `(short)` casts, `table[i]` arrays. Two rows were retyped when the first build showed added casts.\n"
    "      - **Reverted:** retyping the oil-change block 0x3fee34–0x3fee3d made three boot-ROM functions worse, because the boot ROM time-shares those bytes. That block keeps its old types, and the rows document why.\n"
    "      - `verify` is deterministic, the audit is clean, the tests pass and the headers compile.\n"
    "    - **Still open:** 9 items left uncertain and 49 further notes, recorded in task 042.\n\n")
assert t.count(anchor) == 1
open(p, "w").write(t.replace(anchor, add + anchor))
print("ok")
