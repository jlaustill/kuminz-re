"""Round 55 closing: task 046, PR body, README, todo, memory. No CLAUDE.md edit. Idempotent.
usage: apply_r55_closing.py <repo> <pr_body.md> <hash A> <count> <proof>"""
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


T46 = f"""## Done, round 55 (2026-11-23, same PR): the fault manager core named from its code

A peer relay started the round; the scripts are in `session_folder/round55/`.
- **Stage A ({ha}, function names and plates):** the fault manager at 0x533aec-0x535344, read function by function
  (`function_summary.py` lists a range's functions, plates and callers).
  - 14 unprefixed legacy names and `cm848_initFaultManagement` (now "initialize").
  - Two old names were swapped in meaning: `diag_resetSingleFault` cleared every record (now
    `cm848_clearAllFaultRecords`) and `diag_resetAllFaults` only the previously active faults (now
    `cm848_clearPreviouslyActiveFaults`, the DM3 meaning).
  - The others: the warm-up cycle auto clear, the similar-conditions test, the heal step, the occurrence count, the
    freeze frame queue, the detection record (pending, then confirmed), and the completed-monitor registration.
  - `diagnosticMainStateProcessor` is shared with CM550 and keeps its name.
- **Proof:** {proof}
- **firmware/CLAUDE.md:** no edit. HARD stays 0 and MISSING 221.
- **Leads:**
  - 84 unprefixed CM848-only functions remain. The protection cluster at 0x514048-0x514394 is next.
  - The fault manager's prototypes still read `param_1` (the slot or fault code); naming them needs full
    `function_definitions.csv` rows.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 55.**\n"
     f"- **Stage A ({ha}, function names):** the fault manager core, 15 functions named from their code. Two old names\n"
     "  were swapped in meaning (`cm848_clearAllFaultRecords` / `cm848_clearPreviouslyActiveFaults`).\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 54:", f"- [x] Round 55: {proof}\n- [x] Round 54:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 55: the fault manager core named from its code (`session_folder/round55/`)\n\n"
       "- `function_summary.py`. **Stage A:** `apply_r55a.py`, `map_r55a.csv`, `refresh_struct_comments_r55.py`. "
       "Proof: `prove_r55.sh`. **Closing:** `apply_r55_closing.py`, `update_large_tar_r55.sh`.\n")
if "## Round 55:" not in t:
    i = t.index("## Round 54:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md",
     "round 54: the last unnamed tables, the stack monitor, legacy boot functions - open: the task 046 leads",
     "round 54: the last unnamed tables, the stack monitor, legacy boot functions; round 55: the fault manager core "
     "(15 functions) - open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "high-water monitor; 5 legacy boot functions); task 046 leads"
new = ("high-water monitor; 5 legacy boot functions) + round 55 (the fault manager core: 15 functions, two old names "
       "swapped in meaning); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
f = M + "typing_focus_2026_11.md"
note = (f"  - Round 55 (2026-11-23): {ha}. The fault manager core named from its code; legacy names can be swapped in "
        "meaning (resetSingleFault cleared everything). refresh_references.py skips structure_definitions.csv: refresh "
        "struct field comments by hand.\n")
if "Round 55 (2026-11-23" not in open(f).read():
    open(f, "a").write(note)
print("round 55 closing applied")
