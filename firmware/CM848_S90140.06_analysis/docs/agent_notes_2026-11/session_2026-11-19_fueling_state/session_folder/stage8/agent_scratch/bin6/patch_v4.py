import json
import re

PATH = "/tmp/w13b6/make_results.py"
s = open(PATH).read()

# [0]: the data collector family names (bins 1-3 use data_collector_center_address / _end_address / _status)
assert s.count('"data_collector_buffer_read_pointer"') == 1
s = s.replace('"data_collector_buffer_read_pointer"', '"data_collector_start_address"')

split = s.index("COMMENTS = {")
head, tail = s[:split], s[split:]


def replace_entry(text, key, value):
    pat = re.compile(r'(?m)^    %d: "e2m.*?(?=^    \d+: "|^\}\n|^for i, text)' % key, re.S)
    m = pat.search(text)
    assert m, key
    return text[:m.start()] + "    %d: %s,\n" % (key, json.dumps(value)) + text[m.end():]


head = replace_entry(
    head, 0,
    "e2m 0033 +8 Collector_Start_Address (logical beginning of the collector buffer; e2m 0034 +C Collector_Center_Address = "
    "0x40c27c and 0035 +10 Collector_End_Address = 0x40c280 share the base 0x40c270): diag_dm1Buffer_circularFill advances / "
    "wraps it when the write pointer catches it and j1939_dm1_diagnosticMessage_send advances it past the bytes it sends; "
    "the diag_dm1_* buffer words are the data collector, not DM1")
tail = replace_entry(
    tail, 0,
    "e2m 0033 +8 Collector_Start_Address 'Logical beginning address of the data collector buffer' (HEX): the read / tail "
    "pointer of the data collector ring buffer, the oldest byte still held (center address 0x40c27c, end address = write "
    "pointer 0x40c280, buffer bounds 0x40c270 / 0x40c274): diag_dm1Buffer_circularFill advances / wraps it when the write "
    "pointer catches it, j1939_dm1_diagnosticMessage_send moves it past the bytes it sends. The diag_dm1_buffer_* words are "
    "the data collector, not DM1.")
s = head + tail

# [53]: keep -> rename (bin 5 renames its reload value engine_event_countdown_cal to crank_preliminary_sync_evaluation_count)
a = s.index('keep(53, "Prelim_Sync_Count",')
b = s.index("rename(54,")
new53 = '''rename(53, "Prelim_Sync_Count", "crank_preliminary_sync_count",
       "e2m 819B +44 Prelim_Sync_Count: mpc555_updateEngineRunState counts it down in run state 3 and at 0 compares "
       "crank_tooth_count_b with crank_tooth_count_b_min_cal (e2m Prelim_Sync_Detection_Threshold) to enter run state 4, else "
       "reloads it from engine_event_countdown_cal (e2m Prelim_Sync_Evaluation_Count; bin 5 renames that cal to "
       "crank_preliminary_sync_evaluation_count, this keeps the pair readable)",
       "e2m 819B +44 Prelim_Sync_Count 'Counts crank revs until verification decision is made' (UNITLESS, 0..255): the "
       "countdown of engine run state 3 (preliminary sync): reloaded from the evaluation count (engine_event_countdown_cal, "
       "e2m Prelim_Sync_Evaluation_Count) by mpc555_resetEngineTimingAccumulators and the run state 3 handlers, counted down "
       "by mpc555_updateEngineRunState; at 0 crank_tooth_count_b is compared with crank_tooth_count_b_min_cal (e2m "
       "Prelim_Sync_Detection_Threshold) to enter run state 4. dump 6.")

'''
s = s[:a] + new53 + s[b:]
open(PATH, "w").write(s)
print("patched")
