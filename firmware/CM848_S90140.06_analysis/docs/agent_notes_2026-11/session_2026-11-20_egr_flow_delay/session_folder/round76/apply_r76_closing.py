"""Round 76 closing: task 046, PR body, session README, todo, memory. Idempotent (each edit skips when its new text is
already there).  usage: apply_r76_closing.py <repo> <pr_body.md> <hash A> <count> <proof A>"""
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


T46 = f"""## Done, round 76 (2026-11-23, same PR): CM550's MC68336 register map

A peer relay started the round; the scripts are in `session_folder/round76/`. This was round 75's first lead.
- **Stage A ({ha}), CM550:** all 141 MC68336 module registers that the code reaches now have names. Before this,
  only round 75's four SCI registers had names, and the rest rendered as raw `Ram00fffXXX` addresses.
  - **Source:** the MC68336/376 User's Manual, Appendix D (Register Summary, Rev. 15 Oct 2000:
    https://www.nxp.jp/docs/en/user-guide/MC68336376UMD.pdf). The code addresses the block at $FFF000 (Y = F).
    - Names follow CM848's `mpc555_registers.csv` form `<module>_<mnemonic>`.
    - Widths are the manual's. The m68k accesses that llvm-mc decodes agree with them
      (`register_access_sizes.py`; LLVM's m68k decoder misses some forms such as `ori.w` / `bset`).
  - **SIM:** the watchdog service `SIM_SWSR` (128 references) and the system protection, periodic interrupt, port E /
    F and chip-select registers.
  - **QADC, QSM (QSPI with its RAM entries), CTM4 and TPU:**
    - QADC: `QADC_PORTQA_PORTQB` is one word, because the code reads and writes both ports together.
    - CTM4: MCSM2, DASM3 / 4 / 9 / 10, PWMSM5-8, MCSM11 and FCSM12.
    - TPU: the module registers and the parameter RAM words in use (Table D-57). The code clears `TPU_CH0_PARAM6`,
      which the table says is not implemented on channels 0-13.
  - **Dwords for 32-bit-only pairs:** `SRAM_RAMBAH_RAMBAL` and three TPU parameter pairs (channel 0 parameters 4-5,
    channel 3 parameters 2-3, channel 12 parameters 2-3) are one dword each, since the code reaches them only with one
    32-bit access.
  - **Mixed pairs:** eight pairs that the code also reaches as separate words keep word names, and their 32-bit accesses
    render as the raw address. These are DASM3 A / B, PWMSM5-8 period / pulse width, and the TPU channel 1 / 3 / 10
    parameter pairs.
  - **Removed, five register struct types (41 rows):** `mc68336_reg16_t`, `tpu_dscr_block_t`, `tpu_hsq_block_t`,
    `sim_timer_block_t` and `serial_port_regs_t`. Their instances never applied, because the register space has no
    memory block when ApplyStructures runs, and their names contradict the manual:
    - a QSM SCI data register at 0xFFD00E;
    - TPU blocks on QSM addresses;
    - TPU parameter RAM on the QSPI command RAM;
    - a SIM timer on CTM4 BIUTBR.
  - **Removed, `param_circular_buffer_t` (6 rows):** each of its fields had its own address, so it built one 1544-byte
    type with an instance at every field address. None rendered before this round. The changed type set let its
    instance at 0x80C3FE apply, and then a 1280-byte buffer rendered as `circular_buffer_count.metadata[...]`.
  - **Proof:** {proof_a}
- **firmware/CLAUDE.md:** none.
- **Leads:**
  - **Three external devices on chip selects:**
    - 0xFFC800: an 82527-style CAN controller layout, with message objects every 0x10 bytes; CM550's J1939?
    - 0xFFD000-0xFFD00F: 0xFFD00F has 128 references, next to the SWSR service.
    - 0xFFD800: a second controller of the same layout?
    The CSBARn / CSORn values that the code writes at start-up say which chip select maps each one.
  - **The 1280-byte parameter buffer at 0x80C7A8:** `cm550_parameterCircularBufferWrite` wraps its index at 0x500, and
    the QSPI path sends from it through `QSM_TR5`. Its indexes are `_eeprom_circular_buffer_write_index` and
    `_DAT_0080cca8`. The `circular_buffer_*` labels at 0x80C3FA-0x80C402 still name another model of it.
  - **Bit fields:** TPU function selections per channel (CFSR0 / 1 / 3), host service requests and priorities could
    become bitfields or enums once each channel's TPU function is known. The same goes for the CTM4 PWM / DASM modes.
  - **Misnamed `mc68k_*` functions:** with the registers named, `mc68k_tpuChannelStateMachine`,
    `mc68k_can1TimerBufferInitDivided`, `mc68k_pwmTimerMode*` and others can be read for what they drive.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 76.**\n"
     f"- **Stage A ({ha}):** CM550's MC68336 register map: the 141 module registers the code reaches are named from the\n"
     "  MC68336/376 manual's register summary (SIM, QADC, QSM, CTM4, TPU and its parameter RAM, the RAM modules), with\n"
     "  the manual's widths; five wrong register struct types and a malformed circular buffer struct are removed.\n"
     "\n## Test plan\n")
edit(pr, "- **Beyond CM848 (rounds 72-75):** the J1939 memory write service and the development mode code are shared:\n"
     "  eleven CM550 functions are CM848 twins and share their names. Round 74 also dismantles a misapplied CM550\n"
     "  struct, and round 75 types CM550's InSite parameter schedule and names its J1708 SCI, so CM550's CSVs, the root\n"
     "  README and `firmware/feature_comparison.csv` change too.\n",
     "- **Beyond CM848 (rounds 72-76):** the J1939 memory write service and the development mode code are shared:\n"
     "  eleven CM550 functions are CM848 twins and share their names. Round 74 also dismantles a misapplied CM550\n"
     "  struct, round 75 types CM550's InSite parameter schedule and names its J1708 SCI, and round 76 names CM550's\n"
     "  MC68336 registers, so CM550's CSVs, the root README and `firmware/feature_comparison.csv` change too.\n")
edit(pr, "- [x] Round 75:", f"- [x] Round 76: A: {proof_a}\n- [x] Round 75:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 76: CM550's MC68336 register map (`session_folder/round76/`)\n\n"
       "- **Stage A (CM550):** `register_access_sizes.py` (each register's m68k access sizes, decoded with llvm-mc-18;\n"
       "  `register_access_sizes.txt`), `apply_r76a.py` (the 141 register rows and the five struct types removed),\n"
       "  `apply_r76a2.py` (the 32-bit-only pairs as dwords), `apply_r76a3.py` (the malformed circular buffer struct).\n"
       "  The register names come from the MC68336/376 User's Manual, Appendix D (NXP, MC68336376UMD.pdf); the manual\n"
       "  itself is not archived here.\n"
       "- **Proof:** `prove_r76a_cm550.py`, `residual_r76a_cm550.py`, `diff_r76a_cm550.py`. **Closing:**\n"
       "  `apply_r76_closing.py`, `update_large_tar_r76.sh`.\n")
if "## Round 76:" not in t:
    i = t.index("## Round 75:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 75: the boot EEPROM header named, CM550's InSite parameter schedule and J1708 SCI - open: the "
     "task 046 leads",
     "round 75: the boot EEPROM header named, CM550's InSite parameter schedule and J1708 SCI; round 76: CM550's "
     "MC68336 register map - open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "ApplyHardwareRegisters typed rows ImportAnalysis had already labelled); task 046 leads"
new = ("ApplyHardwareRegisters typed rows ImportAnalysis had already labelled) + round 76 (CM550's 141 MC68336 registers "
       "named from the MC68336/376 UM Appendix D register summary - <module>_<mnemonic>, the manual's widths; 32-bit-only "
       "pairs as dwords; 5 wrong register struct types + the per-field-address param_circular_buffer_t removed; leads: "
       "the external chips at 0xFFC800 / 0xFFD000 / 0xFFD800); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
print("round 76 closing applied")
