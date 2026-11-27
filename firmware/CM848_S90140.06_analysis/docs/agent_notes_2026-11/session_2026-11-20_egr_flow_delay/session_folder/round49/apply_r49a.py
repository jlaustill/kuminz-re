"""Round 49 stage A: unnamed data the .cpp reads, at addresses the dumped parameter ID table resolves to a default-e2m
record (unnamed_table_reads.py), named from the record in the style of the block's named rows. Types follow the access
(raw_address_scan.py): lhz / sth word, lha + a signed record i16, lwz dword, lbz / stb byte. An array-sized record that
the code reaches only through an addi pointer gets a row at its base (the e2m size in the comment), so '&name' replaces
'&DAT_'. Also: 0x40af72 fuel_demand_mode_active_flag is 1982 +A Charge_Saturation_Tmptr_Source (0 while charge
pressure, ambient temperature and barometric pressure all come from their primary sources), and 0x40af74 copies it as
+C Exhaust_Saturation_Tmptr_Source.
Skipped: 0x4086ca (the table's 8A14 +30 reaches past 8A2A's base: drift). Idempotent.
usage: apply_r49a.py <repo> <map.csv>"""
import ast
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
CM = os.path.join(repo, "firmware/CM848_S90140.06_analysis")
gp = os.path.join(CM, "output/global_variables.csv")
src = open("/home/linux/.claude/jobs/374b0424/tmp/w15/apply_hand_worklist.py").read()
BANNED = ast.literal_eval(re.search(r"BANNED = (\{.*?\})", src, re.S).group(1))
R = "PR #53 round 49"
ram = open(os.path.join(CM, "originals/cm848_ram.bin"), "rb").read()
rom = open(os.path.join(CM, "originals/cm848_rom.bin"), "rb").read()
recs = {}
for line in open(os.path.join(repo, "e2m-analysis/CHR/CHR_CC_11.45.01.07.e2m"), errors="replace"):
    head, _, desc = line.strip().partition(";")
    f = head.split(",")
    if len(f) > 11 and re.fullmatch(r"[0-9A-Fa-f]{4}", f[2]) and re.fullmatch(r"[0-9A-Fa-f]{1,4}", f[3]):
        recs.setdefault((int(f[2], 16), int(f[3], 16)), (f[0], f[1], f[7], f[9], f[10], desc.strip()))


def cite(block, off, a, access):
    name, unit, size, sign, scale, desc = recs[(block, off)]
    size = int(size)
    unit = f"{unit}, " if unit.upper() not in ("NONE", "UNITLESS", "HEX", "") else ""
    val = ""
    if size in (1, 2, 4):
        v = (int.from_bytes(ram[a - 0x3FA000:a - 0x3FA000 + size], "big") if 0x3FA000 <= a < 0x3FA000 + len(ram)
             else int.from_bytes(rom[a:a + size], "big"))
        if sign == "S" and v >> (8 * size - 1):
            v -= 1 << (8 * size)
        try:
            val = f"; {v} = {v * float(scale):.6g} here"
        except ValueError:
            val = f"; {v} here"
    else:
        val = f"; {size} bytes"
    return (f"e2m {block:04X} +{off:X} {name} '{desc}' ({unit}{'signed, ' if sign == 'S' else ''}{scale} per count{val}; "
            f"the dumped parameter ID table resolves the address). {access}")


g = open(gp).read().split("\n")
names = {l.split(",")[1] for l in g if l.startswith("0x") and len(l.split(",")) > 1}
if "charge_saturation_temperature_source" in names:
    print("already applied")
    sys.exit(0)


def index():
    return {l[:10]: k for k, l in enumerate(g) if l.startswith("0x")}


idx = index()
mapping = ["address,name,old_label,kind,dims"]


def add(a, new, typ, block, off, access):
    global idx
    a = f"0x{a:08x}"
    assert a not in idx, a
    assert new not in names and not any(t in BANNED for t in new.split("_")), new
    names.add(new)
    later = sorted(x for x in idx if int(x, 16) > int(a, 16))
    k = idx[later[0]] if later else len(g)
    g.insert(k, f"{a},{new},{typ},{cite(block, off, int(a, 16), access)} ({R})")
    idx = index()
    mapping.append(f"{a},{new},DAT_{int(a, 16):08x},global,1")


ADD = [
    (0x3ff06c, "altitude_derate_charge_pressure_fault_enable_bits", "byte", 0x10A0, 0xE,
     "A 4-byte bitmap; cm848_calculateAltitudeDerateFuelLimit tests bit 0 of its first byte (lbz) with the wastegate "
     "pressure control driver error"),
    (0x5c35a, "j1939_low_power_derated_engine_speed_at_point_2", "word", 0x1104, 0x12,
     "cm848_updateJ1939EngineConfigurationTorqueCurve (lhz)"),
    (0x5c35c, "j1939_low_power_derated_fueling_at_point_2", "word", 0x1104, 0x14, "Same function (lhz)"),
    (0x5c35e, "j1939_low_power_point_5_intersection_engine_speed", "word", 0x1104, 0x16, "Same function (lhz)"),
    (0x5c360, "j1939_high_power_derated_engine_speed_at_point_2", "word", 0x1104, 0x18, "Same function (lhz)"),
    (0x5c362, "j1939_high_power_derated_fueling_at_point_2", "word", 0x1104, 0x1A, "Same function (lhz)"),
    (0x5c2bc, "duty_cycle_monitor_high_cutoff_engine_speed", "word", 0x111C, 0x0,
     "cm848_updateDutyCycleMonitorLoadHistogram forms its address (addi)"),
    (0x40a64a, "duty_cycle_monitor_operating_region", "byte", 0x111F, 0x2,
     "cm848_updateDutyCycleMonitorLoadHistogram stores it (stb)"),
    (0x40a606, "compressor_inlet_density_source", "word", 0x18E8, 0x2,
     "cm848_calculateCompressorInletDensity stores it (sth)"),
    (0x405d4e, "injection_quantity_temperature_headroom_cap_exhaust_temperature_limit", "word", 0x1965, 0x4,
     "cm848_calculateTemperatureHeadroomFuelCap (lhz)"),
    (0x40a620, "coolant_temperature_state", "word", 0x19C2, 0x4, "cm848_selectCoolantTemperature stores it (sth)"),
    (0x40a60c, "compressor_inlet_temperature_state", "word", 0x1A0C, 0x4,
     "cm848_selectCompressorInletTemperature stores it (sth)"),
    (0x4090bc, "injector_driver_continuous_recharge_interval", "dword", 0x8041, 0x1C,
     "cm848_loadInjectorDriverCalibration (lwz)"),
    (0x5c78a, "intake_air_heater_fuel_threshold", "word", 0x8A2B, 0x2, "cm848_updateIntakeAirHeaterPostheat (lhz)"),
    (0x5c79c, "intake_air_heater_postheat_coolant_temperature_limit", "i16", 0x8A2B, 0x14,
     "cm848_updateIntakeAirHeaterPostheat (lha; a signed record, so i16)"),
    (0x5c7a8, "intake_air_heater_crank_off_engine_speed", "word", 0x8A2B, 0x20,
     "cm848_updateIntakeAirHeaterCrankPhase (lhz)"),
    (0x5c7aa, "intake_air_heater_crank_on_engine_speed", "word", 0x8A2B, 0x22, "Same function (lhz)"),
    (0x40af74, "exhaust_saturation_temperature_source", "word", 0x1982, 0xC,
     "cm848_calculateWaterVaporAndSaturationTemperatures copies charge_saturation_temperature_source into it (sth)"),
    (0x5a476, "j1939_default_engine_name", "byte", 0x10E3, 0xA,
     "The 8-byte J1939 NAME; cm848_copyROMCalibrationToRAM forms its address (addi)"),
    (0x5a47e, "j1939_default_retarder_name", "byte", 0x10E3, 0x12, "8 bytes; same copy (addi)"),
    (0x5a486, "j1939_command_security_flags", "dword", 0x10E3, 0x1A,
     "j1939_diagServiceDispatch forms its address (addi)"),
    (0x40ad6c, "j1939_engine_name", "byte", 0x11D7, 0x0,
     "The 8-byte J1939 NAME in RAM; cm848_copyROMCalibrationToRAM forms its address (addi)"),
    (0x40ad76, "j1939_engine_retarder_name", "byte", 0x11D7, 0xA, "8 bytes; same copy (addi)"),
    (0x5c2ec, "engine_protection_fueling_index_ramp_rate", "word", 0x10B4, 0x0,
     "cm848_calculateFaultDerateFuelLimit (lha, but the record is unsigned: word)"),
    (0x5c2f4, "engine_protection_maximum_shutdowns", "word", 0x10B9, 0x0,
     "cm848_checkEngineProtectionRestartLimitation and its sibling (lhz)"),
    (0x5b6d0, "mil_fault_indicator_bits", "byte", 0x11FA, 0x0,
     "A 22-byte bitmap, one bit per fault; cm848_latchNewlyActiveFault forms its address (addi)"),
    (0x5a496, "j1939_dm4_manufacturer_specific_parameters", "byte", 0x1228, 0xA,
     "6 bytes; cm848_j1939BuildDm4FreezeFrame forms its address (addi)"),
    (0x5a4aa, "fault_111_j1939_data", "byte", 0x1253, 0x2,
     "4 bytes; the DM2 / DM4 builders form its address (addi)"),
    (0x408b80, "chrysler_sci_data_plate", "byte", 0x1275, 0x0,
     "32 bytes; cm848_sciCommand42Callback forms its address (addi x5). The calibration_id_byte* rows inside it stay"),
    (0x5985a, "fault_code_assignment_table", "byte", 0x0024, 0x0,
     "1600 bytes; the fault scan and cm848_isDtcStoredOtherThanFault form its address (addi x4)"),
    (0x5f14e, "injector_bank_by_cylinder", "byte", 0x8042, 0x0,
     "8 bytes, one per cylinder; the injector selection forms its address (addi)"),
    (0x5f156, "injection_injector_by_cylinder", "byte", 0x8043, 0x0, "8 bytes; same (addi)"),
    (0x5f15e, "recharge_injector_by_cylinder", "byte", 0x8044, 0x0, "8 bytes; same (addi)"),
]
for item in ADD:
    add(*item)
p = g[idx["0x0040af72"]].split(",", 3)
assert p[1] == "fuel_demand_mode_active_flag", p[1]
new = "charge_saturation_temperature_source"
assert new not in names
g[idx["0x0040af72"]] = (
    f"0x0040af72,{new},{p[2]},e2m 1982 +A Charge_Saturation_Tmptr_Source 'Charge Saturation Temperature Source' "
    "(UNITLESS): cm848_calculateWaterVaporAndSaturationTemperatures sets it to 0 while charge_pressure_source, "
    "ambient_air_temperature_source and barometric_pressure_reference_source are all SENSOR_VALUE_SOURCE_PRIMARY and to 1 "
    "otherwise, and copies it into exhaust_saturation_temperature_source; the old name read the three checks as fuel "
    f"demand modes (was fuel_demand_mode_active_flag; {R}) | earlier note: {p[3]}")
mapping.append(f"0x0040af72,{new},fuel_demand_mode_active_flag,global,1")
open(gp, "w").write("\n".join(g))
with open(map_path, "w") as fh:
    fh.write("\n".join(mapping) + "\n")
print(f"{len(ADD)} rows added, 1 renamed")
