"""Round 69 closing: task 046, PR body, README, todo, memory. Idempotent (each edit skips when its new text is
already there).  usage: apply_r69_closing.py <repo> <pr_body.md> <hash A> <hash B> <count> <proof text file>"""
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


T46 = f"""## Done, round 69 (2026-11-23, same PR): the calibration image header at ROM 0x8100, the checksum region table

A peer relay started the round; the scripts are in `session_folder/round69/`.
- **Stage A ({ha}):** round 67's image header lead.
  - e2m names the header as separate blocks: 1235 `Smart_Boot_Indicator` (0x8100), 1236 (0x8104: the checksum table
    pointer and a dummy range), 1198 (0x810e, the entry pointer) and 002E `Block_Data_Structure` (0x8112, 60 bytes).
    They became `smart_boot_indicator`, `checksum_table_descriptor_t`, the existing `flash_operational_code_entry_pointer`
    and `block_data_structure_t`.
  - `block_data_structure_t`'s arrays each follow their own word count (4 here). The verifier's `0x811e + 8 x count`
    is that layout, now rendered as `block_start_address + download_block_count * 2 + 1`. The counts have no
    reader, so they stay `reserved_<offset>`. `block_length` holds the image lengths (the ROM is 0xff from 0x6fc64,
    where module B's ends); the verifier compares recorded end addresses with them.
  - `checksum_region_table_t` (0xb752): a count and two regions. The verifier's walk now reads
    `region->start_address` / `end_address` / `expected_sum`. Region 1 sums to 0xd501 in the ROM dump; region 2
    (Bank 2) runs past both flash2 dumps.
  - `bank2_image_last_word` (0x53ea6c): the region's pointer field made Ghidra label it inside
    `cm848_lookupParameterIdAddress`.
- **Proof:** {proof}
- **How it got there:** the first plan was one 78-byte struct, and e2m's blocks replaced it. `fix_r69a2.py` named
  0x53ea6c and `fix_r69a3.py` added field rows (a verify was stopped and rerun to cover them). The importer packs
  fields (`eeprom_block_tracking_t`'s dwords sit at odd addresses), and the region stride confirms it here, but
  `block_data_structure`'s fields at +6 / +26 / +44 never render.
- **Follow-up ({hb}):**
  - `smart_boot_indicator`: no CM848 code builds 0x98765432 (no `lis` 0x9876 / `ori` 0x5432 pair in the ROM or
    Bank 2), while CM550's boot code compares it (`cmpi.l #$98765432,(a0)` at CM550 0x3c02, where its ROM holds no
    header - so no second count to name the count words from).
  - Round 67's two live comments that said "the image header at ROM 0x8104" now name `checksum_region_table` /
    `block_data_structure`.
- **firmware/CLAUDE.md:** no edit.
- **Leads:**
  - **Bank 2 is longer than dumped (a bench lead):** the image runs to 0x53ea6d (`block_length[2]` = 0x3ea6e;
    checksum region 2 ends at 0x53ea6c). That is past both flash2 dumps (0x53d4e9 / 0x53dfff), and past the
    0x53DFFF the auditing-cal-suffixes skill gives as Bank 2's end. Re-dumping 0x53e000-0x53ea6d would check region 2's
    sum (0x17b2) and give `parameter_id_table`'s last 445 records. The e2m files carry no binary records (two
    sections each), so it cannot come from them. (The skill is not edited on a peer round.)
  - `mpc555_initTpuConfiguration` copies a TPU RAM init table, `{{offset / count / words}}` records from 0x5862e to
    0x591f6, which is the end of checksum region 1. Type it.
  - 0x8000-0x80ff is a table of `b` instructions at block 1's start.
  - Past `block_data_structure` come more dword pairs; e2m maps nothing from 0x814e to 0x81bf.
  - 0xb768 is 0x0000 between the table and region 1. Region 1 starts with 0xa1a1, and the code starts at 0xb76c.
  - `block_capacity`'s 0x1f7e (0x80 + 0x1f7e = 0x1ffe) is unexplained.
  - Round 67's other open leads stand: a memory region type enum, 0x3fedee / 0x3fedf4, `DAT_01000000`, the boot
    `eeprom_*` vocabulary and the serial response codes. So do round 68's. The image header is this round.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 69.**\n"
     f"- **Stage A ({ha}):** the calibration image header at ROM 0x8100, typed by e2m's own blocks (1235 / 1236 / 002E),\n"
     "  and the checksum region table at 0xb752. The verifier's checksum walk now reads `region->start_address` /\n"
     "  `end_address` / `expected_sum`; region 1 sums to its 0xd501 in the ROM dump.\n"
     f"- **Follow-up ({hb}):** the smart boot indicator's readers (none in CM848; CM550's boot code compares it); two\n"
     "  stale comments. Bank 2's image runs to 0x53ea6d, past both dumps: a bench lead.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 68:", f"- [x] Round 69: {proof}\n- [x] Round 68:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 69: the calibration image header at ROM 0x8100 (`session_folder/round69/`)\n\n"
       "- **Stage A:** `apply_r69a.py`, then `fix_r69a2.py` (`bank2_image_last_word`) and `fix_r69a3.py` (field rows).\n"
       "  **Proof:** `prove_r69.py`, `diff_r69.py`. **Closing:** `apply_r69_closing.py`, `update_large_tar_r69.sh`.\n")
if "## Round 69:" not in t:
    i = t.index("## Round 68:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md",
     "round 68: the application's EEPROM mirror words at 0x3fee18 from e2m - open: the task 046 leads",
     "round 68: the application's EEPROM mirror words at 0x3fee18 from e2m; round 69: the calibration image header at "
     "ROM 0x8100 and the checksum region table - open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "the boot header struct ends at 0x3fee17); task 046 leads"
new = ("the boot header struct ends at 0x3fee17) + round 69 (the calibration image header at ROM 0x8100 = e2m 1235 / "
       "1236 / 002E blocks, checksum_region_table at 0xb752); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
print("round 69 closing applied")
