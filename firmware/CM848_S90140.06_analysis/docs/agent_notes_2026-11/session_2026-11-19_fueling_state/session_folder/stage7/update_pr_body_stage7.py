"""Add stage 7 (the e2m audit, rename wave 12, the fueling chain's e2m names) to pr_body.md.
usage: update_pr_body_stage7.py <pr_body.md>"""
import sys

path = sys.argv[1]
s = open(path).read()


def replace(old, new):
    global s
    assert s.count(old) == 1, old[:70]
    s = s.replace(old, new)


replace("This PR does six stages:", "This PR does seven stages:")
replace("now `ema_filter_state_t`.\n",
        "now `ema_filter_state_t`.\n"
        "7. **The audit.** Every e2m record the table resolves was compared with the CSV, and 383 unnamed addresses the code "
        "uses got names (rename wave 12). The fueling chain takes its e2m names: `governor_fuel_demand_mode`, where this "
        "PR began, is `adjusted_user_fueling_state` ([FSGVFLST]).\n")
replace("## Checks\n", """## Stage 7: the e2m audit, rename wave 12, the fueling chain's e2m names

- **The audit.** `firmware/scripts/e2m_name_audit.py` (tested) resolves every scalar e2m record through the parameter ID table and reports the row at its address: 4691 records, 3000 already named, 1397 without a row, 244 inside a wider row and 50 on unnamed rows. It also gives each dump value against the record's range and a word-overlap score against the current name.
- **Rename wave 12.** 398 records had no name, a code reference and an in-range dump value. Six read-only agents each took a bin of whole blocks, named each record from the e2m, checked its code use and access width, and rejected layout drift.
  - **Verdicts:** 384 confirmed, 6 uncertain, 8 rejected.
  - **Drift:** the labelled e2m is 11.45 and the truck runs 11.46.06. Five blocks shifted, and in each case the code confirmed the table's block, not the e2m offset.
  - **The gate** (the rename_waves rules, cross-bin duplicates, collisions, rows already present, type against size) passed **383 new rows**.
- **The fueling chain's e2m names** (blocks 1045 / 1051, each checked against its writer):
  - `adjusted_user_fueling` / `adjusted_user_fueling_state` (were `governor_fuel_demand_value` / `governor_fuel_demand_mode`, [FSGVFL] / [FSGVFLST]);
  - `final_fueling` (was `fuel_demand_computed`) and its freeze-frame field, `requested_fueling` and `master_slave_control_flag`;
  - `torque_derate_torque_limit` / `_state`. Stage 4 had named these after the power take-off, which is only one source of that limit;
  - `torque_control_indication_flag` and the two "before combustion reference" values.

## Checks
""")
replace("- Every `FUELING_STATE_` name in the `.cpp` sits on a carrier.\n",
        "- **Stage 7.** All 393 names render, with no `_` variant. Distinct `DAT_` labels fell from 1433 to 1047, which is the 383 new rows plus three byte labels now inside a `byte[4]`. Build warnings are unchanged. The 33 differing functions all come from typing the new rows:\n"
        "  - casts and local types;\n"
        "  - renumbered temporaries and local declaration order;\n"
        "  - `PTR_<target>_<address>` labels of unnamed pointers whose targets now have names;\n"
        "  - one table base now indexed in dwords.\n"
        "  One bad render was fixed: a 4-byte version read bytewise, now `byte[4]`.\n"
        "- Every `FUELING_STATE_` name in the `.cpp` sits on a carrier.\n")
replace("- An audit of the whole CSV against the parameter ID table. 445 of its 1886 records lie past the end of the flash2 dump.\n",
        "- **Wave 13, the misname half of the audit:** the 1610 named rows with a low word overlap (mostly struct instances and synonyms, but real misnames too), the 244 rows inside wider rows, and the 24 records whose dump value is out of range. Task 045 lists the wave-12 agents' leads. 445 of the table's 1886 records lie past the end of the flash2 dump.\n")
open(path, "w").write(s)
print("pr_body.md updated for stage 7")
