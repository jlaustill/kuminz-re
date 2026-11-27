"""Round 71 closing: task 046, PR body, README, todo, memory. Idempotent (each edit skips when its new text is
already there).  usage: apply_r71_closing.py <repo> <pr_body.md> <hash A> <hash B> <count> <proof text file>"""
import os
import re
import sys

repo, pr, ha, hb, count, proof_file = os.path.abspath(sys.argv[1]), *sys.argv[2:7]
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


T46 = f"""## Done, round 71 (2026-11-23, same PR): MEMORY_REGION_TYPE - both kernels' memory region maps

A peer relay started the round; the scripts are in `session_folder/round71/`.
- **Stage A ({ha}):** round 67's region-type lead.
  - **The codes:** both write-permission maps decode to the same codes, and both kernels' readers and writers branch
    on them the same way: 0 RAM / 2 Bank 2 flash / 3 AUTHORIZATION_REQUIRED / 4 main flash / 5 EEPROM / 9 UNMAPPED /
    10 REFUSED. Codes 9 and 10 go straight back as the service result, so their words come from
    `J1939_DIAGNOSTIC_RESULT`.
  - **The second type byte:** `memory_region_t`'s second byte is the application's type while development mode is
    OFF (`development_mode_off_region_type`). The old name, `region_type_copy`, described only the boot table.
  - **First match wins:** the boot table's type 3 entry is effectively 0x2fc000-0x301fff, and the application map
    leaves out the dual-port TPU RAM, which comes back UNMAPPED.
  - **New and renamed names:** `application_memory_region_table` (7 entries at 0x53a33a), `boot_memory_region_table`,
    and `serial_download_region_type` (0x3fee05, was `sensor_fault_threshold_state`). Both lookups get prototypes,
    and the two writers that pass a region code back get explicit byte / char returns.
- **Proof:** {proof} 8755bedb's message says "28 placeholders fewer and 8 casts more"; the net figures above are the
  right ones.
- **Also seen:** the application writer also refuses (10) type 3 writes into 0x3fd481 up to `sensor_channel_ram_start`
  (0x40a046: the EEPROM mirror and the ROM-copied constants behind it) while RAM refresh is on. Typing the
  application table removed a `DAT_0006ffff` label from `mpc555_cmfEraseBlocks`: the pointer row at 0x53a33e (entry
  0's end address, 0x6ffff) had created it.
- **Follow-up ({hb}), from the closing review:**
  - The lookups' parameters are `range_start` / `range_length`. Named `address` / `length`, they collided with their
    callers' own and left 20 `length_00` / `address_00` temps.
  - `MEMORY_REGION_TYPE_BANK_2_FLASH`'s comment notes that the application writer's pass-back reaches the tool as
    `J1939_DIAGNOSTIC_RESULT` 0x02 `WRONG_LENGTH`.
  - The junk row at 0x3fee03 (`j1939_cruise_state_t_003fee00.cruise_state_pad_03`: no such struct) is gone. It was an
    EEPROM mirror name without `_cal`, so `audit_cal_suffixes.py` MISSING goes 211 -> 210.
  - **Proof:** 5 of 1968 functions differ (the callers whose temps lost `_00`); casts and placeholders are
    unchanged; verify is byte-identical with stage A's warnings.
- **firmware/CLAUDE.md:** line 108, the reference refresh's factual rename (`memory_region_table` ->
  `boot_memory_region_table`).
- **Leads:**
  - The boot read reply table at 0x7f60 is `boot_kernel_rom_end`'s own address (its comment documents it). Typing it
    would make the image's end bound read as the table.
  - The serial download handlers use unnamed `DAT_003fee06` / `ram0x003fee01` / `ram0x003fedfd`.
  - CM550's `cm550_memoryOperationDispatcher` (0x2148a) is the application J1939 writer's twin, path for path: it
    switches on the same codes from `cm550_addressRangeValidator` (0 copy / 3 and 5 after the security check / 4 ->
    10 / the others back as the result), and its security check calls `sensorRangeValidation`, the twin of
    `cm848_processSecurityCodeConversion` - so MEMORY_REGION_TYPE and the twins' names can carry over to CM550.
  - Round 70's SRAM clear bound and the older leads stand.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 71.**\n"
     f"- **Stage A ({ha}):** `MEMORY_REGION_TYPE` types both kernels' memory region maps (the codes the write paths\n"
     "  branch on; 9 / 10 double as results). `application_memory_region_table` is typed,\n"
     "  `region_type_copy` -> `development_mode_off_region_type`, and `sensor_fault_threshold_state` ->\n"
     "  `serial_download_region_type`.\n"
     f"- **Follow-up ({hb}):** the lookups' parameters renamed so their callers lose 20 `length_00` / `address_00`\n"
     "  temps; a junk row removed.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 70:", f"- [x] Round 71: {proof} Follow-up (88e54bbb): 5 functions differ (the callers' temps), casts and placeholders unchanged, MISSING 210.\n- [x] Round 70:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 71: MEMORY_REGION_TYPE (`session_folder/round71/`)\n\n"
       "- **Stage A:** `apply_r71a.py`, `map_r71a.csv`. **Proof:** `prove_r71.py`, `diff_r71.py`. **Closing:**\n"
       "  `apply_r71_closing.py`, `fix_r71_closing_text.py`, `fix_r71_closing_text2.py`, `update_large_tar_r71.sh`. **Follow-up:** `fix_r71b.py`. **Commit\n  messages:** `commit_r71a.txt`, `commit_r71b.txt`, `commit_r71_closing.txt`.\n")
if "## Round 71:" not in t:
    i = t.index("## Round 70:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md",
     "round 70: the dual-port TPU RAM, the boot CAN rings - open: the task 046 leads",
     "round 70: the dual-port TPU RAM, the boot CAN rings; round 71: MEMORY_REGION_TYPE - open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "the TPU RAM load table 0x5862e); task 046 leads"
new = ("the TPU RAM load table 0x5862e) + round 71 (MEMORY_REGION_TYPE on both kernels' region maps; "
       "application_memory_region_table; 9 / 10 double as results); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
print("round 71 closing applied")
