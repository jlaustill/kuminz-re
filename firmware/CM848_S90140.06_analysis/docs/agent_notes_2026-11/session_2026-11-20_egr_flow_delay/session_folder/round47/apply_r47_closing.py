"""Round 47 closing: task 046, PR body, README, todo, memory. No CLAUDE.md edit. Idempotent (guard: new text present).
usage: apply_r47_closing.py <repo> <pr_body.md> <hash A> <hash B> <count> <proof A> <proof B>"""
import os
import re
import sys

repo, pr, ha, hb, count, pa, pb = os.path.abspath(sys.argv[1]), *sys.argv[2:8]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = f"""## Done, round 47 (2026-11-22, same PR): uncited table rows

A peer relay started the round; the scripts are in `session_folder/round47/`.
- **Method:**
  - `uncited_table_rows.py`: 5121 default-e2m scalar records resolve through the dumped parameter ID table, and 1295
    rows at those addresses do not cite their block.
  - `block_reliability.py`: the default e2m's layout drifts from this firmware for some blocks. A low word score only
    counts inside a block whose other rows match their records: 240 blocks are at least 70 % consistent, and they
    hold 49 outliers. Each was read against the code.
- **Stage A ({ha}, labels, a type):**
  - 0x40a336 `j1939_broadcast_enable_flag` (dword) -> `j1939_torque_and_load_not_available_flag` (word). It is 120C +6
    FSS_Torque_Load_Calculation_Flag: at 1 the EEC1 actual torque byte and the EEC2 percent load byte go out as 0xFE.
  - 0x3fad92 `j1939_dm1_spn_fmi_byte` -> `j1939_eec1_actual_engine_percent_torque_byte`; its only uses are in the
    EEC1 builder.
  - 0x40be5e `sensor_diag_default_a` -> `throttle_valve_actuator_position_sensor_fault_status` (1963 +4A).
  - **Proof:** {pa}
- **Stage B ({hb}, labels, a split):**
  - 0x40a442 `fuel_blend_correction_inhibit_flag` (dword) is two words of 1A57: `egr_off_allowed_flag` (+0
    CHH_CBO_Off) and a new `egr_cooler_fouled_flag` (+2 CHH_EGR_Cooler_Fouled).
  - 0x3fd530 `j1939_ccvs1_switch_logic_option_cal` -> `cruise_set_accelerate_switch_select_cal` (1180 +8).
  - **Proof:** {pb}
- **Kept:**
  - `sendPgn61444ElectronicEngineController1Message` keeps its unprefixed name, shared with its CM550 twin (0x32c76).
    The first attempt renamed it, and the CM550 grep caught it.
  - Drift cases are not renamed: 8A14 / 8A2B reach into the next block's base, and 8A0F +C lands under the chime
    flag.
- refresh_references.py rewrote the old dword's name inside three texts that described its two words; the texts are
  restored (`fix_r47b_texts.py`).
- **firmware/CLAUDE.md:** no edit. HARD stays 0 and MISSING 221.
- **Leads:**
  - The other 44 outliers in consistent blocks; most are wording differences, and the code would settle the rest.
    Candidates: 1070 +20 EB_Active_Driver_Fraction (its scale disagrees with the 0 / 100 the code writes), 10E3 +24 /
    +26 under two OBD names, 1226 +E, 8C34 +14, 1982 +A.
  - The 1295 uncited rows could take citations in bulk wherever their record matches.
  - 138 function names lack a firmware prefix. Many are shared with CM550 by design, so a sweep must rename both
    firmwares or keep the name.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 47.**\n"
     f"- **Stage A ({ha}, labels, a type):** an audit of rows the dumped parameter ID table resolves but that never cited\n"
     "  their e2m block. It renames the EEC1 / EEC2 torque-and-load 0xFE flag (retyped to a word), the EEC1 actual torque\n"
     "  byte (was `j1939_dm1_spn_fmi_byte`) and a throttle valve actuator status.\n"
     f"- **Stage B ({hb}, labels, a split):** the EGR off-allowed / cooler-fouled flags (a dword split into two words of\n"
     "  e2m 1A57) and the cruise set / accelerate switch select.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 46:", f"- [x] Round 47: stage A {pa} Stage B {pb}\n- [x] Round 46:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 47: uncited table rows (`session_folder/round47/`)\n\n"
       "- `uncited_table_rows.py` (+ `uncited.txt`), `block_reliability.py` (+ `reliable_leads.txt`). **Stage A:** "
       "`apply_r47a.py`, `map_r47a*.csv`. **Stage B:** `apply_r47b.py`, `map_r47b.csv`, `fix_r47b_texts.py`. "
       "**Closing:** `apply_r47_closing.py`, `update_large_tar_r47.sh`.\n")
if "## Round 47:" not in t:
    i = t.index("## Round 46:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 46: the warning chime, rock cycle torque management - open: the task 046 leads",
     "round 46: the warning chime, rock cycle torque management; round 47: uncited table rows - open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "park_neutral_exit_* = rock cycle torque management -> rock_cycle_*); task 046 leads"
new = ("park_neutral_exit_* = rock cycle torque management -> rock_cycle_*) + round 47 (uncited table rows: "
       "uncited_table_rows.py + block_reliability.py, 1295 uncited / 49 outliers in consistent blocks, 5 fixed); "
       "task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
f = M + "typing_focus_2026_11.md"
note = (f"  - Round 47 (2026-11-22): {ha} / {hb}. The default e2m's block layouts drift from this firmware (a block's tail "
        "can reach the next block's base), so judge a row by its record only when the block's other rows match "
        "(block_reliability.py). Unprefixed function names are often shared with CM550: grep CM550 before renaming. "
        "A dword the code reads as ._0_2_ / ._2_2_ is two words - check the e2m sizes.\n")
if "Round 47 (2026-11-22" not in open(f).read():
    open(f, "a").write(note)
print("round 47 closing applied")
