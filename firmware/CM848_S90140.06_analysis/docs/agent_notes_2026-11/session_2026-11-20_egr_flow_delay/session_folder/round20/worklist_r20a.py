"""Round 20 stage A (label-only): 0x3fd5a2 (EEPROM 0x120) is algorithm enable flags word 3, not a J1939 word. Its e2m
106B +8 records are the cruise control / road speed governor / power take-off / ANC / cruise set speed save enables
(round 19 lead); the code tests bits 0x10 / 0x40 / 0x80 / 0x100 / 0x8000 with masks only (16 lines; the raw scan
finds only loads)."""
GLOBALS = [
    ("0x003fd5a2", "algorithm_enable_flags_3_cal",
     "Algorithm enable flags word 3 (EEPROM 0x120, in the CRC-guarded block; e2m 106B +8): bit 3 Idle_Speed_Adjust_Enable, "
     "4 PTO_Enable, 6 Cruise_Control_Enable, 7 Road_Speed_Governor_Enable, 10 Cruise_RSG_Droop_Enable, 12-14 the ANC "
     "fuel / timing / speed enables, 15 Cruise_Save_Set_Speed_On_Poweroff_Enable; bit 8 has no record (the road speed "
     "governor without droops below top gear). 0xd0 on this truck (PTO, cruise, road speed governor)"),
]
FUNCTIONS = []
