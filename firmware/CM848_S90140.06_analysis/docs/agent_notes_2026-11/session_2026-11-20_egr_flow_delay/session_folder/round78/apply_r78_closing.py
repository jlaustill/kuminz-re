"""Round 78 closing: task 046, PR body, session README, todo, memory. Idempotent (each edit skips when its new text is
already there).  usage: apply_r78_closing.py <repo> <pr_body.md> <hash A> <count> <proof A>"""
import os
import re
import sys

repo, pr, ha, count, proof_a_file = os.path.abspath(sys.argv[1]), *sys.argv[2:6]
proof_a = open(proof_a_file).read().strip()


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = f"""## Done, round 78 (2026-11-23, same PR): the last CM550 structs with a separate address per field row

A peer relay started the round; the scripts are in `session_folder/round78/`. This was round 77's first lead.
- **Stage A ({ha}), CM550:** the other 16 such structs are removed (68 rows). `multi_address_structs.py` now reports
  none in either firmware.
  - Their globals get the fields' scalar widths: a global that carried a removed type gets the field's width at its own
    address, and the three field addresses without a global get type-only rows.
  - The diagnostic transmit / receive buffers are `byte[256]`.
  - The four rendering ones (`data_collector_t`, `engine_rpm_history_t`, `fuel_arbitrator_diag_t`,
    `diagnostic_buffers_t`) gave 64 fake `global.field` renders of addresses that have their own globals.
    `prove_r78a_cm550.py` maps each old render to the address it reached and prints the name that address has now.
  - **Follow-up in the same commit:** the neighbors the oversize types had covered showed with `_` prefixes. They are
    typed from their decoded accesses (four words and a dword), and `io_control_bit0_state` is a dword (all its
    accesses were 4 bytes). Five coordinate rows of the removed types became
    type-only rows of the measured width, except 0x808DDC, whose accesses do not decode; that row is gone.
  - **Proof:** {proof_a}
- **firmware/CLAUDE.md:** none.
- **Leads:**
  - **The `io_control_*` names at 0x80D038-0x80D046 are older guesses.** 0x80D03E (`io_control_bit0_state`, now a
    dword) is a 32-bit sum with an overflow check, and its neighbor 0x80D042 is named
    `accumulated_backup_eps_period_between_vss_interrupts_0_65535`.
  - **The diagnostic receive buffer:** the code reaches 0x808D00 and 0x808DDC directly, past the 256 bytes typed here.
    The buffer may be larger, or another buffer may follow it.
  - From round 77: `j1708_pending_abort_count`; from round 76: the external devices at 0xFFC800 / 0xFFD000 /
    0xFFD800 and the 1280-byte parameter buffer at 0x80C7A8.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 78.**\n"
     f"- **Stage A ({ha}):** the last 16 CM550 structs with a separate address on each field row are removed (one\n"
     "  oversize type each, with fake field renders of other globals); their globals and the neighbors they covered are\n"
     "  typed from their accesses.\n"
     "\n## Test plan\n")
edit(pr, "- **Beyond CM848 (rounds 72-77):**", "- **Beyond CM848 (rounds 72-78):**")
edit(pr, "- [x] Round 77:", f"- [x] Round 78: A: {proof_a}\n- [x] Round 77:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 78: the last CM550 structs with a separate address per field row (`session_folder/round78/`)\n\n"
       "- **Stage A (CM550):** `multi_address_detail.py` (each struct's rows, the globals at its field addresses and their\n"
       "  field renders), `apply_r78a.py` (the 16 structs removed, their globals typed; `plan_r78a.txt`), `apply_r78a2.py`\n"
       "  (the exposed neighbors typed and the coordinate rows replaced), `field_widths.txt`.\n"
       "- **Proof:** `prove_r78a_cm550.py` (each old field render mapped to the address it reached, then a statement-level\n"
       "  comparison). **Closing:** `apply_r78_closing.py`, `update_large_tar_r78.sh`.\n")
if "## Round 78:" not in t:
    i = t.index("## Round 77:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 77: CM550's malformed J1708 state structs, the J1708 bus timer - open: the task 046 leads",
     "round 77: CM550's malformed J1708 state structs, the J1708 bus timer; round 78: the last CM550 multi-address "
     "structs - open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "16 such structs left); task 046 leads"
new = ("16 such structs left) + round 78 (the 16 removed - their globals get the field widths, the neighbors the oversize "
       "types covered typed from m68k accesses; none left in either firmware; io_control_bit0_state a dword; lead: the "
       "diagnostic receive buffer past 0x808D00); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
print("round 78 closing applied")
