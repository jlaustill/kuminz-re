"""Round 79 closing: task 046, PR body, session README, todo, memory. Idempotent (each edit skips when its new text is
already there).  usage: apply_r79_closing.py <repo> <pr_body.md> <hash A> <count> <proof A>"""
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


T46 = f"""## Done, round 79 (2026-11-23, same PR): CM550's two 82527 CAN controllers

A peer relay started the round; the scripts are in `session_folder/round79/`. This is round 76's external device
lead.
- **Stage A ({ha}), CM550:** the devices on chip selects 5 (0xFFC800) and 4 (0xFFD800) are two Intel 82527 CAN
  controllers.
  - `SIM_CSBAR5 = 0xffc8` and `SIM_CSBAR4 = 0xffd8` share the option word 0x5bf0.
  - Every offset the code touches is in the 82527 address map (Intel's 82527 Architectural Overview, section 4.1:
    https://star.inp.nsk.su/~kozak/canbus/82527ao.pdf), and the code uses them as one:
    - the interrupt handler loops on the 5FH interrupt register and reaches message object n - 2 at
      interrupt * 0x10 + base - 0x20;
    - the control pairs are written as bit pairs (0x9955 / 0x5559).
  - **The names:** 45 rows, `CAN_CS5_*` / `CAN_CS4_*`.
    - The CS5 controller's message objects 1-6 are named (control word, arbitration word, configuration byte).
    - The CS4 controller's message objects are reached by index from a base, so they are left for a struct.
  - **`ApplyHardwareRegisters.java`:** the register block now starts at 0xFFC800. Because it is volatile, the
    decompiler stopped folding CS5 register accesses as if they were memory. Before, it read CPU interface bit 7 back
    as the RAM byte written there, and three functions now render the real accesses.
  - **Renamed:** `mc68k_configureCanCs5MessageObjects` (was `mc68k_tpuTimerInitializer`). It configures receive
    identifiers 0x112 / 0x512 / 0x712 and transmit 0x100 / 0x500 / 0x700, all 11-bit. `mc68k_canCs5InterruptHandler`
    (was `mc68k_serialPort2IsrHandler`).
  - **Proof:** {proof_a}
- **firmware/CLAUDE.md:** none.
- **Leads:**
  - **Which bus each controller carries:** CS5 uses 11-bit identifiers 0x100-0x712, which J1939's 29-bit identifiers
    rule out, so perhaps the VP44 pump link. CS4 sets an extended mask, so perhaps J1939.
  - **A 16-byte 82527 message object struct** for CS4's indexed accesses (`&DAT_00ffd810 + index * 0x10`,
    `(&DAT_00ffd806)[i]`).
  - The device on chip select 2 (0xFFD000-0xFFD00F; 0xFFD00F has 128 references next to the watchdog service).
  - From the earlier rounds: the `io_control_*` names, the diagnostic receive buffer past 0x808D00,
    `j1708_pending_abort_count`, and the parameter buffer at 0x80C7A8.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 79.**\n"
     f"- **Stage A ({ha}):** CM550's two external Intel 82527 CAN controllers (chip selects 5 / 4) are named from the\n"
     "  82527 register map; the register block now covers chip select 5, and the CS5 controller's two functions are\n"
     "  named for what they drive.\n"
     "\n## Test plan\n")
edit(pr, "- **Beyond CM848 (rounds 72-78):**", "- **Beyond CM848 (rounds 72-79):**")
edit(pr, "- [x] Round 78:", f"- [x] Round 79: A: {proof_a}\n- [x] Round 78:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 79: CM550's two 82527 CAN controllers (`session_folder/round79/`)\n\n"
       "- **Stage A (CM550):** `apply_r79a.py` (the 45 register rows), `apply_r79a3.py` (the two CS5 functions),\n"
       "  `map_r79a3.csv`. The register map comes from Intel's 82527 Architectural Overview; the document itself is not\n"
       "  archived here.\n"
       "- **Proof:** `prove_r79a_cm550.py`. **Closing:** `apply_r79_closing.py`, `update_large_tar_r79.sh`.\n")
if "## Round 79:" not in t:
    i = t.index("## Round 78:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 78: the last CM550 multi-address structs - open: the task 046 leads",
     "round 78: the last CM550 multi-address structs; round 79: CM550's two 82527 CAN controllers - open: the task 046 "
     "leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "diagnostic receive buffer past 0x808D00); task 046 leads"
new = ("diagnostic receive buffer past 0x808D00) + round 79 (CM550's chip selects 5 / 4 = two Intel 82527 CAN controllers "
       "at 0xFFC800 / 0xFFD800, CAN_CS5_* / CAN_CS4_* from the 82527 address map; the hwregs block now starts at "
       "0xFFC800 - volatile, so the old memory-style folding of those accesses is gone; "
       "mc68k_configureCanCs5MessageObjects / mc68k_canCs5InterruptHandler); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
print("round 79 closing applied")
