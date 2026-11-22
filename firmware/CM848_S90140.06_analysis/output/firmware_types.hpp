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
    OVERRIDE_ACTIVE_126 = 0x7e,  /* Protection override mode active (~) */
    OVERRIDE_ACTIVE_127 = 0x7f  /* Protection override mode active (DEL) */
} PROTECTION_OVERRIDE;

typedef enum {
    FUELING_STATE_NOT_SELECTED = 0,  /* Cleared at the start of every pass by cm848_resetEngineOperatingMode; the selectors then run in call order 30 then 1 then 2 then 5 then 6 then 7 then 8 and each acts only while the mode is still 0 (first wins) - e2m label NOT_SET (CHR_CC_11.45.01.07 0x00) */
    FUELING_STATE_TSC1_TORQUE_CONTROL = 1,  /* cm848_setEngineOperatingMode1: J1939 TSC1 override control mode 2 (torque); the governor output is tsc1_torque_control_fueling - e2m label JCOMTORQ (CHR_CC_11.45.01.07 0x01) */
    FUELING_STATE_TSC1_SPEED_CONTROL = 2,  /* cm848_selectTsc1SpeedControlMode: J1939 TSC1 override control mode 1 (speed); the all-speed governor PID runs on tsc1_requested_speed_capped with the ROM coefficient record - e2m label JCOMSPED (CHR_CC_11.45.01.07 0x02) */
    FUELING_STATE_POWER_TAKE_OFF = 4,  /* operating_mode_governor_output.mode_code only (cm848_selectPowerTakeOffOrUserFueling): power_take_off_governor_fuel_demand replaces the user fueling while power_take_off_governor_active_flag is 1 and j1939_governor_feature_cal bit 0x10 is set (modes 5 / 6 always; 7 / 8 / 30 unless the user fuel is larger and governor_feature_config_word bit 0x2000 lets the throttle override). Code-proven: the governor's state goes out as J1939 SPN 976 (CCVS1) and OBD-II PID 0x1E - e2m label PTO (CHR_CC_11.45.01.07 0x04) */
    FUELING_STATE_CALIBRATED_FIXED_FUEL_DEMAND = 5,  /* cm848_selectUserCommandedFueling: bit 0 of engine_mode_control_flags (0 in every dump) makes the governor output a calibrated fuel demand; the feature behind it is not identified - e2m label USERCOMD (CHR_CC_11.45.01.07 0x05) */
    FUELING_STATE_ACCELERATOR_PEDAL_FAULT = 6,  /* cm848_transitionEngineOperatingMode: accelerator pedal input fault conditions; cm848_calculatePedalFaultModeFuelDemandAndSpeedLimit ramps the fuel only while the mode is 6 - e2m label LIMPHOME (CHR_CC_11.45.01.07 0x06) */
    FUELING_STATE_VARIABLE_SPEED_GOVERNOR = 7,  /* cm848_selectVariableSpeedGovernorMode: variable_speed_governor_selected_flag = 1; the pedal sets a speed request and the all-speed governor PID runs (dump: 7) - e2m label ASGTHROT (CHR_CC_11.45.01.07 0x07) */
    FUELING_STATE_DUAL_AXIS_FUEL_DEMAND_TABLE = 8,  /* cm848_initEngineOperatingState: left when no other selector claimed the pass; the governor output comes from cm848_calculateDualAxisFuelLimit (engine speed x tracked fuel demand tables) - e2m label FOUR_D (CHR_CC_11.45.01.07 0x08) */
    FUELING_STATE_CRUISE_CONTROL = 9,  /* governor_fuel_demand_working_mode only (cm848_selectCruiseOrUserFueling): cruise control is engaged and the cruise PID fuel cruise_control_fueling replaces the user fueling; cm848_selectCruiseGovernorGainSet and cm848_presetCruiseAndRoadSpeedGovernor run their cruise branches (cruise_control_state set / resume / accelerate / decelerate) in 9 - e2m label CRUISE (CHR_CC_11.45.01.07 0x09) */
    FUELING_STATE_ROAD_SPEED_GOVERNOR = 10,  /* adjusted_user_fueling_state (cm848_arbitrateGovernedFueling): the road speed governor fuel road_speed_governor_fueling (cm848_calculateRoadSpeedGovernorFueling: vehicle_speed_rise_limited - the vehicle speed - against road_speed_governor_reference_speed; no limit while j1939_governor_feature_cal bit 0x80 is clear) is the smallest demand; cm848_presetCruiseAndRoadSpeedGovernor runs the limit-minus-speed error in 10 - e2m label RSG (CHR_CC_11.45.01.07 0x0A) (was FUELING_STATE_VEHICLE_SPEED_LIMIT) */
    FUELING_STATE_LOW_SPEED_GOVERNOR = 11,  /* adjusted_user_fueling_state (cm848_arbitrateGovernedFueling and the initial value of cm848_initFuelFilterCoefficients): at or below the governor speed the low speed governor asks for more fuel than the selected demand (a max select); only in 11 does cm848_runLowSpeedGovernor write its fuel into adjusted_user_fueling (e2m FSGVFL: fueling as limited by limiting governors LSG / HSG) and low_speed_governor_active_flag latch. RAM dump: 11 - e2m label LSG (CHR_CC_11.45.01.07 0x0B) */
    FUELING_STATE_HIGH_SPEED_GOVERNOR = 12,  /* adjusted_user_fueling_state (cm848_arbitrateGovernedFueling): high_speed_governor_fueling is the smallest demand and becomes adjusted_user_fueling; runHighSpeedGovernorPid resets its integrator in 12 (the same compare as CM550 0x1ce7c on FSGVFLST) - e2m label HSG (CHR_CC_11.45.01.07 0x0C) */
    FUELING_STATE_TORQUE_DERATE_OVERRIDE = 13,  /* torque_derate_fuel_source_code (cm848_arbitrateRequestedFueling): while governor_feature_flags bit 0x10 is set the EEPROM limit torque_derate_override_fuel_quantity_cal (EEPROM 0x380) replaces the whole derate chain. Off in the dump: the flags are 0x1020 and the limit is 5888 - e2m label TRQDROVR (CHR_CC_11.45.01.07 0x0D) */
    FUELING_STATE_ALTITUDE_DERATE = 15,  /* torque_derate_fuel_source_code (cm848_applyAltitudeDerateFuelLimit): altitude_derate_fuel_limit - the engine speed x barometric pressure grids for cool / hot ambient air blended by ambient air temperature (or the air handling fault grid while an enabled boost / intake manifold pressure / barometric / intake air or ambient air temperature / wastegate fault is set); cm848_calculateAltitudeDerateFuelLimit - e2m label ALTDERAT (CHR_CC_11.45.01.07 0x0F) */
    FUELING_STATE_AIR_FUEL_CONTROL_DERATE = 16,  /* fuel_demand_minimum_tracked_state (cm848_applyAirFuelControlFuelLimit): air_fuel_control_fuel_limit - the engine speed x boost pressure grid air_fuel_control_fuel_limit_grid blended toward air_fuel_control_low_boost_fuel_limit_grid (cm848_calculateAirFuelControlFuelLimit). RAM dump: 16 (no boost at key on) - e2m label AFCDERAT (CHR_CC_11.45.01.07 0x10) */
    FUELING_STATE_MAXIMUM_THROTTLE = 19,  /* torque_derate_fuel_source_code starting value (cm848_initializeFuelLimitChains): throttle_100_fueling - cm848_calculateMaximumFuelCurve(engine speed / 400) is the fuel at full accelerator (400 = 100 %) - before any derate source takes over - e2m label MAXTHROT (CHR_CC_11.45.01.07 0x13) */
    FUELING_STATE_TSC1_TORQUE_LIMIT = 20,  /* torque_derate_fuel_source_code (cm848_applyTsc1TorqueLimit): J1939 TSC1 override control mode 3 with tsc1_torque_limit_fueling below the running derate - e2m label JCTRQDER (CHR_CC_11.45.01.07 0x14) */
    FUELING_STATE_CRANKING = 22,  /* final_fueling_state (cm848_selectFinalFueling): engine_state CRANKING / JUMP_START (or REENTRY with the command below it) - the fuel is crank_fuel - e2m label CRANK (CHR_CC_11.45.01.07 0x16) */
    FUELING_STATE_FUEL_OVERRIDE = 23,  /* final_fueling_state while governor_feature_flags bit 2 is set (user_override_fueling_cal) and injection_quantity_combustion_reference_source_code while combustion_override_and_estimation_enable_flags_cal bit 9 is set (injection_quantity_combustion_reference_override_value) - e2m label OVERRIDE (CHR_CC_11.45.01.07 0x17) */
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
    FUELING_STATE_FUEL_LIMIT_BY_RPM_AND_DEMAND = 42,  /* torque_derate_fuel_source_code (cm848_applyFuelLimitByRpmAndDemand): fuel_limit_by_rpm_and_demand - the alpha / chi blend of the engine speed x accelerator demand grids - computed only in the variable speed governor (engine_operating_mode 7) while injection_timing_enable_flags bit 0 is set - e2m label PTTHLM (CHR_CC_11.45.01.07 0x2A) */
    FUELING_STATE_TORQUE_MANAGEMENT = 45,  /* torque_derate_fuel_source_code (cm848_applyTorqueManagementFuelLimit): torque_management_fuel_limit - e2m label TORQMGMT (CHR_CC_11.45.01.07 0x2D) */
    FUELING_STATE_COOLANT_OVERHEAT_DERATE = 46,  /* torque_derate_fuel_source_code (cm848_applyCoolantOverheatFuelDerate): coolant_overheat_fuel_derate - the ramped smaller of the PI limit on the coolant temperature error and the engine speed limit of the coolant temperature buckets (cm848_runCoolantOverheatFuelDerate; enabled by engine_feature_enable_flags_cal bit 1) - e2m label CTDERAT (CHR_CC_11.45.01.07 0x2E) */
    FUELING_STATE_FREE_ACCELERATION = 47,  /* only compared (final_fueling_state) - never stored in this build - e2m label FREEACCL (CHR_CC_11.45.01.07 0x2F) */
    FUELING_STATE_UNIDENTIFIED_49 = 49,  /* only compared (final_fueling_state) - never stored in this build. OFC is the combustion reference's oxygen-fuel control (e2m CBR_OFC_*; code 58 OFCDERAT is its derate) - e2m label OFCSTATE (CHR_CC_11.45.01.07 0x31) */
    FUELING_STATE_UNIDENTIFIED_50 = 50,  /* only compared (final_fueling_state) - never stored in this build. AFR is the air-fuel ratio (e2m CBO_Air_Fuel_Ratio_Ref / CBP_Air_Fuel_Ratio) - e2m label AFRSTATE (CHR_CC_11.45.01.07 0x32) */
    FUELING_STATE_COMBUSTION_DENSITY_MAXIMUM = 52,  /* injection_quantity_combustion_gross_source_code (cm848_calculateCombustionGrossFuel): the density maximum (engine speed x compressor_inlet_density) limits the gross fuel - e2m label AIRDENLM (CHR_CC_11.45.01.07 0x34) */
    FUELING_STATE_COMBUSTION_CHI_MAXIMUM = 53,  /* injection_quantity_combustion_gross_source_code (cm848_calculateCombustionGrossFuel): the chi maximum fuel limits the gross fuel - e2m label CHIFULLM (CHR_CC_11.45.01.07 0x35) */
    FUELING_STATE_COMBUSTION_TEMPERATURE_HEADROOM = 54,  /* injection_quantity_combustion_reference_source_code (cm848_calculateCombustionFuelReference): injection_quantity_temperature_headroom_cap - e2m label TFCDERAT (CHR_CC_11.45.01.07 0x36) */
    FUELING_STATE_COMBUSTION_GROSS_FUEL_OVERRIDE = 55,  /* injection_quantity_combustion_gross_source_code: combustion_override_and_estimation_enable_flags_cal bit 10 - injection_quantity_combustion_gross_override_value - e2m label GROSSOVR (CHR_CC_11.45.01.07 0x37) */
    FUELING_STATE_COMBUSTION_OXYGEN_LIMIT = 58,  /* injection_quantity_combustion_reference_source_code (cm848_calculateCombustionFuelReference): injection_quantity_oxygen_limit - e2m label OFCDERAT (CHR_CC_11.45.01.07 0x3A) */
    FUELING_STATE_NET_TORQUE = 59,  /* fuel_demand_minimum_tracked_state (cm848_applyNetTorqueFuelLimit): net_torque_fuel_limit - a rate-limited engine speed fuel curve from the alpha / chi map blend of net_torque_fuel_limit_grid (cm848_calculateNetTorqueFuelLimit) while fault_feature_config_flags bit 2 is set - e2m label NETTORQ (CHR_CC_11.45.01.07 0x3B) */
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
    TIMER_CHANNEL_43 = 0x2b,  /* Timer channel 43 (DAT_003fcf3c) */
    TIMER_CHANNEL_44 = 0x2c,  /* Timer channel 44 (DAT_003fcf3e) */
    TIMER_CHANNEL_53 = 0x35  /* Timer channel 53 (DAT_003fcf40) */
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
    INJECTION_TIMING_INTERMEDIATE_SOURCE_OFFSET_MAPS = 0,  /* cm848_calculateInjectionTimingOffset: the timing offset comes from the two engine speed x fuel demand maps blended by the combustion alpha (engine_mode_control_flags bit 8 clear) */
    INJECTION_TIMING_INTERMEDIATE_SOURCE_FIXED_OFFSET_CALIBRATION = 2,  /* cm848_calculateInjectionTimingOffset: the fixed injection_timing_offset_cal while engine_mode_control_flags bit 8 is set */
    INJECTION_TIMING_INTERMEDIATE_SOURCE_PREVIOUS_VALUES_STORED = 25,  /* cm848_storeFuelDemandPreviousValues: one of the last tasks of every pass stores the compensated reference as the previous value */
    INJECTION_TIMING_INTERMEDIATE_SOURCE_COMBUSTION_MAXIMUM_LIMIT = 27,  /* cm848_applyCombustionTimingLimits: the timing reached the combustion maximum limit (cm848_calculateMainInjectionTiming turns it into 29) */
    INJECTION_TIMING_INTERMEDIATE_SOURCE_COMBUSTION_MINIMUM_LIMIT = 28  /* cm848_applyCombustionTimingLimits: the timing with the user increment is at or below the combustion minimum limit (becomes 30) */
} INJECTION_TIMING_INTERMEDIATE_SOURCE;

typedef enum {
    MAIN_INJECTION_TIMING_SOURCE_COLD_START_MAP = 5,  /* cm848_calculateMainInjectionTiming: the cold start engine speed x coolant temperature map while engine_state is ENGINE_STATE_CRANKING / ENGINE_STATE_JUMP_START / ENGINE_STATE_REENTRY */
    MAIN_INJECTION_TIMING_SOURCE_FIXED_OFFSET_CALIBRATION = 7,  /* cm848_updateMainInjectionTimingByDeliveryMode: injection_delivery_mode 2 uses the fixed injection_timing_offset_cal */
    MAIN_INJECTION_TIMING_SOURCE_INITIAL = 8,  /* cm848_initTimingFilterStates: the value before the first pass */
    MAIN_INJECTION_TIMING_SOURCE_DEMAND_FLOOR = 11,  /* cm848_calculateMainInjectionTiming: the demand was raised to injection_timing_demand_floor */
    MAIN_INJECTION_TIMING_SOURCE_BASE_COMMAND = 18,  /* cm848_calculateMainInjectionTiming: the sum of the base command and the components (combination mode 0) or the base command won the highest / lowest comparison */
    MAIN_INJECTION_TIMING_SOURCE_INTAKE_TEMPERATURE_COMPONENT = 19,  /* cm848_calculateMainInjectionTiming: the intake temperature component won (combination mode 1 / other) */
    MAIN_INJECTION_TIMING_SOURCE_COOLANT_COMPONENT = 20,  /* cm848_calculateMainInjectionTiming: the coolant component won */
    MAIN_INJECTION_TIMING_SOURCE_BAROMETRIC_PRESSURE_COMPONENT = 21,  /* cm848_calculateMainInjectionTiming: the barometric pressure component won */
    MAIN_INJECTION_TIMING_SOURCE_BOOST_COMPONENT = 22,  /* cm848_calculateMainInjectionTiming: the boost component won */
    MAIN_INJECTION_TIMING_SOURCE_GOVERNOR_LIMIT_MINIMUM = 23,  /* cm848_calculateMainInjectionTiming: raised to injection_timing_main_governor_limit_minimum while low_speed_governor_extended_idle_active_flag is set */
    MAIN_INJECTION_TIMING_SOURCE_WORKING_MINIMUM = 24,  /* cm848_calculateMainInjectionTiming: raised to injection_timing_demand_min_working */
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

/* ---- Structures ---- */

typedef struct j1939_rx_msg_t j1939_rx_msg_t;
typedef struct tsc1_payload_t tsc1_payload_t;
typedef struct pci_diagnostic_response_t pci_diagnostic_response_t;
typedef struct fuel_demand_control_t fuel_demand_control_t;
typedef struct transmission_control_flags_t transmission_control_flags_t;
typedef struct transmission_shift_strategy_flags_t transmission_shift_strategy_flags_t;
typedef struct transmission_pressure_state_t transmission_pressure_state_t;
typedef struct engine_crank_state_t engine_crank_state_t;
typedef struct fuel_pressure_governor_state_t fuel_pressure_governor_state_t;
typedef struct engine_speed_state_t engine_speed_state_t;
typedef struct sensor_readings_t sensor_readings_t;
typedef struct eeprom_header_t eeprom_header_t;
typedef struct low_speed_governor_reference_t low_speed_governor_reference_t;
typedef struct pci_link_state_t pci_link_state_t;
typedef struct fault_list_state_t fault_list_state_t;
typedef struct data_transfer_state_t data_transfer_state_t;
typedef struct diag_session_state_t diag_session_state_t;
typedef struct system_status_flags_t system_status_flags_t;
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
typedef struct scheduler_task_stat_t scheduler_task_stat_t;
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
typedef struct toucan_a_mb0_t toucan_a_mb0_t;
typedef struct toucan_a_mb1_t toucan_a_mb1_t;
typedef struct toucan_a_mb2_t toucan_a_mb2_t;
typedef struct qsmcm_sci1_regs_t qsmcm_sci1_regs_t;
typedef struct qsmcm_qspi_ctrl_t qsmcm_qspi_ctrl_t;
typedef struct qsmcm_recram_t qsmcm_recram_t;
typedef struct qsmcm_txram_t qsmcm_txram_t;
typedef struct keyon_flags_t keyon_flags_t;
typedef struct can_tx_ring_t can_tx_ring_t;
typedef struct diag_write_request_state_t diag_write_request_state_t;
typedef struct can_slot_range_t can_slot_range_t;
typedef struct can_rx_channel_t can_rx_channel_t;
typedef struct sys_init_flags_t sys_init_flags_t;
typedef struct eeprom_xfer_state_t eeprom_xfer_state_t;
typedef struct eeprom_block_tracking_t eeprom_block_tracking_t;
typedef struct j1939_tp_queue_t j1939_tp_queue_t;
typedef struct j1939_tp_pause_t j1939_tp_pause_t;
typedef struct diag_buf_b_ctrl_t diag_buf_b_ctrl_t;
typedef struct diag_buf_a_ctrl_t diag_buf_a_ctrl_t;
typedef struct boot_state_t boot_state_t;
typedef struct mios_mpiosm_t mios_mpiosm_t;
typedef struct mios1_isr_t mios1_isr_t;
typedef struct diag_clear_flags_t diag_clear_flags_t;
typedef struct dual_axis_table_dims_t dual_axis_table_dims_t;
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

struct fuel_demand_control_t {
    uint16_t calculated;  /* Final calculated fuel demand value */
    uint16_t idle_validation_state;  /* cm848_evaluateIdleValidationSwitches: 0 at-idle switch + pedal at idle / 1 off-idle switch + pedal above idle / 2 at-idle switch but pedal above the band / 3 off-idle switch but pedal below the band / 4 both switches + pedal outside the band / 5 no switch + pedal above the band / 6 no switch + pedal below the band / 7 equal switches + pedal inside the band / 8 valid pair + pedal between idle and the band edge (was mode) */
    uint16_t accelerator_off_idle;  /* 1 = accelerator demand off idle: idle validation states 1 / 3 / 5 / pedal sensor above threshold / J1939 SPN 558 / or speed-governor demand above cruise_governor_demand_enable_threshold_cal while fuel_demand_enable_flag; the EEC2 broadcast reports it as SPN 558 (was enable_flag) */
    uint16_t rate_limiter_state;  /* Rate limiter state machine value */
    uint16_t rate_delta;  /* Fuel demand rate of change delta */
    uint16_t throttle_based;  /* Throttle-based fuel demand component */
    uint16_t override_value;  /* Diagnostic override fuel demand value */
    uint16_t override_priority;  /* The priority of the throttle override that holds it: each claimer (cm848_claimAcceleratorInterlockThrottleOverride / cm848_claimRemoteThrottleOverride) takes the override when its priority is higher and writes override_value; 0 = no override (was override_active - not a 1 / 0 flag; round 5) */
    uint16_t rate_limited;  /* Rate-limited fuel demand output */
    uint16_t override_countdown;  /* Override timeout countdown (offset 0x12) */
    uint16_t reserved_14;  /* Gap/reserved (0x58e-0x590) */
    uint16_t reserved_16;  /* Gap/reserved (0x590-0x592) */
    uint16_t delta;  /* Fuel demand delta for rate calculations */
    uint16_t delta_filtered;  /* Filtered fuel demand delta */
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
    uint8_t limp_home_flags_4;  /* e2m 8C19 +8 RE_Limp_Flags4 'Contains transmission control limp-home mode flags'. Bits: 0x01 RE_Gov_Sensor_Limp_Offset / 0x04 RE_GCST_Limp ('a problem with the GCST circuit'; GCST is not expanded in the e2m or the DRB database): read with limp_home_flags_3 bit 0 by cm848_determineCurrentGearAndLockupInhibit, no writer in this build / 0x02 RE_Spd_Rat_Limp and 0x08 RE_Trans_Sump_Temp_Circuit: no writer or reader / 0x10 RE_Lockup_Converter_Clutch_Solenoid_Circuit: fault 141 P2769 (drops the transmission relay) / 0x20 RE_OSS_Limp: P0720, from cm848_monitorTransmissionOutputSpeedSensor | earlier note: Fault-active flags byte, updated with | / & masks (so a byte, not a bitfield: Ghidra 12.1 prints those updates as pieces). Bits: 0x01 unnamed: tested (& 1) in cm848_determineCurrentGearAndLockupInhibit (lbz @ 0x34370, .cpp 33439; ORed with reserved_07 bit 0 into transmission_shift_strategy_flags_t.limp_home_and_temperature_flags bit 0) but no store in either bank sets it | 0x04 unnamed: tested (& 4) together with bit 0 in the same place; never set | 0x10 fault 141 active: set / cleared every pass from fault_detected_bits_128_to_143 & 0x2000 = fault 141 in cm848_updateTransmissionLimpHomeFlags (stb @ 0x34eac; ROM 0x5985a slot 133 = P2769, a hint only); tested (& 0x10) in cm848_updateTransmissionRelayRequest (lbz @ 0x34a60), where it keeps logical output request 16 from being set | 0x20 output speed sensor fault active: set with fault 320 (P0720) and cleared with it in cm848_monitorTransmissionOutputSpeedSensor (stb @ 0x3dee4 / 0x3df60, | 0x20 / & 0xdf); read by cm848_calculateTransmissionOutputSpeed (lbz @ 0x3f768: substitutes vehicle_speed x the default or learned ratio), cm848_learnOutputSpeedToVehicleSpeedRatio (lbz @ 0x35e40: no learning while set) and cm848_updateTransmissionConditionFlags (lbz @ 0x34430: skips the transfer-case low-range test); bit 5 (0x20) = RE_OSS_Limp, set and cleared by the P0720 monitor (cm848_monitorTransmissionOutputSpeedSensor) */
    uint8_t low_range_boost_flags;  /* e2m 8C19 +9 RE_Low_Range_Boost_1_2 / RE_Low_Range_Boost_2_3 (the governor pressure is being raised to cause the 1-2 / 2-3 shift in low range): bits 0 / 1, cleared by cm848_initializeTransmissionShiftLogic (& 0xfc) */
};

struct transmission_shift_strategy_flags_t {
    uint8_t wide_open_throttle_flags;  /* e2m 8C19 +A WOT flags (RE_Trans_WOT / RE_WOT_Anti_Hang_Flag / RE_WOT_Boost_1_2 / RE_WOT_Boost_2_3 / RE_WOT_2LU_Flag / RE_WOT_2LU_Init_Flag / RE_WOT_Hung_Shift): bit 4 = the anti-hang timer is armed (RE_WOT_Anti_Hang_Flag), bits 3 / 5 go with the WOT 1-2 / 2-3 boosts (cm848_selectGovernorPressureWideOpenThrottle) | earlier note: Governor pressure / wide open throttle status byte, updated with | / & masks (so a byte, not a bitfield). Bits 0x10 / 0x08 are unproven guesses. Bits: 0x80 wide open throttle flag: mask 0x80: set by cm848_updateTransmissionConditionFlags when fuel_demand_control_t.calculated exceeds transmission_wide_open_throttle_set_threshold, cleared (& 0x1f, which also clears bits 5 and 6, and & 0x7f in cm848_initializeTransmissionControl) when it falls below transmission_wide_open_throttle_clear_threshold; cm848_runTransmissionControl calls cm848_selectGovernorPressureWideOpenThrottle only while it is set and the base / normal curve handlers otherwise (decompile line 32865). | 0x40 gear 1 pressure elevated flag: mask 0x40: set (| 0x40) with governor_pressure_wide_open_throttle_1_2_boost_pressure (status code 8) in gear 1; cleared (& 0xbf) when the pressure returns to the curve; read in the gear 2 branch to run the gear 1 learned gain update and cleared there by & 0xb7. | 0x20 gear 2 pressure elevated flag: mask 0x20: set (flags & 0xef | 0x20 / | 0x20) when governor_pressure_wide_open_throttle_2_3_boost_pressure is commanded (status code 10) in gear 2; cleared (& 0xdf) when the pressure returns to the curve; read in the gear 3 branch, where governor_pressure_wide_open_throttle_boost_timer == 0 triggers the gear 2 learned gain update and & 0x97 clears the elevation bits; also cleared in gear 1 (bVar3 = flags & 0xdf). | 0x10 unnamed: guess (not proven, so reserved): an elevation delay timer armed flag - mask 0x10: set (| 0x10) together with governor_pressure_wide_open_throttle_anti_hang_timer = governor_pressure_wide_open_throttle_anti_hang_time when engine speed sits between governor_pressure_wide_open_throttle_anti_hang_engine_speed and the margin; tested to wait for governor_pressure_wide_open_throttle_anti_hang_timer to reach 0 before the elevation; cleared (& 0xef) by the elevation. Medium confidence. | 0x08 unnamed: guess (not proven, so reserved): a pressure elevation by timer flag - mask 8, cm848_selectGovernorPressureWideOpenThrottle: set (flags & 0xef | 8, lines 32266-32267 / LAB_00031ba8) when the elevated target is applied after the delay timer ran out; cleared (& 0xf7) when the delay timer is armed; while it is set the gain learning of the gear 1 / gear 2 learned gain is skipped ((flags & 8) == 0 guards both learning blocks). Medium confidence. | 0x01 unnamed: no mask uses bit 0 in any of the 43 uses (0x97 / 0xb7 / 0xef / 0x1f / 0xdf / 0xbf / 0x7f only preserve it) */
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

struct engine_crank_state_t {
    uint16_t start_counter;  /* Engine start attempt counter */
    uint16_t crank_state;  /* Cranking state machine value */
    uint16_t cranking_flag;  /* Engine currently cranking flag (1=cranking) */
    uint16_t run_state;  /* Engine run state written by mpc555_updateEngineRunState - a different variable from engine_operating_mode */
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

struct sensor_readings_t {
    uint16_t intake_manifold_pressure;  /* Intake manifold (boost) absolute pressure - sensor_channel_filtered_output[1] - 1/18.56 kPa per count (0.0159 inHg); boost = this minus barometric_pressure (cm848_calculateBoostPressure); J1939 IC1 byte 2 / OBD-II intake manifold pressure; 1700 in the RAM dump with the engine stopped (was oil_pressure) */
    uint16_t coolant_temp;  /* Coolant temperature - sensor_channel_filtered_output[2] - 1/64 deg F per count; J1939 ET1 byte 1 (SPN 110) */
    uint16_t barometric_pressure;  /* Barometric pressure - sensor_channel_filtered_output[3] - 1/18.56 kPa per count; J1939 AMB byte 1 (SPN 108) / the reference subtracted for boost and oil pressure; 1647 (88.5 kPa) in the RAM dump (was intake_air_temp) */
    uint16_t battery_voltage;  /* Battery voltage - sensor_channel_filtered_output[4] - 1/16 V per count (192 = 12.0 V in the RAM dump); PCI 0xC0 byte 1 */
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

struct fault_list_state_t {
    uint16_t write_index;  /* Next write position in fault list */
    uint16_t read_index;  /* Current read position in fault list */
    uint16_t emission_count;  /* Count of emission-related faults */
    uint16_t total_emission_faults;  /* Total emission fault counter */
};

struct data_transfer_state_t {
    uint16_t byte_count;  /* Byte count */
    uint16_t buffer_write_enabled_flag;  /* Buffer write enabled flag */
    uint16_t largest_write_length;  /* Largest write length */
    uint16_t reserved_06;  /* Reserved */
    uint8_t pending_write_transport;  /* 1 = CAN / 2 = serial (was the high byte of the state word) */
    uint8_t finish_requested_flag;  /* Finish requested (was the low byte of the state word) */
    uint8_t flash_program_step;  /* Step 1-5 of cm848_runFlashProgramStateMachine (was the high byte of the status word) */
    uint8_t flash2_erase_state;  /* Medium confidence: 1 programmed / 2 erasing / 3 erased (was the low byte of the status word) */
};

struct diag_session_state_t {
    uint8_t session_flags;  /* Session flags */
    uint8_t response_write_index;  /* Response write index */
    void * response_cursor_pointer;  /* Cursor into diag_serial_buffer (stw r9,-4928(r10) @ 0x6788 stores 0x3fecf0) - the decompiler showed it as four byte stores */
};

struct system_status_flags_t {
    uint16_t fault_detected_bits_0_to_15;  /* Word 0 of fault-detected array 0x3fe974 (fault bit = word*16 + bit via ROM 0x5985a -> obd_dtc_code_table): b0 P0606 b5 P0341 b7 P0191 b8 P0238 boost-high b9 P0237 boost-low b10 P2123 b11 P2122 (was enable_state) */
    uint16_t fault_detected_bits_16_to_31;  /* Word 1 of fault-detected array 0x3fe974 (fault bit = word*16 + bit via ROM 0x5985a -> obd_dtc_code_table): b0 P0118 b1 P0117 coolant b3 P0113 b4 P0112 intake-temp b9 P0108 b10 P0107 baro b11 P0219 overspeed b13 P0500 VSS (was condition_monitor) */
    uint16_t fault_detected_bits_32_to_47;  /* Word 2 of fault-detected array 0x3fe974 (fault bit = word*16 + bit via ROM 0x5985a -> obd_dtc_code_table): b9 P0478 b10 P0477 - not a gap (was reserved_04) (Medium confidence) */
    uint16_t fault_detected_bits_48_to_63;  /* Word 3 of fault-detected array 0x3fe974 (fault bit = word*16 + bit via ROM 0x5985a -> obd_dtc_code_table): b6 P2267 b7 P2266 b8 P2269 water-in-fuel b9 P1221 b10 P1222 b12 P1223 b14 P2127 b15 P2121 pedal - b4/b5 (0x10/0x20) no code (was safety_bits_1) */
    uint16_t fault_detected_bits_64_to_79;  /* Word 4 of fault-detected array 0x3fe974 (fault bit = word*16 + bit via ROM 0x5985a -> obd_dtc_code_table): b0 P0236 b2 P0562 b3 P0563 system-voltage b4 P2128 b5 P1221 b6 P1222 b7 P1223 (was safety_bits_2) */
    uint16_t fault_detected_bits_80_to_95;  /* Word 5 of fault-detected array 0x3fe974 (fault bit = word*16 + bit via ROM 0x5985a -> obd_dtc_code_table): b2/b9/b10 P2509 (b2 = the previous run's power-down did not complete / b9 = more than consecutive_incomplete_power_down_limit of those in a row) b4 no DTC (0x3fdc8e non-zero at start) b11 P0606 (power_down_left_ecm_powered_flag_cal set) b12 P0335 crank b13 P0340 cam (was sensor_diag) */
    uint16_t fault_detected_bits_96_to_111;  /* Word 6 of fault-detected array 0x3fe974 - no OBD DTC slots (all map to 170) - internal fault bits eg b14 (0x4000) set on ETC1/cold-start timeout and cleared with its registered sibling 0x3fe9e4 - confirm b5 (0x20) role (was lamp_status) (Medium confidence) */
    uint16_t fault_detected_bits_112_to_127;  /* Word 7 of fault-detected array 0x3fe974 (fault bit = word*16 + bit via ROM 0x5985a -> obd_dtc_code_table): b5 P0016 crank-cam b9 P0480 fan b12 P0336 crank (was emission_faults) */
    uint16_t fault_detected_bits_128_to_143;  /* Word 8 of the fault-present bit array at 0x3fe974 (fault bit = word x 16 + bit): bit 0 any J1939 input timeout / bit 1 read by the J1939 pedal rate-limit check / bit 2 any J1939 input data error / bits 8-15 DTC slots 128-135 = P0883 P0882 P0974 P0973 P2770 P2769 P0588 P0587 (was reserved_10) */
    uint16_t fault_detected_bits_144_to_159;  /* Word 9 of fault-detected array 0x3fe974 (fault bit = word*16 + bit via ROM 0x5985a -> obd_dtc_code_table): b0 P0584 b1 P0583 vacuum b2 P0596 b3 P0595 servo-supply b4 P0850 park-neutral b5 P1762 governor b6 P0073 b7 P0072 ambient - not a gap (was reserved_12) */
    uint16_t fault_detected_bits_160_to_175;  /* Word 10 of fault-detected array 0x3fe974 - no OBD DTC slots (all map to 170) - internal fault bits eg b5 (0x20) set on EEPROM status-poll failure - registered sibling 0x3fe9ec (was system_faults) (Medium confidence) */
    uint16_t reserved_16;  /* Gap (0x3fe98a-0x3fe98f) */
    uint16_t fault_detected_bits_192_to_207;  /* Word 12 of fault-detected array 0x3fe974 (fault bit = word*16 + bit via ROM 0x5985a -> obd_dtc_code_table): b4 P0699 b5 P0698 sensor-reference - not a gap (was reserved_18) (Medium confidence) */
    uint16_t fault_detected_bits_208_to_223;  /* Word 13 of fault-detected array 0x3fe974 (fault bit = word*16 + bit via ROM 0x5985a -> obd_dtc_code_table): b10/b11 P0381 wait-to-start lamp - not a gap (was reserved_1a) (Medium confidence) */
    uint16_t reserved_1c;  /* Gap */
    uint16_t severity_flags;  /* Fault severity flags */
    uint16_t fault_detected_bits_256_to_271;  /* Word 16 of fault-detected array 0x3fe974 (fault bit = word*16 + bit via ROM 0x5985a -> obd_dtc_code_table): b12/b13/b15 P2146 injector supply voltage - not comm (was comm_faults) (Medium confidence) */
    uint16_t fault_detected_bits_272_to_287;  /* Word 17 of fault-detected array 0x3fe974 (fault bit = word*16 + bit via ROM 0x5985a -> obd_dtc_code_table): b0/b2/b3 P2146 b5/b6/b8/b9/b11/b12 P2149 injector supply b14 P0201 b15 P0202 injector 1/2 (was engine_status) */
    uint16_t fault_detected_bits_288_to_303;  /* Word 18 of fault-detected array 0x3fe974 (fault bit = word*16 + bit via ROM 0x5985a -> obd_dtc_code_table): b0 P0203 b1 P0204 b3 P0205 b4 P0206 injectors b6 P0541 b7 P0542 grid-heater b8 P2607 b9 P2608 b10 P0711 b11 P0868 b12 P0869 b13 P0713 b14 P0712 b15 P0088 (was pending_faults) */
    uint16_t fault_detected_bits_304_to_319;  /* Word 19 of fault-detected array 0x3fe974 at offset 0x26 (fault bit = word*16 + bit via ROM 0x5985a -> obd_dtc_code_table): b0 P0193 b1 P0192 rail pressure b14 P0604 b15 P1740 - not a gap and not offset 0x28 (was reserved_28) */
    uint16_t fault_detected_bits_320_to_335;  /* Word 20 of fault-detected array 0x3fe974 (fault bit = word*16 + bit via ROM 0x5985a -> obd_dtc_code_table): b0 P0720 output speed b8/b10 P0606 b9 P2146 b11 P2149 b12 P0234 overboost b13 P0251 b14 P2121 b15 P0336 (was protection_active) */
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
    uint16_t charge_flow_source;  /* e2m 177D +C Charge_Flow_Source: 0 primary / 1 backup */
    uint16_t fresh_air_mass_flow_filtered;  /* e2m 177B +0 Fresh_Air_Flow: the fresh air flow virtual sensor (lb/min) */
    uint16_t fresh_air_flow_source;  /* e2m 177B +2 Fresh_Air_Flow_Source: 0 primary / 1 backup */
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
    void * data_end_pointer;  /* Pointer one past the last payload byte */
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

struct scheduler_task_stat_t {
    uint32_t total_ticks;  /* Cumulative execution time in timer ticks */
    uint16_t call_count;  /* Number of times task has been executed */
    uint16_t min_time;  /* Minimum execution time (initialized to 0xFFFF) */
    uint16_t max_time;  /* Maximum execution time observed */
    uint16_t overrun_count;  /* Number of deadline overruns detected */
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
    uint8_t etc2_transmission_selected_gear;  /* e2m 10E8 +27 J1939_Selected_Gear (UNITLESS): 'J1939 ETC2 Selected Gear'. J1939 ETC2 (PGN 61445) byte 1 = SPN 524 transmission selected gear - stored by the ETC2 handler at 0x22c5c when DLC is 8; 0xFF at init or when etc2_selected_gear_timeout (ETC2 timeout) expires; 0xFB or 0x7D sets transmission_park_or_neutral_flag; RAM dump 0xFF (was etc1_address_filter) */
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

struct toucan_a_mb0_t {
    uint16_t CTRL;  /* Message Buffer 0 Control/Status (code+DLC+flags) */
    uint16_t ID_HI;  /* Message Buffer 0 ID High (bits 28-16) */
    uint16_t ID_LO;  /* Message Buffer 0 ID Low (bits 15-0) */
    uint16_t DATA0;  /* Message Buffer 0 Data bytes 0-1 */
    uint16_t DATA2;  /* Message Buffer 0 Data bytes 2-3 */
    uint16_t DATA4;  /* Message Buffer 0 Data bytes 4-5 */
    uint16_t DATA6;  /* Message Buffer 0 Data bytes 6-7 */
    uint16_t _pad;  /* Reserved (timestamp) */
};

struct toucan_a_mb1_t {
    uint16_t CTRL;  /* Message Buffer 1 Control/Status */
    uint16_t ID_HI;  /* Message Buffer 1 ID High */
    uint16_t ID_LO;  /* Message Buffer 1 ID Low */
    uint16_t DATA0;  /* Message Buffer 1 Data bytes 0-1 */
    uint16_t DATA2;  /* Message Buffer 1 Data bytes 2-3 */
    uint16_t DATA4;  /* Message Buffer 1 Data bytes 4-5 */
    uint16_t DATA6;  /* Message Buffer 1 Data bytes 6-7 */
    uint16_t _pad;  /* Reserved (timestamp) */
};

struct toucan_a_mb2_t {
    uint16_t CTRL;  /* Message Buffer 2 Control/Status */
    uint16_t ID_HI;  /* Message Buffer 2 ID High */
    uint16_t ID_LO;  /* Message Buffer 2 ID Low */
    uint16_t DATA0;  /* Message Buffer 2 Data bytes 0-1 */
    uint16_t DATA2;  /* Message Buffer 2 Data bytes 2-3 */
    uint16_t DATA4;  /* Message Buffer 2 Data bytes 4-5 */
    uint16_t DATA6;  /* Message Buffer 2 Data bytes 6-7 */
    uint16_t _pad;  /* Reserved (timestamp) */
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

struct can_tx_ring_t {
    uint32_t j1939_tx_write_ptr;  /* J1939 TX queue write pointer (12-byte records base 0x3022E6) */
    uint32_t j1939_tx_read_ptr;  /* J1939 TX queue read pointer */
    uint32_t can_rx_write_ptr;  /* CAN RX queue write pointer (18-byte records base 0x302016) */
    uint32_t can_rx_read_ptr;  /* CAN RX queue read pointer */
    uint32_t _pad16;  /* Reserved */
    uint32_t toucan_mb_ptr;  /* Active TouCAN mailbox base pointer for diagnostic session */
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

struct sys_init_flags_t {
    uint16_t init_sentinel;  /* System initialization sentinel (0xBBBB = fully initialized) */
    uint16_t init_counter;  /* System initialization counter (zeroed at startup) */
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

struct j1939_tp_queue_t {
    uint16_t session_pgn;  /* Active J1939 TP queue session PGN (0xEF__ format) */
    uint8_t queue_status2;  /* J1939 TP queue entry count (number of packets in queue) */
    uint8_t range_start;  /* J1939 TP batch range start index (incremented by batch size) */
    uint8_t queue_ptr;  /* J1939 TP remaining packet pointer (decremented by batch size) */
    uint8_t _pad5;  /* Reserved */
    uint16_t total_bytes;  /* Total data bytes for TP queue session */
    uint32_t data_buf_ptr;  /* Pointer to source data buffer for queue TP session */
    uint32_t state_ptr;  /* Pointer to session status byte (J1939 TP state codes) */
    uint16_t retry_timer;  /* CTS retry countdown timer (nominal 0x37 ticks) */
    uint32_t can_header;  /* CAN frame header word (PGN 0xEC00 RTS or 0xEB00 DT) */
    uint16_t packet_size;  /* Bytes in current CTS packet grant (max 8) */
    uint32_t tx_buf_ptr;  /* Pointer to CAN TX assembly buffer (0x30306D) */
};

struct j1939_tp_pause_t {
    uint16_t pause_pgn;  /* J1939 DataRequest session PGN (0xEF00) */
    uint16_t _pad2;  /* Reserved */
    uint16_t pause_timer;  /* Pause session countdown (0x70 init / 0x19 per packet) */
    uint32_t pause_data;  /* First dword of DataRequest CAN frame copy */
    uint16_t data_count;  /* Number of QADC data items in DataRequest */
    uint32_t rx_buf_ptr;  /* Pointer to CAN RX data assembly buffer (0x303075) */
};

struct diag_buf_b_ctrl_t {
    uint16_t service_count;  /* Service count/size parameter for buffer B */
    uint32_t data_ptr;  /* Pointer to start of buffer B data area (0x30293F) */
    uint32_t end_ptr;  /* Pointer to end of buffer B data area (0x303055) */
};

struct diag_buf_a_ctrl_t {
    uint16_t service_count;  /* Service count/size parameter for buffer A */
    uint32_t data_ptr;  /* Pointer to start of buffer A data area (0x303065) */
    uint32_t end_ptr;  /* Pointer to end of buffer A data area (0x303064) */
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

struct dual_axis_table_dims_t {
    uint16_t row_count;  /* Number of first-axis (RPM) breakpoints */
    uint16_t col_count;  /* Number of second-axis (fuel) breakpoints */
};

struct j1939_ccss_tx_payload_t {
    uint8_t max_vehicle_speed_limit;  /* SPN 74 Maximum Vehicle Speed Limit (km/h); from maximum_road_speed; gate j1939_governor_feature_cal&0x80 */
    uint8_t cruise_high_set_limit_speed;  /* SPN 87 Cruise Control High Set Limit Speed (km/h); gate j1939_governor_feature_cal&0x40; fed by cruise_maximum_road_speed_cal */
    uint8_t cruise_low_set_limit_speed;  /* SPN 88 Cruise Control Operator Low Set Limit Speed (km/h); from DAT_0005c28a */
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
    uint32_t fault_bit_index;  /* Bit index into the fault-enable bitmask and the fault confirmation arrays (0x1f for most entries) */
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
    uint8_t transmission_relay_request : 1;  /* bit 0: e2m 1577 +2 0x01 Transmission_VFS_Battery_Driver (12A7 +0x10 Transmission_VFS_Battery_Driver_Priority): the battery feed of the transmission solenoids. output 16 = the transmission control relay (mask 1). cm848_mainLoopMonitor checks output 16 with diag_faultMatch_outputCheck_update(0x10,0x16,0x88,0x89,...): faults 136 / 137 = P0883 / P0882 'TCM power input signal high / low' (the relay output voltage), and fault 137 sets the e2m 8C19 bit RE_Trans_Relay_Circuit_Open ('transmission power relay is open-circuit'). cm848_updateTransmissionRelayRequest requests it (cm848_setLogicalOutputRequest(0x10,0)) only while the engine is not stopped and none of the relay / solenoid circuit limp bits is set. The solenoid diagnostics (the governor pressure solenoid read-back debounce in cm848_debounceOutputReadBackFaults, the output checks of outputs 17 / 18) and the governor pressure monitors run only while it is set (was reserved_bit_0) | earlier note: guess (not proven, so reserved): a transmission solenoid enable request; the old note said transmission relay */
    uint8_t overdrive_solenoid_request : 1;  /* bit 1: e2m 1577 +2 0x02 Transmission_Overdrive_Driver. output 17 (mask 2). cm848_processOverdriveSwitchAndShift sets it with cm848_setLogicalOutputRequest(0x11,0) together with transmission_3_4_transition_timer and clears it on the overdrive release; read with mask 2 in cm848_monitorConverterClutchAndOverdrivePerformance and cm848_determineCurrentGearAndLockupInhibit. */
    uint8_t converter_clutch_solenoid_request : 1;  /* bit 2: e2m 1577 +2 0x04 Transmission_TCC_Driver. output 18 (mask 4, about 30 uses). cm848_applyConverterLockupSchedule sets it (cm848_setLogicalOutputRequest(0x12,0)); cm848_applyConverterUnlockConditions, cm848_applyConverterUnlockConditionsLowRange and cm848_processOverdriveSwitchAndShift clear it (cm848_clearLogicalOutputRequest(0x12,0)). */
    uint8_t cruise_vent_solenoid_request : 1;  /* bit 3: e2m 1577 +2 0x08 Cruise_Vent_Driver. output 19 (mask 8): cm848_setLogicalOutputRequest(0x13,...) in cm848_controlCruiseVacuumServo (decompile line 41596); wave 2 identified requests 19 / 20 / 21 as cruise vent / vacuum / servo supply. No direct read of this mask. */
    uint8_t cruise_vacuum_solenoid_request : 1;  /* bit 4: e2m 1577 +2 0x10 Cruise_Vacuum_Driver. output 20 (mask 0x10): cm848_setLogicalOutputRequest(0x14,...) in cm848_controlCruiseVacuumServo (decompile line 41602). No direct read of this mask. */
    uint8_t cruise_servo_supply_request : 1;  /* bit 5: e2m 1577 +2 0x20 Cruise_SC_Source_Driver. output 21 (mask 0x20): cm848_setLogicalOutputRequest(0x15,...) in cm848_controlCruiseVacuumServo (decompile line 41584); mask 0x20 is read by cm848_deriveSecondBrakeSwitchSignal and diag_faultMatch_outputCheck_update (the supply runs through the brake switch). */
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
    uint16_t reserved_bit_0 : 1;  /* bit 0: e2m Idle_Speed_Save_Enable (LSISSVEN, saves the last idle speed at shutdown). No reader in either bank (sweep of both banks). Clear in this calibration (0x2e06). */
    uint16_t reserved_bit_1 : 1;  /* bit 1: e2m Overspeed_FSO_Override (EPOSFSO, fuel shut-off valve on overspeed). No reader in either bank (sweep of both banks). Set in this calibration (0x2e06). */
    uint16_t water_in_fuel_enable : 1;  /* bit 2: e2m Water_In_Fuel_Enable (WFAGEN). cm848_sendPgn65279WaterInFuelIndicatorMessage (lhz at 0x26ea0: the PGN 65279 byte stays 0xff while clear) and cm848_monitorWaterInFuel (lhz at 0x5103b8: clears fault 56 bit 0x100 while clear). Code agrees with the e2m label. Set in this calibration (0x2e06). */
    uint16_t air_fuel_control_override_enable : 1;  /* bit 3: e2m AFC_Override_Enable (AFENMAN). cm848_calculateAirFuelControlFuelLimit (lhz 24(r26) at 0xdcf4): while clear it computes the limit from air_fuel_control_fuel_limit_grid, so set overrides it. Code agrees. Clear in this calibration (0x2e06). */
    uint16_t electronic_smart_power_enable : 1;  /* bit 4: e2m ESP_Enable (SPAGEN; ESP = Electronic Smart Power per e2m Group_ESP_8). hpcr_calculateFuelTrimOutput (lhz at 0xe71c) and cm848_calculateThrottle100Fuelings (lhz at 0x1f290): while set the four_dimensional_fueling_interpolation_factor is zeroed around cm848_calculateMaximumFuelCurve. A reader exists but its behaviour is not tied to the e2m label. Clear in this calibration (0x2e06). */
    uint16_t reserved_bit_5 : 1;  /* bit 5: e2m Reverse_ESP_Enable (SPRVEN, Electronic Smart Power launch application). No reader in either bank (sweep of both banks). Clear in this calibration (0x2e06). */
    uint16_t low_speed_governor_droop_enable : 1;  /* bit 6: e2m LSG_Droop_Enable (LSDPEN). cm848_updateProtectionParameters (lhz at 0x20b90) and governor_calculateIntegratorRpmOutput (lhz at 0x507a70): while set the governor integrator output is reduced by governor_integrator_correction_term times ROM 0x5c352 divided by 167 (a droop). Code agrees. Clear in this calibration (0x2e06). */
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
    uint16_t reserved_bit_2 : 1;  /* bit 2: e2m DR_Enable (DREN, driver reward). No reader in either bank (sweep of both banks). Clear in this calibration (0x0008). */
    uint16_t reserved_bit_3 : 1;  /* bit 3: guess (not proven, so reserved): duty cycle monitor enable - e2m DC_Mon_Enable (DCMNEN, duty cycle monitor). cm848_updateDutyCycleMonitorLoadHistogram (lhz at 0x5063a0, mask 8); the reader name agrees, the body was not read. Set in this calibration (0x0008). */
    uint16_t reserved_bit_4 : 1;  /* bit 4: no e2m name. No reader in either bank (sweep of both banks). Clear in this calibration (0x0008). */
    uint16_t reserved_bit_5 : 1;  /* bit 5: no e2m name. No reader in either bank (sweep of both banks). Clear in this calibration (0x0008). */
    uint16_t reserved_bit_6 : 1;  /* bit 6: e2m AC_Smart_Enable (ACEN, smart air compressor). No reader in either bank (sweep of both banks). Clear in this calibration (0x0008). */
    uint16_t executive_timing_enable : 1;  /* bit 7: e2m Executive_Timing_Enable (SSECTMEA, executive timing data gatherer). main_loop (lhz 36(r29) at 0xc0c0, 0xc140, 0xc7b8); the reader agrees by name. Clear in this calibration (0x0008). */
    uint16_t high_speed_governor_gear_ratio_gain_enable : 1;  /* bit 8: e2m HSG_Gear_Ratio_Gain_Enable (HSGRGSEN). cm848_loadHighSpeedGovernorWorkingGainSet (lhz at 0x4248c); the reader agrees by name. Clear in this calibration (0x0008). */
    uint16_t programmable_power_enable : 1;  /* bit 9: e2m Programmable_Power_Enable (PPEN). 6 fuel limit, protection and cruise functions: cm848_calculateDualAxisFuelLimit (0x1ec88, 0x1ed88, 0x1ee74), cm848_calculateThrottle100Fuelings (0x1f194), cm848_initializeJ1939ReferenceEngineFuelingAndTorque (0x212e0), cm848_calculateJ1939TorqueCurveFuelingsAndReferenceFuelings (0x21d1c), cm848_updateCruiseAndRoadSpeedGovernorDroops (0x524bdc), cm848_presetCruiseAndRoadSpeedGovernor (0x52544c); the names agree, the bodies were not read. Clear in this calibration (0x0008). */
    uint16_t reserved_bit_10 : 1;  /* bit 10: no e2m name. No reader in either bank (sweep of both banks). Clear in this calibration (0x0008). */
    uint16_t reserved_bit_11 : 1;  /* bit 11: e2m Cruise_Control_AR_Enable (AREN, cruise control auto resume). No reader in either bank (sweep of both banks). Clear in this calibration (0x0008). */
    uint16_t remote_throttle_enable : 1;  /* bit 12: e2m Remote_Throttle_Enable (CTRMTHEN). cm848_j1939BuildEngineControlByte (0x256ac), cm848_buildPgn61443ElectronicEngineController2Message (0x25cbc), cm848_claimRemoteThrottleOverride (0x50e62c), cm848_clearEngineProtectionFaultsConditional (0x50e784); the names agree, the bodies were not read. Clear in this calibration (0x0008). */
    uint16_t reserved_bit_13 : 1;  /* bit 13: guess (not proven, so reserved): remote throttle transition verification enable - e2m Remote_Throttle_Transition_Verification_Enable (CTRTTZEN). cm848_claimRemoteThrottleOverride (lhz at 0x50e6e4); the name agrees, the body was not read. Clear in this calibration (0x0008). */
    uint16_t engine_retarder_service_brake_activate_enable : 1;  /* bit 14: e2m EB_Service_Brake_Activate_Enable (EBBREN, EB = engine brake). Proven in PR #53 round 17: its only reader, cm848_updateEngineRetarderAllowedState (lhz at 0x41610), lets the driver conditions pass while it is set only after a service brake tap (service_brake_recently_applied_flag) or with a cruise non-override command (was reserved_bit_14). Clear in this calibration (0x0008). */
    uint16_t reserved_bit_15 : 1;  /* bit 15: e2m EB_Rate_Limit_Enable (EBRTLMEA, engine brake level rate limit). No reader in either bank (sweep of both banks). Clear in this calibration (0x0008). */
};

struct algorithm_enable_flags_41_t {
    uint16_t engine_retarder_speed_limit_enable : 1;  /* bit 0: no e2m name; code only. cm848_updateEngineRetarderAllowedState (lhz at 0x41848), cm848_calculateEngineRetarderSelectionPercent (0x41998) and cm848_updateEngineRetarderActiveState (0x41e5c): while low_speed_governor_extended_idle_active_flag is set and this bit is set the retarder selection percent is forced to 100 and engine_retarder_active_flag stays 0. Clear in this calibration (0x7ca6). */
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
    uint16_t reserved_bit_11 : 1;  /* bit 11: guess (not proven, so reserved): torque normalization enable - e2m Torque_Normalization_Enable. cm848_calculateJ1939ReferenceEngineFueling (lhz at 0x20504) and cm848_calculateJ1939TorqueCurveFuelingsAndReferenceFuelings (lhz 82(r29) at 0x21db4); the reader names do not tie to the e2m text, so the name is e2m only. Set in this calibration (0x7ca6). */
    uint16_t reserved_bit_12 : 1;  /* bit 12: guess (not proven, so reserved): full throttle cold fuel increment enable - e2m Throttle_100_Cold_Increment_Enable. cm848_calculateThrottle100Fuelings (lhz 82(r29) at 0x1f1a4); the name agrees, the body was not read. Set in this calibration (0x7ca6). */
    uint16_t reserved_bit_13 : 1;  /* bit 13: guess (not proven, so reserved): air fuel control cold fuel increment enable - e2m AFC_Cold_Increment_Enable. cm848_calculateAirFuelControlFuelLimit (lhz 82(r26) at 0xe064), which also reads the air fuel control override bit of algorithm_enable_flags_12_cal; the name agrees, the body was not read. Set in this calibration (0x7ca6). */
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
    uint8_t driver_asic_shutoff_request : 1;  /* bit 6: output 54 (mask 0x40): e2m 1577 +6 ASIC_FS_Shutoff_Driver (FS is not expanded; not output 30 FSO_Command, which cm848_processProtectionFaultsAndTiming requests every pass). Shuts off the output driver ASIC: the fuel system fault reactions request it - fault reaction mask bit 3 (cm848_updateFuelPressureFaultReactionRequests), fuel pressure too high with fuel_pressure_too_high_logical_output_request_enable (cm848_applyFuelLimitsForFuelPressureFaults), fault 388 excess fuel demand (fuel_quantity_demand_monitor); fuel_quantity_demand_initialize clears it. While it or supervisor_register_36_bit_1_low_held_flag is set, the output read-back debounce, the injector and fuel metering feedback diagnostics and the fault scan stand down (was fuel_shutoff_request, earlier injector_driver_asic_shutoff_request) */
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
