"""J2 investigator run 2: result.json (full evidence, kept as result_full.json) -> result_compact.json, the size that
fits one StructuredOutput call. Rules: evidence is cut at a clause boundary and ends with ' ...' (the full text stays
in result_full.json under the same address); comments lose their dump / housekeeping sentences; seven plate comments
and six roles are rewritten by hand below."""
import json
import os
import re

here = os.path.dirname(os.path.abspath(__file__))
full = json.load(open(os.path.join(here, "result.json")))
json.dump(full, open(os.path.join(here, "result_full.json"), "w"), indent=1)


def cut(text, cap, marker=" ..."):
    if len(text) <= cap:
        return text
    head = text[:cap]
    best = max(head.rfind(". "), head.rfind("; "), head.rfind(" | "))
    if best < cap * 0.5:
        best = head.rfind(" ")
    return head[:best].rstrip(" ;|.,") + marker


def sentences(text, cap):
    """Whole sentences only, as many as fit."""
    parts = re.split(r"(?<=[.)]) (?=[A-Z0-9])", text)
    out = ""
    for p in parts:
        if out and len(out) + 1 + len(p) > cap:
            break
        out = (out + " " + p).strip()
    return out


PLATES = {
    "0x1fdc0": "Records one ended engine control period for the J1922 monitor (algorithm_enable_flags_2_cal.j1922_monitor_enable, e2m JC22MRSW): for control mode 1 (speed) / 2 (torque) / 3 (limit) it adds 1 to the total count 0x804164 (e2m 1101 JC22CU) and to the mode's count (JC22RPCU / JC22TQCU / JC22LMCU) and stores key_on_hour_meter in the mode's time and in the last control time 0x804166 (JC22TM). Callers: cm550_runJ1939PowertrainControlTimeouts when a request changes after network type 0 (J1922), and cm550_resetEngineTsc1Request on a timeout or time limit - with no network type test, so a J1939 request that ends this way is counted too. CM848 has no counterpart (was cm550_j1939MessageTypeCounter; PR #53 round 93)",
    "0x1ff38": "The 10 ms J1939 periodic transmit scheduler, second call of the odd frame task set 0x1b504. With algorithm_enable_flags_11_cal.j1939_communication_enable set it runs queue 0 (the engine node: up to 20 10-byte entries at 0x80096e) while bit 2 of the broadcast enable word 0x80aa12 is set (e2m JCEGBCEA) and queue 1 (the retarder node: up to 10 at 0x800a36) while bit 3 is set (JCRDBCEA): an entry whose next tick equals the queue's tick gets its interval added and its builder called, then the tick counts up. The counterpart of cm848_runJ1939PeriodicTransmitQueues (0x538d3c), which also tests the DM13 broadcast flags (was cm550_engineRunTimeHistogramAccumulator; PR #53 round 93)",
    "0x212b2": "J1939 receive dispatcher, first call of the even frame task set 0x1b4d8. With algorithm_enable_flags_11_cal.j1939_communication_enable set it drains the CAN receive ring (18-byte records at 0x80d72e) for at most 250 CTM4 time base counts: the PGN key is record bytes 1-2 (the PDU specific byte cleared when a PDU1 frame is for the engine's address or 0xFF - for PGN 0 also the retarder's), byte 3 goes to j1939_received_source_address, a frame whose source is in the blocking table 0x80d9e0 (e2m JCSABLTB) is dropped, otherwise the handler registered in j1939_receive_handler_table gets the record. After the ring was full it sets the receive interrupt enable of the 82527 receive message objects again. The counterpart of cm848_dispatchJ1939ReceivedMessages (0x538ef4) (was mc68k_FUN_000212b2; PR #53 round 93)",
    "0x21fac": "Opens a J1939 control session record. session_kind 0: the engine control status 0x80422a = 1 (e2m 1100 +0 JCEGCOSS), the control source 0x80422e = the engine control device 0x80da4e, and the active record 0x8041f8 (e2m 10FE JCAEEG) gets kind 0, the source address datalink_command_source_id, the device, a mode count of 1 with the engine control mode 0x80da50 as first entry, the start time key_on_hour_meter and duration 0. Any other kind does the same for the retarder (0x80422c / 0x804230 / record 0x804212 = e2m 10FF JCAERD, kind 1). Twin of CM848 0x50beec (one shared name; was cm550_diagnosticGroupSnapshotCapture; PR #53 round 93)",
    "0x22070": "J1939 monitor (algorithm_enable_flags_2_cal.j1939_monitor_enable, e2m JC39MREA), third call of the even frame task set 0x1b4d8: it records the sessions in which another device controls the engine or the retarder over J1939. It compares the engine control mode / network type / source address and the retarder control mode / source address with their values of the last pass (0x800b12-0x800b19); a control that starts on network 1 opens a session record (startJ1939ControlSession), each new mode from the same source is appended to the record's five mode words, and when the control ends or the source changes it stores the duration, clears the control status and files the record (storeJ1939ControlSessionInHistoryTable). Twin of CM848 0x50bff4 (one shared name; was cm550_memoryRegisterController; PR #53 round 93)",
    "0x231da": "Ends the engine's datalink control request (a J1939 TSC1 request or a J1922 command): it keeps the control mode in the previous-mode word 0x801982, sets the mode 0x80da50 to 0, the control device 0x80da4e to none and the speed control status 0x80da60 to 0, records the ended mode with cm550_recordJ1922ControlOccurrence and clears the request timeout 0x80da80 and the time limit timer 0x80da7e. cm550_runJ1939PowertrainControlTimeouts calls it when the request times out or reaches its time limit. CM848's function at those call sites, cm848_runTsc1LostManagement (0x26f80), adds the TSC1 lost ramps (was cm550_fuelArbitratorResetHandler; PR #53 round 93)",
    "0x23244": "Runs the datalink powertrain control timers, second call of the even frame task set 0x1b4d8: the high idle override (time limit, timeout, recovery), the progressive shift disable and out of gear flags, the retarder zero torque timer and, for vehicle speed sensor types 4 / 5, the J1939 vehicle speed timers (VSS lost = error status word 4 mask 0x100). It times the engine control request (cm550_resetEngineTsc1Request on a timeout or time limit, cm550_addEngineTsc1IgnoredRequestEntry on a time limit) and the retarder request (resetEngineRetarderTsc1Request, cm550_addRetarderTsc1IgnoredRequestEntry), J1939 and J1922 alike. A timeout counts toward the J1708 (0x804266) or J1939 (0x804268) link timeout fault; a new request asks for that fault to be cleared. The counterpart of cm848_runJ1939PowertrainControlTimeouts (0x2715c) (was cm550_fuelDemandLimitOrchestrator; PR #53 round 93)",
}
ROLES = {
    "0x1fdc0": "With the J1922 monitor enabled it records one ended engine control period of the given mode (1 speed / 2 torque / 3 limit): total count and mode count + 1, key_on_hour_meter into the mode's time and the last control time.",
    "0x212b2": "Drains the J1939 CAN receive ring within a time budget: builds each record's PGN key, drops frames from blocked source addresses, calls the receive handler registered for the key, and re-enables the 82527 receive interrupts after the ring was full.",
    "0x21fac": "Opens an engine (argument 0) or retarder (other) J1939 control session: control status 1, control source = the control device, and the active record filled with kind, source address, device, one mode, the start time and duration 0.",
    "0x22070": "J1939 monitor: each pass it compares the engine and retarder control mode / network / source address with the last pass, opens a session record when a J1939 control starts, appends each new mode, and on the end or a change of source stores the duration and files the record in the history table.",
    "0x231da": "Ends the engine's datalink control request: saves the mode in the runner's previous-mode word, sets mode, control device and speed control status to 0, records the ended mode as a J1922 control occurrence and clears the request timeout and time limit timers.",
    "0x23244": "Counts down the datalink powertrain control timers each pass and acts on their expiry: ends the high idle override and the progressive shift / out of gear flags, ends the engine and retarder control requests on a timeout or time limit, and turns timeouts into the J1708 / J1939 link timeout fault counts.",
}
OUTSIDE = " (Outside the batch list: added because it belongs to this family and its current name is wrong.)"
DROP = re.compile(r"(Power-down data in the EEPROM image[^.]*\.[^.]*\.|Dumps?: [^.]*\.|Dump 0x0004\.|The word before it[^.]*\.|Replaces the rows? [^.]*\.|Working RAM\.|ROM beyond the 256 KB dump, so no value\.|\S+ in the dump\.|\S+ = \S+ ms in the dump\.)")

import summary_notes_compact  # noqa: E402
LISTED = {"0x1fdc0", "0x1ff38", "0x212b2", "0x2142c", "0x216c6", "0x21778", "0x21872", "0x21920", "0x21f4e", "0x21fac",
          "0x22070", "0x231da", "0x23244", "0x23216", "0x21642", "0x238ac", "0x238ec"}
out = dict(batch=full["batch"], summary=summary_notes_compact.summary_compact, functions=[], skipped=full["skipped"],
           globals=[], enum_members=[], notes=summary_notes_compact.notes_compact)
for f in full["functions"]:
    f = dict(f)
    a = f["address"]
    plate = PLATES.get(a, f["plate_comment"])
    plate = re.sub(r"\s*\((one shared name; )?was [A-Za-z0-9_]+; PR #53 round 93\)$", "", plate)
    plate = plate.replace(" (one shared name)", "")
    plate = plate if plate.endswith((".", ")")) else plate + "."
    listed = a in LISTED
    f["plate_comment"] = sentences(plate, 470 if listed else 300)
    f["role"] = ROLES.get(a, f["role"])
    f["discriminator"] = sentences(f["discriminator"].replace(OUTSIDE, ""), 150)
    f["evidence"] = cut(f["evidence"], 170 if listed else 110)
    for k in ("cm848_address", "cm848_current_name"):
        if not f.get(k):
            f.pop(k, None)
    out["functions"].append(f)
from compact_comments import COMMENTS  # noqa: E402
for g in full["globals"]:
    g = dict(g)
    g["comment"] = COMMENTS[(g["firmware"], g["address"])]
    g["evidence"] = cut(g["evidence"], 55)
    out["globals"].append(g)
for e in full["enum_members"]:
    if not e["current_member"]:
        continue  # the three new enums are in result_full.json and in the notes
    e = dict(e)
    e["comment"] = re.sub(r" \(was [^)]*\)$", "", e["comment"])
    e["evidence"] = cut(e["evidence"], 90)
    out["enum_members"].append(e)
path = os.path.join(here, "result_compact.json")
json.dump(out, open(path, "w"), indent=1)
compact = json.dumps(out, separators=(",", ":"))
toks = re.findall(r"0x[0-9a-fA-F]+|[A-Za-z]+|\d+|[^\sA-Za-z\d]", compact)
est = sum(1 + (len(t) - 1) // 2 if t.startswith("0x") else max(1, (len(t) + 5) // 6) if t.isalpha()
          else max(1, (len(t) + 2) // 3) if t.isdigit() else 1 for t in toks)
print(path, len(compact), "bytes compact; crude token estimate", est)
for k in ("functions", "globals", "enum_members"):
    print(" ", k, len(json.dumps(out[k], separators=(",", ":"))))
