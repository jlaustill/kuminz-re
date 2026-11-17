"""Print the old names the sensor follow-up renames or drops (one per line)."""
import contextlib
import io
import runpy
import sys

sys.argv = ["sensor_followup.py", sys.argv[1], "/dev/null"]
buf = io.StringIO()
with contextlib.redirect_stdout(buf):
    ns = runpy.run_path("/home/linux/.claude/jobs/d55ae3c6/tmp/sensor_followup.py", run_name="plan")
st = ns["state"]
for a, new in {**ns["renames"], **ns["out_renames"]}.items():
    old = st.rows.get(a, ("",))[0]
    if old:
        print(f"{old},{new}")
for v in ns["drop"].values():
    print(f"{v},(field)")
