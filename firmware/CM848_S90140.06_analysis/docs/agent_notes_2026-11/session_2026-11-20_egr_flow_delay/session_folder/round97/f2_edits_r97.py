"""Round 97 stage F2 (from stage F's proof review, settled from the machine code of both firmwares):
- CM550 0x18f86 incrementDiagnosticCounters is the twin of CM848 0x508834 cm848_countEngineProtectionShutdownTime:
  the same steps in the same order (cmpi.w #0xffff / addq.w #1 on state +0x1a or +0x1c by the flag word, then while the
  engine start flag is set move.w configuration +0x14 -> state +0x1e or +0x20), the same constants, and the same caller
  (the engine protection shutdown task). Both rows take the shared name countEngineProtectionShutdownTime; CM550 gets
  the full prototype (configuration long +4, state long +8, is_engine_speed word +12, no result).
- CM550 0x800620 (no row) is CM848's engine_protection_engine_start_flag: set at 0x1903e when 0x80061a is 0 and
  filtered_engine_speed is not, cleared at 0x19048; read at 0x18fb0.
- CM550 0x80061a general_counter_1 is CM848's engine_protection_previous_engine_speed: written with filtered_engine_speed
  at 0x192d0 (the end of the shutdown task), read at 0x1902e.
usage: f2_edits_r97.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
O5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
O8 = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 97"


def load(p):
    t = open(p, newline="").read()
    E = "\r\n" if "\r\n" in t else "\n"
    return t.split(E), E


def save(p, lines, E):
    open(p, "w", newline="").write(E.join(lines))


# CM550 function row
p = os.path.join(O5, "function_renames.csv")
lines, E = load(p)
i = next(k for k, l in enumerate(lines) if l.startswith("0x00018f86,"))
assert lines[i].rstrip(",") == "0x00018f86,incrementDiagnosticCounters", lines[i]
lines[i] = ("0x00018f86,countEngineProtectionShutdownTime,Counts the channel's fueling (is_engine_speed 0) or engine speed "
            "shutdown time up by one (state->fueling_shutdown_time_count / engine_speed_shutdown_time_count, saturating at "
            "0xffff) and, in the engine start pass (engine_protection_engine_start_flag), copies configuration->shutdown_delay "
            "into the matching start warning time. processDiagnosticLimitStatus (engine protection task 4) calls it for a "
            "channel past its shutdown threshold. The twin of CM848 0x00508834: one shared name (was "
            f"incrementDiagnosticCounters; {R})")
save(p, lines, E)
# CM848 function row
p = os.path.join(O8, "function_renames.csv")
lines, E = load(p)
i = next(k for k, l in enumerate(lines) if l.startswith("0x00508834,"))
head, plate = lines[i].split(",", 2)[1], lines[i].split(",", 2)[2]
assert head == "cm848_countEngineProtectionShutdownTime", head
lines[i] = (f"0x00508834,countEngineProtectionShutdownTime,{plate} | the twin of CM550 0x00018f86: one shared name (was "
            f"cm848_countEngineProtectionShutdownTime; {R})")
save(p, lines, E)
# CM550 prototype
p = os.path.join(O5, "function_definitions.csv")
lines, E = load(p)
old = [k for k, l in enumerate(lines) if l.startswith("0x00018f86,")]
assert len(old) == 3, old
lines[old[0]:old[-1] + 1] = [
    f"0x00018f86,countEngineProtectionShutdownTime,return,,void,No result: d0 holds is_engine_speed at the rts and the two calls in processDiagnosticLimitStatus ignore it ({R})",
    f"0x00018f86,countEngineProtectionShutdownTime,0,configuration,engine_protection_channel_configuration_t*,The channel's configuration: the long at +4 (movea.l (0x4;a7);a0); only its shutdown_delay (+0x14) is read (was source_pointer int; {R})",
    f"0x00018f86,countEngineProtectionShutdownTime,1,state,cm550_engine_protection_channel_state_t*,The channel's state: the long at +8 (movea.l (0x8;a7);a1); +0x1a / +0x1c counted and +0x1e / +0x20 set (was destination_pointer int; {R})",
    f"0x00018f86,countEngineProtectionShutdownTime,2,is_engine_speed,ushort,0 = the fueling count / 1 = the engine speed count: the word at +12 (move.w (0xc;a7);d0) (was condition_flag; {R})"]
save(p, lines, E)
# CM848 prototype / local rows follow the name
for f in ("function_definitions.csv", "local_variables.csv"):
    p = os.path.join(O8, f)
    lines, E = load(p)
    n = 0
    for k, l in enumerate(lines):
        if l.startswith("0x00508834,cm848_countEngineProtectionShutdownTime,"):
            lines[k] = "0x00508834,countEngineProtectionShutdownTime," + l.split(",", 2)[2]
            n += 1
    save(p, lines, E)
    print("CM848", f, n, "rows re-keyed")
# CM550 globals
p = os.path.join(O5, "global_variables.csv")
lines, E = load(p)
i = next(k for k, l in enumerate(lines) if l.startswith("0x0080061a,"))
assert lines[i].split(",")[1] == "general_counter_1", lines[i]
lines[i] = ("0x0080061a,engine_protection_previous_engine_speed,word,filtered_engine_speed at the end of the last "
            "processDiagnosticLimitStatus pass (move.w (0x80ccf6).l to it at 0x192d0); the engine start test at 0x1902e "
            "reads it. CM848's engine_protection_previous_engine_speed (0x3fbd36) has the same role (was "
            f"general_counter_1; {R})")
assert not any(l.startswith("0x00800620,") for l in lines)
k = next(k for k, l in enumerate(lines) if l.startswith("0x") and int(l.split(",", 1)[0], 16) > 0x800620)
lines.insert(k, "0x00800620,engine_protection_engine_start_flag,word,1 in the pass where the engine speed leaves 0: "
             "processDiagnosticLimitStatus sets it when engine_protection_previous_engine_speed is 0 and "
             "filtered_engine_speed is not (0x1902e-0x1903e) and clears it otherwise (0x19048); "
             "countEngineProtectionShutdownTime then copies the shutdown delay into the start warning times (0x18fb0). "
             f"CM848's engine_protection_engine_start_flag (0x3fbd3c) (new row; {R})")
save(p, lines, E)
print("F2 edits applied")
