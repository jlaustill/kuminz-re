"""Round 82 stage A (CM550): the six can1* / CAN-named functions that touch only the TPU (round 81's hardware name check),
renamed for the TPU channel each sets up and, where the Cummins-named globals they fill show it, the signal.
Idempotent. usage: apply_r82a.py <repo> <map.csv>"""
import os
import sys

repo, map5 = os.path.abspath(sys.argv[1]), sys.argv[2]
p = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/function_renames.csv")
R = "PR #53 round 82"
RENAMES = [
    ("0x00031428", "mc68k_initInternalRamAndCAN1", "mc68k_loadTpuMicrocode",
     "Loads the TPU microcode into the TPU RAM: when TPU_TPUMCR bit 0x400 is clear it maps the TPU RAM at 0xFFE000 "
     "(TPURAM_TRAMBAR = 0xffe0) - copies ROM 0x30c9c to 0xFFE000-0xFFE68B - clears up to 0xFFE6FF - copies ROM 0x31328 "
     "to 0xFFE700-0xFFE7FF - then sets TPU_TPUMCR = 0x407 (bit 0x400 = the TPU runs from its RAM) / TPU_CIER = 0 / "
     "TPU_TICR = 0x440. So the TPU function numbers are Cummins' own. No CAN register is involved"),
    ("0x00019dd0", "mc68k_can1MessageTransmitInit2", "mc68k_initializeTpuChannel0MissingToothInput",
     "Sets up TPU channel 0 (its CIER / HSRR1 bits and parameters 2-6) for the missing-tooth wheel input: it uses "
     "pmm_ratio_tooth_spacing_at_which_missing_tooth_is_found_0_1_9921875 / pmm_num_of_teeth_correct_tooth_count_at_"
     "missing_tooth_0_255 / tooth_count_at_which_missing_tooth_not_detct_err_0_255. No CAN register is involved"),
    ("0x0001ae22", "mc68k_dutyCycleMonitorAltCanInit", "mc68k_initializeTpuChannel1BackupSpeedInput",
     "Sets up TPU channel 1 (CFSR3 bits 7-4 / CIER bit 1 / HSRR1 bits 3-2 / parameters 0-3) for the backup speed sensor "
     "and fills its pulse period table (pulse_period_table_backup_* / period_meas_per_cam_backup_* / "
     "_teeth_per_cam_rev_backup_*). No CAN register is involved"),
    ("0x0001999c", "mc68k_can1TimerBufferInitDivided", "mc68k_initializeTpuChannel10PrimarySpeedInputDivided",
     "Sets up TPU channel 10 for the primary speed sensor and fills its pulse period table "
     "(pulse_period_table_table_containing_main_speed_pulse_per_1000_65535): parameter 1 = DAT_00807ecc << 8 - parameter "
     "0 = 0xb - HSQR0 bits 0x30 - handler vp44_rpmTimerInterruptHandler2. The other mode is "
     "mc68k_initializeTpuChannel10PrimarySpeedInputIfEnabled. No CAN register is involved"),
    ("0x0001a746", "mc68k_can1TimerBufferInitConditional", "mc68k_initializeTpuChannel10PrimarySpeedInputIfEnabled",
     "The same set-up of TPU channel 10 for the primary speed sensor as mc68k_initializeTpuChannel10PrimarySpeedInputDivided "
     "but only when _ESSXSNEN bit 0 is set and in the other mode: parameter 1 = 0x100 - parameter 0 = 7 - HSQR0 bits "
     "0x20 - handler vp44_FUN_0001a8a4. No CAN register is involved"),
    ("0x00030342", "mc68k_can1ControllerInit", "mc68k_initializeTpuChannel12",
     "Sets up TPU channel 12: clears its priority / interrupt enable / interrupt status - function 0xb (CFSR0 bits 3-0) - "
     "parameter 0 = 0x92 - parameters 2-3 = 0xffff - host service request 2 - priority 1. Then it computes "
     "_tach_output_minimum_rpm, so the channel may be the tachometer output (not checked). No CAN register is involved"),
]
s = open(p, newline="").read()
for address, old, new, plate in RENAMES:
    if f"{address},{new}," in s:
        continue
    line = f"{address},{old}\n"
    assert s.count(line) == 1, (address, s.count(line))
    s = s.replace(line, f"{address},{new},{plate} (was {old}; {R})\n")
open(p, "w", newline="").write(s)
with open(map5, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n")
    for address, old, new, _ in RENAMES:
        fh.write(f"{address},{new},{old},function,1\n")
print("round 82 stage A applied")
