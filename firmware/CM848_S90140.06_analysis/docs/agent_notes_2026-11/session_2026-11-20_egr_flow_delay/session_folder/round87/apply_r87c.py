"""Round 87 stage C (CM550 + CM848): fixes from the advisor review of stages A-B. Idempotent; each edit must match once
(or already be applied). usage: apply_r87c.py <repo> <map550.csv>
- The marker check's fault is 318 (P0604, internal control module RAM error), not 462: the store is sth r11,38(r3)
  at 0x5279cc off the fault word base, and Ghidra's piece offsets (_38_2_) are DECIMAL bytes - byte 38 = word 19,
  bit 14. Stage B matched the e2m "+38" of word 28, a hex offset. Word 28 bit 14 goes back to fault_462.
- CM550 0x15f8c emptyStubFunction4 -> cm550_emptyStubFunction4: it shared the name with CM848 0x26f78, which stage A
  made the twin ignoreCanTransmitInterrupt of CM550 0xc80c; 0x15f8c is a different stub (one call, from
  mc68k_sampleAndDebounceDiscreteInputs), so it takes the CM550 prefix.
- CM550 0x1192a's plate states what its body does (the waits, the hour meter saves, the ram_refresh_enable branch)."""
import os
import sys

repo, map550 = os.path.abspath(sys.argv[1]), sys.argv[2]
O5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
O8 = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 87"


def edit(path, old, new):
    s = open(path, newline="").read()
    if new in s and old not in s:
        return
    assert s.count(old) == 1, (os.path.basename(path), old[:80], s.count(old))
    open(path, "w", newline="").write(s.replace(old, new))


S8 = os.path.join(O8, "structure_definitions.csv")
edit(S8, "fault_bit_words_t,0x003fe974,working_ram_end_marker_error,bitfield:1@14,0,fault 462 (no DTC slot): "
         f"cm848_checkWorkingRamEndMarker sets it when working_ram_end_marker no longer holds 0xC0DAC0DA (was fault_462; "
         f"{R}),,verified",
     "fault_bit_words_t,0x003fe974,fault_462,bitfield:1@14,0,fault 462,,verified")
edit(S8, "fault_bit_words_t,0x003fe974,fault_318,bitfield:1@14,0,fault 318 (P0604),,verified",
     "fault_bit_words_t,0x003fe974,working_ram_end_marker_error,bitfield:1@14,0,fault 318 (P0604 internal control "
     "module RAM error): cm848_checkWorkingRamEndMarker sets it when working_ram_end_marker no longer holds 0xC0DAC0DA "
     f"(was fault_318; {R}),,verified")
F8 = os.path.join(O8, "function_renames.csv")
edit(F8, "it clears fault 462 (working_ram_end_marker_error) in fault_detected_cal and fault_registered_cal; otherwise "
         "it sets the fault in fault_detected_cal. Fault 462 has no DTC slot.",
     "it clears fault 318 (working_ram_end_marker_error = P0604, internal control module RAM error) in "
     "fault_detected_cal and fault_registered_cal; otherwise it sets the fault in fault_detected_cal (word 19 bit 14: "
     "sth at byte 38 of the fault words, 0x5279cc).")
G8 = os.path.join(O8, "global_variables.csv")
edit(G8, "cm848_checkWorkingRamEndMarker (lwz at 0x527970) sets fault 462 when it is gone.",
     "cm848_checkWorkingRamEndMarker (lwz at 0x527970) sets fault 318 (P0604) when it is gone.")

F5 = os.path.join(O5, "function_renames.csv")
edit(F5, "0x00015f8c,emptyStubFunction4\n",
     "0x00015f8c,cm550_emptyStubFunction4,Empty function (a single rts); its one call is in "
     "mc68k_sampleAndDebounceDiscreteInputs. Its old name emptyStubFunction4 was shared with CM848 0x26f78, which is the CAN "
     "transmit-complete hook ignoreCanTransmitInterrupt (the twin of CM550 0xc80c), not this stub "
     f"(was emptyStubFunction4; {R})\n")
OLD_1192A = ("Software restart into the boot ROM without a hardware reset (the twin of CM848 0x216fc): only in "
             "engine_state 1. It polls the EEPROM write queue around mc68k_delayTimeBaseTicksWithWatchdogService2 waits "
             "(500 / 250 / 50000 ticks) - acknowledges the request on the link its second argument names (0 the J1939 "
             "response frame - 1 the J1708 diagnostic message queue; CM848's case 2 is its SCI byte) - and jumps through "
             "the ROM vector at 0x8")
NEW_1192A = ("Software restart into the boot ROM without a hardware reset (the twin of CM848 0x216fc): only in "
             "engine_state 1, otherwise it returns 7. It waits for the EEPROM write queue to drain (500-tick waits), "
             "saves the two hour meters to the EEPROM mirror at 0x803b3e / 0x803b50 (while ram_refresh_enable is on it "
             "waits for each write to arrive, otherwise it waits 250 ticks), acknowledges the request on the link its "
             "second argument names (0 the J1939 response frame - 1 the J1708 diagnostic message queue; CM848's case 2 "
             "is its SCI byte), waits 50000 ticks, clears output request bit 4 of 0x80bcf8 when 0x80bd2e is 0, strobes "
             "the outputs (mc68k_ioDriverStrobeHandler) and jumps through the ROM vector at 0x8")
edit(F5, OLD_1192A, NEW_1192A)
with open(map550, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n")
    fh.write("0x00015f8c,cm550_emptyStubFunction4,emptyStubFunction4,function,1\n")
print("round 87 stage C applied")
