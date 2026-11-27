"""Round 23 stage B (types): SENSOR_VALUE_SOURCE's reach (round 19 lead). source_scan.py found ten more *_source words
whose e2m record lists 0=PRIMARY, 1=BACKUP, 2=DEFAULT (in any order) and whose code stores and compares only those
values: 1921 +8 / +C, 1A0C +2, the compressor outlet temperature, the EGR orifice / valve / engine delta pressures, the
EGR delta pressure sensor and the turbocharger speed; and egr_flow_source, whose record lists PRIMARY / BACKUP only
and whose code stores only 0. The fan and fuel metering "sources" use other value sets and stay words.
usage: apply_r23b.py <repo>"""
import os
import sys

out = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output")
ROWS = {"0x0040a19c": "ambient_air_temperature_source", "0x0040a1a0": "compressor_inlet_pressure_source",
        "0x0040a60a": "compressor_inlet_temperature_source", "0x0040a618": "compressor_outlet_temperature_source",
        "0x0040a626": "egr_orifice_delta_pressure_source", "0x0040a62a": "egr_valve_delta_pressure_source",
        "0x0040a62e": "engine_delta_pressure_source", "0x0040a65e": "egr_delta_pressure_sensor_source",
        "0x0040afd6": "turbocharger_speed_source", "0x0040a402": "egr_flow_source"}
gp = os.path.join(out, "global_variables.csv")
lines = open(gp).read().split("\n")
done = 0
for i, l in enumerate(lines):
    a = l[:10]
    if a in ROWS:
        addr, name, typ, comment = (l.split(",", 3) + [""])[:4]
        assert name == ROWS[a] and typ == "word", (a, name, typ)
        why = ("its e2m record lists 0=PRIMARY, 1=BACKUP (no DEFAULT) and the code stores only 0" if name == "egr_flow_source"
               else "its e2m record lists 0=PRIMARY, 1=BACKUP, 2=DEFAULT and the code uses only those values")
        lines[i] = ",".join([addr, name, "SENSOR_VALUE_SOURCE",
                             (comment + " | " if comment else "") + f"typed SENSOR_VALUE_SOURCE in PR #53 round 23 (was "
                             f"word): {why}"])
        done += 1
assert done == len(ROWS), done
open(gp, "w").write("\n".join(lines))
ep = os.path.join(out, "enums.csv")
e = open(ep).read()
note = ("# SENSOR_VALUE_SOURCE also types (PR #53 round 23) the ambient air temperature / compressor inlet pressure / "
        "compressor inlet and outlet temperature / EGR orifice, valve and engine delta pressure / EGR delta pressure "
        "sensor / turbocharger speed / EGR flow sources\n")
if note not in e:
    anchor = "SENSOR_VALUE_SOURCE,2,SENSOR_VALUE_SOURCE_DEFAULT,"
    k = e.index(anchor)
    end = e.index("\n", k) + 1
    e = e[:end] + note + e[end:]
    open(ep, "w").write(e)
print(done, "rows typed SENSOR_VALUE_SOURCE")
