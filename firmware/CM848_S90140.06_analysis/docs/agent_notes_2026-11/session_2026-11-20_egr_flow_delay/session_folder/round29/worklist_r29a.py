"""Round 29 stage A (label-only): the transfer case low-range detector by N/V (engine speed / vehicle speed), named
from the Chrysler e2m blocks 8C5F (ROM calibrations) and 8C60 (RAM), which the parameter ID table maps to every
word; the code use of each word matches its record. Runs only with
algorithm_enable_flags_43_cal.transfer_case_low_range_enable and transmission_type_cal 0 (it was the
'engine_to_vehicle_speed_ratio' monitor). The 48RE side has its own low-range test
(transfer_case_low_range_ratio_threshold, output speed / vehicle speed)."""
D = "cm848_detectTransferCaseLowRange"
GLOBALS = [
    ("0x0040b546", "transfer_case_low_range_flag",
     f"1 = the transfer case is in low range by N/V: {D} sets it while the road speed is under "
     "transfer_case_low_range_maximum_vehicle_speed, the ratio change is under the launch-clear limit, no launch, the "
     "commanded throttle above transfer_case_low_range_minimum_commanded_throttle and the N/V average above "
     "transfer_case_low_range_minimum_engine_to_vehicle_speed_ratio; cleared above the speed limit or on a launch. "
     "cm848_buildPciTransmitMessage12StatusBits reports it"),
    ("0x0040b547", "transfer_case_launch_flag",
     f"1 = a launch / declutch is in progress, so the N/V is not trusted: {D} sets it at zero road speed or under "
     "transfer_case_launch_maximum_vehicle_speed with the ratio change above transfer_case_launch_minimum_ratio_change, "
     "and clears it once the change is under transfer_case_launch_clear_maximum_ratio_change or the speed is above "
     "the launch limit"),
    ("0x0040b542", "transfer_case_engine_to_vehicle_speed_ratio",
     "filtered_engine_speed x 256 / transfer_case_road_speed (rpm per mph x 256), above "
     "transfer_case_ratio_minimum_vehicle_speed; 0 below it"),
    ("0x0040b544", "transfer_case_engine_to_vehicle_speed_ratio_average",
     "transfer_case_engine_to_vehicle_speed_ratio through transfer_case_ratio_average_filter"),
    ("0x003fced6", "transfer_case_engine_to_vehicle_speed_ratio_change",
     "|average - instantaneous| x 25600 / average: the ratio's percent change x 256, before its filter"),
    ("0x0040b540", "transfer_case_engine_to_vehicle_speed_ratio_change_filtered",
     "transfer_case_engine_to_vehicle_speed_ratio_change through transfer_case_ratio_change_filter (0 under the "
     "minimum speed); the launch tests compare it"),
    ("0x0040b548", "transfer_case_road_speed",
     "vehicle_speed_unfiltered through transfer_case_road_speed_filter"),
    ("0x00408a52", "transfer_case_launch_maximum_vehicle_speed",
     "the launch test runs under this road speed, and the launch flag clears above it"),
    ("0x00408a54", "transfer_case_ratio_minimum_vehicle_speed",
     "the N/V is computed only above this road speed"),
    ("0x00408a56", "transfer_case_low_range_maximum_vehicle_speed",
     "low range is detected only under this road speed; above it the flag clears"),
    ("0x00408a5a", "transfer_case_launch_clear_maximum_ratio_change",
     "the launch flag clears when the filtered ratio change is under this (and low range needs it under this too)"),
    ("0x00408a5c", "transfer_case_launch_minimum_ratio_change",
     "the launch flag sets when the filtered ratio change is above this under the launch speed"),
    ("0x00408a60", "transfer_case_low_range_minimum_engine_to_vehicle_speed_ratio",
     "low range needs the N/V average above this"),
    ("0x00408a62", "transfer_case_low_range_minimum_commanded_throttle",
     "low range needs commanded_throttle_state.commanded_throttle above this (e2m TPS)"),
]
FUNCTIONS = [
    ("0x0051a648", D,
     "The transfer case low-range detector by N/V (e2m 8C5F / 8C60 'Tcase NV'): filters the road speed, computes engine "
     "speed / road speed and its average and percent change, keeps transfer_case_launch_flag and "
     "transfer_case_low_range_flag. Runs with algorithm_enable_flags_43_cal.transfer_case_low_range_enable, "
     "transmission_type_cal 0 and the engine running (not in this calibration)"),
    ("0x0051a5f8", "cm848_initializeTransferCaseLowRangeFilters",
     "Clears the three transfer case filters and points them at their e2m 8C5F coefficients (the N/V average, its "
     "percent change, the road speed)"),
]
