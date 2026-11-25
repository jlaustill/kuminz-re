"""Read-only: the N2 proposal data (record rows + table rows), the rows inside each span, the RAM-dump check of
each table's byte count and the name uniqueness check. Writes proposals.json next to this script."""
import csv
import json
import re

REPO = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay"
FW = REPO + "/firmware/CM550_J90350.00_analysis/firmware/"
GLOBALS = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/frozen/cm550/global_variables.csv"
STRUCTS = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/frozen/cm550/structure_definitions.csv"
ram = open(FW + "J90350.00.ram.bin", "rb").read()
ext = open(FW + "J90350.00.extended_ram.bin", "rb").read()


def word(a):
    if 0x800000 <= a < 0x800000 + len(ram) - 1:
        return int.from_bytes(ram[a - 0x800000:a - 0x800000 + 2], "big")
    if 0x809242 <= a < 0x809242 + len(ext) - 1:
        return int.from_bytes(ext[a - 0x809242:a - 0x809242 + 2], "big")
    return None


def dword(a):
    h, lo = word(a), word(a + 2)
    return None if h is None or lo is None else (h << 16) | lo


struct_size = {}
for row in csv.reader(open(STRUCTS)):
    if not row or row[0].startswith("#") or row[0] == "struct_name" or len(row) < 5:
        continue
    try:
        struct_size[row[0]] = struct_size.get(row[0], 0) + int(row[4])
    except ValueError:
        pass
BASE = {"byte": 1, "char": 1, "sbyte": 1, "undefined": 1, "bool": 1, "word": 2, "short": 2, "i16": 2, "ushort": 2,
        "dword": 4, "int": 4, "uint": 4, "pointer": 4, "float": 4}


def type_size(t):
    t = t.strip()
    m = re.match(r"(.+?)\s*\[(\d+)\]$", t)
    if m:
        s = type_size(m.group(1))
        return None if s is None else s * int(m.group(2))
    if t.endswith("*"):
        return 4
    return BASE.get(t, struct_size.get(t))


rows = []
for row in csv.reader(open(GLOBALS)):
    if row and row[0].startswith("0x"):
        rows.append((int(row[0], 16), row[1], row[2] if len(row) > 2 else ""))
rows.sort()
names_in_csv = {}
for a, n, t in rows:
    names_in_csv.setdefault(n, []).append(a)


def rows_in(start, end):
    out = []
    for a, n, t in rows:
        s = type_size(t) or 1
        if a < end and a + s > start:
            out.append((a, n, t))
    return out


CHANNELS = ["intake_manifold_temperature", "fuel_temperature", "coolant_level", "fuel_pressure", "oil_pressure",
            "boost_pressure", "coolant_temperature", "ambient_air_temperature", "power_steering_temperature",
            "exhaust_pressure", "sampled_throttle", "remote_throttle", "ambient_air_pressure", "battery_voltage",
            "engine_speed_sensor_supply_voltage", "throttle_position_sensor_supply_voltage",
            "vehicle_connector_sensor_supply_voltage", "engine_connector_sensor_supply_voltage",
            "frequency_throttle_input_supply_voltage", "cruise_control_switch_multiplexer", "water_in_fuel",
            "egr_current_feedback", "programming_pulse_supply_voltage", "high_side_gate_bias_supply_voltage",
            "operational_amplifier_and_comparator_supply_voltage"]
AD_AXIS = ["101B ADIMTPXA", "8008 ADFLTPXA", "800A ADCVXA", "801F ADFPLZXA", "1018 ADOLPRXA", "1016 ADBSPRXA",
           "1014 ADCLTPXA", "8021 ADAATXA", "8023 ADPOTPXA", "8025 ADEPLZXA", "1012 ADSATHXA", "1023 ADROTHXA",
           "101D ADAAPRXA", "1027 ADBTVTXA", "800C ADESLZXA", "8029 ADTHLIXA", "802B ADVHLZXA", "802D ADECLZXA",
           "802F ADFTLZXA", "800E ADCRLZXA", "8027 ADWFLZXA", "8010 ADEGLZXA", "8031 ADPSLIXA", "8033 ADHBLZXA",
           "8035 ADOCLIXA"]
AD_VALUES = {0: "1019 ADIMTPYA", 1: "8009 ADFLTPYA", 2: "800B ADCVYA"}

# record address -> (name, axis (addr, name, e2m), values (addr, name, e2m)); table words from the dump or given
R = [
    (0x80004a, "acceleration_noise_control_fuel_limit_lookup", (0x6009e, "acceleration_noise_control_fuel_limit_axis", "10A6 NZFLLMXA", 10), (0x600b2, "acceleration_noise_control_fuel_limit_values", "10A7 NZFLLMYA", 10)),
    (0x800058, "acceleration_noise_control_timing_limit_lookup", (0x600c6, "acceleration_noise_control_timing_limit_axis", "10A8 NZTALMXA", 10), (0x600da, "acceleration_noise_control_timing_limit_values", "10A9 NZTALMYA", 10)),
    (0x800102, "all_speed_governor_throttle_prefilter_coefficient_lookup", (0x807acc, "all_speed_governor_throttle_prefilter_coefficient_axis", "1326 ASTHPFXA", None), (0x807ad8, "all_speed_governor_throttle_prefilter_coefficient_values", "1327 ASTHPFYA", None)),
    (0x800118, "all_speed_governor_no_load_fuel_lookup", (0x807230, "all_speed_governor_no_load_fuel_axis", "1321 ASNLFLXA", None), (0x807242, "all_speed_governor_no_load_fuel_values", "1323 ASNLFLYA", None)),
    (0x800126, "all_speed_governor_no_load_fuel_coolant_temperature_adjustment_lookup", (0x807254, "all_speed_governor_no_load_fuel_coolant_temperature_adjustment_axis", "1324 ASCLNLXA", None), (0x807268, "all_speed_governor_no_load_fuel_coolant_temperature_adjustment_values", "1325 ASCLNLYA", None)),
    (0x800136, "all_speed_governor_alternate_droop_lookup", (0x60462, "all_speed_governor_alternate_droop_axis", "116C ASALDPXA", 8), (0x60472, "all_speed_governor_alternate_droop_values", "116D ASALDPYA", 8)),
    (0x800144, "all_speed_governor_droop_lookup", (0x60482, "all_speed_governor_droop_axis", "116E ASDPTBXA", 8), (0x60492, "all_speed_governor_droop_values", "116F ASDPTBYA", 8)),
    (0x800184, "engine_brake_braking_torque_lookup", (0x6052a, "engine_brake_braking_torque_axis", "13D6 JCBCRPXA", 5), None),
    (0x800192, "engine_brake_reference_braking_torque_lookup", None, (0x60566, "engine_brake_6_cylinder_braking_torque_values", "13D5 JC6CTQYA", 5)),
    (0x8001ea, "cylinder_pressure_maintenance_pressure_ratio_per_timing_degree_lookup", (0x60596, "cylinder_pressure_maintenance_pressure_ratio_per_timing_degree_axis", "108B CPCS01XA", 14), (0x605b2, "cylinder_pressure_maintenance_pressure_ratio_per_timing_degree_values", "108C CPCS01YA", 14)),
    (0x80020e, "cylinder_pressure_maintenance_temperature_per_timing_degree_lookup", (0x60640, "cylinder_pressure_maintenance_temperature_per_timing_degree_axis", "108D CPCS03XA", 14), (0x6065c, "cylinder_pressure_maintenance_temperature_per_timing_degree_values", "108E CPCS03YA", 14)),
    (0x80024e, "cylinder_balance_threshold_lookup", (0x8072f4, "cylinder_balance_threshold_axis", "8226 CBDTT1", None), (0x807316, "cylinder_balance_threshold_values", "8227 CBDTT2", None)),
    (0x80025c, "cylinder_balance_real_2_dynamics_compensation_lookup", None, (0x809e9e, "cylinder_balance_real_2_dynamics_compensation_values", "823E CBDDCT", 16)),
    (0x80026a, "cylinder_balance_imaginary_2_dynamics_compensation_lookup", None, (0x809ebe, "cylinder_balance_imaginary_2_dynamics_compensation_values", "823F CBDI2DCT", 16)),
    (0x800278, "cylinder_balance_engine_speed_breakpoint_lookup", (0x807360, "cylinder_balance_engine_speed_breakpoint_axis", "822E CBDESBV", None), (0x807370, "cylinder_balance_engine_speed_breakpoint_values", "822F CBDESBT", None)),
    (0x800286, "cylinder_balance_delta_fueling_breakpoint_lookup", (0x807380, "cylinder_balance_delta_fueling_breakpoint_axis", "8230 CBDDFBV", None), (0x80738e, "cylinder_balance_delta_fueling_breakpoint_values", "8231 CBDDFBT", None)),
    (0x800294, "cylinder_balance_filtered_fueling_breakpoint_lookup", (0x80739c, "cylinder_balance_filtered_fueling_breakpoint_axis", "8232 CBDFFBV", None), (0x8073aa, "cylinder_balance_filtered_fueling_breakpoint_values", "8233 CBDFFBT", None)),
    (0x80058e, "engine_warmup_protection_rifle_to_turbocharger_delay_time_lookup", (0x60846, "engine_warmup_protection_rifle_to_turbocharger_delay_time_axis", "11EF WPCQXA", 10), (0x6085a, "engine_warmup_protection_rifle_to_turbocharger_delay_time_values", "11EE WPDYTMYA", 10)),
    (0x80059c, "engine_warmup_protection_fuel_limit_lookup", (0x607f2, "engine_warmup_protection_fuel_limit_axis", "11ED WPESXA", 21), (0x6081c, "engine_warmup_protection_fuel_limit_values", "11EC WPFLDQYA", 21)),
    (0x8005b4, "crank_wet_stack_timing_by_intake_manifold_temperature_lookup", None, None),
    (0x8005fe, "torque_curve_breakpoint_engine_protection_fuel_derate_lookup", None, None),
    (0x800632, "engine_protection_fuel_derate_lookup", (0x807176, "engine_protection_fuel_derate_axis", "10BA EPFLVSAI", None), (0x8071a8, "engine_protection_fuel_derate_values", "10BB EPFLTB", None)),
    (0x8006aa, "double_pulsing_fueling_mapping_lookup", (0x607d6, "double_pulsing_fueling_mapping_axis", "1084 DPFPTB", 7), (0x607e4, "double_pulsing_fueling_mapping_values", "1085 DPTVOTB", 7)),
    (0x80071e, "high_speed_governor_derivative_gain_adjustment_multiplier_lookup", (0x808068, "high_speed_governor_derivative_gain_adjustment_multiplier_axis", "12E1 HSDVCFXA", None), None),
    (0x80072c, "high_speed_governor_proportional_gain_adjustment_multiplier_lookup", (0x8080a0, "high_speed_governor_proportional_gain_adjustment_multiplier_axis", "12E3 HSPPCFXA", None), None),
    (0x80073a, "high_speed_governor_integral_gain_adjustment_multiplier_lookup", (0x8080d8, "high_speed_governor_integral_gain_adjustment_multiplier_axis", "12E5 HSITCFXA", None), None),
    (0x801a3e, "engine_protection_low_oil_pressure_limit_lookup", (0x611d0, "engine_protection_oil_pressure_limit_axis", "10BC EPO2VSAI", 7), (0x611de, "engine_protection_low_oil_pressure_limit_values", "10BD EPO2LOTB", 7)),
    (0x801a4c, "engine_protection_very_low_oil_pressure_limit_lookup", None, (0x611ec, "engine_protection_very_low_oil_pressure_limit_values", "10BE EPO2VLTB", 7)),
    (0x801c0e, "power_take_off_governor_speed_gain_adjustment_lookup", (0x808958, "power_take_off_governor_speed_gain_adjustment_axis", "13B2 PTSPAX", None), (0x80896e, "power_take_off_governor_speed_gain_adjustment_values", "13B3 PTGNTB", None)),
    (0x801c1c, "power_take_off_governor_derivative_gain_adjustment_lookup", (0x8088b0, "power_take_off_governor_derivative_gain_adjustment_axis", "13AC PTERQDAX", None), None),
    (0x801c2a, "power_take_off_governor_integral_gain_adjustment_lookup", (0x8088e8, "power_take_off_governor_integral_gain_adjustment_axis", "13AE PTERQIAX", None), None),
    (0x801c38, "power_take_off_governor_proportional_gain_adjustment_lookup", (0x808920, "power_take_off_governor_proportional_gain_adjustment_axis", "13B0 PTERQPAX", None), None),
    (0x801e30, "engine_brake_1_cylinder_braking_torque_lookup", None, (0x60534, "engine_brake_1_cylinder_braking_torque_values", "13D0 JC1CTQYA", 5)),
    (0x801e3e, "engine_brake_2_cylinder_braking_torque_lookup", None, (0x6053e, "engine_brake_2_cylinder_braking_torque_values", "13D1 JC2CTQYA", 5)),
    (0x801e4c, "engine_brake_3_cylinder_braking_torque_lookup", None, (0x60548, "engine_brake_3_cylinder_braking_torque_values", "13D2 JC3CTQYA", 5)),
    (0x801e5a, "engine_brake_4_cylinder_braking_torque_lookup", None, (0x60552, "engine_brake_4_cylinder_braking_torque_values", "13D3 JC4CTQYA", 5)),
    (0x801e68, "engine_brake_5_cylinder_braking_torque_lookup", None, (0x6055c, "engine_brake_5_cylinder_braking_torque_values", "13D4 JC5CTQYA", 5)),
    (0x8036c6, "wet_stack_timing_by_intake_manifold_temperature_lookup", (0x8071e0, "wet_stack_timing_by_intake_manifold_temperature_axis", "1075 WSIMAI", None), (0x8071f6, "wet_stack_timing_by_intake_manifold_temperature_values", "1076 WSTATB", None)),
    (0x8036d4, "wet_stack_timing_by_coolant_temperature_lookup", (0x80720c, "wet_stack_timing_by_coolant_temperature_axis", "12CB WSCLAI", None), None),
    (0x80db20, "no_load_fuel_lookup", (0x611fa, "no_load_fuel_axis", "1098 NLFCFLXA", 10), (0x6120e, "no_load_fuel_values", "1099 NLFCFLYA", 10)),
    (0x80db2e, "no_load_fuel_coolant_temperature_adjustment_lookup", (0x61222, "no_load_fuel_coolant_temperature_adjustment_axis", "109A ADCLFLBP", 10), (0x61236, "no_load_fuel_coolant_temperature_adjustment_values", "109B NLCLFLYA", 10)),
]
for n, ch in enumerate(CHANNELS):
    a = 0x80a792 + 14 * n
    xp, vp = dword(a + 2), dword(a + 8)
    R.append((a, f"{ch}_linearization_lookup", (xp, f"{ch}_linearization_axis", AD_AXIS[n], None),
              (vp, f"{ch}_linearization_values", AD_VALUES[n], None) if n in AD_VALUES else None))

out = {"records": [], "tables": []}
proposed = {}
problems = []
for rec, name, axis, values in R:
    xp, vp = dword(rec + 2), dword(rec + 8)
    inside = rows_in(rec, rec + 14)
    out["records"].append({"address": f"0x{rec:08x}", "name": name, "axis_pointer": hex(xp), "values_pointer": hex(vp),
                           "dump_offset": word(rec), "dump_input": word(rec + 6), "dump_flag": word(rec + 12),
                           "current_row": next((n for a, n, t in inside if a == rec), ""),
                           "inside": [f"0x{a:x} {n}" for a, n, t in inside if a != rec]})
    proposed.setdefault(name, []).append(rec)
    for tab, ptr in ((axis, xp), (values, vp)):
        if tab is None:
            continue
        addr, tname, e2m, words = tab
        if addr != ptr and not (rec == 0x800184 and tab is values) and not (rec == 0x800192):
            problems.append(f"{name}: table 0x{addr:x} != record pointer 0x{ptr:x}")
        cnt = word(addr)
        if words is None:
            if cnt is None:
                problems.append(f"{tname}: no dump and no size")
                continue
            words = cnt // 2 + 1
        size = 2 * words
        tin = rows_in(addr, addr + size)
        out["tables"].append({"address": f"0x{addr:08x}", "name": tname, "type": f"word[{words}]", "e2m": e2m,
                              "dump_count": cnt, "record": name,
                              "current_row": next((f"{n} ({t})" for a, n, t in tin if a == addr), ""),
                              "inside": [f"0x{a:x} {n}" for a, n, t in tin if a != addr]})
        proposed.setdefault(tname, []).append(addr)
for n, addrs in proposed.items():
    if len(set(addrs)) > 1:
        problems.append(f"duplicate proposal {n} at {[hex(a) for a in addrs]}")
    for a in names_in_csv.get(n, []):
        if a not in addrs:
            problems.append(f"{n} already used at 0x{a:x}")
json.dump(out, open("/home/linux/.claude/jobs/374b0424/tmp/w15/r95/scratch/N2/investigator/proposals.json", "w"), indent=1)
print("records", len(out["records"]), "tables", len(out["tables"]))
print("PROBLEMS:", problems or "none")
for r in out["records"]:
    print(r["address"], r["name"], "| cur:", r["current_row"] or "-", "| off", r["dump_offset"], "in", r["dump_input"],
          "flag", r["dump_flag"], "| inside:", "; ".join(r["inside"]) or "none")
print()
for t in out["tables"]:
    print(t["address"], t["name"], t["type"], t["e2m"], "count", t["dump_count"], "| cur:", t["current_row"] or "-",
          "| inside:", "; ".join(t["inside"]) or "none")
