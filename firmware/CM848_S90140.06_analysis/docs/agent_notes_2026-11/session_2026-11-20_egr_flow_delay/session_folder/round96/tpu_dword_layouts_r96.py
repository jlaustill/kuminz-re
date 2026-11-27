"""Round 96 stage B, part 2 (CM848): the TPU channel blocks whose code moves two parameters with one 32-bit access get
a layout with that dword, so the accesses render as fields instead of pieces (._8_4_ / ._6_4_):
- tpu3_period_accumulator_parameters_t (TPU-B channels 1 / 2 / 9 / 14: the turbocharger speed, vehicle speed, radiator
  fan speed and transmission output speed sensors): PARAM4-5 is one dword, the accumulated period that each speed sensor
  interrupt handler copies and then clears (the fan and output shaft handlers clear only its upper word, which renders as
  the dword's upper piece). Replaces tpu_b_channel_14_parameters_t, a copy of the generic layout.
- tpu_a_channel_4_parameters_t (TPU-A channel 4, the injector driver channel): PARAM3-4 is one dword, the injector
  driver recharge interval that cm848_loadInjectorDriverCalibration writes (the bank cutoff interval while cylinders
  are cut out, else the continuous one).
Idempotent; keeps line endings. usage: tpu_dword_layouts_r96.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
OUT = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 96"
ACC = ("PARAM4-5 read as one 32-bit value: the accumulated period that the speed sensor interrupt handlers copy and then "
       "clear (cm848_radiatorFanSpeedInterruptHandler and mpc555_updateOutputSpeedSensorPeriod clear only its upper word)")
INJ = ("PARAM3-4 written as one 32-bit value by cm848_loadInjectorDriverCalibration: the injector driver recharge interval "
       "(injector_driver_bank_cutoff_recharge_interval while a cylinder is cut out / else "
       "injector_driver_continuous_recharge_interval)")
TYPES = {
    "tpu3_period_accumulator_parameters_t": [("PARAM0", "word", 2, "Channel parameter 0"),
                                             ("PARAM1", "word", 2, "Channel parameter 1"),
                                             ("PARAM2", "word", 2, "Channel parameter 2"),
                                             ("PARAM3", "word", 2, "Channel parameter 3"),
                                             ("accumulated_period", "dword", 4, ACC),
                                             ("PARAM6", "word", 2, "Channel parameter 6"),
                                             ("PARAM7", "word", 2, "Channel parameter 7")],
    "tpu_a_channel_4_parameters_t": [("PARAM0", "word", 2, "Channel parameter 0"),
                                     ("PARAM1", "word", 2, "Channel parameter 1"),
                                     ("PARAM2", "word", 2, "Channel parameter 2"),
                                     ("injector_driver_recharge_interval", "dword", 4, INJ),
                                     ("PARAM5", "word", 2, "Channel parameter 5 (cm848_loadInjectorDriverCalibration writes injector_driver_decay_duration)"),
                                     ("PARAM6", "word", 2, "Channel parameter 6"),
                                     ("PARAM7", "word", 2, "Channel parameter 7")],
}
for fields in TYPES.values():
    assert sum(f[2] for f in fields) == 16
    assert all("," not in f[3] for f in fields)
p = os.path.join(OUT, "structure_definitions.csv")
t = open(p, newline="").read()
E = "\r\n" if "\r\n" in t else "\n"
lines = t.split(E)
if not any(l.startswith("tpu3_period_accumulator_parameters_t,") for l in lines):
    lines = [l for l in lines if not l.startswith("tpu_b_channel_14_parameters_t,")]
    i = max(i for i, l in enumerate(lines) if l.startswith("tpu3_channel_parameters_t,"))
    block = ["", f"# TPU3 channel layouts with a 32-bit parameter pair ({R}): the code moves those two words with one access"]
    for name, fields in TYPES.items():
        block += [f"{name},,{f},{ty},{z},{c},,verified" for f, ty, z, c in fields]
    lines[i + 1:i + 1] = block
    open(p, "w", newline="").write(E.join(lines))
    print("types added; tpu_b_channel_14_parameters_t removed")
p = os.path.join(OUT, "global_variables.csv")
t = open(p, newline="").read()
E = "\r\n" if "\r\n" in t else "\n"
lines = t.split(E)
RETYPE = {"0x00304510": "tpu3_period_accumulator_parameters_t", "0x00304520": "tpu3_period_accumulator_parameters_t",
          "0x00304590": "tpu3_period_accumulator_parameters_t", "0x003045e0": "tpu3_period_accumulator_parameters_t",
          "0x00304140": "tpu_a_channel_4_parameters_t"}
done = 0
for i, l in enumerate(lines):
    a = l.split(",", 1)[0].lower()
    if a in RETYPE:
        parts = l.split(",", 3)
        if parts[2] != RETYPE[a]:
            assert parts[2] in ("tpu3_channel_parameters_t", "tpu_b_channel_14_parameters_t"), l
            lines[i] = f"{parts[0]},{parts[1]},{RETYPE[a]},{parts[3] if len(parts) > 3 else ''}"
            done += 1
open(p, "w", newline="").write(E.join(lines))
print("retyped", done)
