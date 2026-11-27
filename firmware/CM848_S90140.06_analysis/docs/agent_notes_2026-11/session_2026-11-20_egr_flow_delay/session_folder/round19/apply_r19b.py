"""Round 19 stage B (types):
- SENSOR_VALUE_SOURCE: eleven e2m records share the value list '0=PRIMARY, 1=BACKUP, 2=DEFAULT' (1A11 +2 Air_Press_Source,
  1921 +4 / +12, 19BA +2, 1A2D +2, 18D9 +A, 19C2 +2, 19CA +2, 179D +8, 1A5D +2, 19D2 +2). The code stores and compares
  only 0 / 1 / 2 in each (source_values.py) and never takes an address. 0x40a1a6 (1921 +12 Altitude_Source) gets a row.
- ambient_relative_humidity_cached_axis_offsets: the 2-D cache of the humidity table at 0x3fb9f2 (was the 'dims' word
  boost_fuel_rpm_blend_table_row_count, with its second word DAT_003fb9f4): word[2].
usage: apply_r19b.py <repo>"""
import os
import sys

out = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output")
ENUM = """# SENSOR_VALUE_SOURCE: where a selected sensor value came from (PR #53 round 19) - the e2m value list
# '0=PRIMARY, 1=BACKUP, 2=DEFAULT' shared by eleven *_Source records (1A11 +2, 1921 +4 / +12, 19BA +2, 1A2D +2, 18D9 +A,
# 19C2 +2, 19CA +2, 179D +8, 1A5D +2, 19D2 +2)
SENSOR_VALUE_SOURCE,0,SENSOR_VALUE_SOURCE_PRIMARY,The primary sensor (e2m PRIMARY),2
SENSOR_VALUE_SOURCE,1,SENSOR_VALUE_SOURCE_BACKUP,The backup source (e2m BACKUP): an estimate or a second sensor,2
SENSOR_VALUE_SOURCE,2,SENSOR_VALUE_SOURCE_DEFAULT,The default value (e2m DEFAULT): the sensor has a confirmed fault,2
"""
ROWS = ["0x0040a164", "0x0040a198", "0x0040a34e", "0x0040a430", "0x0040a462", "0x0040a61e", "0x0040a68e", "0x0040a66c",
        "0x0040a7d2", "0x0040b096"]
ep = os.path.join(out, "enums.csv")
e = open(ep).read()
assert "SENSOR_VALUE_SOURCE" not in e
open(ep, "w").write(e.rstrip("\n") + "\n" + ENUM)
gp = os.path.join(out, "global_variables.csv")
lines = open(gp).read().split("\n")
index = {l[:10]: i for i, l in enumerate(lines) if l.startswith("0x")}
for a in ROWS:
    i = index[a]
    addr, name, typ, comment = (lines[i].split(",", 3) + [""])[:4]
    assert typ in ("word", "i16"), (a, typ)
    lines[i] = ",".join([addr, name, "SENSOR_VALUE_SOURCE", comment + f" | typed SENSOR_VALUE_SOURCE in PR #53 round 19 (was {typ})"])
i = index["0x003fb9f2"]
addr, name, typ, comment = (lines[i].split(",", 3) + [""])[:4]
assert name == "boost_fuel_rpm_blend_table_row_count" and typ == "word"
lines[i] = ",".join([addr, "ambient_relative_humidity_cached_axis_offsets", "word[2]",
                     "Lookup cache of the ambient humidity table (the x / y segment offsets kept by "
                     "cm848_dualAxisTableInterpolation; 2 / 2 at power-up) (was boost_fuel_rpm_blend_table_row_count word) | "
                     "earlier note: " + comment])
i = index["0x003fa702"]
addr, name, typ, comment = (lines[i].split(",", 3) + [""])[:4]
assert typ == "word", typ
lines[i] = ",".join([addr, name, "INJECTION_TIMING_INTERMEDIATE_SOURCE",
                     (comment + " | " if comment else "") + "typed INJECTION_TIMING_INTERMEDIATE_SOURCE in PR #53 round 19 (was word): "
                     "cm848_storeFuelDemandPreviousValues stores 25 (COMBUSTION_REFERENCE) into it"])
assert "0x0040a1a6" not in index
j = index["0x0040a198"]
v = 0x40a1a6
prev = max((k for k in index if int(k, 16) < v), key=lambda k: int(k, 16))
j = index[prev]
lines[j] = lines[j] + "\n" + ",".join([
    "0x0040a1a6", "barometric_altitude_source", "SENSOR_VALUE_SOURCE",
    "e2m 1921 +12 Altitude_Source 'Altitude Source: 0=PRIMARY, 1=BACKUP, 2=DEFAULT' (address from the ECU's parameter ID "
    "table): the source of barometric_altitude_feet, copied from barometric_pressure_reference_source each pass "
    "(barometric_pressure_selected_source at power-up)"])
open(gp, "w").write("\n".join(lines))
print("1 enum on 10 rows + 1 new row, 1 cache retyped")
