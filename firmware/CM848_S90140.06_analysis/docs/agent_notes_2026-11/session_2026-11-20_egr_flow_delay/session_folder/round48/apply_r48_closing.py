"""Round 48 closing: task 046, PR body, README, todo, memory. No CLAUDE.md edit. Idempotent (guard: new text present).
usage: apply_r48_closing.py <repo> <pr_body.md> <hash A> <count> <proof>"""
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


T46 = f"""## Done, round 48 (2026-11-22, same PR): the OBD cooling monitors

A peer relay started the round; the scripts are in `session_folder/round48/`.
- **Stage A ({ha}, labels, rows, types):** two leads from the unread gaps are the two cooling system monitors.
  - **The thermostat monitor (P0128).**
    - 8A8B (22 bytes, tiled between 1901 and 18F1) holds its calibrations. Three records match the rows named from
      code; the other eight are the eight unnamed addresses `cm848_runThermostatMonitor` reads, and they gain names.
    - 8A8C (anchored at its end by 18F0; 11 / 13 records land on named rows) holds its state: two new rows, and three
      `cssc_*` rows renamed into `thermostat_monitor_*`.
  - **The coolant temperature in-range (CTIR) monitor.**
    - 8A9D (20 bytes, tiled into the ROM gap between 1631 and 164A) holds its calibrations: nine new rows, one renamed
      into the family. The test timer's limit `DAT_000642d8` is +A CTIR_Max_Test_Time.
    - 8A9E (+0..+4, a field match) holds its state. `cssc_coolant_monitoring_cycle_count` ->
      `coolant_temperature_sensor_performance_test_timer`.
    - The dumped table's 1632 +4 BIR_Ratio at 0x40b9a2 is drift.
  - **Types:** every signed record is loaded with `lha` and every unsigned one with `lhz`, so the signed ones are
    `i16`. The thermostat calibrations +4 / +6 / +8 are retyped by the same rule.
  - `cssc_` was an invented abbreviation; no row carries it now.
- **Proof:** {proof}
- **firmware/CLAUDE.md:** no edit. HARD stays 0 and MISSING 221.
- **Leads:**
  - The 8A8C / 8A9E state rows still use `word` where the e2m record is signed. Their loads are `lha`, but some are
    pointer-passed (`addi`), so each needs the parameter type checked.
  - The 44 remaining round 47 outliers; the 138 unprefixed function names.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 48.**\n"
     f"- **Stage A ({ha}, labels, rows, types):** the OBD cooling monitors from e2m 8A8B / 8A8C (thermostat, P0128) and\n"
     "  8A9D / 8A9E (coolant temperature in-range). It adds 18 rows (the code read 16 of them unnamed), renames 6\n"
     "  (every `cssc_*` row) and retypes 3 to `i16`.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 47:", f"- [x] Round 48: {proof}\n- [x] Round 47:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 48: the OBD cooling monitors (`session_folder/round48/`)\n\n"
       "- **Stage A:** `apply_r48a.py`, `map_r48a.csv`, the cast-stripped proof (`prove_r48a.sh`). **Closing:** "
       "`apply_r48_closing.py`, `update_large_tar_r48.sh`.\n")
if "## Round 48:" not in t:
    i = t.index("## Round 47:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 47: uncited table rows - open: the task 046 leads",
     "round 47: uncited table rows; round 48: the OBD cooling monitors - open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "1295 uncited / 49 outliers in consistent blocks, 5 fixed); task 046 leads"
new = ("1295 uncited / 49 outliers in consistent blocks, 5 fixed) + round 48 (OBD cooling monitors: thermostat e2m "
       "8A8B/8A8C, coolant in-range 8A9D/8A9E, 18 new rows, cssc_* gone); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
f = M + "typing_focus_2026_11.md"
note = (f"  - Round 48 (2026-11-22): {ha}. Unnamed reads inside a gap (DAT_ tokens) point to the block that fills it "
        "(thermostat 8A8B, CTIR 8A9D); a ROM limit read beside a counter (DAT_000642d8) can pin the block's base. "
        "Matching lha / lhz against the records' S / U signs confirms a placement and gives the i16 types.\n")
if "Round 48 (2026-11-22" not in open(f).read():
    open(f, "a").write(note)
print("round 48 closing applied")
