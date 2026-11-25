"""J2 investigator run 2: corrections to build_result_part1.py after the re-check (each replacement must hit once).
Keeps a copy of the run 1 file as build_result_part1.run1.py."""
import os
import shutil

here = os.path.dirname(os.path.abspath(__file__))
path = os.path.join(here, "build_result_part1.py")
backup = os.path.join(here, "build_result_part1.run1.py")
if not os.path.exists(backup):
    shutil.copy(path, backup)
text = open(backup).read()

REPLACEMENTS = [
    # ---- 0x1fdc0: the reset's call has no network type test
    ("role=\"With the J1922 monitor enabled it records one datalink control occurrence of the given control mode (1 speed / 2 torque / 3 limit): it adds 1 to the total count and to that mode's count and stamps key_on_hour_meter into that mode's time and the last control time.\"",
     "role=\"With the J1922 monitor enabled it records one ended datalink control period of the given control mode (1 speed / 2 torque / 3 limit) in the J1922 monitor's records: it adds 1 to the total count and to that mode's count and stamps key_on_hour_meter into that mode's time and the last control time.\""),
    ("any other mode does nothing. Called with the mode that ends: by cm550_resetEngineTsc1Request, and by cm550_runJ1939PowertrainControlTimeouts when the request changes while the previous network type was 0 (J1922). CM848 has no counterpart: its j1922_monitor_enable has no reader (was cm550_j1939MessageTypeCounter; PR #53 round 93)",
     "any other mode does nothing. Called with the mode that ends: by cm550_runJ1939PowertrainControlTimeouts when the request changes while the previous network type was 0 (J1922), and by cm550_resetEngineTsc1Request when a request times out or reaches its time limit - that call has no network type test, so a J1939 request that ends this way is counted too. CM848 has no counterpart: its j1922_monitor_enable has no reader (was cm550_j1939MessageTypeCounter; PR #53 round 93)"),
    ("Callers: jsr at 0x231fc (the reset 0x231da, argument = the mode it just saved in 0x801982) and jsr at 0x234c2",
     "Callers: jsr at 0x231fc (the reset 0x231da, argument = the mode it just saved in 0x801982; nothing between 0x231da and 0x231fc reads the network type word 0x80da68) and jsr at 0x234c2"),
    # ---- 0x1ff38: the task set by address (its row was renamed after the freeze)
    ("The 10 ms J1939 periodic transmit scheduler, called on each odd executive phase by cm550_oddPhaseSchedulerTaskSet.",
     "The 10 ms J1939 periodic transmit scheduler, the second call of the odd frame task set 0x1b504 (every second 5 ms executive frame)."),
    ("Caller: jsr at 0x1b50a in the task set 0x1b504, which the executive calls on its 20 odd phases.",
     "Caller: jsr at 0x1b50a in the task set 0x1b504, which executiveFrameInterruptHandler calls from 20 places (bsr.w at 0x1b98e ... 0x1be6e), its odd frames."),
    # ---- 0x21920: the flow, explicitly
    ("0x21920 a0 = 0x80bcf6; 0x21928 move.b (a0),d0 / andi.l #0x10: nonzero -> 0x21934 d1 = 0x40 and 0x2194e d1 |= 1; 0x21936 btst #1,(a0) -> 0x2193c d1 |= 0x10; 0x21940 btst #6,(a0) -> 0x21946 d1 |= 4; 0x21952 returns d1.",
     "0x21920 a0 = 0x80bcf6, 0x21926 d1 = 0; 0x21928 move.b (a0),d0 / andi.l #0x10 (d0 keeps bit 4): nonzero -> 0x21934 d1 = 0x40; 0x21936 btst #1,(a0) -> 0x2193c d1 |= 0x10; 0x21940 btst #6,(a0) -> 0x21946 d1 |= 4; 0x2194a tst.l d0 (bit 4 again) -> 0x2194e d1 |= 1; 0x21952 returns d1. So bit 4 gives both 0x40 and 0x01."),
    # ---- 0x21fac: the order of the four clears differs
    ("clr.w (8) (0xa) (0xc) (0xe) | sth 0 -> 14 / 12 / 10 / 8.",
     "clr.w (8) (0xa) (0xc) (0xe) | sth 0 -> 14 / 12 / 10 / 8 - THE ONE DIFFERENCE: the four cleared mode words are stored in ascending order here and in descending order in CM848 (0x50bf4c-0x50bf58 and 0x50bfcc-0x50bfd8); the stores are independent, so the result is the same."),
    ("Same steps and constants. Same Calterm records: 1100 +0 JCEGCOSS",
     "Apart from that store order the same steps in the same order, and the same constants. Same Calterm records: 1100 +0 JCEGCOSS"),
    # ---- 0x231da
    ("Same place, other code and a wider job, so the base name is not shared.\",\n   confidence=\"medium\")",
     "Same call sites and the same resets, but other code and a wider job (the TSC1 lost ramps): a counterpart, and the base name says only what this body does.\",\n   confidence=\"medium\")"),
    # ---- 0x23244: masks, not bit numbers
    ("it alone sets the link timeout fault bits (word 7 bit 3 / word 5 bit 10) and the VSS lost bit (word 4 bit 8).",
     "it alone sets the link timeout fault bits (error status word 7 mask 0x8 for J1708 / J1922, word 5 mask 0x400 for J1939) and the VSS lost bit (word 4 mask 0x100)."),
    ("the J1939 vehicle speed timers (VSS lost fault = word 4 bit 8).",
     "the J1939 vehicle speed timers (VSS lost fault = error status word 4 mask 0x100, e2m VSLOSTER)."),
    ("0x236c2-0x23774 J1708: count 0x804266 below (0x8081fc) - 1 else bit 8 of 0x80600e / 0x80604e; 0x2377a-0x2381a J1939: count 0x804268 below (0x8081fc) else bit 0x400 of 0x80600a / 0x80604a; a pending clear request clears the status bit once it is in 0x806aca / 0x806ac6 and gone from 0x80604e / 0x80604a.",
     "0x236c2-0x23774 J1708 (J1922): count 0x804266 (e2m 11C1 +0 JC17TMCU) + 1 while below (0x8081fc) - 1, else ori.w #8 on 0x80600e and 0x80604e (0x236f0 / 0x236f8) and the count cleared; 0x2377a-0x2381a J1939: count 0x804268 (11C1 +2 JC39TMCU) + 1 while below (0x8081fc), else ori.w #0x400 on 0x80600a and 0x80604a (0x237a0 / 0x237a8); without a timeout a pending clear request clears the status bit (andi.w #0xfff7 at 0x2375c / #0xfbff at 0x23806) once the bit is set in 0x806aca / 0x806ac6 and clear in 0x80604e / 0x80604a."),
    # ---- 0x238ac: no hedge
    (" Reported as a counterpart because a constant differs; a judge who follows the round 91 capacity precedent (registerJ1939ReceiveHandler, 16 against 17) may share the name instead.",
     " One constant differs (5 against 10): a counterpart by this round's rule."),
    # ---- plate wording: task sets by address, frames, no global names that this result renames
    ("plate_comment=\"J1939 receive dispatcher, the first call of the even phase task set 0x1b4d8.",
     "plate_comment=\"J1939 receive dispatcher, the first call of the even frame task set 0x1b4d8 (frames 0, 2, ... of the 40-frame executive cycle: every 10 ms)."),
    ("third call of the even phase task set 0x1b4d8: it tracks",
     "third call of the even frame task set 0x1b4d8: it tracks"),
    ("second call of the even phase task set 0x1b4d8: the high idle override",
     "second call of the even frame task set 0x1b4d8: the high idle override"),
    ("Runs on each odd executive phase, right before the periodic transmit queues (was cm550_FUN_0002142c",
     "The first call of the odd frame task set 0x1b504, right before the periodic transmit queue runner (was cm550_FUN_0002142c"),
    ("in the odd phase set; CM848 cm848_phase_group_a_processing, frozen cpp line 6805, in the even phase group).",
     "in the odd frame task set; CM848 cm848_phase_group_a_processing, frozen cpp lines 6805 / 6806)."),
    ("0x23920 counts (6) down each odd phase and moves",
     "0x23920 counts (6) down in each odd frame and moves"),
    ("a mode count of 1 with datalink_speed_control_mode as first entry",
     "a mode count of 1 with the engine control mode 0x80da50 as first entry"),
    ("It compares datalink_speed_control_mode / engine_control_network_type / datalink_command_source_id and retarder_control_mode",
     "It compares the engine control mode 0x80da50 / engine_control_network_type / datalink_command_source_id and retarder_control_mode"),
    ("then sets datalink_speed_control_mode to 0, the control device",
     "then sets the engine control mode 0x80da50 to 0, the control device"),
    ("The engine twin of resetEngineRetarderTsc1Request; CM848's function in its place",
     "The engine-side sibling of resetEngineRetarderTsc1Request; CM848's function in its place"),
]
for old, new in REPLACEMENTS:
    n = text.count(old)
    assert n == 1, (n, old[:90])
    text = text.replace(old, new)
open(path, "w").write(text)
print("patched", len(REPLACEMENTS), "places")
