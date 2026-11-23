"""Round 64 closing: task 046, PR body, README, todo, memory. Idempotent.
usage: apply_r64_closing.py <repo> <pr_body.md> <hash A> <hash B> <hash C> <count> <proof text file>"""
import os
import re
import sys

repo, pr, ha, hb, hc, count, proof_file = os.path.abspath(sys.argv[1]), *sys.argv[2:8]
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


T46 = f"""## Done, round 64 (2026-11-23, same PR): both kernels' transmit records, one result-code enum

A peer relay started the round on round 63's leads; the scripts are in `session_folder/round64/`.
- **Stage A ({ha}): the records `cm848_selectJ1939TransmitBuffer` hands out.**
  - `j1939_single_frame_tx_message` (0x3fcbc4) and `j1939_transport_tx_message` (0x3fc4ad), with their status
    bytes and data. `j1939_single_frame_tx_data` is `byte[8]`. `j1939_transport_tx_data` is a named first byte,
    because boot kernel thunks sit inside its 1800-byte extent.
  - The selector returns `j1939_tx_msg_t *`, so its three callers lose their casts.
- **Stage B ({hb}): the boot kernel's records.**
  - `diagnostic_response_message_t` was `j1939_tx_msg_t` field for field and is merged into it, along with two
    stale comment blocks.
  - The boot allocator gets the selector's prototype.
  - Its two data buffers are named (`diagnostic_transport_response_data` `byte[1800]`,
    `diagnostic_single_frame_response_data` `byte[8]`).
- **Stage C ({hc}): `J1939_DIAGNOSTIC_RESULT`.**
  - It merges `DIAG_RESPONSE` (0 / 4 / 7) and the unused `DIAG_RESPONSE_CODE`, which was ported from CM550.
  - 12 codes, named from what produces them in this firmware: the validator, the dispatcher, the memory workers,
    the region lookup and the handlers.
  - It types the validator's return and the dispatcher's `result_code`.
  - CM550's `DIAG_RESPONSE_CODE` type takes the same name; its members stay its own.
  - **A tool fix:** `refresh_other_csvs_r57.py` rewrote history notes ("(was DIAG_ACK ...)" became the new name).
    `refresh_other_csvs_r64.py` skips history markers as `refresh_references.py` does, and
    `history_corruption.py` finds a rewritten note. Round 63's renames show none.
- **Proof:** {proof}
- **firmware/CLAUDE.md:** no edit. HARD stays 0 and MISSING 219.
- **Leads:**
  - **The boot kernel's result codes differ:** 5 = unknown service, 10 = a ROM handler refused in EEPROM service
    mode. A boot twin of `J1939_DIAGNOSTIC_RESULT` would cover them.
  - 0x14 (CM550's CHECKSUM_MISMATCH) and 0xfe (answered with 0x0e by `cm848_sendJ1939ResponseFrame`) have no CM848
    producer found.
  - CM550's `J1939_DIAGNOSTIC_RESULT` / `J1939_DIAGNOSTIC_SERVICE` members are unreviewed.
  - Still open from round 63: the three unnamed length tables, `DAT_003fba10`, and 38 unprefixed CM848-only
    functions.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 64.**\n"
     f"- **Stage A ({ha}):** the two transmit records `cm848_selectJ1939TransmitBuffer` hands out are typed\n"
     "  `j1939_tx_msg_t` instances with named data and status bytes. The selector returns `j1939_tx_msg_t *`.\n"
     f"- **Stage B ({hb}):** the boot kernel's twin type is merged into `j1939_tx_msg_t`, and its allocator and\n"
     "  data buffers are typed.\n"
     f"- **Stage C ({hc}):** one result-code enum, `J1939_DIAGNOSTIC_RESULT` (12 codes, each named from its producer),\n"
     "  replaces two; CM550's copy of the type is renamed too.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 63:", f"- [x] Round 64: {proof}\n- [x] Round 63:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 64: both kernels' transmit records, one result-code enum (`session_folder/round64/`)\n\n"
       "- **Stage A:** `apply_r64a.py`. **Stage B:** `apply_r64b.py`. **Stage C:** `apply_r64c.py`, `map_r64c.csv`, "
       "`refresh_other_csvs_r64.py` (history-safe), `history_corruption.py`.\n"
       "- **Proof:** `prove_r64.sh` and round 63's `differing.py` / `review_typed.py` / `artifacts.py`. **Closing:** "
       "`apply_r64_closing.py`, `update_large_tar_r64.sh`.\n")
if "## Round 64:" not in t:
    i = t.index("## Round 63:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md",
     "round 63: the PGN 61184 diagnostic services in both kernels - open: the task 046 leads",
     "round 63: the PGN 61184 diagnostic services in both kernels; round 64: both kernels' transmit records and "
     "J1939_DIAGNOSTIC_RESULT - open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "disagree with CM848 = a bench lead); task 046 leads"
new = ("disagree with CM848 = a bench lead) + round 64 (both kernels' transmit records as j1939_tx_msg_t, the boot twin "
       "type merged, J1939_DIAGNOSTIC_RESULT from two enums; refresh_other_csvs_r64.py keeps '(was' notes); task 046 "
       "leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
f = M + "typing_focus_2026_11.md"
note = (f"  - Round 64 (2026-11-23): {ha} / {hb} / {hc}.\n"
        "    - A refresh over enums.csv and the other CSVs must keep '(was ...)' notes: r57's tool rewrote them. Use\n"
        "      r64/refresh_other_csvs_r64.py and check with r64/history_corruption.py.\n"
        "    - Two enums for one code space: merge them, and name each code from its producers.\n")
if "Round 64 (2026-11-23" not in open(f).read():
    open(f, "a").write(note)
print("round 64 closing applied")
