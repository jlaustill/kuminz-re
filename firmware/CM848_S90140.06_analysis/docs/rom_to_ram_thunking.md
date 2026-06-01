# Deferred: ROM-to-RAM thunking as a deterministic build step

**Status:** IMPLEMENTED 2026-06-01 (`ApplyRomToRamThunks.java`, wired into CM848 `cmd_build`).
func_0x 26 → 0; deterministic (29 thunks, 0-diff verify); 0 curated names lost. Notes below
kept for reference. Two refinements vs the original design: (1) only thunk RAM addresses that
are NOT already curated (preserve `*_ramcopy`/named RAM copies; ROM↔RAM names can disagree, so
the curated name wins); (2) `ExportAnalysis` skips RAM-region thunks (0x3F9800–0x3FDB30) from
decompilation — their garbage bytes decompile to noise, and callers already render the ROM name.

## Background — what these calls are

At boot, `copyCalibrationToRam()` copies ROM `0x3C30–0x7F60` (~17 KB) into RAM
`0x3F9800–0x3FDB30` and the MPC555 runs that code from RAM (faster than flash). So each of
~50 functions exists twice: the original in ROM, and a live copy in RAM.

When other code calls into the RAM copy (`bl 0x3Fxxxx`), Ghidra has no function at the RAM
address (it only analyzed the ROM original), so the decompiler emits `func_0x003fae3c()`
instead of the real name. The live RAM dump bytes there are CAN-overwritten garbage, so we
must NOT disassemble them — we point at the ROM source instead.

## The map (verified)

```
ROM_addr = 0x3C30 + (RAM_addr - 0x3F9800)
```
Verified against the documented `dispatchCanMessageHandlers` (RAM 0x3FAE3C → ROM 0x526C).

## The mechanism — thunks (proven earlier this session)

A **thunk** is a tiny function record at the RAM address that redirects to the ROM function.
Ghidra then renders the call with the ROM function's name AND its real signature (so the
return value gets captured too). Proven: `func_0x003fae3c()` → `mpc555_dispatchCanMessageHandlers()`.

Creation recipe (the old `CreateRomToRamThunks.java`, now deleted — reimplement as a build step):
1. The RAM address must be in MAPPED memory. The RAM block starts at `0x3FA000`; targets below
   it need the `ROMRAM_LOW` block (`0x3F9800–0x3F9FFF`, mirrored from ROM `0x3C30`) — this block
   is ALREADY created by `SetupMemoryMapCM848.java` (kept), so memmap covers the whole region.
2. RAM bytes are garbage → do NOT let Ghidra disassemble them. `listing.clearCodeUnits(ram, ram+3)`
   then build a thunk over an explicit 4-byte body:
   `new CreateThunkFunctionCmd(ramAddr, new AddressSet(ramAddr, ramAddr.add(3)), romAddr).applyTo(program)`.
   (Passing a null body makes the cmd try to disassemble the garbage and fail.)
3. Idempotent: skip if a thunk already exists at the address.

## Current targets (26, regenerate from the formula each build)

The build step should NOT hard-code these — derive them: for every `func_0x003fxxxx` (or every
known RAM-region function-call target) in `0x3F9800–0x3FDB30`, compute the ROM address and thunk
to the function there. Snapshot of the current set (RAM,ROM,ROM-function-name):

```
0x003fa5a0,0x0049d0,mpc555_initFlashMemoryConfig
0x003faafc,0x004f2c,cm848_writeCan2ControllerTxMailbox
0x003fae3c,0x00526c,mpc555_dispatchCanMessageHandlers
0x003fb528,0x005958,cm848_getServiceDataOffset
0x003fb54c,0x00597c,validateServiceDataLength
0x003fb6ac,0x005adc,mpc555_multiFrameCanTransmit
0x003fc094,0x0064c4,cm848_processJ1939QueueStatus
0x003fc0d8,0x006508,mpc555_initDiagnosticBuffers
0x003fc380,0x0067b0,mpc555_serialReceiveHandler
0x003fc484,0x0068b4,serialTransmitHandler
0x003fc580,0x0069b0,mpc555_validateSerialChecksum
0x003fc62c,0x006a5c,mpc555_initSerialTransmit
0x003fc688,0x006ab8,mpc555_sensorFaultDetection
0x003fc6f4,0x006b24,mpc555_updateSensorDiagnostics
0x003fc77c,0x006bac,cm848_sensorInputProcessing
0x003fc874,0x006ca4,cm848_processMainLoop
0x003fc9ec,0x006e1c,cm848_sendEepromVersionResponse
0x003fca7c,0x006eac,mpc555_handleEepromDiagnosticResponse
0x003fcb24,0x006f54,mpc555_processEepromDataTransfer
0x003fd070,0x0074a0,cm848_processSensorFilterChain
0x003fd1ac,0x0075dc,mpc555_processSensorWithOverride
0x003fd1d8,0x007608,mpc555_watchdogTimerTick
0x003fd284,0x0076b4,mpc555_watchdogTimerTick_midEntry
0x003fd298,0x0076c8,cm848_sensorFaultThresholdCheck
0x003fd544,0x007974,mpc555_systemWatchdogReset
0x003fd994,0x007dc4,mpc555_systemHaltLoop
```

## How to make it a build step (the deferred work)

1. New script `ApplyRomToRamThunks.java` (mirrors the deleted `CreateRomToRamThunks.java`):
   iterate the region, for each RAM call-target compute ROM via the formula, thunk to the ROM
   function if one exists there. Deterministic; idempotent.
2. Wire into CM848 `cmd_build` AFTER `analyze` (and after `deletions`/second `import`), before
   `export` — so thunks exist when the decompilation is written. Single-threaded already.
3. Re-baseline + `verify` (must stay byte-identical across two builds).
4. CM848-only (CM550 has no ROM-to-RAM copy region).

## Wrinkles / things we already learned
- The 3 targets below `0x3FA000` need `ROMRAM_LOW` — already mapped, don't remove it.
- Whether RAM should be executable: making it non-executable did NOT change the spurious-DAT_
  situation (that was the uRam/DAT_ artifact), so leave RAM as-is unless a new reason appears.
- Expected payoff: `func_0x` 26 → ~0 in `cm848_rom.ghidra.cpp`.
