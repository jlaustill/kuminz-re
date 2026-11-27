"""Round 60 closing: task 046 (with round 59's home claims corrected), PR body, README, todo, memory, and two factual
firmware/CLAUDE.md corrections this round verified (the dispatch table's address; the stuck-warning row the typed boot
table resolves). Idempotent.  usage: apply_r60_closing.py <repo> <pr_body.md> <hash A> <count> <proof>"""
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


T = "work/tasks/046-cm848-egr-flow-estimate.md"
edit(T, "  - **Kept as leads:** `param_id_entry_t`, `diag_dispatch_entry_t` and `ef00_dispatch_entry_t` (the untyped tables\n"
        "    at 0x53be38 / 0x539508 / 0x53a9a0).",
     "  - **Kept as leads:** `param_id_entry_t`, `diag_dispatch_entry_t` and `ef00_dispatch_entry_t`. This round gave\n"
     "    them homes at 0x53be38 / 0x539508 / 0x53a9a0; round 60 found their own comments name others (the boot table\n"
     "    0x3F98AC, RAM 0x3FA8B2, RAM 0x3FDB30), and 0x539508 is code.")
edit(T, "  - Type the parameter ID table (`param_id_entry_t`, 1441 records to the end of the flash2 dump) and the two dispatch\n"
        "    tables.",
     "  - Type the parameter ID table (`param_id_entry_t`, 1441 records to the end of the flash2 dump) and the two dispatch\n"
     "    tables. Done in round 60 for the parameter ID tables and the SCI table; the dispatch types' homes differ.")
T46 = f"""## Done, round 60 (2026-11-23, same PR): the parameter ID tables and the SCI command dispatch table typed

A peer relay started the round; the scripts are in `session_folder/round60/`.
- **Stage A ({ha}).**
  - **`parameter_id_entry_t`** (was `param_id_entry_t`: {{word parameter_id, dword address}}). Its own comments named its
    home, the boot kernel's 20-entry table. It now types both tables:
    - `boot_parameter_id_table` (`parameter_id_entry_t[20]` at 0x3f98ac, was `param_id_lookup_table`), with
      `cm848_lookupBootParameterIdAddress` (was `cm848_lookupTableEntryByKey`);
    - the application's `parameter_id_table` (`parameter_id_entry_t[1441]` at 0x53be38) and its hash index
      `parameter_id_table_bucket_start` (`word[1889]`).
  - **`sci_command_dispatch_entry_t`** (new) on `sci_command_dispatch_table` (flash2 0x53a9a0, 19 records).
  - Five type-only pointer rows inside the arrays are gone. `j1939_ack_msg_t` is deleted: its 8 fields equal
    `j1939_acknowledgement_payload_t`'s.
  - `ef00_dispatch_entry_t` / `diag_dispatch_entry_t` are untouched; their documented RAM homes are unverified.
- **Round 59's homes corrected:** its kept types' homes (0x53be38 / 0x539508 / 0x53a9a0) were wrong for two of the
  three, and 0x539508 is code. The round 59 lines above now say so.
- **Proof:** {proof}
- **firmware/CLAUDE.md (factual corrections, verified this round):**
  - the Bank 2 "Command dispatch table" address 0x00539508 -> 0x0053a9a0 (0x539508 is a run of `bl` calls);
  - the stuck-warning row for `_param_id_lookup_table` now records that the typed array applies over the window.
- **Leads:**
  - The real homes of `ef00_dispatch_entry_t` / `diag_dispatch_entry_t`: read `j1939_diagServiceDispatch` and the
    registration code for each table's address and stride.
  - `cm848_lookupBootParameterIdAddress` keeps its `word` parameter and the `CONCAT22` it causes. A wider prototype
    would remove it but could add casts at its three callers (pilot it).
  - 69 unprefixed CM848-only functions remain.

## Leads (not in this PR)"""
edit(T, "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 60.**\n"
     f"- **Stage A ({ha}):** the parameter ID tables and the SCI command dispatch table get their struct types:\n"
     "  `boot_parameter_id_table` / `parameter_id_table` (`parameter_id_entry_t`) with the bucket index, and\n"
     "  `sci_command_dispatch_table` (`sci_command_dispatch_entry_t`). The boot lookup is renamed and `j1939_ack_msg_t`\n"
     "  is removed.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 59:", f"- [x] Round 60: {proof}\n- [x] Round 59:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 60: the parameter ID tables and the SCI dispatch table typed (`session_folder/round60/`)\n\n"
       "- **Stage A:** `check_tables.py`, `apply_r60a.py`, `map_r60a.csv`. Proof: `prove_r60.sh`, `diff_function_r57.py`, "
       "`count_casts.py`. **Closing:** `apply_r60_closing.py`, `update_large_tar_r60.sh`.\n")
if "## Round 60:" not in t:
    i = t.index("## Round 59:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md",
     "round 59: 29 unused struct types removed - open: the task 046 leads",
     "round 59: 29 unused struct types removed; round 60: the parameter ID tables and the SCI dispatch table typed - "
     "open: the task 046 leads")
edit("firmware/CLAUDE.md",
     "- Command dispatch table at 0x00539508 (19 entries, 6 bytes each: command + function pointer)",
     "- Command dispatch table at 0x0053a9a0 (19 entries, 6 bytes each: command + function pointer)")
edit("firmware/CLAUDE.md",
     "| `_param_id_lookup_table` | ROM-to-RAM code region (0x003F9800–0x003FDB30) — Ghidra reverts type on export |",
     "| `_param_id_lookup_table` | Resolved in PR #53 round 60: it is the boot kernel's parameter ID table, now "
     "`boot_parameter_id_table` (a `parameter_id_entry_t[20]` array, which applies over the ROM-to-RAM window) |")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "3 kept as table leads); task 046 leads"
new = ("3 kept as table leads) + round 60 (the parameter ID tables + SCI dispatch table typed: parameter_id_entry_t, "
       "sci_command_dispatch_entry_t); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
f = M + "typing_focus_2026_11.md"
note = (f"  - Round 60 (2026-11-23): {ha}. A template's own '#' comments name its home - read them before assigning one "
        "(round 59 guessed three homes, two wrong). Typing a table as a struct array turned raw *6 arithmetic into "
        "table[i].field in three functions, with fewer casts.\n")
if "Round 60 (2026-11-23" not in open(f).read():
    open(f, "a").write(note)
print("round 60 closing applied")
