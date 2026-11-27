"""Round 52 stage A (labels / rows / comments only): the rest of round 51's transmission RAM and the governor pressure
blocks' unplaced records.
  8B9A (RAM 0x40b620, two records on two rows): RE_Trans_Temp_Diag_Initial / Trans_Sump_Limpin_Delay. Round 51 wrote
       that the limp-in timer has no RAM record of its own in the e2m - wrong, it is 8B9A +2.
  8BB4 (RAM 0x40b62c, four records on four rows): the output shaft speed sensor's period / average / constant /
       actual. With 8B9A, 8C2D and 8B6C, RAM 0x40b620-0x40b647 is four absent blocks back to back.
  8BB5 +50 / +52 (0x408b30 / 0x408b32) and 8BB6 +1A (RAM 0x40b5a6): the VFS PWM driver's off-cycle (inhibit off
       time / timer offset / timer). Nothing accesses them: in this build a driver read-back fault only latches
       governor_pressure_solenoid_read_back_fault_latched_flag (8BB6 +18). Documentation rows.
  8BB5 +54 (0x408b34): RE_VFS_PWM_On_Time_Init on governor_pressure_controller_initial_output (cite).
  8BB3 (EEPROM mirror 0x3fedfe): RE_Axle_Ratio_Factor_Learned on the struct field
       diag_clear_flags_t.learned_output_speed_to_vehicle_speed_ratio (5141 x 0.0078125 = 40.16 rpm per mph, the
       default 8BB2 +0 = 42); cited in the field comment.
Idempotent.  usage: apply_r52a.py <repo> <map.csv>"""
import ast
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
CM = os.path.join(repo, "firmware/CM848_S90140.06_analysis")
gp = os.path.join(CM, "output/global_variables.csv")
sp = os.path.join(CM, "output/structure_definitions.csv")
src = open("/home/linux/.claude/jobs/374b0424/tmp/w15/apply_hand_worklist.py").read()
BANNED = ast.literal_eval(re.search(r"BANNED = (\{.*?\})", src, re.S).group(1))
R = "PR #53 round 52"
ram = open(os.path.join(CM, "originals/cm848_ram.bin"), "rb").read()
rom = open(os.path.join(CM, "originals/cm848_rom.bin"), "rb").read()
recs, label_sets = {}, {}
for line in open(os.path.join(repo, "e2m-analysis/CHR/CHR_CC_11.45.01.07.e2m"), errors="replace"):
    head, _, desc = line.strip().partition(";")
    f = head.split(",")
    if len(f) > 11 and re.fullmatch(r"[0-9A-Fa-f]{4}", f[2]) and re.fullmatch(r"[0-9A-Fa-f]{1,4}", f[3]):
        key = (int(f[2], 16), int(f[3], 16))
        recs.setdefault(key, (f[0], f[1], f[7], f[9], f[10], desc.strip(), ""))
        if len(f) > 19 and "=" in f[19]:  # long label lists are split over duplicate records: merge them all
            label_sets.setdefault(key, set()).update(x for x in f[19].split(":") if "=" in x)
for key, labs in label_sets.items():
    merged = ":".join(sorted(labs, key=lambda x: int(x.split("=")[0], 16)))
    recs[key] = recs[key][:6] + (merged,)


def numeric_scale(scale):
    if re.fullmatch(r"0[0-9A-Fa-f]+", scale) or re.search(r"[A-Da-fF]", scale.replace("E-", "").replace("E+", "")):
        return None
    try:
        return float(scale)
    except ValueError:
        return None


def cite(block, off, a):
    name, unit, size, sign, scale, desc, labels = recs[(block, off)]
    size = int(size)
    if 0x3FA000 <= a < 0x3FA000 + len(ram):
        v, where = int.from_bytes(ram[a - 0x3FA000:a - 0x3FA000 + size], "big"), "the dump"
    else:
        v, where = int.from_bytes(rom[a:a + size], "big"), "ROM"
    if sign == "S" and v >> (8 * size - 1):
        v -= 1 << (8 * size)
    head = f"e2m {block:04X} +{off:X} {name} '{desc}'"
    if unit.upper() == "HEX":
        return f"{head} (bit-mapped; 0x{v:0{2 * size}x} in {where})."
    s = numeric_scale(scale)
    unit = f"{unit}, " if unit.upper() not in ("NONE", "UNITLESS", "") else ""
    if s is None:
        lab = f" {labels.replace(':', ' / ')};" if labels else ""
        return f"{head} ({unit}enumerated;{lab} {v} in {where})."
    return f"{head} ({unit}{'signed, ' if sign == 'S' else ''}{s:g} per count; {v} = {v * s:.6g} in {where})."


g = open(gp).read().split("\n")
names = {l.split(",")[1] for l in g if l.startswith("0x") and len(l.split(",")) > 1}
if "governor_pressure_solenoid_retest_pass_count" in names:
    print("already applied")
    sys.exit(0)


def index():
    return {l[:10]: k for k, l in enumerate(g) if l.startswith("0x")}


idx = index()


def row(a):
    p = g[idx[a]].split(",", 3)
    return p + [""] * (4 - len(p))


def cite_only(a, cur, block, off, extra=""):
    p = row(a)
    assert p[1] == cur, (a, p[1], cur)
    assert f"e2m {block:04X} +{off:X} " not in p[3], (a, "already cited")
    g[idx[a]] = f"{a},{p[1]},{p[2]},{cite(block, off, int(a, 16))}{extra} ({R}) {p[3]}".rstrip()


def add(a, new, typ, block, off, text):
    global idx
    assert a not in idx, a
    assert new not in names and not any(t in BANNED for t in new.split("_")), new
    names.add(new)
    later = sorted(x for x in idx if int(x, 16) > int(a, 16))
    g.insert(idx[later[0]] if later else len(g), f"{a},{new},{typ},{cite(block, off, int(a, 16))} {text} ({R})")
    idx = index()


SEL = "cm848_selectTransmissionTemperatureInUse"
# ---- 8B9A at RAM 0x40b620 -------------------------------------------------------------------------------------
cite_only("0x0040b620", "transmission_temperature_adc_previous_reading", 0x8B9A, 0,
          " The 8B9A layout (two records) matches 0x40b620-0x40b625; with 8C2D (0x40b626) / 8BB4 (0x40b62c) / 8B6C "
          "(0x40b638) the RAM 0x40b620-0x40b647 is four absent blocks back to back. Once the raw reading has repeated "
          "transmission_temperature_adc_unchanged_reading_limit times the check stops and this word keeps that initial "
          "sample")
p = row("0x0040b622")
stale = "e2m 8B9B's 'Trans Temp Delay Timer' (Trans_Sump_Limpin_Delay; no RAM record of its own in the e2m): "
assert p[1] == "transmission_temperature_limp_in_delay_timer" and p[3].startswith(stale), p[3][:120]
g[idx["0x0040b622"]] = (f"{','.join(p[:3])},{cite(0x8B9A, 2, 0x40b622)} Its reload and speed gate are the 8B9B "
                        f"calibrations; round 51's note that the timer had no RAM record was wrong ({R}): "
                        + p[3][len(stale):])
# ---- 8BB4 at RAM 0x40b62c ---------------------------------------------------------------------------------------
cite_only("0x0040b62c", "transmission_output_speed_period_microseconds", 0x8BB4, 0,
          " The 8BB4 layout (four records) matches the four output shaft speed sensor words 0x40b62c-0x40b637 record "
          "for record")
cite_only("0x0040b630", "transmission_output_speed_in_use_unfiltered", 0x8BB4, 4)
cite_only("0x0040b632", "transmission_output_speed_numerator", 0x8BB4, 6)
cite_only("0x0040b636", "transmission_output_speed_sensor_filtered", 0x8BB4, 0xA)
# ---- 8BB5 tail / 8BB6 +1A: the VFS PWM driver off-cycle, absent from this build's code --------------------------
NONE = ("No direct access found (raw lis + displacement scan of the ROM and the live flash2; the r29 base the read-back "
        "debounce uses for 0x40b5a4 is read at +0 / +42 only): the off-cycle these records describe is not implemented "
        "in this build - a driver read-back fault only latches governor_pressure_solenoid_read_back_fault_latched_flag "
        "(8BB6 +18) so its check stops")
RETEST = (". Named like the drivers that do retest: the same e2m records are cooling_fan_retest_off_passes / "
          "_fault_confirm_passes / _pass_count (8B23 +A6 / +A8, 8B22 +3E) and alternator_field_retest_* (8A5F +5C "
          "/ +5E, 8A60 +2C)")
add("0x00408b30", "governor_pressure_solenoid_retest_off_passes", "word", 0x8BB5, 0x50, NONE + RETEST)
add("0x00408b32", "governor_pressure_solenoid_retest_fault_confirm_passes", "word", 0x8BB5, 0x52, NONE + RETEST)
cite_only("0x00408b34", "governor_pressure_controller_initial_output", 0x8BB5, 0x54,
          " RE_VFS_PWM_On_Time is governor_pressure_controller_output (8BB6 +16)")
add("0x0040b5a6", "governor_pressure_solenoid_retest_pass_count", "word", 0x8BB6, 0x1A, NONE + RETEST)
# ---- six more absent blocks, found by record_for_record_matches.py and read by meaning ---------------------------
mapping = ["address,name,old_label,kind,dims"]
WIDTH = {"byte": 1, "word": 2, "i16": 2, "dword": 4}
RENAMES = {
    # 8B21 (the radiator fan speed sensor): the family of the transmission's 8BB2 rows (same e2m layout)
    "0x004088c8": ("radiator_fan_speed_short_period_value", "radiator_fan_speed_maximum",
                   "The fan speed reported while the sensor period is under radiator_fan_speed_period_minimum; the twin "
                   "of transmission_output_speed_maximum (8BB2 +4)"),
    "0x004088ca": ("radiator_fan_speed_long_period_value", "radiator_fan_speed_minimum",
                   "The fan speed reported while the sensor period is over radiator_fan_speed_period_maximum"),
    "0x004088ce": ("radiator_fan_speed_long_period_limit", "radiator_fan_speed_period_maximum",
                   "Longest accepted fan speed sensor period (above it the speed is radiator_fan_speed_minimum)"),
    "0x004088d2": ("radiator_fan_speed_short_period_limit", "radiator_fan_speed_period_minimum",
                   "Shortest accepted fan speed sensor period (below it the speed is radiator_fan_speed_maximum)"),
    "0x004088d9": ("radiator_fan_speed_prescaler", "radiator_fan_pulses_per_revolution",
                   "Fan speed sensor teeth per revolution: the fan speed numerator is pulses per measurement x 60e6 / "
                   "this (the old name read it as a prescaler); the twin of output_speed_sensor_pulses_per_revolution"),
    "0x004088de": ("radiator_fan_pulses_per_measurement_type_5100", "radiator_fan_pulses_per_measurement_end_of_line",
                   "Fan speed sensor pulses per measurement used instead of radiator_fan_pulses_per_measurement while "
                   "end_of_line_test_settings_cal.field_mode_register = 5100 (the end-of-line field mode)"),
    # 15B4 (the reset capture): the SPRG names said where the values travel, not what they are
    "0x0040c122": ("exception_sprg0", "exception_srr0",
                   "SRR0 at the last exception: the exception entry stubs (0x10650 / 0x106a8 / 0x541b0) move SRR0 into "
                   "SPRG0 (mfspr SRR0 / mtspr SPRG0) and cm848_applicationMain copies SPRG0 here after the reset"),
    "0x0040c126": ("exception_sprg1", "exception_vector",
                   "The exception vector byte the entry stubs put in SPRG1 (lbz then mtspr SPRG1); "
                   "cm848_applicationMain copies SPRG1 here"),
    "0x0040c128": ("exception_sprg2", "exception_link_register",
                   "The link register at the last exception: the entry stubs move LR into SPRG2 (mfspr LR / mtspr SPRG2) "
                   "and cm848_applicationMain copies SPRG2 here"),
    "0x0040c134": ("hardware_timer_capture", "power_on_reset_to_first_executive_frame_time",
                   "cm848_applicationMain latches the time base (TBL) here once (only while it is 0) after its "
                   "initialization calls and just before the background loop starts"),
}


def rename(a, cur, new, block, off, text):
    p = row(a)
    assert p[1] == cur, (a, p[1], cur)
    assert new not in names and not any(t in BANNED for t in new.split("_")), new
    names.add(new)
    g[idx[a]] = (f"{a},{new},{p[2]},{cite(block, off, int(a, 16))} {text} (was {cur}; {R})"
                 + (f" | earlier note: {p[3]}" if p[3] else ""))
    mapping.append(f"{a},{new},{cur},global,1")


def cite_block(block, base, note):
    """cite every record of the block on its row (all of them have one, width checked); rename the RENAMES rows"""
    first = True
    for off in sorted(o for (b, o) in recs if b == block):
        name, unit, size, sign, scale, desc, labels = recs[(block, off)]
        a = f"0x{base + off:08x}"
        p = row(a)
        w = WIDTH.get(p[2])
        assert w is None or w == int(size), (a, p[1], p[2], size)
        extra = note if first else ""
        first = False
        if a in RENAMES:
            cur, new, text = RENAMES[a]
            rename(a, cur, new, block, off, text + extra)
        else:
            cite_only(a, p[1], block, off, extra)


LAYOUT = (" The {} layout ({} records) matches the rows {:#x}-{:#x} record for record (record_for_record_matches.py, read "
          "by meaning)")


def note(block, base):
    offs = sorted(o for (b, o) in recs if b == block)
    end = base + offs[-1] + int(recs[(block, offs[-1])][2]) - 1
    return LAYOUT.format(f"{block:04X}", len(offs), base, end)


for block, base in ((0x8B23, 0x408814), (0x8A5F, 0x4087a0), (0x8B22, 0x40b292), (0x8A60, 0x40b25c),
                    (0x8B21, 0x4088c8), (0x15B4, 0x40c120)):
    cite_block(block, base, note(block, base))
assert len(mapping) - 1 == len(RENAMES), (len(mapping), len(RENAMES))
open(gp, "w").write("\n".join(g))
with open(sys.argv[2], "w") as fh:
    fh.write("\n".join(mapping) + "\n")
# ---- 8BB3 on diag_clear_flags_t.learned_output_speed_to_vehicle_speed_ratio --------------------------------------
t = open(sp).read()
key = "diag_clear_flags_t,0x003fedfc,learned_output_speed_to_vehicle_speed_ratio,word,2,"
assert t.count(key) == 1
i = t.index(key) + len(key)
old_comment = t[i:t.index(",,best_guess", i)]
assert "," not in old_comment and "8BB3" not in old_comment
new_comment = ("e2m 8BB3 +0 RE_Axle_Ratio_Factor_Learned 'Ratio of transmission output shaft speed to road speed (NV "
               "ratio)' (0.0078125 per count = rpm per mph; 5141 = 40.16 in the dump; the default 8BB2 +0 "
               f"output_speed_to_vehicle_speed_default_ratio = 42 on the same scale; EEPROM 0x197c) ({R}): ") + old_comment
assert "," not in new_comment
open(sp, "w").write(t[:i] + new_comment + t[i + len(old_comment):])
print("round 52 stage A applied")
