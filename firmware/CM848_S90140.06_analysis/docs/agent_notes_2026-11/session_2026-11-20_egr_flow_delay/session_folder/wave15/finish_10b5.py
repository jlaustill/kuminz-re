"""Finish 10b-5 after apply_hand_worklist.py stopped at the function step (the repo gate refused the
cm848_sensorChannelNN_* wrapper names: an extra underscore and 'Init'). The four booster capacitor wrappers are named
by when they run: cm848_initProtectionParameter1/2 run from cm848_periodicTaskSet_outputs (the update) and
cm848_processProtectionParameter1/2 once from cm848_applicationMain (the initialize) - the repo's known inversion of
the sensor channel _init / _process suffixes. Then the functions go through apply_renames.py --apply and the map
rows of the 10b-5 globals (old names from their "(was ...)") and functions are appended.
usage: finish_10b5.py <w15 dir> <repo>"""
import json
import os
import re
import runpy
import subprocess
import sys

here, repo = sys.argv[1], os.path.abspath(sys.argv[2])
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
gate = os.path.join(here, "map_stage10c.csv.functions.jsonl")
NEW = {
    "0x000429a0": ("cm848_updateInjectorDriverBoosterCapacitor1VoltageChannel",
                   "Sensor channel 54 wrapper run every pass from cm848_periodicTaskSet_outputs: the injector driver booster "
                   "capacitor 1 voltage (faults 328 / 329; P2146)"),
    "0x00042a2c": ("cm848_initializeInjectorDriverBoosterCapacitor1VoltageChannel",
                   "Sensor channel 54 wrapper run once at boot from cm848_applicationMain: the booster capacitor 1 voltage"),
    "0x00042ab8": ("cm848_updateInjectorDriverBoosterCapacitor2VoltageChannel",
                   "Sensor channel 55 wrapper run every pass from cm848_periodicTaskSet_outputs: the injector driver booster "
                   "capacitor 2 voltage (faults 330 / 331; P2149)"),
    "0x00042b44": ("cm848_initializeInjectorDriverBoosterCapacitor2VoltageChannel",
                   "Sensor channel 55 wrapper run once at boot from cm848_applicationMain: the booster capacitor 2 voltage"),
}
rows = []
for line in open(gate):
    r = json.loads(line)
    if r["address"] in NEW:
        r["new"], plate = NEW[r["address"]]
        r["plate_comment"] = f"{plate} (was {r['old']})"
    rows.append(r)
open(gate, "w").write("".join(json.dumps(r) + "\n" for r in rows))
done = subprocess.run([sys.executable, os.path.join(repo, "firmware", "scripts", "rename_waves", "apply_renames.py"), out,
                       gate, "--apply"], capture_output=True, text=True)
print(done.stdout.strip()[-300:])
assert done.returncode == 0 and "PROBLEM" not in done.stdout, done.stdout[-800:]
work = runpy.run_path(os.path.join(here, "worklist_10b_more.py"))
comments = {}
for line in open(os.path.join(out, "global_variables.csv"), errors="replace"):
    if line.startswith("0x"):
        a, name, typ, comment = (line.rstrip("\n").split(",", 3) + [""])[:4]
        comments[a] = (name, comment)
with open(os.path.join(here, "map_stage10c.csv"), "a") as f:
    for address, new, role in work["GLOBALS"]:
        address = f"0x{int(address, 16):08x}"
        name, comment = comments[address]
        assert name == new, (address, name, new)
        old = re.search(r"\(was ([A-Za-z0-9_]+)\)", comment).group(1)
        f.write(f"{address},{new},{old},global\n")
    for r in rows:
        f.write(f"{r['address']},{r['new']},{r['old']},function\n")
print(f"map: {len(work['GLOBALS'])} globals and {len(rows)} functions appended")
