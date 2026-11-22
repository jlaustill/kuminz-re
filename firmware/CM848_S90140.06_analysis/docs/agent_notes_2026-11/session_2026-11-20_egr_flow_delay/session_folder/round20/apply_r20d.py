"""Round 20 stage D (types): algorithm_enable_flags_<N>_t word bitfields on the 17 algorithm enable flags words whose
every code use is a single-bit masked read (word 0 stays a word: the engine protection loops index the block from it),
and the cold delta fuel lookup cache (0x3fb35c, word[2]).
Naming gate (the advisor's tiers), checked here:
- reader: the bit is tested in the code and the reader matches the e2m record (or, with no record, the name is the
  reader's behaviour); the name uses the reader's vocabulary;
- e2m: no reader, exactly one record (or a chosen one) whose description spells the words out;
- otherwise reserved_bit_N, with the e2m record and the reader in the comment.
Every tested mask must have an explicit entry; names are unique in the struct and new to the repo; no banned
abbreviation. usage: apply_r20d.py <repo> <pre.cpp> [--dry-run]"""
import ast
import collections
import os
import re
import sys

repo, pre_cpp = os.path.abspath(sys.argv[1]), sys.argv[2]
dry = "--dry-run" in sys.argv
# --only N[,N]: stage F typed word 11 alone (its reader was an unnamed DAT_ that stage C found)
ONLY = [int(x) for x in sys.argv[sys.argv.index("--only") + 1].split(",")] if "--only" in sys.argv else None
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
BASE = 0x3fd59a
NAMES = {
    1: {0: "alpha_user_override_enable", 1: "user_override_fueling_enable",
        2: "test_cell_throttle_switch_override_enable", 3: "user_override_timing_enable",
        4: "torque_derate_override_enable", 5: "altitude_derate_enable",
        12: "low_speed_governor_aggressive_gain_set_enable", 13: "low_speed_governor_high_gear_gain_set_enable",
        14: "low_speed_governor_middle_gear_gain_set_enable", 15: "low_speed_governor_tsc1_gain_set_enable"},
    2: {0: "engine_protection_shutdown_enable", 4: "engine_protection_enable", 5: "engine_protection_restart_enable",
        6: "engine_retarder_clutch_deactivation_enable", 7: "j1922_monitor_enable", 8: "j1922_monitor_clear_enable",
        11: "j1939_monitor_enable", 12: "j1939_retarder_shift_assist_enable",
        13: "power_take_off_throttle_override_enable", 14: "user_commanded_timing_increment_enable",
        15: "zero_vehicle_speed_power_take_off_limit_enable"},
    5: {0: "egr_fraction_user_override_enable", 1: "combustion_fuel_command_user_override_enable",
        2: "mass_charge_flow_user_override_enable", 3: "injection_timing_user_increment_enable",
        4: "injection_timing_main_base_user_override_enable", 5: "combustion_alpha_user_override_enable",
        6: "combustion_chi_full_user_override_select", 7: "combustion_chi_user_override_enable",
        8: "combustion_egr_off_user_override_enable", 9: "combustion_fuel_reference_user_override_enable",
        10: "combustion_gross_fuel_user_override_enable",
        11: "oxygen_fuel_limit_equivalence_ratio_user_override_enable", 12: "oxygen_fuel_limit_user_override_enable",
        13: "exhaust_pressure_estimate_enable", 14: "charge_temperature_estimate_enable",
        15: "charge_pressure_estimation_enable"},  # monitor_condition_bits_t has charge_pressure_estimate_enable
    6: {0: "turbocharger_speed_estimate_enable", 1: "low_fuel_pressure_derate_enable", 2: "transmission_control_enable",
        3: "second_gear_converter_lockup_enable", 4: "not_brake_switch_diagnostic_enable",
        5: "enhanced_diagnostics_enable", 10: "fan_air_conditioning_pressure_enable",
        11: "fan_air_conditioning_vehicle_speed_interaction_enable", 12: "fan_clutch_2_enable",
        13: "fan_engine_retarder_enable", 14: "fan_manual_input_enable", 15: "cruise_engine_retarder_enable"},
    11: {0: "proprietary_communication_enable", 1: "j1587_communication_enable", 2: "j1922_communication_enable",
         3: "j1939_communication_enable"},
    13: {0: "engine_retarder_switch_level_override", 1: "driver_demand_torque_active_during_j1939_control",
         2: "net_torque_derate_enable", 5: "fuel_pressure_idle_diagnostic_enable"},
    19: {0: "alternate_curve_configuration_enable", 1: "switched_rear_axle_anti_tamper_enable",
         3: "wastegate_monitor_enable", 5: "alpha_altitude_derate_override_enable",
         6: "egr_condensation_algorithm_enable", 7: "compressor_outlet_temperature_estimate_enable",
         8: "service_brake_prevents_idle_shutdown_enable", 9: "condensation_protection_enable",
         12: "combustion_manager_bypass", 13: "egr_cooler_fouling_diagnostic_enable",
         14: "charge_manager_open_loop_egr_table_active", 15: "charge_manager_virtual_sensors_active"},
    20: {8: "air_handling_system_protection_enable", 9: "extreme_ambient_overheat_protection_enable",
         10: "white_smoke_and_misfire_protection_enable", 11: "extended_idle_protection_enable",
         12: "engine_start_warmup_protection_enable", 14: "intake_manifold_temperature_lead_compensation_enable",
         15: "egr_orifice_temperature_lead_compensation_enable"},
    21: {2: "h_bridge_asic_diagnostic_enable", 3: "turbocharger_speed_limiter_enable",
         4: "charge_pressure_in_range_diagnostic_enable", 5: "turbocharger_speed_in_range_diagnostic_enable",
         6: "general_engine_protection_enable", 9: "air_conditioning_anti_slugging_start_enable",
         10: "deicer_speed_limit_enable"},
    25: {0: "engine_retarder_rate_limit_defeat_enable", 1: "powertrain_protection_enable",
         2: "powertrain_protection_lugback_enable", 3: "j1939_multiplex_limp_home_on_analog_throttle_enable",
         5: "smart_road_speed_governor_enable", 6: "fan_clutch_1_air_conditioning_enable",
         7: "fan_clutch_1_coolant_temperature_enable", 8: "fan_clutch_1_intake_manifold_temperature_enable",
         9: "fan_clutch_2_air_conditioning_enable", 10: "fan_clutch_2_air_conditioning_pressure_enable",
         11: "fan_clutch_2_coolant_temperature_enable", 12: "fan_clutch_2_engine_retarder_enable",
         13: "fan_clutch_2_intake_manifold_temperature_enable", 14: "fan_clutch_2_manual_input_enable",
         15: "manual_fan_level_override"},
    27: {2: "engine_retarder_fuel_to_brake_delay_enable", 3: "switched_throttle_control_governor_select",
         4: "boost_pressure_in_range_diagnostic_enable", 5: "air_handling_enable", 6: "air_mass_calculation_enable",
         7: "turbine_speed_and_temperature_calculation_enable", 8: "four_step_wastegate_control_enable",
         9: "wastegate_tool_override_enable", 10: "idle_shutdown_temperature_enable", 11: "anti_theft_enable",
         12: "anti_theft_automatic_lock_enable", 13: "road_speed_governor_reference_speed_ramp_enable"},
    28: {3: "keyless_restart_enable", 5: "alarm_during_automatic_start_enable", 7: "starter_lockout_enable",
         8: "wastegate_table_control_enable", 10: "j1939_multiplex_enable",
         12: "anti_theft_random_number_generator_enable", 13: "starter_lockout_normally_open_contact_enable"},
    29: {4: "air_handling_direct_derate_enable", 5: "trip_reset_enable", 6: "service_component_reset_enable",
         7: "tire_wear_adjustment_enable", 8: "dm13_enable", 9: "engine_protection_shutdown_override_enable",
         10: "throttle_activated_diagnostic_switch_enable", 11: "throttle_related_error_handler_enable",
         12: "fuel_delivery_pressure_broadcast_enable", 15: "variable_speed_fan_logic_enable"},
    31: {0: "hybrid_governor_enable"},
    32: {0: "intake_air_heater_control_enable", 1: "end_of_injection_limit_enable", 2: "equivalent_throttle_enable",
         4: "intake_air_heater_24_volt_enable"},
    40: {0: "electronic_voltage_regulator_enable", 1: "coolant_temperature_derate_enable",
         2: "engine_oil_pressure_processing_enable", 3: "air_conditioning_control_enable",
         5: "fuel_level_processing_enable", 6: "j1850_communication_enable", 7: "ambient_air_pressure_monitor_enable",
         8: "misfire_timing_limit_enable", 9: "power_take_off_cruise_control_switches_enable",
         10: "power_take_off_park_neutral_enable", 11: "driver_demand_torque_is_unmanaged_torque_enable",
         12: "torque_management_enable", 13: "trip_information_enable",
         14: "engine_retarder_selection_fault_mask_enable",
         15: "engine_retarder_inhibit_during_power_take_off_enable"},
    42: {0: "misfire_relative_enable", 1: "actual_sensor_values_enable", 2: "fuel_pressure_setpoint_cranking_enable",
         3: "fuel_pressure_fault_derate_cold_increment_enable", 4: "high_pressure_safety_valve_test_enable",
         5: "stall_torque_management_enable", 6: "j1939_lost_tsc1_no_broadcast_enable",
         7: "altitude_derate_cold_increment_enable", 8: "hybrid_governor_cold_increment_enable",
         9: "torque_management_cold_increment_enable", 12: "torque_management_gear_ratio_enable",
         13: "fuel_pressure_too_high_monitor_enable", 14: "fuel_pressure_tracking_error_monitor_enable",
         15: "fuel_pressure_setpoint_not_reached_monitor_enable"},
    43: {0: "h_bridge_fault_discrete_feedback_enable", 1: "egr_orifice_temperature_rationality_enable",
         2: "transmission_temperature_rationality_monitor_enable", 3: "rock_cycle_torque_management_enable",
         4: "vacuum_throttle_cruise_enable", 5: "transfer_case_low_range_enable", 6: "chi_cold_increment_enable",
         7: "density_cold_increment_enable", 8: "net_torque_fueling_cold_increment_enable",
         12: "wastegate_solenoid_driver_enable"},
}
# two records on one mask: the reader picks (SAME_ENABLE: the two records are one enable under two names)
SAME_ENABLE = {(19, 7)}
CHOSEN = {(19, 7): "COT_Estimation_Enable", (19, 9): "T_EMO_Condensation_AECD_Enable",
          (19, 13): "T_EGR_Cooler_Fouling_Enable"}
# notes (behaviour of no-record readers, why a read bit stays reserved, odd records)
NOTES = {
    (1, 0): "calculateAlpha also reads it through its pointer to algorithm_enable_flags_0_cal",
    (19, 5): "calculateAlpha also reads it through its pointer to algorithm_enable_flags_0_cal",
    (5, 6): "set = the full user override (e2m CBR_FULL_USER_OVERRIDE), clear = the single one",
    (27, 3): "set = the switched throttle control governor, clear = the all speed governor droop (e2m 08=STCG:00=ASGDROOP)",
    (21, 15): "calculateAlpha takes alpha source 5 while it is set and electronic_smart_power_tau is "
              "0x4000; kept reserved (its meaning beyond that is unknown)",
    (29, 0): "read by cm848_buildPgn65269AmbientConditionsMessage: the ambient air temperature bytes are sent only while "
             "bits 0 and 1 are both set (else 0xFFFF); 'SS' is not spelled out anywhere, so it stays reserved",
    (29, 1): "read by cm848_buildPgn65269AmbientConditionsMessage with bit 0 (see bit 0); 'SS' is not spelled out "
             "anywhere, so it stays reserved",
    (29, 12): "cm848_buildPgn65263EngineFluidLevelPressure1Message sends the fuel delivery pressure "
              "byte only while it is set (else 0xFF)",
    (32, 2): "the e2m record's mask is 7 but its value list says 0=DISABLE:4=ENABLE; the code tests 4",
    (40, 14): "cm848_calculateEngineRetarderSelectionPercent masks the retarder selection to 0 while it "
              "is set and fault bit 41 or 42 is detected",
    (40, 15): "cm848_updateEngineRetarderAllowedState keeps the retarder off while the power take-off "
              "governor is active and it is set",
    (42, 11): "no reader; bit 12 does the gear ratio torque management in this build",
    (42, 12): "the e2m puts Torque_Mgmt_GR_Enable on bit 11, which nothing reads; "
              "cm848_evaluateTorqueManagementRequired runs the manual gear ratio stages while it is set, and "
              "cm848_runTorqueManagement runs while it or algorithm_enable_flags_40_cal torque_management_enable is set",
}
src = open(os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "apply_hand_worklist.py")).read()
BANNED = ast.literal_eval(re.search(r"BANNED = (\{.*?\})", src, re.S).group(1))  # a set literal, parsed, not run
# 'volt' is banned as a short form of 'voltage'; in intake_air_heater_24_volt_enable it is the unit (e2m IAH_24V_Enable)
BANNED_EXCEPTIONS = {"intake_air_heater_24_volt_enable"}

# e2m records per word: mask -> [(name, description)]; a multi-bit mask is placed by its ENABLE value
recs = collections.defaultdict(lambda: collections.defaultdict(list))
for line in open(os.path.join(repo, "e2m-analysis/CHR/CHR_CC_11.45.01.07.e2m"), errors="replace"):
    head, _, desc = line.rstrip("\n").partition(";")
    f = head.split(",")
    if len(f) > 18 and f[2] == "106B":
        mask = int(f[10], 16)
        if bin(mask).count("1") != 1:
            enable = [int(v.split("=")[0], 16) for v in f[-1].split(":") if v.split("=")[1].strip() == "ENABLE"]
            assert len(enable) == 1 and bin(enable[0]).count("1") == 1, f[0]
            mask = enable[0]
        recs[int(f[3], 16)][mask].append((f[0], desc.strip().replace('"', "'")))
# readers per word / mask in the pre-stage .cpp (comments stripped)
raw = open(pre_cpp).read()
code = re.sub(r"/\*.*?\*/", lambda m: "\n" * m.group(0).count("\n"), raw, flags=re.S)
code = re.sub(r"//[^\n]*", "", code)
func, cur = [], "?"
for l in raw.split("\n"):
    if l.startswith("// Function: "):
        cur = l.split()[2]
    func.append(cur)
readers = collections.defaultdict(list)
pat = re.compile(r"\balgorithm_enable_flags_(\d+)_cal\s*&\s*(0x[0-9a-fA-F]+|\d+)\)")
for i, l in enumerate(code.split("\n")):
    for m in pat.finditer(l):
        key = (int(m.group(1)), int(m.group(2), 0))
        if func[i] not in readers[key]:
            readers[key].append(func[i])
dump = open(os.path.join(repo, "firmware/CM848_S90140.06_analysis/originals/cm848_ram.bin"), "rb").read()
sp = os.path.join(out, "structure_definitions.csv")
struct_text = open(sp).read()
existing_fields = {l.split(",")[2] for l in struct_text.split("\n") if l and not l.startswith("#") and l.count(",") > 3}
cpp_ids = set(re.findall(r"[A-Za-z_][A-Za-z0-9_]*", raw))
problems, blocks, tiers = [], [], collections.Counter()
if ONLY:
    NAMES = {w: NAMES[w] for w in ONLY}
for word, names in NAMES.items():
    off = 2 + 2 * word
    address = BASE + off
    value = int.from_bytes(dump[address - 0x3fa000:address - 0x3fa000 + 2], "big")
    struct = f"algorithm_enable_flags_{word}_t"
    tested = {mask.bit_length() - 1 for (w, mask) in readers if w == word}
    for bit in tested:
        if bit not in names and (word, bit) not in NOTES:
            problems.append(f"word {word} bit {bit} is tested but has no entry")
    seen = set()
    rows = [f"# {struct}: algorithm enable flags word {word} (EEPROM 0x{0x118 + off:x}, e2m 106B +{off:X}; PR #53 round "
            f"20); 0x{value:04x} in the dump"]
    for bit in range(16):
        mask = 1 << bit
        rec = recs[off].get(mask, [])
        rd = readers.get((word, mask), [])
        name = names.get(bit, f"reserved_bit_{bit}")
        if bit in names:
            if not re.fullmatch(r"[a-z][a-z0-9_]*", name) or name in seen or name in existing_fields or name in cpp_ids:
                problems.append(f"word {word} bit {bit}: name {name} not new / unique")
            bad = [t for t in name.split("_") if t in BANNED and name not in BANNED_EXCEPTIONS]
            if bad:
                problems.append(f"word {word} bit {bit}: banned {bad} in {name}")
            if not rd:
                if len(rec) != 1 and (word, bit) not in CHOSEN:
                    problems.append(f"word {word} bit {bit}: e2m tier needs exactly one record, has {len(rec)}")
                tiers["e2m"] += 1
            else:
                tiers["reader"] += 1
            seen.add(name)
        else:
            tiers["reserved"] += 1
        parts = []
        if rec:
            chosen = CHOSEN.get((word, bit))
            shown = [r for r in rec if r[0] == chosen] if chosen else rec
            others = [r[0] for r in rec if chosen and r[0] != chosen]
            if (word, bit) in SAME_ENABLE:
                note = f" (the e2m also names this enable {', '.join(others)})"
            else:
                note = f" (the reader rules out the other record on this bit, {', '.join(others)})" if others else ""
            parts.append("; ".join(f"e2m {r[0]} (0x{mask:x}): '{r[1][:110]}'" for r in shown) + note)
        else:
            parts.append(f"no e2m record (0x{mask:x})")
        if rd:
            parts.append("read by " + ", ".join(rd))
        elif (word, bit) not in NOTES:
            parts.append("no reader in this build")
        if (word, bit) in NOTES:
            parts.append(NOTES[(word, bit)])
        parts.append("set on this truck" if value & mask else "clear on this truck")
        comment = "; ".join(parts)
        assert '"' not in comment
        rows.append(f'{struct},,{name},bitfield:1@{bit},{2 if bit == 0 else 0},"{comment}",,verified')
    blocks.append("\n".join(rows))
if problems:
    print("\n".join(problems))
    sys.exit(1)
print(f"{len(NAMES)} structs; tiers {dict(tiers)}")
if dry:
    sys.exit(0)
anchor = struct_text.index("# algorithm_enable_flags_4_t")
end = struct_text.index("\n", struct_text.rindex("\nalgorithm_enable_flags_4_t,") + 1)
open(sp, "w").write(struct_text[:end + 1] + "\n".join(blocks) + "\n" + struct_text[end + 1:])
gp = os.path.join(out, "global_variables.csv")
lines = open(gp).read().split("\n")
for word in NAMES:
    address = BASE + 2 + 2 * word
    k = [i for i, l in enumerate(lines) if l.startswith(f"0x{address:08x},algorithm_enable_flags_{word}_cal,word,")]
    assert len(k) == 1, word
    a, n, t, c = lines[k[0]].split(",", 3)
    lines[k[0]] = ",".join([a, n, f"algorithm_enable_flags_{word}_t",
                            c + f" | typed algorithm_enable_flags_{word}_t in PR #53 round 20 (was word)"])
if ONLY:
    open(gp, "w").write("\n".join(lines))
    print("written (--only: no cache row)")
    sys.exit(0)
assert not any(l.startswith("0x003fb35c,") for l in lines)
cache = ("0x003fb35c,cold_delta_fuel_cached_axis_offsets,word[2],2-D lookup cache of cold_delta_fuel_grid "
         "(cm848_calculateColdDeltaFuel): the X / Y axis offsets of the last lookup (PR #53 round 20)")
k = max(i for i, l in enumerate(lines) if l.startswith("0x") and int(l[:10], 16) < 0x3fb35c)
lines.insert(k + 1, cache)
open(gp, "w").write("\n".join(lines))
print("written")
