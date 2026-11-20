import sys

sys.path.insert(0, "/tmp/w14_globals2")
import spec_data_a as a  # noqa: E402
import spec_data_b as b  # noqa: E402

with open("/tmp/w14_globals2/spec_names.txt", "w") as f:
    for s in a.A + b.B:
        if "new" in s:
            f.write(f"{s['addr']} {s['new']}\n")
print("written")
