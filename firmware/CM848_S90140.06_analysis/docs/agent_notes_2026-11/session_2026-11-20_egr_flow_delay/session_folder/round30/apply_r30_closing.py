"""Round 30 closing: task 046, PR body, README, todo. Idempotent.
usage: apply_r30_closing.py <repo> <pr_body.md> <stage A hash>"""
import os
import sys

repo, pr, ha = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = f"""## Done, round 30 (2026-11-22, same PR): the watchdog fueling monitor

A peer relay started the round. Scripts are in `session_folder/round30/`.
- **Stage A ({ha}, label-only):**
  - `setter_name_scan.py` flags functions whose name shares no word with the fault bits they set.
  - It found `fuel_quantity_demand_monitor`, which sets fault 388 (e2m Watchdog_Fueling_Error). It is now
    `cm848_monitorWatchdogFueling`, and its initializer `cm848_initializeWatchdogFueling`.
  - The Chrysler e2m blocks name its words, aligned by offset; each word matches its code use:
    - 8A70 at 0x40894c: the duration threshold, the error debounce, the speed threshold, the minimum duration offset;
    - 8B3B / 8B3D: the coolant allowance table.
  - Five of the words had no row.
- **Scans that found nothing to change:**
  - `unit_domain_scan.py`: rows whose name names another domain than their e2m unit. The 5 hits were e2m layout
    drift (8A2B +24, the 8C34 tail, 8A14 from +2C) and a unit oddity.
  - The setter-name scan's 9 other hits were generic or table-driven setters.
- **Leads:**
  - The EC1 (PGN 65251) payload as a struct: 28 bytes, J1939 little-endian, two instances. Its field widths need the
    base-register accesses that `xref_addr.py` does not see, so it needs a pilot build.
  - The fault bits 22 / 23 / 179 / 180 / 101 / 410 / 524 / 110.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 30.**\n"
     f"- **Stage A ({ha}, label-only):** the watchdog fueling monitor (fault 388) and its words named from e2m 8A70 /\n"
     "  8B3B / 8B3D; it was `fuel_quantity_demand_monitor` with five `DAT_` words.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 29: stage A is EQUIVALENT.",
     "- [x] Round 30: stage A is EQUIVALENT.\n- [x] Round 29: stage A is EQUIVALENT.")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 30: the watchdog fueling monitor (`session_folder/round30/`)\n\n"
       "- **Scans:** `unit_domain_scan.py`, `setter_name_scan.py`, `ec1_access_census.py` (the EC1 lead).\n"
       "- **Stage A:** `worklist_r30a.py`, `add_rows_r30a.py`. **Closing:** `apply_r30_closing.py`.\n")
if "## Round 30:" not in t:
    i = t.index("## Round 29:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "fault bits from their setters - open: the task 046 leads",
     "fault bits from their setters; round 30: the watchdog fueling monitor - open: the task 046 leads")
print("round 30 closing applied")
