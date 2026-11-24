"""Round 82 closing: task 046, PR body, session README, todo, memory. Idempotent (each edit skips when its new text is
already there).  usage: apply_r82_closing.py <repo> <pr_body.md> <hash A> <count> <proof A>"""
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


T46 = f"""## Done, round 82 (2026-11-24, same PR): CM550's TPU set-up functions

A peer relay started the round; the scripts are in `session_folder/round82/`. This was round 81's first lead.
- **Stage A ({ha}), CM550:** the six CAN-named functions that touch only the TPU are renamed for the TPU channel each
  sets up and, where the Cummins-named globals they fill show it, the signal.
  - `mc68k_loadTpuMicrocode` (was `mc68k_initInternalRamAndCAN1`): copies ROM 0x30c9c / 0x31328 into the TPU RAM at
    0xFFE000 and sets `TPU_TPUMCR = 0x407`, whose bit 0x400 runs the TPU from its RAM. So the TPU's function numbers
    are Cummins' own.
  - `mc68k_initializeTpuChannel0MissingToothInput`: the missing-tooth wheel input.
  - `mc68k_initializeTpuChannel1BackupSpeedInput`: the backup speed sensor.
  - `mc68k_initializeTpuChannel10PrimarySpeedInputDivided` / `...IfEnabled` (when `_ESSXSNEN` bit 0 is set): the
    primary speed sensor's two modes.
  - `mc68k_initializeTpuChannel12`: function 0xb. It also computes `_tach_output_minimum_rpm`, so the channel may be
    the tachometer output (not checked).
  - **Proof:** {proof_a}
- **firmware/CLAUDE.md:** none.
- **Leads:**
  - The TPU microcode is in ROM at 0x30c9c-0x31327 and 0x31328-0x31427. Its function table and entry points would
    name each channel's function.
  - The `pwmTimerMode*` functions (TPU-only).
  - The CS4 message object handlers.
  - The 182 rows inside the EEPROM write queue's range.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 82.**\n"
     f"- **Stage A ({ha}):** CM550's six CAN-named TPU set-up functions renamed for the channel and signal each sets up\n"
     "  (the missing-tooth input, the primary / backup speed sensors) and the TPU microcode loader.\n"
     "\n## Test plan\n")
edit(pr, "- **Beyond CM848 (rounds 72-81):**", "- **Beyond CM848 (rounds 72-82):**")
edit(pr, "- [x] Round 81:", f"- [x] Round 82: A: {proof_a}\n- [x] Round 81:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 82: CM550's TPU set-up functions (`session_folder/round82/`)\n\n"
       "- **Stage A (CM550):** `apply_r82a.py`, `map_r82a.csv`; `ch10_a.txt` / `ch10_b.txt` (the two channel 10 modes).\n"
       "- **Closing:** `apply_r82_closing.py`, `update_large_tar_r82.sh`.\n")
if "## Round 82:" not in t:
    i = t.index("## Round 81:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 81: CM550 functions renamed for the hardware they drive - open: the task 046 leads",
     "round 81: CM550 functions renamed for the hardware they drive; round 82: CM550's TPU set-up functions and "
     "microcode loader - open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "the can1* TPU-only functions are leads); task 046 leads"
new = ("the can1* TPU-only functions are leads) + round 82 (those six renamed: mc68k_loadTpuMicrocode - CM550's TPU runs "
       "Cummins microcode from the TPU RAM (TPUMCR 0x407) - and the TPU channel 0 missing-tooth / 1 backup speed / 10 "
       "primary speed / 12 set-ups); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
print("round 82 closing applied")
