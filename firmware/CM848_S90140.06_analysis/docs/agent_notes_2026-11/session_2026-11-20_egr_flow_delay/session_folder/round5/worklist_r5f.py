"""Round 5 stage f: three more functions (bin 6's TPU leads with their plates and writes; the LSG wrapper read)."""
GLOBALS = []
FUNCTIONS = [
    ("0x00528b90", "cm848_initializeInjectionHardware",
     "(Re)initializes the injection hardware: the TPU-A injection channel set (function select / priority / host "
     "sequence of channels 2 4 5 7 and 14, interrupt enables) and the injector driver PWMs 16-19 "
     "(cm848_loadInjectorDriverCalibration); clears logical output lines 47 / 48, sets the TPU enable and restart flags "
     "and counts the restart in fuel_system_hardware_shutdown_error_count_cal"),
    ("0x00529068", "cm848_monitorFuelSystemHardwareShutdown",
     "The fuel system hardware shutdown check (e2m 8041 +28 / +2A FS_HW_Shutdown thresholds, 8C61 +0 error count): "
     "gates TPU-A channels 4 and 9 by the engine state and the standby QADC sensors, counts the events and requests "
     "the injection hardware restart"),
    ("0x00028adc", "cm848_initializeLowSpeedGovernorGainSelection",
     "Resets the aggressive gain logic and the user gain state (0) and copies low_speed_governor_default_gain_set "
     "into low_speed_governor_override_gain_set"),
]
