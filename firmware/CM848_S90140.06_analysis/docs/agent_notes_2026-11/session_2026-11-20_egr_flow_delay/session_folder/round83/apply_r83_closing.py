"""Round 83 closing: task 046, PR body, session README, todo, memory. Idempotent (each edit skips when its new text is
already there).  usage: apply_r83_closing.py <repo> <pr_body.md> <hash A> <count> <proof A>"""
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


T46 = f"""## Done, round 83 (2026-11-24, same PR): the TPU microcode images; the engine position functions

A peer relay started the round; the scripts are in `session_folder/round83/`. These are round 82's leads.
- **Stage A ({ha}), CM550:**
  - **The microcode:** `tpu_microcode_image` (ROM 0x30C9C) and `tpu_microcode_entry_table` (ROM 0x31328,
    `word[128]`). `mc68k_loadTpuMicrocode` copies them to 0xFFE000-0xFFE68B and to 0xFFE700-0xFFE7FF, the top 256
    bytes of the 2 KB microcode memory (16 functions x 8 entry words).
    - The image array is `dword[342]` and stops at 0x311F4. `mc68k_FUN_0002cc88` reads a signature there
      (0x98765432 / 0x98765433) and a code pointer at 0x31256, a record inside the copied block.
  - **Checking method corrected:** the 'label-only' diffs of rounds 81-82 filtered out every line indented three
    spaces or more, so they compared only the outer lines of each function. `label_only_check.py` strips the
    comments and diffs the full text. It finds 0 differing lines for both rounds, so their claims hold.
  - **The six `pwmTimer*` functions** touch only the TPU. They are the engine position code and are renamed:
    - `mc68k_initializeSpeedMeasurementMode0` / `mc68k_resetSpeedMeasurementMode0`: channel 0, function 0xc;
    - `mc68k_setUpTpuChannel3AnglePulseOutput` / `mc68k_updateTpuChannel3AnglePulseOutput`: function 8, the pulse
      the Cummins names call DZG, placed on the missing-tooth wheel per cylinder;
    - `mc68k_configureTpuChannelsForSpeedMeasurementMode`;
    - `mc68k_alignCylinderIndexToCrankRevolution`.
  - **Proof:** {proof_a}
- **firmware/CM550: none for CLAUDE.md.**
- **Leads:**
  - **Reading the microcode:** its entry table and microinstructions would give each channel's function (0x8 / 0xa /
    0xb / 0xc).
  - **What receives the DZG pulse:** the pump, for example.
  - **The signature record at 0x311F4 / 0x31256:** `mc68k_FUN_0002cc88` jumps through its code pointer when the
    signature matches. A ROM extension?
  - The CS4 message object handlers, and the 182 rows inside the EEPROM write queue's range.

## Leads (not in this PR)"""
T46 = T46.replace("- **firmware/CM550: none for CLAUDE.md.**", "- **firmware/CLAUDE.md:** none.")
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 83.**\n"
     f"- **Stage A ({ha}):** CM550's TPU microcode image and entry table in ROM are typed, and the six TPU-only\n"
     "  `pwmTimer*` functions are renamed for the engine position work they do (speed measurement mode 0 on channel 0,\n"
     "  the angle pulse output on channel 3, the cylinder index alignment).\n"
     "\n## Test plan\n")
edit(pr, "- **Beyond CM848 (rounds 72-82):**", "- **Beyond CM848 (rounds 72-83):**")
edit(pr, "- [x] Round 82:", f"- [x] Round 83: A: {proof_a}\n- [x] Round 82:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 83: the TPU microcode images; the engine position functions (`session_folder/round83/`)\n\n"
       "- **Stage A (CM550):** `apply_r83a.py`, `map_r83a.csv`.\n"
       "- **Closing:** `apply_r83_closing.py`, `update_large_tar_r83.sh`.\n")
if "## Round 83:" not in t:
    i = t.index("## Round 82:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 82: CM550's TPU set-up functions and microcode loader - open: the task 046 leads",
     "round 82: CM550's TPU set-up functions and microcode loader; round 83: the TPU microcode images, the engine "
     "position functions - open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "primary speed / 12 set-ups); task 046 leads"
new = ("primary speed / 12 set-ups) + round 83 (tpu_microcode_image ROM 0x30C9C dword[419] + tpu_microcode_entry_table "
       "0x31328 word[128]; the pwmTimer* functions = engine position: speed measurement mode 0 on channel 0, the angle "
       "(DZG) pulse output on channel 3, the cylinder index alignment); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
print("round 83 closing applied")
