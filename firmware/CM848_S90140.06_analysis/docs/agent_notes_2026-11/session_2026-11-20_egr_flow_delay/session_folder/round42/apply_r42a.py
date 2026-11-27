"""Round 42 stage A: the per-fault-slot status records (EEPROM 0x1710 in the mirror, 3 bytes per slot, indexed
slot x 3 by 22 application functions) as one 3-byte struct at their base. A 170-record array cannot be typed: it would
run across the boot kernel's time-shared structures at 0x3fec7a-0x3fecf6 (reflash_transfer_state,
boot_sci_session_state, diag_serial_buffer). The two overlapping rows fault_status_array (byte) and
fault_status_word_array (word at +1) become fault_status_records_cal (fault_status_record_t). The flags byte keeps
byte type: the code updates it with read-modify-write masks (no bitfields, firmware/CLAUDE.md). Idempotent.
usage: apply_r42a.py <repo> <map.csv>"""
import os
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
T = "fault_status_record_t"
R = "PR #53 round 42"
FLAGS = ("bit 0x01: cleared by cm848_initFaultManagement and tested by cm848_mainLoopServiceMonitor / "
         "cm848_clearMilForHealedFaults; bits 0x0e: a 3-bit count diag_faultState_severity_increment steps; bit 0x10: the "
         "MIL request (cm848_updateMilOnRequest; the sensor monitors fall back to their defaults while it is set; "
         "cm848_clearMilForHealedFaults clears it at 3 heal cycles); bits 0x60: the 2-bit heal cycle count "
         "(diag_faultState_healCycleCount_increment); bit 0x80: a stored DTC (cm848_processPciObdRequest counts "
         "obd_stored_dtc_count from it). Updated with read-modify-write masks, so a byte, not bitfields")
WORD = ("bit 0x0001: the fault is active (cm848_sciCommand51ReportActiveFaultDtcs reports it); bits 0x0002 / 0x0004: "
        "flags cm848_removeHealedFaults / fault_captureDataSnapshot test; bits 3-9 (>> 3 & 0x7f): a 7-bit age the heal "
        "logic compares")
sp = os.path.join(out, "structure_definitions.csv")
s = open(sp).read()
if f"\n{T}," not in s:
    s = s.rstrip("\n") + "\n" + "\n".join([f'{T},,flags,byte,1,"{FLAGS} ({R})",,verified',
                                            f'{T},,status_word,word,2,"{WORD} ({R})",,verified']) + "\n"
    open(sp, "w").write(s)
gp = os.path.join(out, "global_variables.csv")
g = open(gp).read().split("\n")
if any(l.startswith("0x003feb92,fault_status_records_cal,") for l in g):
    print("already applied")
    sys.exit(0)
i = next(k for k, l in enumerate(g) if l.startswith("0x003feb92,fault_status_array,"))
j = next(k for k, l in enumerate(g) if l.startswith("0x003feb93,fault_status_word_array,"))
old_a = g[i].split(",", 3)[3]
old_b = g[j].split(",", 3)[3]
g[i] = ("0x003feb92,fault_status_records_cal," + T + ",The status record of each fault slot, 3 bytes per slot "
        "(EEPROM 0x1710 + 3 x slot; the slot is the fault's entry in the ROM 0x5985a table): flags + status_word. "
        "Typed as one record at the base because 170 records would run across the boot kernel's time-shared "
        "structures at 0x3fec7a-0x3fecf6; the users index it slot x 3 (was fault_status_array / fault_status_word_array; "
        f"{R}) | earlier notes: {old_a} / {old_b}")
g[j] = "0x003feb93,fault_status_records_cal.status_word,,documentation row (was fault_status_word_array; " + R + ")"
open(gp, "w").write("\n".join(g))
with open(map_path, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n0x003feb92,fault_status_records_cal,fault_status_array,global,1\n")
print("stage A applied")
