"""Gate for round 21 stage E (the signed thresholds): the changed functions are the five readers (plus local
declaration-order flips, reported), no (short) cast is left on the seven retyped fields, and the decompiler artifact
counts do not grow. usage: prove_r21e.py <old.cpp> <new.cpp>"""
import re
import sys

PREDICTED = {"hpcr_initializeEngineProtection", "cm848_isEngineProtectionInputPastThreshold",
             "cm848_updateEngineProtectionRestartSeverityIndexes", "cm848_updateEngineProtectionShutdown",
             "cm848_calculateFaultDerateFuelLimit"}
FIELDS = ("fueling_minimum_threshold", "fueling_maximum_threshold", "fueling_shutdown_duration_threshold",
          "engine_speed_shutdown_duration_threshold", "minimum_threshold_pointer", "maximum_threshold_pointer",
          "engine_speed_lower_limit_pointer")


def functions(text):
    out, name, buf = {}, None, []
    for line in text.split("\n"):
        m = re.match(r"// Function: (\S+)", line)
        if m:
            if name:
                out[name] = "\n".join(buf)
            name, buf = m.group(1), []
        elif name:
            buf.append(line)
    if name:
        out[name] = "\n".join(buf)
    return out


def code_only(text):
    text = re.sub(r"/\*.*?\*/", "", text, flags=re.S)
    return re.sub(r"//[^\n]*", "", text)


old, new = open(sys.argv[1]).read(), open(sys.argv[2]).read()
of, nf = functions(old), functions(new)
changed = [f for f in of if f in nf and code_only(of[f]).split() != code_only(nf[f]).split()]
order_only = [f for f in changed if sorted(code_only(of[f]).split("\n")) == sorted(code_only(nf[f]).split("\n"))]
outside = [f for f in changed if f not in PREDICTED and f not in order_only]
print("changed:", sorted(changed))
print("declaration order only:", order_only)
problems = []
if outside:
    problems.append(f"outside the predicted set: {outside}")
casts = re.findall(r"\(short\)\**[A-Za-z_0-9>.\-\[\]]*(?:->|\.)(" + "|".join(FIELDS) + r")\b", code_only(new))
print("(short) casts left on the retyped fields:", len(casts), sorted(set(casts)))
if casts:
    problems.append("casts left")
for label, pat in (("pieces", r"\._\d+_\d+_"), ("extraout_", r"\bextraout_\w+"), ("unaff_", r"\bunaff_\w+"),
                   ("in_r", r"\bin_r\w+")):
    a, b = len(re.findall(pat, code_only(old))), len(re.findall(pat, code_only(new)))
    print(f"{label}: {a} -> {b}")
    if b > a:
        problems.append(f"{label} grew")
print("\n".join(problems) if problems else "GATE PASS")
