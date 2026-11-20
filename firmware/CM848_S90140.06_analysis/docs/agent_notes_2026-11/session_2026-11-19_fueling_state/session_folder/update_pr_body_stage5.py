"""Add stage 5 to pr_body.md (summary item, a stage section, the checks bullet, the open items).
usage: update_pr_body_stage5.py <pr_body.md>"""
import sys

path = sys.argv[1]
s = open(path).read()


def replace(old, new):
    global s
    assert s.count(old) == 1, old[:70]
    s = s.replace(old, new)


replace("This PR does four stages:", "This PR does five stages:")
replace("The limiter producers are renamed: altitude derate, air fuel control, net torque, coolant overheat derate.\n",
        "The limiter producers are renamed: altitude derate, air fuel control, net torque, coolant overheat derate.\n"
        "5. **The words behind them.** The power take-off governor's words and the crank routine are named from e2m blocks "
        "that line up by offset. Two flags turn out to mean the opposite of their names: `engine_starting` is the "
        "shutdown command, and `engine_shutdown_active_flag` stops a key-off shutdown. Code 32 is the master / slave "
        "override.\n")

replace("## Checks\n", """## Stage 5: the power take-off words, the crank routine, two backwards flags

- **The power take-off governor's words.** Five e2m blocks line up by offset, with matching units and RAM-dump values:
  - **10AB, the PID terms:** filtered speed error, the proportional / derivative / integral terms, droop, the smoothed reference, the QD / QI / QP gain adjustments (0x80 = 1.0) and the no-load fuel.
  - **109E:** `power_take_off_requested_engine_speed`.
  - **11B4, EEPROM:** remote speeds 2-5 = 1400 / 1600 / 1800 / 2000 rpm, set / resume 1100 rpm, minimum reference 1100 rpm, a 2 mph road speed limit, the remote count limit, the ramp rate.
  - **109D:** the 300-1200 rpm engage window.
  - **10AA, the gains and clamps.** The +-1000 rpm speed-error clamps had their names swapped. The "byte" filter constant is the word coefficient 0.8.
- **The crank routine** (e2m 105E / 105F / 1032). The `cold_start_*`, `fuel_timing_*` and `governor_*` words at 0x40a798-0x40a7be are Cummins' crank words:
  - `crank_exit_speed`: CRANKING ends at it;
  - `crank_fuel`: the CRANKING fuel (it was named an rpm);
  - `crank_reentry_speed`: RUNNING drops to REENTRY at it;
  - the crank tables;
  - the ROM settings at 0x406852-0x40687c, which lose a wrong `_cal`;
  - `engine_stopped_speed` (10 rpm; was `engine_rpm_trigger_cal`), `ecm_power_down_timer_threshold` / `_delay`;
  - `engine_brake_driveline_brake_type_cal` = 1 (retarder), so ENGINE_BRAKE is never entered on this truck.
- **Two flags that read backwards:**
  - `engine_starting` is now `engine_shutdown_command_flag` (e2m 10B1 +12 Shutdown). It forces SHUTDOWN and zeroes the injection and the rail pressure setpoint.
  - `engine_shutdown_active_flag` is now `key_off_shutdown_inhibit_flag`: 1 stops a key-off shutdown. Only J1939 diagnostic service 24 sets it.
  - Their setters are `cm848_commandEngineShutdown` and `cm848_inhibitKeyOffShutdown`.
- **The rest:**
  - the engine start / extended idle / extreme ambient AECD words (e2m `EMO_*_AECD_Active` / `_Cap_EL`);
  - code 32 = `FUELING_STATE_MASTER_SLAVE_OVERRIDE` (e2m MSOVRIDE, `[MSODEN]` "Enable overriding slave Final_Fueling");
  - the stale `CSP_*` state names in 32 comments, now `ENGINE_STATE_*`.
- **How it was done.** A read-only agent mapped the crank routine. Its e2m offsets, code anchors and dump values were re-checked here before anything was applied. The low-confidence words and the i16 retypes are left for later.

## Checks
""")

replace("- Every `FUELING_STATE_` name in the `.cpp` sits on a carrier.\n",
        "- **Stage 5.** All 104 names render with no `_` variant and no OR render. With the names reversed, one line still differs: an `(undefined *)` cast where the power take-off filter record takes the coefficient's address. It comes from the byte → word fix; `cm848_signedFirstOrderFilter` reads the coefficient as `*(short *)`.\n"
        "- Every `FUELING_STATE_` name in the `.cpp` sits on a carrier.\n")

replace("""- Codes 32 (MSOVRIDE) / 37 (T2SPD) / 38 (T2TORQ) / 49 (OFCSTATE) / 50 (AFRSTATE) are still unidentified.
- CM550's FSGVFLST typing.
- The agents' leads that were not applied:
  - the `power_take_off_governor_t` struct and the PTO speed calibrations;
  - `engine_starting` / `engine_shutdown_active_flag`, which may read backwards;
  - the remaining `cold_start_*` crank-routine words.
""", """- Codes 37 (T2SPD) / 38 (T2TORQ) / 49 (OFCSTATE) / 50 (AFRSTATE) are still unidentified.
- CM550's FSGVFLST typing.
- The six power take-off helper functions, including 0x2abc8, which initializes the whole governor.
- The power take-off filter record (0x3fafb2 pointer + 0x3fafb6 state).
- A shared struct for the 16 `cm848_signedFirstOrderFilter` records.
- The i16 retypes of the signed crank words, and the four low-confidence crank words.
""")
open(path, "w").write(s)
print("pr_body.md updated")
