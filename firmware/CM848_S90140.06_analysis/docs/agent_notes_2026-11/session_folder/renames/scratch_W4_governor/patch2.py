path = '/home/linux/.claude/jobs/d55ae3c6/tmp/renames/scratch_W4_governor/gen.py'
text = open(path).read()


def sub(old, new):
    global text
    if text.count(old) != 1:
        raise SystemExit('not unique / missing (%d): %s' % (text.count(old), old[:90]))
    text = text.replace(old, new)


# (a) 0x3fb54c boot user
sub("so the labels look swapped in the .cpp.' + BOOT)",
    "so the labels look swapped in the .cpp. BOOT USER (time-shared window): mpc555_diagService25_executeFunction (ROM 0x1840, boot ROM, .cpp line 1132) calls the kernel image function at RAM 0x3fb54c (ROM 0x597c) and the .cpp renders that call with this name; the application uses the same address as a data word. xref_addr.py lists only that call (0r/0w) and a raw scan of ROM 0x0-0x7F60 finds no load or store of the address.')")
# (b) label check note
sub("(probably a code unit of the boot kernel image overlapping the data word in the time-shared window)",
    "(the boot kernel image has a function at RAM 0x3fb54c = ROM 0x597c, called from mpc555_diagService25_executeFunction at .cpp line 1132, so the function-image symbol owns the address and the data word renders with the underscore)")
sub("After the rename check how both addresses render; if Bit3 then shows engine_retarder_request_on_delay_counter for the lockup state, the build artifact needs fixing first. No row is proposed for 0x3fb54e.",
    "After the rename expect the boot call at .cpp line 1132 and the 0x3fb54e lockup accesses of cm848_updateEngineRetarderEnableState to print the new name (they print the old name now); if that is not acceptable keep the old name for this row or fix the label mapping first. No row is proposed for 0x3fb54e. Whole-window check: of the 51 window rows only 0x3fb54c has a call by name or func_ / FUN_ label in the .cpp; the raw boot ROM scan found no load or store of any of the 51 addresses.")
# (c) coefficient rows
sub("""for address, old, new, text in SETS:
    G(address, old, new, 'xref_addr.py and the .cpp (cm848_processTorqueLimitTiming / selectSensorRawChannels): ' + text)""",
    """def keep_filter_row(new):
    return (new.startswith('fuel_demand_filter_coefficient_4') or new in ('fuel_demand_filter_coefficient_pointer', 'fuel_demand_filter_input_gain', 'fuel_demand_filter_output_upper_limit', 'fuel_demand_filter_output_lower_limit', 'fuel_demand_filter_output'))


for address, old, new, text in SETS:
    if keep_filter_row(new):
        G(address, old, new, 'xref_addr.py and the .cpp (cm848_processTorqueLimitTiming / selectSensorRawChannels): ' + text)
    else:
        G(address, old, None, 'Left uncertain: ' + text + ' Coefficients 1 to 3 scale injection timing compensation terms, not the filter, so the fuel demand filter wording is unproven; scheme if the domain is confirmed: ' + new + '.', verdict='uncertain')""")
sub("""for address, old, new, text in CACHES:
    G(address, old, new, 'lookupTableInterpolation first argument in cm848_processTorqueLimitTiming: ' + text + '.' + BOOT)""",
    """for address, old, new, text in CACHES:
    if new.endswith('_snapshot'):
        G(address, old, new, 'cm848_processTorqueLimitTiming / cm848_calculateTimingCompensation: ' + text + '.' + BOOT)
    else:
        G(address, old, None, 'Left uncertain: lookupTableInterpolation first argument in cm848_processTorqueLimitTiming, ' + text + '; it belongs to a coefficient 1 to 3 scale lookup, scheme if the domain is confirmed: ' + new + '.' + BOOT, verdict='uncertain')""")
sub("The renames below only spell out coeff -> coefficient and ema -> filter, keeping",
    "The confirmed rows are the filter itself (coefficient 4, the coefficient pointer, input gain, output limits, output, snapshot) and the five injection_timing_compensation_* rows; the coefficient 1 to 3 rows are left uncertain with the planned scheme fuel_demand_filter_coefficient_<n>_<base|working|alternate|scaling_enable|scale_axis|scale_values|scale_cached_axis_offset>, which spells out coeff -> coefficient and ema -> filter and keeps")
# (d) 0x408a84 evidence
sub("Medium confidence for the name: the block purpose is certain, how the other readers use it was not read.",
    "cm848_fuelDemandFinalCalculation uses the single pedal path (cm848_fuelDemandBaseCalculation) when it is 0 and governor_speed_demand_limit_prev, the dual channel demand, when it is nonzero; cm848_selectSensorValuesInUse tests fault bit 348 (P2123, channel 97) for the pedal position substitute when it is 1 and the single pedal fault bit otherwise.")
# (e) function B
sub("the exact latch rule of function B was not read line by line, only its access pattern (same counts as function A).",
    "function B read in full: set when the stage 2 counter reaches limit_b and cleared when it returns to 0, exactly as in function A.")
sub("Inputs of the two instances (protection_confirm_active_a 0x40b060 for A) were not renamed.",
    "Function B was read in full and has the identical structure (stage 1 input protection_confirm_active_b 0x40b09e, stage 2 up / down input protection_condition_active_flag, the same two limits, match flag, snapshot and latched flag). The inputs of the two instances (protection_confirm_active_a 0x40b060 for A, protection_confirm_active_b 0x40b09e for B) were not renamed.")
# (f) mode 7 wording
sub("sets engine_operating_mode = 7 only when engine_operating_mode == 0 and variable_speed_governor_selected_flag == 1",
    "holds the one literal assignment engine_operating_mode = 7 (other writers take the mode as a parameter), made only when engine_operating_mode == 0 and variable_speed_governor_selected_flag == 1")
# (g) group4 evidence
sub("Only written (2) by cm848_initEngineOperatingMode area code at .cpp line 9885; no lookup in the file passes it and xref_addr.py finds no other access, so it stays unnamed.",
    "Only written (2) by cm848_initLookupTableParams (xref_addr.py: 0 reads / 1 write, .cpp line 9885); no lookup in the file passes it and no other access exists, so it stays unnamed.")
sub("Only written (2) next to 0x3fa114; no reader found.",
    "Only written (2) by cm848_initLookupTableParams next to 0x3fa114; no reader found.")
# (h) pedal demand plate + new row
sub("as the idle-corrected reading of the healthy channel (0 when both have a circuit fault, the lower of the two when they disagree) times 400",
    "as the idle-corrected reading of channel 97 (channel 98 when channel 97 has a circuit fault, 0 when both have one; during a disagreement without a latched fault the lower of the two, or 0 when accelerator_pedal_disagreement_zero_demand_enable is set) times 400")
sub("G('0x00408a85', 'cruise_speed_offset_enable_cal', 'accelerator_pedal_compare_relative_to_idle_flag',",
    "G('0x00408a88', 'cruise_active_limit_enable_cal', 'accelerator_pedal_disagreement_zero_demand_enable',\n  'Read once in cm848_calculateAcceleratorPedalDemandFromChannels: with a disagreement and no latched circuit fault, 0 selects the lower of the two readings and a nonzero value selects demand 0. ROM address, so the _cal goes.')\nG('0x00408a85', 'cruise_speed_offset_enable_cal', 'accelerator_pedal_compare_relative_to_idle_flag',")
open(path, 'w').write(text)
print('patched 2')
