"""Round 70 closing: task 046, PR body, README, todo, memory, the engine hours doc. Idempotent (each edit skips when
its new text is already there).  usage: apply_r70_closing.py <repo> <pr_body.md> <hash A> <hash B> <count> <proof>"""
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


T46 = f"""## Done, round 70 (2026-11-23, same PR): the 6 KB dual-port TPU RAM and what lives in it

A peer relay started the round; the scripts are in `session_folder/round70/`.
- **Stage A ({ha}):** from round 69's TPU table lead.
  - **The RAM:** `cm848_clearRamRegions` clears 0x302000-0x3037ff, 6 KB: the dual-port TPU RAM
    (`dual_port_tpu_ram_start` / `_end`). The boot kernel keeps most of its RAM variables there; others sit in the
    SRAM, such as `eeprom_shadow_header` at 0x3fee08 and `serial_reflash_busy_flag` at 0x3fedee.
    `classify_dptram_rows.py` counts 39 named rows in it: 30 rendered before this stage and 33 after, none in an
    application function.
  - **The stale map:** an early campaign had laid a TPU3 register map over it. 28 rows that rendered nowhere are
    removed; `TPU3_TPUMCR` and `TPU3_HSQR1` were renamed.
  - **The CAN rings** tile the RAM: `boot_can_receive_ring` (`j1939_rx_msg_t[40]`) and `boot_can_transmit_ring`
    (a new 12-byte `boot_can_transmit_frame_t[40]`: a TouCAN ID image and 8 data bytes). The wrap bounds prove both
    counts, and `can_ring_state_t`'s pointers are typed to match.
  - **`ecu_power_state_flags`:** three stale flat rows inside it became its field rows.
  - **`dual_port_tpu_ram_load_table`** (0x5862e): three variable-length records that `mpc555_initTpuConfiguration`
    copies into 0x302000-0x302fff before it starts both TPUs - TPU microcode by that use.
  - **The markers:** the 0xa1a1 words that bracket the first checksum region.
- **Proof:** {proof}
- **Along the way:** the first `apply_r70a.py` run stopped before saving: its drop loop had already removed the junk
  `TPU3_HSQR1+1` row that a later line removed again. The ring-pointer retype was tried with a single build first and
  kept (9 casts fewer).
- **Follow-up ({hb}), from the closing review:**
  - NXP's "Motorola MPC5xx Memory Maps" (Rev C, March 2003) lists, for the MPC555, "DPTRAM (6 Kbytes)" at
    0x302000-0x3037ff and "DPTRAM Control" at 0x300000-0x30003f. So the RAM is sourced, not inferred.
  - 0x300004 (`usiu_ext_004`, inside that control block; the USIU is 0x2fc000-0x2fc7ff) is `DPTRAM_RAMBAR`. The
    boot code writes 0xffa0, the value the MPC555 user's manual requires (as a web search excerpted it).
  - TPUMCR bit 0x400 is EMU: a TPU in emulation mode runs its microcode from the DPTRAM and the CPU loses access to
    it, which is why `mpc555_initTpuConfiguration` loads the table first. The function is sourced; the bit position
    comes from the TPU3 register layout.
  - `mpc555_registers.csv`, which the build applies, carried the same TPU3 map at 0x302000 (29 rows); it is gone,
    and the file's TPUA / TPUB headers now say TPU3_A / TPU3_B.
  - `cm848_writeBootKernelCanTxMailbox`'s frame stays `word *`. Typed as the frame struct, its halfword copy started
    at `frame[-1].data + 6`, so `fix_r70b2.py` reverted it.
- **firmware/CLAUDE.md:** no edit.
- **Leads:**
  - `cm848_clearRamRegions`' SRAM bound 0x3fffd0 renders as `wastegate_duty_floor_x_axis + 0x12` (an application
    table time-shares it). The 48 bytes above it are left alone; what they hold is open.
  - Round 69's leads stand: the Bank 2 re-dump, the 0x8000 branch table, the dword pairs after
    `block_data_structure`, and `block_capacity`'s 0x1f7e. So do round 67's and 68's.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 70.**\n"
     f"- **Stage A ({ha}):** the 6 KB dual-port TPU RAM at 0x302000, where the boot kernel lives. Its CAN rings are typed\n"
     "  (`boot_can_receive_ring` / `boot_can_transmit_ring`), a stale TPU3 register map is gone (28 rows), the TPU RAM\n"
     "  load table is named, and the receive path reads record fields.\n"
     f"- **Follow-up ({hb}):** the RAM is sourced from NXP's MPC5xx memory map; `DPTRAM_RAMBAR` (0x300004, written\n"
     "  0xffa0); TPUMCR's EMU bit explains the microcode load; the same stale TPU3 map removed from\n"
     "  `mpc555_registers.csv`.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 69:", f"- [x] Round 70: {proof}\n- [x] Round 69:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 70: the 6 KB dual-port TPU RAM (`session_folder/round70/`)\n\n"
       "- **Stage A:** `apply_r70a.py`, `map_r70a.csv`, `classify_dptram_rows.py`. **Follow-up:** `fix_r70b.py` (the MPC5xx\n"
       "  memory map), then `fix_r70b2.py` (one retype reverted). **Proof:** `prove_r70.py`,\n"
       "  `diff_r70.py`. **Closing:** `apply_r70_closing.py`, `update_large_tar_r70.sh`.\n")
if "## Round 70:" not in t:
    i = t.index("## Round 69:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md",
     "round 69: the calibration image header at ROM 0x8100 and the checksum region table - open: the task 046 leads",
     "round 69: the calibration image header at ROM 0x8100 and the checksum region table; round 70: the dual-port TPU "
     "RAM, the boot CAN rings - open: the task 046 leads")
E = "firmware/CM848_S90140.06_analysis/docs/engine_hours_and_odometer.md"
NOTE = "(was the stale flat row `ecm_runtime_accumulator`, PR #53 round 70)"
e = open(path(E)).read()
if NOTE not in e:
    old_def = "- `ecm_runtime_accumulator` @ 0x00302012 (lifetime counter)"
    assert e.count(old_def) == 1
    e = re.sub(r"\becm_runtime_accumulator\b", "ecu_power_state_flags.runtime_counter", e)
    e = e.replace("- `ecu_power_state_flags.runtime_counter` @ 0x00302012 (lifetime counter)",
                  "- `ecu_power_state_flags.runtime_counter` @ 0x00302012 (lifetime counter)\n  " + NOTE)
    open(path(E), "w").write(e)
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "checksum_region_table at 0xb752); task 046 leads"
new = ("checksum_region_table at 0xb752) + round 70 (0x302000-0x3037ff = the 6 KB dual-port TPU RAM = the boot kernel's "
       "RAM: boot_can_receive_ring / boot_can_transmit_ring typed, a stale TPU3 register map removed, the TPU RAM load "
       "table 0x5862e); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
print("round 70 closing applied")
