"""Round 80 closing: task 046, PR body, session README, todo, memory. Idempotent (each edit skips when its new text is
already there).  usage: apply_r80_closing.py <repo> <pr_body.md> <hash A> <count> <proof A>"""
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


T46 = f"""## Done, round 80 (2026-11-24, same PR): the chip select 2 watchdog register; the EEPROM log's indexes

A peer relay started the round; the scripts are in `session_folder/round80/`. These are round 79's leads.
- **Stage A ({ha}), CM550:**
  - `CS2_WATCHDOG_SERVICE` (0xFFD00F): every watchdog service writes 0x55 / 0xaa there right after `SIM_SWSR`.
    Chip select 2's device is an output driver (the warning lamp driver enable and the commanded driver state go to
    0xFFD004 / 0xFFD006). The part is not identified.
  - **The EEPROM log:** a word array at 0x80BDA8 and a byte array at 0x80C7A8, indexed modulo 0x500. The QSPI path
    sends its entries through `QSM_TR4` / `QSM_TR5`. The read index (`eeprom_circular_buffer_read_index`, new), the
    write index and the pending count are words.
  - **The two 82527s' bit timing** (in the RAM dump) is identical, XTAL / 64 = 250 kbit/s with a 16 MHz crystal. The
    rows' comments record it.
  - **Proof:** {proof_a}
- **firmware/CLAUDE.md:** none.
- **Leads:**
  - **182 rows inside the EEPROM log (0x80BDA8-0x80CCA7):** none renders, and none has an absolute access in the
    dumped ROM, so they are probably old misnames of log contents. Check them against the code above 0x40000 (not in
    the 256 KB dump) before removing them, and then type the two arrays (word[1280] / byte[1280]).
  - Chip select 2's other registers (0xFFD000-0xFFD00E) need the part: they take lamp and driver commands.
  - Which bus each 82527 carries: CS5 uses 11-bit identifiers, so it is not J1939.
  - From the earlier rounds: the `io_control_*` names, the diagnostic receive buffer past 0x808D00, and
    `j1708_pending_abort_count`.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 80.**\n"
     f"- **Stage A ({ha}):** CM550's chip select 2 device has its own watchdog service register (written right after\n"
     "  `SIM_SWSR` every time); the EEPROM log's read / write indexes and count are typed; the 82527s' bit timing is\n"
     "  recorded.\n"
     "\n## Test plan\n")
edit(pr, "- **Beyond CM848 (rounds 72-79):**", "- **Beyond CM848 (rounds 72-80):**")
edit(pr, "- [x] Round 79:", f"- [x] Round 80: A: {proof_a}\n- [x] Round 79:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 80: the chip select 2 watchdog register; the EEPROM log's indexes (`session_folder/round80/`)\n\n"
       "- **Stage A (CM550):** `apply_r80a.py`; `inside_addresses.txt` (the 182 rows inside the log range, each scanned\n"
       "  for absolute accesses).\n"
       "- **Closing:** `apply_r80_closing.py`, `update_large_tar_r80.sh`.\n")
if "## Round 80:" not in t:
    i = t.index("## Round 79:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 79: CM550's two 82527 CAN controllers - open: the task 046 leads",
     "round 79: CM550's two 82527 CAN controllers; round 80: the chip select 2 watchdog register, the EEPROM log's "
     "indexes - open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "mc68k_configureCanCs5MessageObjects / mc68k_canCs5InterruptHandler); task 046 leads"
new = ("mc68k_configureCanCs5MessageObjects / mc68k_canCs5InterruptHandler) + round 80 (CS2_WATCHDOG_SERVICE 0xFFD00F - "
       "written 0x55/0xaa after every SIM_SWSR service; the EEPROM log = word[1280] at 0x80BDA8 + byte[1280] at "
       "0x80C7A8, its indexes typed; lead: 182 rows inside it with no access in the dumped ROM - check vs the code above "
       "0x40000 before removing); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
print("round 80 closing applied")
