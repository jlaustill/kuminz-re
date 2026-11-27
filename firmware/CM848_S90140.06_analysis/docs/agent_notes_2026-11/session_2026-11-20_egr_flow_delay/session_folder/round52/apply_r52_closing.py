"""Round 52 closing: task 046, PR body, README, todo, memory. No CLAUDE.md edit. Idempotent (guard: new text present).
usage: apply_r52_closing.py <repo> <pr_body.md> <hash A> <hash B> <count> <proof>"""
import os
import re
import sys

repo, pr, ha, hb, count, proof = os.path.abspath(sys.argv[1]), *sys.argv[2:7]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = f"""## Done, round 52 (2026-11-23, same PR): nine more blocks record for record, five state enums

A peer relay started the round; the scripts are in `session_folder/round52/`.
- **Method:** `record_for_record_matches.py`.
  - For every absent block, it tries each base that puts the block's first or second record on an existing row, and
    counts records that land on a row start of the same width.
  - A base is rejected if any record lands inside a row, on a row of another width, or in a span already citing an
    e2m block.
  - The mixed-width hits were read by meaning.
  - Dense all-word areas match any all-word block at every even offset, so width alone is only a filter.
- **Stage A ({ha}, labels, rows, comments):**
  - 8B23 (92 records) and 8A5F (46): the cooling fan and EVR / alternator field calibrations, on their code-named
    rows.
  - 8B22 (30) and 8A60 (21): their RAM.
  - 8B21 (11): the radiator fan speed sensor. It joins the transmission's 8BB2 vocabulary
    (`radiator_fan_speed_maximum / _minimum / _period_*`, `radiator_fan_pulses_per_revolution`, which was a
    "prescaler").
  - 15B4 (7): the reset capture. The exception stubs move SRR0 / a vector byte / LR into SPRG0-2, so the rows become
    `exception_srr0 / _vector / _link_register`. `hardware_timer_capture` becomes
    `power_on_reset_to_first_executive_frame_time`.
  - 8B9A / 8BB4: the rest of round 51's transmission RAM, now four blocks back to back at 0x40b620. Round 51's "no
    RAM record" for the limp-in timer was wrong.
  - The governor pressure solenoid's retest records (8BB5 +50 / +52, 8BB6 +1A) get documentation rows. Nothing reads
    them: unlike the fan and EVR drivers, this one only latches.
  - 8BB3 is cited on the learned output-speed-to-vehicle-speed ratio.
  - The e2m splits long value-label lists over duplicate records; the citations merge them.
- **Stage B ({hb}, enums):** five state enums from those labels, each member read against its storing branch:
  - `COOLING_FAN_COOLANT_REQUEST_STATE`, `COOLING_FAN_SPEED_TARGET_SOURCE` (16), `COOLING_FAN_DUTY_SOURCE` (12);
  - `ALTERNATOR_FIELD_REGULATOR_STATE` (on the state and its previous-state copy);
  - `ALTERNATOR_FIELD_LOAD_RESPONSE_STAGE`.
- **Proof:** {proof}
- **firmware/CLAUDE.md:** no edit. HARD stays 0 and MISSING 221.
- **Leads:**
  - The matcher's all-word hits (343 of 433) are unreviewed and need a by-meaning pass.
  - The alternator field regulator's state handlers (the table at 0x57730) return the next state and could return the
    enum.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 52.**\n"
     f"- **Stage A ({ha}, labels, rows):** nine more e2m blocks record for record: the cooling fan (8B23 / 8B22 / 8B21),\n"
     "  the alternator field (8A5F / 8A60), the reset capture (15B4: `exception_srr0 / _vector / _link_register` from the\n"
     "  exception stubs' SPRG saves), and round 51's transmission RAM (8B9A / 8BB4).\n"
     f"- **Stage B ({hb}, enums):** five state enums from those blocks' value labels.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 51:", f"- [x] Round 52: {proof}\n- [x] Round 51:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 52: nine more blocks record for record, five state enums (`session_folder/round52/`)\n\n"
       "- Search: `record_for_record_matches.py` (+ `record_matches.txt`), `placement_*.txt`, `find_sprg_writers.py`. "
       "**Stage A:** `apply_r52a.py` (`apply_r52a_first_draft.py` = before the retest names and the six blocks), "
       "`map_r52a.csv`, `prove_r52a.sh`. **Stage B:** `apply_r52b.py`, `prove_enum_substitution.py`. **Closing:** "
       "`apply_r52_closing.py`, `update_large_tar_r52.sh`.\n")
if "## Round 52:" not in t:
    i = t.index("## Round 51:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md",
     "round 51: the 0x408d38 gap = four blocks, the trip information blocks, the P0711 state enum - open: the task 046 "
     "leads",
     "round 51: the 0x408d38 gap = four blocks, the trip information blocks, the P0711 state enum; round 52: nine more "
     "blocks record for record (fan / alternator field / reset capture), five state enums - open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "bitfields on mask-only words rejected); task 046 leads"
new = ("bitfields on mask-only words rejected) + round 52 (record_for_record_matches.py: fan 8B23/8B22/8B21, EVR "
       "8A5F/8A60, reset capture 15B4 = SRR0/vector/LR, 5 state enums); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
f = M + "typing_focus_2026_11.md"
note = (f"  - Round 52 (2026-11-23): {ha} / {hb}. Absent blocks found record for record: same-width row starts, no record "
        "inside a row, no span already citing an e2m block, then read by meaning (mixed-width hits are the reliable "
        "ones). The e2m splits long value-label lists over duplicate records: merge them before naming enum members.\n")
if "Round 52 (2026-11-23" not in open(f).read():
    open(f, "a").write(note)
print("round 52 closing applied")
