"""Round 18 stage C (types):
- MAIN_INJECTION_TIMING_SELECTION on main_injection_timing_selection (e2m 8085 +0 Main_SOI_Selection_Switch labels
  '3=HPCRINCR:2=USEROVRD:1=HPCRTMNG:0=NOADJUST'; compared with 1 / 2 / 3).
- INJECTION_TIMING_COMBINATION_MODE on injection_timing_main_combination_mode (e2m 8085 +2 Main_Cold_Advance_Select
  '0=add coolant and intake adv,1=MAX WINS,2=MIN WINS'; compared with 0 / 1, else 2).
- algorithm_enable_flags_4_t, a word bitfield on algorithm_enable_flags_4_cal (0x3fd5a4, EEPROM 0x122): bit 0
  User_Commanded_Fueling_Enable, bit 8 User_Commanded_Timing_Enable (e2m 106B +A); both read with masks only.
- 2-D lookup caches typed word[2] (the round 10 rule) and named after their tables:
  - the 4D timing maps' caches at 0x3fa878 / 0x3fa87c (were dual_axis_table_dims_t instances 'row_count / col_count',
    with label rows at +2; the struct type and the labels go);
  - the altitude derate caches at 0x3fb9ca / 0x3fb9ce (were 'dims' words) and 0x3fb9d2 (no row).
usage: apply_r18c.py <repo>"""
import os
import sys

out = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output")
ENUMS = """# MAIN_INJECTION_TIMING_SELECTION: how main_injection_timing is produced (PR #53 round 18) - e2m 8085 +0
# Main_SOI_Selection_Switch value labels; cm848_selectMainInjectionTiming
MAIN_INJECTION_TIMING_SELECTION,0,MAIN_INJECTION_TIMING_SELECTION_NO_ADJUSTMENT,No change to main_injection_timing (e2m NOADJUST),2
MAIN_INJECTION_TIMING_SELECTION,1,MAIN_INJECTION_TIMING_SELECTION_CALCULATED,cm848_calculateMainInjectionTiming (e2m HPCRTMNG: the fuel system's timing); this truck,2
MAIN_INJECTION_TIMING_SELECTION,2,MAIN_INJECTION_TIMING_SELECTION_USER_OVERRIDE,user_commanded_injection_timing_cal (e2m USEROVRD),2
MAIN_INJECTION_TIMING_SELECTION,3,MAIN_INJECTION_TIMING_SELECTION_CALCULATED_PLUS_USER_INCREMENT,The calculated timing plus user_commanded_injection_timing_cal and the top dead center offset (e2m HPCRINCR),2
# INJECTION_TIMING_COMBINATION_MODE: how cm848_calculateMainInjectionTiming combines its components (PR #53 round 18) -
# e2m 8085 +2 Main_Cold_Advance_Select
INJECTION_TIMING_COMBINATION_MODE,0,INJECTION_TIMING_COMBINATION_SUM,The sum of the components clamped to +-1024 (e2m 'add coolant and intake adv'),2
INJECTION_TIMING_COMBINATION_MODE,1,INJECTION_TIMING_COMBINATION_MAXIMUM,The largest component wins (e2m MAX WINS); this truck,2
INJECTION_TIMING_COMBINATION_MODE,2,INJECTION_TIMING_COMBINATION_MINIMUM,The smallest component wins (e2m MIN WINS),2
"""
BITS = {0: ("user_commanded_fueling_enable", "e2m 106B +A User_Commanded_Fueling_Enable [FSUCFLEN] 'Bit 0 Word 4': "
            "cm848_selectUserCommandedFueling uses the user commanded fueling while it is set"),
        8: ("user_commanded_timing_enable", "e2m 106B +A User_Commanded_Timing_Enable [TSUCTAEN] 'Bit 8 of word 4': "
            "cm848_calculateFourDimensionalInjectionTiming takes user_commanded_injection_timing_cal as the 4D timing "
            "while it is set")}
struct_rows = ["# algorithm_enable_flags_4_t: algorithm enable flags word 4 (EEPROM 0x122, e2m 106B +A; PR #53 round 18); "
               "0 in the dump"]
for bit in range(16):
    name, comment = BITS.get(bit, (f"reserved_bit_{bit}", "no e2m name; no reader"))
    struct_rows.append(f'algorithm_enable_flags_4_t,,{name},bitfield:1@{bit},{2 if bit == 0 else 0},"{comment}",,verified')
sp = os.path.join(out, "structure_definitions.csv")
t = open(sp).read()
old_dims = ("dual_axis_table_dims_t,0x003fa878,row_count,word,2,Number of first-axis (RPM) breakpoints,,verified\n"
            "dual_axis_table_dims_t,0x003fa878,col_count,word,2,Number of second-axis (fuel) breakpoints,,verified\n"
            "dual_axis_table_dims_t,0x003fa87c,,,,governor offset table B - second instance,,verified\n")
assert t.count(old_dims) == 1
t = t.replace(old_dims, "")
assert "algorithm_enable_flags_4_t" not in t
anchor = t.index("algorithm_enable_flags_41_t,,")
start = t.rfind("\n", 0, anchor) + 1
t = t[:start] + "\n".join(struct_rows) + "\n" + t[start:]
open(sp, "w").write(t)
ep = os.path.join(out, "enums.csv")
e = open(ep).read()
assert "MAIN_INJECTION_TIMING_SELECTION" not in e
open(ep, "w").write(e.rstrip("\n") + "\n" + ENUMS)
CACHE = "Lookup cache (word[2]: the x / y segment offsets kept by cm848_dualAxisTableInterpolation; 2 / 2 at power-up)"
RETYPE = {
    "0x00409e40": (None, "MAIN_INJECTION_TIMING_SELECTION", None),
    "0x00409e42": (None, "INJECTION_TIMING_COMBINATION_MODE", None),
    "0x003fd5a4": (None, "algorithm_enable_flags_4_t", None),
    "0x003fa878": ("four_dimensional_injection_timing_map_a_cached_axis_offsets", "word[2]",
                   CACHE + " of four_dimensional_injection_timing_map_a (was the dual_axis_table_dims_t instance "
                   "rpm_governor_offset_table_a_dims: its 'row_count / col_count' were these offsets)"),
    "0x003fa87c": ("four_dimensional_injection_timing_map_b_cached_axis_offsets", "word[2]",
                   CACHE + " of four_dimensional_injection_timing_map_b (was rpm_governor_offset_table_b_dims)"),
    "0x003fb9ca": ("fuel_limit_barometric_ambient_air_cached_axis_offsets", "word[2]",
                   CACHE + " of the altitude derate's cool / hot ambient air grids (fuel_limit_barometric_*; they share "
                   "the axes) (was fuel_correction_table_dims_a word)"),
    "0x003fb9ce": ("fuel_limit_barometric_temperature_band_cached_axis_offsets", "word[2]",
                   CACHE + " of fuel_limit_barometric_temperature_band_grid (was fuel_correction_temp_band_dims_b word)"),
}
DELETE = {"0x003fa87a", "0x003fa87e"}
NEW = ("0x003fb9d2", "fuel_limit_barometric_air_handling_fault_cached_axis_offsets", "word[2]",
       CACHE + " of fuel_limit_barometric_air_handling_fault_grid (cm848_calculateAltitudeDerateFuelLimit)")
gp = os.path.join(out, "global_variables.csv")
lines = open(gp).read().split("\n")
index = {l[:10]: i for i, l in enumerate(lines) if l.startswith("0x")}
assert NEW[0] not in index
for a in list(RETYPE) + sorted(DELETE):
    assert a in index, a
for a, (name, typ, comment) in RETYPE.items():
    i = index[a]
    addr, n, t0, c = (lines[i].split(",", 3) + ["", "", ""])[:4]
    if comment is None:
        lines[i] = ",".join([addr, n, typ, c + f" | typed {typ} in PR #53 round 18 (was {t0})"])
    else:
        lines[i] = ",".join([addr, name, typ, comment + (" | earlier note: " + c if c else "")])
for a in DELETE:
    lines[index[a]] = None
i = index["0x003fb9ce"]
lines[i] = lines[i] + "\n" + ",".join(NEW)
MORE = [
    ("0x003fcdc4", "coolant_overheat_derate_final_fueling_state_previous", "FUELING_STATE",
     "final_fueling_state as cm848_runCoolantOverheatFuelDerate last saw it: "
     "cm848_rampCoolantOverheatDerateMinimumInjectionTiming starts the timing minimum when the state enters "
     "FUELING_STATE_COOLANT_OVERHEAT_DERATE (46) from another"),
    ("0x003fcdd2", "coolant_overheat_derate_minimum_injection_timing_cached_axis_offset", "word",
     "Lookup cache of coolant_overheat_derate_minimum_injection_timing_axis (2 after cm848_resetCoolantOverheatFuelDerate)"),
]
for a, name, typ, comment in MORE:
    assert a not in index, a
    v = int(a, 16)
    prev = max((k for k in index if int(k, 16) < v and lines[index[k]] is not None), key=lambda k: int(k, 16))
    j = index[prev]
    lines[j] = lines[j] + "\n" + ",".join([a, name, typ, comment])
open(gp, "w").write("\n".join(l for l in lines if l is not None))
print("2 enums, 1 bitfield struct (16 bits), 1 struct type removed, 7 rows retyped, 2 label rows removed, 1 new row")
