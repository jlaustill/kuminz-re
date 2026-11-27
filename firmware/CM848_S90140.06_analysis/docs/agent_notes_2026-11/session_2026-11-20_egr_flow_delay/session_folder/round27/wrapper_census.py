"""Round 27: every caller of the four sensor channel base functions, with the base it calls (periodic / boot),
the channel(s), its body size (non-blank lines) and the other calls it makes (a thin wrapper makes none).
usage: wrapper_census.py <cpp> > wrappers.tsv"""
import re
import sys

text = open(sys.argv[1]).read()
BASES = {"sensorChannelConfigInit": ("process", "signed"), "updateSensorChannelWithConfig": ("initialize", "signed"),
         "sensorChannelTypeB_configInit": ("process", "unsigned"), "sensorChannelTypeB_update": ("initialize", "unsigned")}
funcs = re.findall(r"^// Function: (\S+) @ (0x[0-9a-f]+)\n(.*?)(?=^// Function: |\Z)", text, re.S | re.M)
print("wrapper\taddress\tkind\tsignedness\tchannels\tlines\tother_calls")
for name, addr, body in funcs:
    if name in BASES:
        continue
    code = re.sub(r"/\*.*?\*/", "", body, flags=re.S)
    calls = [c for c in re.findall(r"\b([A-Za-z_][A-Za-z_0-9]*)\s*\(", code) if c not in ("if", "while", "for", "switch",
                                                                                         "return", "sizeof")]
    hits = [c for c in calls if c in BASES]
    if not hits:
        continue
    kinds = sorted({BASES[c][0] for c in hits})
    signs = sorted({BASES[c][1] for c in hits})
    channels = sorted(set(re.findall(r"(?:" + "|".join(BASES) + r")\s*\((?:[^;]*?,){7}\s*([0-9a-fx]+)\s*,", code, re.S)))
    others = sorted(set(c for c in calls if c not in BASES and c != name and not re.match(r"^(CONCAT|SUB|ZEXT|SEXT)", c)))
    lines = sum(1 for l in code.splitlines() if l.strip() and not l.strip().startswith("//"))
    print("\t".join([name, addr, "/".join(kinds), "/".join(signs), ",".join(channels), str(lines), ",".join(others)]))
