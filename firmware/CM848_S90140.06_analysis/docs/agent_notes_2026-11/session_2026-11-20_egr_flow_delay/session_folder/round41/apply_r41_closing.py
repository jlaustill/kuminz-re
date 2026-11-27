"""Round 41 closing: task 046, PR body, README, todo, memory. Idempotent.
usage: apply_r41_closing.py <repo> <pr_body.md> <hash A> <commit count>"""
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


T46 = f"""## Done, round 41 (2026-11-22, same PR): the injector driver booster capacitor monitor

A peer relay started the round; the scripts are in `session_folder/round41/`.
- **Stage A ({ha}, types, labels):** `cm848_processFaultScanLookup` is `cm848_monitorInjectorDriverBoosterCapacitorVoltage`.
  - It runs for each cylinder event and checks the cylinder's capacitor (channel 54 / 55) three ways: the high
    threshold (fault 328 / 330), the low threshold (329 / 331), and the low voltage at injection count.
  - **`injector_driver_booster_capacitor_monitor_record_t[2]`** (0x5762c, 52 bytes each, decoded from the ROM) replaces
    12 loose rows; two of them were J1939-named fault numbers.
  - **`injector_driver_booster_capacitor_cylinder_record_t[8]`** (0x57694, was `calibration_constant_1`) holds the
    capacitor index and the four injector circuit faults that skip the cylinder.
  - **The RAM:** the lookup cache, the per-capacitor `word[2]` counts and the per-cylinder `word[8]` counts (were
    `per_cylinder_timing_array` / `_sync_counter` / `_timing_counter`). `injection_check_flags` is
    `injector_driver_booster_capacitor_low_voltage_mask`.
  - The initializer is `cm848_initializeInjectorDriverBoosterCapacitorMonitor` (was mpc555_initSensorCalibrationTables).
- **Proof:** `prove_records.py` maps the old raw addresses and the new struct accesses to field tokens by offset.
  - The monitor has 112 statements on each side, identical apart from its name.
  - The initializer was checked address by address.
  - The other functions match the canonical form or differ in the order of local declarations only.
- **Leads:**
  - The monitor still carries decompiler temps and one goto (Readability Medium).
  - The record's spare count pointer has no reader.
  - `cylinder_event_count_max` (e2m 8194 Engine_Cylinders) keeps its name.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 41.**\n"
     f"- **Stage A ({ha}, types, labels):** the injector driver booster capacitor monitor (was\n"
     "  cm848_processFaultScanLookup): its two ROM record tables typed as struct arrays, its RAM counts as arrays, the\n"
     "  low voltage mask and the initializer named.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 40: every function matches the canonical form or has 0 differing statements",
     "- [x] Round 41: the monitor's 112 statements match field by field (prove_records.py); the other functions match "
     "the canonical form or differ in local declaration order only.\n"
     "- [x] Round 40: every function matches the canonical form or has 0 differing statements")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 41: the injector driver booster capacitor monitor (`session_folder/round41/`)\n\n"
       "- `apply_r41a.py` (the two record types decoded from the ROM, the RAM arrays, the renames), `prove_records.py` "
       "(old raw addresses and new struct fields to one canonical form). **Closing:** `apply_r41_closing.py`, "
       "`update_large_tar_r41.sh`.\n")
if "## Round 41:" not in t:
    i = t.index("## Round 40:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 40: the EEPROM mirror names (MISSING 258 -> 234) - open: the task 046 leads",
     "round 40: the EEPROM mirror names (MISSING 258 -> 234); round 41: the booster capacitor monitor - open: the task "
     "046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "the exhaust brake switch learned flag); task 046 leads"
new = ("the exhaust brake switch learned flag) + round 41 (the injector driver booster capacitor monitor: two ROM "
       "record tables as struct arrays); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
f = M + "typing_focus_2026_11.md"
note = (f"  - Round 41 (2026-11-22): {ha} the booster capacitor monitor's ROM records typed as struct arrays (decode the "
        "record from the ROM dump: pointers show where each field points). A struct array accessed with computed "
        "offsets renders as records[i].field; prove it with a canonicalizer that maps old raw addresses and new "
        "fields to one token by offset (r41/prove_records.py).\n")
if "Round 41 (2026-11-22" not in open(f).read():
    open(f, "a").write(note)
print("round 41 closing applied")
