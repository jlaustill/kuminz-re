"""Round 84 stage B closing: task 046, PR body, session README, the memory round log. Idempotent (each edit skips when
its new text is already there).  usage: apply_r84b_closing.py <repo> <pr_body.md> <hash B> <count> <proof B>"""
import os
import re
import sys

repo, pr, hb, count, proof_b_file = os.path.abspath(sys.argv[1]), *sys.argv[2:6]
proof_b = open(proof_b_file).read().strip()


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46_OLD = "- **firmware/CLAUDE.md:** none.\n- **Leads:**\n  - The ROM 0x8000 / 0x8062 application signature"
T46_NEW = f"""- **Stage B ({hb}), CM550, from an advisor review of stage A:**
  - **The image is data:** no real code calls into it (`prefix_rule_check.py`: only other image copies reference the
    nine copies). CM550's first `deleted_functions.csv` lists the nine, so the build removes them after the analysis;
    their rows go. `boot_block_image`'s comment keeps the mapping and the stage A names.
  - `tpu_microcode_image` is `dword[419]` again: the whole 0x68C bytes the loader copies. Round 83's cut at 0x311F4 came
    only from the image copy's PC-relative reads.
  - `mc68k_waitForChipSelect2InputBit0High` (0x395a): the `mc68k_` prefix, because it writes `SIM_SWSR`.
  - **B2:** an old prototype row for the Huffman tree builder sat on its copy's address (0x2C834). It moves to the
    original, `cm550_huffmanTreeBuilder` (0x3640): `tree_buffer`, the base of the 0xC0C-byte node buffer it fills.
  - **Proof:** {proof_b}
- **firmware/CLAUDE.md:** none.
- **Leads:**
  - **The prefix rule:** `prefix_rule_check.py` finds 31 CM550 functions without `mc68k_` that touch MC68336 or chip
    select device registers. Several only service the watchdog inside a loop; some names look wrong
    (`clearModuleSyncFlag` writes `TPU_HSRR0` 16 times).
  - **16-bit stack arguments:** CM550 pushes a word argument as 2 bytes (`move.w #2,-(sp)`, then `jsr (-0x126,pc)` to
    the delay loop). Ghidra's CPU32 prototype puts a word parameter at SP+6, so 72 lines read `in_stack_00000004` and 79
    read `param_N._0_2_`.
  - `cm550_FUN_0001c484` copies `cm550_flashEraseWithWatchdog` into a 2 KB stack buffer and runs it there: the erase
    twin of `cm550_flashProgramFromRam`.
  - The ROM 0x8000 / 0x8062 application signature"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", T46_OLD, T46_NEW)
edit(pr, "  `cm550_updateBootBlockFromImage` are named; the nine image copies are named after their originals.\n",
     "  `cm550_updateBootBlockFromImage` are named; the nine image copies are named after their originals.\n"
     f"- **Stage B ({hb}):** the image is data, so its nine function copies go into CM550's first `deleted_functions.csv`;\n"
     "  `tpu_microcode_image` gets back its whole extent (`dword[419]`); 0x395a takes the `mc68k_` prefix.\n")
edit(pr, "- [x] Round 84: A: ", f"- [x] Round 84: B: {proof_b}\n- [x] Round 84: A: ")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
edit(README, "- **Closing:** `apply_r84_closing.py`, `update_large_tar_r84.sh`,",
     "- **Stage B (CM550):** `prefix_rule_check.py` (functions without `mc68k_` that touch MC68336 registers),\n"
     "  `function_set_check.py` (functions removed / added / changed between two builds), `apply_r84b.py`,\n"
     "  `apply_r84b2.py`, `map_r84b.csv`, `apply_r84b_closing.py`.\n"
     "- **Closing:** `apply_r84_closing.py`, `update_large_tar_r84.sh`,")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m2 = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
assert m2 != m or f"{count} commits" in m, "the commit count pattern is gone from MEMORY.md"
open(M + "MEMORY.md", "w").write(m2)
log = M + "pr53_egr_flow_delay_rounds.md"
t = open(log).read()
old = "(version word ROM 0x16, key 0xbad1 / 0x1d1d); its 9 functions are <original>ImageCopy - PC-relative, so they show 0x8000 as 0x311F4)"
new = ("(version dword ROM 0x16 = 0x02020300 in both, so no reflash; key 0xbad1 / 0x1d1d); stage B: its 9 functions "
       "(PC-relative, so they showed 0x8000 as 0x311F4) = CM550's first deleted_functions.csv rows, tpu_microcode_image "
       "back to dword[419], 0x395a mc68k_; leads: the prefix rule (31 functions), 16-bit stack arguments)")
if new not in t:
    assert t.count(old) == 1, t.count(old)
    t = t.replace(old, new)
t = re.sub(r"is still OPEN on 2026-11-24\n\(\d+ commits\)", f"is still OPEN on 2026-11-24\n({count} commits)", t)
open(log, "w").write(t)
print("round 84 stage B closing applied")
