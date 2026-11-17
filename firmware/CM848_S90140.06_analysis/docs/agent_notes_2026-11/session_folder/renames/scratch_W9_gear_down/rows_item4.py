# Item (4): ADC forced-reading enable words and the boot-kernel dispatch table overlay
ROWS = []


def G(address, old, new, evidence, verdict="confirmed", kind="global"):
    r = {"kind": kind, "address": address}
    if kind == "global":
        r["verdict"] = verdict
    if old:
        r["old"] = old
    if new:
        r["new"] = new
    if kind == "new_global":
        r["type"] = "word"
    r["evidence"] = evidence
    ROWS.append(r)


def N(text):
    ROWS.append({"kind": "note", "text": text})


N("[W9 item 4 - how far the boot-kernel table really reaches] PROVEN by scans of ROM and flash 2 (kernscan.py in "
  "scratch_W9_gear_down). cm848_registerDiagnosticService (0x2c94) has exactly 14 call sites in the whole binary and none in "
  "flash 2: ROM 0x398 / 0x3a8 / 0x3bc / 0x3c8 / 0x3d4 (cm848_registerStandardDiagServices: services 2, 7, 11, 16, 24), 0x1934 "
  "(cm848_initService25Handler: 25), 0x19a4 / 0x19b4 / 0x19c4 / 0x19d4 (cm848_initDataBasedDiagServices: 68, 69, 75, 77), 0x1ae8 "
  "(cm848_registerService65Handler: 65), 0x1b14 / 0x1b24 / 0x1b34 (cm848_registerMemoryReadServices: 67, 74, 76); no plain b "
  "targets it. cm848_dispatchDiagnosticService (0x6d24) has one direct call (ROM 0x60f8 in "
  "mpc555_handleJ1939TransportDataPacket); its RAM copy (&DAT_003fc8f4) is also passed to cm848_registerPgnEf00Handler, so it "
  "can additionally run through that registration. The "
  "register function refuses entry 21 (count 0x14, returns true), so the CAPACITY is 20 entries x 5 bytes = 100 bytes, "
  "0x3fdb30-0x3fdb93, and the count byte diag_scan_step_counter 0x3fdb94 follows the table directly; only 14 entries are ever "
  "registered, so the REAL REACH is 14 x 5 = 70 bytes, 0x3fdb30-0x3fdb75 (entry n: service id byte at 0x3fdb30 + 5n, 4-byte "
  "handler pointer at +1, unaligned). Every instruction in ROM 0x0-0x7f5f carrying a displacement 0xdb30-0xdb94 (load / store / "
  "addi / ori / andi forms): ONLY 0x2c98 (addi 0xdb94: the count, register function), 0x2cb4 (addi 0xdb30: the base there), "
  "0x6d3c (addi 0xdb30, dispatch) and 0x6d6c (lbz 0xdb94, the count in dispatch); both functions index the table as base + 5n, "
  "so the kernel makes no constant-offset access into it. Everything else in 0x3fdb30-0x3fdb93 is application data: the RAM "
  "dump window equals the EEPROM image at 0x6ae-0x711 byte for byte (0x3fdb30 = EEPROM 0x6ae; compared all 100 bytes; the count "
  "byte is 0), so in the running application the kernel table is completely overwritten by the EEPROM mirror - the two uses of "
  "the RAM are time-shared, never concurrent.")

N("[W9 item 4 - rows to shrink the overlay, NOT build-verified] ApplyArrays.java takes ONE primitive element type per row "
  "(byte / word / dword / qword / float / double / pointer), so the 5-byte entry cannot be an array element and "
  "structure_definitions.csv needs no row (it has none for this table). ApplyArrays calls clearListing(start, end) over the "
  "whole array and the arrays stage runs LAST (analyze.sh: enums, import, import again, romramthunks, arrays), so the byte[100] "
  "row wipes every named row inside 0x3fdb30-0x3fdb93 - the reason adc_forced_reading_enable_bits_96_to_111_cal prints as "
  "diagnostic_service_dispatch_table._84_2_ - and, sitting after row 59 (switch_input_polarity_bits_cal 0x3fdb8a byte[4], "
  "inside the range), it wipes that array too. EXACT REPLACEMENT of the arrays.csv row 0x003fdb30 (the comment cell has no "
  "commas): 0x003fdb30,diagnostic_service_dispatch_table,byte,10,Reflash-kernel diagnostic dispatch table - only its first two "
  "packed 5-byte entries { byte service_id - void* handler } are typed here because the application's EEPROM mirror words share "
  "the RAM from 0x3fdb3a on; the boot kernel registers 14 entries (70 bytes up to 0x3fdb75; capacity 20 entries = 100 bytes up "
  "to the count byte diag_scan_step_counter 0x3fdb94) in cm848_registerDiagnosticService and scans them in "
  "cm848_dispatchDiagnosticService with a variable index x 5 so the declared length does not matter there. Any length from 10 "
  "to 22 frees every NAMED application word (the lowest one is transmission_temperature_qadc_channel_cal at +22 = 0x3fdb46); "
  "10 stops at the first application word (0x3fdb3a, the QADC index word of slot 97) and leaves 0x3fdb3a / 0x3fdb3c free to be "
  "named later. After the cut these rows print their own names: 0x3fdb46 transmission_temperature_qadc_channel_cal, "
  "0x3fdb78-0x3fdb86 the eight enable words, 0x3fdb88 sensor_validation_startup_accumulator, 0x3fdb8a "
  "switch_input_polarity_bits_cal (the arrays.csv row survives), 0x3fdb8e switch_input_hardware_line_cal, 0x3fdb92 "
  "protection_j1939_mode_enable_flag. The qadc_channel_index_table row (0x3fda78 word[92], ends 0x3fdb2f) needs no change. "
  "Reverse mapping for the label-only proof (the new spelling of the indexed forms depends on how Ghidra rebases a constant that "
  "now has its own symbol, so a build diff is the real check): ._22_2_ -> transmission_temperature_qadc_channel_cal; ._76_2_ -> "
  "adc_forced_reading_enable_bits_32_to_47_cal; ._78_2_ -> adc_forced_reading_enable_bits_48_to_63_cal; ._84_2_ -> "
  "adc_forced_reading_enable_bits_96_to_111_cal; ._98_2_ -> protection_j1939_mode_enable_flag; "
  "diagnostic_service_dispatch_table + k + 0x48 (cpp 34477, 57942, 57956, 57970, 57990; k = (slot >> 4) x 2) -> "
  "adc_forced_reading_enable_bits_0_to_15_cal + k; diagnostic_service_dispatch_table[(param >> 3) + 0x5a] (cpp 51996, 52042) -> "
  "switch_input_polarity_bits_cal[param >> 3]; diagnostic_service_dispatch_table + 2 x param + 0x5e (cpp 51995, 52029) -> "
  "switch_input_hardware_line_cal[param]. WHAT STAYS HIDDEN if the caller instead keeps a 14-entry array (byte[70], the exact "
  "kernel reach): 0x3fdb3a / 0x3fdb3c / 0x3fdb46 (._22_2_) lie INSIDE the 70 bytes, so transmission_temperature_qadc_channel_cal "
  "would still print as diagnostic_service_dispatch_table._22_2_ while the enable words (+72 and up) would render. That is "
  "the caller's decision: exact kernel extent in the declaration, or rendering of the transmission temperature index word.")

N("[W9 item 4 - the enable word family] Layout proof that there are EIGHT words, not seven: the QADC index table is 128 words "
  "(0x3fda78 + 2 x 128 = 0x3fdb78, the first enable word) and sensor_channel_type_table is 128 words (0x3fd948-0x3fda47), so "
  "the enable bits for 128 sensor slots take 8 words, 0x3fdb78-0x3fdb86 (EEPROM 0x6f6-0x704; 0x3fdb88 is a separate word). "
  "Formula (W8, re-checked): enable word = 0x3fdb78 + 2 x (slot >> 4), bit = slot & 15, forced value = "
  "sensor_channel_diag_override[slot] = 0x40bc80 + 2 x slot (that array is already named in the CSV), QADC index word = "
  "0x3fda78 + 2 x slot. The generic readers test the bit for every channel: sensorChannelConfigInit (Bank 2 0x500234; cpp "
  "57942 / 57956 / 57970 / 57990: '(diagnostic_service_dispatch_table + iVar3 + 0x48) & uVar12', then qadc_channel_index_table "
  "or (&sensor_channel_diag_override)[channel_index]) and cm848_processFaultScanLookup (0x35fa8, cpp 34477, slot from the ROM "
  "record word). Constant-offset readers exist only for +76 (cm848_processFuelPressureSensor and cm848_sampleFuelPressureSensor: "
  "bit 2 = slot 34), +78 (cm848_updateFuelPressureDiagnosticCountersAndCheckFeedbackCircuit: bit 15 = slot 63) and +84 (done: "
  "slots 97 / 98 / 103); +72 (heater test and SCI case 10: bit 4 = slot 4) and +80 (SCI case 1: bit 5 = slot 69) are read by "
  "code the W8 agent traced; +74 (0x3fdb7a), +82 (0x3fdb82) and +86 (0x3fdb86) are reached ONLY through the indexed generic "
  "reader (no constant-offset site in the cpp, hence no existing row). All eight are EEPROM-mirror words and 0 in the RAM dump "
  "and the EEPROM image (no forced reading enabled). No user below 0x7F60 (scan above). The rows are word LABELS (the reads "
  "are ushort / lhz); no type of an existing row changes. Whether any channel at slot 112 or above is used was not checked, so "
  "the 8th row (0x3fdb86) rests on the layout alone.")

G("0x003fdb78", "diag_feature_flags", "adc_forced_reading_enable_bits_0_to_15_cal",
  "EEPROM-backed (EEPROM 0x6f6): bit n set = sensor slot n reads its forced value sensor_channel_diag_override[n] instead of the "
  "QADC result; slot 4 (battery voltage, battery_voltage_adc_forced_reading) is bit 0x10. Read by the generic readers (indexed) "
  "and the heater test / SCI case 10. Dump 0. The old row has no comment; the comment of sensor_channel_diag_override names it "
  "'diag_feature_flags' - one more stale mention to refresh.")
G("0x003fdb7a", None, "adc_forced_reading_enable_bits_16_to_31_cal",
  "EEPROM-backed (EEPROM 0x6f8): enable bits of sensor slots 16-31 (bit n = slot 16 + n); reached only through the indexed "
  "generic readers; dump 0.", kind="new_global")
G("0x003fdb7c", "diag_cam_sync_config_flags", "adc_forced_reading_enable_bits_32_to_47_cal",
  "EEPROM-backed (EEPROM 0x6fa): enable bits of slots 32-47; bit 2 (0x4) = slot 34 is tested by "
  "cm848_processFuelPressureSensor and cm848_sampleFuelPressureSensor (cpp 47458 / 47641: ._76_2_ & 4). Dump 0. Nothing to do "
  "with cam sync.")
G("0x003fdb7e", "diag_cam_sync_fault_config_flags", "adc_forced_reading_enable_bits_48_to_63_cal",
  "EEPROM-backed (EEPROM 0x6fc): enable bits of slots 48-63; bit 15 (0x8000) = slot 63, the fuel metering feedback "
  "(cm848_updateFuelPressureDiagnosticCountersAndCheckFeedbackCircuit, cpp 47096: ._78_2_ & 0x8000; forced value "
  "fuel_metering_feedback_adc_forced_reading 0x40bcfe). Dump 0.")
G("0x003fdb80", None, "adc_forced_reading_enable_bits_64_to_79_cal",
  "EEPROM-backed (EEPROM 0x6fe): enable bits of slots 64-79; bit 5 (0x20) = slot 69, battery temperature (SCI case 1 reads "
  "battery_temperature_adc_forced_reading 0x40bd0a unless this bit is clear). No constant-offset access in the cpp. Dump 0.",
  kind="new_global")
G("0x003fdb82", None, "adc_forced_reading_enable_bits_80_to_95_cal",
  "EEPROM-backed (EEPROM 0x700): enable bits of slots 80-95; reached only through the indexed generic readers; dump 0.",
  kind="new_global")
G("0x003fdb86", None, "adc_forced_reading_enable_bits_112_to_127_cal",
  "EEPROM-backed (EEPROM 0x704): enable bits of slots 112-127, the eighth word of the family (the QADC index table is 128 words "
  "and the enable words follow it directly). Proposed from the layout only; dump 0.", kind="new_global")
G("0x003fdb84", "adc_forced_reading_enable_bits_96_to_111_cal", "adc_forced_reading_enable_bits_96_to_111_cal",
  "Name kept (wave 8). Only its comment changes once the array is cut: replace 'read as "
  "diagnostic_service_dispatch_table._84_2_ (0x3fdb30 + 84)' by 'read at 0x3fdb84' and delete 'Hidden by the arrays.csv "
  "byte[100] overlay.'")
