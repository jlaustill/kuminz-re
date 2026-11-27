"""Round 50 closing: task 046, PR body, README, todo, memory. No CLAUDE.md edit. Idempotent (guard: new text present).
usage: apply_r50_closing.py <repo> <pr_body.md> <hash A> <count> <proof>"""
import os
import re
import sys

repo, pr, ha, count, proof = os.path.abspath(sys.argv[1]), *sys.argv[2:6]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = f"""## Done, round 50 (2026-11-22, same PR): gaps by access signature - the TSC1-lost counter, the throttle threshold

A peer relay started the round; the scripts are in `session_folder/round50/`.
- **Method:** `gap_access_signatures.py` matches each gap by access signature. Every load and store inside it (raw
  lis + displacement scan) must land on a record of its width, with `lha` / `lhz` agreeing with the record's sign.
  Only four gaps still hold unnamed reads.
- **Stage A ({ha}, labels, rows):**
  - 8A7B (tiled between 8A2A and 8C49) holds the TSC1-lost counter's calibrations ("PTP mode" = the backup powertrain
    protection).
    - The counter, its reload and threshold, and its intermittent count join the `tsc1_lost_*` family:
      `tsc1_lost_counter`, `tsc1_lost_time_limit`, `tsc1_lost_intermittent_time_limit`,
      `tsc1_lost_intermittent_count`.
    - New rows: `tsc1_lost_counter_initial_value`, `tsc1_lost_maximum_intermittent_count`, and the documentation row
      `park_neutral_status_from_pci_message_0e_enable`.
  - 1585 (tiled between 1052 and 1034) is Throttle_Diff_Threshold: a new `i16` row,
    `commanded_throttle_difference_threshold`, where the commanded throttle filter ends a transient.
- **Proof:** {proof}
- **firmware/CLAUDE.md:** no edit. HARD stays 0 and MISSING 221.
- **Leads:** the two large gaps with unnamed reads (0x408d38 +62, 0x40b592 +52) have no one- or two-block fit; they may
  hold three or more blocks.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 50.**\n"
     f"- **Stage A ({ha}, labels, rows):** gaps matched by access signature. They give the TSC1-lost counter's calibrations\n"
     "  (e2m 8A7B), with the `j1939_tsc1_*` timing rows joining the `tsc1_lost_*` family, and the commanded throttle\n"
     "  difference threshold (1585).\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 49:", f"- [x] Round 50: {proof}\n- [x] Round 49:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 50: gaps by access signature (`session_folder/round50/`)\n\n"
       "- `gap_access_signatures.py` (+ `gap_access.txt`). **Stage A:** `apply_r50a.py`, `map_r50a.csv`, `prove_r50a.sh`. "
       "**Closing:** `apply_r50_closing.py`, `update_large_tar_r50.sh`.\n")
if "## Round 50:" not in t:
    i = t.index("## Round 49:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 49: 33 unnamed table-resolved reads named - open: the task 046 leads",
     "round 49: 33 unnamed table-resolved reads named; round 50: gaps by access signature (TSC1-lost, throttle) - open: "
     "the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "33 unnamed reads named from table-resolved e2m records); task 046 leads"
new = ("33 unnamed reads named from table-resolved e2m records) + round 50 (gap_access_signatures.py: TSC1-lost 8A7B, "
       "throttle 1585); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
f = M + "typing_focus_2026_11.md"
note = (f"  - Round 50 (2026-11-22): {ha}. Access signatures (every load / store in a gap on a record of its width, "
        "lha / lhz = S / U) place blocks even where no row exists yet; rounds 45-50 have used up most gaps of 64 bytes "
        "or less.\n")
if "Round 50 (2026-11-22" not in open(f).read():
    open(f, "a").write(note)
print("round 50 closing applied")
