"""Round 27: census of the sensor channel calls. For each call of the four channel functions, the 13 arguments
(config, state, cache, x axis, y data, flags, filter, channel, high fault bit, low fault bit, value out, default out,
status out); the channel's identity <x> from its named arguments (value output '<x>_sensor_value', tables
'<x>_linearization_*', config '<x>_sensor_config', state '<x>_sensor_state' / '<x>_sensor_channel_state'); and every
argument that is still a Ghidra label (sensor_channel_config_t_ / sensor_channel_state_t_ / ema_filter_state_t_ /
WORD_ / DAT_), with the name the convention gives it. Prints TSV.
usage: channel_census.py <cpp> > census.tsv"""
import re
import sys

cpp = open(sys.argv[1]).read()
CALL = re.compile(r"\b(sensorChannelConfigInit|updateSensorChannelWithConfig|sensorChannelTypeB_configInit|"
                  r"sensorChannelTypeB_update)\s*\(([^;]*?)\);", re.S)
HEAD = re.compile(r"^// Function: (\S+) @", re.M)
LABEL = re.compile(r"^&?(sensor_channel_config_t_|sensor_channel_state_t_|ema_filter_state_t_|WORD_|DAT_|"
                   r"WORD_ARRAY_)([0-9a-f]{8})$")
ROLE = ["config", "state", "cache", "x_axis", "y_data", "flags", "filter", "channel", "high_fault", "low_fault",
        "value", "default", "status"]
SUFFIX = {"config": "_sensor_config", "state": "_sensor_state", "cache": "_linearization_cached_axis_offset",
          "filter": "_sensor_filter_state", "value": "_sensor_value", "default": "_sensor_default_value",
          "status": "_sensor_status", "x_axis": "_linearization_axis", "y_data": "_linearization_values"}
heads = [(m.start(), m.group(1)) for m in HEAD.finditer(cpp)]


def func_at(pos):
    name = "?"
    for p, n in heads:
        if p > pos:
            break
        name = n
    return name


def identity(args):
    cands = []
    for a in args:
        a = a.lstrip("&")
        for pat in (r"^(.+)_sensor_value$", r"^(.+)_sensor_default_value$", r"^(.+)_linearization_(x_axis|y_axis|axis|values)$",
                    r"^(.+)_sensor_config$", r"^(.+)_sensor_channel_state$", r"^(.+)_sensor_state$"):
            m = re.match(pat, a)
            if m and not m.group(1).startswith("sensor_channel"):
                cands.append(m.group(1))
    return sorted(set(cands))


print("\t".join(["function", "call", "channel", "identity", "role", "label", "proposal"]))
for m in CALL.finditer(cpp):
    args = [re.sub(r"\s+", "", a) for a in m.group(2).split(",")]
    if len(args) != 13:
        continue
    ident = identity(args)
    for role, a in zip(ROLE, args):
        lm = LABEL.match(a)
        if lm:
            prop = (ident[0] + SUFFIX[role]) if len(ident) == 1 and role in SUFFIX else ""
            print("\t".join([func_at(m.start()), m.group(1), args[7], "/".join(ident) or "-", role, a, prop]))
