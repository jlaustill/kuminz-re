"""Proof gate for round 21 stage A (the engine protection channel structs):
1. layout: each expected access (function, field) renders - the sites were read in the old .cpp at known byte offsets
   (see EXPECT), spread over the three structs, so a padded or shifted layout fails them;
2. containment: rewrite each <instance>.<field> back to its old flat name (flat_to_field_r21a.json); the functions that
   still differ from the old .cpp must all be in the predicted set (the record readers and the five helpers);
3. no new decompiler artifacts: pieces (._N_M_) and extraout_ / unaff_ / in_r tokens do not grow.
usage: prove_r21a.py <old.cpp> <new.cpp> <flat_to_field.json> [--structs configuration,state,history]"""
import json
import re
import sys

old_cpp, new_cpp, mapping_path = sys.argv[1:4]
structs = sys.argv[sys.argv.index("--structs") + 1].split(",") if "--structs" in sys.argv else ["configuration",
                                                                                                "state", "history"]
EXPECT = [  # (struct, function, field) - old byte offset in the comment
    ("state", "protection_event_timestamp", "fueling_shutdown_time_count"),        # +0x1a
    ("state", "protection_event_timestamp", "engine_speed_shutdown_time_count"),   # +0x1c
    ("state", "protection_state_transition", "errors_allowed"),                    # +0x16
    ("state", "protection_state_transition", "fueling_duration"),                  # +0x06
    ("state", "threshold_adjustment_ramp", "engine_speed_duration"),               # +0x08
    ("state", "protection_threshold_check", "minimum_threshold_pointer"),          # +0x0a
    ("state", "protection_threshold_check", "maximum_threshold_pointer"),          # +0x0e
    ("state", "protection_threshold_check", "engine_speed_lower_limit_pointer"),   # +0x12
    ("state", "protection_threshold_check", "input_mask"),                         # +0x04
    ("state", "cm848_updateEngineProtectionShutdown", "errors_allowed"),           # +0x16
    ("configuration", "threshold_adjustment_ramp", "fueling_derate_start_duration"),    # +0x02
    ("configuration", "threshold_adjustment_ramp", "engine_speed_ramp_rate"),           # +0x08 (iVar5 = 8: may stay
                                                                                        # an offset; see the report)
    ("configuration", "protection_state_transition", "shutdown_warning_time"),         # +0x1e
    ("configuration", "protection_event_timestamp", "shutdown_delay"),                 # +0x14
    ("history", "protection_threshold_update", "fueling_restart_severity_index"),      # +0x04
    ("history", "protection_threshold_update", "engine_speed_restart_severity_index"), # +0x06
    ("history", "threshold_adjustment_ramp", "engine_speed_severity_index"),           # +0x02
]
PREDICTED = {"cm848_calculateFaultDerateEngineSpeedLimit", "cm848_calculateFaultDerateFuelLimit",
             "cm848_completeEngineStartSequence", "cm848_examineEngineProtectionBeforeCranking",
             "cm848_initSensorChannelDataStructures", "cm848_updateEngineProtectionShutdown",
             "governor_fault_channelProcess_mainLoop", "governor_fault_derateCalc_channelIter",
             "governor_fault_eventCounter_update", "hpcr_initFuelTemperatureSensorChannel",
             "threshold_adjustment_ramp", "protection_threshold_check", "protection_threshold_update",
             "protection_state_transition", "protection_event_timestamp"}


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


old, new = open(old_cpp).read(), open(new_cpp).read()
mapping = json.load(open(mapping_path))
oldf, newf = functions(old), functions(new)
problems = []
for struct, fn, field in EXPECT:
    if struct not in structs:
        continue
    body = code_only(newf.get(fn, ""))
    if not re.search(r"(->|\.)" + re.escape(field) + r"\b", body):
        problems.append(f"layout: {fn} does not render {struct}.{field}")
rewritten = new
for flat, dotted in sorted(mapping.items(), key=lambda kv: -len(kv[1])):
    rewritten = re.sub(re.escape(dotted) + r"\b", flat, rewritten)
rewf = functions(rewritten)
changed = sorted(f for f in oldf if f in rewf and code_only(oldf[f]).split() != code_only(rewf[f]).split())
outside = [f for f in changed if f not in PREDICTED]
print(f"functions changed beyond the flat-name rewrite: {len(changed)}; outside the predicted set: {outside}")
if outside:
    problems.append(f"containment: {outside}")
for label, pat in (("pieces", r"\._\d+_\d+_"), ("extraout_", r"\bextraout_\w+"), ("unaff_", r"\bunaff_\w+"),
                   ("in_r", r"\bin_r\w+")):
    a, b = len(re.findall(pat, code_only(old))), len(re.findall(pat, code_only(new)))
    print(f"{label}: {a} -> {b}")
    if b > a:
        problems.append(f"{label} grew {a} -> {b}")
print("\n".join(problems) if problems else "GATE PASS")
