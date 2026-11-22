"""Round 29 closing: task 046, PR body, README, todo. Idempotent.
usage: apply_r29_closing.py <repo> <pr_body.md> <stage A hash>"""
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


T46 = f"""## Done, round 29 (2026-11-22, same PR): the transfer case low-range detector, fault bits from their setters

A peer relay started the round. Scripts are in `session_folder/round29/`.
- **Stage A ({ha}, label-only):**
  - `opposite_words.py` scanned the e2m audit for records whose row name carries the opposite word (min / max, high /
    low, enable / disable ...). It found 29; their code uses settled each one.
  - **The transfer case low-range detector by N/V (e2m 8C5F / 8C60, "Tcase NV"):** the
    `engine_to_vehicle_speed_ratio_*` family is now `transfer_case_*`.
    - The flags: `transfer_case_low_range_flag` (was `..._high_flag`) and `transfer_case_launch_flag` (was
      `..._invalid_flag`).
    - The quantities: the N/V, its average and percent change, and the road speed.
    - The limits; the throttle limit compares `commanded_throttle` (e2m TPS).
    - The three filters and their coefficients.
    - The functions: `cm848_detectTransferCaseLowRange` / `cm848_initializeTransferCaseLowRangeFilters` (was
      `initGovernorTempTableParams`).
    - It runs only with `transmission_type_cal` 0, not in this calibration.
  - **Nine `fault_<n>` bits named from their setters or sensor channel:**
    - 57 / 58 / 59 / 60, the fuel pressure monitors (P1221 / P1222 / - / P1223);
    - 308 `engine_off_time_stuck_error` (e2m Chry_Dat42 = PCI frame 0x42's engine-off time unchanged for N key cycles);
    - 342 / 343, overspeed protection / warning;
    - 682 / 683, channel 101's VGT position sensor bits.
  - **The other hits read correctly:**
    - e2m 8C35 and 1631 name the thresholds by operating region, and the rows name them by check;
    - the misfire load is an upper bound;
    - the pedal count's "minimum" is the learned pedal minimum;
    - the cold-soak coolant limit is a maximum in the code.
- **Leads:**
  - Faults 22 / 23 (they gate an ET1 field), 179 / 180 (they gate EFL/P1 fuel delivery pressure, but which is high
    and which low is not known), 101, 410, 524 and 110 need more reading.
  - The kernel transport's message parameter.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 29.**\n"
     f"- **Stage A ({ha}, label-only):** the transfer case low-range detector named from e2m 8C5F / 8C60 (was the\n"
     "  `engine_to_vehicle_speed_ratio_*` monitor: the low-range flag read as a \"high ratio\" flag, the launch flag as\n"
     "  \"invalid\"). Nine `fault_<n>` bits named from the code that sets them.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 28: stage A is EQUIVALENT;",
     "- [x] Round 29: stage A is EQUIVALENT.\n- [x] Round 28: stage A is EQUIVALENT;")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 29: the transfer case low-range detector, fault bits from their setters (`session_folder/round29/`)\n\n"
       "- **Stage A:** `opposite_words.py` (the scan), `worklist_r29a.py`, `labels_r29a.tsv`, `fault_n_evidence.py` / "
       "`fault_n_context.py` (each bit's setters and readers), `fault_bits_r29a.py`.\n"
       "- **Closing:** `apply_r29_closing.py`.\n")
if "## Round 29:" not in t:
    i = t.index("## Round 28:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 28: the sensor-present flags, the boot CAN ring state - open: the task 046 leads",
     "round 28: the sensor-present flags, the boot CAN ring state; round 29: the transfer case low-range detector, "
     "fault bits from their setters - open: the task 046 leads")
print("round 29 closing applied")
