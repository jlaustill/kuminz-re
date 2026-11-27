"""Round 97 stage C (plan, read-only): spelled-out function names, both firmwares. Words (camelCase parts after the
prefix) that are abbreviations are expanded; 'init' as the first word becomes the verb 'initialize', as the last word
it moves to the front ('<x>Init' -> 'initialize<X>'), elsewhere it becomes 'Initialization'. Functions that the
round 97 workflow's batches name are left out (their addresses appear in the workflow script). A name used by both
firmwares (an unprefixed twin) is renamed in both. Writes <out.csv>: firmware,address,old,new and prints clashes.
usage: function_spelling_plan_r97.py <repo> <workflow.js> <out.csv>"""
import collections
import csv
import os
import re
import sys

repo, wf, out = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]
WORDS = {"diag": "diagnostic", "tx": "transmit", "rx": "receive", "temp": "temperature", "params": "parameters",
         "param": "parameter", "calc": "calculation", "ack": "acknowledgement", "msg": "message", "cfg": "configuration",
         "config": "configuration", "ctrl": "control", "buf": "buffer", "idx": "index", "cnt": "count", "addr": "address",
         "req": "request", "resp": "response", "cmd": "command", "err": "error", "util": "utility", "mgr": "manager",
         "proc": "process", "accum": "accumulator", "info": "information", "seq": "sequence", "aux": "auxiliary",
         "eps": "enginePositionSensor"}
SPECIAL = {"cm848_diagSendResponseCode": "cm848_sendDiagnosticResponseCode",
           "cm550_emptyPlaceholderInit": "cm550_emptyPlaceholderInitialization",
           "cm848_continuePciControllerInit": "cm848_continuePciControllerInitialization",
           "cm848_sciInitDefaultCallback": "cm848_initializeSciDefaultCallback",
           "cm848_sciInitCommandCallback": "cm848_initializeSciCommandCallback",
           "cm848_sciInitPort1": "cm848_initializeSciPort1"}
KEEP = {"buildPgn65228Dm3ClearInitMessage"}            # no plate says what its Init is
OUT = {"CM550": "firmware/CM550_J90350.00_analysis/output", "CM848": "firmware/CM848_S90140.06_analysis/output"}
PREFIXES = ("cm550_", "cm848_", "mpc555_", "mc68k_", "vp44_", "hpcr_")
excluded = {int(a, 16) for a in re.findall(r"\b0x([0-9a-f]{4,6})\b", open(wf).read())}


def split_camel(s):
    return re.findall(r"[A-Z]?[a-z]+|[A-Z]+(?![a-z])|\d+", s)


def spell(name):
    if name in SPECIAL:
        return SPECIAL[name]
    prefix = next((p for p in PREFIXES if name.startswith(p)), "")
    body = name[len(prefix):]
    if "_" in body or name in KEEP or name.startswith("hpcr_cbd") or re.search(r"[0-9][a-z]", body):
        return name                                    # snake_case / kept / the R7 batch / number-letter parts
    words = split_camel(body)
    if not words:
        return name
    low = [w.lower() for w in words]
    if "init" in low:
        k = low.index("init")
        if k == 0:
            words[0] = "initialize"
        elif k == len(words) - 1:
            words = ["initialize"] + words[:-1]
        else:
            words[k] = "Initialization"
    words = [WORDS.get(w.lower(), w) if w.lower() in WORDS else w for w in words]
    new = words[0][0].lower() + words[0][1:] + "".join(w[0].upper() + w[1:] for w in words[1:])
    return prefix + new


names = {}
for fw, d in OUT.items():
    for line in open(os.path.join(repo, d, "function_renames.csv"), newline=""):
        p = line.rstrip("\r\n").split(",", 2)
        if len(p) > 1 and p[0].startswith("0x"):
            names[(fw, int(p[0], 16))] = p[1]
by_name = collections.defaultdict(list)
for k, n in names.items():
    by_name[n].append(k)
rows = []
for (fw, a), n in sorted(names.items()):
    if a in excluded:
        continue
    new = spell(n)
    if new != n and new.lower() != n.lower():          # case-only changes are not spellings
        rows.append((fw, f"0x{a:08x}", n, new))
newnames = collections.Counter((fw, new) for fw, a, n, new in rows)
for (fw, new), c in newnames.items():
    if c > 1:
        print("CLASH (two old names -> one)", fw, new)
for fw, a, n, new in rows:
    if any(k[0] == fw for k in by_name.get(new, [])):
        print("CLASH (exists)", fw, n, "->", new)
shared = [n for n, ks in by_name.items() if len({k[0] for k in ks}) > 1]
for fw, a, n, new in rows:
    if n in shared:
        print("TWIN NAME (both rows change):", n, "->", new)
with open(out, "w", newline="") as f:
    w = csv.writer(f)
    w.writerow(["firmware", "address", "old", "new"])
    w.writerows(rows)
print(collections.Counter(r[0] for r in rows))
