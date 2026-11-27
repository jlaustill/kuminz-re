"""Round 9 stage D: the two 8C19 flag struct instances (the types and fields are renamed by apply_r9d_structs.py)."""
GLOBALS = [
    ("0x0040b0e8", "transmission_control_flags",
     "e2m 8C19 +0..+9, the RE transmission control flag bytes (transmission_control_flags_t): the shift / unlock "
     "requests, the mode flags (cruise / decel / low range), the state flags, the overdrive flags, the axle ratio learning "
     "flags, the four limp-home bytes and the low range boost flags. 8C19 aligns here: its +0 / +1 / +2 / +3 / +4 / +9 "
     "records match the bits the code sets"),
    ("0x0040b0f2", "transmission_shift_strategy_flags",
     "e2m 8C19 +A..+11 (transmission_shift_strategy_flags_t): the WOT flags, the anti-hunt / detent flags, the actuator "
     "test and service tool test requests, the limp-home 3rd gear / temperature flags"),
]
FUNCTIONS = []
