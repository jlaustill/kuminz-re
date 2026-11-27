Batch A2 draft (scratch, not a report)

Override priority slots (e2m 12A7, base 0x80bd1a, output N = image bit at 0x80bcf6 + N/8, mask 1 << N%8):
row1  0x80bd23 CSA1PZ  -> cold_start_aid_1_driver_override_priority byte (slot 9, 0x80bcf7 bit 1 relay 2; strobe DRC1RSRQ)
row2  0x80bd24 CSA2PZ  -> cold_start_aid_2_driver_override_priority byte (slot 10, 0x80bcf7 bit 2 relay 3; strobe DRC2RSRQ)
row3  0x80bd20 DGLPPZ  -> warning_lamp_override_priority byte (slot 6, 0x80bcf6 bit 6; lamp_driver_output_bitmask bit 1 = warning lamp)
row4  0x80bd47 DRFSPZ  -> fuel_shutoff_driver_override_priority byte (slot 45, 0x80bcfb bit 5 -> TPU ch13; FSAPFSCO input)  [alt vp44_pump_enable_override_priority]
row5  0x80bd23 DRR2PZ  -> skip (same address as row 1)
row6  0x80bd24 DRR3PZ  -> skip (same address as row 2)
row7  0x80bd27 DRR6PZ  -> ether_start_driver_override_priority byte (slot 13, 0x80bcf7 bit 5 relay 6; strobe DRETRSRQ)
row8  0x80bd1e EPLPPZ  -> engine_protection_lamp_override_priority byte (slot 4, 0x80bcf6 bit 4; bitmask bit 2 = fluids lamp)
row9  0x80bd1c LCL3PZ  -> water_in_fuel_lamp_override_priority byte (slot 2, 0x80bcf6 bit 2; bitmask bit 4 = WIF sensor)
row10 0x80bd20 LCL4PZ  -> skip (row 3)
row11 0x80bd1e LCL5PZ  -> skip (row 8)
row12 0x80bd47 VPENPZ  -> skip (row 4)
row13 0x80bd1c WFLPPZ  -> skip (row 9)

Trip fuel (e2m 1216, base 0x806126; cm550_FUN_000306ca trip update, cm550_accumulatorWithOverflowCarry carries 2^20 remainder counts (2^-23) into a 0.125 count):
row14 0x80612e TID2FU   -> trip_fuel_used_remainder dword
row15 0x806132 TID2ISFU -> trip_idle_fuel_used_remainder dword
row16 0x806136 TID2PTFU -> trip_power_take_off_fuel_used_remainder dword
row17 0x806126 TID2VSFU -> trip_driving_fuel_used_remainder dword
row18 0x80617a TIT2FU   -> lifetime_fuel_used dword (CM848 lifetime_fuel_used_cal)
row19 0x806142 TIT3FU   -> trip_fuel_used dword (CM848 trip_fuel_used_cal)
row20 0x806146 TIT3ISFU -> trip_idle_fuel_used dword (CM848 trip_idle_fuel_used_cal)
row21 0x80614a TIT3PTFU -> trip_power_take_off_fuel_used dword
row22 0x80613e TIT3VSFU -> trip_driving_fuel_used dword

Dump check: 232117 + 11708 + 21 = 243846 = 243847 - 1; remainders 335691 + 753480 + 274071 = 1363242 = 314666 + 2^20.
