"""Round 97 stage B (plan, read-only): spelled-out enum type and member names for both firmwares. Every '_'-separated
word in WORDS is expanded; an enum excluded below keeps its names. Writes <out.csv>: firmware,kind,enum,old,new and
prints the table plus clashes (a new member name that another member of the firmware already uses, or two old names
that map to one). usage: enum_spelling_plan_r97.py <repo> <out.csv>"""
import collections
import csv
import os
import sys

repo, out = os.path.abspath(sys.argv[1]), sys.argv[2]
WORDS = {"DIAG": "DIAGNOSTIC", "SVC": "SERVICE", "SUBFUNC": "SUBFUNCTION", "CMD": "COMMAND", "PARAM": "PARAMETER",
         "PARAMS": "PARAMETERS", "MSG": "MESSAGE", "INIT": "INITIALIZATION", "ADDR": "ADDRESS", "RESP": "RESPONSE",
         "MEM": "MEMORY", "OP": "OPERATION", "SRC": "SOURCE", "CALC": "CALCULATION", "EXT": "EXTENDED",
         "INFO": "INFORMATION", "LEN": "LENGTH", "CTRL": "CONTROL", "LIM": "LIMIT", "MAX": "MAXIMUM", "MIN": "MINIMUM",
         "CONFIG": "CONFIGURATION", "CFG": "CONFIGURATION", "REQ": "REQUEST", "STAT": "STATUS", "ERR": "ERROR",
         "SEQ": "SEQUENCE", "BUF": "BUFFER", "IDX": "INDEX", "CNT": "COUNT", "VAL": "VALUE", "NUM": "NUMBER",
         "HDR": "HEADER", "PTR": "POINTER", "DST": "DESTINATION", "DEST": "DESTINATION", "TX": "TRANSMIT",
         "RX": "RECEIVE", "XFER": "TRANSFER", "PROT": "PROTECTION", "THR": "THRESHOLD", "SPD": "SPEED",
         "TRQ": "TORQUE", "ENG": "ENGINE", "VEH": "VEHICLE", "PWR": "POWER", "BRK": "BRAKE", "ACCEL": "ACCELERATION",
         "DECEL": "DECELERATION", "REGS": "REGISTERS", "HI": "HIGH", "LO": "LOW", "EPS": "ENGINE_POSITION_SENSOR",
         "ASG": "ALL_SPEED_GOVERNOR", "LSG": "LOW_SPEED_GOVERNOR", "HSG": "HIGH_SPEED_GOVERNOR",
         "RSG": "ROAD_SPEED_GOVERNOR", "ANC": "ACCELERATION_NOISE_CONTROL", "VSG": "VARIABLE_SPEED_GOVERNOR",
         "PKT": "PACKET", "MULTI": "MULTIPLE", "TEMP": "TEMPERATURE", "PROP": "PROPRIETARY",
         "PTO": "POWER_TAKE_OFF", "AUX": "AUXILIARY", "COMM": "COMMUNICATION", "MON": "MONITOR",
         "ALT": "ALTERNATE", "SYS": "SYSTEM", "PERF": "PERFORMANCE", "STATS": "STATISTICS",
         "COEFF": "COEFFICIENT", "TRANS": "TRANSMISSION"}
SPECIAL = {"SPN_91_ACCEL_PEDAL": "SPN_91_ACCELERATOR_PEDAL",                    # SPN 91 is the accelerator pedal position
           "MULTI_PKT_RX": "DIAGNOSTIC_SERVICE_5_MULTIPLE_PACKET_RECEIVE",       # DIAG_MEMORY_OP holds the same codes
           "MULTI_PKT_TX": "DIAGNOSTIC_SERVICE_5_MULTIPLE_PACKET_TRANSMIT",
           "VP44_COMM_IDLE": "VP44_COMMUNICATION_STATE_IDLE"}            # VP44_COMM_MODE has VP44_COMMUNICATION_IDLE
EXCLUDE = {"J1939_DIAGNOSTIC_SERVICE"}          # the round 97 workflow's batch R7 judges its members
OUT = {"CM550": "firmware/CM550_J90350.00_analysis/output", "CM848": "firmware/CM848_S90140.06_analysis/output"}


def spell(name):
    return SPECIAL.get(name) or "_".join(WORDS.get(w, w) for w in name.split("_"))


rows = []
for fw, d in OUT.items():
    entries = []
    for r in csv.reader(l for l in open(os.path.join(repo, d, "enums.csv"), newline="") if not l.startswith("#")):
        if len(r) > 2 and r[0] and r[0] != "enum_name":
            entries.append(r)
    members = {r[2] for r in entries}
    types = {r[0] for r in entries}
    new_members = collections.defaultdict(list)
    for t in sorted(types - EXCLUDE):
        nt = spell(t)
        if nt != t:
            rows.append((fw, "type", t, t, nt))
    for r in entries:
        if r[0] in EXCLUDE:
            continue
        nm = spell(r[2])
        new_members[nm].append(r[2])
        if nm != r[2]:
            rows.append((fw, "member", r[0], r[2], nm))
    for nm, olds in new_members.items():
        if len(set(olds)) > 1:
            print(f"CLASH {fw}: {sorted(set(olds))} -> {nm}")
        elif nm != olds[0] and nm in members:
            print(f"CLASH {fw}: {olds[0]} -> {nm}, which exists already")
with open(out, "w", newline="") as f:
    w = csv.writer(f)
    w.writerow(["firmware", "kind", "enum", "old", "new"])
    w.writerows(rows)
c = collections.Counter((r[0], r[1]) for r in rows)
print(dict(c))
