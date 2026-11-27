"""Read-only: compare the new names of bin 5 with the new names the other bins have written so far.
usage: crosscheck.py"""
import glob
import json

RES = "/home/linux/.claude/jobs/374b0424/tmp/w15/results/"
mine = {}
for line in open(RES + "result_W15_bin5.jsonl"):
    e = json.loads(line)
    if e["verdict"] == "confirmed":
        mine[e["new"]] = e["address"]
others = {}
for path in sorted(glob.glob(RES + "result_W15_bin[1-46].jsonl")) + sorted(glob.glob(RES + "result_W15_bin3.jsonl")):
    for line in open(path, errors="replace"):
        line = line.strip()
        if not line.startswith("{"):
            continue
        try:
            e = json.loads(line)
        except ValueError:
            continue
        if e.get("verdict") == "confirmed" and e.get("new"):
            others.setdefault(e["new"], []).append((path.split("_")[-1], e["address"]))
print("collisions:", [(n, mine[n], others[n]) for n in mine if n in others])
families = ("low_speed_governor", "wastegate_duty", "j1939_anti_theft", "tsc1_lost", "intake_air_heater_crank",
            "cruise_road_speed", "electronic_smart_power", "programmable_power", "user_override_alpha", "trip_distance",
            "vehicle_speed_limit_fueling", "compressor_outlet_temperature_default", "auxiliary_driver", "cruise_driver")
for name in sorted(others):
    if name.startswith(families):
        print("other bin, same family:", name, others[name])
print("other bins so far:", len(others), "new names")
