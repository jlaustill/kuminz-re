src = open("/tmp/w14_globals2/spec_data_a.py").read()
old = "Freeze frame in the EEPROM mirror (EEPROM 0x1620): cm848_selectFinalFueling copies"
new = "Freeze frame (EEPROM mirror, EEPROM 0x1620): cm848_selectFinalFueling copies"
assert old in src
src = src.replace(old, new)
old2 = "The previous final_fueling_state goes to the twin at 0x3feaa0. Not read by the application."
new2 = "The previous final_fueling_state goes to the twin 0x3feaa0. Not read by the application."
assert old2 in src
src = src.replace(old2, new2)
open("/tmp/w14_globals2/spec_data_a.py", "w").write(src)
print("ok")
