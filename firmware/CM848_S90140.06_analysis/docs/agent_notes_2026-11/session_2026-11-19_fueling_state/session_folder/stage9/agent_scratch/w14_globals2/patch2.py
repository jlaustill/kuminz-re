src = open("/tmp/w14_globals2/spec_data_a.py").read()
old = "holds a smaller value. 65535 after cm848_initFuelDemandTracking. No e2m record here."
new = "holds a smaller value. 65535 after cm848_initFuelDemandTracking. No e2m record."
assert old in src
open("/tmp/w14_globals2/spec_data_a.py", "w").write(src.replace(old, new))
print("ok")
