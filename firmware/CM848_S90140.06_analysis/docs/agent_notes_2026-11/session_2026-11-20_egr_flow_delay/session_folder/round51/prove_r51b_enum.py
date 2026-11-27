"""Round 51 stage B proof for the enum and the prototype: in the NEW (cast-stripped) text put each
TRANSMISSION_TEMPERATURE_RATIONALITY_* member's value back, drop the void prototype's removed argument from the OLD
text, remove all whitespace (line wraps move), and require the six changed functions to match exactly.
usage: prove_r51b_enum.py <old_stripped.cpp> <new_stripped.cpp>"""
import re
import sys

MEMBERS = {"NOT_RUN": 0, "RUNNING": 1, "PASSED": 2, "FAILED": 3, "ABORTED": 4, "PASS_VERDICT": 5, "FAIL_VERDICT": 6}


def functions(path):
    t = open(path, errors="replace").read()
    return {m.group(1): m.group(0) for m in re.finditer(r"^// Function: (\S+) @.*?(?=^// Function: |\Z)", t, re.S | re.M)}


def body(text):
    """the code after the plate comment, whitespace collapsed"""
    code = text[text.index("\n", text.index("(")):] if "(" in text else text
    return re.sub(r"\s+", "", re.sub(r"/\*.*?\*/", "", code, flags=re.S))


old, new = functions(sys.argv[1]), functions(sys.argv[2])
ok = True
for f in ("cm848_applicationMain", "cm848_restartApplicationWithoutReset",
          "cm848_initializeTransmissionTemperatureSensorPerformanceMonitor",
          "cm848_updateTransmissionTemperatureSensorPerformanceFault",
          "cm848_completeTransmissionTemperatureMonitorReport", "cm848_checkTransmissionTemperatureSensorPerformance"):
    n = re.sub(r"TRANSMISSION_TEMPERATURE_RATIONALITY_(" + "|".join(sorted(MEMBERS, key=len, reverse=True)) + r")\b",
               lambda m: str(MEMBERS[m.group(1)]), new[f])
    o = old[f].replace("cm848_flagTripInformationPowerDownDataLoss(0x30d4)", "cm848_flagTripInformationPowerDownDataLoss()")
    same = body(o) == body(n)
    ok &= same
    print(f"{'same' if same else 'DIFFERENT'}  {f}")
print("PROVEN" if ok else "NOT PROVEN")
if len(sys.argv) > 3:
    f = sys.argv[3]
    n = re.sub(r"TRANSMISSION_TEMPERATURE_RATIONALITY_(" + "|".join(sorted(MEMBERS, key=len, reverse=True)) + r")\b",
               lambda m: str(MEMBERS[m.group(1)]), new[f])
    a, b = body(old[f]), body(n)
    i = next((k for k in range(min(len(a), len(b))) if a[k] != b[k]), min(len(a), len(b)))
    print("OLD:", a[max(0, i - 160):i + 160])
    print("NEW:", b[max(0, i - 160):i + 160])
