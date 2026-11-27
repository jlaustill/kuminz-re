"""Round 87 stage B (CM550 + CM848): the skeptics' apply notes on stage A, and the CM848 working RAM end marker.
Idempotent; every edit must match its old text exactly once (or already be applied). Keeps line endings.
usage: apply_r87b.py <repo> <map550.csv> <map848.csv>
- Plate fixes the skeptics asked for (the right call position, J1708 message type 3 then command 67, the block number,
  the erase-or-program failure, the two power-down waits, one 4-byte store per step, the ram_refresh_enable wait) and
  the parameter block saver plates in the new vocabulary.
- CM550: 0x15dd0 vp44_initVP44StatusMonitoring -> cm550_initializeDiscreteInputs (points the discrete input override
  mask and runs mc68k_sampleAndDebounceDiscreteInputs 4 times; no VP44 status, no hardware access of its own); the
  service 0x0B enum member takes CM848's name (the handler is the twin handleJ1939RestartService); the 0x803b15
  ecu_serial_number row goes (no access of its own: it is the low byte of parameter_block_2_checksum_cal).
- CM848: cm848_timer_state_preservation / cm848_main_loop_initialization are the working RAM end marker's writer and
  check (0xC0DAC0DA at 0x41428e, fault 462); main_loop_scheduler_phase is the executive's phase; the function_renames
  header line and firmware/CLAUDE.md name the boot kernel copy cm848_copyBootKernelToRam (0x340)."""
import os
import re
import sys

repo, map550, map848 = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]
O5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
O8 = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 87"


def edit(path, old, new):
    s = open(path, newline="").read()
    if new in s and old not in s:
        return
    assert s.count(old) == 1, (os.path.basename(path), old[:80], s.count(old))
    open(path, "w", newline="").write(s.replace(old, new))


def set_comment(path, address, text):
    """Replace a function_renames row's comment up to its '(was ...; PR #53 round 87...)' note."""
    s = open(path, newline="").read()
    m = re.search(rf"^({address},[^,\r\n]+,)([^\r\n]*)$", s, re.M)
    assert m, address
    note = re.search(r"\(was [^()]*" + re.escape(R) + r"[^()]*\)\s*$", m.group(2))
    assert note, (address, m.group(2)[-90:])
    new = f"{text} {note.group(0)}"
    if m.group(2) != new:
        s = s[:m.start(2)] + new + s[m.end(2):]
        open(path, "w", newline="").write(s)


F5, G5, E5 = (os.path.join(O5, n) for n in ("function_renames.csv", "global_variables.csv", "enums.csv"))
F8, G8, S8 = (os.path.join(O8, n) for n in ("function_renames.csv", "global_variables.csv", "structure_definitions.csv"))

# ---- CM550 plates
set_comment(F5, "0x00015df0",
            "The start-up set-up of the discrete outputs. mc68k_applicationMain calls it once (jsr at 0x28708), after "
            "the discrete input set-up cm550_initializeDiscreteInputs (0x15dd0) and cm550_initADCChannelConfiguration. "
            "1. It writes the default output states into the output images 0x80bcf6-0x80bcfb, each only while no "
            "client holds that output's override slot (0x80bd1a + n). 2. It sets up the chip select 2 output driver: "
            "registers 8 / 9 / 10 = 0x0F / 0x80 / 0x80, output port 1 (0xFFD004) cleared, port 2 bit 7 (0xFFD006) "
            "cleared. 3. It starts TPU channel 13 (function 0xE, PARAM0 0x113) with a handshake: HSR 2 and wait for "
            "PARAM1 bit 15 = 0, HSR 1 and wait for 1, HSR 2 and wait for 0; then it sets port 2 bit 7 and issues HSR 1. "
            "4. It ends with mc68k_ioDriverStrobeHandler, which writes the ports from the images and drives channel 13 "
            "from bit 5 of 0x80bcfb (set: HSR 2, clear: HSR 1), most likely the fuel shut-off command")
edit(F5, "mc68k_dispatchJ1708ReceivedMessages jumps here for J1708 diagnostic command 67 (command - 64 = 3 in its "
         "21-entry table at 0x160b8).",
     "mc68k_dispatchJ1708ReceivedMessages jumps here for J1708 message type 3, then command 67 (0x43: entry 3 of its "
     "21-entry table at 0x160b8, which covers the commands 0x40-0x54).")
edit(F5, "so the bank 1 + bank 2 sum ends odd (block 1 = newest)",
     "so the sum of the two blocks' save start counts ends odd (block 1 = newest)")
edit(F5, "stores the new block sum in EEPROM 0x8 and the sequence at 0x803FD8",
     "stores the new block sum in parameter_block_1_checksum_cal (EEPROM 0x8) and the start count in "
     "parameter_block_1_save_complete_count_cal (0x803FD8)")
edit(F5, "The block 2 saver: the sequence sum ends even (block 2 = newest)",
     "The block 2 saver: the sum of the save start counts ends even (block 2 = newest)")
edit(F5, "stores the block sum in EEPROM 0xA and the sequence at 0x803FE0",
     "stores the block sum in parameter_block_2_checksum_cal (EEPROM 0xA) and the start count in "
     "parameter_block_2_save_complete_count_cal (0x803FE0)")
edit(F5, "when all fail it sets 0x803FE8 = 1", "when all fail it sets flash_write_failure_flag_cal (0x803FE8) = 1")
edit(F5, "0x00015dd0,vp44_initVP44StatusMonitoring\n",
     "0x00015dd0,cm550_initializeDiscreteInputs,The start-up set-up of the discrete inputs: points "
     "discrete_input_override_mask_ptr at switch_override_configuration and runs mc68k_sampleAndDebounceDiscreteInputs "
     "4 times. It monitors no VP44 status, and its own body has no hardware access, so cm550_ "
     f"(was vp44_initVP44StatusMonitoring; {R})\n")

# ---- CM550 globals
edit(G5, "so 10C7 is exactly ram_refresh_enable / 0x80dc6e / 0x80dc70.",
     "so 10C7 is exactly ram_refresh_enable / power_down_refresh_enable / parameter_block_uploaded. It holds a block "
     "number (0 none / 1 / 2): the block the RAM copy came from at power-up; the savers also write 1 / 2 after a "
     "completed save (0x11240 / 0x114ba).")
edit(G5, "so the name is shared. (was eeprom_calibration_write_success;",
     "so the name is shared. It is set to 1 when all 3 attempts failed to erase or program the flash (0x27d48 / "
     "0x27e1e) and cleared at 0x27db4 / 0x27e86; the boot reader at 0x28690 sets error status word 10 bit 0x40. "
     "(was eeprom_calibration_write_success;")
edit(G5, "0x00803b15,ecu_serial_number,undefined,\n", "")
edit(G5, "the block 2 saver writes it.",
     "the block 2 saver writes it. Its low byte 0x803b15 had a row ecu_serial_number with no access of its own; "
     f"that row is removed ({R}).")

# ---- CM550 enum: service 0x0B is the twin restart service
edit(E5, "J1939_DIAGNOSTIC_SERVICE,0x0B,SYSTEM_SERVICE_0B,System service 0B - dispatch @ 0x00011908 - SECURED - in "
         "dispatch table,1",
     "J1939_DIAGNOSTIC_SERVICE,0x0B,J1939_DIAGNOSTIC_SERVICE_RESTART_THROUGH_BOOT_ROM,handleJ1939RestartService "
     f"(0x11908): restartThroughBootRom - SECURED - in dispatch table (was SYSTEM_SERVICE_0B; {R}),1")

# ---- CM848 plates
edit(F8, "counts the start in completed_power_down_count_cal / writes the new power_cycle_sequence_number_cal (= "
         "completed + incomplete counts) / waits up to 1000 x 2500 timebase ticks for that EEPROM write / then",
     "counts the start in completed_power_down_count_cal (waiting up to 1000 x cm848_delayMicroseconds(19) for that "
     "EEPROM write) / writes the new power_cycle_sequence_number_cal (= completed + incomplete counts) and waits up "
     "to 1000 x 2500 timebase ticks for it / then")
edit(F8, "(two words per step, 256 bytes per outer pass)",
     "(one 4-byte store per step; each outer pass runs to 256 bytes on, inclusive, so it makes 65 stores = 260 "
     "bytes - the CM550 twin's quirk; the last store, at 0x41428c, also clears the first half of "
     "working_ram_end_marker)")
edit(F8, "(waiting for each while a diagnostic session is active)",
     "(while ram_refresh_enable is on it waits for each write to reach the EEPROM mirror; otherwise it waits 9 us)")
edit(F8, "# copyCalibrationToRam() copies ROM 0x3C30-0x7F60 (17KB) to RAM 0x3F9800-0x3FDB30 at boot.",
     "# cm848_copyBootKernelToRam (0x340) copies ROM 0x3C30-0x7F60 (17KB) to RAM 0x3F9800-0x3FDB30 at boot.")
edit(F8, "0x00527958,cm848_timer_state_preservation\n",
     "0x00527958,cm848_writeWorkingRamEndMarker,Writes 0xC0DAC0DA to working_ram_end_marker (0x41428e) - the dword "
     "at the end of the RAM that clearWorkingRam clears. cm848_applicationMain calls it once at start-up, after "
     f"clearWorkingRam; cm848_checkWorkingRamEndMarker checks it (was cm848_timer_state_preservation; {R})\n")
edit(F8, "0x0052796c,cm848_main_loop_initialization\n",
     "0x0052796c,cm848_checkWorkingRamEndMarker,Once per executive cycle (phase 17): while working_ram_end_marker "
     "still holds 0xC0DAC0DA it clears fault 462 (working_ram_end_marker_error) in fault_detected_cal and "
     "fault_registered_cal; otherwise it sets the fault in fault_detected_cal. Fault 462 has no DTC slot. Nothing "
     f"here initializes a main loop (was cm848_main_loop_initialization; {R})\n")

# ---- CM848 globals and the fault bit
edit(G8, "0x003fa008,main_loop_scheduler_phase,dword,\n",
     "0x003fa008,executive_frame_phase,dword,The 40-phase executive's current phase: executiveFrameInterruptHandler "
     f"runs that phase's task set and stores the next phase (was main_loop_scheduler_phase; {R})\n")
s = open(G8, newline="").read()
row = ("0x0041428e,working_ram_end_marker,dword,0xC0DAC0DA once cm848_writeWorkingRamEndMarker has run at start-up "
       "(stw at 0x527964); cm848_checkWorkingRamEndMarker (lwz at 0x527970) sets fault 462 when it is gone. Its "
       "address is also the end pointer of clearWorkingRam, whose last store clears its first half "
       f"(was DAT_0041428e; {R})")
if "0x0041428e,working_ram_end_marker," not in s:
    lines = s.split("\n")
    for i, l in enumerate(lines):
        if l.startswith("0x") and int(l.split(",")[0], 16) > 0x41428e:
            lines.insert(i, row)
            break
    else:
        raise SystemExit("no row after 0x41428e")
    open(G8, "w", newline="").write("\n".join(lines))
edit(S8, "fault_bit_words_t,0x003fe974,fault_462,bitfield:1@14,0,fault 462,,verified",
     "fault_bit_words_t,0x003fe974,working_ram_end_marker_error,bitfield:1@14,0,fault 462 (no DTC slot): "
     "cm848_checkWorkingRamEndMarker sets it when working_ram_end_marker no longer holds 0xC0DAC0DA "
     f"(was fault_462; {R}),,verified")

# ---- firmware/CLAUDE.md: the boot kernel copy's name (verified: 0x340 copies boot_kernel_rom_start..end to 0x3f9800)
edit(os.path.join(repo, "firmware/CLAUDE.md"),
     "`copyCalibrationToRam()` copies ROM 0x3C30-0x7F60 (17KB) to RAM 0x3F9800-0x3FDB30 at boot.",
     "`cm848_copyBootKernelToRam` (0x340) copies ROM 0x3C30-0x7F60 (17KB) to RAM 0x3F9800-0x3FDB30 at boot.")

with open(map550, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n")
    fh.write("0x00015dd0,cm550_initializeDiscreteInputs,vp44_initVP44StatusMonitoring,function,1\n")
with open(map848, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n")
    fh.write("0x00527958,cm848_writeWorkingRamEndMarker,cm848_timer_state_preservation,function,1\n")
    fh.write("0x0052796c,cm848_checkWorkingRamEndMarker,cm848_main_loop_initialization,function,1\n")
    fh.write("0x003fa008,executive_frame_phase,main_loop_scheduler_phase,global,1\n")
    fh.write("0x0041428e,working_ram_end_marker,DAT_0041428e,global,1\n")
print("round 87 stage B applied")
