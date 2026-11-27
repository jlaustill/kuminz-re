"""Scratch helper: two wording fixes in gen_output.py (scratch file only)."""
p = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/scratch/N2/investigator/gen_output.py"
s = open(p).read()
rep = [
    ('"vp44_liftPumpFuelDeliveryController (0x34cc4) itself, on every call (x_axis_offset 2 each time)"',
     '"vp44_liftPumpFuelDeliveryController (0x34cc4), before every lookup,"'),
    ('"vp44_liftPumpFuelDeliveryController (0x34cc4) itself, on every call"',
     '"vp44_liftPumpFuelDeliveryController (0x34cc4), before every lookup,"'),
    ('"Seven callers: cm550_FUN_00026b3a', '"Four callers, eight calls: cm550_FUN_00026b3a'),
]
for old, new in rep:
    if old not in s:
        raise SystemExit("missing: " + old[:80])
    s = s.replace(old, new)
open(p, "w").write(s)
print("patched")
