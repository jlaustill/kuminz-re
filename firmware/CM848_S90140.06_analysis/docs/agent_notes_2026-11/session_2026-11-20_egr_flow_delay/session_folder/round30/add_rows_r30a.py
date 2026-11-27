"""Round 30 stage A: the watchdog fueling words that had no row (they rendered as DAT_ labels); widths from the
disassembly (lhz / sth). Appends address,name,label,global map rows. Idempotent.
usage: add_rows_r30a.py <repo> <map.csv>"""
import os
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
gp = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/global_variables.csv")
g = open(gp).read().split("\n")
NEW = [
    (0x40894c, "watchdog_fueling_duration_threshold",
     "e2m 8A70 +0 Watchdog_Duration_Threshold 'Gov Watchdog error set when sum of main and pilot is > this param' "
     "(0.4 us per count): cm848_monitorWatchdogFueling compares the on-time sum with it plus the coolant allowance "
     "(lhz @ 0x516d80)"),
    (0x40894e, "watchdog_fueling_error_debounce_limit",
     "e2m 8A70 +2 Watchdog_Fueling_Error_Debounce 'Consecutive occurrences of high fuel/high rpm/0 throttle allowed': "
     "fault 388 sets when watchdog_fueling_debounce_count reaches it (lhz @ 0x516da0)"),
    (0x408950, "watchdog_fueling_minimum_engine_speed",
     "e2m 8A70 +4 Watchdog_Speed_Threshold 'Watchdog fuel error may be set above this speed' (rpm x 8): the monitor "
     "resets its count at or below it (lhz @ 0x516d54)"),
    (0x3fce30, "watchdog_fueling_coolant_duration_adjustment",
     "watchdog_coolant_duration_adjustment_values at coolant_temperature_sensor_filtered: the on-time allowance added "
     "to watchdog_fueling_duration_threshold (sth @ 0x516cd4)"),
    (0x3fce32, "watchdog_coolant_duration_adjustment_cached_axis_offset",
     "The lookup cache of the watchdog coolant allowance table (cm848_initializeWatchdogFueling sets 2; sth @ 0x516e48)"),
]
rows = []
for address, name, comment in NEW:
    a = f"0x{address:08x}"
    if any(l.startswith(a + ",") for l in g):
        continue
    i = max(j for j, l in enumerate(g) if l.startswith("0x") and int(l[:10], 16) < address)
    g.insert(i + 1, f"{a},{name},word,{comment} (PR #53 round 30)")
    rows.append(f"{a},{name},DAT_{address:08x},global")
open(gp, "w").write("\n".join(g))
with open(map_path, "a") as fh:
    for r in rows:
        fh.write(r + "\n")
print(f"{len(rows)} rows added")
