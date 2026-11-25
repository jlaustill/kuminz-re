"""One-off exact replacements in build_result.py (each must match exactly once)."""
p = "/home/linux/.claude/jobs/374b0424/tmp/w15/r92/scratch/W2/build_result.py"
s = open(p).read()
pairs = [
    ("because two pairs of \"\n                                  \"overlapping function entries share code)",
     "because three pairs of \"\n                                  \"overlapping function entries share code)"),
    ("bit 1 0x1ca9a; bit 2", "bit 1 0x1ca9a (shared); bit 2"),
    ("while set the low \"\n     \"speed governor breakpoint speed drops by fueling x droop / 0xa7",
     "while set the \"\n     \"torque curve breakpoint 1 speed is lsg_breakpoint_speed minus a fueling x 0x80daf4 / 0xa7 droop term"),
]
for old, new in pairs:
    assert s.count(old) == 1, (old, s.count(old))
    s = s.replace(old, new)
open(p, "w").write(s)
print("ok")
