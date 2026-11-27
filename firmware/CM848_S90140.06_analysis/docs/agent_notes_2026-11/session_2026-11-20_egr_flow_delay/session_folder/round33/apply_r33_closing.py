"""Round 33 closing: task 046, PR body, README, todo, memory. Idempotent.
usage: apply_r33_closing.py <repo> <pr_body.md> <stage A hash> <stage B hash>"""
import os
import sys

repo, pr, ha, hb = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3], sys.argv[4]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = f"""## Done, round 33 (2026-11-22, same PR): the J1939 transmit status bytes and three text / configuration payloads

A peer relay started the round. Scripts are in `session_folder/round33/`.
- **Stage A ({ha}, labels):**
  - The finding: `j1939_tx_msg_t`'s third field is the pointer to the message's status byte, not a data end pointer.
    `mpc555_sendJ1939SingleFrame` stores its result there (0 queued / 1 zero length / 4 queue full), and the
    application transport stores its session codes there (0x12 started / 0x13 sending / 9 complete / 10 aborted /
    6 clear to send timeout / 7 send failed / 8 busy / 3 not our source address).
  - The five multi-frame builders (EC1, DM1, DM2, DM4, RC) rebuild only while its 0xf0 nibble is clear.
  - The field is `status_pointer`, the name its boot twin `diagnostic_response_message_t` already had.
  - 29 new `j1939_<message>_transmit_status` byte rows (all `lbz`), and DM1's misnamed
    `j1939_dm1_fault_data_channel_byte` renamed.
  - `j1939_ackm_msg` is `j1939_pgn59392_tx_message`; five stale flat rows inside it are now dotted documentation
    rows.
  - The proof needed the field rename applied forward to the old `.cpp`, since the boot twin's `status_pointer`
    collides with a reverse map. One derived `PTR_` row was proof-only.
- **Stage B ({hb}, types):**
  - The RC (PGN 65249) payload. Its byte 1 decodes against SPN 901 / 902: exhaust brake (0x14) for one retarder
    output driver, compression release brake (3) for two or more.
  - The CI (PGN 65259) payload, which covers the boot-called 0x3fab3c: the thunk became a call override.
  - The SOFT (PGN 65242) payload, plus the decimal text formatter's prototype. Its int text buffer had made a struct
    field print as a bare constant.
  - Proof: 1962 functions token-equal, 2 declaration reorders, 5 read as label-substituted diffs.
- **Leads:**
  - Round 34: the application J1939 transport transmit session (`j1939_multiframe_tx_*`, the `ptr` / `addr` / `len`
    abbreviations) as a struct, with `initiateJ1939TransportProtocol(j1939_tx_msg_t *msg)` and
    `mpc555_sendJ1939SingleFrame`'s parameters. They were deferred so the same functions change only once.
  - `j1939_diag_response_word_b` (0x3faddd) sits at EFL/P1 bytes 5-6 (SPN 101 crankcase pressure in J1939-71):
    check its writer.
  - The stale rows `j1939_rpm_tx_word+1` / `j1939_etc1_speed_offset_tx_word+1` (0x3faeb0-0x3faeb3).
  - The component / software identification sources in the EEPROM mirror (0x3fd653, 0x3fd69b-0x3fd6b9, 0x3fd71b)
    have no e2m records; name them once their writers are found.
  - Prototype `char` maps to `byte`, so ASCII digits print as 0x30.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 33.**\n"
     f"- **Stage A ({ha}, labels):** the J1939 transmit descriptor's third field is the status pointer (was\n"
     "  `data_end_pointer`). 30 status bytes are named, the ACK descriptor is `j1939_pgn59392_tx_message`, and five\n"
     "  stale rows inside it are fixed.\n"
     f"- **Stage B ({hb}, types):** the RC (PGN 65249), CI (PGN 65259) and SOFT (PGN 65242) payloads as structs, and\n"
     "  the decimal text formatter's prototype. RC byte 1 decodes as exhaust brake (one driver) or compression release\n"
     "  brake (two or more).\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 32: stage A matches token for token apart from the check's parameter names (verified) and one\n"
         "  declaration reorder.",
     "- [x] Round 33: stage A is EQUIVALENT (with the field rename applied forward and one derived `PTR_` row);\n"
     "  stage B matches token for token apart from 2 declaration reorders and 5 hand-read functions.\n"
     "- [x] Round 32: stage A matches token for token apart from the check's parameter names (verified) and one\n"
     "  declaration reorder.")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 33: the J1939 transmit status bytes and three payload structs (`session_folder/round33/`)\n\n"
       "- **Stage A:** `status_bytes.py` (every descriptor's status byte and its readers), `coverage_check.py` (what "
       "covers an address), `apply_r33a.py`, `fix_text_r33a.py`; the proof map `map_r33a_proof*.csv` and "
       "`proof_r33a.txt`. **Stage B:** `apply_r33b.py`, `apply_r33b2.py`; the proof `tokens_r33b.json`, "
       "`check_reorders_r33b.py`, `diff_functions.py` (label-substituted unified diffs). **Closing:** "
       "`apply_r33_closing.py`.\n")
if "## Round 33:" not in t:
    i = t.index("## Round 32:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 32: the discrete output read-back checks - open: the task 046 leads",
     "round 32: the discrete output read-back checks; round 33: the J1939 transmit status bytes, the RC / CI / SOFT "
     "payload structs - open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = m.replace("(cm848/egr-flow-delay-model, 169 commits)", "(cm848/egr-flow-delay-model, 172 commits)")
old = "(the discrete output read-back checks, 11 outputs; messy_functions.py ranks what is left); task 046 leads"
new = ("(the discrete output read-back checks, 11 outputs; messy_functions.py ranks what is left) + round 33 "
       "(j1939_tx_msg_t.status_pointer was data_end_pointer: 30 transmit status bytes; the RC / CI / SOFT payload "
       "structs); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
f = M + "typing_focus_2026_11.md"
note = (f"  - Round 33 (2026-11-22): {ha} the J1939 transmit descriptor's third field = status pointer (send result / "
        f"transport session code; builders gate on the 0xf0 nibble), 30 status bytes, j1939_ackm_msg -> "
        f"j1939_pgn59392_tx_message; {hb} the RC / CI / SOFT payload structs (CI covers the boot-called 0x3fab3c -> "
        "call override). Proof tricks: a field rename that collides with another struct's field needs the rename "
        "applied forward to the old .cpp; a struct over RAM-image code units clears them. Next: the application "
        "transport transmit session struct.\n")
if "Round 33 (2026-11-22" not in open(f).read():
    open(f, "a").write(note)
print("round 33 closing applied")
