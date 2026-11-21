"""Stage 2b: the signed EGR flow limits and the locals of cm848_calculateDelayedEgrFlowAndFraction.
Usage: apply_stage2b.py <firmware output dir>
- egr_mass_flow_estimate_maximum / _minimum (0x4002e4 / 0x4002e6): word -> i16 (lha x2 in
  cm848_calculateEgrMassFlowBeforeDelay @ 0x12800 / 0x1284c and 0x127e0 / 0x1282c; e2m 177E +2 / +4 'S').
- local_variables.csv: the five temporaries, auto-names read from the stage 2 build."""
import os
import sys

out = sys.argv[1]
path = os.path.join(out, "global_variables.csv")
lines = open(path).read().split("\n")
done = 0
for i, line in enumerate(lines):
    p = line.split(",", 3)
    if p[0] in ("0x004002e4", "0x004002e6"):
        assert p[2] == "word", p
        p[2] = "i16"
        lines[i] = ",".join(p)
        done += 1
assert done == 2
open(path, "w").write("\n".join(lines))

F = "0x000128a0,cm848_calculateDelayedEgrFlowAndFraction"
LOCALS = [
    f"{F},uVar1,delay_volume_term,uint,oxygen_flow_delay_volume_fraction x 120 >> 10 (0xffff above 1.0): with x 1000 / "
    "(volumetric efficiency x speed) it gives the oxygen delay in ms",
    f"{F},dVar2,filtered_oxygen_fraction,uint,exponentialMovingAverage output - stored as egr_oxygen_fraction",
    f"{F},wVar3,delayed_oxygen_fraction,word,The residual oxygen fraction from oxygen_flow_delay_milliseconds / 10 "
    "passes back (cm848_delayUnsignedSample)",
    f"{F},sVar4,delayed_egr_mass_flow,sword,The EGR mass flow before delay from egr_flow_delay_milliseconds / 10 passes "
    "back (cm848_delaySignedSample)",
    f"{F},uVar5,scratch,uint,One register reused: volumetric efficiency x speed then the oxygen delay then the EGR "
    "delay then the EGR fraction",
]
path = os.path.join(out, "local_variables.csv")
lines = open(path).read().split("\n")
assert not any(l.startswith("0x000128a0,") for l in lines)
for i, l in enumerate(lines):
    if l.startswith("0x") and int(l.split(",", 1)[0], 16) > 0x128a0:
        lines[i:i] = LOCALS
        break
else:
    while lines and lines[-1] == "":
        lines.pop()
    lines += LOCALS + [""]
open(path, "w").write("\n".join(lines))
print(f"retyped {done}, locals {len(LOCALS)}")
