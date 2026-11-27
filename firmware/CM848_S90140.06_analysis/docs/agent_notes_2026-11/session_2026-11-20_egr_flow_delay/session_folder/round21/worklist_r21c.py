"""Round 21 stage C (label-only): the engine protection module's functions and working words, named from their typed
bodies (stages A and B). None is a CM550 twin. 0x3fbd4a (unnamed) and 0x40a78b (no row) are handled by
apply_r21c2.py."""
GLOBALS = [
    ("0x003fbd38", "engine_protection_shutdown_latch",
     "Set when an engine protection shutdown is commanded (cm848_updateEngineProtectionShutdown); while it is set no "
     "channel is examined. Cleared with the engine stopped and by cm848_completeEngineStartSequence"),
    ("0x003fbd3e", "engine_protection_longest_shutdown_time_count",
     "The longest fueling / engine speed shutdown time count over the channels in this pass of "
     "cm848_updateEngineProtectionShutdown (reset each pass); while it is nonzero engine_protection_timer_state is 1"),
    ("0x003fbd36", "engine_protection_previous_engine_speed",
     "filtered_engine_speed at the end of the last cm848_updateEngineProtectionShutdown pass (0 after "
     "cm848_completeEngineStartSequence)"),
    ("0x003fbd3c", "engine_protection_engine_start_flag",
     "1 in the pass where the engine speed leaves 0 (engine_protection_previous_engine_speed 0, filtered speed not 0); "
     "cm848_countEngineProtectionShutdownTime then sets the start warning times from the shutdown delay"),
    ("0x003fbd2c", "engine_protection_task_index",
     "cm848_runFaultDerateScheduler's round-robin task: 0 the over-limit durations, 1 the override latch and the "
     "restart severity, 2 the fault derate fuel limit, 3 the engine speed limit and the fault logs, 4 the shutdown"),
    ("0x003fbd42", "engine_protection_current_configuration",
     "The configuration record of the channel cm848_logEngineProtectionChannelFaults is on (the two fault log helpers "
     "read it)"),
    ("0x003fbd46", "engine_protection_current_state",
     "The state record of the channel cm848_logEngineProtectionChannelFaults is on (the two fault log helpers read it)"),
]
FUNCTIONS = [
    ("0x00507d50", "cm848_rampEngineProtectionSeverityIndex",
     "Returns the channel's fueling (is_engine_speed 0) or engine speed severity index after one ramp step: plus the "
     "ramp rate (capped at 0x100) while the over-limit duration is past the derate start duration, else minus it "
     "(floored at 0)"),
    ("0x00507ebc", "cm848_isEngineProtectionInputPastThreshold",
     "1 when the channel's input is past the threshold picked by is_engine_speed and threshold_select (the minimum / "
     "maximum or lower limit pointer, the shutdown duration threshold, the shutdown severity threshold), compared below "
     "or above by configuration flag 0x4; a switch input (configuration flags 0x30) tests its masked bit instead"),
    ("0x0050832c", "cm848_updateEngineProtectionRestartSeverityIndexes",
     "Sets the channel's restart severity indexes: with configuration flag 0x1 the fueling one is 0 while the input is "
     "inside its threshold, else 0x100 (flag 0x40) or the input interpolated between the minimum and maximum "
     "thresholds; with flag 0x2 the engine speed one is 0 or 0x100"),
    ("0x00508408", "cm848_checkEngineProtectionRestartLimitation",
     "Channel 4 only (this build has channel 0 alone; the e2m names the restart limitation after oil pressure): once "
     "engine_protection_shutdown_count_cal reaches the limit and the channel's errors are allowed, raises the restart "
     "limitation shutdown approaching flag while the fueling duration runs, takes an override request (clears the "
     "duration, starts the override lamp), and commands the shutdown once the duration passes the shutdown warning time"),
    ("0x00508834", "cm848_countEngineProtectionShutdownTime",
     "Counts the channel's fueling (is_engine_speed 0) or engine speed shutdown time up by one (saturating at 0xFFFF); "
     "in the engine start pass it also sets the matching start warning time to the configuration's shutdown delay"),
    ("0x005084b4", "cm848_updateEngineProtectionRestartSeverity",
     "With the engine protection shutdown and restart enabled and a shutdown channel recorded, updates that channel's "
     "restart severity indexes and checks its restart limitation while its shutdown and restart enables are set "
     "(bits 130 + 4n / 131 + 4n of the algorithm enable flags); every other channel's restart indexes are 0"),
    ("0x0050802c", "cm848_countEngineProtectionOverLimitDurations",
     "Per channel, while its errors are allowed: counts the fueling duration (configuration flags 0x101) and the engine "
     "speed duration (0x402) up by one while the input is past its threshold (saturating), 0 otherwise; both are 0 "
     "while the errors are not allowed"),
    ("0x00509278", "cm848_logEngineProtectionChannelFaults",
     "Per channel: arms the errors-allowed timer (the start monitor engine speed and time), then, while the errors are "
     "allowed, treats a fueling / engine speed fault as active when the precrank error, the severity index or the "
     "shutdown time count says so, counts its elapsed time and opens its fault log entry, or closes the entry"),
    ("0x00508f64", "cm848_recordEngineProtectionFaultLogEntry",
     "For the current channel's fueling (0) or engine speed (1) fault: opens the log entry at the history's log index "
     "the first time (occurrence time = key_on_hour_meter, extreme value 0x8000 / 0x7fff, duration 0), sets the "
     "fault's detected bit, tracks the extreme value, and copies the entry into the channel state"),
    ("0x005090fc", "cm848_closeEngineProtectionFaultLogEntry",
     "For the current channel's fueling (0) or engine speed (1) fault: once the fault's active bit is set, clears the "
     "detected and active bits and, if an entry is open, writes its duration (key_on_hour_meter - occurrence time), "
     "copies it into the channel state and advances the log index % 5"),
    ("0x00507e20", "hpcr_initializeEngineProtection",
     "Initializes the engine protection module: points the fuel temperature channel's state at its input "
     "(fuel_temperature_sensor_filtered), thresholds and fault logs, resets the fault derate limits, the start "
     "sequence, the protection mode state and the sensor channel data, and sets engine_protection_task_index to 0 "
     "(it is not a sensor channel initializer)"),
]
