"""Round 83 stage A (CM550): the TPU microcode images in ROM, and the six pwmTimer* functions renamed for the engine
position work they do (round 81's hardware name check: they touch only the TPU, not a PWM module). Idempotent; keeps
line endings. usage: apply_r83a.py <repo> <map.csv>"""
import os
import sys

repo, map5 = os.path.abspath(sys.argv[1]), sys.argv[2]
O5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
R = "PR #53 round 83"
F5, G5 = os.path.join(O5, "function_renames.csv"), os.path.join(O5, "global_variables.csv")
RENAMES = [
    ("0x00034674", "mc68k_pwmTimerMode0Init", "mc68k_initializeSpeedMeasurementMode0",
     "When speed_measurement_mode is 0: sets TPU channel 0 to function 0xc (CFSR3 bits 3-0) - parameter 2 = "
     "_DAT_00807ec8 / 6 - parameter 1 = 0xe - and the handler pointer _DAT_00808edc = 0x19c88. No PWM module is "
     "involved"),
    ("0x0003478c", "mc68k_pwmTimerMode0Reset", "mc68k_resetSpeedMeasurementMode0",
     "Resets TPU channel 0's speed measurement mode 0 parameters (0-2) by speed_measurement_mode. No PWM module is "
     "involved"),
    ("0x0003480e", "mc68k_pwmTimerMode1ChannelSetup", "mc68k_setUpTpuChannel3AnglePulseOutput",
     "Sets up the angle-based pulse output on TPU channel 3 (function 8 in CFSR3 bits 15-12): the pulse start and end as "
     "a tooth number plus a fraction from index_of_first_tdc_after_missed_pulse_1_6 - "
     "_dzg_angle_after_cyl_tdc_angle_after_cyl_tdc_to_put_dzg_first_60_60 - "
     "_engine_position_offset_distance_between_tooth_0_and_tdc_1_100_100 - the per-cylinder offsets at 0x80a23a and "
     "_dzg_angular_duration_angular_high_duration_of_dzg_pulse_at_tpu_0_60 - modulo the teeth "
     "(pmm_num_of_teeth_correct_tooth_count_at_missing_tooth_0_255 + 2). The Cummins names call this pulse the DZG pulse. "
     "No PWM module is involved"),
    ("0x0003494a", "mc68k_pwmTimerMode1Update", "mc68k_updateTpuChannel3AnglePulseOutput",
     "Recomputes the TPU channel 3 angle pulse's start and end for current_cylinder_index (the same arithmetic as "
     "mc68k_setUpTpuChannel3AnglePulseOutput) and writes them to its parameters. No PWM module is involved"),
    ("0x00034a82", "mc68k_pwmTimerModeDispatcher", "mc68k_configureTpuChannelsForSpeedMeasurementMode",
     "Reprograms TPU channels 0 and 3 for speed_measurement_mode: in mode 0 channel 0 parameter 2 = _DAT_00807ec8 / 6 and "
     "channel 3 takes function 0xa (CFSR3 bits 15-12) - mode 1 uses the angle pulse output (function 8). No PWM module "
     "is involved"),
    ("0x00034b20", "mc68k_pwmTimerCycleAdvance", "mc68k_alignCylinderIndexToCrankRevolution",
     "When CMSYSS is 1 it moves current_cylinder_index by 3 (modulo 6) so that it agrees with "
     "flag_indicating_crank_rev_1_or_2_of_cam_rev_0_1: cylinders 0 / 4 / 5 on the first crank revolution and 1 / 2 / 3 "
     "on the second. No PWM module is involved"),
]
s = open(F5, newline="").read()
for address, old, new, plate in RENAMES:
    if f"{address},{new}," in s:
        continue
    line = f"{address},{old}\n"
    assert s.count(line) == 1, (address, s.count(line))
    s = s.replace(line, f"{address},{new},{plate} (was {old}; {R})\n")
open(F5, "w", newline="").write(s)
ROWS = [
    ("0x00030c9c", "0x00030c9c,tpu_microcode_image,dword[419],The TPU microcode: mc68k_loadTpuMicrocode copies these 419 "
     f"32-bit words into the TPU RAM at 0xFFE000-0xFFE68B before it runs the TPU from its RAM (TPU_TPUMCR = 0x407; {R})"),
    ("0x00031328", "0x00031328,tpu_microcode_entry_table,word[128],The TPU microcode's entry table: mc68k_loadTpuMicrocode "
     "copies these 256 bytes to 0xFFE700-0xFFE7FF - the top of the 2 KB microcode memory - 16 functions x 8 entry "
     f"words ({R})"),
]
g = open(G5, newline="").read()
lines = g.split("\n")
for address, row in ROWS:
    if any(l.startswith(address + ",") for l in lines):
        continue
    for i, l in enumerate(lines):
        if l.startswith("0x") and int(l.split(",")[0], 16) > int(address, 16):
            lines.insert(i, row)
            break
open(G5, "w", newline="").write("\n".join(lines))
with open(map5, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n")
    for address, old, new, _ in RENAMES:
        fh.write(f"{address},{new},{old},function,1\n")
print("round 83 stage A applied")
