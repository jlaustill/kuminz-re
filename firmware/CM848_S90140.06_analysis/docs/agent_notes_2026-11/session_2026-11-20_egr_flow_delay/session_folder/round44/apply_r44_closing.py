"""Round 44 closing: task 046, PR body, README, todo, memory. No CLAUDE.md edit (no count it states changed).
Idempotent (guard: the new text already present).  usage: apply_r44_closing.py <repo> <pr_body.md> <hash A> <count>"""
import os
import re
import sys

repo, pr, ha, count = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3], sys.argv[4]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = f"""## Done, round 44 (2026-11-22, same PR): round 39's unverified rows, the last typed junk row

A peer relay started the round; the scripts are in `session_folder/round44/`.
- **Stage A ({ha}, labels, a type):** the three rows round 39 left unverified, named from their code, and the typed
  junk row.
  - `governor_override_fuel_decay` is `all_speed_governor_vacuum_cruise_fueling_reduction`. While vacuum-throttle
    cruise is engaged, `cm848_runOperatingModeSpeedGovernor` subtracts it from `all_speed_governor_fueling`, with a
    floor of 0 (44 here).
  - `governor_override_fuel_threshold` is `cruise_accelerator_override_throttle_threshold`. On the accelerator path of
    `cm848_selectCruiseOrUserFueling`, the commanded throttle must be above it (0 here) before the operating mode
    governor takes the fueling from cruise. The function's plate named the wrong operands (`fuel_demand_control`);
    it now names the governor's fuel demand and the commanded throttle.
  - `cruise_speed_target_min` is `accelerator_pedal_single_channel_minimum_idle_threshold`. With the pedal fault
    latched, the demand stays valid only for P2127 (sensor 2, channel 98, low), and only while channel 97's learned
    idle threshold is at least this value (68; the dump holds 78).
  - The typed junk row at 0x3fb52a (`fuel_demand_enable_sync_flag_shadow+2`, `undefined2`) is
    `cruise_control_engaged_flag_previous_arbitration`, a word (lhz / sth). Its falling edge starts the cruise fuel
    ramp-down. Task 045 read it the same way.
  - 0x408e94 gets a documentation row from e2m 118F +0x0C: `cruise_out_of_gear_disable` (1 here). No instruction in
    the ROM or the live flash2 forms its address.
- **Evidence:**
  - The parameter ID table resolves none of the three rows.
  - No record sits at 107D +0x44..+0x49 or 118F +0x0D..+0x11 in any of the 68 e2m files. The search reads the offsets
    as numbers because some files zero-pad them to four digits.
  - The pedal block 0x408a72-0x408a7e lies past the dumped table, and no e2m record describes dual-channel pedal idle
    learning or disagreement.
  - `raw_address_scan.py` (lis + displacement over both images) finds exactly the accesses the `.cpp` shows.
    - Its first run read `cm848_flash2.bin`, which differs from the live image the build uses, and reported a false
      reader of 0x408a76.
  - The dump values agree with ROM through the copy rule.
- **Proof:** `prove_caches.py` matches all 1968 functions. The retype from `undefined2` to `word` changes no statement.
- This resolves round 39's unverified rows, round 43's typed junk row lead, and task 045's 0x3fb52a lead.
- **firmware/CLAUDE.md:** no edit. HARD stays 0 and MISSING 221.
- **Leads:**
  - The oil change monitor's third accumulator. CHR_B2's e2m has an OCM "FOD" accumulator: grams since the last oil
    change, from an rpm x fueling quantity map scaled by an Aux2 start-of-injection factor. CM848's is a 1-D table on
    `main_injection_end_timing`, so the names do not transfer. Its "engine power" name stays unproven.
  - `cruise_out_of_gear_disable` is 1 in the calibration, but no code reads it.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 44.**\n"
     f"- **Stage A ({ha}, labels, a type):** round 39's three unverified rows named from their code (the vacuum cruise\n"
     "  fueling reduction, the cruise accelerator override threshold, the single-channel pedal idle threshold minimum),\n"
     "  the last typed junk row (the previous-pass cruise engaged flag) and a documentation row for e2m\n"
     "  Cruise_Out_Of_Gear_Disable.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 43: the end timing function has 0 differing statements;",
     "- [x] Round 44: label-only proof matches all 1968 functions (the `undefined2` -> `word` retype changes nothing); "
     "a raw lis + displacement scan of both images finds exactly the accesses the `.cpp` shows.\n"
     "- [x] Round 43: the end timing function has 0 differing statements;")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 44: round 39's unverified rows, the last typed junk row (`session_folder/round44/`)\n\n"
       "- **Stage A:** `apply_r44a.py`, `map_r44a.csv`. **Evidence:** `e2m_negatives.py` (+ `e2m_negatives.txt`), "
       "`raw_address_scan.py`, `pedal_records.txt`. **Closing:** `apply_r44_closing.py`, `update_large_tar_r44.sh`.\n")
if "## Round 44:" not in t:
    i = t.index("## Round 43:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 43: the main injection end timing, 30 junk rows - open: the task 046 leads",
     "round 43: the main injection end timing, 30 junk rows; round 44: round 39's unverified rows, the last typed junk "
     "row - open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "+ round 43 (main_injection_end_timing; 30 junk '+N' rows removed); task 046 leads"
new = ("+ round 43 (main_injection_end_timing; 30 junk '+N' rows removed) + round 44 (round 39's 3 unverified rows + "
       "the last typed junk row named from code; raw_address_scan.py); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
f = M + "typing_focus_2026_11.md"
note = (f"  - Round 44 (2026-11-22): {ha}. Scan the images the build uses: cm848_flash2.bin differs from "
        "cm848_flash2_live.bin (the build's), and a raw scan of the wrong one invented a reader. Read e2m offsets as "
        "numbers (some files zero-pad to four digits, so a 1-2 digit regex misses them). refresh_references.py rewrites "
        "an old name inside a new comment unless it sits in a `(was a, b` list.\n")
if "Round 44 (2026-11-22" not in open(f).read():
    open(f, "a").write(note)
print("round 44 closing applied")
