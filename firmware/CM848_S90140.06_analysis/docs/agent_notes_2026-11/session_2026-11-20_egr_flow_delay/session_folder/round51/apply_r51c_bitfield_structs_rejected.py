"""Round 51 stage C: the two trip information status words (e2m 8B6D +C / +E, EEPROM mirror 0x3fee64 / 0x3fee66)
become bitfield structs, one field per mask their setters use (structs always yes). Every setter and the trip reset
are in cm848_updateTripAndLifetimeCounters and cm848_flagTripInformationPowerDownDataLoss; bits nobody sets are
reserved_bit_N. Trip / lifetime scope comes from the trip reset masks (0x3fee64 & 0xffcf clears 0x0030, 0x3fee66 &
0xc3f7 clears 0x3c08), confirmed by the setters for every overflow bit; for the power-down pair (bits 3 / 9) it is the
reset mask alone - the overflow pairs sit 6 bits apart (lifetime 4-7, trip 10-13), which would make bit 3 the lifetime
one, so that pair's scope is marked inferred.
Idempotent.  usage: apply_r51c.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 51"
TRIP = "cm848_updateTripAndLifetimeCounters"
FLAG = "cm848_flagTripInformationPowerDownDataLoss"
DIST = "trip_information_distance_fault_status_t"
FAULT = "trip_information_fault_status_t"
distance = {
    1: ("lifetime_distance_vehicle_speed_sensor_fault",
        f"set with bit 4 (0x12) by {TRIP} once a vehicle speed sensor fault (fault_detected_cal.vss_signal_lost_error / "
        "vss_tampering_error) outlasts trip_information_fault_minimum_time; a trip reset keeps it"),
    2: ("lifetime_distance_overflow",
        f"set by {TRIP} when lifetime_distance_pulses_cal would overflow (it restarts at 0); a trip reset keeps it"),
    4: ("trip_distance_vehicle_speed_sensor_fault",
        "set with bit 1 (0x12) by the same check; a trip reset clears it"),
    5: ("trip_distance_overflow",
        f"set by {TRIP} when the trip distance (the dword at 0x3fee28) would overflow (it restarts at 0); a trip reset "
        "clears it"),
}
fault = {
    3: ("trip_power_down_data_lost",
        f"set with bit 9 (0x208) by {FLAG} while fault_detected_cal.power_down_data_lost_error is set; a trip reset "
        "clears it. Trip scope inferred from the reset mask alone: the overflow pairs sit 6 bits apart (lifetime 4-7 / "
        "trip 10-13) and that spacing would make this the lifetime bit"),
    4: ("lifetime_engine_run_time_overflow", f"set by {TRIP} when lifetime_engine_run_time_cal would overflow"),
    5: ("lifetime_fuel_used_overflow", f"set by {TRIP} when lifetime_fuel_used_cal would overflow"),
    6: ("lifetime_idle_fuel_used_overflow", f"set by {TRIP} when lifetime_idle_fuel_used_cal would overflow"),
    7: ("lifetime_idle_time_overflow", f"set by {TRIP} when lifetime_idle_time_cal would overflow"),
    9: ("lifetime_power_down_data_lost",
        f"set with bit 3 (0x208) by {FLAG}; a trip reset keeps it. Lifetime scope inferred from the reset mask alone "
        "(see bit 3)"),
    10: ("trip_engine_run_time_overflow", f"set by {TRIP} when trip_engine_run_time_cal would overflow; a trip reset "
         "clears it"),
    11: ("trip_fuel_used_overflow", f"set by {TRIP} when trip_fuel_used_cal would overflow; a trip reset clears it"),
    12: ("trip_idle_fuel_used_overflow", f"set by {TRIP} when trip_idle_fuel_used_cal would overflow; a trip reset "
         "clears it"),
    13: ("trip_idle_time_overflow", f"set by {TRIP} when trip_idle_time_cal would overflow; a trip reset clears it"),
}


def rows(struct, bits, record):
    lines = [f"# {struct}: e2m 8B6D {record}, one field per setter mask ({R})"]
    for b in range(16):
        name, text = bits.get(b, (f"reserved_bit_{b}", "no setter or reader in this build"))
        assert "," not in name and '"' not in text
        lines.append(f'{struct},,{name},bitfield:1@{b},{2 if b == 0 else 0},"mask 0x{1 << b:04x}: {text} ({R})",,'
                     "verified")
    return lines


sp = os.path.join(out, "structure_definitions.csv")
s = open(sp).read()
if f"\n{DIST}," not in s:
    s = s if s.endswith("\n") else s + "\n"
    s += "\n".join(rows(DIST, distance, "+C Trip_Info_Auto_Fault_Status") +
                   rows(FAULT, fault, "+E Trip_Info_Fault_Status")) + "\n"
    open(sp, "w").write(s)
gp = os.path.join(out, "global_variables.csv")
g = open(gp).read().split("\n")
idx = {l[:10]: k for k, l in enumerate(g) if l.startswith("0x")}
done = 0
for a, name, struct in (("0x003fee64", "trip_information_distance_fault_status_cal", DIST),
                        ("0x003fee66", "trip_information_fault_status_cal", FAULT)):
    p = g[idx[a]].split(",", 3)
    assert p[1] == name, (a, p[1])
    if p[2] == struct:
        continue
    assert p[2] == "word", (a, p[2])
    g[idx[a]] = f"{a},{name},{struct},Typed {struct}: one bitfield per setter mask ({R}). {p[3]}"
    done += 1
open(gp, "w").write("\n".join(g))
print(f"{done} rows retyped")
