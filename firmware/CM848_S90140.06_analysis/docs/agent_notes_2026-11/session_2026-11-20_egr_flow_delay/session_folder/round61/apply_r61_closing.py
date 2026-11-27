"""Round 61 closing: task 046, PR body, README, todo, memory, and two factual firmware/CLAUDE.md corrections this round's
own rows caused (the MISSING count; where the boot kernel's dispatch table row lives). Idempotent.
usage: apply_r61_closing.py <repo> <pr_body.md> <hash A> <count> <proof>"""
import os
import re
import sys

repo, pr, ha, count, proof = os.path.abspath(sys.argv[1]), *sys.argv[2:6]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = f"""## Done, round 61 (2026-11-23, same PR): both diagnostic service dispatch tables typed

A peer relay started the round; the scripts are in `session_folder/round61/`.
- **Stage A ({ha}).** The two dispatch templates got the homes their own comments named:
  - **`j1939_diagnostic_service_entry_t`** (was `ef00_dispatch_entry_t`) on `j1939_diagnostic_service_table` (RAM
    0x3fa8b2, 32 slots). `cm848_j1939RegisterDiagnosticService` fills it and `cm848_j1939DiagnosticServiceHandler`
    scans it.
  - **`boot_diagnostic_service_entry_t`** (was `diag_dispatch_entry_t`; 5 bytes, handler at offset 1) on the boot
    kernel's `diagnostic_service_dispatch_table` (0x3fdb30). The `arrays.csv` `byte[10]` row became a
    `global_variables.csv` `[2]` row, the same 10 bytes.
  - `cm848_validateJ1939DiagnosticRequest` (was `j1939_diagServiceDispatch`): it checks length and security; it does not
    dispatch.
  - The 15 `j1939_diagService` plates now name the registrar's current name.
  - The three stale `function_definitions.csv` names are synced, so the build's three "Function name mismatch"
    warnings are gone. Later rounds should expect none.
- **Proof:** {proof}
- **firmware/CLAUDE.md (factual corrections, numbers / locations only):**
  - MISSING 218 -> 219 (78 boot-named rows): the boot table's row moved into `global_variables.csv` at a time-shared
    EEPROM-mirror address.
  - The wave 9 note on `diagnostic_service_dispatch_table` now says where the row lives.
- **Leads:** the `j1939_dm1_request_mode_byte` global holds the DM7 request's mode byte, so the name looks wrong; 69
  unprefixed CM848-only functions remain.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 61.**\n"
     f"- **Stage A ({ha}):** both diagnostic service dispatch tables typed (`j1939_diagnostic_service_entry_t` on the\n"
     "  application's 32-slot table, `boot_diagnostic_service_entry_t` on the boot kernel's). The request check is named\n"
     "  `cm848_validateJ1939DiagnosticRequest`, 15 plates are refreshed, and the three stale prototype names are synced,\n"
     "  so the build no longer warns about name mismatches.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 60:", f"- [x] Round 61: {proof}\n- [x] Round 60:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 61: both diagnostic service dispatch tables typed (`session_folder/round61/`)\n\n"
       "- **Stage A:** `apply_r61a.py`, `map_r61a.csv`. Proof: `prove_r61.sh`, `diff_function_r57.py`, `count_casts.py`. "
       "**Closing:** `apply_r61_closing.py`, `update_large_tar_r61.sh`.\n")
if "## Round 61:" not in t:
    i = t.index("## Round 60:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md",
     "round 60: the parameter ID tables and the SCI dispatch table typed - open: the task 046 leads",
     "round 60: the parameter ID tables and the SCI dispatch table typed; round 61: both diagnostic service dispatch "
     "tables typed - open: the task 046 leads")
edit("firmware/CLAUDE.md",
     "MISSING (EEPROM-backed names without `_cal`) is 218 since PR #53 round 58: 121 documentation rows (`name[n]` / "
     "`name.field`, which never end in `_cal`), 77 boot-named and 10 dual-use rows",
     "MISSING (EEPROM-backed names without `_cal`) is 219 since PR #53 round 61: 121 documentation rows (`name[n]` / "
     "`name.field`, which never end in `_cal`), 78 boot-named and 10 dual-use rows")
edit("firmware/CLAUDE.md",
     "The boot kernel's `diagnostic_service_dispatch_table`\n  (`arrays.csv`) is cut from byte[100] to byte[10]",
     "The boot kernel's `diagnostic_service_dispatch_table`\n  (`arrays.csv` then; since PR #53 round 61 a "
     "`boot_diagnostic_service_entry_t[2]` row in `global_variables.csv`, the same 10 bytes) is cut from byte[100] to "
     "byte[10]")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
edit(M + "feedback_cal_suffix_memory_map.md",
     "MISSING is 218 since round 58 (121 documentation rows, 77 boot-named",
     "MISSING is 219 since round 61 (121 documentation rows, 78 boot-named")
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "sci_command_dispatch_entry_t); task 046 leads"
new = ("sci_command_dispatch_entry_t) + round 61 (both diagnostic service dispatch tables typed; the 3 name-mismatch "
       "warnings fixed); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
f = M + "typing_focus_2026_11.md"
note = (f"  - Round 61 (2026-11-23): {ha}. The build's long-standing 3 'Function name mismatch' warnings were stale names "
        "in function_definitions.csv (the importer applies prototypes anyway); they are synced, so a build should now "
        "show none. ApplyArrays maps primitive element types only: a struct array goes in global_variables.csv.\n")
if "Round 61 (2026-11-23" not in open(f).read():
    open(f, "a").write(note)
print("round 61 closing applied")
