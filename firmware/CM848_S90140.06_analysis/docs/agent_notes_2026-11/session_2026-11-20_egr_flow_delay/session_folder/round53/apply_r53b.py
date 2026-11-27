"""Round 53 stage B (labels / rows / comments; the two new tables are typed rows): the coolant temperature derate
module, e2m CT_Derate_* (blocks 8A71 calibrations, 8A7A / 8A79 tables, 8A72 RAM). Its rows were named for a cold
start, but every one belongs to the overheat derate: the plates of its functions already said so.
  minimum derate (fault 390): coolant above CT_Derate_Max_Allowed_Temp for CT_Derate_Max_Temp_Time; it stops below
      CT_Derate_Halt_Temp after CT_Derate_Halt_Time.
  aggressive derate (fault 389): a level timer (CT_Derate_Timer1-5, time above each CT_Derate_Temp_Axis level) runs
      over its CT_Derate_Time_Table limit; it stops after CT_Derate_Agg_Stop_Time below CT_Derate_Agg_Stop_Temp.
  The PI loop (CT_Derate_Prop_Gain / Int_Gain) and the check-gauges / chime requests (CT_Derate_Check_Gages / _Chime,
  read by cm848_updateEngineWarningFlags).
8A71 at 0x40874e: 16 records - 9 on rows, 7 accessed with no row (each access has the record's width and sign:
lwz / lha / lhz). With 8A7A at 0x408770 and 8A79 at 0x40877c (byte-length word 10, then five words each) it tiles
0x40874e-0x408787 up to the next row. The lifetime totals (8A73) at 0x3fee04 are time-shared with the boot kernel's
eeprom_shadow_header and stay untyped.
Idempotent.  usage: apply_r53b.py <repo> <map.csv>"""
import os
import re
import sys

sys.path.insert(0, "/home/linux/.claude/jobs/374b0424/tmp/w15/r53")
from e2m_cite import Records, Rows, place  # noqa: E402

repo = os.path.abspath(sys.argv[1])
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
records = Records(repo)
rows = Rows(repo, "PR #53 round 53")
if "coolant_overheat_aggressive_derate_reference_temperature" in rows.names:
    print("already applied")
    sys.exit(0)
AGG = "cm848_monitorCoolantOverheatAggressiveDerate"
MIN = "cm848_monitorCoolantOverheatMinimumDerate"
ACC = "cm848_accumulateCoolantOverheatLevelTimers"
PI = "cm848_calculateCoolantOverheatPiFuelLimit"
RENAMES = {
    # 8A71: the aggressive derate's calibrations, and the one 'temp' abbreviation
    "0x00408750": ("cold_start_coolant_bucket_overheat_setpoint", "coolant_overheat_aggressive_derate_reference_temperature",
                   f"{AGG} sets engine_overheat_derate_coolant_temperature_setpoint to it when a level timer runs over "
                   "its limit"),
    "0x00408752": ("cold_start_coolant_bucket_recovery_temp_threshold", "coolant_overheat_aggressive_derate_stop_temperature",
                   f"{AGG} counts coolant_overheat_aggressive_derate_stop_count while the coolant is below it"),
    "0x00408754": ("cold_start_coolant_bucket_recovery_count_limit", "coolant_overheat_aggressive_derate_stop_time",
                   f"{AGG} ends the aggressive derate (fault 389 / reason 6) once coolant_overheat_aggressive_derate_"
                   "stop_count reaches it"),
    "0x0040876c": ("coolant_overheat_temp_threshold", "coolant_overheat_maximum_allowed_temperature",
                   f"{MIN} starts the minimum derate (fault 390 / reason 3) after coolant_overheat_debounce_count_limit "
                   "passes above it and makes it the derate setpoint (the old name used the abbreviation 'temp')"),
    # 8A72: the derate's RAM
    "0x0040b22e": ("coolant_bucket_overheat_detected_flag", "coolant_overheat_check_gauges_flag",
                   f"Set by {AGG} with the aggressive derate; cm848_updateEngineWarningFlags ORs it with "
                   "low_oil_pressure_active_flag into coolant_overheat_or_low_oil_pressure_flag (the check gauges lamp)"),
    "0x0040b230": ("coolant_bucket_overheat_active_flag", "coolant_overheat_chime_flag",
                   f"Set by {AGG} when level timer 5 runs over its limit or the aggressive derate outlasts "
                   "coolant_overheat_aggressive_derate_active_time_limit above the reference; its rising edge loads "
                   "warning_chime_countdown in cm848_updateEngineWarningFlags (the twin of low_oil_pressure_chime_flag)"),
    "0x0040b236": ("cold_start_fuel_demand_integral", "coolant_overheat_pi_integral_fuel",
                   f"{PI}: coolant_overheat_pi_integral_accumulator / 0x2280, clamped between coolant_overheat_fuel_floor "
                   "and throttle_100_fueling"),
    "0x0040b23c": ("cold_start_fuel_demand_proportional", "coolant_overheat_pi_proportional_fuel",
                   f"{PI}: coolant_overheat_temperature_error x coolant_overheat_pi_proportional_gain / 0x2580"),
}
NEW_ROWS = {
    "0x0040874e": ("coolant_overheat_aggressive_derate_active_time_limit", "word",
                   f"{AGG}: with coolant_overheat_aggressive_derate_active_time above it and the coolant above "
                   "coolant_overheat_aggressive_derate_reference_temperature, coolant_overheat_chime_flag is set (lhz)",
                   "DAT_0040874e"),
    "0x00408756": ("coolant_overheat_recovery_temperature", "i16",
                   f"{MIN} counts coolant_overheat_recovery_count while the coolant is below it (lha; a signed record)",
                   "DAT_00408756"),
    "0x0040875a": ("coolant_overheat_pi_integral_gain", "dword",
                   f"{PI} adds this x coolant_overheat_temperature_error to coolant_overheat_pi_integral_accumulator "
                   "each pass (lwz)", "DAT_0040875a"),
    "0x00408764": ("coolant_overheat_pi_proportional_gain", "word",
                   f"{PI}: coolant_overheat_pi_proportional_fuel = coolant_overheat_temperature_error x this / 0x2580 "
                   "(lhz)", "DAT_00408764"),
    "0x00408766": ("coolant_overheat_level_timer_reset_temperature", "i16",
                   f"{ACC} counts coolant_overheat_level_timer_reset_count while a level timer is nonzero and the "
                   "coolant is below it (lha; a signed record)", "DAT_00408766"),
    "0x00408768": ("coolant_overheat_level_timer_reset_time", "word",
                   f"{ACC}: past it the level timers are added into the lifetime totals (e2m 8A73, EEPROM mirror "
                   "0x3fee04 + 4 x level) and cleared (lhz)", "DAT_00408768"),
    "0x0040876a": ("coolant_overheat_derate_skip_temperature", "i16",
                   "cm848_runCoolantOverheatFuelDerate skips the derate while the coolant is below it (lha; a signed "
                   "record)", "DAT_0040876a"),
}
for block, base, note, elsewhere in (
        (0x8A71, 0x40874e, " The 8A71 layout (16 records) matches 0x40874e-0x40876f: 9 records on rows and 7 accessed "
                           "with the record's width and sign (lwz / lha / lhz); 8A7A and 8A79 follow", ()),
        (0x8A72, 0x40b22c, " The 8A72 layout (17 records) matches 0x40b22c-0x40b257; CT_Derate_Timer1-5 (+14..+24) are "
                           "the arrays.csv row coolant_overheat_level_timers",
         {0x40b240 + 4 * k for k in range(5)})):
    missing = place(records, rows, block, base, RENAMES, NEW_ROWS, note, elsewhere)
    if missing:
        print(f"{block:04X}: no row for {missing}")
# ---- the two tables (byte-length word then five words, the CSV convention for tables) ------------------------------
rows.add_text("0x00408770", "coolant_overheat_level_temperature_axis", "word[6]",
              "e2m 8A7A +0 CT_Derate_Temp_Axis 'Coolant Temp Derate' (DEG_F, signed, 0.015625 per count; a T table): the "
              "byte-length word (10) then the five coolant levels 18560 / 14720 / 15232 / 15552 / 15808 = 290 / 230 / 238 "
              f"/ 243 / 247 deg F in ROM. {ACC} steps a pointer from here and counts coolant_overheat_level_timers[i] "
              "while the coolant is above level i. 8A79's time table follows at 0x40877c", None)
p = rows.row("0x0040877e")
assert p[1] == "cold_start_coolant_bucket_thresholds" and p[2] == "word[5]"
rows.rename(records, "0x0040877e", "cold_start_coolant_bucket_thresholds", "coolant_overheat_level_time_limits", 0x8A79, 0,
            f"The five values after the table's byte-length word at 0x40877c (50 / 18000 / 12000 / 3000 / 50): {AGG} "
            "starts the aggressive derate when coolant_overheat_level_timers[1-4] passes its limit and sets "
            "coolant_overheat_chime_flag on timer 5")
# ---- RAM words outside the e2m blocks ---------------------------------------------------------------------------------
for a, cur, new, text in (
        ("0x003fcddc", "cold_start_fuel_demand_integral_q8_scaled", "coolant_overheat_pi_integral_accumulator",
         f"{PI}: starts at final_fueling x 0x2280 when the derate starts, adds coolant_overheat_pi_integral_gain x the "
         "temperature error each pass; coolant_overheat_pi_integral_fuel = this / 0x2280 (the scale is 0x2280, not a Q8)"),
        ("0x003fcdcc", "cold_start_coolant_overheat_event_count", "coolant_overheat_aggressive_derate_active_time",
         f"Passes {AGG} finds a level timer over its limit (+1 each pass while the aggressive derate holds, cleared when "
         "it stops); compared with coolant_overheat_aggressive_derate_active_time_limit"),
        ("0x003fcdce", "sensor_overheat_recovery_count", "coolant_overheat_aggressive_derate_stop_count",
         f"Passes below coolant_overheat_aggressive_derate_stop_temperature while fault 389 is set ({AGG}); zeroed "
         "above it, ends the aggressive derate at coolant_overheat_aggressive_derate_stop_time"),
        ("0x003fcdb4", "coolant_bucket_overheat_active_flag_previous", "coolant_overheat_chime_flag_previous",
         "coolant_overheat_chime_flag at the last pass of cm848_updateEngineWarningFlags (its rising edge loads the chime)"),
        ("0x003fcdc6", "coolant_temperature_bucket_cycle_count", "coolant_overheat_level_timer_reset_count",
         f"{ACC}: passes with a level timer nonzero and the coolant below coolant_overheat_level_timer_reset_temperature; "
         "past coolant_overheat_level_timer_reset_time the timers go into the lifetime totals")):
    rows.rename(records, a, cur, new, None, None, text)
rows.save(sys.argv[2])
# ---- arrays.csv: CT_Derate_Timer1-5 -----------------------------------------------------------------------------------
ap = os.path.join(out, "arrays.csv")
t = open(ap).read()
old = "0x0040b240,cold_start_coolant_bucket_counters,dword,5,"
assert t.count(old) == 1
line_end = t.index("\n", t.index(old))
old_line = t[t.index(old):line_end]
new_line = ("0x0040b240,coolant_overheat_level_timers,dword,5,e2m 8A72 +14..+24 CT_Derate_Timer1-5 'Coolant Temp Derate "
            f"timerN; time over table bkpt N': {ACC} counts timer i while the coolant is above "
            "coolant_overheat_level_temperature_axis level i (was cold_start_coolant_bucket_counters; PR #53 round 53) | "
            "earlier note: " + old_line[len(old):])
assert "," not in new_line.split(",", 4)[4], "arrays.csv comments go through the quote-aware parser: no commas"
open(ap, "w").write(t.replace(old_line, new_line))
with open(sys.argv[2], "a") as fh:
    fh.write("0x0040b240,coolant_overheat_level_timers,cold_start_coolant_bucket_counters,global,5\n")
# ---- the three functions ----------------------------------------------------------------------------------------------
fp = os.path.join(out, "function_renames.csv")
t = open(fp).read()
FUNCS = [("0x0051375c", "cm848_monitorCoolantTemperatureBucketOverheat", AGG),
         ("0x00513508", "cm848_accumulateCoolantTemperatureBuckets", ACC),
         ("0x0051361c", "engine_coolant_overheat_check", MIN)]
with open(sys.argv[2], "a") as fh:
    for a, cur, new in FUNCS:
        m = re.search(rf"^{a},{cur}(,[^\n]*)?$", t, re.M)
        assert m, (a, cur)
        assert re.fullmatch(r"(cm848|hpcr|mpc555)_[a-z][A-Za-z0-9]*", new) and new not in t
        plate = (m.group(1) or ",")[1:].replace(" Name kept.", "")
        text = (plate.rstrip() + f" (was {cur}; PR #53 round 53: the e2m's CT_Derate vocabulary)").strip()
        t = t[:m.start()] + f"{a},{new},{text}" + t[m.end():]
        fh.write(f"{a},{new},{cur},function,1\n")
open(fp, "w").write(t)
print("round 53 stage B applied")
