"""Round 85 stage A (CM550): the prefix rule audit (workflow wf_53689291-e4b: 6 read-only investigators, then 6 skeptics;
every proposal accepted). Applied under commit 16143a5c's rule: a function whose only hardware access is the inline
watchdog kick (SIM_SWSR / CS2_WATCHDOG_SERVICE) is generic code and is not mc68k_ (hardware_access_kinds.py). The nine
function records the audit proved spurious (mid-function points with no reference - references_to.py) go into
deleted_functions.csv.  Idempotent; keeps line endings.  usage: apply_r85a.py <repo> <map.csv>"""
import os
import sys

repo, map5 = os.path.abspath(sys.argv[1]), sys.argv[2]
O5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
F5, D5, X5, L5 = (os.path.join(O5, n) for n in ("function_renames.csv", "function_definitions.csv",
                                               "deleted_functions.csv", "local_variables.csv"))
R = "PR #53 round 85"
WATCHDOG_ONLY = "Its only hardware access is the inline watchdog kick, so not mc68k_ (commit 16143a5c)"
RENAMES = [
    ("0x00010e80", "cm550_calibrationDataCopyWithChecksum", "cm550_loadParameterBlock1FromFlash",
     "Start-up load of flash parameter block 1: it copies flash 0x4000-0x55B3 into the RAM copy 0x804F96-0x806549 - "
     "sets calibration_bank_active = 1 and returns 0 - only when the word sum of 0x4000-0x55B3 matches EEPROM 0x8 or the "
     f"marker word 0x55B2 holds 0xA1A1; otherwise it returns 1 and copies nothing. {WATCHDOG_ONLY}"),
    ("0x00010f32", "cm550_calibrationDataCopySecondary", "cm550_loadParameterBlock2FromFlash",
     "The block 2 loader: it copies flash 0x6000-0x75B3 into the same RAM copy - sets calibration_bank_active = 2 and "
     "returns 0 - only when the word sum of 0x6000-0x75B3 matches EEPROM 0xA (no marker exception); otherwise it returns "
     f"1. {WATCHDOG_ONLY}"),
    ("0x00010fe0", "cm550_eepromCalibrationWriteSecondary", "cm550_saveParameterBlock1ToFlash",
     "Saves the RAM copy (0x804F96) into flash parameter block 1: it bumps calibration_bank1_write_sequence so the bank 1 "
     "+ bank 2 sum ends odd (block 1 = newest) - erases block 0x4000 with cm550_flashEraseFromRam - programs 0x4000-0x55B1 "
     "- stores the new block sum in EEPROM 0x8 and the sequence at 0x803FD8 - and sets calibration_bank_active = 1. "
     f"Returns 0 saved / 2 a program step failed / 1 or 2 after a failed erase. {WATCHDOG_ONLY}"),
    ("0x0001125a", "cm550_FUN_0001125a", "cm550_saveParameterBlock2ToFlash",
     "The block 2 saver: the sequence sum ends even (block 2 = newest); it erases block 0x6000 - programs 0x6000-0x75B1 "
     "from RAM 0x804F96 - stores the block sum in EEPROM 0xA and the sequence at 0x803FE0 - and sets "
     f"calibration_bank_active = 2. The same return codes as cm550_saveParameterBlock1ToFlash. {WATCHDOG_ONLY}"),
    ("0x000117ec", "cm550_firmwareDataCopyToWorkingMemory", "cm550_copyCalibrationFromRomToRam",
     "Copies 2401 dwords from ROM 0x61376-0x638F9 (above the dumped 256 KB) into RAM 0x80654A-0x808ACD - the calibration "
     "parameters (1757 named e2m rows there) - once at start-up after cm550_clearWorkingMemory. CM848's "
     f"cm848_copyRomToRamBuffer holds the same start-up slot. {WATCHDOG_ONLY}"),
    ("0x0001c31a", "cm550_flashEraseWithWatchdog", "mc68k_flashEraseBlock",
     "Flash block erase - run only from the 2 KB stack copy cm550_flashEraseFromRam makes: it writes 0x2020 / 0xD0D0 "
     "(erase set-up / confirm) to *flash_target_address_ptr and polls the status word for bit 7 up to 40000 times. "
     "Returns 0 erased / 1 erase error (status bit 5) or timeout / 2 suspended (0xB0B0) when the suspend check is on and "
     "bit 0 of the chip select 2 device's register 0 reads 1 on 4 consecutive reads. The .cpp drops the 0 path and the "
     "status commands - read ROM 0x1C354 onward. mc68k_ for the 0xFFD000 read"),
    ("0x0001c484", "cm550_FUN_0001c484", "cm550_flashEraseFromRam",
     "The erase runner - the erase twin of cm550_flashProgramFromRam: it stores the block address in "
     "flash_target_address_ptr and the suspend flag at 0x8006A6 (1 = never suspend: the boot block; 0 from the parameter "
     "block savers), copies mc68k_flashEraseBlock (0x1C31A-0x1C483) into a 2 KB stack buffer and calls the copy. Returns "
     "its result: 0 erased / 1 error or timeout / 2 suspended"),
    ("0x0001c4ba", "cm550_flashProgramWordWithWatchdog", "cm550_flashProgramAndVerifyWords",
     "The RAM-run flash programmer (run only from the stack copy cm550_flashProgramFromRam makes): for each word up to the "
     "end pointer at 0x8006A2 it writes 0x4040 and the source word - polls the status up to 5000 times - accepts the word "
     "only when status & 0xF8F8 = 0x0080 and the read-back matches - and retries a failed word up to 5 times. Returns 1 "
     f"all words programmed / 0 a word failed (the .cpp's 'return 0' on both exits is wrong). {WATCHDOG_ONLY}"),
    ("0x00014fca", "injectorTimingCalculation", "mc68k_sampleAndDebounceDiscreteInputs",
     "The discrete input sampler and debouncer - nothing in it concerns injector timing: it reads the chip select 2 "
     "device's input bytes 0xFFD000-0xFFD003 / 0xFFD005 / 0xFFD007 and SIM_PORTE0 / SIM_PORTF0 - XORs them with the "
     "polarity masks into three 4-sample rings - debounces each byte as (AND of 4) | (OR of 4 & previous) - then decodes "
     "the PTO and cruise switches with 25-pass hold counters and two 50-pass switch-pair faults"),
    ("0x00019acc", "vp44_rpmTimerInterruptHandler2", "mc68k_tpuChannel10PrimarySpeedInterruptHandlerMode0",
     "The TPU channel 10 (primary engine speed sensor) interrupt handler for speed_measurement_mode 0 (saves d0-d1 / a0-a5 "
     "and ends in RTE): it reads the 32-bit pulse period from channel 10 parameters 4-5 and clears parameter 4 - updates "
     "the pulse period ring with its per-cam and per-cylinder sums - the tooth counter and the lost-sensor timeout - checks "
     "the cylinder identification pulse - then runs the main / backup phase comparator and clears TPU_CISR bit 10"),
    ("0x00019e90", "vp44_FUN_00019e90", "mc68k_tpuChannel10PrimarySpeedInterruptHandlerMode1",
     "The TPU channel 10 primary speed interrupt handler for speed_measurement_mode 1 (set up with "
     "mc68k_initializeTpuChannel0MissingToothInput): the mode 0 period read / ring / sums / lost-sensor timeout without "
     "the tooth counter and the cylinder identification check - then the same phase comparator and TPU_CISR bit 10 tail. "
     "It is the handler the dumped ECU runs (RAM 0x808F04 = 0x19E90)"),
    ("0x0001a52c", "vp44_FUN_0001a52c", "mc68k_tpuChannel10PrimarySpeedInterruptHandlerMode2",
     "The TPU channel 10 primary speed interrupt handler for speed_measurement_mode 2: ROM 0x1A52C-0x1A6E7 is the same 444 "
     "bytes as the mode 0 handler (0x19ACC-0x19C87); only its set-up differs (channel 10 parameter 1 from the per-cam "
     "pulse count, paired with the channel 0 missing-tooth set-up)"),
    ("0x0001a8a4", "vp44_FUN_0001a8a4", "mc68k_tpuChannel10PrimarySpeedInterruptHandlerMode3",
     "The TPU channel 10 primary speed interrupt handler for speed_measurement_mode 3 (saves d0-d3 / a0-a1 and ends in "
     "RTE): it reads the period and the edge time TPU_CH10_PARAM2 - clears parameter 4 - passes them to "
     "cm550_throttleTimeAccumulatorProcessor (in fact the mode 3 period ring / sync gap processor) - re-arms channel 10 "
     "(parameter 0 and HSR 2) - then runs the same phase comparator tail"),
    ("0x0002dde8", "oilPressureRpmFaultMonitor", "mc68k_monitorPwmOutputReadBackFaults",
     "A PWM output driver read-back fault monitor - nothing in it reads oil pressure or engine speed: for PWM1 / PWM2 / "
     "PWM5 with a non-zero period it compares the read-back pin (bit 7 of DASM10SIC / DASM9SIC / DASM4SIC) with the "
     "commanded duty - a high pin at 0 % or a low pin at 100 % counts a driver error and the right level heals it. For its "
     "first 6 passes it also steps mc68k_waterInFuelDiagnosticHandler (in fact the PWM 3 / 4 start-up check)"),
    ("0x00027af0", "vp44StatusInitAndWait", "cm550_restartOnKeyOnDuringPowerDown",
     "Services both watchdogs and re-samples the discrete inputs - adds 1 to the completed power-down count (0x803FEC) and "
     "queues the EEPROM write - waits up to 1000 passes - writes the power cycle sequence number 0x803FE2 = the incomplete "
     "count (0x803FEA) + the completed count - waits again - and jumps to the application main's restart entry 0x28978. "
     f"CM848's cm848_restartOnKeyOnDuringPowerDown runs the same steps. {WATCHDOG_ONLY}"),
    ("0x00027cd0", "vp44_FUN_00027cd0", "cm550_savePowerDownDataToFlashBank",
     "Writes the RAM power-down data block into the flash bank its word argument names first (1 = bank 1 at 0x4000 "
     "through cm550_saveParameterBlock1ToFlash; otherwise bank 2 at 0x6000 through cm550_saveParameterBlock2ToFlash) "
     "with up to 3 attempts; when all fail it sets 0x803FE8 = 1 and - unless "
     "enable_to_protects_parameter_block_data_at_powerdown is set - writes the other bank. " + WATCHDOG_ONLY),
    ("0x00027f9c", "vp44_FUN_00027f9c", "mc68k_runPowerDownSequence",
     "The power-down sequence mc68k_applicationMain runs after its background loop ends (ROM 0x289FA; the .cpp shows no "
     "caller because Ghidra prunes the main's exit). CM848's cm848_runPowerDownSequence runs the same sequence with the "
     "same constants. mc68k_ for its CTM4_BIUTBR reads"),
    ("0x000284e8", "vp44_FUN_000284e8", "mc68k_applicationMain",
     "The application main: mc68k_main calls it once (ROM 0x1DCF4) and it never returns. Its start-up clears working RAM "
     "(cm550_clearWorkingMemory) after mc68k_loadTpuMicrocode - copies the calibration (cm550_copyCalibrationFromRomToRam) "
     "- loads a parameter block - and configures the QSM / SIM / TPU / CTM4 interrupts and channels; then it runs the "
     "background loop and mc68k_runPowerDownSequence. 0x28978 inside it is the restart entry "
     "cm550_restartOnKeyOnDuringPowerDown jumps to. CM848's cm848_applicationMain has the same skeleton"),
    ("0x00015f8e", "diagnosticCommandDispatcher", "mc68k_dispatchJ1708ReceivedMessages",
     "Drains the J1708 receive buffer for at most 500 CTM4_BIUTBR ticks: first it sends the deferred reply "
     "commitEepromMirrorToEeprom arms (once the EEPROM write queue is empty); each record is [length][message bytes] and "
     "the first message byte picks the handler (3 = the 10-byte key through validateSecurityKey and then commands "
     "0x40-0x54 - 4 = control commands 0x64-0x76 - 5 = memory read / write / multipacket). Its old shared name came from "
     "a pairing CM848 later dropped"),
    ("0x0001e5f0", "cm550_FUN_0001e5f0", "mc68k_queueCanCs4ReceiveMessage",
     "Copies the frame in message object n of the chip select 4 82527 (n = the low byte of its word argument) into the "
     "next 18-byte entry of the CAN receive ring: the identifier (arbitration >> 3) - the length - a pointer to the "
     "entry's data - the 8 data bytes. Objects 1-14 are re-read while control 1 bit 1 is set again; object 15 is read "
     "at 0xFFD8F2 / 0xFFD8F6 / 0xFFD8F7. The ring wraps from past 0x80D884 to 0x80D72E"),
    ("0x00028b80", "initDiagnosticBufferPointers", "mc68k_initializeJ1939Datalink",
     "Initializes the J1939 datalink on the chip select 4 82527: the CAN transmit / receive ring pointers - the transport "
     "frame buffers - a 4-entry source address list of 0xFE - 21 transmit buffer initializers - 19 periodic schedule "
     "entries - and the remaining set-up / registration calls. Its old shared name came from a pairing CM848 later "
     "dropped"),
    ("0x00034bba", "cm550_watchdogServiceLoop", "mc68k_delayTimeBaseTicksWithWatchdogService",
     "A busy-wait: it reads CTM4_BIUTBR once - then services both watchdogs on every pass until the 16-bit difference "
     "CTM4_BIUTBR - start reaches its word argument. Callers push a 2-byte tick count (500 or 10000) between polls of the "
     "EEPROM write queue or the VP44 status"),
    ("0x00034bf8", "cm550_FUN_00034bf8", "mc68k_delayTimeBaseTicksWithWatchdogService2",
     "A byte-identical copy of mc68k_delayTimeBaseTicksWithWatchdogService (ROM 0x34BF8-0x34C35 = 0x34BBA-0x34BF7); its "
     "only reference is movea.l #0x34BF8,a3 in the restart routine cm550_FUN_0001192a"),
]
DELETIONS = [
    ("0x00015e06", "clearModuleSyncFlag", "byte 0x16 of mc68k_FUN_00015df0 - after its movem.l a2-a4 prologue - and the "
     "only epilogue pops a2-a4"),
    ("0x00028508", "vp44_mainSystemInitialization", "the instruction after move.l a0,sp inside mc68k_applicationMain"),
    ("0x0002874a", "vp44_slowCycle4Coordinator", "a fall-through point after a jsr inside mc68k_applicationMain"),
    ("0x00028792", "vp44_engineDiagnosticSystemCoordinator", "a fall-through point after a jsr inside mc68k_applicationMain"),
    ("0x00028816", "cm550_fuelDemandUpdateOrchestrator", "a fall-through point after a jsr inside mc68k_applicationMain"),
    ("0x00028828", "cm550_advancedEngineProtectionCoordinator", "a fall-through point after a jsr inside mc68k_applicationMain"),
    ("0x00028936", "cm550_shutdownMinimumSelectorOrchestrator", "a fall-through point after a jsr inside mc68k_applicationMain"),
    ("0x00028990", "cm550_phase4InitSequence", "a fall-through point after a jsr in the restart path from 0x28978"),
    ("0x00028e32", "cm550_mainCanTransmissionLoop", "a fall-through point after jsr cm550_diagnosticDataDump inside "
     "mc68k_initializeJ1939Datalink - whose only epilogue pops what 0x28B80 pushed"),
]

s = open(F5, newline="").read()
for address, old, new, plate in RENAMES:
    if f"\n{address},{new}," in s:
        continue
    line = f"\n{address},{old}\n"
    assert s.count(line) == 1, (address, old, s.count(line))
    s = s.replace(line, f"\n{address},{new},{plate} (was {old}; {R})\n")
for address, old, _ in DELETIONS:
    line = f"\n{address},{old}\n"
    if line in s:
        s = s.replace(line, "\n")
fix_old = "mc68k_ because it writes SIM_SWSR - round 84 stage B)"
fix_new = ("mc68k_ because it polls the chip select 2 device's register 0xFFD000 - the watchdog kick alone would not make "
           "it mc68k_ (commit 16143a5c); round 84 stage B / round 85)")
if fix_new not in s:
    assert s.count(fix_old) == 1
    s = s.replace(fix_old, fix_new)
open(F5, "w", newline="").write(s)

x = open(X5, newline="").read()
for address, old, why in DELETIONS:
    if f"\n{address}," not in x:
        x = x.rstrip("\n") + (f"\n{address},not a function entry: {why}; no reference in the dumped ROM (references_to.py) "
                              f"- the row came from the J90280.05 relocation map (was {old}; {R})\n")
open(X5, "w", newline="").write(x)

d = open(D5, newline="").read()
edits = [
    ("0x0001c484,flashEraseRamExecutor,0,start_address,uint,Flash start address to erase",
     "0x0001c484,cm550_flashEraseFromRam,0,block_address,uint,The flash block's base address (0x4000 / 0x6000 / 0)"),
    ("0x0001c484,flashEraseRamExecutor,1,end_address,uint,Flash end address to erase",
     "0x0001c484,cm550_flashEraseFromRam,1,suspend_check_disabled,uint,1 = never suspend the erase (the boot block); 0 = "
     f"suspend when the chip select 2 device's input bit 0 reads 1 (the parameter block savers) ({R})\n"
     "0x0001c484,cm550_flashEraseFromRam,return,,int,The erase result: 0 erased / 1 erase error or timeout / 2 suspended "
     f"({R})"),
    ("0x00034bf8,hardwareTimerDelayLoop,0,timer_ticks,ushort,", "0x00034bf8,mc68k_delayTimeBaseTicksWithWatchdogService2,0,timer_ticks,ushort,"),
    ("0x0001e5f0,tpuChannelConfigurator,0,channel_config,uint,TPU channel configuration value",
     "0x0001e5f0,mc68k_queueCanCs4ReceiveMessage,0,message_object,uint,The 82527 message object number (the low byte of a "
     f"word the callers push) ({R})"),
]
for old, new in edits:
    if new not in d:
        assert d.count(old) == 1, (old[:50], d.count(old))
        d = d.replace(old, new)
open(D5, "w", newline="").write(d)

lv = open(L5, newline="").read()
lv = lv.replace("0x00015f8e,j1708DiagnosticCommandDispatcher,", "0x00015f8e,mc68k_dispatchJ1708ReceivedMessages,")
open(L5, "w", newline="").write(lv)
with open(map5, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n")
    for address, old, new, _ in RENAMES:
        fh.write(f"{address},{new},{old},function,1\n")
print(f"round 85 stage A applied: {len(RENAMES)} renames, {len(DELETIONS)} deletions")
