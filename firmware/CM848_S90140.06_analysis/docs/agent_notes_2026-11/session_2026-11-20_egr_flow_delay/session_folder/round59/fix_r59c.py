"""Round 59 follow-up (the advisor's closing checks; docs, the archive note and memory only). Idempotent.
usage: fix_r59c.py <repo> <session archive dir>
- "Superseded: a live type has the layout" held for two of the four: ad_sensor_config_t (16 bytes) = sensor_channel_
  config_t (16) and address_range_entry_t (10) = memory_region_t (10). sensor_fault_config_t (24 bytes) and
  sensor_debounce_state_t (22) only cover the role of sensor_channel_config_t / sensor_channel_state_t (16 / 12), and
  were marked "Documentation only - do NOT apply". The deletions stand (orphans); the wording changes.
- Origins traced: 24 of the 29 came with fdc657a (the 2026-01-30 CM550 port); 5 (parameter_response_t,
  calterm_protocol_t, insite_protocol_t, dma_descriptor_t, memory_patch_entry_t) were there before.
- j1939_ack_msg_t is unused too: only an enums.csv comment names it; j1939_acknowledgement_payload_t covers its role.
- The booster counter's "exactly 2 stores" is now checked in the disassembly too (sth 0(r6) at 0x5290dc / 0x529140,
  r6 = &0x3fd0b8 until 0x529194)."""
import os
import sys

repo, archive_dir = os.path.abspath(sys.argv[1]), sys.argv[2]


def edit(path, old, new):
    s = open(path).read()
    if new in s:
        return
    assert s.count(old) == 1, (path, old[:70], s.count(old))
    open(path, "w").write(s.replace(old, new))


T = os.path.join(repo, "work/tasks/046-cm848-egr-flow-estimate.md")
edit(T, "  dependency, CSV, `.cpp` render, script, test, CLAUDE.md or skill. 32 of the 192 qualified, most from the\n"
        "  2026-01-30 port of 26 generic CM550 structures.",
     "  dependency, CSV, `.cpp` render, script, test, CLAUDE.md or skill. 32 of the 192 qualified. 24 of the 29 removed\n"
     "  came with the 2026-01-30 port of 26 generic CM550 structures (fdc657a); the 5 protocol / DMA / patch types were\n"
     "  there before.")
edit(T, "  - **Superseded (deleted):** `ad_sensor_config_t` / `sensor_fault_config_t` (now `sensor_channel_config_t`),\n"
        "    `sensor_debounce_state_t` (`sensor_channel_state_t`) and `address_range_entry_t` (`memory_region_t`).",
     "  - **Covered by a live type (deleted):** `ad_sensor_config_t` (16 bytes) and `address_range_entry_t` (10) have\n"
     "    the same size as `sensor_channel_config_t` / `memory_region_t`. `sensor_fault_config_t` (24) and\n"
     "    `sensor_debounce_state_t` (22) only cover the role of `sensor_channel_config_t` / `sensor_channel_state_t`\n"
     "    (16 / 12) and were marked \"documentation only\". The stage A commit message calls all four \"superseded\".")
edit(T, "  - CM550 keeps unused copies of 18 of the removed types.",
     "  - CM550 keeps unused copies of 18 of the removed types.\n"
     "  - `j1939_ack_msg_t` is unused as well (only an `enums.csv` comment names it); `j1939_acknowledgement_payload_t`\n"
     "    covers its role.")
edit(T, "  forgotten at each call), and the seven rows, task 046 and the memory note now say that.",
     "  forgotten at each call), and the seven rows, task 046 and the memory note now say that. Both words' 2 stores were\n"
     "  checked in the disassembly (0x52deac / 0x52df64 and 0x5290dc / 0x529140).")
P = "/home/linux/.claude/jobs/374b0424/tmp/egr/pr_body.md"
edit(P, "29 CM848 struct types that nothing uses are removed: 4 superseded by live types and 25\n"
        "  with no CM848 home",
     "29 CM848 struct types that nothing uses are removed: 4 whose role a live type covers (2\n"
     "  with the same layout) and 25 with no CM848 home")
for d in (archive_dir, "/home/linux/.claude/jobs/374b0424/tmp/w15/r59"):
    f = os.path.join(d, "removed_orphan_types.txt")
    s = open(f).read()
    note = ("Correction (round 59 follow-up): of the four SUPERSEDED types, ad_sensor_config_t (16 bytes) and "
            "address_range_entry_t (10) match their live types' sizes; sensor_fault_config_t (24) and "
            "sensor_debounce_state_t (22) only cover the role of sensor_channel_config_t / sensor_channel_state_t "
            "(16 / 12). 24 of the 29 came with fdc657a; the 5 protocol / DMA / patch types were there before.\n\n")
    if not s.startswith("Correction"):
        open(f, "w").write(note + s)
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/MEMORY.md"
mm = open(M).read()
open(M, "w").write(mm.replace("(cm848/egr-flow-delay-model, 258 commits)", "(cm848/egr-flow-delay-model, 259 commits)"))
print("round 59 follow-up applied")
