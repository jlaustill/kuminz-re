"""Round 11 stage A, the rows apply_hand_worklist.py does not take:
- FUN_0051dfdc has no function_renames.csv row: insert cm848_sciPackOutputStatusWord (split(",", 3) rows: the plate
  takes unquoted commas).
- arrays.csv (quote-aware): the switch_input_state_bits comment gets the e2m 1612 switch map.
usage: apply_r11a_extra.py <repo> <map.csv>"""
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
fr = os.path.join(out, "function_renames.csv")
lines = open(fr).read().split("\n")
assert not any(l.startswith("0x0051dfdc,") for l in lines)
plate = ("Packs the SCI output status word (sci_output_status_word) from three logical output requests: bit 12 = output "
         "4 (wait to start lamp), bit 5 = output 53 (lift pump), bit 6 = output 54 (ASIC_FS_Shutoff_Driver). "
         "cm848_sciHighSpeedReadTableByte calls it, with cm848_sciPackEventHistoryWords, before each table read")
row = f"0x0051dfdc,cm848_sciPackOutputStatusWord,{plate}"
k = next(i for i, l in enumerate(lines) if re.match(r"^0x[0-9a-f]{8},", l) and int(l[:10], 16) > 0x51dfdc)
lines.insert(k, row)
open(fr, "w").write("\n".join(lines))
ar = os.path.join(out, "arrays.csv")
text = open(ar).read()
prefix = "0x0040c050,switch_input_state_bits,byte,4,"
start = text.index(prefix)
end = text.index("\n", start)
old = text[start + len(prefix):end]
assert not old.startswith('"')
MAP = ("e2m 1612 (the debounced discrete inputs; their override priorities are e2m 12A8 at 0x40c058) names each switch: "
       "0 Keyswitch / 1 Lift_Pump_Driver_Feedback / 2 Not_Brake_Switch (cm848_deriveSecondBrakeSwitchSignal) / 3 "
       "PTO_On_Switch / 4 Wait_To_Start_Lamp_Feedback / 5 Engine_Brake_Driver_1_Feedback / 6 "
       "AC_Discrete_Output_Feedback / 7 Idle_Switch / 8 Not_Idle_Switch / 9 and 10 Cold_Start_Aid_1 and 2 "
       "_Driver_Feedback / 11 Brake_Switch / 12 Engine_Brake_Select_1 (the exhaust brake switch) / 13 AC_On_Off_Switch "
       "(cm848_updateAirConditioningSwitchFromPci) / 14 Low_Oil_Switch / 15 Clutch_Switch / 16 and 17 EGR and "
       "VGT_ASIC_Feedback / 19 Remote_PTO_Switch / 20 Transmission_Park_Neutral_Switch / 21 "
       "Transmission_Overdrive_Switch / 22 Transmission_VFS_Battery_Feedback (the transmission relay) / 23 and 24 "
       "Transmission_Overdrive and TCC_Feedback / 25 Cruise_Vent_Feedback / 26 Throttle_Interlock_Switch / 27 "
       "Cruise_Vacuum_Feedback / 28 Cruise_SC_Source_Feedback / 30 TVA_ASIC_Feedback (18 / 29 / 31 have no 11.45 "
       "record). It stays a byte array: three functions update single bits with | / & (switches 2 / 13 / 31), which "
       "Ghidra 12.1 prints as pieces of a bitfield struct (the wave 11 rule)")
new = f'"{MAP} | earlier note: {old}"'
assert old.count('"') == 0
text = text[:start + len(prefix)] + new + text[end:]
open(ar, "w").write(text)
with open(map_path, "a") as f:
    f.write("0x0051dfdc,cm848_sciPackOutputStatusWord,FUN_0051dfdc,function\n")
print("function row inserted; switch map written")
