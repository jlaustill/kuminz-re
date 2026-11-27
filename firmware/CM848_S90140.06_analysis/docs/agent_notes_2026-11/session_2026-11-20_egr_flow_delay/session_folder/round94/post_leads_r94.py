"""Round 94 stage E hand fixes after the leads apply (each old text must occur exactly once in its file; idempotent):
- the comment refresh replaced e2m mnemonic DCMNLDTB (the old row name at 0x807d32 was the mnemonic itself) inside
  two e2m citations: the CM848 row's quoted Calterm text and a CM550 comment next to DCMNESTB;
- CM848 docs / tool comments name the hour meter loader by its twin name loadHourMetersFromEeprom;
- both firmwares' HIGH_RPM_PROTECTION_STATE / HIGH_RPM_PROTECTION_FLAGS enums are removed (L1's judge: no global,
  struct field, local, definition or .cpp line uses a member; the FLAGS masks are the J1587 PID 71 idle shutdown
  timer status byte CM550 builds in a register at 0xefa2, and STATE is superseded by IDLE_SHUTDOWN_STATE);
- CM550 0x2efd0 is the PGN 61442 receive handler (L2's judge: registered for 0xf002 at 0x2f114; CM848's counterpart
  cm848_j1939ProcessPgn61442Etc1): cm550_receivePgn61442ElectronicTransmissionController1Message.
usage: post_leads_r94.py <repo>"""
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
R = "PR #53 round 94"
done = []


def read(rel):
    return open(os.path.join(repo, rel), newline="").read()


def write(rel, text):
    open(os.path.join(repo, rel), "w", newline="").write(text)


def edit(rel, pairs):
    text = read(rel)
    for old, new in pairs:
        if new in text and old not in text:
            continue
        assert text.count(old) == 1, (rel, old[:60], text.count(old))
        text = text.replace(old, new)
    write(rel, text)
    done.append(rel)


C5 = "firmware/CM550_J90350.00_analysis/output"
C8 = "firmware/CM848_S90140.06_analysis/output"
edit(f"{C8}/global_variables.csv", [("'[duty_cycle_monitor_load_axis] Duty Cycle Mon Y-Axis", "'[DCMNLDTB] Duty Cycle Mon Y-Axis")])
edit(f"{C5}/function_renames.csv", [("(6 - load bin of duty_cycle_monitor_load_axis) x 8", "(6 - load bin of DCMNLDTB) x 8")])
edit("firmware/CM848_S90140.06_analysis/docs/engine_hours_and_odometer.md",
     [("Both are loaded at start (`cm848_loadHourMetersFromEeprom`)", "Both are loaded at start (`loadHourMetersFromEeprom`)")])
edit("firmware/CM848_S90140.06_analysis/tools/read_engine_hours.sh",
     [("Both are loaded at start (cm848_loadHourMetersFromEeprom)", "Both are loaded at start (loadHourMetersFromEeprom)")])
# the two enums, with the comment lines right above their rows and one blank separator
for rel in (f"{C5}/enums.csv", f"{C8}/enums.csv"):
    text = read(rel)
    E = "\r\n" if "\r\n" in text else "\n"
    lines = text.split(E)
    out, i, removed = [], 0, 0
    while i < len(lines):
        if lines[i].startswith(("HIGH_RPM_PROTECTION_STATE,", "HIGH_RPM_PROTECTION_FLAGS,")):
            while out and out[-1].startswith("#") and ("HIGH_RPM_PROTECTION" in out[-1] or "high rpm" in out[-1].lower()):
                out.pop()
                removed += 1
            while i < len(lines) and lines[i].startswith(("HIGH_RPM_PROTECTION_STATE,", "HIGH_RPM_PROTECTION_FLAGS,")):
                i += 1
                removed += 1
            if out and out[-1] == "" and i < len(lines) and lines[i] == "":
                i += 1
            continue
        out.append(lines[i])
        i += 1
    assert not any(l.startswith(("HIGH_RPM_PROTECTION_STATE,", "HIGH_RPM_PROTECTION_FLAGS,")) for l in out)
    if removed:
        write(rel, E.join(out))
        done.append(f"{rel}: {removed} lines removed")
# INSITE_PARAM_CODE 0x47 = 71: the J1587 PID 71 Idle Shutdown Timer Status byte (L1's judge), not a high rpm status
for rel in (f"{C5}/enums.csv", f"{C8}/enums.csv"):
    edit(rel, [("INSITE_PARAM_CODE,0x47,HIGH_RPM_PROTECTION_STATUS,High RPM protection status flags,1",
                "INSITE_PARAM_CODE,0x47,IDLE_SHUTDOWN_TIMER_STATUS,J1587 PID 71 Idle Shutdown Timer Status: the response byte "
                "(CM550 builds it at 0xefa2-0xf004: 0x80 timer active / 0x08 function enabled / 0x04 override active / 0x02 "
                f"engine shut down by the idle timer / 0x01 driver alert); was HIGH_RPM_PROTECTION_STATUS ({R}),1")])
# the ETC1 receive handler
F = f"{C5}/function_renames.csv"
text = read(F)
new = "cm550_receivePgn61442ElectronicTransmissionController1Message"
if new not in text:
    m = re.search(r"^0x0002efd0,([^,\r\n]*)(?:,([^\r\n]*))?", text, re.M)
    assert m, "0x2efd0 row"
    old = m.group(1)
    plate = m.group(2) or ""
    note = (f"The PGN 61442 (ETC1) receive handler: registered for 0xf002 at 0x2f114 (L2's judge, {R}); CM848's counterpart is "
            f"cm848_j1939ProcessPgn61442Etc1")
    text = text[:m.start()] + f"0x0002efd0,{new},{note}" + (f" | {plate}" if plate else "") + f" (was {old}; {R})" + text[m.end():]
    write(F, text)
    done.append(f"{F}: 0x2efd0 {old} -> {new}")
    for k in ("function_definitions.csv", "local_variables.csv"):
        t = read(f"{C5}/{k}")
        t2 = re.sub(rf"^(0x0002efd0,){re.escape(old)},", lambda x: x.group(1) + new + ",", t, flags=re.M)
        if t2 != t:
            write(f"{C5}/{k}", t2)
            done.append(f"{C5}/{k}: 0x2efd0 follows")
    open("/home/linux/.claude/jobs/374b0424/tmp/w15/r94/map_r94e_hand_cm550.csv", "w").write(
        f"address,name,old_label,kind,dims\n0x0002efd0,{new},{old},symbol,1\n")
print("\n".join(done))
