"""Round 5 stage c: 0x3fdda6 is e2m 117F +3A RSC_Sensor_Type [VSRSSNTY] '0=none, 1=inductive, 2=minigen, 3=tach,
4=dlw/GR&OOG, 5=dlw/o GR&OOG' - the vehicle (road) speed sensor type, not a drivetrain type. The code agrees: 0 sends
no CCVS1 speed and lets the HSG compensator run; 3 (tachograph) changes how the TPU-B channel 2 speed sensor is set up
and read; 4 (J1939 with gear ratio and out-of-gear) takes the vehicle speed from the output shaft and uses the ETC2
gear ratio; 5 (J1939 without) uses ETC1 only. The truck's EEPROM holds 1 (inductive). It sits in the EEPROM mirror,
so _cal. The DRIVETRAIN_TYPE enum names were a transmission-kind reading of the same values.
usage: apply_r5c_vehicle_speed_sensor_type.py <repo> <map.csv>"""
import os
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
E = "VEHICLE_SPEED_SENSOR_TYPE"
MEMBERS = [  # value, new, old, comment
    (0, "VEHICLE_SPEED_SENSOR_NONE", "DRIVETRAIN_STANDALONE",
     "e2m VSRSSNTY 0 = none: no vehicle speed sensor (the CCVS1 builder sends no speed; the HSG compensator runs)"),
    (1, "VEHICLE_SPEED_SENSOR_INDUCTIVE", "DRIVETRAIN_MANUAL_VSS",
     "1 = inductive (the magnetic vehicle speed sensor on TPU-B channel 2; this truck's EEPROM holds 1)"),
    (2, "VEHICLE_SPEED_SENSOR_MINIGEN", None, "2 = minigen (a mini generator speed sensor); no code compares with it"),
    (3, "VEHICLE_SPEED_SENSOR_TACHOGRAPH", "DRIVETRAIN_MANUAL_TPU",
     "3 = tach: the speed comes from a tachograph signal; cm848_initVehicleSpeedSensorChannel and the sensor "
     "interrupt handle the TPU-B channel 2 input differently"),
    (4, "VEHICLE_SPEED_SENSOR_J1939_WITH_GEAR_RATIO", "DRIVETRAIN_AUTO_J1939_FULL",
     "4 = dlw/GR&OOG: data link with gear ratio and out-of-gear - the vehicle speed from the J1939 ETC1 output shaft "
     "speed (cm848_calculateVehicleSpeedFromOutputShaft) and the ETC2 gear ratio"),
    (5, "VEHICLE_SPEED_SENSOR_J1939_WITHOUT_GEAR_RATIO", "DRIVETRAIN_AUTO_J1939_ETC1",
     "5 = dlw/o GR&OOG: data link without gear ratio and out-of-gear - ETC1 only"),
]
path = os.path.join(out, "enums.csv")
lines = open(path, newline="").read().split("\n")
old_rows = [i for i, l in enumerate(lines) if l.startswith("DRIVETRAIN_TYPE,")]
assert len(old_rows) == 5, old_rows
size = lines[old_rows[0]].rsplit(",", 1)[1]
first = old_rows[0]
for i in sorted(old_rows, reverse=True):
    del lines[i]
new_rows = [f"{E},{v},{new},{c}" + (f" (was {old})" if old else "") + f",{size}" for v, new, old, c in MEMBERS]
lines[first:first] = new_rows
open(path, "w", newline="").write("\n".join(lines))
path = os.path.join(out, "global_variables.csv")
lines = open(path, newline="").read().split("\n")
i = [k for k, l in enumerate(lines) if l.startswith("0x003fdda6,")][0]
a, name, typ, comment = (lines[i].split(",", 3) + [""])[:4]
assert name == "drivetrain_type" and typ == "DRIVETRAIN_TYPE", (name, typ)
lines[i] = ",".join([a, "vehicle_speed_sensor_type_cal", E,
                     "e2m 117F +3A RSC_Sensor_Type '[VSRSSNTY] 0=none 1=inductive 2=minigen 3=tach 4=dlw/GR&OOG "
                     "5=dlw/o GR&OOG' (EEPROM mirror; 1 = inductive in this truck's EEPROM): the vehicle speed sensor "
                     "type - which source the vehicle speed comes from (none / the TPU-B channel 2 sensor as an "
                     "inductive / minigen / tachograph signal / the J1939 transmission with or without the gear ratio); "
                     f"typed {E} (round 5) (was drivetrain_type) | earlier note: {comment}"])
open(path, "w", newline="").write("\n".join(lines))
with open(map_path, "w") as f:
    f.write("address,name,old_label,kind\n")
    f.write("0x003fdda6,vehicle_speed_sensor_type_cal,drivetrain_type,global\n")
    f.write(f",{E},DRIVETRAIN_TYPE,enum\n")
    for v, new, old, c in MEMBERS:
        if old:
            f.write(f",{new},{old},enum\n")
print("enum renamed; global renamed; map written")
