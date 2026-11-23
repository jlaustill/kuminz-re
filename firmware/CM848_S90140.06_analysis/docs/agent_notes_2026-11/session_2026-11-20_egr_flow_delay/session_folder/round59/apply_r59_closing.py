"""Round 59 closing: task 046, PR body, README, todo, memory. No CLAUDE.md edit. Idempotent.
usage: apply_r59_closing.py <repo> <pr_body.md> <hash A> <hash B> <count> <proof>"""
import os
import re
import sys

repo, pr, ha, hb, count, proof = os.path.abspath(sys.argv[1]), *sys.argv[2:7]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = f"""## Done, round 59 (2026-11-23, same PR): 29 struct types nothing in CM848 uses are removed

A peer relay started the round; the scripts are in `session_folder/round59/`.
- **Stage A ({ha}):** `orphan_struct_types.py` lists every struct type that nothing names: no address row, field,
  dependency, CSV, `.cpp` render, script, test, CLAUDE.md or skill. 32 of the 192 qualified, most from the
  2026-01-30 port of 26 generic CM550 structures.
  - **Superseded (deleted):** `ad_sensor_config_t` / `sensor_fault_config_t` (now `sensor_channel_config_t`),
    `sensor_debounce_state_t` (`sensor_channel_state_t`) and `address_range_entry_t` (`memory_region_t`).
  - **No CM848 home (deleted, 25):** speculative protocol / DMA / patch types, CM550 templates unused there too, and
    three CM550 applies with no CM848 layout. The data plate is not at CM550's EEPROM 0x2C0 here.
    - The last `protection_` field names went with `engine_control_flags_t` and `timing_mode_control_t`.
  - **Kept as leads:** `param_id_entry_t`, `diag_dispatch_entry_t` and `ef00_dispatch_entry_t` (the untyped tables
    at 0x53be38 / 0x539508 / 0x53a9a0).
  - The removed text is archived verbatim with each type's pile (`removed_orphan_types.txt`). CM550 is untouched.
- **Stage B ({hb}): round 58's scan claim corrected.** Round 58's follow-up said `scan_accesses_v2.py` found "2 of
  the 6 stores" to two words. The machine code has exactly 2 stores to each; the decompile prints 6 lines by repeating
  a shared store in each branch's return path. The scan still cannot prove absence (computed pointers; volatile bases
  forgotten at each call), and the seven rows, task 046 and the memory note now say that.
- **Proof:** {proof}
- **firmware/CLAUDE.md:** no edit. HARD stays 0 and MISSING 218.
- **Leads:**
  - Type the parameter ID table (`param_id_entry_t`, 1441 records to the end of the flash2 dump) and the two dispatch
    tables.
  - CM550 keeps unused copies of 18 of the removed types.
  - 69 unprefixed CM848-only functions remain.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 59.**\n"
     f"- **Stage A ({ha}):** 29 CM848 struct types that nothing uses are removed: 4 superseded by live types and 25\n"
     "  with no CM848 home, taking the last `protection_` field names with them. Three are kept as leads for untyped\n"
     "  tables.\n"
     f"- **Stage B ({hb}):** round 58's \"2 of 6 stores\" scan claim corrected (the decompile repeats a shared store).\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 58:", f"- [x] Round 59: {proof}\n- [x] Round 58:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 59: struct types nothing uses (`session_folder/round59/`)\n\n"
       "- **Stage A:** `orphan_struct_types.py`, `apply_r59a.py`, `removed_orphan_types.txt`. **Stage B:** `fix_r59b.py`. "
       "**Closing:** `apply_r59_closing.py`, `update_large_tar_r59.sh`.\n")
if "## Round 59:" not in t:
    i = t.index("## Round 58:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md",
     "round 58: the last protection_* globals - open: the task 046 leads",
     "round 58: the last protection_* globals; round 59: 29 unused struct types removed - open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "the P0116 snapshot; MISSING 218); task 046 leads"
new = ("the P0116 snapshot; MISSING 218) + round 59 (29 struct types nothing in CM848 uses removed; 3 kept as table "
       "leads); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
f = M + "typing_focus_2026_11.md"
note = (f"  - Round 59 (2026-11-23): {ha} / {hb}. 29 orphan struct types removed (orphan_struct_types.py: search the "
        "dependency column, every CSV, scripts, tests, CLAUDE.md files and skills; rerun until stable).\n")
if "Round 59 (2026-11-23" not in open(f).read():
    open(f, "a").write(note)
print("round 59 closing applied")
