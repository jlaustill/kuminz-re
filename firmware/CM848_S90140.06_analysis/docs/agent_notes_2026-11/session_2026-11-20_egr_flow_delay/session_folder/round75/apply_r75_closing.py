"""Round 75 closing: task 046, PR body, session README, todo, memory. Idempotent (each edit skips when its new text is
already there).  usage: apply_r75_closing.py <repo> <pr_body.md> <hash A> <hash B> <count> <proof A> <proof B>"""
import os
import re
import sys

repo, pr, ha, hb, count, proof_a_file, proof_b_file = os.path.abspath(sys.argv[1]), *sys.argv[2:8]
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


T46 = f"""## Done, round 75 (2026-11-23, same PR): the boot kernel's EEPROM header; CM550's InSite parameter schedule and J1708 SCI

A peer relay started the round; the scripts are in `session_folder/round75/`. These are round 74's leads.
- **Stage B ({hb}), CM848:** `cm848_loadVersionConfigFromEeprom` fills `eeprom_shadow_header` from five EEPROM words.
  Each field is now named for the word it holds:
  - +0 `security_key_copy` (was `version_marker`) holds EEPROM 0x34. The boot service loop `mpc555_systemInitialization`
    writes EEPROM 0x8e there each time it starts. `cm848_validateBootSecurityKey` passes every key while the copy is 0xff,
    which is the same gate `validateSecurityKey` applies to EEPROM 0x8e itself.
  - +4 `security_master_password` (was `header_block`) holds EEPROM 0x2, e2m 0005 ECM_PSWD. The boot key check compares
    the unscrambled key with it.
  - +10 `key_on_hour_meter` (was `config_dword`) holds EEPROM 0x30, the runtime counter's source.
  - +14 `calibration_download_security_key` (was `config_word`) holds EEPROM 0x8e, e2m 1000 Security_Key.
  - The EEPROM-space rows get the same names with `_cal` and their real widths. `eeprom_serial_number` was the security
    key. CM848 MISSING: 210 -> 206.
  - `docs/engine_hours_and_odometer.md` said the runtime counter is read from EEPROM 0x34; it is read from 0x30.
  - **Proof:** {proof_b}
- **Stage A ({ha}), CM550:** the InSite parameter schedule and the J1708 SCI.
  - **The schedule:** `insite_parameter_schedule_entry_t` {{`parameter_id`, `period`, `first_due_offset`}} types
    `insite_parameter_table_pointer`. `insite_parameter_schedule_pointer` is a `byte *` into the new
    `insite_parameter_next_due_ticks` (byte[30]). `insite_parameter_schedule_tick` (0x80ddfe) is the tick that
    `cm550_diagnosticMessageTransmissionManager` advances after each pass.
  - **The schedule table** (ROM 0x612ee, `insite_parameter_schedule_table`) lies past the 256 KB dump, where CM550 has no
    memory block, so the row stays label-only. The first build typed the row, and the importer reported '1 failed (in code)'.
  - **Pointer types:** three address-holding dwords become `byte *` and drop their `(dword)&` casts: the scratch pad
    buffer and directory pointers and `j1708_transmit_buffer_2_32_ddc6`.
  - **The J1708 SCI:** CM550 had no row in the MC68336 register space, so every register rendered `Ram00fffXXX`.
    `QSM_SCCR0` / `QSM_SCCR1` / `QSM_SCSR` / `QSM_SCDR` are named from the J1708 code.
    `mc68k_tpuTransmissionTrigger` is renamed `mc68k_startJ1708Transmission` (it drives no TPU channel),
    `mc68k_FUN_00029130` is renamed `mc68k_initializeJ1708Datalink`, and `mc68k_epsPositionSensorIsrHandler` is
    renamed `mc68k_j1708SciInterruptHandler`. That function reads each received byte from SCDR on RDRF, sends the next
    transmit byte, and ends a transmission with the two's complement checksum. All three keep CM550's `mc68k_` prefix
    for functions that access MC68336 registers (16143a5c).
  - **`firmware/scripts/ApplyHardwareRegisters.java`:** ImportAnalysis labels every `global_variables.csv` row before
    this stage creates the register block. The stage therefore found the four registers already named, skipped them and
    left them without data, so they rendered as `Ram00fffc0X`. A row's own name no longer counts as already named, and
    the four now render at all 31 references. CM848 does not run this script.
  - **Proof:** {proof_a}
- **firmware/CLAUDE.md:** two factual corrections. The EEPROM 0x0002 row is the master password, and the shadow header's
  runtime counter field is `key_on_hour_meter`.
- **Leads:**
  - **The MC68336 register map for CM550:** besides the four SCI registers, the TPU, QSPI, SIM and CTM4 registers still
    render as `Ram00fffXXX` (0xFFFE0A and 0xFFFE18 have 76 renders each, 0xFFFE1E has 72, 0xFFFC1A has 44). Name them
    from the MC68336 manual and check each against its code. CM550's struct rows `tpu_dscr` / `tpu_hsqr0` / `tpu_cpr1`
    sit at QSM addresses 0xFFFC04 / 0xFFFC14 / 0xFFFC1E, but the TPU is at 0xFFFE00. They never apply.
  - **`mc68k_tpuChannelStateMachine` (0x300d4) is J1708 code, not TPU code.** It clears the flag bits of the timer at
    0xFFF458, ends a received message (it drops messages of fewer than 3 bytes and checks the checksum) and writes a
    pending transmit byte to SCDR. Its exact role (the bus idle timer?) still needs a reading. Its sibling
    `mc68k_tpuTimerChannelEnable`, which the SCI interrupt handler calls, needs one too.
  - `relocation_map.csv` (a generated snapshot) still lists `epsPositionSensorIsrHandler`.
  - `insite_response_frame_start` can become a pointer only after `insite_response_write_pointer` is typed, and that
    global has 99 CONCAT renders.
  - `diagnostic_multipacket_data_pointer` is used both as an address (the uint parameter of
    `lookupApplicationMemoryRegionType`) and as a byte pointer.
  - The scratch pad directory holds 6-byte entries (an address dword + a word): a struct candidate.
  - The parameter bitmaps: ROM 0x6134a (past the dump) and the RAM one named `vp44_fuel_demand_accumulator`.
  - `j1708_rx_state_t_0080dcaf` renders in pieces (`buffer_ptr_1._1_1_`): its fields do not fit the code.
  - The six startup functions that call `mc68k_initializeJ1708Datalink` (`vp44_FUN_000284e8`,
    `vp44_slowCycle4Coordinator` ...) have doubtful names.
  - `j1708_receive_buffer_2_32` holds the address of `diagnostic_rx_buffer_base` (a `diagnostic_buffers_t`); the
    pointer's target type is open.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 75.**\n"
     f"- **Stage B ({hb}):** the boot kernel's EEPROM header shadow is named for the EEPROM words it holds (the master\n"
     "  password, the key-on hour meter, the security key and the boot kernel's copy of it); the EEPROM rows get their\n"
     "  widths and `_cal` (`eeprom_serial_number` was the security key).\n"
     f"- **Stage A ({ha}):** CM550's InSite parameter schedule is typed (a 3-byte record struct, the next due ticks, the\n"
     "  tick); the first MC68336 registers CM550 names are the J1708 SCI's (`QSM_SCCR0` ... `QSM_SCDR`), and the J1708\n"
     "  transmit start, datalink initializer and SCI interrupt handler get their names (`ApplyHardwareRegisters.java`\n"
     "  now types a register row the importer has already labelled).\n"
     "\n## Test plan\n")
edit(pr, "- **Beyond CM848 (rounds 72-74):** the J1939 memory write service and the development mode code are shared:\n"
     "  eleven CM550 functions are CM848 twins and share their names. Round 74 also dismantles a misapplied CM550\n"
     "  struct, so CM550's CSVs, the root README and `firmware/feature_comparison.csv` change too.\n",
     "- **Beyond CM848 (rounds 72-75):** the J1939 memory write service and the development mode code are shared:\n"
     "  eleven CM550 functions are CM848 twins and share their names. Round 74 also dismantles a misapplied CM550\n"
     "  struct, and round 75 types CM550's InSite parameter schedule and names its J1708 SCI, so CM550's CSVs, the root\n"
     "  README and `firmware/feature_comparison.csv` change too.\n")
edit(pr, "- [x] Round 74:", f"- [x] Round 75: A: {proof_a} B: {proof_b}\n- [x] Round 74:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 75: the boot kernel's EEPROM header; CM550's InSite parameter schedule and J1708 SCI "
       "(`session_folder/round75/`)\n\n"
       "- **Stage B (CM848):** `apply_r75b.py` (the header fields, the EEPROM rows, the plate comment), `map_r75b.csv`.\n"
       "- **Stage A (CM550):** `apply_r75a.py` (the schedule struct, the pointer types), `apply_r75a2.py` (the table row\n"
       "  label-only: no memory block past the dump), `apply_r75a3.py` (the SCI registers, the two J1708 functions),\n"
       "  `apply_r75a4.py` (the mc68k_ prefix), `apply_r75a5.py` (the SCI interrupt handler), `map_r75a3/4/5.csv`.\n"
       "- **Proof:** `prove_r75*.py`, `diff_r75*.py`. **Closing:** `apply_r75_closing.py`, `update_large_tar_r75.sh`.\n")
if "## Round 75:" not in t:
    i = t.index("## Round 74:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 74: CM550's misapplied J1708 struct dismantled, the boot kernel's key check - open: the task "
     "046 leads",
     "round 74: CM550's misapplied J1708 struct dismantled, the boot kernel's key check; round 75: the boot EEPROM header "
     "named, CM550's InSite parameter schedule and J1708 SCI - open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "its scramble mask differs); task 046 leads"
new = ("its scramble mask differs) + round 75 (eeprom_shadow_header's fields = the EEPROM words they hold: security_key_copy "
       "= EEPROM 0x34, written from 0x8e by the boot service loop and the boot key gate; master password 0x2; key-on hour "
       "meter 0x30; eeprom_serial_number was the security key; CM550: the InSite parameter schedule typed, its first "
       "MC68336 registers named (QSM SCI - CM550 had none in 0x00FFxxxx), mc68k_startJ1708Transmission / "
       "mc68k_initializeJ1708Datalink / mc68k_j1708SciInterruptHandler; ApplyHardwareRegisters typed rows ImportAnalysis had already labelled); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
print("round 75 closing applied")
