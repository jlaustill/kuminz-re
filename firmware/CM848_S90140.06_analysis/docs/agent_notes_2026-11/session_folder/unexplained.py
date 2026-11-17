"""Changed functions (old vs new .cpp) whose new body names none of the symbols this branch typed."""
import re
import sys

HEADER = re.compile(r"^// Function: (\S+) @ (0x[0-9a-f]+)$", re.M)

def split(path):
    parts = HEADER.split(open(path).read())
    return {parts[i + 1]: (parts[i], parts[i + 2]) for i in range(1, len(parts), 3)}

old, new = split(sys.argv[1]), split(sys.argv[2])
explain = {"lookupTableInterpolation", "cm848_dualAxisTableInterpolation", "cm848_interpolateTableWithoutCache",
           "cm848_interpolateFuelMapTable", "sensorChannelTypeB_configInit", "sensorChannelTypeB_update",
           "sensorChannelConfigInit", "updateSensorChannelWithConfig", "input_line_image", "output_line_state",
           "output_line_read_back", "cm848_refreshInputLineImage", "discrete_line_image_t", "mios_port_data_register_t"}
for line in open(sys.argv[3]):
    p = line.rstrip("\n").split(",", 3)
    if p[0].startswith("0x") and len(p) > 2 and p[1] and ("[" in p[2] or p[2] in ("mios_mdasm_t", "mios_mpwmsm_t", "mios_mpiosm_t")):
        explain.add(p[1])
pattern = re.compile(r"WORD_ARRAY_|WORD_00|mios_m|" + "|".join(re.escape(e) for e in sorted(explain, key=len, reverse=True)))
changed = [a for a in new if a in old and old[a][1] != new[a][1]]
left = [a for a in changed if not pattern.search(new[a][1]) and not pattern.search(old[a][1])]
print(f"changed: {len(changed)}  not explained by a typed symbol: {len(left)}")
for a in left:
    o, n = old[a][1].split("\n"), new[a][1].split("\n")
    import difflib
    d = [l for l in difflib.unified_diff(o, n, lineterm="", n=0) if l[:1] in "+-" and not l.startswith(("+++", "---"))]
    print(f"== {a} {new[a][0]} ({len(d)} diff lines)")
    for l in d[:8]:
        print("   ", l[:150])
