"""Round 85 closing: task 046, PR body, session README, todo, the memory round log. Idempotent (each edit skips when its
new text is already there).  usage: apply_r85_closing.py <repo> <pr_body.md> <hash A> <hash B> <count> <proof A> <proof B>"""
import os
import re
import sys

repo, pr, ha, hb, count, pa_file, pb_file = os.path.abspath(sys.argv[1]), *sys.argv[2:8]
proof_a, proof_b = open(pa_file).read().strip(), open(pb_file).read().strip()


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = f"""## Done, round 85 (2026-11-24, same PR): the CM550 prefix rule audit, the Huffman tree struct, FLASH_ERASE_RESULT

Peer relays started and continued the round (04:50, 05:20, 05:50). Ultracode was on, so the audit and the research ran
as workflows. The scripts are in `session_folder/round85/`.
- **Stage A ({ha}), the prefix rule audit:** a workflow of 6 read-only investigators and 6 skeptics audited the 31
  functions round 84's `prefix_rule_check.py` listed, plus `cm550_FUN_0001c484`. Every proposal survived its skeptic.
  - **The rule:** commit 16143a5c (2026-03-17) says a function whose only hardware access is the inline watchdog kick
    is generic code, not `mc68k_`. `hardware_access_kinds.py` splits each body's accesses, unnamed 0xFFxxxx addresses
    included, so 12 of the proposed `mc68k_` names keep `cm550_`.
  - **23 renames, 11 `mc68k_` and 12 `cm550_`**, for example:
    - `injectorTimingCalculation` -> `mc68k_sampleAndDebounceDiscreteInputs`;
    - `oilPressureRpmFaultMonitor` -> `mc68k_monitorPwmOutputReadBackFaults`;
    - the four TPU channel 10 primary speed handlers, one per `speed_measurement_mode`;
    - `mc68k_applicationMain` and `mc68k_runPowerDownSequence`;
    - the parameter block loaders and savers;
    - `cm550_flashEraseFromRam`.
  - **9 spurious function records deleted** (`deleted_functions.csv`): mid-function points with no reference
    (`references_to.py`), rows inherited from the J90280.05 relocation map. Their parents' bodies do not change; the
    records only showed duplicates of their tails.
  - `relocation_map.csv` is the historical J90280.05 -> J90350.00 map, not CM550 -> CM848.
  - **Proof:** {proof_a}
- **Stage B ({hb}):**
  - The existing `huffman_tree_node_t` is applied: the `tree_buffer` pointers and the 513-node stack array.
  - `FLASH_ERASE_RESULT` is the return type of the erase routine and of its runner.
  - **Proof:** {proof_b}
- **Research for round 86: CM550's small stack arguments** (a read-only workflow; `stack_argument_survey/`):
  - **The compiler:** every byte or word argument takes a 2-byte slot (a byte sits at the odd address). Longs and
    pointers take 4 bytes and are not 4-aligned. 89 functions are affected, and no call site contradicts this.
  - **Ghidra:** `68000.cspec` right-justifies stack parameters in 4-byte slots (pentry align 4, and `<stackpointer>` has
    no `reversejustify`), so a word lands at +6. That gives `in_stack_00000004` and `param_N._0_2_`. A spec extension
    cannot change the justification; it can add a prototype.
- **firmware/CLAUDE.md:** none.
- **Leads:**
  - **Twins for a two-firmware rename:**
    - `cm550_restartOnKeyOnDuringPowerDown` / `cm848_restartOnKeyOnDuringPowerDown`;
    - `mc68k_runPowerDownSequence` / `cm848_runPowerDownSequence`;
    - `mc68k_applicationMain` / `cm848_applicationMain`;
    - `cm550_copyCalibrationFromRomToRam` / `cm848_copyRomToRamBuffer`.
  - `main_loop` (shared with CM848) is the 40-phase executive's periodic interrupt handler, not a loop.
  - **Still to name:**
    - `mc68k_FUN_00015df0` (the chip select 2 output set-up and the TPU channel 13 handshake);
    - `cm550_FUN_00028978` (the application main's restart entry);
    - `cm550_FUN_0001192a` (the restart routine).
  - **Wrong vocabulary:**
    - `calibration_bank_*` are the parameter block words;
    - `eeprom_calibration_write_success` (0x803FE8) is a save-failed flag;
    - `mc68k_waterInFuelDiagnosticHandler` is the PWM 3 / 4 start-up check;
    - `cm550_throttleTimeAccumulatorProcessor` is the mode 3 period ring / sync gap processor.
  - **Unreliable renders:** the .cpp drops blocks in `mc68k_flashEraseBlock` and `cm550_flashProgramAndVerifyWords`;
    read the ROM.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "\n**Round 85.**\n"
     f"- **Stage A ({ha}):** a workflow audit of CM550's hardware-touching functions. 23 are renamed for what they do\n"
     "  (11 take `mc68k_`; the watchdog-only ones stay `cm550_` under commit 16143a5c), and 9 spurious function records\n"
     "  are deleted.\n"
     f"- **Stage B ({hb}):** the Huffman tree node struct is applied; `FLASH_ERASE_RESULT`.\n"
     "\n## Test plan\n")
edit(pr, "- **Beyond CM848 (rounds 72-84):**", "- **Beyond CM848 (rounds 72-85):**")
edit(pr, "- [x] Round 84: B: ", f"- [x] Round 85: B: {proof_b}\n- [x] Round 85: A: {proof_a}\n- [x] Round 84: B: ")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 85: the CM550 prefix rule audit, the Huffman tree struct (`session_folder/round85/`)\n\n"
       "- **Stage A (CM550):** `audit_table.py` / `audit_records.py` (the audit workflow's result as a table / as full\n"
       "  records, `audit_records.txt`), `hardware_access_kinds.py` (watchdog-only vs real hardware access),\n"
       "  `references_to.py` (every m68k reference form to an address), `apply_r85a.py`, `map_r85a.csv`.\n"
       "- **Stage B (CM550):** `apply_r85b.py`.\n"
       "- **Research:** `stack_argument_survey/` (a CPU32 decoder and call-site walker that classifies CM550's small\n"
       "  stack arguments; its scripts and text outputs).\n"
       "- **Closing:** `apply_r85_closing.py`, `update_large_tar_r85.sh`.\n")
if "## Round 85:" not in t:
    i = t.index("## Round 84:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 84: CM550's boot block image and its updater - open: the task 046 leads",
     "round 84: CM550's boot block image and its updater; round 85: the CM550 prefix rule audit (23 renames, 9 spurious "
     "records), the Huffman tree struct - open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m2 = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
assert f"{count} commits" in m2
open(M + "MEMORY.md", "w").write(m2)
log = M + "pr53_egr_flow_delay_rounds.md"
t = open(log).read()
note = ("- Round 85 (CM550 prefix rule audit as a workflow: 23 renames under commit 16143a5c's rule - watchdog-kick-only "
        "= not mc68k_ - and 9 spurious J90280.05-map function records into deleted_functions.csv; huffman_tree_node_t "
        "applied, FLASH_ERASE_RESULT; research: CM550 passes byte / word arguments in 2-byte stack slots while Ghidra's "
        "68000.cspec right-justifies them in 4-byte slots - 89 functions; the fix is round 86)\n")
if "- Round 85 (" not in t:
    t = t.rstrip("\n") + "\n" + note
t = re.sub(r"is still OPEN on 2026-11-24\n\(\d+ commits\)", f"is still OPEN on 2026-11-24\n({count} commits)", t)
open(log, "w").write(t)
print("round 85 closing applied")
