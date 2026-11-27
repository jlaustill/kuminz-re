"""Round 84 closing: task 046, PR body, session README, todo, memory. Idempotent (each edit skips when its new text is
already there).  usage: apply_r84_closing.py <repo> <pr_body.md> <hash A> <count> <proof A>"""
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


T46 = f"""## Done, round 84 (2026-11-24, same PR): CM550's boot block image and its updater

A peer relay started the round; the scripts are in `session_folder/round84/`.
- **The check:** `placeholder_hardware_functions.py` lists the CM550 functions that still have placeholder names but
  drive named hardware (29). Its clearest cluster was a second copy of the start-up code.
- **Stage A ({ha}), CM550:**
  - **The image:** ROM 0x291F4-0x2CE63 is byte-for-byte ROM 0x0-0x3C6F, the boot block image (`boot_block_image`).
  - **The updater:** `cm550_updateBootBlockFromImage` (was `cm550_FUN_0002ce64`, right after the image) programs the
    image into flash at address 0. It does so when `boot_block_version` (ROM 0x16) is non-zero and the key is 0xbad1
    with an older version, or 0x1d1d with a different one (`boot_block_image_version` at 0x2920A). Both versions are
    dwords, 0x02020300 in this dump, so the updater leaves the boot block alone.
  - **The copies:** the nine functions Ghidra found inside the image are copies of the boot block's and are named
    `<original>ImageCopy`. Their PC-relative references show the original's 0x8000 / 0x8062 / 0x80339E as 0x311F4 /
    0x31256 / 0x82C592.
  - **Correction to round 83:** the "signature record" at 0x311F4 / 0x31256 is only the image copy's view of ROM
    0x8000 / 0x8062. That is where the boot block's start-up looks for the application's signature (0x98765432 /
    0x98765433) and entry pointer.
  - `cm550_waitForChipSelect2InputBit0High` (was `cm550_FUN_0000395a`) waits for 5 consecutive 1 samples of bit 0
    at 0xFFD000, the same pattern as CM848's `cm848_waitForStableIgnitionKeyOn`. The signal is not identified.
  - **Proof:** {proof_a}
- **firmware/CLAUDE.md:** none.
- **Leads:**
  - The ROM 0x8000 / 0x8062 application signature and entry pointer, and the RAM program at 0x80339E (decompressed by
    `cm550_huffmanDecompressMain`: the service program?).
  - What 0xFFD000 bit 0 is (the key line?).
  - The other placeholder-named hardware functions (the speed sensor handlers `vp44_FUN_00019e90` / `_0001a52c` /
    `_0001a8a4`, `mc68k_FUN_00015df0` ...).

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 84.**\n"
     f"- **Stage A ({ha}):** CM550's boot block image (ROM 0x291F4, a byte-for-byte copy of the boot block) and its updater\n"
     "  `cm550_updateBootBlockFromImage` are named; the nine image copies are named after their originals.\n"
     "\n## Test plan\n")
edit(pr, "- **Beyond CM848 (rounds 72-83):**", "- **Beyond CM848 (rounds 72-84):**")
edit(pr, "- [x] Round 83:", f"- [x] Round 84: A: {proof_a}\n- [x] Round 83:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 84: CM550's boot block image and its updater (`session_folder/round84/`)\n\n"
       "- **Stage A (CM550):** `placeholder_hardware_functions.py` (the placeholder-named functions that drive hardware),\n"
       "  `apply_r84a.py`, `map_r84a.csv`.\n"
       "- **Closing:** `apply_r84_closing.py`, `update_large_tar_r84.sh`, `fix_pr_body_round_headings_r84.py` (the PR\n  body's round 24-84 headings had no blank line above them, so GitHub showed each inside the bullet above it).\n")
if "## Round 84:" not in t:
    i = t.index("## Round 83:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 83: the TPU microcode images, the engine position functions - open: the task 046 leads",
     "round 83: the TPU microcode images, the engine position functions; round 84: CM550's boot block image and its "
     "updater - open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "the cylinder index alignment); task 046 leads"
new = ("the cylinder index alignment) + round 84 (CM550 ROM 0x291F4-0x2CE63 = byte copy of boot block 0x0-0x3C6F = "
       "boot_block_image, reflashed by cm550_updateBootBlockFromImage (version word ROM 0x16, key 0xbad1 / 0x1d1d); its "
       "9 functions are <original>ImageCopy - PC-relative, so they show 0x8000 as 0x311F4); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
print("round 84 closing applied")
