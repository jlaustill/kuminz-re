"""Round 25 stage C (types): the executive frame timing (e2m 12A6 Executive_Timing_Overflows / Executive_Frame_Max_Time_
Capture). With algorithm_enable_flags_18_cal.executive_timing_enable set, main_loop clears 12-byte records from
0x40be6a up to ram_refresh_enable (0x40c04a: 40 records, nothing else lives there) when the enable rises, and after
every pass adds the pass's timebase ticks to the record the walking pointer points at (sum, count, minimum, maximum,
overflows above the threshold; an overflow also counts the EEPROM total), then steps the pointer by one record; phase
0 resets it to the first record.
- scheduler_task_stat_t -> executive_frame_timing_t (type-only), fields spelled out; the instance becomes the array
  executive_frame_timings (executive_frame_timing_t[40]); its 4 dotted alias rows go.
- The helpers: the two walking pointers typed executive_frame_timing_t *, the pass ticks / start ticks / enable edge /
  threshold / EEPROM overflow total named; 0x3feec0 gets its e2m row.
Writes the proof's token map. usage: apply_r25c.py <repo> <tokens.json>"""
import csv
import io
import json
import os
import sys

repo, tokens_out = os.path.abspath(sys.argv[1]), sys.argv[2]
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
T = "executive_frame_timing_t"
FIELDS = {"total_ticks": ("total_ticks", "Sum of the frame's pass times in timebase ticks"),
          "call_count": ("frame_count", "Passes of the frame counted"),
          "min_time": ("minimum_ticks", "Shortest pass time (0xffff after a clear)"),
          "max_time": ("maximum_ticks", "Longest pass time"),
          "overrun_count": ("overflow_count", "Passes longer than executive_frame_overflow_threshold_ticks (each also "
                                              "counts executive_timing_overflow_count_cal)")}


def write_csv_row(row):
    s = io.StringIO()
    csv.writer(s, lineterminator="").writerow(row)
    return s.getvalue()


sp = os.path.join(out, "structure_definitions.csv")
sd = open(sp).read().split("\n")
n = 0
for i, line in enumerate(sd):
    if line.startswith("scheduler_task_stat_t,"):
        row = next(csv.reader([line]))
        new, comment = FIELDS[row[2]]
        row[0], row[1], row[2] = T, "", new
        row[5] = f"{comment} (was {row[2] if False else next(csv.reader([line]))[2]}; PR #53 round 25)"
        sd[i] = write_csv_row(row)
        n += 1
assert n == 5, n
open(sp, "w").write("\n".join(sd))
RENAME = {  # address: (old name, new name, new type or None, comment)
    0x40be6a: ("scheduler_task_stat_t_0040be6a", "executive_frame_timings", f"{T}[40]",
               "The executive's frame timing records, 40 of 12 bytes (0x40be6a-0x40c049: main_loop's clear loop runs up "
               "to ram_refresh_enable): with algorithm_enable_flags_18_cal.executive_timing_enable set, main_loop "
               "clears them when the enable rises and adds every pass to the record executive_frame_timing_pointer "
               "points at. This main_loop has two phases and resets the pointer in phase 0, so it fills records 0 and "
               "1"),
    0x3fa00c: ("scheduler_task_stat_ptr_b", "executive_frame_timing_pointer", f"{T} *",
               "The record of the current frame: main_loop sets it to executive_frame_timings in phase 0, updates the "
               "record after the pass and steps it by one record"),
    0x3fa010: ("scheduler_task_stat_ptr", "executive_frame_timing_clear_pointer", f"{T} *",
               "main_loop's pointer while it clears executive_frame_timings (stored each step)"),
    0x3fa000: ("scheduler_task_stat_value_working", "executive_frame_ticks", None,
               "The pass's time in timebase ticks (TBLr - executive_frame_start_ticks), stored by main_loop. Its "
               "address is also the start of working RAM for cm848_clearWorkingRam and "
               "cm848_evaluateCalibratedMonitorDisableConditions"),
    0x3fa002: ("timer_base_snapshot", "executive_frame_start_ticks", None,
               "TBLr at the start of main_loop's pass"),
    0x3fa006: ("scheduler_feature_enabled_flag", "executive_timing_enabled_previous_flag", None,
               "algorithm_enable_flags_18_cal.executive_timing_enable at the last pass: main_loop clears the records "
               "when the enable is set and this is 0"),
    0x40be64: ("task_execution_time_threshold", "executive_frame_overflow_threshold_ticks", None,
               "Pass time in timebase ticks above which a pass is an overflow; 0x3095 from cm848_initSensorDefaults"),
    0x3feebe: ("scheduler_overrun_count_cal", "executive_timing_overflow_count_cal", None, None),
}
gp = os.path.join(out, "global_variables.csv")
g = open(gp).read().split("\n")
new_g, done, dropped = [], set(), 0
for line in g:
    if line.startswith("0x") and len(line) > 10:
        a = int(line[:10], 16)
        name = line.split(",", 2)[1]
        if name.startswith("scheduler_task_stat_t_0040be6a."):
            dropped += 1
            continue
        if a in RENAME:
            old, new, typ, comment = RENAME[a]
            parts = line.split(",", 3) + [""] * 3
            assert parts[1] == old, (hex(a), parts[1])
            text = parts[3] if comment is None else f"{comment} (was {old}) (PR #53 round 25)" + (
                f" | earlier note: {parts[3]}" if parts[3] else "")
            if comment is None:
                text = f"{parts[3]} (was {old}; PR #53 round 25)"
            new_g.append(f"0x{a:08x},{new},{typ or parts[2]},{text}")
            done.add(a)
            if a == 0x3feebe:
                new_g.append("0x003feec0,executive_frame_maximum_time_capture_cal,word,e2m 12A6 +2 Executive_Frame_Max_"
                             "Time_Capture 'Set frame maximum timing capture functionality' (EEPROM 0x1a3e); no reader in "
                             "the .cpp (PR #53 round 25)")
            continue
    new_g.append(line)
assert done == set(RENAME) and dropped == 4, (done, dropped)
assert not any(l.startswith("0x003feec0,") for l in g)
open(gp, "w").write("\n".join(new_g))
old_tok = {o: f"EXEC_{hex(a)}" for a, (o, n, t, c) in RENAME.items()}
new_tok = {n: f"EXEC_{hex(a)}" for a, (o, n, t, c) in RENAME.items()}
json.dump({"old": old_tok, "new": new_tok}, open(tokens_out, "w"), indent=1)
print("executive frame timing typed and named")
