"""Round 74 closing: task 046, PR body, session README, todo, memory. Idempotent (each edit skips when its new text is
already there).  usage: apply_r74_closing.py <repo> <pr_body.md> <hash A> <hash B> <hash C> <count> <proof A> <proof B> <proof C>"""
import os
import re
import sys

repo, pr, ha, hb, hc, count, proof_a_file, proof_b_file, proof_c_file = os.path.abspath(sys.argv[1]), *sys.argv[2:10]
proof_c = open(proof_c_file).read().strip()
proof_a = open(proof_a_file).read().strip()
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


T46 = f"""## Done, round 74 (2026-11-23, same PR): CM550's misapplied J1708 struct dismantled; the boot kernel's key check

A peer relay started the round; the scripts are in `session_folder/round74/`. These are round 73's leads.
- **Stage A ({ha}):** CM550's 256-byte `j1708_multipacket_msg_t` instance at 0x80ddc6 is gone.
  - **Why it was wrong:** CM550's parameter ID table puts 13 separate e2m blocks inside it. CM848's e2m names them:
    1127 J1708_Tx_Buffer, 1128 J1708_Rx_Buffer, the scratch pad, Development_Mode and more. Nothing took its address,
    and the type had no other instance.
  - **The renders:** its 980 field renders become CM550's existing names (`insite_response_write_pointer`,
    `insite_parameter_id`, `multipacket_bytes_remaining`, `instantaneous_fuel_rate_raw` ...). Each row is typed with
    the field's width.
  - **Removed rows:** the coordinate rows, and two byte rows inside pointers (their names kept in the comments).
  - **A2, real widths:** removing the struct exposed the real widths that its byte arrays had split, each confirmed in
    the m68k code. 0x80ddce is a dword; 0x80de50 / 0x80de6e / 0x80de72 are words. `fuel_timing_advance_value` and
    `timing_control_status_flags` are words, which drops their `_` prefix in 9 functions.
  - **Proof:** {proof_a} {ha}'s message says "all predicted"; the A2 widths came from the build, so "all
    explained" is the right word.
- **Stage B ({hb}):** the boot kernel's copies of the security key check.
  - **`cm848_validateBootSecurityKey`** (was `cm848_validateWriteAuth`) and **`cm848_unscrambleBootSecurityKey`** (was
    `cm848_descrambleAuthToken`).
  - **Their tables** in the boot image: `boot_security_key_byte_order` is the application's, but
    `boot_security_key_scramble_mask` is not. The reflash kernel scrambles its key differently.
  - **CM550's subcommands** 0x40 / 0x41 / 0x69 are the development mode functions (enter / force exit / exit), not
    J90280.05's 'calibration bank' switches.
  - **Proof:** {proof_b}
  - **The boot check's tail:** it compares the 6 characters with `eeprom_shadow_header.header_block`, which is the
    boot kernel's view of the master password. A match clears the count; a miss adds one.
- **Stage C ({hc}), from the closing review:** two more J90280.05-era CM550 enums duplicated CM848's.
  - `CALIBRATION_BANK` (0x80dc6c) duplicated `RAM_REFRESH_STATE`.
  - `CALIBRATION_STATE_SIGNATURE` (0x80dc90) duplicated `RUN_LOCATION`. No write of its extra 0xeaeb / 0xeeef was
    found.
  - Both rendered nowhere and are removed. The bank notes' parameter-table claim stays as a lead.
  - **Proof:** {proof_c}
- **firmware/CLAUDE.md:** line 398, the reference refresh's factual rename (`cm848_validateWriteAuth` ->
  `cm848_validateBootSecurityKey`).
- **Leads:**
  - **Pointer types for four dword rows** that hold addresses, which would remove the 4 casts: `j1708_receive_buffer_2_32`,
    `address_of_scratch_pad_directory_...`, `buffer_used_to_store_secure_write_data_...` and
    `insite_parameter_schedule_pointer`. Its constant 0x80de00 starts a table it walks (`bVar2 < 0x1e`).
  - **Names for the former span's type-only rows** (`BYTE_` / `WORD_` / `DWORD_` labels). Examples: 0x80de36 is block
    0015 Scratch_Pad_CRC; 0x80ddce is set to 0x808cff next to the receive buffer pointer; 0x80ddc6 is block 1127
    J1708_Tx_Buffer and keeps the old instance name.
  - **The boot kernel's `eeprom_shadow_header` fields** `version_marker` (the key byte) and `header_block` (the
    password) may be misnamed. Check them against the EEPROM offsets 0x8e / 0x02.
  - **The tool side:** `clip-core/src/SecurityAuth.cpp` scrambles with the application tables. They are J90350's,
    byte-identical to CM848's application tables, so service 0x4b / 0x4d keys work on both. A write through CM848's
    boot kernel needs `boot_security_key_scramble_mask` (23 24 c0 11 30 0e 46 22 0b c8).
  - **`WORD_0080de2e` (10 renders)** sits at block 1002 +2. CM848's e2m has Key_Switch_Override there; check it
    against CM550's e2m.
  - **Old CM550 enum members** (`CALIBRATION_FLASH_SOURCE` and others) and the parameter table's 'bytes 0-3 / 4-7 by
    ram_refresh_enable' claim are not checked.
  - **Left as they are:** the generated snapshots, including CM550's `parameter_id_lookup_table.csv` (old names in its
    variable column) and the `context_tier1` / `context_tier2` batches.
  - **`CALIBRATION_WRITE_PROTECT`** (0x80dc92's 0 / 1 / 2) and the CM550 mirror's 31 MISSING names; the writers'
    locals; `cm550_circularBufferWrite`; the skill notes' CM550 `_cal` line.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 74.**\n"
     f"- **Stage A ({ha}):** CM550's misapplied 256-byte `j1708_multipacket_msg_t` instance is gone (13 separate e2m\n"
     "  blocks lived inside it); its 980 field renders become CM550's own names for those globals, and the widths its\n"
     "  byte arrays had split are typed from the m68k code.\n"
     f"- **Stage B ({hb}):** the boot kernel's own copies of the security key check and unscramble (its scramble mask\n"
     "  differs from the application's); CM550's 'calibration bank' subcommands are the development mode ones.\n"
     f"- **Stage C ({hc}):** two more duplicate J90280.05-era CM550 enums removed (`CALIBRATION_BANK`,\n"
     "  `CALIBRATION_STATE_SIGNATURE`).\n"
     "\n## Test plan\n")
edit(pr, "- **Beyond CM848 (round 72):** the J1939 memory write service is shared code. Seven CM550 functions are\n"
         "  CM848 twins and share their names, so CM550's CSVs, the root README and `firmware/feature_comparison.csv`\n"
         "  change too.\n",
     "- **Beyond CM848 (rounds 72-74):** the J1939 memory write service and the development mode code are shared:\n"
     "  eleven CM550 functions are CM848 twins and share their names. Round 74 also dismantles a misapplied CM550\n"
     "  struct, so CM550's CSVs, the root README and `firmware/feature_comparison.csv` change too.\n")
edit(pr, "- [x] Round 73:", f"- [x] Round 74: A: {proof_a} B: {proof_b} C: {proof_c}\n- [x] Round 73:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 74: CM550's misapplied J1708 struct dismantled; the boot kernel's key check (`session_folder/round74/`)\n\n"
       "- **Stage A:** `struct_accesses.py` (every access with its address and width), `apply_r74a.py` (+ "
       "`patch_r74a_render.py`), `apply_r74a2.py`, `pairs_r74a.json`. **Stage B:** `apply_r74b.py`, `map_r74b_cm848.csv`. "
       "**Stage C:** `apply_r74c.py`. **Checks:** `closing_checks_r74.py`, `sweep_r74.py`.\n"
       "- **Proof:** `prove_r74*.py`, `diff_r74*.py`. **Closing:** `apply_r74_closing.py`, `update_large_tar_r74.sh`.\n")
if "## Round 74:" not in t:
    i = t.index("## Round 73:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 73: CM550's EEPROM mirror, the security key variables, development mode twins - open: the "
                     "task 046 leads",
     "round 73: CM550's EEPROM mirror, the security key variables, development mode twins; round 74: CM550's misapplied "
     "J1708 struct dismantled, the boot kernel's key check - open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "CM550 m68k widths via session_folder/round73/m68k_*.py); task 046 leads"
new = ("CM550 m68k widths via session_folder/round73/m68k_*.py) + round 74 (CM550's 256-byte j1708_multipacket_msg_t "
       "instance at 0x80ddc6 dismantled - 13 e2m blocks inside, 980 renders now CM550's own names; the boot kernel's "
       "cm848_validateBootSecurityKey / cm848_unscrambleBootSecurityKey - its scramble mask differs); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
print("round 74 closing applied")
