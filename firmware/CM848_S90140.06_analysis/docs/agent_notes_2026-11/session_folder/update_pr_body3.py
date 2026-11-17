"""PR #50 body: the table-naming campaign."""
import sys

p = sys.argv[1]
t = open(p).read()
anchor = "## Finding for task 022: the J1939 pedal reaches fueling"
add = (
    "13. **Table-naming campaign: 519 of the 564 unnamed lookup tables named** (e081b73 pilot, 973925d main wave).\n"
    "    - **Method:** one agent per bin of reader functions, given each lookup's call, its inputs and the table contents. Each agent named the lookup from its traced input, its traced output and breakpoints converted to units (0.125 rpm, 0.0679 mm³, 0.0488 MPa, 1/64 °F, 0.0159 inHg), or skipped it. A script added the role suffix (`_axis` / `_values`, `_x_axis` / `_y_axis` / `_grid`).\n"
    "    - **Pilot gate:** 4 agents ran first, with the go / no-go criteria written down before any result came back. Two independent agents agreed on the meaning of 11 of 11 lookups in the same bin, and 15 of 15 hand-checked names fit their breakpoints. After that, 16 agents named the rest. Several agents reproduced table outputs from the RAM dump; for example, the stored rail-pressure setpoint 1000 matched an interpolated 999.9.\n"
    "    - **Consistency pass:** sibling families share one vocabulary (`base_map` + `map_1`..`map_4`, and `coolant` / `ambient` / `boost` factor pairs) across `injection_timing_main_*`, `injection_timing_offset_*`, `injection_timing_auxiliary_*`, `injection_quantity_auxiliary_*`, `pilot_quantity_*` and `fuel_pressure_setpoint_*`. Sensor tables are `<sensor>_linearization`, identified by decoded DTCs or the slot table, or `sensor_channel<N>_linearization` with N = the output slot. The three injection events are pilot / main / auxiliary.\n"
    "    - **Proof:** mapping every new name back to its old label gives back the old `.cpp`. The only exception is three functions whose local declarations changed order; they hold the same declarations. `WORD_ARRAY_` labels went from 568 to 47, there are no underscore variants and no new warnings. The audit is clean, the tests pass, `verify` is deterministic, and the headers compile.\n"
    "    - **45 tables stay unnamed** because their input units or output could not be traced.\n"
    "    - **Rename leads for the code around the tables** are in `work/tasks/042`: about 20 wrong-domain functions, for example `cm848_torque_limit_state_update` is the pilot injection quantity and `cm848_boostCompensatedRpmGovernor` is the wastegate duty. Two duplicate global names are listed there too.\n\n")
assert t.count(anchor) == 1
open(p, "w").write(t.replace(anchor, add + anchor))
print("ok")
