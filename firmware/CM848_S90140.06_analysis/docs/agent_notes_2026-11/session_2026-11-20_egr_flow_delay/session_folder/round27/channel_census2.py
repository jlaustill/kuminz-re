"""Round 27: sensor channel block names from each call's own named anchors.
- base = the config argument minus '_config', else the value output minus '_value' (never a generic sensor_channel*);
- config / state / filter / status / value / default = base + '_config' / '_state' / '_filter_state' / '_status' /
  '_value' / '_default_value' (the reference voltage B channel's pattern);
- cache = the x axis table's base (minus '_axis' / '_x_axis') + '_cached_axis_offset' (round 10's rule).
Only arguments that are Ghidra labels (type-only rows) get a proposal. A label seen in two calls must get the same
proposal (init / update twins), else it is reported. Channels in SKIP are left (mixed vocabulary or unidentified).
usage: channel_census2.py <cpp> <out.tsv>"""
import re
import sys
from collections import defaultdict

cpp, out = sys.argv[1], sys.argv[2]
text = open(cpp).read()
CALL = re.compile(r"\b(sensorChannelConfigInit|updateSensorChannelWithConfig|sensorChannelTypeB_configInit|"
                  r"sensorChannelTypeB_update)\s*\(([^;]*?)\);", re.S)
LABEL = re.compile(r"^&?(sensor_channel_config_t_|sensor_channel_state_t_|ema_filter_state_t_|WORD_)([0-9a-f]{8})$")
ROLE = ["config", "state", "cache", "x_axis", "y_data", "flags", "filter", "channel", "high_fault", "low_fault",
        "value", "default", "status"]
SKIP = {"0x14", "0x4d"}       # channel 20: sensor_channel1_* / ambient tables / compressor inlet outputs mixed; 77 ?
proposals = defaultdict(set)
rows = []
for m in CALL.finditer(text):
    args = [re.sub(r"\s+", "", a) for a in m.group(2).split(",")]
    if len(args) != 13:
        continue
    a = dict(zip(ROLE, (x.lstrip("&") for x in args)))
    ch = a["channel"]
    base = None
    if not LABEL.match(a["config"]) and a["config"].endswith("_config"):
        base = a["config"][:-len("_config")]
    elif not LABEL.match(a["value"]) and a["value"].endswith("_value"):
        base = a["value"][:-len("_value")]
    if base and base.startswith("sensor_channel"):
        base = None
    tbase = re.sub(r"(_x_axis|_axis)$", "", a["x_axis"]) if not LABEL.match(a["x_axis"]) else None
    for role in ("config", "state", "cache", "filter", "value", "default", "status"):
        if not LABEL.match(a[role]):
            continue
        if ch in SKIP or base is None:
            prop = ""
        elif role == "cache":
            prop = (tbase + "_cached_axis_offset") if tbase and not tbase.startswith("sensor_channel") else ""
        else:
            prop = base + {"config": "_config", "state": "_state", "filter": "_filter_state", "value": "_value",
                           "default": "_default_value", "status": "_status"}[role]
        proposals[a[role]].add(prop)
        rows.append((ch, base or "-", role, a[role], prop))
with open(out, "w") as fh:
    fh.write("channel\tbase\trole\tlabel\tproposal\n")
    for r in sorted(set(rows)):
        fh.write("\t".join(r) + "\n")
conflicts = {k: v for k, v in proposals.items() if len(v) > 1}
print(len({r[3] for r in rows}), "labels;", sum(1 for k, v in proposals.items() if "" not in v and len(v) == 1),
      "named;", len(conflicts), "conflicts", conflicts)
