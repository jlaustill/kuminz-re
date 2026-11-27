"""Round 96 stage H (proposal, read-only): spelled-out names for the parameters (function_definitions.csv), locals
(local_variables.csv new_name) and struct fields (structure_definitions.csv) of both firmwares whose words are
invented abbreviations. All-caps names (hardware register mnemonics from the manuals: PARAM0, RX0, CNT, FLG ...) are
kept, as are the industry abbreviations the CLAUDE.md rule allows (ID, ISR, CAN, ADC, RPM ...).
Checks: a new name must not repeat another field of the same struct / parameter or local of the same function, and
must not be a global name of that firmware (a local that shadows a global).
Writes <out.csv>: firmware,file,owner,old,new. usage: abbreviation_renames_r96.py <repo> <out.csv>"""
import collections
import csv
import os
import re
import sys

repo, out_path = os.path.abspath(sys.argv[1]), sys.argv[2]
WORDS = {"ptr": "pointer", "msg": "message", "func": "function", "idx": "index", "dest": "destination",
         "src": "source", "config": "configuration", "cfg": "configuration", "ctrl": "control", "req": "request",
         "cmd": "command", "hi": "high", "lo": "low", "len": "length", "param": "parameter", "params": "parameters",
         "diag": "diagnostic", "resp": "response", "buf": "buffer", "calc": "calculation", "init": "initialization",
         "ack": "acknowledgement", "addr": "address", "accum": "accumulator", "auth": "authentication",
         "cnt": "count", "tmp": "temporary", "val": "value", "num": "number", "prev": "previous", "cur": "current",
         "curr": "current", "seq": "sequence", "sel": "selected", "err": "error", "stat": "status"}
WHOLE = {"rx_msg": "received_message", "request_msg": "request_message", "msg_ptr": "message",
         "handler_func": "handler", "search_idx": "entry_index", "tx_cm_buf": "transmit_connection_management_buffer",
         "rx_active_flag": "receive_active_flag", "tx_active_flag": "transmit_active_flag",
         "tx_header_id": "transmit_header_id", "tx_length": "transmit_length",
         "out_cmd": "output_command", "cmd_raw": "raw_command"}
OUT = {"CM550": "firmware/CM550_J90350.00_analysis/output", "CM848": "firmware/CM848_S90140.06_analysis/output"}


def spell(name):
    if name in WHOLE:
        return WHOLE[name]
    if name.upper() == name:                                   # a register mnemonic
        return name
    parts = name.split("_")
    if any(not p.islower() and not p.isdigit() and p for p in parts):  # camelCase or mixed: leave for review
        return name
    return "_".join(WORDS.get(p, p) for p in parts)


rows = []
for fw, d in OUT.items():
    globals_ = set()
    for line in open(os.path.join(repo, d, "global_variables.csv"), newline=""):
        p = line.rstrip("\r\n").split(",", 2)
        if len(p) > 1 and p[0].startswith("0x"):
            globals_.add(p[1])
    owners = collections.defaultdict(set)
    plan = []
    for f, owner_col, col in (("function_definitions.csv", 0, 3), ("local_variables.csv", 0, 3), ("structure_definitions.csv", 0, 2)):
        for r in csv.reader(l for l in open(os.path.join(repo, d, f), newline="") if not l.startswith("#")):
            if len(r) <= col or not r[col] or r[col] in ("name", "new_name", "field_name"):
                continue
            owner = r[owner_col]
            owners[(f, owner)].add(r[col])
            new = spell(r[col])
            if new != r[col]:
                plan.append((f, owner, r[col], new))
    seen = set()
    for f, owner, old, new in plan:
        if (f, owner, old) in seen:
            continue
        seen.add((f, owner, old))
        problem = ""
        if new in owners[(f, owner)]:
            problem = "repeats a name of the same owner"
        elif f != "structure_definitions.csv" and new in globals_:
            problem = "shadows a global"
        rows.append((fw, f, owner, old, new, problem))
with open(out_path, "w", newline="") as fh:
    w = csv.writer(fh)
    w.writerow(["firmware", "file", "owner", "old", "new", "problem"])
    w.writerows(rows)
c = collections.Counter((r[0], r[1]) for r in rows)
for k, n in sorted(c.items()):
    print(k, n)
print(sum(1 for r in rows if r[5]), "with a problem")
