import json
import re

PATH = "/tmp/w13b6/make_results.py"
s = open(PATH).read()
split = s.index("COMMENTS = {")
head, tail = s[:split], s[split:]


def replace_entry(text, key, value):
    pat = re.compile(r'(?m)^    %d: "e2m.*?(?=^    \d+: "|^\}\n|^for i, text)' % key, re.S)
    m = pat.search(text)
    assert m, key
    return text[:m.start()] + "    %d: %s,\n" % (key, json.dumps(value)) + text[m.end():]


tail = replace_entry(
    tail, 0,
    "e2m 0033 +8 Collector_Start_Address 'Logical beginning address of the data collector buffer' (HEX): the read / tail "
    "pointer of the data collector ring buffer, the oldest byte still held (center 0x40c27c, end = write pointer 0x40c280): "
    "diag_dm1Buffer_circularFill advances / wraps it when the write pointer catches it, j1939_dm1_diagnosticMessage_send "
    "moves it past the bytes it sends. The diag_dm1_buffer_* words are the data collector, not DM1.")
# [53] lives in the rename() call, not in COMMENTS: patch the call text
old53 = ('"countdown of engine run state 3 (preliminary sync): reloaded from the evaluation count (engine_event_countdown_cal, "\n'
         '       "e2m Prelim_Sync_Evaluation_Count) by mpc555_resetEngineTimingAccumulators and the run state 3 handlers, counted down "\n'
         '       "by mpc555_updateEngineRunState; at 0 crank_tooth_count_b is compared with crank_tooth_count_b_min_cal (e2m "\n'
         '       "Prelim_Sync_Detection_Threshold) to enter run state 4. dump 6.")')
assert old53 in head, "53 not found"
new53 = ('"countdown of engine run state 3 (preliminary sync): reloaded from engine_event_countdown_cal (e2m "\n'
         '       "Prelim_Sync_Evaluation_Count) by mpc555_resetEngineTimingAccumulators and the run state 3 handlers, counted down "\n'
         '       "by mpc555_updateEngineRunState; at 0 crank_tooth_count_b is checked against crank_tooth_count_b_min_cal to enter "\n'
         '       "run state 4. dump 6.")')
head = head.replace(old53, new53)
open(PATH, "w").write(head + tail)
print("patched")
