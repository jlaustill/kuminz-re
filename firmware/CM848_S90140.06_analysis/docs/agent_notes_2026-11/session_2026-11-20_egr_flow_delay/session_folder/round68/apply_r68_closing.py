"""Round 68 closing: task 046, PR body, README, todo, memory. Idempotent (each edit skips when its new text is
already there).  usage: apply_r68_closing.py <repo> <pr_body.md> <hash A> <count> <proof text file>"""
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


T46 = f"""## Done, round 68 (2026-11-23, same PR): the application's EEPROM mirror words at 0x3fee18, typed from e2m

A peer relay started the round; the scripts are in `session_folder/round68/`.
- **Stage A ({ha}):** round 67's first lead.
  - The boot kernel's `eeprom_header_t` ran to 0x3fee29 over the application's EEPROM mirror, so 13 application
    functions rendered their words as `eeprom_shadow_header.calibration_block1[N]` / `cal_word2` / ... It now ends at
    0x3fee17.
  - Three structs from e2m, with the widths from the asm (lbz / lhz / sth):
    - `fuel_level_saved_values_t` (8A24, 4 bytes; e2m's own filler byte says the source has a struct);
    - `intake_air_heater_saved_values_t` (8A36). The end-of-line step's one `sth` of 0x19 had rendered as two byte
      stores;
    - `engine_off_time_saved_values_t` (8C36 Chry_Dat42), the PCI engine-off time check.
  - The boot kernel's copies of EEPROM 0x4a-0x4f / 0x50-0x54 time-share these words. Three boot plates say so, and
    `cm848_lookupEepromParameterAddress` (it returns those bytes by parameter number) gets a `byte *` prototype: the
    struct start at 0x3fee1c had made Ghidra type its return as the struct pointer, and its caller loses a cast. Its
    local still shows as that struct's pointer: a `byte *` local row split the variable in two, so the row was
    dropped (`fix_r68a3.py` / `fix_r68a4.py`).
  - `boot_serial_reflash_unlock_request` / `boot_eeprom_status_block` (0x3fee24 / 0x3fee26). The old
    `serial_number` was EEPROM 0x0c; the serial number is EEPROM 0x8e.
- **Proof:** {proof}
- **firmware/CLAUDE.md:** line 146, a factual rename from the reference refresh (the boot copy of EEPROM 0x56 is
  `boot_serial_reflash_unlock_request`).
- **Leads:**
  - `cm848_latchAndCheckEngineOffTime` sets its fault with `fault_detected_cal._38_2_ | 0x10`. The bit has a field
    (word 19 bit 4 `engine_off_time_stuck_error`; e2m 1036 Chry_Dat42_Stuck_Error "Last ignition off time message
    stuck", which also confirms Chry_Dat42 is PCI frame 0x42's ignition-off time). Ghidra just does not map this
    word-wide read-modify-write onto the bitfield.
  - 0x3fee38 is the boot kernel's word buffer for `cm848_lookupEepromParameterAddress`, inside the application's
    `oil_change_monitor_fuel_hundredth_gallons_cal` dword; it stays unnamed.
  - Round 67's other leads stand: the image header at ROM 0x8100, a memory region type enum, 0x3fedee / 0x3fedf4,
    `DAT_01000000`, the boot `eeprom_*` vocabulary and the serial response codes.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 68.**\n"
     f"- **Stage A ({ha}):** the application's EEPROM mirror words at 0x3fee18 typed from e2m: the fuel level (8A24),\n"
     "  intake air heater (8A36) and engine-off time (8C36) blocks as structs. The boot kernel's header struct no longer\n"
     "  runs over them, and its time-shared uses are noted.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 67:", f"- [x] Round 68: {proof}\n- [x] Round 67:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 68: the application's EEPROM mirror words at 0x3fee18 (`session_folder/round68/`)\n\n"
       "- **Stage A:** `apply_r68a.py`, then `fix_r68a2.py` (the lookup's prototype), `fix_r68a3.py` (a typed local)\n"
       "  and `fix_r68a4.py` (which undoes it), `map_r68a.csv`. **Proof:**\n"
       "  `prove_r68.py` (exact string renames: the old labels end in `]`), `diff_r68.py`. **Closing:**\n"
       "  `apply_r68_closing.py`, `update_large_tar_r68.sh`.\n")
if "## Round 68:" not in t:
    i = t.index("## Round 67:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md",
     "round 67: the boot kernel's reflash state machine (ECM_STATUS) - open: the task 046 leads",
     "round 67: the boot kernel's reflash state machine (ECM_STATUS); round 68: the application's EEPROM mirror words "
     "at 0x3fee18 from e2m - open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "crc_ccitt_table; time-shared header fields = lead); task 046 leads"
new = ("crc_ccitt_table; time-shared header fields = lead) + round 68 (0x3fee18-0x3fee23 = the application's e2m "
       "8A24 / 8A36 / 8C36 structs; the boot header struct ends at 0x3fee17); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
print("round 68 closing applied")
