"""Round 86 closing: task 046, PR body, session README, todo, the memory round log. Idempotent.
usage: apply_r86_closing.py <repo> <pr_body.md> <hash A> <hash B> <hash C> <count> <proof A> <proof C> <remaining>"""
import os
import re
import sys

repo, pr, ha, hb, hc, count, pa_file, pc_file, remaining = os.path.abspath(sys.argv[1]), *sys.argv[2:10]
proof_a, proof_c = open(pa_file).read().strip(), open(pc_file).read().strip()


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = f"""## Done, round 86 (2026-11-24, same PR): CM550's stack parameters in 2-byte slots

Peer relays started and continued the round (06:20, 06:50, 07:20). The scripts are in `session_folder/round86/`.
- **Stage A ({ha}), the fix from round 85's research and design:**
  - `ScriptUtils.java` gains `parseStackParameterLayout()` and `packStackParameters()`, with 15 unit tests.
  - `ApplyFunctionDefinitions.java` takes an optional layout file. With it, each typed parameter gets custom stack
    storage at its packed offset, read back and checked. A function with a gap or an unknown row is skipped with an
    Error.
  - `common.sh` passes CM550's new `stack_parameter_layout.csv` (first offset 4, 2-byte slots).
  - CM550's rows: the design's wave 0 (26 functions re-typed, re-indexed or reshaped) and wave 1 (3 new prototypes).
  - **Proof:** {proof_a}
- **Stage B ({hb}), docs:** two firmware/CLAUDE.md statements that stage A made false (the test count, and the
  return-only / gap rule on CM550), and the local-variable storage rule in the CM550 prototype file's header.
- **Stage C ({hc}), wave 2:** a workflow of 6 read-only investigators and 6 skeptics proposed and verified rows for
  the 58 functions that still showed stack-argument pieces: 50 accepted, 8 amended (comments only), 88 parameter rows.
  - **Proof:** {proof_c}
- **firmware/CLAUDE.md:** the two corrections in stage B (old and new lines in its commit).
- **Leads:**
  - {remaining}
  - The `editing-firmware-csvs` skill still says a return-only row is auto-handled; on CM550 it is now skipped.
  - Callers that push a word with a stale high byte (the compiler replaced only the low byte) render a CONCAT now that
    the callee takes the whole word; `cm550_serialNodeAddressChecker` uses only `node_address & 0xff`.
  - The EMA filter records at 0x800066 / 0x80006e (a coefficient pointer, then an accumulator) are misnamed
    `timing_table_4_ptr` and so on: CM848's `ema_filter_state_t` shape, a struct lead.
  - The `undefined8` returns of the EMA and interpolation helpers (the D0:D1 join) are a separate return-row issue.
  - Wave 2's naming leads: 0xb688 is the same code as CM848's `cm848_getJ1939DiagnosticResponseEchoLength`;
    `cm550_modeBasedDataDispatcher` is the chip select 5 CAN receive message object dispatcher, and its two wrappers
    read their own word argument; `cm550_retarderModeThresholdCalculator` works on the engine speed pulse period
    rings.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "\n**Round 86.**\n"
     f"- **Stage A ({ha}):** CM550's stack arguments in 2-byte slots. `ApplyFunctionDefinitions` places each parameter\n"
     "  itself (custom storage) from the new `stack_parameter_layout.csv`, so the 125 `in_stack_` tokens are gone and the\n"
     "  calls show their arguments. CM848's output is unchanged.\n"
     f"- **Stage B ({hb}):** two firmware/CLAUDE.md corrections.\n"
     f"- **Stage C ({hc}):** wave 2 - rows for 58 more functions, proposed and verified by a workflow.\n"
     "\n## Test plan\n")
edit(pr, "- **Beyond CM848 (rounds 72-85):**", "- **Beyond CM848 (rounds 72-86):**")
edit(pr, "- [x] Round 85: B: ", f"- [x] Round 86: C: {proof_c}\n- [x] Round 86: A: {proof_a}\n- [x] Round 85: B: ")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 86: CM550's stack parameters in 2-byte slots (`session_folder/round86/`)\n\n"
       "- **Stage A:** `apply_r86a_rows.py` (the design's wave 0 / 1 rows; `fix_design/` holds its inputs),\n"
       "  `compare_rows.py`, `check_r86a.py` (the design's T3 checks), `caller_census.py` (call-site artifacts before /\n"
       "  after), `placed_vs_survey.py` (each placed prototype against the survey's reads and pushes),\n"
       "  `classify_changes.py`, `remaining_and_hazard.py`, `list_remaining.py`.\n"
       "- **Stage B:** `apply_r86b_docs.py`.\n"
       "- **Stage C:** `wave2_summary.py`, `apply_r86c_rows.py`, `applied_r86c.csv`.\n"
       "- **Closing:** `apply_r86_closing.py`, `update_large_tar_r86.sh`.\n")
if "## Round 86:" not in t:
    i = t.index("## Round 85:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 85: the CM550 prefix rule audit (23 renames, 9 spurious records), the Huffman tree struct - open:",
     "round 85: the CM550 prefix rule audit (23 renames, 9 spurious records), the Huffman tree struct; round 86: CM550's "
     "stack parameters in 2-byte slots (custom storage, 120 placed prototypes) - open:")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
for name, pat, rep in (("MEMORY.md", r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)"),
                       ("pr53_egr_flow_delay_rounds.md", r"is still OPEN on 2026-11-24\n\(\d+ commits\)",
                        f"is still OPEN on 2026-11-24\n({count} commits)")):
    p = M + name
    s = open(p).read()
    s2 = re.sub(pat, rep, s)
    assert f"{count} commits" in s2, name
    open(p, "w").write(s2)
log = M + "pr53_egr_flow_delay_rounds.md"
s = open(log).read()
note = ("- Round 86 (CM550 passes byte / word stack arguments in 2-byte slots: ApplyFunctionDefinitions places each "
        "parameter itself (CUSTOM_STORAGE) when the firmware has output/stack_parameter_layout.csv - CM848 has none, "
        "its output unchanged; in_stack tokens 125 -> 0; a function with a gap / unknown row is skipped with an Error; "
        "never retype a placed parameter in local_variables.csv; wave 2 workflow: 58 more functions)\n")
if "- Round 86 (" not in s:
    open(log, "w").write(s.rstrip("\n") + "\n" + note)
print("round 86 closing applied")
