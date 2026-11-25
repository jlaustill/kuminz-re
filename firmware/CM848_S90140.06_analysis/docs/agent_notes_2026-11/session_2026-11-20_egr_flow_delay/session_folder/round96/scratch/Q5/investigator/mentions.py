"""List CM848 CSV rows (other than the renamed rows themselves) whose text mentions a name this batch changes."""
import csv
import os
import re

FROZEN = "/home/linux/.claude/jobs/374b0424/tmp/w15/r96/frozen/cm848"
OLD = ["qadc_control_word_cal", "qadc_control_word_b", "qadc_control_word_c", "qadc_control_word_d",
       "qadc_control_word_e", "qadc_control_word_f", "qadc_control_word_g", "qadc_channel_config_mask_c",
       "qadc_channel_config_mask_d", "qadc_channel_config_mask_e", "qadc_channel_config_mask_f",
       "qadc_channel_config_mask_g", "qadc_channel_config_mask_h", "qadc_channel_config_mask_i",
       "qadc_queue_timing_config", "qadc_queue_timing_config_b", "qadc_queue_timing_config_c",
       "qadc_queue_timing_config_d", "qadc_queue_timing_config_e", "qadc_queue_timing_config_f",
       "qadc_queue_timing_config_g", "qadc_queue_timing_config_h", "qadc_prescale_count_b", "qadc_prescale_count_c",
       "qadc_prescale_count_d", "qadc_prescale_count_e", "qadc_prescale_count_f", "qadc_prescale_count_g",
       "qadc_sample_rate_cal", "flash_poll_timeout_cycles", "flash_poll_timeout_cal", "flash_poll_retry_limit_cal",
       "data_transfer_retry_count", "cmf_pulses_per_step", "cmf_control_step_bits", "cmf_control_base",
       "cmf_control_pulse_value"]
own = set()
pat = {n: re.compile(r"(?<![A-Za-z0-9_])" + re.escape(n) + r"(?![A-Za-z0-9_])") for n in OLD}
for f in sorted(os.listdir(FROZEN)):
    if not f.endswith(".csv"):
        continue
    for i, line in enumerate(open(os.path.join(FROZEN, f), errors="replace"), 1):
        first = line.split(",")[:2]
        rowname = first[1] if len(first) > 1 else ""
        found = [n for n in OLD if n in line and pat[n].search(line) and n != rowname]
        if found:
            print(f"{f}:{i} row={','.join(first)} mentions {found}")
