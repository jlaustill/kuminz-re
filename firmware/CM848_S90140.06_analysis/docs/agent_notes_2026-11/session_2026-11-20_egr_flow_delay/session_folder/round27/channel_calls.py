"""Round 27: one line per sensor channel (unique argument lists of the four channel functions), with the caller.
usage: channel_calls.py <cpp>"""
import re
import sys

text = open(sys.argv[1]).read()
CALL = re.compile(r"\b(sensorChannelConfigInit|updateSensorChannelWithConfig|sensorChannelTypeB_configInit|"
                  r"sensorChannelTypeB_update)\s*\(([^;]*?)\);", re.S)
HEAD = re.compile(r"^// Function: (\S+) @", re.M)
heads = [(m.start(), m.group(1)) for m in HEAD.finditer(text)]
seen = {}
for m in CALL.finditer(text):
    args = tuple(re.sub(r"\s+", "", a) for a in m.group(2).split(","))
    if len(args) != 13:
        continue
    caller = max((p, n) for p, n in heads if p < m.start())[1]
    seen.setdefault(args, []).append(caller)
for args, callers in sorted(seen.items(), key=lambda kv: int(kv[0][7], 0)):
    print(f"ch {args[7]} ({int(args[7], 0)}): " + " | ".join(args[:7] + args[8:]) + "  <- " + ", ".join(callers))
