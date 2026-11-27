"""For each array candidate (address, element type, count), list the CSV rows inside the would-be range (they must be
folded in), the DAT_ labels inside it that the code uses, and how the code addresses the base ((&x)[i], x + n, ...).
usage: array_candidates.py <global_variables.csv> <cpp>"""
import re
import sys

gv, cpp = sys.argv[1:3]
SIZES = {"byte": 1, "word": 2, "i16": 2, "dword": 4}
CANDIDATES = [  # address, name, element type, count
    (0x3fb900, "switch_input_debounce_history", "byte", 16),
    (0x3fd0ca, "fuel_pressure_setpoint_map_cached_axis_offsets", "word", 16),
    (0x3fdb8e, "switch_input_hardware_line_cal", "word", 32),
    (0x3fba38, "fuel_demand_timing_demand_ring_buf", "word", 150),
    (0x40877e, "cold_start_coolant_bucket_thresholds", "word", 5),
    (0x40ad56, "j1939_receive_source_address_whitelist", "byte", 4),
    (0x3fce55, "intake_air_heater_level_duration_table", "word", 4),
    (0x409ee2, "fuel_pressure_sensor_plausibility_expected_fuel_demand_table", "word", 5),
    (0x40b9ee, "misfire_monitor_cylinder_attempt_counts", "word", 6),
    (0x3fd1ff, "misfire_monitor_cylinder_misfire_flags", "byte", 6),
]
rows = {}
for line in open(gv):
    m = re.match(r"^(0x[0-9a-f]{8}),([^,]*),([^,]*),", line)
    if m:
        rows.setdefault(int(m.group(1), 16), (m.group(2), m.group(3)))
text = open(cpp).read()
for addr, name, typ, count in CANDIDATES:
    end = addr + SIZES[typ] * count
    inside = [(f"0x{a:06x}", rows[a]) for a in sorted(rows) if addr < a < end]
    dats = sorted({m for m in re.findall(r"DAT_00([0-9a-f]{6})", text) if addr < int(m, 16) < end})
    forms = {
        "(&x)[i]": len(re.findall(r"\(&" + re.escape(name) + r"\)\[", text)),
        "x[i]": len(re.findall(r"(?<![&A-Za-z0-9_])" + re.escape(name) + r"\[", text)),
        "plain": len(re.findall(r"(?<![&A-Za-z0-9_(])" + re.escape(name) + r"(?![A-Za-z0-9_\[])", text)),
        "&x": len(re.findall(r"&" + re.escape(name) + r"(?![A-Za-z0-9_])(?!\)\[)", text)),
    }
    print(f"{name} @0x{addr:06x} {rows.get(addr)} -> {typ}[{count}] (to 0x{end:06x}): inside rows {inside[:6]} "
          f"| DAT_ inside {dats[:8]} | forms {forms}")
