"""Round 17 stage D (label-only, after the review): the engine retarder words still named 'request' beside the round 17
'command' / 'output level' words, and the algorithm_enable_flags_41_t bit 0 name (apply_r17d_field.py), which came
from the extended idle flag's old name governor_speed_limit_active_flag (e2m 1496 +A is LSG_Extended_Idle_Status)."""
GLOBALS = [
    ("0x003fb540", "engine_retarder_command_age_counter",
     "Passes since engine_retarder_command_percent last rose from 0 (saturates at 0xffff): with a boost sensor fault "
     "the engage inhibit lasts engine_retarder_boost_sensor_fault_hold_passes passes of it"),
    ("0x003fb54c", "engine_retarder_output_on_delay_counter",
     "Counts the passes the output level has been at least 50 %; the outputs engage when it reaches "
     "engine_retarder_output_on_delay_passes"),
    ("0x00408ec0", "engine_retarder_output_on_delay_passes",
     "The passes the output level must stay at 50 % or more before the brake outputs engage"),
]
FUNCTIONS = []
