"""Token-overlap meaning score between an e2m record (name + description) and a CSV row name, for ranking
record-for-record placements before a by-hand read. Abbreviations the e2m uses are expanded to the words the row
names spell out.  score(record name, description, row name) -> 0..1 (share of the row name's content tokens the
record covers)."""
import re

EXPAND = {
    "fs": "fan speed", "tot": "transmission oil temperature", "imt": "intake manifold temperature",
    "ac": "air conditioning", "evr": "alternator field charging voltage regulator", "vss": "vehicle speed sensor",
    "rpm": "engine speed rpm", "temp": "temperature", "max": "maximum", "min": "minimum", "pwm": "duty pwm",
    "dc": "duty", "tc": "torque converter", "tcc": "converter clutch", "oss": "output shaft speed",
    "eb": "exhaust brake", "ocm": "oil change monitor", "tva": "throttle valve actuator", "cc": "cruise control",
    "rsg": "road speed governor", "lsg": "low speed governor", "asg": "all speed governor",
    "hsg": "high speed governor", "pto": "power take off", "vgt": "variable geometry turbocharger",
    "amb": "ambient", "baro": "barometric", "batt": "battery", "eol": "end line", "num": "numerator",
    "den": "denominator", "int": "integral", "prop": "proportional", "der": "derivative", "deriv": "derivative",
    "cnt": "count", "cnts": "count", "thd": "threshold", "thresh": "threshold", "err": "error",
    "diag": "diagnostic", "clnt": "coolant", "ect": "coolant temperature", "iat": "intake air temperature",
    "map": "manifold pressure", "pps": "accelerator pedal position", "tps": "throttle position", "afc": "air fuel control",
    "fp": "fuel pressure", "hpcr": "rail pressure", "inj": "injection injector", "ign": "ignition", "ka": "keep alive",
    "spd": "speed", "pos": "position", "ref": "reference", "cmd": "command", "req": "request", "lim": "limit",
    "acc": "accelerator", "accel": "acceleration accelerator", "decel": "deceleration", "veh": "vehicle",
    "eng": "engine", "trans": "transmission", "gov": "governor", "press": "pressure", "fuel": "fuel",
    "flt": "fault", "msg": "message", "tmr": "timer", "ctr": "counter", "dly": "delay", "hyst": "hysteresis",
    "cal": "", "re": "transmission", "jcomm": "j1939", "tsc": "tsc1", "pgn": "pgn", "sa": "source address",
    "obd": "obd", "mil": "mil", "dtc": "dtc", "ptp": "powertrain protection", "pid": "pid", "oil": "oil",
}
STOP = {"the", "of", "a", "an", "to", "for", "and", "or", "in", "is", "at", "on", "by", "this", "that", "be", "if",
        "when", "used", "value", "cal", "flag", "n", "x", "1", "2", "3", "with", "from", "than", "as", "it"}


def tokens(text):
    out = set()
    for word in re.findall(r"[A-Za-z][a-z]*|[A-Z]+(?![a-z])|\d+", text):
        w = word.lower()
        for t in EXPAND.get(w, w).split():
            if t and t not in STOP:
                out.add(t[:-1] if len(t) > 4 and t.endswith("s") else t)
    return out


def score(record_name, description, row_name):
    want = tokens(row_name.replace("_", " "))
    if not want:
        return 0.0
    have = tokens(record_name.replace("_", " ") + " " + description)
    return len(want & have) / len(want)
