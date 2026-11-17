"""Type A sensor channels: parameters 2-5 are the lookupTableInterpolation arguments (proven by the call)."""
import sys

path = sys.argv[1]
NEW = {
    2: ("cached_axis_offset", "word *", "Cache word of the lookup (r5) - passed to lookupTableInterpolation as its cached_axis_offset (was cal_ptr_3)"),
    3: ("x_axis", "word *", "X axis (r6): byte-length word then the breakpoints - looked up with the state word at +10 (was cal_ptr_4)"),
    4: ("y_data", "word *", "Y data (r7): one value per breakpoint after a byte-length word (was ram_buffer_1)"),
    5: ("flags", "int", "lookupTableInterpolation flags (r8): bit 0 = signed axis / bit 1 = signed data / bit 3 = step lookup (was ram_buffer_2)"),
}
out, replaced = [], 0
for line in open(path).read().split("\n"):
    p = line.split(",", 5)
    if len(p) >= 5 and p[1] in ("sensorChannelConfigInit", "updateSensorChannelWithConfig") and p[2].isdigit() and int(p[2]) in NEW:
        name, typ, comment = NEW[int(p[2])]
        line = f"{p[0]},{p[1]},{p[2]},{name},{typ},{comment}"
        replaced += 1
    out.append(line)
open(path, "w").write("\n".join(out))
print("rows replaced:", replaced)
