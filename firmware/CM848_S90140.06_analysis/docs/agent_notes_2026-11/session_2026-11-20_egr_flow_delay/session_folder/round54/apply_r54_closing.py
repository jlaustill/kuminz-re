"""Round 54 closing: task 046, PR body, README, todo, memory. No CLAUDE.md edit. Idempotent.
usage: apply_r54_closing.py <repo> <pr_body.md> <hash A> <hash B> <count> <proof>"""
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


T46 = f"""## Done, round 54 (2026-11-23, same PR): the last unnamed tables, the stack monitor, legacy boot functions

A peer relay started the round; the scripts are in `session_folder/round54/`.
- **Round 53's disputed matcher hits stay rejected.** Read by meaning, every one contradicts its rows:
  - 8BA4 is a sensor-channel config, but the rows hold temperatures in deg F;
  - 158D would put a reset flag on a word that holds 27136;
  - 1497 / 1498 would put low speed governor droop slopes on code-proven words.
- **Stage A ({ha}, labels, rows, plates):**
  - The ten tables the 2026-11-16 campaign left `WORD_ARRAY_` are named: nine through the parameter ID table
    (turbocharger speed linearization, EGR orifice temperature lead time constant, turbocharger speed derate gain,
    torque management fuel grid) and one lookup cache. No `WORD_ARRAY_` table is left.
  - The application stack (RAM 0x3f9800-0x3f9ff8, r1 = 0x3f9ff8) has a high-water monitor, `cm848_updateStackHighWaterMark`
    (was `bufferManagementWithBounds`, read as a message buffer); its new `stack_headroom_factor_tenths` is 27 in the dump.
  - `cm848_initializeLifetimeDistanceRecordIndex` (was `initSensorTableIndexing`).
  - `test_disasm_tools.py` needed an unnamed table to test the xref tool and none is left; it falls back to a
    type-only word row.
- **Stage B ({hb}):**
  - Five boot-time functions named from their bodies: the rail pressure shortfall limit, the engine oil pressure
    processing, the oil change monitor lookups, the EEPROM calibration identifier update, and the OBD-II service state.
  - The calibration ID characters 4-9 (EEPROM 0x4a-0x4f) are the `byte[6]` row
    `calibration_identifier_characters_4_to_9_cal`.
- **Proof:** {proof}
- **firmware/CLAUDE.md:** no edit. HARD stays 0 and MISSING 221.
- **Leads:**
  - 98 unprefixed CM848-only functions remain, 46 with no plate (`list_unprefixed.py`). The fault manager core at
    0x533aec-0x535270 and the protection cluster at 0x514048-0x514394 are the largest groups; reviewing them all
    is an agent-sized job.
  - `initGovernorFlagsAux` only zeroes 0x3fcfba, which nothing reads directly.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 54.**\n"
     f"- **Stage A ({ha}, labels, rows):** the last ten unnamed tables (nine through the parameter ID table), the\n"
     "  application stack high-water monitor (was read as a message buffer), the lifetime distance record index.\n"
     f"- **Stage B ({hb}):** five legacy boot-time functions named from their bodies; the calibration ID characters 4-9.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 53:", f"- [x] Round 54: {proof}\n- [x] Round 53:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 54: the last unnamed tables, the stack monitor, legacy boot functions (`session_folder/round54/`)\n\n"
       "- `placements.txt` (round 53's disputed hits), `word_arrays.txt`, `list_unprefixed.py` (+ `unprefixed.txt`), "
       "`order_only.py`. **Stage A:** `apply_r54a.py`, `map_r54a.csv`. **Stage B:** `apply_r54b.py`, `map_r54b.csv`. "
       "Proof: `prove_r54.sh`. **Closing:** `apply_r54_closing.py`, `update_large_tar_r54.sh`.\n")
if "## Round 54:" not in t:
    i = t.index("## Round 53:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md",
     "round 53: eleven more blocks by meaning, the coolant temperature derate module - open: the task 046 leads",
     "round 53: eleven more blocks by meaning, the coolant temperature derate module; round 54: the last unnamed tables, "
     "the stack monitor, legacy boot functions - open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "the cold_start_* names were wrong); task 046 leads"
new = ("the cold_start_* names were wrong) + round 54 (no WORD_ARRAY_ table left; the app stack 0x3f9800-0x3f9ff8 "
       "high-water monitor; 5 legacy boot functions); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
f = M + "typing_focus_2026_11.md"
note = (f"  - Round 54 (2026-11-23): {ha} / {hb}. The parameter ID table names tables the 2026-11-16 campaign could not "
        "trace; no WORD_ARRAY_ table is left. 98 unprefixed CM848-only functions remain (46 without a plate).\n")
if "Round 54 (2026-11-23" not in open(f).read():
    open(f, "a").write(note)
print("round 54 closing applied")
