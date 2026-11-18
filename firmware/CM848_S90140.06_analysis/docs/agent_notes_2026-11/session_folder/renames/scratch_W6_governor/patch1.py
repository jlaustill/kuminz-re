p = '/home/linux/.claude/jobs/d55ae3c6/tmp/renames/scratch_W6_governor/gen_W6_governor.py'
s = open(p).read()


def rep(a, b, count=1):
    global s
    assert a in s, 'missing: ' + a[:70]
    s = s.replace(a, b) if count == 0 else s.replace(a, b, count)


# (a) time-shared wording
rep("""TS = ('Time-shared window: xref_addr.py lists no access below 0x7F60 (only application functions at or above 0x1f34c); '
      'the whole-binary scan of ROM and Bank 2 finds no other user of the displacement.')""",
    """TS = ('Time-shared window: xref_addr.py lists only application functions, and a raw displacement scan of ROM and Bank 2 finds no instruction below 0x7F60 (no boot user).')""")
# (b) 0x3fd05a
rep("'Time-shared window: xref_addr.py lists only protectionTimeoutControl (0x525e54), no access below 0x7F60.')",
    "'Time-shared window: xref_addr.py lists only protectionTimeoutControl (0x525e54) and a raw displacement scan of ROM and Bank 2 finds no instruction below 0x7F60 (no boot user).')")
# (c) prefix for the fuel demand counter
rep("fuel_demand_at_minimum_pass_counter", "engine_retarder_fuel_demand_at_minimum_pass_counter", 0)
# (d) 0x408ebc neutral name
rep("""g(0x00408ebc, 'engine_retarder_engine_speed_threshold_governor_mode_4',
  'Code: only user is cm848_updateEngineRetarderEnableState, in the governor fuel demand mode 4 branch: entry needs protection_monitored_rpm <= this, exit when this < protection_monitored_rpm. '
  'protection_monitored_rpm (0x40af40) is the engine speed with hysteresis (cm848_setProtectionParamFromRpm copies current_rpm, cm848_smoothProtectionParamTransition adds / subtracts protection_rpm_hysteresis_cal). '
  'Sibling of engine_retarder_fuel_demand_threshold_governor_mode_4. Dump value 9200 (1150 rpm). ROM address, so the _cal goes.')""",
    """g(0x00408ebc, 'engine_retarder_monitored_rpm_threshold_governor_mode_4',
  'Code: only user is cm848_updateEngineRetarderEnableState, in the governor fuel demand mode 4 branch: entry needs protection_monitored_rpm <= this, exit when this < protection_monitored_rpm. '
  'protection_monitored_rpm (0x40af40) is an rpm x 8 word that is current_rpm (cm848_setProtectionParamFromRpm) or, while governor_fuel_active_flag is 1, follows protection_rpm_reference inside a +-protection_rpm_hysteresis_cal band (cm848_smoothProtectionParamTransition, read in full); '
  'whether it is engine speed or a reference speed is not settled, so the name only says monitored rpm. Sibling of engine_retarder_fuel_demand_threshold_governor_mode_4. Dump value 9200 (1150 rpm). ROM address, so the _cal goes.')""")
# (e) 0x40a370 uncertain
i = s.index("g(0x0040a370,")
j = s.index("g(0x0040a35c,")
s = s[:i] + """g(0x0040a370, None,
  'UNCERTAIN, no name. Code: cm848_selectTemperatureTrimValue sets fuel_demand_rate_min to this while engine_retarder_active_flag is 1 and to mass_charge_flow_combustion_command otherwise; only the init writes it (0), dump 0. '
  'The consumer (.cpp 10140-10185) makes fuel_demand_rate_limited = min(fuel_demand_rate_min, fuel_quantity_ema_filtered - 2 x the rate filter term) while the threshold flags are set and = fuel_demand_rate_min otherwise, so fuel_demand_rate_min is a CAP of a mass charge flow quantity (wave 5 found fuel_quantity_ema_filtered is the charge flow), not a fuel minimum; with the retarder active the cap is 0. '
  'The fuel_demand_rate_* vocabulary itself is domain-suspect, so no name is proposed until that family is re-domained; the old fuel_mode_1 wording has no support in the code.', verdict='uncertain')
""" + s[j:]
# (f) function 0x10874 uncertain
i = s.index("f(0x00010874,")
j = s.index("# ---------------------------------------------------------------------------------------------------\n# B. High speed")
s = s[:i] + """f(0x00010874, None, '',
  'UNCERTAIN, no name. The body is two stores and one test (fuel_demand_rate_min = fuel_demand_rate_minimum_fuel_mode_1_value while engine_retarder_active_flag is 1, else mass_charge_flow_combustion_command); it has no temperature input, so cm848_selectTemperatureTrimValue is wrong, but the role of fuel_demand_rate_min (a cap of a mass charge flow quantity, see 0x40a370) is not settled enough to name it.', verdict='uncertain')

""" + s[j:]
# (g) cache words uncertain
rep("g(0x003fa114, 'unused_lookup_cached_axis_offset_a', UN)",
    "g(0x003fa114, None, 'UNCERTAIN, no name (candidate unused_lookup_cached_axis_offset_a if medium confidence is accepted). ' + UN, verdict='uncertain')")
rep("g(0x003fa116, 'unused_lookup_cached_axis_offset_d', UN)",
    "g(0x003fa116, None, 'UNCERTAIN, no name (candidate unused_lookup_cached_axis_offset_d if medium confidence is accepted). ' + UN, verdict='uncertain')")
rep("'Name keeps the old a / d disambiguator; medium confidence that it is a lookup cache (adjacent group, init value), high that nothing uses it.')",
    "'Medium confidence that it is a lookup cache (adjacent group, init value 2), high that the application never reads or passes it.')")
# (h) dump identities
rep("Dump: P term 2062 = 8000 x 287 / 1113.')",
    "Dump reproduces all three terms and the sum: P 2062 (= 8000 x 287 / 1113) + D 0 + I 117 (= 8000 x 262 / 17809) = 2179 = governor_fuel_demand_threshold_cal.')")
rep("RAM dump check: P term 2062 = error 8000 x adjusted gain 287 / 1113;",
    "RAM dump check: the three terms and the sum are reproduced - P 2062 = error 8000 x adjusted gain 287 / 1113, D 0, I 117 = 8000 x 262 / 17809, sum 2179 = governor_fuel_demand_threshold_cal;")
# (i) gain set plate
rep("""'Selects the high speed governor gain set - error filter coefficient plus proportional, integral and derivative gains - and records its code in fuel_demand_state_code: the base set (code 16) when system_feature_config_flags bit 0 is clear; otherwise a transient set (code 17) while engine acceleration is above DAT_0005c314, and the working set or one of two load dependent sets (codes 18 / 19, base set code 16 between them) once the transient timer has run; it also records the alternate set (was selectSensorRawChannels).',
  'Read from the .cpp body (all four coefficients are always written together with the code); nothing to do with sensor raw channels.')""",
    """'Selects the high speed governor gain set - error filter coefficient plus proportional, integral and derivative gains - and records its code in fuel_demand_state_code: the base set (code 16) when system_feature_config_flags bit 0 is clear; otherwise a transient set (code 17, DAT_0005c32c-0x5c332) while engine acceleration is above DAT_0005c314 and governor_mode_code_prev is not 12, and once the transient time DAT_0005c316 has elapsed the working set (when loaded) or the low / high reference speed set (codes 18 / 19, chosen by torque_limit_load_working against DAT_0005c322 / DAT_0005c318; base set 16 between them); it also records the alternate set (was selectSensorRawChannels).',
  'Read from the .cpp body (all four coefficients are always written together with the code); nothing to do with sensor raw channels. The ROM constants DAT_0005c314 .. 0x5c332 line up offset by offset with the e2m HSG block 0x01129000 (acceleration threshold +0, acceleration time +2, high reference speed threshold +4 then derivative / filter / integral / proportional +6..+0xC, low threshold +0xE then +0x10..+0x16, transient +0x18..+0x1E): corroboration only, but it makes torque_limit_load_working a reference speed.')""")
# (j) preset + pid plates
rep("The integrator is preset to the fuel demand while governor_mode_code is not 12 (cm848_calculateTimingCompensation) and reset when engine speed exceeds the limit plus an offset with governor mode 12 and low fuel demand (was cm848_processTorqueLimitTiming).",
    "The integrator is preset to the fuel demand while governor_mode_code (0x40a2d0) is not 12 (cm848_presetHighSpeedGovernorIntegrator) and reset when engine speed exceeds the limit plus an offset with governor_fuel_demand_mode (0x40a154) 12 and low fuel demand (was cm848_processTorqueLimitTiming).")
rep("'While governor_mode_code is not 12 (the high speed governor does not supply the fuel demand) presets the integrator",
    "'While governor_mode_code (0x40a2d0) is not 12 presets the integrator")
# (k) working-set writer
rep("WK = 'Working set coefficient written by cm848_processSystemStatusLimits (set code 20 / 21), read by selectSensorRawChannels.",
    "WK = 'Working set coefficient written by cm848_processSystemStatusLimits (set code 20 / 21; xref_addr.py lists it as the only writer), read by selectSensorRawChannels.")
# (l) engage-delay note
rep("The branch that sets the hold flag unconditionally on a new request needs governor_system_config_flags bit 4 (value 4); the EEPROM value here is 0x10, so it is off.",
    "The branch that sets the hold flag unconditionally on a new request needs governor_system_config_flags mask 4 (bit 2); the EEPROM value here is 0x10 (mask 0x10 only), so it is off.")
# (m) 0x53cd8 plate
rep("(was cm848_refreshTsc1RequestEntry; the old plate said was cm848_addCoolantCalEntry, which is the name 0x53d3c had).",
    "(was cm848_refreshTsc1RequestEntry; the older plate said was cm848_addCoolantCalEntry).")
# (n) saved block note
rep("(3) NOTHING in ROM or Bank 2 writes the saved block: xref_addr.py shows 0 writes and",
    "(3) No write to the saved block is visible: xref_addr.py lists 0 writes and exactly one reader (the restore function) for each of the 26 words 0x40a216-0x40a246, and")
rep("So the block is a reset-survival image that this firmware only reads (the writer, if any, is outside the application, e.g. an image kept across a warm reset), which is why names must say saved / restored, not fuel trim.",
    "So either the restore path never runs in this build (flag stays 0) or something outside the visible application fills the block (for example a RAM image kept across a warm reset); in both cases the names must say saved / restored, not fuel trim.")
# scope note first
rep("# ---------------------------------------------------------------------------------------------------\n# validation",
    """out.insert(0, {'kind': 'note', 'text': 'SCOPE: seven rows override names applied in wave 4 (global 0x406fba, 0x40a8d1, 0x40a8af, 0x40a8bf, 0x40a8d3, 0x406fbc, 0x40a8c3, all marked CORRECTION: the fuel_demand_filter_* words are the error filter of the high speed governor PID, in the same coefficient set as the lead rows fuel_ema_coeff_1-3); six functions (0x1f40c, 0x1f34c, 0x1fa20, 0x1f98c, 0x422c0, 0x42438) and global 0x40b706 are outside the lead list and are the code and the input of that same block, so the family stays consistent; the rows for 0x40a370, function 0x10874 and 0x3fa114 / 0x3fa116 are uncertain with no new name.'})

# ---------------------------------------------------------------------------------------------------
# validation""")
open(p, 'w').write(s)
print('patched')
