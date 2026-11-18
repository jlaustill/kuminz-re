# Item (3b): source 16 = the turbocharger speed limiter (e2m Trbo_Spd_Limiter_*); replaces the cold start reading
ROWS = []


def F(address, old, new, plate, evidence, verdict="confirmed"):
    r = {"kind": "function", "address": address, "old": old, "verdict": verdict}
    if new:
        r["new"] = new
    if plate:
        r["plate_comment"] = plate
    r["evidence"] = evidence
    ROWS.append(r)


def G(address, old, new, evidence, verdict="confirmed", kind="global", typ=None):
    r = {"kind": kind, "address": address}
    if kind == "global":
        r["verdict"] = verdict
        if old:
            r["old"] = old
    if new:
        r["new"] = new
    if kind == "new_global":
        r["type"] = typ or "word"
    r["evidence"] = evidence
    ROWS.append(r)


def N(text):
    ROWS.append({"kind": "note", "text": text})


N("[W9 item 3 - source 16 = the TURBOCHARGER SPEED LIMITER (e2m Trbo_Spd_Limiter_*), not a cold start or speed compensation "
  "feature] e2m block match (corroboration; every part also agrees with the code below): the enable is Trbo_Spd_Limiter_Enable, "
  "mask 0x0008 of e2m 0x01106B2C = governor_feature_config_flags 0x3fd5c6 (word n 21 of the enable word mapping "
  "0x01106B02 + 2n = 0x3fd59c + 2n) and the code tests governor_feature_config_flags & 8; the ROM words "
  "Trbo_Spd_Limiter_Eng_Spd_Limit (RPM 0.125, 'engine speed limit to limit turbo speed') / _Max_Temp (DEG_F 1/64, 'algorithm "
  "is disabled above this temperature') / _Max_Time (SEC 0.2, 'can be in effect for this max time as default') / "
  "_Veh_Spd_Threshold (MPH 1/256, 'disabled above this veh spd') at e2m 0x018D7900 / 02 / 04 / 06 = our 0x408d76 / 78 / 7a / 7c "
  "(12800 = 1600 rpm, 4544 = 71 deg F, 227, 256 = 1 mph; e2m = ours + 0x14CEB8A); the RAM words Trbo_Spd_Limiter_Flag / "
  "_Temperature ('value to trigger timer') / _Timer ('time for which the limit is in effect once below temp thres', 0.2 s) at "
  "e2m 0x018D7A00 / 02 / 04 = our 0x40b648 / 4a / 4c (e2m = ours + 0x14CC3B8); and the axes Trbo_Spd_Limiter_Coolant_Temp_Axis "
  "(DEG_F) 0x018D7B00 and Trbo_Spd_Limiter_Time_Table (SEC 0.2) 0x018D7C00 = our 10-point axis 0x408d7e and values 0x408d94. The "
  "e2m axis is the COOLANT temperature, which settles the sensor: sensor_channelGeneric_ram is the coolant temperature channel "
  "state (value 2064 = 32 deg F in the dump against 2052 in coolant_temperature_sensor_value), and faults 16 / 17 / 401 are its "
  "faults, as cm848_selectTransmissionTemperatureInUse already assumes. CODE: initGovernorSpeedControl (0x523858, one call at "
  "boot from cm848_applicationMain, cpp 55598) stores the coolant temperature (1/64 deg F: 1987 = 31 deg F in the dump) in "
  "0x40b64a, sets the flag 0x40b648 and loads the counter 0x40b64c from a 10-point table over that temperature (axis -35 / -20 / "
  "-10 / 0 / 10 / 20 / 35 / 45 / 55 / 70 deg F; values 226 / 173 / 144 / 121 / 101 / 85 / 65 / 54 / 45 / 35; the dump's 71 is the "
  "interpolation at 31 deg F) or from 0x408d7a (227) while the coolant faults are active. governorSpeedCompensation (0x523798, "
  "cpp 7597's callee) counts it down once per call while the engine is at the governor setpoint and clears the flag when "
  "governor_feature_config_flags bit 8 is clear, the start temperature is above 4544 (71 deg F), fault 29 (bit 0x2000 of "
  "fault_detected_bits_16_to_31) is set, transmission_park_or_neutral_flag is 0 (in gear), vehicle_speed_copy is above 256 "
  "(1 mph) or the counter is 0; while the flag is set cm848_selectEngineSpeedLimit applies engine_speed_limit_source_16 as source "
  "16. So after start-up with a coolant temperature at or below 71 deg F, in park or neutral and below 1 mph, the engine speed is "
  "limited to 1600 rpm for 35-226 counts (0.2 s each by the e2m: 7 - 45 s), the colder the longer, to limit the turbocharger "
  "speed. The old names ('governor speed compensation', 'b648') were wrong; 'cold start' alone would also mislead, the limiter "
  "is the turbocharger's. Stale text to refresh after the rename: the comment of 0x408d76 engine_speed_limit_source_16 "
  "('governor_active_flag_b648'); that row's name may stay in the numbered source family or take the e2m spelling "
  "turbocharger_speed_limiter_engine_speed_limit (caller's choice).")
F("0x00523858", "initGovernorSpeedControl", "cm848_startTurbochargerSpeedLimiter",
  "Boot start of the turbocharger speed limiter: stores the coolant temperature in "
  "turbocharger_speed_limiter_start_coolant_temperature, sets turbocharger_speed_limiter_active_flag and loads "
  "turbocharger_speed_limiter_timer from the time table over that temperature (turbocharger_speed_limiter_maximum_time when "
  "the coolant sensor faults 16 / 17 / 401 are active). (was initGovernorSpeedControl)",
  "Read in full (cpp 80944); caller cm848_applicationMain (cpp 55598); e2m Trbo_Spd_Limiter_* block, see the note.")
F("0x00523798", "governorSpeedCompensation", "cm848_updateTurbochargerSpeedLimiter",
  "While turbocharger_speed_limiter_active_flag is set and the engine is at the governor setpoint, counts "
  "turbocharger_speed_limiter_timer down and clears the flag when the enable bit (governor_feature_config_flags bit 8), the "
  "start coolant temperature, fault 29, park / neutral or the vehicle speed condition fails or the timer reaches 0; the engine "
  "speed limit arbitration then stops applying engine_speed_limit_source_16. (was governorSpeedCompensation)",
  "Read in full (cpp, callee of cpp 7597); conditions in the note.")
G("0x0040b648", "governor_active_flag_b648", "turbocharger_speed_limiter_active_flag",
  "Set by cm848_startTurbochargerSpeedLimiter, cleared by cm848_updateTurbochargerSpeedLimiter; while set "
  "cm848_selectEngineSpeedLimit returns early with engine_speed_limit_source_16 (source 16). e2m Trbo_Spd_Limiter_Flag "
  "(0x018D7A00 = ours + 0x14CC3B8) 'indicates Trbo Spd Limiter is active when TRUE'. Dump 1.")
G("0x0040b64a", "governor_speed_compensation_initial_ref", "turbocharger_speed_limiter_start_coolant_temperature",
  "Coolant temperature (1/64 deg F, signed) captured at boot; the limiter only runs while it is at or below "
  "turbocharger_speed_limiter_maximum_coolant_temperature (71 deg F). e2m Trbo_Spd_Limiter_Temperature (+2) 'value to trigger "
  "timer'. Dump 1987 = 31 deg F.")
G("0x0040b64c", "governor_speed_compensation_steps", "turbocharger_speed_limiter_timer",
  "Counts left (0.2 s each by the e2m): loaded at boot from turbocharger_speed_limiter_time_values by the start coolant "
  "temperature (or turbocharger_speed_limiter_maximum_time), decremented by cm848_updateTurbochargerSpeedLimiter. e2m "
  "Trbo_Spd_Limiter_Timer (+4). Dump 71.")
G("0x00408d7e", "governor_speed_compensation_steps_axis", "turbocharger_speed_limiter_coolant_temperature_axis",
  "10 coolant temperatures in 1/64 deg F (signed) after the byte length word 20: -35 / -20 / -10 / 0 / 10 / 20 / 35 / 45 / 55 / "
  "70 deg F. e2m Trbo_Spd_Limiter_Coolant_Temp_Axis. Read only by cm848_startTurbochargerSpeedLimiter. ROM-copied, no _cal.")
G("0x00408d94", "governor_speed_compensation_steps_values", "turbocharger_speed_limiter_time_values",
  "Counts (0.2 s each by the e2m) per axis temperature after the byte length word 20: 226 / 173 / 144 / 121 / 101 / 85 / 65 / 54 / "
  "45 / 35, the colder the longer. e2m Trbo_Spd_Limiter_Time_Table. ROM-copied, no _cal.")
G("0x00408d78", None, "turbocharger_speed_limiter_maximum_coolant_temperature",
  "4544 = 71 deg F (1/64): above this start temperature the limiter ends at once. e2m Trbo_Spd_Limiter_Max_Temp "
  "'algorithm is disabled above this temperature' (+2 of the 0x018D7900 block). Width: xref_addr.py word (1 read / 0 writes, "
  "lha at 0x5237dc), signed. ROM-copied, no _cal.", kind="new_global", typ="i16")
G("0x00408d7a", None, "turbocharger_speed_limiter_maximum_time",
  "227 counts (0.2 s each: 45 s): the default duration, used while the coolant sensor faults are active. e2m "
  "Trbo_Spd_Limiter_Max_Time 'can be in effect for this max time as default' (+4). Width: word (1 read / 0 writes, lhz at "
  "0x5238cc). ROM-copied, no _cal.", kind="new_global")
G("0x00408d7c", None, "turbocharger_speed_limiter_vehicle_speed_threshold",
  "256 = 1 mph at 1/256 mph: above this vehicle_speed_copy the limiter ends. e2m Trbo_Spd_Limiter_Veh_Spd_Threshold "
  "'algorithm is disabled above this veh spd' (+6). Width: word (1 read / 0 writes, lhz at 0x523818). ROM-copied, no _cal.",
  kind="new_global")
