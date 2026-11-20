"""Compare globals4 results with the other W14 result files: name collisions, address overlaps, family views."""
import glob
import json
import re

S = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/"
mine = [json.loads(l) for l in open(S + "result_W14_globals4.jsonl")]
mynew = {r["new"]: r for r in mine if r.get("verdict") == "confirmed"}
others = {}
for p in sorted(glob.glob(S + "result_W14_*.jsonl")):
    if p.endswith("globals4.jsonl"):
        continue
    rows = []
    for line in open(p):
        line = line.strip()
        if line:
            try:
                rows.append(json.loads(line))
            except ValueError:
                print("bad json line in", p)
    others[p.split("result_W14_")[1]] = rows
    print(p.split("/")[-1], len(rows))
for f, rows in others.items():
    for r in rows:
        nw = r.get("new")
        if nw and nw in mynew and r.get("verdict") == "confirmed":
            print("COLLISION", f, r.get("address"), r.get("old"), "->", nw, "| mine at", mynew[nw]["address"])
mine_addr = {r["address"]: r for r in mine}
for f, rows in others.items():
    for r in rows:
        if r.get("address") in mine_addr and r.get("kind") == "global":
            print("OVERLAP address", f, r.get("address"), r.get("verdict"), r.get("new"))
pat = re.compile(r"coolant_temperature_sensor_performance|cssc|droop|all_speed_governor|drivetrain_ratio|charge_pressure|_source\b|"
                 r"data_collector|j1939_torque_curve|j1939_determined|sensor_channel\d+|channel\d+|governor_pressure|pre_start|"
                 r"egr_.*delta|thermostat")
for f, rows in others.items():
    for r in rows:
        nw = r.get("new") or ""
        if r.get("kind") == "global" and r.get("verdict") == "confirmed" and pat.search(nw):
            print("FAMILY", f, r["address"], r["old"], "->", nw)
