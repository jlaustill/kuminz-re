"""Round 45 stage A: the gap sweep's new blocks. Records from the default e2m CHR_CC_11.45.01.07 (each block has one
layout across the CHR_CC releases). Placement:
  8A88 (8 bytes)          0x409a8a-0x409a91  tiled: fills the gap between 8022 and 8114
  8A89 + 1D41 (28 bytes)  0x409ec6-0x409ee1  tiled: the only width match for the gap between 17C3 and 1D8D
  15C7 (18 bytes)         ROM 0x5c964-0x5c975 tiled: fills the gap between 1298 and 80C5
  8A7E (14 bytes)         0x408986-0x408993  tiled: fills the gap between 8D37 and 8C68
  14EB (6 bytes)          0x40add6-0x40addb  anchored at the start (after 1102) + field match (the rows quote its
                                             bracket codes DM13BRD / DM13HLDT / DM13FLTF)
  8B3C                    0x40913a           placed in round 12; three rows gain citations
Idempotent.  usage: apply_r45a.py <repo> <map.csv>"""
import ast
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
CM = os.path.join(repo, "firmware/CM848_S90140.06_analysis")
gp = os.path.join(CM, "output/global_variables.csv")
src = open("/home/linux/.claude/jobs/374b0424/tmp/w15/apply_hand_worklist.py").read()
BANNED = ast.literal_eval(re.search(r"BANNED = (\{.*?\})", src, re.S).group(1))
R = "PR #53 round 45"
ram = open(os.path.join(CM, "originals/cm848_ram.bin"), "rb").read()
rom = open(os.path.join(CM, "originals/cm848_rom.bin"), "rb").read()
E2M = os.path.join(repo, "e2m-analysis/CHR/CHR_CC_11.45.01.07.e2m")
recs = {}
for line in open(E2M, errors="replace"):
    head, _, desc = line.strip().partition(";")
    f = head.split(",")
    if len(f) > 11 and re.fullmatch(r"[0-9A-Fa-f]{4}", f[2]) and re.fullmatch(r"[0-9A-Fa-f]{1,4}", f[3]):
        recs.setdefault((int(f[2], 16), int(f[3], 16)), (f[0], f[1], f[7], f[9], f[10], desc.strip()))


def value(a, size, signed):
    if 0x3FA000 <= a < 0x3FA000 + len(ram):
        v = int.from_bytes(ram[a - 0x3FA000:a - 0x3FA000 + size], "big")
    else:
        v = int.from_bytes(rom[a:a + size], "big")
    return v - (1 << (8 * size)) if signed and v >> (8 * size - 1) else v


def cite(block, off, a, extra=""):
    name, unit, size, sign, scale, desc = recs[(block, off)]
    size = int(size)
    v = value(a, size, sign == "S")
    s = float(scale)
    unit = f"{unit}, " if unit.upper() not in ("NONE", "UNITLESS", "") else ""
    where = "the dump" if a >= 0x3FA000 else "ROM"
    return (f"e2m {block:04X} +{off:X} {name} '{desc}' ({unit}{'signed, ' if sign == 'S' else ''}{s:g} per count; "
            f"{v} = {v * s:.6g} in {where}){extra}.")


g = open(gp).read().split("\n")
idx = {l[:10]: k for k, l in enumerate(g) if l.startswith("0x")}
names = {l.split(",")[1] for l in g if l.startswith("0x") and len(l.split(",")) > 1}
if "engine_oil_pressure_filter_state" in names:
    print("already applied")
    sys.exit(0)
mapping = ["address,name,old_label,kind,dims"]


def row(a):
    p = g[idx[a]].split(",", 3)
    return p + [""] * (4 - len(p))


def prefix(a, cur, text):
    p = row(a)
    assert p[1] == cur, (a, p[1], cur)
    g[idx[a]] = f"{a},{p[1]},{p[2]},{text} {p[3]}".rstrip()


def name_row(a, cur, new, rendered, text, typ=None):
    p = row(a)
    assert p[1] == cur, (a, p[1], cur)
    assert new not in names and not any(t in BANNED for t in new.split("_")), new
    hist = f" (was {cur}; {R})" if cur else f" ({R})"
    rest = f" | earlier note: {p[3]}" if p[3] else ""
    g[idx[a]] = f"{a},{new},{typ or p[2]},{text}{hist}{rest}"
    names.add(new)
    mapping.append(f"{a},{new},{rendered},global,1")


def new_row(a, new, typ, text, rendered=None, before=None):
    assert a not in idx and new not in names and not any(t in BANNED for t in new.split("_")), new
    k = idx[before] if before else len(g)
    g.insert(k, f"{a},{new},{typ},{text} ({R})")
    idx.clear()  # the insert shifts every later line: rebuild the address index
    idx.update({l[:10]: j for j, l in enumerate(g) if l.startswith("0x")})
    names.add(new)
    if rendered:
        mapping.append(f"{a},{new},{rendered},global,1")


TILED = " - the block fills the gap between dumped-table blocks {} and {} exactly"
# --- 8A88: the injector diagnostic debounce limits
for a, cur, off in [("0x00409a8a", "injector_diagnostic_bits_fast_decay_debounce_limit", 0),
                    ("0x00409a8c", "injector_diagnostic_bits_open_circuit_debounce_limit", 2),
                    ("0x00409a8e", "injector_diagnostic_bits_short_to_ground_debounce_limit", 4),
                    ("0x00409a90", "injector_diagnostic_bits_short_to_battery_debounce_limit", 6)]:
    prefix(a, cur, cite(0x8A88, off, int(a, 16), TILED.format("8022", "8114") if off == 0 else ""))
# --- 8A89: the fuel level rationality monitor (the rows' low distance check)
for a, cur, off, size in [("0x00409ec6", "fuel_level_low_distance_level_threshold", 0, 2),
                          ("0x00409ec8", "fuel_level_low_distance_accumulator_limit", 2, 4),
                          ("0x00409ecc", "fuel_level_low_distance_vehicle_speed_scale", 6, 4),
                          ("0x00409ed0", "fuel_level_low_distance_check_start_delay_limit", 0xA, 2)]:
    prefix(a, cur, cite(0x8A89, off, int(a, 16), (TILED.format("17C3", "1D8D") + " with 1D41 after it")
                        if off == 0 else ""))
# --- 1D41: the fuel pressure idle rationality test (the rows' sensor plausibility check)
for a, cur, off in [("0x00409ed2", "fuel_pressure_sensor_plausibility_minimum_coolant_temperature", 0),
                    ("0x00409ed4", "fuel_pressure_sensor_plausibility_result_count_limit", 2),
                    ("0x00409ed5", "fuel_pressure_sensor_plausibility_maximum_setpoint_error", 3),
                    ("0x00409ed6", "fuel_pressure_sensor_plausibility_alternator_field_duty_threshold", 4),
                    ("0x00409ed8", "fuel_pressure_sensor_plausibility_in_gear_fuel_addend", 6),
                    ("0x00409edc", "fuel_pressure_sensor_plausibility_maximum_speed_error", 0xA),
                    ("0x00409ede", "fuel_pressure_sensor_plausibility_step_limit", 0xC),
                    ("0x00409ee0", "fuel_pressure_sensor_plausibility_maximum_vehicle_speed", 0xE)]:
    prefix(a, cur, cite(0x1D41, off, int(a, 16)))
name_row("0x00409eda", "fuel_pressure_sensor_plausibility_maximum_governor_output",
         "fuel_pressure_sensor_plausibility_maximum_throttle", "fuel_pressure_sensor_plausibility_maximum_governor_output",
         cite(0x1D41, 8, 0x409eda) + " The check runs only while all_speed_governor_equivalent_throttle is not above it "
         "(0 here: the throttle must be closed)")
# --- 15C7: the P0500 vehicle speed sensor monitor (ROM)
for a, cur, off in [("0x0005c964", "vehicle_speed_zero_under_load_event_limit", 0),
                    ("0x0005c966", "vehicle_speed_zero_under_load_minimum_boost_pressure", 2),
                    ("0x0005c96a", "vehicle_speed_zero_under_load_accelerator_off_idle_entry_limit", 6),
                    ("0x0005c96c", "vehicle_speed_signal_loss_minimum_vehicle_speed", 8),
                    ("0x0005c96e", "vehicle_speed_zero_under_load_minimum_engine_load", 0xA),
                    ("0x0005c970", "vehicle_speed_signal_loss_minimum_engine_load", 0xC),
                    ("0x0005c972", "vehicle_speed_zero_under_load_engine_load_filter_coefficient", 0xE),
                    ("0x0005c974", "vehicle_speed_zero_under_load_passes_per_event", 0x10)]:
    prefix(a, cur, cite(0x15C7, off, int(a, 16), TILED.format("1298", "80C5") if off == 0 else ""))
new_row("0x0005c968", "vehicle_speed_sensor_stopped_engine_speed", "word",
        cite(0x15C7, 4, 0x5c968) + " No direct access found (raw lis + displacement scan of the ROM and the live flash2)",
        before="0x0005c96a")
# --- 8A7E: the oil pressure gauge and the low oil switch. This truck runs the switch-only path
#     (oil_pressure_switch_only_cal set): the rpm x coolant model feeds engine_oil_pressure, the sensor-path threshold
#     is unused, and the switch drives the faults.
PATH = " This truck runs the switch-only path (oil_pressure_switch_only_cal set)"
prefix("0x00408986", "low_oil_pressure_check_minimum_rpm", cite(0x8A7E, 0, 0x408986, TILED.format("8D37", "8C68")))
prefix("0x00408988", "oil_pressure_switch_stuck_count_limit", cite(0x8A7E, 2, 0x408988) + " The stuck count runs while "
       "the engine is stopped and the switch shows no low pressure.")
name_row("0x0040898a", "", "engine_oil_pressure_filter_coefficient", "WORD_0040898a",
         cite(0x8A7E, 4, 0x40898a) + " The coefficient of engine_oil_pressure_filter_state, the EMA that turns "
         "oil_pressure_model_unfiltered into engine_oil_pressure (0 = no filtering)." + PATH)
prefix("0x0040898c", "low_oil_pressure_threshold", cite(0x8A7E, 6, 0x40898c) + " Used only on the sensor path, so it "
       "is unused on this truck.")
new_row("0x0040898e", "low_oil_switch_chime_enable", "word",
        cite(0x8A7E, 8, 0x40898e) + " cm848_processEngineOilPressure (lhz @ 0x51a5c4): when the switch error has "
        "persisted for oil_pressure_switch_fault_running_count_limit, a nonzero value also sets "
        "low_oil_pressure_active_flag and low_oil_pressure_derate_flag", rendered="DAT_0040898e", before="0x00408990")
prefix("0x00408990", "oil_pressure_switch_fault_running_count_limit", cite(0x8A7E, 0xA, 0x408990) + " The count runs "
       "while the switch error is set and the engine is running.")
new_row("0x00408992", "engine_oil_pressure_default", "word",
        cite(0x8A7E, 0xC, 0x408992) + " cm848_processEngineOilPressure (lhz @ 0x51a5b4): engine_oil_pressure takes "
        "this once the switch error has persisted for oil_pressure_switch_fault_running_count_limit",
        rendered="DAT_00408992", before="0x00408990")
name_row("0x003fceb4", "", "engine_oil_pressure_filter_state", "ema_filter_state_t_003fceb4",
         "The EMA that turns oil_pressure_model_unfiltered into engine_oil_pressure in cm848_processEngineOilPressure "
         "(switch-only path); its coefficient is engine_oil_pressure_filter_coefficient (e2m 8A7E +4 "
         "OPG_Pressure_Filter_Constant)")
# --- 14EB: the J1939 DM13 state
for a, cur, off in [("0x0040add6", "j1939_dm13_broadcast_enable_flags", 0),
                    ("0x0040add8", "j1939_dm13_hold_timer", 2),
                    ("0x0040adda", "j1939_dm13_fault_log_inhibit_flag", 4)]:
    prefix(a, cur, cite(0x14EB, off, int(a, 16), " - placed after 1102's end by field match (the gap is 24 bytes)"
                        if off == 0 else ""))
# --- 8B3C: the three rows round 12 left uncited
for a, cur, off in [("0x00409140", "fuel_metering_read_back_minimum_command", 6),
                    ("0x00409144", "fuel_pressure_governor_sensor_fault_command", 0xA),
                    ("0x0040914e", "fuel_metering_command_filter_coefficient", 0x14)]:
    prefix(a, cur, cite(0x8B3C, off, int(a, 16)))
open(gp, "w").write("\n".join(g))
with open(map_path, "w") as fh:
    fh.write("\n".join(mapping) + "\n")
print(f"{len(mapping) - 1} names for the proof map; rows cited and added")
