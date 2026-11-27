"""Name uniqueness check of the N1 proposals (and the judge's amendments) against the frozen CSVs.
usage: unique.py   (names are listed below)"""
import csv
import re

FROZEN = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/frozen"
FUNCS = """cm550_countEngineBrakeTime cm550_updateTripInformation cm550_flagTripInformationPowerDownDataLoss cm550_emptyStubFunction11
cm550_evaluateTrendingTriggers cm550_runTrendingIntervalAndStoreSamples cm550_restartTrendingAfterEngineRebuild
cm550_buildPgn65269AmbientConditionsMessage cm550_initializePgn65265CruiseControlVehicleSpeedBuffer
cm550_initializePgn65265CruiseControlVehicleSpeedHandler cm550_buildPgn65259ComponentIdentificationMessage
cm550_initializePgn61441ElectronicBrakeController1Buffer cm550_buildPgn65263EngineFluidLevelPressure1Message
cm550_hasWordIncreasedOrDroppedToZero cm550_hasByteIncreasedOrDroppedToZero sendPgn65251EngineConfiguration1OnChange
sendPgn65251EngineConfiguration1Message cm550_buildPgn65253EngineHoursRevolutionsMessage
cm550_initializePgn65253EngineHoursRevolutionsBuffer cm550_initializePgn65253EngineHoursRevolutionsHandler
cm550_buildPgn65262EngineTemperature1Message initializePgn65213FanDrive1Buffer cm550_buildPgn65257FuelConsumptionMessage
cm550_buildPgn65270InletExhaustConditions1Message cm550_buildPgn65264PowerTakeOffInformationMessage
cm550_initializePgn65249RetarderConfigurationBuffer cm550_buildPgn65248VehicleDistanceMessage cm550_buildPgn65255VehicleHoursMessage
cm550_initializePgn65260VehicleIdentificationBuffer cm550_initializePgn65260VehicleIdentificationHandler
cm550_initializePgn65279WaterInFuelIndicatorBuffer cm550_calculateWetStackTimingAdvance""".split()
GLOBALS = """trip_engine_brake_time lifetime_engine_brake_time trip_information_fault_status trip_counters_reset_pending_flag
trip_engine_run_time lifetime_engine_run_time trip_electronic_smart_power_high_horsepower_time
lifetime_electronic_smart_power_high_horsepower_time trip_information_engine_state total_engine_operating_time
engine_run_time_tool_offset_cal total_fuel_consumed trip_fuel_consumed trending_storage_record_count trending_requested_sample_count
trending_sample_interval_hours trending_trigger_hold_time trending_engine_speed_upper_limit trending_engine_speed_lower_limit
trending_engine_load_upper_limit trending_engine_load_lower_limit trending_intake_manifold_temperature_upper_limit
trending_intake_manifold_temperature_lower_limit trending_coolant_temperature_upper_limit trending_coolant_temperature_lower_limit
trending_engine_speed_in_window_flag trending_engine_load_in_window_flag trending_intake_manifold_temperature_in_window_flag
trending_coolant_temperature_in_window_flag trending_engine_speed_trigger_satisfied_flag trending_engine_load_trigger_satisfied_flag
trending_intake_manifold_temperature_trigger_satisfied_flag trending_coolant_temperature_trigger_satisfied_flag
trending_minute_divider_counter trending_sample_ready_flag trending_engine_rebuild_flag_cal trending_engine_rebuild_time_stamp_cal
trending_sample_time_stamp_cal trending_interval_elapsed_minutes_cal trending_interval_window_length_cal
trending_interval_window_elapsed_minutes_cal trending_sample_count_before_rebuild_cal trending_interval_window_active_flag_cal
trending_interval_window_active_previous_cal trending_all_triggers_satisfied_flag_cal trending_load_sample_count_cal
trending_load_accumulator_cal trending_interval_average_load_cal trending_torque_curve_maximum_fueling_cal
trending_interval_average_fuel_consumption_cal trending_lifetime_fuel_used_snapshot_cal trending_storage_table_cal
j1939_pgn65259_payload component_identification_make_cal component_identification_model_cal component_identification_serial_number_cal
component_identification_unit_number_cal vehicle_vin_string_cal j1939_pgn65269_barometric_pressure j1939_pgn65263_engine_oil_pressure
j1939_pgn65253_total_engine_hours j1939_pgn65262_engine_coolant_temperature j1939_pgn65262_fuel_temperature
j1939_pgn65262_engine_oil_temperature j1939_pgn65257_trip_fuel j1939_pgn65257_total_fuel_used j1939_pgn65270_boost_pressure
j1939_pgn65270_intake_manifold_temperature j1939_pgn65264_power_take_off_set_speed j1939_pgn65264_enable_and_remote_switches_byte
j1939_pgn65264_set_and_resume_switches_byte j1939_pgn65248_trip_distance j1939_pgn65248_total_vehicle_distance
j1939_pgn65255_total_vehicle_hours j1939_pgn65255_total_power_take_off_hours j1939_pgn65279_water_in_fuel_indicator_byte
j1939_pgn61441_payload_byte_1 j1939_pgn61441_payload_byte_3 wet_stack_timing_advance_minimum wet_stack_timing_ramp_rate
wet_stack_timing_advance trending_sample_record_t TRIP_INFORMATION_ENGINE_STATE""".split()


def names(path, col):
    out = {}
    with open(path, errors="replace") as f:
        for row in csv.reader(f):
            if not row or row[0].startswith("#") or len(row) <= col:
                continue
            out.setdefault(row[col].split("[")[0], []).append(row[0])
    return out


for fw in ("cm550", "cm848"):
    fn = names(f"{FROZEN}/{fw}/function_renames.csv", 1)
    gv = names(f"{FROZEN}/{fw}/global_variables.csv", 1)
    st = names(f"{FROZEN}/{fw}/structure_definitions.csv", 0)
    en = names(f"{FROZEN}/{fw}/enums.csv", 0)
    print(f"== {fw}")
    for n in FUNCS:
        hits = fn.get(n, []) + gv.get(n, [])
        if hits:
            print(f"  function name {n}: {hits[:5]}")
    for n in GLOBALS:
        hits = gv.get(n, []) + fn.get(n, []) + st.get(n, []) + en.get(n, [])
        if hits:
            print(f"  global name {n}: {sorted(set(hits))[:5]}")
