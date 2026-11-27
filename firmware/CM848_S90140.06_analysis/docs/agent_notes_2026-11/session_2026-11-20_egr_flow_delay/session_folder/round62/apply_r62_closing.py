"""Round 62 closing: task 046, PR body, README, todo, memory. No CLAUDE.md edit. Idempotent.
usage: apply_r62_closing.py <repo> <pr_body.md> <hash A> <count> <proof> <unprefixed left>"""
import os
import re
import sys

repo, pr, ha, count, proof, left = os.path.abspath(sys.argv[1]), *sys.argv[2:7]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = f"""## Done, round 62 (2026-11-23, same PR): the J1939 registration functions, the DM7 test identifier, a startup fault delay

A peer relay started the round; the scripts are in `session_folder/round62/`.
- **Stage A ({ha}):**
  - **The registration functions called by `cm848_j1939_system_init`:**
    `cm848_registerJ1939ParameterAndBroadcastServices` / `cm848_registerJ1939MemoryWriteServices` /
    `cm848_registerJ1939MemoryReadServices` / `cm848_registerJ1939GetAddressByParameterIdService` (were the
    `j1939_diag_request_batch_*` / `_41_handler` names), `cm848_registerJ1939InputMessageHandlers` (was
    `j1939_pgn_handler_init_batch`) and `cm848_registerJ1939Dm7Handler` (was `cm848_initJ1939Dm1RequestHandler`).
  - **`j1939_dm7_test_identifier`** (was `j1939_dm1_request_mode_byte`): DM7's first byte, the Test Identifier
    (SPN 1224, from the local J1939 database).
  - **`j1939_input_fault_start_delay`** (was `governor_table_check_startup_delay`): while it counts down, the J1939
    input processors clear their data error and timeout faults instead of setting them.
  - **The vague Bank 2 helpers:** `cm848_initializeTorqueLookupCaches`, `cm848_initializeOxygenLimitLookupCaches`,
    `cm848_calculateFrictionTorquePercentAndNetOutputTorque` and `cm848_presetPedalFaultModeFuelDemand`.
  - **New rows:** the pedal fault mode engine speed filter and its coefficient (two type-only rows named) and
    `combustion_torque_by_fuel_quantity_timing_adjusted_cached_axis_offsets` (`word[2]`).
  - `cm848_validateJ1939DiagnosticRequest`'s plate says "is not 0xff" for the key test (round 61's lead).
- **Not done:** typing the J1939 service ID as `EF00_SERVICE_ID`. The enum covers all 24 registered IDs, but its
  members are placeholders or abbreviations (`SYSTEM_SERVICE_04`, `MEM_READ_2B_PARAM_4B_OFFSET`), and the handler
  names already say more.
- **Proof:** {proof}
- **firmware/CLAUDE.md:** no edit. HARD stays 0 and MISSING 219.
- **Leads:**
  - Rename the `EF00_SERVICE_ID` members from their registered handlers, then type the registrar's `service_id`
    parameter (24 call sites would read the names).
  - `DAT_003fba10`, the word next to the new cache in `cm848_calculateNetCombustionTorque`.
  - {left} unprefixed CM848-only functions remain. Round 61's "69" did not count its own rename, so it was 68.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 62.**\n"
     f"- **Stage A ({ha}):** the J1939 registration functions, the DM7 test identifier (SPN 1224), the J1939 input fault\n"
     "  start delay and four vague Bank 2 helpers are named from their code, and one more combustion torque cache is\n"
     "  typed.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 61:", f"- [x] Round 62: {proof}\n- [x] Round 61:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 62: the J1939 registration functions, the DM7 test identifier (`session_folder/round62/`)\n\n"
       "- **Stage A:** `service_ids.py`, `apply_r62a.py`, `map_r62a.csv`. Proof: `prove_r62.sh`. **Closing:** "
       "`apply_r62_closing.py`, `update_large_tar_r62.sh`.\n")
if "## Round 62:" not in t:
    i = t.index("## Round 61:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md",
     "round 61: both diagnostic service dispatch tables typed - open: the task 046 leads",
     "round 61: both diagnostic service dispatch tables typed; round 62: the J1939 registration functions and the DM7 "
     "test identifier - open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "the 3 name-mismatch warnings fixed); task 046 leads"
new = ("the 3 name-mismatch warnings fixed) + round 62 (the J1939 registration functions, the DM7 test identifier, "
       "the J1939 input fault start delay); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
f = M + "typing_focus_2026_11.md"
note = (f"  - Round 62 (2026-11-23): {ha}. Enum-typing pays only where a constant meets the type: check the members "
        "cover every value AND read better than what is already there before typing a parameter.\n")
if "Round 62 (2026-11-23" not in open(f).read():
    open(f, "a").write(note)
print("round 62 closing applied")
