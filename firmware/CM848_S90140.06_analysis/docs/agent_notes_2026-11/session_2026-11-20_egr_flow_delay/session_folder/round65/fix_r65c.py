"""Round 65 follow-up (the advisor's closing review). Idempotent.
- cm848_updateCylinderCutoutAndInjectionQuantities -> cm848_updateCylinderCutoutAndInjectionDemand: it also writes the
  pilot / main / auxiliary timings for the cylinder event and main_injection_timing_for_air_handling.
- The two TPU-A handler plates still cited schedule_crankValid / schedule_crankInvalid (short old names no refresh
  matched): now cm848_scheduleInjectionAnglesInSpeedLimpHome / cm848_scheduleInjectionAnglesOnPrimarySpeedInput (the
  rename history and the channel 10 handler's branches agree).
- docs/tpu_mios_channel_map.md and four memory notes on the current names.
usage: fix_r65c.py <repo> --csv <map.csv> | --docs <pr_body.md> <hash>"""
import os
import re
import sys

repo, phase = os.path.abspath(sys.argv[1]), sys.argv[2]
O = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
MEM = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
R = "PR #53 round 65"
LIMP, PRIMARY = "cm848_scheduleInjectionAnglesInSpeedLimpHome", "cm848_scheduleInjectionAnglesOnPrimarySpeedInput"


def edit(path, old, new, count=1):
    p = path if os.path.isabs(path) else os.path.join(repo, path)
    s = open(p).read()
    if new in s and old not in s:
        return
    assert s.count(old) == count, (path, old[:70], s.count(old))
    open(p, "w").write(s.replace(old, new))


def subword(path, old, new):
    p = path if os.path.isabs(path) else os.path.join(repo, path)
    s = open(p).read()
    t = re.sub(rf"(?<![\w]){re.escape(old)}\b", new, s)
    if t != s:
        open(p, "w").write(t)


if phase == "--csv":
    map_path = sys.argv[3]
    fp = os.path.join(O, "function_renames.csv")
    edit(fp, "0x0052731c,cm848_updateCylinderCutoutAndInjectionQuantities,Debounced cylinder-cutout evaluation (fault "
             "masks 0x55 / 0xaa per bank -> cylinder_cutout_mask; can clear TPU-A channel 4 enable bit) then the "
             "per-cylinder timing demand: rate-limits injection_quantity_scale_factor and computes "
             "total_injection_quantity / pilot_injection_quantity / auxiliary_injection_quantity with the cylinder trim",
         "0x0052731c,cm848_updateCylinderCutoutAndInjectionDemand,Debounced cylinder-cutout evaluation (fault masks 0x55 "
         "/ 0xaa per bank -> cylinder_cutout_mask; can clear TPU-A channel 4 enable bit) then the per-cylinder injection "
         "demand: it rate-limits injection_quantity_scale_factor / computes total_injection_quantity / "
         "pilot_injection_quantity / auxiliary_injection_quantity with the cylinder trim / sets the pilot / main / "
         "auxiliary timings for the cylinder event and main_injection_timing_for_air_handling (stage A of this round "
         "named it ...InjectionQuantities - it writes the timings too)")
    s = open(fp).read()
    for address in ("0x005283d0", "0x00529640"):
        m = re.search(rf"^{address},[^\n]*$", s, re.M)
        line = m.group(0)
        new = re.sub(r"(?<![\w])schedule_crankValid\b", LIMP, line)
        new = re.sub(r"(?<![\w])schedule_crankInvalid\b", PRIMARY, new)
        s = s.replace(line, new)
    open(fp, "w").write(s)
    with open(map_path, "w") as fh:
        fh.write("address,name,old_label,kind,dims\n0x0052731c,cm848_updateCylinderCutoutAndInjectionDemand,"
                 "cm848_updateCylinderCutoutAndInjectionQuantities,function,1\n")
    print("csv: rename + 2 plates")
elif phase == "--docs":
    pr, hc = sys.argv[3], sys.argv[4]
    D = "firmware/CM848_S90140.06_analysis/docs/tpu_mios_channel_map.md"
    subword(D, "engine_injectionTiming_crankSyncDispatch", "cm848_dispatchCrankSynchronousInjection")
    edit(D, "`engine_injectionAngle_{computeLoadCh6,schedule_crankValid,schedule_crankInvalid}`",
         f"`cm848_loadInjectionStartAnglesOnTpuChannel6` / `{LIMP}` / `{PRIMARY}` (were "
         "`engine_injectionAngle_{computeLoadCh6,schedule_crankValid,schedule_crankInvalid}`)")
    subword(MEM + "cm848_cruise_drivetrain_type_fork.md", "j1939_receivePgn65265Handler",
            "cm848_receivePgn65265CruiseControlVehicleSpeedMessage")
    subword(MEM + "task022_phase3_findings.md", "j1939_handlerInitializer", "cm848_registerJ1939ReceiveHandler")
    tpu = MEM + "cm848_tpu_mios_channel_map.md"
    subword(tpu, "engine_injectionAngle_tpuChannel6EventHandler", "cm848_handleTpuChannel6InjectionEvent")
    subword(tpu, "engine_injectionAngle_tpuChannel10CylinderEventHandler", "cm848_handleTpuChannel10CylinderEvent")
    subword(tpu, "engine_injectionAngle_writeTpuEvent", "cm848_writeInjectionAngleToTpuChannel5")
    edit(tpu, "(all three `engine_injectionAngle_*` functions own it)",
         f"(all three channel 6 loaders own it: `cm848_loadInjectionStartAnglesOnTpuChannel6` / `{LIMP}` / `{PRIMARY}`)")
    T = "work/tasks/046-cm848-egr-flow-estimate.md"
    OLD = "the two SCI functions and the registrar by newly named globals"
    NEW = ("the two SCI functions by the newly named globals and the registrar by its renamed count plus the "
           "PTR_<handler>_003fd416 auto-label that embeds the renamed TP.CM dispatcher's name")
    for p in (T, pr, "/home/linux/.claude/jobs/374b0424/tmp/w15/r65/proof_r65.txt"):
        edit(p, OLD, NEW)
    edit(T, "- **Proof:** stage A 4 of 1968",
         f"- **Follow-up ({hc}), from the closing review:**\n"
         "  - `cm848_updateCylinderCutoutAndInjectionQuantities` became `cm848_updateCylinderCutoutAndInjectionDemand`.\n"
         "    It also writes the pilot / main / auxiliary timings for the cylinder event and\n"
         "    `main_injection_timing_for_air_handling`.\n"
         "  - `cm848_armTpuChannel10AtEndOfInjectionLimit` holds: both branches arm channel 10 at the end-limit angle;\n"
         "    the enable flag only picks the top nibble of `TPUA_CH10_PARAM0`.\n"
         "  - The two TPU-A handler plates cited `schedule_crankValid` / `schedule_crankInvalid`. They now name\n"
         "    `cm848_scheduleInjectionAnglesInSpeedLimpHome` / `cm848_scheduleInjectionAnglesOnPrimarySpeedInput`\n"
         "    (the rename history and the channel 10 handler's branches agree).\n"
         "  - `docs/tpu_mios_channel_map.md` and four memory notes use the current names.\n"
         "  - All 17 receive registrations, listed with comments stripped, keep their keys and handlers: 0xdd00 the\n"
         "    anti-theft request / 0xe000 Cab Message 1 / 0xea00 the request dispatcher.\n"
         "  - Commit 5e0d02e6 says the registrar differs by newly named globals. It differs by its renamed count and\n"
         "    the `PTR_..._003fd416` auto-label.\n"
         "- **Proof:** stage A 4 of 1968")
    f = MEM + "typing_focus_2026_11.md"
    note = (f"  - Round 65 (2026-11-23): the 38 unprefixed CM848-only functions (37 named) and the J1939 receive table.\n"
            "    - A constant equal to a function's address renders as that function until its parameter has a committed\n"
            "      integer type: the PGN key 0xea00 showed as cm848_runOperatingModeSpeedGovernor.\n"
            "    - A callee whose argument stays in r3 shows no argument at its calls until its prototype is committed:\n"
            "      the TP.CM sub-handlers.\n"
            "    - Read the whole body before naming. One stage A name dropped the timing writes it never read.\n")
    if "Round 65 (2026-11-23" not in open(f).read():
        open(f, "w").write(open(f).read().rstrip("\n") + "\n" + note)
    print("docs + memory + corrections")
