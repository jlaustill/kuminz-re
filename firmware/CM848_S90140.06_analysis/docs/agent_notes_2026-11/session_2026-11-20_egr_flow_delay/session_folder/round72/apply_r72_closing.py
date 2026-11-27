"""Round 72 closing: task 046, PR body, session README, todo, memory, and the firmware/CLAUDE.md line 108 factual
correction (from round 71's own verified work, disclosed in the round report). Idempotent (each edit skips when its new
text is already there).  usage: apply_r72_closing.py <repo> <pr_body.md> <hash A> <hash B1> <hash B2> <count> <proof A> <proof B1> <proof B2>"""
import os
import re
import sys

repo, pr, ha, hb, hb2, count, proof_a_file, proof_b_file, proof_b2_file = os.path.abspath(sys.argv[1]), *sys.argv[2:10]
proof_a = open(proof_a_file).read().strip()
proof_b = open(proof_b_file).read().strip()
proof_b2 = open(proof_b2_file).read().strip()


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = f"""## Done, round 72 (2026-11-23, same PR): the J1939 memory write service is shared code - CM550 twins

A peer relay started the round; the scripts are in `session_folder/round72/`. Round 71's CM550 lead: CM550's
`cm550_memoryOperationDispatcher` turned out to be CM848's application J1939 writer, path for path, and so did its
lookup, its two service handlers, its header-length getter and its security key check. Twins share one unprefixed
name (the stage 9b rule).
- **Gate:** an unchanged CM550 build reproduced the committed `.cpp`; only the Generated line differed.
- **Stage A ({ha}):** `lookupApplicationMemoryRegionType` (CM848 0x50d784 / CM550 0x3460e, was
  `cm550_addressRangeValidator`).
  - **CM550's codes:** CM550 already modeled the region codes as `MEMORY_ACCESS_FLAG`; the shared
    `MEMORY_REGION_TYPE` takes its place, with the old member names kept in the comments.
  - **The table:** `memory_region_t` is a type-only template, and `application_memory_region_table` is a
    `memory_region_t[5]` at ROM 0x345dc. It holds CM848's codes; there is no Bank 2.
  - **J90280.05 leftovers:** CM550's enum notes held J90280.05's table. `VALID_MEMORY_RANGE` is removed and the notes
    now give J90350's ranges.
  - **README:** the lookup box said the table was at 0x801be8; the code reads ROM 0x345dc.
  - **The `word` length:** tried and dropped, because Ghidra put the word at the stack slot's other half.
  - **Stale CM550 local rows:** removed. One had started matching the wrong variable after the retype.
  - **Proof:** {proof_a} The count in {ha}'s message ("13 MEMORY_REGION_TYPE members") was the number of lines
    in the whole file; the renders are counted above.
  - **Not done:** stage A said that stage B would write rows for the CM550 writer's real locals. B1 did not; that
    is a lead below.
- **Stage B1 ({hb}):** `writeJ1939DiagnosticMemory` (0x50af58 / 0x2148a), `handleJ1939WriteMemoryService` (0x50b408 /
  0x217de), `handleJ1939WriteMemoryLongLengthService` (0x50b474 / 0x21826), `getJ1939MemoryServiceHeaderLength`
  (0x50b610 / 0x21964), `validateSecurityKey` (0x5573c / 0x2fcdc, was `cm848_processSecurityCodeConversion` /
  `sensorRangeValidation`) and `unscrambleSecurityKey` (0x555cc / 0x2fbd8, was `cm848_copyDataBuffer`).
  - **Tables:** `j1939_memory_service_header_lengths`, `security_key_scramble_mask` and `security_key_byte_order` are
    byte-identical in both ROMs.
  - **The CM550 writer's prototype:** `char` (request, address, length). Its jump-table switch now names its
    `MEMORY_REGION_TYPE` cases.
  - **Locals:** the handlers' address / length locals are named in both firmwares.
  - **Docs:** README, the service 0x4B analysis' name map, and `feature_comparison.csv`.
  - **Method versioning:** a type 3 write without the key returns 0x1a in CM848 and 3 in CM550. CM848 also refuses
    its calibration RAM while RAM refresh is on, and adds Bank 2.
  - **Proof:** {proof_b}
- **Stage B2 ({hb2}), from the closing review's repo-wide sweep:**
  - **CM848's `MEMORY_ACCESS_FLAG`:** its `enums.csv` still carried it ('ported from CM550'), with
    `MEMORY_REGION_TYPE`'s codes and the J90280.05-era reading. It rendered nowhere and is removed, as CM550's was.
  - **The CM550 writer's header:** it no longer says it returns `MEMORY_OP_RESULT`.
  - **Proof:** {proof_b2}
  - **Left as they are:** the generated pipeline snapshots that still hold the old names: `classification.csv`,
    `cross_firmware_matches.csv` / `cross_firmware_variable_matches.csv`, CM550's `local_variables_actual.csv`,
    and the bank / worklist dumps.
  - **The pipeline's errors:** it had paired CM550's writer with CM848 0x50ac04 (not 0x50af58), and CM550's
    password with CM848's `eeprom_version_marker`.
- **firmware/CLAUDE.md:** line 108's registers entry now says that it is effectively 0x2FC000-0x301FFF. This is round
  71's verified finding: the first match wins, and the RAM entry takes 0x302000 and up.
- **Leads:**
  - **The writers' locals, in both firmwares:** CM550 shows `bVar2` / `bVar3` / `MVar4` / `cVar5`.
    - The importer rejects `bool`.
    - A row names the apply-time variable (`local_8`), not the displayed one (`auStack_8`).
  - **The security globals, in both firmwares:**
    - CM848's `security_sequence_step` (0x3fb9a8) is the key failure count (lockout at 0x11); CM550 has it at
      `DAT_00801e76`.
    - CM550's key byte `_DAT_00803b98` is EEPROM offset 0x8e. CM550's EEPROM mirror is at RAM 0x803b0a: the writer's
      EEPROM copy goes to `address - 0x7fc4f6`.
    - **The password:** both firmwares keep the 6-character password at EEPROM offset 2: CM848 0x3fd484 (mirror
      0x3fd482 + 2) and CM550 0x803b0c, its `ecu_identity_test_pattern` (mirror 0x803b0a + 2).
    - These need m68k width checks first.
  - **CM550's development mode flag at 0x80de30:** it renders as `j1708_transmit_buffer_2_32_ddc6.count_106`, inside a
    `j1708_multipacket_msg_t` instance. Its setters are `cm550_waterInFuelFaultClear` (0x118b2, sets it - J1708
    command 3 subcommand 0x40 after the key), `cm550_FUN_000118cc` (clears it) and
    `cm550_waterInFuelDetectionStateInit`. They are likely CM848's enter / exit / force exit development mode twins.
  - **CM550 read side:** `cm550_diagMemoryReadResponseBuilder`'s `extraout_var` (a 1-byte return would clear it), and
    the read-side twins: the memory read / write handlers 0x1edae / 0x1ec3c and the J1708 multipacket handlers
    0x1666c / 0x1686e.
  - **CM550 prototypes:** the handlers' void returns, `cm550_memcpy`'s short first parameter, and
    `cm550_circularBufferWrite` (0x16cd8), which has no body in the `.cpp`.
  - **Result enums:** CM550's `DIAG_ERROR_SOURCE` / `MEMORY_OP_RESULT` against CM848's `J1939_DIAGNOSTIC_RESULT`.
    `DIAG_ERROR_SOURCE` has two 0x0A members.
  - **README diagram:** it still reads the EEPROM path as "logging" and puts 0x1A on the type 3 path (J90350 returns 3).
  - **CM550 request struct:** CM550's 6-byte `j1939_header_t` against the request layout (+4 length / +6 data pointer
    = CM848's `j1939_rx_msg_t`).

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 72.**\n"
     f"- **Stage A ({ha}):** `lookupApplicationMemoryRegionType` is one function in CM848 and CM550 (shared name);\n"
     "  CM550's `MEMORY_ACCESS_FLAG` becomes `MEMORY_REGION_TYPE` and its 5-entry region table is typed.\n"
     f"- **Stage B1 ({hb}):** the PGN 61184 memory write service and its security key check are shared code: the\n"
     "  writer, both service handlers, the header-length getter, `validateSecurityKey` and `unscrambleSecurityKey`\n"
     "  share names in both firmwares; the key and header tables are named (byte-identical in both ROMs); the CM550\n"
     "  writer's switch names its region cases.\n"
     f"- **Stage B2 ({hb2}):** CM848's stale `MEMORY_ACCESS_FLAG` (ported from CM550, unused) removed.\n"
     "\n## Test plan\n")
edit(pr, "  misname.\n\nWhat 0x128a0 does",
     "  misname.\n"
     "- **Beyond CM848 (round 72):** the J1939 memory write service is shared code. Seven CM550 functions are\n"
     "  CM848 twins and share their names, so CM550's CSVs, the root README and `firmware/feature_comparison.csv`\n"
     "  change too.\n"
     "\nWhat 0x128a0 does")
edit(pr, "- [x] Round 71:", f"- [x] Round 72: A: {proof_a} B1: {proof_b} B2: {proof_b2}\n- [x] Round 71:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 72: the J1939 memory write service shared with CM550 (`session_folder/round72/`)\n\n"
       "- **Stage A:** `apply_r72a.py` / `apply_r72a2.py` / `apply_r72a3.py` / `apply_r72a4.py`, the maps "
       "`map_r72a_cm848.csv` / `map_r72a_cm550.csv`. **Stage B1:** `apply_r72b1.py` / `apply_r72b1b.py` / "
       "`apply_r72b1c.py` / `apply_r72b1d.py`, `map_r72b_*.csv`.\n"
       "- **Proof:** `prove_r72*.py` (renamed functions keyed by their new name; boundary-aware renames), "
       "`diff_r72*.py`. **Closing:** `apply_r72_closing.py`, `update_large_tar_r72.sh`.\n")
if "## Round 72:" not in t:
    i = t.index("## Round 71:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 71: MEMORY_REGION_TYPE - open: the task 046 leads",
     "round 71: MEMORY_REGION_TYPE; round 72: the J1939 memory write service shared with CM550 - open: the task 046 "
     "leads")
edit("firmware/CLAUDE.md", "registers 0x2FC000-0x307FFF type 3 auth)",
     "registers 0x2FC000-0x307FFF type 3 auth - effectively 0x2FC000-0x301FFF: the first match wins and the RAM entry "
     "takes 0x302000 and up)")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "application_memory_region_table; 9 / 10 double as results); task 046 leads"
new = ("application_memory_region_table; 9 / 10 double as results) + round 72 (the J1939 memory write service is "
       "shared with CM550: 7 twin functions share unprefixed names - lookupApplicationMemoryRegionType / "
       "writeJ1939DiagnosticMemory / validateSecurityKey / unscrambleSecurityKey ...; CM550 MEMORY_ACCESS_FLAG -> "
       "MEMORY_REGION_TYPE; CM550 builds need line-ending care: its structure_definitions.csv is CRLF); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
print("round 72 closing applied")
