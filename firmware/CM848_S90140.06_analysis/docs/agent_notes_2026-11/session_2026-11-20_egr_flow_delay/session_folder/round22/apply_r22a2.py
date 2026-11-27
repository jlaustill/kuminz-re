"""Round 22 stage A, part 2 (label-only): the module's two unnamed words, and the configuration flags documented.
- 0x3fbd3a (DAT_003fbd3a, lha / sth): cm848_resetEngineProtectionShutdownState copies
  engine_protection_shutdown_active_channel_cal into it at boot / restart, and cm848_updateEngineProtectionShutdown
  counts a new shutdown in engine_protection_shutdown_count_cal only when it is on this channel again;
- 0x3fbd4e (DAT_003fbd4e, word): the lookup cache of fault_derate_fuel_limit_by_engine_speed at the engine speed
  (cm848_calculateFaultDerateFuelLimit), preset to 2 by cm848_resetFaultDerateFuelLimit;
- engine_protection_channel_configuration_t.configuration_flags: not a clean bitfield (most tests go through a whole
  word copy, with combined masks 0x30 / 0x101 / 0x402 / 0x300 / 0xc00 / 0xc), so the bits are documented in its
  comment, each from the code that tests it.
usage: apply_r22a2.py <repo> <map.csv>"""
import os
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
gp, sp = os.path.join(out, "global_variables.csv"), os.path.join(out, "structure_definitions.csv")
g = open(gp).read().split("\n")
ROWS = [
    (0x3fbd3a, "engine_protection_power_up_shutdown_channel", "i16",
     "The engine protection shutdown channel recorded at power-up / restart: cm848_resetEngineProtectionShutdownState "
     "copies engine_protection_shutdown_active_channel_cal here, and cm848_updateEngineProtectionShutdown increments "
     "engine_protection_shutdown_count_cal only when a new shutdown is on this channel again (lha, sth)"),
    (0x3fbd4e, "fault_derate_fuel_limit_by_engine_speed_cached_axis_offset", "word",
     "Lookup cache of fault_derate_fuel_limit_by_engine_speed at the filtered engine speed "
     "(cm848_calculateFaultDerateFuelLimit); preset to 2 by cm848_resetFaultDerateFuelLimit. The table's cache for "
     "the J1939 torque curve points is fault_derate_torque_curve_points_cached_axis_offset"),
]
for address, name, typ, comment in ROWS:
    assert not any(l.startswith(f"0x{address:08x},") for l in g), hex(address)
    i = max(j for j, l in enumerate(g) if l.startswith("0x") and int(l[:10], 16) < address)
    g.insert(i + 1, f"0x{address:08x},{name},{typ},{comment} (PR #53 round 22)")
open(gp, "w").write("\n".join(g))
FLAGS = ("Configuration flags, from the code that tests each bit (no e2m bit records): 0x1 fueling derate "
         "(cm848_calculateFaultDerateFuelLimit; the fueling restart index); 0x2 engine speed derate "
         "(cm848_calculateFaultDerateEngineSpeedLimit; the engine speed restart index); 0x101 / 0x402 count the "
         "fueling / engine speed over-limit duration; 0x4 the input is past its threshold when above it (clear: below); "
         "0x8 the fault log's extreme value starts at 0x7fff (the minimum is tracked; clear: 0x8000, the maximum); 0xc "
         "track the extreme at all; 0x30 a switch input (its masked bit, not a threshold): 0x10 active while the bit is "
         "set, 0x20 while it is clear; 0x40 the fueling restart index is 0x100 instead of interpolated; 0x300 the "
         "fueling shutdown (0x100 by the over-limit duration, else by the severity threshold); 0xc00 the engine speed "
         "shutdown (0x400 by duration, else by severity); 0x1000 the engine speed fault shares the fueling fault log "
         "(hpcr_initializeEngineProtection)")
lines = open(sp).read().split("\n")
prefix = "engine_protection_channel_configuration_t,,configuration_flags,word,2,"
k = [i for i, l in enumerate(lines) if l.startswith(prefix)]
assert len(k) == 1
line = lines[k[0]]
assert line.endswith('",,verified') and '"' not in FLAGS
lines[k[0]] = line[:-len('",,verified')] + " | " + FLAGS + '",,verified'
open(sp, "w").write("\n".join(lines))
with open(map_path, "a") as fh:
    fh.write("0x003fbd3a,engine_protection_power_up_shutdown_channel,DAT_003fbd3a,global\n"
             "0x003fbd4e,fault_derate_fuel_limit_by_engine_speed_cached_axis_offset,DAT_003fbd4e,global\n")
print("2 rows, the flags comment, 2 map rows")
