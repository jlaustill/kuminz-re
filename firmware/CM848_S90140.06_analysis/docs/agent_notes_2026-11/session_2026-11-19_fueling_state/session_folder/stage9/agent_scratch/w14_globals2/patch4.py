src = open("/tmp/w14_globals2/spec_data_a.py").read()
old = "The previous final_fueling_state goes to the twin at 0x3feaa0. Never read."
new = "The previous final_fueling_state goes to the twin at 0x3feaa0. Not read by the application."
assert old in src
open("/tmp/w14_globals2/spec_data_a.py", "w").write(src.replace(old, new))
print("ok")
