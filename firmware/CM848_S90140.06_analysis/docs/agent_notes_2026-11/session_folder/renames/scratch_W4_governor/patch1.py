path = '/home/linux/.claude/jobs/d55ae3c6/tmp/renames/scratch_W4_governor/gen.py'
text = open(path).read()
replacements = [
    ("BOOT = ' Time-shared window: xref_addr.py lists no access below 0x7F60 (no boot users).'",
     "BOOT = ' Time-shared window: xref_addr.py lists no access below 0x7F60 and a raw scan of the 8152 instructions in ROM 0x0-0x7F60 for the displacement finds none (no boot users; the same scan finds the known boot users of 0x3fdba4 / 0x3fdbb2 / 0x3fee34, so it works).'"),
    ("selectSensorRawChannels (0x1f2xx, chooses", "selectSensorRawChannels (0x1fa20, chooses"),
    ("and uses it only through the register; xref_addr.py: 0 reads, 1 write.')",
     "and uses it only through the register; xref_addr.py: no reader (0 reads, 1 write).')"),
    ("with the same value as 0x40a362 (100 when switch_input_state_bits[1] mask 0x10 is set, else 0); write-only (0 reads).')",
     "with the same value as 0x40a362 (100 when switch_input_state_bits[1] mask 0x10 is set, else 0); no reader (write-only, 0 reads).')"),
    ("at the same points as logical output 11 (engage after the request stayed at 50 percent or more for the on-delay, release below 50 percent), 3 writes, 0 reads; enabled",
     "at the same points as logical output 11 (engage after the request stayed at 50 percent or more for the on-delay, release below 50 percent), 3 writes, no reader (0 reads); enabled"),
]
for old, new in replacements:
    if text.count(old) != 1:
        raise SystemExit('replacement not unique or missing: ' + old[:60] + ' count=' + str(text.count(old)))
    text = text.replace(old, new)

extra = '''
N('LABEL CHECK before applying 0x3fb54c: cm848_processProtectionSystemBit3 stores the torque converter lockup state at 0x3fb54e (disassembly: lis 0x40, addi -19122, sth at 0x41428; loads at 0x4157c / 0x41798) and cm848_processFuelEfficiencyTrim counts at 0x3fb54c (addi -19124; lhz 0x42074, sth 0x4207c / 0x4212c), but the .cpp prints the plain name governor_j1939_fuel_input_counter for the 0x3fb54e accesses and the underscore name for the 0x3fb54c ones, and never prints the CSV name tc_lockup_disengage_state of 0x3fb54e (which is the right name for it). The CSV rows are 0x3fb54c governor_j1939_fuel_input_counter and 0x3fb54e tc_lockup_disengage_state, so the .cpp labels look swapped (probably a code unit of the boot kernel image overlapping the data word in the time-shared window). After the rename check how both addresses render; if Bit3 then shows engine_retarder_request_on_delay_counter for the lockup state, the build artifact needs fixing first. No row is proposed for 0x3fb54e.')
N('Skipped on purpose: the type notes of the [W3 governor] leads (j1939_diag_code / 0x3fee34 dword to word, 0x3fee3a word to dword, the 0x3fee3e row) because 0x3fee34-0x3fee3d is time-shared with boot users and no type change is proposed for time-shared words; the oil change monitor offsets note and the engine_power_accumulator_increment_axis / _values axis (no new evidence); the J1939 DB has no SPN list for PGN 65249, so the RC payload bytes got positional names only.')
N('Not renamed in the retarder cluster (listed so they are not lost): governor_cruise_mode_count (0x3fb540), governor_enable_delay_counter (0x3fb54a), governor_cruise_enable_count_cal (0x408e9e) and cruise_rpm_range_low / mid / high_cal (0x408ea6 / 0x408eac / 0x408eae) form the engine speed dependent engage delay chain of cm848_updateEngineRetarderActiveState whose writes to the hold flag are overwritten by the unconditional clear; fuel_demand_rate_minimum_fuel_mode_1_value (0x40a370, only the init writes 0) and engine_idle_cal_valid_flag (0x40a35c, write-only) belong to the same logic; protection_monitored_rpm_threshold_cal (0x408ebc) is the governor mode 4 speed threshold of the enter / exit conditions but what protection_monitored_rpm is was not checked.')
'''
marker = "# ---------------------------------------------------------------------------------------------\n# WRITE + VALIDATE (keep at the bottom)"
if text.count(marker) != 1:
    raise SystemExit('marker missing')
text = text.replace(marker, extra + '\n' + marker)
open(path, 'w').write(text)
print('patched')
