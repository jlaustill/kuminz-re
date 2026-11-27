"""Round 81 closing: task 046, PR body, session README, todo, memory. Idempotent (each edit skips when its new text is
already there).  usage: apply_r81_closing.py <repo> <pr_body.md> <hash A> <count> <proof A>"""
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


T46 = f"""## Done, round 81 (2026-11-24, same PR): CM550 functions renamed for the hardware they drive

A peer relay started the round; the scripts are in `session_folder/round81/`.
- **The check:** `hardware_name_check.py` compares each CM550 function's name with the register modules it touches,
  using the register names from rounds 75-80. It finds 16 functions whose names claim hardware they do not touch.
- **Stage A ({ha}), CM550:** the four clearest are renamed.
  - `mc68k_checkSerialEepromSignature` (was `mc68k_tpuAndQadcVerification`): reads EEPROM word 0 over the QSPI and
    checks it is 0x600d.
  - `mc68k_runSerialEepromWriteQueue` (was `mc68k_qadcDataCollectionStateMachine`): SPI EEPROM commands 5 / 6 / 2 / 3.
  - `mc68k_canCs4TransmitNextFrame` (was `serialTransmitHandler`).
  - `mc68k_canCs4InterruptHandler` (was `cm550_FUN_0001e0fa`).
  - **Correction to round 80:** the "EEPROM log" is a serial EEPROM write queue. Each entry is an EEPROM address word
    (0x80BDA8 + 2 i) and a data byte (0x80C7A8 + i). The queue rows' comments now say so.
  - **Proof:** {proof_a}
- **firmware/CLAUDE.md:** none.
- **Leads:**
  - The six `can1*` functions that touch only the TPU (`mc68k_can1TimerBufferInitDivided`, `mc68k_can1ControllerInit`,
    ...) need their TPU channels and functions read before they can be renamed. So do the `pwmTimerMode*` functions:
    they touch only the TPU, which can itself generate PWM, so those names may stand.
  - `cm550_serialNodeAddressForwarder` / `cm550_serialNodeAddressChecker` are the CS4 message object handlers. One
    compares with `_can_first_receive_object_index`, and its prototype renders an `in_stack` byte.
  - The 182 rows inside the EEPROM write queue's range, and the earlier leads.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 81.**\n"
     f"- **Stage A ({ha}):** four CM550 functions renamed for the hardware they drive (the serial EEPROM driver over the\n"
     "  QSPI and the chip select 4 CAN controller); round 80's EEPROM \"log\" is a write queue (address word + data byte).\n"
     "\n## Test plan\n")
edit(pr, "- **Beyond CM848 (rounds 72-80):**", "- **Beyond CM848 (rounds 72-81):**")
edit(pr, "- [x] Round 80:", f"- [x] Round 81: A: {proof_a}\n- [x] Round 80:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 81: CM550 functions renamed for the hardware they drive (`session_folder/round81/`)\n\n"
       "- **Stage A (CM550):** `hardware_name_check.py` (each function's name against the register modules it touches),\n"
       "  `apply_r81a.py`, `map_r81a.csv`.\n"
       "- **Closing:** `apply_r81_closing.py`, `update_large_tar_r81.sh`.\n")
if "## Round 81:" not in t:
    i = t.index("## Round 80:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 80: the chip select 2 watchdog register, the EEPROM log's indexes - open: the task 046 leads",
     "round 80: the chip select 2 watchdog register, the EEPROM log's indexes; round 81: CM550 functions renamed for the "
     "hardware they drive - open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "0x40000 before removing); task 046 leads"
new = ("0x40000 before removing) + round 81 (r81/hardware_name_check.py: 16 CM550 functions name hardware they don't "
       "touch; renamed the serial EEPROM driver mc68k_checkSerialEepromSignature / mc68k_runSerialEepromWriteQueue - the "
       "'log' is an EEPROM write queue (address word + data byte) - and mc68k_canCs4TransmitNextFrame / "
       "mc68k_canCs4InterruptHandler; the can1* TPU-only functions are leads); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
print("round 81 closing applied")
