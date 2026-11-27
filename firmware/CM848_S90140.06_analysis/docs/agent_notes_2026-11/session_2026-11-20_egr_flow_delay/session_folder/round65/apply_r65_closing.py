"""Round 65 closing: task 046, PR body, README, todo, memory. Idempotent.
usage: apply_r65_closing.py <repo> <pr_body.md> <hash A> <hash B> <count> <proof text file>"""
import os
import re
import sys

repo, pr, ha, hb, count, proof_file = os.path.abspath(sys.argv[1]), *sys.argv[2:7]
proof = open(proof_file).read().strip()


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = f"""## Done, round 65 (2026-11-23, same PR): the unprefixed CM848-only functions, the J1939 receive table

A peer relay started the round on round 63's lead; the scripts are in `session_folder/round65/`.
- **Stage A ({ha}): 37 of the 38 unprefixed CM848-only functions named from their code.** That leaves 1.
  - The application's J1939 transport (11), e.g. `cm848_startJ1939TransportSession`.
  - The 7 receive handlers, named with the database's PGN names (`cm848_receivePgn61441ElectronicBrakeController1Message`
    and so on), and their registrar `cm848_registerJ1939ReceiveHandler` (was `j1939_handlerInitializer`).
  - Two misnamed schedulers: `cm848_runCoolingFanControl` (was `j1939_periodic_processing`) and
    `cm848_scheduleJ1939PeriodicMessage` (was `diag_record_queue_add_entry`).
  - The injection angle cluster (10).
  - The SCI service timers, with the SCI 0x17 clear-diagnostics delay and its two bytes.
  - `cm848_getSensorChannelReferenceSupplyState`.
  - **Not renamed:** `initGovernorFlagsAux`. It only clears the word at 0x3fcfba, and nothing else is found reading
    it.
  - `firmware/CLAUDE.md`: the reference refresh updated 5 renamed names on 4 lines.
- **Stage B ({hb}): the receive table and its handlers.**
  - `j1939_receive_handler_table` (0x3fd414, `j1939_receive_handler_entry_t[17]`) with the registrar's prototype.
  - All 16 handlers take `j1939_rx_msg_t *message`. The 4 TP.CM sub-handlers that the TP.CM dispatcher calls with
    the message still in r3 now show that argument.
- **Proof:** {proof}
- **Leads:**
  - `initGovernorFlagsAux` / the word at 0x3fcfba, in the trip counter block.
  - 30 unprefixed names are shared with CM550. A rename needs both firmwares or neither.
  - Still open from rounds 63-64: the boot result codes, 0x14 / 0xfe, CM550's unreviewed members, the three length
    tables, and `DAT_003fba10`.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 65.**\n"
     f"- **Stage A ({ha}):** 37 of the 38 unprefixed CM848-only functions are named from their code: the J1939\n"
     "  transport, the receive handlers and their registrar, two misnamed schedulers, the injection angle cluster and the\n"
     "  SCI timers.\n"
     f"- **Stage B ({hb}):** the J1939 receive handler table is typed, and its 16 handlers take `j1939_rx_msg_t *`.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 64:", f"- [x] Round 65: {proof}\n- [x] Round 64:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 65: the unprefixed CM848-only functions, the J1939 receive table (`session_folder/round65/`)\n\n"
       "- **Stage A:** `apply_r65a.py`, `map_r65a.csv`. **Stage B:** `apply_r65b.py`, `param_passing.py`.\n"
       "- **Proof:** `prove_r65.sh` and round 63's `differing.py` / `artifacts.py`. **Closing:** `apply_r65_closing.py`, "
       "`update_large_tar_r65.sh`.\n")
if "## Round 65:" not in t:
    i = t.index("## Round 64:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md",
     "round 64: both kernels' transmit records and J1939_DIAGNOSTIC_RESULT - open: the task 046 leads",
     "round 64: both kernels' transmit records and J1939_DIAGNOSTIC_RESULT; round 65: 37 unprefixed CM848-only "
     "functions named and the J1939 receive table typed - open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "refresh_other_csvs_r64.py keeps '(was' notes); task 046 leads"
new = ("refresh_other_csvs_r64.py keeps '(was' notes) + round 65 (37 of 38 unprefixed CM848-only functions named - "
       "1 left: initGovernorFlagsAux; the J1939 receive table + its 16 handlers typed); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
print("round 65 closing applied")
