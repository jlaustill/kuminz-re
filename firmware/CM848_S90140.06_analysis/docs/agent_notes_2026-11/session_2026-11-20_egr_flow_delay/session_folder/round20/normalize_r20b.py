"""Proof helper for round 20 stage B: rewrite each algorithm_enable_flags_3_cal bitfield read in the new .cpp back to
the old masked form (algorithm_enable_flags_3_cal & mask), the mask as Ghidra writes it (decimal below 10, else hex).
usage: normalize_r20b.py <new.cpp> <out.cpp>"""
import re
import sys

FIELDS = {"power_take_off_enable": 0x10, "cruise_control_enable": 0x40, "road_speed_governor_enable": 0x80,
          "road_speed_governor_without_droops_below_top_gear": 0x100, "cruise_save_set_speed_at_power_down_enable": 0x8000,
          "idle_speed_adjust_enable": 0x8, "cruise_governor_droop_enable": 0x400}
text = open(sys.argv[1]).read()
counts = {}
for field, mask in FIELDS.items():
    m = str(mask) if mask < 10 else f"0x{mask:x}"
    text, counts[field] = re.subn(rf"\balgorithm_enable_flags_3_cal\.{field}\b", f"(algorithm_enable_flags_3_cal & {m})", text)
open(sys.argv[2], "w").write(text)
print({k: v for k, v in counts.items() if v}, "total", sum(counts.values()))
