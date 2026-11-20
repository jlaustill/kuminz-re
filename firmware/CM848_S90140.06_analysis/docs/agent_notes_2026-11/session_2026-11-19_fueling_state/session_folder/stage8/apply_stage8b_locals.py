"""Stage 8b, second build: name and type the three stack copies of the gain records in
cm848_calculateFuelMeteringCommand. Ghidra typed local_64 / local_54 as piecewise_linear_gain_t on its own after the
first build; local_44 (the derivative record) stayed undefined1[20], so its call took a (derivative_gain_t *) cast.
usage: apply_stage8b_locals.py <CM848 output dir>"""
import os
import sys

out = sys.argv[1]
ROWS = [
    "0x00047bd0,cm848_calculateFuelMeteringCommand,local_64,working_proportional_gains,piecewise_linear_gain_t,Stack copy"
    " of fuel_pressure_governor_proportional_gains (each gain scaled by its lookup table while"
    " cam_timing_alt_mode_enable_cal is 0) passed to cm848_applyPiecewiseLinearGain",
    "0x00047bd0,cm848_calculateFuelMeteringCommand,local_54,working_integral_gains,piecewise_linear_gain_t,Stack copy of"
    " fuel_pressure_governor_integral_gains (scaled the same way) passed to cm848_integrateWithZoneGain",
    "0x00047bd0,cm848_calculateFuelMeteringCommand,local_44,working_derivative_gains,derivative_gain_t,Stack copy of"
    " fuel_pressure_governor_derivative_gains (scaled the same way; the 4-byte gains are copied as halfwords because they"
    " are not 4-aligned) passed to cm848_calculateFilteredDerivative",
]
path = os.path.join(out, "local_variables.csv")
text = open(path, newline="").read()
assert "\n0x00047bd0," not in text
open(path, "w", newline="").write(text.rstrip("\n") + "\n" + "\n".join(ROWS) + "\n")
print(f"appended {len(ROWS)} local rows")
