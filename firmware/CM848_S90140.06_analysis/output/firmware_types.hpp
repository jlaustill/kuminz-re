#pragma once
#include <stdint.h>

// Ghidra primitive type aliases
typedef uint8_t   undefined;
typedef uint8_t   undefined1;
typedef uint16_t  undefined2;
typedef uint32_t  undefined4;
typedef uint64_t  undefined8;
typedef uint64_t  ulonglong;
typedef int64_t   longlong;
typedef uint8_t   byte;
typedef uint16_t  ushort;
typedef uint32_t  uint;
typedef uint16_t  word;
typedef uint32_t  dword;
typedef int8_t    sbyte;
typedef int16_t   sword;
typedef int32_t   sdword;
typedef int64_t   sqword;
typedef int32_t   bool32;

// Ghidra CONCATxy macros — concatenate x bytes of a with y bytes of b
// e.g. CONCAT22(hi16, lo16) produces a 32-bit value
#define CONCAT11(a, b) ((uint16_t)((uint16_t)((uint8_t)(a)) << 8 | (uint16_t)((uint8_t)(b))))
#define CONCAT12(a, b) ((uint32_t)((uint32_t)((uint8_t)(a)) << 16 | (uint32_t)((uint16_t)(b))))
#define CONCAT13(a, b) ((uint32_t)((uint32_t)((uint8_t)(a)) << 24 | (uint32_t)(b) & 0xFFFFFF))
#define CONCAT14(a, b) ((uint64_t)((uint64_t)((uint8_t)(a)) << 32 | (uint64_t)((uint32_t)(b))))
#define CONCAT21(a, b) ((uint32_t)((uint32_t)((uint16_t)(a)) << 8 | (uint32_t)((uint8_t)(b))))
#define CONCAT22(a, b) ((uint32_t)((uint32_t)((uint16_t)(a)) << 16 | (uint32_t)((uint16_t)(b))))
#define CONCAT24(a, b) ((uint64_t)((uint64_t)((uint16_t)(a)) << 32 | (uint64_t)((uint32_t)(b))))
#define CONCAT31(a, b) ((uint32_t)((uint32_t)(a) << 8 | (uint32_t)((uint8_t)(b))))
#define CONCAT44(a, b) ((uint64_t)((uint64_t)((uint32_t)(a)) << 32 | (uint64_t)((uint32_t)(b))))


/* ---- Enumerations ---- */

typedef enum {
    PGN_65265_CRUISE_VEHICLE_SPEED = 0xfef1,  /* Cruise Control/Vehicle Speed (CCVS) */
    PGN_65228_DM3_CLEAR_DIAG = 0xfecc,  /* Diagnostic Message 3 - Clear Diagnostics */
    PGN_65226_DM1_ACTIVE_DTC = 0xfeca,  /* Diagnostic Message 1 - Active DTCs */
    PGN_65227_DM2_PREVIOUS_DTC = 0xfecb,  /* Diagnostic Message 2 - Previous DTCs */
    PGN_65229_DM4_FREEZE_FRAME = 0xfecd,  /* Diagnostic Message 4 - Freeze Frame */
    PGN_65230_DM5_READINESS = 0xfece,  /* Diagnostic Message 5 - Readiness */
    PGN_65234_DM11_CLEAR_ACTIVE = 0xfed2,  /* Diagnostic Message 11 - Clear Active */
    PGN_65261_CRUISE_CONTROL_SETUP = 0xfeed,  /* Cruise Control/Vehicle Speed Setup (CCSS) */
    PGN_65263_FLUID_LEVEL_PRESSURE = 0xfeef,  /* Engine Fluid Level/Pressure */
    PGN_65264_PTO = 0xfef0,  /* Power Takeoff Information */
    PGN_65269_AMBIENT_CONDITIONS = 0xfef5,  /* Ambient Conditions */
    PGN_65270_INLET_EXHAUST_CONDITIONS = 0xfef6,  /* Inlet/Exhaust Conditions 1 (IC1) */
    PGN_65271_VEHICLE_ELECTRICAL = 0xfef7,  /* Vehicle Electrical Power */
    PGN_65504_PROPRIETARY_A = 0xffe0,  /* Proprietary A Message */
    PGN_65259_COMPONENT_ID = 0xfeeb,  /* Component Identification */
    PGN_65262_ENGINE_TEMP = 0xfeee,  /* Engine Temperature */
    PGN_65242_SOFTWARE_ID = 0xfeda,  /* Software Identification */
    PGN_65248_VEHICLE_DISTANCE = 0xfee0,  /* Vehicle Distance */
    PGN_65260_VEHICLE_ID = 0xfeec,  /* Vehicle Identification */
    PGN_61443_EEC2 = 0xf003  /* Electronic Engine Controller 2 */
} J1939_PGN_LOWER;

typedef enum {
    VALID_MARKER = 0x600d,  /* EEPROM contains valid calibration data */
    NEEDS_PROGRAMMING = 0x2b16,  /* EEPROM needs calibration programming */
    FLASH_MODE_MARKER = 0x1d0a  /* Flash programming mode marker */
} EEPROM_MAGIC;

typedef enum {
    SECURED_WRITE = 3,  /* Secured write operations (requires security check) */
    SYSTEM_CONTROL = 4,  /* System control operations */
    MEMORY_ACCESS = 5,  /* Memory read/write operations */
    SPECIAL_CONTROL = 6  /* Special timing/control functions */
} DIAG_SERVICE_ID;

typedef enum {
    COEFFICIENT_INIT = 2  /* Standard filter coefficient initialization value */
} FILTER_INIT;

typedef enum {
    PROTECTION_IDLE = 0,  /* Protection system inactive/normal operation */
    PROTECTION_LEVEL_1 = 1,  /* First protection threshold level (warning) */
    PROTECTION_LEVEL_2 = 2,  /* Second protection threshold level (derate) */
    PROTECTION_SHUTDOWN = 3,  /* Shutdown protection level */
    PROTECTION_RECOVERY = 4  /* Protection condition cleared - returning to normal */
} PROTECTION_STATE;

typedef enum {
    STATUS_SENSOR_FAULT = 0x05,  /* Sensor fault condition detected */
    STATUS_TEMP_DERATE = 0x0B,  /* Temperature derate active */
    STATUS_SHUTDOWN = 0x10,  /* Shutdown level reached */
    STATUS_LEVEL_2_ACTIVE = 0x11,  /* Level 2 protection active */
    STATUS_LEVEL_1_ACTIVE = 0x12  /* Level 1 protection active */
} PROTECTION_STATUS_CODE;

typedef enum {
    FLAG_STATE1_EXCEEDED = 0x80,  /* State 1 threshold exceeded */
    FLAG_STATE2_EXCEEDED = 0x40,  /* State 2 threshold exceeded */
    FLAG_WARNING_THRESHOLD = 0x20,  /* Warning threshold crossed */
    FLAG_DERATE_ACTIVE = 0x10,  /* Derate condition active */
    FLAG_CONDITION_CHECK = 0x08  /* Condition check flag */
} PROTECTION_FLAGS;

typedef enum {
    TRANSMISSION_SELECTED_GEAR_REVERSE = 0x7c,  /* -1: reverse (shift lever position 2, cm848_updateSelectedGearFromShiftLever) */
    TRANSMISSION_SELECTED_GEAR_NEUTRAL = 0x7d,  /* 0: neutral (lever position 3) */
    TRANSMISSION_SELECTED_GEAR_FIRST = 0x7e,  /* 1st gear */
    TRANSMISSION_SELECTED_GEAR_SECOND = 0x7f,  /* 2nd gear */
    TRANSMISSION_SELECTED_GEAR_THIRD = 0x80,  /* 3rd gear (drive while overdrive is off) */
    TRANSMISSION_SELECTED_GEAR_FOURTH = 0x81,  /* 4th gear (drive with overdrive) */
    TRANSMISSION_SELECTED_GEAR_FIFTH = 0x82,  /* 5th gear */
    TRANSMISSION_SELECTED_GEAR_PARK = 0xfb,  /* 251: park (lever position 1; J1939 SPN 524 special value) */
    TRANSMISSION_SELECTED_GEAR_ERROR = 0xfe,  /* 254: J1939 error indicator */
    TRANSMISSION_SELECTED_GEAR_NOT_AVAILABLE = 0xff  /* 255: not available (the PCI 0x37 message is invalid, or no ETC2 arrived) */
} TRANSMISSION_SELECTED_GEAR;

typedef enum {
    FUELING_STATE_NOT_SELECTED = 0,  /* Cleared at the start of every pass by cm848_resetEngineOperatingMode; the selectors then run in call order 30 then 1 then 2 then 5 then 6 then 7 then 8 and each acts only while the mode is still 0 (first wins) - e2m label NOT_SET (CHR_CC_11.45.01.07 0x00) */
    FUELING_STATE_TSC1_TORQUE_CONTROL = 1,  /* cm848_setEngineOperatingMode1: J1939 TSC1 override control mode 2 (torque); the governor output is tsc1_torque_control_fueling - e2m label JCOMTORQ (CHR_CC_11.45.01.07 0x01) */
    FUELING_STATE_TSC1_SPEED_CONTROL = 2,  /* cm848_selectTsc1SpeedControlMode: J1939 TSC1 override control mode 1 (speed); the all-speed governor PID runs on tsc1_requested_speed_capped with the ROM coefficient record - e2m label JCOMSPED (CHR_CC_11.45.01.07 0x02) */
    FUELING_STATE_POWER_TAKE_OFF = 4,  /* operating_mode_governor_output.mode_code only (cm848_selectPowerTakeOffOrUserFueling): power_take_off_governor_fuel_demand replaces the user fueling while power_take_off_governor_active_flag is 1 and algorithm_enable_flags_3_cal bit 0x10 is set (modes 5 / 6 always; 7 / 8 / 30 unless the user fuel is larger and algorithm_enable_flags_2_cal bit 0x2000 lets the throttle override). Code-proven: the governor's state goes out as J1939 SPN 976 (CCVS1) and OBD-II PID 0x1E - e2m label PTO (CHR_CC_11.45.01.07 0x04) */
    FUELING_STATE_CALIBRATED_FIXED_FUEL_DEMAND = 5,  /* cm848_selectUserCommandedFueling: bit 0 of algorithm_enable_flags_4_cal (0 in every dump) makes the governor output a calibrated fuel demand; the feature behind it is not identified - e2m label USERCOMD (CHR_CC_11.45.01.07 0x05) */
    FUELING_STATE_ACCELERATOR_PEDAL_FAULT = 6,  /* cm848_transitionEngineOperatingMode: accelerator pedal input fault conditions; cm848_calculatePedalFaultModeFuelDemandAndSpeedLimit ramps the fuel only while the mode is 6 - e2m label LIMPHOME (CHR_CC_11.45.01.07 0x06) */
    FUELING_STATE_VARIABLE_SPEED_GOVERNOR = 7,  /* cm848_selectVariableSpeedGovernorMode: variable_speed_governor_selected_flag = 1; the pedal sets a speed request and the all-speed governor PID runs (dump: 7) - e2m label ASGTHROT (CHR_CC_11.45.01.07 0x07) */
    FUELING_STATE_DUAL_AXIS_FUEL_DEMAND_TABLE = 8,  /* cm848_initEngineOperatingState: left when no other selector claimed the pass; the governor output comes from cm848_calculateDualAxisFuelLimit (engine speed x tracked fuel demand tables) - e2m label FOUR_D (CHR_CC_11.45.01.07 0x08) */
    FUELING_STATE_CRUISE_CONTROL = 9,  /* governor_fuel_demand_working_mode only (cm848_selectCruiseOrUserFueling): cruise control is engaged and the cruise PID fuel cruise_control_fueling replaces the user fueling; cm848_selectCruiseGovernorGainSet and cm848_presetCruiseAndRoadSpeedGovernor run their cruise branches (cruise_control_state set / resume / accelerate / decelerate) in 9 - e2m label CRUISE (CHR_CC_11.45.01.07 0x09) */
    FUELING_STATE_ROAD_SPEED_GOVERNOR = 10,  /* adjusted_user_fueling_state (cm848_arbitrateGovernedFueling): the road speed governor fuel road_speed_governor_fueling (cm848_calculateRoadSpeedGovernorFueling: vehicle_speed_rise_limited - the vehicle speed - against road_speed_governor_reference_speed; no limit while algorithm_enable_flags_3_cal bit 0x80 is clear) is the smallest demand; cm848_presetCruiseAndRoadSpeedGovernor runs the limit-minus-speed error in 10 - e2m label RSG (CHR_CC_11.45.01.07 0x0A) (was FUELING_STATE_VEHICLE_SPEED_LIMIT) */
    FUELING_STATE_LOW_SPEED_GOVERNOR = 11,  /* adjusted_user_fueling_state (cm848_arbitrateGovernedFueling and the initial value of cm848_initFuelFilterCoefficients): at or below the governor speed the low speed governor asks for more fuel than the selected demand (a max select); only in 11 does cm848_runLowSpeedGovernor write its fuel into adjusted_user_fueling (e2m FSGVFL: fueling as limited by limiting governors LSG / HSG) and low_speed_governor_active_flag latch. RAM dump: 11 - e2m label LSG (CHR_CC_11.45.01.07 0x0B) */
    FUELING_STATE_HIGH_SPEED_GOVERNOR = 12,  /* adjusted_user_fueling_state (cm848_arbitrateGovernedFueling): high_speed_governor_fueling is the smallest demand and becomes adjusted_user_fueling; runHighSpeedGovernorPid resets its integrator in 12 (the same compare as CM550 0x1ce7c on FSGVFLST) - e2m label HSG (CHR_CC_11.45.01.07 0x0C) */
    FUELING_STATE_TORQUE_DERATE_OVERRIDE = 13,  /* torque_derate_fuel_source_code (cm848_arbitrateRequestedFueling): while algorithm_enable_flags_1_cal bit 0x10 is set the EEPROM limit torque_derate_override_fuel_quantity_cal (EEPROM 0x380) replaces the whole derate chain. Off in the dump: the flags are 0x1020 and the limit is 5888 - e2m label TRQDROVR (CHR_CC_11.45.01.07 0x0D) */
    FUELING_STATE_ALTITUDE_DERATE = 15,  /* torque_derate_fuel_source_code (cm848_applyAltitudeDerateFuelLimit): altitude_derate_fuel_limit - the engine speed x barometric pressure grids for cool / hot ambient air blended by ambient air temperature (or the air handling fault grid while an enabled boost / intake manifold pressure / barometric / intake air or ambient air temperature / wastegate fault is set); cm848_calculateAltitudeDerateFuelLimit - e2m label ALTDERAT (CHR_CC_11.45.01.07 0x0F) */
    FUELING_STATE_AIR_FUEL_CONTROL_DERATE = 16,  /* fuel_demand_minimum_tracked_state (cm848_applyAirFuelControlFuelLimit): air_fuel_control_fuel_limit - the engine speed x boost pressure grid air_fuel_control_fuel_limit_grid blended toward air_fuel_control_low_boost_fuel_limit_grid (cm848_calculateAirFuelControlFuelLimit). RAM dump: 16 (no boost at key on) - e2m label AFCDERAT (CHR_CC_11.45.01.07 0x10) */
    FUELING_STATE_MAXIMUM_THROTTLE = 19,  /* torque_derate_fuel_source_code starting value (cm848_initializeFuelLimitChains): throttle_100_fueling - cm848_calculateMaximumFuelCurve(engine speed / 400) is the fuel at full accelerator (400 = 100 %) - before any derate source takes over - e2m label MAXTHROT (CHR_CC_11.45.01.07 0x13) */
    FUELING_STATE_TSC1_TORQUE_LIMIT = 20,  /* torque_derate_fuel_source_code (cm848_applyTsc1TorqueLimit): J1939 TSC1 override control mode 3 with tsc1_torque_limit_fueling below the running derate - e2m label JCTRQDER (CHR_CC_11.45.01.07 0x14) */
    FUELING_STATE_CRANKING = 22,  /* final_fueling_state (cm848_selectFinalFueling): engine_state CRANKING / JUMP_START (or REENTRY with the command below it) - the fuel is crank_fuel - e2m label CRANK (CHR_CC_11.45.01.07 0x16) */
    FUELING_STATE_FUEL_OVERRIDE = 23,  /* final_fueling_state while algorithm_enable_flags_1_cal bit 2 is set (user_override_fueling_cal) and injection_quantity_combustion_reference_source_code while algorithm_enable_flags_5_cal bit 9 is set (injection_quantity_combustion_reference_override_value) - e2m label OVERRIDE (CHR_CC_11.45.01.07 0x17) */
    FUELING_STATE_ENGINE_BRAKE = 24,  /* final_fueling_state (cm848_selectFinalFueling): engine_state ENGINE_BRAKE - the fuel is the ROM word 0x5c308 (0 here) - e2m label ENGBRAKE (CHR_CC_11.45.01.07 0x18) */
    FUELING_STATE_OVERSPEED = 25,  /* final_fueling_state (cm848_selectFinalFueling): engine_state OVERSPEED - the fuel is the ROM word 0x5c30a (0 here) - e2m label OVERSPED (CHR_CC_11.45.01.07 0x19) */
    FUELING_STATE_ENGINE_STOPPED = 26,  /* final_fueling_state (cm848_selectFinalFueling): engine_state 1 - the final fuel is 0. RAM dump (key on / engine stopped): 26 with engine_state 1 - e2m label STOP (CHR_CC_11.45.01.07 0x1A) */
    FUELING_STATE_SHUTDOWN = 27,  /* final_fueling_state (cm848_selectFinalFueling): engine_state SHUTDOWN - the fuel is fuel_demand_minimum (0 here) - e2m label SHUTDOWN (CHR_CC_11.45.01.07 0x1B) */
    FUELING_STATE_FUEL_SYSTEM_DERATE = 28,  /* torque_derate_fuel_source_code (cm848_applyFuelPressureFaultFuelLimit): fuel_pressure_fault_fuel_limit_working from cm848_applyFuelLimitsForFuelPressureFaults (rail pressure faults) - e2m block 105D +4 FSAPLMFL fuel system specific fuel derate - e2m label FSSDERAT (CHR_CC_11.45.01.07 0x1C) */
    FUELING_STATE_FAULT_DERATE = 29,  /* torque_derate_fuel_source_code (cm848_applyFaultDerateFuelLimit): fault_derate_fuel_limit from cm848_calculateFaultDerateFuelLimit - e2m label EPFDERAT (CHR_CC_11.45.01.07 0x1D) */
    FUELING_STATE_ALL_SPEED_GOVERNOR_APPLICATION = 30,  /* cm848_selectAllSpeedGovernorApplicationMode: all_speed_governor_application_override_mode nonzero; loads the application-specific record 0x40a216-0x40a246 (e2m 1170 +C..+3C ASG_*_As; never set in this build and RAM is zeroed at every start) - e2m label ASG_APPL (CHR_CC_11.45.01.07 0x1E) (was FUELING_STATE_ALL_SPEED_GOVERNOR_RESTORE) */
    FUELING_STATE_MASTER_SLAVE_OVERRIDE = 32,  /* final_fueling_state / fuel_demand_arbitrated_state: master_slave_override_enable_flag set without master_slave_control_flag - the fuel is master_slave_final_override_fueling. e2m MSOVRIDE with [MSODEN] Enable overriding slave Final_Fueling / Final_Timing: one ECM overrides another's final fueling. Nothing stores either word (both only lhz; 0 in the RAM dump): not fitted on this single-ECM truck - e2m label MSOVRIDE (CHR_CC_11.45.01.07 0x20) */
    FUELING_STATE_POWER_TAKE_OFF_DERATE = 34,  /* torque_derate_torque_limit_state (cm848_applyPowerTakeOffTorqueLimit): power_take_off_maximum_torque_cal lowers torque_derate_torque_limit while power_take_off_governor_active_flag is 1 - e2m label PTODERAT (CHR_CC_11.45.01.07 0x22) */
    FUELING_STATE_UNIDENTIFIED_37 = 37,  /* only compared (engine_operating_mode / operating_mode_governor_output.mode_code / cruise_governor_fueling_state_previous - next to the TSC1 modes 1 / 2) - never stored in this build. The e2m T2 family has high gear / low gear / neutral / shift / lockout / lamp drivers: probably a two-speed axle or transfer case shift controller (not proved) - e2m label T2SPD (CHR_CC_11.45.01.07 0x25) */
    FUELING_STATE_UNIDENTIFIED_38 = 38,  /* only compared (engine_operating_mode / operating_mode_governor_output.mode_code / cruise_governor_fueling_state_previous - next to the TSC1 modes 1 / 2) - never stored in this build; see 37 for the T2 family - e2m label T2TORQ (CHR_CC_11.45.01.07 0x26) */
    FUELING_STATE_NO_DERATE = 40,  /* torque_derate_torque_limit_state default (cm848_arbitrateRequestedFueling) and the starting value of fuel_demand_minimum_tracked_state (cm848_initializeFuelLimitChains) - e2m label NODERAT (CHR_CC_11.45.01.07 0x28) */
    FUELING_STATE_IMMOBILIZER_FUEL_DISABLE = 41,  /* final_fueling_state (cm848_selectFinalFueling): immobilizer_fuel_disable_flag is 1 - the final fuel is 0 - e2m label ATDERAT (CHR_CC_11.45.01.07 0x29) */
    FUELING_STATE_FUEL_LIMIT_BY_RPM_AND_DEMAND = 42,  /* torque_derate_fuel_source_code (cm848_applyFuelLimitByRpmAndDemand): fuel_limit_by_rpm_and_demand - the alpha / chi blend of the engine speed x accelerator demand grids - computed only in the variable speed governor (engine_operating_mode 7) while algorithm_enable_flags_31_cal bit 0 is set - e2m label PTTHLM (CHR_CC_11.45.01.07 0x2A) */
    FUELING_STATE_TORQUE_MANAGEMENT = 45,  /* torque_derate_fuel_source_code (cm848_applyTorqueManagementFuelLimit): torque_management_fuel_limit - e2m label TORQMGMT (CHR_CC_11.45.01.07 0x2D) */
    FUELING_STATE_COOLANT_OVERHEAT_DERATE = 46,  /* torque_derate_fuel_source_code (cm848_applyCoolantOverheatFuelDerate): coolant_overheat_fuel_derate - the ramped smaller of the PI limit on the coolant temperature error and the engine speed limit of the coolant temperature buckets (cm848_runCoolantOverheatFuelDerate; enabled by algorithm_enable_flags_40_cal bit 1) - e2m label CTDERAT (CHR_CC_11.45.01.07 0x2E) */
    FUELING_STATE_FREE_ACCELERATION = 47,  /* only compared (final_fueling_state) - never stored in this build - e2m label FREEACCL (CHR_CC_11.45.01.07 0x2F) */
    FUELING_STATE_UNIDENTIFIED_49 = 49,  /* only compared (final_fueling_state) - never stored in this build. OFC is the combustion reference's oxygen-fuel control (e2m CBR_OFC_*; code 58 OFCDERAT is its derate) - e2m label OFCSTATE (CHR_CC_11.45.01.07 0x31) */
    FUELING_STATE_UNIDENTIFIED_50 = 50,  /* only compared (final_fueling_state) - never stored in this build. AFR is the air-fuel ratio (e2m CBO_Air_Fuel_Ratio_Ref / CBP_Air_Fuel_Ratio) - e2m label AFRSTATE (CHR_CC_11.45.01.07 0x32) */
    FUELING_STATE_COMBUSTION_DENSITY_MAXIMUM = 52,  /* injection_quantity_combustion_gross_source_code (cm848_calculateCombustionGrossFuel): the density maximum (engine speed x compressor_inlet_density) limits the gross fuel - e2m label AIRDENLM (CHR_CC_11.45.01.07 0x34) */
    FUELING_STATE_COMBUSTION_CHI_MAXIMUM = 53,  /* injection_quantity_combustion_gross_source_code (cm848_calculateCombustionGrossFuel): the chi maximum fuel limits the gross fuel - e2m label CHIFULLM (CHR_CC_11.45.01.07 0x35) */
    FUELING_STATE_COMBUSTION_TEMPERATURE_HEADROOM = 54,  /* injection_quantity_combustion_reference_source_code (cm848_calculateCombustionFuelReference): injection_quantity_temperature_headroom_cap - e2m label TFCDERAT (CHR_CC_11.45.01.07 0x36) */
    FUELING_STATE_COMBUSTION_GROSS_FUEL_OVERRIDE = 55,  /* injection_quantity_combustion_gross_source_code: algorithm_enable_flags_5_cal bit 10 - injection_quantity_combustion_gross_override_value - e2m label GROSSOVR (CHR_CC_11.45.01.07 0x37) */
    FUELING_STATE_COMBUSTION_OXYGEN_LIMIT = 58,  /* injection_quantity_combustion_reference_source_code (cm848_calculateCombustionFuelReference): injection_quantity_oxygen_limit - e2m label OFCDERAT (CHR_CC_11.45.01.07 0x3A) */
    FUELING_STATE_NET_TORQUE = 59,  /* fuel_demand_minimum_tracked_state (cm848_applyNetTorqueFuelLimit): net_torque_fuel_limit - a rate-limited engine speed fuel curve from the alpha / chi map blend of net_torque_fuel_limit_grid (cm848_calculateNetTorqueFuelLimit) while algorithm_enable_flags_13_cal bit 2 is set - e2m label NETTORQ (CHR_CC_11.45.01.07 0x3B) */
    FUELING_STATE_RAIL_PRESSURE_SHORTFALL_LIMIT = 61,  /* torque_derate_fuel_source_code (cm848_limitFuelQuantityOnRailPressureShortfall) - e2m label LOFPRDER (CHR_CC_11.45.01.07 0x3D) */
    FUELING_STATE_FUEL_PRESSURE_GOVERNOR_FAULT_BLEND = 62  /* torque_derate_fuel_source_code (cm848_applyFuelPressureGovernorFaultBlend while safety_system_enable_cal is set): injection_quantity_combustion_chi_maximum - blended toward an engine speed table limit while fault 57 / 58 / 60 (P1221 / P1222 / P1223 - the fuel pressure governor plausibility checks) or 59 is set. RAM dump: 62 */
} FUELING_STATE;

typedef enum {
    SPN_51_THROTTLE_PLATE = 51,  /* Throttle Plate Position Sensor */
    SPN_84_VEHICLE_SPEED = 84,  /* Vehicle Speed Signal */
    SPN_89_PTO_SPEED = 89,  /* PTO Speed Switch */
    SPN_91_ACCEL_PEDAL = 91,  /* Accelerator Pedal Position */
    SPN_93_TORQUE_CURVE = 93,  /* Torque Curve Switch */
    SPN_95_FUEL_FILTER = 95,  /* Fuel Filter Restriction Switch */
    SPN_100_OIL_PRESSURE = 100,  /* Engine Oil Pressure */
    SPN_101_BLOWBY = 101,  /* Engine Blowby */
    SPN_102_BOOST_PRESSURE = 102,  /* Boost Pressure */
    SPN_105_INTAKE_TEMP = 105,  /* Intake Manifold Temperature */
    SPN_108_AMBIENT_PRESS = 108,  /* Barometric/Ambient Air Pressure */
    SPN_109_COOLANT_PRESS = 109,  /* Engine Coolant Pressure */
    SPN_110_COOLANT_TEMP = 110,  /* Engine Coolant Temperature */
    SPN_111_COOLANT_LEVEL = 111,  /* Engine Coolant Level */
    SPN_113_DROOP_SWITCH = 113,  /* Alternate Droop Switch */
    SPN_121_ENGINE_BRAKE = 121,  /* Engine Brake Circuit */
    SPN_157_FUEL_PRESS = 157,  /* Fuel Pressure */
    SPN_168_BATTERY_VOLT = 168,  /* Battery Voltage */
    SPN_174_FUEL_TEMP = 174,  /* Fuel Temperature Sensor */
    SPN_175_OIL_TEMP = 175,  /* Engine Oil Temperature */
    SPN_177_TRANS_TEMP = 177,  /* Transmission Temperature */
    SPN_183_GAS_MASS = 183,  /* Gas Mass Sensor */
    SPN_190_ENGINE_SPEED = 190,  /* Engine Speed */
    SPN_608_J1587 = 608,  /* J1587 Protocol */
    SPN_609_MODULE_ID = 609,  /* Module ID */
    SPN_620_SENSOR_SUPPLY = 620,  /* Sensor Supply Voltage */
    SPN_627_POWER_OFF = 627,  /* Power Off Without Ignition */
    SPN_629_ECM_INTERNAL = 629,  /* ECM Internal */
    SPN_630_CHECKSUM = 630,  /* ECM Checksum */
    SPN_632_FUEL_SHUTOFF = 632,  /* Fuel Shutoff Valve */
    SPN_633_FUEL_CONTROL = 633,  /* Fuel Control Valve */
    SPN_639_J1939 = 639,  /* J1939 Network */
    SPN_646_WASTEGATE = 646,  /* Wastegate Control Valve */
    SPN_735_CYL2_CIRCUIT = 735,  /* Cylinder 2 Circuit */
    SPN_737_CYL4_CIRCUIT = 737,  /* Cylinder 4 Circuit */
    SPN_738_CYL5_CIRCUIT = 738,  /* Cylinder 5 Circuit */
    SPN_1195_ANTI_THEFT = 1195  /* Anti-Theft System */
} J1939_SPN;

typedef enum {
    FAULT_0111_SPN_629 = 111,  /* ECM Internal Failure */
    FAULT_0115_SPN_190 = 115,  /* BOTH ENGINE SPEED AND OR POSITION SIGNALS LOST (RED) */
    FAULT_0121_SPN_190 = 121,  /* ONE ENGINE SPEED AND OR POSIION SIGNAL LOST. INTERMITTENT (YELLOW) */
    FAULT_0122_SPN_102 = 122,  /* BOOST PRESS */
    FAULT_0123_SPN_102 = 123,  /* BOOST PRESS */
    FAULT_0125_SPN_102 = 125,  /* BOOST PRESS */
    FAULT_0131_SPN_91 = 131,  /* ACCELERATOR PEDAL POSITIONS SHORTED HIGH (RED) */
    FAULT_0132_SPN_91 = 132,  /* ACCELERATOR PEDAL POSITIONS SHORTED LOW (RED) */
    FAULT_0133_SPN_91 = 133,  /* REMOTE THROTTLE SHORTED HIGH (RED) */
    FAULT_0134_SPN_91 = 134,  /* REMOTE THROTTLE SHORTED LOW (RED) */
    FAULT_0135_SPN_100 = 135,  /* OIL PRESSURE SHORTED HIGH (YELLOW) */
    FAULT_0141_SPN_100 = 141,  /* OIL PRESSURE SHORTED LOW (YELLOW) */
    FAULT_0143_SPN_100 = 143,  /* OIL PRESSURE DATA BELOW NORMAL RANGE (PROTECTION) */
    FAULT_0144_SPN_110 = 144,  /* ENGINE COOLANT TEMPERATURE SHORTED HIGH (YELLOW) */
    FAULT_0145_SPN_110 = 145,  /* ENGINE COOLANT TEMPERATURE SHORTED LOW (YELLOW) */
    FAULT_0147_SPN_091 = 147,  /* Frequency Throttle Signal Low OOR (RED) */
    FAULT_0148_SPN_091 = 148,  /* Frequency Throttle Signal High OOR (RED) */
    FAULT_0151_SPN_110 = 151,  /* ENGINE COOLANT TEMPERATURE DATA ABOVE NORMAL RANGE (PROTECTION) */
    FAULT_0152_SPN_110 = 152,  /* ENGINE COOLANT TEMPERATURE DATA BELOW NORMAL RANGE (PROTECTION) */
    FAULT_0153_SPN_105 = 153,  /* INTAKE MANIFOLD TEMP */
    FAULT_0154_SPN_105 = 154,  /* INTAKE MANIFOLD TEMP */
    FAULT_0155_SPN_105 = 155,  /* INTAKE MANIFOLD TEMP */
    FAULT_0184_SPN_609 = 184,  /* Module ID Input State Error for Master/Slave (RED) */
    FAULT_0185_SPN_639 = 185,  /* Engine Controller Communication Lost Error for Master/Slave (YELLOW) */
    FAULT_0212_SPN_175 = 212,  /* OIL TEMPERATURE SHORTED HIGH (YELLOW) */
    FAULT_0213_SPN_175 = 213,  /* OIL TEMPERATURE SHORTED LOW (YELLOW) */
    FAULT_0214_SPN_175 = 214,  /* OIL TEMPERATURE DATA ABOVE NORMAL RANGE (PROTECTION) */
    FAULT_0221_SPN_108 = 221,  /* AMBIENT AIR PRESSURE SHORTED HIGH (YELLOW) */
    FAULT_0222_SPN_108 = 222,  /* AMBIENT AIR PRESSURE SHORTED LOW (YELLOW) */
    FAULT_0231_SPN_109 = 231,  /* ENGINE COOLANT PRESSURE SHORTED HIGH (YELLOW) */
    FAULT_0232_SPN_109 = 232,  /* ENGINE COOLANT PRESSURE SHORTED LOW (YELLOW) */
    FAULT_0234_SPN_190 = 234,  /* ENGINE SPEED DATA ABOVE NORMAL RANGE (RED) */
    FAULT_0235_SPN_111 = 235,  /* ENGINE COOLANT LEVEL DATA BELOW NORMAL RANGE (PROTECTION) */
    FAULT_0241_SPN_084 = 241,  /* VEHICLE SPEED SIGNAL LOST (YELLOW) */
    FAULT_0242_SPN_084 = 242,  /* VEHICLE SPEED SIGNAL INTERMITTENT TAMPERING (YELLOW) */
    FAULT_0243_SPN_121 = 243,  /* ENGINE BRAKE CIRCUIT FAILURE (YELLOW) */
    FAULT_0254_SPN_632 = 254,  /* FUEL SHUTOFF VALVE SHORTED LOW (RED) */
    FAULT_0263_SPN_174 = 263,  /* FUEL TEMP SENSOR - COMPONENT SHORTED HIGH (YELLOW) */
    FAULT_0265_SPN_174 = 265,  /* Fuel Temperature - Component Shorted Low (YELLOW) */
    FAULT_0269_SPN_1195 = 269,  /* ANTI_THEFT START ATTEMPT WHILE LOCKED (INFO) */
    FAULT_0312_SPN_738 = 312,  /* CYL 5 CIRCUIT - CURRENT ABOVE NORMAL (YELLOW) */
    FAULT_0315_SPN_735 = 315,  /* CYL 2 CIRCUIT - CURRENT ABOVE NORMAL (YELLOW) */
    FAULT_0331_SPN_735 = 331,  /* CYL 2 CIRCUIT - LOW CURRENT OR OPEN CIRCUIT (YELLOW) */
    FAULT_0332_SPN_737 = 332,  /* CYL 4 CIRCUIT - LOW CURRENT OR OPEN CIRCUIT (YELLOW) */
    FAULT_0333_SPN_629 = 333,  /* NO VOLTAGE ON ONE OR MORE OF INJECTOR SUPPLY (YELLOW) */
    FAULT_0334_SPN_110 = 334,  /* ENGINE COOLANT TEMPERATURE IN RANGE FAILURE (YELLOW) */
    FAULT_0343_SPN_629 = 343,  /* ECM HARDWARE FAILURE */
    FAULT_0345_SPN_095 = 345,  /* FUEL FILTER RESTRICTION SWITCH INVALID (YELLOW) */
    FAULT_0346_SPN_630 = 346,  /* ECM SOFTWARE - READ/WRITE CHECKSUM NONMISSION DISABLING (YELLOW) */
    FAULT_0351_SPN_629 = 351,  /* INJECTOR POWER SUPPLY BAD DEVICE (YELLOW) */
    FAULT_0352_SPN_620 = 352,  /* SENSOR SUPPLY VOLTAGE BELOW NORMAL (YELLOW) */
    FAULT_0412_SPN_608 = 412,  /* J1587 DATA LINK CANNOT TRANSMIT (YELLOW) */
    FAULT_0414_SPN_608 = 414,  /* J1587 DATA LINK NOT FAST ENOUGH (YELLOW) */
    FAULT_0415_SPN_100 = 415,  /* Very Low Oil Pressure Fault (PROTECTION) */
    FAULT_0421_SPN_175 = 421,  /* OIL TEMPERATURE ABOVE NORMAL ENGINE RANG (YELLOW) */
    FAULT_0422_SPN_111 = 422,  /* ENGINE COOLANT LEVEL SIGNAL DATA INVALID (YELLOW) */
    FAULT_0425_SPN_175 = 425,  /* OIL TEMPERATURE IN RANGE FAILURE (YELLOW) */
    FAULT_0426_SPN_639 = 426,  /* DATALINK (J1939) CANNOT TRANSMIT (YELLOW) */
    FAULT_0427_SPN_639 = 427,  /* DATALINK (J1939) NOT FAST ENOUGH (YELLOW) */
    FAULT_0431_SPN_91 = 431,  /* ACCELERATOR PEDAL IDLE VALIDATION INVALID (YELLOW) */
    FAULT_0432_SPN_91 = 432,  /* ACCELERATOR PEDAL IDLE VALIDATION - SWITCH DOES NOT AGREE WITH POT (RED) */
    FAULT_0433_SPN_102 = 433,  /* BOOST PRESS */
    FAULT_0434_SPN_627 = 434,  /* Power Off Without Ignition Off (YELLOW) */
    FAULT_0435_SPN_100 = 435,  /* OIL PRESSURE IN RANGE FAILURE (YELLOW) */
    FAULT_0441_SPN_168 = 441,  /* BATTERY VOLTAGE DATA BELOW NORMAL RANGE (YELLOW) */
    FAULT_0442_SPN_168 = 442,  /* BATTERY VOLTAGE DATA ABOVE NORMAL ENGINE RANGE (YELLOW) */
    FAULT_0443_SPN_629 = 443,  /* ACCELERATOR PEDAL SENSOR SUPPLY VOLTAGE DATA BELOW NORMAL (YELLOW) */
    FAULT_0444_SPN_629 = 444,  /* OEM SENSOR SUPPLLY VOLTAGE DATA BELOW NORMAL RANGE (YELLOW) */
    FAULT_0445_SPN_629 = 445,  /* OEM SWITCH SUPPLY SHORTED HIGH (YELLOW) */
    FAULT_0451_SPN_157 = 451,  /* Fuel pressure component shorted high (RED) */
    FAULT_0452_SPN_157 = 452,  /* Fuel pressure component shorted low (RED) */
    FAULT_0453_SPN_183 = 453,  /* GAS MASS SENSOR SHORTED HIGH (YELLOW) */
    FAULT_0454_SPN_183 = 454,  /* GAS MASS SENSOR SHORTED LOW (YELLOW) */
    FAULT_0455_SPN_633 = 455,  /* Fuel control valve -- component shorted high or open (RED) */
    FAULT_0511_SPN_633 = 511,  /* Fuel control valve component shorted low (INFO) */
    FAULT_0512_SPN_051 = 512,  /* THROTTLE PLATE POSITION SENSOR SHORTED HIGH (YELLOW) */
    FAULT_0513_SPN_051 = 513,  /* THROTTLE PLATE POSITION SENSOR SHORTED LOW (YELLOW) */
    FAULT_0514_SPN_633 = 514,  /* Fuel control valve mechanically stuck open (RED) */
    FAULT_0521_SPN_177 = 521,  /* AUX (TRANSMISSION) TEMPERATURE SHORTED HIGH (YELLOW) */
    FAULT_0522_SPN_177 = 522,  /* AUX (TRANSMISSION) TEMPERATURE SHORTED LOW (YELLOW) */
    FAULT_0523_SPN_089 = 523,  /* OEM - INTERMEDIATE (PTO) SPEED SWITCH VALIDATION FAULT (YELLOW) */
    FAULT_0524_SPN_113 = 524,  /* OEM - Alternate droop switch validation fault (YELLOW) */
    FAULT_0528_SPN_93 = 528,  /* OEM Torque Curve Switch Validation Fault (YELLOW) */
    FAULT_0545_SPN_646 = 545,  /* WASTEGATE CONTROL VALVE MECH. STUCK OPEN (RED) */
    FAULT_0551_SPN_91 = 551,  /* ACCELERATOR PEDAL IDLE VALIDATION BOTH SHORTED LOW (RED) */
    FAULT_0553_SPN_157 = 553,  /* Engine fueling pressure exceeded - data above normal range (RED) */
    FAULT_0554_SPN_157 = 554,  /* Fuel rail pressure in range error (YELLOW) */
    FAULT_0555_SPN_101 = 555,  /* ENGINE BLOWBY DATA ABOVE NORMAL ENGINE RANGE (PROTECTION) */
    FAULT_0753_SPN_190 = 753  /* CAM SHAFT GEAR OUT OF SYNCH (YELLOW) */
} J1939_FAULT_CODE;

typedef enum {
    HANDLER_DIAGNOSTIC_CALLBACK = 0xdd00,  /* Diagnostic callback handler */
    HANDLER_GOVERNOR_CONTROL = 0xdf00,  /* Governor control message (proprietary) */
    HANDLER_DM1_REQUEST = 0xe300,  /* DM1 active fault request handler */
    HANDLER_DIAGNOSTIC_SERVICE = 0xef00,  /* Diagnostic service handler (DM14) */
    HANDLER_ETC1 = 0xf002,  /* Electronic Transmission Controller 1 (ETC1 PGN 61442) */
    HANDLER_ENGINE_CONTROLLER = 0xf005  /* Engine Controller message */
} J1939_HANDLER_TYPE;

typedef enum {
    EVENT_FUEL_EFFICIENCY_DERATE = 0x0b,  /* Fuel efficiency protection derate */
    EVENT_TEMP_TRIM_RESET_C = 0x0c,  /* Temperature trim reset state C (init with 0x0b-0x0f in initProtectionEventStates) */
    EVENT_TEMP_TRIM_RESET_D = 0x0d,  /* Temperature trim reset state D (init with 0x0b-0x0f in initProtectionEventStates) */
    EVENT_TEMP_TRIM_RESET_E = 0x0e,  /* Temperature trim reset state E (init with 0x0b-0x0f in initProtectionEventStates) */
    EVENT_TEMP_TRIM_RESET_F = 0x0f,  /* Temperature trim reset state F (init with 0x0b-0x0f in initProtectionEventStates) */
    EVENT_SHUTDOWN = 0x10,  /* Shutdown protection event */
    EVENT_LEVEL1_ACTIVE = 0x12,  /* Level 1 protection triggered */
    EVENT_LOAD_DERATE_PHASE_A = 0x13,  /* Engine load derate phase A - duty cycle based on protection timer counter */
    EVENT_LOAD_DERATE_PHASE_B = 0x14,  /* Engine load derate phase B - duty cycle based on protection timer counter */
    EVENT_LOAD_DERATE_FULL = 0x15,  /* Engine load full derate - triggered when protection_derate_factor = -25600 (-100%) */
    EVENT_LEVEL2_ACTIVE = 0x3f,  /* Level 2 protection triggered - checkProtectionModeFlags when mode_flags bit 2 clear */
    EVENT_SENSOR_FAULT_ACTIVE = 0x43,  /* Sensor fault condition active - updateFaultConditionState debounced sensor_fault_detect_flags */
    EVENT_DIAG_CONDITION_ACTIVE = 0x48  /* Diagnostic condition active - processFaultConditionFlags based on diagnostic_condition_flags */
} PROTECTION_EVENT;

typedef enum {
    MODE_IDLE = 0x01,  /* Idle/inactive mode */
    MODE_PROTECTION_ACTIVE = 0x02,  /* Protection system active */
    MODE_FUEL_RATE_1 = 0x0b,  /* Fuel rate calculation mode 1 */
    MODE_PROTECTION_WITH_LIMIT = 0x0c,  /* Protection with limit source active */
    MODE_OIL_PRESSURE_TIMING = 0x10,  /* Oil pressure timing adjustment active */
    MODE_EXTENDED_PROTECTION = 0x13,  /* Extended protection mode */
    MODE_CRANK_INITIAL = 0x14,  /* Initial cranking mode */
    MODE_CRANK_START = 0x16,  /* Crank/start fuel mode */
    MODE_FUEL_CONTROL_ENABLED = 0x17,  /* Fuel control system enabled */
    MODE_FUEL_DEMAND_STATE_4 = 0x18,  /* Fuel demand accumulator state 4 */
    MODE_FUEL_DEMAND_STATE_5 = 0x19,  /* Fuel demand accumulator state 5 */
    MODE_FUEL_DEMAND_STATE_1 = 0x1a,  /* Fuel demand accumulator state 1 */
    MODE_FUEL_DEMAND_STATE_8 = 0x1b,  /* Fuel demand accumulator state 8 */
    MODE_OVERRIDE = 0x20,  /* Diagnostic override mode */
    MODE_FUEL_CONTROL_BITS = 0x29,  /* Fuel control bits active */
    MODE_PROTECTION_2 = 0x2d,  /* Protection mode variant 2 */
    MODE_EXTENDED_TIMING = 0x31,  /* Extended timing adjustment mode */
    MODE_PROTECTION_3 = 0x3a  /* Protection mode variant 3 */
} FUEL_TIMING_MODE;

typedef enum {
    CRANKING_RPM_LIMIT = 125,  /* Cold crank sync determination limit */
    RUNNING_RPM_THRESHOLD = 300,  /* Engine considered running threshold */
    PTO_MIN_RPM = 700,  /* PTO minimum RPM setpoint */
    PTO_MAX_RPM = 3000,  /* PTO maximum RPM setpoint */
    ASG_MAX_RPM = 3000  /* ASG maximum allowed speed */
} ENGINE_RPM_LIMITS;

typedef enum {
    DERATE_ACTIVE = 0x80,  /* Derate condition is active */
    DERATE_BIT6 = 0x40,  /* Derate status bit 6 - maps to INSITE bit 0x40 */
    DERATE_BIT5 = 0x20,  /* Derate status bit 5 - maps to INSITE bit 0x20 */
    DERATE_STATUS_BIT3 = 0x08,  /* Derate status bit 3 - maps to INSITE status 0x20 */
    DERATE_STATUS_BIT2 = 0x04  /* Derate status bit 2 - maps to INSITE status 0x40 */
} DERATE_STATUS_BITS;

typedef enum {
    SUCCESS = 0,  /* Operation successful */
    DIAG_INVALID_LENGTH = 2,  /* Invalid message length */
    SECURITY_FAILED = 3,  /* Security check failed */
    BUFFER_OVERFLOW = 4,  /* Buffer overflow or unsupported */
    ADDR_VALIDATION_FAIL = 8,  /* Address validation failed */
    INVALID_ADDR_RANGE = 9,  /* Invalid address range */
    INVALID_ADDR_ALT = 10,  /* Invalid address range (alternate) */
    CHECKSUM_MISMATCH = 0x14,  /* Checksum mismatch */
    UNKNOWN_SUBFUNC = 0x18  /* Unknown sub-function - default error */
} DIAG_RESPONSE_CODE;

typedef enum {
    RESET_MODE = 0,  /* Reset/clear arbitrator state */
    RPM_TARGET_MODE = 1,  /* Set RPM target mode */
    THROTTLE_PCT_MODE = 2,  /* Throttle percentage control mode */
    FUEL_LIMIT_MODE = 3  /* Fuel limit control mode */
} FUEL_ARB_MODE;

typedef enum {
    DIRECT_ACCESS = 0x00,  /* READ: Allowed | WRITE: Direct access no security check */
    SECURITY_REQUIRED = 0x03,  /* READ: Allowed | WRITE: Requires security check or bypass */
    WRITE_DENIED = 0x04,  /* READ: Allowed | WRITE: Denied - returns error 0x0A */
    LOGGING_MODE = 0x05,  /* READ: Allowed | WRITE: Requires system_logging_state check */
    RANGE_INVALID = 0x09,  /* READ: Denied | WRITE: Error - address not in validation table */
    ACCESS_DENIED = 0x0A  /* READ: Denied | WRITE: Error - explicitly blocked region */
} MEMORY_ACCESS_FLAG;

typedef enum {
    CORE_SERVICES = 0x01,  /* Enable core diagnostic services (secured memory ops) */
    INSITE_LIVE = 0x02,  /* Enable Insite live data monitoring */
    EXTENDED_SERVICES = 0x04,  /* Enable extended diagnostic services */
    SPECIAL_MODE = 0x08  /* Special diagnostic mode enabled */
} DIAG_ENABLE_FLAGS;

typedef enum {
    DTC_STATUS_FLAGS = 0x02,  /* DTC search result status flags */
    DERATE_STATUS = 0x03,  /* Derate status byte bit flags */
    HIGH_RPM_PROTECTION_STATUS = 0x47,  /* High RPM protection status flags */
    BOOST_PRESSURE_TARGET = 0x4A,  /* Boost pressure target pointer (scaled >>7) */
    DIAGNOSTIC_FUEL_MODE_FLAG = 0x53,  /* Diagnostic fuel control mode flag (0x80 if mode==10) */
    THROTTLE_POSITION = 0x54,  /* Throttle position value (scaled >>7) */
    INSITE_STATUS_BYTE = 0x55,  /* Combined status byte with sensor/derate flags */
    BOOST_PRESSURE_BASE = 0x56,  /* Target boost pressure base (scaled >>7) */
    FUEL_TIMING_LIMIT = 0x57,  /* Fuel timing transition limit (scaled >>7) */
    FUEL_TIMING_DISPLAY = 0x58,  /* INSITE fuel timing display (scaled >>7) */
    OIL_PRESSURE_STATUS = 0x59,  /* Oil pressure protection status byte */
    ACTIVE_DERATE_VALUE = 0x5B,  /* Active derate value (scaled *250/400) */
    PARAM_DISPLAY_VALUE = 0x64,  /* INSITE parameter display value (scaled >>6) */
    DIAGNOSTIC_SENSOR = 0x66,  /* Diagnostic sensor reading (scaled >>4 max 0xFF) */
    INTAKE_MANIFOLD_TEMP = 0x69,  /* Intake manifold temp (offset 0x1900 scaled >>7) */
    DIAGNOSTIC_READING = 0x6C,  /* INSITE diagnostic reading (scaled >>3) */
    RETARDER_MODE_STATUS = 0x79,  /* Retarder mode threshold status */
    ACTIVE_FAULT_LIST = 0xC1,  /* Active fault list builder */
    FAULT_DETAIL = 0xC2,  /* Fault detail builder */
    ECU_ID_RESPONSE = 0xEA,  /* ECU ID response builder */
    CAPACITY_RESPONSE = 0xED,  /* Capacity response builder */
    VERSION_INFO = 0xF3  /* Version info builder */
} INSITE_PARAM_CODE;

typedef enum {
    QUERY_INITIALIZE = 0x00,  /* Initialize query session */
    QUERY_TERMINATE = 0x01,  /* Terminate query session */
    GET_PARAMETERS_BY_ID = 0x10,  /* Read parameters by ID */
    SET_PARAMETERS_BY_ID = 0x11,  /* Write parameters by ID */
    EXECUTE_OPERATION = 0x12,  /* Execute ECU operation */
    GET_DATA_BY_ADDRESS = 0x13,  /* Read memory by address */
    SET_DATA_BY_ADDRESS = 0x14,  /* Write memory by address */
    GET_ADDRESS_BY_PARAMETER_ID = 0x15  /* Get parameter address from ID */
} CLIP_INSTRUCTION;

typedef enum {
    MODULE_EN = 0x454E,  /* Cummins EN module family (CM550 VP44 ECUs) */
    MODULE_HA = 0x4841,  /* Cummins HA module family (CM848 HPCR ECUs) */
    MODULE_AN = 0x4E41  /* Cummins AN module family */
} CUMMINS_MODULE_IDS;

typedef enum {
    WATER_IN_FUEL_CLEAR = 0x40,  /* Clear water-in-fuel fault */
    WATER_IN_FUEL_VALIDATE = 0x41,  /* Validate water-in-fuel condition */
    HIGH_RPM_SHUTDOWN_ACTIVATE = 0x42,  /* Activate high RPM shutdown flag */
    SYSTEM_RESET_TRIGGER = 0x43,  /* Trigger diagnostic system reset */
    NOP_ACK = 0x50,  /* No operation - returns success (0) */
    MEMORY_PATCH = 0x51,  /* RAM patching system */
    SECURED_SHUTDOWN_REQUEST = 0x52,  /* Request secured shutdown */
    UNSUPPORTED_ERROR = 0x53,  /* Unsupported operation - returns error 4 */
    CAN_BUFFER_LOGGER = 0x54  /* CAN message buffer logger */
} DIAG_SECURED_SUBFUNC;

typedef enum {
    SYSTEM_CONTROL_100 = 0x64,  /* System control function 100 */
    FAULT_SCANNER_ENABLE = 0x65,  /* Enable fault flag scanner */
    CLEAR_COMMAND_STATE = 0x66,  /* Clear diagnostic_command_state to 0 */
    WATER_IN_FUEL_INIT = 0x69,  /* Water in fuel detection init */
    RESERVED_112 = 0x70,  /* Reserved - returns error code 4 */
    SET_COMMAND_STATE_BIT0 = 0x71,  /* Set bit 0 of diagnostic_command_state */
    RESERVED_114 = 0x72,  /* Reserved - returns error code 4 */
    SET_COMMAND_STATE_BIT1 = 0x73,  /* Set bit 1 of diagnostic_command_state */
    SYSTEM_CONTROL_116 = 0x74,  /* System control function 116 */
    SYSTEM_CONTROL_117 = 0x75,  /* System control function 117 */
    RESERVED_118 = 0x76  /* Reserved - returns error code 4 */
} DIAG_CONTROL_SUBFUNC;

typedef enum {
    READ_3BYTE_ADDR = 0x60,  /* Memory read with 3-byte addressing */
    WRITE_4BYTE_ADDR = 0x80,  /* Memory write with 4-byte addressing */
    WRITE_2BYTE_ADDR = 0xA0,  /* Memory write with 2-byte addressing */
    MULTI_PKT_RECEIVE = 0xB0,  /* Multi-packet data receive */
    READ_2BYTE_ADDR = 0xC0,  /* Memory read with 2-byte addressing */
    READ_1BYTE_ADDR = 0xE0,  /* Memory read with 1-byte addressing */
    MULTI_PKT_TRANSMIT = 0xF0  /* Multi-packet data transmit */
} DIAG_MEMORY_OP;

typedef enum {
    MEM_READ_2BYTE_4BYTE = 0x43,  /* Memory read: 2-byte param + 4-byte offset */
    MEM_READ_2BYTE_ONLY = 0x46,  /* Memory read: 2-byte param only */
    MEM_READ_2BYTE_4BYTE_4BYTE = 0x48,  /* Memory read: 2-byte + 4-byte + 4-byte params */
    MEM_READ_4BYTE_1BYTE = 0x4A,  /* Memory read: 4-byte address + 1-byte length */
    MEM_READ_4BYTE_4BYTE = 0x4C,  /* Memory read: 4-byte address + 4-byte length */
    EXTENDED_4F = 0x4F,  /* Extended diagnostic service 0x4F */
    EXTENDED_51 = 0x51  /* Extended diagnostic service 0x51 */
} DIAG_EXTENDED_SVC;

typedef enum {
    SUCCESS_RESPONSE = 0x0C,  /* Operation successful - no error code follows */
    STATUS_RESPONSE = 0x0D  /* Error/status response - error code follows in byte 1 */
} CAN_MULTIPACKET_RESPONSE;

typedef enum {
    NONE = 0,  /* No active diagnostic source */
    FUEL_ARBITRATOR = 1,  /* Fuel arbitrator triggered (rpm_target == 2) */
    DIAG_STATUS_2 = 2,  /* Diagnostic status 2 condition */
    ENGINE_FLAGS = 5,  /* Engine control flags triggered */
    EPS_FAULT = 6,  /* Electronic Position Sensor fault */
    DIAG_STATUS_7 = 7,  /* Diagnostic status 7 condition */
    DIAG_STATUS_30 = 30  /* Diagnostic status 30 condition */
} DIAGNOSTIC_SOURCE_CODE;

typedef enum {
    FUEL_MODE_INSITE_DISPLAY = 0x0A,  /* INSITE live data display mode */
    FUEL_MODE_RPM_THRESHOLD = 0x0B,  /* RPM threshold protection mode */
    FUEL_MODE_FUEL_DELIVERY = 0x0C  /* Fuel delivery control mode */
} DIAGNOSTIC_FUEL_CONTROL_MODE;

typedef enum {
    FUELMODE_NORMAL = 0,  /* PID governor controls fuel (engine running) */
    FUELMODE_IDLE = 1,  /* Engine at zero RPM (base idle fueling) */
    FUELMODE_CALIBRATION_LIMIT = 2,  /* Calibration table fuel limit override */
    FUELMODE_FAULT_LIMIT = 3,  /* Fault threshold fuel derate */
    FUELMODE_PROTECTION_LIMIT = 4,  /* Protection override fuel limit */
    FUELMODE_DISABLED = 5  /* Fuel control bypassed (mode flags off) */
} FUEL_CONTROL_MODE_SELECT;

typedef enum {
    NORMAL_OPERATION = 0,  /* No diagnostic mode active - normal operation */
    FUEL_ARBITRATOR_SOURCE = 1  /* Fuel arbitrator rpm_target==2 active */
} DIAGNOSTIC_STATUS;

typedef enum {
    NO_DERATE = 0,  /* No derate condition active */
    TIMING_ACTIVE = 1,  /* Derate timing accumulator active */
    EVENT_COUNTED = 2  /* Event counted - counter incremented */
} DERATE_EVENT_STATE;

typedef enum {
    INVALID_LENGTH = 0x02,  /* Security validator - message length mismatch */
    ERROR_SECURITY_FAILED = 0x03,  /* Security validator - security check returned non-zero */
    CONDITION_NOT_MET = 0x07,  /* Memory operation - system_logging_state check failed */
    ADDR_LOOKUP_FAIL = 0x08,  /* Memory resolver - initial address lookup failed */
    ADDR_RANGE_INVALID = 0x09,  /* Address validator - address not in validation table */
    ADDR_ACCESS_DENIED = 0x0A,  /* Address validator - access blocked in normal mode */
    BUFFER_WRITE_FAIL = 0x0B,  /* Memory operation - circular buffer write error */
    PATCH_LIMIT = 0x0E,  /* Response builder - memory patch count exceeded */
    UNKNOWN_SERVICE = 0x18  /* Service dispatcher - service ID not in dispatch table */
} DIAG_ERROR_SOURCE;

typedef enum {
    ENABLE_SPECIAL_MODE = 0x40,  /* Enable special diagnostic mode for high memory access */
    VALIDATE_SPECIAL_MODE = 0x41,  /* Validate special mode state transition */
    HIGH_RPM_SHUTDOWN = 0x42,  /* Trigger high RPM shutdown */
    SYSTEM_RESET = 0x43,  /* Diagnostic system reset */
    NOP = 0x50,  /* No operation - returns success */
    SERVICE_3_MEMORY_PATCH = 0x51,  /* Apply queued memory patches */
    SECURED_SHUTDOWN = 0x52,  /* Request secured engine shutdown */
    RESERVED_ERROR = 0x53,  /* Reserved - always returns error 0x04 */
    CAN_BUFFER_LOG = 0x54  /* Log CAN message buffer */
} DIAG_SERVICE_3_CMD;

typedef enum {
    CONTROL_64 = 0x64,  /* System control function 64 */
    FAULT_SCANNER = 0x65,  /* Enable fault flag scanning */
    STATE_RESET = 0x66,  /* Reset diagnostic_command_state to 0 */
    DISABLE_SPECIAL_MODE = 0x69,  /* Disable special diagnostic mode */
    RESERVED_70 = 0x70,  /* Reserved - returns error 0x04 */
    STATE_BIT0 = 0x71,  /* Set diagnostic_command_state bit 0 */
    RESERVED_72 = 0x72,  /* Reserved - returns error 0x04 */
    STATE_BIT1 = 0x73,  /* Set diagnostic_command_state bit 1 */
    CONTROL_74 = 0x74,  /* System control function 74 */
    CONTROL_75 = 0x75,  /* System control function 75 */
    RESERVED_76 = 0x76  /* Reserved - returns error 0x04 */
} DIAG_SERVICE_4_CMD;

typedef enum {
    MEM_READ_MODE3 = 0x60,  /* Memory read mode 3 - standard read */
    MEM_WRITE_MODE4 = 0x80,  /* Memory write mode 4 - 4-byte address */
    MEM_WRITE_MODE2 = 0xA0,  /* Memory write mode 2 - 2-byte address */
    MULTI_PKT_RX = 0xB0,  /* Multi-packet receive handler */
    MEM_READ_MODE2 = 0xC0,  /* Memory read mode 2 - compact read */
    MEM_READ_MODE1 = 0xE0,  /* Memory read mode 1 - extended read */
    MULTI_PKT_TX = 0xF0  /* Multi-packet transmit handler */
} DIAG_SERVICE_5_MODE;

typedef enum {
    ASYNC = 0xC0,  /* Asynchronous frame - no immediate response expected */
    SYNC = 0x80  /* Synchronous frame - wait for response */
} DPA_FRAME_TYPE;

typedef enum {
    TRANSMIT = 0x49,  /* Send data to ECU (TX instruction) */
    RECEIVE = 0x48  /* Receive data from ECU (RX instruction) */
} DPA_INSTRUCTION;

typedef enum {
    DATA_PLATE_BLOCK = 0,  /* Data plate identifier block */
    PRIMARY_BLOCK = 9  /* Main parameter memory block */
} EEPROM_MEMORY_BLOCKS;

typedef enum {
    SERVICE_QUERY_TERMINATE = 0x01,  /* QueryTerminate - CLIP compatible */
    SYSTEM_SERVICE_04 = 0x04,  /* System service 04 */
    SYSTEM_SERVICE_05 = 0x05,  /* System service 05 */
    SYSTEM_SERVICE_06 = 0x06,  /* High RPM shutdown activation */
    SYSTEM_SERVICE_07 = 0x07,  /* System service 07 */
    SYSTEM_SERVICE_0A = 0x0A,  /* System service 0A */
    SYSTEM_SERVICE_0B = 0x0B,  /* System service 0B */
    GET_PARAMETERS_BY_ID_ALT = 0x0F,  /* GetParametersByID alternate */
    SERVICE_GET_PARAMETERS_BY_ID = 0x10,  /* GetParametersByID - CLIP compatible */
    GET_ADDRESS_BY_PARAM_ID = 0x15,  /* GetAddressByParameterID - CLIP compatible */
    SYSTEM_SERVICE_16 = 0x16,  /* System service 16 */
    SYSTEM_SERVICE_18 = 0x18,  /* System service 18 */
    DIAG_ADDR_RESOLVER = 0x41,  /* Address resolver via diagnosticMemoryAddressResolver */
    MEM_READ_2B_PARAM_4B_OFFSET = 0x43,  /* Memory read: 2-byte param + 4-byte offset */
    SERVICE_44 = 0x44,  /* Service 44 */
    SERVICE_45 = 0x45,  /* Service 45 */
    MEM_READ_2B_PARAM_ONLY = 0x46,  /* Memory read: 2-byte param only */
    SERVICE_47 = 0x47,  /* Service 47 */
    SERVICE_48 = 0x48,  /* Service 48 */
    J1939_DATA_COPY = 0x49,  /* J1939 TP memory read/copy */
    MEM_READ_4B_ADDR_1B_LEN = 0x4A,  /* Memory read: 4-byte addr + 1-byte len */
    SERVICE_4B = 0x4B,  /* Service 4B */
    MEM_READ_4B_ADDR_4B_LEN = 0x4C,  /* Memory read: 4-byte addr + 4-byte len */
    SERVICE_4D = 0x4D  /* Service 4D */
} EF00_SERVICE_ID;

typedef enum {
    BASIC_DELAY = 0,  /* Basic timer + delay with watchdog */
    ALT_TRANSMIT = 1,  /* Alt timer + message transmit init */
    DIVIDED_TRANSMIT = 2,  /* Divided timer + message transmit init */
    CONDITIONAL_DELAY = 3  /* Conditional timer + watchdog delay */
} CAN_TIMER_INIT_MODE;

typedef enum {
    CAN_STATUS_BYTE = 0x36,  /* CAN message status byte offset */
    PARAM_BYTE_1 = 0x37,  /* First parameter byte offset */
    PARAM_BYTE_2 = 0x38,  /* Second parameter byte offset */
    PARAM_BYTE_3 = 0x39  /* Third parameter byte offset */
} CAN_BUFFER_OFFSETS;

typedef enum {
    SCALE_FACTOR = 3,  /* Base interpolation scaling */
    SHIFT_BITS = 8,  /* Bit shift amount for scaling */
    WORD_MULTIPLIER = 256  /* Word-size multiplication factor */
} INTERPOLATION_FACTORS;

typedef enum {
    CRUISE_RECEIVE_ENABLE = 1,  /* CCVS message reception filter */
    CRUISE_MESSAGE_ENABLE = 2,  /* Enable cruise control/vehicle speed message processing */
    SPEED_CONTROL_STATUS = 3,  /* Speed control status (1=SPEED_CONTROL 0=NORMAL) */
    SPEED_BRAKE_INTERACTION = 4  /* Enable speed control/engine braking interaction */
} J1939_CRUISE_CONTROL_ENABLE;

typedef enum {
    ETC1_RECEIVE_ENABLE = 1,  /* ETC1(PGN 61442) message reception enable */
    J1939_MESSAGE_FLAGS = 2,  /* J1939 message enable flags table */
    ASG_THROTTLE_COEFF_1 = 3,  /* ASG throttle mode compensation filter coef 1 */
    ASG_THROTTLE_COEFF_2 = 4,  /* ASG throttle mode compensation filter coef 2 */
    ASG_THROTTLE_COEFF_3 = 5  /* ASG throttle mode compensation filter coef 3 */
} J1939_THROTTLE_ENABLE;

typedef enum {
    DRIVELINE_NOT_DEFINED = 0,  /* Driveline state not defined/not supported */
    DRIVELINE_DISENGAGED = 1,  /* Transmission driveline disengaged */
    DRIVELINE_ENGAGED = 2,  /* Transmission driveline engaged */
    DRIVELINE_NA = 3  /* Driveline state not available */
} ETC1_SPN560_DRIVELINE_STATE;

typedef enum {
    TC_LOCKUP_DISENGAGED = 0,  /* Torque converter lockup disengaged */
    TC_LOCKUP_ENGAGING = 1,  /* Torque converter lockup engaging (in progress) */
    TC_LOCKUP_ENGAGED = 2,  /* Torque converter lockup fully engaged */
    TC_LOCKUP_NA = 3  /* Torque converter lockup state not available */
} ETC1_SPN573_TC_LOCKUP_STATE;

typedef enum {
    NO_SHIFT_IN_PROCESS = 0,  /* No transmission shift in progress */
    SHIFT_IN_PROCESS = 1,  /* Transmission shift currently in process */
    SHIFT_RESERVED = 2,  /* Reserved (not used) */
    SHIFT_NA = 3  /* Shift state not available */
} ETC1_SPN574_SHIFT_STATE;

typedef enum {
    OVERSPEED_DISABLED = 0,  /* Engine momentary overspeed not requested */
    OVERSPEED_ENABLED = 1,  /* Engine momentary overspeed requested by transmission */
    OVERSPEED_RESERVED = 2,  /* Reserved */
    OVERSPEED_NA = 3  /* Overspeed enable state not available */
} ETC1_SPN606_OVERSPEED_ENABLE;

typedef enum {
    PROGRESSIVE_SHIFT_ALLOW = 0,  /* Progressive shift allowed by transmission */
    PROGRESSIVE_SHIFT_DISABLE = 1,  /* Progressive shift disabled - transmission controlling torque */
    PROGRESSIVE_SHIFT_RESERVED = 2,  /* Reserved */
    PROGRESSIVE_SHIFT_NA = 3  /* Progressive shift state not available */
} ETC1_SPN607_PROGRESSIVE_SHIFT;

typedef enum {
    VEHICLE_SPEED_SENSOR_NONE = 0,  /* e2m VSRSSNTY 0 = none: no vehicle speed sensor (the CCVS1 builder sends no speed; the HSG compensator runs) (was DRIVETRAIN_STANDALONE) */
    VEHICLE_SPEED_SENSOR_INDUCTIVE = 1,  /* 1 = inductive (the magnetic vehicle speed sensor on TPU-B channel 2; this truck's EEPROM holds 1) (was DRIVETRAIN_MANUAL_VSS) */
    VEHICLE_SPEED_SENSOR_MINIGEN = 2,  /* 2 = minigen (a mini generator speed sensor); no code compares with it */
    VEHICLE_SPEED_SENSOR_TACHOGRAPH = 3,  /* 3 = tach: the speed comes from a tachograph signal; cm848_initVehicleSpeedSensorChannel and the sensor interrupt handle the TPU-B channel 2 input differently (was DRIVETRAIN_MANUAL_TPU) */
    VEHICLE_SPEED_SENSOR_J1939_WITH_GEAR_RATIO = 4,  /* 4 = dlw/GR&OOG: data link with gear ratio and out-of-gear - the vehicle speed from the J1939 ETC1 output shaft speed (cm848_calculateVehicleSpeedFromOutputShaft) and the ETC2 gear ratio (was DRIVETRAIN_AUTO_J1939_FULL) */
    VEHICLE_SPEED_SENSOR_J1939_WITHOUT_GEAR_RATIO = 5  /* 5 = dlw/o GR&OOG: data link without gear ratio and out-of-gear - ETC1 only (was DRIVETRAIN_AUTO_J1939_ETC1) */
} VEHICLE_SPEED_SENSOR_TYPE;

typedef enum {
    CALTERM_COMMUNICATION = 1,  /* CalTerm parameter read/write via J1939 */
    INSITE_COMMUNICATION = 2,  /* Insite live data monitoring via J1939 */
    DIAG_MESSAGE_DISPATCHER = 3,  /* Routes diagnostic requests by message type */
    PARAM_REQUEST_HANDLER = 4,  /* Processes EEPROM parameter read requests */
    PARAM_RESPONSE_BUILDER = 5  /* Formats parameter values for J1939 response */
} J1939_DIAGNOSTIC_PROTOCOL;

typedef enum {
    PARAM_STANDARD = 0x00,  /* Standard parameter read (0x00-0x7F) - response length 2 */
    PARAM_EXTENDED = 0x80,  /* Extended parameter read (0x80-0xBF) - response length 3 */
    INSITE_COMMAND_ACTIVE_FAULT_LIST = 0xC1,  /* Active DTC list builder */
    INSITE_COMMAND_FAULT_DETAIL = 0xC2,  /* Detailed fault information builder */
    PID_DTC_REQUEST = 0xC3,  /* PID/DTC handler request */
    PID_DTC_RESPONSE = 0xC4,  /* PID/DTC response - response length 4 or 7 */
    CAPACITY_INFO = 0xEA,  /* Capacity response builder - 24 bytes */
    ECU_ID = 0xED,  /* ECU identification builder */
    INSITE_COMMAND_VERSION_INFO = 0xF3  /* Version info builder - 31 bytes */
} INSITE_CMD;

typedef enum {
    PROTECTION_ENABLED = 0x80,  /* Protection system enable flag is set */
    DERATE_BIT2_SET = 0x40,  /* Derate status byte bit 2 is set */
    DERATE_BIT3_SET = 0x20,  /* Derate status byte bit 3 is set */
    SENSOR_BIT1_SET = 0x10,  /* Sensor status register bit 1 is set */
    SENSOR_BIT0_SET = 0x08,  /* Sensor status register bit 0 is set */
    SENSOR_BIT3_SET = 0x04,  /* Sensor status register bit 3 is set */
    SENSOR_BIT2_SET = 0x02,  /* Sensor status register bit 2 is set */
    SENSOR_BIT4_SET = 0x01  /* Sensor status register bit 4 is set */
} INSITE_STATUS_OUTPUT;

typedef enum {
    MEMORY_OPERATION_SUCCESS = 0x00,  /* Memory operation completed successfully */
    MEMORY_OPERATION_INVALID_LENGTH = 0x02,  /* Message length mismatch */
    MEMORY_OPERATION_AUTH_FAILED = 0x03,  /* Security check returned non-zero */
    LOGGING_STATE_ERROR = 0x07,  /* EEPROM write blocked - logging state check failed */
    MEMORY_OPERATION_WRITE_DENIED = 0x0A,  /* ROM/Flash region - write not permitted */
    MEMORY_OPERATION_BUFFER_WRITE_FAIL = 0x0B,  /* Circular buffer write error during EEPROM logging */
    AUTH_REQUIRED_MISSING = 0x1A  /* EEPROM write requires auth but not provided */
} MEMORY_OP_RESULT;

typedef enum {
    AUTH_SUCCESS = 0x00,  /* Security check passed - operation authorized */
    SECURITY_INVALID_LENGTH = 0x02,  /* Invalid message length for service */
    AUTH_FAILED = 0x03,  /* Security check failed - access denied */
    SECURITY_CONDITION_NOT_MET = 0x07,  /* Pre-condition not satisfied */
    INVALID_ADDR = 0x0A,  /* Invalid memory address range */
    SECURITY_BUFFER_WRITE_FAIL = 0x0B,  /* Circular buffer write failed */
    PROCEED_TO_HANDLER = 0xFF  /* Proceed to handler (auth passed or not required) */
} SECURITY_RESULT;

typedef enum {
    BYPASS_ENABLED = 0xB522,  /* Magic value to bypass security checks */
    LEGACY_BYPASS = 0x00FF  /* Legacy security bypass value */
} SECURITY_BYPASS;

typedef enum {
    BYPASS_FLAG_ENABLED = 0xFF,  /* Security checks completely bypassed */
    SECURITY_ACTIVE = 0x00  /* Normal security - checks enforced */
} SECURITY_BYPASS_FLAG;

typedef enum {
    SENSOR_STATUS_BIT4 = 0x10,  /* Sensor status bit 4 - maps to INSITE output 0x01 */
    SENSOR_STATUS_BIT3 = 0x08,  /* Sensor status bit 3 - maps to INSITE output 0x04 */
    SENSOR_STATUS_BIT2 = 0x04,  /* Sensor status bit 2 - maps to INSITE output 0x02 */
    SENSOR_STATUS_BIT1 = 0x02,  /* Sensor status bit 1 - maps to INSITE output 0x10 */
    SENSOR_STATUS_BIT0 = 0x01  /* Sensor status bit 0 - maps to INSITE output 0x08 */
} SENSOR_STATUS_BITS;

typedef enum {
    SENSOR_IDLE = 0,  /* Initial monitoring state */
    SENSOR_ACTIVE = 1,  /* Sensor actively being monitored */
    SENSOR_FAULT_DETECTED = 2,  /* Fault condition detected */
    RECOVERY = 3  /* Recovery countdown state */
} SENSOR_HISTORY_STATE;

typedef enum {
    NO_SYNC = 0,  /* No synchronization established */
    HAVE_SYNC = 1,  /* Synchronization established and maintained */
    LOST_SYNC = 2  /* Synchronization was established but lost */
} SYNC_STATE;

typedef enum {
    MONITORING = 0,  /* Initial state - monitoring conditions for entry */
    TIMER_COUNTING = 1,  /* Timer countdown active - conditions met */
    RPM_PROTECTION_WARNING_ACTIVE = 2,  /* Warning threshold reached - protection active */
    FAULT_TRIGGERED = 3,  /* Fault triggered - derate change detected */
    SHUTDOWN_PENDING = 4  /* Shutdown pending - timer expired waiting for idle */
} HIGH_RPM_PROTECTION_STATE;

typedef enum {
    TIMER_ACTIVE = 0x80,  /* High RPM protection timer is running */
    HIGH_RPM_DIAG_FLAG = 0x08,  /* Diagnostic system flags bit 1 is set */
    FAULT_WITH_DIAG = 0x04,  /* High RPM fault + diagnostic flag bit 2 */
    SHUTDOWN_TIMER_ZERO = 0x02,  /* Shutdown active and timer expired */
    HIGH_RPM_WARNING_ACTIVE = 0x01  /* High RPM protection warning flag set */
} HIGH_RPM_PROTECTION_FLAGS;

typedef enum {
    TABLE_BLEND_CALC = 0,  /* Table interpolation blend calculation result */
    RPM_BASED_LIMIT = 1,  /* RPM-based fuel demand limit */
    BLEND_PARAM_FALLBACK = 2,  /* Blend parameter 2 fallback value */
    HIGH_RPM_FUEL_LIMIT = 3,  /* High RPM fuel limit */
    FUEL_LIMIT_FLOOR = 4,  /* Fuel limit floor value */
    ENGINE_MODE_TRANSITION = 5  /* Engine mode transition timing */
} FUEL_DEMAND_SOURCE;

typedef enum {
    NO_LIMIT_ACTIVE = 0,  /* No fuel limit active / cleared state */
    OVERRIDE_STATE_ACTIVE = 1,  /* Override state active from fuel_demand_override_state */
    PROTECTION_OVERRIDE_LIMIT = 5  /* Protection/override state - init and fault recovery */
} FUEL_DEMAND_LIMIT;

typedef enum {
    THROTTLE_OVERRIDE = 0x04,  /* Override throttle control when set */
    SPEED_LIMIT_ACTIVE = 0x08,  /* Activate speed limiter when set */
    FUEL_LIMIT_ACTIVE = 0x10  /* Activate fuel limiter when set */
} FUEL_ARB_FLAGS;

typedef enum {
    FUEL_DEMAND_MODE_OVERRIDE = 13,  /* Fuel demand mode selector override */
    SHUTDOWN_PROTECTION_LIMIT = 15,  /* Shutdown protection fuel limit */
    DIAGNOSTIC_MODE_BUFFER = 16,  /* Diagnostic mode buffer limit */
    FUEL_LIMIT_SHUTDOWN = 17,  /* Fuel limit from shutdown calc */
    CALCULATED_FUEL_TIMING = 19,  /* Calculated fuel timing value */
    FUEL_ARBITRATOR_DIAG = 20,  /* Fuel arbitrator diagnostic mode */
    SHUTDOWN_LIMIT_SELECTOR = 21,  /* Shutdown limit selector value */
    SHUTDOWN_MINIMUM_INIT = 28,  /* Shutdown minimum init value */
    PROTECTION_SHUTDOWN_LIMIT = 29,  /* Protection shutdown fuel limit */
    OIL_PRESSURE_PROTECTION = 34  /* Oil pressure protection limit */
} SHUTDOWN_SELECTOR_SOURCE;

typedef enum {
    OFF_INACTIVE = 0,  /* Output off/inactive - waiting for condition */
    TRANSITIONING = 1,  /* Transition state - checking conditions */
    ON_ACTIVE = 2  /* Output on/active - condition met */
} IO_CONTROL_STATE;

typedef enum {
    OUTPUT_TIMER_IDLE = 0,  /* Output timer idle state */
    OUTPUT_TIMER_STATE_1 = 1,  /* Output timer state 1 */
    OUTPUT_TIMER_STATE_2 = 2,  /* Output timer state 2 */
    OUTPUT_TIMER_STATE_3 = 3,  /* Output timer state 3 */
    OUTPUT_TIMER_STATE_4 = 4,  /* Output timer state 4 */
    OUTPUT_TIMER_STATE_5 = 5  /* Output timer state 5 */
} OUTPUT_CONTROL_TIMER_STATE;

typedef enum {
    TIMING_MODE_A = 0x01,  /* PWM output timing mode A */
    TIMING_MODE_B = 0x02  /* PWM output timing mode B */
} OUTPUT_CONTROL_TIMING_STATE;

typedef enum {
    STATUS_NORMAL = 0xF0,  /* Normal operation - load below threshold */
    PROP_DIAG_STATUS_F1 = 0xF1,  /* Status F1 - specific condition */
    STATUS_LOAD_HIGH = 0xF4,  /* Load above threshold */
    STATUS_FAULT_ACTIVE = 0xF8,  /* Critical fault active */
    STATUS_BIT0_LOAD_INACTIVE = 0x01  /* Bit 0 set when load calculation inactive */
} PROP_DIAG_STATUS;

typedef enum {
    SAFETY_LIMIT = 32000,  /* Maximum allowed parameter value */
    BLOCK_LIMIT = 65535  /* Block validation limit */
} PARAM_VALIDATION;

typedef enum {
    TIMER_CHANNEL_04 = 0x04,  /* Timer channel 4 (DAT_003fcf42) */
    TIMER_CHANNEL_11 = 0x0b,  /* Timer channel 11 (DAT_003fcf44) */
    TIMER_CHANNEL_16 = 0x10,  /* Timer channel 16 (DAT_003fcf54) */
    TIMER_CHANNEL_17 = 0x11,  /* Timer channel 17 (DAT_003fcf4c) */
    TIMER_CHANNEL_18 = 0x12,  /* Timer channel 18 (DAT_003fcf4a) */
    TIMER_CHANNEL_19 = 0x13,  /* Timer channel 19 (DAT_003fcf4e) */
    TIMER_CHANNEL_20 = 0x14,  /* Timer channel 20 (DAT_003fcf50) */
    TIMER_CHANNEL_21 = 0x15,  /* Timer channel 21 (DAT_003fcf52) */
    TIMER_CHANNEL_38 = 0x26,  /* Timer channel 38 (DAT_003fcf3a) */
    TIMER_CHANNEL_43 = 0x2b,  /* Timer channel 43 (sci_output_test_active_count) */
    TIMER_CHANNEL_44 = 0x2c,  /* Timer channel 44 (sci_output_test_phase_countdown) */
    TIMER_CHANNEL_53 = 0x35  /* Timer channel 53 (sci_output_test_timers) */
} EVENT_TIMER_CHANNEL;

typedef enum {
    PRIOR_BOOT_NORMAL = 0,  /* Previous boot completed a normal run cycle; diagnostics permitted */
    PRIOR_BOOT_FAULTED = 1  /* Previous boot faulted or shut down mid cold-start; diagnostics locked out */
} PRIOR_BOOT_STATE;

typedef enum {
    RAM_REFRESH_DISABLED = 0,  /* RAM refresh off (development mode); the refresh pass and the EEPROM mirror reload do nothing; stored by the reset service and temporarily by cm848_runCylinderContributionTest */
    RAM_REFRESH_ENABLED = 1  /* RAM refresh on (the normal state); stored at start-up and power-down and by the activate services */
} RAM_REFRESH_STATE;

typedef enum {
    DEVELOPMENT_MODE_OFF = 0,  /* Normal operation; stored by the activate services and the power-down sequence; the register address ranges of the diagnostic memory services are refused */
    DEVELOPMENT_MODE_ON = 1  /* Development mode; stored only by the reset service together with the RAM refresh disabled; the activate service needs it and the register address ranges of the diagnostic memory services open */
} DEVELOPMENT_MODE_STATE;

typedef enum {
    RUN_LOCATION_DEVELOPMENT = 0xea,  /* Development: set by cm848_resetDiagnosticSession together with development_mode on and the RAM refresh off */
    RUN_LOCATION_NORMAL = 0xee  /* Normal: set at boot / power-down and by the activate services; the only value for which cm848_lookupParameterIdAddress gives raw EEPROM addresses */
} RUN_LOCATION;

typedef enum {
    DIAG_ACK = 0,  /* Request fulfilled successfully */
    DIAG_NACK_NOT_READY = 4,  /* Rejected: ECU not in standby (development_mode was 0) */
    DIAG_NACK_PROTECTED = 7  /* Rejected: protection mode active */
} DIAG_RESPONSE;

typedef enum {
    EEPROM_DIAG_HANDLE_RESPONSE = 0x03,  /* Handle EEPROM diagnostic response */
    EEPROM_DIAG_DATA_TRANSFER = 0x10,  /* Process EEPROM data transfer */
    EEPROM_DIAG_SEND_VERSION = 0x11,  /* Send EEPROM version response */
    EEPROM_DIAG_TRANSFER_BLOCK = 0x12,  /* Transfer data block service */
    EEPROM_DIAG_WRITE_DISPATCH = 0x20  /* Dispatch EEPROM write request */
} EEPROM_DIAG_STATE;

typedef enum {
    CAL_VOLATILE = 0xea,  /* Writes land in RAM only; lost on power cycle */
    CAL_PERSISTENT = 0xee  /* Writes go through to EEPROM; survive power cycle */
} CAL_WRITE_MODE;

typedef enum {
    TSC1_OVERRIDE_OFF = 0,  /* SPN 695 00 = override disabled (e2m Jcomm_Engine_Control_Mode / Jcomm_Retarder_Control_Mode 0 = disable) */
    TSC1_SPEED_CONTROL = 1,  /* SPN 695 01 = speed control: the engine governs to the requested speed (e2m 1 = speed) */
    TSC1_TORQUE_CONTROL = 2,  /* SPN 695 10 = torque control (e2m 2 = torque) */
    TSC1_SPEED_TORQUE_LIMIT = 3  /* SPN 695 11 = speed and torque limit control (e2m 3 = limit) */
} TSC1_OVERRIDE_MODE;

typedef enum {
    J1939_CONTROL_DEVICE_NONE = 0,  /* e2m Jcomm_Engine_Control_Device_Indicator 0 = NONE */
    J1939_CONTROL_DEVICE_TRANSMISSION = 1,  /* 1 = TRANS: the sender is j1939_transmission_source_address */
    J1939_CONTROL_DEVICE_ANTI_LOCK_BRAKES = 2,  /* 2 = ABS: j1939_anti_lock_brake_source_address */
    J1939_CONTROL_DEVICE_ANTI_SLIP_REGULATION = 3,  /* 3 = ASR: j1939_anti_slip_regulation_source_address */
    J1939_CONTROL_DEVICE_UNKNOWN = 4  /* 4 = UNKNOWN: any other source address */
} J1939_CONTROL_DEVICE;

typedef enum {
    CONTROL_NETWORK_J1922 = 0,  /* e2m Jcomm_Engine_Control_Network_Type 0 = J1922 (on the J1708 link) */
    CONTROL_NETWORK_J1939 = 1  /* 1 = J1939 */
} CONTROL_NETWORK;

typedef enum {
    ENGINE_STATE_UNINITIALIZED = 0,  /* Zeroed RAM: cm848_updateEngineState turns 0 (or anything above 8) into STOPPED */
    ENGINE_STATE_STOPPED = 1,  /* e2m STOP: engine speed at or below engine_stopped_speed - the final fuel is 0 (FUELING_STATE_ENGINE_STOPPED). RAM dump (key on / engine stopped): 1 */
    ENGINE_STATE_CRANKING = 2,  /* e2m CRANK: above engine_stopped_speed until crank_exit_speed - the fuel is crank_fuel (FUELING_STATE_CRANKING) */
    ENGINE_STATE_RUNNING = 3,  /* e2m RUN: at or above crank_exit_speed; no final-fuel override; engine_is_active_flag is 1 */
    ENGINE_STATE_ENGINE_BRAKE = 4,  /* e2m ENGBRAKE: from RUN while engine_retarder_active_flag is 1 (and engine_brake_driveline_brake_type_cal 0) until it clears - the fuel is the ROM word 0x5c308 (FUELING_STATE_ENGINE_BRAKE) */
    ENGINE_STATE_OVERSPEED = 5,  /* e2m OVERSPED: while engine_overspeed_active_flag is 1 (P0219) - the fuel is the ROM word 0x5c30a (FUELING_STATE_OVERSPEED) */
    ENGINE_STATE_JUMP_START = 6,  /* e2m JUMPSTRT: from CRANK after the crank pass count passes its limit; the consumers treat it like CRANK */
    ENGINE_STATE_REENTRY = 7,  /* e2m REENTRY: from RUN when engine speed drops to crank_reentry_speed - the crank fuel is a floor (FUELING_STATE_CRANKING) */
    ENGINE_STATE_SHUTDOWN = 8  /* e2m SHUTDOWN: the key line (mios_mdasm30.SCRD bit 15) is off without key_off_shutdown_inhibit_flag - or engine_shutdown_command_flag is 1; ecm_power_down_timer runs - the fuel is fuel_demand_minimum (FUELING_STATE_SHUTDOWN) */
} ENGINE_STATE;

typedef enum {
    J1939_ACK = 0,  /* Positive acknowledgment - request fulfilled */
    J1939_NACK = 1,  /* Negative acknowledgment - cannot comply with request */
    J1939_ACCESS_DENIED = 2,  /* Access denied - not authorized for requested action */
    J1939_CANNOT_RESPOND = 3  /* Cannot respond - busy or resource unavailable */
} J1939_ACK_TYPE;

typedef enum {
    CRUISE_OFF = 0,  /* Off: clears engaged, resume and the resume speed valid flag (e2m 1184 +2 Cruise_Command_Mode value list 'off/set/resume/coast/accel/bump down/bump up/hold/cancel') | earlier note: Cruise off/disabled - clears override and fuel-enable */
    CRUISE_SET = 1,  /* Set: cruise_speed_command = the road speed (at most the cruise maximum); engaged (e2m 1184 +2 Cruise_Command_Mode value list 'off/set/resume/coast/accel/bump down/bump up/hold/cancel') | earlier note: SET pressed - latch current speed as cruise_speed_command (J1939 SET) */
    CRUISE_RESUME = 2,  /* Resume: cruise_speed_command = cruise_resume_speed; an external reset of the governor (e2m 1184 +2 Cruise_Command_Mode value list 'off/set/resume/coast/accel/bump down/bump up/hold/cancel') | earlier note: RESUME - restore cruise_resume_speed (J1939 RESUME) */
    CRUISE_COAST = 3,  /* Coast: cruise_speed_command falls by cruise_coast_ramp per pass (e2m 1184 +2 Cruise_Command_Mode value list 'off/set/resume/coast/accel/bump down/bump up/hold/cancel') (was CRUISE_DECELERATE) | earlier note: Decelerate/coast via fuel-rate step (J1939 DECELERATE) */
    CRUISE_ACCELERATE = 4,  /* Accelerate: cruise_speed_command rises by cruise_accelerate_ramp per pass (e2m 1184 +2 Cruise_Command_Mode value list 'off/set/resume/coast/accel/bump down/bump up/hold/cancel') | earlier note: Accelerate via fuel-rate ramp (J1939 ACCELERATE) */
    CRUISE_BUMP_DOWN = 5,  /* Bump down: cruise_speed_command falls by cruise_bump_down_step (e2m 1184 +2 Cruise_Command_Mode value list 'off/set/resume/coast/accel/bump down/bump up/hold/cancel') (was CRUISE_DECELERATE_2) | earlier note: Decelerate alternate fuel-rate step (J1939 DECELERATE) */
    CRUISE_BUMP_UP = 6,  /* Bump up: cruise_speed_command rises by cruise_bump_up_step while below the road speed plus one step (e2m 1184 +2 Cruise_Command_Mode value list 'off/set/resume/coast/accel/bump down/bump up/hold/cancel') (was CRUISE_ACCELERATE_2) | earlier note: Accelerate alternate fuel-rate ramp (J1939 ACCELERATE) */
    CRUISE_HOLD = 7,  /* Hold: cruise_resume_speed follows cruise_speed_command (e2m 1184 +2 Cruise_Command_Mode value list 'off/set/resume/coast/accel/bump down/bump up/hold/cancel') (was CRUISE_ACTIVE_HOLD) | earlier note: Override active - holding setpoint (J1939 HOLD) */
    CRUISE_CANCEL = 8  /* Cancel: clears engaged and resume but keeps the resume speed (e2m 1184 +2 Cruise_Command_Mode value list 'off/set/resume/coast/accel/bump down/bump up/hold/cancel') (was CRUISE_STANDBY) | earlier note: Armed/enabled - driver in control not overriding */
} CRUISE_CONTROL_STATE;

typedef enum {
    CRUISE_SWITCH_ON_OFF = 0,  /* ON/OFF master button - arms cruise (engage check wants state_b 0 with prev 5). Confirmed live 2026-06-12 */
    CRUISE_SWITCH_CANCEL = 1,  /* CANCEL button. Confirmed live 2026-06-12 */
    CRUISE_SWITCH_COAST = 2,  /* COAST button - decelerate (governor_cruise_coastButton_handler returns CRUISE_COAST). Confirmed live 2026-06-12 */
    CRUISE_SWITCH_SET = 3,  /* SET button - rising edge latches setpoint (CRUISE_SET). Confirmed live 2026-06-12 */
    CRUISE_SWITCH_RESUME = 4,  /* RESUME/ACCEL button - tap returns CRUISE_RESUME - held accelerates (CRUISE_ACCELERATE). Confirmed live 2026-06-12 */
    CRUISE_SWITCH_IDLE = 5  /* No button pressed / debounce-settling value */
} CRUISE_SWITCH_REQUEST;

typedef enum {
    VARIABLE_GEOMETRY_TURBOCHARGER_SPAN_ADJUSTMENT_NORMAL = 0,  /* engine-load protection not derating */
    VARIABLE_GEOMETRY_TURBOCHARGER_SPAN_ADJUSTMENT_ERROR = 8  /* engine-load protection actively derating - bit3 (0x08) of the protection status word mirrors governor_status_flags confirm-B (0x8000) */
} VARIABLE_GEOMETRY_TURBOCHARGER_SPAN_ADJUSTMENT_STATE;

typedef enum {
    DIAGNOSTIC_SERVICE_EEPROM_TRANSFER_INIT = 0x02,  /* mpc555_diagServiceInitEepromTransfer */
    DIAGNOSTIC_SERVICE_DOWNLOAD_CALIBRATION = 0x07,  /* cm848_diagServiceDownloadCalibration */
    DIAGNOSTIC_SERVICE_ACKNOWLEDGE_11 = 0x0b,  /* stub */
    DIAGNOSTIC_SERVICE_ACKNOWLEDGE_16 = 0x10,  /* stub */
    DIAGNOSTIC_SERVICE_ACKNOWLEDGE_24 = 0x18,  /* stub */
    DIAGNOSTIC_SERVICE_EXECUTE_ROUTINE = 0x19,  /* mpc555_diagService25_executeFunction */
    DIAGNOSTIC_SERVICE_GET_ADDRESS_BY_PARAMETER_ID = 0x41,  /* cm848_diagService65_handler */
    DIAGNOSTIC_SERVICE_READ_BY_PARAMETER_ID_OFFSET = 0x43,  /* cm848_diagService67_memoryReadOffset */
    DIAGNOSTIC_SERVICE_MEMORY_WRITE = 0x44,  /* kernel memory-write (ROM->RAM window) */
    DIAGNOSTIC_SERVICE_MEMORY_WRITE_69 = 0x45,  /* kernel memory-write */
    DIAGNOSTIC_SERVICE_MEMORY_READ = 0x4a,  /* cm848_diagService74_memoryRead */
    DIAGNOSTIC_SERVICE_MEMORY_WRITE_75 = 0x4b,  /* kernel memory-write */
    DIAGNOSTIC_SERVICE_MEMORY_READ_EXT = 0x4c,  /* cm848_diagService76_memoryReadExt */
    DIAGNOSTIC_SERVICE_MEMORY_WRITE_EXT = 0x4d  /* kernel memory-write ext */
} DIAGNOSTIC_SERVICE;

typedef enum {
    FUEL_PRESSURE_GOVERNOR_OPEN_LOOP_START = 1,  /* Open-loop start command (two tables blended by the input fuel_metering_outer_loop_preset_temperature_source picks); the mode the others fall back to */
    FUEL_PRESSURE_GOVERNOR_CLOSED_LOOP_AFTER_START = 2,  /* PID on fuel_pressure_setpoint - fuel_pressure_feedback_filtered for the first 1000 revolutions (fuel_pressure_governor_start_revolutions) */
    FUEL_PRESSURE_GOVERNOR_CLOSED_LOOP = 4,  /* PID after the start revolutions */
    FUEL_PRESSURE_GOVERNOR_LOW_PRESSURE_FIXED = 8,  /* Timed fixed command when the pressure is low inside an rpm window (impossible in this calibration: threshold 0 and an empty rpm window) */
    FUEL_PRESSURE_GOVERNOR_KEY_OFF = 0x10,  /* Fixed command while the ignition key switch is off and no shutdown is running */
    FUEL_PRESSURE_GOVERNOR_DISABLED = 0x20,  /* Fixed command while fuel_pressure_governor_disable is set */
    FUEL_PRESSURE_GOVERNOR_SENSOR_FAULT = 0x40  /* Fixed command (2865 here) while P0193 / P0192 / P0653 / P0652 are set (faults 304 / 305 / 377 / 378) - the open-loop fallback */
} FUEL_PRESSURE_GOVERNOR_MODE;

typedef enum {
    EGR_VALVE_CLOSED_LOOP = 0,  /* PID position control: cm848_selectEgrValveDutyByControlState takes egr_valve_pid_duty */
    EGR_VALVE_CLOSED_HOLD = 1,  /* Open-loop closed-hold duty: egr_valve_closed_hold_flag is set */
    EGR_VALVE_USER_DUTY_OVERRIDE = 2,  /* Fixed duty override: bit 1 of egr_valve_user_override_flags_cal is set */
    EGR_VALVE_AUTOZERO_DRIVE = 3,  /* Position autozero drive: the autozero holding duty is output (the dump is permanently here) */
    EGR_VALVE_DISABLED = 4  /* Output disabled: logical output request 67 (the PWM enable) is clear; the duty is 0 */
} EGR_VALVE_CONTROL_STATE;

typedef enum {
    COMBUSTION_CHI_SOURCE_AMBIENT_AIR_DENSITY = 1,  /* Base chi from the ambient air density protective chi table (the density chi is not smaller) */
    COMBUSTION_CHI_SOURCE_COOLANT_TEMPERATURE = 3,  /* Base chi from the coolant temperature protective chi table (the density chi is smaller) */
    COMBUSTION_CHI_SOURCE_EGR_OFF = 10,  /* Fixed EGR-off chi and level while EGR is requested off and no combustion status flag 0x08 / 0x10 / 0x200 is set; the normal state on this truck (dump: 10) */
    COMBUSTION_CHI_SOURCE_FULL_USER_OVERRIDE = 12,  /* Calibrated override of chi and both map numbers (override mask 0x80 and 0x40 set) */
    COMBUSTION_CHI_SOURCE_SINGLE_USER_OVERRIDE = 13,  /* Calibrated override with one whole chi that sets both map numbers (mask 0x80 set and 0x40 clear) */
    COMBUSTION_CHI_SOURCE_STATUS_FLAG_FIXED_VALUE = 14  /* Fixed chi and level selected when a combustion status flag 0x08 / 0x10 / 0x200 is set */
} COMBUSTION_CHI_SOURCE;

typedef enum {
    INJECTION_TIMING_INTERMEDIATE_SOURCE_FOUR_DIMENSIONAL_TIMING = 0,  /* e2m 103B value label 00 FOUR_D: the 4D timing maps (was INJECTION_TIMING_INTERMEDIATE_SOURCE_OFFSET_MAPS) | earlier note: cm848_calculateFourDimensionalInjectionTiming: the timing offset comes from the two engine speed x fuel demand maps blended by the combustion alpha (algorithm_enable_flags_4_cal bit 8 clear) */
    INJECTION_TIMING_INTERMEDIATE_SOURCE_USER_COMMANDED_TIMING = 2,  /* e2m 103B value label 02 USERCOMD: user_commanded_injection_timing_cal (algorithm_enable_flags_4_cal bit 8) (was INJECTION_TIMING_INTERMEDIATE_SOURCE_FIXED_OFFSET_CALIBRATION) | earlier note: cm848_calculateFourDimensionalInjectionTiming: the fixed user_commanded_injection_timing_cal while algorithm_enable_flags_4_cal bit 8 is set */
    INJECTION_TIMING_INTERMEDIATE_SOURCE_COMBUSTION_REFERENCE = 25,  /* e2m 103B value label 19 CBR_SOI: cm848_passCompensatedTimingToCombustionLimits copies the off-nominal compensated reference (1711 +8 CBO_SOI_Ref) into ANC_SOI (10A4 +14) (was INJECTION_TIMING_INTERMEDIATE_SOURCE_PREVIOUS_VALUES_STORED) | earlier note: cm848_passCompensatedTimingToCombustionLimits: one of the last tasks of every pass stores the compensated reference as the previous value */
    INJECTION_TIMING_INTERMEDIATE_SOURCE_COMBUSTION_MAXIMUM_LIMIT = 27,  /* cm848_applyCombustionTimingLimits: the timing reached the combustion maximum limit (cm848_calculateMainInjectionTiming turns it into 29) */
    INJECTION_TIMING_INTERMEDIATE_SOURCE_COMBUSTION_MINIMUM_LIMIT = 28  /* cm848_applyCombustionTimingLimits: the timing with the user increment is at or below the combustion minimum limit (becomes 30) */
} INJECTION_TIMING_INTERMEDIATE_SOURCE;

typedef enum {
    MAIN_INJECTION_TIMING_SOURCE_CRANK = 5,  /* e2m 103B value label 05 CRANK: the cranking timing map (engine state CRANKING / JUMP_START / REENTRY) (was MAIN_INJECTION_TIMING_SOURCE_COLD_START_MAP) | earlier note: cm848_calculateMainInjectionTiming: the cold start engine speed x coolant temperature map while engine_state is ENGINE_STATE_CRANKING / ENGINE_STATE_JUMP_START / ENGINE_STATE_REENTRY */
    MAIN_INJECTION_TIMING_SOURCE_USER_OVERRIDE = 7,  /* e2m 103B value label 07 USEROVRD: main_injection_timing_selection 2 takes user_commanded_injection_timing_cal (was MAIN_INJECTION_TIMING_SOURCE_FIXED_OFFSET_CALIBRATION) | earlier note: cm848_selectMainInjectionTiming: main_injection_timing_selection 2 uses the fixed user_commanded_injection_timing_cal */
    MAIN_INJECTION_TIMING_SOURCE_POWER_UP = 8,  /* The power-up value (cm848_initTimingFilterStates), the only store of 8; the e2m 103B value label is 08 STOP, but the dump with the engine stopped reads 20 (coolant) (was MAIN_INJECTION_TIMING_SOURCE_INITIAL, then _ENGINE_STOPPED) */
    MAIN_INJECTION_TIMING_SOURCE_MISFIRE_LIMIT = 11,  /* e2m 103B value label 0B MISFIRE: injection_timing_main_misfire_limit (e2m 8A3D Misfire_Timing_Limit) raised the timing (was MAIN_INJECTION_TIMING_SOURCE_DEMAND_FLOOR) | earlier note: cm848_calculateMainInjectionTiming: the demand was raised to injection_timing_main_misfire_limit */
    MAIN_INJECTION_TIMING_SOURCE_COMBUSTION_MANAGER = 18,  /* e2m 103B value label 12 COMB_MGR: injection_timing_main_base_command (e2m 171B +8 CBL_SOI_Cmd) won or the sum includes it (was MAIN_INJECTION_TIMING_SOURCE_BASE_COMMAND) | earlier note: cm848_calculateMainInjectionTiming: the sum of the base command and the components (combination mode 0) or the base command won the highest / lowest comparison */
    MAIN_INJECTION_TIMING_SOURCE_INTAKE_TEMPERATURE_COMPONENT = 19,  /* cm848_calculateMainInjectionTiming: the intake temperature component won (combination mode 1 / other) */
    MAIN_INJECTION_TIMING_SOURCE_COOLANT_COMPONENT = 20,  /* cm848_calculateMainInjectionTiming: the coolant component won */
    MAIN_INJECTION_TIMING_SOURCE_BAROMETRIC_PRESSURE_COMPONENT = 21,  /* cm848_calculateMainInjectionTiming: the barometric pressure component won */
    MAIN_INJECTION_TIMING_SOURCE_BOOST_COMPONENT = 22,  /* cm848_calculateMainInjectionTiming: the boost component won */
    MAIN_INJECTION_TIMING_SOURCE_EXTENDED_IDLE = 23,  /* e2m 103B value label 17 EX_IDLE: injection_timing_main_extended_idle_minimum raised the timing during extended idle (was MAIN_INJECTION_TIMING_SOURCE_GOVERNOR_LIMIT_MINIMUM) | earlier note: cm848_calculateMainInjectionTiming: raised to injection_timing_main_extended_idle_minimum while low_speed_governor_extended_idle_active_flag is set */
    MAIN_INJECTION_TIMING_SOURCE_COOLANT_OVERHEAT_DERATE = 24,  /* e2m 103B value label 18 CTDRATE: coolant_overheat_derate_minimum_injection_timing raised the timing (was MAIN_INJECTION_TIMING_SOURCE_WORKING_MINIMUM) | earlier note: cm848_calculateMainInjectionTiming: raised to coolant_overheat_derate_minimum_injection_timing */
    MAIN_INJECTION_TIMING_SOURCE_COMBUSTION_MAXIMUM_LIMIT = 29,  /* cm848_calculateMainInjectionTiming: the base command won and the intermediate source code was 27 */
    MAIN_INJECTION_TIMING_SOURCE_COMBUSTION_MINIMUM_LIMIT = 30,  /* cm848_calculateMainInjectionTiming: the base command won and the intermediate source code was 28 */
    MAIN_INJECTION_TIMING_SOURCE_FUEL_PRESSURE_LIMP_HOME_COMPONENT = 31  /* cm848_calculateMainInjectionTiming: injection_timing_main_fuel_pressure_limp_home_component won */
} MAIN_INJECTION_TIMING_SOURCE;

typedef enum {
    POWER_TAKE_OFF_GOVERNOR_STATE_REMOTE_COUNT = 0,  /* Counting presses of the remote switch (j1939_governor_feature_byte bit 1) - the count picks a preset speed */
    POWER_TAKE_OFF_GOVERNOR_STATE_REMOTE_RUN = 1,  /* Running at the remote preset speed until the switch opens or a cancel condition */
    POWER_TAKE_OFF_GOVERNOR_STATE_WAIT = 2,  /* Waiting: vehicle speed / engine speed window / faults / engine stopped / brake or clutch cancel. RAM dump: 2 */
    POWER_TAKE_OFF_GOVERNOR_STATE_NORMAL = 3  /* Running under cab control from the set / resume speeds (j1939_governor_feature_byte bit 0) */
} POWER_TAKE_OFF_GOVERNOR_STATE;

typedef enum {
    POWER_TAKE_OFF_GOVERNOR_J1939_STATE_OFF_OR_DISABLED = 0,  /* SPN 976 value 0 */
    POWER_TAKE_OFF_GOVERNOR_J1939_STATE_HOLD = 1,  /* SPN 976 value 1 */
    POWER_TAKE_OFF_GOVERNOR_J1939_STATE_REMOTE_HOLD = 2,  /* SPN 976 value 2 */
    POWER_TAKE_OFF_GOVERNOR_J1939_STATE_STANDBY = 3,  /* SPN 976 value 3 - not stored */
    POWER_TAKE_OFF_GOVERNOR_J1939_STATE_REMOTE_STANDBY = 4,  /* SPN 976 value 4 - not stored */
    POWER_TAKE_OFF_GOVERNOR_J1939_STATE_SET = 5,  /* SPN 976 value 5 - not stored */
    POWER_TAKE_OFF_GOVERNOR_J1939_STATE_DECELERATE_OR_COAST = 6,  /* SPN 976 value 6 */
    POWER_TAKE_OFF_GOVERNOR_J1939_STATE_RESUME = 7,  /* SPN 976 value 7 - not stored */
    POWER_TAKE_OFF_GOVERNOR_J1939_STATE_ACCELERATE = 8,  /* SPN 976 value 8 */
    POWER_TAKE_OFF_GOVERNOR_J1939_STATE_ACCELERATOR_OVERRIDE = 9,  /* SPN 976 value 9 */
    POWER_TAKE_OFF_GOVERNOR_J1939_STATE_PREPROGRAMMED_SET_SPEED_1 = 10,  /* SPN 976 value 10 */
    POWER_TAKE_OFF_GOVERNOR_J1939_STATE_PREPROGRAMMED_SET_SPEED_2 = 11,  /* SPN 976 value 11 */
    POWER_TAKE_OFF_GOVERNOR_J1939_STATE_PREPROGRAMMED_SET_SPEED_3 = 12,  /* SPN 976 value 12 */
    POWER_TAKE_OFF_GOVERNOR_J1939_STATE_PREPROGRAMMED_SET_SPEED_4 = 13,  /* SPN 976 value 13 */
    POWER_TAKE_OFF_GOVERNOR_J1939_STATE_PREPROGRAMMED_SET_SPEED_5 = 14,  /* SPN 976 value 14 */
    POWER_TAKE_OFF_GOVERNOR_J1939_STATE_PREPROGRAMMED_SET_SPEED_6 = 15,  /* SPN 976 value 15 */
    POWER_TAKE_OFF_GOVERNOR_J1939_STATE_PREPROGRAMMED_SET_SPEED_7 = 16,  /* SPN 976 value 16 */
    POWER_TAKE_OFF_GOVERNOR_J1939_STATE_PREPROGRAMMED_SET_SPEED_8 = 17,  /* SPN 976 value 17 */
    POWER_TAKE_OFF_GOVERNOR_J1939_STATE_NOT_AVAILABLE = 31  /* SPN 976 value 31 - sent as 0x1F while the power take-off feature is off */
} POWER_TAKE_OFF_GOVERNOR_J1939_STATE;

typedef enum {
    INTAKE_AIR_HEATER_PHASE_KEY_ON = 0,  /* e2m IAH_Phase 0 = key on */
    INTAKE_AIR_HEATER_PHASE_SETUP = 1,  /* e2m IAH_Phase 1 = setup */
    INTAKE_AIR_HEATER_PHASE_PREHEAT = 2,  /* e2m IAH_Phase 2 = preheat */
    INTAKE_AIR_HEATER_PHASE_CRANK = 3,  /* e2m IAH_Phase 3 = crank */
    INTAKE_AIR_HEATER_PHASE_POSTHEAT = 4,  /* e2m IAH_Phase 4 = postheat */
    INTAKE_AIR_HEATER_PHASE_OFF = 5  /* e2m IAH_Phase 5 = off */
} INTAKE_AIR_HEATER_PHASE;

typedef enum {
    DRIVETRAIN_GEAR_RANGE_TOP_GEAR = 1,  /* drivetrain_ratio below top_gear_ratio_threshold */
    DRIVETRAIN_GEAR_RANGE_ONE_GEAR_DOWN = 2,  /* below gear_down_ratio_threshold but not top gear */
    DRIVETRAIN_GEAR_RANGE_LOWER = 3  /* at or above gear_down_ratio_threshold */
} DRIVETRAIN_GEAR_RANGE;

typedef enum {
    TRANSMISSION_PRESSURE_STATE_NORMAL_CURVE = 1,  /* governor_pressure_base_curve (e2m RE_Normal_Curve 'Gov press vs OSS for normal operating conditions'): cm848_selectGovernorPressureBaseCurve; cm848_selectGovernorPressureAntiHunt after a shift */
    TRANSMISSION_PRESSURE_STATE_FUEL_ECONOMY_CURVE = 2,  /* governor_pressure_fuel_economy_curve (RE_Fuel_Economy_Curve) below governor_pressure_fuel_economy_maximum_throttle: cm848_selectGovernorPressureBaseCurve */
    TRANSMISSION_PRESSURE_STATE_CRUISE_CURVE = 3,  /* governor_pressure_cruise_curve (RE_Cruise_Curve): cm848_selectGovernorPressureCruise */
    TRANSMISSION_PRESSURE_STATE_COLD_CURVE = 4,  /* governor_pressure_cold_curve (RE_Cold_Curve): cm848_selectGovernorPressureCold */
    TRANSMISSION_PRESSURE_STATE_WIDE_OPEN_THROTTLE_CURVE = 5,  /* governor_pressure_wide_open_throttle_curve (RE_WOT_Curve): the WOT / detent mode (cm848_selectGovernorPressureWideOpenThrottle / _Normal, cm848_runTransmissionControl) */
    TRANSMISSION_PRESSURE_STATE_WIDE_OPEN_THROTTLE_COLD_CURVE = 6,  /* governor_pressure_wide_open_throttle_cold_curve (RE_WOT_Cold_Curve): cm848_selectGovernorPressureCold */
    TRANSMISSION_PRESSURE_STATE_WIDE_OPEN_THROTTLE_1_2_HOLD = 7,  /* governor_pressure_wide_open_throttle_1_2_hold_pressure (RE_WOT_Hold_Pressure_1_2): holds 1st until the upshift point (or while the anti-hang timer runs) */
    TRANSMISSION_PRESSURE_STATE_WIDE_OPEN_THROTTLE_1_2_BOOST = 8,  /* governor_pressure_wide_open_throttle_1_2_boost_pressure (RE_WOT_Boost_Pressure_1_2): forces the 1-2 upshift */
    TRANSMISSION_PRESSURE_STATE_WIDE_OPEN_THROTTLE_2_3_HOLD = 9,  /* governor_pressure_wide_open_throttle_2_3_hold_pressure (RE_WOT_Hold_Pressure_2_3) */
    TRANSMISSION_PRESSURE_STATE_WIDE_OPEN_THROTTLE_2_3_BOOST = 10,  /* governor_pressure_wide_open_throttle_2_3_boost_pressure (RE_WOT_Boost_Pressure_2_3) */
    TRANSMISSION_PRESSURE_STATE_LOW_RANGE_CURVE = 11,  /* governor_pressure_low_range_curve (RE_Low_Range_Curve): cm848_selectGovernorPressureLowRange, cm848_runTransmissionControl */
    TRANSMISSION_PRESSURE_STATE_LOW_RANGE_1_2_HOLD = 12,  /* transmission_low_range_1_2_hold_pressure (RE_Low_Range_Hold_Pressure_1_2) */
    TRANSMISSION_PRESSURE_STATE_LOW_RANGE_1_2_BOOST = 13,  /* transmission_low_range_1_2_boost_pressure (RE_Low_Range_Boost_Pressure_1_2) */
    TRANSMISSION_PRESSURE_STATE_LOW_RANGE_2_3_HOLD = 14,  /* transmission_low_range_2_3_hold_pressure (RE_Low_Range_Hold_Pressure_2_3) */
    TRANSMISSION_PRESSURE_STATE_LOW_RANGE_2_3_BOOST = 15,  /* transmission_low_range_2_3_boost_pressure (RE_Low_Range_Boost_Pressure_2_3) */
    TRANSMISSION_PRESSURE_STATE_LOCKUP_BOOST = 16,  /* governor_pressure_lockup_boost (RE_Lockup_Boost 'Gov pressure target during lockup, to prevent downshift'): cm848_selectGovernorPressureLockupBoost, cm848_runTransmissionControl */
    TRANSMISSION_PRESSURE_STATE_2ND_GEAR_LOCKUP_BOOST = 17,  /* governor_pressure_2nd_gear_lockup_boost (RE_Lockup_Boost_2nd): cm848_runTransmissionControl; cm848_determineCurrentGearAndLockupInhibit compares with it */
    TRANSMISSION_PRESSURE_STATE_ANTI_HUNT_1_2_BOOST = 18,  /* transmission_anti_hunt_1_2_boost_pressure (RE_AH_Boost_Curve_1_2): forces the 1-2 upshift (cm848_selectGovernorPressureAntiHunt / _Normal) */
    TRANSMISSION_PRESSURE_STATE_ANTI_HUNT_2_3_BOOST = 19,  /* transmission_anti_hunt_2_3_boost_pressure (RE_AH_Boost_Curve_2_3) */
    TRANSMISSION_PRESSURE_STATE_ANTI_HUNT_1_2_HOLD = 20,  /* transmission_anti_hunt_1_2_hold_pressure (RE_Hold_Curve_1): prevents the 1-2 upshift */
    TRANSMISSION_PRESSURE_STATE_ANTI_HUNT_2_3_HOLD = 21,  /* transmission_anti_hunt_2_3_hold_pressure (RE_Hold_Curve_2) */
    TRANSMISSION_PRESSURE_STATE_MANUAL_2ND_CURVE = 22,  /* governor_pressure_manual_2nd_curve (RE_Manual_2nd_Curve) with the lever in 1 or 2 */
    TRANSMISSION_PRESSURE_STATE_OVERRIDE = 23,  /* governor_pressure_override_value (RE_Governor_Set_Override_Value) while governor_pressure_override_enable is set: cm848_selectGovernorPressureLockupBoost */
    TRANSMISSION_PRESSURE_STATE_EXHAUST_BRAKE_CURVE = 24  /* governor_pressure_exhaust_brake_curve with the exhaust brake switch (12) on at light throttle (cm848_selectGovernorPressureBaseCurve); cm848_applyConverterLockupSchedule, cm848_applyConverterUnlockConditions and cm848_determineCurrentGearAndLockupInhibit compare with it */
} TRANSMISSION_PRESSURE_STATE;

typedef enum {
    DIAGNOSTIC_MONITOR_STATE_NOT_RUN = 0,  /* e2m NORUN: the monitor has not run (initializers store 0) */
    DIAGNOSTIC_MONITOR_STATE_RUNNING = 1,  /* e2m RUN: the enable conditions hold and the test is running */
    DIAGNOSTIC_MONITOR_STATE_PASSED = 2,  /* e2m CMPPS (complete, passed): the monitor cleared its fault */
    DIAGNOSTIC_MONITOR_STATE_FAILED = 3,  /* e2m CMPFL (complete, failed): the monitor set its fault */
    DIAGNOSTIC_MONITOR_STATE_ABORTED = 4  /* e2m ABORT: a related fault or condition stopped the monitor */
} DIAGNOSTIC_MONITOR_STATE;

typedef enum {
    LIFT_PUMP_RUN_REASON_KEY_ON = 1,  /* Key on without starting (cm848_initializeLiftPumpControl): the pump stops after lift_pump_run_time_after_key_on */
    LIFT_PUMP_RUN_REASON_ENGINE_RUNNING = 2,  /* The engine ran (RUNNING or ENGINE_BRAKE): after it stops the pump runs lift_pump_run_time_after_running */
    LIFT_PUMP_RUN_REASON_ENGINE_CRANKING = 3  /* The engine cranked (CRANKING / REENTRY / JUMP_START): after it stops the pump runs lift_pump_run_time_after_cranking */
} LIFT_PUMP_RUN_REASON;

typedef enum {
    SERVICE_TOOL_TEST_NOT_RUN = 0,  /* e2m NOT_RUN: no service tool request (SCI command 0x25) */
    SERVICE_TOOL_TEST_RUNNING = 1,  /* e2m RUN: requested and every condition holds */
    SERVICE_TOOL_TEST_ABORTED = 2  /* e2m ABORT: requested but a condition fails; cm848_expireSciCommand37Tests then ends the request */
} SERVICE_TOOL_TEST_STATE;

typedef enum {
    END_OF_LINE_TEST_STEP_START = 0,  /* cm848_runEndOfLineTestStartStep: clears the flags of disabled tests and picks the first pending step */
    END_OF_LINE_TEST_STEP_OUTPUT_TESTS = 1,  /* cm848_runEndOfLineOutputTestStep: lift pump / lamp and relay / intake air heaters */
    END_OF_LINE_TEST_STEP_INTAKE_AIR_HEATER_RESULT = 2,  /* cm848_runEndOfLineIntakeAirHeaterResultStep: the two heater voltage drops */
    END_OF_LINE_TEST_STEP_ALTERNATOR_TEST = 3,  /* cm848_runEndOfLineAlternatorTestStep: cuts the field and checks the voltage falls */
    END_OF_LINE_TEST_STEP_RADIATOR_FAN_SPEED_NOISE = 4,  /* cm848_checkRadiatorFanSpeedSignalNoise */
    END_OF_LINE_TEST_STEP_MISFIRE_TEST = 5,  /* cm848_runEndOfLineMisfireTestStep */
    END_OF_LINE_TEST_STEP_FINAL_RESULT = 6,  /* cm848_runEndOfLineFinalResultStep: the plant tester's verdict on the MIL */
    END_OF_LINE_TEST_STEP_DONE = 7  /* no step runs */
} END_OF_LINE_TEST_STEP;

typedef enum {
    END_OF_LINE_OUTPUT_TEST_IDLE = 0,  /* a case that does nothing; no code stores 0 */
    END_OF_LINE_OUTPUT_TEST_START = 1,  /* starts the fuel control / alternator field / cooling fan actuator tests and turns the MIL on */
    END_OF_LINE_OUTPUT_TEST_LIFT_PUMP = 2,  /* output 53 for end_of_line_test_lift_pump_on_time; passes without P0629 / P0628 */
    END_OF_LINE_OUTPUT_TEST_RELAYS = 3,  /* the wait-to-start lamp (output 4) and the A/C clutch relay (output 38) for end_of_line_test_relay_on_time */
    END_OF_LINE_OUTPUT_TEST_BEFORE_INTAKE_AIR_HEATER_1 = 4,  /* end_of_line_test_relay_off_time, then heater 1 (output 43) on */
    END_OF_LINE_OUTPUT_TEST_INTAKE_AIR_HEATER_1_ON = 5,  /* heater 1 on for end_of_line_test_relay_on_time */
    END_OF_LINE_OUTPUT_TEST_BEFORE_INTAKE_AIR_HEATER_2 = 6,  /* end_of_line_test_relay_off_time, then heater 2 (output 44) on */
    END_OF_LINE_OUTPUT_TEST_INTAKE_AIR_HEATER_2_ON = 7,  /* heater 2 on, then the output test verdict (no DTC stored) */
    END_OF_LINE_OUTPUT_TEST_DONE = 8  /* done, or left early (engine not stopped / nothing pending) */
} END_OF_LINE_OUTPUT_TEST_STATE;

typedef enum {
    LOW_SPEED_GOVERNOR_REFERENCE_COOLANT = 0,  /* e2m COOLANT: low_speed_governor_coolant_temperature_speed_request */
    LOW_SPEED_GOVERNOR_REFERENCE_PARK_NEUTRAL = 1,  /* e2m PARK_NEU: low_speed_governor_park_or_drive_speed_request */
    LOW_SPEED_GOVERNOR_REFERENCE_EXTENDED_IDLE = 2,  /* e2m EXTENDED: low_speed_governor_extended_idle_speed_request */
    LOW_SPEED_GOVERNOR_REFERENCE_AIR_CONDITIONING = 3,  /* e2m AC: low_speed_governor_air_conditioning_speed_request (switch 13) */
    LOW_SPEED_GOVERNOR_REFERENCE_J1850 = 4,  /* e2m J1850: low_speed_governor_j1850_speed_request (the PCI idle speed request) */
    LOW_SPEED_GOVERNOR_REFERENCE_BASE = 5,  /* e2m BASE: low_speed_governor_base_reference_speed_cal; also whenever it differs from its boot copy */
    LOW_SPEED_GOVERNOR_REFERENCE_J1939 = 6,  /* e2m JCOMM: a J1939 TSC1 override with low_speed_governor_j1939_override_enable (the minimum idle speed) */
    LOW_SPEED_GOVERNOR_REFERENCE_MINIMUM = 7,  /* e2m MIN: the slew clamped the reference to low_speed_governor_minimum_idle_speed */
    LOW_SPEED_GOVERNOR_REFERENCE_MAXIMUM = 8,  /* e2m MAX: the slew clamped the reference to low_speed_governor_maximum_idle_speed */
    LOW_SPEED_GOVERNOR_REFERENCE_ALTITUDE = 9,  /* e2m ALTITUDE: the altitude speed (low_speed_governor_reference.altitude_speed) */
    LOW_SPEED_GOVERNOR_REFERENCE_SHIFT_IN_PROCESS = 10,  /* e2m SIP: a shift in process holds the desired speed (low_speed_governor_shift_in_process_timer) */
    LOW_SPEED_GOVERNOR_REFERENCE_TOOL = 11,  /* e2m TOOL: low_speed_governor_tool_speed_request (SCI SET RPM or the high pressure safety valve test) */
    LOW_SPEED_GOVERNOR_REFERENCE_MOVING = 12  /* e2m MOVING: low_speed_governor_moving_speed_request */
} LOW_SPEED_GOVERNOR_REFERENCE_SPEED_STATE;

typedef enum {
    ENGINE_RETARDER_COMMAND_SOURCE_NONE = 0,  /* No command (e2m NONE / NOT_COMM): cm848_selectEngineRetarderCommand with the allowed state NONE or no override in OVERRIDE_ONLY */
    ENGINE_RETARDER_COMMAND_SOURCE_J1939_OVERRIDE = 1,  /* A TSC1 torque control request (e2m JCOMMOVD / JC_OVRD): the override command */
    ENGINE_RETARDER_COMMAND_SOURCE_CRUISE = 2,  /* The cruise permission (e2m CRUISE): cm848_limitEngineRetarderPercentToCruisePermission */
    ENGINE_RETARDER_COMMAND_SOURCE_SWITCH = 3,  /* The operator selection (e2m SWITCH): cm848_limitEngineRetarderPercentToOperatorSelection */
    ENGINE_RETARDER_COMMAND_SOURCE_J1939_LIMIT = 4,  /* A TSC1 torque limit (e2m JCOMMLMT / JC_LIM): cm848_applyEngineRetarderTsc1Request */
    ENGINE_RETARDER_COMMAND_SOURCE_NOT_SET = 5,  /* Not set (e2m NOT_SET): the power-up value of the override and command sources */
    ENGINE_RETARDER_COMMAND_SOURCE_NO_OVERRIDE = 6  /* No override (e2m NOOVERDE / NO_OVRD): the override source without a TSC1 torque control request */
} ENGINE_RETARDER_COMMAND_SOURCE;

typedef enum {
    ENGINE_RETARDER_ALLOWED_NONE = 0,  /* No command may brake: the brake is not wanted or an exit condition holds */
    ENGINE_RETARDER_ALLOWED_OVERRIDE_ONLY = 1,  /* Only the override command (TSC1) may brake: the driver conditions (pedal / clutch / service brake) hold the rest off */
    ENGINE_RETARDER_ALLOWED_OVERRIDE_OR_NON_OVERRIDE = 2  /* The override or the non-override command may brake (the non-override command restarts at 101) */
} ENGINE_RETARDER_ALLOWED_STATE;

typedef enum {
    MAIN_INJECTION_TIMING_SELECTION_NO_ADJUSTMENT = 0,  /* No change to main_injection_timing (e2m NOADJUST) */
    MAIN_INJECTION_TIMING_SELECTION_CALCULATED = 1,  /* cm848_calculateMainInjectionTiming (e2m HPCRTMNG: the fuel system's timing); this truck */
    MAIN_INJECTION_TIMING_SELECTION_USER_OVERRIDE = 2,  /* user_commanded_injection_timing_cal (e2m USEROVRD) */
    MAIN_INJECTION_TIMING_SELECTION_CALCULATED_PLUS_USER_INCREMENT = 3  /* The calculated timing plus user_commanded_injection_timing_cal and the top dead center offset (e2m HPCRINCR) */
} MAIN_INJECTION_TIMING_SELECTION;

typedef enum {
    INJECTION_TIMING_COMBINATION_SUM = 0,  /* The sum of the components clamped to +-1024 (e2m 'add coolant and intake adv') */
    INJECTION_TIMING_COMBINATION_MAXIMUM = 1,  /* The largest component wins (e2m MAX WINS); this truck */
    INJECTION_TIMING_COMBINATION_MINIMUM = 2  /* The smallest component wins (e2m MIN WINS) */
} INJECTION_TIMING_COMBINATION_MODE;

typedef enum {
    SENSOR_VALUE_SOURCE_PRIMARY = 0,  /* e2m PRIMARY */
    SENSOR_VALUE_SOURCE_BACKUP = 1,  /* e2m BACKUP */
    SENSOR_VALUE_SOURCE_DEFAULT = 2  /* e2m DEFAULT */
} SENSOR_VALUE_SOURCE;

/* ---- Structures ---- */

typedef struct j1939_rx_msg_t j1939_rx_msg_t;
typedef struct tsc1_payload_t tsc1_payload_t;
typedef struct pci_diagnostic_response_t pci_diagnostic_response_t;
typedef struct commanded_throttle_state_t commanded_throttle_state_t;
typedef struct transmission_control_flags_t transmission_control_flags_t;
typedef struct transmission_shift_strategy_flags_t transmission_shift_strategy_flags_t;
typedef struct transmission_pressure_state_t transmission_pressure_state_t;
typedef struct cam_crank_sync_state_t cam_crank_sync_state_t;
typedef struct fuel_pressure_governor_state_t fuel_pressure_governor_state_t;
typedef struct engine_speed_state_t engine_speed_state_t;
typedef struct eeprom_header_t eeprom_header_t;
typedef struct low_speed_governor_reference_t low_speed_governor_reference_t;
typedef struct pci_link_state_t pci_link_state_t;
typedef struct j1587_fault_count_data_t j1587_fault_count_data_t;
typedef struct reflash_transfer_state_t reflash_transfer_state_t;
typedef struct boot_sci_session_state_t boot_sci_session_state_t;
typedef struct fault_bit_words_t fault_bit_words_t;
typedef struct wastegate_duty_controller_state_t wastegate_duty_controller_state_t;
typedef struct egr_flow_estimate_terms_t egr_flow_estimate_terms_t;
typedef struct delay_line_t delay_line_t;
typedef struct combustion_reference_state_t combustion_reference_state_t;
typedef struct charge_flow_estimate_terms_t charge_flow_estimate_terms_t;
typedef struct engine_speed_limit_arbitration_t engine_speed_limit_arbitration_t;
typedef struct operating_mode_governor_output_t operating_mode_governor_output_t;
typedef struct transmission_lockup_timers_t transmission_lockup_timers_t;
typedef struct j1939_msg_hdr_t j1939_msg_hdr_t;
typedef struct parameter_response_t parameter_response_t;
typedef struct calterm_protocol_t calterm_protocol_t;
typedef struct insite_protocol_t insite_protocol_t;
typedef struct sensor_channel_config_t sensor_channel_config_t;
typedef struct sensor_channel_state_t sensor_channel_state_t;
typedef struct cruise_governor_gain_set_t cruise_governor_gain_set_t;
typedef struct second_order_filter_state_t second_order_filter_state_t;
typedef struct engine_retarder_brake_type_t engine_retarder_brake_type_t;
typedef struct ema_filter_state_t ema_filter_state_t;
typedef struct high_speed_governor_gain_set_t high_speed_governor_gain_set_t;
typedef struct q16_fixed_point_t q16_fixed_point_t;
typedef struct dma_descriptor_t dma_descriptor_t;
typedef struct memory_patch_entry_t memory_patch_entry_t;
typedef struct j1939_pgn_handler_entry_t j1939_pgn_handler_entry_t;
typedef struct j1939_tx_msg_t j1939_tx_msg_t;
typedef struct j1939_acknowledgement_payload_t j1939_acknowledgement_payload_t;
typedef struct j1939_ack_msg_t j1939_ack_msg_t;
typedef struct eeprom_param_t eeprom_param_t;
typedef struct param_lookup_args_t param_lookup_args_t;
typedef struct can_param_msg_t can_param_msg_t;
typedef struct scheduler_phase_slot_t scheduler_phase_slot_t;
typedef struct ad_sensor_config_t ad_sensor_config_t;
typedef struct sensor_fault_config_t sensor_fault_config_t;
typedef struct sensor_debounce_state_t sensor_debounce_state_t;
typedef struct cummins_data_plate_t cummins_data_plate_t;
typedef struct memory_operation_request_t memory_operation_request_t;
typedef struct j1939_source_addresses_t j1939_source_addresses_t;
typedef struct network_type_switches_t network_type_switches_t;
typedef struct diag_transfer_state_t diag_transfer_state_t;
typedef struct diag_service_request_t diag_service_request_t;
typedef struct circular_buffer_t circular_buffer_t;
typedef struct address_range_entry_t address_range_entry_t;
typedef struct fuel_limit_arbitration_t fuel_limit_arbitration_t;
typedef struct engine_control_flags_t engine_control_flags_t;
typedef struct high_rpm_protection_t high_rpm_protection_t;
typedef struct oil_pressure_protection_t oil_pressure_protection_t;
typedef struct fault_persistence_counters_t fault_persistence_counters_t;
typedef struct fault_status_registers_t fault_status_registers_t;
typedef struct fault_latch_registers_t fault_latch_registers_t;
typedef struct engine_operating_mode_t engine_operating_mode_t;
typedef struct rpm_fuel_protection_t rpm_fuel_protection_t;
typedef struct timing_mode_control_t timing_mode_control_t;
typedef struct j1939_powertrain_messages_received_t j1939_powertrain_messages_received_t;
typedef struct param_id_entry_t param_id_entry_t;
typedef struct ef00_dispatch_entry_t ef00_dispatch_entry_t;
typedef struct diag_dispatch_entry_t diag_dispatch_entry_t;
typedef struct executive_frame_timing_t executive_frame_timing_t;
typedef struct j1939_dm13_requester_slot_t j1939_dm13_requester_slot_t;
typedef struct combustion_chi_maximum_fuel_points_t combustion_chi_maximum_fuel_points_t;
typedef struct fault_entry_t fault_entry_t;
typedef struct usiu_pit_t usiu_pit_t;
typedef struct usiu_clock_t usiu_clock_t;
typedef struct usiu_memc_t usiu_memc_t;
typedef struct siu_gpio_data_register_t siu_gpio_data_register_t;
typedef struct discrete_line_image_t discrete_line_image_t;
typedef struct mios_port_data_register_t mios_port_data_register_t;
typedef struct j1939_powertrain_control_state_t j1939_powertrain_control_state_t;
typedef struct tsc1_source_configuration_t tsc1_source_configuration_t;
typedef struct tpua_module_regs_t tpua_module_regs_t;
typedef struct tpub_module_regs_t tpub_module_regs_t;
typedef struct mios_mpwmsm_t mios_mpwmsm_t;
typedef struct mios_mdasm_t mios_mdasm_t;
typedef struct qadc64_regs_t qadc64_regs_t;
typedef struct tpu3_ch_params_t tpu3_ch_params_t;
typedef struct qadc64b_regs_t qadc64b_regs_t;
typedef struct tpua_ch1_params_t tpua_ch1_params_t;
typedef struct tpua_ch9_params_t tpua_ch9_params_t;
typedef struct tpua_ch12_params_t tpua_ch12_params_t;
typedef struct tpua_ch14_params_t tpua_ch14_params_t;
typedef struct tpub_ch0_params_t tpub_ch0_params_t;
typedef struct tpub_ch11_params_t tpub_ch11_params_t;
typedef struct tpub_ch14_params_t tpub_ch14_params_t;
typedef struct mios_mmcsm_b_t mios_mmcsm_b_t;
typedef struct toucan_module_registers_t toucan_module_registers_t;
typedef struct toucan_message_buffer_t toucan_message_buffer_t;
typedef struct qsmcm_sci1_regs_t qsmcm_sci1_regs_t;
typedef struct qsmcm_qspi_ctrl_t qsmcm_qspi_ctrl_t;
typedef struct qsmcm_recram_t qsmcm_recram_t;
typedef struct qsmcm_txram_t qsmcm_txram_t;
typedef struct keyon_flags_t keyon_flags_t;
typedef struct can_ring_state_t can_ring_state_t;
typedef struct diag_write_request_state_t diag_write_request_state_t;
typedef struct can_slot_range_t can_slot_range_t;
typedef struct can_rx_channel_t can_rx_channel_t;
typedef struct system_initialization_flags_t system_initialization_flags_t;
typedef struct eeprom_xfer_state_t eeprom_xfer_state_t;
typedef struct eeprom_block_tracking_t eeprom_block_tracking_t;
typedef struct j1939_transport_transmit_session_t j1939_transport_transmit_session_t;
typedef struct j1939_tp_pause_t j1939_tp_pause_t;
typedef struct diagnostic_response_message_t diagnostic_response_message_t;
typedef struct boot_state_t boot_state_t;
typedef struct mios_mpiosm_t mios_mpiosm_t;
typedef struct mios1_isr_t mios1_isr_t;
typedef struct diag_clear_flags_t diag_clear_flags_t;
typedef struct j1939_ccss_tx_payload_t j1939_ccss_tx_payload_t;
typedef struct pci_message_descriptor_t pci_message_descriptor_t;
typedef struct qspi_job_t qspi_job_t;
typedef struct qspi_device_slot_t qspi_device_slot_t;
typedef struct qspi_job_queue_t qspi_job_queue_t;
typedef struct memory_region_t memory_region_t;
typedef struct j1939_input_signal_descriptor_t j1939_input_signal_descriptor_t;
typedef struct output_read_back_fault_bits_t output_read_back_fault_bits_t;
typedef struct monitor_condition_bits_t monitor_condition_bits_t;
typedef struct logical_output_request_bits_16_to_23_t logical_output_request_bits_16_to_23_t;
typedef struct qadc_channel_dispatch_entry_t qadc_channel_dispatch_entry_t;
typedef struct fault_definition_t fault_definition_t;
typedef struct fault_monitor_group_t fault_monitor_group_t;
typedef struct monitor_calibrated_condition_t monitor_calibrated_condition_t;
typedef struct engine_overspeed_event_t engine_overspeed_event_t;
typedef struct dtc_list_t dtc_list_t;
typedef struct fault_state_t fault_state_t;
typedef struct pci_controller_command_word_t pci_controller_command_word_t;
typedef struct end_of_line_test_settings_t end_of_line_test_settings_t;
typedef struct algorithm_enable_flags_12_t algorithm_enable_flags_12_t;
typedef struct algorithm_enable_flags_18_t algorithm_enable_flags_18_t;
typedef struct algorithm_enable_flags_3_t algorithm_enable_flags_3_t;
typedef struct algorithm_enable_flags_4_t algorithm_enable_flags_4_t;
typedef struct algorithm_enable_flags_11_t algorithm_enable_flags_11_t;
typedef struct algorithm_enable_flags_1_t algorithm_enable_flags_1_t;
typedef struct algorithm_enable_flags_2_t algorithm_enable_flags_2_t;
typedef struct algorithm_enable_flags_5_t algorithm_enable_flags_5_t;
typedef struct algorithm_enable_flags_6_t algorithm_enable_flags_6_t;
typedef struct algorithm_enable_flags_13_t algorithm_enable_flags_13_t;
typedef struct algorithm_enable_flags_19_t algorithm_enable_flags_19_t;
typedef struct algorithm_enable_flags_20_t algorithm_enable_flags_20_t;
typedef struct algorithm_enable_flags_21_t algorithm_enable_flags_21_t;
typedef struct algorithm_enable_flags_25_t algorithm_enable_flags_25_t;
typedef struct algorithm_enable_flags_27_t algorithm_enable_flags_27_t;
typedef struct algorithm_enable_flags_28_t algorithm_enable_flags_28_t;
typedef struct algorithm_enable_flags_29_t algorithm_enable_flags_29_t;
typedef struct algorithm_enable_flags_31_t algorithm_enable_flags_31_t;
typedef struct algorithm_enable_flags_32_t algorithm_enable_flags_32_t;
typedef struct algorithm_enable_flags_40_t algorithm_enable_flags_40_t;
typedef struct algorithm_enable_flags_42_t algorithm_enable_flags_42_t;
typedef struct algorithm_enable_flags_43_t algorithm_enable_flags_43_t;
typedef struct algorithm_enable_flags_41_t algorithm_enable_flags_41_t;
typedef struct piecewise_linear_gain_t piecewise_linear_gain_t;
typedef struct derivative_gain_t derivative_gain_t;
typedef struct low_speed_governor_gain_set_t low_speed_governor_gain_set_t;
typedef struct all_speed_governor_gain_set_t all_speed_governor_gain_set_t;
typedef struct j1939_control_session_t j1939_control_session_t;
typedef struct sci_output_test_timers_t sci_output_test_timers_t;
typedef struct logical_output_request_bits_8_to_15_t logical_output_request_bits_8_to_15_t;
typedef struct logical_output_request_bits_32_to_39_t logical_output_request_bits_32_to_39_t;
typedef struct logical_output_request_bits_40_to_47_t logical_output_request_bits_40_to_47_t;
typedef struct logical_output_request_bits_48_to_55_t logical_output_request_bits_48_to_55_t;
typedef struct logical_output_request_bits_64_to_71_t logical_output_request_bits_64_to_71_t;
typedef struct logical_output_request_bits_72_to_79_t logical_output_request_bits_72_to_79_t;
typedef struct switch_input_state_t switch_input_state_t;
typedef struct engine_protection_fault_log_entry_t engine_protection_fault_log_entry_t;
typedef struct engine_protection_channel_configuration_t engine_protection_channel_configuration_t;
typedef struct engine_protection_channel_state_t engine_protection_channel_state_t;
typedef struct engine_protection_channel_history_t engine_protection_channel_history_t;
typedef struct j1939_pgn65251_payload_t j1939_pgn65251_payload_t;
typedef struct discrete_output_read_back_counters_t discrete_output_read_back_counters_t;
typedef struct j1939_pgn65249_payload_t j1939_pgn65249_payload_t;
typedef struct j1939_pgn65259_payload_t j1939_pgn65259_payload_t;
typedef struct j1939_pgn65242_payload_t j1939_pgn65242_payload_t;
typedef struct j1939_broadcast_transmit_session_t j1939_broadcast_transmit_session_t;

struct j1939_rx_msg_t {
    uint8_t priority_dp_flags;  /* J1939 priority/reserved/data-page bits packed from upper CAN ID */
    uint8_t pgn_pf;  /* PDU Format - high byte of PGN (0xEF=EF00 0xDF=DF00 0x00=TSC1 etc) */
    uint8_t dest_address;  /* Destination address (PDU1) or PGN low byte (PDU2); compared against j1939_source_address to filter incoming messages */
    uint8_t source_address;  /* J1939 source address of sending node */
    uint16_t data_length;  /* CAN DLC - payload byte count (handlers expect 8 for TSC1/ETC1) */
    byte* data_pointer;  /* Pointer to inline_data below (always this+10 per processCanReceiveBuffer) */
    uint8_t inline_data[8];  /* CAN payload bytes copied directly from TouCAN mailbox data registers */
};

struct tsc1_payload_t {
    uint8_t control_byte;  /* Override control mode (bits 0-1) priority (bits 4-5) tx_rate (bits 6-7) */
    uint16_t requested_speed;  /* Requested speed/speed limit - little-endian 0.125 rpm/bit */
    uint8_t requested_torque;  /* Requested torque/torque limit - 1pct/bit offset -125pct */
    uint8_t reserved[4];  /* Reserved bytes 4-7 per J1939-71 */
};

struct pci_diagnostic_response_t {
    uint8_t source_address;  /* Reply byte 1: the ECM's own PCI address (pci_ecm_address 0x10) - comment fix only: it is the responder not a J1939 destination */
    uint8_t response_service_id;  /* Reply byte 2: request service + 0x40 (60 / 67 / 68 / 69 / E1 / E4) or 0x7F for a negative reply (was service_id) */
    uint8_t data_1;  /* Reply byte 3: sub-function echo (0x27: 1 or 2 / 0x28: request byte 3) / the refused service in a 7F reply / 0xA4 memory byte 1 / 0xA1 the byte written (was subfunction) */
    uint8_t data_2;  /* Reply byte 4: the 7F reply code (0x11 / 0x12 / 0x33 / 0x35 / 0x36 / 0x37 / 0x40 / 0x42 / 0x52 / 0x90 / 0xC0) / seed high byte / 0xA4 memory byte 2 / 0x62 in the E1 reply (was error_code) */
    uint8_t data_3;  /* Reply byte 5: seed low byte / 0xA4 memory byte 3 / otherwise 0 - never a length (was data_length) */
    uint8_t data_4_to_7[4];  /* Reply bytes 6 on: element 0 = 0xA4 memory byte 4; elements 1-3 unused; element 4 (0x40b49b) is the TX[10] descriptor status byte (0x80 at init) - split into data_4_to_7 byte[4] + status (was data) */
    uint8_t status;  /* PCI TX[10] descriptor status byte (cm848_initializePciMessageStatusBytes writes 0x80 / cm848_completePciFrame ORs the completion bits in) */
    uint16_t transmit_timer;  /* This buffer is pci_transmit_message_table[10] (header 0x26 diagnostic response) and this word is its timer (sth): writing 1 queues the response on the PCI bus (was response_pending byte) */
};

struct commanded_throttle_state_t {
    uint16_t commanded_throttle;  /* e2m 1047 +0 Commanded_Throttle 'VALIDATED PERCENT THROTTLE COMMANDED BY DRIVER' (0-400 = 0-100 %): the calculated commanded throttle, or the alternate throttle while a claim holds (cm848_selectCommandedThrottle); read by the governors, cruise and the transmission logic (was calculated) | earlier note: Final calculated fuel demand value */
    uint16_t idle_validation_state;  /* cm848_evaluateIdleValidationSwitches: 0 at-idle switch + pedal at idle / 1 off-idle switch + pedal above idle / 2 at-idle switch but pedal above the band / 3 off-idle switch but pedal below the band / 4 both switches + pedal outside the band / 5 no switch + pedal above the band / 6 no switch + pedal below the band / 7 equal switches + pedal inside the band / 8 valid pair + pedal between idle and the band edge (was mode) | e2m 1047 +2 Throttle_ID 'identifies different combinations of the throttle pot and switches' */
    uint16_t accelerator_off_idle;  /* 1 = accelerator demand off idle: idle validation states 1 / 3 / 5 / pedal sensor above threshold / J1939 SPN 558 / or speed-governor demand above cruise_governor_demand_enable_threshold_cal while fuel_demand_enable_flag; the EEC2 broadcast reports it as SPN 558 (was enable_flag) | e2m 1047 +4 Throttle_Status 'Status of the idle validation switch IDLE = 0; NOT_IDLE = 1' */
    uint16_t throttle_transition_state;  /* e2m 1047 +6 Transition_State 'state of potentiometer and idle validation switch readings': 0-3, advanced by cm848_updateThrottleTransitionState; cm848_monitorAcceleratorPedalIdleValidationFaults acts in state 3. No rate limiter (was rate_limiter_state) | earlier note: Rate limiter state machine value */
    uint16_t throttle_minimum_confidence_counter;  /* e2m 1047 +8 Current_Confidence_Counter (MSEC) 'CURRENT TIME OF COUNTER THAT MUST TIME OUT BEFORE A NEW THROTTLE_MIN IS SET': loaded with accelerator_pedal_minimum_learning_confidence_count_limit when a lower pedal reading starts a candidate (throttle_minimum_candidate), counted down by readings within the confidence band - the candidate becomes the Throttle_Min at 0 - and up by readings above it (was rate_delta) | earlier note: Fuel demand rate of change delta */
    uint16_t throttle_minimum;  /* e2m 1047 +A Throttle_Min 'minimum Sampled_Throttle detected' (pedal counts): the learned closed pedal reading (cm848_learnAcceleratorPedalAutozero; accelerator_pedal_autozero_cal = it + accelerator_pedal_autozero_offset); accelerator_pedal_highest_valid_minimum + 4 at boot and while the pedal has a fault (was throttle_based) | earlier note: Throttle-based fuel demand component */
    uint16_t alternate_throttle;  /* e2m 1047 +C Alternate_Throttle 'Percent throttle overriden by other algorithm': the throttle a claimer sets with its priority (remote_accelerator_pedal_sensor_filtered from cm848_claimRemoteThrottleOverride, 0 from cm848_claimAcceleratorInterlockThrottleOverride) (was override_value) | earlier note: Diagnostic override fuel demand value */
    uint16_t alternate_throttle_priority;  /* e2m 1047 +E Throttle_Selection 'Alternate throttle priority #, 0=normal, 9=high priority': each claimer takes the alternate throttle only above the priority already set; cm848_selectCommandedThrottle uses alternate_throttle while it is non-zero and clears it every pass (was override_priority) | earlier note: The priority of the throttle override that holds it: each claimer (cm848_claimAcceleratorInterlockThrottleOverride / cm848_claimRemoteThrottleOverride) takes the override when its priority is higher and writes override_value; 0 = no override (was override_active - not a 1 / 0 flag; round 5) */
    uint16_t calculated_commanded_throttle;  /* e2m 1047 +10 Calculated_Commanded_Throttle 'Intermediate calculated value of commanded throttle based on standard input' (0-400): from cm848_calculateCommandedThrottleFromPedal, accelerator_pedal_dual_channel_validated_demand or channel 13 (cm848_selectCommandedThrottle). Not rate limited (was rate_limited) | earlier note: Rate-limited fuel demand output */
    uint16_t selected_alternate_throttle_priority;  /* e2m 1047 +12 Alternate_Throttle_Selection_State 'State of selected alternate throttle priority': the alternate_throttle_priority that set the commanded throttle this pass, 0 when none did (cm848_selectCommandedThrottle). It never counts down (was override_countdown) | earlier note: Override timeout countdown (offset 0x12) */
    uint16_t sampled_frequency_throttle;  /* e2m 1047 +14 Sampled_Frequency_Throttle 'requested throttle after being lin. and fil. via freq. thr. algorithm' (%THROTTLE); no access in the .cpp (was reserved_14) | earlier note: Gap/reserved (0x58e-0x590) */
    uint16_t frequency_throttle_active_flag;  /* e2m 1047 +16 Frequency_Throttle_Active 'indicates frequency throttle has been enabled'; no access in the .cpp (was reserved_16) | earlier note: Gap/reserved (0x590-0x592) */
    uint16_t commanded_throttle_delta;  /* e2m 1047 +18 Delta_Throttle 'Percent Throttle change per execution': commanded_throttle minus the previous pass's, kept in commanded_throttle_previous (cm848_selectCommandedThrottle) (was delta) | earlier note: Fuel demand delta for rate calculations */
    uint16_t commanded_throttle_delta_filtered;  /* e2m 1047 +1A Filtered_Delta_Throttle 'Percent Throttle change per execution with filter applied': commanded_throttle_delta through commanded_throttle_delta_filter (e2m 1048 +1C Delta_Throttle_Filter_Constant) (was delta_filtered) | earlier note: Filtered fuel demand delta */
};

struct transmission_control_flags_t {
    uint8_t request_flags;  /* e2m 8C19 +0 RE_Trans_Flag1 (RE_Request_4_3 / RE_Request_3_4 / RE_CT_Unlock / RE_In_Cal / RE_Init_Timer_Complete / RE_Lockup_OD_Off_Flag / RE_Lockup_TC_Mimic / RE_Offset_Learning_Enable): bit 1 = the 4-3 request and bit 2 = the 3-4 request (set by the cruise / normal / low range shift lines, cleared by cm848_processOverdriveSwitchAndShift); bit 6 = the converter unlock request that blocks lockup (set by the exhaust brake inhibit timeout, the closed-throttle unlock and a brake transition) */
    uint8_t mode_flags;  /* e2m 8C19 +1 RE_Trans_Flag2 (RE_Cruise_Active / RE_Decel_Mode_Active / RE_Low_Range / RE_Relock / RE_Previous_Brake_Switch / RE_Init_Cal_Complete / RE_Prev_Calc_Neg): bit 0 = cruise decel mode (set with the cruise decel 4-3, cleared with its 3-4), bit 2 = transfer-case low range, bit 4 = cruise active (follows cruise_control_engaged_flag); bits 3 / 5 are set by the brake-transition unlock */
    uint8_t state_flags;  /* e2m 8C19 +2 RE_Trans_Flag3 (RE_Forced_2nd_Gear_ID / RE_High_Pressure / RE_Upshift_3_4 / RE_Service_Lockup_Switch / RE_Force_4_Gear_Identification / RE_Launch_NV / RE_Low_Range_NV): bit 1 = the gear forced to 2nd (cm848_determineCurrentGearAndLockupInhibit), bit 2 = the lockup boost hold (RE_High_Pressure; cm848_selectGovernorPressureLockupBoost), bit 5 is read with the lockup / unlock service output speed limits, so it is probably RE_Service_Lockup_Switch (no setter found in the decompile), bit 7 = a 3-4 upshift in progress */
    uint8_t overdrive_flags;  /* e2m 8C19 +3 RE_OD_Flags (RE_OD_Inhibit / RE_OD_Toggle / RE_OD_Mimic / RE_OD_Disable_Cold / RE_OD_Disable_Hot / RE_Inhibit_3_4_Cruise / RE_Quick_Key_On_Toggle / RE_T_Cool_BP_Kit) | earlier note: bit 0 cruise 4-3 request / 1 cold lockout also checks the slot 69 temperature (config) / 2 overdrive-off switch released / 3 overdrive solenoid off / 5 overdrive off by switch / 6 overdrive locked out above 270 deg F / 7 overdrive locked out below 19.4 deg F (was overtemp_flags) (Medium confidence) */
    uint8_t axle_ratio_learning_flags;  /* e2m 8C19 +4 RE_Nvratio_Learn_Flags (the N / V (engine speed / vehicle speed) ratio learning flags): only cm848_learnOutputSpeedToVehicleSpeedRatio uses it (bit 0 set / tested) */
    uint8_t limp_home_flags_1;  /* e2m 8C19 +5 RE_Limp_Flags1 'Contains transmission control limp-home mode flags'. Bits: 0x01 RE_Trans_Relay_Circuit_Open ('transmission power relay is open-circuit'): fault 137 P0882 / 0x02 RE_TPS_Elect_Limp ('throttle signal is invalid'): the pedal faults P2121 / P2122 / P2123 / P2127 / P2128 and P0698 / 0x04 RE_Cltemp_Elect_Limp: no writer or reader in this build. Set and cleared by cm848_updateTransmissionLimpHomeFlags; bit 0 drops the transmission relay (cm848_updateTransmissionRelayRequest), bit 1 is read by cm848_runTransmissionControl */
    uint8_t limp_home_flags_2;  /* e2m 8C19 +6 RE_Limp_Flags2 'Contains transmission control limp-home mode flags'. Bits: 0x01 RE_Governor_Press_Sol_Circuit: fault 351 P0748 / 0x02 RE_Overdrive_Solenoid_Circuit: fault 139 P0973 (both set and cleared by cm848_updateTransmissionLimpHomeFlags; either drops the transmission relay) / 0x04 RE_TPS_Rat_Limp: read by cm848_runTransmissionControl, no writer in this build */
    uint8_t limp_home_flags_3;  /* e2m 8C19 +7 RE_Limp_Flags3 'Contains transmission control limp-home mode flags'. Bits: 0x01 RE_Gov_Sensor_Limp_Circuit: faults 299 / 300 P0868 / P0869, or governor_pressure_rationality_monitor_state = FAILED (P1762); set and cleared by cm848_updateTransmissionLimpHomeFlags; cm848_determineCurrentGearAndLockupInhibit turns it (with limp_home_flags_4 bits 0 / 2) into limp_home_and_temperature_flags bit 0 / 0x02 RE_Trans_Sump_Temp_Rationality: no writer or reader in this build | earlier note: bit 0 blocks lockup in cm848_determineCurrentGearAndLockupInhibit (with limp_home_flags_4 bit 0) */
    uint8_t limp_home_flags_4;  /* e2m 8C19 +8 RE_Limp_Flags4 'Contains transmission control limp-home mode flags'. Bits: 0x01 RE_Gov_Sensor_Limp_Offset / 0x04 RE_GCST_Limp ('a problem with the GCST circuit'; GCST is not expanded in the e2m or the DRB database): read with limp_home_flags_3 bit 0 by cm848_determineCurrentGearAndLockupInhibit, no writer in this build / 0x02 RE_Spd_Rat_Limp and 0x08 RE_Trans_Sump_Temp_Circuit: no writer or reader / 0x10 RE_Lockup_Converter_Clutch_Solenoid_Circuit: fault 141 P2769 (drops the transmission relay) / 0x20 RE_OSS_Limp: P0720, from cm848_monitorTransmissionOutputSpeedSensor | earlier note: Fault-active flags byte, updated with | / & masks (so a byte, not a bitfield: Ghidra 12.1 prints those updates as pieces). Bits: 0x01 unnamed: tested (& 1) in cm848_determineCurrentGearAndLockupInhibit (lbz @ 0x34370, .cpp 33439; ORed with reserved_07 bit 0 into transmission_shift_strategy_flags_t.limp_home_and_temperature_flags bit 0) but no store in either bank sets it | 0x04 unnamed: tested (& 4) together with bit 0 in the same place; never set | 0x10 fault 141 active: set / cleared every pass from fault_detected_cal.faults_128_to_143 & 0x2000 = fault 141 in cm848_updateTransmissionLimpHomeFlags (stb @ 0x34eac; ROM 0x5985a slot 133 = P2769, a hint only); tested (& 0x10) in cm848_updateTransmissionRelayRequest (lbz @ 0x34a60), where it keeps logical output request 16 from being set | 0x20 output speed sensor fault active: set with fault 320 (P0720) and cleared with it in cm848_monitorTransmissionOutputSpeedSensor (stb @ 0x3dee4 / 0x3df60, | 0x20 / & 0xdf); read by cm848_calculateTransmissionOutputSpeed (lbz @ 0x3f768: substitutes vehicle_speed x the default or learned ratio), cm848_learnOutputSpeedToVehicleSpeedRatio (lbz @ 0x35e40: no learning while set) and cm848_updateTransmissionConditionFlags (lbz @ 0x34430: skips the transfer-case low-range test); bit 5 (0x20) = RE_OSS_Limp, set and cleared by the P0720 monitor (cm848_monitorTransmissionOutputSpeedSensor) */
    uint8_t low_range_boost_flags;  /* e2m 8C19 +9 RE_Low_Range_Boost_1_2 / RE_Low_Range_Boost_2_3 (the governor pressure is being raised to cause the 1-2 / 2-3 shift in low range): bits 0 / 1, cleared by cm848_initializeTransmissionShiftLogic (& 0xfc) */
};

struct transmission_shift_strategy_flags_t {
    uint8_t wide_open_throttle_flags;  /* e2m 8C19 +A WOT flags (RE_Trans_WOT / RE_WOT_Anti_Hang_Flag / RE_WOT_Boost_1_2 / RE_WOT_Boost_2_3 / RE_WOT_2LU_Flag / RE_WOT_2LU_Init_Flag / RE_WOT_Hung_Shift): bit 4 = the anti-hang timer is armed (RE_WOT_Anti_Hang_Flag), bits 3 / 5 go with the WOT 1-2 / 2-3 boosts (cm848_selectGovernorPressureWideOpenThrottle) | earlier note: Governor pressure / wide open throttle status byte, updated with | / & masks (so a byte, not a bitfield). Bits 0x10 / 0x08 are unproven guesses. Bits: 0x80 wide open throttle flag: mask 0x80: set by cm848_updateTransmissionConditionFlags when commanded_throttle_state_t.commanded_throttle exceeds transmission_wide_open_throttle_set_threshold, cleared (& 0x1f, which also clears bits 5 and 6, and & 0x7f in cm848_initializeTransmissionControl) when it falls below transmission_wide_open_throttle_clear_threshold; cm848_runTransmissionControl calls cm848_selectGovernorPressureWideOpenThrottle only while it is set and the base / normal curve handlers otherwise (decompile line 32865). | 0x40 gear 1 pressure elevated flag: mask 0x40: set (| 0x40) with governor_pressure_wide_open_throttle_1_2_boost_pressure (status code 8) in gear 1; cleared (& 0xbf) when the pressure returns to the curve; read in the gear 2 branch to run the gear 1 learned gain update and cleared there by & 0xb7. | 0x20 gear 2 pressure elevated flag: mask 0x20: set (flags & 0xef | 0x20 / | 0x20) when governor_pressure_wide_open_throttle_2_3_boost_pressure is commanded (status code 10) in gear 2; cleared (& 0xdf) when the pressure returns to the curve; read in the gear 3 branch, where governor_pressure_wide_open_throttle_boost_timer == 0 triggers the gear 2 learned gain update and & 0x97 clears the elevation bits; also cleared in gear 1 (bVar3 = flags & 0xdf). | 0x10 unnamed: guess (not proven, so reserved): an elevation delay timer armed flag - mask 0x10: set (| 0x10) together with governor_pressure_wide_open_throttle_anti_hang_timer = governor_pressure_wide_open_throttle_anti_hang_time when engine speed sits between governor_pressure_wide_open_throttle_anti_hang_engine_speed and the margin; tested to wait for governor_pressure_wide_open_throttle_anti_hang_timer to reach 0 before the elevation; cleared (& 0xef) by the elevation. Medium confidence. | 0x08 unnamed: guess (not proven, so reserved): a pressure elevation by timer flag - mask 8, cm848_selectGovernorPressureWideOpenThrottle: set (flags & 0xef | 8, lines 32266-32267 / LAB_00031ba8) when the elevated target is applied after the delay timer ran out; cleared (& 0xf7) when the delay timer is armed; while it is set the gain learning of the gear 1 / gear 2 learned gain is skipped ((flags & 8) == 0 guards both learning blocks). Medium confidence. | 0x01 unnamed: no mask uses bit 0 in any of the 43 uses (0x97 / 0xb7 / 0xef / 0x1f / 0xdf / 0xbf / 0x7f only preserve it) */
    uint8_t run_fuel_mode_flags;  /* e2m 8C19 +B RE_Run_Fuel_Mode (Indicates run fuel mode is active): no access found */
    uint8_t anti_hunt_flags;  /* e2m 8C19 +C anti-hunt / detent flags (RE_AH_Boost_1_2 / RE_AH_Boost_2_3 / RE_Anti_Hunt / RE_Detent / RE_Detent_2_3 / RE_Rollstest): bit 7 = the anti-hunt 1-2 boost and bit 6 = the 2-3 boost (cm848_selectGovernorPressureNormal), bit 4 = throttle past the detent (transmission_throttle_detent_set_threshold) */
    uint8_t output_shaft_speed_flags;  /* e2m 8C19 +D RE_OSS_Too_Slow (Indicates output shaft speed too slow): no access found */
    uint8_t actuator_test_flags;  /* e2m 8C19 +E RE_Act_Test_Running (Indicates service tool request for trans solenoid test): bit 0, set and cleared by cm848_sciCommand19OutputTestCallback */
    uint8_t service_test_request_flags;  /* e2m 8C19 +F RE_Cmd25_3_4_Shift / RE_Cmd25_Gov_Press / RE_Cmd25_TCC (service tool requests to test the OD solenoid / the pressure control / the lockup solenoid): bits 0-2; set by cm848_sciCommand37Callback; the shift and lockup logic skip their work while any is set - bit 0 is set by all three tests (the governor pressure solenoid under test control: test 0x14 drives it and 0x15 / 0x16 hold it at its minimum duty) / bit 1 = the converter clutch solenoid test (0x15 / output 18) / bit 2 = the overdrive solenoid test (0x16 / output 17); cm848_expireSciCommand37Tests clears bit 0 / bits 0-1 / bits 0 and 2 at each test's timeout (round 13) */
    uint8_t reserved_06;  /* Reserved */
    uint8_t limp_home_and_temperature_flags;  /* e2m 8C19 +11 RE_Governor_3rd_Gear_Default / RE_Trans_Temp_Initial_Obtained (limp-home 3rd gear mode / the first transmission temperature reading obtained): cm848_selectTransmissionTemperatureInUse / cm848_resetTransmissionTemperatureValidation, cm848_controlGovernorPressureSolenoid, cm848_calibrateGovernorPressureSensorOffset */
};

struct transmission_pressure_state_t {
    TRANSMISSION_PRESSURE_STATE pressure_state;  /* e2m 8C53 +0 RE_Trans_Pressure_State ('Indicate the RE transmission pressure state'; table-resolved): which governor pressure curve sets governor_pressure_target, 1-0x18, written by every governor pressure mode (the anti-hunt mode: 1 base / 0x12 / 0x13 boost / 0x14 / 0x15 hold); 2 in the RAM dump (was status_code) Typed TRANSMISSION_PRESSURE_STATE (round 9). */
    uint16_t anti_hunt_boost_limit_timer;  /* e2m 8C17 +0 RE_AH_Boost_Limit_Timer ('Used to limit time trans gov pressure can be boosted for upshift'): reloaded from transmission_anti_hunt_boost_limit_time; at 0 the 1-2 boost stops (was status_code_hold_timer) */
    uint16_t anti_hunt_delay_timer;  /* e2m 8C17 +2 RE_AH_Delay_Timer ('Used to delay start of gov pressure boost for AH upshifts'): reloaded from transmission_anti_hunt_delay_time when a forced upshift completes; no new boost until it is 0 (was timeout_counter) */
    uint16_t anti_hunt_1_2_boost_timer;  /* e2m 8C17 +4 RE_AH_Timer_1_2 ('Controls duration of boost press for AH 1-2 upshift'): reloaded from transmission_anti_hunt_1_2_boost_time (was state1_timer) */
    uint16_t anti_hunt_2_3_boost_timer;  /* e2m 8C17 +6 RE_AH_Timer_2_3 ('Controls duration of boost press for AH 2-3 upshift'): reloaded from transmission_anti_hunt_2_3_boost_time (was state2_timer) */
};

struct cam_crank_sync_state_t {
    uint16_t cam_sync_error_count;  /* e2m 819C +0 Cam_Sync_Error_Count 'TOTAL NUMBER OF SYNC LOSSES': +1 per crank signal interrupt while cam_sync_state is not 4 above engine_position_sensor_error_detection_minimum_engine_speed (mpc555_updateCrankSyncState); cm848_updateEngineSpeedFromCrankSignal compares it with cam_sync_error_count_limit. No engine start counter (was start_counter) | earlier note: Engine start attempt counter */
    uint16_t cam_sync_state;  /* e2m 819C +2 Cam_Sync_State: the cam signal handler's state, 4 = in sync, 1 = lost (cm848_enterCamSyncLost); the e2m value labels (0 no sync / 1 have sync / 2 lost on cam / 3 start sync) do not match this firmware's numbering. No crank state (was crank_state) | earlier note: Cranking state machine value */
    uint16_t crank_sync_error_count;  /* e2m 819C +4 Crank_Sync_Error_Count 'Incremented 6/cam when crank not synched' (CNTS): counted up and down by mpc555_updateCrankSyncState from the TPU-A channel 0 status; cm848_updateEngineSpeedFromCrankSignal compares it with crank_sync_error_count_limit. No cranking flag (was cranking_flag) | earlier note: Engine currently cranking flag (1=cranking) */
    uint16_t crank_sync_state;  /* e2m 819C +6 Crank_Sync_State: 0 no sync / 2 start sync / 3 preliminary sync / 4 in sync / 1 lost (mpc555_updateCrankSyncState and its setters); the e2m value labels (0 no sync / 1 have sync / 2 lost on crank / 3 start sync) do not match this firmware's numbering. State 4 gates the cylinder balance and the fuel pressure feedback filter. No engine run state (was run_state) | earlier note: Engine run state written by mpc555_updateEngineRunState - a different variable from engine_operating_mode */
};

struct fuel_pressure_governor_state_t {
    FUEL_PRESSURE_GOVERNOR_MODE fuel_pressure_governor_mode;  /* Fuel pressure governor mode (FUEL_PRESSURE_GOVERNOR_MODE; was sync_status) */
    uint16_t fuel_pressure_governor_demand;  /* Fuel pressure governor demand: the PID / fixed-mode result of cm848_calculateFuelMeteringCommand before its limits; its table turns the clamped value into the fuel metering feedback target (was reference_count) */
    uint16_t fuel_metering_command;  /* Fuel metering command 0-4095 (= 0-100 % on-time of TPU-B channel 11 via cm848_setFuelMeteringPwm) from cm848_calculateFuelMeteringCommand - not an engine speed (was speed_raw) */
    uint16_t filtered_battery_voltage;  /* e2m 8019 +5 HPCR_Filtered_Battery_Voltage (volts): stored by cm848_filterEngineSensorValue (sth) and read by cm848_calculateFuelMeteringCommand for its battery voltage compensation (lhz) - a word, so the struct is 7 bytes (was the 1-byte reserved_05) */
};

struct engine_speed_state_t {
    uint16_t engine_speed;  /* e2m 819B +1E Engine_Speed '[ESCMES] Engine speed based from period of one cam rev' (1/8 rpm): in this firmware written with the same value as filtered_engine_speed by the same writers; the fault freeze frames copy it (was filtered_rpm) */
    uint32_t main_speed_period_sum_between_vss_pulses;  /* e2m 819B +20 EPS_VSS_Accumulator '[ESACGR] Accumulated main EPS period between VSS interrupts': hpcr_processEngineSyncPulses adds each crank_accumulated_period; cm848_vehicleSpeedSensorInterruptHandler divides it by the count (was crank_capture_period_sum) */
    uint32_t backup_speed_period_sum_between_vss_pulses;  /* e2m 819B +24 EPS_VSS_Accumulator_Backup '[ESACBKGR] Accumulated backup EPS period between VSS interrupts': added by mpc555_handleCamSignalInterrupt; divided by the count in cm848_vehicleSpeedSensorInterruptHandler (was crank_tooth_period_sum) */
    uint16_t main_speed_pulse_count_between_vss_pulses;  /* e2m 819B +28 EPS_VSS_Counter '[ESCTGR] Number of main EPS interrupts between VSS interrupts' (was crank_capture_period_sample_count) */
    uint16_t backup_speed_pulse_count_between_vss_pulses;  /* e2m 819B +2A EPS_VSS_Counter_Backup '[ESCTBKGR] Number of backup EPS interrupts between VSS interrupts' (was crank_tooth_period_sample_count) */
    uint16_t filtered_engine_speed;  /* e2m 819B +2C Filtered_Engine_Speed '[ENGRPM] Variable 2^n pulse averaged and filtered engine speed' (1/8 rpm; x 0.125 verified live at 0x40b7ba 2026-01-31): the engine speed the rest of the firmware reads (was current_rpm) */
};

struct eeprom_header_t {
    uint16_t version_marker;  /* EEPROM data version marker */
    uint16_t magic;  /* Validation magic (EEPROM_MAGIC enum: 0x600D=valid) */
    uint8_t header_block[6];  /* EEPROM header data block */
    uint32_t config_dword;  /* EEPROM configuration dword */
    uint16_t config_word;  /* EEPROM configuration word */
    uint8_t calibration_block1[6];  /* Calibration data block 1 */
    uint16_t eeprom_status_flags;  /* Bit0=IAT derate history | Bit3=calibration validated */
    uint16_t cal_word2;  /* Calibration parameter word 2 */
    uint16_t cal_word3;  /* Calibration parameter word 3 */
    uint16_t serial_reflash_unlock_request;  /* Boot copy of EEPROM 0x56 (serial_reflash_unlock_request_cal) - the application's serial reflash hand-off; non-zero makes mpc555_initDiagnosticSession start the boot SCI session unlocked (was cal_word4) */
    uint32_t serial_number;  /* ECU serial number from EEPROM */
};

struct low_speed_governor_reference_t {
    uint16_t reference_speed;  /* e2m 1496 +10 LSG_Reference_Speed '[LSRF] Current reference speed being used by the LSG feature' (1/8 rpm; 6000 = 750 rpm in the RAM dump): written by cm848_slewLowSpeedGovernorReferenceSpeed (was idle_reference_speed) | earlier note: Low speed governor idle reference speed in 1/8 rpm (6000 = 750 rpm in the RAM dump) - the high word of the old integrator dword */
    int16_t no_load_fuel;  /* e2m 1496 +12 No_Load_Fuel_At_LSG_Ref 'No load fueling value at LSG reference speed before droop' (signed; lha @ 0x28060): cm848_calculateLowSpeedGovernorNoLoadFuel (was fuel_feed_forward_quantity) | earlier note: Signed fuel feed-forward quantity (lha @ 0x28060) - the low word of the old integrator dword */
    LOW_SPEED_GOVERNOR_REFERENCE_SPEED_STATE reference_speed_state;  /* e2m 1496 +14 LSG_Reference_Speed_State 'Indication of which logic is controlling LSG idle speed': 0 COOLANT / 1 PARK_NEU / 2 EXTENDED / 3 AC / 4 J1850 / 5 BASE / 6 JCOMM / 7 MIN / 8 MAX / 9 ALTITUDE / 10 SIP (shift in process) / 11 TOOL / 12 MOVING (was governor_output) | earlier note: Idle-speed candidate number 0-12 (name kept; see the wave-11 note) */
    uint32_t altitude_speed;  /* e2m 1496 +16 LSG_Altitude_Speed (4 bytes; 1/8 rpm x 256): the altitude speed request after its slew (state 9) (was idle_speed_barometric_ramped) | earlier note: Barometric-ramped idle speed (lwz / stw @ 0x2931c / 0x29440) - the old word field at +6 covered only its high half */
};

struct pci_link_state_t {
    uint8_t rx_match_index;  /* pci_receive_message_table entry whose header matches the frame being received (search resumes here per byte) */
    uint8_t tx_match_index;  /* pci_transmit_message_table entry whose header matches (own transmission echoed back) */
    uint8_t receive_byte_count;  /* Bytes stored in pci_receive_frame_buffer for the current frame */
    uint8_t init_complete_marker;  /* Set to 1 at the end of cm848_initJ1939CommunicationSystem; no reader found */
    uint32_t link_event_code;  /* PCI link event 1..7 (all stw/lwz); cm848_handlePciLinkEvent maps each to a recovery-action mask at 0x3fd8e0..0x3fd8e7; 7 = every scheduled PCI transmit overdue (set by cm848_checkPciMessageTimeouts); was dm1_pending (word) */
};

struct j1587_fault_count_data_t {
    uint16_t active_fault_count;  /* e2m 1097 +C0 J1587_Fault_Count_Data 'Data used by J1587 and Fault Handler to keep track of fault counts': the number of faults in active_dtc_list_cal - it moves with active_dtc_list_cal.count and active_dtc_cummins_fault_codes_cal[0], and the list code indexes the slots with it. No ring buffer write index (was write_index) | earlier note: Next write position in fault list */
    uint16_t previously_active_fault_count;  /* The number of faults in previously_active_dtc_list_cal (it moves with its count and previously_active_dtc_cummins_fault_codes_cal[0]). No ring buffer read index (was read_index) | earlier note: Current read position in fault list */
    uint16_t emission_count;  /* Count of emission-related faults | It counts the active faults whose fault_definition_t.definition_flags bit 0x2000 is clear - every slot in this calibration, so it equals active_fault_count. Only these count updates test the bit, so 'emission' is unproven */
    uint16_t total_emission_faults;  /* Total emission fault counter | It counts the previously active faults whose definition_flags bit 0x2000 is clear - every slot in this calibration, so it equals previously_active_fault_count; 'emission' is unproven */
};

struct reflash_transfer_state_t {
    uint16_t byte_count;  /* Byte count */
    uint16_t buffer_write_enabled_flag;  /* Buffer write enabled flag */
    uint16_t largest_write_length;  /* Largest write length */
    uint16_t reserved_06;  /* Reserved */
    uint8_t pending_write_transport;  /* 1 = CAN / 2 = serial (was the high byte of the state word) */
    uint8_t finish_requested_flag;  /* Finish requested (was the low byte of the state word) */
    uint8_t flash_program_step;  /* Step 1-5 of cm848_runFlashProgramStateMachine (was the high byte of the status word) */
    uint8_t flash2_erase_state;  /* Medium confidence: 1 programmed / 2 erasing / 3 erased (was the low byte of the status word) */
};

struct boot_sci_session_state_t {
    uint8_t session_flags;  /* Session flags */
    uint8_t response_write_index;  /* Response write index */
    void * response_cursor_pointer;  /* Cursor into diag_serial_buffer (stw r9,-4928(r10) @ 0x6788 stores 0x3fecf0) - the decompiler showed it as four byte stores */
};

struct fault_bit_words_t {
    uint16_t faults_0_to_15;  /* Faults 0-15: e2m 1036 +00 System_Error_Status_00; b0 RAM_Image_Word_Error P0606; b1 FSO_Command_High_Control_Error; b2 FSO_Command_Low_Control_Error; b3 TU_WG_Driver1_High_Control_Error; b4 TU_WG_Driver1_Low_Control_Error; b5 P0341; b6 AFC_Low_Boost_Error; b7 FP_Idle_Error P0191; b8 Boost_Pressure_High_Error P0238; b9 Boost_Pressure_Low_Error P0237; b10 Sampled_Throttle_High_Error P2123; b11 Sampled_Throttle_Low_Error P2122; b12 Oil_Pressure_High_Error; b13 Oil_Pressure_Low_Error; b14 HPCR_OBD_Neg_Dev_Error; b15 HPCR_OBD_Pos_Dev_Error | earlier note: Word 0 of fault-detected array 0x3fe974 (fault bit = word*16 + bit via ROM 0x5985a -> obd_dtc_code_table): b0 P0606 b5 P0341 b7 P0191 b8 P0238 boost-high b9 P0237 boost-low b10 P2123 b11 P2122 (was enable_state) */
    uint16_t coolant_temperature_high_error : 1;  /* bit 0: word faults_16_to_31 (e2m 1036 +02 System_Error_Status_01) bit 0 = fault 16: e2m 1036 Coolant_Temperature_High_Error (P0118) */
    uint16_t coolant_temperature_low_error : 1;  /* bit 1: fault 17: e2m 1036 Coolant_Temperature_Low_Error (P0117) */
    uint16_t fault_18 : 1;  /* bit 2: fault 18 */
    uint16_t intake_manifold_temperature_high_error : 1;  /* bit 3: fault 19: e2m 1036 Intake_Manifold_Temperature_High_Error (P0113) */
    uint16_t intake_manifold_temperature_low_error : 1;  /* bit 4: fault 20: e2m 1036 Intake_Manifold_Temperature_Low_Error (P0112) */
    uint16_t fault_21 : 1;  /* bit 5: fault 21 */
    uint16_t fault_22 : 1;  /* bit 6: fault 22 */
    uint16_t fault_23 : 1;  /* bit 7: fault 23 */
    uint16_t fault_24 : 1;  /* bit 8: fault 24 */
    uint16_t ambient_air_pressure_high_error : 1;  /* bit 9: fault 25: e2m 1036 Ambient_Air_Pressure_High_Error (P0108) */
    uint16_t ambient_air_pressure_low_error : 1;  /* bit 10: fault 26: e2m 1036 Ambient_Air_Pressure_Low_Error (P0107) */
    uint16_t overspeed_injector_shutoff_error : 1;  /* bit 11: fault 27: e2m 1036 Overspeed_Injector_Shutoff_Error (P0219) */
    uint16_t fault_28 : 1;  /* bit 12: fault 28 */
    uint16_t vss_signal_lost_error : 1;  /* bit 13: fault 29: e2m 1036 VSS_Signal_Lost_Error (P0500) */
    uint16_t vss_tampering_error : 1;  /* bit 14: fault 30: e2m 1036 VSS_Tampering_Error */
    uint16_t fault_31 : 1;  /* bit 15: fault 31 */
    uint16_t fault_32 : 1;  /* bit 0: word faults_32_to_47 (e2m 1036 +04 System_Error_Status_02) bit 0 = fault 32 */
    uint16_t fuel_shutoff_control_error : 1;  /* bit 1: fault 33: e2m 1036 FSO_Control_Error */
    uint16_t fault_34 : 1;  /* bit 2: fault 34 */
    uint16_t turbocharger_wastegate_driver_2_high_control_error : 1;  /* bit 3: fault 35: e2m 1036 TU_WG_Driver2_High_Control_Error */
    uint16_t turbocharger_wastegate_driver_2_low_control_error : 1;  /* bit 4: fault 36: e2m 1036 TU_WG_Driver2_Low_Control_Error */
    uint16_t fault_37 : 1;  /* bit 5: fault 37: e2m 1036 CORS_Makeup_Valve_Driver_High_Control_Error; e2m CORS_Makeup_Valve_Driver_High_Control_Error has an abbreviation the code does not resolve (cors) */
    uint16_t fault_38 : 1;  /* bit 6: fault 38: e2m 1036 CORS_Makeup_Valve_Driver_Low_Control_Error; e2m CORS_Makeup_Valve_Driver_Low_Control_Error has an abbreviation the code does not resolve (cors) */
    uint16_t fault_39 : 1;  /* bit 7: fault 39 */
    uint16_t fault_40 : 1;  /* bit 8: fault 40 */
    uint16_t engine_brake_driver_1_high_control_error : 1;  /* bit 9: fault 41: e2m 1036 Engine_Brake_Driver_1_High_Control_Error (P0478) */
    uint16_t engine_brake_driver_1_low_control_error : 1;  /* bit 10: fault 42: e2m 1036 Engine_Brake_Driver_1_Low_Control_Error (P0477) */
    uint16_t engine_brake_driver_2_high_control_error : 1;  /* bit 11: fault 43: e2m 1036 Engine_Brake_Driver_2_High_Control_Error */
    uint16_t engine_brake_driver_2_low_control_error : 1;  /* bit 12: fault 44: e2m 1036 Engine_Brake_Driver_2_Low_Control_Error */
    uint16_t engine_brake_driver_3_high_control_error : 1;  /* bit 13: fault 45: e2m 1036 Engine_Brake_Driver_3_High_Control_Error */
    uint16_t engine_brake_driver_3_low_control_error : 1;  /* bit 14: fault 46: e2m 1036 Engine_Brake_Driver_3_Low_Control_Error */
    uint16_t fuel_temperature_high_error : 1;  /* bit 15: fault 47: e2m 1036 Fuel_Temperature_High_Error */
    uint16_t fuel_temperature_low_error : 1;  /* bit 0: word faults_48_to_63 (e2m 1036 +06 System_Error_Status_03) bit 0 = fault 48: e2m 1036 Fuel_Temperature_Low_Error */
    uint16_t fault_49 : 1;  /* bit 1: fault 49 */
    uint16_t fault_50 : 1;  /* bit 2: fault 50 */
    uint16_t fault_51 : 1;  /* bit 3: fault 51 */
    uint16_t frequency_throttle_low_error : 1;  /* bit 4: fault 52: e2m 1036 Frequency_Throttle_Low_Error */
    uint16_t frequency_throttle_high_error : 1;  /* bit 5: fault 53: e2m 1036 Frequency_Throttle_High_Error */
    uint16_t water_in_fuel_high_error : 1;  /* bit 6: fault 54: e2m 1036 Water_In_Fuel_High_Error (P2267) */
    uint16_t water_in_fuel_low_error : 1;  /* bit 7: fault 55: e2m 1036 Water_In_Fuel_Low_Error (P2266) */
    uint16_t water_in_fuel_error : 1;  /* bit 8: fault 56: e2m 1036 Water_In_Fuel_Error (P2269) */
    uint16_t fuel_pressure_governed_speed_check_error : 1;  /* bit 9: cm848_checkFuelPressureGovernorDemandAtGovernedSpeed sets it when fuel_pressure_governed_speed_check_debounce_count reaches its limit (was fault_57; PR #53 round 29) | fault 57 (P1221) */
    uint16_t fuel_pressure_governor_demand_above_limit_error : 1;  /* bit 10: cm848_checkFuelPressureWithoutInjection sets it when fuel_pressure_governor_demand_above_limit_debounce_count reaches its limit (was fault_58; PR #53 round 29) | fault 58 (P1222) */
    uint16_t fuel_pressure_decay_below_model_error : 1;  /* bit 11: cm848_checkFuelPressureWithoutInjection sets it when fuel_pressure_allowed_decay_below_model_debounce_count reaches its limit (was fault_59; PR #53 round 29) | fault 59 */
    uint16_t fuel_metering_feedback_low_error : 1;  /* bit 12: cm848_monitorFuelMeteringFeedbackAgainstGovernorDemand sets it when fuel_metering_feedback_low_debounce_count reaches its limit (was fault_60; PR #53 round 29) | fault 60 (P1223) */
    uint16_t fault_61 : 1;  /* bit 13: fault 61 */
    uint16_t throttle_validation_switch_low_error : 1;  /* bit 14: fault 62: e2m 1036 Throttle_Validation_Switch_Low_Error (P2127) */
    uint16_t throttle_validation_process_error : 1;  /* bit 15: fault 63: e2m 1036 Throttle_Validation_Process_Error (P2121) */
    uint16_t boost_in_range_high_error : 1;  /* bit 0: word faults_64_to_79 (e2m 1036 +08 System_Error_Status_04) bit 0 = fault 64: e2m 1036 Boost_In_Range_High_Error (P0236) */
    uint16_t fault_65 : 1;  /* bit 1: fault 65 */
    uint16_t battery_voltage_low_error : 1;  /* bit 2: fault 66: e2m 1036 Battery_Voltage_Low_Error (P0562) */
    uint16_t battery_voltage_high_error : 1;  /* bit 3: fault 67: e2m 1036 Battery_Voltage_High_Error (P0563) */
    uint16_t throttle_validation_switch_high_error : 1;  /* bit 4: fault 68: e2m 1036 Throttle_Validation_Switch_High_Error (P2128) */
    uint16_t fault_69 : 1;  /* bit 5: fault 69 (P1221) */
    uint16_t fault_70 : 1;  /* bit 6: fault 70 (P1222) */
    uint16_t fault_71 : 1;  /* bit 7: fault 71 (P1223) */
    uint16_t fault_72 : 1;  /* bit 8: fault 72 */
    uint16_t increment_decrement_switch_error : 1;  /* bit 9: fault 73: e2m 1036 Increment_Decrement_Switch_Error */
    uint16_t ram_overrun_error : 1;  /* bit 10: fault 74: e2m 1036 Ram_Overrun_Error */
    uint16_t fault_75 : 1;  /* bit 11: fault 75 */
    uint16_t fault_76 : 1;  /* bit 12: fault 76 */
    uint16_t remote_throttle_high_error : 1;  /* bit 13: fault 77: e2m 1036 Remote_Throttle_High_Error */
    uint16_t remote_throttle_low_error : 1;  /* bit 14: fault 78: e2m 1036 Remote_Throttle_Low_Error */
    uint16_t fault_79 : 1;  /* bit 15: fault 79 */
    uint16_t qspi_command_error : 1;  /* bit 0: word faults_80_to_95 (e2m 1036 +0A System_Error_Status_05) bit 0 = fault 80: e2m 1036 QSPI_Command_Error */
    uint16_t qspi_initialization_error : 1;  /* bit 1: fault 81: e2m 1036 QSPI_Initialization_Error */
    uint16_t power_off_without_ignition_off_error : 1;  /* bit 2: fault 82: e2m 1036 Power_Off_Without_Ignition_Off_Error (P2509) */
    uint16_t fault_83 : 1;  /* bit 3: fault 83 */
    uint16_t flash_failure_error : 1;  /* bit 4: fault 84: e2m 1036 Flash_Failure_Error */
    uint16_t fault_85 : 1;  /* bit 5: fault 85 */
    uint16_t fault_86 : 1;  /* bit 6: fault 86 */
    uint16_t fault_87 : 1;  /* bit 7: fault 87 */
    uint16_t fault_88 : 1;  /* bit 8: fault 88 */
    uint16_t power_down_data_lost_error : 1;  /* bit 9: fault 89: e2m 1036 Powerdown_Data_Lost_Error (P2509) */
    uint16_t all_power_down_data_lost_error : 1;  /* bit 10: fault 90: e2m 1036 All_Powerdown_Data_Lost_Error (P2509) */
    uint16_t power_off_command_ignored_error : 1;  /* bit 11: fault 91: e2m 1036 Poweroff_Command_Ignored_Error (P0606) */
    uint16_t engine_position_sensor_main_channel_lost_error : 1;  /* bit 12: fault 92: e2m 1036 EPS_Main_Channel_Lost_Error (P0335); EPS: faults 92 / 93 (P0335 / P0340) are set by cm848_updateEngineSpeedFromCrankSignal (main / backup sensor) */
    uint16_t engine_position_sensor_backup_channel_lost_error : 1;  /* bit 13: fault 93: e2m 1036 EPS_Backup_Channel_Lost_Error (P0340); EPS: faults 92 / 93 (P0335 / P0340) are set by cm848_updateEngineSpeedFromCrankSignal (main / backup sensor) */
    uint16_t fault_94 : 1;  /* bit 14: fault 94 */
    uint16_t fault_95 : 1;  /* bit 15: fault 95 */
    uint16_t fault_96 : 1;  /* bit 0: word faults_96_to_111 (e2m 1036 +0C System_Error_Status_06) bit 0 = fault 96 */
    uint16_t fault_97 : 1;  /* bit 1: fault 97 */
    uint16_t fault_98 : 1;  /* bit 2: fault 98 */
    uint16_t fault_99 : 1;  /* bit 3: fault 99 */
    uint16_t fault_100 : 1;  /* bit 4: fault 100 */
    uint16_t fault_101 : 1;  /* bit 5: fault 101 */
    uint16_t fault_102 : 1;  /* bit 6: fault 102 */
    uint16_t fault_103 : 1;  /* bit 7: fault 103 */
    uint16_t fault_104 : 1;  /* bit 8: fault 104 */
    uint16_t fault_105 : 1;  /* bit 9: fault 105 */
    uint16_t fault_106 : 1;  /* bit 10: fault 106 */
    uint16_t fault_107 : 1;  /* bit 11: fault 107 */
    uint16_t fault_108 : 1;  /* bit 12: fault 108 */
    uint16_t fault_109 : 1;  /* bit 13: fault 109 */
    uint16_t fault_110 : 1;  /* bit 14: fault 110 */
    uint16_t j1939_link_cannot_transmit_error : 1;  /* bit 15: fault 111: e2m 1036 J1939_Link_Cannot_Transmit_Error */
    uint16_t j1939_link_not_fast_enough_error : 1;  /* bit 0: word faults_112_to_127 (e2m 1036 +0E System_Error_Status_07) bit 0 = fault 112: e2m 1036 J1939_Link_Not_Fast_Enough_Error */
    uint16_t fault_113 : 1;  /* bit 1: fault 113 */
    uint16_t fault_114 : 1;  /* bit 2: fault 114 */
    uint16_t fault_115 : 1;  /* bit 3: fault 115 */
    uint16_t fault_116 : 1;  /* bit 4: fault 116 */
    uint16_t cam_crank_sync_mismatch_error : 1;  /* bit 5: fault 117: e2m 1036 Cam_Crank_Sync_Mismatch_Error (P0016) */
    uint16_t fault_118 : 1;  /* bit 6: fault 118 */
    uint16_t fault_119 : 1;  /* bit 7: fault 119 */
    uint16_t fault_120 : 1;  /* bit 8: fault 120 */
    uint16_t fan_clutch_1_pwm_control_error : 1;  /* bit 9: fault 121: e2m 1036 Fan_Clutch_1_PWM_Control_Error (P0480) */
    uint16_t fault_122 : 1;  /* bit 10: fault 122 */
    uint16_t fault_123 : 1;  /* bit 11: fault 123 */
    uint16_t crank_sync_error : 1;  /* bit 12: fault 124: e2m 1036 Crank_Sync_Error (P0336) */
    uint16_t fault_125 : 1;  /* bit 13: fault 125 */
    uint16_t fault_126 : 1;  /* bit 14: fault 126 */
    uint16_t j1939_multiplexed_accelerator_pedal_sensor_system_error : 1;  /* bit 15: fault 127: e2m 1036 J1939_Mux_APS_System_Error */
    uint16_t j1939_multiplexed_pgn_timeout_error : 1;  /* bit 0: word faults_128_to_143 (e2m 1036 +10 System_Error_Status_08) bit 0 = fault 128: e2m 1036 J1939_Mux_PGN_Timeout_Error */
    uint16_t j1939_multiplexed_remote_throttle_data_error : 1;  /* bit 1: fault 129: e2m 1036 J1939_Mux_Remote_Throttle_Data_Error */
    uint16_t j1939_multiplexed_configuration_error : 1;  /* bit 2: fault 130: e2m 1036 J1939_Mux_Configuration_Error */
    uint16_t fault_131 : 1;  /* bit 3: fault 131 */
    uint16_t engine_brake_driver_4_high_control_error : 1;  /* bit 4: fault 132: e2m 1036 Engine_Brake_Driver_4_High_Control_Error */
    uint16_t engine_brake_driver_4_low_control_error : 1;  /* bit 5: fault 133: e2m 1036 Engine_Brake_Driver_4_Low_Control_Error */
    uint16_t engine_brake_driver_5_high_control_error : 1;  /* bit 6: fault 134: e2m 1036 Engine_Brake_Driver_5_High_Control_Error */
    uint16_t engine_brake_driver_5_low_control_error : 1;  /* bit 7: fault 135: e2m 1036 Engine_Brake_Driver_5_Low_Control_Error */
    uint16_t transmission_variable_force_solenoid_battery_driver_high_control_error : 1;  /* bit 8: fault 136: e2m 1036 Transmission_VFS_Battery_Driver_High_Control_Error (P0883) */
    uint16_t transmission_variable_force_solenoid_battery_driver_low_control_error : 1;  /* bit 9: fault 137: e2m 1036 Transmission_VFS_Battery_Driver_Low_Control_Error (P0882) */
    uint16_t transmission_overdrive_driver_high_control_error : 1;  /* bit 10: fault 138: e2m 1036 Engine_Alarm_Driver_High_Control_Error/Transmission_Overdrive_Driver_High_Control_Error (P0974); the P0974 alternative of Engine_Alarm_Driver_High_Control_Error/Transmission_Overdrive_Driver_High_Control_Error */
    uint16_t transmission_overdrive_driver_low_control_error : 1;  /* bit 11: fault 139: e2m 1036 Engine_Alarm_Driver_Low_Control_Error/Transmission_Overdrive_Driver_Low_Control_Error (P0973); the P0973 alternative of Engine_Alarm_Driver_Low_Control_Error/Transmission_Overdrive_Driver_Low_Control_Error */
    uint16_t transmission_torque_converter_clutch_driver_high_control_error : 1;  /* bit 12: fault 140: e2m 1036 Fan_Clutch_Control_Driver1_High_Control_Error/Transmission_TCC_Driver_High_Control_Error (P2770); the P2770 alternative of Fan_Clutch_Control_Driver1_High_Control_Error/Transmission_TCC_Driver_High_Control_Error */
    uint16_t transmission_torque_converter_clutch_driver_low_control_error : 1;  /* bit 13: fault 141: e2m 1036 Fan_Clutch_Control_Driver1_Low_Control_Error/Transmission_TCC_Driver_Low_Control_Error (P2769); the P2769 alternative of Fan_Clutch_Control_Driver1_Low_Control_Error/Transmission_TCC_Driver_Low_Control_Error */
    uint16_t cruise_vent_driver_high_control_error : 1;  /* bit 14: fault 142: e2m 1036 Cruise_Vent_Driver_High_Control_Error/Fan_Clutch_Control_Driver2_High_Control_Error (P0588); the P0588 alternative of Cruise_Vent_Driver_High_Control_Error/Fan_Clutch_Control_Driver2_High_Control_Error */
    uint16_t cruise_vent_driver_low_control_error : 1;  /* bit 15: fault 143: e2m 1036 Cruise_Vent_Driver_Low_Control_Error/Fan_Clutch_Control_Driver2_Low_Control_Error (P0587); the P0587 alternative of Cruise_Vent_Driver_Low_Control_Error/Fan_Clutch_Control_Driver2_Low_Control_Error */
    uint16_t cruise_vacuum_driver_high_control_error : 1;  /* bit 0: word faults_144_to_159 (e2m 1036 +12 System_Error_Status_09) bit 0 = fault 144: e2m 1036 Cruise_Vacuum_Driver_High_Control_Error/Maintenance_Lamp_Driver_High_Control_Error (P0584); the P0584 alternative of Cruise_Vacuum_Driver_High_Control_Error/Maintenance_Lamp_Driver_High_Control_Error */
    uint16_t cruise_vacuum_driver_low_control_error : 1;  /* bit 1: fault 145: e2m 1036 Cruise_Vacuum_Driver_Low_Control_Error/Maintenance_Lamp_Driver_Low_Control_Error (P0583); the P0583 alternative of Cruise_Vacuum_Driver_Low_Control_Error/Maintenance_Lamp_Driver_Low_Control_Error */
    uint16_t cruise_servo_supply_driver_high_control_error : 1;  /* bit 2: logical output 21 (logical_output_request_bits_16_to_23_t.cruise_servo_supply_request; e2m 1577 Cruise_SC_Source_Driver) is checked with this bit by cm848_checkDiscreteOutputReadBack (was fault_146; PR #53 round 32) | fault 146: e2m 1036 Cruise_SC_Source_Driver_High_Control_Error (P0596); e2m Cruise_SC_Source_Driver_High_Control_Error has an abbreviation the code does not resolve (sc) */
    uint16_t cruise_servo_supply_driver_low_control_error : 1;  /* bit 3: logical output 21 (logical_output_request_bits_16_to_23_t.cruise_servo_supply_request; e2m 1577 Cruise_SC_Source_Driver) is checked with this bit by cm848_checkDiscreteOutputReadBack (was fault_147; PR #53 round 32) | fault 147: e2m 1036 Cruise_SC_Source_Driver_Low_Control_Error (P0595); e2m Cruise_SC_Source_Driver_Low_Control_Error has an abbreviation the code does not resolve (sc) */
    uint16_t transmission_park_neutral_switch_error : 1;  /* bit 4: fault 148: e2m 1036 Transmission_Park_Neutral_Switch_Error (P0850) */
    uint16_t transmission_governor_pressure_rationality_error : 1;  /* bit 5: fault 149: e2m 1036 RE_Governor_Pressure_Rationality_Error (P1762) */
    uint16_t ambient_air_temperature_high_error : 1;  /* bit 6: fault 150: e2m 1036 Ambient_Air_Temperature_High_Error (P0073) */
    uint16_t ambient_air_temperature_low_error : 1;  /* bit 7: fault 151: e2m 1036 Ambient_Air_Temperature_Low_Error (P0072) */
    uint16_t transmission_overdrive_driver_2_high_control_error : 1;  /* bit 8: fault 152: e2m 1036 Transmission_Overdrive_Driver_2_High_Control_Error */
    uint16_t transmission_overdrive_driver_2_low_control_error : 1;  /* bit 9: fault 153: e2m 1036 Transmission_Overdrive_Driver_2_Low_Control_Error */
    uint16_t transmission_torque_converter_clutch_driver_2_high_control_error : 1;  /* bit 10: fault 154: e2m 1036 Transmission_TCC_Driver_2_High_Control_Error */
    uint16_t transmission_torque_converter_clutch_driver_2_low_control_error : 1;  /* bit 11: fault 155: e2m 1036 Transmission_TCC_Driver_2_Low_Control_Error */
    uint16_t fault_156 : 1;  /* bit 12: fault 156 */
    uint16_t fault_157 : 1;  /* bit 13: fault 157 */
    uint16_t fault_158 : 1;  /* bit 14: fault 158 */
    uint16_t fault_159 : 1;  /* bit 15: fault 159 */
    uint16_t fault_160 : 1;  /* bit 0: word faults_160_to_175 (e2m 1036 +14 System_Error_Status_10) bit 0 = fault 160 */
    uint16_t fault_161 : 1;  /* bit 1: fault 161 */
    uint16_t fault_162 : 1;  /* bit 2: fault 162 */
    uint16_t fault_163 : 1;  /* bit 3: fault 163 */
    uint16_t fault_164 : 1;  /* bit 4: fault 164 */
    uint16_t eeprom_write_error : 1;  /* bit 5: fault 165: e2m 1036 EEPROM_Write_Error */
    uint16_t power_down_eeprom_checksum_error : 1;  /* bit 6: fault 166: e2m 1036 Powerdown_EEPROM_Checksum_Error */
    uint16_t fault_167 : 1;  /* bit 7: fault 167 */
    uint16_t fault_168 : 1;  /* bit 8: fault 168 */
    uint16_t fault_169 : 1;  /* bit 9: fault 169 */
    uint16_t fault_170 : 1;  /* bit 10: fault 170 */
    uint16_t remote_throttle_enabled_low_error : 1;  /* bit 11: fault 171: e2m 1036 RT_Low_Error; cm848_claimRemoteThrottleOverride copies fault 78 (Remote_Throttle_Low_Error) into it while algorithm_enable_flags_18_cal.remote_throttle_enable is set; RT = remote throttle; RT: fault 171 / 172 are set by cm848_claimRemoteThrottleOverride */
    uint16_t remote_throttle_enabled_high_error : 1;  /* bit 12: fault 172: e2m 1036 RT_High_Error; cm848_claimRemoteThrottleOverride copies fault 77 (Remote_Throttle_High_Error) into it while the remote throttle is enabled; RT: fault 171 / 172 are set by cm848_claimRemoteThrottleOverride */
    uint16_t fault_173 : 1;  /* bit 13: fault 173 */
    uint16_t fault_174 : 1;  /* bit 14: fault 174 */
    uint16_t fault_175 : 1;  /* bit 15: fault 175 */
    uint16_t fault_176 : 1;  /* bit 0: word faults_176_to_191 (e2m 1036 +16 System_Error_Status_11) bit 0 = fault 176 */
    uint16_t fault_177 : 1;  /* bit 1: fault 177 */
    uint16_t fault_178 : 1;  /* bit 2: fault 178 */
    uint16_t fault_179 : 1;  /* bit 3: fault 179 */
    uint16_t fault_180 : 1;  /* bit 4: fault 180 */
    uint16_t fault_181 : 1;  /* bit 5: fault 181 */
    uint16_t fault_182 : 1;  /* bit 6: fault 182 */
    uint16_t fault_183 : 1;  /* bit 7: fault 183 */
    uint16_t fault_184 : 1;  /* bit 8: fault 184 */
    uint16_t fault_185 : 1;  /* bit 9: fault 185 */
    uint16_t fault_186 : 1;  /* bit 10: fault 186 */
    uint16_t fault_187 : 1;  /* bit 11: fault 187 */
    uint16_t fault_188 : 1;  /* bit 12: fault 188 */
    uint16_t fault_189 : 1;  /* bit 13: fault 189 */
    uint16_t fault_190 : 1;  /* bit 14: fault 190 */
    uint16_t fault_191 : 1;  /* bit 15: fault 191 */
    uint16_t fault_192 : 1;  /* bit 0: word faults_192_to_207 (e2m 1036 +18 System_Error_Status_12) bit 0 = fault 192 */
    uint16_t fault_193 : 1;  /* bit 1: fault 193 */
    uint16_t fault_194 : 1;  /* bit 2: fault 194 */
    uint16_t fault_195 : 1;  /* bit 3: fault 195 */
    uint16_t throttle_sensor_supply_voltage_high_error : 1;  /* bit 4: fault 196: e2m 1036 Throttle_Sensor_Supply_Voltage_High_Error (P0699) */
    uint16_t throttle_sensor_supply_voltage_low_error : 1;  /* bit 5: fault 197: e2m 1036 Throttle_Sensor_Supply_Voltage_Low_Error (P0698) */
    uint16_t fault_198 : 1;  /* bit 6: fault 198 */
    uint16_t fault_199 : 1;  /* bit 7: fault 199 */
    uint16_t fault_200 : 1;  /* bit 8: fault 200 */
    uint16_t fault_201 : 1;  /* bit 9: fault 201 */
    uint16_t fault_202 : 1;  /* bit 10: fault 202 */
    uint16_t fault_203 : 1;  /* bit 11: fault 203 */
    uint16_t stop_lamp_driver_high_control_error : 1;  /* bit 12: fault 204: e2m 1036 Stop_Lamp_Driver_High_Control_Error */
    uint16_t stop_lamp_driver_low_control_error : 1;  /* bit 13: fault 205: e2m 1036 Stop_Lamp_Driver_Low_Control_Error */
    uint16_t fault_206 : 1;  /* bit 14: fault 206: e2m 1036 T2_High_Gear_Driver_High_Control_Error/T2_Shift_Driver_High_Control_Error; e2m 'T2_High_Gear_Driver_High_Control_Error/T2_Shift_Driver_High_Control_Error' names two applications and no DTC decides */
    uint16_t fault_207 : 1;  /* bit 15: fault 207: e2m 1036 T2_High_Gear_Driver_Low_Control_Error/T2_Shift_Driver_Low_Control_Error; e2m 'T2_High_Gear_Driver_Low_Control_Error/T2_Shift_Driver_Low_Control_Error' names two applications and no DTC decides */
    uint16_t fault_208 : 1;  /* bit 0: word faults_208_to_223 (e2m 1036 +1A System_Error_Status_13) bit 0 = fault 208: e2m 1036 T2_Lamp_Driver_High_Control_Error; e2m T2_Lamp_Driver_High_Control_Error has an abbreviation the code does not resolve (t2) */
    uint16_t fault_209 : 1;  /* bit 1: fault 209: e2m 1036 T2_Lamp_Driver_Low_Control_Error; e2m T2_Lamp_Driver_Low_Control_Error has an abbreviation the code does not resolve (t2) */
    uint16_t fault_210 : 1;  /* bit 2: fault 210: e2m 1036 T2_Lockout_Driver_High_Control_Error; e2m T2_Lockout_Driver_High_Control_Error has an abbreviation the code does not resolve (t2) */
    uint16_t fault_211 : 1;  /* bit 3: fault 211: e2m 1036 T2_Lockout_Driver_Low_Control_Error; e2m T2_Lockout_Driver_Low_Control_Error has an abbreviation the code does not resolve (t2) */
    uint16_t fault_212 : 1;  /* bit 4: fault 212: e2m 1036 T2_Low_Gear_Driver_High_Control_Error; e2m T2_Low_Gear_Driver_High_Control_Error has an abbreviation the code does not resolve (t2) */
    uint16_t fault_213 : 1;  /* bit 5: fault 213: e2m 1036 T2_Low_Gear_Driver_Low_Control_Error; e2m T2_Low_Gear_Driver_Low_Control_Error has an abbreviation the code does not resolve (t2) */
    uint16_t fault_214 : 1;  /* bit 6: fault 214: e2m 1036 T2_Neutral_Driver_High_Control_Error; e2m T2_Neutral_Driver_High_Control_Error has an abbreviation the code does not resolve (t2) */
    uint16_t fault_215 : 1;  /* bit 7: fault 215: e2m 1036 T2_Neutral_Driver_Low_Control_Error; e2m T2_Neutral_Driver_Low_Control_Error has an abbreviation the code does not resolve (t2) */
    uint16_t fault_216 : 1;  /* bit 8: fault 216: e2m 1036 TAS_Lamp_Driver_High_Control_Error; e2m TAS_Lamp_Driver_High_Control_Error has an abbreviation the code does not resolve (tas) */
    uint16_t fault_217 : 1;  /* bit 9: fault 217: e2m 1036 TAS_Lamp_Driver_Low_Control_Error; e2m TAS_Lamp_Driver_Low_Control_Error has an abbreviation the code does not resolve (tas) */
    uint16_t wait_to_start_lamp_driver_high_control_error : 1;  /* bit 10: fault 218: e2m 1036 Wait_To_Start_Lamp_Driver_High_Control_Error/Wait_To_Start_Lamp_High_Control_Error (P0381); the P0381 alternative of Wait_To_Start_Lamp_Driver_High_Control_Error/Wait_To_Start_Lamp_High_Control_Error */
    uint16_t wait_to_start_lamp_driver_low_control_error : 1;  /* bit 11: fault 219: e2m 1036 Wait_To_Start_Lamp_Driver_Low_Control_Error/Wait_To_Start_Lamp_Low_Control_Error (P0381); the P0381 alternative of Wait_To_Start_Lamp_Driver_Low_Control_Error/Wait_To_Start_Lamp_Low_Control_Error */
    uint16_t warning_lamp_driver_high_control_error : 1;  /* bit 12: fault 220: e2m 1036 Warning_Lamp_Driver_High_Control_Error */
    uint16_t warning_lamp_driver_low_control_error : 1;  /* bit 13: fault 221: e2m 1036 Warning_Lamp_Driver_Low_Control_Error */
    uint16_t water_in_fuel_lamp_driver_high_control_error : 1;  /* bit 14: fault 222: e2m 1036 Water_In_Fuel_Lamp_Driver_High_Control_Error */
    uint16_t water_in_fuel_lamp_driver_low_control_error : 1;  /* bit 15: fault 223: e2m 1036 Water_In_Fuel_Lamp_Driver_Low_Control_Error */
    uint16_t fault_224 : 1;  /* bit 0: word faults_224_to_239 (e2m 1036 +1C System_Error_Status_14) bit 0 = fault 224 */
    uint16_t fault_225 : 1;  /* bit 1: fault 225 */
    uint16_t fault_226 : 1;  /* bit 2: fault 226 */
    uint16_t fault_227 : 1;  /* bit 3: fault 227 */
    uint16_t overspeed_pump_shutoff_error : 1;  /* bit 4: fault 228: e2m 1036 Overspeed_Pump_Shutoff_Error */
    uint16_t warning_lamp_driver_open_control_error : 1;  /* bit 5: fault 229: e2m 1036 Warning_Lamp_Driver_Open_Control_Error */
    uint16_t stop_lamp_driver_open_control_error : 1;  /* bit 6: fault 230: e2m 1036 Stop_Lamp_Driver_Open_Control_Error */
    uint16_t fault_231 : 1;  /* bit 7: fault 231 */
    uint16_t maintenance_lamp_driver_open_control_error : 1;  /* bit 8: fault 232: e2m 1036 Maintenance_Lamp_Driver_Open_Control_Error */
    uint16_t fault_233 : 1;  /* bit 9: fault 233 */
    uint16_t fault_234 : 1;  /* bit 10: fault 234 */
    uint16_t fault_235 : 1;  /* bit 11: fault 235 */
    uint16_t fault_236 : 1;  /* bit 12: fault 236 */
    uint16_t fault_237 : 1;  /* bit 13: fault 237 */
    uint16_t fault_238 : 1;  /* bit 14: fault 238 */
    uint16_t fault_239 : 1;  /* bit 15: fault 239 */
    uint16_t fault_240 : 1;  /* bit 0: word faults_240_to_255 (e2m 1036 +1E System_Error_Status_15) bit 0 = fault 240 */
    uint16_t fault_241 : 1;  /* bit 1: fault 241 */
    uint16_t fault_242 : 1;  /* bit 2: fault 242 */
    uint16_t fault_243 : 1;  /* bit 3: fault 243 */
    uint16_t fault_244 : 1;  /* bit 4: fault 244 */
    uint16_t fault_245 : 1;  /* bit 5: fault 245 */
    uint16_t fault_246 : 1;  /* bit 6: fault 246 */
    uint16_t fault_247 : 1;  /* bit 7: fault 247 */
    uint16_t fault_248 : 1;  /* bit 8: fault 248 */
    uint16_t fault_249 : 1;  /* bit 9: fault 249 */
    uint16_t fault_250 : 1;  /* bit 10: fault 250 */
    uint16_t fault_251 : 1;  /* bit 11: fault 251 */
    uint16_t fault_252 : 1;  /* bit 12: fault 252 */
    uint16_t fault_253 : 1;  /* bit 13: fault 253 */
    uint16_t fault_254 : 1;  /* bit 14: fault 254 */
    uint16_t fault_255 : 1;  /* bit 15: fault 255 */
    uint16_t fault_256 : 1;  /* bit 0: word faults_256_to_271 (e2m 1036 +20 System_Error_Status_16) bit 0 = fault 256 */
    uint16_t fault_257 : 1;  /* bit 1: fault 257 */
    uint16_t fault_258 : 1;  /* bit 2: fault 258 */
    uint16_t fault_259 : 1;  /* bit 3: fault 259 */
    uint16_t fault_260 : 1;  /* bit 4: fault 260 */
    uint16_t fault_261 : 1;  /* bit 5: fault 261 */
    uint16_t fuel_temperature_rpm_error_active : 1;  /* bit 6: fault 262: e2m 1036 Fuel_Temperature_RPM_Error_Active */
    uint16_t fuel_temperature_fueling_error_active : 1;  /* bit 7: fault 263: e2m 1036 Fuel_Temperature_Fueling_Error_Active */
    uint16_t high_pressure_common_rail_cp3_low_current_error : 1;  /* bit 8: fault 264: e2m 1036 HPCR_CP3_Low_Current_Error */
    uint16_t high_pressure_common_rail_cp3_high_current_error : 1;  /* bit 9: fault 265: e2m 1036 HPCR_CP3_High_Current_Error */
    uint16_t fault_266 : 1;  /* bit 10: fault 266 */
    uint16_t fault_267 : 1;  /* bit 11: fault 267 */
    uint16_t injector_1_short_to_battery_error : 1;  /* bit 12: fault 268: e2m 1036 Injector_1_Short_to_Vbatt_Error (P2146) */
    uint16_t injector_1_short_to_ground_error : 1;  /* bit 13: fault 269: e2m 1036 Injector_1_Short_to_Ground_Error (P2146) */
    uint16_t injector_1_fast_decay_error : 1;  /* bit 14: fault 270: e2m 1036 Injector_1_Fast_Decay_Error */
    uint16_t injector_5_short_to_battery_error : 1;  /* bit 15: fault 271: e2m 1036 Injector_5_Short_to_Vbatt_Error (P2146) */
    uint16_t injector_5_short_to_ground_error : 1;  /* bit 0: word faults_272_to_287 (e2m 1036 +22 System_Error_Status_17) bit 0 = fault 272: e2m 1036 Injector_5_Short_to_Ground_Error (P2146) */
    uint16_t injector_5_fast_decay_error : 1;  /* bit 1: fault 273: e2m 1036 Injector_5_Fast_Decay_Error */
    uint16_t injector_3_short_to_battery_error : 1;  /* bit 2: fault 274: e2m 1036 Injector_3_Short_to_Vbatt_Error (P2146) */
    uint16_t injector_3_short_to_ground_error : 1;  /* bit 3: fault 275: e2m 1036 Injector_3_Short_to_Ground_Error (P2146) */
    uint16_t injector_3_fast_decay_error : 1;  /* bit 4: fault 276: e2m 1036 Injector_3_Fast_Decay_Error */
    uint16_t injector_6_short_to_battery_error : 1;  /* bit 5: fault 277: e2m 1036 Injector_6_Short_to_Vbatt_Error (P2149) */
    uint16_t injector_6_short_to_ground_error : 1;  /* bit 6: fault 278: e2m 1036 Injector_6_Short_to_Ground_Error (P2149) */
    uint16_t injector_6_fast_decay_error : 1;  /* bit 7: fault 279: e2m 1036 Injector_6_Fast_Decay_Error */
    uint16_t injector_2_short_to_battery_error : 1;  /* bit 8: fault 280: e2m 1036 Injector_2_Short_to_Vbatt_Error (P2149) */
    uint16_t injector_2_short_to_ground_error : 1;  /* bit 9: fault 281: e2m 1036 Injector_2_Short_to_Ground_Error (P2149) */
    uint16_t injector_2_fast_decay_error : 1;  /* bit 10: fault 282: e2m 1036 Injector_2_Fast_Decay_Error */
    uint16_t injector_4_short_to_battery_error : 1;  /* bit 11: fault 283: e2m 1036 Injector_4_Short_to_Vbatt_Error (P2149) */
    uint16_t injector_4_short_to_ground_error : 1;  /* bit 12: fault 284: e2m 1036 Injector_4_Short_to_Ground_Error (P2149) */
    uint16_t injector_4_fast_decay_error : 1;  /* bit 13: fault 285: e2m 1036 Injector_4_Fast_Decay_Error */
    uint16_t injector_1_open_circuit_error : 1;  /* bit 14: fault 286: e2m 1036 Injector_1_Open_Circuit_Error (P0201) */
    uint16_t injector_5_open_circuit_error : 1;  /* bit 15: fault 287: e2m 1036 Injector_5_Open_Circuit_Error (P0202) */
    uint16_t injector_3_open_circuit_error : 1;  /* bit 0: word faults_288_to_303 (e2m 1036 +24 System_Error_Status_18) bit 0 = fault 288: e2m 1036 Injector_3_Open_Circuit_Error (P0203) */
    uint16_t injector_6_open_circuit_error : 1;  /* bit 1: fault 289: e2m 1036 Injector_6_Open_Circuit_Error (P0204) */
    uint16_t fault_290 : 1;  /* bit 2: fault 290 */
    uint16_t injector_2_open_circuit_error : 1;  /* bit 3: fault 291: e2m 1036 Injector_2_Open_Circuit_Error (P0205) */
    uint16_t injector_4_open_circuit_error : 1;  /* bit 4: fault 292: e2m 1036 Injector_4_Open_Circuit_Error (P0206) */
    uint16_t fault_293 : 1;  /* bit 5: fault 293 */
    uint16_t cold_start_aid_1_low_control_error : 1;  /* bit 6: fault 294: e2m 1036 Cold_Start_Aid_1_Low_Control_Error (P0541) */
    uint16_t cold_start_aid_1_high_control_error : 1;  /* bit 7: fault 295: e2m 1036 Cold_Start_Aid_1_High_Control_Error (P0542) */
    uint16_t cold_start_aid_2_low_control_error : 1;  /* bit 8: fault 296: e2m 1036 Cold_Start_Aid_2_Low_Control_Error (P2607) */
    uint16_t cold_start_aid_2_high_control_error : 1;  /* bit 9: fault 297: e2m 1036 Cold_Start_Aid_2_High_Control_Error (P2608) */
    uint16_t transmission_oil_temperature_rationality_error : 1;  /* bit 10: fault 298: e2m 1036 Transmission_Oil_Temperature_Rationality_Error (P0711) */
    uint16_t transmission_governor_pressure_high_error : 1;  /* bit 11: fault 299: e2m 1036 Transmission_Governor_Pressure_High_Error (P0868) */
    uint16_t transmission_governor_pressure_low_error : 1;  /* bit 12: fault 300: e2m 1036 Transmission_Governor_Pressure_Low_Error (P0869) */
    uint16_t transmission_oil_temperature_high_error : 1;  /* bit 13: fault 301: e2m 1036 Transmission_Oil_Temperature_High_Error (P0713) */
    uint16_t transmission_oil_temperature_low_error : 1;  /* bit 14: fault 302: e2m 1036 Transmission_Oil_Temperature_Low_Error (P0712) */
    uint16_t high_pressure_common_rail_pressure_too_high_error : 1;  /* bit 15: fault 303: e2m 1036 HPCR_Pressure_Too_High_Error (P0088) */
    uint16_t fuel_rail_pressure_high_error : 1;  /* bit 0: word faults_304_to_319 (e2m 1036 +26 System_Error_Status_19) bit 0 = fault 304: e2m 1036 Fuel_Rail_Pressure_High_Error (P0193) */
    uint16_t fuel_rail_pressure_low_error : 1;  /* bit 1: fault 305: e2m 1036 Fuel_Rail_Pressure_Low_Error (P0192) */
    uint16_t ecm_internal_temperature_low_error : 1;  /* bit 2: fault 306: e2m 1036 ECM_Internal_Temperature_Low_Error */
    uint16_t ecm_internal_temperature_high_error : 1;  /* bit 3: fault 307: e2m 1036 ECM_Internal_Temperature_High_Error */
    uint16_t engine_off_time_stuck_error : 1;  /* bit 4: cm848_latchAndCheckEngineOffTime sets it when the engine-off time in PCI frame 0x42 stays within engine_off_time_unchanged_delta of the last value for engine_off_time_unchanged_count_limit key cycles (e2m Chry_Dat42 = Chrysler data frame 0x42); the temperature rationality checks skip while it is set (was fault_308; PR #53 round 29) | fault 308: e2m 1036 Chry_Dat42_Stuck_Error; e2m Chry_Dat42_Stuck_Error has an abbreviation the code does not resolve (chry; dat42) */
    uint16_t fault_309 : 1;  /* bit 5: fault 309 */
    uint16_t fault_310 : 1;  /* bit 6: fault 310 */
    uint16_t fault_311 : 1;  /* bit 7: fault 311 */
    uint16_t fault_312 : 1;  /* bit 8: fault 312 */
    uint16_t fault_313 : 1;  /* bit 9: fault 313 */
    uint16_t fault_314 : 1;  /* bit 10: fault 314 */
    uint16_t fault_315 : 1;  /* bit 11: fault 315 */
    uint16_t fault_316 : 1;  /* bit 12: fault 316 */
    uint16_t fault_317 : 1;  /* bit 13: fault 317 */
    uint16_t fault_318 : 1;  /* bit 14: fault 318 (P0604) */
    uint16_t torque_converter_clutch_rationality_error : 1;  /* bit 15: fault 319: e2m 1036 TCC_Rationality_Error (P1740) */
    uint16_t output_speed_sensor_rationality_error : 1;  /* bit 0: word faults_320_to_335 (e2m 1036 +28 System_Error_Status_20) bit 0 = fault 320: e2m 1036 OSS_Rationality_Error (P0720) */
    uint16_t fault_321 : 1;  /* bit 1: fault 321 */
    uint16_t fault_322 : 1;  /* bit 2: fault 322 */
    uint16_t fault_323 : 1;  /* bit 3: fault 323 */
    uint16_t fault_324 : 1;  /* bit 4: fault 324 */
    uint16_t fault_325 : 1;  /* bit 5: fault 325 */
    uint16_t fault_326 : 1;  /* bit 6: fault 326 */
    uint16_t fault_327 : 1;  /* bit 7: fault 327 */
    uint16_t booster_capacitor_1_voltage_high_error : 1;  /* bit 8: fault 328: e2m 1036 Booster_Cap_1_Voltage_High_Error (P0606) */
    uint16_t booster_capacitor_1_voltage_low_error : 1;  /* bit 9: fault 329: e2m 1036 Booster_Cap_1_Voltage_Low_Error (P2146) */
    uint16_t booster_capacitor_2_voltage_high_error : 1;  /* bit 10: fault 330: e2m 1036 Booster_Cap_2_Voltage_High_Error (P0606) */
    uint16_t booster_capacitor_2_voltage_low_error : 1;  /* bit 11: fault 331: e2m 1036 Booster_Cap_2_Voltage_Low_Error (P2149) */
    uint16_t wastegate_high_boost_error : 1;  /* bit 12: fault 332: e2m 1036 CWG_High_Boost_Error (P0234); CWG: fault 332 is set by cm848_monitorWastegateBoostPressure (P0234) */
    uint16_t cp3_pump_regulator_control_error : 1;  /* bit 13: fault 333: e2m 1036 CP3_Pump_Regulator_Control_Error (P0251) */
    uint16_t pedal_position_sensor_conformance_error : 1;  /* bit 14: fault 334: e2m 1036 PPS_Conformance_Error (P2121) */
    uint16_t speed_limp_home_error : 1;  /* bit 15: fault 335: e2m 1036 Speed_Limp_Home_Error (P0336) */
    uint16_t water_in_fuel_too_long_error : 1;  /* bit 0: word faults_336_to_351 (e2m 1036 +2A System_Error_Status_21) bit 0 = fault 336: e2m 1036 WIF_Too_Long_Error (P0169) */
    uint16_t sensor_supply_1_voltage_low_error : 1;  /* bit 1: fault 337: e2m 1036 Sensor_Supply_1_Voltage_Low_Error (P0642) */
    uint16_t sensor_supply_1_voltage_high_error : 1;  /* bit 2: fault 338: e2m 1036 Sensor_Supply_1_Voltage_High_Error (P0643) */
    uint16_t ambient_air_temperature_rationality_error : 1;  /* bit 3: fault 339: e2m 1036 Ambient_Air_Temperature_Rationality_Error (P0071) */
    uint16_t ambient_air_pressure_in_range_error : 1;  /* bit 4: fault 340: e2m 1036 Ambient_Air_Pressure_In_Range_Error (P0106) */
    uint16_t low_oil_switch_error : 1;  /* bit 5: fault 341: e2m 1036 Low_Oil_Switch_Error (P0521) */
    uint16_t overspeed_protection_error : 1;  /* bit 6: cm848_checkRpmOverspeedProtection sets it above overspeed_protection_threshold (and clears logical outputs 0x2f / 0x30 until overspeed_protection_recovery_threshold) (was fault_342; PR #53 round 29) | fault 342 */
    uint16_t overspeed_warning_error : 1;  /* bit 7: cm848_checkRpmOverspeedProtection sets it above overspeed_warning_threshold (until overspeed_warning_recovery_threshold) (was fault_343; PR #53 round 29) | fault 343 */
    uint16_t vin_eeprom_not_entered_error : 1;  /* bit 8: fault 344: e2m 1036 VIN_E2_Not_Entered_Error (P0630) */
    uint16_t odometer_eeprom_not_entered_error : 1;  /* bit 9: fault 345: e2m 1036 Odometer_E2_Not_Entered_Error */
    uint16_t vehicle_theft_alarm_secret_key_eeprom_not_entered_error : 1;  /* bit 10: fault 346: e2m 1036 VTA_Secret_Key_E2_Not_Entered_Error (P0633) */
    uint16_t pedal_position_sensor_1_low_error : 1;  /* bit 11: fault 347: e2m 1036 Pedal_Position_Sensor_1_Low_Error (P2122) */
    uint16_t pedal_position_sensor_1_high_error : 1;  /* bit 12: fault 348: e2m 1036 Pedal_Position_Sensor_1_High_Error (P2123) */
    uint16_t pedal_position_sensor_2_low_error : 1;  /* bit 13: fault 349: e2m 1036 Pedal_Position_Sensor_2_Low_Error (P2127) */
    uint16_t pedal_position_sensor_2_high_error : 1;  /* bit 14: fault 350: e2m 1036 Pedal_Position_Sensor_2_High_Error (P2128) */
    uint16_t transmission_variable_force_solenoid_pwm_driver_error : 1;  /* bit 15: fault 351: e2m 1036 Transmission_VFS_PWM_Driver_Error (P0748) */
    uint16_t high_pressure_common_rail_cumulative_sum_leak_error : 1;  /* bit 0: word faults_352_to_367 (e2m 1036 +2C System_Error_Status_22) bit 0 = fault 352: e2m 1036 HPCR_Cusum_Leak_Error */
    uint16_t battery_temperature_rationality_error : 1;  /* bit 1: fault 353: e2m 1036 Battery_Temperature_Rationality_Error (P0514) */
    uint16_t intake_manifold_temperature_rationality_error : 1;  /* bit 2: fault 354: e2m 1036 Intake_Manifold_Temperature_Rationality_Error (P0111) */
    uint16_t j1850_open_circuit_no_message_error : 1;  /* bit 3: fault 355: e2m 1036 J1850_Open_Ckt_No_Message_Error (P1652) */
    uint16_t j1939_tsc1_lost_fault : 1;  /* bit 4: fault 356: e2m 1036 Jcomm_TSC_Lost_Fault; TSC: fault 356 is set by cm848_updateParkNeutralFlagAndTsc1Activity */
    uint16_t checksum_error : 1;  /* bit 5: fault 357: e2m 1036 Checksum_Error (P0602) */
    uint16_t intake_manifold_temperature_key_on_rationality_error : 1;  /* bit 6: fault 358: e2m 1036 Intake_Manifold_Temperature_Keyon_Ration_Error (P0111) */
    uint16_t battery_temperature_key_on_rationality_error : 1;  /* bit 7: fault 359: e2m 1036 Battery_Temperature_Keyon_Rationality_Error (P0514) */
    uint16_t ambient_air_temperature_key_on_rationality_error : 1;  /* bit 8: fault 360: e2m 1036 Ambient_Air_Temperature_Keyon_Rationality_Error (P0071) */
    uint16_t cylinder_1_misfire_error : 1;  /* bit 9: fault 361: e2m 1036 Cylinder_1_Misfire_Error (P0301) */
    uint16_t cylinder_2_misfire_error : 1;  /* bit 10: fault 362: e2m 1036 Cylinder_2_Misfire_Error (P0302) */
    uint16_t cylinder_3_misfire_error : 1;  /* bit 11: fault 363: e2m 1036 Cylinder_3_Misfire_Error (P0303) */
    uint16_t cylinder_4_misfire_error : 1;  /* bit 12: fault 364: e2m 1036 Cylinder_4_Misfire_Error (P0304) */
    uint16_t cylinder_5_misfire_error : 1;  /* bit 13: fault 365: e2m 1036 Cylinder_5_Misfire_Error (P0305) */
    uint16_t cylinder_6_misfire_error : 1;  /* bit 14: fault 366: e2m 1036 Cylinder_6_Misfire_Error (P0306) */
    uint16_t multiple_cylinders_misfire_error : 1;  /* bit 15: fault 367: e2m 1036 Multiple_Cylinders_Misfire_Error (P0300) */
    uint16_t alternator_error : 1;  /* bit 0: word faults_368_to_383 (e2m 1036 +2E System_Error_Status_23) bit 0 = fault 368: e2m 1036 Alternator_Error (P2502) */
    uint16_t charging_system_high_error : 1;  /* bit 1: fault 369: e2m 1036 Charging_System_High_Error (P2504) */
    uint16_t charging_system_low_error : 1;  /* bit 2: fault 370: e2m 1036 Charging_System_Low_Error (P2503) */
    uint16_t air_conditioning_discrete_output_high_control_error : 1;  /* bit 3: fault 371: e2m 1036 AC_Discrete_Output_High_Control_Error (P0647) */
    uint16_t air_conditioning_discrete_output_low_control_error : 1;  /* bit 4: fault 372: e2m 1036 AC_Discrete_Output_Low_Control_Error (P0646) */
    uint16_t cruise_control_switch_multiplexed_high_error : 1;  /* bit 5: fault 373: e2m 1036 Cruise_Control_Switch_Mux_High_Error (P0581) */
    uint16_t cruise_control_switch_multiplexed_low_error : 1;  /* bit 6: fault 374: e2m 1036 Cruise_Control_Switch_Mux_Low_Error (P0580) */
    uint16_t engine_speed_sensor_supply_voltage_high_error : 1;  /* bit 7: fault 375: e2m 1036 Engine_Speed_Sensor_SV_High_Error (P0338); SV: e2m spells the throttle one both ways (Throttle_Sensor_Supply_Voltage / Throttle_Position_Sensor_SV) */
    uint16_t engine_speed_sensor_supply_voltage_low_error : 1;  /* bit 8: fault 376: e2m 1036 Engine_Speed_Sensor_SV_Low_Error (P0337); SV: e2m spells the throttle one both ways (Throttle_Sensor_Supply_Voltage / Throttle_Position_Sensor_SV) */
    uint16_t engine_connector_sensors_supply_voltage_high_error : 1;  /* bit 9: fault 377: e2m 1036 Engine_Conn_Sensors_SV_High_Error (P0653); SV: e2m spells the throttle one both ways (Throttle_Sensor_Supply_Voltage / Throttle_Position_Sensor_SV) */
    uint16_t engine_connector_sensors_supply_voltage_low_error : 1;  /* bit 10: fault 378: e2m 1036 Engine_Conn_Sensors_SV_Low_Error (P0652); SV: e2m spells the throttle one both ways (Throttle_Sensor_Supply_Voltage / Throttle_Position_Sensor_SV) */
    uint16_t battery_temperature_high_error : 1;  /* bit 11: fault 379: e2m 1036 Battery_Temperature_High_Error (P0517) */
    uint16_t battery_temperature_low_error : 1;  /* bit 12: fault 380: e2m 1036 Battery_Temperature_Low_Error (P0516) */
    uint16_t fuel_level_high_error : 1;  /* bit 13: fault 381: e2m 1036 Fuel_Level_High_Error (P0463) */
    uint16_t fuel_level_low_error : 1;  /* bit 14: fault 382: e2m 1036 Fuel_Level_Low_Error (P0462) */
    uint16_t j1850_system_bus_fault : 1;  /* bit 15: fault 383: e2m 1036 J1850_System_Bus_Fault (P1652) */
    uint16_t air_conditioning_pressure_high_error : 1;  /* bit 0: word faults_384_to_399 (e2m 1036 +30 System_Error_Status_24) bit 0 = fault 384: e2m 1036 AC_Pressure_High_Error (P0533) */
    uint16_t air_conditioning_pressure_low_error : 1;  /* bit 1: fault 385: e2m 1036 AC_Pressure_Low_Error (P0532) */
    uint16_t lift_pump_driver_high_control_error : 1;  /* bit 2: fault 386: e2m 1036 Lift_Pump_Driver_High_Control_Error (P0629) */
    uint16_t lift_pump_driver_low_control_error : 1;  /* bit 3: fault 387: e2m 1036 Lift_Pump_Driver_Low_Control_Error (P0628) */
    uint16_t watchdog_fueling_error : 1;  /* bit 4: fault 388: e2m 1036 Watchdog_Fueling_Error (P0606) */
    uint16_t coolant_temperature_derate_aggressive_derate_error : 1;  /* bit 5: fault 389: e2m 1036 CT_Derate_Agg_Derate_Error (P0217); CT: faults 389 / 390 are set by the coolant overheat monitors (P0217) */
    uint16_t coolant_temperature_derate_minimum_derate_error : 1;  /* bit 6: fault 390: e2m 1036 CT_Derate_Min_Derate_Error (P0217); CT: faults 389 / 390 are set by the coolant overheat monitors (P0217) */
    uint16_t transmission_governor_pressure_zero_rationality_error : 1;  /* bit 7: fault 391: e2m 1036 RE_Governor_Pr_Zero_Rationality_Error (P1757) */
    uint16_t transmission_governor_pressure_mid_rationality_error : 1;  /* bit 8: fault 392: e2m 1036 RE_Governor_Pr_Mid_Rationality_Error (P1756) */
    uint16_t low_oil_pressure_error : 1;  /* bit 9: fault 393: e2m 1036 Low_Oil_Pressure_Error (P0524) */
    uint16_t brake_switch_high_error : 1;  /* bit 10: fault 394: e2m 1036 Brake_Switch_High_Error (P0573) */
    uint16_t brake_switch_low_error : 1;  /* bit 11: fault 395: e2m 1036 Brake_Switch_Low_Error (P0572) */
    uint16_t alternator_field_driver_control_error : 1;  /* bit 12: fault 396: e2m 1036 EVR_Driver_Control_Error (P0622); EVR: fault 396 = output 27; the alternator field; P0622 (the output read-back debounce) */
    uint16_t obd_fuel_level_low_error : 1;  /* bit 13: fault 397: e2m 1036 OBD_Fuel_Level_Low_Error */
    uint16_t fuel_level_rationality_error : 1;  /* bit 14: fault 398: e2m 1036 Fuel_Level_Rationality_Error (P0461) */
    uint16_t fuel_system_shutdown_hardware_error : 1;  /* bit 15: fault 399: e2m 1036 FS_Shutdown_HW_Error (P0607) */
    uint16_t thermostat_system_error : 1;  /* bit 0: word faults_400_to_415 (e2m 1036 +32 System_Error_Status_25) bit 0 = fault 400: e2m 1036 Tstat_System_Error (P0128) */
    uint16_t coolant_temperature_in_range_error : 1;  /* bit 1: fault 401: e2m 1036 Coolant_Temperature_In_Range_Error (P0116) */
    uint16_t fuel_temperature_in_range_error : 1;  /* bit 2: fault 402: e2m 1036 Fuel_Temperature_In_Range_Error */
    uint16_t wastegate_pressure_control_driver_error : 1;  /* bit 3: fault 403: e2m 1036 Wastegate_Pressure_Control_Driver_Error (P0243) */
    uint16_t transmission_receive_emissions_fault : 1;  /* bit 4: fault 404: e2m 1036 Transmission_Rx_Emissions_Fault */
    uint16_t transmission_receive_message_fault : 1;  /* bit 5: fault 405: e2m 1036 Transmission_Rx_Message_Fault */
    uint16_t transfer_case_switch_multiplexed_out_of_range_error : 1;  /* bit 6: fault 406: e2m 1036 Tcase_Switch_Mux_OOR_Error (P0837) */
    uint16_t fan_speed_error : 1;  /* bit 7: fault 407: e2m 1036 Fan_Speed_Error (P0483) */
    uint16_t high_pressure_common_rail_cumulative_sum_positive_error : 1;  /* bit 8: fault 408: e2m 1036 HPCR_Cusum_Pos_Error (P0148) */
    uint16_t high_pressure_common_rail_cumulative_sum_negative_error : 1;  /* bit 9: fault 409: e2m 1036 HPCR_Cusum_Neg_Error (P0148) */
    uint16_t fault_410 : 1;  /* bit 10: fault 410 */
    uint16_t intake_air_heater_system_error : 1;  /* bit 11: fault 411: e2m 1036 Intake_Air_Heater_System_Error (P2609) */
    uint16_t transfer_case_switch_multiplexed_high_error : 1;  /* bit 12: fault 412: e2m 1036 Tcase_Switch_Mux_High_Error (P0839) */
    uint16_t transfer_case_switch_multiplexed_low_error : 1;  /* bit 13: fault 413: e2m 1036 Tcase_Switch_Mux_Low_Error (P0838) */
    uint16_t fuel_pressure_key_on_rationality_error : 1;  /* bit 14: fault 414: e2m 1036 Fuel_Pressure_Keyon_Rationality_Error (P0191) */
    uint16_t turbocharger_high_boost_error : 1;  /* bit 15: fault 415: e2m 1036 Turbo_High_Boost_Error (P0234) */
    uint16_t cylinder_7_misfire_error : 1;  /* bit 0: word faults_416_to_431 (e2m 1036 +34 System_Error_Status_26) bit 0 = fault 416: e2m 1036 Cylinder_7_Misfire_Error */
    uint16_t cylinder_8_misfire_error : 1;  /* bit 1: fault 417: e2m 1036 Cylinder_8_Misfire_Error */
    uint16_t injector_7_open_circuit_error : 1;  /* bit 2: fault 418: e2m 1036 Injector_7_Open_Circuit_Error */
    uint16_t injector_8_open_circuit_error : 1;  /* bit 3: fault 419: e2m 1036 Injector_8_Open_Circuit_Error */
    uint16_t injector_7_short_to_battery_error : 1;  /* bit 4: fault 420: e2m 1036 Injector_7_Short_to_Vbatt_Error */
    uint16_t injector_8_short_to_battery_error : 1;  /* bit 5: fault 421: e2m 1036 Injector_8_Short_to_Vbatt_Error */
    uint16_t injector_7_short_to_ground_error : 1;  /* bit 6: fault 422: e2m 1036 Injector_7_Short_to_Ground_Error */
    uint16_t injector_8_short_to_ground_error : 1;  /* bit 7: fault 423: e2m 1036 Injector_8_Short_to_Ground_Error */
    uint16_t injector_7_fast_decay_error : 1;  /* bit 8: fault 424: e2m 1036 Injector_7_Fast_Decay_Error */
    uint16_t injector_8_fast_decay_error : 1;  /* bit 9: fault 425: e2m 1036 Injector_8_Fast_Decay_Error */
    uint16_t fault_426 : 1;  /* bit 10: fault 426 */
    uint16_t fault_427 : 1;  /* bit 11: fault 427 */
    uint16_t fault_428 : 1;  /* bit 12: fault 428 */
    uint16_t fault_429 : 1;  /* bit 13: fault 429 */
    uint16_t fault_430 : 1;  /* bit 14: fault 430 */
    uint16_t fault_431 : 1;  /* bit 15: fault 431 */
    uint16_t can_general_network_error : 1;  /* bit 0: word faults_432_to_447 (e2m 1036 +36 System_Error_Status_27) bit 0 = fault 432: e2m 1036 CAN_General_Network_Error (P0653) */
    uint16_t implausible_air_conditioning_pressure_voltage_from_totally_integrated_power_module_error : 1;  /* bit 1: fault 433: e2m 1036 Implausible_AC_Pressure_Voltage_From_TIPM_Error */
    uint16_t implausible_fuel_voltage_from_totally_integrated_power_module_error : 1;  /* bit 2: fault 434: e2m 1036 Implausible_Fuel_Voltage_From_TIPM_Error */
    uint16_t implausible_ignition_off_timer_from_totally_integrated_power_module_error : 1;  /* bit 3: fault 435: e2m 1036 Implausible_Ign_Off_Timer_From_TIPM_Error */
    uint16_t implausible_vehicle_speed_from_abs_error : 1;  /* bit 4: fault 436: e2m 1036 Implausible_Vehicle_Speed_From_ABS_Error */
    uint16_t lost_communication_with_abs_error : 1;  /* bit 5: fault 437: e2m 1036 Lost_Communication_With_ABS_Error */
    uint16_t lost_communication_with_totally_integrated_power_module_error : 1;  /* bit 6: fault 438: e2m 1036 Lost_Communication_With_TIPM_Error */
    uint16_t vehicle_theft_alarm_invalid_key_error : 1;  /* bit 7: fault 439: e2m 1036 VTA_Invalid_Key_Error */
    uint16_t fault_440 : 1;  /* bit 8: fault 440 */
    uint16_t fault_441 : 1;  /* bit 9: fault 441 */
    uint16_t fault_442 : 1;  /* bit 10: fault 442 */
    uint16_t fault_443 : 1;  /* bit 11: fault 443 */
    uint16_t fault_444 : 1;  /* bit 12: fault 444 */
    uint16_t fault_445 : 1;  /* bit 13: fault 445 */
    uint16_t fault_446 : 1;  /* bit 14: fault 446 */
    uint16_t fault_447 : 1;  /* bit 15: fault 447 */
    uint16_t fault_448 : 1;  /* bit 0: word faults_448_to_463 (e2m 1036 +38 System_Error_Status_28) bit 0 = fault 448 */
    uint16_t fault_449 : 1;  /* bit 1: fault 449 */
    uint16_t fault_450 : 1;  /* bit 2: fault 450 */
    uint16_t fault_451 : 1;  /* bit 3: fault 451 */
    uint16_t fault_452 : 1;  /* bit 4: fault 452 */
    uint16_t fault_453 : 1;  /* bit 5: fault 453 */
    uint16_t fault_454 : 1;  /* bit 6: fault 454 */
    uint16_t fault_455 : 1;  /* bit 7: fault 455 */
    uint16_t fault_456 : 1;  /* bit 8: fault 456 */
    uint16_t fault_457 : 1;  /* bit 9: fault 457 */
    uint16_t fault_458 : 1;  /* bit 10: fault 458 */
    uint16_t fault_459 : 1;  /* bit 11: fault 459 */
    uint16_t fault_460 : 1;  /* bit 12: fault 460 */
    uint16_t fault_461 : 1;  /* bit 13: fault 461 */
    uint16_t fault_462 : 1;  /* bit 14: fault 462 */
    uint16_t fault_463 : 1;  /* bit 15: fault 463 */
    uint16_t fault_464 : 1;  /* bit 0: word faults_464_to_479 (e2m 1036 +3A System_Error_Status_29) bit 0 = fault 464 */
    uint16_t fault_465 : 1;  /* bit 1: fault 465 */
    uint16_t fault_466 : 1;  /* bit 2: fault 466 */
    uint16_t fault_467 : 1;  /* bit 3: fault 467 */
    uint16_t fault_468 : 1;  /* bit 4: fault 468 */
    uint16_t fault_469 : 1;  /* bit 5: fault 469 */
    uint16_t fault_470 : 1;  /* bit 6: fault 470 */
    uint16_t fault_471 : 1;  /* bit 7: fault 471 */
    uint16_t fault_472 : 1;  /* bit 8: fault 472 */
    uint16_t fault_473 : 1;  /* bit 9: fault 473 */
    uint16_t fault_474 : 1;  /* bit 10: fault 474 */
    uint16_t fault_475 : 1;  /* bit 11: fault 475 */
    uint16_t fault_476 : 1;  /* bit 12: fault 476 */
    uint16_t fault_477 : 1;  /* bit 13: fault 477 */
    uint16_t fault_478 : 1;  /* bit 14: fault 478 */
    uint16_t fault_479 : 1;  /* bit 15: fault 479 */
    uint16_t fault_480 : 1;  /* bit 0: word faults_480_to_495 (e2m 1036 +3C System_Error_Status_30) bit 0 = fault 480 */
    uint16_t fault_481 : 1;  /* bit 1: fault 481 */
    uint16_t fault_482 : 1;  /* bit 2: fault 482 */
    uint16_t fault_483 : 1;  /* bit 3: fault 483 */
    uint16_t fault_484 : 1;  /* bit 4: fault 484 */
    uint16_t fault_485 : 1;  /* bit 5: fault 485 */
    uint16_t fault_486 : 1;  /* bit 6: fault 486 */
    uint16_t fault_487 : 1;  /* bit 7: fault 487 */
    uint16_t fault_488 : 1;  /* bit 8: fault 488 */
    uint16_t fault_489 : 1;  /* bit 9: fault 489 */
    uint16_t fault_490 : 1;  /* bit 10: fault 490 */
    uint16_t fault_491 : 1;  /* bit 11: fault 491 */
    uint16_t fault_492 : 1;  /* bit 12: fault 492 */
    uint16_t fault_493 : 1;  /* bit 13: fault 493 */
    uint16_t fault_494 : 1;  /* bit 14: fault 494 */
    uint16_t fault_495 : 1;  /* bit 15: fault 495 */
    uint16_t fault_496 : 1;  /* bit 0: word faults_496_to_511 (e2m 1036 +3E System_Error_Status_31) bit 0 = fault 496 */
    uint16_t fault_497 : 1;  /* bit 1: fault 497 */
    uint16_t fault_498 : 1;  /* bit 2: fault 498 */
    uint16_t fault_499 : 1;  /* bit 3: fault 499 */
    uint16_t fault_500 : 1;  /* bit 4: fault 500 */
    uint16_t fault_501 : 1;  /* bit 5: fault 501 */
    uint16_t fault_502 : 1;  /* bit 6: fault 502 */
    uint16_t fault_503 : 1;  /* bit 7: fault 503 */
    uint16_t fault_504 : 1;  /* bit 8: fault 504 */
    uint16_t fault_505 : 1;  /* bit 9: fault 505 */
    uint16_t fault_506 : 1;  /* bit 10: fault 506 */
    uint16_t fault_507 : 1;  /* bit 11: fault 507 */
    uint16_t fault_508 : 1;  /* bit 12: fault 508 */
    uint16_t diagnostic_low_battery_voltage_error : 1;  /* bit 13: fault 509: e2m 1036 Gen_Diag_Low_Battery_Voltage_Error */
    uint16_t obd_low_battery_voltage_error : 1;  /* bit 14: fault 510: e2m 1036 OBD_Low_Battery_Voltage_Error */
    uint16_t fault_511 : 1;  /* bit 15: fault 511 */
    uint16_t egr_orifice_temperature_rationality_error : 1;  /* bit 0: word faults_512_to_527 (e2m 1036 +40 System_Error_Status_32) bit 0 = fault 512: e2m 1036 EGR_Orifice_Temp_Rationality_Error */
    uint16_t egr_orifice_temperature_startup_error : 1;  /* bit 1: fault 513: e2m 1036 EGR_Orifice_Temp_Startup_Error */
    uint16_t egr_valve_rationality_error : 1;  /* bit 2: fault 514: e2m 1036 EGR_Valve_Rationality_Error */
    uint16_t egr_valve_response_time_error : 1;  /* bit 3: fault 515: e2m 1036 EGR_Valve_Response_Time_Error */
    uint16_t fault_516 : 1;  /* bit 4: fault 516 */
    uint16_t fault_517 : 1;  /* bit 5: fault 517 */
    uint16_t boost_in_range_error : 1;  /* bit 6: fault 518: e2m 1036 Boost_In_Range_Error */
    uint16_t variable_geometry_turbocharger_stuck_actuator_error : 1;  /* bit 7: fault 519: e2m 1036 TVA_Stuck_Actuator_Error (B1976); TVA: e2m names channel 101's VGT position block TVA_Sampled_Position */
    uint16_t variable_geometry_turbocharger_position_rationality_error : 1;  /* bit 8: fault 520: e2m 1036 TVA_Position_Rationality_Error (B1972); TVA: e2m names channel 101's VGT position block TVA_Sampled_Position */
    uint16_t variable_geometry_turbocharger_span_error : 1;  /* bit 9: fault 521: e2m 1036 TVA_Span_Error (B1975); TVA: e2m names channel 101's VGT position block TVA_Sampled_Position */
    uint16_t variable_geometry_turbocharger_autozero_error : 1;  /* bit 10: fault 522: e2m 1036 TVA_AZ_Error (B1971); TVA: e2m names channel 101's VGT position block TVA_Sampled_Position */
    uint16_t fault_523 : 1;  /* bit 11: fault 523 */
    uint16_t fault_524 : 1;  /* bit 12: fault 524 */
    uint16_t variable_geometry_turbocharger_motor_over_current_error : 1;  /* bit 13: fault 525: e2m 1036 TVA_Motor_Overcurrent_Error; TVA: e2m names channel 101's VGT position block TVA_Sampled_Position */
    uint16_t variable_geometry_turbocharger_electrical_fault : 1;  /* bit 14: fault 526: e2m 1036 TVA_Electrical_Fault; TVA: e2m names channel 101's VGT position block TVA_Sampled_Position */
    uint16_t charge_pressure_in_range_error : 1;  /* bit 15: fault 527: e2m 1036 Charge_Press_IR_Error; IR: fault 527 is set by cm848_updateChargePressureInRangeFaultCount */
    uint16_t fault_528 : 1;  /* bit 0: word faults_528_to_543 (e2m 1036 +42 System_Error_Status_33) bit 0 = fault 528 */
    uint16_t fault_529 : 1;  /* bit 1: fault 529 */
    uint16_t fault_530 : 1;  /* bit 2: fault 530 */
    uint16_t fault_531 : 1;  /* bit 3: fault 531 */
    uint16_t fault_532 : 1;  /* bit 4: fault 532 */
    uint16_t fault_533 : 1;  /* bit 5: fault 533 */
    uint16_t fault_534 : 1;  /* bit 6: fault 534 */
    uint16_t fault_535 : 1;  /* bit 7: fault 535 */
    uint16_t fault_536 : 1;  /* bit 8: fault 536 */
    uint16_t fault_537 : 1;  /* bit 9: fault 537 */
    uint16_t fault_538 : 1;  /* bit 10: fault 538 */
    uint16_t fault_539 : 1;  /* bit 11: fault 539 */
    uint16_t fault_540 : 1;  /* bit 12: fault 540 */
    uint16_t fault_541 : 1;  /* bit 13: fault 541 */
    uint16_t fault_542 : 1;  /* bit 14: fault 542 */
    uint16_t fault_543 : 1;  /* bit 15: fault 543 */
    uint16_t fault_544 : 1;  /* bit 0: word faults_544_to_559 (e2m 1036 +44 System_Error_Status_34) bit 0 = fault 544 */
    uint16_t fault_545 : 1;  /* bit 1: fault 545 */
    uint16_t fault_546 : 1;  /* bit 2: fault 546 */
    uint16_t fault_547 : 1;  /* bit 3: fault 547 */
    uint16_t fault_548 : 1;  /* bit 4: fault 548 */
    uint16_t fault_549 : 1;  /* bit 5: fault 549 */
    uint16_t fault_550 : 1;  /* bit 6: fault 550 */
    uint16_t fault_551 : 1;  /* bit 7: fault 551 */
    uint16_t fault_552 : 1;  /* bit 8: fault 552 */
    uint16_t fault_553 : 1;  /* bit 9: fault 553 */
    uint16_t fault_554 : 1;  /* bit 10: fault 554 */
    uint16_t fault_555 : 1;  /* bit 11: fault 555 */
    uint16_t fault_556 : 1;  /* bit 12: fault 556 */
    uint16_t fault_557 : 1;  /* bit 13: fault 557 */
    uint16_t fault_558 : 1;  /* bit 14: fault 558 */
    uint16_t fault_559 : 1;  /* bit 15: fault 559 */
    uint16_t fault_560 : 1;  /* bit 0: word faults_560_to_575 (e2m 1036 +46 System_Error_Status_35) bit 0 = fault 560 */
    uint16_t fault_561 : 1;  /* bit 1: fault 561 */
    uint16_t fault_562 : 1;  /* bit 2: fault 562 */
    uint16_t fault_563 : 1;  /* bit 3: fault 563 */
    uint16_t fault_564 : 1;  /* bit 4: fault 564 */
    uint16_t fault_565 : 1;  /* bit 5: fault 565 */
    uint16_t fault_566 : 1;  /* bit 6: fault 566 */
    uint16_t fault_567 : 1;  /* bit 7: fault 567 */
    uint16_t fault_568 : 1;  /* bit 8: fault 568 */
    uint16_t fault_569 : 1;  /* bit 9: fault 569 */
    uint16_t fault_570 : 1;  /* bit 10: fault 570 */
    uint16_t fault_571 : 1;  /* bit 11: fault 571 */
    uint16_t fault_572 : 1;  /* bit 12: fault 572 */
    uint16_t fault_573 : 1;  /* bit 13: fault 573 */
    uint16_t fault_574 : 1;  /* bit 14: fault 574 */
    uint16_t fault_575 : 1;  /* bit 15: fault 575 */
    uint16_t fault_576 : 1;  /* bit 0: word faults_576_to_591 (e2m 1036 +48 System_Error_Status_36) bit 0 = fault 576 */
    uint16_t fault_577 : 1;  /* bit 1: fault 577 */
    uint16_t fault_578 : 1;  /* bit 2: fault 578 */
    uint16_t fault_579 : 1;  /* bit 3: fault 579 */
    uint16_t fault_580 : 1;  /* bit 4: fault 580 */
    uint16_t fault_581 : 1;  /* bit 5: fault 581 */
    uint16_t fault_582 : 1;  /* bit 6: fault 582 */
    uint16_t fault_583 : 1;  /* bit 7: fault 583 */
    uint16_t fault_584 : 1;  /* bit 8: fault 584 */
    uint16_t fault_585 : 1;  /* bit 9: fault 585 */
    uint16_t fault_586 : 1;  /* bit 10: fault 586 */
    uint16_t fault_587 : 1;  /* bit 11: fault 587 */
    uint16_t fault_588 : 1;  /* bit 12: fault 588 */
    uint16_t fault_589 : 1;  /* bit 13: fault 589 */
    uint16_t fault_590 : 1;  /* bit 14: fault 590 */
    uint16_t fault_591 : 1;  /* bit 15: fault 591 */
    uint16_t fault_592 : 1;  /* bit 0: word faults_592_to_607 (e2m 1036 +4A System_Error_Status_37) bit 0 = fault 592 */
    uint16_t fault_593 : 1;  /* bit 1: fault 593 */
    uint16_t fault_594 : 1;  /* bit 2: fault 594 */
    uint16_t fault_595 : 1;  /* bit 3: fault 595 */
    uint16_t oil_pressure_error : 1;  /* bit 4: fault 596: e2m 1036 Oil_Pressure_Error */
    uint16_t oil_pressure_high_postprocessed_error : 1;  /* bit 5: fault 597: e2m 1036 Oil_Pressure_High_Postprocessed_Error */
    uint16_t fault_598 : 1;  /* bit 6: fault 598 */
    uint16_t fault_599 : 1;  /* bit 7: fault 599 */
    uint16_t fault_600 : 1;  /* bit 8: fault 600 */
    uint16_t fault_601 : 1;  /* bit 9: fault 601 */
    uint16_t fault_602 : 1;  /* bit 10: fault 602 */
    uint16_t fault_603 : 1;  /* bit 11: fault 603 */
    uint16_t fault_604 : 1;  /* bit 12: fault 604 */
    uint16_t fault_605 : 1;  /* bit 13: fault 605 */
    uint16_t fault_606 : 1;  /* bit 14: fault 606 */
    uint16_t fault_607 : 1;  /* bit 15: fault 607 */
    uint16_t fault_608 : 1;  /* bit 0: word faults_608_to_623 (e2m 1036 +4C System_Error_Status_38) bit 0 = fault 608 */
    uint16_t fault_609 : 1;  /* bit 1: fault 609 */
    uint16_t fault_610 : 1;  /* bit 2: fault 610 */
    uint16_t turbocharger_speed_high_error : 1;  /* bit 3: fault 611: e2m 1036 Turbo_Speed_High_Error (P2581) */
    uint16_t fault_612 : 1;  /* bit 4: fault 612 */
    uint16_t turbocharger_speed_low_error : 1;  /* bit 5: fault 613: e2m 1036 Turbo_Speed_Low_Error (P2580) */
    uint16_t fault_614 : 1;  /* bit 6: fault 614 */
    uint16_t fault_615 : 1;  /* bit 7: fault 615 */
    uint16_t fault_616 : 1;  /* bit 8: fault 616 */
    uint16_t fault_617 : 1;  /* bit 9: fault 617 */
    uint16_t turbocharger_speed_in_range_error : 1;  /* bit 10: fault 618: e2m 1036 Turbo_Speed_In_Range_Error (P2579) */
    uint16_t fault_619 : 1;  /* bit 11: fault 619: e2m 1036 /; e2m '/' names two applications and no DTC decides */
    uint16_t fault_620 : 1;  /* bit 12: fault 620 (B1934) */
    uint16_t fault_621 : 1;  /* bit 13: fault 621 */
    uint16_t fault_622 : 1;  /* bit 14: fault 622 */
    uint16_t fault_623 : 1;  /* bit 15: fault 623 */
    uint16_t fault_624 : 1;  /* bit 0: word faults_624_to_639 (e2m 1036 +4E System_Error_Status_39) bit 0 = fault 624 */
    uint16_t fault_625 : 1;  /* bit 1: fault 625 */
    uint16_t fault_626 : 1;  /* bit 2: fault 626 */
    uint16_t fault_627 : 1;  /* bit 3: fault 627 */
    uint16_t fault_628 : 1;  /* bit 4: fault 628 */
    uint16_t fault_629 : 1;  /* bit 5: fault 629 */
    uint16_t fault_630 : 1;  /* bit 6: fault 630 */
    uint16_t fault_631 : 1;  /* bit 7: fault 631 */
    uint16_t fault_632 : 1;  /* bit 8: fault 632 */
    uint16_t fault_633 : 1;  /* bit 9: fault 633 */
    uint16_t fault_634 : 1;  /* bit 10: fault 634 */
    uint16_t fault_635 : 1;  /* bit 11: fault 635 */
    uint16_t fault_636 : 1;  /* bit 12: fault 636 */
    uint16_t fault_637 : 1;  /* bit 13: fault 637 */
    uint16_t fault_638 : 1;  /* bit 14: fault 638 */
    uint16_t fault_639 : 1;  /* bit 15: fault 639 */
    uint16_t fault_640 : 1;  /* bit 0: word faults_640_to_655 (e2m 1036 +50 System_Error_Status_40) bit 0 = fault 640 */
    uint16_t fault_641 : 1;  /* bit 1: fault 641 */
    uint16_t egr_position_before_autozero_high_error : 1;  /* bit 2: fault 642: e2m 1036 EGR_Position_Before_Autozero_High_Error */
    uint16_t egr_position_before_autozero_low_error : 1;  /* bit 3: fault 643: e2m 1036 EGR_Position_Before_Autozero_Low_Error */
    uint16_t fault_644 : 1;  /* bit 4: fault 644 */
    uint16_t fault_645 : 1;  /* bit 5: fault 645 */
    uint16_t fault_646 : 1;  /* bit 6: fault 646 */
    uint16_t fault_647 : 1;  /* bit 7: fault 647 */
    uint16_t boost_pressure_absolute_high_error : 1;  /* bit 8: fault 648: e2m 1036 Boost_Pressure_Absolute_High_Error */
    uint16_t boost_pressure_absolute_low_error : 1;  /* bit 9: fault 649: e2m 1036 Boost_Pressure_Absolute_Low_Error */
    uint16_t fault_650 : 1;  /* bit 10: fault 650 */
    uint16_t fault_651 : 1;  /* bit 11: fault 651 */
    uint16_t fault_652 : 1;  /* bit 12: fault 652 */
    uint16_t fault_653 : 1;  /* bit 13: fault 653 */
    uint16_t fault_654 : 1;  /* bit 14: fault 654 */
    uint16_t fault_655 : 1;  /* bit 15: fault 655 */
    uint16_t fault_656 : 1;  /* bit 0: word faults_656_to_671 (e2m 1036 +52 System_Error_Status_41) bit 0 = fault 656 */
    uint16_t fault_657 : 1;  /* bit 1: fault 657 */
    uint16_t exhaust_throttle_position_high_error : 1;  /* bit 2: fault 658: e2m 1036 Exhaust_Throttle_Position_High_Error */
    uint16_t exhaust_throttle_position_low_error : 1;  /* bit 3: fault 659: e2m 1036 Exhaust_Throttle_Position_Low_Error */
    uint16_t fault_660 : 1;  /* bit 4: fault 660 */
    uint16_t fault_661 : 1;  /* bit 5: fault 661 */
    uint16_t fault_662 : 1;  /* bit 6: fault 662 */
    uint16_t fault_663 : 1;  /* bit 7: fault 663 */
    uint16_t fault_664 : 1;  /* bit 8: fault 664 */
    uint16_t fault_665 : 1;  /* bit 9: fault 665 */
    uint16_t fault_666 : 1;  /* bit 10: fault 666 */
    uint16_t fault_667 : 1;  /* bit 11: fault 667 */
    uint16_t fault_668 : 1;  /* bit 12: fault 668 */
    uint16_t fault_669 : 1;  /* bit 13: fault 669 */
    uint16_t variable_geometry_turbocharger_closed_adjustment_error : 1;  /* bit 14: fault 670: e2m 1036 VGT_Closed_Adjustment_Error */
    uint16_t variable_geometry_turbocharger_span_adjustment_error : 1;  /* bit 15: fault 671: e2m 1036 VGT_Span_Adjustment_Error */
    uint16_t exhaust_pressure_sensor_high_error : 1;  /* bit 0: word faults_672_to_687 (e2m 1036 +54 System_Error_Status_42) bit 0 = fault 672: e2m 1036 Exhaust_Pressure_Sensor_High_Error */
    uint16_t exhaust_pressure_sensor_low_error : 1;  /* bit 1: fault 673: e2m 1036 Exhaust_Pressure_Sensor_Low_Error */
    uint16_t fault_674 : 1;  /* bit 2: fault 674 */
    uint16_t fault_675 : 1;  /* bit 3: fault 675 */
    uint16_t fault_676 : 1;  /* bit 4: fault 676 */
    uint16_t fault_677 : 1;  /* bit 5: fault 677 */
    uint16_t fault_678 : 1;  /* bit 6: fault 678 */
    uint16_t fault_679 : 1;  /* bit 7: fault 679 */
    uint16_t fault_680 : 1;  /* bit 8: fault 680 */
    uint16_t fault_681 : 1;  /* bit 9: fault 681 */
    uint16_t variable_geometry_turbocharger_position_sensor_high_error : 1;  /* bit 10: sensor channel 101's high fault bit (cm848_processVariableGeometryTurbochargerPositionChannel passes 0x2aa) (was fault_682; PR #53 round 29) | fault 682 */
    uint16_t variable_geometry_turbocharger_position_sensor_low_error : 1;  /* bit 11: sensor channel 101's low fault bit (0x2ab) (was fault_683; PR #53 round 29) | fault 683 */
    uint16_t fault_684 : 1;  /* bit 12: fault 684 */
    uint16_t fault_685 : 1;  /* bit 13: fault 685 */
    uint16_t fault_686 : 1;  /* bit 14: fault 686 */
    uint16_t fault_687 : 1;  /* bit 15: fault 687 */
    uint16_t fault_688 : 1;  /* bit 0: word faults_688_to_703 (e2m 1036 +56 System_Error_Status_43) bit 0 = fault 688 */
    uint16_t fault_689 : 1;  /* bit 1: fault 689 */
    uint16_t egr_delta_pressure_sensor_high_error : 1;  /* bit 2: fault 690: e2m 1036 EGR_Delta_P_Sensor_High_Error */
    uint16_t egr_delta_pressure_sensor_low_error : 1;  /* bit 3: fault 691: e2m 1036 EGR_Delta_P_Sensor_Low_Error */
    uint16_t fault_692 : 1;  /* bit 4: fault 692 */
    uint16_t fault_693 : 1;  /* bit 5: fault 693 */
    uint16_t fault_694 : 1;  /* bit 6: fault 694 */
    uint16_t fault_695 : 1;  /* bit 7: fault 695 */
    uint16_t fault_696 : 1;  /* bit 8: fault 696 */
    uint16_t fault_697 : 1;  /* bit 9: fault 697 */
    uint16_t fault_698 : 1;  /* bit 10: fault 698 */
    uint16_t fault_699 : 1;  /* bit 11: fault 699 */
    uint16_t fault_700 : 1;  /* bit 12: fault 700 */
    uint16_t fault_701 : 1;  /* bit 13: fault 701 */
    uint16_t fault_702 : 1;  /* bit 14: fault 702 */
    uint16_t fault_703 : 1;  /* bit 15: fault 703 */
    uint16_t fault_704 : 1;  /* bit 0: word faults_704_to_719 (e2m 1036 +58 System_Error_Status_44) bit 0 = fault 704 */
    uint16_t fault_705 : 1;  /* bit 1: fault 705 */
    uint16_t fault_706 : 1;  /* bit 2: fault 706 */
    uint16_t fault_707 : 1;  /* bit 3: fault 707 */
    uint16_t fault_708 : 1;  /* bit 4: fault 708 */
    uint16_t fault_709 : 1;  /* bit 5: fault 709: e2m 1036 VGT_Position_PP_High_Error; e2m VGT_Position_PP_High_Error has an abbreviation the code does not resolve (pp) */
    uint16_t fault_710 : 1;  /* bit 6: fault 710: e2m 1036 VGT_Position_PP_Low_Error; e2m VGT_Position_PP_Low_Error has an abbreviation the code does not resolve (pp) */
    uint16_t fault_711 : 1;  /* bit 7: fault 711 */
    uint16_t fault_712 : 1;  /* bit 8: fault 712 */
    uint16_t fault_713 : 1;  /* bit 9: fault 713 */
    uint16_t fault_714 : 1;  /* bit 10: fault 714 */
    uint16_t fault_715 : 1;  /* bit 11: fault 715 */
    uint16_t fault_716 : 1;  /* bit 12: fault 716 */
    uint16_t fault_717 : 1;  /* bit 13: fault 717 */
    uint16_t egr_valve_autozero_error : 1;  /* bit 14: fault 718: e2m 1036 EGR_Valve_Autozero_Error */
    uint16_t egr_delta_pressure_autozero_error : 1;  /* bit 15: fault 719: e2m 1036 EGR_Delta_P_Autozero_Error */
    uint16_t egr_valve_actuator_fault_h_bridge_1_a : 1;  /* bit 0: word faults_720_to_735 (e2m 1036 +5A System_Error_Status_45) bit 0 = fault 720: e2m 1036 EGA_Fault_HB1A; EGA: faults 720-728 are set by cm848_processEgrValveHBridgeFaults and its egr_valve family */
    uint16_t egr_valve_actuator_fault_h_bridge_1_b : 1;  /* bit 1: fault 721: e2m 1036 EGA_Fault_HB1B; EGA: faults 720-728 are set by cm848_processEgrValveHBridgeFaults and its egr_valve family */
    uint16_t egr_valve_actuator_fault_h_bridge_1_over_current_high : 1;  /* bit 2: fault 722: e2m 1036 EGA_Fault_HB1_OC_HI; EGA: faults 720-728 are set by cm848_processEgrValveHBridgeFaults and its egr_valve family */
    uint16_t egr_valve_actuator_fault_h_bridge_1_over_current_low : 1;  /* bit 3: fault 723: e2m 1036 EGA_Fault_HB1_OC_LO; EGA: faults 720-728 are set by cm848_processEgrValveHBridgeFaults and its egr_valve family */
    uint16_t egr_valve_actuator_fault_h_bridge_1_inrush : 1;  /* bit 4: fault 724: e2m 1036 EGA_Fault_HB1_Inrush; EGA: faults 720-728 are set by cm848_processEgrValveHBridgeFaults and its egr_valve family */
    uint16_t egr_valve_actuator_control_error : 1;  /* bit 5: fault 725: e2m 1036 EGA_Control_Error; EGA: faults 720-728 are set by cm848_processEgrValveHBridgeFaults and its egr_valve family */
    uint16_t egr_valve_actuator_electrical_fault : 1;  /* bit 6: fault 726: e2m 1036 EGA_Electrical_Fault; EGA: faults 720-728 are set by cm848_processEgrValveHBridgeFaults and its egr_valve family */
    uint16_t egr_valve_actuator_driver_over_current : 1;  /* bit 7: fault 727: e2m 1036 EGA_Driver_Over_Current; EGA: faults 720-728 are set by cm848_processEgrValveHBridgeFaults and its egr_valve family */
    uint16_t egr_valve_actuator_over_temperature : 1;  /* bit 8: fault 728: e2m 1036 EGA_Over_Temperature; EGA: faults 720-728 are set by cm848_processEgrValveHBridgeFaults and its egr_valve family */
    uint16_t boost_in_range_low_error : 1;  /* bit 9: fault 729: e2m 1036 Boost_In_Range_Low_Error (P0299) */
    uint16_t fault_730 : 1;  /* bit 10: fault 730 */
    uint16_t fault_731 : 1;  /* bit 11: fault 731 */
    uint16_t fault_732 : 1;  /* bit 12: fault 732 */
    uint16_t fault_733 : 1;  /* bit 13: fault 733 */
    uint16_t fault_734 : 1;  /* bit 14: fault 734 */
    uint16_t fault_735 : 1;  /* bit 15: fault 735 */
    uint16_t fault_736 : 1;  /* bit 0: word faults_736_to_751 (e2m 1036 +5C System_Error_Status_46) bit 0 = fault 736 */
    uint16_t fault_737 : 1;  /* bit 1: fault 737 */
    uint16_t variable_geometry_turbocharger_actuator_fault_h_bridge_0_a : 1;  /* bit 2: fault 738: e2m 1036 VGA_Fault_HB0A; VGA: faults 738-746 are set by cm848_processVariableGeometryTurbochargerHBridgeFaults and its family */
    uint16_t variable_geometry_turbocharger_actuator_fault_h_bridge_0_b : 1;  /* bit 3: fault 739: e2m 1036 VGA_Fault_HB0B; VGA: faults 738-746 are set by cm848_processVariableGeometryTurbochargerHBridgeFaults and its family */
    uint16_t variable_geometry_turbocharger_actuator_fault_h_bridge_0_over_current_high : 1;  /* bit 4: fault 740: e2m 1036 VGA_Fault_HB0_OC_HI; VGA: faults 738-746 are set by cm848_processVariableGeometryTurbochargerHBridgeFaults and its family */
    uint16_t variable_geometry_turbocharger_actuator_fault_h_bridge_0_over_current_low : 1;  /* bit 5: fault 741: e2m 1036 VGA_Fault_HB0_OC_LO; VGA: faults 738-746 are set by cm848_processVariableGeometryTurbochargerHBridgeFaults and its family */
    uint16_t variable_geometry_turbocharger_actuator_fault_h_bridge_0_inrush : 1;  /* bit 6: fault 742: e2m 1036 VGA_Fault_HB0_Inrush; VGA: faults 738-746 are set by cm848_processVariableGeometryTurbochargerHBridgeFaults and its family */
    uint16_t variable_geometry_turbocharger_actuator_control_error : 1;  /* bit 7: fault 743: e2m 1036 VGA_Control_Error; VGA: faults 738-746 are set by cm848_processVariableGeometryTurbochargerHBridgeFaults and its family */
    uint16_t variable_geometry_turbocharger_actuator_electrical_fault : 1;  /* bit 8: fault 744: e2m 1036 VGA_Electrical_Fault (B1978); VGA: faults 738-746 are set by cm848_processVariableGeometryTurbochargerHBridgeFaults and its family */
    uint16_t variable_geometry_turbocharger_actuator_driver_over_current : 1;  /* bit 9: fault 745: e2m 1036 VGA_Driver_Over_Current; VGA: faults 738-746 are set by cm848_processVariableGeometryTurbochargerHBridgeFaults and its family */
    uint16_t variable_geometry_turbocharger_actuator_over_temperature : 1;  /* bit 10: fault 746: e2m 1036 VGA_Over_Temperature; VGA: faults 738-746 are set by cm848_processVariableGeometryTurbochargerHBridgeFaults and its family */
    uint16_t fault_747 : 1;  /* bit 11: fault 747 */
    uint16_t fault_748 : 1;  /* bit 12: fault 748 */
    uint16_t fault_749 : 1;  /* bit 13: fault 749 */
    uint16_t fault_750 : 1;  /* bit 14: fault 750 */
    uint16_t fault_751 : 1;  /* bit 15: fault 751 */
    uint16_t fault_752 : 1;  /* bit 0: word faults_752_to_767 (e2m 1036 +5E System_Error_Status_47) bit 0 = fault 752 */
    uint16_t fault_753 : 1;  /* bit 1: fault 753 */
    uint16_t fault_754 : 1;  /* bit 2: fault 754 */
    uint16_t fault_755 : 1;  /* bit 3: fault 755 */
    uint16_t fault_756 : 1;  /* bit 4: fault 756 */
    uint16_t fault_757 : 1;  /* bit 5: fault 757 */
    uint16_t fault_758 : 1;  /* bit 6: fault 758 */
    uint16_t fault_759 : 1;  /* bit 7: fault 759 */
    uint16_t fault_760 : 1;  /* bit 8: fault 760 */
    uint16_t fault_761 : 1;  /* bit 9: fault 761 */
    uint16_t fault_762 : 1;  /* bit 10: fault 762 */
    uint16_t fault_763 : 1;  /* bit 11: fault 763 */
    uint16_t fault_764 : 1;  /* bit 12: fault 764 */
    uint16_t fault_765 : 1;  /* bit 13: fault 765 */
    uint16_t fault_766 : 1;  /* bit 14: fault 766 */
    uint16_t fault_767 : 1;  /* bit 15: fault 767 */
    uint16_t fault_768 : 1;  /* bit 0: word faults_768_to_783 (e2m 1036 +60 System_Error_Status_48) bit 0 = fault 768 */
    uint16_t fault_769 : 1;  /* bit 1: fault 769 */
    uint16_t fault_770 : 1;  /* bit 2: fault 770 */
    uint16_t fault_771 : 1;  /* bit 3: fault 771 */
    uint16_t fault_772 : 1;  /* bit 4: fault 772 */
    uint16_t fault_773 : 1;  /* bit 5: fault 773 */
    uint16_t egr_delta_pressure_in_range_error : 1;  /* bit 6: fault 774: e2m 1036 EGR_DP_In_Range_Error */
    uint16_t egr_delta_pressure_in_range_high_error : 1;  /* bit 7: fault 775: e2m 1036 EGR_DP_In_Range_High_Error */
    uint16_t egr_delta_pressure_in_range_low_error : 1;  /* bit 8: fault 776: e2m 1036 EGR_DP_In_Range_Low_Error */
    uint16_t egr_delta_pressure_startup_error : 1;  /* bit 9: fault 777: e2m 1036 EGR_DP_Startup_Error */
    uint16_t boost_ambient_delta_error : 1;  /* bit 10: fault 778: e2m 1036 Boost_Ambient_Delta_Error (P0069) */
    uint16_t fault_779 : 1;  /* bit 11: fault 779 */
    uint16_t fault_780 : 1;  /* bit 12: fault 780 */
    uint16_t fault_781 : 1;  /* bit 13: fault 781 */
    uint16_t fault_782 : 1;  /* bit 14: fault 782 */
    uint16_t fault_783 : 1;  /* bit 15: fault 783 */
    uint16_t fault_784 : 1;  /* bit 0: word faults_784_to_799 (e2m 1036 +62 System_Error_Status_49) bit 0 = fault 784 */
    uint16_t fault_785 : 1;  /* bit 1: fault 785 */
    uint16_t fault_786 : 1;  /* bit 2: fault 786 */
    uint16_t fault_787 : 1;  /* bit 3: fault 787 */
    uint16_t variable_geometry_turbocharger_sampled_position_high_error : 1;  /* bit 4: fault 788: e2m 1036 TVA_Sampled_Position_High_Error (B1973); TVA: e2m names channel 101's VGT position block TVA_Sampled_Position */
    uint16_t variable_geometry_turbocharger_sampled_position_low_error : 1;  /* bit 5: fault 789: e2m 1036 TVA_Sampled_Position_Low_Error (B1974); TVA: e2m names channel 101's VGT position block TVA_Sampled_Position */
    uint16_t fault_790 : 1;  /* bit 6: fault 790 */
    uint16_t fault_791 : 1;  /* bit 7: fault 791 */
    uint16_t fault_792 : 1;  /* bit 8: fault 792 */
    uint16_t fault_793 : 1;  /* bit 9: fault 793 */
    uint16_t fault_794 : 1;  /* bit 10: fault 794 */
    uint16_t fault_795 : 1;  /* bit 11: fault 795 */
    uint16_t egr_orifice_temperature_high_error : 1;  /* bit 12: fault 796: e2m 1036 EGR_Orifice_Temperature_High_Error */
    uint16_t egr_orifice_temperature_low_error : 1;  /* bit 13: fault 797: e2m 1036 EGR_Orifice_Temperature_Low_Error */
    uint16_t fault_798 : 1;  /* bit 14: fault 798 */
    uint16_t fault_799 : 1;  /* bit 15: fault 799 */
};

struct wastegate_duty_controller_state_t {
    uint16_t request_half_duty_counts;  /* Governor output RPM */
    uint16_t selected_control_term;  /* Gap (0xa3cc) */
    uint16_t first_error_proportional_derivative_term;  /* Gap (0xa3ce) */
    uint16_t first_error_gain;  /* Gap (0xa3d0) */
    uint16_t floor_half_duty_counts;  /* Bottom of governor droop band */
    uint16_t floor_altitude_adjustment_half_duty_counts;  /* Pressure-based limit trim */
    uint16_t ceiling_grid_lookup_half_duty_counts;  /* Gap (0xa3d6) */
    uint16_t floor_grid_lookup_half_duty_counts;  /* Gap (0xa3d8) */
    uint16_t ceiling_half_duty_counts;  /* Target RPM setpoint */
    uint16_t ceiling_altitude_adjustment_half_duty_counts;  /* Pressure-based setpoint trim */
    uint16_t engine_speed_ceiling_half_duty_counts;  /* Base RPM from calibration table before adjustments */
};

struct egr_flow_estimate_terms_t {
    uint16_t egr_oxygen_fraction;  /* e2m 177F +0 CHP_O2_Frac_EGR 'Oxygen fraction in EGR' (1/8192; 8192 = 1.0 in the RAM dump with the engine stopped): residual_oxygen_fraction_before_delay delayed by oxygen_flow_delay_milliseconds and filtered in cm848_calculateDelayedEgrFlowAndFraction; read by cm848_calculateCylinderOxygenMasses (was residual_oxygen_fraction_delayed_filtered) */
    uint16_t egr_fraction_actual;  /* e2m 177F +2 EGR_Fraction (1/8192; capped at 8192 = 1.0): egr_mass_flow_delayed_filtered x 8192 / charge_mass_flow_filtered in cm848_calculateDelayedEgrFlowAndFraction (0 while the charge flow is 64 counts = 0.5 lb/min or less). The e2m text says 'Charge Mgr demanded EGR fraction after limiters' but the code computes the delayed flow ratio. Readers: cm848_calculateChargeSystemErrors / cm848_calculateAirFuelRatioAndIntakeOxygenFraction / cm848_calculateWaterVaporAndSaturationTemperatures */
    int16_t egr_mass_flow_before_delay;  /* e2m 177F +4 CHP_EGR_Flow_Before_Delay 'EGR flow before delay is imposed' (signed lb/min x 128): cm848_calculateEgrMassFlowBeforeDelay limits the selected model (upstream_egr_mass_flow or downstream_egr_mass_flow) to egr_mass_flow_estimate_minimum .. egr_mass_flow_estimate_maximum and forces 0 while egr_valve_closed_flag is set (was final_trim) */
    uint16_t egr_flow_delay_milliseconds;  /* e2m 177F +6 CHP_EGR_Flow_Delay 'Delay between air passing EGR valve and when that air reaches the intake valve' (0.001 s per count): oxygen_flow_delay_milliseconds x egr_flow_delay_fraction / 32767; its tenth is the EGR mass flow delay in 10 ms samples (was load_adjusted) */
    int16_t downstream_egr_mass_flow;  /* e2m 177F +8 CHP_Downstream_EGR_Flow 'Model of incompressible flow across fixed orifice' (signed lb/min x 128): downstream_egr_corrected_flow x charge_pressure / egr_orifice_temperature_rankine_square_root saturated at +-25600 in cm848_calculateDownstreamEgrMassFlow (was load_based_trim) */
    int16_t upstream_egr_mass_flow;  /* e2m 177F +A CHP_Upstream_EGR_Flow 'Empirical model relating lift and hot side dP to Flow' (signed lb/min x 128): upstream_egr_corrected_flow x exhaust_pressure (e2m 1A5D +0 Exhaust_Press) / exhaust_temperature_rankine_square_root saturated at +-25600 in cm848_calculateUpstreamEgrMassFlow (was rpm_based_trim) */
    int16_t downstream_egr_corrected_flow;  /* e2m 177F +C CHP_Downstream_Corrected_Flow 'Table output for downstream EGR corrected flow 3D Table': cm848_dualAxisTableInterpolation of the filtered egr_valve_position and downstream_egr_pressure_ratio in cm848_calculateDownstreamEgrMassFlow (was reserved_0c) */
    int16_t downstream_egr_pressure_ratio;  /* e2m 177F +E CHP_Downstream_Pratio 'EGR dP/P pressure ratio' (Q15): egr_orifice_delta_pressure x 32767 / charge_pressure limited to +-32440 (+-0.99) in cm848_calculateDownstreamEgrMassFlow (was rpm_conversion) */
    uint16_t exhaust_temperature_rankine_square_root;  /* e2m 177F +10 CHP_Sqrt_Texhaust_R 'Output of SQRT(Texhaust) Table for EGR flow Calculation' (SQRT(DEG_R)): lookupTableInterpolation of exhaust_temperature in cm848_calculateUpstreamEgrMassFlow (was reserved_10) */
    int16_t upstream_egr_corrected_flow;  /* e2m 177F +12 CHP_Upstream_Corrected_Flow 'table output for upstream EGR flow 3D Table': cm848_dualAxisTableInterpolation of egr_valve_position and charge_flow_estimate_terms.pressure_ratio in cm848_calculateUpstreamEgrMassFlow (was reserved_12) */
    uint16_t oxygen_flow_delay_milliseconds;  /* e2m 177F +14 CHP_O2_Flow_Delay 'Delay between exhaust man calculated O2 and when that O2 reaches intake valve' (0.001 s per count): oxygen_flow_delay_volume_fraction x 120 x 1000 / (engine_volumetric_efficiency x engine speed) in cm848_calculateDelayedEgrFlowAndFraction; 40959 in the RAM dump (engine stopped: the 0xffff sentinel for a fraction above 1.0 over the 1600-count floor) (was throttle_conversion) */
    uint16_t egr_orifice_temperature_rankine_square_root;  /* e2m 177F +16 CHP_Sqrt_Torifice_R 'Output of SQRT(Torifice) Table for CHP_Downstream_EGR_Flow calculation' (SQRT(DEG_R); 2951 in the RAM dump): lookupTableInterpolation of egr_orifice_temperature in cm848_calculateDownstreamEgrMassFlow (was reserved_16) */
};

struct delay_line_t {
    uint16_t samples[256];  /* The 256 samples: each call stores its sample at write_index (sthx) and reads the one written delay_samples calls earlier at (write_index - delay_samples) mod 256 */
    uint8_t write_index;  /* The slot of the next sample: lbz / stb at +0x200; advanced once per call and wraps at 256 (191 / 215 in the RAM dump) */
    uint8_t spare;  /* Pads the record to 514 bytes (the second line starts at +0x202); no access found; 0 in the RAM dump */
};

struct combustion_reference_state_t {
    uint16_t alpha_percent;  /* Fuel blend mode selector */
    uint16_t egr_off_flag;  /* enable flag (=fuel_blend_enable_flag); overridden by fuel_blend_mode_override_cal when engine_feature_enable_flags & 0x100 */
    uint16_t gross_fuel_timing_adjustment_active_flag;  /* 1 when final_fueling_before_combustion_reference >= injection_quantity_combustion_gross_timing_adjustment_threshold */
    uint16_t injection_timing_fuel_limited_adjustment;  /* dual-axis table result added to engine_load_normalized when fuel_blend_bypass_flag active */
    uint16_t injection_quantity_gross_before_timing_adjustment;  /* snapshot of final_fueling_before_combustion_reference */
    uint16_t chi_hundredths;  /* Fuel blend weight factor (0-100%) */
};

struct charge_flow_estimate_terms_t {
    uint16_t intake_manifold_temperature_rankine;  /* e2m 177D +2 CHP_Intake_Manifold_Tmptr_R: the intake manifold temperature in degrees Rankine (intake_manifold_temperature_filtered + 0x7300) */
    uint16_t volumetric_efficiency_mach;  /* e2m 177D +4 CHP_Veff_Mach: the volumetric efficiency test point based on engine speed and stroke */
    uint16_t volumetric_efficiency_square_root;  /* e2m 177D +6 CHP_Veff_Sqrt: the volumetric efficiency test point based only on energy */
    uint16_t flow_area_constant;  /* e2m 177D +8 CHP_Flow_Area_Constant */
    uint16_t pressure_ratio;  /* e2m 177D +A CHP_Pratio: the charge flow pressure ratio */
    SENSOR_VALUE_SOURCE charge_flow_source;  /* e2m 177D +C Charge_Flow_Source: 0 primary / 1 backup | typed SENSOR_VALUE_SOURCE in PR #53 round 23 (was word): e2m 177D +C Charge_Flow_Source lists 0=PRIMARY, 1=BACKUP, and the code uses only 0 / 1 */
    uint16_t fresh_air_mass_flow_filtered;  /* e2m 177B +0 Fresh_Air_Flow: the fresh air flow virtual sensor (lb/min) */
    SENSOR_VALUE_SOURCE fresh_air_flow_source;  /* e2m 177B +2 Fresh_Air_Flow_Source: 0 primary / 1 backup | typed SENSOR_VALUE_SOURCE in PR #53 round 23 (was word): e2m 177B +2 Fresh_Air_Flow_Source lists 0=PRIMARY, 1=BACKUP, and the code uses only 0 / 1 and compares 2 (DEFAULT) */
};

struct engine_speed_limit_arbitration_t {
    uint16_t limiting_source_number;  /* Number of the engine speed limit source that wins the arbitration (e2m HSG_Ref_Speed_State) */
    uint16_t applied_speed_limit;  /* Engine speed limit applied by the governor in 0.125 rpm counts - the ramped limit or the ramped limit plus the droop term capped by the droop cap (e2m HSG_Reference_Speed) */
    uint16_t lowest_source_speed_limit;  /* Lowest engine speed limit of the sources in the current pass in 0.125 rpm counts - reset to engine_speed_limit_default_cal at the end of cm848_selectEngineSpeedLimit (e2m HSG_Ref_Speed_Before_Droop) */
};

struct operating_mode_governor_output_t {
    uint16_t fuel_demand;  /* Fuel demand of the engine operating mode governor as the output stages see it: engine_operating_mode_fuel_demand or power_take_off_governor_fuel_demand (the power take-off fuel - Cummins PTSLFL per e2m block 1265 +4) (was proportional_gain) */
    FUELING_STATE mode_code;  /* The user fueling state after the power take-off selection (Cummins PTSLFLST per e2m block 1265 +6 - 1-8): engine_operating_mode (1 2 5 6 7 8 30 37 38) or FUELING_STATE_POWER_TAKE_OFF when cm848_selectPowerTakeOffOrUserFueling lets power_take_off_governor_fuel_demand replace the fuel (was integral_term) */
};

struct transmission_lockup_timers_t {
    uint16_t lockup_delay_2_3_timer;  /* e2m 8C17 +1A RE_Lockup_Delay_2_3 ('Timer used to delay lockup') after the 2-3 shift (was thermal_lockout) */
    uint16_t lockup_delay_3_4_timer;  /* e2m 8C17 +1C RE_Lockup_Delay_3_4 ('Timer used to delay lockup') after the 3-4 shift (was load_lockout) */
    uint16_t lockup_delay_4_3_timer;  /* e2m 8C17 +1E RE_Lockup_Delay_4_3 ('Timer used to delay lockup') after the 4-3 shift (was rpm_lockout) */
    uint16_t lockup_off_timer;  /* e2m 8C17 +20 RE_Lockup_Off_Timer ('Timer used to anticipate unlock delay') (was sensor_fault_active) */
    uint16_t low_range_hold_timer;  /* e2m 8C17 +22 RE_Low_Range_Hold_Timer ('Timer used to delay low range hold pressure') (was reserved_08) */
    uint16_t low_range_shift_timer;  /* e2m 8C17 +24 RE_Low_Range_Shift_Timer ('Timer used to delay low range shifts'): reloaded from transmission_low_range_1_2_boost_time / _2_3_ (was timer_expired) */
};

struct j1939_msg_hdr_t {
    uint32_t can_id;  /* Packed J1939 29-bit CAN identifier (priority[31:29] DP[28] PGN[27:8] SA[7:0]) */
    uint16_t data_length;  /* CAN DLC - payload byte count for TX message */
};

struct parameter_response_t {
    uint8_t error_code;  /* Error code (0=success non-zero=error) */
    uint16_t param_value;  /* Retrieved parameter value */
    uint8_t scaling_applied;  /* Flag indicating if scaling was applied */
    uint32_t timestamp;  /* Response generation timestamp */
};

struct calterm_protocol_t {
    uint8_t command_id;  /* CalTerm command identifier */
    uint8_t parameter_count;  /* Number of parameters in request/response */
    uint8_t data_payload[8];  /* Parameter data payload (up to 8 bytes) */
    uint8_t checksum;  /* Message integrity checksum */
};

struct insite_protocol_t {
    uint8_t function_code;  /* Insite function code */
    uint8_t live_data_request;  /* Live data monitoring request flag */
    uint8_t status_flags;  /* Monitoring status flags */
    uint8_t response_data[6];  /* Live parameter response data */
};

struct sensor_channel_config_t {
    uint16_t filter_coefficient;  /* EMA coefficient: the weight of the previous filtered value in 1/65536 (0 = no filtering) - the channel's ema_filter_state_t.coefficient points here (was config_word0) */
    uint16_t default_value;  /* Nominal/fault fallback value (written to filtered output and state_ptr[1]) */
    uint16_t high_threshold;  /* Upper limit - sensor value above this trips the high fault path */
    uint16_t low_threshold;  /* Lower limit - sensor value below this trips the low fault path */
    uint16_t debounce_step;  /* Per-cycle increment added to the debounce counter while ramping toward the limit */
    uint16_t recovery_decrement;  /* Per-cycle decrement applied to the debounce counter when back in range */
    uint16_t debounce_limit;  /* Debounce counter target - reached = fault confirmed */
    uint16_t debounce_clear_threshold;  /* Counter at or below this clears the confirmed-fault flags */
};

struct sensor_channel_state_t {
    uint16_t raw_adc_counts;  /* QADC result read this pass (sensor_channel_diag_override while diagnostics override the channel) */
    uint16_t value;  /* Engineering value: the table lookup of lookup_input (config default_value while the channel is disabled or faulted) - filtered into sensor_channel_filtered_output[channel] */
    uint16_t debounce_count;  /* Fault debounce: + debounce_step toward debounce_limit while out of range / - recovery_decrement back in range */
    uint16_t held_value;  /* Output while the channel is held (its fuel_demand_feature_flags bit set) - config default_value from the boot pass */
    uint8_t held_value_source_priority;  /* Priority of the source that last wrote held_value - the J1939 input layer arbitrates with it (the accelerator pedal channel 13 - cm848_processJ1939AcceleratorPedalPosition); not used by the sensor-channel functions */
    uint8_t spare;  /* Not accessed */
    uint16_t lookup_input;  /* Table input: raw x sensor_channel_ratio_scale / the supply channel's filtered output (capped at 0x3ff) or the raw reading for type-0 channels */
};

struct cruise_governor_gain_set_t {
    int16_t proportional_gain;  /* +0: e2m Cruise_RSG_Proportional_Gain_Cal* (MM3S/RPM); the working cruise_pid_proportional_gain */
    int16_t integral_gain;  /* +2: e2m Cruise_RSG_Integral_Gain_Cal* (MM3S/RPM/SEC); the working cruise_pid_integral_gain */
    int16_t derivative_gain;  /* +4: e2m Cruise_RSG_Derivative_Gain_Cal* (MM3S*SEC/RPM); the working cruise_pid_derivative_gain */
    int16_t integral_acceleration_gain;  /* +6: e2m Cruise_RSG_Integral_Acc_Gain_Cal* (MM3S/RPM) 'Integral Acceleration Gain from the differential path'; the working cruise_pid_integral_acceleration_gain */
};

struct second_order_filter_state_t {
    word* coefficient_1;  /* +0: points at coefficient 1 (1/65536): the weight of the new input */
    word* coefficient_3;  /* +4: points at coefficient 3 (1/65536): the weight of the output before last */
    uint32_t output;  /* +8: the filter output (Q16.16 in cm848_secondOrderFilter; its integer part is returned) */
    uint32_t output_previous;  /* +C: the output of the previous call */
};

struct engine_retarder_brake_type_t {
    uint16_t exhaust_brake : 1;  /* bit 0: Bit 0 (e2m 1 = EXHAUST): drive the exhaust brake output (logical output 11); set on this truck */
    uint16_t variable_geometry_turbocharger_brake : 1;  /* bit 1: Bit 1 (e2m 2 = VG): brake with the VGT (variable_geometry_turbocharger_brake_active_flag); clear on this truck */
    uint16_t : 14;
};

struct ema_filter_state_t {
    word* coefficient;  /* Points at the filter coefficient (a sensor channel's config filter_coefficient): the weight of the previous value in 1/65536 - 0 = no filtering */
    uint32_t accumulator;  /* Q16.16 filtered value - its integer part is the output */
};

struct high_speed_governor_gain_set_t {
    uint16_t derivative_gain;  /* Derivative gain (coefficient 3) */
    uint16_t error_filter_coefficient;  /* Error filter coefficient (coefficient 4): the weight of the previous filtered speed error in 1/65536 - 0 = no filtering */
    uint16_t integral_gain;  /* Integral gain (coefficient 2) */
    uint16_t proportional_gain;  /* Proportional gain (coefficient 1) */
};

struct q16_fixed_point_t {
    uint16_t integer_part;  /* High 16 bits - integer/whole number portion */
    uint16_t fractional_part;  /* Low 16 bits - fractional portion */
};

struct dma_descriptor_t {
    uint32_t source_address;  /* DMA transfer source memory address */
    uint32_t dest_address;  /* DMA transfer destination memory address */
    uint16_t transfer_count;  /* Number of bytes/words to transfer */
    uint16_t control_flags;  /* DMA control flags (mode type enable etc) */
    uint32_t next_descriptor;  /* Pointer to next descriptor in chain */
};

struct memory_patch_entry_t {
    uint32_t target_address;  /* Memory address to patch */
    uint8_t patch_size;  /* Number of bytes to copy to target address */
    uint8_t reserved;  /* Unused padding byte for 6-byte alignment */
};

struct j1939_pgn_handler_entry_t {
    uint8_t pgn_byte_1;  /* First PGN byte for matching (compared against msg+6+1) */
    uint8_t pgn_byte_0;  /* Second PGN byte for matching (compared against msg+6+0) */
    uint32_t handler_func;  /* Function pointer to PGN handler callback */
};

struct j1939_tx_msg_t {
    j1939_msg_hdr_t header;  /* J1939 TX message header (can_id + data_length) */
    void * data_pointer;  /* Pointer to the first payload byte */
    void * status_pointer;  /* Points at the message's status byte j1939_<message>_transmit_status (was data_end_pointer: the byte often sits right after the payload; PR #53 round 33): in the application mpc555_sendJ1939SingleFrame stores its result there (0 queued / 1 zero length / 4 queue full) and the transport its session codes: a broadcast (BAM) session through the per source address records at 0x3fbd74 (initiateJ1939TransportProtocol / cm848_sendJ1939BroadcastDataPacket: 0x10 announced / 0x11 sending / 5 complete / 2 already active) and a destination-specific (RTS / CTS) session through j1939_multiframe_tx_status_ptr (0x12 started / 0x13 sending / 9 complete / 10 aborted / 6 clear to send timeout / 7 send failed / 8 busy); 3 = not our source address. The multi-frame builders rebuild only while its 0xf0 nibble is clear (no session in progress). The boot twin is diagnostic_response_message_t.status_pointer */
};

struct j1939_acknowledgement_payload_t {
    J1939_ACK_TYPE control_byte;  /* J1939-21 ACKM control byte (ACK/NACK/ACCESS_DENIED/CANNOT_RESPOND) */
    uint8_t group_function;  /* Group function value (0xFF = not defined per J1939-21) */
    uint8_t reserved_byte2;  /* Reserved byte 2 (always 0xFF per J1939-21) */
    uint8_t reserved_byte3;  /* Reserved byte 3 (always 0xFF per J1939-21) */
    uint8_t address_acknowledged;  /* Source address of message being acknowledged (0xFF = global) */
    uint8_t pgn_low;  /* Acknowledged PGN low byte (hardcoded 0 for PDU1 requests) */
    uint8_t pgn_mid;  /* Acknowledged PGN mid byte (= pgn_pf of request) */
    uint8_t pgn_high;  /* Acknowledged PGN high byte (= dest_address of request) */
};

struct j1939_ack_msg_t {
    J1939_ACK_TYPE control_byte;  /* J1939-21 ACKM control byte */
    uint8_t group_function;  /* Group function value (0xFF = not defined per J1939-21) */
    uint8_t reserved_byte2;  /* Reserved byte 2 (always 0xFF per J1939-21) */
    uint8_t reserved_byte3;  /* Reserved byte 3 (always 0xFF per J1939-21) */
    uint8_t address_acknowledged;  /* Source address of message being acknowledged (0xFF = global) */
    uint8_t pgn_low;  /* Acknowledged PGN low byte (hardcoded 0 for PDU1 requests) */
    uint8_t pgn_mid;  /* Acknowledged PGN mid byte (= PF byte of request) */
    uint8_t pgn_high;  /* Acknowledged PGN high byte (= PS/DP byte of request) */
};

struct eeprom_param_t {
    uint16_t value;  /* Parameter value (resolution varies per parameter) */
    uint16_t min_limit;  /* Minimum allowed value for parameter */
    uint16_t max_limit;  /* Maximum allowed value for parameter */
    uint16_t default_value;  /* Factory default value */
    uint32_t callback_param;  /* Diagnostic callback parameter for EEPROM transfer */
};

struct param_lookup_args_t {
    uint32_t calculated_block;  /* Block × 256 × 4 calculation result */
    uint16_t offset;  /* Parameter offset within block */
    uint16_t result_value;  /* Retrieved parameter value (capped at 32000) */
};

struct can_param_msg_t {
    uint8_t msg_id;  /* Message identifier */
    uint8_t param_1;  /* First parameter byte */
    uint8_t param_2;  /* Second parameter byte */
    uint8_t param_3;  /* Third parameter byte */
    uint8_t param_4;  /* Fourth parameter byte */
    uint16_t timestamp;  /* Message timestamp */
    uint8_t checksum;  /* Message checksum */
};

struct scheduler_phase_slot_t {
    uint32_t last_execution_time;  /* Timer value of last task execution */
    uint16_t runtime_ticks;  /* Task runtime duration in timer ticks */
    uint16_t deadline_ticks;  /* Task execution deadline (0xFFFF = disabled) */
    uint16_t execution_count;  /* Number of times task has been executed */
    uint16_t overrun_count;  /* Number of deadline overruns detected */
    uint32_t reserved;  /* Reserved/padding bytes for alignment */
};

struct ad_sensor_config_t {
    uint16_t channel_addr;  /* A/D channel address for sensor input */
    uint16_t filter_const;  /* Digital filter constant (0-1) */
    uint16_t fault_clear_count;  /* Fault clear counter threshold */
    uint16_t fault_decrement;  /* Fault counter decrement value */
    uint16_t fault_increment;  /* Fault counter increment value */
    uint16_t fault_set_threshold;  /* Fault set threshold */
    uint16_t high_error_limit;  /* A/D high error limit (0-1023) */
    uint16_t low_error_limit;  /* A/D low error limit (0-1023) */
};

struct sensor_fault_config_t {
    uint16_t reserved_00;  /* Reserved/padding at offset 0x00 */
    uint16_t default_value;  /* Default sensor value on fault (offset 0x02) */
    uint16_t clear_threshold;  /* Threshold for fault clear (offset 0x04) */
    uint16_t decrement_value;  /* Debounce counter decrement (offset 0x06) */
    uint16_t increment_value;  /* Debounce counter increment (offset 0x08) */
    uint16_t set_threshold;  /* Threshold for fault set (offset 0x0a) */
    uint16_t high_limit;  /* High error limit (offset 0x0c) */
    uint16_t low_limit;  /* Low error limit (offset 0x0e) */
    uint16_t adc_lookup_index;  /* A/D channel lookup table index (offset 0x10) */
    uint8_t reserved_12;  /* Reserved byte at offset 0x12 */
    uint8_t alt_fault_enable;  /* Alternative fault enable flag (offset 0x13) */
    uint8_t primary_fault_id;  /* Primary fault code packed bit/word (offset 0x14) */
    uint8_t secondary_fault_id;  /* Secondary fault code (offset 0x15) */
    uint8_t tertiary_fault_id;  /* Tertiary fault code (offset 0x16) */
    uint8_t debounce_max;  /* Maximum debounce count (offset 0x17) */
};

struct sensor_debounce_state_t {
    uint8_t reserved_00[8];  /* Reserved bytes at offset 0x00-0x07 */
    uint16_t interpolated_value;  /* Interpolated sensor value (offset 0x08) */
    uint16_t lookup_result;  /* Table lookup result (offset 0x0a) */
    uint16_t debounce_counter;  /* Current debounce count (offset 0x0c) */
    uint8_t fault_active_flag;  /* Fault currently active flag (offset 0x0e) */
    uint8_t sample_counter;  /* Sample phase counter (offset 0x0f) */
    uint16_t adc_raw_value;  /* Raw A/D conversion value (offset 0x10) */
    uint8_t reserved_12[4];  /* Reserved bytes at offset 0x12-0x15 */
};

struct cummins_data_plate_t {
    uint16_t data_plate_length;  /* Data plate length field */
    uint8_t engine_make[5];  /* Engine manufacturer identifier */
    uint8_t engine_model[17];  /* Engine model designation */
    uint32_t engine_serial_number;  /* Engine serial number */
    uint8_t engine_build_month;  /* Engine manufacturing month */
    uint8_t engine_build_day;  /* Engine manufacturing day */
    uint8_t engine_build_year;  /* Engine manufacturing year */
    uint16_t engine_cpl;  /* Engine CPL (Component Parts List) */
    uint16_t peak_torque_low_range;  /* Peak torque low range value */
    uint16_t peak_torque_high_range;  /* Peak torque high range value */
    uint16_t peak_torque_rpm_low;  /* Peak torque RPM low range */
    uint16_t peak_torque_rpm_high;  /* Peak torque RPM high range */
    uint16_t governed_speed_low;  /* Governed speed low range */
    uint16_t governed_speed_high;  /* Governed speed high range */
    uint16_t horsepower_low_range;  /* Horsepower low range value */
    uint16_t horsepower_high_range;  /* Horsepower high range value */
    uint16_t horsepower_rpm_low;  /* Horsepower RPM low range */
    uint16_t horsepower_rpm_high;  /* Horsepower RPM high range */
    uint8_t fuel_code_part_number[7];  /* Fuel code part number */
    uint8_t percent_torque_rise;  /* Percent torque rise specification */
    uint16_t peak_torque;  /* Peak torque specification */
    uint16_t peak_torque_rpm;  /* Peak torque RPM specification */
    uint16_t governed_speed;  /* Governed speed specification */
    uint16_t ecm_id;  /* ECM identification number */
    uint32_t ecm_part_number;  /* ECM part number */
    uint32_t ecm_serial_number;  /* ECM serial number */
    uint8_t ecm_voltage_low_range;  /* ECM voltage low range */
    uint8_t ecm_voltage_high_range;  /* ECM voltage high range */
    uint8_t ecm_code[10];  /* ECM identification code */
    uint8_t engine_calibration_time[12];  /* Engine calibration timestamp */
    uint16_t sc_option_number;  /* SC option number */
    uint16_t do_option_number;  /* DO option number */
    uint8_t other_options[40];  /* Other options field */
    uint8_t oem_name[15];  /* Original equipment manufacturer name */
    uint8_t oem_vehicle[15];  /* OEM vehicle designation */
    uint8_t vin[20];  /* Vehicle identification number */
    uint8_t vehicle_year[10];  /* Vehicle manufacturing year */
    uint8_t customer_name[15];  /* Customer name */
    uint8_t location[15];  /* Installation location */
    uint8_t unit_number[10];  /* Unit identification number */
};

struct memory_operation_request_t {
    uint32_t source_data_ptr;  /* Pointer to source data for memory operation */
    uint32_t target_data_ptr;  /* Pointer to destination memory location */
    uint16_t operation_size;  /* Number of bytes to copy (max varies) */
    uint16_t metadata_value;  /* Logging metadata/timestamp for circular buffer */
};

struct j1939_source_addresses_t {
    uint16_t source_addr_1;  /* J1939 source address 1 */
    uint16_t source_addr_2;  /* J1939 source address 2 */
    uint16_t source_addr_3;  /* J1939 source address 3 */
    uint16_t source_addr_4;  /* J1939 source address 4 */
    uint16_t source_addr_5;  /* J1939 source address 5 */
};

struct network_type_switches_t {
    uint8_t type_switch_1;  /* Network type switch 1 (0=J1922 1=J1939) */
    uint8_t type_switch_2;  /* Network type switch 2 (0=J1922 1=J1939) */
    uint8_t type_switch_3;  /* Network type switch 3 (0=J1922 1=J1939) */
    uint8_t type_switch_4;  /* Network type switch 4 (0=J1922 1=J1939) */
    uint8_t type_switch_5;  /* Network type switch 5 (0=J1922 1=J1939) */
};

struct diag_transfer_state_t {
    uint16_t target_address;  /* Target memory address for transfer */
    uint32_t data_pointer;  /* Pointer to source/dest data buffer */
    uint16_t remaining_length;  /* Remaining bytes to transfer */
    uint16_t byte_count;  /* Total byte count for operation */
    uint8_t tx_active_flag;  /* Transmit operation active (0/1) */
    uint8_t rx_active_flag;  /* Receive operation active (0/1) */
};

struct diag_service_request_t {
    uint8_t message_length;  /* Total message length including header */
    uint8_t service_id;  /* Service identifier (3=secured 4=control 5=memory) */
    uint8_t sub_function;  /* Sub-function code for service routing */
    uint8_t data_payload[16];  /* Variable-length request data payload */
};

struct circular_buffer_t {
    uint16_t write_index;  /* Current write position (0-N) */
    uint16_t entry_count;  /* Number of entries in buffer */
    uint16_t read_index;  /* Current read position (0-N) */
    uint16_t buffer_size;  /* Maximum buffer capacity */
};

struct address_range_entry_t {
    uint32_t start_address;  /* Start of valid address range (big-endian) */
    uint32_t end_address;  /* End of valid address range (big-endian) */
    uint8_t special_mode_flag;  /* Access flag when in special mode (non-0x09/0x0A = allow) */
    uint8_t normal_mode_flag;  /* Access flag in normal operation (0x09=invalid 0x0A=denied other=allow) */
};

struct fuel_limit_arbitration_t {
    uint16_t source_id;  /* ID of current fuel limit source (arbitrator output) */
    uint16_t demand_limited;  /* Rate-limited fuel demand */
    uint16_t arbitration_threshold;  /* Fuel limit arbitration threshold */
    uint16_t demand_delta;  /* Fuel demand delta for rate limiting */
    uint16_t maximum_limit;  /* Maximum fuel demand limit */
    uint16_t offset_value;  /* Fuel limit offset value */
    uint16_t comparison_low;  /* Fuel limit comparison low value */
    uint16_t comparison_high;  /* Fuel limit comparison high value */
    uint16_t rate_limit;  /* Fuel demand rate limiting value */
};

struct engine_control_flags_t {
    uint16_t fuel_demand_control;  /* Fuel demand mode control flags */
    uint16_t protection_system;  /* Protection system status flags */
    uint16_t engine_operating_state;  /* Engine operating state flags */
    uint16_t reserved_06;  /* Gap/reserved */
    uint16_t reserved_08;  /* Gap/reserved */
    uint16_t fuel_temp_control;  /* Fuel temp control bit flags */
};

struct high_rpm_protection_t {
    uint16_t fault_flag;  /* High RPM protection fault active flag */
    uint16_t state;  /* State machine state */
    uint16_t timer;  /* Countdown timer */
    uint16_t reserved_06;  /* Reserved/gap */
    uint16_t warning_flag;  /* Warning active flag */
};

struct oil_pressure_protection_t {
    uint32_t sensor_status_history_bits;  /* Sensor status history bits - shifting record */
    uint16_t rpm_ramp_complete;  /* Flag indicating RPM ramp complete */
    uint16_t rpm_limit_current;  /* Current RPM limit from oil pressure */
    uint16_t rpm_limit_target;  /* Target RPM limit for oil pressure */
    uint16_t rpm_limit_previous;  /* Previous RPM limit for tracking */
    uint16_t state_index;  /* State index for oil pressure protection */
    uint16_t validation_timer;  /* Timer for oil pressure validation */
    uint16_t sensor_validation_counter;  /* Sensor status validation counter */
};

struct fault_persistence_counters_t {
    uint8_t periodic_monitor_phase;  /* 5-phase counter for periodic fault monitoring */
    uint8_t can_pin_fault;  /* CAN pin switching fault persistence counter */
    uint8_t io_fault_1;  /* I/O control fault 1 persistence counter */
    uint8_t io_fault_2;  /* I/O control fault 2 persistence counter */
    uint8_t io_fault_3;  /* I/O control fault 3 persistence counter */
    uint8_t io_fault_4;  /* I/O control fault 4 persistence counter */
    uint8_t io_fault_5;  /* I/O control fault 5 persistence counter */
    uint8_t io_fault_6;  /* I/O control fault 6 persistence counter */
};

struct fault_status_registers_t {
    uint16_t sensor_fault_status;  /* Sensor fault status register */
    uint16_t fault_status_2;  /* Fault status flags register 2 */
    uint16_t engine_fault_status;  /* Engine fault status register */
    uint16_t reserved_06;  /* Reserved/gap */
    uint16_t io_fault_status_1;  /* IO fault status register 1 */
    uint16_t io_fault_status_2;  /* IO fault status register 2 */
    uint16_t io_fault_status_3;  /* IO fault status register 3 */
    uint16_t io_fault_status_4;  /* IO fault status register 4 */
};

struct fault_latch_registers_t {
    uint16_t sensor_fault_latch;  /* Sensor fault latch register */
    uint16_t fault_status_8_previous;  /* Previous state for edge detection */
    uint16_t engine_fault_latch;  /* Engine fault latch register */
    uint16_t reserved_06;  /* Reserved/gap */
    uint16_t io_fault_latch_1;  /* IO fault latch register 1 */
    uint16_t io_fault_latch_2;  /* IO fault latch register 2 */
    uint16_t io_fault_latch_3;  /* IO fault latch register 3 */
    uint16_t io_fault_latch_4;  /* IO fault latch register 4 */
};

struct engine_operating_mode_t {
    uint16_t state;  /* Engine operating mode state 1-8 */
    uint16_t shutdown_complete_flag;  /* Engine shutdown complete flag */
};

struct rpm_fuel_protection_t {
    uint16_t fuel_limit_shutdown;  /* Fuel limit during shutdown */
    uint16_t high_rpm_fuel_limit;  /* High RPM fuel control limit */
    uint16_t low_rpm_fuel_protection_limit;  /* Low RPM fuel protection limit */
    uint16_t rpm_rate_limiter_output;  /* RPM rate limiter output */
    uint16_t rpm_rate_limited_value;  /* RPM rate limited value */
    uint16_t rpm_rate_secondary_calc;  /* Secondary RPM rate calculation */
    uint16_t rpm_state_accumulator;  /* RPM state accumulator */
    uint16_t high_rpm_fuel_accumulator;  /* High RPM fuel accumulator */
    uint16_t low_rpm_fuel_accumulator;  /* Low RPM fuel accumulator */
    uint16_t fuel_demand_before_limiting;  /* Fuel demand saved before limiting */
    uint16_t low_rpm_threshold_exceeded_flag;  /* Low RPM threshold exceeded flag */
    uint16_t rpm_threshold_exceeded_flag;  /* RPM threshold exceeded flag */
    uint16_t high_rpm_threshold_exceeded_flag;  /* High RPM threshold exceeded flag */
    uint16_t fuel_protection_timer_enable;  /* Timer enable for protection state machines */
    uint16_t fuel_system_protection_enabled;  /* Master fuel protection system enable (1=active) */
};

struct timing_mode_control_t {
    uint16_t blend_factor;  /* Fuel timing mode blend factor Q14 */
    uint16_t protection_blend_ramp;  /* Timing protection blend ramp 0-16384 */
    uint16_t source_selector;  /* Timing mode source selector 0-4 */
    uint16_t transition_result;  /* Timing mode transition result */
    uint16_t fuel_blend_result;  /* Timing fuel blend result */
    uint16_t oil_pressure_result;  /* Timing oil pressure condition result */
    uint16_t mode_11_result;  /* Timing mode 11 countdown result */
    uint16_t protection_counter_1;  /* Timing protection counter 1 */
    uint16_t protection_counter_2;  /* Timing protection counter 2 */
    uint16_t blend_state;  /* Timing blend state */
    uint16_t blend_accumulator;  /* Timing blend accumulator */
    uint16_t fuel_source_mode_11_state;  /* Fuel source mode 11 state */
    uint16_t fuel_source_mode_11_timer;  /* Fuel source mode 11 timer */
    uint16_t fuel_mode_transition_state;  /* Fuel mode transition state */
    uint16_t fuel_mode_transition_timer;  /* Fuel mode transition timer */
};

struct j1939_powertrain_messages_received_t {
    uint16_t etc1_output_shaft_speed_previous;  /* output_shaft_speed_current before the latest valid ETC1 output shaft speed (was speed_previous) */
    uint8_t etc1_status_byte_1;  /* ETC1 byte 1: bits 1-2 driveline engaged (SPN 560), 3-4 torque converter lockup engaged (SPN 573), 5-6 shift in process (SPN 574) (was byte1_status) */
    uint16_t etc1_spn191_output_shaft_speed;  /* ETC1 bytes 2-3: the transmission output shaft speed (SPN 191, 0.125 rpm) (was spn191_output_shaft_speed) */
    uint8_t etc1_spn522_percent_clutch_slip;  /* ETC1 byte 4: the percent clutch slip (SPN 522); no access found in the decompile (was spn522_clutch_slip) */
    uint8_t etc1_status_byte_5;  /* ETC1 byte 5: bits 1-2 engine momentary overspeed enable (SPN 606), 3-4 progressive shift disable (SPN 607) (was byte5_control) */
    uint8_t reserved_07[3];  /* Gap/reserved bytes */
    uint16_t etc2_actual_gear_ratio_previous;  /* etc2_actual_gear_ratio before the latest valid ETC2 (sth @ 0x22cf0; cm848_initEtc2Handler zeroes it, sth @ 0x22d2c); no reader in the decompile (was auxiliary_state, a byte: the word store rendered as the _10_2_ piece) */
    uint8_t reserved_0c;  /* no access found */
    uint16_t etc2_spn526_actual_gear_ratio;  /* ETC2 bytes 2-3 (SPN 526 transmission actual gear ratio, 0.001 per bit) as received: cm848_j1939ProcessPgn61445Etc2 stores byte 3 at +0xd and byte 2 at +0xe and reads the word (lhz @ 0x22cc4); below 0xfb00 it becomes etc2_actual_gear_ratio (was bytes 2-3 of reserved_0b) */
    uint8_t reserved_0f[5];  /* no access found */
    uint8_t tsc1_control_byte;  /* TSC1 byte 1: bits 1-2 override control mode (SPN 695), 3-4 requested speed control conditions (SPN 696), 5-6 override control mode priority (SPN 897) (was control_word) */
    uint16_t tsc1_requested_speed;  /* TSC1 bytes 2-3: the requested speed / speed limit (SPN 898, 0.125 rpm) (was requested_speed) */
    uint8_t tsc1_requested_torque;  /* TSC1 byte 4: the requested torque / torque limit (SPN 518, percent + 125) (was requested_torque) */
    uint8_t reserved_18[4];  /* Gap/reserved bytes */
    uint8_t tsc1_accepted_priority;  /* the priority bits (byte 1 & 0x30) of the accepted request; while a J1939 request is active another sender needs a higher priority (a lower value); at the same priority only an active mode 3 request can be taken over (was priority_byte) */
    uint16_t tsc1_accepted_requested_speed;  /* the requested speed of the accepted speed control / limit request (modes 1 and 3); a mode 3 takeover at the same priority needs a lower torque or speed (was speed_stored, described as an SPN 191 copy) */
    uint8_t tsc1_accepted_requested_torque;  /* the requested torque of the accepted torque control / limit request (modes 2 and 3) (was torque_stored, described as an SPN 522 copy) */
};

struct param_id_entry_t {
    uint16_t param_id;  /* Parameter ID (0x0000-0x12A9 for CM848) */
    uint32_t address;  /* Resolved memory address (EEPROM/ROM/MPC555 regs) */
};

struct ef00_dispatch_entry_t {
    uint8_t service_id;  /* EF00 service ID (see EF00_SERVICE_ID enum) */
    uint8_t reserved;  /* Padding byte */
    uint32_t handler_ptr;  /* Function pointer to service handler */
};

struct diag_dispatch_entry_t {
    uint8_t service_id;  /* Diagnostic service ID (0x43=paramRead 0x4A=memRead 0x4C=memReadExt) */
    uint32_t handler_ptr;  /* Function pointer to service handler */
};

struct executive_frame_timing_t {
    uint32_t total_ticks;  /* Sum of the frame's pass times in timebase ticks (was total_ticks; PR #53 round 25) */
    uint16_t frame_count;  /* Passes of the frame counted (was call_count; PR #53 round 25) */
    uint16_t minimum_ticks;  /* Shortest pass time (0xffff after a clear) (was min_time; PR #53 round 25) */
    uint16_t maximum_ticks;  /* Longest pass time (was max_time; PR #53 round 25) */
    uint16_t overflow_count;  /* Passes longer than executive_frame_overflow_threshold_ticks (each also counts executive_timing_overflow_count_cal) (was overrun_count; PR #53 round 25) */
};

struct j1939_dm13_requester_slot_t {
    uint16_t broadcast_enable_flags;  /* Cummins DM13BRDn - broadcast enable flags requested by this source (0xFFFF = nothing suspended): DM13 stop (00) clears J1587 bit 0 / J1922 bit 1 / J1939 network 1 bits 2 3 7 and start (01) sets them; back to 0xFFFF when the stop broadcast timer expires (was derivative_term) */
    uint16_t stop_broadcast_source_address;  /* Cummins STPBRDSn - J1939 source address of the device whose DM13 asked this ECM to stop broadcasting; matched against the source address of each received DM13 (was channel_identifier) */
    uint16_t stop_broadcast_timer;  /* Cummins DM13BDTn (0.1 s): reloaded with j1939_dm13_stop_broadcast_time_limit_cal (60 = 6 s) by this source's stop or hold message (byte 4 hold signal 0 or 1) and counted down; 0 = free slot and its flags return to 0xFFFF (was gain_schedule) */
};

struct combustion_chi_maximum_fuel_points_t {
    uint16_t chi_maximum_fuel_at_point_1;  /* Scaled protection threshold from table lookup */
    uint16_t chi_maximum_fuel_at_point_2;  /* Recovery/hysteresis exit threshold */
    uint16_t chi_maximum_fuel_at_point_3;  /* Protection hysteresis band value */
    uint16_t chi_maximum_fuel_at_point_4;  /* Alternate scaled threshold (same input different context) */
    uint16_t chi_maximum_fuel_at_point_5;  /* Base protection threshold before correction */
};

struct fault_entry_t {
    uint32_t key_on_hour_meter;  /* Fuel timing advance value at capture time */
    uint8_t fault_code;  /* Fault code ID (0xAA = empty/available slot) */
    uint16_t vehicle_speed;  /* Vehicle speed when the fault was captured (copy of vehicle_speed - 1/256 mph) (was temperature_trim) */
    uint16_t filtered_rpm;  /* Target engine RPM at fault time */
    uint16_t system_switch_status;  /* Sensor scale factor 1 */
    uint16_t engine_load_at_current_speed;  /* engine_load_at_current_speed_percent at capture (1/256 percent) - OBD-II mode 2 PID 4 (was fault_status) */
    uint16_t accelerator_pedal_position;  /* accelerator_pedal_position_in_use at capture - OBD-II mode 2 PID 0x11 (was protection_high) */
    uint16_t intake_manifold_pressure;  /* intake_manifold_pressure_in_use at capture (was protection_low) */
    uint16_t coolant_temperature;  /* coolant_temperature_in_use at capture (1/64 deg F) (was timing_param_1) */
    uint16_t intake_manifold_temperature;  /* intake_manifold_temperature_in_use at capture (1/64 deg F) (was timing_param_2) */
    uint16_t oil_pressure;  /* oil_pressure_sensor_filtered at capture (was timing_param_3) */
    uint16_t system_switch_status_2;  /* Sensor scale factor 2 */
    uint32_t reserved;  /* Reserved gap (not written by set/capture functions) */
    uint8_t final_fueling_state;  /* Low byte of final_fueling_state when the freeze frame was stored (hpcr_setFaultActiveStatus) (was governor_mode_code - Pressure fuel adjustment byte) */
    uint16_t battery_voltage;  /* Battery voltage reading at fault time */
    uint16_t final_fueling;  /* final_fueling (e2m Final_Fueling) when the fault was recorded (was fuel_demand_computed: Processed load/throttle value) */
    uint16_t main_injection_timing;  /* Torque limit factor at fault time */
    uint16_t fuel_metering_feedback;  /* Diagnostic data word 1 */
    uint8_t fuel_metering_feedback_fault;  /* Diagnostic data byte 3 */
    uint8_t fuel_pressure_diagnostic;  /* Diagnostic data byte 4 */
    uint16_t fuel_pressure_sensor_voltage;  /* Diagnostic data word 2 */
    uint16_t fuel_pressure_setpoint;  /* Diagnostic data word 3 */
    uint16_t fuel_temperature;  /* fuel_temperature_sensor_filtered at capture (1/64 deg F) - not coolant (was coolant_temp_raw) */
    uint16_t status_flags;  /* Fault entry status/severity flags (bit 0 = newly active) */
};

struct usiu_pit_t {
    uint16_t PISCR;  /* PIT Status and Control Register (firmware writes 0x101 to enable PIE+PS) */
    uint16_t _pad_piscr;  /* Padding after PISCR (16-bit register in 32-bit slot) */
    uint16_t PITC;  /* PIT Count Register (firmware writes 4999 for 5000-count period) */
    uint16_t _pad_pitc;  /* Padding after PITC */
    uint16_t PITR;  /* PIT Register (read-only current count value) */
};

struct usiu_clock_t {
    uint32_t SCCR;  /* System Clock Control Register (firmware writes 0x2010000/0xe010000) */
    uint32_t PLPRCR;  /* PLL Low Power and Reset Control Register (firmware writes 0x1304001) */
    uint16_t RSR;  /* Reset Status Register (read at startup then cleared with 0xFFFF) */
    uint16_t _pad_rsr;  /* Padding after RSR (16-bit register in 32-bit slot) */
    uint16_t COLIR;  /* Change of Lock Interrupt Register */
    uint16_t _pad_colir;  /* Padding after COLIR */
    uint16_t VSRMCR;  /* VDD Sense Mode Control Register (firmware writes 0x400) */
};

struct usiu_memc_t {
    uint32_t BR0;  /* Base Register 0 (Flash2 chip select) */
    uint32_t OR0;  /* Option Register 0 */
    uint32_t BR1;  /* Base Register 1 (RAM chip select) */
    uint32_t OR1;  /* Option Register 1 */
    uint32_t BR2;  /* Base Register 2 */
    uint32_t OR2;  /* Option Register 2 */
    uint32_t BR3;  /* Base Register 3 */
    uint32_t OR3;  /* Option Register 3 */
};

struct siu_gpio_data_register_t {
    uint8_t byte_0;  /* Bits 31-24: lines 24-31 in SIU_SGPIODT1 / lines 56-63 in SIU_SGPIODT2 */
    uint8_t byte_1;  /* Bits 23-16: lines 32-39 in SIU_SGPIODT1 / lines 64-71 in SIU_SGPIODT2 */
    uint8_t byte_2;  /* Bits 15-8: lines 40-47 in SIU_SGPIODT1 / lines 72-79 in SIU_SGPIODT2 */
    uint8_t byte_3;  /* Bits 7-0: lines 48-55 in SIU_SGPIODT1 / lines 80-87 in SIU_SGPIODT2 */
};

struct discrete_line_image_t {
    uint8_t lines_0_to_7;  /* Lines 0-7 (bit = line - 0) */
    uint8_t lines_8_to_15;  /* Lines 8-15 (bit = line - 8) */
    uint8_t lines_16_to_23;  /* Lines 16-23 (bit = line - 16) */
    uint8_t lines_24_to_31;  /* Lines 24-31 (bit = line - 24) */
    uint8_t lines_32_to_39;  /* Lines 32-39 (bit = line - 32) */
    uint8_t lines_40_to_47;  /* Lines 40-47 (bit = line - 40) */
    uint8_t lines_48_to_55;  /* Lines 48-55 (bit = line - 48) */
    uint8_t lines_56_to_63;  /* Lines 56-63 (bit = line - 56) */
    uint8_t lines_64_to_71;  /* Lines 64-71 (bit = line - 64) */
    uint8_t lines_72_to_79;  /* Lines 72-79 (bit = line - 72) */
    uint8_t lines_80_to_87;  /* Lines 80-87 (bit = line - 80) */
    uint8_t lines_88_to_95;  /* Lines 88-95 (bit = line - 88) */
    uint8_t lines_96_to_103;  /* Lines 96-103 (bit = line - 96) */
    uint8_t lines_104_to_111;  /* Lines 104-111 (bit = line - 104) */
    uint8_t lines_112_to_119;  /* Lines 112-119 (bit = line - 112) */
    uint8_t lines_120_to_127;  /* Lines 120-127 (bit = line - 120) */
    uint8_t lines_128_to_135;  /* Lines 128-135 (bit = line - 128) */
    uint8_t lines_136_to_143;  /* Lines 136-143 (bit = line - 136) */
    uint8_t lines_144_to_151;  /* Lines 144-151 (bit = line - 144) */
    uint8_t lines_152_to_159;  /* Lines 152-159 (bit = line - 152) */
};

struct mios_port_data_register_t {
    uint8_t byte_0;  /* Bits 15-8 (the byte at the lower address): input lines 16-23 */
    uint8_t byte_1;  /* Bits 7-0: input lines 8-15 */
};

struct j1939_powertrain_control_state_t {
    TSC1_OVERRIDE_MODE tsc1_override_control_mode;  /* e2m 10E8 +4 Jcomm_Engine_Control_Mode (UNITLESS): 'JCOMM CONTROL MODE 0 = DISABLE 1 = SPEED 2 = TORQUE 3 = LIMIT'. the accepted engine TSC1 request's override control mode (J1939 SPN 695: 0 override disabled / 1 speed control / 2 torque control / 3 speed and torque limit control); processEngineTsc1Request sets it from byte 1 bits 1-2 and cm848_runTsc1LostManagement sets 3 / 0 (was governor_mode) */
    uint16_t high_idle_override_active_flag;  /* e2m 10E8 +6 Jcomm_High_Idle_Override (UNITLESS): 'Jcomm High Idle Override 0 = FALSE; no override 1 = TRUE; override'. 1 = the high idle override is granted: ETC1 byte 5 bits 1-2 (SPN 606 engine momentary overspeed enable) = 01 while the engine TSC1 speed control (mode 1) comes from source index 1; selectEngineSpeedLimit then applies the e2m Jcomm_High_Idle_Override_Speed (0x5c39a) (was torque_limit_mode_select) */
    uint16_t etc1_out_of_gear_flag;  /* e2m 10E8 +8 Jcomm_Out_of_Gear (UNITLESS): 'Jcomm Out of Gear 0 = FALSE; in gear 1 = TRUE; out of gear'. e2m Jcomm_Out_of_Gear: 1 when ETC1 byte 1 reports the driveline disengaged (SPN 560 = 00) and no shift in process (SPN 574 = 00); cleared when etc1_out_of_gear_timer runs out (was etc1_disable_control) */
    uint16_t etc1_spn607_progressive_shift_disable;  /* e2m 10E8 +A Jcomm_Progressive_Shift_Disable (UNITLESS): 'Jcomm Progressive Shift Disable 1=TRUE;disable prog shift 0=FALSE;allow prog s'. 1=ETC1 torque limit active (was etc1_limit_state._0_2_) */
    uint16_t tsc1_speed_limit;  /* e2m 10E8 +C Jcomm_Engine_Speed_Limit_RPM (RPM): 'Jcomm Engine Speed Limit RPM maximum allowed engine speed as per link user'. the TSC1 speed limit of mode 3 (the requested speed); cm848_runTsc1LostManagement ramps it up by tsc1_lost_speed_ramp_rate or resets it to the engine speed; read by selectEngineSpeedLimit (was etc1_torque_limit_value) */
    int16_t tsc1_requested_percent_torque_times_256;  /* e2m 10E8 +E Jcomm_Engine_Torque_Command (%): 'Torque command to engine as received over datalink'. mode 2 (torque control): the requested torque in percent x 256 (byte 4 x 256 - 32000 = (raw - 125) x 256) (was etc1_speed_setpoint) */
    uint16_t tsc1_requested_speed_capped;  /* e2m 10E8 +10 Jcomm_Reference_RPM (RPM): 'Jcomm Reference RPM engine speed to be output by engine as per link user'. mode 1 (speed control): the requested speed capped at 24000 (3000 rpm); read by cm848_selectTsc1SpeedControlMode (was etc1_capped_speed_target) */
    uint16_t tsc1_speed_control_flag;  /* e2m 10E8 +12 Jcomm_Speed_Control_Status (UNITLESS): 'Jcomm Speed Control Status 1 = speed control mode 0 = not in speed control mo'. 1 while the accepted request is speed control (mode 1), else 0; no reader in the decompile (was etc1_control_flags) */
    uint16_t tsc1_torque_limit_fueling;  /* e2m 10E8 +14 Jcomm_Torque_Derate_Fueling (MM3S): 'Jcomm Torque Derate Fueling maximum allowed fuel as per link user'. mode 3: the requested torque limit as fueling ((j1939_reference_engine_fueling - zero_torque_fueling) x percent / 100 + the zero fueling, at least 0); cm848_runTsc1LostManagement ramps it through tsc1_torque_limit_ramp_integrator; read by cm848_applyTsc1TorqueLimit and cm848_arbitrateGovernedFueling (was etc1_mode3_torque_limit) */
    uint16_t tsc1_torque_control_fueling;  /* e2m 10E8 +16 Jcomm_Fueling_Command (MM3S): 'Jcomm Fueling Command Fuel commanded to engine as dictated by link user'. mode 2 (torque control): the requested torque as fueling (the conversion of tsc1_torque_limit_fueling); read by cm848_setEngineOperatingMode1 (was etc1_torque_limit_calc) */
    uint16_t tsc1_requested_speed_control_condition;  /* e2m 10E8 +18 Jcomm_Speed_Governor_Mode (UNITLESS): 'Jcomm Speed Governor Mode indicator of which speed mode characteristic ASG is i'. TSC1 byte 1 bits 3-4 (J1939 SPN 696 Engine Requested Speed Control Conditions) of a speed control request: the index into j1939_tsc1_speed_control_condition_gain_sets (was etc1_speed_control_mode) */
    CONTROL_NETWORK tsc1_controlling_data_link;  /* e2m 10E8 +1A Jcomm_Engine_Control_Network_Type (UNITLESS): 'network type in control of engine 0 = J1922; 1 = J1939'. the data link of the accepted control request: 1 = J1939 (processEngineTsc1Request); a timeout counts as a J1939 link fault when it is 1, else as a J1708 (J1922) one. The first argument of the ignored request and source configuration lookups (was etc1_active_state) */
    CONTROL_NETWORK out_of_gear_network_type;  /* e2m 10E8 +1C Jcomm_Out_of_Gear_Network_Type (UNITLESS): 'Indicator of which network set Jcomm_Out_of_Gear: 0 = 1922; 1 = 1939'. the network that set the out of gear flag (e2m: 0 = J1922, 1 = J1939); the ETC1 handler sets 1 with etc1_out_of_gear_flag (was etc1_out_of_gear_latch, before that etc1_speed_disable_latch) */
    uint16_t etc1_out_of_gear_data_valid_flag;  /* e2m 10E8 +1E Jcomm_OOG_Valid_Flag (UNITLESS): 'Indicates valid jcomm oog; 0=FALSE; 1=TRUE'. 1 while ETC1 gives a valid driveline / shift status with a J1939 vehicle speed source (vehicle_speed_sensor_type_cal 4 / 5); cleared when etc1_out_of_gear_data_timer or the ETC1 message timeout runs out; read by cm848_updateDrivetrainRatio and cm848_applyJ1939OutOfGearToDrivetrainRatio (was etc1_control_active) */
    uint16_t etc1_spn573_torque_converter_lockup_disengaged_flag;  /* e2m 10E8 +20 Jcomm_Torque_Converter_Lockup_Disengaged (HEX): 'Indicates when Torque Converter is locked up 0=engaged; 1=disengaged'. ETC1 byte 1 bits 3-4 (SPN 573): 1 when the torque converter lockup is disengaged (00), 0 when engaged (01); set to 0 when etc1_torque_converter_lockup_timer runs out; read by cm848_updateEngineRetarderAllowedState (was etc1_spn573_tc_lockup_disengage) */
    uint16_t etc1_output_shaft_speed_fault_hold_off_flag;  /* e2m 10E8 +22 J1939_Powerup_Faults_Inhibit (UNITLESS): 'flag indicating VSS lost fault is prohibited.'. 1 holds off the J1939 output shaft speed fault: while switch input bit 0 is 0, or while the engine has run for fewer passes than j1939_pgn61442_output_shaft_speed_fault_run_state_delay (e2m J1939_Powerup_Runtime_Fault_Delay) (was etc1_handler_initialized) */
    uint16_t j1939_blocked_message_bits;  /* e2m 10E8 +24 J1939_Block_Message (HEX): 'Bit 0 TSC1 destination engine; Bit 1 TSC1 Destination retarder; Bit 2 ETC1'. The J1939 messages blocked after a time limit: bit 0 = TSC1 to the engine (the sender went into the ignored request list), bit 1 = TSC1 to the engine retarder, bit 2 = the ETC1 high idle override (in recovery: e2m Jcomm_Recovery_Time). processEngineTsc1Request clears bit 0 on override disabled; ETC1 SPN 606 = 00 and the high idle timeout clear bit 2. A word, not a bitfield: the code clears and sets the bits with masks, which Ghidra renders as a raw piece on a bitfield (was time_limited_node_status_bits, before that speed_control_target) */
    uint8_t etc1_spn574_shift_in_process;  /* e2m 10E8 +26 Jcomm_Shift_In_Process (UNITLESS): 'J1939 ETC1 Shift in process status bits state. 0=F;1=T'. 1=coast/brake mode from ETC1 byte0 bits 0x30==0x10 */
    TRANSMISSION_SELECTED_GEAR etc2_transmission_selected_gear;  /* e2m 10E8 +27 J1939_Selected_Gear (UNITLESS): 'J1939 ETC2 Selected Gear'. J1939 ETC2 (PGN 61445) byte 1 = SPN 524 transmission selected gear - stored by the ETC2 handler at 0x22c5c when DLC is 8; 0xFF at init or when etc2_selected_gear_timeout (ETC2 timeout) expires; 0xFB or 0x7D sets transmission_park_or_neutral_flag; RAM dump 0xFF (was etc1_address_filter) */
    int16_t engine_net_output_torque;  /* e2m 10E8 +28 Jcomm_Engine_Output_Net_Torque (FT*LB): 'Jcomm Net ouput torque = Actual - friction'. the engine's net output torque in ft lb (e2m: actual - friction, signed); read by cm848_j1939HandlePgn65504ProprietaryB, cm848_checkAirHandlingSystemProtectionHighLoad and governor_speedRatio_etcFuelCorrection_calc (was proprietary_offset_value) */
    uint16_t tsc1_request_timed_out_flag;  /* e2m 10E8 +2A TSC_Lost_Flag (UNITLESS): 'Flag indicated J1939 TSC1 message has timed out used as signal for PTP mode.'. 1 when tsc1_request_timeout_count is below 2 (the accepted engine TSC1 request timed out); cm848_runTsc1LostManagement then ramps the limits (was etc1_speed_error_timeout_flag) */
    uint16_t tsc1_request_time_limit_timer;  /* the time limit of a speed / torque control request: the sender's tsc1_source_configuration_t speed_control_time_limit / torque_control_time_limit + 1 when the request starts or changes; at 1 the sender goes into the ignored request list (bit 0 of j1939_blocked_message_bits) and cm848_runTsc1LostManagement runs (was etc1_activation_confirm_timer) */
    uint16_t tsc1_request_timeout_count;  /* the accepted engine TSC1 request's message timeout: the sender's request timeout for the mode (+4 / +8 / +0xc of its configuration entry) + 1 on each accepted message, counted down each pass (was etc1_speed_error_timeout) */
    uint16_t retarder_tsc1_request_time_limit_timer;  /* the engine retarder TSC1 torque control (mode 2) time limit: retarder_torque_control_time_limit + 1 of the retarder sender's entry when its request starts or changes; at 1 the sender goes into the retarder ignored request list (bit 1 of j1939_blocked_message_bits) (was etc1_error_fault_timer) */
    uint16_t retarder_tsc1_request_timeout_count;  /* the engine retarder TSC1 request's message timeout: the entry's retarder request timeout (+0xe mode 2 / +0x12 mode 3) + 1, loaded by cm848_processEngineRetarderTsc1Request; at 1 the retarder request ends (cm848_resetEngineRetarderTsc1Request) (was etc1_multiframe_timeout) */
    uint16_t high_idle_override_timeout_timer;  /* the high idle override's message timeout: j1939_pgn61442_engine_overspeed_enable_timeout + 1 (e2m Jcomm_Eng_Overspeed_TO) on each ETC1 with SPN 606 = 01, or j1939_time_limited_node_recovery_time + 1 (Jcomm_Recovery_Time) while high_idle_override_recovery_flag is set; at 1 the override and the recovery end (was etc1_torque_mode_timer) */
    uint16_t high_idle_override_time_limit_timer;  /* the high idle override's time limit: j1939_pgn61442_engine_overspeed_enable_time_limit + 1 (e2m Jcomm_Eng_Overspeed_TL), loaded once per request; at 1 the override ends and high_idle_override_recovery_flag is set (was etc1_torque_active_timer) */
    uint16_t etc1_out_of_gear_timer;  /* j1939_pgn61442_driveline_disengaged_timeout + 1 (e2m Jcomm_Driveline_Disengaged_TO: the time out for Jcomm_Out_of_Gear) while ETC1 reports out of gear; at 1 etc1_out_of_gear_flag is cleared (was etc1_speed_override_timer) */
    uint16_t etc1_progressive_shift_disable_timer;  /* j1939_pgn61442_progressive_shift_disable_timeout + 1 (e2m Jcomm_Prog_Shift_TO) while ETC1 byte 5 bits 3-4 (SPN 607) = 01; at 1 etc1_spn607_progressive_shift_disable is cleared (was etc1_torque_limit_timer) */
    uint16_t retarder_tsc1_zero_torque_request_timer;  /* armed with the retarder request timeout when the stage-quantized torque request is 0 (torque control) or, in limit control, when the previous torque limit (read before this message updates it) is 0; cleared otherwise; at 1 it counts as a link timeout, and a drop to override disabled while it runs counts as a request change (cm848_runJ1939PowertrainControlTimeouts). Why a zero torque request is timed is not settled (was retarder_tsc1_mode_transition_timer, before that etc1_mode_transition_timer) */
    uint16_t retarder_tsc1_speed_control_flag;  /* inferred: the retarder twin of tsc1_speed_control_flag (no e2m record covers 0x40ae20-0x40ae4c). Always written 0, since cm848_processEngineRetarderTsc1Request rejects speed control (SPN 695 = 1); no reader (was retarder_tsc1_speed_mode_flag, before that etc1_speed_mode_flag) */
    uint16_t etc1_out_of_gear_data_timer;  /* j1939_pgn61442_out_of_gear_timeout + 1 (e2m Jcomm_OOG_Timeout: the time of no data link out of gear before it is calculated) on each valid ETC1 status; at 1 etc1_out_of_gear_data_valid_flag is cleared (was etc1_mode_timeout) */
    uint16_t etc1_output_shaft_speed_timer;  /* j1939_pgn61442_output_shaft_speed_timeout + 1 (e2m J1939_TSS_Timeout) on each valid ETC1 output shaft speed; at 0 (outside the hold-off) the speed is zeroed and the vehicle speed fault (bit 0x2000 of fault word 16-31) is set (was etc1_speed_cmd_timeout) */
    uint16_t etc1_torque_converter_lockup_timer;  /* j1939_pgn61442_torque_converter_lockup_timeout (e2m J1939_TQ_Cnv_Lockup_TO) on each valid SPN 573; at 1 etc1_spn573_torque_converter_lockup_disengaged_flag is set to 0 (was etc1_override_timeout) */
    uint16_t etc1_output_shaft_speed_run_state_count;  /* counts the passes the engine runs (RUNNING / ENGINE_BRAKE / OVERSPEED) with the J1939 speed source with gear ratio, for etc1_output_shaft_speed_fault_hold_off_flag (was governor_mode_transition_counter) */
    uint8_t _pad;  /* Alignment padding */
    uint8_t tsc1_controlling_source_address;  /* the source address of the accepted engine TSC1 request (the sender in control). Not SPN 1482, which is ETC1's source address of the device controlling the transmission (was etc1_spn1482_source_address) */
    tsc1_source_configuration_t* tsc1_matched_source_configuration_ptr;  /* the tsc1_source_configuration_table entry cm848_findTsc1SourceConfiguration matched for the last sender (was etc1_config_entry_ptr) */
    tsc1_source_configuration_t* tsc1_source_configuration_ptr;  /* the configuration entry of the accepted engine TSC1 sender (its request timeouts and time limits); while a J1922 request is active a J1939 sender takes over only with an entry at the same or an earlier position (was etc1_active_config_ptr) */
    tsc1_source_configuration_t* retarder_tsc1_source_configuration_ptr;  /* the configuration entry of the accepted engine retarder TSC1 sender (+0xe / +0x10 / +0x12 read) (was etc1_secondary_config_ptr) */
    uint16_t high_idle_override_recovery_flag;  /* 1 after the high idle override hit its time limit: the transmission must stop asking for it for j1939_time_limited_node_recovery_time (e2m Jcomm_Recovery_Time) before it is granted again; cleared by ETC1 SPN 606 = 00 or when high_idle_override_timeout_timer runs out (was etc1_torque_limit_active) */
    uint16_t etc1_message_timeout;  /* Countdown: fires if no ETC1 message received within window */
};

struct tsc1_source_configuration_t {
    CONTROL_NETWORK data_link;  /* the data link the entry is for (1 = J1939; the 0xff source address wildcard counts only on 1) (was match_key) */
    uint16_t source_address_filter;  /* Low byte = the J1939 source address (0xff would match any J1939 sender; the ROM image lists 0x03 / 0x0B / 0x21 / 0x4A / 0x4F and 0xFE = the null address in the five unused entries); the high byte is 0 in every entry (a priority filter role is not verified) */
    uint16_t speed_control_request_timeout;  /* the request timeout of a speed control request (mode 1): tsc1_request_timeout_count reload (was speed_error_timeout_mode1) */
    uint16_t speed_control_time_limit;  /* the time limit of a speed control request: tsc1_request_time_limit_timer reload (was activation_confirm_timeout_mode1) */
    uint16_t torque_control_request_timeout;  /* the request timeout of a torque control request (mode 2) (was speed_error_timeout_mode2) */
    uint16_t torque_control_time_limit;  /* the time limit of a torque control request (was activation_confirm_timeout_mode2) */
    uint16_t speed_torque_limit_control_request_timeout;  /* the request timeout of a speed / torque limit control request (mode 3) (was speed_error_timeout_mode3) */
    uint16_t retarder_torque_control_request_timeout;  /* the engine retarder TSC1 torque control (mode 2) request timeout: retarder_tsc1_request_timeout_count reload (was multiframe_timeout_mode2) */
    uint16_t retarder_torque_control_time_limit;  /* the engine retarder TSC1 torque control time limit: retarder_tsc1_request_time_limit_timer reload (was error_fault_timeout) */
    uint16_t retarder_speed_torque_limit_control_request_timeout;  /* the engine retarder TSC1 speed / torque limit control (mode 3) request timeout (was multiframe_timeout_mode3) */
};

struct tpua_module_regs_t {
    uint16_t TPUMCR;  /* Module Configuration Register (0x8000=STOP 0x4460=run w/prescaler) */
    uint16_t _pad1;  /* Reserved (TPU3 offset +0x02) */
    uint16_t _pad2;  /* Reserved (TPU3 offset +0x04) */
    uint16_t _pad3;  /* Reserved (TPU3 offset +0x06) */
    uint16_t TICR;  /* Timer Interrupt Configuration Register (written 0x100 at init) */
    uint16_t CIER;  /* Channel Interrupt Enable Register */
    uint16_t CFSR0;  /* Channel Function Select Register 0 (ch 0-3) */
    uint16_t CFSR1;  /* Channel Function Select Register 1 (ch 4-7) */
    uint16_t CFSR2;  /* Channel Function Select Register 2 (ch 8-11) */
    uint16_t CFSR3;  /* Channel Function Select Register 3 (ch 12-15) */
    uint16_t HSQR0;  /* Host Sequence Register 0 (ch 0-7) */
    uint16_t HSQR1;  /* Host Sequence Register 1 (ch 8-15) */
    uint16_t HSRR0;  /* Host Service Request Register 0 (ch 0-7) */
    uint16_t HSRR1;  /* Host Service Request Register 1 (ch 8-15) */
    uint16_t CPR0;  /* Channel Priority Register 0 (ch 0-7) */
    uint16_t CPR1;  /* Channel Priority Register 1 (ch 8-15) */
    uint16_t CISR;  /* Channel Interrupt Status Register */
    uint16_t _pad4;  /* Reserved (TPU3 offset +0x22) */
    uint16_t _pad5;  /* Reserved (TPU3 offset +0x24) */
    uint16_t _pad6;  /* Reserved (TPU3 offset +0x26) */
    uint16_t R028;  /* Unknown register at +0x28 (written 0x80/0x20 at init) */
    uint16_t R02A;  /* Unknown register at +0x2A (written 0x00 at init) */
};

struct tpub_module_regs_t {
    uint16_t TPUMCR;  /* Module Configuration Register (0x8000=STOP 0x4430=run w/prescaler) */
    uint16_t _pad1;  /* Reserved (TPU3 offset +0x02) */
    uint16_t _pad2;  /* Reserved (TPU3 offset +0x04) */
    uint16_t _pad3;  /* Reserved (TPU3 offset +0x06) */
    uint16_t TICR;  /* Timer Interrupt Configuration Register (written 0x200 at init) */
    uint16_t CIER;  /* Channel Interrupt Enable Register */
    uint16_t CFSR0;  /* Channel Function Select Register 0 (ch 0-3) */
    uint16_t CFSR1;  /* Channel Function Select Register 1 (ch 4-7) */
    uint16_t CFSR2;  /* Channel Function Select Register 2 (ch 8-11) */
    uint16_t CFSR3;  /* Channel Function Select Register 3 (ch 12-15) */
    uint16_t HSQR0;  /* Host Sequence Register 0 (ch 0-7) */
    uint16_t HSQR1;  /* Host Sequence Register 1 (ch 8-15) */
    uint16_t HSRR0;  /* Host Service Request Register 0 (ch 0-7) */
    uint16_t HSRR1;  /* Host Service Request Register 1 (ch 8-15) */
    uint16_t CPR0;  /* Channel Priority Register 0 (ch 0-7) */
    uint16_t CPR1;  /* Channel Priority Register 1 (ch 8-15) */
    uint16_t CISR;  /* Channel Interrupt Status Register */
    uint16_t _pad4;  /* Reserved (TPU3 offset +0x22) */
    uint16_t _pad5;  /* Reserved (TPU3 offset +0x24) */
    uint16_t _pad6;  /* Reserved (TPU3 offset +0x26) */
    uint16_t R028;  /* Unknown register at +0x28 (written 0x80/0x20 at init) */
    uint16_t R02A;  /* Unknown register at +0x2A (written 0x1E at init) */
};

struct mios_mpwmsm_t {
    uint16_t PERR;  /* Period Register (sets PWM frequency) */
    uint16_t PULR;  /* Pulse Width Register (sets duty cycle) */
    uint16_t CNTR;  /* Counter Register (current count value) */
    uint16_t SCR;  /* Status/Control Register (0x9=enable 0x4ff=period-mode) */
};

struct mios_mdasm_t {
    uint32_t AR_BR;  /* A and B registers as one 32-bit pair (AR = high half / BR = low half): the drivers read and write them with one access - edge captures in input mode / the PWM compare pair in output mode */
    uint16_t XR;  /* X Register (extended capture/status value) */
    uint16_t SCRD;  /* Status/Control Register D (0x9=enable output) */
};

struct qadc64_regs_t {
    uint16_t MCR;  /* Module Configuration Register (bit15=QSTOP) */
    uint16_t TEST;  /* Test Register (reserved/debug) */
    uint16_t INTC;  /* Interrupt Configure Register */
    uint16_t PORTQA_B;  /* Port QA (high byte) and QB (low byte) Data Registers */
    uint16_t DDRQA_B;  /* Port QA (high byte) and QB (low byte) Data Direction Registers */
    uint16_t CCW;  /* Current Command Word pointer (queue head) */
    uint16_t RJURR;  /* Right-Justified Unsigned Result Register */
    uint16_t LJSRR;  /* Left-Justified Signed Result Register */
    uint16_t LJURR;  /* Left-Justified Unsigned Result Register */
};

struct tpu3_ch_params_t {
    uint16_t PARAM0;  /* Channel parameter 0 (SCR/function config) */
    uint16_t PARAM1;  /* Channel parameter 1 */
    uint16_t PARAM2;  /* Channel parameter 2 */
    uint16_t PARAM3;  /* Channel parameter 3 */
    uint16_t PARAM4;  /* Channel parameter 4 */
    uint16_t PARAM5;  /* Channel parameter 5 */
    uint16_t PARAM6;  /* Channel parameter 6 */
    uint16_t PARAM7;  /* Channel parameter 7 */
};

struct qadc64b_regs_t {
    uint16_t MCR;  /* Module Configuration Register (bit15=QSTOP) */
    uint16_t TEST;  /* Test Register (reserved/debug) */
    uint16_t INTC;  /* Interrupt Configure Register */
    uint16_t PORTQA_B;  /* Port QA (high byte) and QB (low byte) Data Registers */
    uint16_t DDRQA_B;  /* Port QA (high byte) and QB (low byte) Data Direction Registers */
    uint16_t CCW;  /* Current Command Word pointer (queue head) */
    uint16_t RJURR;  /* Right-Justified Unsigned Result Register */
    uint16_t LJSRR;  /* Left-Justified Signed Result Register */
    uint16_t LJURR;  /* Left-Justified Unsigned Result Register */
};

struct tpua_ch1_params_t {
    uint16_t PARAM0;  /* Channel 1 parameter 0 */
    uint16_t PARAM1;  /* Channel 1 parameter 1 */
    uint16_t PARAM2;  /* Channel 1 parameter 2 */
    uint16_t PARAM3;  /* Channel 1 parameter 3 */
    uint16_t PARAM4;  /* Channel 1 parameter 4 */
    uint16_t PARAM5;  /* Channel 1 parameter 5 */
    uint16_t PARAM6;  /* Channel 1 parameter 6 */
    uint16_t PARAM7;  /* Channel 1 parameter 7 */
};

struct tpua_ch9_params_t {
    uint16_t PARAM0;  /* Channel 9 parameter 0 */
    uint16_t PARAM1;  /* Channel 9 parameter 1 */
    uint16_t PARAM2;  /* Channel 9 parameter 2 */
    uint16_t PARAM3;  /* Channel 9 parameter 3 */
    uint16_t PARAM4;  /* Channel 9 parameter 4 */
    uint16_t PARAM5;  /* Channel 9 parameter 5 */
    uint16_t PARAM6;  /* Channel 9 parameter 6 */
    uint16_t PARAM7;  /* Channel 9 parameter 7 */
};

struct tpua_ch12_params_t {
    uint16_t PARAM0;  /* Channel 12 parameter 0 */
    uint16_t PARAM1;  /* Channel 12 parameter 1 */
    uint16_t PARAM2;  /* Channel 12 parameter 2 */
    uint16_t PARAM3;  /* Channel 12 parameter 3 */
    uint16_t PARAM4;  /* Channel 12 parameter 4 */
    uint16_t PARAM5;  /* Channel 12 parameter 5 */
    uint16_t PARAM6;  /* Channel 12 parameter 6 */
    uint16_t PARAM7;  /* Channel 12 parameter 7 */
};

struct tpua_ch14_params_t {
    uint16_t PARAM0;  /* Channel 14 parameter 0 */
    uint16_t PARAM1;  /* Channel 14 parameter 1 */
    uint16_t PARAM2;  /* Channel 14 parameter 2 */
    uint16_t PARAM3;  /* Channel 14 parameter 3 */
    uint16_t PARAM4;  /* Channel 14 parameter 4 */
    uint16_t PARAM5;  /* Channel 14 parameter 5 */
    uint16_t PARAM6;  /* Channel 14 parameter 6 */
    uint16_t PARAM7;  /* Channel 14 parameter 7 */
};

struct tpub_ch0_params_t {
    uint16_t PARAM0;  /* TPUB Channel 0 parameter 0 */
    uint16_t PARAM1;  /* TPUB Channel 0 parameter 1 */
    uint16_t PARAM2;  /* TPUB Channel 0 parameter 2 */
    uint16_t PARAM3;  /* TPUB Channel 0 parameter 3 */
    uint16_t PARAM4;  /* TPUB Channel 0 parameter 4 */
    uint16_t PARAM5;  /* TPUB Channel 0 parameter 5 */
    uint16_t PARAM6;  /* TPUB Channel 0 parameter 6 */
    uint16_t PARAM7;  /* TPUB Channel 0 parameter 7 */
};

struct tpub_ch11_params_t {
    uint16_t PARAM0;  /* TPUB Channel 11 parameter 0 */
    uint16_t PARAM1;  /* TPUB Channel 11 parameter 1 */
    uint16_t PARAM2;  /* TPUB Channel 11 parameter 2 */
    uint16_t PARAM3;  /* TPUB Channel 11 parameter 3 */
    uint16_t PARAM4;  /* TPUB Channel 11 parameter 4 */
    uint16_t PARAM5;  /* TPUB Channel 11 parameter 5 */
    uint16_t PARAM6;  /* TPUB Channel 11 parameter 6 */
    uint16_t PARAM7;  /* TPUB Channel 11 parameter 7 */
};

struct tpub_ch14_params_t {
    uint16_t PARAM0;  /* TPUB Channel 14 parameter 0 */
    uint16_t PARAM1;  /* TPUB Channel 14 parameter 1 */
    uint16_t PARAM2;  /* TPUB Channel 14 parameter 2 */
    uint16_t PARAM3;  /* TPUB Channel 14 parameter 3 */
    uint16_t PARAM4;  /* TPUB Channel 14 parameter 4 */
    uint16_t PARAM5;  /* TPUB Channel 14 parameter 5 */
    uint16_t PARAM6;  /* TPUB Channel 14 parameter 6 */
    uint16_t PARAM7;  /* TPUB Channel 14 parameter 7 */
};

struct mios_mmcsm_b_t {
    uint16_t CNT;  /* Up-Counter Register */
    uint16_t ML;  /* Modulus Latch Register (period/reload value) */
    uint16_t _pad;  /* Reserved/unused padding */
    uint16_t SCRD;  /* Status/Control Register D */
};

struct toucan_module_registers_t {
    uint16_t MCR;  /* Module configuration: mpc555_initCanController writes 0x5000 (freeze + halt) before the setup and 0 after it (PR #53 round 25) */
    uint16_t TCR;  /* Test register (PR #53 round 25) */
    uint16_t CANICR;  /* Interrupt configuration (0x400 at init) (PR #53 round 25) */
    uint8_t CANCTRL0;  /* Control register 0 (0 at init) (PR #53 round 25) */
    uint8_t CANCTRL1;  /* Control register 1 (0x10 at init) (PR #53 round 25) */
    uint8_t PRESDIV;  /* Prescaler divide (9 at init) (PR #53 round 25) */
    uint8_t CANCTRL2;  /* Control register 2 (0x36 at init) (PR #53 round 25) */
    uint16_t TIMER;  /* Free-running timer (the message buffer time stamps count it) (PR #53 round 25) */
    uint32_t reserved_0c;  /* Reserved (PR #53 round 25) */
    uint32_t RXGMSK;  /* Receive global mask, high and low halves (0x1fee0000 at init, one 32-bit store) (PR #53 round 25) */
    uint32_t RX14MSK;  /* Receive buffer 14 mask (0x1feffe00 at init) (PR #53 round 25) */
    uint32_t RX15MSK;  /* Receive buffer 15 mask (PR #53 round 25) */
    uint32_t reserved_1c;  /* Reserved (PR #53 round 25) */
    uint16_t ESR;  /* Error and status (PR #53 round 25) */
    uint16_t IMASK;  /* Interrupt mask, one bit per message buffer (0 at init) (PR #53 round 25) */
    uint16_t IFLAG;  /* Interrupt flags, one bit per message buffer (read, then cleared, at init) (PR #53 round 25) */
    uint8_t RXECTR;  /* Receive error counter (PR #53 round 25) */
    uint8_t TXECTR;  /* Transmit error counter (PR #53 round 25) */
};

struct toucan_message_buffer_t {
    uint16_t CONTROL_STATUS;  /* Bits 15-8 time stamp, 7-4 CODE, 3-0 LENGTH; mpc555_initCanController zeroes byte +1 (CODE / LENGTH) of all 16 buffers */
    uint16_t ID_HIGH;  /* Identifier, high word */
    uint16_t ID_LOW;  /* Identifier, low word */
    uint16_t DATA_0_1;  /* Data bytes 0-1 */
    uint16_t DATA_2_3;  /* Data bytes 2-3 */
    uint16_t DATA_4_5;  /* Data bytes 4-5 */
    uint16_t DATA_6_7;  /* Data bytes 6-7 */
    uint16_t RESERVED;  /* Reserved */
};

struct qsmcm_sci1_regs_t {
    uint16_t SCC1R0;  /* SCI1 Control Register 0 (baud/config) */
    uint16_t SCC1R1;  /* SCI1 Control Register 1 (interrupt enables) */
    uint16_t SC1SR;  /* SCI1 Status Register (TDRE/RDRF/OR/FE/NF/PF) */
    uint16_t SC1DR;  /* SCI1 Data Register (read=RX data write=TX data) */
};

struct qsmcm_qspi_ctrl_t {
    uint16_t SPCR0;  /* QSPI control 0: MSTR / bit size / CPOL / CPHA / baud (sth) */
    uint16_t SPCR1;  /* QSPI control 1: bit 15 = SPE (start) / DSCKL / DTL delays (sth) */
    uint16_t SPCR2;  /* QSPI queue pointers (ENDQP bits 12-8 / NEWQP bits 4-0) */
    uint8_t SPCR3;  /* QSPI control 3 */
    uint8_t SPSR;  /* QSPI status: bit 0x80 = SPIF (queue finished; cleared by cm848_onQspiFinished) */
};

struct qsmcm_recram_t {
    uint16_t RX0;  /* QSPI Receive RAM entry 0 */
    uint16_t RX1;  /* QSPI Receive RAM entry 1 */
    uint16_t RX2;  /* QSPI Receive RAM entry 2 */
    uint16_t RX3;  /* QSPI Receive RAM entry 3 */
    uint16_t RX4;  /* QSPI Receive RAM entry 4 (injector sequence index at bits 3-0) */
    uint16_t RX5;  /* QSPI Receive RAM entry 5 */
};

struct qsmcm_txram_t {
    uint16_t TX0;  /* QSPI Transmit RAM entry 0 (SPI opcode byte) */
    uint16_t TX1;  /* QSPI Transmit RAM entry 1 (SPI write command byte) */
    uint16_t TX2;  /* QSPI Transmit RAM entry 2 (EEPROM address / SPI data) */
    uint16_t TX3;  /* QSPI Transmit RAM entry 3 (write data word) */
    uint16_t TX4;  /* QSPI Transmit RAM entry 4 */
    uint16_t TX5;  /* QSPI Transmit RAM entry 5 */
};

struct keyon_flags_t {
    uint32_t capability_flags;  /* ECU capability bitmask (bit0=MIOS_ER bit1=key_on bit4=IMB3) */
    uint32_t state;  /* Key-on state machine state (0=idle 1=active) */
    uint16_t transfer_crc;  /* CRC-CCITT block transfer running accumulator */
    uint16_t _pad10;  /* Reserved */
    uint16_t mailbox_index;  /* CAN mailbox slot index for channel assignment */
    uint16_t _pad14;  /* Reserved */
    uint32_t runtime_counter;  /* ECU runtime counter (RAM 0x302012): loaded from EEPROM 0x1000030 at boot / +1 every 41 PIT ticks (~0.205 s per count if the PIT runs at 1 MHz) / written back at key-off; also the auth-token freshness clock (was eeprom_write_count) */
};

struct can_ring_state_t {
    uint32_t transmit_write_pointer;  /* Transmit ring write pointer: 12-byte frames from 0x3022e6; mpc555_canTransmitQueuePush stores a frame and advances it (was j1939_tx_write_ptr) | earlier note: J1939 TX queue write pointer (12-byte records base 0x3022E6) */
    uint32_t transmit_read_pointer;  /* Transmit ring read pointer: mpc555_manageCan1TransmitBuffer sends the frame there and advances it (wrapping after 0x3024ba) (was j1939_tx_read_ptr) | earlier note: J1939 TX queue read pointer */
    uint32_t receive_write_pointer;  /* Receive ring write pointer: 18-byte records from 0x302016 (mpc555_processCanReceiveBuffer) (was can_rx_write_ptr) | earlier note: CAN RX queue write pointer (18-byte records base 0x302016) */
    uint32_t receive_read_pointer;  /* Receive ring read pointer (mpc555_dispatchCanMessageHandlers) (was can_rx_read_ptr) | earlier note: CAN RX queue read pointer */
    uint8_t transmit_ring_full_flag;  /* 1 = the transmit ring is full: mpc555_canTransmitQueuePush sets it when its write pointer reaches the read pointer (and returns 4 while it is set); mpc555_manageCan1TransmitBuffer clears it after sending a frame (was _pad16 byte 0; PR #53 round 28) */
    uint8_t receive_ring_full_flag;  /* 1 = the receive ring is full: mpc555_processCanReceiveBuffer sets it when its write pointer reaches the read pointer; mpc555_dispatchCanMessageHandlers clears it (was _pad16 byte 1; PR #53 round 28) */
    uint16_t reserved_18;  /* No users (bytes 2-3 of the old _pad16) */
    uint32_t transmit_message_buffer_pointer;  /* The transmit message buffer: mpc555_initDiagnosticSubsystem sets it to TouCAN A buffer 0x3070f0 + 16 x n; the empty-ring path of mpc555_manageCan1TransmitBuffer clears its control byte (was toucan_mb_ptr) | earlier note: Active TouCAN mailbox base pointer for diagnostic session */
};

struct diag_write_request_state_t {
    uint32_t pending_request;  /* Boot reflash kernel: request whose positive response is deferred until the flash write completes (was adc_trigger_t.sensor_param_ptr) */
    uint32_t address_mode;  /* 0 = parameter-ID addressing (services 68/69) / 1 = absolute address (75/77); stored as a dword (was adc_scan_active word + _pad6) */
};

struct can_slot_range_t {
    uint16_t slot_start;  /* First CAN mailbox slot for diagnostic service */
    uint16_t slot_end;  /* Last CAN mailbox slot for diagnostic service */
};

struct can_rx_channel_t {
    uint16_t channel_id;  /* J1939 source address filter for CAN receive matching */
};

struct system_initialization_flags_t {
    uint16_t initialization_sentinel;  /* 0xBBBB, stored by mpc555_systemInitialization (the boot service loop); no reader in the .cpp (was init_sentinel) | earlier note: System initialization sentinel (0xBBBB = fully initialized) */
    uint16_t initialization_counter;  /* 0, stored by mpc555_systemInitialization; no reader in the .cpp (was init_counter) | earlier note: System initialization counter (zeroed at startup) */
};

struct eeprom_xfer_state_t {
    uint32_t bytes_transferred;  /* Current byte offset progress in EEPROM transfer block */
    uint32_t block_length;  /* Total bytes in current EEPROM transfer block */
    uint16_t _pad8;  /* Reserved */
    uint32_t eeprom_write_callback;  /* Writer for memory region type 5 (EEPROM) called by cm848_writeDiagMemory (was write_callback_ptr) */
    uint32_t flash2_write_callback;  /* Writer for memory region type 2 (Bank-2 flash) called by cm848_writeDiagMemory (was read_callback_ptr - it writes) */
    uint16_t transfer_timer;  /* Transfer timeout countdown (0x28 or 0x4B ticks init) */
};

struct eeprom_block_tracking_t {
    uint16_t watchdog_counter;  /* Transfer watchdog counter (reset each block) */
    uint8_t _pad2;  /* Reserved */
    uint32_t last_write_addr;  /* Previous block write address for continuity validation */
    uint32_t block_start_addr;  /* Start address of current EEPROM transfer range */
    uint16_t block_count;  /* Completed transfer block count (max 9) */
};

struct j1939_transport_transmit_session_t {
    uint16_t transported_pgn;  /* The PGN of the transported message (its PDU format byte and data page; mpc555_sendJ1939TransportRequestToSend masks the low byte), compared with each clear-to-send (was session_pgn) | earlier note: Active J1939 TP queue session PGN (0xEF__ format) */
    uint8_t total_packet_count;  /* (message_size - 1) / 7 + 1, set by mpc555_sendJ1939TransportRequestToSend; TP.CM byte 4 of the request-to-send (was queue_status2) | earlier note: J1939 TP queue entry count (number of packets in queue) */
    uint8_t next_packet_number;  /* The next packet number (TP.CM clear-to-send byte 3, recorded by mpc555_handleJ1939TransportClearToSend); mpc555_sendJ1939TransportDataPackets adds 15 per call (was range_start) | earlier note: J1939 TP batch range start index (incremented by batch size) */
    uint8_t granted_packet_count;  /* The packets left in the granted window (TP.CM clear-to-send byte 2); 0 at the request-to-send, 15 less per data packet call (was queue_ptr) | earlier note: J1939 TP remaining packet pointer (decremented by batch size) */
    uint8_t frame_queue_status;  /* The status mpc555_canTransmitQueuePush writes through its fourth argument (0x30290a) for the last frame: 0 queued / 1 no data / 4 queue full; the senders test it. No padding (was _pad5) | earlier note: Reserved */
    uint16_t message_size;  /* The transported message's size in bytes (its header data_length; TP.CM bytes 2-3), set by mpc555_sendJ1939TransportRequestToSend (was total_bytes) | earlier note: Total data bytes for TP queue session */
    uint32_t message_data_pointer;  /* The transported message's data (the message record's data pointer) (was data_buf_ptr) | earlier note: Pointer to source data buffer for queue TP session */
    uint32_t session_status_pointer;  /* Points at the message's status byte (the message record's last dword): 0x12 while the data transfer runs, 6 on a timeout (was state_ptr) | earlier note: Pointer to session status byte (J1939 TP state codes) */
    uint16_t timeout_timer;  /* Counted down by mpc555_sendJ1939TransportDataPackets while no window is granted; 0x37 after the request-to-send and each clear-to-send, 0x70 after a window; at 0 the session status becomes 6 (timeout) (was retry_timer) | earlier note: CTS retry countdown timer (nominal 0x37 ticks) */
    uint32_t frame_can_id;  /* The CAN identifier of the next frame: the message's with PDU format 0xEC (TP.CM, PGN 60416) for the request-to-send, then 0xEB (TP.DT, PGN 60160) (was can_header) | earlier note: CAN frame header word (PGN 0xEC00 RTS or 0xEB00 DT) */
    uint16_t frame_data_length;  /* Data bytes of the next frame: 8, or what is left for the last data packet (was packet_size) | earlier note: Bytes in current CTS packet grant (max 8) */
    uint32_t transmit_frame_pointer;  /* The frame assembly buffer the senders fill (0x30306D) (was tx_buf_ptr) | earlier note: Pointer to CAN TX assembly buffer (0x30306D) */
};

struct j1939_tp_pause_t {
    uint16_t pause_pgn;  /* J1939 DataRequest session PGN (0xEF00) */
    uint16_t _pad2;  /* Reserved */
    uint16_t pause_timer;  /* Pause session countdown (0x70 init / 0x19 per packet) */
    uint32_t pause_data;  /* First dword of DataRequest CAN frame copy */
    uint16_t data_count;  /* Number of QADC data items in DataRequest */
    uint32_t rx_buf_ptr;  /* Pointer to CAN RX data assembly buffer (0x303075) */
};

struct diagnostic_response_message_t {
    j1939_msg_hdr_t header;  /* CAN id and data length (the reply length the allocator gets) */
    void * data_pointer;  /* The reply data */
    void * status_pointer;  /* Points at the status byte right after the record (the J1939 transport writes 0x12 while it sends, 6 on a timeout); not a data end pointer */
};

struct boot_state_t {
    uint16_t boot_param;  /* Boot state machine initialization parameter */
    uint16_t boot_phase;  /* Boot phase counter (cycles 0-3 per PISCR interrupt) */
};

struct mios_mpiosm_t {
    uint16_t data;  /* Port data register: pin n = bit n (whole-word read-modify-write by the output line drivers) */
    uint16_t data_direction;  /* Port data direction register: bit n set = pin n is an output (0x2000 at startup / 0x200 / 0x8200 before driving pins 9 and 15) */
};

struct mios1_isr_t {
    uint16_t FLG;  /* MIOS1 interrupt flag register (bits cleared on service) */
    uint16_t _pad2;  /* Reserved */
    uint16_t EN;  /* MIOS1 interrupt enable register (channel mask) */
};

struct diag_clear_flags_t {
    uint8_t diag_response_write_count;  /* Diagnostic response write count pending */
    uint8_t diag_eeprom_work_byte;  /* EEPROM channel scratch byte */
    uint16_t learned_output_speed_to_vehicle_speed_ratio;  /* EEPROM-backed learned ratio = output shaft speed x 4096 / vehicle_speed (5141 = 40.2 rpm per mph) clamped 4480-6656; synthesizes the output shaft speed on sensor fault; 0x3fedfb bit 0 marks it learned (was fuel_temp_protection_ratio) */
};

struct j1939_ccss_tx_payload_t {
    uint8_t max_vehicle_speed_limit;  /* SPN 74 Maximum Vehicle Speed Limit (km/h); from maximum_road_speed; gate algorithm_enable_flags_3_cal&0x80 */
    uint8_t cruise_high_set_limit_speed;  /* SPN 87 Cruise Control High Set Limit Speed (km/h); gate algorithm_enable_flags_3_cal&0x40; fed by cruise_maximum_road_speed_cal */
    uint8_t cruise_low_set_limit_speed;  /* SPN 88 Cruise Control Operator Low Set Limit Speed (km/h); from cruise_speed_low_limit */
    uint8_t reserved3;  /* reserved - init 0xff (not available) */
    uint8_t reserved4;  /* reserved - init 0xff (not available) */
    uint8_t reserved5;  /* reserved - init 0xff (not available) */
    uint8_t reserved6;  /* reserved - init 0xff (not available) */
    uint8_t reserved7;  /* reserved - init 0xff (not available) */
};

struct pci_message_descriptor_t {
    uint8_t header_byte_0;  /* J1850 message header byte 1 (message ID - e.g. 0x10 engine data / 0x37 shift lever / 0x68 OBD-II request) */
    uint8_t header_byte_1;  /* Header byte 2 - 0 terminates a 1-byte header (e.g. 0x6A in 68 6A / 0x03 in D1 03) */
    uint8_t header_byte_2;  /* Header byte 3 - 0 terminates */
    uint8_t header_byte_3;  /* Header terminator (always 0 in ROM) */
    byte* data_buffer;  /* RAM payload buffer: TX copies it after the header / RX stores received bytes into it */
    byte* data_length;  /* Pointer to the payload length byte (ROM 0x57741..0x57748 or RAM) */
    uint16_t interval;  /* TX: send when *timer exceeds this / RX: receive timeout; 0 = event-driven (armed by writing 1 to *timer) and not timeout-checked; same units as *timer (+10 per monitor pass) */
    word* timer;  /* RAM age timer: +10 per pass saturating at 0xff00; TX reset on own-message echo and RX reset on reception; RX starts at 0xff37 = never received */
    uint8_t in_frame_response_enabled;  /* Nonzero = J1850 in-frame response: RX entry -> ECM sends in_frame_response_bytes inside the frame (pci_frame_match_flags 0x04); TX entry -> ECM expects them back (0x08). Only TX 0xB0 sets it in this ROM (RX path inactive under this cal) */
    uint8_t reserved_19;  /* Unused padding */
    byte* in_frame_response_bytes;  /* Zero-terminated in-frame response bytes (up to 12): RX entry = bytes the ECM sends (cm848_sendPciInFrameResponseByte) / TX entry = bytes expected back and compared against the frame tail (mismatch sets status bit 0x08); ROM 0x57740 (empty) except TX 0xB0 (RAM 0x40b4fd) */
    byte* status;  /* RAM status byte: bit 0x10 = message timed out (latched; RX handler keeps it via &= 0x90) / bit 0x80 meaning unconfirmed */
};

struct qspi_job_t {
    uint32_t busy_state;  /* 0 = idle / 1 = queued / 2 = transfer started */
    uint8_t device_slot;  /* QSPI device slot (bus reconfigured via mpc555_j1939InitTransmitBuffer when it changes) */
    uint8_t word_count;  /* Number of QSPI words to transfer (must be under 0x21) */
    word* transmit_words;  /* Words copied into QSPI transmit RAM (must be non-null) */
    byte* command_bytes;  /* Bytes copied into QSPI command RAM (must be non-null) */
    word* receive_words;  /* Where the received QSPI words are stored */
    void * completion_callback;  /* Function called when the transfer completes */
};

struct qspi_device_slot_t {
    uint16_t spcr0;  /* SPCR0 value for this device (mode + baud) */
    uint16_t spcr1;  /* SPCR1 value for this device (delays) */
};

struct qspi_job_queue_t {
    uint8_t active_index;  /* jobs[] index of the job being transferred */
    uint8_t write_index;  /* jobs[] index the next queued job is stored at (wraps at 16) */
    uint8_t pending_count;  /* Jobs queued and not yet completed (max 16) */
    qspi_job_t* jobs;  /* Ring of 16 queued job pointers */
};

struct memory_region_t {
    uint32_t start_address;  /* First address of the region */
    uint32_t end_address;  /* Last address of the region */
    uint8_t region_type;  /* 0 RAM / 2 Bank-2 flash / 3 registers / 4 main flash / 5 EEPROM (9 = not found) */
    uint8_t region_type_copy;  /* Same value as region_type in every entry */
};

struct j1939_input_signal_descriptor_t {
    byte* signal_value;  /* Received signal byte (j1939_received_*) */
    uint8_t timeout_slot;  /* Index into j1939_input_signal_timeouts (also the fault bitmap index) */
    uint8_t reserved_5;  /* Always 0 */
    uint32_t logical_switch;  /* The logical switch (0-31) this input drives: cm848_evaluateJ1939InputSignalFault indexes switch_input_datalink_source_bits_cal / switch_input_source_priority / j1939_switch_input_default_state_bits with it and sets / clears its switch_input_datalink_state_bits bit through cm848_setDatalinkSwitchStateIfPriority / cm848_clearDatalinkSwitchStateIfPriority (received 1 sets / 0 clears; 2 / 3 or a timeout apply the default bit). Table values: brake switch 11 / clutch switch 15 / PTO on 3 / remote PTO 19 / accelerator interlock 26 / the other 12 inputs 31 (the unwired switch) (was fault_bit_index */
};

struct output_read_back_fault_bits_t {
    uint16_t : 1;
    uint16_t cooling_fan : 1;  /* bit 1: Bit 1 of word 0 = output channel assignment table entry 1: cooling fan read-back fault (P0480 / fault 121) */
    uint16_t : 8;
    uint16_t governor_pressure_solenoid : 1;  /* bit 10: Bit 10 of word 0 = entry 10: governor pressure solenoid read-back fault (P0748 / fault 351) */
    uint16_t wastegate_solenoid : 1;  /* bit 11: Bit 11 of word 0 = entry 11: wastegate solenoid read-back fault (P0243 / fault 403) */
    uint16_t : 4;
    uint16_t : 4;
    uint16_t fuel_metering : 1;  /* bit 4: Bit 4 of word 1 = entry 20: fuel metering read-back fault (P0251 / fault 333) */
    uint16_t : 6;
    uint16_t alternator_field : 1;  /* bit 11: Bit 11 of word 1 = entry 27: alternator field read-back fault (P0622 / fault 396) */
    uint16_t : 4;
    uint16_t entries_32_to_47;  /* Word 2 = entries 32-47 (no read-back output assigned in this calibration) */
};

struct monitor_condition_bits_t {
    uint32_t vehicle_speed_sensor_signal_loss : 1;  /* bit 0: set when OBD battery voltage in range; power take off disengaged delay elapsed; NOT power take off active (switch 3 or power_take_off_governor_active_flag); OBD engine running. Read by cm848_detectVehicleSpeedSensorSignalLoss (lwz at 0x526928, clrlwi 31, P0500 path 1). */
    uint32_t vehicle_speed_sensor_zero_under_load : 1;  /* bit 1: set when OBD battery voltage in range; power take off disengaged delay elapsed; NOT power take off active (switch 3 or power_take_off_governor_active_flag); OBD engine running. Read by cm848_detectVehicleSpeedSensorZeroUnderLoad (lwz at 0x5269d4, mask 2, P0500 path 2). */
    uint32_t overboost_and_high_load_boost_band : 1;  /* bit 2: set when power take off disengaged delay elapsed; NOT power take off active (switch 3 or power_take_off_governor_active_flag); monitor group 0 complete. Read by cm848_monitorOverboostAndHighLoadBoostBand (lwz at 0x5372e4, mask 4). */
    uint32_t reserved_bit_3 : 1;  /* bit 3: never set: ROM mask 0 with expected 0xfff7 can not match. No reader in either bank (sweep of 0x40b9d0). */
    uint32_t coolant_temperature_sensor_performance : 1;  /* bit 4: set when OBD battery voltage in range; NOT power take off active (switch 3 or power_take_off_governor_active_flag); OBD engine running. Read by cm848_checkCoolantTemperatureSensorPerformance (lwz at 0x52e090, mask 0x10). */
    uint32_t fuel_level_low_distance : 1;  /* bit 5: set when OBD battery voltage in range; NOT power take off active (switch 3 or power_take_off_governor_active_flag); OBD engine running. Read by cm848_monitorFuelLevelLowDistance (lwz at 0x5307e4, mask 0x20). */
    uint32_t fuel_temperature_sensor_cold_soak_check : 1;  /* bit 6: set when OBD battery voltage in range; engine_state 1. Read by cm848_checkFuelTemperatureSensorAfterColdSoak (lwz at 0x53047c, mask 0x40). */
    uint32_t fuel_pressure_tracking : 1;  /* bit 7: set when OBD battery voltage in range; NOT power take off active (switch 3 or power_take_off_governor_active_flag); engine_state 3; logical output request 53; NOT fault 397 registered (OBD fuel level low). Read by cm848_monitorFuelPressureTrackingError (lwz at 0x532184) and cm848_monitorFuelPressureSetpointNotReached (lwz at 0x536ea0, 0x537170), mask 0x80. */
    uint32_t reserved_bit_8 : 1;  /* bit 8: never set: ROM mask 0 with expected 0xfff7 can not match. No reader in either bank (sweep of 0x40b9d0). */
    uint32_t reserved_bit_9 : 1;  /* bit 9: never set: ROM mask 0 with expected 0xfff7 can not match. No reader in either bank (sweep of 0x40b9d0). */
    uint32_t reserved_bit_10 : 1;  /* bit 10: never set: ROM mask 0 with expected 0xfff7 can not match. No reader in either bank (sweep of 0x40b9d0). */
    uint32_t thermostat_system : 1;  /* bit 11: set when OBD battery voltage in range; NOT power take off active (switch 3 or power_take_off_governor_active_flag); OBD engine running. Read by cm848_runThermostatMonitor (lwz at 0x536b94, mask 0x800). */
    uint32_t reserved_bit_12 : 1;  /* bit 12: never set: ROM mask 0 with expected 0xfff7 can not match. No reader in either bank (sweep of 0x40b9d0). */
    uint32_t boost_pressure_sensor_and_underboost : 1;  /* bit 13: set when OBD battery voltage in range; NOT power take off active (switch 3 or power_take_off_governor_active_flag); OBD engine running. Read by cm848_monitorBoostPressureSensorAndUnderboost (lwz at 0x52d908, 0x52dae0, mask 0x2000). */
    uint32_t misfire : 1;  /* bit 14: set when OBD battery voltage in range; NOT power take off active (switch 3 or power_take_off_governor_active_flag); NOT fault 397 registered (OBD fuel level low). Read by cm848_checkMisfireMonitorTestConditions (lwz at 0x532dbc) and cm848_runMisfireMonitor (lwz at 0x533130, 0x53339c), mask 0x4000. */
    uint32_t charge_pressure_estimate_enable : 1;  /* bit 15: set when OBD battery voltage in range; NOT power take off active (switch 3 or power_take_off_governor_active_flag); OBD engine running. The enabling condition of the charge pressure estimate: cm848_estimateChargePressure (lwz at 0x13488, mask 0x8000) forces charge_pressure_estimate_with_turbocharger_speed_state to 0x80 while the bit is clear (was boost_fuel_weight_factor). */
    uint32_t egr_delta_pressure_sensor_performance : 1;  /* bit 16: set when OBD battery voltage in range; NOT power take off active (switch 3 or power_take_off_governor_active_flag). Read by cm848_checkEgrDeltaPressureSensorPerformance (lwz at 0x52e4c8 with mask 0x10000 in r29, .cpp line 87691). */
    uint32_t reserved_bit_17 : 1;  /* bit 17: set when OBD battery voltage in range; NOT power take off active (switch 3 or power_take_off_governor_active_flag). No reader in either bank (sweep of 0x40b9d0). */
    uint32_t reserved_bit_18 : 1;  /* bit 18: set when OBD battery voltage in range; NOT power take off active (switch 3 or power_take_off_governor_active_flag). No reader in either bank (sweep of 0x40b9d0). */
    uint32_t reserved_bit_19 : 1;  /* bit 19: set when OBD battery voltage in range; NOT power take off active (switch 3 or power_take_off_governor_active_flag). No reader in either bank (sweep of 0x40b9d0). */
    uint32_t reserved_bit_20 : 1;  /* bit 20: set when OBD battery voltage in range; NOT power take off active (switch 3 or power_take_off_governor_active_flag). No reader in either bank (sweep of 0x40b9d0). */
    uint32_t reserved_bit_21 : 1;  /* bit 21: set when OBD battery voltage in range; NOT power take off active (switch 3 or power_take_off_governor_active_flag). No reader in either bank (sweep of 0x40b9d0). */
    uint32_t reserved_bit_22 : 1;  /* bit 22: set when OBD battery voltage in range; NOT power take off active (switch 3 or power_take_off_governor_active_flag). No reader in either bank (sweep of 0x40b9d0). */
    uint32_t unidentified_monitor_23 : 1;  /* bit 23: set when OBD battery voltage in range; NOT power take off active (switch 3 or power_take_off_governor_active_flag). Read by cm848_monitorEgrOrificeTemperatureSensorRationality (lwz at 0x52eb38 with mask 0x800000 in r27, .cpp line 87883, monitor not identified, faults 512 and 513 have no DTC slot). */
    uint32_t wastegate_boost_pressure : 1;  /* bit 24: set when power take off disengaged delay elapsed; NOT power take off active (switch 3 or power_take_off_governor_active_flag); monitor group 0 complete. Read by cm848_monitorWastegateBoostPressure (lwz at 0x5375b0 with mask 0x1000000 in r31, .cpp line 92888). */
    uint32_t reserved_bit_25 : 1;  /* bit 25: set when OBD battery voltage in range; NOT power take off active (switch 3 or power_take_off_governor_active_flag). No reader in either bank (sweep of 0x40b9d0). */
    uint32_t park_neutral_switch : 1;  /* bit 26: set when NOT power take off active (switch 3 or power_take_off_governor_active_flag); NOT fault 397 registered (OBD fuel level low). Read by cm848_monitorParkNeutralSwitch (lwz at 0x51b628, 0x51b7c0, mask 0x4000000). */
    uint32_t governor_pressure_sensor_offset : 1;  /* bit 27: set when OBD battery voltage in range; power take off disengaged delay elapsed; engine_state 3; NOT fault 397 registered (OBD fuel level low); OBD engine running. Read by cm848_monitorGovernorPressureSensorOffset (lwz at 0x51ad34, mask 0x8000000). */
    uint32_t transmission_output_speed_sensor : 1;  /* bit 28: set when OBD battery voltage in range; power take off disengaged delay elapsed; NOT fault 397 registered (OBD fuel level low); OBD engine running. Read by cm848_monitorTransmissionOutputSpeedSensor (lwz at 0x3de14, mask 0x10000000, P0720). */
    uint32_t governor_pressure_tracking : 1;  /* bit 29: set when OBD battery voltage in range; power take off disengaged delay elapsed; NOT fault 397 registered (OBD fuel level low); OBD engine running. Read by cm848_monitorGovernorPressureTracking (lwz at 0x51aff0, mask 0x20000000). */
    uint32_t converter_clutch_and_overdrive_performance : 1;  /* bit 30: set when OBD battery voltage in range; power take off disengaged delay elapsed; NOT fault 397 registered (OBD fuel level low); OBD engine running. Read by cm848_monitorConverterClutchAndOverdrivePerformance (lwz at 0x51bec0 with mask 0x40000000 in r21, .cpp line 75941). */
    uint32_t reserved_bit_31 : 1;  /* bit 31: set when OBD battery voltage in range; power take off disengaged delay elapsed; NOT fault 397 registered (OBD fuel level low); OBD engine running. No reader in either bank (sweep of 0x40b9d0). */
};

struct logical_output_request_bits_16_to_23_t {
    uint8_t transmission_relay_request : 1;  /* bit 0: e2m 1577 +2 0x01 Transmission_VFS_Battery_Driver (12A7 +0x10 Transmission_VFS_Battery_Driver_Priority): the battery feed of the transmission solenoids. output 16 = the transmission control relay (mask 1). cm848_monitorDiscreteOutputReadBack checks output 16 with cm848_checkDiscreteOutputReadBack(0x10,0x16,0x88,0x89,...): faults 136 / 137 = P0883 / P0882 'TCM power input signal high / low' (the relay output voltage), and fault 137 sets the e2m 8C19 bit RE_Trans_Relay_Circuit_Open ('transmission power relay is open-circuit'). cm848_updateTransmissionRelayRequest requests it (cm848_setLogicalOutputRequest(0x10,0)) only while the engine is not stopped and none of the relay / solenoid circuit limp bits is set. The solenoid diagnostics (the governor pressure solenoid read-back debounce in cm848_debounceOutputReadBackFaults, the output checks of outputs 17 / 18) and the governor pressure monitors run only while it is set (was reserved_bit_0) | earlier note: guess (not proven, so reserved): a transmission solenoid enable request; the old note said transmission relay */
    uint8_t overdrive_solenoid_request : 1;  /* bit 1: e2m 1577 +2 0x02 Transmission_Overdrive_Driver. output 17 (mask 2). cm848_processOverdriveSwitchAndShift sets it with cm848_setLogicalOutputRequest(0x11,0) together with transmission_3_4_transition_timer and clears it on the overdrive release; read with mask 2 in cm848_monitorConverterClutchAndOverdrivePerformance and cm848_determineCurrentGearAndLockupInhibit. */
    uint8_t converter_clutch_solenoid_request : 1;  /* bit 2: e2m 1577 +2 0x04 Transmission_TCC_Driver. output 18 (mask 4, about 30 uses). cm848_applyConverterLockupSchedule sets it (cm848_setLogicalOutputRequest(0x12,0)); cm848_applyConverterUnlockConditions, cm848_applyConverterUnlockConditionsLowRange and cm848_processOverdriveSwitchAndShift clear it (cm848_clearLogicalOutputRequest(0x12,0)). */
    uint8_t cruise_vent_solenoid_request : 1;  /* bit 3: e2m 1577 +2 0x08 Cruise_Vent_Driver. output 19 (mask 8): cm848_setLogicalOutputRequest(0x13,...) in cm848_controlCruiseVacuumServo (decompile line 41596); wave 2 identified requests 19 / 20 / 21 as cruise vent / vacuum / servo supply. No direct read of this mask. */
    uint8_t cruise_vacuum_solenoid_request : 1;  /* bit 4: e2m 1577 +2 0x10 Cruise_Vacuum_Driver. output 20 (mask 0x10): cm848_setLogicalOutputRequest(0x14,...) in cm848_controlCruiseVacuumServo (decompile line 41602). No direct read of this mask. */
    uint8_t cruise_servo_supply_request : 1;  /* bit 5: e2m 1577 +2 0x20 Cruise_SC_Source_Driver. output 21 (mask 0x20): cm848_setLogicalOutputRequest(0x15,...) in cm848_controlCruiseVacuumServo (decompile line 41584); mask 0x20 is read by cm848_deriveSecondBrakeSwitchSignal and cm848_checkDiscreteOutputReadBack (the supply runs through the brake switch). */
    uint8_t reserved_bit_6 : 1;  /* bit 6: output 22 (mask 0x40): e2m 1577 +2 CORS_Makeup_Valve_Driver; no direct read or write found */
    uint8_t reserved_bit_7 : 1;  /* bit 7: output 23 (mask 0x80): e2m 1577 +2 Fan_Clutch_Control_Driver1; no direct read or write found */
};

struct qadc_channel_dispatch_entry_t {
    word* result_register;  /* Points at the QADC result register of this channel slot */
    void * shared_zero_word_pointer;  /* 0x57dd0 in all 129 records */
};

struct fault_definition_t {
    uint16_t cummins_fault_code;  /* Cummins fault code of the slot (cross-checked against obd_dtc_code_table for slots 1-13) */
    uint16_t definition_flags;  /* Definition flags */
    uint8_t entry_flags;  /* Entry flags */
    uint8_t aging_flags;  /* Aging flags */
};

struct fault_monitor_group_t {
    uint8_t fault_slots[16];  /* The fault slots of one OBD monitor group (lbzx @ 0x53469c) */
};

struct monitor_calibrated_condition_t {
    uint32_t disabled_monitor_mask;  /* Monitors this condition disables */
    uint16_t parameter_id;  /* Parameter ID of the value it tests */
    uint16_t parameter_byte_offset;  /* Byte offset added to the parameter's address */
    uint16_t comparison_type;  /* Comparison type */
    uint16_t comparison_value;  /* Comparison value */
};

struct engine_overspeed_event_t {
    uint32_t start_key_on_hour_meter;  /* Key-on hour meter when the overspeed started (lwz / stw) */
    uint16_t engine_speed_at_detection;  /* Engine speed at detection (1/8 rpm) */
    uint16_t duration;  /* Duration of the overspeed */
};

struct dtc_list_t {
    uint8_t count;  /* Number of codes in the list (the loops are 1-based from this byte) */
    uint8_t slots[31];  /* The listed fault slots */
};

struct fault_state_t {
    uint32_t timestamp;  /* Key-on hour meter stamp of the fault (was fault_timestamp_array) */
    uint8_t debounce_count;  /* Debounce count (was fault_entry_debounce_array) */
    uint8_t status;  /* Status (was fault_entry_status_array) */
    uint8_t timer;  /* Timer (was fault_timer_array) */
};

struct pci_controller_command_word_t {
    uint8_t data_byte;  /* Data byte of the command word sent to the external J1850 controller */
    uint8_t command_code;  /* Command code (the low byte; written bytewise - read once with lhz @ 0x39f14) */
};

struct end_of_line_test_settings_t {
    uint8_t test_results_1;  /* Chrysler in-plant test results 1 (SCI id 0x77) - bits 2-3 read by cm848_runEndOfLineFinalResultStep: bit 3 set = the plant tester's verdict is pending / bit 2 set = fail (clear = pass) */
    uint8_t test_results_3;  /* Test results 3 */
    uint8_t final_test_results_1;  /* Final test results 1 - bit 3: cm848_runEndOfLineTestStartStep goes to the final result step when no test is pending */
    uint8_t final_test_results_2;  /* Final test results 2 */
    uint16_t field_mode_register;  /* e2m Field Mode register (0xFFFF in the dumps) */
    uint8_t test_flags_1;  /* Test flags 1 ($CC) - cleared to 0 by cm848_runEndOfLineTestStartStep */
    uint8_t test_flags_2;  /* Test flags 2 ($CD): bit 3 = the output tests pending (cleared at the end of the output test step) / bit 4 = the output tests not passed (cleared when no DTC is stored) / bits 5 and 7 = the lift pump test not passed (cleared without P0629 / P0628); the start step keeps only bits 3-5 and 7 */
    uint8_t test_flags_3;  /* Test flags 3 ($CE): bit 5 = the alternator test pending (cleared after the test); the start step keeps only bit 5 */
    uint8_t test_flags_4;  /* Test flags 4 ($CF): bit 0 = the alternator test not passed (cleared on a pass and when end_of_line_test_enable_flags bit 5 is clear); the start step keeps only bit 0 */
    uint8_t test_flags_5;  /* Test flags 5 (bit 0x10 holds the end-of-line misfire test) ($D0): bit 0 = the intake air heater test pending / bit 1 = it has not passed / bit 4 = the misfire test pending / bit 5 = it has not passed (bits 0-1 and 4-5 are cleared when enable bit 0 / 1 is clear); the start step clears bits 2-3 */
    uint8_t final_test_reserved_1;  /* Final test reserved byte */
    uint8_t maximum_miles;  /* Max miles for the in-plant mode (32 in the dumps) */
    uint8_t reserved_13;  /* Reserved */
    uint8_t misfire_test_timeout_seconds;  /* Misfire test timeout (30 s in the dumps) */
    uint8_t misfire_test_warm_up_seconds;  /* Misfire test warm-up (18 s in the dumps) */
};

struct algorithm_enable_flags_12_t {
    uint16_t idle_speed_save_enable : 1;  /* bit 0: e2m Idle_Speed_Save_Enable (LSISSVEN, saves the last idle speed at shutdown). No reader in either bank (sweep of both banks). Clear in this calibration (0x2e06). (was reserved_bit_0; named from its e2m record in PR #53 round 20, as in algorithm_enable_flags_3_t) */
    uint16_t reserved_bit_1 : 1;  /* bit 1: e2m Overspeed_FSO_Override (EPOSFSO, fuel shut-off valve on overspeed). No reader in either bank (sweep of both banks). Set in this calibration (0x2e06). */
    uint16_t water_in_fuel_enable : 1;  /* bit 2: e2m Water_In_Fuel_Enable (WFAGEN). cm848_sendPgn65279WaterInFuelIndicatorMessage (lhz at 0x26ea0: the PGN 65279 byte stays 0xff while clear) and cm848_monitorWaterInFuel (lhz at 0x5103b8: clears fault 56 bit 0x100 while clear). Code agrees with the e2m label. Set in this calibration (0x2e06). */
    uint16_t air_fuel_control_override_enable : 1;  /* bit 3: e2m AFC_Override_Enable (AFENMAN). cm848_calculateAirFuelControlFuelLimit (lhz 24(r26) at 0xdcf4): while clear it computes the limit from air_fuel_control_fuel_limit_grid, so set overrides it. Code agrees. Clear in this calibration (0x2e06). */
    uint16_t electronic_smart_power_enable : 1;  /* bit 4: e2m ESP_Enable (SPAGEN; ESP = Electronic Smart Power per e2m Group_ESP_8). hpcr_calculateFuelTrimOutput (lhz at 0xe71c) and cm848_calculateThrottle100Fuelings (lhz at 0x1f290): while set the four_dimensional_fueling_interpolation_factor is zeroed around cm848_calculateMaximumFuelCurve. A reader exists but its behaviour is not tied to the e2m label. Clear in this calibration (0x2e06). */
    uint16_t reverse_electronic_smart_power_enable : 1;  /* bit 5: e2m Reverse_ESP_Enable (SPRVEN, Electronic Smart Power launch application). No reader in either bank (sweep of both banks). Clear in this calibration (0x2e06). (was reserved_bit_5; named from its e2m record in PR #53 round 20, as in algorithm_enable_flags_3_t) */
    uint16_t low_speed_governor_droop_enable : 1;  /* bit 6: e2m LSG_Droop_Enable (LSDPEN). cm848_updateProtectionParameters (lhz at 0x20b90) and cm848_calculateFaultDerateJ1939TorqueCurveSpeedPoints (lhz at 0x507a70): while set the governor integrator output is reduced by governor_integrator_correction_term times ROM 0x5c352 divided by 167 (a droop). Code agrees. Clear in this calibration (0x2e06). */
    uint16_t accelerator_interlock_enable : 1;  /* bit 7: e2m Accelerator_Interlock_Enable (ANEN). cm848_claimAcceleratorInterlockThrottleOverride (lhz at 0x403e8: with switch 26 set it forces the fuel demand override to its minimum) and cm848_j1939BuildEngineControlByte (lhz 24(r5) at 0x25788). Code agrees. Clear in this calibration (0x2e06). */
    uint16_t vehicle_speed_sensor_signal_loss_enable : 1;  /* bit 8: e2m VSS_Moving_Enable (VSMVEN): the sensor drops to 0 while the filtered speed is still above 10 mph. Named after the detector it gates. cm848_detectVehicleSpeedSensorSignalLoss (lhz at 0x526950, P0500 path 1) and cm848_clearHealedVehicleSpeedSensorFault (lhz at 0x526be8). Code agrees. Clear in this calibration (0x2e06). */
    uint16_t vehicle_speed_sensor_zero_under_load_enable : 1;  /* bit 9: e2m VSS_Stopped_Enable (VSSTEN): the sensor reads stopped (0) while the engine is under load. Named after the detector it gates. cm848_detectVehicleSpeedSensorZeroUnderLoad (lhz at 0x5269fc, P0500 path 2) and cm848_clearHealedVehicleSpeedSensorFault (lhz at 0x526bd8). Code agrees: the sensor reads 0 while the engine is under load. Set in this calibration (0x2e06). */
    uint16_t obd_fault_handler_enable : 1;  /* bit 10: e2m OBD_Fault_Handler_Enable (DGOBFUHN). 11 fault framework functions test it (cm848_registerFaultInActiveList at 0x1cf1c, cm848_clearDiagnosticState, cm848_processFaultScanGroup, diagnosticMainStateProcessor, cm848_updateFaultEntryCounters, cm848_resetFaultStatus, hpcr_setFaultActiveStatus, cm848_advanceDiagnosticActionState, cm848_j1939HandlePgn65228Dm3ClearDiag, cm848_completeBoostPressureMonitorReport, cm848_monitorEgrOrificeTemperatureSensorRationality); the names agree, the bodies were not read. Set in this calibration (0x2e06). */
    uint16_t power_take_off_brake_override_enable : 1;  /* bit 11: e2m PTO_Brake_Override_Enable (PTBRODEN). cm848_runPowerTakeOffGovernorStateMachine (lhz 24(r31) at 0x2b214) pairs it with power_take_off_governor_switch_state_bits 0x10000, which that function sets from switch 11 (brake), to leave power take off control. Code agrees. Set in this calibration (0x2e06). */
    uint16_t power_take_off_clutch_override_enable : 1;  /* bit 12: e2m PTO_Clutch_Override_Enable (PTCHODEN). The same function pairs it with power_take_off_governor_switch_state_bits 0x4000, set from switch 15 (clutch). Code agrees. Clear in this calibration (0x2e06). */
    uint16_t oil_change_monitor_enable : 1;  /* bit 13: e2m OCM_Enable (OCEA). cm848_updateOilChangeMonitor (lhz at 0x51a89c), together with j1939_governor_feature_byte mask 4. Code agrees. Set in this calibration (0x2e06). */
    uint16_t reserved_bit_14 : 1;  /* bit 14: no e2m name. No reader in either bank (sweep of both banks). Clear in this calibration (0x2e06). */
    uint16_t reserved_bit_15 : 1;  /* bit 15: no e2m name. No reader in either bank (sweep of both banks). Clear in this calibration (0x2e06). */
};

struct algorithm_enable_flags_18_t {
    uint16_t high_speed_governor_gain_scheduling_enable : 1;  /* bit 0: e2m HSG_Gain_Scheduling_Enable (HSGNSDEN). selectHighSpeedGovernorGainSet (lhz at 0x1fa24, clrlwi 31). Code agrees. Clear in this calibration (0x0008). */
    uint16_t reserved_bit_1 : 1;  /* bit 1: no e2m name. No reader in either bank (sweep of both banks). Clear in this calibration (0x0008). */
    uint16_t driver_reward_enable : 1;  /* bit 2: e2m DR_Enable (DREN, driver reward). No reader in either bank (sweep of both banks). Clear in this calibration (0x0008). (was reserved_bit_2; named from its e2m record in PR #53 round 20, as in algorithm_enable_flags_3_t) */
    uint16_t duty_cycle_monitor_enable : 1;  /* bit 3: duty cycle monitor enable - e2m DC_Mon_Enable (DCMNEN, duty cycle monitor). cm848_updateDutyCycleMonitorLoadHistogram (lhz at 0x5063a0, mask 8); the reader name agrees, the body was not read. Set in this calibration (0x0008). (was reserved_bit_3: a guess until PR #53 round 20 proved the e2m 106B block alignment) */
    uint16_t reserved_bit_4 : 1;  /* bit 4: no e2m name. No reader in either bank (sweep of both banks). Clear in this calibration (0x0008). */
    uint16_t reserved_bit_5 : 1;  /* bit 5: no e2m name. No reader in either bank (sweep of both banks). Clear in this calibration (0x0008). */
    uint16_t smart_air_compressor_enable : 1;  /* bit 6: e2m AC_Smart_Enable (ACEN, smart air compressor). No reader in either bank (sweep of both banks). Clear in this calibration (0x0008). (was reserved_bit_6; named from its e2m record in PR #53 round 20, as in algorithm_enable_flags_3_t) */
    uint16_t executive_timing_enable : 1;  /* bit 7: e2m Executive_Timing_Enable (SSECTMEA, executive timing data gatherer). main_loop (lhz 36(r29) at 0xc0c0, 0xc140, 0xc7b8); the reader agrees by name. Clear in this calibration (0x0008). */
    uint16_t high_speed_governor_gear_ratio_gain_enable : 1;  /* bit 8: e2m HSG_Gear_Ratio_Gain_Enable (HSGRGSEN). cm848_loadHighSpeedGovernorWorkingGainSet (lhz at 0x4248c); the reader agrees by name. Clear in this calibration (0x0008). */
    uint16_t programmable_power_enable : 1;  /* bit 9: e2m Programmable_Power_Enable (PPEN). 6 fuel limit, protection and cruise functions: cm848_calculateDualAxisFuelLimit (0x1ec88, 0x1ed88, 0x1ee74), cm848_calculateThrottle100Fuelings (0x1f194), cm848_initializeJ1939ReferenceEngineFuelingAndTorque (0x212e0), cm848_calculateJ1939TorqueCurveFuelingsAndReferenceFuelings (0x21d1c), cm848_updateCruiseAndRoadSpeedGovernorDroops (0x524bdc), cm848_presetCruiseAndRoadSpeedGovernor (0x52544c); the names agree, the bodies were not read. Clear in this calibration (0x0008). */
    uint16_t reserved_bit_10 : 1;  /* bit 10: no e2m name. No reader in either bank (sweep of both banks). Clear in this calibration (0x0008). */
    uint16_t cruise_control_auto_resume_enable : 1;  /* bit 11: e2m Cruise_Control_AR_Enable (AREN, cruise control auto resume). No reader in either bank (sweep of both banks). Clear in this calibration (0x0008). (was reserved_bit_11; named from its e2m record in PR #53 round 20, as in algorithm_enable_flags_3_t) */
    uint16_t remote_throttle_enable : 1;  /* bit 12: e2m Remote_Throttle_Enable (CTRMTHEN). cm848_j1939BuildEngineControlByte (0x256ac), cm848_buildPgn61443ElectronicEngineController2Message (0x25cbc), cm848_claimRemoteThrottleOverride (0x50e62c), cm848_clearEngineProtectionFaultsConditional (0x50e784); the names agree, the bodies were not read. Clear in this calibration (0x0008). */
    uint16_t remote_throttle_transition_verification_enable : 1;  /* bit 13: remote throttle transition verification enable - e2m Remote_Throttle_Transition_Verification_Enable (CTRTTZEN). cm848_claimRemoteThrottleOverride (lhz at 0x50e6e4); the name agrees, the body was not read. Clear in this calibration (0x0008). (was reserved_bit_13: a guess until PR #53 round 20 proved the e2m 106B block alignment) */
    uint16_t engine_retarder_service_brake_activate_enable : 1;  /* bit 14: e2m EB_Service_Brake_Activate_Enable (EBBREN, EB = engine brake). Proven in PR #53 round 17: its only reader, cm848_updateEngineRetarderAllowedState (lhz at 0x41610), lets the driver conditions pass while it is set only after a service brake tap (service_brake_recently_applied_flag) or with a cruise non-override command (was reserved_bit_14). Clear in this calibration (0x0008). */
    uint16_t engine_retarder_rate_limit_enable : 1;  /* bit 15: e2m EB_Rate_Limit_Enable (EBRTLMEA, engine brake level rate limit). No reader in either bank (sweep of both banks). Clear in this calibration (0x0008). (was reserved_bit_15; named from its e2m record in PR #53 round 20, as in algorithm_enable_flags_3_t) */
};

struct algorithm_enable_flags_3_t {
    uint16_t reserved_bit_0 : 1;  /* bit 0: no e2m record; no reader */
    uint16_t reserved_bit_1 : 1;  /* bit 1: no e2m record; no reader */
    uint16_t reserved_bit_2 : 1;  /* bit 2: no e2m record; no reader */
    uint16_t idle_speed_adjust_enable : 1;  /* bit 3: e2m 106B +8 Idle_Speed_Adjust_Enable (mask 0x8); no reader in this build */
    uint16_t power_take_off_enable : 1;  /* bit 4: e2m PTO_Enable (0x10): the power take-off governor state machine, its fueling and the PGN 65264 / 65265 broadcasts need it; set on this truck */
    uint16_t reserved_bit_5 : 1;  /* bit 5: no e2m record; no reader */
    uint16_t cruise_control_enable : 1;  /* bit 6: e2m Cruise_Control_Enable (0x40): cruise standby / denied status, PGN 65261 / 65265; set on this truck */
    uint16_t road_speed_governor_enable : 1;  /* bit 7: e2m Road_Speed_Governor_Enable (0x80): cm848_calculateRoadSpeedGovernorFueling gives no limit (0x1700) while it is clear; PGN 65261; set on this truck */
    uint16_t road_speed_governor_without_droops_below_top_gear : 1;  /* bit 8: No e2m record (0x100): while it is set and the drivetrain is not in top gear, cm848_calculateRoadSpeedGovernorFueling cuts to 0 / no limit at the reference speed and cm848_selectCruiseGovernorGainSet zeroes the droop delta; clear on this truck */
    uint16_t reserved_bit_9 : 1;  /* bit 9: no e2m record; no reader */
    uint16_t cruise_governor_droop_enable : 1;  /* bit 10: e2m Cruise_RSG_Droop_Enable (0x400); no reader in this build */
    uint16_t reserved_bit_11 : 1;  /* bit 11: no e2m record; no reader */
    uint16_t reserved_bit_12 : 1;  /* bit 12: e2m ANC_Fuel_Algorithm_Enable (0x1000); no reader (the ANC stage is compiled out) */
    uint16_t reserved_bit_13 : 1;  /* bit 13: e2m ANC_Timing_Algorithm_Enable (0x2000); no reader (the ANC stage is compiled out) */
    uint16_t reserved_bit_14 : 1;  /* bit 14: e2m ANC_Speed_Algorithm_Enable (0x4000); no reader (the ANC stage is compiled out) */
    uint16_t cruise_save_set_speed_at_power_down_enable : 1;  /* bit 15: e2m Cruise_Save_Set_Speed_On_Poweroff_Enable (0x8000): cm848_saveCruiseSetSpeedForPowerDown saves 0 while it is clear; clear on this truck */
};

struct algorithm_enable_flags_4_t {
    uint16_t user_commanded_fueling_enable : 1;  /* bit 0: e2m 106B +A User_Commanded_Fueling_Enable [FSUCFLEN] 'Bit 0 Word 4': cm848_selectUserCommandedFueling uses the user commanded fueling while it is set */
    uint16_t reserved_bit_1 : 1;  /* bit 1: no e2m name; no reader */
    uint16_t reserved_bit_2 : 1;  /* bit 2: no e2m name; no reader */
    uint16_t reserved_bit_3 : 1;  /* bit 3: no e2m name; no reader */
    uint16_t reserved_bit_4 : 1;  /* bit 4: no e2m name; no reader */
    uint16_t reserved_bit_5 : 1;  /* bit 5: no e2m name; no reader */
    uint16_t reserved_bit_6 : 1;  /* bit 6: no e2m name; no reader */
    uint16_t reserved_bit_7 : 1;  /* bit 7: no e2m name; no reader */
    uint16_t user_commanded_timing_enable : 1;  /* bit 8: e2m 106B +A User_Commanded_Timing_Enable [TSUCTAEN] 'Bit 8 of word 4': cm848_calculateFourDimensionalInjectionTiming takes user_commanded_injection_timing_cal as the 4D timing while it is set */
    uint16_t reserved_bit_9 : 1;  /* bit 9: no e2m name; no reader */
    uint16_t reserved_bit_10 : 1;  /* bit 10: no e2m name; no reader */
    uint16_t reserved_bit_11 : 1;  /* bit 11: no e2m name; no reader */
    uint16_t reserved_bit_12 : 1;  /* bit 12: no e2m name; no reader */
    uint16_t reserved_bit_13 : 1;  /* bit 13: no e2m name; no reader */
    uint16_t reserved_bit_14 : 1;  /* bit 14: no e2m name; no reader */
    uint16_t reserved_bit_15 : 1;  /* bit 15: no e2m name; no reader */
};

struct algorithm_enable_flags_11_t {
    uint16_t proprietary_communication_enable : 1;  /* bit 0: e2m Proprietary_Communication_Enable (0x1): 'parameter indicating whether datalink protocols are 'turned on''; no reader in this build; set on this truck */
    uint16_t j1587_communication_enable : 1;  /* bit 1: e2m J1587_Communication_Enable (0x2): '[JC87CZEA] bit 1 of 0-15 indicates whether J1587 communication is enabled'; no reader in this build; set on this truck */
    uint16_t j1922_communication_enable : 1;  /* bit 2: e2m J1922_Communication_Enable (0x4): '[JC22CZEA] bit 2 of 0-15 indicates whether J1922 communication is enabled'; no reader in this build; clear on this truck */
    uint16_t j1939_communication_enable : 1;  /* bit 3: e2m J1939_Communication_Enable (0x8): '[JC39CZEA] bit 3 of 0-15 indicates whether J1939 communication is enabled'; read by cm848_runJ1939PeriodicTransmitQueues, cm848_dispatchJ1939ReceivedMessages; set on this truck */
    uint16_t reserved_bit_4 : 1;  /* bit 4: no e2m record (0x10); no reader in this build; clear on this truck */
    uint16_t reserved_bit_5 : 1;  /* bit 5: no e2m record (0x20); no reader in this build; clear on this truck */
    uint16_t reserved_bit_6 : 1;  /* bit 6: no e2m record (0x40); no reader in this build; clear on this truck */
    uint16_t reserved_bit_7 : 1;  /* bit 7: no e2m record (0x80); no reader in this build; clear on this truck */
    uint16_t reserved_bit_8 : 1;  /* bit 8: no e2m record (0x100); no reader in this build; clear on this truck */
    uint16_t reserved_bit_9 : 1;  /* bit 9: no e2m record (0x200); no reader in this build; clear on this truck */
    uint16_t reserved_bit_10 : 1;  /* bit 10: no e2m record (0x400); no reader in this build; clear on this truck */
    uint16_t reserved_bit_11 : 1;  /* bit 11: no e2m record (0x800); no reader in this build; clear on this truck */
    uint16_t reserved_bit_12 : 1;  /* bit 12: no e2m record (0x1000); no reader in this build; clear on this truck */
    uint16_t reserved_bit_13 : 1;  /* bit 13: no e2m record (0x2000); no reader in this build; clear on this truck */
    uint16_t reserved_bit_14 : 1;  /* bit 14: no e2m record (0x4000); no reader in this build; clear on this truck */
    uint16_t reserved_bit_15 : 1;  /* bit 15: no e2m record (0x8000); no reader in this build; clear on this truck */
};

struct algorithm_enable_flags_1_t {
    uint16_t alpha_user_override_enable : 1;  /* bit 0: e2m Alpha_User_Override_Enable (0x1): '[APUOAPEN] Bit 0 Word 1. EEPROM indicator set by engr applications to control alpha'; read by calculateAlpha, cm848_temperatureBasedFuelTrim; calculateAlpha also reads it through its pointer to algorithm_enable_flags_0_cal; clear on this truck */
    uint16_t user_override_fueling_enable : 1;  /* bit 1: e2m User_Override_Fueling_Enable (0x2): '[FSUOFLEN] Bit 1 Word 1. Enable indicator for engineering fuel override command'; read by cm848_selectFinalFueling; clear on this truck */
    uint16_t test_cell_throttle_switch_override_enable : 1;  /* bit 2: e2m Test_Cell_Throttle_Switch_Override_Enable (0x4): '[CTTHSWOD] BIT 2 OF 0-15. (WORD 1:B2) TEST CELL USE - ENABLE OVERRIDES UNDEFINED SWITCH F'; read by cm848_fuelDemandBaseCalculation, cm848_fuelDemandCoordinator; clear on this truck */
    uint16_t user_override_timing_enable : 1;  /* bit 3: e2m User_Override_Timing_Enable (0x8): '[TSUOTAEN] Bit 3 Word 1. Indicator of which algorithm is in control of the o'ride tmg ena'; no reader in this build; clear on this truck */
    uint16_t torque_derate_override_enable : 1;  /* bit 4: e2m Torque_Derate_Override_Enable (0x10): '[FSTQUOEN] Bit 4 Word 1. Enable indicator for torque derate fuel override'; read by cm848_arbitrateRequestedFueling, cm848_j1939BuildEngineControlByte; clear on this truck */
    uint16_t altitude_derate_enable : 1;  /* bit 5: e2m Altitude_Derate_Enable (0x20): '[ATAGEN] Bit 5 of 0-15. Calibration trim used to enable the altitude derate algorithm'; read by cm848_calculateAltitudeDerateFuelLimit; set on this truck */
    uint16_t reserved_bit_6 : 1;  /* bit 6: no e2m record (0x40); no reader in this build; clear on this truck */
    uint16_t reserved_bit_7 : 1;  /* bit 7: no e2m record (0x80); no reader in this build; clear on this truck */
    uint16_t reserved_bit_8 : 1;  /* bit 8: no e2m record (0x100); no reader in this build; clear on this truck */
    uint16_t reserved_bit_9 : 1;  /* bit 9: no e2m record (0x200); no reader in this build; clear on this truck */
    uint16_t reserved_bit_10 : 1;  /* bit 10: no e2m record (0x400); no reader in this build; clear on this truck */
    uint16_t reserved_bit_11 : 1;  /* bit 11: no e2m record (0x800); no reader in this build; clear on this truck */
    uint16_t low_speed_governor_aggressive_gain_set_enable : 1;  /* bit 12: e2m LSG_Aggressive_Gain_Set_Enable (0x1000): '[LSAGGNEN] Low speed governor aggressive gain set enable.'; read by cm848_updateLowSpeedGovernorAggressiveGainLogic; set on this truck */
    uint16_t low_speed_governor_high_gear_gain_set_enable : 1;  /* bit 13: e2m LSG_High_Gear_Gain_Set_Enable (0x2000): '[LSHGGNEN] Enables the LSG gain set for when in high gears.'; read by cm848_selectLowSpeedGovernorGearGainSet; clear on this truck */
    uint16_t low_speed_governor_middle_gear_gain_set_enable : 1;  /* bit 14: e2m LSG_Mid_Gear_Gain_Set_Enable (0x4000): '[LSMGGNEN] Enable parameter for LSG gain set used when in middle gears'; read by cm848_selectLowSpeedGovernorGearGainSet; clear on this truck */
    uint16_t low_speed_governor_tsc1_gain_set_enable : 1;  /* bit 15: e2m LSG_Jcomm_Gain_Set_Enable (0x8000): '[LSJCGNEN] Enables/Disables the LSG Jcomm PID gains'; read by cm848_selectLowSpeedGovernorTsc1GainSet; clear on this truck */
};

struct algorithm_enable_flags_2_t {
    uint16_t engine_protection_shutdown_enable : 1;  /* bit 0: e2m Engine_Protection_Shutdown_Enable (0x1): '[EPSOEN] BIT 0 OF 0-15. ENABLE SHUTDOWN ALGORITHM.'; read by cm848_examineEngineProtectionBeforeCranking, cm848_updateEngineProtectionRestartSeverity, cm848_updateEngineProtectionShutdown; clear on this truck */
    uint16_t reserved_bit_1 : 1;  /* bit 1: no e2m record (0x2); no reader in this build; clear on this truck */
    uint16_t reserved_bit_2 : 1;  /* bit 2: no e2m record (0x4); no reader in this build; clear on this truck */
    uint16_t reserved_bit_3 : 1;  /* bit 3: no e2m record (0x8); no reader in this build; clear on this truck */
    uint16_t engine_protection_enable : 1;  /* bit 4: e2m Engine_Protection_Enable (0x10): '[EPEN] BIT 4 OF 0-15. ENGINE PROTECTION FEATURES ENABLE PARAMETER.'; read by cm848_runFaultDerateScheduler, cm848_examineEngineProtectionBeforeCranking; set on this truck */
    uint16_t engine_protection_restart_enable : 1;  /* bit 5: e2m Engine_Protection_Restart_Enable (0x20): '[EPRYEN] BIT 5 OF 0-15. ENABLE RESTART ALGORITHM.'; read by cm848_examineEngineProtectionBeforeCranking, cm848_updateEngineProtectionRestartSeverity; clear on this truck */
    uint16_t engine_retarder_clutch_deactivation_enable : 1;  /* bit 6: e2m EB_Clutch_Enable (0x40): '[EBCHDBEN] BIT 6 OF 0-15. CALIBRATION INDICATOR USED TO ENABLE ENGINE BRAKE DEACTIVATION'; read by cm848_updateEngineRetarderAllowedState; clear on this truck */
    uint16_t j1922_monitor_enable : 1;  /* bit 7: e2m J1922_Monitor_Enable (0x80): '[JC22MRSW] J1922 Monitor Enable 0 = disable monitor algorithm 1 = enable monitor algori'; no reader in this build; clear on this truck */
    uint16_t j1922_monitor_clear_enable : 1;  /* bit 8: e2m J1922_Monitor_Clear_Enable (0x100): '[JC22CCSW] Bit 1 of Bits 0:15 J1922 Monitor Clear Enable 0 = don't clear J1922 control fla'; no reader in this build; clear on this truck */
    uint16_t reserved_bit_9 : 1;  /* bit 9: no e2m record (0x200); no reader in this build; set on this truck */
    uint16_t reserved_bit_10 : 1;  /* bit 10: no e2m record (0x400); no reader in this build; set on this truck */
    uint16_t j1939_monitor_enable : 1;  /* bit 11: e2m J1939_Monitor_Enable (0x800): '[JC39MREA] J1939 Monitor Enable 0 = 1939 monitor algo. disabled 1 = 1939 monitor algo. en'; read by cm848_trackJ1939ControlSessions; set on this truck */
    uint16_t j1939_retarder_shift_assist_enable : 1;  /* bit 12: e2m J1939_Retarder_Shift_Assist_Enable (0x1000): '[JCRDTXEA] enable for speed control / engine braking interaction'; read by cm848_processEngineRetarderTsc1Request, cm848_endRetarderShiftAssistAboveFuelDemandLimit; set on this truck */
    uint16_t power_take_off_throttle_override_enable : 1;  /* bit 13: e2m PTO_Throttle_Override_Enable (0x2000): '[PTTHOVEN] Bit 13 of 0-15. Calibration indicator as to whether throttle depression disabl'; read by cm848_selectPowerTakeOffOrUserFueling; set on this truck */
    uint16_t user_commanded_timing_increment_enable : 1;  /* bit 14: e2m User_Commanded_Timing_Increment_Enable (0x4000): '[TSUCICEN] Bit 14 Word 2. Parameter used to enable the User Timing Increment'; read by cm848_calculateFourDimensionalInjectionTiming; clear on this truck */
    uint16_t zero_vehicle_speed_power_take_off_limit_enable : 1;  /* bit 15: e2m Zero_Vss_PTO_Limit_Enable (0x8000): '[ZVPTLMEN] Bit 15 Word 2 - Enable engine speed to be limited when in PTO mode'; no reader in this build; clear on this truck */
};

struct algorithm_enable_flags_5_t {
    uint16_t egr_fraction_user_override_enable : 1;  /* bit 0: e2m T_CBL_EGR_Frac_User_Override (0x1): 'Bit 0 of Word 6, EGR fraction user override in combustion manager'; read by cm848_selectEgrFractionCommand; clear on this truck */
    uint16_t combustion_fuel_command_user_override_enable : 1;  /* bit 1: e2m T_CBL_Fuel_User_Override (0x2): 'Bit 1 of Word 6, Fueling user override in before Advanced FS Control'; read by cm848_selectCombustionFuelCommand; clear on this truck */
    uint16_t mass_charge_flow_user_override_enable : 1;  /* bit 2: e2m T_CBL_MCF_User_Override (0x4): 'Bit 2 of Word 6, Mass charge flow user override on final output of comb mgr'; read by cm848_selectMassChargeFlowCommand; clear on this truck */
    uint16_t injection_timing_user_increment_enable : 1;  /* bit 3: e2m T_CBL_SOI_Increment_Enable (0x8): 'Bit 3 of Word 6, Enable use of C_CBL_SOI_Increment'; read by cm848_applyCombustionTimingLimits; clear on this truck */
    uint16_t injection_timing_main_base_user_override_enable : 1;  /* bit 4: e2m T_CBL_SOI_User_Override (0x10): 'Bit 4 of Word 6, SOI user override before Cranking or Advanced FS Control'; read by cm848_selectMainBaseTimingOverride; clear on this truck */
    uint16_t combustion_alpha_user_override_enable : 1;  /* bit 5: e2m T_CBR_Alpha_User_Override (0x20): 'Bit 5 of Word 6, Enables override of CBR_Alpha'; read by cm848_selectChiAndAlpha; clear on this truck */
    uint16_t combustion_chi_full_user_override_select : 1;  /* bit 6: e2m T_CBR_Chi_Selective_Override (0x40): 'Bit 6 of Word 6, 0:CBR_SINGLE_USER_OVERRIDE; 1:CBR_FULL_USER_OVERRIDE'; read by cm848_selectChiAndAlpha; set = the full user override (e2m CBR_FULL_USER_OVERRIDE), clear = the single one; clear on this truck */
    uint16_t combustion_chi_user_override_enable : 1;  /* bit 7: e2m T_CBR_Chi_User_Override (0x80): 'Bit 7 of Word 6, set chi = C_CBR_Chi_Override_..'s'; read by cm848_selectChiAndAlpha; clear on this truck */
    uint16_t combustion_egr_off_user_override_enable : 1;  /* bit 8: e2m T_CBR_EGR_Off_User_Override (0x100): 'Bit 8 of Word 6, Use C_CBR_EGR_Off_Override_Value'; read by cm848_selectChiAndAlpha; clear on this truck */
    uint16_t combustion_fuel_reference_user_override_enable : 1;  /* bit 9: e2m T_CBR_Fuel_Ref_User_Override (0x200): 'Bit 0 of Word 9, Fueling user override in combustion manager after OFC limit'; read by cm848_calculateCombustionFuelReference; clear on this truck */
    uint16_t combustion_gross_fuel_user_override_enable : 1;  /* bit 10: e2m T_CBR_Gross_Fuel_User_Override (0x400): 'Bit 10 of Word 6, Fueling user override in combustion manager before OFC limit'; read by cm848_calculateCombustionGrossFuel; clear on this truck */
    uint16_t oxygen_fuel_limit_equivalence_ratio_user_override_enable : 1;  /* bit 11: e2m T_OFC_Equiv_Ratio_User_Override (0x800): 'Bit 11 of Word 6, OFC equivalence ratio user override'; read by cm848_calculateOxygenFuelLimit; clear on this truck */
    uint16_t oxygen_fuel_limit_user_override_enable : 1;  /* bit 12: e2m T_OFC_Fuel_Limit_User_Override (0x1000): 'Bit 12 of Word 6, OFC fuel limit user override'; read by cm848_calculateOxygenFuelLimit; clear on this truck */
    uint16_t exhaust_pressure_estimate_enable : 1;  /* bit 13: e2m T_TPE_Exhaust_Press_Est_Enable (0x2000): 'Exhaust pressure estimate enable'; read by cm848_estimateExhaustPressure; clear on this truck */
    uint16_t charge_temperature_estimate_enable : 1;  /* bit 14: e2m T_Charge_Tmptr_Estimate_Enable (0x4000): 'Enables or Disables the charge temperature estimate algorithm'; read by cm848_estimateChargeTemperature, cm848_initializeChargeTemperatureEstimate; clear on this truck */
    uint16_t charge_pressure_estimation_enable : 1;  /* bit 15: e2m T_Charge_Press_Estimate_Enable (0x8000): 'Enables or disables charge pressure estimation'; read by cm848_estimateChargePressure; clear on this truck */
};

struct algorithm_enable_flags_6_t {
    uint16_t turbocharger_speed_estimate_enable : 1;  /* bit 0: e2m T_Turbo_Speed_Estimation_Enable (0x1): 'Bit 1 of Algorithm_Enables_Flags[6] enables feature'; read by cm848_estimateTurbochargerSpeed; set on this truck */
    uint16_t low_fuel_pressure_derate_enable : 1;  /* bit 1: e2m Low_Fuelpr_Derate_Enable (0x2): 'Enable for Low Fuel Pressure Derate Feature'; read by cm848_limitFuelQuantityOnRailPressureShortfall; set on this truck */
    uint16_t transmission_control_enable : 1;  /* bit 2: e2m RE_Trans_Enable (0x4): 'Bit 3 of Algorithm_Enables_Flags[6] enables feature'; read by cm848_updateTransmissionControlState, cm848_runTransmissionControlWhenEnabled, cm848_learnOutputSpeedToVehicleSpeedRatio, cm848_selectTransmissionTemperatureInUse, cm848_calculateTransmissionOutputSpeed, cm848_updateEngineRetarderAllowedState, cm848_processOverdriveSwitchAndShift, cm848_monitorConverterClutchAndOverdrivePerformance, cm848_calibrateGovernorPressureSensorOffset, cm848_controlGovernorPressureSolenoid; set on this truck */
    uint16_t second_gear_converter_lockup_enable : 1;  /* bit 3: e2m RE_2Lock_Enable (0x8): 'Algorithm enable for 2nd gear lockup strategy'; read by cm848_applyConverterLockupSchedule, cm848_applyConverterUnlockConditions, cm848_runTransmissionControl, cm848_determineCurrentGearAndLockupInhibit; set on this truck */
    uint16_t not_brake_switch_diagnostic_enable : 1;  /* bit 4: e2m Alt_Not_Brake_Switch_Enable (0x10): 'Alternate Brake switch diagnostics algorithm enable/disable'; read by cm848_deriveSecondBrakeSwitchSignal, cm848_monitorBrakeSwitchPairAgreement; set on this truck */
    uint16_t enhanced_diagnostics_enable : 1;  /* bit 5: e2m Enhanced_Diagnostics_Enable (0x20): 'Enhanced diagnostics enable flag.'; read by cm848_processSensorDeviationOnKeyoff; clear on this truck */
    uint16_t reserved_bit_6 : 1;  /* bit 6: no e2m record (0x40); no reader in this build; clear on this truck */
    uint16_t reserved_bit_7 : 1;  /* bit 7: no e2m record (0x80); no reader in this build; clear on this truck */
    uint16_t reserved_bit_8 : 1;  /* bit 8: no e2m record (0x100); no reader in this build; clear on this truck */
    uint16_t reserved_bit_9 : 1;  /* bit 9: no e2m record (0x200); no reader in this build; clear on this truck */
    uint16_t fan_air_conditioning_pressure_enable : 1;  /* bit 10: e2m Fan_AC_Pressure_Enable (0x400): '[FCAKAGEN] BIT 10 OF 0-15, allows pressure switch functionality'; no reader in this build; clear on this truck */
    uint16_t fan_air_conditioning_vehicle_speed_interaction_enable : 1;  /* bit 11: e2m Fan_AC_Vehicle_Speed_Interaction_Enable (0x800): '[FCAKVSEN] BIT 11 OF 0-15, Allows special AC pressure switch functionality'; no reader in this build; clear on this truck */
    uint16_t fan_clutch_2_enable : 1;  /* bit 12: e2m Fan_Clutch_2_Enable (0x1000): '[FC02EN] BIT 12 of 0-15 allows bus applications imt fan control'; no reader in this build; clear on this truck */
    uint16_t fan_engine_retarder_enable : 1;  /* bit 13: e2m Fan_EB_Enable (0x2000): '[FCEBAGEN] BIT 13 OF 0-15, allows engine brake functionality'; no reader in this build; clear on this truck */
    uint16_t fan_manual_input_enable : 1;  /* bit 14: e2m Fan_Manual_Input_Enable (0x4000): '[FCEN] BIT 14 OF 0-15, allows manual switch input functionality'; no reader in this build; clear on this truck */
    uint16_t cruise_engine_retarder_enable : 1;  /* bit 15: e2m Cruise_Brake_Enable (0x8000): '[CREBEN] BIT 5 OF 0-15. CRUISE BRAKE CONTROL ENABLE/DISABLE PARAMETER'; read by cm848_calculateEngineRetarderCruisePermissionPercent; set on this truck */
};

struct algorithm_enable_flags_13_t {
    uint16_t engine_retarder_switch_level_override : 1;  /* bit 0: e2m EB_Switch_Level_Override (0x1): '[ADEBLVOD] A/D override for Engine Brake switch level.'; read by cm848_j1939BuildEngineControlByte, cm848_calculateEngineRetarderSelectionPercent, cm848_processJ1939EngineRetarderSelection; clear on this truck */
    uint16_t driver_demand_torque_active_during_j1939_control : 1;  /* bit 1: e2m Active_Driver_Demand_With_Jcomm (0x2): 'Makes driver demand torque active durring JCOMM CONTROL mode msgs.'; no reader in this build; clear on this truck */
    uint16_t net_torque_derate_enable : 1;  /* bit 2: e2m Net_Torque_Derate_Enable (0x4): 'Enable for Net Torque Derate algorihm'; read by cm848_calculateNetTorqueFuelLimit, cm848_applyNetTorqueFuelLimit; set on this truck */
    uint16_t reserved_bit_3 : 1;  /* bit 3: no e2m record (0x8); no reader in this build; clear on this truck */
    uint16_t reserved_bit_4 : 1;  /* bit 4: no e2m record (0x10); no reader in this build; clear on this truck */
    uint16_t fuel_pressure_idle_diagnostic_enable : 1;  /* bit 5: e2m Fuel_Press_Idle_Diag_Enable (0x20): 'Enable for Fuel Pressure Idle Diagnostic'; read by cm848_runFuelPressureSensorPlausibilityMonitor; set on this truck */
    uint16_t reserved_bit_6 : 1;  /* bit 6: no e2m record (0x40); no reader in this build; clear on this truck */
    uint16_t reserved_bit_7 : 1;  /* bit 7: no e2m record (0x80); no reader in this build; clear on this truck */
    uint16_t reserved_bit_8 : 1;  /* bit 8: no e2m record (0x100); no reader in this build; clear on this truck */
    uint16_t reserved_bit_9 : 1;  /* bit 9: no e2m record (0x200); no reader in this build; clear on this truck */
    uint16_t reserved_bit_10 : 1;  /* bit 10: no e2m record (0x400); no reader in this build; clear on this truck */
    uint16_t reserved_bit_11 : 1;  /* bit 11: no e2m record (0x800); no reader in this build; clear on this truck */
    uint16_t reserved_bit_12 : 1;  /* bit 12: no e2m record (0x1000); no reader in this build; clear on this truck */
    uint16_t reserved_bit_13 : 1;  /* bit 13: no e2m record (0x2000); no reader in this build; clear on this truck */
    uint16_t reserved_bit_14 : 1;  /* bit 14: no e2m record (0x4000); no reader in this build; clear on this truck */
    uint16_t reserved_bit_15 : 1;  /* bit 15: no e2m record (0x8000); no reader in this build; clear on this truck */
};

struct algorithm_enable_flags_19_t {
    uint16_t alternate_curve_configuration_enable : 1;  /* bit 0: e2m Alternate_Curve_Configuration_Enable (0x1): '[FSALCFEN] Alternate Torque Curve Fueling Points enable flag, Bit 0 of word 0x13.'; no reader in this build; clear on this truck */
    uint16_t switched_rear_axle_anti_tamper_enable : 1;  /* bit 1: e2m Switched_Rear_Axle_Anti_Tamper_Enable (0x2): 'Enables reduction of RSG road speed limit to prevent tampering.'; no reader in this build; clear on this truck */
    uint16_t reserved_bit_2 : 1;  /* bit 2: no e2m record (0x4); no reader in this build; clear on this truck */
    uint16_t wastegate_monitor_enable : 1;  /* bit 3: e2m CWG_Monitor_Enable (0x8): 'Control wastegate enable flag'; read by cm848_monitorWastegateBoostPressure; set on this truck */
    uint16_t reserved_bit_4 : 1;  /* bit 4: no e2m record (0x10); no reader in this build; clear on this truck */
    uint16_t alpha_altitude_derate_override_enable : 1;  /* bit 5: e2m Alpha_Altitude_Derate_Override_Enable (0x20): 'Bit F Word 0. Enables altitude derate override logic in the alpha feature'; read by cm848_calculateAlphaAltitudeDerateLatch; calculateAlpha also reads it through its pointer to algorithm_enable_flags_0_cal; clear on this truck */
    uint16_t egr_condensation_algorithm_enable : 1;  /* bit 6: e2m EGR_Condensation_Algorithm_Enable (0x40): 'enable flag for EGR Condesnation prediction algorithm'; no reader in this build; clear on this truck */
    uint16_t compressor_outlet_temperature_estimate_enable : 1;  /* bit 7: e2m COT_Estimation_Enable (0x80): 'ENABLE/DISABLE compressor outlet temperature estimation.' (the e2m also names this enable T_TPE_COT_Estimation_Enable); read by cm848_selectCompressorOutletTemperature; set on this truck */
    uint16_t service_brake_prevents_idle_shutdown_enable : 1;  /* bit 8: e2m IS_Brake_On_Prevent_Shutdown_Enable (0x100): 'Enables depressed serv. brake to prevent idle shutdow'; no reader in this build; clear on this truck */
    uint16_t condensation_protection_enable : 1;  /* bit 9: e2m T_EMO_Condensation_AECD_Enable (0x200): 'Condensation AECD Enable engineering trim' (the reader rules out the other record on this bit, ESP_Smart_Torque_Enable); read by cm848_updateCondensationProtection; clear on this truck */
    uint16_t reserved_bit_10 : 1;  /* bit 10: e2m T_VGA_Swingvane_Enable (0x400): 'Enable for Swingvane VG Manager'; no reader in this build; set on this truck */
    uint16_t reserved_bit_11 : 1;  /* bit 11: no e2m record (0x800); no reader in this build; clear on this truck */
    uint16_t combustion_manager_bypass : 1;  /* bit 12: e2m T_Bypass_Combustion_Mgr (0x1000): 'Flag to bypass combustion mgr and use old Core fueling/timing algorithms'; no reader in this build; clear on this truck */
    uint16_t egr_cooler_fouling_diagnostic_enable : 1;  /* bit 13: e2m T_EGR_Cooler_Fouling_Enable (0x2000): 'Enables EGR cooler fouling diagnostic algorithm' (the reader rules out the other record on this bit, T_VGT_Pneumatic_Control_Enable); read by cm848_updateEgrCoolerFoulingFaultCounter; clear on this truck */
    uint16_t charge_manager_open_loop_egr_table_active : 1;  /* bit 14: e2m T_EAC_EGR_Table_Active (0x4000): 'Establishes whether Charge Manager uses open loop EGR position table'; no reader in this build; clear on this truck */
    uint16_t charge_manager_virtual_sensors_active : 1;  /* bit 15: e2m T_CSE_Virtual_Sensor_Active (0x8000): 'Establishes whether Charge Manager uses virtual feedback sensors'; no reader in this build; set on this truck */
};

struct algorithm_enable_flags_20_t {
    uint16_t reserved_bit_0 : 1;  /* bit 0: e2m T_CSE_Delta_P_Only_Mode (0x1): 'Selects denominator in CSE_Delta_P_Over_P'; no reader in this build; clear on this truck */
    uint16_t reserved_bit_1 : 1;  /* bit 1: no e2m record (0x2); no reader in this build; clear on this truck */
    uint16_t reserved_bit_2 : 1;  /* bit 2: no e2m record (0x4); no reader in this build; clear on this truck */
    uint16_t reserved_bit_3 : 1;  /* bit 3: no e2m record (0x8); no reader in this build; clear on this truck */
    uint16_t reserved_bit_4 : 1;  /* bit 4: no e2m record (0x10); no reader in this build; clear on this truck */
    uint16_t reserved_bit_5 : 1;  /* bit 5: no e2m record (0x20); no reader in this build; clear on this truck */
    uint16_t reserved_bit_6 : 1;  /* bit 6: no e2m record (0x40); no reader in this build; clear on this truck */
    uint16_t reserved_bit_7 : 1;  /* bit 7: no e2m record (0x80); no reader in this build; clear on this truck */
    uint16_t air_handling_system_protection_enable : 1;  /* bit 8: e2m T_EMO_Air_Handling_AECD_Enable (0x100): 'Air Handling System Protection AECD enabler'; read by cm848_updateAirHandlingSystemProtection; set on this truck */
    uint16_t extreme_ambient_overheat_protection_enable : 1;  /* bit 9: e2m T_EMO_Extreme_Amb_AECD_Enable (0x200): 'Extreme ambient AECD Enable trim'; read by cm848_updateExtremeAmbientOverheatProtection; clear on this truck */
    uint16_t white_smoke_and_misfire_protection_enable : 1;  /* bit 10: e2m T_EMO_White_Smoke_AECD_Enable (0x400): 'White Smoke and Misfire Protection AECD enable trim'; read by cm848_updateWhiteSmokeAndMisfireProtection; clear on this truck */
    uint16_t extended_idle_protection_enable : 1;  /* bit 11: e2m T_EMO_Extended_Idle_AECD_Enable (0x800): 'Extended Idle and PTO Protection enable trim'; read by cm848_updateExtendedIdleProtection; clear on this truck */
    uint16_t engine_start_warmup_protection_enable : 1;  /* bit 12: e2m T_EMO_Engine_Start_AECD_Enable (0x1000): 'Engine Starting and Warmup Protection AECD enable trim'; read by cm848_updateEngineStartWarmupProtection; clear on this truck */
    uint16_t reserved_bit_13 : 1;  /* bit 13: no e2m record (0x2000); no reader in this build; clear on this truck */
    uint16_t intake_manifold_temperature_lead_compensation_enable : 1;  /* bit 14: e2m T_INM_ICT_Lead_Enable (0x4000): 'Enable bit for the lead compensator'; read by cm848_filterAndSelectIntakeManifoldTemperature; clear on this truck */
    uint16_t egr_orifice_temperature_lead_compensation_enable : 1;  /* bit 15: e2m T_INM_EGRT_Lead_Enable (0x8000): 'Enables EGR orifice temperature lead compensation algorithm'; read by cm848_filterEgrOrificeTemperature; clear on this truck */
};

struct algorithm_enable_flags_21_t {
    uint16_t reserved_bit_0 : 1;  /* bit 0: no e2m record (0x1); no reader in this build; clear on this truck */
    uint16_t reserved_bit_1 : 1;  /* bit 1: no e2m record (0x2); no reader in this build; clear on this truck */
    uint16_t h_bridge_asic_diagnostic_enable : 1;  /* bit 2: e2m TVA_ASIC_Diagnostic_Enable (0x4): 'Enables ASIC based H-bridge diagnostics'; no reader in this build; clear on this truck */
    uint16_t turbocharger_speed_limiter_enable : 1;  /* bit 3: e2m Trbo_Spd_Limiter_Enable (0x8): 'Trbo Spd Limiter Algorithm Enable'; read by cm848_updateTurbochargerSpeedLimiter; set on this truck */
    uint16_t charge_pressure_in_range_diagnostic_enable : 1;  /* bit 4: e2m T_Charge_Press_IR_Enable (0x10): 'Enable for the charge pressure in range.'; read by cm848_updateChargePressureInRangeFaultCount; clear on this truck */
    uint16_t turbocharger_speed_in_range_diagnostic_enable : 1;  /* bit 5: e2m T_Turbo_Speed_IR_Enable (0x20): 'Trim parameter to enable/disable turbospd sensor in-range'; no reader in this build; clear on this truck */
    uint16_t general_engine_protection_enable : 1;  /* bit 6: e2m T_EMO_Gen_Protect_AECD_Enable (0x40): 'General Engine Protection AECD Enable trim'; read by cm848_updateGeneralEngineProtection; clear on this truck */
    uint16_t reserved_bit_7 : 1;  /* bit 7: no e2m record (0x80); no reader in this build; clear on this truck */
    uint16_t reserved_bit_8 : 1;  /* bit 8: no e2m record (0x100); no reader in this build; clear on this truck */
    uint16_t air_conditioning_anti_slugging_start_enable : 1;  /* bit 9: e2m AC_Anti_Slugging_Start_Enable (0x200): 'Enable for initial ac anti slugging flag status'; no reader in this build; clear on this truck */
    uint16_t deicer_speed_limit_enable : 1;  /* bit 10: e2m T_Deicer_Speed_Limit_Enable (0x400): 'RSG Deicer Function Enable word 15h, bit 10 of 0 to 15'; no reader in this build; clear on this truck */
    uint16_t reserved_bit_11 : 1;  /* bit 11: no e2m record (0x800); no reader in this build; clear on this truck */
    uint16_t reserved_bit_12 : 1;  /* bit 12: no e2m record (0x1000); no reader in this build; clear on this truck */
    uint16_t reserved_bit_13 : 1;  /* bit 13: no e2m record (0x2000); no reader in this build; clear on this truck */
    uint16_t reserved_bit_14 : 1;  /* bit 14: no e2m record (0x4000); no reader in this build; clear on this truck */
    uint16_t reserved_bit_15 : 1;  /* bit 15: no e2m record (0x8000); read by calculateAlpha; calculateAlpha takes alpha source 5 while it is set and electronic_smart_power_tau is 0x4000; kept reserved (its meaning beyond that is unknown); clear on this truck */
};

struct algorithm_enable_flags_25_t {
    uint16_t engine_retarder_rate_limit_defeat_enable : 1;  /* bit 0: e2m EB_Rate_Limit_Defeat_Enable (0x1): '[EBRTDFEN] Bit 0 of 0-15 - Enable brake Rate Limit defeat during on/off trans.'; read by cm848_updateEngineRetarderAllowedState; clear on this truck */
    uint16_t powertrain_protection_enable : 1;  /* bit 1: e2m PTP_Enable (0x2): '[TCEN] Powertrain Protection Enable Word 19h, bit 1 of 0 to 15'; no reader in this build; clear on this truck */
    uint16_t powertrain_protection_lugback_enable : 1;  /* bit 2: e2m PTP_Lugback_Enable (0x4): '[TCLDEN] Powertrain Protection Lugback Enable Word 19h, bit 2 of 0 to 15'; no reader in this build; clear on this truck */
    uint16_t j1939_multiplex_limp_home_on_analog_throttle_enable : 1;  /* bit 3: e2m J1939_Mux_Limphome_On_AD_Enable (0x8): '[MXLPANEA] Bit 3 Enabled indicates limphome via MUXing shall use Raw Sampled Throttle.'; read by cm848_updateIdleSwitchesFromLocalInputs; clear on this truck */
    uint16_t reserved_bit_4 : 1;  /* bit 4: no e2m record (0x10); no reader in this build; clear on this truck */
    uint16_t smart_road_speed_governor_enable : 1;  /* bit 5: e2m SR_Enable (0x20): '[SREN] Smart RSG Enable word 19h, bit 5 of 0 to 15'; no reader in this build; clear on this truck */
    uint16_t fan_clutch_1_air_conditioning_enable : 1;  /* bit 6: e2m Fan_Clutch_1_AC_Enable (0x40): '[FCAKINEN] AC Input Enable, Bit 6 of Word 19h'; no reader in this build; clear on this truck */
    uint16_t fan_clutch_1_coolant_temperature_enable : 1;  /* bit 7: e2m Fan_Clutch_1_Coolant_Enable (0x80): '[FCCLINEN] CT Input Enable, Bit 7 of Word 19h'; no reader in this build; clear on this truck */
    uint16_t fan_clutch_1_intake_manifold_temperature_enable : 1;  /* bit 8: e2m Fan_Clutch_1_IMT_Enable (0x100): '[FCIMINEN] IMT Input Enable, Bit 8 of Word 19h'; no reader in this build; clear on this truck */
    uint16_t fan_clutch_2_air_conditioning_enable : 1;  /* bit 9: e2m Fan_Clutch_2_AC_Enable (0x200): '[FCAKI2EN] AC Input Enable, Bit 9 of Word 19h'; no reader in this build; clear on this truck */
    uint16_t fan_clutch_2_air_conditioning_pressure_enable : 1;  /* bit 10: e2m Fan_Clutch_2_AC_Pressure_Enable (0x400): '[FCAK02EN] AC Switch Enable, Bit 10 of Word 19h'; no reader in this build; clear on this truck */
    uint16_t fan_clutch_2_coolant_temperature_enable : 1;  /* bit 11: e2m Fan_Clutch_2_Coolant_Enable (0x800): '[FCCLI2EN] CT Input Enable, Bit 11 of Word 19h'; no reader in this build; clear on this truck */
    uint16_t fan_clutch_2_engine_retarder_enable : 1;  /* bit 12: e2m Fan_Clutch_2_EB_Enable (0x1000): '[FCEBINEN] Fan_Clutch_2_EB_Enable, Bit 12 of Word 19h'; no reader in this build; clear on this truck */
    uint16_t fan_clutch_2_intake_manifold_temperature_enable : 1;  /* bit 13: e2m Fan_Clutch_2_IMT_Enable (0x2000): '[FCIMI2EN] IMT Input Enable, Bit 13 of Word 19h'; no reader in this build; clear on this truck */
    uint16_t fan_clutch_2_manual_input_enable : 1;  /* bit 14: e2m Fan_Clutch_2_Manual_Input_Enable (0x4000): '[FCSW02EN] Fan_Clutch_2_Manual_Input_Enable, Bit 14 of Word 19h'; no reader in this build; clear on this truck */
    uint16_t manual_fan_level_override : 1;  /* bit 15: e2m Manual_Fan_Level_Override (0x8000): '[ADMNFMOD] A/D Override for Manual Fan Level (Requested % fan Speed)'; read by cm848_processJ1939EngineFanRequestedSpeed; clear on this truck */
};

struct algorithm_enable_flags_27_t {
    uint16_t reserved_bit_0 : 1;  /* bit 0: no e2m record (0x1); no reader in this build; clear on this truck */
    uint16_t reserved_bit_1 : 1;  /* bit 1: e2m Cruise_Use_Min_Fuel_Ramp_OOG_Enable (0x2): '[CRMFOGEA] If enabled, uses cc/rsg min fuel transtion ramp during OOG'; no reader in this build; clear on this truck */
    uint16_t engine_retarder_fuel_to_brake_delay_enable : 1;  /* bit 2: e2m EB_Fuel_to_Brake_Delay_Enable (0x4): '[EBAEDYEN] 0 = do not delay on e-brake transition, 1 = delay on e-brake transition'; read by cm848_updateEngineRetarderActiveState; clear on this truck */
    uint16_t switched_throttle_control_governor_select : 1;  /* bit 3: e2m STCG_ASG_Droop_Select (0x8): '[STCGASDS] Switched Throttle Control Governor select (bit 3, 0 - 15) 0=ASG_DROOP, 1=STCG'; read by cm848_blendAllSpeedGovernorReferenceSpeeds, cm848_updateVariableSpeedGovernorSelection; set = the switched throttle control governor, clear = the all speed governor droop (e2m 08=STCG:00=ASGDROOP); clear on this truck */
    uint16_t boost_pressure_in_range_diagnostic_enable : 1;  /* bit 4: e2m Boost_In_Range_Enable (0x10): '[DGBSIREN] Enable flag for boost pressure in-range diagnostic algorithm'; read by cm848_monitorBoostPressureSensorAndUnderboost; set on this truck */
    uint16_t air_handling_enable : 1;  /* bit 5: e2m AH_Enable (0x20): '[AHEN] Bit 5 ENABLE/DISABLE for Air Handeling feature. Bit 11 of 0-15'; no reader in this build; clear on this truck */
    uint16_t air_mass_calculation_enable : 1;  /* bit 6: e2m TB_Airmass_Enable (0x40): '[TBAMEN] Bit 6 Enable/Disable for Airmass calculation. Bit 12 of 0-15'; no reader in this build; clear on this truck */
    uint16_t turbine_speed_and_temperature_calculation_enable : 1;  /* bit 7: e2m TB_Speed_Temp_Enable (0x80): '[TBSPTMEN] Bit 7 Enable/Disable Turbin Speed /Temp. calc. Bit 13 of 0-15'; no reader in this build; clear on this truck */
    uint16_t four_step_wastegate_control_enable : 1;  /* bit 8: e2m TU_WG_Enable (0x100): '[TUWGEN] Enable/Disable for 4 Step WG control. Bit8 15 of 0-15'; no reader in this build; clear on this truck */
    uint16_t wastegate_tool_override_enable : 1;  /* bit 9: e2m TU_WG_Tool_Override_Enable (0x200): '[TUWGOVEN] Bit9 Enable/Disable for tool override of wastegates. Bit 14 of 0-15'; no reader in this build; clear on this truck */
    uint16_t idle_shutdown_temperature_enable : 1;  /* bit 10: e2m Idle_Shutdown_Temperature_Enable (0x400): '[ISAATPEN] bit 10 of 15.selects the temp. interaction option for Idle Shutdown'; no reader in this build; clear on this truck */
    uint16_t anti_theft_enable : 1;  /* bit 11: e2m AT_AUTO_Anti_Theft_Enable (0x800): '[AT01EN] Bit 11 of 15. Enables the anti theft at_auto module'; read by j1939_receivePgn56576Handler, cm848_sendPgn56320AntiTheftStatus; clear on this truck */
    uint16_t anti_theft_automatic_lock_enable : 1;  /* bit 12: e2m Anti_Theft_Auto_Lock_Enable (0x1000): '[ATAULOEN] Bit 12 of 15. Enables the automatic locking functionality'; no reader in this build; clear on this truck */
    uint16_t road_speed_governor_reference_speed_ramp_enable : 1;  /* bit 13: e2m SR_Ramp_Enable (0x2000): '[SRRMEN] If enabled, RSG ref speed is allowed to ramp'; no reader in this build; clear on this truck */
    uint16_t reserved_bit_14 : 1;  /* bit 14: no e2m record (0x4000); no reader in this build; clear on this truck */
    uint16_t reserved_bit_15 : 1;  /* bit 15: no e2m record (0x8000); no reader in this build; clear on this truck */
};

struct algorithm_enable_flags_28_t {
    uint16_t reserved_bit_0 : 1;  /* bit 0: no e2m record (0x1); no reader in this build; clear on this truck */
    uint16_t reserved_bit_1 : 1;  /* bit 1: no e2m record (0x2); no reader in this build; clear on this truck */
    uint16_t reserved_bit_2 : 1;  /* bit 2: no e2m record (0x4); no reader in this build; clear on this truck */
    uint16_t keyless_restart_enable : 1;  /* bit 3: e2m ES_Keyless_Restart (0x8): '[ESNKASEN] Allows engine to run while keyswitch is off.'; no reader in this build; clear on this truck */
    uint16_t reserved_bit_4 : 1;  /* bit 4: no e2m record (0x10); no reader in this build; clear on this truck */
    uint16_t alarm_during_automatic_start_enable : 1;  /* bit 5: e2m ES_Alarm_During_Autostart_Enable (0x20): '[ESALASEN] Enables Alarm sounding for auto-start Keyswitch on.'; no reader in this build; clear on this truck */
    uint16_t reserved_bit_6 : 1;  /* bit 6: no e2m record (0x40); no reader in this build; clear on this truck */
    uint16_t starter_lockout_enable : 1;  /* bit 7: e2m SL_Enable (0x80): '[STLOCKEN] Enables Starter Lockout feature (exclusive of ISTAEN).'; no reader in this build; clear on this truck */
    uint16_t wastegate_table_control_enable : 1;  /* bit 8: e2m TU_WG_Table_Control_Enable (0x100): '[TCWGTCEN] Enable/Disable direct table control of WG.'; no reader in this build; clear on this truck */
    uint16_t reserved_bit_9 : 1;  /* bit 9: no e2m record (0x200); no reader in this build; clear on this truck */
    uint16_t j1939_multiplex_enable : 1;  /* bit 10: e2m J1939_Multiplex_Enable (0x400): '[JC39MXEA] bit 10 of 0-15, enables or disables multiplex processing'; read by cm848_processJ1939SwitchAndRequestInputs, cm848_processJ1939AcceleratorInputs, cm848_tickJ1939InputSupervision; clear on this truck */
    uint16_t reserved_bit_11 : 1;  /* bit 11: no e2m record (0x800); no reader in this build; clear on this truck */
    uint16_t anti_theft_random_number_generator_enable : 1;  /* bit 12: e2m AT_Random_Number_Generator_Enable (0x1000): '[ATRNGNEN] enable for generation of random numbers (for VAT)'; no reader in this build; clear on this truck */
    uint16_t starter_lockout_normally_open_contact_enable : 1;  /* bit 13: e2m SL_NO_Contact_Enable (0x2000): '[SLNOCTEN] Enables Normally Open contacts for SL Relay, Relay failures will disable missio'; no reader in this build; clear on this truck */
    uint16_t reserved_bit_14 : 1;  /* bit 14: no e2m record (0x4000); no reader in this build; clear on this truck */
    uint16_t reserved_bit_15 : 1;  /* bit 15: e2m LSG_QPID_Inhibit_Enable (0x8000): '[LSQAIHEN] When enabled LSG QPID is inhibited for middle and high gear'; no reader in this build; clear on this truck */
};

struct algorithm_enable_flags_29_t {
    uint16_t reserved_bit_0 : 1;  /* bit 0: e2m SS_Ambient_Adv_Enable (0x1): '[SSAADQEN] Calibration trim used to enable the SS Ambient Advance algorithm'; read by cm848_buildPgn65269AmbientConditionsMessage; read by cm848_buildPgn65269AmbientConditionsMessage: the ambient air temperature bytes are sent only while bits 0 and 1 are both set (else 0xFFFF); 'SS' is not spelled out anywhere, so it stays reserved; clear on this truck */
    uint16_t reserved_bit_1 : 1;  /* bit 1: e2m SS_Ambient_Derate_Enable (0x2): '[SSADDQEN] Calibration trim used to enable the SS Ambient Fueling Derate'; read by cm848_buildPgn65269AmbientConditionsMessage; read by cm848_buildPgn65269AmbientConditionsMessage with bit 0 (see bit 0); 'SS' is not spelled out anywhere, so it stays reserved; clear on this truck */
    uint16_t reserved_bit_2 : 1;  /* bit 2: e2m Trans_Clt_Rtrd_Enable (0x4): '[TSCQTAEN] Calibration trim used to enable the Coolant Temp Retard algorithm'; no reader in this build; clear on this truck */
    uint16_t reserved_bit_3 : 1;  /* bit 3: e2m Trans_Clt_Derate_Enable (0x8): '[TSCQDQEN] Calibration trim used to enable the Coolant Temp Derate algorithm'; no reader in this build; clear on this truck */
    uint16_t air_handling_direct_derate_enable : 1;  /* bit 4: e2m AH_Direct_Derate_Enable (0x10): '[AHDRLAEN] ENABLE/DISABLE turbo protection latched fuel derate'; no reader in this build; clear on this truck */
    uint16_t trip_reset_enable : 1;  /* bit 5: e2m Trip_Reset_Enable (0x20): '[TRPRSTEN] Enable/Disable trip information reset asked from reset PGN'; read by cm848_j1939HandlePgn56832Reset; clear on this truck */
    uint16_t service_component_reset_enable : 1;  /* bit 6: e2m Service_Component_Reset_Enable (0x40): '[SRCRSTEN] Enable/Disable service component reset asked from reset PGN'; read by cm848_j1939HandlePgn56832Reset; clear on this truck */
    uint16_t tire_wear_adjustment_enable : 1;  /* bit 7: e2m TW_Enable (0x80): '[TWEN] Tire Wear Adjustment Enable'; no reader in this build; clear on this truck */
    uint16_t dm13_enable : 1;  /* bit 8: e2m DM13_Enable (0x100): '[DM13EN] Algorithm enable flag for DM13'; read by cm848_processJ1939Dm13StopStartBroadcast, cm848_dispatchJ1939ReceivedMessages; clear on this truck */
    uint16_t engine_protection_shutdown_override_enable : 1;  /* bit 9: e2m EPF_Shutdown_Override_Enable (0x200): '[EPSOOVEN] Algorithm enable for EPS shutdown override'; read by cm848_detectEngineProtectionShutdownOverrideRequest; clear on this truck */
    uint16_t throttle_activated_diagnostic_switch_enable : 1;  /* bit 10: e2m Throttle_Diagnostic_Switch_Enable (0x400): '[THDGSWEN] ENABLE/DISABLE parameter for the Throttle Activated Diagnostic Switch feature'; read by cm848_updateSwitch31FromAcceleratorPedal, cm848_checkSwitch31OnTimeFault; clear on this truck */
    uint16_t throttle_related_error_handler_enable : 1;  /* bit 11: e2m Throttle_Related_Error_Handler_Enable (0x800): '[THDGEREN] Enable/Disable parameter, which defines how to handle throttle errors'; read by cm848_checkAcceleratorPedalSensorFaults; clear on this truck */
    uint16_t fuel_delivery_pressure_broadcast_enable : 1;  /* bit 12: no e2m record (0x1000); read by cm848_buildPgn65263EngineFluidLevelPressure1Message; cm848_buildPgn65263EngineFluidLevelPressure1Message sends the fuel delivery pressure byte only while it is set (else 0xFF); clear on this truck */
    uint16_t reserved_bit_13 : 1;  /* bit 13: no e2m record (0x2000); no reader in this build; clear on this truck */
    uint16_t reserved_bit_14 : 1;  /* bit 14: no e2m record (0x4000); no reader in this build; clear on this truck */
    uint16_t variable_speed_fan_logic_enable : 1;  /* bit 15: e2m Fan_Clutch_Variable_Speed_Fan_Logic_Enable (0x8000): 'Flag which allows variable speed fan logic to execute'; no reader in this build; clear on this truck */
};

struct algorithm_enable_flags_31_t {
    uint16_t hybrid_governor_enable : 1;  /* bit 0: e2m Hybrid_Governor_Enable (0x1): 'Hybrid Governor Enable - Bit 0 of 0-15 in word 31'; read by cm848_calculateFuelLimitByRpmAndDemand, cm848_applyFuelLimitByRpmAndDemand; set on this truck */
    uint16_t reserved_bit_1 : 1;  /* bit 1: no e2m record (0x2); no reader in this build; clear on this truck */
    uint16_t reserved_bit_2 : 1;  /* bit 2: no e2m record (0x4); no reader in this build; clear on this truck */
    uint16_t reserved_bit_3 : 1;  /* bit 3: no e2m record (0x8); no reader in this build; clear on this truck */
    uint16_t reserved_bit_4 : 1;  /* bit 4: no e2m record (0x10); no reader in this build; clear on this truck */
    uint16_t reserved_bit_5 : 1;  /* bit 5: no e2m record (0x20); no reader in this build; clear on this truck */
    uint16_t reserved_bit_6 : 1;  /* bit 6: no e2m record (0x40); no reader in this build; clear on this truck */
    uint16_t reserved_bit_7 : 1;  /* bit 7: no e2m record (0x80); no reader in this build; clear on this truck */
    uint16_t reserved_bit_8 : 1;  /* bit 8: no e2m record (0x100); no reader in this build; clear on this truck */
    uint16_t reserved_bit_9 : 1;  /* bit 9: no e2m record (0x200); no reader in this build; clear on this truck */
    uint16_t reserved_bit_10 : 1;  /* bit 10: no e2m record (0x400); no reader in this build; clear on this truck */
    uint16_t reserved_bit_11 : 1;  /* bit 11: no e2m record (0x800); no reader in this build; clear on this truck */
    uint16_t reserved_bit_12 : 1;  /* bit 12: no e2m record (0x1000); no reader in this build; clear on this truck */
    uint16_t reserved_bit_13 : 1;  /* bit 13: no e2m record (0x2000); no reader in this build; clear on this truck */
    uint16_t reserved_bit_14 : 1;  /* bit 14: no e2m record (0x4000); no reader in this build; clear on this truck */
    uint16_t reserved_bit_15 : 1;  /* bit 15: no e2m record (0x8000); no reader in this build; clear on this truck */
};

struct algorithm_enable_flags_32_t {
    uint16_t intake_air_heater_control_enable : 1;  /* bit 0: e2m IAH_Control_Enable (0x1): 'Intake Air Heater Control Algorithm Enable'; read by cm848_updateIntakeAirHeaterControl, cm848_updateIntakeAirHeaterAmbientTemperature; set on this truck */
    uint16_t end_of_injection_limit_enable : 1;  /* bit 1: e2m EOI_Limit_Algorithm_Enable (0x2): 'Algorithm enable calibration for eoi_limit'; read by engine_injectionAngle_tpuUpdate; set on this truck */
    uint16_t equivalent_throttle_enable : 1;  /* bit 2: e2m Equivalent_Throttle_Enable (0x4): 'Equivalent_Throttle Algorithm Enable'; read by cm848_calculateAllSpeedGovernorEquivalentThrottle; the e2m record's mask is 7 but its value list says 0=DISABLE:4=ENABLE; the code tests 4; set on this truck */
    uint16_t reserved_bit_3 : 1;  /* bit 3: no e2m record (0x8); no reader in this build; clear on this truck */
    uint16_t intake_air_heater_24_volt_enable : 1;  /* bit 4: e2m IAH_24V_Enable (0x10): 'Intake Air Heater 24V Control Algorithm Enable'; read by cm848_initIntakeAirHeaterControl, cm848_computeIntakeAirHeaterPreheatDuration, cm848_countDownIntakeAirHeaterPreheat, cm848_pulseIntakeAirHeaterRelays, cm848_shutdownIntakeAirHeater, cm848_updateIntakeAirHeaterPostheat, cm848_updateIntakeAirHeaterControl; clear on this truck */
    uint16_t reserved_bit_5 : 1;  /* bit 5: no e2m record (0x20); no reader in this build; clear on this truck */
    uint16_t reserved_bit_6 : 1;  /* bit 6: no e2m record (0x40); no reader in this build; clear on this truck */
    uint16_t reserved_bit_7 : 1;  /* bit 7: no e2m record (0x80); no reader in this build; clear on this truck */
    uint16_t reserved_bit_8 : 1;  /* bit 8: no e2m record (0x100); no reader in this build; clear on this truck */
    uint16_t reserved_bit_9 : 1;  /* bit 9: no e2m record (0x200); no reader in this build; clear on this truck */
    uint16_t reserved_bit_10 : 1;  /* bit 10: no e2m record (0x400); no reader in this build; clear on this truck */
    uint16_t reserved_bit_11 : 1;  /* bit 11: no e2m record (0x800); no reader in this build; clear on this truck */
    uint16_t reserved_bit_12 : 1;  /* bit 12: no e2m record (0x1000); no reader in this build; clear on this truck */
    uint16_t reserved_bit_13 : 1;  /* bit 13: no e2m record (0x2000); no reader in this build; clear on this truck */
    uint16_t reserved_bit_14 : 1;  /* bit 14: no e2m record (0x4000); no reader in this build; clear on this truck */
    uint16_t reserved_bit_15 : 1;  /* bit 15: no e2m record (0x8000); no reader in this build; clear on this truck */
};

struct algorithm_enable_flags_40_t {
    uint16_t electronic_voltage_regulator_enable : 1;  /* bit 0: e2m EVR_Enable (0x1): 'Electronic Voltage Regulation algorithm enable'; read by cm848_calculateChargingVoltageTarget, cm848_calculateChargingVoltageError, cm848_updateAlternatorFieldRegulatorState, cm848_calculateAlternatorFieldDutyByRegulatorState, cm848_applyAlternatorFieldDuty; set on this truck */
    uint16_t coolant_temperature_derate_enable : 1;  /* bit 1: e2m CT_Derate_Enable (0x2): 'Coolant Temp Derate; algorithm enable'; read by cm848_runCoolantOverheatFuelDerate; set on this truck */
    uint16_t engine_oil_pressure_processing_enable : 1;  /* bit 2: e2m OPG_Enable (0x4): 'Enable bit for Low Oil Pressure algorithm'; read by cm848_buildPciTransmitMessage14VoltageOilPressureTemperatures, cm848_processEngineOilPressure; set on this truck */
    uint16_t air_conditioning_control_enable : 1;  /* bit 3: e2m AC_Control_Enable (0x8): 'Enables AC control'; read by cm848_controlAirConditioningClutchForBrTruck, cm848_controlAirConditioningClutchForDrTruck; set on this truck */
    uint16_t reserved_bit_4 : 1;  /* bit 4: no e2m record (0x10); no reader in this build; clear on this truck */
    uint16_t fuel_level_processing_enable : 1;  /* bit 5: e2m Fuel_Lvl_Process_Enable (0x20): 'Disable=use CORE A/D for bus msg.Enabled=fuel level alg to determine bus msg'; read by cm848_qualifyFuelLevelSample; set on this truck */
    uint16_t j1850_communication_enable : 1;  /* bit 6: e2m J1850_Communication_Enable (0x40): 'J1850 Total Network Enable setting Enable=1=Network is ACTIVE'; read by cm848_checkPciMessageTimeouts, cm848_onPciControllerInterrupt, cm848_servicePciTransmit, cm848_schedulePciTransmit, cm848_runPciMessageHandlers; set on this truck */
    uint16_t ambient_air_pressure_monitor_enable : 1;  /* bit 7: e2m Ambient_Air_Pressure_Monitor_Enable (0x80): 'Detect ambient air pressure in range error'; read by cm848_detectBarometricPressureSensorAboveMaximum; set on this truck */
    uint16_t misfire_timing_limit_enable : 1;  /* bit 8: e2m Misfire_Timing_Limit_Enable (0x100): 'Misfire timing limit algorithm enable'; read by cm848_calculateInjectionTimingMainMisfireLimit; set on this truck */
    uint16_t power_take_off_cruise_control_switches_enable : 1;  /* bit 9: e2m PTO_MUX_Enable (0x200): 'Enable cruise control switches to operate PTO'; read by cm848_runPowerTakeOffGovernorStateMachine; set on this truck */
    uint16_t power_take_off_park_neutral_enable : 1;  /* bit 10: e2m PTO_Park_Neutral_Enable (0x400): 'Enables PTO only when PARK/NEUTRAL status is TRUE'; read by cm848_runPowerTakeOffGovernorStateMachine; set on this truck */
    uint16_t driver_demand_torque_is_unmanaged_torque_enable : 1;  /* bit 11: e2m DDT_Is_Unmanaged_Torque_Enable (0x800): 'Makes EEC1 DDT msg. to be Adjusted_User_Fueling when Enabled'; read by cm848_calculateEffectiveFuelLimit; clear on this truck */
    uint16_t torque_management_enable : 1;  /* bit 12: e2m Torque_Mgmt_Enable (0x1000): 'Enable for Torque Management Feature'; read by cm848_evaluateTorqueManagementRequired, cm848_runTorqueManagement; clear on this truck */
    uint16_t trip_information_enable : 1;  /* bit 13: e2m Trip_Info_Enable (0x2000): 'Enable bit for the Trip Information Feature'; read by cm848_updateTripAndLifetimeCounters; set on this truck */
    uint16_t engine_retarder_selection_fault_mask_enable : 1;  /* bit 14: no e2m record (0x4000); read by cm848_calculateEngineRetarderSelectionPercent; cm848_calculateEngineRetarderSelectionPercent masks the retarder selection to 0 while it is set and fault bit 41 or 42 is detected; clear on this truck */
    uint16_t engine_retarder_inhibit_during_power_take_off_enable : 1;  /* bit 15: no e2m record (0x8000); read by cm848_updateEngineRetarderAllowedState; cm848_updateEngineRetarderAllowedState keeps the retarder off while the power take-off governor is active and it is set; clear on this truck */
};

struct algorithm_enable_flags_42_t {
    uint16_t misfire_relative_enable : 1;  /* bit 0: e2m Misfire_Relative_Enable (0x1): 'Misfire relative enabler'; read by cm848_runMisfireMonitor; clear on this truck */
    uint16_t actual_sensor_values_enable : 1;  /* bit 1: e2m Actual_Sensor_Values_Enable (0x2): 'Enable flag for actual sensor values algorithm'; read by cm848_selectSensorValuesInUse; set on this truck */
    uint16_t fuel_pressure_setpoint_cranking_enable : 1;  /* bit 2: e2m HPCR_Fuelpr_Crank_Mode_Enable (0x4): 'Enables use of crank rail press table during start'; read by cm848_calculateFuelPressureSetpoint; set on this truck */
    uint16_t fuel_pressure_fault_derate_cold_increment_enable : 1;  /* bit 3: e2m FSS_Derate_Cold_Increment_Enable (0x8): 'If enabled, adds Cold_Delta_Fuel to FSS_Fueling_Derate'; read by cm848_applyFuelLimitsForFuelPressureFaults; set on this truck */
    uint16_t high_pressure_safety_valve_test_enable : 1;  /* bit 4: e2m HPSV_Test_Enable (0x10): 'High Pressure Safety Valve Test enable'; read by cm848_selectLowSpeedGovernorDesiredReferenceSpeed; set on this truck */
    uint16_t stall_torque_management_enable : 1;  /* bit 5: e2m TC_Stall_Enable (0x20): 'Enable for stall troque management'; read by cm848_monitorConverterSlipAndEngineSpeedLimit; set on this truck */
    uint16_t j1939_lost_tsc1_no_broadcast_enable : 1;  /* bit 6: e2m J1939_Lost_TSC_No_Broadcast_Enable (0x40): 'Enable for shut-off of J1939/71 broadcast on lost/intermittent TSC1.'; read by cm848_updateParkNeutralFlagAndTsc1Activity; clear on this truck */
    uint16_t altitude_derate_cold_increment_enable : 1;  /* bit 7: e2m Altitude_Derate_Cold_Increment_Enable (0x80): 'Enable to add Cold_Delta_Fuel to Altitide_Derate_Fueling'; read by cm848_calculateAltitudeDerateFuelLimit; set on this truck */
    uint16_t hybrid_governor_cold_increment_enable : 1;  /* bit 8: e2m Hybrid_Governor_Cold_Increment_Enable (0x100): 'Enable to add Cold_Delta_Fuel to Hybrid_Governor_Fueling'; read by cm848_calculateFuelLimitByRpmAndDemand; set on this truck */
    uint16_t torque_management_cold_increment_enable : 1;  /* bit 9: e2m Torque_Mgmt_Cold_Increment_Enable (0x200): 'Enable to add Cold_Delta_Fuel to Torque_Mgmt_Fueling'; read by cm848_calculateTorqueManagementFuelTableLimit; set on this truck */
    uint16_t reserved_bit_10 : 1;  /* bit 10: no e2m record (0x400); no reader in this build; set on this truck */
    uint16_t reserved_bit_11 : 1;  /* bit 11: e2m Torque_Mgmt_GR_Enable (0x800): 'Enable to'; no reader; bit 12 does the gear ratio torque management in this build; clear on this truck */
    uint16_t torque_management_gear_ratio_enable : 1;  /* bit 12: no e2m record (0x1000); read by cm848_evaluateTorqueManagementRequired, cm848_runTorqueManagement; the e2m puts Torque_Mgmt_GR_Enable on bit 11, which nothing reads; cm848_evaluateTorqueManagementRequired runs the manual gear ratio stages while it is set, and cm848_runTorqueManagement runs while it or algorithm_enable_flags_40_cal torque_management_enable is set; clear on this truck */
    uint16_t fuel_pressure_too_high_monitor_enable : 1;  /* bit 13: e2m HPCR_Pressure_Too_High_Monitor_Enable (0x2000): 'HPCR Pressure Too High diagnostic enable/disable'; read by cm848_diagnoseFuelPressureGovernor; set on this truck */
    uint16_t fuel_pressure_tracking_error_monitor_enable : 1;  /* bit 14: e2m HPCR_Cusum_Monitor_Enable (0x4000): 'HPCR Cusum diagnostics enable/disable'; read by cm848_monitorFuelPressureTrackingError, cm848_resetFuelPressureTrackingErrorMonitor; set on this truck */
    uint16_t fuel_pressure_setpoint_not_reached_monitor_enable : 1;  /* bit 15: e2m HPCR_Cusum_Leak_Monitor_Enable (0x8000): 'HPCR Cusum leak detection enable/disable'; read by cm848_monitorFuelPressureSetpointNotReached, cm848_resetFuelPressureSetpointNotReachedMonitor; clear on this truck */
};

struct algorithm_enable_flags_43_t {
    uint16_t h_bridge_fault_discrete_feedback_enable : 1;  /* bit 0: e2m HB_Fault_Discrete_Feedback_Enable (0x1): 'Enable h-bridge fault A & B discrete input logic'; read by cm848_processEgrValveHBridgeFaults, cm848_processVariableGeometryTurbochargerHBridgeFaults; clear on this truck */
    uint16_t egr_orifice_temperature_rationality_enable : 1;  /* bit 1: e2m EGR_Orifice_Temp_Rationality_Enable (0x2): 'Enable for EGR orifice temp rationality'; read by cm848_monitorEgrOrificeTemperatureSensorRationality; clear on this truck */
    uint16_t transmission_temperature_rationality_monitor_enable : 1;  /* bit 2: e2m TTSR_Monitor_Enable (0x4): 'transmission temp rationality monitor enable'; read by cm848_checkTransmissionTemperatureSensorPerformance; set on this truck */
    uint16_t rock_cycle_torque_management_enable : 1;  /* bit 3: e2m TC_Rock_Cycle_Enable (0x8): 'Enable for rock cycle torque management'; read by cm848_calculateParkNeutralExitEngineSpeedLimit, cm848_updateParkNeutralExitEngineSpeedLimitWindow; set on this truck */
    uint16_t vacuum_throttle_cruise_enable : 1;  /* bit 4: e2m Vac_Throttle_Cruise_Enable (0x10): 'Cal enable to control throttle actuator during cruise mode'; read by cm848_runOperatingModeSpeedGovernor, cm848_controlCruiseVacuumServo, cm848_calculateAllSpeedGovernorEquivalentThrottle; set on this truck */
    uint16_t transfer_case_low_range_enable : 1;  /* bit 5: e2m Tcase_Trans_Low_Range_Enable (0x20): 'Enables 4WD Low Range Indication'; read by cm848_detectTransferCaseLowRange; clear on this truck */
    uint16_t chi_cold_increment_enable : 1;  /* bit 6: e2m Chi_Cold_Increment_Enable (0x40): 'Enable to add Cold_Delta_Fuel to CBR_Max_Chi_Fuel'; read by cm848_calculateCombustionGrossFuel; set on this truck */
    uint16_t density_cold_increment_enable : 1;  /* bit 7: e2m Density_Cold_Increment_Enable (0x80): 'Enable to add Cold_Delta_Fuel to CBR_Density_Max_Fuel'; read by cm848_calculateCombustionGrossFuel; set on this truck */
    uint16_t net_torque_fueling_cold_increment_enable : 1;  /* bit 8: e2m Net_Torque_Fueling_Cold_Increment_Enable (0x100): 'Enable to add Cold_Delta_Fuel to Net_Torque_Fueling_Limit'; read by cm848_calculateNetTorqueFuelLimit; set on this truck */
    uint16_t reserved_bit_9 : 1;  /* bit 9: no e2m record (0x200); no reader in this build; clear on this truck */
    uint16_t reserved_bit_10 : 1;  /* bit 10: no e2m record (0x400); no reader in this build; clear on this truck */
    uint16_t reserved_bit_11 : 1;  /* bit 11: e2m TVA_Algorithm_Enable (0x800): 'Enables TTVA position control and end-stop learning'; no reader in this build; clear on this truck */
    uint16_t wastegate_solenoid_driver_enable : 1;  /* bit 12: e2m CWG_LS_Pressure_Driver_Enable (0x1000): 'Input Enable, Bit of Word'; read by cm848_applyWastegateSolenoidDuty; set on this truck */
    uint16_t reserved_bit_13 : 1;  /* bit 13: no e2m record (0x2000); no reader in this build; clear on this truck */
    uint16_t reserved_bit_14 : 1;  /* bit 14: no e2m record (0x4000); no reader in this build; clear on this truck */
    uint16_t reserved_bit_15 : 1;  /* bit 15: no e2m record (0x8000); no reader in this build; clear on this truck */
};

struct algorithm_enable_flags_41_t {
    uint16_t engine_retarder_extended_idle_enable : 1;  /* bit 0: No e2m name; code only (PR #53 round 17). With low_speed_governor_extended_idle_active_flag (e2m 1496 +A LSG_Extended_Idle_Status) set, cm848_calculateEngineRetarderSelectionPercent forces the selection to 100 and cm848_updateEngineRetarderAllowedState forces the allowed state to OVERRIDE_OR_NON_OVERRIDE, while cm848_updateEngineRetarderActiveState keeps engine_retarder_active_flag at 0: the exhaust brake runs at extended idle (a warm-up use) without reporting braking (was engine_retarder_speed_limit_enable, from the flag's old name governor_speed_limit_active_flag) | earlier note: no e2m name; code only. cm848_updateEngineRetarderAllowedState (lhz at 0x41848), cm848_calculateEngineRetarderSelectionPercent (0x41998) and cm848_updateEngineRetarderActiveState (0x41e5c): while low_speed_governor_extended_idle_active_flag is set and this bit is set the retarder selection percent is forced to 100 and engine_retarder_active_flag stays 0. Clear in this calibration (0x7ca6). */
    uint16_t brake_switch_diagnostic_enable : 1;  /* bit 1: e2m Brake_Switch_Diag_Enable. cm848_monitorBrakeSwitchPairAgreement (lhz 82(r31) at 0x512140). Code agrees (wave 10). Set in this calibration (0x7ca6). */
    uint16_t fuel_level_rationality_diagnostic_enable : 1;  /* bit 2: e2m Fuel_Lvl_Rationality_Enable. cm848_monitorFuelLevelLowDistance (lhz at 0x5307f8). Code agrees (wave 10). Set in this calibration (0x7ca6). */
    uint16_t reserved_bit_3 : 1;  /* bit 3: no e2m name. No reader in either bank (sweep of both banks). Clear in this calibration (0x7ca6). */
    uint16_t thermostat_system_monitor_enable : 1;  /* bit 4: e2m Tstat_System_Monitor_Enable. cm848_runThermostatMonitor (lhz at 0x536a04) and cm848_selectCoolingFanSpeedTarget (lhz at 0x5152e8, the thermostat monitor hold). Code agrees. Clear in this calibration (0x7ca6). */
    uint16_t electronic_voltage_regulator_pid_enable : 1;  /* bit 5: e2m EVR_PID_Enable (EVR = Electronic Voltage Regulation per e2m EVR_Enable). cm848_calculateAlternatorFieldDutyByPid (lhz at 0x37a54), the charging voltage PI loop. Code agrees. Set in this calibration (0x7ca6). */
    uint16_t coolant_temperature_in_range_monitor_enable : 1;  /* bit 6: e2m CTIR_Monitor_Enable. cm848_checkCoolantTemperatureSensorPerformance (lhz at 0x52de5c). Code agrees. Clear in this calibration (0x7ca6). */
    uint16_t reserved_bit_7 : 1;  /* bit 7: no e2m name. No reader in either bank (sweep of both banks). Set in this calibration (0x7ca6). */
    uint16_t fuel_temperature_in_range_monitor_enable : 1;  /* bit 8: e2m Fuel_Temp_Monitor_Enable. cm848_checkFuelTemperatureSensorAfterColdSoak (lhz at 0x530468); with the bit clear that check never starts. Code agrees (wave 10). Clear in this calibration (0x7ca6). */
    uint16_t intake_air_heater_monitor_enable : 1;  /* bit 9: e2m IAH_Monitor_Enable. cm848_monitorIntakeAirHeaterPerformance (lhz at 0x53248c), cm848_computeIntakeAirHeaterPreheatDuration (0x517048), cm848_countDownIntakeAirHeaterPreheat (0x5171b4, 0x51726c). Code agrees. Clear in this calibration (0x7ca6). */
    uint16_t turbocharger_monitor_enable : 1;  /* bit 10: e2m Turbo_Monitor_Enable. cm848_monitorOverboostAndHighLoadBoostBand (lhz at 0x5372d0). Code agrees. Set in this calibration (0x7ca6). */
    uint16_t torque_normalization_enable : 1;  /* bit 11: torque normalization enable - e2m Torque_Normalization_Enable. cm848_calculateJ1939ReferenceEngineFueling (lhz at 0x20504) and cm848_calculateJ1939TorqueCurveFuelingsAndReferenceFuelings (lhz 82(r29) at 0x21db4); the reader names do not tie to the e2m text, so the name is e2m only. Set in this calibration (0x7ca6). (was reserved_bit_11: a guess until PR #53 round 20 proved the e2m 106B block alignment) */
    uint16_t throttle_100_cold_increment_enable : 1;  /* bit 12: full throttle cold fuel increment enable - e2m Throttle_100_Cold_Increment_Enable. cm848_calculateThrottle100Fuelings (lhz 82(r29) at 0x1f1a4); the name agrees, the body was not read. Set in this calibration (0x7ca6). (was reserved_bit_12: a guess until PR #53 round 20 proved the e2m 106B block alignment) */
    uint16_t air_fuel_control_cold_increment_enable : 1;  /* bit 13: air fuel control cold fuel increment enable - e2m AFC_Cold_Increment_Enable. cm848_calculateAirFuelControlFuelLimit (lhz 82(r26) at 0xe064), which also reads the air fuel control override bit of algorithm_enable_flags_12_cal; the name agrees, the body was not read. Set in this calibration (0x7ca6). (was reserved_bit_13: a guess until PR #53 round 20 proved the e2m 106B block alignment) */
    uint16_t reserved_bit_14 : 1;  /* bit 14: no e2m name. No reader in either bank (sweep of both banks). Set in this calibration (0x7ca6). */
    uint16_t misfire_monitor_enable : 1;  /* bit 15: e2m Misfire_Monitor_Enable. cm848_initializeMisfireMonitor (lhz at 0x532bd8). Code agrees (wave 10). Clear in this calibration (0x7ca6). */
};

struct piecewise_linear_gain_t {
    uint32_t small_signal_gain;  /* Gain while the input is inside the window (Q16: output = gain x input >> 16; units per instance) */
    uint32_t positive_large_signal_gain;  /* Gain above positive_window_width: the proportional step applies it to the part above; the integral step uses it for the whole error */
    uint32_t negative_large_signal_gain;  /* Gain below negative_window_width (the same way as the positive one) */
    int16_t positive_window_width;  /* Upper breakpoint of the window (>= 0; in the input's units) */
    int16_t negative_window_width;  /* Lower breakpoint of the window (<= 0) */
};

struct derivative_gain_t {
    uint16_t filter_coefficient;  /* Weight of the previous state in 1/65536 (e2m Derivative_Gain_Constant): the state moves toward gain x input by 1 - coefficient / 65536 per call */
    uint32_t small_signal_gain;  /* Gain while the input is inside the window */
    uint32_t positive_large_signal_gain;  /* Gain while the input is above positive_window_width */
    uint32_t negative_large_signal_gain;  /* Gain while the input is below negative_window_width */
    int16_t positive_window_width;  /* Upper breakpoint of the window (>= 0) */
    int16_t negative_window_width;  /* Lower breakpoint of the window */
};

struct low_speed_governor_gain_set_t {
    int16_t proportional_gain;  /* +0: e2m *_Proportional_Gain (MM3S/RPM); cm848_loadLowSpeedGovernorGainSet copies it into the working low_speed_governor_proportional_gain (stage 10c) */
    int16_t integral_gain;  /* +2: e2m *_Integral_Gain (MM3S/RPM/SEC); cm848_loadLowSpeedGovernorGainSet copies it into the working low_speed_governor_integral_gain (stage 10c) */
    int16_t derivative_gain;  /* +4: e2m *_Derivative_Gain (MM3S*SEC/RPM); cm848_loadLowSpeedGovernorGainSet copies it into the working low_speed_governor_derivative_gain (stage 10c) */
    int16_t jerk_gain;  /* +6: e2m *_Jerk_Gain (MM3S*SEC/RPM); cm848_loadLowSpeedGovernorGainSet copies it into the working low_speed_governor_jerk_gain (stage 10c) */
};

struct all_speed_governor_gain_set_t {
    int16_t proportional_gain_1;  /* +0x0: e2m ASG_Proportional_Gain_1 (MM3S/RPM); cm848_runOperatingModeSpeedGovernor reads it through all_speed_governor_gain_set_pointer (round 5) */
    int16_t proportional_gain_2;  /* +0x2: e2m ASG_Proportional_Gain_2 (MM3S/RPM); cm848_runOperatingModeSpeedGovernor reads it through all_speed_governor_gain_set_pointer (round 5) */
    int16_t integral_gain_1;  /* +0x4: e2m ASG_Integral_Gain_1 (MM3S/RPM/SEC); cm848_runOperatingModeSpeedGovernor reads it through all_speed_governor_gain_set_pointer (round 5) */
    int16_t integral_gain_2;  /* +0x6: e2m ASG_Integral_Gain_2 (MM3S/RPM/SEC); cm848_runOperatingModeSpeedGovernor reads it through all_speed_governor_gain_set_pointer (round 5) */
    int16_t derivative_gain_1;  /* +0x8: e2m ASG_Derivative_Gain_1 (MM3S*SEC/RPM); cm848_runOperatingModeSpeedGovernor reads it through all_speed_governor_gain_set_pointer (round 5) */
    int16_t derivative_gain_2;  /* +0xa: e2m ASG_Derivative_Gain_2 (MM3S*SEC/RPM); cm848_runOperatingModeSpeedGovernor reads it through all_speed_governor_gain_set_pointer (round 5) */
    int16_t compensation_filter_coefficient_1;  /* +0xc: e2m ASG_Compensation_Filter_Coefficient_1 (UNITLESS); cm848_runOperatingModeSpeedGovernor reads it through all_speed_governor_gain_set_pointer (round 5) */
    int16_t compensation_filter_coefficient_2;  /* +0xe: e2m ASG_Compensation_Filter_Coefficient_2 (UNITLESS); cm848_runOperatingModeSpeedGovernor reads it through all_speed_governor_gain_set_pointer (round 5) */
    int16_t compensation_filter_coefficient_3;  /* +0x10: e2m ASG_Compensation_Filter_Coefficient_3 (UNITLESS); cm848_runOperatingModeSpeedGovernor reads it through all_speed_governor_gain_set_pointer (round 5) */
};

struct j1939_control_session_t {
    uint8_t session_kind;  /* 0 = an engine control (TSC1) session, 1 = a retarder control session; 0xFE (with the source address 0xFE) in an empty record */
    uint8_t controlling_source_address;  /* the J1939 source address of the controlling device */
    J1939_CONTROL_DEVICE control_device;  /* engine_control_device_indicator / engine_retarder_control_device_indicator at the start */
    uint16_t override_control_mode_count;  /* how many override_control_modes are filled: 1 at the start, + 1 per mode change, at most 5 (then the history shifts) */
    TSC1_OVERRIDE_MODE override_control_modes;  /* the session's override control modes in order (the last five when there were more) */
    uint32_t start_time;  /* key_on_hour_meter at the start (0.2 s counts) */
    uint32_t duration;  /* key_on_hour_meter - start_time, stored when the session ends (0.2 s counts) */
};

struct sci_output_test_timers_t {
    uint16_t air_conditioning_clutch_relay;  /* +0x00: timer of the DRB actuator test 13-09 A/C CLUTCH RELAY (logical output 38; started with 300 phases) */
    uint16_t intake_heater_1;  /* +0x02: timer of the DRB actuator test 13-28 INTAKE HEATER #1 (logical output 43; started with 11 phases) */
    uint16_t intake_heater_2;  /* +0x04: timer of the DRB actuator test 13-29 INTAKE HEATER #2 (logical output 44; started with 11 phases) */
    uint16_t fuel_transfer_pump;  /* +0x06: timer of the DRB actuator test 13-33 FUEL PUMP RELAY / TRANSFER PUMP (logical output 53; started with 300 phases) */
    uint16_t wait_to_start_lamp;  /* +0x08: timer of the DRB actuator test 13-49 WAIT TO START LAMP (logical output 4; started with 300 phases) */
    uint16_t exhaust_brake;  /* +0x0a: timer of the DRB actuator test 13-5D EXHAUST BRAKE (logical output 11; started with 11 phases) */
    uint16_t fuel_control;  /* +0x0c: timer of the DRB actuator test 13-5E FUEL CONTROL (fuel_control_actuator_test_active_flag; started with 11 phases) (was cold_start_sync_protection_countdown) | earlier note: per-crank countdown for engine_sync cold-start protection */
    uint16_t cooling_fan;  /* +0x0e: timer of the DRB actuator test 13-5F PWM RAD FAN (cooling_fan_actuator_test_active_flag; started with 11 phases) (was cold_start_injection_protection_countdown) | earlier note: per-crank countdown for cold-start injection protection */
    uint16_t converter_clutch_solenoid;  /* +0x10: timer of the DRB actuator test 13-0F TORQUE CONV CLUTCH (logical output 18; started with 300 phases) */
    uint16_t overdrive_solenoid;  /* +0x12: timer of the DRB actuator test 13-16 OVERDRIVE SOLENOID (logical output 17; started with 300 phases) */
    uint16_t cruise_vent_solenoid;  /* +0x14: timer of the DRB actuator test 13-1A S/C VENT SOLENOID (and 13-0C with the vacuum solenoid) (logical output 19; started with 300 phases) */
    uint16_t cruise_vacuum_solenoid;  /* +0x16: timer of the DRB actuator test 13-1B S/C VAC SOLENOID (and 13-0C) (logical output 20; started with 300 phases) */
    uint16_t cruise_servo_supply;  /* +0x18: timer of the DRB actuator test 13-2C S/C 12 VOLT FEED (logical output 21; started with 11 phases) */
    uint16_t transmission_relay;  /* +0x1a: timer of the DRB actuator test 13-43 TRANS 12V RELAY (logical output 16; started with 300 phases) */
};

struct logical_output_request_bits_8_to_15_t {
    uint8_t reserved_bit_0 : 1;  /* bit 0: output 8 (mask 0x01): e2m 1577 +1 T2_Low_Gear_Driver; no direct read or write found */
    uint8_t reserved_bit_1 : 1;  /* bit 1: output 9 (mask 0x02): e2m 1577 +1 T2_Neutral_Driver; no direct read or write found */
    uint8_t reserved_bit_2 : 1;  /* bit 2: output 10 (mask 0x04): e2m 1577 +1 Engine_Alarm_Driver; no direct read or write found */
    uint8_t engine_brake_driver_1_request : 1;  /* bit 3: output 11 (mask 0x08): e2m 1577 +1 Engine_Brake_Driver_1. output 11 (DRB test 13-5D EXHAUST BRAKE): cm848_driveEngineRetarderOutput sets it; cm848_updateEngineRetarderActiveState and cm848_calculateEngineRetarderTorque read it */
    uint8_t engine_brake_driver_2_request : 1;  /* bit 4: output 12 (mask 0x10): e2m 1577 +1 Engine_Brake_Driver_2. output 12: cm848_calculateEngineRetarderTorque counts it as a stage */
    uint8_t engine_brake_driver_3_request : 1;  /* bit 5: output 13 (mask 0x20): e2m 1577 +1 Engine_Brake_Driver_3. output 13: cm848_calculateEngineRetarderTorque counts it as a stage */
    uint8_t engine_brake_driver_4_request : 1;  /* bit 6: output 14 (mask 0x40): e2m 1577 +1 Engine_Brake_Driver_4. output 14: cm848_calculateEngineRetarderTorque counts it as a stage */
    uint8_t engine_brake_driver_5_request : 1;  /* bit 7: output 15 (mask 0x80): e2m 1577 +1 Engine_Brake_Driver_5. output 15: cm848_calculateEngineRetarderTorque counts it as a stage */
};

struct logical_output_request_bits_32_to_39_t {
    uint8_t reserved_bit_0 : 1;  /* bit 0: output 32 (mask 0x01): e2m 1577 +4 TU_WG_Driver_2; no direct read or write found */
    uint8_t reserved_bit_1 : 1;  /* bit 1: output 33 (mask 0x02): e2m 1577 +4 VR_Hall_Select; no direct read or write found */
    uint8_t reserved_bit_2 : 1;  /* bit 2: output 34 (mask 0x04): e2m 1577 +4 EPS_Select; no direct read or write found */
    uint8_t reserved_bit_3 : 1;  /* bit 3: output 35 (mask 0x08): e2m 1577 +4 Malfunction_Lamp_Driver; no direct read or write found */
    uint8_t reserved_bit_4 : 1;  /* bit 4: output 36 (mask 0x10): e2m 1577 +4 T2_Lockout_Driver; no direct read or write found */
    uint8_t reserved_bit_5 : 1;  /* bit 5: output 37 (mask 0x20): e2m 1577 +4 T2_Shift_Driver; no direct read or write found */
    uint8_t air_conditioning_clutch_request : 1;  /* bit 6: output 38 (mask 0x40): e2m 1577 +4 AC_Discrete_Output. output 38 (DRB test 13-09 A/C CLUTCH RELAY): the A/C clutch control (cm848_controlAirConditioningClutchForBrTruck / ...ForDrTruck) requests it */
    uint8_t reserved_bit_7 : 1;  /* bit 7: output 39 (mask 0x80): e2m 1577 +4 Unassigned_Discrete_Output_39; no direct read or write found */
};

struct logical_output_request_bits_40_to_47_t {
    uint8_t reserved_bit_0 : 1;  /* bit 0: output 40 (mask 0x01): e2m 1577 +5 Solenoid_A_Command; no direct read or write found */
    uint8_t reserved_bit_1 : 1;  /* bit 1: output 41 (mask 0x02): e2m 1577 +5 Solenoid_B_Command; no direct read or write found */
    uint8_t reserved_bit_2 : 1;  /* bit 2: output 42 (mask 0x04): e2m 1577 +5 Ether_Solenoid_Command; no direct read or write found */
    uint8_t intake_air_heater_1_request : 1;  /* bit 3: output 43 (mask 0x08): e2m 1577 +5 Cold_Start_Aid_1_Driver. output 43 (DRB test 13-28 INTAKE HEATER #1): the intake air heater preheat / post-heat functions request it */
    uint8_t intake_air_heater_2_request : 1;  /* bit 4: output 44 (mask 0x10): e2m 1577 +5 Cold_Start_Aid_2_Driver. output 44 (DRB test 13-29 INTAKE HEATER #2): the intake air heater preheat / post-heat functions request it */
    uint8_t reserved_bit_5 : 1;  /* bit 5: output 45 (mask 0x20): e2m 1577 +5 Fuel_Heater_Driver; no direct read or write found */
    uint8_t reserved_bit_6 : 1;  /* bit 6: output 46 (mask 0x40): e2m 1577 +5 Electherm_Driver; no direct read or write found */
    uint8_t reserved_bit_7 : 1;  /* bit 7: output 47 (mask 0x80): e2m 1577 +5 CY220_Off1; no direct read or write found */
};

struct logical_output_request_bits_48_to_55_t {
    uint8_t reserved_bit_0 : 1;  /* bit 0: output 48 (mask 0x01): e2m 1577 +6 CY220_Off2; no direct read or write found */
    uint8_t reserved_bit_1 : 1;  /* bit 1: output 49 (mask 0x02): e2m 1577 +6 Fan_Clutch_Control_Driver3; no direct read or write found */
    uint8_t reserved_bit_2 : 1;  /* bit 2: output 50 (mask 0x04): e2m 1577 +6 Starter_Interlocks_Sink; no direct read or write found */
    uint8_t reserved_bit_3 : 1;  /* bit 3: output 51 (mask 0x08): e2m 1577 +6 Starter_Interlocks_Source; no direct read or write found */
    uint8_t reserved_bit_4 : 1;  /* bit 4: output 52 (mask 0x10): e2m 1577 +6 Alternator_Field_Driver; no direct read or write found */
    uint8_t lift_pump_request : 1;  /* bit 5: output 53 (mask 0x20): e2m 1577 +6 Lift_Pump_Driver. output 53 (DRB test 13-33 FUEL PUMP RELAY / TRANSFER PUMP): cm848_controlLiftPump */
    uint8_t driver_asic_shutoff_request : 1;  /* bit 6: output 54 (mask 0x40): e2m 1577 +6 ASIC_FS_Shutoff_Driver (FS is not expanded; not output 30 FSO_Command, which cm848_processProtectionFaultsAndTiming requests every pass). Shuts off the output driver ASIC: the fuel system fault reactions request it - fault reaction mask bit 3 (cm848_updateFuelPressureFaultReactionRequests), fuel pressure too high with fuel_pressure_too_high_logical_output_request_enable (cm848_applyFuelLimitsForFuelPressureFaults), fault 388 excess fuel demand (cm848_monitorWatchdogFueling); cm848_initializeWatchdogFueling clears it. While it or supervisor_register_36_bit_1_low_held_flag is set, the output read-back debounce, the injector and fuel metering feedback diagnostics and the fault scan stand down (was fuel_shutoff_request, earlier injector_driver_asic_shutoff_request) */
    uint8_t reserved_bit_7 : 1;  /* bit 7: output 55 (mask 0x80): e2m 1577 +6 Protocol_Select; no direct read or write found */
};

struct logical_output_request_bits_64_to_71_t {
    uint8_t reserved_bit_0 : 1;  /* bit 0: output 64 (mask 0x01): e2m 1577 +8 OBD_Lamp; no direct read or write found */
    uint8_t reserved_bit_1 : 1;  /* bit 1: output 65 (mask 0x02): e2m 1577 +8 VR_Tachograph_Mode_Sel_1; no direct read or write found */
    uint8_t reserved_bit_2 : 1;  /* bit 2: output 66 (mask 0x04): e2m 1577 +8 VR_Tachograph_Mode_Sel_2; no direct read or write found */
    uint8_t egr_valve_pwm_enable_request : 1;  /* bit 3: output 67 (mask 0x08): e2m 1577 +8 EGA_PWM_Enable. output 67: read by the EGR valve control (cm848_selectEgrValveControlState, cm848_estimateEgrValveMotorCurrent) */
    uint8_t egr_valve_motor_opening_direction_request : 1;  /* bit 4: output 68 (mask 0x10): e2m 1577 +8 EGA_Motor_Cmd_Opening_Direction. output 68: read by cm848_estimateEgrValveMotorCurrent */
    uint8_t reserved_bit_5 : 1;  /* bit 5: output 69 (mask 0x20): e2m 1577 +8 IMA_Current_Lowside_Driver; no direct read or write found */
    uint8_t reserved_bit_6 : 1;  /* bit 6: output 70 (mask 0x40): e2m 1577 +8 APR_Current_Lowside_Driver; no direct read or write found */
    uint8_t variable_geometry_turbocharger_motor_closing_direction_request : 1;  /* bit 7: output 71 (mask 0x80): e2m 1577 +8 VGA_Motor_Cmd_Closing_Direction. output 71: read by cm848_estimateVariableGeometryTurbochargerMotorCurrent */
};

struct logical_output_request_bits_72_to_79_t {
    uint8_t variable_geometry_turbocharger_pwm_enable_request : 1;  /* bit 0: output 72 (mask 0x01): e2m 1577 +9 VGA_PWM_Enable. output 72: read by the VGT control (cm848_selectVariableGeometryTurbochargerControlState) */
    uint8_t reserved_bit_1 : 1;  /* bit 1: output 73 (mask 0x02): e2m 1577 +9 TVA_Motor_Cmd_Increase_Direction; no direct read or write found */
    uint8_t reserved_bit_2 : 1;  /* bit 2: output 74 (mask 0x04): e2m 1577 +9 TVA_PWM_Enable; no direct read or write found */
    uint8_t reserved_bit_3 : 1;  /* bit 3: output 75 (mask 0x08): e2m 1577 +9 Unassigned_Discrete_Output_75; no direct read or write found */
    uint8_t reserved_bit_4 : 1;  /* bit 4: output 76 (mask 0x10): e2m 1577 +9 Unassigned_Discrete_Output_76; no direct read or write found */
    uint8_t reserved_bit_5 : 1;  /* bit 5: output 77 (mask 0x20): e2m 1577 +9 Unassigned_Discrete_Output_77; no direct read or write found */
    uint8_t reserved_bit_6 : 1;  /* bit 6: output 78 (mask 0x40): e2m 1577 +9 Unassigned_Discrete_Output_78; no direct read or write found */
    uint8_t reserved_bit_7 : 1;  /* bit 7: output 79 (mask 0x80): e2m 1577 +9 Unassigned_Discrete_Output_79; no direct read or write found */
};

struct switch_input_state_t {
    uint8_t key_switch : 1;  /* bit 0: switch 0 (byte 0 mask 0x01): e2m 1612 Keyswitch; the ignition key switch (line 128 = the MDA30 pin; 1 = key on) */
    uint8_t lift_pump_feedback : 1;  /* bit 1: switch 1 (byte 0 mask 0x02): e2m 1612 Lift_Pump_Driver_Feedback */
    uint8_t not_brake_switch : 1;  /* bit 2: switch 2 (byte 0 mask 0x04): e2m 1612 Not_Brake_Switch; the second brake contact; cm848_deriveSecondBrakeSwitchSignal writes it */
    uint8_t power_take_off_on_switch : 1;  /* bit 3: switch 3 (byte 0 mask 0x08): e2m 1612 PTO_On_Switch */
    uint8_t wait_to_start_lamp_feedback : 1;  /* bit 4: switch 4 (byte 0 mask 0x10): e2m 1612 Wait_To_Start_Lamp_Feedback */
    uint8_t engine_brake_driver_1_feedback : 1;  /* bit 5: switch 5 (byte 0 mask 0x20): e2m 1612 Engine_Brake_Driver_1_Feedback */
    uint8_t air_conditioning_clutch_feedback : 1;  /* bit 6: switch 6 (byte 0 mask 0x40): e2m 1612 AC_Discrete_Output_Feedback */
    uint8_t idle_switch : 1;  /* bit 7: switch 7 (byte 0 mask 0x80): e2m 1612 Idle_Switch; the accelerator at idle (the idle validation pair with switch 8) */
    uint8_t not_idle_switch : 1;  /* bit 0: switch 8 (byte 1 mask 0x01): e2m 1612 Not_Idle_Switch; the accelerator off idle */
    uint8_t intake_air_heater_1_feedback : 1;  /* bit 1: switch 9 (byte 1 mask 0x02): e2m 1612 Cold_Start_Aid_1_Driver_Feedback */
    uint8_t intake_air_heater_2_feedback : 1;  /* bit 2: switch 10 (byte 1 mask 0x04): e2m 1612 Cold_Start_Aid_2_Driver_Feedback */
    uint8_t brake_switch : 1;  /* bit 3: switch 11 (byte 1 mask 0x08): e2m 1612 Brake_Switch; the brake switch the CCVS1 broadcast reports */
    uint8_t exhaust_brake_switch : 1;  /* bit 4: switch 12 (byte 1 mask 0x10): e2m 1612 Engine_Brake_Select_1; Engine_Brake_Select_1: the exhaust brake switch on this truck (round 8) */
    uint8_t air_conditioning_switch : 1;  /* bit 5: switch 13 (byte 1 mask 0x20): e2m 1612 AC_On_Off_Switch; cm848_updateAirConditioningSwitchFromPci writes it from the PCI bus */
    uint8_t low_oil_pressure_switch : 1;  /* bit 6: switch 14 (byte 1 mask 0x40): e2m 1612 Low_Oil_Switch */
    uint8_t clutch_switch : 1;  /* bit 7: switch 15 (byte 1 mask 0x80): e2m 1612 Clutch_Switch; the clutch switch the CCVS1 broadcast reports */
    uint8_t egr_valve_driver_feedback : 1;  /* bit 0: switch 16 (byte 2 mask 0x01): e2m 1612 EGR_ASIC_Feedback */
    uint8_t variable_geometry_turbocharger_driver_feedback : 1;  /* bit 1: switch 17 (byte 2 mask 0x02): e2m 1612 VGT_ASIC_Feedback */
    uint8_t reserved_bit_18 : 1;  /* bit 2: switch 18 (byte 2 mask 0x04): no e2m 1612 record; no named use */
    uint8_t remote_power_take_off_switch : 1;  /* bit 3: switch 19 (byte 2 mask 0x08): e2m 1612 Remote_PTO_Switch */
    uint8_t park_neutral_switch : 1;  /* bit 4: switch 20 (byte 2 mask 0x10): e2m 1612 Transmission_Park_Neutral_Switch; the transmission park / neutral switch (line 13) */
    uint8_t overdrive_off_switch : 1;  /* bit 5: switch 21 (byte 2 mask 0x20): e2m 1612 Transmission_Overdrive_Switch; the O/D OFF button (it toggles overdrive_off_flag) */
    uint8_t transmission_relay_feedback : 1;  /* bit 6: switch 22 (byte 2 mask 0x40): e2m 1612 Transmission_VFS_Battery_Feedback; the transmission relay output (logical output 16) */
    uint8_t overdrive_solenoid_feedback : 1;  /* bit 7: switch 23 (byte 2 mask 0x80): e2m 1612 Transmission_Overdrive_Feedback */
    uint8_t converter_clutch_solenoid_feedback : 1;  /* bit 0: switch 24 (byte 3 mask 0x01): e2m 1612 Transmission_TCC_Feedback */
    uint8_t cruise_vent_solenoid_feedback : 1;  /* bit 1: switch 25 (byte 3 mask 0x02): e2m 1612 Cruise_Vent_Feedback */
    uint8_t throttle_interlock_switch : 1;  /* bit 2: switch 26 (byte 3 mask 0x04): e2m 1612 Throttle_Interlock_Switch */
    uint8_t cruise_vacuum_solenoid_feedback : 1;  /* bit 3: switch 27 (byte 3 mask 0x08): e2m 1612 Cruise_Vacuum_Feedback */
    uint8_t cruise_servo_supply_feedback : 1;  /* bit 4: switch 28 (byte 3 mask 0x10): e2m 1612 Cruise_SC_Source_Feedback */
    uint8_t reserved_bit_29 : 1;  /* bit 5: switch 29 (byte 3 mask 0x20): no e2m 1612 record; no named use */
    uint8_t reserved_bit_30 : 1;  /* bit 6: switch 30 (byte 3 mask 0x40): e2m 1612 TVA_ASIC_Feedback; no named use */
    uint8_t unwired_switch : 1;  /* bit 7: switch 31 (byte 3 mask 0x80): no e2m 1612 record; no 11.45 record and no line: every unwired switch function compiles to it (the two-speed axle switch of cm848_updateCruiseAndRoadSpeedGovernorDroops among them), and cm848_updateSwitch31FromAcceleratorPedal / cm848_checkSwitch31OnTimeFault pulse or hold it from the accelerator pedal */
};

struct engine_protection_fault_log_entry_t {
    uint32_t occurrence_time;  /* +0: key_on_hour_meter when the fault became active (cm848_recordEngineProtectionFaultLogEntry); e2m 1152 +2E EPF_Input_Source_0_Fueling_Fault_Occurrence_Time (0.2 s) names the copy in the channel state */
    int16_t extreme_value;  /* +4: the input's extreme while the fault is active: starts at 0x8000, or 0x7fff while configuration flag 0x8 is set, and with configuration flags 0xc it takes the input whenever cm848_isEngineProtectionInputMoreExtreme(input, value, flags) is nonzero (the code reads it as a signed short); e2m 1152 +32 EPF_Input_Source_0_Fueling_Fault_Log_Value */
    uint16_t duration;  /* +6: 0 while the fault is active, then key_on_hour_meter - occurrence_time when it clears (cm848_closeEngineProtectionFaultLogEntry); e2m 1152 +34 EPF_Input_Source_0_Fueling_Fault_Log_Duration (0.2 s) */
};

struct engine_protection_channel_configuration_t {
    uint16_t configuration_flags;  /* +0x0 e2m Fuel_Temperature_EPF_Configuration [HEX] '[EPFTCG] Configuration word for fuel temperature EPF input' (was the flat row fuel_temperature_derate_configuration_flags) | earlier note: e2m 112E +0 Fuel_Temperature_EPF_Configuration '[EPFTCG] Configuration word for fuel temperature EPF input' (address from the ECU's parameter ID table) (bit fie | Configuration flags, from the code that tests each bit (no e2m bit records): 0x1 fueling derate (cm848_calculateFaultDerateFuelLimit; the fueling restart index); 0x2 engine speed derate (cm848_calculateFaultDerateEngineSpeedLimit; the engine speed restart index); 0x101 / 0x402 count the fueling / engine speed over-limit duration; 0x4 the input is past its threshold when above it (clear: below), and the fault log tracks the input's maximum; 0x8 with 0x4 clear the log tracks the minimum (cm848_isEngineProtectionInputMoreExtreme); with neither (0xc clear) no extreme is tracked; the extreme starts at 0x7fff while 0x8 is set, else 0x8000; 0x30 a switch input (its masked bit, not a threshold): 0x10 active while the bit is set, 0x20 while it is clear; 0x40 the fueling severity is the time-ramped index (cm848_rampEngineProtectionSeverityIndex) and the fueling restart index 0x100, instead of the input's place between the minimum and maximum thresholds (cm848_calculateFaultDerateFuelLimit, cm848_updateEngineProtectionRestartSeverityIndexes); 0x300 the fueling shutdown (0x100 by the over-limit duration, else by the severity threshold); 0xc00 the engine speed shutdown (0x400 by duration, else by severity); 0x1000 the engine speed fault shares the fueling fault log (hpcr_initializeEngineProtection) */
    uint16_t fueling_derate_start_duration;  /* +0x2 e2m Fuel_Temperature_Fueling_Derate_Start_Duration [SEC] '[EPFTFLDD] Time from fuel temperature overlimit reached to start of fuel derate' */
    uint16_t engine_speed_derate_start_duration;  /* +0x4 e2m Fuel_Temperature_RPM_Derate_Start_Duration [SEC] '[EPFTRPDD] Time from fuel temperature overlimit reached to start of RPM derate' */
    uint16_t fueling_ramp_rate;  /* +0x6 e2m Fuel_Temperature_Fueling_Ramp_Rate [SEC] '[EPFTFLIC] Time to reach full derate w/ fuel temperature engine protect. fueling flt' */
    uint16_t engine_speed_ramp_rate;  /* +0x8 e2m Fuel_Temperature_RPM_Ramp_Rate [SEC] '[EPFTRPIC] Time to reach full derate w/ fuel temperature engine protection RPM fault' */
    int16_t fueling_minimum_threshold;  /* +0xa e2m Fuel_Temperature_Fueling_Min_Threshold [DEG_F] '[EPFTMNTD] Minimum temperature threshold for fuel temperature fuel limiting' (was the flat row fuel_temperature_derate_fueling_minimum_temperature) | earlier note: e2m 112E +A Fuel_Temperature_Fueling_Min_Threshold '[EPFTMNTD] Minimum temperature threshold for fuel temperature fuel limiting' (address from the ECU's paramet | typed signed in round 21 stage E: every load is lha (the e2m's NU notwithstanding) */
    int16_t fueling_maximum_threshold;  /* +0xc e2m Fuel_Temperature_Fueling_Max_Threshold [DEG_F] '[EPFTMXTD] Maximum threshold for fuel temperature fuel limiting' (was the flat row fuel_temperature_derate_fueling_maximum_temperature) | earlier note: e2m 112E +C Fuel_Temperature_Fueling_Max_Threshold '[EPFTMXTD] Maximum threshold for fuel temperature fuel limiting' (address from the ECU's parameter ID table) | typed signed in round 21 stage E: every load is lha (the e2m's NU notwithstanding) */
    int16_t engine_speed_lower_limit_threshold;  /* +0xe e2m Fuel_Temperature_RPM_Lower_Limit [DEG_F] '[EPFTRPLL] Minimum threshold for fuel temperature RPM limiting' (was the flat row fuel_temperature_derate_engine_speed_minimum_temperature) | earlier note: e2m 112E +E Fuel_Temperature_RPM_Lower_Limit '[EPFTRPLL] Minimum threshold for fuel temperature RPM limiting' (address from the ECU's parameter ID table) (1/64 */
    int16_t fueling_shutdown_duration_threshold;  /* +0x10 e2m Fuel_Temperature_Fueling_Shutdown_Duration_Thres [SEC] '[EPFTFLSD] Threshold for fuel temperature fuel limiting to initiate shutdown' | typed signed in round 21 stage E: every load is lha (the e2m's NU notwithstanding) */
    int16_t engine_speed_shutdown_duration_threshold;  /* +0x12 e2m Fuel_Temperature_RPM_Shutdown_Duration_Thres [SEC] '[EPFTRPSD] Threshold for fuel temperature RPM limiting to initiate shutdown' | typed signed in round 21 stage E: every load is lha (the e2m's NU notwithstanding) */
    uint16_t shutdown_delay;  /* +0x14 e2m Fuel_Temperature_Shutdown_Delay [SEC] '[EPFTFSDY] Shutdown delay for fuel temperature shutdown' */
    uint16_t start_monitor_engine_speed;  /* +0x16 e2m Fuel_Temperature_Start_Monitor_RPM [RPM] '[EPFTSRRP] RPM threshold that must be crossed in order to log fuel temp fault' */
    uint16_t start_monitor_time;  /* +0x18 e2m Fuel_Temperature_Start_Monitor_Time [SEC] '[EPFTSRTM] Time threshold that must be crossed in order to log fuel temperature fault' */
    uint16_t fueling_fault_index;  /* +0x1a e2m EPF_Input_Source_0_Fueling_Index_Fault [HEX] '[EP00FLFU] Fault index indicating Input source 0 fueling error detected'; +0x1a e2m Fuel_Temperature_Fueling_Error [HEX] '[EPFTFLFU] Fault index indicating temperature fueling error detected' */
    uint16_t engine_speed_fault_index;  /* +0x1c e2m EPF_Input_Source_0_RPM_Index_Fault [HEX] '[EP00RPFU] Fault index indicating Input source 0 RPM error detected'; +0x1c e2m Fuel_Temperature_RPM_Error [HEX] '[EPFTRPFU] Fault index indicating Fuel temperature RPM error detected' */
    uint16_t shutdown_warning_time;  /* +0x1e e2m Fuel_Temperature_Shutdown_Warning_Time [SEC] '[EPFTWNTM] time duration to warn driver before shutdown due to fuel temperature' */
    int16_t fueling_shutdown_severity_threshold;  /* +0x20 e2m Fuel_Temperature_Fueling_Shutdown_Severity_Thres [DEG_F] '[EPFTFLSS] Threshold for fuel temperature fuel limiting to initiate shutdown' */
    int16_t engine_speed_shutdown_severity_threshold;  /* +0x22 e2m Fuel_Temperature_RPM_Shutdown_Severity_Thres [DEG_F] '[EPFTRPSS] Threshold for fuel temperature RPM limiting to initiate shutdown' */
};

struct engine_protection_channel_state_t {
    word* input_pointer;  /* +0x0 e2m Fuel_Temperature_Input_Source [HEX] '[EPFTSA] Pointer to source of fuel temperature' (was the flat row fuel_temperature_derate_input_pointer) | earlier note: Input pointer (offset 0) of the single fuel temperature torque derate channel = &fuel_temperature_sensor_filtered (slot 7 - 1/64 deg F) - derate ramps from 200 */
    uint16_t input_mask;  /* +0x4 e2m Fuel_Temperature_Input_Mask [HEX] '[EPFTSAMK] Mask for source of fuel temperature' */
    uint16_t fueling_duration;  /* +0x6 e2m Fuel_Temperature_Fuel_Duration [SEC] '[EPFTFLTM] Amount of time since fuel temperature failure was detected' */
    uint16_t engine_speed_duration;  /* +0x8 e2m Fuel_Temperature_RPM_Duration [SEC] '[EPFTRPTM] Amount of time since fuel temperature failure was detected' */
    short* minimum_threshold_pointer;  /* +0xa e2m Fuel_Temperature_Min_Threshold_Pointer [HEX] '[EPFTMNSA] Pointer to fuel temperature min threshold' | typed signed in round 21 stage E: every load is lha (the e2m's NU notwithstanding) */
    short* maximum_threshold_pointer;  /* +0xe e2m Fuel_Temperature_Max_Threshold_Pointer [HEX] '[EPFTMXSA] Pointer to fuel temperature max threshold' | typed signed in round 21 stage E: every load is lha (the e2m's NU notwithstanding) */
    short* engine_speed_lower_limit_pointer;  /* +0x12 e2m Fuel_Temperature_RPM_Lower_Limit_Pointer [HEX] '[EPFTRLSA] Pointer to fuel temperature RPM limit threshold' | typed signed in round 21 stage E: every load is lha (the e2m's NU notwithstanding) */
    uint16_t errors_allowed;  /* +0x16 e2m Fuel_Temperature_Errors_Allowed [UNITLESS] '[EPFTEREN] TRUE = fuel temperature error allowed, FALSE = not allowed' */
    uint16_t precrank_error;  /* +0x18 e2m Fuel_Temperature_Precrank_Error [HEX] '[EPFTPKER] Fuel temperature system error detected before cranking in restart' (was the flat row fuel_temperature_derate_precrank_error_flag) | earlier note: e2m 1152 +18 Fuel_Temperature_Precrank_Error [EPFTPKER] 'Fuel temperature system error detected before cranking in restart' (address from the ECU's parameter ID */
    uint16_t fueling_shutdown_time_count;  /* +0x1a e2m Fuel_Temperature_Fuel_Shutdown_Time_Count [SEC] '[EPFTFSCU] Amount of time over fuel temperature fuel shutdown threshold' (was the flat row fuel_temperature_derate_fuel_shutdown_time_count) | earlier note: e2m 1152 +1A Fuel_Temperature_Fuel_Shutdown_Time_Count '[EPFTFSCU] Amount of time over fuel temperature fuel shutdown threshold' (address from the ECU's paramet */
    uint16_t engine_speed_shutdown_time_count;  /* +0x1c e2m Fuel_Temperature_RPM_Shutdown_Time_Count [SEC] '[EPFTRSCU] Amount of time over fuel temperature RPM shutdown threshold' (was the flat row fuel_temperature_derate_rpm_shutdown_time_count) | earlier note: e2m 1152 +1C Fuel_Temperature_RPM_Shutdown_Time_Count '[EPFTRSCU] Amount of time over fuel temperature RPM shutdown threshold' (address from the ECU's parameter */
    uint16_t fueling_start_warning_time;  /* +0x1e e2m Fuel_Temperature_Fuel_Start_Warning_Time [SEC] '[EPFTFLWN] Time to start of warning after fuel temp fuel error declared' */
    uint16_t engine_speed_start_warning_time;  /* +0x20 e2m Fuel_Temperature_RPM_Start_Warning_Time [SEC] '[EPFTRPWN] Time to start of warning after fuel temp RPM error declared' */
    uint16_t errors_allowed_timer;  /* +0x22 e2m Fuel_Temperature_Errors_Allowed_Timer [SEC] '[EPFTERTM] Time since RPM crossed fuel temperature start threshold' */
    uint16_t errors_allowed_timer_running;  /* +0x24 e2m Fuel_Temperature_Errors_Allowed_Timer_Running [UNITLESS] '[EPFTERFG] Flag indicating fuel temp. errors allowed timer is running' */
    engine_protection_fault_log_entry_t* fueling_fault_log_pointer;  /* +0x26 e2m Fuel_Temperature_Fuel_Fault_Log_Pointer [HEX] '[EPFTFLSA] Pointer to Fuel Temperature Fuel Fault Log Data' | points at the channel's EEPROM fault log (fuel temperature: fuel_temperature_engine_protection_*_fault_log_cal; typed in round 21 stage B) */
    engine_protection_fault_log_entry_t* engine_speed_fault_log_pointer;  /* +0x2a e2m Fuel_Temperature_RPM_Fault_Log_Pointer [HEX] '[EPFTRPSA] Pointer to Fuel Temperature RPM Fault Log Data' | points at the channel's EEPROM fault log (fuel temperature: fuel_temperature_engine_protection_*_fault_log_cal; typed in round 21 stage B) */
    engine_protection_fault_log_entry_t fueling_fault_log_entry;  /* +0x2e: a copy of the fueling fault log's current entry (both log helpers copy the 8 bytes here); e2m 1152 EPF_Input_Source_0_Fueling_Fault_Occurrence_Time / _Log_Value / _Log_Duration (were the fields fueling_fault_occurrence_time, fueling_fault_log_value, fueling_fault_log_duration in stage A) */
    engine_protection_fault_log_entry_t engine_speed_fault_log_entry;  /* +0x36: a copy of the engine speed fault log's current entry (both log helpers copy the 8 bytes here); e2m 1152 EPF_Input_Source_0_RPM_Fault_Occurrence_Time / _Log_Value / _Log_Duration (were the fields engine_speed_fault_occurrence_time, engine_speed_fault_log_value, engine_speed_fault_log_duration in stage A) */
};

struct engine_protection_channel_history_t {
    uint16_t fueling_severity_index;  /* +0x0 e2m Fuel_Temperature_Fueling_Index [UNITLESS] '[EPFTFLIX] Fuel temperature fueling severity index.' (was the flat row fuel_temperature_derate_fueling_severity_index_cal) | earlier note: e2m 1143 +0 Fuel_Temperature_Fueling_Index '[EPFTFLIX] Fuel temperature fueling severity index.' (1/256 per count; EEPROM mirror): word 0 of the 30-byte record */
    uint16_t engine_speed_severity_index;  /* +0x2 e2m Fuel_Temperature_RPM_Index [UNITLESS] '[EPFTRPIX] Fuel temperature RPM severity index.' (was the flat row fuel_temperature_derate_engine_speed_severity_index_cal) | earlier note: e2m Fuel_Temperature_RPM_Index [EPFTRPIX] (UNITLESS, 1/256, 0..1): fuel temperature RPM severity index. Word 1 of the per-channel record at 0x3fdfbe (stride 30, */
    uint16_t fueling_restart_severity_index;  /* +0x4 e2m Fuel_Temperature_Fueling_Restart_Index [UNITLESS] '[EPFTRYIX] Fuel temperature fueling restart severity index.' */
    uint16_t engine_speed_restart_severity_index;  /* +0x6 e2m Fuel_Temperature_RPM_Restart_Index [UNITLESS] '[EPFTRRIX] Fuel temperature RPM restart severity index.' */
    int16_t input_extremity;  /* +0x8 e2m Fuel_Temperature_Extremity [DEG_F] '[EPFTEX] Fuel temperature extremity (max)' */
    uint32_t input_extremity_time;  /* +0xa e2m Fuel_Temperature_Extremity_Time [UNITLESS] '[EPFTEXTM] Fuel temperature extremity time' */
    uint32_t fueling_fault_elapsed_time;  /* +0xe e2m Fuel_Temperature_Fueling_Fault_Elapse_Time [SEC] '[EPFTFFET] Total time fuel pres. fuel fault has been active' */
    uint32_t engine_speed_fault_elapsed_time;  /* +0x12 e2m Fuel_Temperature_RPM_Fault_Elapse_Time [SEC] '[EPFTRFET] Total time fuel temperature. rpm fault has been active' */
    uint16_t fueling_fault_log_flag;  /* +0x16 e2m Fuel_Temperature_Fueling_Fault_Log_Flag [UNITLESS] '[EPFTFLFG] Fault log recording flag for fuel temperature fueling' */
    uint16_t fueling_fault_log_index;  /* +0x18 e2m Fuel_Temperature_Fueling_Fault_Log_Index [UNITLESS] '[EPFTFLIN] Index into EPF fault log for Fuel temperature fueling' */
    uint16_t engine_speed_fault_log_flag;  /* +0x1a e2m Fuel_Temperature_RPM_Fault_Log_Flag [UNITLESS] '[EPFTRPFG] Fault log recording flag for fuel temperature RPM' */
    uint16_t engine_speed_fault_log_index;  /* +0x1c e2m Fuel_Temperature_RPM_Fault_Log_Index [UNITLESS] '[EPFTRPIN] Index into EPF fault log for fuel temperature RPM' */
};

struct j1939_pgn65251_payload_t {
    uint16_t engine_speed_at_idle_point_1;  /* SPN 188 engine speed at idle (point 1); J1939 byte order (low byte at +0): the send-on-change test reads it as one (byte-swapped) halfword */
    uint8_t percent_torque_at_idle_point_1;  /* SPN 539 percent torque at idle (point 1); +125 offset */
    uint8_t engine_speed_at_point_2_low_byte;  /* SPN 528 engine speed at point 2; low byte */
    uint8_t engine_speed_at_point_2_high_byte;  /* SPN 528; high byte (the test joins the two bytes) */
    uint8_t percent_torque_at_point_2;  /* SPN 540; +125 offset */
    uint16_t engine_speed_at_point_3;  /* SPN 529; J1939 byte order */
    uint8_t percent_torque_at_point_3;  /* SPN 541; +125 offset */
    uint16_t engine_speed_at_point_4;  /* SPN 530; J1939 byte order; at +9 (the test reads it with an unaligned halfword) */
    uint8_t percent_torque_at_point_4;  /* SPN 542; +125 offset */
    uint16_t engine_speed_at_point_5;  /* SPN 531; J1939 byte order */
    uint8_t percent_torque_at_point_5;  /* SPN 543; +125 offset */
    uint8_t engine_speed_at_high_idle_point_6_low_byte;  /* SPN 532 engine speed at high idle (point 6); low byte */
    uint8_t engine_speed_at_high_idle_point_6_high_byte;  /* SPN 532; high byte */
    uint16_t endspeed_governor_gain;  /* SPN 545 gain (Kp) of the endspeed governor: 0xffff (not available); initializePgn65251EngineConfiguration1Buffer writes it */
    uint16_t reference_engine_torque;  /* SPN 544 reference engine torque; J1939 byte order */
    uint16_t maximum_momentary_override_speed_point_7;  /* SPN 533 maximum momentary engine override speed (point 7); J1939 byte order */
    uint8_t maximum_momentary_override_time_limit;  /* SPN 534 maximum momentary override time limit */
    uint8_t requested_speed_control_range_lower_limit;  /* SPN 535 (10 rpm per bit) */
    uint8_t requested_speed_control_range_upper_limit;  /* SPN 536 (10 rpm per bit) */
    uint8_t requested_torque_control_range_lower_limit;  /* SPN 537; +125 offset (0x7d = 0 %) */
    uint8_t requested_torque_control_range_upper_limit;  /* SPN 538; +125 offset */
};

struct discrete_output_read_back_counters_t {
    uint8_t on_mismatch_count;  /* commanded on but reads off: passes */
    uint8_t off_mismatch_count;  /* commanded off but reads on: passes before the low fault bit sets */
    uint8_t high_fault_recovery_count;  /* passes with the read-back agreeing while the high fault is registered; it clears at the recovery threshold */
    uint8_t low_fault_recovery_count;  /* the same for the low fault */
};

struct j1939_pgn65249_payload_t {
    uint8_t retarder_type_and_location;  /* SPN 901 retarder type (bits 1-4) and SPN 902 retarder location (bits 5-8): 0x14 = exhaust (4) at the engine exhaust brake (1) for one engine_retarder_output_driver_count / 3 = compression release (3) at the engine compression release brake (0) for two or more / 0xff = not available */
    uint8_t retarder_control_method;  /* SPN 557 retarder control method: 0xff / 6 / 3 / 2 / 1 for engine_retarder_stage_1_weight 0 / 1 / 2 / 3 / 6 (6 divided by the weight); other weights leave it */
    uint8_t retarder_speed_at_idle_point_1_low_byte;  /* SPN 546 retarder speed at idle (point 1); low byte */
    uint8_t retarder_speed_at_idle_point_1_high_byte;  /* SPN 546; high byte */
    uint8_t percent_torque_at_idle_point_1;  /* SPN 551; 125 minus the high byte of the ROM percent word */
    uint8_t maximum_retarder_speed_point_2_low_byte;  /* SPN 548 maximum retarder speed (point 2); low byte */
    uint8_t maximum_retarder_speed_point_2_high_byte;  /* SPN 548; high byte */
    uint8_t percent_torque_at_maximum_speed_point_2;  /* SPN 552; 125 minus the percent */
    uint8_t retarder_speed_at_point_3_low_byte;  /* SPN 549; low byte */
    uint8_t retarder_speed_at_point_3_high_byte;  /* SPN 549; high byte */
    uint8_t percent_torque_at_point_3;  /* SPN 553; 125 minus the percent */
    uint8_t retarder_speed_at_point_4_low_byte;  /* SPN 550; low byte */
    uint8_t retarder_speed_at_point_4_high_byte;  /* SPN 550; high byte */
    uint8_t percent_torque_at_point_4;  /* SPN 554; 125 minus the percent */
    uint8_t retarder_speed_at_peak_torque_point_5_low_byte;  /* SPN 547 retarder speed at peak torque (point 5); low byte */
    uint8_t retarder_speed_at_peak_torque_point_5_high_byte;  /* SPN 547; high byte */
    uint8_t reference_retarder_torque_low_byte;  /* SPN 556 reference retarder torque; low byte */
    uint8_t reference_retarder_torque_high_byte;  /* SPN 556; high byte */
    uint8_t percent_torque_at_peak_torque_point_5;  /* SPN 555; 125 minus the percent */
};

struct j1939_pgn65259_payload_t {
    uint8_t make[5];  /* SPN 586 make: characters 1-5 of the component identification string at 0x3fd653 in the EEPROM mirror (CMMNS in the RAM dump) */
    uint8_t make_delimiter;  /* the '*' after the make */
    uint8_t model[17];  /* SPN 587 model: characters 6-22 of the same string (the field order follows the J1939-71 sequence make / model / serial number / unit number; the databases give no positions) */
    uint8_t model_delimiter;  /* the '*' after the model */
    uint8_t serial_number[8];  /* SPN 588 serial number: cm848_formatNumberAsDecimalText writes 8 decimal digits of the number at 0x3fd66a */
    uint8_t serial_number_delimiter;  /* the '*' after the serial number */
    uint8_t unit_number[10];  /* SPN 233 unit number (power unit): 10 characters from 0x3fd743 */
    uint8_t unit_number_delimiter;  /* the '*' that ends the message (data length 44) */
};

struct j1939_pgn65242_payload_t {
    uint8_t number_of_software_identification_fields;  /* SPN 965: 6 */
    uint8_t software_identification_field_1[8];  /* 8 decimal digits of the 4-byte number at 0x3fd69b (EEPROM 0x219) from cm848_formatNumberAsDecimalText */
    uint8_t software_identification_field_1_delimiter;  /* '*' */
    uint8_t software_identification_field_2[8];  /* 8 decimal digits of the 4-byte number at 0x3fd69f (EEPROM 0x21d) */
    uint8_t software_identification_field_2_delimiter;  /* '*' */
    uint8_t software_identification_field_3[12];  /* characters 10-21 of the string at 0x3fd6a5 (EEPROM 0x22d-0x238) */
    uint8_t software_identification_field_3_delimiter;  /* '*' */
    uint8_t calibration_version_number[8];  /* application_overlay_core_software_version (e2m 0019) as two decimal digits per byte (11460600 for V11.46.06) */
    uint8_t calibration_version_number_delimiter;  /* '*' */
    uint8_t ecm_identifier[2];  /* the two ASCII characters of ecm_hardware_type_identifier_cal (e2m 0000 ECM_Identifier) high byte first */
    uint8_t ecm_identifier_delimiter;  /* '*' */
    uint8_t application_identifier[2];  /* the two ASCII characters of application_identifier_cal (e2m 1292) high byte first */
    uint8_t application_identifier_delimiter;  /* the '*' that ends the message (data length 47) */
};

struct j1939_broadcast_transmit_session_t {
    uint8_t active;  /* 1 while the session runs: initiateJ1939TransportProtocol sets it / cm848_sendJ1939BroadcastDataPacket clears it after the last packet or a failed frame */
    uint8_t total_packet_count;  /* (message_size - 1) / 7 + 1 */
    uint16_t message_size;  /* the broadcast message's size in bytes (its descriptor's data_length) */
    uint16_t next_data_byte_number;  /* the 1-based number of the next data byte: 1 at the announce and +7 per packet (one sth; the last packet carries message_size - this + 1 bytes) */
    uint8_t next_packet_number;  /* the next packet's number: 1 at the announce */
    uint8_t frame_queue_status;  /* the result mpc555_sendJ1939SingleFrame writes for the last frame (0 queued / 1 zero length / 4 queue full) */
    byte* message_data_pointer;  /* the next data byte (the descriptor's data pointer; advanced per byte) */
    byte* session_status_pointer;  /* the message's status byte (the descriptor's status_pointer): 0x10 announced / 0x11 sending / 5 complete / the send result */
    uint16_t packet_delay_timer;  /* service passes until the next packet: 5 after each (0 while j1939_broadcast_no_packet_delay_flag is set) */
    uint32_t frame_can_id;  /* the CAN identifier of the next frame: the message's with PDU format 0xEC (TP.CM) for the announce then 0xEB (TP.DT) / destination 0xff */
    uint16_t frame_data_length;  /* data bytes of the next frame: 8 / the last packet's */
    byte* transmit_frame_pointer;  /* the frame assembly buffer (j1939_broadcast_transmit_frame_buffer_0 / _1; cm848_initializeJ1939Transport) */
    uint8_t unused[4];  /* no access found in the application transport (the records are 32 bytes apart) */
};
