src = open("/tmp/w14_globals2/spec_data_b.py").read()
old = "(a margin below the maximum throttle fueling; it is 9.99 mm3, no hysteresis)"
if old not in src:
    old = "(a margin below the maximum throttle fueling; it is 9.99 mm3, no hysteresis);"
print(old in src)
old2 = "fuel_correction_hysteresis_cal (a margin below the maximum throttle fueling; it is 9.99 mm3, no hysteresis);"
new2 = "fuel_correction_hysteresis_cal (a margin below the maximum throttle fueling, not a hysteresis band);"
assert old2 in src
open("/tmp/w14_globals2/spec_data_b.py", "w").write(src.replace(old2, new2))
print("ok")
