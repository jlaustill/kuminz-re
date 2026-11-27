"""Round 55 stage A (function names and plates only): the fault manager core at 0x533aec-0x535344, read function by
function. Fourteen unprefixed legacy names (none in CM550) and cm848_initFaultManagement ('initialize' now that it is
touched). Two old names were swapped in meaning: diag_resetSingleFault cleared every fault record and
diag_resetAllFaults only the previously active faults (cm848_clearDiagnosticState runs the second alone, or both on a
full clear). diagnosticMainStateProcessor is shared with CM550 and keeps its name.
Bits used below (fault_status_record_t, PR #53 round 42): flags 0x0e a 3-bit count / 0x10 MIL request / 0x60 heal
cycle count / 0x80 stored DTC; status_word bits 0-2 flags / bits 3-9 an age / bits 10-15 the warm-up cycle count.
Idempotent.  usage: apply_r55a.py <repo> <map.csv>"""
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
fp = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/function_renames.csv")
R = "PR #53 round 55"
t = open(fp).read()
original = t
if "cm848_clearPreviouslyActiveFaults" in t:
    print("already applied")
    sys.exit(0)
KEEP = None  # keep the existing plate
FUNCS = [
    ("0x00533aec", "fault_clearByIndex", "cm848_clearFaultStatusRecord",
     "Clears one fault slot's status record: flags = 0 and status_word bits 10-15 (the warm-up cycle count). "
     "Called by cm848_clearFaultFromActiveList and cm848_autoClearFaultsAfterWarmUpCycles"),
    ("0x00533bc4", "fault_clearFromRing", "cm848_removeFaultFromRecentDtcList",
     "Removes the slot's DTC (obd_dtc_code_table[slot]) from the 8-entry recent_fault_dtc_codes_cal list: shifts the "
     "later entries down and drops the matching engine start count (cm848_removeEngineStartCountSinceFaultLogged)"),
    ("0x00533c80", "fault_updateActiveCounters", "cm848_removeFaultFreezeFrameEntry",
     "For the freeze frame entry holding this fault code (status_flags bit 0 set): removes its pointer from "
     "fault_entry_pointer_queue_cal (shifting the rest) - clears the entry's flags (bit 1 also calls "
     "cm848_markFaultForReplacement) - and counts the queue down"),
    ("0x00533df0", "diag_resetSingleFault", "cm848_clearAllFaultRecords",
     "Clears every one of the 170 fault status records (flags and status_word) - the monitor complete bits - the "
     "readiness codes (all 1 = not ready) - fault_handled_bitmap - the recent DTC list and its engine start counts - "
     "and the freeze frame pointer queue. The old name said single; cm848_clearDiagnosticState runs it for a full clear"),
    ("0x00533efc", "diag_resetAllFaults", "cm848_clearPreviouslyActiveFaults",
     "Clears the faults on previously_active_dtc_list_cal: their status records - freeze frame entries "
     "(cm848_removeFaultFreezeFrameEntry) and recent DTC list entries - then the monitor complete bits / readiness "
     "codes / fault_handled_bitmap. The old name said all; cm848_clearDiagnosticState runs it alone when the request "
     "does not ask for a full clear (the J1939 DM3 meaning)"),
    ("0x00534010", "fault_ring_buffer_auto_clear_emission", "cm848_autoClearFaultsAfterWarmUpCycles",
     "From cm848_monitorWarmUpCycle: erases each stored (flags 0x80) inactive fault without the MIL request whose "
     "warm-up cycle count (status_word >> 10) reached fault_auto_clear_warm_up_cycle_count_cal - its status record / "
     "recent DTC list entry / fault status and its place in previously_active_dtc_list_cal - and counts "
     "j1587_fault_count_data_cal.total_emission_faults down unless the definition has flag 0x2000"),
    ("0x00534250", "diag_faultEntry_conditions_validate", "cm848_areConditionsSimilarToFreezeFrame",
     "Returns 1 when the conditions match this fault code's freeze frame entry: engine speed within 3000 (375 rpm) - "
     "engine_load_at_current_speed_percent within 0x1400 - and the coolant on the same side of "
     "warm_up_coolant_temperature_threshold; 0 when they differ or the code has no entry (cm848_mainLoopServiceMonitor)"),
    ("0x00534890", "diag_activeFault_remove", "cm848_removeHealedFault",
     "The per-fault step of cm848_removeHealedFaults: clears status_word bits 0-9 and for a fault that is not a stored "
     "DTC (flags 0x80 clear) resets its fault status and drops it from previously_active_dtc_list_cal"),
    ("0x00534ae4", "diag_faultState_severity_increment", "cm848_countFaultOccurrence",
     "From cm848_latchNewlyActiveFault: steps the 3-bit count in flags bits 1-3 (saturating at 7) - sets the slot's "
     "fault_handled_bitmap bit - and zeroes the heal cycle count (flags bits 5-6)"),
    ("0x005346e8", "diag_faultState_healCycleCount_increment", "cm848_incrementFaultHealCycleCount", KEEP),
    ("0x00534c6c", "fault_enqueueRecord", "cm848_queueFaultFreezeFrameEntry",
     "Puts a freeze frame entry into fault_entry_pointer_queue_cal: with the queue full or an entry marked for "
     "replacement (status_flags bit 1) it keeps the entries whose fault definitions rank higher (entry_flags 0x0e / "
     "0x0a). Called by cm848_recordFaultDetection and hpcr_setFaultActiveStatus"),
    ("0x00534fb0", "fault_captureDataSnapshot", "cm848_recordFaultDetection",
     "Records a detection of the fault in this slot. The first time (status_word bit 0 clear) it sets bits 0-1 - "
     "marks the slot handled - zeroes the heal cycle count - and when the definition has entry_flags 0x02 sets bit 2 "
     "and stores fault_aging_drive_cycle_counter_cal in bits 3-9. On a later detection with bit 1 clear it marks the "
     "freeze frame entry used and queues it (cm848_queueFaultFreezeFrameEntry) - latches the fault "
     "(cm848_latchNewlyActiveFault) - and clears bits 0-9. Called by hpcr_setFaultActiveStatus"),
    ("0x0053515c", "diag_mainStateHandler", "cm848_registerFaultsOfCompletedMonitors",
     "For each of the 32 fault monitor groups whose diagnostic_monitor_complete_bits bit is newly set: registers each "
     "of its 16 slots (0xaa = none) whose status_word has bit 0 without bit 1 and whose fault_state_records_cal status "
     "bit 0 is set (cm848_registerFaultInActiveList) - then marks the group in "
     "diagnostic_monitor_complete_handled_bits. Called by diagnosticMainStateProcessor"),
    ("0x00535270", "diag_stateTransition", "cm848_markFaultsOfCompletedMonitorsHandled",
     "For each fault monitor group whose complete bit is set and not yet handled: sets fault_handled_bitmap for each of "
     "its slots whose fault_state_records_cal status bit 0 is set. Called by diagnosticMainStateProcessor"),
    ("0x00535344", "cm848_initFaultManagement", "cm848_initializeFaultManagement",
     "Boot (cm848_applicationMain): loads fault_service_monitor_startup_delay_count from "
     "warm_up_cycle_start_coolant_temperature_read_delay and clears status_word bits 1-2 and flags bit 0 of all 170 "
     "fault slots"),
]
mapping = ["address,name,old_label,kind,dims"]
for a, cur, new, plate in FUNCS:
    m = re.search(rf"^{a},{cur}(,[^\n]*)?$", t, re.M)
    assert m, (a, cur)
    assert re.fullmatch(r"(cm848|hpcr|mpc555)_[a-z][A-Za-z0-9]*", new) and not re.search(rf"\b{new}\b", original), new
    old_plate = (m.group(1) or ",")[1:].strip()
    if plate is KEEP:
        assert old_plate, (a, "no plate to keep")
        text = f"{old_plate} (was {cur}; {R})"
    else:
        assert "," not in plate, (a, plate[:60])
        text = f"{plate} (was {cur}; {R})" + (f" | earlier note: {old_plate}" if old_plate else "")
    t = t[:m.start()] + f"{a},{new},{text}" + t[m.end():]
    mapping.append(f"{a},{new},{cur},function,1")
open(fp, "w").write(t)
with open(sys.argv[2], "w") as fh:
    fh.write("\n".join(mapping) + "\n")
print(f"{len(mapping) - 1} functions renamed")
