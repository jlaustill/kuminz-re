"""Proof gate for round 21 stage B (the fault log entry and the current-channel pointers), from prove_r21a.py:
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
structs = sys.argv[sys.argv.index("--structs") + 1].split(",") if "--structs" in sys.argv else ["configuration", "state", "history", "entry"]
EXPECT = [  # (struct, function, field) - stage B: the current-channel pointers and the fault log entry
    ("configuration", "governor_fault_channelProcess_mainLoop", "start_monitor_engine_speed"),   # +0x16
    ("configuration", "governor_fault_channelProcess_mainLoop", "start_monitor_time"),           # +0x18
    ("state", "governor_fault_channelProcess_mainLoop", "errors_allowed"),                       # +0x16
    ("state", "governor_fault_channelProcess_mainLoop", "errors_allowed_timer"),                 # +0x22
    ("state", "governor_fault_channelProcess_mainLoop", "errors_allowed_timer_running"),         # +0x24
    ("state", "governor_fault_channelProcess_mainLoop", "precrank_error"),                       # +0x18
    ("history", "governor_fault_channelProcess_mainLoop", "fueling_fault_elapsed_time"),         # +0x0e
    ("history", "governor_fault_channelProcess_mainLoop", "engine_speed_fault_elapsed_time"),    # +0x12
    ("history", "fault_snapshot_capture", "fueling_fault_log_index"),                            # +0x18
    ("configuration", "fault_snapshot_capture", "fueling_fault_index"),                          # +0x1a
    ("state", "fault_snapshot_capture", "fueling_fault_log_pointer"),                            # +0x26
    ("entry", "fault_snapshot_capture", "occurrence_time"),                                      # entry +0
    ("entry", "fault_event_timing_snapshot", "duration"),                                        # entry +6
    ("history", "fault_event_timing_snapshot", "engine_speed_fault_log_index"),                  # +0x1c
]
PREDICTED = {"governor_fault_channelProcess_mainLoop", "fault_snapshot_capture", "fault_event_timing_snapshot",
             "hpcr_initFuelTemperatureSensorChannel"}


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
