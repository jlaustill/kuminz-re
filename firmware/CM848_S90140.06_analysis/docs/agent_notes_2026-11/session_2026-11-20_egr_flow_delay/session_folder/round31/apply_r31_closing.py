"""Round 31 closing: task 046, PR body, README, todo, and the memory note. Idempotent.
usage: apply_r31_closing.py <repo> <pr_body.md> <stage A hash>"""
import os
import sys

repo, pr, ha = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = f"""## Done, round 31 (2026-11-22, same PR): the J1939 EC1 payload as a struct

A peer relay started the round; the lead is round 30's. Scripts are in `session_folder/round31/`.
- **Stage A ({ha}, types):** `j1939_pgn65251_payload_t` is the 28-byte EC1 (PGN 65251) payload in the original
  J1939-71 layout and J1939 byte order.
  - Two instances: the payload and the send-on-change previous copy.
  - The SPN names come from the automotive `j1939_spns` table. The local Mongo `j1939` entry for 65251 holds the
    PGN 65252 Shutdown parameters.
  - Field widths follow the code's accesses: words where it reads a halfword (one unaligned, at +9), byte pairs
    where it joins two bytes, bytes for the torques and limits.
  - `cm848_sendPgn65251EngineConfiguration1OnChange` and `initializePgn65251EngineConfiguration1Buffer` read by
    field. They were `DAT_` / `ram0x` / `CONCAT11` renders. The compiler's four dword copies stay pieces.
  - Underscore renders 31 -> 23.
- **The proof:** only those two functions differ, and each access was checked against its old byte offset.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 31.**\n"
     f"- **Stage A ({ha}, types):** the J1939 EC1 (PGN 65251) payload and its previous copy as one 28-byte struct with\n"
     "  the SPN fields; the send-on-change test now reads by field.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 30: stage A is EQUIVALENT.",
     "- [x] Round 31: stage A changes only the two EC1 functions, each access checked.\n"
     "- [x] Round 30: stage A is EQUIVALENT.")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 31: the J1939 EC1 payload as a struct (`session_folder/round31/`)\n\n"
       "- **Stage A:** `apply_r31a.py` (the struct, the instances, the dotted rows). **Closing:** "
       "`apply_r31_closing.py`.\n")
if "## Round 31:" not in t:
    i = t.index("## Round 30:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 30: the watchdog fueling monitor - open: the task 046 leads",
     "round 30: the watchdog fueling monitor; round 31: the J1939 EC1 payload struct - open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = m.replace("(cm848/egr-flow-delay-model, 165 commits)", "(cm848/egr-flow-delay-model, 167 commits)")
old = "was fuel_quantity_demand_monitor); task 046 leads"
new = ("was fuel_quantity_demand_monitor) + round 31 (the J1939 EC1 PGN 65251 payload struct, 2 instances); task 046 "
       "leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
f = M + "typing_focus_2026_11.md"
note = ("  - Round 31 (2026-11-22): 8146833 j1939_pgn65251_payload_t (EC1, 28 bytes J1939 LE, 2 instances 0x3fa7f8 / "
        "0x3fa814): field widths from the decompiled accesses (words incl. an unaligned one at +9, byte pairs where "
        "CONCAT11 joins two bytes); unaligned struct fields work; the local Mongo j1939 65251 entry holds 65252's "
        "parameters - use the automotive Postgres j1939_spns table for SPN names.\n")
if "Round 31 (2026-11-22" not in open(f).read():
    open(f, "a").write(note)
print("round 31 closing applied")
