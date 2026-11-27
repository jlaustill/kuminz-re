"""Round 96 tooling: derive the round 96 workflow from round 95's (the same investigator / independent describer /
judge prompts, schemas incl. prototypes[] and the 'prototype' verdict kind, and sturdy() restarts) with R = the round 96
folder (frozen copies of HEAD bdf1fdf8 in r96/frozen) and five batches:
Q1 the periodic J1939 broadcast builders of both firmwares, paired by PGN through the scheduleJ1939PeriodicMessage
   calls; Q2 CM550's PGN 59904 request responders and the J1939 receive / request code around 0x2ec50-0x2fbb2 with
   CM848's counterparts; Q3 CM550's placeholders in 0x10000-0x1ffff; Q4 the rest of CM550's placeholders; Q5 CM848's
   time-shared boot kernel RAM 0x3fdba4-0x3fdc38 (the CMF erase / program step tables named qadc_*).
usage: make_workflow_r96.py <workflow_r95.js> <out.js>"""
import sys

src, out = sys.argv[1], sys.argv[2]
s = open(src).read()


def rep(old, new, count=1):
    global s
    assert s.count(old) == count, (old[:80], s.count(old))
    s = s.replace(old, new)


rep("name: 'kuminz-naming-round-95',", "name: 'kuminz-naming-round-96',")
rep("description: 'Round 95 naming (CM550 placeholder functions 0x30000-0x34fff, CM550 1-D lookup records, prototypes and leads): investigator + independent describer + judge per batch, restarted from notes on API errors',",
    "description: 'Round 96 naming (the periodic J1939 builders of both firmwares by PGN, CM550 request responders, CM550 placeholders 0x0-0x2dfff, CM848 boot kernel CMF tables): investigator + independent describer + judge per batch, restarted from notes on API errors',")
rep("const R = '/home/linux/.claude/jobs/374b0424/tmp/w15/r95'", "const R = '/home/linux/.claude/jobs/374b0424/tmp/w15/r96'")
rep("CONTEXT (PR #53 of the kuminz-re Cummins ECU reverse engineering repository, round 95).",
    "CONTEXT (PR #53 of the kuminz-re Cummins ECU reverse engineering repository, round 96).")
start = s.index("const BATCHES = [")
end = s.index("\n]\n", start) + 3
Q3 = ("0x10e06 cm550_FUN_00010e06; 0x1266e mc68k_FUN_0001266e; 0x127c2 vp44_FUN_000127c2; 0x133fc cm550_FUN_000133fc; "
      "0x133fe vp44_FUN_000133fe; 0x142d4 cm550_FUN_000142d4; 0x14348 cm550_FUN_00014348; 0x14812 cm550_FUN_00014812; "
      "0x17baa cm550_FUN_00017baa; 0x183cc cm550_FUN_000183cc (round 95: it caps the five torque curve fueling points by the fault derate limit at each point's speed); "
      "0x184c6 cm550_FUN_000184c6; 0x185f0 cm550_FUN_000185f0; 0x192e0 cm550_FUN_000192e0; 0x19702 cm550_FUN_00019702; "
      "0x19caa mc68k_FUN_00019caa; 0x19e8e cm550_FUN_00019e8e; 0x1a298 cm550_FUN_0001a298; 0x1a350 mc68k_FUN_0001a350; "
      "0x1a47c mc68k_FUN_0001a47c; 0x1a52a cm550_FUN_0001a52a; 0x1a89a cm550_FUN_0001a89a; 0x1a8a2 cm550_FUN_0001a8a2; "
      "0x1b1ea mc68k_FUN_0001b1ea; 0x1b30a mc68k_FUN_0001b30a; 0x1b4b2 mc68k_FUN_0001b4b2; 0x1c7a8 cm550_FUN_0001c7a8; "
      "0x1c824 cm550_FUN_0001c824; 0x1c8a0 cm550_FUN_0001c8a0; 0x1cad6 vp44_FUN_0001cad6; 0x1cb3c vp44_FUN_0001cb3c; "
      "0x1cb48 cm550_FUN_0001cb48; 0x1cdf8 cm550_FUN_0001cdf8; 0x1dbd8 cm550_FUN_0001dbd8; 0x1ddb4 cm550_FUN_0001ddb4; "
      "0x1de58 cm550_FUN_0001de58; 0x1e04c cm550_FUN_0001e04c; 0x1f4e8 cm550_FUN_0001f4e8")
Q4 = ("0xb3d0 cm550_FUN_0000b3d0; 0xc87c cm550_FUN_0000c87c; 0xc87e cm550_FUN_0000c87e; 0xc880 cm550_FUN_0000c880; "
      "0xd3b2 cm550_FUN_0000d3b2; 0xd4ae cm550_FUN_0000d4ae; 0xf716 cm550_FUN_0000f716; 0xf99a cm550_FUN_0000f99a; "
      "0xf99c cm550_FUN_0000f99c; 0xfa68 vp44_FUN_0000fa68; 0xff48 cm550_FUN_0000ff48; 0x22530 cm550_FUN_00022530; "
      "0x2257c cm550_FUN_0002257c; 0x225e0 cm550_FUN_000225e0; 0x22646 cm550_FUN_00022646; 0x2268e cm550_FUN_0002268e; "
      "0x226da cm550_FUN_000226da; 0x24804 cm550_FUN_00024804; 0x25806 cm550_FUN_00025806; 0x25a34 vp44_FUN_00025a34; "
      "0x26616 cm550_FUN_00026616; 0x26b3a cm550_FUN_00026b3a; 0x26b82 cm550_FUN_00026b82; 0x26e86 cm550_FUN_00026e86; "
      "0x26e8e cm550_FUN_00026e8e; 0x277e6 cm550_FUN_000277e6; 0x27c20 vp44_FUN_00027c20; 0x2cf52 cm550_FUN_0002cf52; "
      "0x2cf7e cm550_FUN_0002cf7e; 0x2ddbc cm550_FUN_0002ddbc")
BATCHES = r"""const BATCHES = [
  { id: 'Q1', title: "The periodic J1939 broadcast builders of both firmwares, paired by PGN", text: `Both firmwares start their periodic J1939 broadcasts with 19 calls of scheduleJ1939PeriodicMessage(queue, PGN key, interval ms, first-send offset ms, builder) (CM550 0x1fe84 in mc68k_initializeJ1939Datalink, CM848 0x538c8c in cm848_j1939_system_init; both prototypes were typed in round 95). The builder argument is the function the periodic transmit code calls when the message is due. Pairing the calls by PGN (queue / PGN / interval / offset / CM550 builder / CM848 builder):
ENGINE 65265 100 0x46 j1939HandlePgn65265CruiseVehicleSpeed / cm848_buildPgn65265CruiseControlVehicleSpeedMessage
ENGINE 61444 0x14 0 sendPgn61444ElectronicEngineController1Message / the same (a twin)
ENGINE 61443 0x32 (CM848 0x14) 10 j1939HandlePgn61443Eec2 / cm848_buildPgn61443ElectronicEngineController2Message
ENGINE 65247 0xfa (CM848 0x32) 0x1e vp44_configParamCanBuilder / cm848_buildPgn65247ElectronicEngineController3Message
ENGINE 65251 5000 0x6e sendPgn65251EngineConfiguration1Message / the same (a twin)
RETARDER 61440 100 0x32 cm550_dutyCycleMonitorAltIsrHandler / cm848_buildPgn61440ElectronicRetarderController1Message
ENGINE 65266 100 0x5a cm550_fuelEconomyDataBuilder / (CM848 schedules 65241 cm848_buildPgn65241AuxiliaryInputOutputStatus1Message instead)
RETARDER 65249 5000 0x12d vp44CanMessage100ResponseBuilder / cm848_buildPgn65249RetarderConfigurationMessage
ENGINE 65262 1000 0x1ae cm550_buildPgn65262EngineTemperature1Message / cm848_buildPgn65262EngineTemperature1Message
ENGINE 65252 1000 0x6e cm550_buildPgn65252ShutdownMessage / (none)
ENGINE 65263 / 65264 / 65269 / 65270: cm550_buildPgn6526xxx... / cm848_buildPgn6526xxx... (named in round 95)
ENGINE 65271 1000 0xd2 cm550_retarderDataBuilder / cm848_j1939HandlePgn65271VehicleElectrical
ENGINE 65504 200 0xfa (CM848 only) cm848_j1939HandlePgn65504ProprietaryB
ENGINE 65226 1000 500 &LAB_0003229a (CM550: NO function yet) / cm848_processDm1FaultBroadcast
ENGINE 65213 1000 0x32 &LAB_000339fe (no function yet) / cm848_buildPgn65213FanDrive1Message
ENGINE 61441 100 0x14 &LAB_00032bbc (no function yet) / cm848_j1939BuildEngineControlByte
ENGINE 65279 10000 0x28 &LAB_00034496 (no function yet) / cm848_sendPgn65279WaterInFuelIndicatorMessage
YOUR TASK: for every builder of both firmwares, read its code and confirm what it builds and sends (the PGN's payload: use the j1939 Mongo PGN / SPN definitions through the j1939-lookup skill to name each byte it fills), then name it: <firmware prefix>_buildPgn<N><MessageName>Message for a builder that fills a payload (or send... when it also calls the send function and the repository already uses that word for the pair; follow the existing CM848 names), with the J1939-71 message name spelled out (ElectronicRetarderController1, VehicleElectricalPower1, ...). A builder whose code is identical in both firmwares is a twin and shares one unprefixed name (both rows renamed); otherwise each keeps its firmware prefix. Wrong names to correct include the "Handle" builders (they handle no received message), cm550_dutyCycleMonitorAltIsrHandler, vp44_configParamCanBuilder, vp44CanMessage100ResponseBuilder, cm550_retarderDataBuilder, cm550_fuelEconomyDataBuilder and cm848_j1939BuildEngineControlByte. The four CM550 builders with no function (0x3229a / 0x339fe / 0x32bbc / 0x34496) need a function row: give them in functions[] with current_name '' and say where each one ends (its rts) and that nothing else enters it. Name the payload / status / descriptor globals the builders own when the code and the PGN definition prove them (globals[] with the firmware).`},
  { id: 'Q2', title: "CM550's PGN 59904 request responders and the J1939 receive / request code 0x2ec50-0x2fbb2", text: `Round 95's N1 judge left these leads: cm550_diagnosticDataDump (0x2f538) is the request-responder registration list; 0x2f47e registers a PGN 59904 request responder (32 entries of 6 bytes at 0x801d5a: a PGN word and a function pointer; the count word at 0x801e1a) and 0x2f4be dispatches the requests; neither 0x2f47e nor the table has a row. The CM550 placeholders in this area are 0x2ec50 cm550_FUN_0002ec50; 0x2ed62 cm550_FUN_0002ed62; 0x2ef4a cm550_FUN_0002ef4a (it reads the byte 0x801d3c, eight bytes before j1939_powertrain_messages_received); 0x2f4be cm550_FUN_0002f4be; 0x2f606 cm550_FUN_0002f606; 0x2faa4 cm550_FUN_0002faa4; 0x2fbb2 cm550_FUN_0002fbb2.
YOUR TASK: name the registrar, the dispatcher, the registration list and every responder they register (each answers a request for one PGN: name it from the PGN with the j1939-lookup skill and from what it sends), the table and its count (a struct for the 6-byte entry if the code proves it: give its fields in notes with offsets / types / sizes), and the placeholders above. Find CM848's counterparts: CM848 registers its request responders too (the cm848_initialize...Handler functions, e.g. cm848_initializePgn65234Dm10Handler, and a PGN 59904 request dispatcher); twins share one unprefixed name. A function row is needed for any responder that has none (functions[] with current_name '').`},
  { id: 'Q3', title: "CM550's placeholders in 0x10000-0x1ffff", text: `These CM550 functions still carry the decompiler's placeholder name. Name each one from its code, as the earlier batches did (role, discriminator, relation to CM848, plate comment, evidence):
""" + Q3 + r""".
A vp44_ / mc68k_ prefix is right only for code that handles the VP44 pump / a generic 68k or MC68336 driver; check it. Name the globals these functions own where the code and the e2m record prove them.`},
  { id: 'Q4', title: "CM550's other placeholders (0x0-0xffff and 0x20000-0x2dfff)", text: `These CM550 functions still carry the decompiler's placeholder name. Name each one from its code, as the earlier batches did (role, discriminator, relation to CM848, plate comment, evidence):
""" + Q4 + r""".
A vp44_ prefix is right only for code that handles the VP44 pump; check it. Name the globals these functions own where the code and the e2m record prove them.`},
  { id: 'Q5', title: "CM848's time-shared boot kernel RAM 0x3fdba4-0x3fdc38", text: `RAM 0x3fdba4-0x3fdc38 holds the boot reflash kernel's CMF (flash) erase / program parameters during boot and reflash (mpc555_cmfEraseBlocks 0x49d0, mpc555_cmfSelectBlockAndStartSequence / mpc555_cmfLoadProgramPage / mpc555_cmfApplyHighVoltagePulse / mpc555_cmfEndHighVoltagePulse / mpc555_cmfRestoreNormalMode 0x4320-0x46dc; mpc555_initHardwareConfig 0x1454 fills them), but some of the same addresses are read by application code at run time (firmware/CLAUDE.md names 0x3fdba4 / 0x3fdba8 / 0x3fdbb2 / 0x3fdbd1 / 0x3fdbd2 / 0x3fdbdc / 0x3fdbfe). Many rows there carry QADC names (qadc_control_word_cal / qadc_channel_config_mask_c ... / qadc_queue_timing_config ...) that look wrong: the boot code writes per-step CMFTST / CMFCTL values (0xc20, 0xd20 ... and 0x4f0000 / 0xf0000) into them.
YOUR TASK: for every row in 0x3fdba4-0x3fdc38, find its boot users and its application users (caller >= 0x7f60 in ROM or flash2; a name grep misses users that reach it through a base register: scan the disassembly). Boot-only rows take a name from their CMF role (the MPC555 CMF registers: CMFMCR / CMFTST / CMFCTL; the erase / program step tables, their counts and timings) and a type that fits (word[N] / dword[N] tables where the code indexes them). Dual-use rows keep an application-side name but it must be right for the application use (fix it if not) and their comment must document both roles. _cal only where the row lies in the EEPROM mirror 0x3fd482-0x3feec1 AND the application reads it as an EEPROM value (0x3fdba4-0x3fdc38 is inside the mirror range: check whether the application load covers it). Give each row as a globals[] element with firmware CM848.`},
]
"""
s = s[:start] + BATCHES + s[end:]
open(out, "w").write(s)
print("written", out, len(s))
