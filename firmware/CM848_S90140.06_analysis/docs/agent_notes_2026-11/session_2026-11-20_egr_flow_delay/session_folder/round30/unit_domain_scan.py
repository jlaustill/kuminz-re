"""Round 30: e2m records whose unit belongs to one domain while the row name carries another domain's word and none
of its own (a temperature unit under a 'pressure' name, an rpm unit under a 'temperature' name ...). Candidates for a
wrong-domain name; each needs its code use read (a name can describe a derived quantity on purpose).
usage: unit_domain_scan.py <e2m_audit.csv>"""
import csv
import re
import sys

DOMAINS = {
    "temperature": ({"DEG_F", "DEG_C", "DEGF", "DEGC"}, {"temperature", "temp", "tmptr", "thermostat", "overheat", "cold",
                                                        "warm", "heat", "heater", "hot", "dew", "condensation"}),
    "pressure": ({"IN_HG", "INHG", "KPA", "PSI", "BAR", "PSIA", "PSIG"}, {"pressure", "boost", "barometric", "vacuum",
                                                                       "altitude", "charge", "manifold", "rail",
                                                                       "exhaust", "intake", "delta"}),
    "engine speed": ({"RPM"}, {"speed", "rpm", "idle", "governor", "overspeed", "crank", "engine", "turbocharger",
                               "fan", "shaft"}),
    "vehicle speed": ({"MPH", "KPH", "KM/H"}, {"speed", "mph", "vehicle", "road", "cruise", "distance", "velocity"}),
    "voltage": ({"VOLT", "VOLTS", "MV", "VDC"}, {"voltage", "volts", "battery", "supply", "reference", "charging",
                                                "capacitor", "sensor"}),
    "time": ({"SEC", "MSEC", "MS", "MIN", "HR", "HOURS", "SECONDS", "USEC"}, {"time", "timer", "delay", "duration",
                                                                             "period", "timeout", "seconds", "ticks",
                                                                             "passes", "count", "counter", "limit",
                                                                             "dwell", "interval", "debounce",
                                                                             "milliseconds", "hours", "age"}),
}
WORD_DOMAIN = {"temperature": "temperature", "pressure": "pressure", "voltage": "voltage", "rpm": "engine speed",
               "mph": "vehicle speed"}


def words(s):
    return {w.lower() for w in re.split(r"[_\W]+", s) if w}


for r in csv.DictReader(open(sys.argv[1])):
    if r["status"] != "named" or not r["row_name"]:
        continue
    unit = r["unit"].strip().upper()
    domain = next((d for d, (units, _) in DOMAINS.items() if unit in units), None)
    if not domain:
        continue
    w = words(r["row_name"])
    own = DOMAINS[domain][1]
    others = {WORD_DOMAIN[x] for x in w if x in WORD_DOMAIN and WORD_DOMAIN[x] != domain}
    if others and not (w & own):
        print(f"{r['address']} {r['block']} +{r['offset']} {r['record']:42} [{unit}] -> {r['row_name']} "
              f"({r['references']} refs; name says {', '.join(sorted(others))})")
