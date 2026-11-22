"""Round 21 stage C, part 2 (label-only): the two engine protection words the worklist tool cannot take - 0x3fbd4a has
a row but no name (it rendered as Ghidra's PTR_engine_startup_inhibit_cal_003fbd4a, after its boot copy's value), and
0x40a78b has no row (DAT_0040a78b). Appends their map rows. usage: apply_r21c2.py <repo> <map.csv>"""
import os
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
gp = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/global_variables.csv")
g = open(gp).read().split("\n")
k = [i for i, l in enumerate(g) if l.startswith("0x003fbd4a,,engine_protection_channel_history_t*,")]
assert len(k) == 1
a, n, t, c = g[k[0]].split(",", 3)
g[k[0]] = ",".join([a, "engine_protection_current_history", t,
                    "The history record of the channel cm848_logEngineProtectionChannelFaults is on (the two fault log "
                    "helpers read it); it rendered as PTR_engine_startup_inhibit_cal_003fbd4a, Ghidra's name after its "
                    "boot copy's value | " + c])
assert not any(l.startswith("0x0040a78b,") for l in g)
row = ("0x0040a78b,engine_protection_shutdown_override_lamp_flag,byte,e2m 10B1 +19 EPF_Shutdown_Override_Lamp_Flag "
       "'[EPSOLPFG] True indicates starting epf shutdown override lamp sequencing': set to 1 when a shutdown override "
       "request takes effect (cm848_updateEngineProtectionShutdown, cm848_checkEngineProtectionRestartLimitation), 0 in "
       "cm848_completeEngineStartSequence; four stb, no reader in this build")
i = max(j for j, l in enumerate(g) if l.startswith("0x") and int(l[:10], 16) < 0x40a78b)
g.insert(i + 1, row)
open(gp, "w").write("\n".join(g))
with open(map_path, "a") as fh:
    fh.write("0x003fbd4a,engine_protection_current_history,PTR_engine_startup_inhibit_cal_003fbd4a,global\n"
             "0x0040a78b,engine_protection_shutdown_override_lamp_flag,DAT_0040a78b,global\n")
print("0x3fbd4a named, 0x40a78b row added, 2 map rows")
