"""Give sensorChannelTypeB_configInit / _update their real lookup parameters (todo 039)."""
import sys

path = sys.argv[1]
NEW = {
    2: ("cached_axis_offset", "word *",
        "Cache word of the lookup (r5): the byte offset (2 x index) of the axis segment found last time - the update resets it to 2 - passed to lookupTableInterpolation as its cached_axis_offset (was table_interp_args_t *)"),
    3: ("x_axis", "word *",
        "X axis (r6): first word = byte length of the breakpoints - looked up with state_ptr[5] (was table_ptr - not unused)"),
    4: ("y_data", "word *",
        "Y data (r7): one value per breakpoint after a byte-length word (was axes_ptr - not unused)"),
    5: ("flags", "int",
        "lookupTableInterpolation flags (r8): bit 0 = signed axis / bit 1 = signed data / bit 3 = step lookup - 0 in the calls (was mode_flag)"),
}
out, replaced = [], 0
for line in open(path).read().split("\n"):
    parts = line.split(",", 5)
    if len(parts) >= 5 and parts[1] in ("sensorChannelTypeB_configInit", "sensorChannelTypeB_update") and parts[2].isdigit() and int(parts[2]) in NEW:
        name, typ, comment = NEW[int(parts[2])]
        line = f"{parts[0]},{parts[1]},{parts[2]},{name},{typ},{comment}"
        replaced += 1
    out.append(line)
open(path, "w").write("\n".join(out))
print("rows replaced:", replaced)
