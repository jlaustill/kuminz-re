# A2 skeptic draft (scratch)

Verified from scratch:
- resolver: all 16 addresses resolve to the cited records (12A7 +2/+4/+6/+9/+A/+D/+2D, 1216 +0/+8/+C/+10/+18/+1C/+20/+24/+54).
- names: 0 hits each in CM550 global_variables.csv; trip_drive_fuel_used(_remainder) also 0.
- widths: every cited byte sequence matches the ROM (checkbytes.py, checkbytes_trip.py). Slots: tst.b/clr.b d16(a3|a2) with a3/a2 = #0x80bd1a. Trip: clr.l / pea into the 32-bit helper at 0x303d4 (add.l / cmpi.l #0x100000 / lsr.l #20 / sub.l). No overlapping _DAT_ word access on any slot.
- dumps: slots all 0 (ext RAM); trip values match; partition exact in 2^-23 units (255692426538 both).
- lamp identity: cm550_FUN_00021920 (DM1 PGN 65226 / DM2 lamp byte): output 6 -> 0x04 amber warning, output 4 -> 0x40 MIL + 0x01 protect, output 1 -> 0x10 red stop.
- ether start: aux_driver_ether_start diagnostic compares DSFMCHFB / io_driver_port_2_feedback bit 0x20 (output 13) and sets the ether strobe request.
- FSO: 0x1ca54 is one routine (2f0a 247c 0080bd1a ... 245f 4e75); key-off / FSAPFSCO / retarder+0x40 / overspeed+word9 bit 2 clear bit 5, else set.
- drive fuel: other Cummins e2m (74be/74te family, 18 files) name the VS family TRIP_DRIVE_FUEL_USED (TIS1VSFU), TOTAL_DRIVE_FUEL_USED (TIS2VSFU), DELTA_DRIVE_FUEL (TIDCVSFU).

Verdicts:
- 0x80bd23 x2 CONFIRMED cold_start_aid_1_driver_override_priority byte
- 0x80bd24 x2 CONFIRMED cold_start_aid_2_driver_override_priority byte
- 0x80bd20 x2 CONFIRMED warning_lamp_override_priority byte
- 0x80bd47 x2 CONFIRMED fuel_shutoff_driver_override_priority byte (medium; alt vp44_pump_enable_override_priority)
- 0x80bd27 CONFIRMED ether_start_driver_override_priority byte
- 0x80bd1e x2 CONFIRMED engine_protection_lamp_override_priority byte
- 0x80bd1c x2 CONFIRMED water_in_fuel_lamp_override_priority byte
- 0x80612e CONFIRMED trip_fuel_used_remainder dword
- 0x806132 CONFIRMED trip_idle_fuel_used_remainder dword
- 0x806136 CONFIRMED trip_power_take_off_fuel_used_remainder dword
- 0x806126 AMENDED trip_drive_fuel_used_remainder dword (was trip_driving_...)
- 0x80617a CONFIRMED lifetime_fuel_used dword
- 0x806142 CONFIRMED trip_fuel_used dword
- 0x806146 CONFIRMED trip_idle_fuel_used dword
- 0x80614a CONFIRMED trip_power_take_off_fuel_used dword
- 0x80613e AMENDED trip_drive_fuel_used dword (was trip_driving_...)
