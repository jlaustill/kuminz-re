src = open("/tmp/w14_globals2/spec_data_a.py").read()
old = "or the excess injection monitor fault (fault_detected_bits_384_to_399 mask 0x10, fault 388) is set, once until cm848_clearFuelDemandFlag re-arms it."
new = "or the excess injection fault (fault_detected_bits_384_to_399 mask 0x10, fault 388) is set, once until cm848_clearFuelDemandFlag re-arms it."
assert old in src
open("/tmp/w14_globals2/spec_data_a.py", "w").write(src.replace(old, new))
print("ok")
