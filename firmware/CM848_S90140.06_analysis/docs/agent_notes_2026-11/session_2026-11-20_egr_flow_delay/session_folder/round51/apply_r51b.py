"""Round 51 stage B: types from the records stage A cited.
  0x408d42 transmission_temperature_default_during_limp_in_delay  word -> i16  (8B9B +A S2; its one load is lha)
  0x408d46 transmission_temperature_coolant_model_offset          word -> i16  (8B9B +E S2; its one load is lha)
  0x40b628 transmission_temperature_rationality_driving_range     word -> i16  (8C2D +2 S2; never loaded - the check
           compares the value it just stored as a short)
  0x40b62a transmission_temperature_rationality_state -> a new enum TRANSMISSION_TEMPERATURE_RATIONALITY_STATE:
           8C2D +4's labels give 0-4 (NORUN / RUN / CMPPS / CMPFL / ABORT), and the check's own verdict states 5 / 6
           need members too - typed with the shared DIAGNOSTIC_MONITOR_STATE they rendered as ABORTED|RUNNING and
           ABORTED|PASSED (a first build of this stage).
  0x408d40 transmission_temperature_default_after_limp_in_delay stays word: 8B9B +8 is S2 but its only reference is
           an addi (read through a pointer shared with the sensor value).
  0x523760 cm848_flagTripInformationPowerDownDataLoss: a full void (void) prototype, so its two power-down calls stop
           passing the r3 left over from the preceding code (0x30d4). Its stage A plate named the wrong second caller
           (cm848_restartApplicationWithoutReset, not cm848_applicationMain twice): fixed here.
Idempotent.  usage: apply_r51b.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 51"
ENUM = "TRANSMISSION_TEMPERATURE_RATIONALITY_STATE"
CHECK = "cm848_checkTransmissionTemperatureSensorPerformance"
REPORT = "cm848_completeTransmissionTemperatureMonitorReport"
VERDICT = "cm848_updateTransmissionTemperatureSensorPerformanceFault"
members = [
    (0, "NOT_RUN", f"e2m 8C2D +4 label NORUN: {CHECK} qualifies the start conditions and takes the start snapshot"),
    (1, "RUNNING", "e2m label RUN: the check tracks the temperature swing while driving above 30 mph"),
    (2, "PASSED", f"e2m label CMPPS (complete / passed): {REPORT} reports state 5 as this"),
    (3, "FAILED", f"e2m label CMPFL (complete / failed): {REPORT} reports every other verdict as this"),
    (4, "ABORTED", "e2m label ABORT: no verdict this key cycle (the check is disabled / a related fault / the soak "
                   "was not qualified)"),
    (5, "PASS_VERDICT", f"no e2m label: {CHECK} sets it once the swing reaches transmission_temperature_rationality_"
                        f"minimum_swing; {REPORT} turns it into PASSED"),
    (6, "FAIL_VERDICT", f"no e2m label: {VERDICT} sets it while a result flag is set; {REPORT} turns it into FAILED"),
]
done = 0
ep = os.path.join(out, "enums.csv")
e = open(ep).read()
if f"\n{ENUM}," not in e:
    e = e if e.endswith("\n") else e + "\n"
    lines = [f"# {ENUM}: transmission_temperature_rationality_state, the P0711 check's states ({R})"]
    for v, m, text in members:
        assert "," not in m and '"' not in text
        lines.append(f'{ENUM},{v},{ENUM.removesuffix("_STATE")}_{m},"{text} ({R})",2')
    open(ep, "w").write(e + "\n".join(lines) + "\n")
    done += 1
gp = os.path.join(out, "global_variables.csv")
g = open(gp).read().split("\n")
idx = {l[:10]: k for k, l in enumerate(g) if l.startswith("0x")}
changes = [("0x00408d42", "transmission_temperature_default_during_limp_in_delay", "word", "i16",
            "Typed i16: 8B9B +A is signed and its one load is lha"),
           ("0x00408d46", "transmission_temperature_coolant_model_offset", "word", "i16",
            "Typed i16: 8B9B +E is signed and its one load is lha"),
           ("0x0040b628", "transmission_temperature_rationality_driving_range", "word", "i16",
            "Typed i16: 8C2D +2 is signed; never loaded (the check compares the value it just stored as a short)"),
           ("0x0040b62a", "transmission_temperature_rationality_state", "word", ENUM,
            f"Typed {ENUM}: 8C2D +4's labels are members 0-4 and the check's own verdicts 5 / 6 have members too (the "
            "shared DIAGNOSTIC_MONITOR_STATE rendered them as ABORTED|RUNNING / ABORTED|PASSED)")]
for a, name, old, new, note in changes:
    p = g[idx[a]].split(",", 3)
    assert p[1] == name, (a, p[1])
    if p[2] == new:
        continue
    assert p[2] == old, (a, p[2])
    g[idx[a]] = f"{a},{name},{new},{note} ({R}). {p[3]}"
    done += 1
open(gp, "w").write("\n".join(g))
CALLERS = "cm848_applicationMain and cm848_restartApplicationWithoutReset"
fd = os.path.join(out, "function_definitions.csv")
t = open(fd).read()
proto = ("# The trip information power-down step takes no parameters (PR #53 round 51)\n"
         "0x00523760,cm848_flagTripInformationPowerDownDataLoss,return,,void,Takes no parameters: its power-down "
         f"calls in {CALLERS} pass the r3 left over from the preceding code (0x30d4) ({R})\n")
if "0x00523760," not in t:
    t = t if t.endswith("\n") else t + "\n"
    open(fd, "w").write(t + proto)
    done += 1
fp = os.path.join(out, "function_renames.csv")
t = open(fp).read()
wrong = "Power-down step (cm848_applicationMain calls it twice after the RAM calibration refresh)"
right = f"Power-down step ({CALLERS} each call it after the RAM calibration refresh)"
if wrong in t:
    open(fp, "w").write(t.replace(wrong, right))
    done += 1
print(f"{done} changes")
