"""Round 66 closing: task 046, PR body, README, todo, memory. Idempotent (each edit skips when its new text is
already there).  usage: apply_r66_closing.py <repo> <pr_body.md> <hash A> <count> <proof text file>"""
import os
import re
import sys

repo, pr, ha, count, proof_file = os.path.abspath(sys.argv[1]), *sys.argv[2:6]
proof = open(proof_file).read().strip()


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = f"""## Done, round 66 (2026-11-23, same PR): the boot kernel's result codes, the coolant friction torque term

A peer relay started the round; the scripts are in `session_folder/round66/`.
- **Stage A ({ha}):**
  - `BOOT_DIAGNOSTIC_RESULT` (size 4), the boot kernel's twin of `J1939_DIAGNOSTIC_RESULT`, with 11 codes named
    from their producers. Its own codes are 5 (unknown service; the application uses 0x18), 0x11 (a flash write
    failed) and 0x17 (the EEPROM transfer did not start). 0xff is no member.
  - It types the boot validator's return (whose full prototype also takes `j1939_rx_msg_t *request`) and the boot
    dispatcher's `result_code`. The dispatcher locals were keyed on positional names (`BVar4`) from round 64's
    lesson, and they applied on the first build.
  - `net_combustion_torque_coolant_friction_term` (was `DAT_003fba10`, round 62's lead), with its scale renamed
    `net_combustion_torque_coolant_friction_scale`.
- **Proof:** {proof}
- **firmware/CLAUDE.md:** no edit. HARD stays 0 and MISSING 219.
- **Leads:**
  - **The 30 unprefixed names shared with CM550** are cross-firmware twins by design. Only a few are vague
    (`emptyStubFunction2`-`4`, empty functions called from code - compiled-out hooks), and renaming them needs
    their CM550 call sites read too.
  - `initGovernorFlagsAux` / the word at 0x3fcfba.
  - CM550's unreviewed members, the three length tables, and 0x14 / 0xfe with no CM848 producer.
  - `cm848_handleBootExecuteAtAddressService` now shows `& 0xff` masks from the inferred enum return. Its own
    prototype could return `char` if that reads better.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 66.**\n"
     f"- **Stage A ({ha}):** `BOOT_DIAGNOSTIC_RESULT`, the boot kernel's result codes (11, including its own 5 / 0x11 /\n"
     "  0x17), types the boot validator and dispatcher. The coolant friction torque term is named (round 62's lead).\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 65:", f"- [x] Round 66: {proof}\n- [x] Round 65:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 66: the boot kernel's result codes, the coolant friction torque term (`session_folder/round66/`)\n\n"
       "- **Stage A:** `apply_r66a.py`, `map_r66a.csv`, `shared_unprefixed.py`. **Proof:** `prove_r66.sh`. "
       "**Closing:** `apply_r66_closing.py`, `update_large_tar_r66.sh`.\n")
if "## Round 66:" not in t:
    i = t.index("## Round 65:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md",
     "round 65: 37 unprefixed CM848-only functions named and the J1939 receive table typed - open: the task 046 leads",
     "round 65: 37 unprefixed CM848-only functions named and the J1939 receive table typed; round 66: "
     "BOOT_DIAGNOSTIC_RESULT and the coolant friction torque term - open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "the J1939 receive table + its 16 handlers typed); task 046 leads"
new = ("the J1939 receive table + its 16 handlers typed) + round 66 (BOOT_DIAGNOSTIC_RESULT, the coolant friction "
       "torque term); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
print("round 66 closing applied")
