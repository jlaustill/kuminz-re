"""Stage 8c: the review fixes after stages 8 / 8b.
- Widths: three wave-13 rows were wider than their e2m record, so a neighbour rendered under their name or as a piece:
  0x408f56 word -> byte (8194 +0; its three lbz reads of +1 now go to crank_signal_window_with_added_tooth, typed byte at
  0x408f57), 0x40a87d dword -> word (11D4 +2, lhz only), 0x40a2b4 dword -> word (117D +4C, lhz / sth only).
- 80B9: the bits run in firing order (the ROM row table at 0x57d76 gives the open circuit codes P0201 / P0205 / P0203 /
  P0206 / P0202 / P0204 for bits 0-5), and the short to ground / short to battery caveat is reworded to what the code
  shows (different internal faults, one shared OBD slot).
- The facts stage 8b dropped from the gain comments (the scaling curves' e2m blocks, the window direction, no _cal).
- The gain scheduling curves: the 24 word[11] tables that cm848_calculateFuelMeteringCommand multiplies each gain or
  filter coefficient by (gain_scaling_tables.py maps each to its field and its e2m block) and HPCR_Governor_Mode, whose
  only use selects them. They had cam_sync_* names and a wrong _cal.
Writes map_stage8c.csv (address,name,old_label,kind).
usage: apply_stage8c.py <stage8 dir> <CM848 analysis dir>"""
import os
import sys

here, analysis = sys.argv[1:3]
out = os.path.join(analysis, "output")
ram = open(os.path.join(analysis, "originals", "cm848_ram.bin"), "rb").read()


def words(address, count):
    at = address - 0x3FA000
    return [int.from_bytes(ram[at + 2 * i:at + 2 * i + 2], "big") for i in range(count)]


# (address, old name, scaled field, e2m block / record, divisor of the product)
CURVES = [
    ("0x0040918a", "cam_sync_cyl1_timing_axis_a_cal", "proportional_small_signal_gain", "8005 HPCR_SF_Propcomp_Small_Signal_RPM_Axis", None),
    ("0x004091a0", "cam_sync_cyl1_timing_values_a_cal", "proportional_small_signal_gain", "8008 HPCR_SF_Propcomp_Small_Signal_SF_Axis", 4096),
    ("0x004091b6", "cam_sync_cyl2_timing_axis_a_cal", "proportional_positive_large_signal_gain", "8006 HPCR_SF_Propcomp_Positive_Large_Signal_RPM_Axis", None),
    ("0x004091cc", "cam_sync_cyl2_timing_values_a_cal", "proportional_positive_large_signal_gain", "8009 HPCR_SF_Propcomp_Positive_Large_Signal_SF_Axis", 4096),
    ("0x004091e2", "cam_sync_cyl3_timing_axis_a_cal", "proportional_negative_large_signal_gain", "8007 HPCR_SF_Propcomp_Negative_Large_Signal_RPM_Axis", None),
    ("0x004091f8", "cam_sync_cyl3_timing_values_a_cal", "proportional_negative_large_signal_gain", "800A HPCR_SF_Propcomp_Negative_Large_Signal_SF_Axis", 4096),
    ("0x0040920e", "cam_sync_cyl4_timing_axis_a_cal", "integral_small_signal_gain", "800B HPCR_SF_Integral_Small_Signal_RPM_Axis", None),
    ("0x00409224", "cam_sync_cyl4_timing_values_a_cal", "integral_small_signal_gain", "800E HPCR_SF_Integral_Small_Signal_SF_Axis", 4096),
    ("0x0040923a", "cam_sync_cyl5_timing_axis_a_cal", "integral_positive_large_signal_gain", "800C HPCR_SF_Integral_Positive_Large_Signal_RPM_Axis", None),
    ("0x00409250", "cam_sync_cyl5_timing_values_a_cal", "integral_positive_large_signal_gain", "800F HPCR_SF_Integral_Positive_Large_Signal_SF_Axis", 4096),
    ("0x00409266", "cam_sync_cyl6_timing_axis_a_cal", "integral_negative_large_signal_gain", "800D HPCR_SF_Integral_Negative_Large_Signal_RPM_Axis", None),
    ("0x0040927c", "cam_sync_cyl6_timing_values_a_cal", "integral_negative_large_signal_gain", "8010 HPCR_SF_Integral_Negative_Large_Signal_SF_Axis", 4096),
    ("0x00409292", "cam_sync_cyl4_timing_axis_b_cal", "derivative_small_signal_gain", "80E7 HPCR_SF_Derivative_Small_Signal_RPM_Axis", None),
    ("0x004092a8", "cam_sync_cyl4_timing_values_b_cal", "derivative_small_signal_gain", "80EA HPCR_SF_Derivative_Small_Signal_SF_Axis", 4096),
    ("0x004092be", "cam_sync_cyl5_timing_axis_b_cal", "derivative_positive_large_signal_gain", "80E8 HPCR_SF_Derivative_Positive_Large_Signal_RPM_Axis", None),
    ("0x004092d4", "cam_sync_cyl5_timing_values_b_cal", "derivative_positive_large_signal_gain", "80EB HPCR_SF_Derivative_Positive_Large_Signal_SF_Axis", 4096),
    ("0x004092ea", "cam_sync_cyl6_timing_axis_b_cal", "derivative_negative_large_signal_gain", "80E9 HPCR_SF_Derivative_Negative_Large_Signal_RPM_Axis", None),
    ("0x00409300", "cam_sync_cyl6_timing_values_b_cal", "derivative_negative_large_signal_gain", "80EC HPCR_SF_Derivative_Negative_Large_Signal_SF_Axis", 4096),
    ("0x00409316", "cam_sync_prot_gain_axis_cal", "derivative_filter_coefficient", "80ED HPCR_SF_Derivative_Constant_RPM_Axis", None),
    ("0x0040932c", "cam_sync_prot_gain_values_cal", "derivative_filter_coefficient", "80EE HPCR_SF_Derivative_Constant_SF_Axis", 65536),
    ("0x00409342", "cam_sync_scale_axis_cal", "sensor_filter_coefficient", "80F0 HPCR_SF_Fuel_Pressure_Constant_RPM_Axis", None),
    ("0x00409358", "cam_sync_scale_values_cal", "sensor_filter_coefficient", "80F1 HPCR_SF_Fuel_Pressure_Constant_SF_Axis", 65536),
]
TARGET = {"sensor_filter_coefficient": "fuel_pressure_sensor_filter_coefficient (the pressure sensor filter)",
          "derivative_filter_coefficient": "fuel_pressure_governor_derivative_gains.filter_coefficient"}
for term in ("proportional", "integral", "derivative"):
    for signal, field in (("small_signal", "small_signal_gain"), ("positive_large_signal", "positive_large_signal_gain"),
                          ("negative_large_signal", "negative_large_signal_gain")):
        TARGET[f"{term}_{signal}_gain"] = f"fuel_pressure_governor_{term}_gains.{field}"
MODE = ("0x004090fa", "cam_timing_alt_mode_enable_cal", "fuel_pressure_governor_gain_mode",
        "e2m 8000 +0 HPCR_Governor_Mode 'Switch to select governor mode' (byte; 0 here): its only use in the code is the"
        " test in cm848_calculateFuelMeteringCommand that, at 0, multiplies every fuel pressure governor gain and filter"
        " coefficient by its engine speed curve (the gain scaling tables at 0x40918a-0x40936d) before the P / I / D steps;"
        " otherwise the"
        " gains are used as stored. RAM outside the EEPROM mirror, so no _cal.")

lines = open(os.path.join(out, "global_variables.csv"), newline="").read().split("\n")
index = {l.split(",", 1)[0]: i for i, l in enumerate(lines) if l.startswith("0x")}


def row(address):
    a, name, typ, comment = (lines[index[address]].split(",", 3) + [""])[:4]
    return a, name, typ, comment


def put(address, name, typ, comment):
    lines[index[address]] = ",".join([address, name, typ, comment])


def insert_before_was(comment, text):
    at = comment.find(" (was ")
    assert at > 0, comment[:80]
    return comment[:at] + text + comment[at:]


mapping = []
# widths
for address, name, old_type, new_type, text in [
        ("0x00408f56", "backup_consecutive_error_threshold", "word", "byte",
         " Byte (stage 8c): the word row also covered 8194 +1, whose three lbz reads rendered under this name."),
        ("0x0040a87d", "master_slave_override_enable_flag", "dword", "word",
         " Word (stage 8c): every access is lhz; the dword row also covered 11D4 +4 MS_Final_Override_Timing (0x40a87f)."),
        ("0x0040a2b4", "ecm_power_down_delay_request_flag", "dword", "word",
         " Word (stage 8c): every access is lhz / sth; the dword row also covered 117D +4E (0x40a2b6).")]:
    a, n, t, c = row(address)
    assert (n, t) == (name, old_type), (address, n, t)
    put(address, n, new_type, insert_before_was(c, text))
a, n, t, c = row("0x00408f57")
assert (n, t, c) == ("crank_sync_reference_flag_cal", "", ""), (n, t, c)
put("0x00408f57", "crank_signal_window_with_added_tooth", "byte",
    "e2m 8194 +1 Bank_With_Added_Tooth 'which crank signal window has the cam +1 pulse' (UNITLESS, 0 / 1, 1 byte; 1 here):"
    " read three times with lbz - compared twice with the current crank signal window and once with bit 15 of"
    " tpu_a_ch0_param0.PARAM0. RAM outside the EEPROM mirror, so no _cal. (was crank_sync_reference_flag_cal)")
mapping.append(("0x00408f57", "crank_signal_window_with_added_tooth", "crank_sync_reference_flag_cal"))

# 80B9
ORDER = ("bit n = injector n + 1 in firing order (bits 0-5 = cylinders 1 / 5 / 3 / 6 / 2 / 4 by the open circuit codes"
         " P0201 / P0205 / P0203 / P0206 / P0202 / P0204 of the ROM row table at 0x57d76)")
for address in ("0x0040b8cc", "0x0040b8cd", "0x0040b8ce", "0x0040b8cf"):
    a, n, t, c = row(address)
    assert c.count("bit n = injector n + 1") == 1, address
    put(address, n, t, c.replace("bit n = injector n + 1", ORDER))
OLD_CAVEAT = (" The code treats the short to ground and short to battery bytes alike, so the e2m byte order (+2 Short_Ground /"
              " +3 Short_Vbatt) is the only evidence for which is which (wave 13 bin 3).")
NEW_CAVEAT = (" The two short classes set different internal faults (268 / 269 for the first injector in the ROM row table at"
              " 0x57d76) but both map to one OBD slot (P2146 for cylinders 1-3, P2149 for 4-6), so nothing in the code says"
              " which byte is short to ground: that rests on the e2m byte order (+2 Short_Ground / +3 Short_Vbatt) alone.")
for address in ("0x0040b8ce", "0x0040b8cf", "0x003fb700", "0x003fb6fe", "0x00409a8e", "0x00409a90"):
    a, n, t, c = row(address)
    assert c.count(OLD_CAVEAT) == 1, address
    put(address, n, t, c.replace(OLD_CAVEAT, NEW_CAVEAT))

# the facts stage 8b dropped
for address, text in [
        ("0x004094a2", " Scaling curves (engine speed; the product >> 12): e2m 8005 / 8008 for the small signal gain, 8006 /"
                       " 8009 positive large, 8007 / 800A negative large. The error is setpoint minus feedback, so the"
                       " positive window lies about 10 MPa below the setpoint. Never written by the code (constants"
                       " copied to RAM), so no _cal."),
        ("0x004094b2", " Scaling curves (the product >> 12): e2m 800B / 800E, 800C / 800F, 800D / 8010."),
        ("0x004094c2", " Scaling curves: e2m 80ED / 80EE for the filter coefficient (the product >> 16); 80E7 / 80EA, 80E8"
                       " / 80EB and 80E9 / 80EC for the gains (>> 12). Never written by the code (constants copied to"
                       " RAM), so no _cal.")]:
    a, n, t, c = row(address)
    put(address, n, t, insert_before_was(c, text))

# the gain scheduling curves and the mode switch
for address, old, scaled, record, divisor in CURVES:
    a, n, t, c = row(address)
    assert (n, t) == (old, "word[11]"), (address, n, t)
    base = ("fuel_pressure_sensor_filter_coefficient_scaling" if scaled == "sensor_filter_coefficient"
            else f"fuel_pressure_governor_{scaled}_scaling")
    new = base + ("_axis" if divisor is None else "_values")
    points = words(int(address, 16), 11)
    block, name = record.split(" ", 1)
    if divisor is None:
        what = (f"the engine speed axis (word[11]: header {points[0]}, then 10 points; {points[1] // 8}-{points[10] // 8}"
                f" rpm here)")
    else:
        what = (f"the scaling factors (word[11]: header {points[0]}, then 10 points in 1/{divisor};"
                f" {points[1] / divisor:.2f} to {points[10] / divisor:.2f} here)")
    comment = (f"e2m {block} +0 {name}: {what} of the curve that cm848_calculateFuelMeteringCommand multiplies"
               f" {TARGET[scaled]} by (product >> {12 if divisor == 4096 or divisor is None and 'coefficient' not in scaled else 16})"
               f" while fuel_pressure_governor_gain_mode is 0. RAM outside the EEPROM mirror, so no _cal. (was {old})")
    if c:
        comment += f" | earlier note: {c}"
    put(address, new, t, comment)
    mapping.append((address, new, old))
a, n, t, c = row(MODE[0])
assert (n, t) == (MODE[1], "byte"), (n, t)
put(MODE[0], MODE[2], t, f"{MODE[3]} (was {MODE[1]})" + (f" | earlier note: {c}" if c else ""))
mapping.append((MODE[0], MODE[2], MODE[1]))

open(os.path.join(out, "global_variables.csv"), "w", newline="").write("\n".join(lines))
with open(os.path.join(here, "map_stage8c.csv"), "w") as f:
    f.write("address,name,old_label,kind\n")
    for address, new, old in mapping:
        f.write(f"{address},{new},{old},global\n")
print(f"{len(mapping)} renames, 4 width fixes, 10 80B9 comment fixes, 3 restored notes")
