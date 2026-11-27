"""Round 26 closing (the peer session's cruise review of 69d6f68): task 046, PR body, README, todo. Idempotent.
usage: apply_r26_closing.py <repo> <pr_body.md> <stage A hash>"""
import os
import sys

repo, pr, h = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = f"""## Done, round 26 (2026-11-22, same PR): the peer session's cruise review of 69d6f68

The peer session passed on naming corrections from a read-only cruise review, at the user's request. Every item was
checked in the code before anything was renamed. Scripts are in `session_folder/round26/`.
- **Stage A ({h}, label-only): the cruise vacuum throttle actuator (`cm848_controlCruiseVacuumServo`).**
  - The Chrysler e2m blocks 8C2E (17 calibrations at 0x408daa-0x408dc9) and 8C2F (10 working words at
    0x40b64e-0x40b665) line up with its words by relative offset, and every code use matches its record.
  - So the `fuel_demand_*` / `governor_cycle_*` / `cruise_servo_*` words are `vacuum_throttle_*`: the PID gains,
    the integral clamps and reset, the duty cycle and its clamps / override, the target position (the equivalent
    throttle in cruise), the position error, the vacuum / vent PWM, the PWM period and counter, the deadband, and
    the disabled latch with its threshold, time and counter.
  - The wrong `_cal` on the ROM words went.
  - The latch (`vacuum_throttle_actuator_disabled_flag`, was `governor_cycle_active_flag`) is set on an
    accelerator pedal fault, or after `vacuum_throttle_maximum_error_time` of errors above the threshold with the
    brake off. Only the boot initializer clears it. With `vacuum_throttle_cruise_actuator_disable_mode` = 1 it gives
    cruise denied status 4.
  - Also `cruise_control_engaged_previous_flag` (0x3fb530, was `governor_override_active_prev_flag`): its only
    writer is the end of `cm848_calculateCruiseControlFueling`.
  - Also `cm848_checkCruiseSwitchLearnCondition` (0x512e70, was `governor_cruise_engage_check`): a fresh ON / OFF
    request with the switch ADC in its window, after which its caller sets `cruise_control_switches_learned_flag`.
    The rename gate bans 'press' (the e2m's abbreviation for pressure), so the name avoids it.
- **The vehicle speed path (the review's item 6, checked here):**
  - `cm848_calculateVehicleSpeed` runs unconditionally from `cm848_periodicTaskSet_canTx` and never tests
    `vehicle_speed_sensor_type_cal`. It rewrites `vehicle_speed_unfiltered` from the TPU-B sensor period (0 once the
    pulse timeout expires) and filters that into `vehicle_speed`.
  - `cm848_calculateVehicleSpeedFromOutputShaft` (in `cm848_periodicTaskSet_monitoring`) writes
    `vehicle_speed_unfiltered` from the J1939 output shaft speed only in mode 4
    (`VEHICLE_SPEED_SENSOR_J1939_WITH_GEAR_RATIO`).
  - So the filtered `vehicle_speed` never takes the mode-4 value. Only the direct readers of
    `vehicle_speed_unfiltered` can see it, depending on the task order: the drivetrain ratio, the speed sensor
    monitors, the engine / vehicle speed ratio monitor, PCI OBD, the power down delay and the transmission
    condition flags.
  - The context from the user: the truck runs an Allison LCT1000 on J1939. Transmission type 3 (48RE) is only what
    the ECM is calibrated for.
- **Not done:** the review's item 5. Its claim is that firmware/CLAUDE.md's J1939 input layer notes give the right
  outcome (no cruise code reads the CCVS switches) through the wrong mechanism: `j1939_input_signal_descriptor_table`'s
  third field is the logical switch that `cm848_evaluateJ1939InputSignalFault` sets (brake 11, clutch 15, PTO 3,
  remote PTO 19, interlock 26, the cruise / PTO set-resume fields 31). I did not verify it, and a CLAUDE.md edit
  needs the user's go-ahead rather than a peer request.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 26 (the peer session's cruise review of 69d6f68).**\n"
     f"- **Stage A ({h}, label-only):** the cruise vacuum throttle actuator named from e2m 8C2E / 8C2F (30 words, the\n"
     "  learn check, the previous-pass flag); the vehicle speed path's mode-4 behaviour recorded in task 046.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 25: stage A passes the enum proof",
     "- [x] Round 26: stage A is EQUIVALENT.\n- [x] Round 25: stage A passes the enum proof")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 26: the peer session's cruise review (`session_folder/round26/`)\n\n"
       "- **Stage A:** `worklist_r26a.py` (e2m 8C2E / 8C2F aligned by offset; each record's code use is in its comment), "
       "`map_r26a.csv`. **Closing:** `apply_r26_closing.py`.\n")
if "## Round 26:" not in t:
    i = t.index("## Round 25:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "the boot kernel's response messages - open: the task 046 leads",
     "the boot kernel's response messages; round 26: the cruise vacuum throttle actuator named from e2m 8C2E / 8C2F "
     "(a peer cruise review) - open: the task 046 leads")
print("round 26 closing applied")
