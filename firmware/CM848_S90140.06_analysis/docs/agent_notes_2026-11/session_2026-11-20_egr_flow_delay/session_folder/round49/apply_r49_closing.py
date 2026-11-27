"""Round 49 closing: task 046, PR body, README, todo, memory. No CLAUDE.md edit. Idempotent (guard: new text present).
usage: apply_r49_closing.py <repo> <pr_body.md> <hash A> <count> <proof>"""
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


T46 = f"""## Done, round 49 (2026-11-22, same PR): unnamed data the code reads, named from table-resolved records

A peer relay started the round; the scripts are in `session_folder/round49/`.
- **Method:** `unnamed_table_reads.py`.
  - The `.cpp` reads 411 unnamed addresses; 34 resolve through the dumped parameter ID table to a default-e2m scalar
    record.
  - Each is graded by its block's consistency, and each access width was checked with `raw_address_scan.py`.
- **Stage A ({ha}, rows, a rename):** 33 rows in their blocks' naming style.
  - Groups: the J1939 torque curve's derated points, the duty cycle monitor, the compressor inlet and coolant states,
    the temperature headroom cap's exhaust limit, the injector continuous recharge interval, four intake air heater
    calibrations, the altitude derate's charge pressure bitmap, engine protection's ramp rate and maximum shutdowns,
    the J1939 NAMEs / security flags / DM4 / fault 111 data, the MIL bitmap, the fault code assignment table, the SCI
    data plate, and the per-cylinder injector maps.
  - Array-sized records reached only by `addi` get a row at their base, with the e2m size in the comment.
  - `fuel_demand_mode_active_flag` -> `charge_saturation_temperature_source` (1982 +A); the new
    `exhaust_saturation_temperature_source` (+C) copies it. This resolves round 47's 1982 +A outlier.
  - Skipped: 0x4086ca (8A14 +30 reaches past 8A2A's base: drift).
- **Proof:** {proof}
- **firmware/CLAUDE.md:** no edit. HARD stays 0 and MISSING 221.
- **Leads:**
  - Full array types for the base-only rows: the NAMEs, the MIL bitmap, the fault code table and the cylinder maps.
    The SCI data plate and the fault code table hold rows inside them.
  - The other 377 unnamed reads do not resolve through the dumped table.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 49.**\n"
     f"- **Stage A ({ha}, rows, a rename):** 33 unnamed addresses the code reads are named from the e2m records the dumped\n"
     "  parameter ID table resolves them to (the J1939 torque curve, intake air heater, engine protection, the J1939\n"
     "  NAMEs, the MIL bitmap, the fault code table, the injector maps, ...).\n"
     "  `fuel_demand_mode_active_flag` -> `charge_saturation_temperature_source`.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 48:", f"- [x] Round 49: {proof}\n- [x] Round 48:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 49: unnamed table-resolved reads (`session_folder/round49/`)\n\n"
       "- `unnamed_table_reads.py` (+ `unnamed_reads.txt`). **Stage A:** `apply_r49a.py`, `map_r49a.csv`, "
       "`prove_r49a.sh`. **Closing:** `apply_r49_closing.py`, `update_large_tar_r49.sh`.\n")
if "## Round 49:" not in t:
    i = t.index("## Round 48:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 48: the OBD cooling monitors - open: the task 046 leads",
     "round 48: the OBD cooling monitors; round 49: 33 unnamed table-resolved reads named - open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "18 new rows, cssc_* gone); task 046 leads"
new = ("18 new rows, cssc_* gone) + round 49 (unnamed_table_reads.py: 33 unnamed reads named from table-resolved e2m "
       "records); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
f = M + "typing_focus_2026_11.md"
note = (f"  - Round 49 (2026-11-22): {ha}. Unnamed DAT_ reads at table-resolved addresses are the cheapest e2m names "
        "(unnamed_table_reads.py): 34 of 411 resolve. Name in the block's own style, type from the access "
        "(raw_address_scan.py).\n")
if "Round 49 (2026-11-22" not in open(f).read():
    open(f, "a").write(note)
print("round 49 closing applied")
