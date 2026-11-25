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
    BASIC_DELAY = 0,  /* Basic timer + delay with watchdog (can1TimerBufferInit) */
    ALT_TRANSMIT = 1,  /* Alt timer + message transmit init (can1TimerBufferInitAlt) */
    DIVIDED_TRANSMIT = 2,  /* Divided timer + message transmit init 2 (can1TimerBufferInitDivided) */
    CONDITIONAL_DELAY = 3  /* Conditional timer + watchdog delay 2 (can1TimerBufferInitConditional) */
} CAN_TIMER_INIT_MODE;

typedef enum {
    CAN_STATUS_BYTE = 0x36,  /* CAN message status byte offset */
    PARAM_BYTE_1 = 0x37,  /* First parameter byte offset */
    PARAM_BYTE_2 = 0x38,  /* Second parameter byte offset */
    PARAM_BYTE_3 = 0x39  /* Third parameter byte offset */
} CAN_BUFFER_OFFSETS;

typedef enum {
    VP44_FUEL_TEMP = 16,  /* VP44 fuel temperature message */
    ALTERNATIVE_MSG = 17,  /* Alternative message handler */
    THIRD_MSG = 19,  /* Third message handler */
    ERROR_DEFAULT = 255  /* Error/default case message */
} CAN_MSG_TYPE;

typedef enum {
    VP44_CMD_BUILDER = 1,  /* vp44Command0x100Builder function (0x2a418) */
    CONFIG_BUILDER = 2  /* configParamCanBuilder function (0x2a57e) */
} CAN_PARAM_BUILDERS;

typedef enum {
    FSO_CIRCUIT_STATUS_BIT0 = 0x01,  /* VP44 FSO circuit status bit 0 - when set indicates normal operation */
    FSO_CIRCUIT_STATUS_BIT1 = 0x02,  /* VP44 FSO circuit status bit 1 - redundant FSO monitoring */
    STATUS_BIT2 = 0x04,  /* VP44 status bit 2 */
    STATUS_BIT3 = 0x08,  /* VP44 status bit 3 */
    STATUS_BIT4 = 0x10,  /* VP44 status bit 4 - affects fuel timing control */
    STATUS_BIT5 = 0x20,  /* VP44 status bit 5 */
    STATUS_BIT6 = 0x40,  /* VP44 status bit 6 */
    STATUS_BIT7 = 0x80  /* VP44 status bit 7 */
} VP44_STATUS_BITS;

typedef enum {
    ENGINE_IDLE = 1,  /* Engine idle/startup mode */
    LOW_RPM_RUNNING = 2,  /* Low RPM running mode */
    HIGH_RPM_RUNNING = 3,  /* High RPM running mode */
    VP44_INJECTION_ACTIVE = 4,  /* VP44 injection system active mode */
    HIGH_PERFORMANCE = 5,  /* High performance/load mode */
    TRANSITIONAL_MODE_6 = 6,  /* Transitional operating mode 6 */
    TRANSITIONAL_MODE_7 = 7,  /* Transitional operating mode 7 */
    FAULT_EMERGENCY = 8  /* Fault/emergency mode */
} ENGINE_OPERATING_MODE;

typedef enum {
    VP44Handler = 16,  /* VP44 pump communication handler */
    DiagParamRequestHandler = 17,  /* Alternative handler for parameter requests */
    StatusRequestHandler = 19,  /* Third handler for status/diagnostic requests */
    ErrorDefaultHandler = 255  /* Error/default case handler */
} DIAGNOSTIC_MESSAGE_TYPES;

typedef enum {
    FUEL_HIGH_BYTE = 1,  /* Fuel amount high byte (param_table_aux>>8 + 125) */
    FUEL_LOW_BYTE = 2,  /* Fuel amount low byte (param_table_main>>8 + 125) */
    RESERVED_ZERO_1 = 3,  /* Reserved/zero byte 3 */
    RESERVED_ZERO_2 = 4,  /* Reserved/zero byte 4 */
    TIMING_BYTE1 = 5,  /* Injection timing advance (byte 5) */
    TIMING_BYTE2 = 6,  /* Injection timing advance (byte 6) */
    RPM_LOW_BYTE = 7,  /* Engine RPM×4 low byte (current_engine_rpm & 0xFF) */
    RPM_HIGH_BYTE = 8  /* Engine RPM×4 high byte (current_engine_rpm >> 8) */
} VP44_DATA_FIELDS;

typedef enum {
    CAN_CONTROLLER_MAIN = 0,  /* Primary CAN controller (SSCNLTOB) */
    CAN_CONTROLLER_1 = 1  /* Secondary CAN controller 1 (SSC1LTOB) */
} DUAL_CAN_CONTROLLERS;

typedef enum {
    J1939_SOURCE_ADDR_1 = 1,  /* J1939 source address 1 (JCSA1) */
    J1939_SOURCE_ADDR_2 = 2,  /* J1939 source address 2 (JCSA2) */
    J1939_SOURCE_ADDR_3 = 3,  /* J1939 source address 3 (JCSA3) */
    J1939_SOURCE_ADDR_4 = 4,  /* J1939 source address 4 (JCSA4) */
    J1939_SOURCE_ADDR_5 = 5  /* J1939 source address 5 (JCSA5) */
} DUAL_CAN_J1939_SOURCE_ADDR;

typedef enum {
    DATA_PLATE_BLOCK = 0,  /* Data plate identifier block */
    PRIMARY_BLOCK = 9  /* Main parameter memory block (PTESLOLM etc.) */
} EEPROM_MEMORY_BLOCKS;

typedef enum {
    MultiDimensionalTableSupport = 1,  /* 5-stage table interpolation system confirmed */
    StructuredParameterSystem = 2,  /* EEPROM → Tables → CAN flow */
    TimingTableSupport_4DTBTA = 3,  /* 4D timing base table advance parameter */
    FuelMappingIntegration = 4  /* Integration with throttle/parameter systems */
} EFILIVE_COMPATIBILITY;

typedef enum {
    SCALE_FACTOR = 3,  /* Base interpolation scaling */
    SHIFT_BITS = 8,  /* Bit shift amount for scaling */
    WORD_MULTIPLIER = 256  /* Word-size multiplication factor */
} INTERPOLATION_FACTORS;

typedef enum {
    CruiseControlReceiveEnable_JCCNRXFT = 1,  /* CCVS message reception filter (0x07F0FEF1) */
    CruiseControlMessageEnable_JCCCBCEA = 2,  /* Enable cruise control/vehicle speed message processing */
    SpeedControlStatus_JCRPGVSS = 3,  /* Speed control status (1=SPEED_CONTROL_MODE 0=NORMAL) */
    SpeedControlBrakingInteraction_JCRDTXEA = 4  /* Enable speed control/engine braking interaction */
} J1939_CRUISE_CONTROL_ENABLE;

typedef enum {
    CalTermCommunication = 1,  /* CalTerm parameter read/write via J1939 */
    InsiteCommunication = 2,  /* Insite live data monitoring via J1939 */
    DiagnosticMessageDispatcher = 3,  /* Routes diagnostic requests by message type */
    J1939ParamRequestHandler = 4,  /* Processes EEPROM parameter read requests */
    ParameterResponseBuilder = 5  /* Formats parameter values for J1939 response */
} J1939_DIAGNOSTIC_PROTOCOL;

typedef enum {
    TorqueSpeedControlReceiveEnable_JCCNRXFT = 1,  /* TSC1 message reception enable (0x07F00400) */
    JC39ENFG = 2,  /* J1939 message enable flags table */
    J1939_THROTTLE_ENABLE_AS01CF = 3,  /* ASG throttle mode compensation filter coef. 1 */
    J1939_THROTTLE_ENABLE_AS02CF = 4,  /* ASG throttle mode compensation filter coef. 2 */
    J1939_THROTTLE_ENABLE_AS03CF = 5  /* ASG throttle mode compensation filter coef. 3 */
} J1939_THROTTLE_ENABLE;

typedef enum {
    PHASE_0_VP44_RPM = 0,  /* Even: VP44 engine management + RPM control */
    PHASE_1_ENGINE_FUEL = 1,  /* Odd: Engine control + RPM fuel limiter */
    PHASE_2_DIAG_AUX = 2,  /* Even: Diagnostic + Auxiliary + Advanced protection */
    PHASE_3_SLOW_CYCLES = 3,  /* Odd: SlowCycle 4/8/10/20 coordinators */
    PHASE_4_BOOST_DIAG = 4,  /* Even: VP44 + Boost + Diagnostic monitoring */
    PHASE_5_EPS_SLOW20 = 5,  /* Odd: Engine + EPS monitoring + SlowCycle20 ext */
    PHASE_6_FUEL_CALC = 6,  /* Even: Diagnostic + IO + Fuel calc + Kickdown */
    PHASE_7_SHUTDOWN = 7,  /* Odd: SlowCycle4 + Shutdown protection + Trending */
    PHASE_8_DIAG_COMM = 8,  /* Even: VP44 + Diagnostic comm + Fuel smoke */
    PHASE_9_CAM_TIMING = 9,  /* Odd: Engine + Diagnostic data + Cam sync + Timing arb */
    PHASE_10_DERATE = 10,  /* Even: Diagnostic + RPM + Derate protection */
    PHASE_11_VP44_PROT = 11,  /* Odd: SlowCycle4/8 + RPM limiter + VP44 protection */
    PHASE_12_FSO_FRIC = 12,  /* Even: VP44 + Boost + FSO detection + Frictional load */
    PHASE_13_DIAG_FAULT = 13,  /* Odd: Engine + SlowCycle10 + VP44 diagnostic fault */
    PHASE_14_FSO_MON = 14,  /* Even: Diagnostic + Diagnostic monitoring + FSO fault */
    PHASE_15_EPS_TIMING = 15,  /* Odd: SlowCycle4 + EPS + Timing calc + VP44 timing + Protection */
    PHASE_16_DZG_TIMING = 16,  /* Even: VP44 + IO control + DZG timing */
    PHASE_17_OUTPUT_CTRL = 17,  /* Odd: Engine + Shutdown + Mode-based output */
    PHASE_18_DIAG_TEMP = 18,  /* Even: Diagnostic + Auxiliary + VP44 diag + Fuel temp */
    PHASE_19_DIAG_STATS = 19,  /* Odd: SlowCycle4/8 + Diagnostic data + Stats */
    PHASE_20_RPM_VP44 = 20,  /* Even: VP44 + Boost + RPM + VP44 control */
    PHASE_21_EXT_FAULT = 21,  /* Odd: Engine + Boost + RPM limiter + VP44 ext fault */
    PHASE_22_ADV_PROT = 22,  /* Even: Diagnostic + Secondary + Advanced protection */
    PHASE_23_SLOW_ALL = 23,  /* Odd: SlowCycle 4/8/10/20 all */
    PHASE_24_FUEL_TIME = 24,  /* Even: VP44 + Diagnostic monitoring + Fuel timing */
    PHASE_25_EPS_EXT = 25,  /* Odd: Engine + EPS monitoring + SlowCycle20 ext */
    PHASE_26_IO_FUEL = 26,  /* Even: Diagnostic + IO control + Fuel calc */
    PHASE_27_SENSOR_HIST = 27,  /* Odd: SlowCycle4/8 + Shutdown + Sensor history */
    PHASE_28_SMOKE_LIM = 28,  /* Even: VP44 + Boost + Diagnostic comm + Smoke limiter */
    PHASE_29_CAM_SYNC = 29,  /* Odd: Engine + Diagnostic data + Cam sync */
    PHASE_30_DERATE2 = 30,  /* Even: Diagnostic + RPM + Derate protection */
    PHASE_31_VP44_PROT2 = 31,  /* Odd: SlowCycle4 + RPM limiter + VP44 protection */
    PHASE_32_FSO_DET = 32,  /* Even: VP44 + Secondary + FSO detection */
    PHASE_33_DIAG_MON = 33,  /* Odd: Engine + SlowCycle10 + VP44 diag fault */
    PHASE_34_FSO_MON2 = 34,  /* Even: Diagnostic + Auxiliary + FSO fault monitoring */
    PHASE_35_EPS_EMPTY = 35,  /* Odd: SlowCycle4/8 + EPS + Empty placeholder */
    PHASE_36_DZG_IO = 36,  /* Even: VP44 + Boost + IO control + DZG timing */
    PHASE_37_OUTPUT2 = 37,  /* Odd: Engine + Shutdown + Mode-based output */
    PHASE_38_VP44_DIAG = 38,  /* Even: Diagnostic + Diagnostic comm + VP44 control */
    PHASE_39_FINAL = 39  /* Odd: SlowCycle4 + Diagnostic data + Stats (returns to 0) */
} MAIN_LOOP_PHASE;

typedef enum {
    CAN_BUFFER_1 = 1,  /* CAN parameter message buffer 1 (0x803066) */
    CAN_BUFFER_2 = 2,  /* CAN parameter message buffer 2 (0x803056) */
    CAN_BUFFER_3 = 3,  /* CAN parameter message buffer 3 (0x80306e) */
    CAN_BUFFER_4 = 4  /* CAN parameter message buffer 4 (0x80303e) */
} MC68336_CAN_BUFFERS;

typedef enum {
    J1922_PROTOCOL = 0,  /* J1922 network protocol selection */
    J1939_PROTOCOL = 1  /* J1939 network protocol selection */
} NETWORK_TYPE_SELECTION;

typedef enum {
    LOOKUP_1 = 1,  /* param_lookup_1 function (0xd632) */
    LOOKUP_2 = 2,  /* param_lookup_2 function (0xd69c) */
    LOOKUP_3 = 3  /* param_lookup_3 function (0xd756) */
} PARAM_ACCESS_FUNCTIONS;

typedef enum {
    DMA_ENABLE = 0x80000000,  /* DMA channel enable flag */
    DMA_CHAIN_MODE = 0x40000000,  /* DMA descriptor chaining enabled */
    DMA_INTERRUPT_ENABLE = 0x20000000,  /* DMA completion interrupt enable */
    DMA_AUTO_RELOAD = 0x10000000  /* DMA auto-reload descriptor */
} DMA_CONTROL_FLAGS;

typedef enum {
    DMA_SINGLE_TRANSFER = 0,  /* Single data transfer mode */
    DMA_BLOCK_TRANSFER = 1,  /* Block transfer mode */
    DMA_BURST_TRANSFER = 2,  /* Burst transfer mode */
    DMA_CONTINUOUS = 3  /* Continuous transfer mode */
} DMA_TRANSFER_MODES;

typedef enum {
    MODULE_EN = 0x454E,  /* Cummins EN module family (CM550 VP44 ECUs) */
    MODULE_AN = 0x4E41,  /* Hypothetical AN module family */
    MODULE_DE = 0x4445  /* Hypothetical DE module family */
} CUMMINS_MODULE_IDS;

typedef enum {
    VARIANT_A = 0x41,  /* InCal calibration variant A */
    VARIANT_B = 0x42,  /* InCal calibration variant B */
    VARIANT_C = 0x43  /* InCal calibration variant C (ENC) */
} INCAL_VARIANTS;

typedef enum {
    BLOCK_MULTIPLIER = 256  /* Parameter block size multiplier */
} PARAM_BLOCK_SIZE;

typedef enum {
    EEPROM_TO_TABLE = 1,  /* EEPROM parameter → memory table */
    TABLE_TO_BUFFER = 2,  /* Memory table → CAN buffer */
    BUFFER_TO_NETWORK = 3  /* CAN buffer → J1939 transmission */
} PARAM_CAN_FLOW;

typedef enum {
    ActiveParameterRead = 1,  /* Active EEPROM parameter reading mode */
    CachedParameterRead = 11,  /* Cached parameter value retrieval */
    SpecialParameterHandling = 12  /* Special parameter processing mode */
} PARAMETER_SYSTEM_MODES;

typedef enum {
    DWORD_SHIFT = 2,  /* 32-bit addressing (lsll #2) */
    BLOCK_SHIFT = 8  /* Block×256 calculation (lsll #8) */
} PARAM_SHIFT_OPERATIONS;

typedef enum {
    SAFETY_LIMIT = 32000,  /* Maximum allowed parameter value */
    BLOCK_LIMIT = 65535  /* Block validation limit (Block × 65535) */
} PARAM_VALIDATION;

typedef enum {
    RPM_DIRECT = 1,  /* Direct RPM value (no scaling) */
    RPM_HALF = 2,  /* RPM divided by 2 */
    RPM_QUARTER = 4  /* RPM divided by 4 (lsll #2) */
} RPM_SCALING;

typedef enum {
    CRANKING_RPM_LIMIT = 125,  /* Cold crank sync determination limit (CSCDESTR) */
    RUNNING_RPM_THRESHOLD = 300,  /* Engine considered running threshold (CSCKES) */
    PTO_MIN_RPM = 700,  /* PTO minimum RPM setpoint (PTESLOLM) */
    PTO_MAX_RPM = 3000,  /* PTO maximum RPM setpoint (PTESHILM) */
    ASG_MAX_RPM = 3000  /* ASG maximum allowed speed (ASTLMNMX) */
} ENGINE_RPM_LIMITS;

typedef enum {
    FSMXTHFL = 1,  /* Fueling value at 100% throttle (param_lookup_3) */
    ASTHRFES = 2,  /* ASG reference speed based on throttle position (param_lookup_2) */
    JCTHKCTD = 3  /* JCOMM throttle kickdown threshold (param_lookup_3) */
} THROTTLE_PARAMS;

typedef enum {
    BYTE_OFFSET = 6,  /* Data byte position in VP44 message */
    FUEL_TEMP_OFFSET = 112  /* Fuel temperature sensor offset */
} VP44_SENSOR_OFFSETS;

typedef enum {
    DERATE_ACTIVE = 0x80,  /* Derate condition is active */
    DERATE_BIT6 = 0x40,  /* Derate status bit 6 - maps to INSITE bit 0x40 */
    DERATE_BIT5 = 0x20,  /* Derate status bit 5 - maps to INSITE bit 0x20 */
    DERATE_STATUS_BIT3 = 0x08,  /* Derate status bit 3 - maps to INSITE status 0x20 */
    DERATE_STATUS_BIT2 = 0x04  /* Derate status bit 2 - maps to INSITE status 0x40 */
} DERATE_STATUS_BITS;

typedef enum {
    SECURED_WRITE = 3,  /* Secured write operations (requires security check) */
    SYSTEM_CONTROL = 4,  /* System control operations */
    MEMORY_ACCESS = 5,  /* Memory read/write operations */
    SPECIAL_CONTROL = 6,  /* Special timing/control functions */
    SECURED_COMMANDS = 0x03,  /* Secured commands - requires systemSecurityCheck (always passes) */
    MEMORY_OPERATIONS = 0x05,  /* Memory read/write with CRC validation */
    RETRY_CONTROL = 0x06,  /* Transmission retry control (subfunction 0x74) */
    FUEL_ARBITRATOR = 0x4A,  /* fuelArbitratorControlService - fuel system control */
    EXTENDED_4C = 0x4C,  /* extendedDiagnosticService4C */
    SERVICE_79_EXTENDED = 0x4F,  /* extendedDiagnosticService4F */
    SERVICE_81_EXTENDED = 0x51  /* extendedDiagnosticService51 */
} DIAG_SERVICE_ID;

typedef enum {
    ENTER_DEVELOPMENT_MODE = 0x40,  /* enterDevelopmentMode after the security key (was SWITCH_TO_FACTORY_BANK - J90280.05 read it as a calibration bank switch; PR #53 round 74) */
    FORCE_EXIT_DEVELOPMENT_MODE = 0x41,  /* forceExitDevelopmentMode after the security key (was FORCE_ACTIVE_BANK; PR #53 round 74) */
    HIGH_RPM_SHUTDOWN_ACTIVATE = 0x42,  /* Activate high RPM shutdown flag (activateHighRpmShutdownFlag) */
    SYSTEM_RESET_TRIGGER = 0x43,  /* Trigger diagnostic system reset (triggerDiagnosticSystemReset) */
    NOP_ACK = 0x50,  /* No operation - returns success (0) */
    MEMORY_PATCH = 0x51,  /* RAM patching system (memoryPatchingSystem) */
    SECURED_SHUTDOWN_REQUEST = 0x52,  /* Request secured shutdown (requestSecuredShutdown) */
    UNSUPPORTED_ERROR = 0x53,  /* Unsupported operation - returns error code 4 */
    CAN_BUFFER_LOGGER = 0x54  /* CAN message buffer logger (canMessageBufferLogger) */
} DIAG_SECURED_SUBFUNC;

typedef enum {
    SYSTEM_CONTROL_100 = 0x64,  /* System control function 100 (systemControl64) */
    FAULT_SCANNER_ENABLE = 0x65,  /* Enable fault flag scanner (enableFaultFlagScanner) */
    CLEAR_COMMAND_STATE = 0x66,  /* Clear diagnostic_command_state to 0 */
    EXIT_DEVELOPMENT_MODE = 0x69,  /* exitDevelopmentMode (was SWITCH_TO_ACTIVE_BANK; PR #53 round 74) */
    RESERVED_112 = 0x70,  /* Reserved - returns error code 4 */
    SET_COMMAND_STATE_BIT0 = 0x71,  /* Set bit 0 of diagnostic_command_state */
    RESERVED_114 = 0x72,  /* Reserved - returns error code 4 */
    SET_COMMAND_STATE_BIT1 = 0x73,  /* Set bit 1 of diagnostic_command_state */
    SYSTEM_CONTROL_116 = 0x74,  /* System control function 116 (systemControl74) */
    SYSTEM_CONTROL_117 = 0x75,  /* System control function 117 (systemControl75) */
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
    MEM_READ_2BYTE_4BYTE = 0x43,  /* Memory read: 2-byte param + 4-byte offset (diagMemoryReadService43Handler) */
    MEM_READ_2BYTE_ONLY = 0x46,  /* Memory read: 2-byte param only (diagMemoryReadService46Handler) */
    MEM_READ_2BYTE_4BYTE_4BYTE = 0x48,  /* Memory read: 2-byte + 4-byte + 4-byte params (diagMemoryReadService48Handler) */
    MEM_READ_4BYTE_1BYTE = 0x4A,  /* Memory read: 4-byte address + 1-byte length (diagMemoryReadService4aHandler) */
    MEM_READ_4BYTE_4BYTE = 0x4C,  /* Memory read: 4-byte address + 4-byte length (diagMemoryReadService4cHandler) */
    EXTENDED_SERVICE_79 = 0x4F,  /* Extended diagnostic service 0x4F */
    EXTENDED_SERVICE_81 = 0x51  /* Extended diagnostic service 0x51 */
} DIAG_EXTENDED_SVC;

typedef enum {
    RESET_MODE = 0,  /* Reset/clear arbitrator state */
    RPM_TARGET_MODE = 1,  /* Set RPM target mode */
    THROTTLE_PCT_MODE = 2,  /* Throttle percentage control mode */
    FUEL_LIMIT_MODE = 3,  /* Fuel limit control mode */
    MODE_RESET = 0x00,  /* Reset fuel arbitrator - clear all targets and modes */
    MODE_RPM_TARGET = 0x01,  /* RPM target mode - set target RPM from diagnostic command */
    MODE_FUEL_PERCENT = 0x02,  /* Fuel percentage mode - control fuel delivery percentage */
    MODE_TORQUE_CMD = 0x03  /* Torque command mode - direct torque control */
} FUEL_ARB_MODE;

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
    ASTHRFES_CALC = 0x5C,  /* ASTHRFES calculation input (scaled >>7) */
    PARAM_DISPLAY_VALUE = 0x64,  /* INSITE parameter display value (scaled >>6) */
    DIAGNOSTIC_SENSOR = 0x66,  /* Diagnostic sensor reading (scaled >>4 max 0xFF) */
    INTAKE_MANIFOLD_TEMP = 0x69,  /* Intake manifold temp (offset 0x1900 scaled >>7) */
    DIAGNOSTIC_READING = 0x6C,  /* INSITE diagnostic reading (scaled >>3) */
    THROTTLE_RAW = 0x6E,  /* Throttle position raw (offset 0x1900 scaled >>7) */
    RETARDER_MODE_STATUS = 0x79,  /* Retarder mode threshold status */
    RESERVED_9C = 0x9C,  /* Reserved two-byte response */
    RESERVED_9D = 0x9D,  /* Reserved two-byte response */
    ECU_COMMAND_SELECTOR = 0xA6,  /* ECU command selector high/low bytes */
    RETARDER_INPUT = 0xA8,  /* Retarder input value (>>1 + *2) */
    RESERVED_AF = 0xAF,  /* Reserved two-byte response */
    CLUTCH_OPERATING_STATS = 0xB6,  /* Clutch operating statistics output */
    FUEL_STATISTICS_CMD = 0xB7,  /* Fuel statistics command value */
    FUEL_ECONOMY_STATS = 0xB8,  /* Fuel economy statistics output */
    CLUTCH_TRANSITIONS = 0xB9,  /* Clutch transitions per distance */
    OIL_PRESSURE_THRESHOLD = 0xBB,  /* Oil pressure RPM limit threshold (scaled >>1) */
    GOVERNOR_RPM_ERROR = 0xBC,  /* Governor RPM error value (scaled >>1) */
    AC_HIGH_PRESSURE = 0xBD,  /* AC high pressure switch (scaled >>1) */
    CURRENT_RPM_RAW = 0xBE,  /* Current engine RPM raw (scaled >>1) */
    ACTIVE_FAULT_LIST = 0xC1,  /* Active fault list builder (insiteActiveFaultListBuilder) */
    FAULT_DETAIL = 0xC2,  /* Fault detail builder (insiteFaultDetailBuilder) */
    LIVE_DATA_PARAM = 0xC4,  /* Live data parameter with lookup state */
    ECU_ID_RESPONSE = 0xEA,  /* ECU ID response builder (insiteEcuIdResponseBuilder) */
    RUNTIME_HOURS = 0xEB,  /* Runtime hours accumulator (/0x708) */
    COMMAND_BASE_VALUE = 0xEC,  /* INSITE command base value (4 bytes) */
    CAPACITY_RESPONSE = 0xED,  /* Capacity response builder (insiteCapacityResponseBuilder) */
    VERSION_INFO = 0xF3,  /* Version info builder (insiteVersionInfoBuilder) */
    VEHICLE_DISTANCE_CLUTCH = 0xF4,  /* Vehicle distance clutch value (proportional calc) */
    VEHICLE_DISTANCE_STATS = 0xF5,  /* Vehicle distance statistics value (proportional calc) */
    VEHICLE_HOURS_STATS = 0xF7,  /* Vehicle hours statistics value (/0x708) */
    IDLE_HOURS = 0xF8,  /* INSITE idle hours accumulator (/0x708) */
    FUEL_STATS_OUTPUT = 0xFA  /* INSITE fuel statistics output */
} INSITE_PARAM_CODE;

typedef enum {
    PROTECTION_ENABLED = 0x80,  /* Protection system enable flag is set */
    DERATE_BIT2_SET = 0x40,  /* Derate status byte bit 2 (0x04) is set */
    DERATE_BIT3_SET = 0x20,  /* Derate status byte bit 3 (0x08) is set */
    SENSOR_BIT1_SET = 0x10,  /* Sensor status register bit 1 (0x02) is set */
    SENSOR_BIT0_SET = 0x08,  /* Sensor status register bit 0 (0x01) is set */
    SENSOR_BIT3_SET = 0x04,  /* Sensor status register bit 3 (0x08) is set */
    SENSOR_BIT2_SET = 0x02,  /* Sensor status register bit 2 (0x04) is set */
    SENSOR_BIT4_SET = 0x01  /* Sensor status register bit 4 (0x10) is set */
} INSITE_STATUS_OUTPUT;

typedef enum {
    SINGLE_PARAM = 0x00,  /* Single parameter request */
    EXTENDED_PARAM = 0x80,  /* Extended parameter request */
    PID_DTC_REQUEST = 0xC3,  /* PID/DTC diagnostic request */
    PID_DTC_ACK = 0xC4  /* PID/DTC acknowledgment */
} INSITE_COMMAND;

typedef enum {
    SUCCESS = 0,  /* Operation successful */
    DIAG_INVALID_LENGTH = 2,  /* Invalid message length */
    SECURITY_FAILED = 3,  /* Security check failed */
    BUFFER_OVERFLOW = 4,  /* Buffer overflow or unsupported */
    ADDR_VALIDATION_FAIL = 8,  /* Address validation failed */
    INVALID_ADDR_RANGE = 9,  /* Invalid address range */
    INVALID_ADDR_ALT = 10,  /* Invalid address range (alternate) */
    CHECKSUM_MISMATCH = 0x14,  /* Checksum mismatch */
    UNKNOWN_SUBFUNC = 0x18  /* Unknown sub-function - default error in diagnosticServiceDispatcher */
} J1939_DIAGNOSTIC_RESULT;

typedef enum {
    SUCCESS_RESPONSE = 0x0C,  /* Operation successful - no error code follows */
    STATUS_RESPONSE = 0x0D  /* Error/status response - error code follows in byte 1 */
} CAN_MULTIPACKET_RESPONSE;

typedef enum {
    CORE_SERVICE_ENABLE = 0x01,  /* Core diagnostic service enable */
    INSITE_ENABLE = 0x02,  /* Insite live data enable */
    EXTENDED_ENABLE = 0x04,  /* Extended diagnostics enable (0x45-0x56) */
    CORE_SERVICES = 0x01,  /* Enable services 0x03-0x06 (secured memory ops diagnostic control) */
    INSITE_LIVE = 0x02,  /* Enable services 0x80+ (Insite live data monitoring insiteLiveDataHandler) */
    EXTENDED_SERVICES = 0x04,  /* Enable services 0x45-0x56 (fuel arbitrator extended diagnostics) */
    SPECIAL_MODE = 0x08  /* Special diagnostic mode (checked in multiple functions) */
} DIAG_ENABLE_FLAGS;

typedef enum {
    SENSOR_STATUS_BIT4 = 0x10,  /* Sensor status bit 4 - maps to INSITE output 0x01 */
    SENSOR_STATUS_BIT3 = 0x08,  /* Sensor status bit 3 - maps to INSITE output 0x04 */
    SENSOR_STATUS_BIT2 = 0x04,  /* Sensor status bit 2 - maps to INSITE output 0x02 */
    SENSOR_STATUS_BIT1 = 0x02,  /* Sensor status bit 1 - maps to INSITE output 0x10 */
    SENSOR_STATUS_BIT0 = 0x01  /* Sensor status bit 0 - maps to INSITE output 0x08 */
} SENSOR_STATUS_BITS;

typedef enum {
    BYPASS_FLAG_ENABLED = 0xFF,  /* Security checks completely bypassed */
    BYPASS_MAGIC = 0xB522,  /* Alternative bypass magic value (-0x4ADE signed) */
    SECURITY_ACTIVE = 0x00  /* Normal security - checks enforced */
} SECURITY_BYPASS_FLAG;

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
    SERVICE_SECURED_WRITE = 3,  /* Secured write operations (length=3) */
    SERVICE_SYSTEM_CONTROL = 4  /* System control operations (length=3) */
} SECURED_SERVICE_ID;

typedef enum {
    INIT = 0,  /* Initialize transmission - setup buffers and addresses */
    WRITE_BUFFER = 1,  /* Write buffer data with circular buffer */
    VP44_COMMUNICATION_TRANSMIT = 2,  /* Execute circular buffer write transmission */
    VP44_COMM_IDLE = 3  /* Idle/complete - transmission inactive */
} VP44_COMM_STATE;

typedef enum {
    VP44_COMMUNICATION_IDLE = 0,  /* Idle mode - transition to state 3 */
    VP44_COMMUNICATION_ACTIVE = 1,  /* Active mode - perform mid-buffer transmission */
    VP44_COMMUNICATION_RESET = 2  /* Reset mode - transmit to end address and reset pointers */
} VP44_COMM_MODE;

typedef enum {
    STATUS_BIT15 = 0x8000,  /* VP44 status flag bit 15 - checked in fuel control */
    STATUS_BIT14 = 0x4000,  /* VP44 status flag bit 14 - protection mode check */
    STATUS_BIT13 = 0x2000,  /* VP44 status flag bit 13 */
    STATUS_BIT12 = 0x1000,  /* VP44 status flag bit 12 */
    STATUS_BIT11 = 0x0800,  /* VP44 status flag bit 11 */
    STATUS_BIT10 = 0x0400  /* VP44 status flag bit 10 */
} VP44_STATUS_FLAGS_1;

typedef enum {
    OVERRIDE_FUEL_MODE = 0x08  /* VP44 override fuel mode active */
} VP44_STATUS_FLAGS_2;

typedef enum {
    FLAG_BIT14 = 0x4000  /* VP44 flag register bit 14 - fuel control decision */
} VP44_FLAG_REGISTER_1;

typedef enum {
    DIAG_FLAG_BIT14 = 0x4000,  /* Diagnostic flag bit 14 */
    DIAG_FLAG_BIT13 = 0x2000,  /* Diagnostic flag bit 13 */
    DIAG_FLAG_BIT12 = 0x1000,  /* Diagnostic flag bit 12 */
    DIAG_FLAG_BIT2 = 0x04,  /* Diagnostic flag bit 2 - used with high RPM protection */
    DIAG_SYS_FLAG_BIT1 = 0x02  /* Diagnostic flag bit 1 - high RPM protection check */
} DIAGNOSTIC_SYSTEM_FLAGS_1;

typedef enum {
    STATUS_F0 = 0xF0,  /* Engine state 11 (0x0B case) */
    VP44_STATUS_F1 = 0xF1,  /* Engine state 3/7/8 */
    STATUS_F2 = 0xF2,  /* Engine state 9 */
    STATUS_F3 = 0xF3,  /* Engine state 4 */
    STATUS_F4 = 0xF4,  /* Engine state 10 (0x0A case) */
    STATUS_F5 = 0xF5,  /* Fuel mode 3 - limited fueling */
    STATUS_F6 = 0xF6,  /* Fuel mode 1 - normal operation */
    STATUS_F7 = 0xF7,  /* Fuel mode 2 - transition mode */
    STATUS_F8 = 0xF8,  /* Engine state 13-21 (0x0D-0x15 cases) */
    STATUS_F9 = 0xF9,  /* Engine state 12 (0x0C case) */
    STATUS_FA = 0xFA,  /* Engine state 24 (0x18 case) */
    STATUS_FE = 0xFE  /* Default/error state */
} VP44_CMD_STATUS;

typedef enum {
    VP44_STATUS_BYTE = 0,  /* Engine status/mode byte (0xF0-0xFE values) */
    FUEL_HIGH = 1,  /* Fuel amount high byte (param_table_aux>>8 + 125) */
    FUEL_LOW = 2,  /* Fuel amount low byte (param_table_main>>8 + 125) */
    TIMING_3 = 3,  /* Timing advance data byte 3 */
    TIMING_4 = 4,  /* Timing advance data byte 4 */
    TIMING_5 = 5,  /* Timing advance data byte 5 */
    RPM_LOW = 6,  /* Engine RPM low byte (current_engine_rpm & 0xFF) */
    RPM_HIGH = 7  /* Engine RPM high byte (current_engine_rpm >> 8) */
} VP44_CMD_BYTE;

typedef enum {
    FUEL_TEMP_LOW = 1,  /* Fuel temperature low byte */
    FUEL_TEMP_HIGH = 2,  /* Fuel temperature high byte */
    SEQUENCE_NUM = 3,  /* Message sequence number */
    MSG_ID_HIGH = 6  /* Message ID high byte (must be 0xEF) */
} VP44_RESP_BYTE;

typedef enum {
    FUEL_TEMP_MSG = 0x10,  /* VP44 fuel temperature response (calls vp44FuelTempHandler) */
    PARAM_REQUEST_MSG = 0x11,  /* Diagnostic parameter request (calls diagnosticParamRequestHandler) */
    STATUS_REQUEST_MSG = 0x13,  /* Diagnostic status request (calls diagnosticStatusRequestHandler) */
    ERROR_MSG = 0xFF  /* Error message (calls diagnosticErrorHandler) */
} VP44_CAN_DISPATCH;

typedef enum {
    NO_SYNC = 0,  /* No synchronization established */
    HAVE_SYNC = 1,  /* Synchronization established and maintained */
    LOST_SYNC = 2  /* Synchronization was established but lost */
} SYNC_STATE;

typedef enum {
    FSO_BIT1_FAULT = 0x10,  /* FSO bit 1 fault detected (vp44_status_register & 0x02) */
    FSO_CIRCUIT_FAULT = 0x20  /* FSO circuit fault detected (vp44_status_register & 0x01) */
} VP44_FSO_FAULT;

typedef enum {
    MSG_HEADER = 0xF00400,  /* VP44 command message header constant */
    TRANSPORT_HEADER = 0x18EC,  /* J1939 transport protocol header */
    EXPECTED_RESPONSE = 0xEF00  /* Expected VP44 response ID (0xEF byte) */
} VP44_PROTOCOL;

typedef enum {
    FAULT_DURATION_COUNT = 0,  /* Count fault duration (protectionState0FaultDurationCounter) */
    DIAGNOSTIC_VALIDATE = 1,  /* Validate diagnostic conditions (protectionState1DiagnosticValidator) */
    THRESHOLD_CALC = 2,  /* Calculate protection thresholds (protectionState2ThresholdCalculator) */
    PRIMARY_RPM_MONITOR = 3,  /* Primary coordinator + RPM monitor (protectionState3a/3b) */
    EMERGENCY_HANDLER = 4  /* Emergency shutdown handler (protectionState4EmergencyHandler) */
} PROTECTION_STATE;

typedef enum {
    STATUS_NORMAL = 0xF0,  /* Normal operation - load below threshold */
    PROP_DIAG_STATUS_F1 = 0xF1,  /* Status F1 - specific condition */
    STATUS_LOAD_HIGH = 0xF4,  /* Load above threshold */
    STATUS_FAULT_ACTIVE = 0xF8,  /* Critical fault active (fault 67 or 69) */
    STATUS_BIT0_LOAD_INACTIVE = 0x01  /* Bit 0 set when load calculation inactive */
} PROP_DIAG_STATUS;

typedef enum {
    TIMER_ACTIVE = 0x80,  /* High RPM protection timer is running */
    HIGH_RPM_DIAG_FLAG_BIT1 = 0x08,  /* Diagnostic system flags bit 1 (0x02) is set */
    FAULT_WITH_DIAG = 0x04,  /* High RPM fault + diagnostic flag bit 2 */
    SHUTDOWN_TIMER_ZERO = 0x02,  /* Shutdown active and timer expired */
    HIGH_RPM_WARNING_ACTIVE = 0x01  /* High RPM protection warning flag set */
} HIGH_RPM_PROTECTION_FLAGS;

typedef enum {
    FAULT_67_BIT = 0x08,  /* Fault ID 67 - critical fault affecting load status */
    FAULT_68_BIT = 0x10,  /* Fault ID 68 - affects FSO detection */
    FAULT_69_BIT = 0x20  /* Fault ID 69 - critical fault affecting load status */
} FAULT_WORD_4_BITS;

typedef enum {
    FUEL_SYNC_IDLE = 0,  /* Idle - waiting for VP44 diagnostic fault */
    FAULT_COUNTING = 1,  /* Fault counting - increment until threshold reached */
    STATUS_MONITORING = 2,  /* Status monitoring - check RPM and injection flags */
    FAULT_CONFIRMED = 3,  /* Fault confirmed - wait for VP44 fault clear */
    DELAY_RECOVERY = 4  /* Delay recovery - count down before returning to idle */
} FUEL_SYNC_STATE;

typedef enum {
    FUEL_SRC_GOVERNOR_LOW = 0x09,  /* Governor control - low fuel demand */
    FUEL_SRC_GOVERNOR_HIGH = 0x0A,  /* Governor control - high fuel demand */
    FUEL_SRC_DIAGNOSTIC = 0x0B,  /* Diagnostic mode override (mode 0xB) */
    FUEL_SRC_RAMP_LIMIT = 0x12,  /* Ramp rate limited fuel demand */
    FUEL_SRC_CALCULATED = 0x14,  /* Calculated fuel demand from tables */
    FUEL_SRC_LOW_RPM = 0x16,  /* Low RPM running / transitional mode fuel */
    FUEL_SRC_OVERRIDE = 0x17,  /* Manual override fuel command */
    FUEL_SRC_VP44_ACTIVE = 0x18,  /* VP44 injection system active fuel */
    FUEL_SRC_HIGH_PERF = 0x19,  /* High performance mode fuel */
    FUEL_SRC_IDLE = 0x1A,  /* Idle mode - zero fuel command */
    FUEL_SRC_FAULT = 0x1B  /* Fault/emergency mode fuel */
} FUEL_SOURCE_ID;

typedef enum {
    NONE = 0,  /* No active diagnostic source */
    SOURCE_FUEL_ARBITRATOR = 1,  /* Fuel arbitrator triggered (rpm_target == 2) */
    DIAG_STATUS_2 = 2,  /* Diagnostic status 2 condition */
    ENGINE_FLAGS = 5,  /* Engine control flags triggered */
    EPS_FAULT = 6,  /* Electronic Position Sensor fault */
    DIAG_STATUS_7 = 7,  /* Diagnostic status 7 condition */
    DIAG_STATUS_30 = 30  /* Diagnostic status 30 condition */
} DIAGNOSTIC_SOURCE_CODE;

typedef enum {
    LOW_RPM_OR_TRANSITIONAL = 0x16,  /* Low RPM running or transitional fuel mode */
    MANUAL_OVERRIDE = 0x17,  /* Manual override fuel command mode */
    VP44_ACTIVE_MODE = 0x18,  /* VP44 injection system active */
    HIGH_PERFORMANCE_MODE = 0x19,  /* High performance mode */
    IDLE_STATE = 0x1A,  /* Idle/no-fuel state */
    FAULT_EMERGENCY_STATE = 0x1B  /* Fault/emergency shutdown state */
} VP44_ENGINE_STATE;

typedef enum {
    FUEL_MODE_INSITE_DISPLAY = 0x0A,  /* INSITE live data display mode */
    FUEL_MODE_RPM_THRESHOLD = 0x0B,  /* RPM threshold protection mode */
    FUEL_MODE_FUEL_DELIVERY = 0x0C  /* Fuel delivery control mode */
} DIAGNOSTIC_FUEL_CONTROL_MODE;

typedef enum {
    TIMING_MODE_A = 0x01,  /* PWM output timing mode A */
    TIMING_MODE_B = 0x02  /* PWM output timing mode B */
} OUTPUT_CONTROL_TIMING_STATE;

typedef enum {
    RETARDER_DISABLED = 0,  /* Retarder control disabled */
    RETARDER_SPEED_SYNC = 1,  /* Speed synchronization mode */
    RETARDER_LOAD_BASED = 2,  /* Load-based retard mode */
    RETARDER_PROPORTIONAL = 3  /* Proportional control mode */
} RETARDER_MODE_STATE;

typedef enum {
    OUTPUT_TIMER_IDLE = 0,  /* Output timer idle state */
    OUTPUT_TIMER_STATE_1 = 1,  /* Output timer state 1 */
    OUTPUT_TIMER_STATE_2 = 2,  /* Output timer state 2 */
    OUTPUT_TIMER_STATE_3 = 3,  /* Output timer state 3 */
    OUTPUT_TIMER_STATE_4 = 4,  /* Output timer state 4 */
    OUTPUT_TIMER_STATE_5 = 5  /* Output timer state 5 */
} OUTPUT_CONTROL_TIMER_STATE;

typedef enum {
    INITIAL = 0,  /* Initial state check angle threshold */
    DZG_ACTIVE = 1,  /* Active state monitor for transitions */
    ALTERNATE = 2  /* Alternative mode state */
} DZG_TIMING_STATE;

typedef enum {
    SENSOR_IDLE = 0,  /* Initial monitoring state */
    SENSOR_ACTIVE = 1,  /* Sensor actively being monitored */
    SENSOR_FAULT_DETECTED = 2,  /* Fault condition detected */
    RECOVERY = 3  /* Recovery countdown state */
} SENSOR_HISTORY_STATE;

typedef enum {
    FUEL_DEMAND_MODE_OVERRIDE = 13,  /* Fuel demand mode selector override (fuelDemandModeSelector) */
    SHUTDOWN_PROTECTION_LIMIT = 15,  /* Shutdown protection fuel limit (shutdownMinimumSelector15) */
    DIAGNOSTIC_MODE_BUFFER = 16,  /* Diagnostic mode buffer limit (shutdownMinimumSelector16) */
    FUEL_LIMIT_SHUTDOWN = 17,  /* Fuel limit from shutdown calc (shutdownMinimumSelector17) */
    CALCULATED_FUEL_TIMING = 19,  /* Calculated fuel timing value (shutdownMinimumSelector19) */
    FUEL_ARBITRATOR_DIAG = 20,  /* Fuel arbitrator diagnostic mode (shutdownMinimumSelector20) */
    SHUTDOWN_LIMIT_SELECTOR = 21,  /* Shutdown limit selector value (shutdownMinimumSelector21) */
    SHUTDOWN_MINIMUM_INIT = 28,  /* Shutdown minimum init value (shutdownMinimumSelector28) */
    PROTECTION_SHUTDOWN_LIMIT = 29,  /* Protection shutdown fuel limit (shutdownMinimumSelector29) */
    OIL_PRESSURE_PROTECTION = 34  /* Oil pressure protection limit (oilPressureProtection) */
} SHUTDOWN_SELECTOR_SOURCE;

typedef enum {
    TABLE_BLEND_CALC = 0,  /* Table interpolation blend calculation result */
    RPM_BASED_LIMIT = 1,  /* RPM-based fuel demand limit (fuelDemandLimitMinimumUpdater) */
    BLEND_PARAM_FALLBACK = 2,  /* Blend parameter 2 fallback value */
    HIGH_RPM_FUEL_LIMIT = 3,  /* High RPM fuel limit (fuelLimitMinimumSelector) */
    FUEL_LIMIT_FLOOR = 4,  /* Fuel limit floor value (fuelDemandLimitSelector4) */
    ENGINE_MODE_TRANSITION = 5,  /* Engine mode transition timing (engineModeTransitionStateUpdater) */
    STATE_24_OVERRIDE = 6,  /* VP44 active mode state 24 override (fuelDemandState24Override) */
    VP44_FLAG_REGISTER = 11  /* VP44 flag register RPM load lookup (fuelDemandLimitSelector11) */
} FUEL_DEMAND_SOURCE;

typedef enum {
    NO_LIMIT_ACTIVE = 0,  /* No fuel limit active / cleared state */
    OVERRIDE_STATE_ACTIVE = 1,  /* Override state active from fuel_demand_override_state */
    VP44_DIAGNOSTIC_FAULT = 2,  /* VP44 diagnostic fault limit (fuelDemandLimitSource2Selector) */
    RETARDER_INPUT_LIMIT = 3,  /* Retarder input flags based limit (fuelDemandLimitSource3Selector) */
    RETARDER_MODE_TABLE = 4,  /* Retarder mode table count limit (fuelDemandLimitSource4Selector) */
    PROTECTION_OVERRIDE = 5  /* Protection/override state - init and fault recovery */
} FUEL_DEMAND_LIMIT;

typedef enum {
    NORMAL_OPERATION = 0,  /* No diagnostic mode active - normal operation */
    FUEL_ARBITRATOR_SOURCE = 1,  /* Fuel arbitrator rpm_target==2 (setDiagnosticSourceFromFuelArbitrator) */
    DERATE_CONDITION_2 = 2,  /* Derate condition 2 active (diagnosticStatus2Initializer) */
    DERATE_CONDITION_3 = 3,  /* Derate condition 3 - governor PID active mode */
    ENGINE_FLAGS_SOURCE = 5,  /* Engine flags diagnostic source (setDiagnosticSourceFromEngineFlags) */
    EPS_FAULT_MODE = 6,  /* EPS diagnostic mode from fault registers (epsDiagnosticModeChecker) */
    DIAGNOSTIC_MODE_7 = 7,  /* Diagnostic mode 7 - target RPM rate limiting active */
    DEFAULT_DIAGNOSTIC = 8,  /* Default diagnostic mode (diagnosticStatusDefaultSetter) */
    DERATE_CONDITION_30 = 30  /* Derate condition 0x1e active (diagnosticStatus30Setter) */
} DIAGNOSTIC_STATUS;

typedef enum {
    INACTIVE = 0,  /* Diagnostic mode inactive / cleared */
    BOOST_PRESSURE_INIT = 1,  /* Boost pressure threshold check init (set protection_system_enable_flag=1) */
    BOOST_PRESSURE_MONITOR = 2,  /* Boost pressure monitoring active */
    SENSOR_BIT8_TRIGGERED = 3,  /* Sensor status bit 8 triggered protection */
    SENSOR_BIT2_PROTECTION = 4,  /* Sensor status bit 2 protection active */
    SENSOR_TYPE_0_MODE = 5,  /* Sensor type 0 mode (vp44_sensor_type_selector==0) */
    SENSOR_TYPE_1_MODE = 6,  /* Sensor type 1 mode (vp44_sensor_type_selector!=0) */
    PROTECTION_CONTINUE = 7,  /* Protection system continue state */
    EXIT_DISABLED = 8,  /* Exit/disabled state - protection clearing */
    UNINITIALIZED = 256  /* Transitional/uninitialized state (0x100) */
} VP44_DIAG_MODE;

typedef enum {
    MONITORING = 0,  /* Initial state - monitoring conditions for entry */
    TIMER_COUNTING = 1,  /* Timer countdown active - conditions met */
    RPM_PROTECTION_WARNING_ACTIVE = 2,  /* Warning threshold reached - protection active */
    FAULT_TRIGGERED = 3,  /* Fault triggered - derate change detected during protection */
    SHUTDOWN_PENDING = 4  /* Shutdown pending - timer expired waiting for idle */
} HIGH_RPM_PROTECTION_STATE;

typedef enum {
    INIT_SEND = 0,  /* Initial send state - start transmission */
    SENDING_DATA = 1,  /* Actively sending data bytes */
    CHECKSUM_CALC = 2,  /* Checksum calculation state */
    TRANSMISSION_COMPLETE = 3  /* Transmission complete - cleanup */
} TPU_TRANSMISSION_STATE;

typedef enum {
    CYCLE_PHASE_0 = 0,  /* Timing cycle phase 0 */
    CYCLE_PHASE_1 = 1,  /* Timing cycle phase 1 */
    CYCLE_PHASE_2 = 2,  /* Timing cycle phase 2 */
    CYCLE_PHASE_3 = 3,  /* Timing cycle phase 3 */
    CYCLE_PHASE_4 = 4,  /* Timing cycle phase 4 */
    CYCLE_PHASE_5 = 5  /* Timing cycle phase 5 */
} PWM_TIMER_CYCLE_STATE;

typedef enum {
    NO_DERATE = 0,  /* No derate condition active */
    TIMING_ACTIVE = 1,  /* Derate timing accumulator active */
    EVENT_COUNTED = 2  /* Event counted - counter incremented */
} DERATE_EVENT_STATE;

typedef enum {
    OFF_INACTIVE = 0,  /* Output off/inactive - waiting for condition */
    TRANSITIONING = 1,  /* Transition state - checking conditions */
    ON_ACTIVE = 2  /* Output on/active - condition met */
} IO_CONTROL_STATE;

typedef enum {
    INITIALIZING = 0,  /* Initial state - buffers being configured */
    CAPTURING = 1,  /* Actively capturing timer pulses */
    RPM_FAULT_DETECTED = 2  /* Fault detected in capture sequence */
} RPM_CAPTURE_STATE;

typedef enum {
    BLEND_RAMP_DEFAULT = 0,  /* Default timing protection blend ramp */
    ARBITRATION_VALUE = 1,  /* Fuel timing mode arbitration value */
    ARBITRATION_1 = 2,  /* Fuel timing mode arbitration 1 (VP44 timing) */
    ARBITRATION_2 = 3,  /* Fuel timing mode arbitration 2 (protection mode active) */
    PARAM_OVERRIDE = 4  /* Parameter override mode (fuel_timing_mode_arbitration_param_2) */
} TIMING_MODE_SOURCE;

typedef enum {
    RESET_INACTIVE = 0,  /* Reset/inactive state - initialized in cm550_clearKickdownControlState */
    FUEL_CONTROL_A = 1,  /* Fuel control condition A - checked with value 2 */
    FUEL_CONTROL_B = 2,  /* Fuel control condition B - checked with value 1 */
    TRANSITION_STATE_3 = 3,  /* Transition state 3 - triggers mode change on entry */
    TRANSITION_STATE_4 = 4  /* Transition state 4 - triggers mode change on entry */
} VP44_OPERATING_CONDITION;

typedef enum {
    STATE_0_IDLE = 0,  /* State 0 - idle/cleared state (returns 0 from mapper) */
    STATE_1_ACTIVE = 1,  /* State 1 - active state with timer/transition handling */
    STATE_2_MONITOR = 2,  /* State 2 - monitoring state with transition handling */
    STATE_3_TRANSITION = 3,  /* State 3 - transition state */
    STATE_4_DEFAULT = 4,  /* State 4 - default init state (set in vp44StateVariablesInit) */
    STATE_5_FAULT = 5  /* State 5 - fault/error state (returns 1 from mapper) */
} VP44_STATE;

typedef enum {
    HISTOGRAM_IDLE = 0,  /* No histogram update needed */
    INCREMENT = 1,  /* Increment histogram index (data < conversion state) */
    DECREMENT = 2  /* Decrement histogram index (counter < conversion state) */
} ENGINE_HISTOGRAM_MODE;

typedef enum {
    GET_STATUS_REQ = 0x00,  /* CLIP Get Status Request - sets response buffer flags */
    DATA_TRANSFER_UNHANDLED = 0x03,  /* DataTransfer - NO HANDLER falls through to else clause */
    LIVE_DATA_STREAM = 0x80,  /* Multi-frame live data stream with sequence handling */
    SEQUENCE_HANDLER = 0xC3  /* Sequence handling (0x30/0x31 patterns) */
} INSITE_LIVE_DATA_MSG_TYPE;

typedef enum {
    UNKNOWN_SERVICE_DEFAULT = 0x18  /* Default error code when service ID not found in dispatch table */
} DIAG_SERVICE_ERROR;

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
    TRANSPORT_OPEN = 0x02,  /* Session open request (Tool -> ECU) */
    DATA_TRANSFER = 0x03,  /* Data transfer with sequence in bits[7:5] */
    CLEAR_TO_SEND = 0x04,  /* Flow control acknowledgment / CTS */
    CONNECTION_REFUSED = 0x05,  /* Session rejected by ECU */
    TRANSPORT_CLOSE = 0x06,  /* Session close request */
    SESSION_OPEN_RESPONSE = 0x0D  /* Session accepted (CM550 variant ECU -> Tool) */
} CLIP_TRANSPORT_MSG_TYPE;

typedef enum {
    SEED_REPLY = 0x02,  /* ECU is providing security seed */
    CONTEXT_REPLY = 0x04  /* ECU context/status response */
} CLIP_CONTROL_TYPE;

typedef enum {
    CLOSED = 0x01,  /* No active session */
    OPENING = 0x02,  /* Waiting for seed reply */
    REQUESTING_SEED = 0x04,  /* Sent open waiting for seed */
    SEEDED = 0x05,  /* Seed received ready to encrypt */
    AUTHENTICATED = 0x07,  /* Session ready for data transfer */
    SECURED_LOCKED = 0x08  /* Encryption required but not licensed */
} CLIP_SESSION_STATE;

typedef enum {
    ASYNC = 0xC0,  /* Asynchronous frame - no immediate response expected */
    SYNC = 0x80  /* Synchronous frame - wait for response */
} DPA_FRAME_TYPE;

typedef enum {
    TRANSMIT = 0x49,  /* Send data to ECU (TX instruction) */
    RECEIVE = 0x48  /* Receive data from ECU (RX instruction) */
} DPA_INSTRUCTION;

typedef enum {
    TRUE = 0x00,  /* Security checks are enforced - services <= 0x19 require authentication */
    FALSE = 0xFF  /* Security checks are SKIPPED - all services accessible without auth */
} SECURITY_ENABLED;

typedef enum {
    J1939_DIAGNOSTIC_SERVICE_CLEAR_INACTIVE_FAULTS = 0x01,  /* Service 1 (CM848's member name). The service does the same job in both firmwares: it sets the CLEAR_INACTIVE bit of e2m 1080 +2. (was SERVICE_QUERY_TERMINATE; PR #53 round 88) */
    J1939_DIAGNOSTIC_SERVICE_DISABLE_BROADCAST = 0x04,  /* Service 4 (CM848's member name). CM550's handler 0x200a4 calls 0x1ffd6(request, 0), which clears the request's item bits in the J1939 broadcast enable word (_bit_2_0_15_enables_j1939_71_engine_broadcast_1_on_0_off). (was SYSTEM_SERVICE_04; PR #53 round 88) */
    J1939_DIAGNOSTIC_SERVICE_ENABLE_BROADCAST = 0x05,  /* Service 5 (CM848's member name). CM550's handler 0x200b4 calls 0x1ffd6(request, 1), which sets the request's item bits in the J1939 broadcast enable word, as CM848's 0x509d0c does through cm848_updateJ1939BroadcastEnableMask(request, 1). (was SYSTEM_SERVICE_05; PR #53 round 88) */
    J1939_DIAGNOSTIC_SERVICE_COMMAND_ENGINE_SHUTDOWN = 0x06,  /* Service 6 (CM848's member name). The handler is the twin commandEngineShutdown (0x118fc), which sets the e2m 10B1 +12 SHSS shutdown command. There is no rpm test. The row's comment should name commandEngineShutdown. (was SERVICE_HIGH_RPM_SHUTDOWN_ACTIVATE; PR #53 round 88) */
    J1939_DIAGNOSTIC_SERVICE_EXIT_DEVELOPMENT_MODE = 0x07,  /* Service 7 (CM848's member name). The handler is the twin exitDevelopmentMode (0x1188c, shared since round 73), re-checked. (was SYSTEM_SERVICE_07; PR #53 round 88) */
    J1939_DIAGNOSTIC_SERVICE_ENTER_DEVELOPMENT_MODE = 0x0A,  /* Service 10 (CM848's member name). The handler is the twin enterDevelopmentMode (0x118b2), re-checked. It sets ram_refresh_enable 0, development_mode 1 and run_location 0xeaea, and returns 0. CM550 also reaches it as J1708 command 64. (was SYSTEM_SERVICE_0A; PR #53 round 88) */
    J1939_DIAGNOSTIC_SERVICE_RESTART_THROUGH_BOOT_ROM = 0x0B,  /* handleJ1939RestartService (0x11908): restartThroughBootRom - SECURED - in dispatch table (was SYSTEM_SERVICE_0B; PR #53 round 87) */
    J1939_DIAGNOSTIC_SERVICE_NO_OPERATION_15 = 0x0F,  /* Service 15 (CM848's member name). CM550's handler 0x1ffd2 is clr.b d0; rts: it is accepted and does nothing, like CM848's cm848_j1939DiagnosticServiceAcknowledgeNoOperation (li r3,0; blr). That explains the bench note 'RESPONDS!'. (was GET_PARAMETERS_BY_ID_ALT; PR #53 round 88) */
    J1939_DIAGNOSTIC_SERVICE_NO_OPERATION_16 = 0x10,  /* Service 16 (CM848's member name). It uses the same no-operation handler 0x1ffd2 as service 15 (accepted, does nothing), as CM848 registers 16 to the same no-operation handler. The live table holds it (entry 21). (was SERVICE_GET_PARAMETERS_BY_ID; PR #53 round 88) */
    J1939_DIAGNOSTIC_SERVICE_COMMIT_EEPROM_MIRROR = 0x15,  /* Service 21 (CM848's member name). Its handler commits the EEPROM mirror in both firmwares. The handler is a counterpart because of the reply path (cm550_commitEepromMirrorToEeprom), but the service's job is the same. (was GET_ADDRESS_BY_PARAM_ID; PR #53 round 88) */
    J1939_DIAGNOSTIC_SERVICE_FORCE_EXIT_DEVELOPMENT_MODE = 0x16,  /* Service 22 (CM848's member name). The handler is the twin forceExitDevelopmentMode (0x118cc), re-checked. It returns 7 while not_safe_to_program_flag is 1. (was SYSTEM_SERVICE_16; PR #53 round 88) */
    J1939_DIAGNOSTIC_SERVICE_INHIBIT_KEY_OFF_SHUTDOWN = 0x18,  /* Service 24 (CM848's member name). The handler is the twin inhibitKeyOffShutdown (0x11a68), which sets key_off_shutdown_inhibit_flag. The enum header's '# Dispatch table: 20 entries' comment should say 24: the dump's count byte is 0x18. (was SYSTEM_SERVICE_18; PR #53 round 88) */
    DIAG_ADDR_RESOLVER = 0x41,  /* canDiagnosticResponseSender - dispatch @ 0x000222B4 - UNSECURED - RESPONDS! in dispatch table */
    MEM_READ_2B_PARAM_4B_OFFSET = 0x43,  /* Memory read - dispatch @ 0x00022530 - UNSECURED - RESPONDS! Format: [43][Param:2][Offset:4] */
    J1939_DIAGNOSTIC_SERVICE_WRITE_BY_PARAMETER_ID = 0x44,  /* Service 0x44 (CM848's member name): handleJ1939WriteByParameterIdService (0x2167e) - the ID (2 bytes) and a length (1) then the data (was J1939_DIAGNOSTIC_SERVICE_WRITE_BY_PARAMETER_ID; PR #53 round 94) */
    J1939_DIAGNOSTIC_SERVICE_WRITE_BY_PARAMETER_ID_LONG_LENGTH = 0x45,  /* Service 0x45 (CM848's member name): handleJ1939WriteByParameterIdLongLengthService (0x216c6) - the ID (2 bytes) and a length (4) then the data (was J1939_DIAGNOSTIC_SERVICE_WRITE_BY_PARAMETER_ID_LONG_LENGTH; PR #53 round 94) */
    MEM_READ_2B_PARAM_ONLY = 0x46,  /* Memory read - dispatch @ 0x0002257C - UNSECURED - RESPONDS! Format: [46][Param:2] */
    J1939_DIAGNOSTIC_SERVICE_WRITE_BY_PARAMETER_ID_SHORT_OFFSET = 0x47,  /* Service 0x47 (CM848's member name): handleJ1939WriteByParameterIdShortOffsetService (0x21714) - the ID (2 bytes) / an offset (2) / a length (1) then the data (was J1939_DIAGNOSTIC_SERVICE_WRITE_BY_PARAMETER_ID_SHORT_OFFSET; PR #53 round 94) */
    SERVICE_48 = 0x48,  /* Service 48 - dispatch @ 0x000225E0 - UNSECURED - in dispatch table */
    J1939_DIAGNOSTIC_SERVICE_WRITE_BY_PARAMETER_ID_LONG_OFFSET = 0x49,  /* Service 0x49 (CM848's member name): handleJ1939WriteByParameterIdLongOffsetService (0x21778) - the ID (2 bytes) / an offset (4) / a length (4) then the data (was J1939_DIAGNOSTIC_SERVICE_WRITE_BY_PARAMETER_ID_LONG_OFFSET; PR #53 round 94) */
    MEM_READ_4B_ADDR_1B_LEN = 0x4A,  /* Memory read - dispatch @ 0x00022646 - UNSECURED - WORKING! Format: [4A][Addr:4][Len:1] */
    J1939_DIAGNOSTIC_SERVICE_WRITE_MEMORY = 0x4B,  /* Service 0x4b (CM848's member name): handleJ1939WriteMemoryService (0x217de) - an address (4 bytes) and a length (1) then the data (was J1939_DIAGNOSTIC_SERVICE_WRITE_MEMORY; PR #53 round 94) */
    MEM_READ_4B_ADDR_4B_LEN = 0x4C,  /* Memory read - dispatch @ 0x0002268E - UNSECURED - Format: [4C][Addr:4][Len:4] multi-frame */
    J1939_DIAGNOSTIC_SERVICE_WRITE_MEMORY_LONG_LENGTH = 0x4D  /* Service 0x4d (CM848's member name): handleJ1939WriteMemoryLongLengthService (0x21826) - an address (4 bytes) and a length (4) then the data (was J1939_DIAGNOSTIC_SERVICE_WRITE_MEMORY_LONG_LENGTH; PR #53 round 94) */
} J1939_DIAGNOSTIC_SERVICE;

typedef enum {
    INVALID_LENGTH = 0x02,  /* diagnosticServiceSecurityValidator - message length mismatch */
    ERROR_SECURITY_FAILED = 0x03,  /* diagnosticServiceSecurityValidator - systemSecurityCheck returned non-zero */
    CONDITION_NOT_MET = 0x07,  /* writeJ1939DiagnosticMemory - not_safe_to_program_flag is 1 while ram_refresh_enable is on (was read as a system_logging_state check; PR #53 round 73) */
    ADDR_LOOKUP_FAIL = 0x08,  /* j1939MemoryDataCopyResolver - initial address lookup at 0xeaf0 failed */
    ADDR_RANGE_INVALID = 0x09,  /* lookupApplicationMemoryRegionType @ 0x3460e (MEMORY_REGION_TYPE_UNMAPPED) - the range is in no application_memory_region_table entry (J90280.05: addressRangeValidator @ 0x2b544; PR #53 round 72) */
    ADDR_ACCESS_DENIED = 0x0A,  /* lookupApplicationMemoryRegionType @ 0x3460e (MEMORY_REGION_TYPE_REFUSED) - the registers 0xffc800-0xffffff while the development mode flag is not 1 (J90280.05: addressRangeValidator @ 0x2b544; PR #53 round 72) */
    BUFFER_WRITE_FAIL = 0x0B,  /* writeJ1939DiagnosticMemory - circularBufferWrite returned error */
    WRITE_DENIED = 0x0A,  /* writeJ1939DiagnosticMemory - write to read-only region (ROM/Flash case 4) */
    PATCH_LIMIT = 0x0E,  /* diagnosticResponseBuilder - memory patch count exceeded limit */
    UNKNOWN_SERVICE = 0x18,  /* diagnosticServiceDispatcher - service ID not in dispatch table */
    AUTH_REQUIRED_MISSING = 0x1A  /* writeJ1939DiagnosticMemory - EEPROM write requires auth but none provided */
} DIAG_ERROR_SOURCE;

typedef enum {
    MEMORY_OPERATION_SUCCESS = 0x00,  /* Memory operation completed successfully (masked from memcpy return) */
    MEMORY_OPERATION_INVALID_LENGTH = 0x02,  /* Message length mismatch - expected calculated_msg_length or +10 for auth */
    MEMORY_OPERATION_AUTH_FAILED = 0x03,  /* validateSecurityKey returned non-zero (auth payload invalid) */
    CALIBRATION_WRITE_BLOCKED = 0x07,  /* EEPROM write refused - not_safe_to_program_flag is 1 while ram_refresh_enable is on (J90280.05 read them as calibration_write_protect_state / calibration_bank_selector; PR #53 round 73) */
    MEMORY_OPERATION_WRITE_DENIED = 0x0A,  /* Region type 4 (ROM/Flash) - write operations not permitted */
    MEMORY_OPERATION_BUFFER_WRITE_FAIL = 0x0B,  /* circularBufferWrite returned error during EEPROM logging */
    MEMORY_OPERATION_AUTH_REQUIRED_MISSING = 0x1A  /* EEPROM write (region type 5) requires auth but has_auth_payload=false */
} MEMORY_OP_RESULT;

typedef enum {
    SERVICE_74_SUCCESS = 0x4B  /* Service 0x4A success response code (service ID + 1) */
} SERVICE_4A_RESPONSE;

typedef enum {
    MEMORY_REGION_TYPE_RAM = 0x00,  /* Copied without a check: the extended RAM 0x8091dc-0x80ffff (was MEMORY_ACCESS_FLAG DIRECT_ACCESS; PR #53 round 72) */
    MEMORY_REGION_TYPE_AUTHORIZATION_REQUIRED = 0x03,  /* Copied after the security code check: RAM 0x800000-0x8091dc and - while the development mode flag is 1 - the registers 0xffc800-0xffffff (was MEMORY_ACCESS_FLAG SECURITY_REQUIRED; PR #53 round 72) */
    MEMORY_REGION_TYPE_MAIN_FLASH = 0x04,  /* Main flash 0x0-0x7ffff: the memory write service refuses it (10) (was MEMORY_ACCESS_FLAG MEMORY_ACCESS_WRITE_DENIED; PR #53 round 72) */
    MEMORY_REGION_TYPE_EEPROM = 0x05,  /* EEPROM 0x1000000-0x1001fff: written after the security code check (was MEMORY_ACCESS_FLAG LOGGING_MODE - the range is the EEPROM; PR #53 round 72) */
    MEMORY_REGION_TYPE_UNMAPPED = 0x09,  /* No entry holds the range or it wraps past 0xffffffff - passed back as the result (was MEMORY_ACCESS_FLAG RANGE_INVALID; PR #53 round 72) */
    MEMORY_REGION_TYPE_REFUSED = 0x0a  /* The registers while the development mode flag is not 1 - passed back as the result (was MEMORY_ACCESS_FLAG ACCESS_DENIED; PR #53 round 72) */
} MEMORY_REGION_TYPE;

typedef enum {
    BYPASS_ENABLED = 0xB522,  /* Magic value to bypass security checks (stored at 0x803586) */
    LEGACY_BYPASS = 0x00FF  /* Legacy security bypass value check in writeJ1939DiagnosticMemory */
} SECURITY_BYPASS;

typedef enum {
    SERVICE_3_ENTER_DEVELOPMENT_MODE = 0x40,  /* enterDevelopmentMode after the security key (was SERVICE_3_SWITCH_TO_FACTORY_BANK; PR #53 round 74) */
    SERVICE_3_FORCE_EXIT_DEVELOPMENT_MODE = 0x41,  /* forceExitDevelopmentMode - when not_safe_to_program_flag allows (was SERVICE_3_FORCE_ACTIVE_BANK; PR #53 round 74) */
    HIGH_RPM_SHUTDOWN = 0x42,  /* activateHighRpmShutdownFlag - trigger high RPM shutdown */
    SYSTEM_RESET = 0x43,  /* triggerDiagnosticSystemReset - diagnostic system reset */
    NOP = 0x50,  /* No operation - returns success (0x00) */
    SERVICE_3_MEMORY_PATCH = 0x51,  /* memoryPatchingSystem - apply queued memory patches */
    SECURED_SHUTDOWN = 0x52,  /* requestSecuredShutdown - request secured engine shutdown */
    RESERVED_ERROR = 0x53,  /* Reserved - always returns error 0x04 */
    CAN_BUFFER_LOG = 0x54  /* canMessageBufferLogger - log CAN message buffer */
} DIAG_SERVICE_3_CMD;

typedef enum {
    CONTROL_64 = 0x64,  /* systemControl64 - system control function */
    FAULT_SCANNER = 0x65,  /* enableFaultFlagScanner - enable fault flag scanning */
    STATE_RESET = 0x66,  /* Reset diagnostic_command_state to 0 */
    SERVICE_4_EXIT_DEVELOPMENT_MODE = 0x69,  /* exitDevelopmentMode (was SERVICE_4_SWITCH_TO_ACTIVE_BANK; PR #53 round 74) */
    RESERVED_70 = 0x70,  /* Reserved - returns error 0x04 */
    STATE_BIT0 = 0x71,  /* Set diagnostic_command_state bit 0 */
    RESERVED_72 = 0x72,  /* Reserved - returns error 0x04 */
    STATE_BIT1 = 0x73,  /* Set diagnostic_command_state bit 1 */
    CONTROL_74 = 0x74,  /* systemControl74 - system control function */
    CONTROL_75 = 0x75,  /* systemControl75 - system control function */
    RESERVED_76 = 0x76  /* Reserved - returns error 0x04 */
} DIAG_SERVICE_4_CMD;

typedef enum {
    MEM_READ_MODE3 = 0x60,  /* diagnosticMemoryReadHandler mode 3 - standard read */
    MEM_WRITE_MODE4 = 0x80,  /* diagnosticMemoryWriteHandler mode 4 - 4-byte address write */
    MEM_WRITE_MODE2 = 0xA0,  /* diagnosticMemoryWriteHandler mode 2 - 2-byte address write */
    MULTI_PKT_RX = 0xB0,  /* multiPacketReceiveHandler - multi-packet receive */
    MEM_READ_MODE2 = 0xC0,  /* diagnosticMemoryReadHandler mode 2 - compact read */
    MEM_READ_MODE1 = 0xE0,  /* diagnosticMemoryReadHandler mode 1 - extended read */
    MULTI_PKT_TX = 0xF0  /* multiPacketTransmitHandler - multi-packet transmit */
} DIAG_SERVICE_5_MODE;

typedef enum {
    THROTTLE_OVERRIDE = 0x04,  /* Override throttle control when set */
    SPEED_LIMIT_ACTIVE = 0x08,  /* Activate speed limiter when set */
    FUEL_LIMIT_ACTIVE = 0x10  /* Activate fuel limiter when set */
} FUEL_ARB_FLAGS;

typedef enum {
    PARAM_STANDARD = 0x00,  /* Standard parameter read (0x00-0x7F) - response length 2 */
    PARAM_EXTENDED = 0x80,  /* Extended parameter read (0x80-0xBF) - response length 3 */
    INSITE_COMMAND_ACTIVE_FAULT_LIST = 0xC1,  /* insiteActiveFaultListBuilder - list of active DTCs */
    INSITE_COMMAND_FAULT_DETAIL = 0xC2,  /* insiteFaultDetailBuilder - detailed fault information */
    INSITE_COMMAND_PID_DTC_REQUEST = 0xC3,  /* PID/DTC handler request - triggers insitePidDtcHandler */
    PID_DTC_RESPONSE = 0xC4,  /* PID/DTC response - response length 4 or 7 */
    CAPACITY_INFO = 0xEA,  /* insiteCapacityResponseBuilder - response length 0x18 (24 bytes) */
    ECU_ID = 0xED,  /* insiteEcuIdResponseBuilder - ECU identification (3 parts with 0x2A separator) */
    INSITE_COMMAND_VERSION_INFO = 0xF3  /* insiteVersionInfoBuilder - response length 0x1F (31 bytes) */
} INSITE_CMD;

typedef enum {
    NOT_LOADED = 0,  /* Calibration not loaded from flash */
    PRIMARY_FLASH = 1,  /* Loaded from primary flash bank @ 0x4000-0x55b2 */
    SECONDARY_FLASH = 2  /* Loaded from secondary flash bank @ 0x6000-0x75b2 */
} CALIBRATION_FLASH_SOURCE;

typedef enum {
    WRITES_ALLOWED = 0,  /* EEPROM writes allowed - no restrictions */
    WRITES_BLOCKED_IF_ACTIVE = 1,  /* EEPROM writes blocked when active bank selected */
    WRITES_ALLOWED_OVERRIDE = 2  /* EEPROM writes allowed via special override */
} CALIBRATION_WRITE_PROTECT;

typedef enum {
    RAM_REFRESH_DISABLED = 0,  /* RAM refresh off (development mode - set by enterDevelopmentMode) */
    RAM_REFRESH_ENABLED = 1  /* RAM refresh on - set by exitDevelopmentMode / forceExitDevelopmentMode and the boot code */
} RAM_REFRESH_STATE;

typedef enum {
    RUN_LOCATION_DEVELOPMENT = 0xeaea,  /* Development - set by enterDevelopmentMode (CM848: 0xea) */
    RUN_LOCATION_NORMAL = 0xeeee  /* Normal - set at boot / power-down and on leaving development mode (CM848: 0xee) */
} RUN_LOCATION;

typedef enum {
    DEVELOPMENT_MODE_OFF = 0,  /* Normal operation - cleared by exitDevelopmentMode / forceExitDevelopmentMode and the boot code */
    DEVELOPMENT_MODE_ON = 1  /* Development mode - set by enterDevelopmentMode (J1708 command 3 subcommand 0x40 after the security key) */
} DEVELOPMENT_MODE_STATE;

typedef enum {
    FLASH_ERASE_DONE = 0,  /* The block is erased: status bit 7 (ready) without the erase error bit (PR #53 round 85) */
    FLASH_ERASE_FAILED = 1,  /* The erase error bit (status bit 5) or no ready bit after 40000 status reads (PR #53 round 85) */
    FLASH_ERASE_SUSPENDED = 2  /* Suspended with 0xB0B0: the suspend check is on and the chip select 2 device's input bit 0 read 1 on 4 consecutive reads (PR #53 round 85) */
} FLASH_ERASE_RESULT;

typedef enum {
    ENGINE_STATE_UNINITIALIZED = 0,  /* Zeroed RAM - a member for parity with CM848: no CM550 code in the dumped 256 KB compares engine_state with 0 or stores 0 (PR #53 round 88) */
    ENGINE_STATE_STOPPED = 1,  /* e2m 1068 FSEGST 1=STOP. (PR #53 round 88) */
    ENGINE_STATE_CRANKING = 2,  /* e2m 2=CRANK. Entered from STOPPED. It leaves to RUNNING at crank_exit_speed, to JUMP_START when crank_jump_start_timer exceeds crank_jump_start_time, and to STOPPED at engine_stopped_speed. (PR #53 round 88) */
    ENGINE_STATE_RUNNING = 3,  /* e2m 3=RUN. Entered at crank_exit_speed from CRANKING / JUMP_START / REENTRY, and from ENGINE_BRAKE / OVERSPEED when their condition ends. (PR #53 round 88) */
    ENGINE_STATE_ENGINE_BRAKE = 4,  /* e2m 4=ENGBRAKE. Entered from RUNNING while engine_retarder_active_flag (117D +4 EBSS) is 1 and engine_brake_driveline_brake_type_cal is 0. It returns to RUNNING when both are 0. (PR #53 round 88) */
    ENGINE_STATE_OVERSPEED = 5,  /* e2m 5=OVERSPED. Entered from RUNNING while engine_overspeed_active_flag is 1. It returns to RUNNING when the flag clears. (PR #53 round 88) */
    ENGINE_STATE_JUMP_START = 6,  /* e2m 6=JUMPSTRT. Entered from CRANKING after crank_jump_start_timer passes crank_jump_start_time. It leaves like CRANKING, without the jump start test. The consumers treat it like CRANKING. (PR #53 round 88) */
    ENGINE_STATE_REENTRY = 7,  /* e2m 7=REENTRY. Entered from RUNNING when engine_rpm_primary falls to crank_reentry_speed. It leaves like JUMP_START: to RUNNING at crank_exit_speed, to STOPPED at engine_stopped_speed. (PR #53 round 88) */
    ENGINE_STATE_SHUTDOWN = 8  /* e2m 8=SHUTDOWN. (PR #53 round 88) */
} ENGINE_STATE;

typedef enum {
    FUELING_STATE_NOT_SELECTED = 0,  /* Calterm FSFNFLST 0=NOT_SET (CM848's member of the same label) */
    FUELING_STATE_TSC1_TORQUE_CONTROL = 1,  /* Calterm FSFNFLST 1=JCOMTORQ (CM848's member of the same label) */
    FUELING_STATE_TSC1_SPEED_CONTROL = 2,  /* Calterm FSFNFLST 2=JCOMSPED (CM848's member of the same label) */
    FUELING_STATE_UNIDENTIFIED_3 = 3,  /* Calterm FSFNFLST 3=PSSPEED (no CM848 member; the label's meaning is not proved) */
    FUELING_STATE_POWER_TAKE_OFF = 4,  /* Calterm FSFNFLST 4=PTO (CM848's member of the same label) */
    FUELING_STATE_CALIBRATED_FIXED_FUEL_DEMAND = 5,  /* Calterm FSFNFLST 5=USERCOMD (CM848's member of the same label) */
    FUELING_STATE_ACCELERATOR_PEDAL_FAULT = 6,  /* Calterm FSFNFLST 6=LIMPHOME (CM848's member of the same label) */
    FUELING_STATE_VARIABLE_SPEED_GOVERNOR = 7,  /* Calterm FSFNFLST 7=ASGTHROT (CM848's member of the same label) */
    FUELING_STATE_DUAL_AXIS_FUEL_DEMAND_TABLE = 8,  /* Calterm FSFNFLST 8=FOUR_D (CM848's member of the same label) */
    FUELING_STATE_CRUISE_CONTROL = 9,  /* Calterm FSFNFLST 9=CRUISE (CM848's member of the same label) */
    FUELING_STATE_ROAD_SPEED_GOVERNOR = 10,  /* Calterm FSFNFLST A=RSG (CM848's member of the same label) */
    FUELING_STATE_LOW_SPEED_GOVERNOR = 11,  /* Calterm FSFNFLST B=LSG (CM848's member of the same label) */
    FUELING_STATE_HIGH_SPEED_GOVERNOR = 12,  /* Calterm FSFNFLST C=HSG (CM848's member of the same label) */
    FUELING_STATE_TORQUE_DERATE_OVERRIDE = 13,  /* Calterm FSFNFLST D=TRQDROVR (CM848's member of the same label) */
    FUELING_STATE_LOW_GEAR = 14,  /* Calterm FSFNFLST E=LOWGEAR (no CM848 member) */
    FUELING_STATE_ALTITUDE_DERATE = 15,  /* Calterm FSFNFLST F=ALTDERAT (CM848's member of the same label) */
    FUELING_STATE_AIR_FUEL_CONTROL_DERATE = 16,  /* Calterm FSFNFLST 10=AFCDERAT (CM848's member of the same label) */
    FUELING_STATE_ACCELERATION_NOISE_CONTROL_DERATE = 17,  /* torque_derate_fuel_source_code (cm550_applyAccelerationNoiseControlFuelLimit 0xb3b2): acceleration_noise_control_fuel_limit (e2m 10A4 +0 NZFLLM 'fueling limit as determined by the ANC feature') is below the running derate minimum - Calterm FSFNFLST 11=ANCDERAT (no CM848 member: CM848 has no such limiter) (was FUELING_STATE_ACCELERATION_NOISE_CONTROL_DERATE; PR #53 round 94) */
    FUELING_STATE_ENGINE_PROTECTION = 18,  /* only compared - never stored in the dumped ROM: cm550_rpmHistogramAndAveragingStatistics counts the trip record 1216 +6C TIT3DQTM 'TIME THE FUELING HAS BEEN UNDER CONTROL OF ENGINE PROTECTION SINCE LAS(T ...)' (the text is cut; dword 0x806192 - 0 in the RAM dump) while final_fueling_state is 18. The engine protection fuel derate itself stamps 29 (FUELING_STATE_FAULT_DERATE - Calterm EPFDERAT), so with the dumped code that counter cannot advance; 18 is another code of the same feature family - Calterm FSFNFLST 12=EPF (no CM848 member) (was FUELING_STATE_ENGINE_PROTECTION; PR #53 round 94) */
    FUELING_STATE_MAXIMUM_THROTTLE = 19,  /* Calterm FSFNFLST 13=MAXTHROT (CM848's member of the same label) */
    FUELING_STATE_TSC1_TORQUE_LIMIT = 20,  /* Calterm FSFNFLST 14=JCTRQDER (CM848's member of the same label) */
    FUELING_STATE_OUT_OF_GEAR = 21,  /* Calterm FSFNFLST 15=OUTOGEAR (no CM848 member) */
    FUELING_STATE_CRANKING = 22,  /* Calterm FSFNFLST 16=CRANK (CM848's member of the same label) */
    FUELING_STATE_FUEL_OVERRIDE = 23,  /* Calterm FSFNFLST 17=OVERRIDE (CM848's member of the same label) */
    FUELING_STATE_ENGINE_BRAKE = 24,  /* Calterm FSFNFLST 18=ENGBRAKE (CM848's member of the same label) */
    FUELING_STATE_OVERSPEED = 25,  /* Calterm FSFNFLST 19=OVERSPED (CM848's member of the same label) */
    FUELING_STATE_ENGINE_STOPPED = 26,  /* Calterm FSFNFLST 1A=STOP (CM848's member of the same label) */
    FUELING_STATE_SHUTDOWN = 27,  /* Calterm FSFNFLST 1B=SHUTDOWN (CM848's member of the same label) */
    FUELING_STATE_FUEL_SYSTEM_DERATE = 28,  /* Calterm FSFNFLST 1C=FSSDERAT (CM848's member of the same label) */
    FUELING_STATE_FAULT_DERATE = 29,  /* Calterm FSFNFLST 1D=EPFDERAT (CM848's member of the same label) */
    FUELING_STATE_ALL_SPEED_GOVERNOR_APPLICATION = 30,  /* Calterm FSFNFLST 1E=ASG_APPL (CM848's member of the same label) */
    FUELING_STATE_ALTERNATE_TORQUE = 31,  /* Calterm FSFNFLST 1F=ALT_TORQ (no CM848 member) */
    FUELING_STATE_MASTER_SLAVE_OVERRIDE = 32,  /* Calterm FSFNFLST 20=MSOVRIDE (CM848's member of the same label) */
    FUELING_STATE_ENGINE_WARMUP_PROTECTION = 33,  /* torque_derate_fuel_source_code (cm550_applyEngineWarmupProtectionFuelLimit 0x17120): with engine_state RUNNING and engine_warmup_protection_fuel_limiting_flag (e2m 11EA +0 WPLMFG) set - engine_warmup_protection_fuel_limit (11EA +14 WPTQLM) is below the running derate minimum. The warmup protection limits the fuel after a start until the oil pressure has been up long enough - Calterm FSFNFLST 21=ESUOILLM (no CM848 member) (was FUELING_STATE_ENGINE_WARMUP_PROTECTION; PR #53 round 94) */
    FUELING_STATE_POWER_TAKE_OFF_DERATE = 34,  /* Calterm FSFNFLST 22=PTODERAT (CM848's member of the same label) */
    FUELING_STATE_TORQUE_CONTROL = 35,  /* Calterm FSFNFLST 23=TORQCTRL (no CM848 member) */
    FUELING_STATE_UNIDENTIFIED_36 = 36,  /* Calterm FSFNFLST 24=PTPDERAT (no CM848 member; the label's meaning is not proved) */
    FUELING_STATE_TOP2_TRANSMISSION_SPEED_CONTROL = 37,  /* only compared - never stored in either firmware. A speed control state of the Top2 transmission feature: CM848's all-speed governor runs while engine_operating_mode is 7 / 2 / 30 / 37, and 37 is tested with 38 beside the TSC1 states 1 / 2 in the power take-off - cruise - governed fueling and driver demand selection; both EEC1 torque mode tables put 37 with the accelerator pedal states. e2m group TOP208 'TOP2 CALIBRATIONS AND DATA' holds the T2* records (T2HGSXDR 'TOP2 SPICER TRANSMISSION HIGH GEAR DRIVER SOLENOID') - Calterm FSFNFLST 25=T2SPD (was FUELING_STATE_TOP2_TRANSMISSION_SPEED_CONTROL) (was FUELING_STATE_TOP2_TRANSMISSION_SPEED_CONTROL; PR #53 round 94) */
    FUELING_STATE_TOP2_TRANSMISSION_TORQUE_CONTROL = 38,  /* only compared - never stored in either firmware. The torque control state of the Top2 transmission feature: CM848 tests it with 37 beside the TSC1 states 1 / 2 (power take-off - cruise - governed fueling - driver demand selection) but its all-speed governor does not run in 38 - as it does not in TSC1 torque control (1). CM550 has it only in the EEC1 torque mode table, in the torque limiting group - Calterm FSFNFLST 26=T2TORQ (was FUELING_STATE_TOP2_TRANSMISSION_TORQUE_CONTROL) (was FUELING_STATE_TOP2_TRANSMISSION_TORQUE_CONTROL; PR #53 round 94) */
    FUELING_STATE_UNIDENTIFIED_39 = 39,  /* Calterm FSFNFLST 27=T2DERAT (no CM848 member; the label's meaning is not proved) */
    FUELING_STATE_NO_DERATE = 40,  /* Calterm FSFNFLST 28=NODERAT (CM848's member of the same label) */
    FUELING_STATE_IMMOBILIZER_FUEL_DISABLE = 41  /* Calterm FSFNFLST 29=ATDERAT (CM848's member of the same label) */
} FUELING_STATE;

typedef enum {
    J1939_CONTROL_DEVICE_NONE = 0,  /* e2m Jcomm_Engine_Control_Device_Indicator 0 = NONE */
    J1939_CONTROL_DEVICE_TRANSMISSION = 1,  /* 1 = TRANS: the sender is j1939_transmission_source_address */
    J1939_CONTROL_DEVICE_ANTI_LOCK_BRAKES = 2,  /* 2 = ABS: j1939_anti_lock_brake_source_address */
    J1939_CONTROL_DEVICE_ANTI_SLIP_REGULATION = 3,  /* 3 = ASR: j1939_anti_slip_regulation_source_address */
    J1939_CONTROL_DEVICE_UNKNOWN = 4  /* 4 = UNKNOWN: any other source address */
} J1939_CONTROL_DEVICE;

typedef enum {
    TSC1_OVERRIDE_OFF = 0,  /* SPN 695 00 = override disabled (e2m Jcomm_Engine_Control_Mode / Jcomm_Retarder_Control_Mode 0 = disable) */
    TSC1_SPEED_CONTROL = 1,  /* SPN 695 01 = speed control: the engine governs to the requested speed (e2m 1 = speed) */
    TSC1_TORQUE_CONTROL = 2,  /* SPN 695 10 = torque control (e2m 2 = torque) */
    TSC1_SPEED_TORQUE_LIMIT = 3  /* SPN 695 11 = speed and torque limit control (e2m 3 = limit) */
} TSC1_OVERRIDE_MODE;

typedef enum {
    IDLE_SHUTDOWN_STATE_RESET = 0,  /* Not counting: the timer is held at the idle shutdown period, the warning lamp request and the overridden / override successful flags are cleared and output 30 is switched off (unless a client overrides it); leaves to COUNT when idle_shutdown_reset_flag is 0. PGN 65252 byte 1 = 0x00. (new enum, size 2, type of idle_shutdown_state) (PR #53 round 94) */
    IDLE_SHUTDOWN_STATE_COUNT = 1,  /* The idle shutdown timer counts down (0.1 s per pass): to RESET on the reset flag, to DELAY when the temperature option and the override successful flag are set, to WARNING when the timer is at or below the warning period. PGN 65252 byte 1 = 0x40 (SPN 590 idle shutdown timer state active). (PR #53 round 94) */
    IDLE_SHUTDOWN_STATE_WARNING = 2,  /* Shutdown approaching: sets the warning lamp request ISWRRQ and counts passes; to OVERRIDE when the override is enabled and successful, to RESET on the reset from warning flag, to SHUTDOWN after the warning period. PGN 65252 byte 1 = 0x44 (timer state active + SPN 594 driver alert mode active). (PR #53 round 94) */
    IDLE_SHUTDOWN_STATE_DELAY = 3,  /* A 600-pass (60 s) delay before the override, entered from COUNT with the temperature option: to RESET on the reset flag, to OVERRIDE when the delay timer reaches 0. PGN 65252 byte 1 is left unchanged. No J90350.00 e2m text names this state; the name is the code's delay timer, and the later CHR_B2 e2m labels value 3 DELAY. (PR #53 round 94) */
    IDLE_SHUTDOWN_STATE_OVERRIDE = 4,  /* Idle shutdown overridden: the timer is reloaded, the warning request cleared, ISOD (overridden until the vehicle moves) and the override lamp request ISODRQ set; to RESET on the reset from override flag. PGN 65252 byte 1 = 0x10 (SPN 592 idle shutdown timer override active). (PR #53 round 94) */
    IDLE_SHUTDOWN_STATE_SHUTDOWN = 5  /* The idle shutdown has shut the engine down: on entry the warning request is cleared, the engine shutdown command SHSS set and output 30 switched on; to RESET when engine_state is CRANKING. PGN 65252 byte 1 = 0x01 (SPN 593 idle shutdown has shut down engine). (PR #53 round 94) */
} IDLE_SHUTDOWN_STATE;

typedef enum {
    EEPROM_BYTE_WRITE_STATE_IDLE = 0,  /* No write in progress: the driver step stores the words read into the EEPROM mirror and queues the next read; a queued write takes it to SEND_WRITE. (new enum, size 4, type of eeprom_byte_write_state) (PR #53 round 94) */
    EEPROM_BYTE_WRITE_STATE_SEND_WRITE = 1,  /* Send the next queued byte write: write enable (command 6) and write (command 2) with the queue entry's address and data byte; then WAIT_FOR_COMPLETION. (PR #53 round 94) */
    EEPROM_BYTE_WRITE_STATE_WAIT_FOR_COMPLETION = 2  /* A write was sent: read the status register (command 5) each pass until the write-in-progress bit is clear, then SEND_WRITE when more is queued, else IDLE with a READ at the saved offset. (PR #53 round 94) */
} EEPROM_BYTE_WRITE_STATE;

/* ---- Structures ---- */

typedef struct j1939_msg_hdr_t j1939_msg_hdr_t;
typedef struct j1939_tx_msg_t j1939_tx_msg_t;
typedef struct engine_overspeed_event_t engine_overspeed_event_t;
typedef struct j1939_diagnostic_service_entry_t j1939_diagnostic_service_entry_t;
typedef struct can_std_rx_desc_t can_std_rx_desc_t;
typedef struct param_lookup_args_t param_lookup_args_t;
typedef struct table_interp_args_t table_interp_args_t;
typedef struct dma_descriptor_t dma_descriptor_t;
typedef struct memory_operation_request_t memory_operation_request_t;
typedef struct q16_fixed_point_t q16_fixed_point_t;
typedef struct division_operand_t division_operand_t;
typedef struct sensor_config_t sensor_config_t;
typedef struct ema_filter_state_t ema_filter_state_t;
typedef struct second_order_filter_state_t second_order_filter_state_t;
typedef struct sensor_state_t sensor_state_t;
typedef struct cummins_data_plate_header_t cummins_data_plate_header_t;
typedef struct module_variant_offsets_t module_variant_offsets_t;
typedef struct cummins_data_plate_t cummins_data_plate_t;
typedef struct j1939_tx_msg_buffer_t j1939_tx_msg_buffer_t;
typedef struct j1939_vp44_msg_t j1939_vp44_msg_t;
typedef struct diag_service_request_t diag_service_request_t;
typedef struct diag_tp_state_t diag_tp_state_t;
typedef struct diag_transfer_state_t diag_transfer_state_t;
typedef struct fuel_governor_state_t fuel_governor_state_t;
typedef struct fuel_demand_state_t fuel_demand_state_t;
typedef struct fuel_limit_arbitration_t fuel_limit_arbitration_t;
typedef struct engine_rpm_target_t engine_rpm_target_t;
typedef struct engine_operating_mode_t engine_operating_mode_t;
typedef struct high_rpm_protection_t high_rpm_protection_t;
typedef struct rpm_fuel_protection_t rpm_fuel_protection_t;
typedef struct fault_persistence_counters_t fault_persistence_counters_t;
typedef struct fault_status_registers_t fault_status_registers_t;
typedef struct vp44_fault_state_t vp44_fault_state_t;
typedef struct timing_mode_control_t timing_mode_control_t;
typedef struct scheduler_phase_slot_t scheduler_phase_slot_t;
typedef struct scheduler_phase_table_t scheduler_phase_table_t;
typedef struct system_callback_table_t system_callback_table_t;
typedef struct address_range_entry_t address_range_entry_t;
typedef struct circular_buffer_control_t circular_buffer_control_t;
typedef struct huffman_tree_node_t huffman_tree_node_t;
typedef struct huffman_tree_t huffman_tree_t;
typedef struct insite_parameter_schedule_entry_t insite_parameter_schedule_entry_t;
typedef struct memory_region_t memory_region_t;
typedef struct parameter_id_table_entry_t parameter_id_table_entry_t;
typedef struct fault_count_record_t fault_count_record_t;
typedef struct datalogger_trigger_t datalogger_trigger_t;
typedef struct datalogger_data_parameter_t datalogger_data_parameter_t;
typedef struct datalogger_trigger_information_t datalogger_trigger_information_t;
typedef struct all_speed_governor_gain_set_t all_speed_governor_gain_set_t;
typedef struct j1939_receive_handler_entry_t j1939_receive_handler_entry_t;
typedef struct j1939_input_signal_descriptor_t j1939_input_signal_descriptor_t;
typedef struct tsc1_source_configuration_t tsc1_source_configuration_t;
typedef struct algorithm_enable_flags_1_t algorithm_enable_flags_1_t;
typedef struct cm550_algorithm_enable_flags_2_t cm550_algorithm_enable_flags_2_t;
typedef struct cm550_algorithm_enable_flags_3_t cm550_algorithm_enable_flags_3_t;
typedef struct algorithm_enable_flags_4_t algorithm_enable_flags_4_t;
typedef struct cm550_algorithm_enable_flags_5_t cm550_algorithm_enable_flags_5_t;
typedef struct cm550_algorithm_enable_flags_7_t cm550_algorithm_enable_flags_7_t;
typedef struct cm550_algorithm_enable_flags_8_t cm550_algorithm_enable_flags_8_t;
typedef struct algorithm_enable_flags_11_t algorithm_enable_flags_11_t;
typedef struct cm550_algorithm_enable_flags_12_t cm550_algorithm_enable_flags_12_t;
typedef struct cm550_algorithm_enable_flags_13_t cm550_algorithm_enable_flags_13_t;
typedef struct cm550_algorithm_enable_flags_14_t cm550_algorithm_enable_flags_14_t;
typedef struct cm550_algorithm_enable_flags_16_t cm550_algorithm_enable_flags_16_t;
typedef struct cm550_algorithm_enable_flags_18_t cm550_algorithm_enable_flags_18_t;
typedef struct algorithm_enable_flags_25_t algorithm_enable_flags_25_t;
typedef struct cm550_algorithm_enable_flags_27_t cm550_algorithm_enable_flags_27_t;
typedef struct cm550_algorithm_enable_flags_28_t cm550_algorithm_enable_flags_28_t;
typedef struct cm550_algorithm_enable_flags_32_t cm550_algorithm_enable_flags_32_t;
typedef struct cm550_algorithm_enable_flags_33_t cm550_algorithm_enable_flags_33_t;
typedef struct cm550_fault_entry_t cm550_fault_entry_t;
typedef struct cm550_commanded_throttle_state_t cm550_commanded_throttle_state_t;
typedef struct j1939_control_session_t j1939_control_session_t;
typedef struct j1939_periodic_transmit_entry_t j1939_periodic_transmit_entry_t;
typedef struct engine_tsc1_ignored_request_t engine_tsc1_ignored_request_t;
typedef struct cm550_retarder_tsc1_ignored_request_t cm550_retarder_tsc1_ignored_request_t;
typedef struct table_lookup_2d_arguments_t table_lookup_2d_arguments_t;

struct j1939_msg_hdr_t {
    uint32_t can_id;  /* The CAN identifier: priority / PGN / source address (was j1939_header_t.id; CM848's type name; PR #53 round 88) */
    uint16_t data_length;  /* The payload length in bytes: above 8 goes out as a transport session (was j1939_header_t.length; PR #53 round 88) */
};

struct j1939_tx_msg_t {
    j1939_msg_hdr_t header;  /* The CAN identifier and the payload length */
    void * data_pointer;  /* Points at the first payload byte */
    void * status_pointer;  /* Points at the message's status byte j1939_<message>_transmit_status: the send result or the transport session code (CM848's layout; PR #53 round 88) */
};

struct engine_overspeed_event_t {
    uint32_t start_key_on_hour_meter;  /* key_on_hour_meter when the overspeed began */
    uint16_t engine_speed_at_detection;  /* engine_rpm_primary on the pass the overspeed latch set */
    uint16_t duration;  /* The passes the overspeed lasted (PR #53 round 88) */
};

struct j1939_diagnostic_service_entry_t {
    J1939_DIAGNOSTIC_SERVICE service_id;  /* The PGN 61184 service byte */
    uint8_t pad;  /* Unused */
    void * handler;  /* The service handler registerJ1939DiagnosticService stored (PR #53 round 88) */
};

struct can_std_rx_desc_t {
    uint32_t id;  /* 11-bit CAN ID stored in 32-bit (ABI) */
    uint16_t length;  /* DLC */
    uint8_t * data_ptr;  /* Pointer to payload bytes */
};

struct param_lookup_args_t {
    uint32_t calculated_block;  /* Block x 256 x 4 calculation result */
    uint16_t offset;  /* Parameter offset within block */
    uint16_t result_value;  /* Retrieved parameter value (capped at 32000) */
};

struct table_interp_args_t {
    uint16_t current_index;  /* Current interpolation index into table */
    uint32_t x_axis_ptr;  /* Pointer to X-axis table (input values) */
    uint16_t input_value;  /* Input value for table lookup */
    uint32_t y_axis_ptr;  /* Pointer to Y-axis table (output values) */
};

struct dma_descriptor_t {
    uint32_t source_address;  /* DMA transfer source memory address */
    uint32_t dest_address;  /* DMA transfer destination memory address */
    uint16_t transfer_count;  /* Number of bytes/words to transfer */
    uint16_t control_flags;  /* DMA control flags (mode type enable etc) */
    uint32_t next_descriptor;  /* Pointer to next descriptor in chain */
};

struct memory_operation_request_t {
    uint32_t source_data_ptr;  /* Pointer to source data for memory operation */
    uint32_t target_data_ptr;  /* Pointer to destination memory location */
    uint16_t operation_size;  /* Number of bytes to copy (max 1764 bytes) */
    uint16_t metadata_value;  /* Logging metadata/timestamp for circular buffer */
};

struct q16_fixed_point_t {
    uint16_t integer_part;  /* High 16 bits - integer/whole number portion */
    uint16_t fractional_part;  /* Low 16 bits - fractional portion */
};

struct division_operand_t {
    uint16_t value;  /* Primary 16-bit value (used for division) */
    uint16_t limit;  /* Secondary 16-bit limit/clamp value */
};

struct sensor_config_t {
    uint16_t filter_coefficient;  /* +0: A/D digital filter constant (1/65536): the weight of the previous value - the channel's sensor_state_t.filter.coefficient points here and cm550_exponentialMovingAverage reads it (Calterm ...CS) */
    uint16_t default_value;  /* +2: global default value in the channel's units: filtered_value and the accumulator (<< 16) while the fault is active or on a tri-state reading (Calterm ...GD or ADDF + the channel code) */
    int16_t fault_clear_threshold;  /* +4: A/D fault clear counts: debounce_counter at or below it clears fault_active_flag; each high / low status bit (0x806000) clears only while its 0x806040 first-occurrence bit is clear (Calterm ...CC or ...FC) */
    int16_t debounce_counter_decrement;  /* +6: A/D fault decrement: taken off debounce_counter on each in-range sample (floored at 0) (Calterm ...DT or ...FD) */
    int16_t debounce_counter_increment;  /* +8: A/D fault increment: added to debounce_counter on each out-of-range sample (Calterm ...IC or ...FI) */
    int16_t fault_set_threshold;  /* +10: A/D fault set: debounce_counter at or above it sets the fault and is capped there (Calterm ...SE or ...FS) */
    uint16_t high_error_limit;  /* +12: A/D high error limit in raw counts (0-1023): adc_raw_value above it counts toward high_error_fault_number (Calterm ...HL) */
    uint16_t low_error_limit;  /* +14: A/D low error limit in raw counts: adc_raw_value below it counts toward low_error_fault_number (Calterm ...LL) */
    uint16_t qadc_result_register_index;  /* +16: the QADC result slot (0-39) whose right-justified result register (0xfff2b0 + 2 x n) gives adc_raw_value (Calterm ...CA: channel address) */
    uint8_t multiplexer_setting;  /* +18: channel multiplexer setting: no reader in J90350.00 (0 in all 25 records) (Calterm ...MU) */
    uint8_t tri_state_error_enable;  /* +19: tri-state flag: nonzero makes a lookup result of 4 count toward tri_state_error_fault_number (0 in all 25 records) (Calterm ...TS) */
    uint8_t high_error_fault_number;  /* +20: the fault the high limit sets (bit n mod 16 of status word n / 16 at 0x806000 / 0x806040) (Calterm ...HE) */
    uint8_t low_error_fault_number;  /* +21: the fault the low limit sets (Calterm ...LE) */
    uint8_t tri_state_error_fault_number;  /* +22: the in-range / tri-state error: set at the fifth consecutive lookup result of 4 and cleared at the fifth other reading (Calterm ...TE) */
    uint8_t sample_period;  /* +23: the channel runs once every sample_period passes of the A/D loop (0 = not processed); the e2m scale calls a pass 20 ms - not measured (Calterm ...SA or ...SR) */
};

struct ema_filter_state_t {
    word* coefficient;  /* Points at the filter coefficient word: the weight of the previous value in 1/65536 (0 = no filtering) */
    uint32_t accumulator;  /* Q16.16 filtered value (offset binary in the signed filter); the filters return its rounded integer part */
};

struct second_order_filter_state_t {
    word* coefficient_1;  /* +0: points at coefficient 1 (1/65535): the weight of the new input */
    word* coefficient_3;  /* +4: points at coefficient 3 (1/65535): the weight of the output before last */
    uint32_t output;  /* +8: the filter output (its integer part is returned) */
    uint32_t output_previous;  /* +12: the output of the previous call */
};

struct sensor_state_t {
    ema_filter_state_t filter;  /* +0: the channel's filter record (its coefficient points at the channel config's +0 filter constant) (was reserved_00; PR #53 round 88) */
    uint16_t filtered_value;  /* +8: the filter output - or the config default while the fault is active - or the channel's override value (Calterm ...FT: filtered and linearized) (was interpolated_value; PR #53 round 88) */
    uint16_t unfiltered_value;  /* +10: the linearized reading before the filter - the table lookup result (Calterm ...UF: unfiltered and linearized) (was lookup_result; PR #53 round 89) */
    int16_t debounce_counter;  /* +12: the fault debounce count (signed: floored at 0) */
    uint8_t fault_active_flag;  /* +14: fault currently active flag */
    uint8_t sample_counter;  /* +15: sample phase counter */
    uint16_t adc_raw_value;  /* +16: raw A/D conversion value (Calterm ...RC: raw counts) */
    uint32_t reserved_18;  /* +18-+21: no access; 0 in all 25 dumped records. One dword: as byte[4] the decompiler made it the base of byte arithmetic (the array end and indexed channel reads) (was reserved_12 - the hex offset; PR #53 round 88; byte[4] until round 89) */
};

struct cummins_data_plate_header_t {
    uint16_t data_plt_module_id;  /* Module identifier (EN=0x454E for CM550/VP44 ECUs) */
};

struct module_variant_offsets_t {
    uint16_t cm550_data_plate_offset;  /* CM550 data plate offset (0x2C0) */
    uint16_t vp44_data_plate_offset;  /* VP44 data plate offset (0x2C0-0x22=0x29E) */
    uint8_t incal_variant_code;  /* InCal calibration variant (A/B/C) */
};

struct cummins_data_plate_t {
    uint16_t data_plate_length;  /* Data plate length field */
    uint8_t engine_make[5];  /* Engine manufacturer identifier (JCMMNS) */
    uint8_t engine_model[17];  /* Engine model designation (ISB 195) */
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
    uint32_t ecm_part_number;  /* ECM part number (98502) */
    uint32_t ecm_serial_number;  /* ECM serial number (T03942860) */
};

struct j1939_tx_msg_buffer_t {
    uint8_t data[8];  /* J1939 message payload data array */
    j1939_msg_hdr_t header;  /* CAN message header (ID + length) */
};

struct j1939_vp44_msg_t {
    uint8_t j1939_status_byte;  /* J1939 transmission message status/header byte */
    uint8_t fuel_amount_high;  /* Fuel amount high byte */
    uint8_t fuel_amount_low;  /* Fuel amount low byte */
    uint8_t rpm_low;  /* Engine RPM low byte */
    uint8_t rpm_high;  /* Engine RPM high byte */
    uint32_t vp44_header;  /* VP44 0x100 command message header */
    uint8_t timing_byte3;  /* VP44 timing advance data byte 3 */
    uint8_t timing_byte4;  /* VP44 timing advance data byte 4 */
    uint8_t timing_byte5;  /* VP44 timing advance data byte 5 */
    uint8_t timing_byte6;  /* VP44 timing advance data byte 6 */
};

struct diag_service_request_t {
    uint8_t message_length;  /* Total message length including header */
    uint8_t service_id;  /* Service identifier (3=secured 4=control 5=memory) */
    uint8_t sub_function;  /* Sub-function code for service routing */
    uint8_t data_payload[16];  /* Variable-length request data payload */
};

struct diag_tp_state_t {
    uint8_t diag_state;  /* State flag: 0=idle 1=active */
    uint8_t expected_id_low;  /* Expected low byte of std CAN ID */
    uint16_t expected_guard;  /* Guard word; must match (payload[6]<<8) */
    uint8_t total_packets;  /* ((total_bytes-1)/7)+1 */
    uint8_t req_start;  /* Current sequence index (1-based) */
    uint8_t req_count;  /* Remaining packets to send */
    uint8_t pre_status;  /* Abort/status flag (non-zero aborts with 7) */
    uint16_t total_bytes;  /* Total payload length */
    uint8_t * src_data_ptr;  /* Pointer to source payload */
    uint8_t * resp_byte_ptr;  /* Pointer to 1-byte response/status */
    uint8_t status_code;  /* Countdown/NACK (0x37 init or 0x70 delay) */
    uint8_t reserved_0x47;  /* Padding */
    uint32_t tx_header_id;  /* Composed CAN ID for TP.CM/TP.DT */
    uint16_t tx_length;  /* DLC for frame (8 or tail) */
    uint8_t * tx_cm_buf;  /* Scratch 8-byte CM/DT buffer */
};

struct diag_transfer_state_t {
    uint16_t target_address;  /* Target memory address for transfer */
    uint32_t data_pointer;  /* Pointer to source/dest data buffer */
    uint16_t remaining_length;  /* Remaining bytes to transfer */
    uint16_t byte_count;  /* Total byte count for operation */
    uint8_t tx_active_flag;  /* Transmit operation active (0/1) */
    uint8_t rx_active_flag;  /* Receive operation active (0/1) */
};

struct fuel_governor_state_t {
    int16_t out_cmd;  /* Final clamped output (governor/fueling command) */
    int16_t cmd_raw;  /* Current raw command (signed) */
    int16_t term_ff;  /* Feed-forward/scaling term (signed) */
    int16_t term_rate;  /* Rate/derivative term (signed saturating) */
    ushort accum_lo;  /* Q16.16 accumulator low 16 bits (fractional part) */
    ushort accum_hi;  /* Q16.16 accumulator high 16 bits (integer part) */
    int16_t limit_hi;  /* Accumulator integer ceiling (upper clamp) */
    int16_t limit_cap;  /* Accumulator/output cap */
    int16_t rpm_window;  /* RPM window/threshold term used for gating */
};

struct fuel_demand_state_t {
    uint16_t command;  /* Current fuel demand value */
    uint8_t source_identifier;  /* Source of fuel command (FUEL_SOURCE_ID enum) */
    uint8_t reserved_03;  /* Padding byte */
    uint16_t diagnostic_buffer;  /* Diagnostic parameter buffer */
    uint16_t timing_blend_factor;  /* Fuel timing blend factor 0-16384 */
    uint16_t table_output;  /* Fuel demand table output */
    uint16_t limit_minimum;  /* Fuel limit minimum value */
    uint16_t demand_source_id;  /* Fuel demand source identifier */
    uint16_t adjustment_active;  /* Fuel adjustment active flag */
};

struct fuel_limit_arbitration_t {
    uint16_t source_id;  /* ID of current fuel limit source */
    uint16_t demand_limited;  /* Rate-limited fuel demand */
    uint16_t arbitration_threshold;  /* Fuel limit arbitration threshold */
    uint16_t demand_delta;  /* Fuel demand delta for rate limiting */
    uint16_t maximum_limit;  /* Maximum fuel demand limit */
    uint16_t offset_value;  /* Fuel limit offset value */
    uint16_t comparison_low;  /* Fuel limit comparison low value */
    uint16_t comparison_high;  /* Fuel limit comparison high value */
    uint16_t rate_limit;  /* Fuel demand rate limiting value */
};

struct engine_rpm_target_t {
    uint16_t target_engine_rpm;  /* Commanded/target engine RPM */
};

struct engine_operating_mode_t {
    uint16_t state;  /* Engine operating mode state 1-8 */
    uint16_t shutdown_complete_flag;  /* Engine shutdown complete flag */
};

struct high_rpm_protection_t {
    uint16_t fault_flag;  /* High RPM protection fault active flag */
    uint16_t state;  /* State machine state */
    uint16_t timer;  /* Countdown timer */
    uint16_t reserved_06;  /* Reserved/gap */
    uint16_t warning_flag;  /* Warning active flag */
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

struct vp44_fault_state_t {
    uint16_t fault_status;  /* VP44 fault status register */
    uint16_t fso_fault_status;  /* VP44 FSO fault status register 2 */
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
    uint16_t reserved_14;  /* Gap/reserved */
    uint16_t reserved_16;  /* Gap/reserved */
    uint16_t blend_accumulator;  /* Timing blend accumulator */
    uint16_t reserved_1A;  /* Gap/reserved */
    uint16_t fuel_source_mode_11_state;  /* Fuel source mode 11 state */
    uint16_t fuel_source_mode_11_timer;  /* Fuel source mode 11 timer */
    uint16_t fuel_mode_transition_state;  /* Fuel mode transition state */
    uint16_t fuel_mode_transition_timer;  /* Fuel mode transition timer */
};

struct scheduler_phase_slot_t {
    uint32_t last_execution_time;  /* Timer value of last task execution */
    uint16_t runtime_ticks;  /* Task runtime duration in timer ticks */
    uint16_t deadline_ticks;  /* Task execution deadline (0xFFFF = disabled) */
    uint16_t execution_count;  /* Number of times task has been executed */
    uint16_t overrun_count;  /* Number of deadline overruns detected */
    uint32_t reserved;  /* Reserved/padding bytes for alignment */
};

struct scheduler_phase_table_t {
    scheduler_phase_slot_t slots[1];  /* Array of phase slots - size depends on scheduler_phase_slot_count */
};

struct system_callback_table_t {
    uint32_t engine_position_sensor_isr;  /* EPS position sensor ISR handler */
    uint32_t tpu_adc_isr;  /* TPU/QADC interrupt handler */
    uint32_t main_loop_callback;  /* Main scheduler loop callback */
};

struct address_range_entry_t {
    uint32_t start_address;  /* Start of valid address range (big-endian) */
    uint32_t end_address;  /* End of valid address range (big-endian) */
    uint8_t special_mode_flag;  /* Access flag when water_in_fuel_detection_flag==1 */
    uint8_t normal_mode_flag;  /* Access flag in normal operation */
};

struct circular_buffer_control_t {
    uint32_t read_ptr;  /* Current read position pointer */
    uint32_t write_ptr;  /* Current write position pointer */
    uint32_t base_ptr;  /* Start address of buffer data */
    uint32_t end_ptr;  /* End address of buffer data */
    uint8_t full_flag;  /* Buffer full indicator (1=full 0=space available) */
};

struct huffman_tree_node_t {
    uint16_t frequency;  /* Symbol frequency or combined weight */
    uint16_t left_child;  /* Index of left child node (0-512) */
    uint16_t right_child;  /* Index of right child node (0-512) */
};

struct huffman_tree_t {
    huffman_tree_node_t nodes;  /* Array of 513 tree nodes (256 leaves + 257 internal) */
    uint16_t root_marker;  /* Root node marker at offset 0x600 */
    uint16_t terminator;  /* Tree terminator at offset 0xC06 (set to 0xFFFF) */
};

struct insite_parameter_schedule_entry_t {
    uint8_t parameter_id;  /* The parameter's ID (0 ends the list) - vp44_insiteParameterTableIterator tests its bit in the 32-byte bitmap at ROM 0x6134a before it calls cm550_activeParamReadFunction */
    uint8_t period;  /* Schedule ticks between two sends: the iterator adds it to the parameter's next due tick each time that tick comes */
    uint8_t first_due_offset;  /* Ticks added to the period for the first due tick (the initializer mc68k_initializeJ1708Datalink sets next due = period + this) */
};

struct memory_region_t {
    uint32_t start_address;  /* First address of the region */
    uint32_t end_address;  /* Last address of the region (inclusive) */
    MEMORY_REGION_TYPE region_type;  /* The type while the development mode flag (0x80de30) is 1 */
    MEMORY_REGION_TYPE development_mode_off_region_type;  /* The type while the development mode flag is not 1 (the registers become REFUSED) */
};

struct parameter_id_table_entry_t {
    uint32_t address_ram_refresh_disabled;  /* +0: the parameter's address while ram_refresh_enable is RAM_REFRESH_DISABLED (development mode); 0 = no parameter */
    uint32_t address_ram_refresh_enabled;  /* +4: the address otherwise; equal to +0 in all 1806 J90350.00 entries */
};

struct fault_count_record_t {
    uint32_t status_change_time;  /* +0: key_on_hour_meter (0.2 s counts) when the fault last became active (status 3) or inactive (status 2) - cm550_processFaultScanGroup stores it (move.l at 0x14972 / 0x14bd0). The first countdown step waits until key_on_hour_meter minus it reaches the mode's elapsed time before countdown (e2m DGnnELTM at 0x80654c + 8 x mode); cm550_findOldestFreezeFrameEntryByFaultStatus picks the snapshot slot whose fault has the smallest one (cmp.l at 0x146fa); cm550_resetFaultStatus zeroes it. Unsigned (sub.l then cmp.l / bls) */
    uint32_t last_countdown_time;  /* +4: key_on_hour_meter at the last countdown step (move.l at 0x145bc); 0 until the first step - the activation (clr.l at 0x14988) and cm550_resetFaultStatus (clr.l at 0x2fe0e) zero it. While it is not 0 each step waits until key_on_hour_meter minus it reaches the mode's count down rate (e2m DGnnCUDN at 0x806550 + 8 x mode). Unsigned (sub.l then cmp.l / bhi) */
    uint8_t status;  /* +8: bit 0 = active / bit 1 = given a snapshot slot in fault_freeze_frame_entries[0].fault_code_index. cm550_processFaultScanGroup writes 3 on activation (after cm550_assignFaultFreezeFrameEntry assigns the slot) and 2 on deactivation (whatever bit 1 was - in the RAM dump fault 70 is 2 and holds no slot); the registrar writes 0 (from 2) or 1 (from 3) to the oldest fault whose slot it hands to a new fault; cm550_resetFaultStatus releases the slot when the status is 2 and writes 0. Readers test bit 0 (btst #0 in the countdown) or group 1 / 3 against 0 / 2 (cm550_FUN_000315be / cm550_evaluateDataloggerTrigger) */
    uint8_t occurrence_count;  /* +9: times the fault became active: +1 on each new fault bit mapped to it up to 255 (cmpi.b #0xff / bcc at 0x1491e) and -1 per countdown step (subq.b at 0x145d4); at 0 the record is cleared and the fault leaves previously_active_dtc_list. DM1 / DM2 send it capped at 127 (cmpi.b #0x7f / bls) and the InSite fault list (J1587 PID 194 layout) sends it whole; cm550_insitePidDtcHandler skips a fault whose count is 0. Unsigned */
};

struct datalogger_trigger_t {
    uint8_t value_length;  /* +0 (e2m UD0nTRBY 'DATALOGGER TRIGGER LENGTH' 0-4): the width in bytes of the value the trigger compares: 1 = byte / 2 = word / any other value = dword (move.b (0;a0;d0.w*8);d0b at 0x13f30 then cmp.b #1 / #2 / #4); 2 in all four dump records */
    uint8_t disable_flag;  /* +1 (UD0nTRDB 'DISABLES DATALOGGER TRIGGER INPUT'): nonzero = not evaluated; the trigger task then stores 1 (satisfied) for triggers 1-3 so the AND condition ignores them and 0 for trigger 4 (tst.b (0;a0;d3.w) at 0x1396c with a0 = 0x803d65 / tst.b $803d95 at 0x13994); 1 in all four dump records */
    uint16_t fault_code_flag;  /* +2 (UD0nTRFU 'SET TRIGGER INPUT TO A FAULT CODE'): 1 = the trigger watches a fault code's status in the fault count table / 0 = it compares a parameter with threshold. The address is resolved only for 0 (tst.w at 0x13dd2) and the fault is looked up only for 1 (cmpi.w #1 at 0x13cf4 / 0x13e78); the evaluation takes the fault path for any nonzero value (tst.w at 0x13f00); 0 in the dump */
    uint16_t above_threshold_or_fault_active_flag;  /* +4 (UD0nTRMD 'TRIGGER => THRESHOLD OR < THRESHOLD'): parameter trigger: nonzero = satisfied while the value is above threshold / 0 = while it is below; both strict (bls / bcc / ble / bge after cmp; tst.w at 0x13f0e). Fault trigger: nonzero = satisfied on the pass the fault status turns from inactive (0 or 2) to active (1 or 3) / 0 = on the pass it turns from active to inactive (tst.w at 0x1419c); 1 in the dump */
    uint16_t parameter_id_or_fault_code;  /* +6 (UD0nTRNM 'NAME TABLE NAME'): with fault_code_flag 0 the parameter ID passed to cm550_lookupParameterIdAddress (move.w (0;a0;d2.w);-(sp) at 0x13de0); with 1 the fault code matched against the code word of the 125 six-byte fault definitions at 0x8067c4 (cmp.w (a2);d0w at 0x13ea0); dump 0x100c / 0x1004 / 0x1051 / 0x1047 */
    uint16_t parameter_offset;  /* +8 (UD0nTROF 'NAME TABLE OFFSET'): byte offset added zero-extended to the parameter ID's address (move.w (0;a0;d2.w);d0w / andi.l #0xffff / add.l d0;(a2) at 0x13df2-0x13dfc); dump 2 / 0x76 / 0 / 0 */
    uint32_t threshold;  /* +10 = +0xA (UD0nTRTD 'TRIGGER THRESHOLD' 0-FFFFFFFF): read as one dword (move.l (0;a0;d2.w)) and compared through its low byte for value_length 1 (andi.l #0xff - also in signed mode so a 1-byte threshold is 0-255) / its low word for 2 / the whole dword otherwise; dump 0x18fc / 0 / 0 / 0x4f */
    uint16_t signed_value_flag;  /* +14 = +0xE (UD0nTRTY 'DATA TYPE (SET: SIGNED; CLEAR: UNSIGNED)'): nonzero = signed compares (extb.l / ble / bge) / 0 = unsigned (bls / bcc) (tst.w at 0x13f1c and 0x1405c with a0 = 0x803d72); 0 in the dump */
};

struct datalogger_data_parameter_t {
    uint16_t value_length;  /* +0 (e2m 1283 UD0nDXBY 'DATALOGGER DATA LENGTH' 0-10): bytes copied from the parameter's address into the ring buffer at each sample (move.w (0;a0;d4.w);d0w at 0x13bb2); the set-up counts the parameters whose running byte total stays at or below 10 (move.w at 0x13abe / add.b d0b;d2b / cmpi.b #10 at 0x13ac4); 2 in all five dump records */
    uint16_t parameter_id;  /* +2 (UD0nDXNM 'NAME TABLE NAME'): the parameter ID passed to cm550_lookupParameterIdAddress (move.w (0;a0;d2.w);-(sp) at 0x13e2a); dump 0x100c / 0x1004 / 0x1051 / 0x1047 / 0x1004 */
    uint16_t parameter_offset;  /* +4 (UD0nDXOF 'NAME TABLE OFFSET'): byte offset added zero-extended to that address (move.w at 0x13e3c / andi.l #0xffff / add.l d0;(a2) at 0x13e46); dump 2 / 0x76 / 0 / 0 / 0x8c */
};

struct datalogger_trigger_information_t {
    uint16_t ring_buffer_trigger_offset;  /* +0: the ring buffer write pointer minus the ring buffer start (0x800374) when the event began (move.l $800504;d0 / subi.l #0x800374;d0 / move.w d0w;$800522 at 0x13b06-0x13b12): where the first post-trigger byte sits in the saved 400-byte copy */
    uint32_t trigger_key_on_hour_meter;  /* +2: key_on_hour_meter when the event began (move.l $80bda4;$800524 at 0x13b18) */
    uint8_t and_inputs_trigger_flag;  /* +6: the low byte of the AND trigger flag word 0x80bac6 (e2m 1285 +2 UDADTR; move.b $80bac7;$800528 at 0x13b22): 1 when triggers 1-3 together started the event */
    uint8_t or_input_trigger_flag;  /* +7: the low byte of the OR trigger flag word 0x80bac8 (e2m 1285 +4 UDORTR; move.b $80bac9;$800529 at 0x13b2c): 1 when trigger 4 started the event */
};

struct all_speed_governor_gain_set_t {
    int16_t proportional_gain_1;  /* +0: e2m ASPP01GN / ASJ1nnPP / ASAP01PP 'ASG proportional gain 1' (%F/R 8.29282E-6 per count; signed). cm550_runAllSpeedGovernor multiplies (this + integral_gain_1) by asg_error_difference (move.w (a3) + ext.l @ 0xcd86) (PR #53 round 91) */
    int16_t proportional_gain_2;  /* +2: e2m ASPP02GN / ASJ2nnPP / ASAP02PP 'ASG proportional gain 2' (%F/R; signed). cm550_runAllSpeedGovernor subtracts asg_feedback_difference_term x this from the PI sum (muls.w (2;a3) = c1eb 0002 @ 0xcdc2) (PR #53 round 91) */
    int16_t integral_gain_1;  /* +4: e2m ASIT01GN / ASJ1nnIT / ASAP01IT 'ASG integral gain 1' (F/RS 0.000414641 per count; signed). cm550_runAllSpeedGovernor: the reference preset divides by asg_droop_gain_2 x (this + integral_gain_2) (move.w (4;a0) + ext.l @ 0xc9b8); the PI sum uses (proportional_gain_1 + this) and (this + integral_gain_2) (move.w (a2) + ext.l @ 0xcd8a / 0xcda2 with a2 = pointer + 4) (PR #53 round 91) */
    int16_t integral_gain_2;  /* +6: e2m ASIT02GN / ASJ2nnIT / ASAP02IT 'ASG integral gain 2' (F/RS; signed). cm550_runAllSpeedGovernor: the reference preset (move.w (6;a0) + ext.l @ 0xc9c4) and (integral_gain_1 + this) x the previous speed error X1 in the PI sum (move.w (6;a3) + ext.l @ 0xcda6) (PR #53 round 91) */
    int16_t derivative_gain_1;  /* +8: e2m ASDV01GN / ASJ1nnDV / ASAP01DV 'ASG derivative gain 1' (FS/R 3.31713E-7 per count; signed). cm550_runAllSpeedGovernor: derivative term = (asg_error_difference x this - asg_feedback_difference_term x derivative_gain_2) >> 13 (muls.w (8;a0) = c1e8 0008 @ 0xce16) (PR #53 round 91) */
    int16_t derivative_gain_2;  /* +10: e2m ASDV02GN / ASJ2nnDV / ASAP02DV 'ASG derivative gain 2' (FS/R; signed). cm550_runAllSpeedGovernor subtracts asg_feedback_difference_term x this in the derivative term (muls.w (10;a0) = c1e8 000a @ 0xce28) (PR #53 round 91) */
    int16_t compensation_filter_coefficient_1;  /* +12: e2m AS01CF / ASJ1nnCF / ASAP01CF 'ASG compensation filter coef. 1' (0.00390625 per count; signed). cm550_runAllSpeedGovernor: state X6 = (X5 x this - previous X5 x coefficient 2 + previous X6 x coefficient 3) >> 8 (muls.w (12;a2) = c1ea 000c @ 0xcfea); in the state preset this equal to coefficient 2 (cmp.w (14;a0) @ 0xcbce) gives a zero preset and otherwise the preset divides by this - coefficient 2 (move.w (12;a2) + ext.l @ 0xcbfa / 0xcc58) (PR #53 round 91) */
    int16_t compensation_filter_coefficient_2;  /* +14: e2m AS02CF / ASJ2nnCF / ASAP02CF 'ASG compensation filter coef. 2' (signed). cm550_runAllSpeedGovernor: the previous X5 term of X6 (muls.w (14;a2) = c1ea 000e @ 0xcff2; subtracted) and the preset compare and divisor (cmp.w (14;a0) @ 0xcbce; move.w (14;a2) + ext.l @ 0xcc00 / 0xcc5e) (PR #53 round 91) */
    int16_t compensation_filter_coefficient_3;  /* +16: e2m AS03CF / ASJ3nnCF / ASAP03CF 'ASG compensation filter coef. 3' (signed). cm550_runAllSpeedGovernor: the previous X6 term of X6 (muls.w (16;a2) = c1ea 0010 @ 0xcffa) and the preset factor 0x100 - this (move.w (16;a2) + ext.l @ 0xcc0a / 0xcc68) (PR #53 round 91) */
};

struct j1939_receive_handler_entry_t {
    uint16_t pgn_key;  /* The PGN key: the PDU format and PDU specific bytes as one word - specific 0 for a destination-specific PGN (0xef00 = PGN 61184 / 0xfef1 = PGN 65265 / 0 = TSC1) */
    void * handler;  /* The receive handler: the dispatcher mc68k_dispatchJ1939ReceivedMessages calls it with the received frame's record */
};

struct j1939_input_signal_descriptor_t {
    byte* signal_value;  /* The received signal byte (a j1939_received_* switch byte) */
    uint8_t timeout_slot;  /* Index into j1939_input_signal_timeouts */
    uint8_t reserved_5;  /* Always 0 (no reader) */
    uint32_t logical_switch;  /* The logical switch this input drives: cm550_processJ1939SwitchInput indexes the e2m 12A8 input priority bytes (0x80bd4a) and the switch bitmaps with it and tests enable bit switch + 0xd0 of the calibration feature words (it reads the low word at +8 for that) */
};

struct tsc1_source_configuration_t {
    uint16_t data_link;  /* e2m 10E7 JCNES{n}SW 'JCOMM NETWORK TYPE SA n' (0 = J1922 / 1 = J1939): findTsc1SourceConfiguration compares it with the data link (cmp.w (a0)); only data link 1 takes the 0xff source address wildcard. 1 in all five entries of the RAM dump. CM848's field is typed CONTROL_NETWORK, an enum CM550 does not have yet */
    uint16_t source_address_filter;  /* e2m JCSA{n} 'JCOMM SOURCE ADDRESS n' (2 bytes, 0-255): findTsc1SourceConfiguration compares the low byte (+3, cmp.b (3,a0)) with the source address; 0xff on data link 1 matches any sender. RAM dump 0x03 / 0x0b / 0x21 / 0xfe / 0xfe, high byte 0 (CM848 reads the word and masks the low byte) */
    uint16_t speed_control_request_timeout;  /* e2m JCRPS{n}TM (10 ms per count): the request timeout of a speed control request (mode 1); processEngineTsc1Request and the J1922 command handlers reload datalink_command_timeout_counter with it + 1. 5 = 50 ms in the dump */
    uint16_t speed_control_time_limit;  /* e2m JCRPS{n}TL (10 ms per count): the time limit of a speed control request; cm550_runJ1939PowertrainControlTimeouts reloads the time limit word 0x80da7e with it + 1 when the request starts or changes. 0 in the dump */
    uint16_t torque_control_request_timeout;  /* e2m JCTQS{n}TM (10 ms per count): the request timeout of a torque control request (mode 2). 5 in the dump */
    uint16_t torque_control_time_limit;  /* e2m JCTQS{n}TL (10 ms per count): the time limit of a torque control request (the 0x80da7e reload). 0 in the dump */
    uint16_t speed_torque_limit_control_request_timeout;  /* e2m JCLMS{n}TM (10 ms per count): the request timeout of a speed / torque limit control request (mode 3). 5 in the dump */
    uint16_t retarder_torque_control_request_timeout;  /* e2m JCRDT{n}TM (10 ms per count): cm550_retarderControlModeHandler reloads retarder_command_timeout_counter (and retarder_disengage_hold_timer) with it + 1 for a retarder torque control request (mode 2). 25 = 250 ms in the dump */
    uint16_t retarder_torque_control_time_limit;  /* e2m JCRDT{n}TL (10 ms per count): cm550_runJ1939PowertrainControlTimeouts reloads retarder_tsc1_request_time_limit_timer with it + 1. 0 in the dump */
    uint16_t retarder_speed_torque_limit_control_request_timeout;  /* e2m JCRDL{n}TM (10 ms per count): the retarder speed / torque limit control (mode 3) request timeout (retarder_command_timeout_counter / retarder_disengage_hold_timer reload). 25 in the dump */
};

struct algorithm_enable_flags_1_t {
    uint16_t alpha_user_override_enable : 1;  /* bit 0: APUOAPEN 'BIT 0 WORD 1. EEPROM INDICATOR SET BY ENGR APPLICATION(S TO CONTROL ALPHA)'; andi 0x1 at 0xc3a2: calculateAlpha takes alpha_state 1 with the user alpha 0x803d4c; clear in the dumps */
    uint16_t user_override_fueling_enable : 1;  /* bit 1: FSUOFLEN 'BIT 1 WORD 1. ENABLE INDICATOR FOR ENGINEERING FUEL OV(ERRIDE)'; andi 0x2 at 0x1c204: cm550_selectFinalFueling takes the fuel limit from 0x803f2c (selection state 0x17); clear */
    uint16_t test_cell_throttle_switch_override_enable : 1;  /* bit 2: CTTHSWOD 'DISABLES AUTOZERO & IDLE VALIDATION' (bit 2 of 0-15); andi.l 0x4 at 0x10602 / 0x1084e: the throttle processing skips its idle validation fault checks while set; clear */
    uint16_t user_override_timing_enable : 1;  /* bit 3: TSUOTAEN 'BIT 3 WORD 1. INDICATOR OF WHICH ALGORITHM IS IN CONTR(OL OF THE OVERRIDE TIMING)'; andi 0x8 at 0x30bc2: vp44InjectionSystemStateController selects the override timing 0x804024 (timing state 7); clear */
    uint16_t torque_derate_override_enable : 1;  /* bit 4: FSTQUOEN 'BIT 4 WORD 1. ENABLE INDICATOR FOR TORQUE DERATE FUEL (OVERRIDE)'; andi 0x10 at 0x1c16e: cm550_selectFinalFueling sets torque_derate_fuel_quantity from 0x803f2a (state 0xd); clear */
    uint16_t altitude_derate_enable : 1;  /* bit 5: ATAGEN 'BIT 5 OF 0-15. CALIBRATION TRIM USED TO ENABLE THE ALTITUDE (DERATE)'; andi 0x20 at 0xc686: _altitude_derate_fuel_limit_0_100 comes from the ambient air pressure table only while set; clear */
    uint16_t reserved_bit_6 : 1;  /* bit 6: no e2m record; no reader in the dumped ROM; clear in the dumps */
    uint16_t reserved_bit_7 : 1;  /* bit 7: no e2m record; no reader in the dumped ROM; clear in the dumps */
    uint16_t reserved_bit_8 : 1;  /* bit 8: no e2m record; no reader in the dumped ROM; clear in the dumps */
    uint16_t reserved_bit_9 : 1;  /* bit 9: no e2m record; no reader in the dumped ROM; clear in the dumps */
    uint16_t reserved_bit_10 : 1;  /* bit 10: no e2m record; no reader in the dumped ROM; clear in the dumps */
    uint16_t reserved_bit_11 : 1;  /* bit 11: no e2m record; no reader in the dumped ROM; clear in the dumps */
    uint16_t low_speed_governor_aggressive_gain_set_enable : 1;  /* bit 12: LSAGGNEN 'LOW SPEED GOVERNOR AGGRESSIVE GAIN SET ENABLE' (no bit in the CM550 text; CM848 S mask 0x1000); andi 0x1000 at 0x26188: cm550_epsAccelerationMonitor selects LSG PID gain set 1; set in the dumps */
    uint16_t low_speed_governor_high_gear_gain_set_enable : 1;  /* bit 13: LSHGGNEN 'ENABLES THE LSG GAIN SET FOR WHEN IN HIGH GEARS' (CM848 S mask 0x2000); andi.l 0x2000 at 0x26408: cm550_epsDiagnosticModeHandler selects gain set 3 (the high gear gains); clear */
    uint16_t low_speed_governor_middle_gear_gain_set_enable : 1;  /* bit 14: LSMGGNEN 'ENABLE PARAMETER FOR LSG GAIN SET USED WHEN IN MIDDLE (GEARS)' (CM848 S mask 0x4000); andi.l 0x4000 at 0x263e0: cm550_epsDiagnosticModeHandler selects gain set 2 (the middle gear gains); clear */
    uint16_t low_speed_governor_tsc1_gain_set_enable : 1;  /* bit 15: LSJCGNEN 'ENABLES/DISABLES THE LSG JCOMM PID GAINS' (CM848 S mask 0x8000); andi.l 0x8000 at 0x265ee: cm550_epsRpmTargetModeChecker selects gain set 4 while _datalink_speed_control_mode is set; clear */
};

struct cm550_algorithm_enable_flags_2_t {
    uint16_t engine_protection_shutdown_enable : 1;  /* bit 0: EPSOEN 'BIT 0 OF 0-15. ENABLE SHUTDOWN ALGORITHM'; andi 0x1 at 0x18ade / 0x18cba / 0x18fe6 (cm550_diagnosticProtectionEvaluator / cm550_protectionState1DiagnosticValidator / processDiagnosticLimitStatus); clear in the dumps */
    uint16_t reserved_bit_1 : 1;  /* bit 1: no record belongs here: JC22CCSW's text says 'BIT 1 OF BITS 0:15' but the code tests that flag at 0x100 (bit 8); no reader in the dumped ROM; clear */
    uint16_t reserved_bit_2 : 1;  /* bit 2: no e2m record; no reader in the dumped ROM; clear */
    uint16_t idle_shutdown_during_power_take_off_enable : 1;  /* bit 3: ISRPEN S mask 0x8 'BIT 3 WORD2. 1 - PTO WILL NOT OVERRIDE SHUTDOWN' (0 = power take-off overrides the idle shutdown; another e2m: Idle_Shutdown_PTO_Enable 0x8); no reader in the dumped ROM; CM848 has no record (reserved_bit_3); clear */
    uint16_t engine_protection_enable : 1;  /* bit 4: EPEN 'BIT 4 OF 0-15. ENGINE PROTECTION FEATURES ENABLE'; andi 0x10 at 0x18628: cm550_engineProtectionMultiStateSlowCycle40Coordinator runs the protection phases only while set (else no derate); also 0x18ace / 0x1cade; set */
    uint16_t engine_protection_restart_enable : 1;  /* bit 5: EPRYEN 'BIT 5 OF 0-15. ENABLE RESTART ALGORITHM'; andi.l 0x20 at 0x18aee / 0x18cca (the restart checks after a protection shutdown); set */
    uint16_t engine_retarder_clutch_deactivation_enable : 1;  /* bit 6: EBCHDBEN 'BIT 6 OF 0-15. CALIBRATION INDICATOR USED TO ENABLE EN(GINE BRAKE DEACTIVATION)'; CM848 label EB_Clutch_Enable mask 0x40; no reader in the dumped ROM; set */
    uint16_t j1922_monitor_enable : 1;  /* bit 7: JC22MRSW 'J1922 MONITOR ENABLE' (no bit in the text; CM848 S mask 0x80); andi.w 0x80 at 0x1fdc6: cm550_recordJ1922ControlOccurrence counts the control sessions of modes 1 / 2 / 3 with key-on hour stamps; clear */
    uint16_t j1922_monitor_clear_enable : 1;  /* bit 8: JC22CCSW 'J1922 MONITOR CLEAR ENABLE' (its text says bit 1; CM848 and other e2m S mask 0x100); andi.l 0x100 at 0x1fd6c: cm550_clearExpiredJ1922ControlOccurrences clears those session counters once the J1922 clear occurrence time has passed; clear */
    uint16_t reserved_bit_9 : 1;  /* bit 9: no e2m record; no reader in the dumped ROM; clear */
    uint16_t reserved_bit_10 : 1;  /* bit 10: no e2m record; no reader in the dumped ROM; clear */
    uint16_t j1939_monitor_enable : 1;  /* bit 11: JC39MREA 'J1939 MONITOR ENABLE' (no bit in the text; CM848 S mask 0x800); andi.w 0x800 at 0x22080: trackJ1939ControlSessions records the J1939 speed control session history; set */
    uint16_t j1939_retarder_shift_assist_enable : 1;  /* bit 12: JCRDTXEA 'ENABLE FOR SPEED CONTROL / ENGINE BRAKING INTERACTION' (CM848 S mask 0x1000); andi 0x1000 at 0x21432 (endRetarderShiftAssistAboveFuelDemandLimit ends retarder mode 2 at or above the user fueling limit) / 0x2f850 (cm550_retarderControlModeHandler) / 0x33900 (cm550_dutyCycleMonitorAltIsrHandler status 0x40); set */
    uint16_t power_take_off_throttle_override_enable : 1;  /* bit 13: PTTHOVEN 'BIT 13 OF 0-15. CALIBRATION INDICATOR AS TO WHETHER (THROTTLE DEPRESSION DISABLES PTO)'; andi.l 0x2000 at 0x2dd34: cm550_oil_pressure_shutdown_controller lets throttle fueling override power take-off fueling; clear */
    uint16_t user_commanded_timing_increment_enable : 1;  /* bit 14: TSUCICEN 'BIT 14 WORD 2. PARAMETER USED TO ENABLE THE USER TIMING (INCREMENT)'; andi 0x4000 at 0x1c770: cm550_fuelDemandTableBlendCalculator adds 0x803f3c to the 4D timing; clear */
    uint16_t zero_vehicle_speed_power_take_off_limit_enable : 1;  /* bit 15: ZVPTLMEN 'BIT 15 WORD 2 - ENABLE ENGINE SPEED TO BE LIMITED (WHEN IN PTO MODE)'; no reader in the dumped ROM; clear */
};

struct cm550_algorithm_enable_flags_3_t {
    uint16_t reserved_bit_0 : 1;  /* bit 0: no e2m record; no reader in the dumped ROM; clear in the dumps */
    uint16_t idle_shutdown_enable : 1;  /* bit 1: ISAGEN S mask 0x2 '1 - IDLE SHUTDOWN ENABLED' (word 3 bit 1); andi 0x2 at 0x1d9ca (cm550_runIdleShutdownStateMachine = the idle shutdown state machine) / 0xefbe (J1587 PID 71 status bit 0x08) / 0x33d80 (PGN 65252 payload byte 0x8035f7 = 0x7f or 0x3f); CM848 reserved_bit_1; clear */
    uint16_t idle_shutdown_override_enable : 1;  /* bit 2: ISODEN S mask 0x4 '1 - ISOD IS ABLE TO BE SET' (ISOD = idle shutdown overridden until the vehicle moves); andi.l 0x4 at 0x1dab0 (cm550_runIdleShutdownStateMachine) / 0xefd6 (J1587 PID 71 status bit 0x04); CM848 reserved_bit_2; clear */
    uint16_t idle_speed_adjust_enable : 1;  /* bit 3: LSISAJEN 'BIT 3 OF 0-15. ENABLE ALLOWS OPERATOR TO ADJUST SPEED'; andi.l 0x8 at 0x26490: the idle increment / decrement switches move the low speed governor reference only while set; set */
    uint16_t power_take_off_enable : 1;  /* bit 4: PTAGEN S mask 0x10 'BIT 4 OF 0-15. PARAMETER USED TO ENABLE/DISABLE PTO'; andi.l 0x10 at 0x2dd0a: cm550_oil_pressure_shutdown_controller (the power take-off / user fueling selection) uses the closed-loop PTO fueling only while set; clear */
    uint16_t remote_power_take_off_enable : 1;  /* bit 5: PTRXEN 'BIT 5 OF 0-15. CALIBRATION INDICATOR AS TO WHETHER REMOTE PTO IS ALLO(WED)' (full text and S mask 0x20 from other e2m files); no reader in the dumped ROM; CM848 reserved_bit_5; set */
    uint16_t cruise_control_enable : 1;  /* bit 6: CRAGEN 'BIT 6 OF 0-15. STATUS INDICATOR WHICH ENABLES/DISABL(ES CRUISE CONTROL)'; no reader in the dumped ROM; set */
    uint16_t road_speed_governor_enable : 1;  /* bit 7: RSAGEN 'ENABLE/DISABLE ROAD SPEED GOVERNOR FOR ENGINEERING USE' (bit 7); no reader in the dumped ROM; set */
    uint16_t gear_down_protection_enable : 1;  /* bit 8: GRGDPNEN 'GEAR DOWN PROTECTION ENABLE' (bit 8 of 0-15; another e2m: Gear_Down_Protection_Enable S mask 0x100); no reader in the dumped ROM; CM848 reads this bit below top gear (no road speed governor droops there) and its field takes the same name in this change; clear */
    uint16_t trip_information_enable : 1;  /* bit 9: TIEN 'BIT 9 OF 0-15 IN WORD 3. TRIP INFO SYSTEM ENABLED = 1' (another e2m: Fuel_Log_Enable S mask 0x200); andi 0x200 at 0x306e0 (cm550_FUN_000306ca resets the trip records) / 0x30a64 (fuel statistics flags); CM848 reserved_bit_9; set */
    uint16_t cruise_governor_droop_enable : 1;  /* bit 10: CRDPEN 'BIT 10 OF 0-15. BIT 10 IS CRUISE_RSG_DROOP_ENABLE'; no reader in the dumped ROM; set */
    uint16_t cylinder_pressure_maintenance_enable : 1;  /* bit 11: CPAGEN 'BIT 11 OF 0-15. ENABLES AND DISABLES THE CYLINDER PRESSURE MAINTENANC(E)'; andi.l 0x800 at 0x11e74: cm550_coldStartFuelControlSlowCycle40Coordinator zeroes _cylinder_pressure_maintenance_status and its timing increment while clear; CM848 reserved_bit_11; clear */
    uint16_t acceleration_noise_control_fuel_limit_enable : 1;  /* bit 12: NZFLAGEN 'ENABLE FOR FUEL LIMITING OF THE ACCELERATION NOISE C(ONTROL)' (no bit in the CM550 text; CM848 e2m ANC_Fuel_Algorithm_Enable S mask 0x1000); andi 0x1000 at 0xb2c6: cm550_rpm_system_state_controller computes _anc_fuel_limit_value; clear */
    uint16_t acceleration_noise_control_timing_limit_enable : 1;  /* bit 13: NZTAAGEN 'ENABLE FOR TIMING ADVANCE OF THE ACCELERATION NOISE (CONTROL)' (CM848 e2m ANC_Timing_Algorithm_Enable S mask 0x2000); andi 0x2000 at 0xb3ec: cm550_FUN_0000b3d0 = the ANC timing limit; clear */
    uint16_t acceleration_noise_control_engine_speed_limit_enable : 1;  /* bit 14: NZESAGEN 'ENABLE FOR SPEED LIMITING OF THE ACCELERATION NOISE (CONTROL)' (CM848 e2m ANC_Speed_Algorithm_Enable S mask 0x4000); andi 0x4000 at 0xb50e: cm550_engineStateFuelLimitInterpolator = the ANC engine speed limit; clear */
    uint16_t cruise_save_set_speed_at_power_down_enable : 1;  /* bit 15: CRSVPWEN 'ENABLES/DISABLES SAVING CRUISE SET SP(EED)' (bit 15 of 0-15); no reader in the dumped ROM; set */
};

struct algorithm_enable_flags_4_t {
    uint16_t user_commanded_fueling_enable : 1;  /* bit 0: FSUCFLEN 'BIT 0 WORD 4. ENABLES THE USE OF USER_COMMANDED_FUELING'; andi.l 0x1 at 0x3456e: cm550_setDiagnosticSourceFromEngineFlags sets user_fueling_state 5 with the fuel demand from 0x80404a; clear in the dumps */
    uint16_t reserved_bit_1 : 1;  /* bit 1: no e2m record; no reader in the dumped ROM; clear */
    uint16_t reserved_bit_2 : 1;  /* bit 2: no e2m record; no reader in the dumped ROM; clear */
    uint16_t reserved_bit_3 : 1;  /* bit 3: no e2m record; no reader in the dumped ROM; clear */
    uint16_t reserved_bit_4 : 1;  /* bit 4: no e2m record; no reader in the dumped ROM; clear */
    uint16_t reserved_bit_5 : 1;  /* bit 5: no e2m record; no reader in the dumped ROM; clear */
    uint16_t reserved_bit_6 : 1;  /* bit 6: no e2m record; no reader in the dumped ROM; clear */
    uint16_t reserved_bit_7 : 1;  /* bit 7: no e2m record; no reader in the dumped ROM; clear */
    uint16_t user_commanded_timing_enable : 1;  /* bit 8: TSUCTAEN and ADV_OVER 'BIT 8 OF WORD 4. ENABLE INDICATOR FOR THE ENGINE(ERING COMMAND TIMING ADVANCE)'; andi 0x100 at 0x1c67a: cm550_fuelDemandTableBlendCalculator takes the 4D timing from 0x803f3e (intermediate timing state 2); clear */
    uint16_t reserved_bit_9 : 1;  /* bit 9: no e2m record; no reader in the dumped ROM; clear */
    uint16_t reserved_bit_10 : 1;  /* bit 10: no e2m record; no reader in the dumped ROM; clear */
    uint16_t reserved_bit_11 : 1;  /* bit 11: no e2m record; no reader in the dumped ROM; clear */
    uint16_t reserved_bit_12 : 1;  /* bit 12: no e2m record; no reader in the dumped ROM; clear */
    uint16_t reserved_bit_13 : 1;  /* bit 13: no e2m record; no reader in the dumped ROM; clear */
    uint16_t reserved_bit_14 : 1;  /* bit 14: no e2m record; no reader in the dumped ROM; clear */
    uint16_t reserved_bit_15 : 1;  /* bit 15: no e2m record; no reader in the dumped ROM; clear */
};

struct cm550_algorithm_enable_flags_5_t {
    uint16_t intake_manifold_temperature_override_enable : 1;  /* bit 0: ADIMTPOD S mask 0x1 'INTAKE_MANIFOLD_TEMPERATURE_OVERRIDE'; channel 0 intake_manifold_temperature_sensor_state: mc68k_processAnalogSensorChannels (word load at 0xb7d2) takes analog_sensor_override_values[0] while set; clear in the dumps */
    uint16_t fuel_temperature_override_enable : 1;  /* bit 1: ADFLTPOD S mask 0x2 'FUEL_TEMPERATURE_OVERRIDE'; channel 1 fuel_temperature_sensor_state via the channel loop; clear */
    uint16_t coolant_level_override_enable : 1;  /* bit 2: ADCVOD S mask 0x4 'COOLANT_LEVEL_OVERRIDE'; channel 2 coolant_level_sensor_state via the channel loop; clear */
    uint16_t fuel_pressure_override_enable : 1;  /* bit 3: ADSYFPOD S mask 0x8 'ALGORITHM_ENABLE_FLAGS WORD 5 BIT 3' (other e2m files: 'OVERRIDE FOR FUEL PRESSURE FILTERED VALUE'); channel 3 fuel_pressure_sensor_state (stem ADSYFP) via the channel loop; clear */
    uint16_t oil_pressure_override_enable : 1;  /* bit 4: ADOLPROD S mask 0x10 'OIL_PRESSURE_OVERRIDE'; channel 4 oil_pressure_sensor_state via the channel loop; clear */
    uint16_t boost_pressure_override_enable : 1;  /* bit 5: ADBSPROD S mask 0x20 'BOOST_PRESSURE_OVERRIDE'; channel 5 boost_pressure_sensor_state via the channel loop; clear */
    uint16_t coolant_temperature_override_enable : 1;  /* bit 6: ADCLTPOD S mask 0x40 'COOLANT_TEMPERATURE_OVERRIDE'; channel 6 coolant_temperature_sensor_state via the channel loop; clear */
    uint16_t ambient_air_temperature_override_enable : 1;  /* bit 7: ADAATPOD S mask 0x80 'AMBIENT_AIR_TEMPERATURE_OVERRIDE'; channel 7 ambient_air_temperature_sensor_state via the channel loop; clear */
    uint16_t power_steering_temperature_override_enable : 1;  /* bit 8: ADPOTPOD S mask 0x100 'POWER_STEERING_TEMPERATURE_OVERRIDE'; channel 8 power_steering_temperature_sensor_state via the channel loop; clear */
    uint16_t exhaust_pressure_override_enable : 1;  /* bit 9: ADSYEPOD S mask 0x200 'SPARE_CHANNEL_1_OVERRIDE' (other e2m files: ADEXPROD 0x200 'OVERRIDE FOR EXHAUST PRESSURE FILTERED VALUE'); channel 9 exhaust_pressure_sensor_state (stem ADSYEP) via the channel loop; clear */
    uint16_t sampled_throttle_override_enable : 1;  /* bit 10: ADSATHOD S mask 0x400 'SAMPLED_THROTTLE_OVERRIDE'; channel 10 sampled_throttle_sensor_state via the channel loop; also andi 0x400 at 0x10584 / 0x1083e (throttle processing skipped) / 0x20cae / 0x20e4a (a J1939 accelerator pedal fills analog_sensor_override_values[10]) / 0x2582e / 0x32f78 (EEC2 pedal position 0xff); clear */
    uint16_t remote_throttle_override_enable : 1;  /* bit 11: ADROTHOD S mask 0x800 'REMOTE_THROTTLE_OVERRIDE'; channel 11 remote_throttle_sensor_state via the channel loop; also andi.l 0x800 at 0x32fd8 (j1939HandlePgn61443Eec2 sends the remote accelerator position as 0xff); clear */
    uint16_t ambient_air_pressure_override_enable : 1;  /* bit 12: ADAAPROD S mask 0x1000 'AMBIENT_AIR_PRESSURE_OVERRIDE'; channel 12 ambient_air_pressure_sensor_state via the channel loop; clear */
    uint16_t battery_voltage_override_enable : 1;  /* bit 13: ADBTVTOD S mask 0x2000 'ALGORITHM_ENABLE_FLAGS WORD 5 BIT 13' (other e2m files: 'OVERRIDE FOR BATTERY VOLTAGE OVERRIDE FILTERED VALUE'); channel 13 battery_voltage_sensor_state (stem ADBTVT) via the channel loop; clear */
    uint16_t engine_speed_sensor_supply_voltage_override_enable : 1;  /* bit 14: ADESSVOD S mask 0x4000 'ENGINE_SPEED_SENSOR_SV_OVERRIDE'; channel 14 engine_speed_sensor_supply_voltage_sensor_state via the channel loop; clear */
    uint16_t throttle_position_sensor_supply_voltage_override_enable : 1;  /* bit 15: ADTHSVOD S mask 0x8000 'THROTTLE_POSITION_SENSOR_SV_OVERRIDE'; channel 15 throttle_position_sensor_supply_voltage_sensor_state via the channel loop; clear */
};

struct cm550_algorithm_enable_flags_7_t {
    uint16_t coolant_level_fueling_limiting_enable : 1;  /* bit 0: EPCVFLEN 'BIT 0 OF 0-15. ENABLE PARAMETER FOR FUEL LIMITIN(G DUE TO COOLANT LEVEL)'; table bit 112 = 0x70 + 4 x 0 + 0 (channel 0): read by the fuel limit loop cm550_FUN_00019702; set in the dumps */
    uint16_t coolant_level_rpm_limiting_enable : 1;  /* bit 1: EPCVRPEN 'BIT 1 OF 0-15. ENABLE PARAMETER FOR RPM LIMITING (DUE TO COOLANT LEVEL)'; table bit 113 = 0x70 + 4 x 0 + 1 (channel 0): read by cm550_calculateFaultDerateEngineSpeedLimit; set in the dumps */
    uint16_t coolant_level_shutdown_enable : 1;  /* bit 2: EPCVSOEN 'BIT 2 OF 0-15. ENABLE SHUTDOWN ON COOLANT LEVEL (ERRORS)'; table bit 114 = 0x70 + 4 x 0 + 2 (channel 0): read by the shutdown loop processDiagnosticLimitStatus and by the restart checks; set in the dumps */
    uint16_t coolant_level_restart_enable : 1;  /* bit 3: EPCVRYEN 'B3. PREVENTS RESTART AT POWERUP WHEN SHUTDN CNT > (MAX SHUTDN CNT DUE TO CLT LEV)'; table bit 115 = 0x70 + 4 x 0 + 3 (channel 0): read by the restart checks cm550_diagnosticProtectionEvaluator / cm550_protectionState1DiagnosticValidator; set in the dumps */
    uint16_t coolant_temperature_fueling_limiting_enable : 1;  /* bit 4: EPCQFLEN 'BIT 4 OF 0-15. ENABLE PARAMETER FOR FUEL LIMITIN(G DUE TO COOLANT TEMPERATURE)'; table bit 116 = 0x70 + 4 x 1 + 0 (channel 1): read by the fuel limit loop cm550_FUN_00019702; set in the dumps */
    uint16_t coolant_temperature_rpm_limiting_enable : 1;  /* bit 5: EPCQRPEN 'BIT 5 OF 5-15. EPF COOLANT TEMPERATURE RPM LIMIT(ING ENABLE)'; table bit 117 = 0x70 + 4 x 1 + 1 (channel 1): read by cm550_calculateFaultDerateEngineSpeedLimit; set in the dumps */
    uint16_t coolant_temperature_shutdown_enable : 1;  /* bit 6: EPCQSOEN 'BIT 6 OF 0-15. ENABLE SHUTDOWN ON COOLANT TEMPER(ATURE ERRORS)'; table bit 118 = 0x70 + 4 x 1 + 2 (channel 1): read by the shutdown loop processDiagnosticLimitStatus and by the restart checks; set in the dumps */
    uint16_t coolant_temperature_restart_enable : 1;  /* bit 7: EPCQRYEN 'BIT 7 OF 0-15. PREVENTS RESTART AT POWERUP WHEN S(HUTDN CNT > MAX SHUTDN CNT)'; table bit 119 = 0x70 + 4 x 1 + 3 (channel 1): read by the restart checks cm550_diagnosticProtectionEvaluator / cm550_protectionState1DiagnosticValidator; set in the dumps */
    uint16_t intake_manifold_temperature_fueling_limiting_enable : 1;  /* bit 8: EPIMFLEN 'BIT 8 OF 0-15 ENABLE FOR TVO LIMITING DUE TO INTA(KE MANIFOLD TEMP)'; table bit 120 = 0x70 + 4 x 2 + 0 (channel 2): read by the fuel limit loop cm550_FUN_00019702; set in the dumps */
    uint16_t intake_manifold_temperature_rpm_limiting_enable : 1;  /* bit 9: EPIMRPEN 'BIT 9 OF 0-15. ENABLE PARAMETER FOR RPM LIMITING (DUE TO IMT)'; table bit 121 = 0x70 + 4 x 2 + 1 (channel 2): read by cm550_calculateFaultDerateEngineSpeedLimit; set in the dumps */
    uint16_t intake_manifold_temperature_shutdown_enable : 1;  /* bit 10: EPIMSOEN 'BIT 10 OF 0-15. ENABLE SHUTDOWN ON INTAKE MANIFO(LD TEMPERATURE ERRORS)'; table bit 122 = 0x70 + 4 x 2 + 2 (channel 2): read by the shutdown loop processDiagnosticLimitStatus and by the restart checks; set in the dumps */
    uint16_t intake_manifold_temperature_restart_enable : 1;  /* bit 11: EPIMRYEN 'BIT 11 OF 0-15. PREVENTS RESTART AT POWERUP WHEN (SHUTDN CNT > MAX SHUTDN CNT)'; table bit 123 = 0x70 + 4 x 2 + 3 (channel 2): read by the restart checks cm550_diagnosticProtectionEvaluator / cm550_protectionState1DiagnosticValidator; set in the dumps */
    uint16_t oil_pressure_fueling_limiting_enable : 1;  /* bit 12: EPO2FLEN 'BIT 12 OF 0-15. ENABLE PARAMETER FOR FUEL LIMITI(NG DUE TO OIL PRESSURE)'; table bit 124 = 0x70 + 4 x 3 + 0 (channel 3): read by the fuel limit loop cm550_FUN_00019702; also tested directly: andi.w #0x1000 at 0x1983e (cm550_FUN_00019702) - while set and oil_pressure_fault_inhibit_timer is below the power-up period 0x807f34 the oil pressure fueling severity index and the loop maximum are forced to 0x100 (the full derate); set in the dumps */
    uint16_t oil_pressure_rpm_limiting_enable : 1;  /* bit 13: EPO2RPEN 'BIT 13 OF 0-15. EPF OIL PRESSURE FAULT ENABLE PA(RAMETER)' (CM848 label Oil_Pressure_RPM_Limiting_Enable); table bit 125 = 0x70 + 4 x 3 + 1 (channel 3): read by cm550_calculateFaultDerateEngineSpeedLimit; set in the dumps */
    uint16_t oil_pressure_shutdown_enable : 1;  /* bit 14: EPO2SOEN 'BIT 14 OF 0-15. ENABLE SHUTDOWN ON OIL PRESSURE (ERRORS)'; table bit 126 = 0x70 + 4 x 3 + 2 (channel 3): read by the shutdown loop processDiagnosticLimitStatus and by the restart check cm550_protectionState1DiagnosticValidator (cm550_diagnosticProtectionEvaluator skips channel 3); set in the dumps */
    uint16_t oil_pressure_restart_enable : 1;  /* bit 15: EPO2RYEN 'BIT 15 OF 0-15. PREVENTS RESTART AT POWERUP WHEN (SHUTDN CNT > MAX SHUTDN CNT)'; table bit 127 = 0x70 + 4 x 3 + 3 (channel 3): read by the restart checks cm550_diagnosticProtectionEvaluator / cm550_protectionState1DiagnosticValidator; cm550_diagnosticProtectionEvaluator skips channel 3 so only cm550_protectionState1DiagnosticValidator reads this one; set in the dumps */
};

struct cm550_algorithm_enable_flags_8_t {
    uint16_t water_in_fuel_fueling_limiting_enable : 1;  /* bit 0: EPWFFLEN S mask 0x1 'ENABLE PARAMETER FOR FAULT LIMITING DUE TO WATER IN( FUEL)'; table bit 128 = 0x70 + 4 x 4 + 0 (channel 4): read by the fuel limit loop cm550_FUN_00019702; clear in the dumps */
    uint16_t water_in_fuel_rpm_limiting_enable : 1;  /* bit 1: EPWFRPEN S mask 0x2 'ENABLE PARAMETER FOR FAULT RPM LIMITING DUE TO WATE(R IN FUEL)'; table bit 129 = 0x70 + 4 x 4 + 1 (channel 4): read by cm550_calculateFaultDerateEngineSpeedLimit; clear in the dumps */
    uint16_t water_in_fuel_shutdown_enable : 1;  /* bit 2: EPWFSOEN S mask 0x4 'ENABLE SHUTDOWN ON WATER IN FUEL ERRORS'; table bit 130 = 0x70 + 4 x 4 + 2 (channel 4): read by the shutdown loop processDiagnosticLimitStatus and by the restart checks; clear in the dumps */
    uint16_t water_in_fuel_restart_enable : 1;  /* bit 3: EPWFRYEN S mask 0x8 'PREVENTS RESTRT AT PWR UP WHEN SHUTDN CNT>MAX SHUTD(N CNT)'; table bit 131 = 0x70 + 4 x 4 + 3 (channel 4): read by the restart checks cm550_diagnosticProtectionEvaluator / cm550_protectionState1DiagnosticValidator; clear in the dumps */
    uint16_t boost_pressure_fueling_limiting_enable : 1;  /* bit 4: EPBSFLEN S mask 0x10 'ENABLE PARAMETER FOR FAULT LIMITING DUE TO ENG SYNC' (the text is the engine sync record's; the mnemonic and its three siblings say boost pressure); table bit 132 = 0x70 + 4 x 5 + 0 (channel 5): read by the fuel limit loop cm550_FUN_00019702; clear in the dumps */
    uint16_t boost_pressure_rpm_limiting_enable : 1;  /* bit 5: EPBSRPEN S mask 0x20 'ENABLE PARAMETER FOR FAULT RPM LIMITING DUE TO BOOS(T PRESSURE)'; table bit 133 = 0x70 + 4 x 5 + 1 (channel 5): read by cm550_calculateFaultDerateEngineSpeedLimit; clear in the dumps */
    uint16_t boost_pressure_shutdown_enable : 1;  /* bit 6: EPBSSOEN S mask 0x40 'ENABLE SHUTDOWN ON BOOST PRESSURE ERRORS'; table bit 134 = 0x70 + 4 x 5 + 2 (channel 5): read by the shutdown loop processDiagnosticLimitStatus and by the restart checks; clear in the dumps */
    uint16_t boost_pressure_restart_enable : 1;  /* bit 7: EPBSRYEN S mask 0x80 'PREVENTS RESTRT AT PWR UP WHEN SHUTDN CNT>MAX SHUTD(N CNT)'; table bit 135 = 0x70 + 4 x 5 + 3 (channel 5): read by the restart checks cm550_diagnosticProtectionEvaluator / cm550_protectionState1DiagnosticValidator; clear in the dumps */
    uint16_t engine_sync_fuel_pressure_fueling_limiting_enable : 1;  /* bit 8: EPFPFLEN S mask 0x100 'ENABLE PARAMETER FOR FAULT LIMITING DUE TO ENG SYNC( FUEL PRESSURE)'; table bit 136 = 0x70 + 4 x 6 + 0 (channel 6): read by the fuel limit loop cm550_FUN_00019702; clear in the dumps */
    uint16_t engine_sync_fuel_pressure_rpm_limiting_enable : 1;  /* bit 9: EPFPRPEN S mask 0x200 'ENABLE PARAMETER FOR FAULT RPM LIMITING DUE TO ENG (SYNC FUEL PRESSURE)'; table bit 137 = 0x70 + 4 x 6 + 1 (channel 6): read by cm550_calculateFaultDerateEngineSpeedLimit; clear in the dumps */
    uint16_t engine_sync_fuel_pressure_shutdown_enable : 1;  /* bit 10: EPFPSOEN S mask 0x400 'ENABLE SHUTDOWN ON ENGINE SYNC FUEL PRESSURE ERRORS'; table bit 138 = 0x70 + 4 x 6 + 2 (channel 6): read by the shutdown loop processDiagnosticLimitStatus and by the restart checks; clear in the dumps */
    uint16_t engine_sync_fuel_pressure_restart_enable : 1;  /* bit 11: EPFPRYEN S mask 0x800 'PREVENTS RESTRT AT PWR UP WHEN SHUTDN CNT>MAX SHUTD(N CNT)'; table bit 139 = 0x70 + 4 x 6 + 3 (channel 6): read by the restart checks cm550_diagnosticProtectionEvaluator / cm550_protectionState1DiagnosticValidator; clear in the dumps */
    uint16_t fuel_temperature_fueling_limiting_enable : 1;  /* bit 12: EPFTFLEN 'BIT 12 OF 0-15 ENABLES FUEL LIMITING DUE TO FUEL (TEMPERATURE ERRORS)'; table bit 140 = 0x70 + 4 x 7 + 0 (channel 7): read by the fuel limit loop cm550_FUN_00019702; also tested directly: andi.l #0x1000 at 0x1caec (vp44_FUN_0001cad6) - with engine protection enabled (word 2 bit 4) and this bit or bit 13 set it updates the channel input vp44_fuel_temperature_value; clear in the dumps */
    uint16_t fuel_temperature_rpm_limiting_enable : 1;  /* bit 13: EPFTRPEN 'BIT 13 OF 0-15 ENABLES RPM LIMITING DUE TO FUEL T(EMPERATURE ERRORS)'; table bit 141 = 0x70 + 4 x 7 + 1 (channel 7): read by cm550_calculateFaultDerateEngineSpeedLimit; also tested directly: andi.l #0x2000 at 0x1cafa (vp44_FUN_0001cad6) - the second operand of the fuel temperature input update (see bit 12); clear in the dumps */
    uint16_t fuel_temperature_shutdown_enable : 1;  /* bit 14: EPFTSOEN 'BIT 14 OF 0-14 ENABLES SHUTDOWN ON FUEL TEMPERATU(RE ERRORS)'; table bit 142 = 0x70 + 4 x 7 + 2 (channel 7): read by the shutdown loop processDiagnosticLimitStatus and by the restart checks; clear in the dumps */
    uint16_t fuel_temperature_restart_enable : 1;  /* bit 15: EPFTRYEN 'BIT 15 OF 0-15 PREVENTS RESTART AT POWERUP WHEN S(HUTDN CNT > MAX SHUTDN CNT)'; table bit 143 = 0x70 + 4 x 7 + 3 (channel 7): read by the restart checks cm550_diagnosticProtectionEvaluator / cm550_protectionState1DiagnosticValidator; clear in the dumps */
};

struct algorithm_enable_flags_11_t {
    uint16_t proprietary_communication_enable : 1;  /* bit 0: JCJPEA 'PARAMETER INDICATING WHETHER DATALINK PROTOCOLS ARE TURNED ON' (an N record with no bit; CM848's label Proprietary_Communication_Enable has S mask 0x1); andi.w #0x1 at 0x15fe8: mc68k_dispatchJ1708ReceivedMessages handles the proprietary J1708 messages (message identifier below 8: the security key / development mode / shutdown / restart commands) only while set; set in the dumps (0x000b) */
    uint16_t j1587_communication_enable : 1;  /* bit 1: JC87CZEA 'BIT 1 OF 0-15 INDICATES WHETHER J1587 COMMUNICATION IS ENABLED'; andi.w #0x2 at 0xebe0 (cm550_diagnosticMessageTransmissionManager: the periodic J1587 broadcast vp44_insiteParameterTableIterator) and 0x16396 (mc68k_dispatchJ1708ReceivedMessages: message identifiers 0x80 and up); set */
    uint16_t j1922_communication_enable : 1;  /* bit 2: JC22CZEA 'BIT 2 OF 0-15 INDICATES WHETHER J1922 COMMUNICATION IS ENABLED'; andi.w #0x4 at 0xebac (cm550_diagnosticMessageTransmissionManager: the periodic cm550_diagnosticMessage45Builder / cm550_diagnosticMessage53Builder) and 0x163be (mc68k_dispatchJ1708ReceivedMessages: message identifiers 0x45-0x56 = 69-86 the J1922 range); clear */
    uint16_t j1939_communication_enable : 1;  /* bit 3: JC39CZEA 'BIT 3 OF 0-15 INDICATES WHETHER J1939 COMMUNICATI(ON IS ENABLED)'; andi.w #0x8 at 0x1ff4e (cm550_runJ1939PeriodicTransmitQueues = the J1939 periodic transmit schedule) and 0x212c0 (mc68k_dispatchJ1939ReceivedMessages = the J1939 receive dispatch) - the twins of CM848's two readers; set */
    uint16_t reserved_bit_4 : 1;  /* bit 4: no record in v64t6_s and no reader in the dumped ROM; guess JCRWDXEN 'J1587 TRANSPORT PROTOCOL ENABLE' (S mask 0x10 in 13 other ISB e2m files); CM848 reserved_bit_4 too; clear in the dumps */
    uint16_t reserved_bit_5 : 1;  /* bit 5: no e2m record and no reader in the dumped ROM; CM848 reserved too; clear in the dumps */
    uint16_t reserved_bit_6 : 1;  /* bit 6: no e2m record and no reader in the dumped ROM; CM848 reserved too; clear in the dumps */
    uint16_t reserved_bit_7 : 1;  /* bit 7: no e2m record and no reader in the dumped ROM; CM848 reserved too; clear in the dumps */
    uint16_t reserved_bit_8 : 1;  /* bit 8: no e2m record and no reader in the dumped ROM; CM848 reserved too; clear in the dumps */
    uint16_t reserved_bit_9 : 1;  /* bit 9: no e2m record and no reader in the dumped ROM; CM848 reserved too; clear in the dumps */
    uint16_t reserved_bit_10 : 1;  /* bit 10: no e2m record and no reader in the dumped ROM; CM848 reserved too; clear in the dumps */
    uint16_t reserved_bit_11 : 1;  /* bit 11: no e2m record and no reader in the dumped ROM; CM848 reserved too; clear in the dumps */
    uint16_t reserved_bit_12 : 1;  /* bit 12: no e2m record and no reader in the dumped ROM; CM848 reserved too; clear in the dumps */
    uint16_t reserved_bit_13 : 1;  /* bit 13: no e2m record and no reader in the dumped ROM; CM848 reserved too; clear in the dumps */
    uint16_t reserved_bit_14 : 1;  /* bit 14: no e2m record and no reader in the dumped ROM; CM848 reserved too; clear in the dumps */
    uint16_t reserved_bit_15 : 1;  /* bit 15: no e2m record and no reader in the dumped ROM; CM848 reserved too; clear in the dumps */
};

struct cm550_algorithm_enable_flags_12_t {
    uint16_t idle_speed_save_enable : 1;  /* bit 0: LSISSVEN 'BIT 0 OF 0 - 15 ENABLES SAVE OF LAST IDLE SPEED AT SHUT(DOWN)'; andi.w #0x1 at 0x26546 (cm550_engineModeTimingAdjuster: set keeps the operator idle adjustment in rpm_added_to_lsg_reference_300_300 0x805f0a - clear zeroes it) and 0x265a0 (cm550_initializeLowSpeedGovernorIdleAdjustment: the start-up restore of that adjustment); CM848 field name; set in the dumps (0xbb87) */
    uint16_t overspeed_fuel_shutoff_enable : 1;  /* bit 1: EPOSFSO 'IF T FSO CLOSES WHEN OVRSPD DETECTED BY MAIN MICRO. BI(T 1 OF 0 - 15 OF WORD C)' (FSO = fuel shut off: e2m DRFSEA 'CONTROLS FUEL SHUT OFF DRIVER'); andi.l #0x2 at 0x1ca9a (cm550_commandFuelShutoffDriver): in ENGINE_STATE_OVERSPEED the fuel shutoff driver bit 0x20 of fuel_system_output_driver_control is cleared only while set; CM848 reserved_bit_1 with the same record (rename proposed); set */
    uint16_t water_in_fuel_enable : 1;  /* bit 2: WFAGEN 'BIT 2 ENABLE FLAG USED FOR WATER_IN_FUEL ALGORITHM.'; andi.w #0x4 at 0x34c3e (vp44FaultRegisterBit2Monitor): set = a wet water_in_fuel_sensor_state sets fault status word 4 bit 0x2000 and lamp driver bit 0x10 - clear = that fault bit is cleared; CM848 field name; set */
    uint16_t air_fuel_control_override_enable : 1;  /* bit 3: AFENMAN 'BIT 3 OF 0-15 IN WORD C'; andi.w #0x8 at 0xc19c (cm550_fuelTimingTransitionStateMachine): set takes the derate fuel adjustment from afc_fueling_derate_value_when_afc_override_is_enabled_0_100 instead of the engine speed x boost pressure table; CM848 field name; clear */
    uint16_t electronic_smart_power_enable : 1;  /* bit 4: SPAGEN '0 - DISBALE 1 - ENABLE ESP ALGORITHM BIT 4 OF 0 - 15.' (e2m group ESP_08 'ELECTRONIC SMART POWER GROUP'); andi #0x10 at 0x1abcc (gates cm550_updateElectronicSmartPowerTau) / 0xc3ea (calculateAlpha copies the alpha into the timing alpha only while clear) / 0x1cd96 (cm550_FUN_0001cc72: the maximum fueling without programmable power comes from the low horsepower curve while set); CM848 field name; clear */
    uint16_t reverse_electronic_smart_power_enable : 1;  /* bit 5: SPRVEN '0 - DISBALE 1 - ENABLE ESP LAUNCH APPLICATION ALGORITH(M BIT 5 OF 0 - 15.)' (CM848 label Reverse_ESP_Enable S mask 0x20); andi.l #0x20 at 0x1ad52: cm550_updateElectronicSmartPowerTau enters ESP tau source state 1 (e2m 11DC +6 SPTUST lists NORMAL / LAUNCH / STEEP) only while set; CM848 field name; clear */
    uint16_t low_speed_governor_droop_enable : 1;  /* bit 6: LSDPEN 'LSG DROOP ENABLE BIT 6 OF 0 - 15 IN WORD C'; andi.l #0x40 at 0xfa1c (vp44State2TransitionHandler) and 0x1850e (cm550_FUN_000184c6): set lowers the torque curve speed point 1 by fueling x the selected droop slope 0x80daf4 (e2m LSDPSE) / 167 - the same droop as CM848's reader; CM848 field name; clear */
    uint16_t accelerator_interlock_enable : 1;  /* bit 7: ANEN 'BIT 7 OF 0-15 IN WORD C ACCELERATOR INTERLOCK ENABLE B(IT)'; no reader in the dumped ROM; CM848 field name; set */
    uint16_t vehicle_speed_sensor_signal_loss_enable : 1;  /* bit 8: VSMVEN 'BIT 8 WORD C. ENABLES VSS SENSOR LOST WHILE MOVING( DETECTION)'; no reader in the dumped ROM; CM848 field name (named there after the detector it gates); set */
    uint16_t vehicle_speed_sensor_lost_while_stopped_detection_enable : 1;  /* bit 9: VSSTEN 'BIT 9 WORD C. ENABLES VSS SENSOR LOST WHILE STOPPE(D DETECTION)'; no reader in the dumped ROM; the same record as CM848 vehicle_speed_sensor_zero_under_load_enable (CM848 named that field after its own detector - nothing proves that detector for J90350.00); set */
    uint16_t reserved_bit_10 : 1;  /* bit 10: no record in v64t6_s and no reader in the dumped ROM; guess DGOBFUHN 'INDICATES WHETHER OBDII FAULT HANDLER IS ENABLED' (S mask 0x400 here in 28 other e2m files - the 23 CHR files and 5 ISB files - and an N record with no bit in 4 more ISB files; CM848 obd_fault_handler_enable); clear in the dumps */
    uint16_t power_take_off_brake_override_enable : 1;  /* bit 11: PTBRODEN 'WHEN ENABLED IT ALLOWS THE BRAKE TO CANCEL CAB PTO. WORD C BIT (B)' (v64t6_s cuts the bit letter: 22 other e2m files give it and every S record has mask 0x800); no reader in the dumped ROM; CM848 field name; set */
    uint16_t power_take_off_clutch_override_enable : 1;  /* bit 12: PTCHODEN 'WHEN ENABLED IT ALLOWS THE CLUTCH TO CANCEL CAB PTO. WORD C BIT( C)' (v64t6_s cuts the bit letter: 22 other e2m files give it and every S record has mask 0x1000); no reader in the dumped ROM; CM848 field name; set */
    uint16_t oil_change_monitor_enable : 1;  /* bit 13: OCEA 'ENABLES OIL CHANGE MONITOR FEATURE BIT 13 OF 0-15 OF W(ORD C)'; no reader in the dumped ROM; CM848 field name; set */
    uint16_t low_speed_governor_cold_idle_override_enable : 1;  /* bit 14: LSCIIHEN 'ENABLE FOR OVERRIDING THE COLD IDLE ADJUST IN THE LSG' (9 other e2m files go on '- BIT 14'); andi.w #0x4000 at 0x26646 (cm550_FUN_00026616): the cold idle speed adder raises the idle reference unless this bit is set and the cold idle override flag 0x80db08 (e2m 1049 +6 LSCIOD 'TRUE INHIBITS COLD IDLE ADJUSTMEN(T)') is non-zero; CM848 reserved_bit_14 (no record there); clear */
    uint16_t engine_data_files_enable : 1;  /* bit 15: EDEN 'BIT 15 OF 0 - 15; ENABLES/DISABLES EDF FEATURE.' in e2m group 12C ENDTFL07 'ENGINE DATA FILES ENABLE AND POWER-DOWNS' (EDF = engine data files); no reader in the dumped ROM; CM848 reserved_bit_15 (no record there); set */
};

struct cm550_algorithm_enable_flags_13_t {
    uint16_t key_switch_override_enable : 1;  /* bit 0: no 106B record; logical switch 0: status e2m 000E +0 DSKYSWSS 'BIT 0 OF BYTE 0 STATUS OF THE VEHICLE KEY SWITCH - DEBOUNCED' (cm550_updateEngineState and mc68k_runPowerDownSequence read that bit as the key); named from the code and the status record; code: mask byte [1] bit 0 over status 0x80bcce / set = the key switch state comes from user value 0x80bcd8 bit 0; clear in the dumps */
    uint16_t cruise_control_resume_switch_override_enable : 1;  /* bit 1: DSCRRUUO S mask 0x2 'BIT 1 USER OVERRIDE ENABLE FLAG FOR THE CRUISE CONTROL( RESUME SWITCH)' / DS01SWUO 'SWITCH 1'; logical switch 1: status DSRUSWSS 'STATUS OF CRUISE RESUME/ACCEL SWITCH INPUT' / priority 12A8 +1 DSPZCRRU; code: mask byte [1] bit 1 over status 0x80bcce / table bit 209 tested by cm550_processJ1939SwitchInput for J1939 entry 6 (j1939_received_cruise_control_resume_switch); clear in the dumps */
    uint16_t cruise_control_set_switch_override_enable : 1;  /* bit 2: DSCRSEUO S mask 0x4 'BIT 2 USER OVERRIDE ENABLE FLAG FOR THE CRUISE CONTROL( SWITCH SET ACTIVATION)' / DS02SWUO 'SWITCH 2'; logical switch 2: status DSSESWSS 'STATUS OF CRUISE SET/COAST SWITCH INPUT' / priority 12A8 +2 DSPZCRSE; code: mask byte [1] bit 2 over status 0x80bcce / table bit 210 tested by cm550_processJ1939SwitchInput for J1939 entry 7 (j1939_received_cruise_control_set_switch); clear in the dumps */
    uint16_t cruise_control_on_off_switch_override_enable : 1;  /* bit 3: DSCRONUO S mask 0x8 'BIT 3 USER OVERRIDE ENABLE FLAG FOR THE CC/PTO ON/OFF S(WITCH)' / DS03SWUO 'SWITCH 3'; logical switch 3: the cruise control and power take-off on/off switch - status DSCRSWSS 'STATUS OF CRUISE ON SWITCH INPUT' / priority 12A8 +3 DSPZCRON; code: mask byte [1] bit 3 over status 0x80bcce / table bit 211 tested by cm550_processJ1939SwitchInput for J1939 entry 5 (j1939_received_cruise_control_enable_switch); clear in the dumps */
    uint16_t manual_fan_switch_override_enable : 1;  /* bit 4: DSMNFNUO S mask 0x10 'BIT 4 USER OVERRIDE ENABLE FLAG FOR THE MANUAL FAN INPU(T SWITCH)' / DSFACLUO 'USER OVERRIDE ENABLE FLAG FOR FAN CLUTCH SWITCH' / DS05SWUO 'SWITCH 5'; logical switch 4: status DSFMSW 'STATUS OF THE MANUAL FAN INPUT SWITCH - DEBOUNCED VALUE' / priority 12A8 +4 DSPZFMIP; code: mask byte [1] bit 4 over status 0x80bcce; clear in the dumps */
    uint16_t powertrain_protection_switch_override_enable : 1;  /* bit 5: DSPPSWUO S mask 0x20 'USER OVERRIDE ENABLE FLAG FOR PTP SWITCHED INPUT SWITCH' (PTP = powertrain protection: e2m group PTP_07) / DS06SWUO 'SWITCH 6'; logical switch 5: status PTSWINSW 'DEBOUNCED VALUE OF THE PTP SWITCHED INPUT SWIT(CH)' / priority 12A8 +5 DSP2PTSW (12A8 and 12FC also keep the older alias PTO_VALIDATE); code: mask byte [1] bit 5 over status 0x80bcce; clear in the dumps */
    uint16_t high_speed_governor_droop_select_switch_override_enable : 1;  /* bit 6: DSHSDPUO S mask 0x40 'USER OVERRIDE ENABLE FLAG FOR HSG DROOP SELECT SWITCH' / DS07SWUO 'SWITCH 7'; logical switch 6: status HSDRSLSW 'DEBOUNCED VALUE FOR THE HSG DROOOP SELECT SWIT(CH)' / priority 12A8 +6 DSPZHGSW; code: mask byte [1] bit 6 over status 0x80bcce; clear in the dumps */
    uint16_t idle_switch_override_enable : 1;  /* bit 7: DSIVSWUO S mask 0x80 'BIT 7 USER OVERRIDE ENABLE FLAG FOR THE RAW IDLE SWITCH( INPUT)' / DS08SWUO 'SWITCH 8'; logical switch 7: status DSIVSWSS 'DEBOUNCED VALUE OF IDLE VALIDATION 1 SWITCH' / priority 12A8 +7 DSPZISSW IDLE_SWITCH; code: mask byte [1] bit 7 over status 0x80bcce / direct tests andi #0x80 at 0x204e6 (cm550_processJ1939AcceleratorLowIdleSwitch: the J1939 low idle switch writes the override value) - 0x20cbe (cm550_processJ1939AcceleratorPedalPosition: the J1939 accelerator pedal position becomes the throttle override) - 0x20e5a (cm550_processJ1939AcceleratorIdleSwitchPair: the idle switch pair values) - 0x32ed4 (j1939HandlePgn61443Eec2 sends the EEC2 low idle switch as 3 while set); clear in the dumps */
    uint16_t not_idle_switch_override_enable : 1;  /* bit 8: DSNTIVUO S mask 0x100 'BIT 8 USER OVERRIDE ENABLE FLAG FOR THE RAW NOT IDLE SW(ITCH INPUT)' / DS09SWUO 'SWITCH 9'; logical switch 8: status DSIVNTSW 'DEBOUNCED VALUE OF IDLE VALIDATION 2 SWITCH' / priority 12A8 +8 DSPZNTIS NOT_IDLE_SWITCH; code: mask byte [0] bit 0 over status 0x80bccf; clear in the dumps */
    uint16_t accelerator_interlock_switch_override_enable : 1;  /* bit 9: DSOVAISW S mask 0x200 'WORD 13 BIT 9 OF BITS 0-15 STATUS OF OVERRIDE FLAG TO' (cut) / DS10SWUO 'SWITCH 10'; logical switch 9: priority 12A8 +9 DSPZAISW 'PRIORITY OF CLIENT CURRENTLY OVERRIDING ACCELERATOR INTERLOCK SWI(TCH)' / default 12FC DSGDAISW / status DSACILSS; code: mask byte [0] bit 1 over status 0x80bccf / table bit 217 tested by cm550_processJ1939SwitchInput for J1939 entry 1 (j1939_received_accelerator_interlock_switch); clear in the dumps */
    uint16_t clutch_switch_override_enable : 1;  /* bit 10: DSCHSWUO S mask 0x400 'BIT A USER OVERRIDE ENABLE FLAG FOR THE CLUTCH SWITCH' / DS11SWUO 'SWITCH 11'; logical switch 10: status DSCHSWSS 'DEBOUNCED VALUE OF CLUTCH SWITCH INPUT' / priority 12A8 +A DSPZCHSW; code: mask byte [0] bit 2 over status 0x80bccf / table bit 218 tested by cm550_processJ1939SwitchInput for J1939 entry 4 (j1939_received_clutch_switch); clear in the dumps */
    uint16_t brake_switch_override_enable : 1;  /* bit 11: DSBRSWUO S mask 0x800 'BIT B USER OVERRIDE ENABLE FLAG FOR THE BRAKE SWITCH' / DS12SWUO 'SWITCH 12'; logical switch 11: status DSBRSWSS 'DEBOUNCED VALUE OF SERVICE BRAKE SWITCH INPU(T)' / priority 12A8 +B DSPZBRSW; code: mask byte [0] bit 3 over status 0x80bccf / table bit 219 tested by cm550_processJ1939SwitchInput for J1939 entry 3 (j1939_received_brake_switch); clear in the dumps */
    uint16_t engine_brake_select_1_switch_override_enable : 1;  /* bit 12: DSEBUO01 S mask 0x1000 'BIT C USER OVERRIDE ENABLE ENGINE BRAKE SELECT 1' / DSOVEBSW 'USER OVERRIDE ENABLE FOR ENGINE_BRAKE_SWITCH' / DS13SWUO 'SWITCH 13'; logical switch 12: status DSEBS1 'DEBOUNCED VALUE OF ENGINE BRAKE SELECT 1 SWITCH INPUT' / priority 12A8 +C DSPZEBS1 (CM848 names its switch 12 from the same Engine_Brake_Select_1); code: mask byte [0] bit 4 over status 0x80bccf; clear in the dumps */
    uint16_t idle_increment_switch_override_enable : 1;  /* bit 13: DSICSWUO S mask 0x2000 'BIT D USER OVERRIDE ENABLE FLAG FOR THE IDLE ADJUST INC(REMENT SWITCH)' / DS14SWUO 'SWITCH 14'; logical switch 13: status DSICSWSS 'DEBOUNCED VALUE OF IDLE INCREMENT SWITCH INP(UT)' / priority 12A8 +D DSPZICSW; code: mask byte [0] bit 5 over status 0x80bccf / table bit 221 tested by cm550_processJ1939SwitchInput for J1939 entry 9 (j1939_received_engine_idle_increment_switch) / direct test andi.w #0x2000 at 0x15830 (mc68k_sampleAndDebounceDiscreteInputs: after the increment / decrement decode from the cruise switches it takes status 0x80bccf bit 5 from switch_9_to_16_override_values again); clear in the dumps */
    uint16_t idle_decrement_switch_override_enable : 1;  /* bit 14: DSDTSWUO S mask 0x4000 'BIT E USER OVERRIDE ENABLE FLAG FOR THE IDLE ADJUST DEC(REMENT SWITCH)' / DS15SWUO 'SWITCH 15'; logical switch 14: status DSDTSWSS 'DEBOUNCED VALUE OF IDLE DECREMENT SWITCH INP(UT)' / priority 12A8 +E DSPZDTSW; code: mask byte [0] bit 6 over status 0x80bccf / table bit 222 tested by cm550_processJ1939SwitchInput for J1939 entry 8 (j1939_received_engine_idle_decrement_switch) / direct test andi.w #0x4000 at 0x15850 (mc68k_sampleAndDebounceDiscreteInputs: status 0x80bccf bit 6 from switch_9_to_16_override_values after the cruise switch decode); clear in the dumps */
    uint16_t diagnostic_test_switch_override_enable : 1;  /* bit 15: DSTESWUO S mask 0x8000 'BIT F USER OVERRIDE ENABLE FLAG FOR THE DIAGNOSTIC TEST( AND FAULT FLASH OUT)' / DS16SWUO 'SWITCH 16'; logical switch 15: status DSTESWSS 'DEBOUNCED VALUE OF THE DIAGNOSTIC/TEST SWITC(H)' / priority 12A8 +F DSPZTESW; code: mask byte [0] bit 7 over status 0x80bccf / table bit 223 tested by cm550_processJ1939SwitchInput for J1939 entry 15 (j1939_received_engine_diagnostic_test_mode_switch); clear in the dumps */
};

struct cm550_algorithm_enable_flags_14_t {
    uint16_t switch_17_override_enable : 1;  /* bit 0: DS17SWUO S mask 0x1 'BIT 0 SWITCH 17 USER OVERRIDE ENABLE FLAG' is the only record; logical switch 16: no function name in 106B / 000E / 12A8 / 12FC / 1234 and no reader of the status bit; code: mask byte [3] bit 0 over status 0x80bcd0; clear in the dumps */
    uint16_t air_conditioning_pressure_turnkey_switch_override_enable : 1;  /* bit 1: DSAKTKUO S mask 0x2 'WORD 14 BIT 1 OF BITS 0-15 STATUS OF OVERRIDE FLAG TO' (cut) / DS18SWUO 'SWITCH 18'; logical switch 17: default 12FC DSDFACTK 'DEFAULT/INITIALIZATION VALUE FOR THE AC PRESSURE TURNKEY SWITCH' / priority 12A8 +11 DSPZACPT / inversion 1234 DSINACPT; code: mask byte [3] bit 1 over status 0x80bcd0 / the debouncer copies status 0x80bcd0 bit 1 into 0x80bcd7 bit 0 (e2m 000E +9 DSAKPRSW 'SOFTWARE VALUE OF AIR CONDITIONER PRESSURE S(WITCH)'); clear in the dumps */
    uint16_t rear_axle_ratio_switch_override_enable : 1;  /* bit 2: DSRARSUO S mask 0x4 'USER OVERRIDE ENABLE FLAG FOR REAR AXLE RATIO SWITCH' / DS19SWUO 'SWITCH 19'; logical switch 18: status DSRARASW 'DEBOUNCED VALUE FOR REAR_AXLE_RATIO_SWITCH' (j1939HandlePgn65265CruiseVehicleSpeed reads it) / priority 12A8 +12 DSPZRARA; code: mask byte [3] bit 2 over status 0x80bcd0; clear in the dumps */
    uint16_t remote_throttle_switch_override_enable : 1;  /* bit 3: DSRMTHUO S mask 0x8 'BIT 3 USER OVERRIDE ENABLE FLAG FOR THE REMOTE THROTTLE( SWITCH)' / DS20SWUO 'SWITCH 20'; logical switch 19: status RMTHSW 'DEBOUNCED VALUE OF REMOTE THROTTLE SWITCH INPU(T)' / priority 12A8 +13 DSPZRTSW; code: mask byte [3] bit 3 over status 0x80bcd0 / table bit 227 tested by cm550_processJ1939SwitchInput for J1939 entry 14 (j1939_received_remote_accelerator_enable_switch) / direct test andi.l #0x8 at 0x207d0 (cm550_processJ1939RemoteAcceleratorPedalPosition: with word 18 bit 12 it lets the J1939 remote accelerator pedal position into analog_sensor_override_values[11]); clear in the dumps */
    uint16_t remote_power_take_off_switch_override_enable : 1;  /* bit 4: DSRXSWUO S mask 0x10 'BIT 4 USER OVERRIDE ENABLE FLAG FOR THE REMOTE PTO SWIT(CH)' / DS21SWUO 'SWITCH 21'; logical switch 20: status DSRXSWSS 'DEBOUNCED VALUE OF REMOTE PTO SWITCH INPUT' / priority 12A8 +14 DSPZRXSW; code: mask byte [3] bit 4 over status 0x80bcd0 / table bit 228 tested by cm550_processJ1939SwitchInput for J1939 entry 13 (j1939_received_remote_power_take_off_switch); clear in the dumps */
    uint16_t coolant_level_low_switch_override_enable : 1;  /* bit 5: DSCLLOUO S mask 0x20 'USER OVERRIDE ENABLE FLAG FOR COOLANT LEVEL LOW SWITCH' / DS22SWUO 'SWITCH 22'; logical switch 21: status DSCLLOSW 'STATUS OF THE SWITCH (COOLANT LEVEL LOW)' (the debouncer's coolant level switch pair check reads it) / priority 12A8 +15 DSPZCLLO; code: mask byte [3] bit 5 over status 0x80bcd0; clear in the dumps */
    uint16_t user_datalogger_switch_override_enable : 1;  /* bit 6: DSUSDLUO and DSORUDSW S mask 0x40 'USER OVERRIDE ENABLE FLAG FOR USER DATALOGGER SWITCH' / DS26SWUO 'BIT 6 SWITCH 26'; logical switch 22: status DSILSSSW 'STATUS OF THE DEBOUNCED SWITCH USER_DATALOGGER_SWITCH' (cm550_updateDataloggerTriggers reads it) / priority 12A8 +16 DSPZININ (12A8 and 12FC also keep the alias PTO1); code: mask byte [3] bit 6 over status 0x80bcd0; clear in the dumps */
    uint16_t parking_brake_switch_override_enable : 1;  /* bit 7: DSPRBRUO S mask 0x80 (its text 'USER OVERRIDE ENABLE FLAG MANUAL FAN INPUT SWITCH' is the manual fan record's - the mnemonic says parking brake) / DS24SWUO 'BIT 7 SWITCH 24'; logical switch 23: value 000E +C DSPRBRUC 'USER VALUE OF THE PARKING BRAKE SWITCH' / priority 12A8 +17 DSPZPRBR 'PARKING_BRAKE_SW(ITCH)' / inversion 1234 DSPRBRIV - no reader of the status bit; code: mask byte [3] bit 7 over status 0x80bcd0; clear in the dumps */
    uint16_t coolant_level_high_switch_override_enable : 1;  /* bit 8: DSCLHIUO S mask 0x100 'USER OVERRIDE ENABLE FLAG FOR COOLANT LEVEL HIGH SWITCH' / DS25SWUO 'BIT 8 SWITCH 25'; logical switch 24: status DSCLHISW 'STATUS OF THE SWITCH (COOLANT LEVEL HIGH)' (the coolant level switch pair check reads it) / priority 12A8 +18 DSPZCLHI; code: mask byte [2] bit 0 over status 0x80bcd1; clear in the dumps */
    uint16_t switched_throttle_control_or_all_speed_governor_droop_switch_override_enable : 1;  /* bit 9: DSSTCNUO S mask 0x200 'USER OVERRIDE ENABLE FLAG FOR STCG ASG DROOP SWITCH' (STCG = switched throttle control governor per STCGASDS - ASG = all speed governor) / DS04SWUO 'BIT 9 SWITCH 4'; logical switch 25: status SLTHCNSW 'DEBOUNCED VALUE OF THE STCG ASG DROOP SWITCH' (cm550_acceleratorThrottleFaultDetector and cm550_FUN_0000d4ae read it with word 27 bit 3) / priority 12A8 +19 DSPZSTCN; code: mask byte [2] bit 1 over status 0x80bcd1; clear in the dumps */
    uint16_t switch_27_override_enable : 1;  /* bit 10: DS27SWUO S mask 0x400 'BIT A SWITCH 27 USER OVERRIDE ENABLE FLAG' is the only 106B record; logical switch 26: guess an air conditioning pressure switch (12A8 +1A DSPZAKPR 'AIR CONDITIONER' / 12FC DSDFAKPR 'AIR_CONDITIONER_PRESSURE_SWITC(H)' / 1234 DSINACHP 'AC HIGH PRESSURE SWIT(CH)') - but this ROM keeps the air conditioning pressure switch at logical switch 72 (J1939 entry 0) and nothing reads the status bit; code: mask byte [2] bit 2 over status 0x80bcd1; clear in the dumps */
    uint16_t switch_28_override_enable : 1;  /* bit 11: DS28SWUO S mask 0x800 'BIT B SWITCH 28 USER OVERRIDE ENABLE FLAG' plus two function records that disagree: DSAKHIUO 'WORD 14 BIT 11 OF BITS 0-15 STATUS OF OVERRIDE FLAG T' (cut - the AC high pressure switch: 12A8 +1B DSPZACHP / 12FC DSDFACHP) and DSTHILUO 'USER OVERRIDE ENABLE FLAG FOR THE ACCELERATOR INTERLOCK' (the throttle interlock: DSTHILSS / DSPZTHIL / DSDFTHIL); logical switch 27: undecided - this ROM routes the J1939 accelerator interlock to logical switch 9 (word 13 bit 9) so the interlock alias looks stale and nothing reads the status bit; code: mask byte [2] bit 3 over status 0x80bcd1; clear in the dumps */
    uint16_t switch_23_override_enable : 1;  /* bit 12: DS23SWUO S mask 0x1000 'BIT C SWITCH 23 USER OVERRIDE ENABLE FLAG' is the only 106B record; logical switch 28: guess engine brake select 2 (12FC DSDFEBS2 'DEFAULT/INITIALIZATION VALUE FOR ENGINE_BRAKE_SELECT_2' / 12A8 +1C DSPZEBS2) - no reader of the status bit; code: mask byte [2] bit 4 over status 0x80bcd1; clear in the dumps */
    uint16_t air_conditioning_cycle_switch_override_enable : 1;  /* bit 13: DSAKCYUO S mask 0x2000 'WORD 14 BIT 13 OF BITS 0-15 STATUS OF OVERRIDE FLAG T' (cut) / DS29SWUO 'SWITCH 29'; logical switch 29: default 12FC DSDFACCY 'DEFAULT/INITIALIZATION VALUE FOR THE AC CYCLE SWITCH' / inversion 1234 DSACCYIV / priority 12A8 +1D DSPZACCY (12A8 and 12FC also keep the alias PTO2) - no reader of the status bit; code: mask byte [2] bit 5 over status 0x80bcd1; clear in the dumps */
    uint16_t air_conditioning_on_off_switch_override_enable : 1;  /* bit 14: DSAKONUO S mask 0x4000 (its text 'BIT 6 OF 0-7 STATUS OF THE SWITCH' is the status record's) / DS30SWUO 'SWITCH 30'; logical switch 30: value 000E +D DSAKONUC 'USER SUPPLIED VALUE FOR AC_ON_OFF_SWITCH' / priority 12A8 +1E DSPZACOO 'AC ON OFF SWITCH' / default 12FC DSDFACOO - no reader of the status bit; code: mask byte [2] bit 6 over status 0x80bcd1; clear in the dumps */
    uint16_t switch_31_override_enable : 1;  /* bit 15: DS31SWUO S mask 0x8000 'BIT F SWITCH 31 USER OVERRIDE ENABLE FLAG' is the only record; logical switch 31: no function name in 106B / 000E / 12A8 / 12FC / 1234 and no reader of the status bit; code: mask byte [2] bit 7 over status 0x80bcd1; clear in the dumps */
};

struct cm550_algorithm_enable_flags_16_t {
    uint16_t cruise_control_resume_switch_override_enable : 1;  /* bit 0: Set: the decoded cruise resume bit 0x80bcd4 bit 0 (e2m 000E +6 CRRESUSW) is ORed in from the override value 0x80bcde bit 0 (set only, not cleared) instead of switch input 0x80bcce bit 1. mc68k_sampleAndDebounceDiscreteInputs andi.w #0x0001 at 0x15648. Logical input 48; no 106B record. Unlike word 13's DSCRRUUO (raw switch) this overrides the debounced status byte. Clear */
    uint16_t reserved_bit_1 : 1;  /* bit 1: No reader in the dumped ROM and no 106B record; by the logical input layout (49) the cruise accelerate bit 0x80bcd4 bit 1 (CRACELSW). Clear */
    uint16_t cruise_control_set_switch_override_enable : 1;  /* bit 2: Set: the decoded cruise set bit 0x80bcd4 bit 2 (CRSETSW) is ORed in from 0x80bcde bit 2 (set only, not cleared) instead of switch input 0x80bcce bit 2. andi.w #0x0004 at 0x1561a. Logical input 50; no 106B record. Clear */
    uint16_t reserved_bit_3 : 1;  /* bit 3: No reader and no 106B record; by the layout (51) the cruise coast bit 0x80bcd4 bit 3 (CRCOASSW). Clear */
    uint16_t cruise_control_on_switch_override_enable : 1;  /* bit 4: Set: the decoded cruise on bit 0x80bcd4 bit 4 (CRONSW) is ORed in from 0x80bcde bit 4 (set only, not cleared) instead of switch input 0x80bcce bit 3. andi.w #0x0010 at 0x155ec. Logical input 52; no 106B record. Clear */
    uint16_t reserved_bit_5 : 1;  /* bit 5: No reader and no 106B record; by the layout (53) the cruise set and resume bit 0x80bcd4 bit 5 (CRSERUSW). Clear */
    uint16_t auxiliary_shutdown_switch_override_enable : 1;  /* bit 6: e2m DSAUSHUO 0x40 'USER OVERRIDE ENABLE FLAG FOR THE AUXILIARY SHUTDOWN SW'. Code: table bit 262 (logical input 54) tested by cm550_processJ1939SwitchInput for J1939 descriptor entry 2 (j1939_received_engine_auxiliary_shutdown_switch) and by cm550_copyOutputBitToSwitchOverrideValue(0x36 ...) three times. Caveats: entry 16 (engine derate switch) also points at 54; the e2m value / status / priority records (DSAUSHUC E +11 0x40; DSAUSHSW E +7 0x40; 12A8 +3E DSPZAUSH) sit at logical input 62 = bit 14. Clear In the dumped ROM the override value bit 54 (0x80bcde bit 6) has no reader, and cm550_copyOutputBitToSwitchOverrideValue(0x36, 1 / 4 / 2) also stores output image bits 1 / 4 / 2 (the stop / engine protection / water in fuel lamp commands) into it after the J1939 entries. The status bit 54 (0x80bcd4 bit 6) is no auxiliary shutdown status: mc68k_sampleAndDebounceDiscreteInputs sets it on the power take-off on switch's rising edge at zero road speed while word 28 bit 4 (e2m ISTAEN) is set and clears it on set / resume, and j1939HandlePgn65265CruiseVehicleSpeed sends it as the CCVS1 parking brake switch (byte 1 0xF7 instead of 0xF3). */
    uint16_t reserved_bit_7 : 1;  /* bit 7: No reader and no record; logical input 55 = 0x80bcd4 bit 7 (no e2m name). Clear */
    uint16_t power_take_off_resume_switch_override_enable : 1;  /* bit 8: Set: the power take-off resume bit (power_take_off_switch_state_bits 0x80bcd5 bit 0; DSPTRUSW) is ORed in from 0x80bcdf bit 0 (DSPTRUUC 0x01) (set only, not cleared) instead of switch input 0x80bcce bit 1. andi.w #0x0100 at 0x153fc; J1939 entry 11 (logical input 56 = table bit 264); 12A8 +38 DSPZPTRU. The 106B record DSPTRUUO claims mask 0x2000 but the code uses this bit. Clear */
    uint16_t reserved_bit_9 : 1;  /* bit 9: No reader and no 106B record; by the layout (57) the power take-off accelerate bit 0x80bcd5 bit 1 (PTACELSW). Clear */
    uint16_t power_take_off_set_switch_override_enable : 1;  /* bit 10: Set: 0x80bcd5 bit 2 (DSPTSESW) is ORed in from 0x80bcdf bit 2 (DSPTSEUC 0x04) (set only, not cleared) instead of switch input 0x80bcce bit 2. e2m DSPTSEUO 0x400 'PTO SET SWITCH'; andi.w #0x0400 at 0x153c8; J1939 entry 12 (logical input 58); 12A8 +3A DSPZPTSE. Clear */
    uint16_t reserved_bit_11 : 1;  /* bit 11: No reader and no 106B record; by the layout (59) the power take-off coast bit 0x80bcd5 bit 3 (PTCOASSW). Clear */
    uint16_t power_take_off_on_switch_override_enable : 1;  /* bit 12: Set: 0x80bcd5 bit 4 (DSPTONSW) is ORed in from 0x80bcdf bit 4 (DSPTONUC 0x10) (set only, not cleared) instead of switch input 0x80bcce bit 3. e2m DSPTONUO 0x1000 'PTO ENABLE SWITCH'; andi.w #0x1000 at 0x15394; J1939 entry 10 (logical input 60); 12A8 +3C DSPZPTON. Clear */
    uint16_t reserved_bit_13 : 1;  /* bit 13: e2m DSPTRUUO 0x2000 'USER OVERRIDE ENABLE FLAG FOR THE PTO RESUME SWITCH' but the code reads the power take-off resume override at bit 8; no reader here; by the layout (61) the set and resume bit 0x80bcd5 bit 5 (PTSERUSW). Clear */
    uint16_t reserved_bit_14 : 1;  /* bit 14: No reader and no 106B record; by the layout (62) the auxiliary shutdown status 0x80bcd5 bit 6 (DSAUSHSW; 12A8 +3E DSPZAUSH; value DSAUSHUC 0x80bcdf bit 6) - see bit 6. Clear */
    uint16_t reserved_bit_15 : 1;  /* bit 15: No reader and no record; logical input 63 = 0x80bcd5 bit 7. Clear */
};

struct cm550_algorithm_enable_flags_18_t {
    uint16_t high_speed_governor_gain_scheduling_enable : 1;  /* bit 0: e2m HSGNSDEN (N) 'BIT 0 OF 0-15 OF WORD 12H ENABLES HSG GAIN SCHEDULING' (HS_GOV); CM848 same name and bit. Code: selectHighSpeedGovernorGainSet andi.w #0x0001 at 0x1d3ae (the cross-firmware twin of CM848 0x1fa20 which tests the same bit). Clear in the dump (0x303a) */
    uint16_t engine_warmup_protection_enable : 1;  /* bit 1: e2m WPEAFG (N) 'ENABLE ENGINE WARMUP PROTECTION ALGORITHM WORD 12 BIT 1' (EWP_HDR). Code: cm550_highRpmEngineProtectionStateMachine (0x16df0 0x16e32; the oil drain-back time and maximum warmup time state machine) and cm550_fuelTemperatureLimitingSecondary (0x170c0). CM848 leaves it reserved_bit_1 (no CHR record). Set in the dump */
    uint16_t driver_reward_enable : 1;  /* bit 2: e2m DREN (N) 'WORD 12H BIT 2 OF 0 TO 15 DRIVER REWARD ENABLE' (DRVRWD07); CM848 same name and bit. No reference in the dumped 256 KB ROM (none in CM848 either). Clear */
    uint16_t duty_cycle_monitor_enable : 1;  /* bit 3: e2m DCMNEN (N) 'DUTY CYCLE MONITOR ENABLE BIT 3 OF 0-15' and DMAGEN 0x08 (DCMN); CM848 same name and bit. Code: cm550_updateDutyCycleMonitorLoadHistogram andi.w #0x0008 at 0xac52 (the duty cycle monitor long and short term maps). Set in the dump */
    uint16_t trending_enable : 1;  /* bit 4: e2m TRAGEN 0x10 'ENABLE FLAG FOR TRENDING ALGORITHM' (TRENDING group). Code: cm550_FUN_00031496 (0x314b2) cm550_FUN_000315be (0x315e6) and cm550_FUN_00031a68 (0x31a68) - the trending capture (_trending_data_capture_active / _trending_total_sample_count). CM848 leaves it reserved_bit_4 (no CHR record). Set in the dump */
    uint16_t datalogger_enable : 1;  /* bit 5: e2m UDEN (N) 'TRIM FOR ENABLING THE DATALOGGER. BIT 5 OF 0-15.' (USERDATA). Code: cm550_updateDataloggerTriggers (0x138f4; clear = triggers and set-up cleared) and cm550_recordDataloggerSamples (0x13a70). CM848 leaves it reserved_bit_5 (no CHR record). Set in the dump */
    uint16_t smart_air_compressor_enable : 1;  /* bit 6: e2m ACEN (N) 'WORD 12H BIT 6 OF 0 TO 15 - SMART AIR COMPRESSOR ENABLE' (AIRCOMP7); CM848 same name and bit. No reference in the dumped ROM (none in CM848 either). Clear */
    uint16_t reserved_bit_7 : 1;  /* bit 7: No CM550 e2m record and no reference in the dumped ROM. Guess: CM848 names this bit executive_timing_enable (CHR Executive_Timing_Enable SSECTMEA; read by its executive frame interrupt handler). Clear */
    uint16_t high_speed_governor_gear_ratio_gain_enable : 1;  /* bit 8: e2m HSGRGSEN (N) 'GEAR RATIO BASED GAIN SET SELECTION (ENABLED/DISABLED) BIT 8' (HSGGRGS); CM848 same name and bit (read by cm848_loadHighSpeedGovernorWorkingGainSet). No reference in the CM550 dumped ROM. Clear */
    uint16_t programmable_power_enable : 1;  /* bit 9: e2m PPEN (N) 'PROGRAMMABLE POWER BIT 9 OF 0 TO 15 WORD 12H/18D' (PROG_PWR); CM848 same name and bit. Code: cm550_FUN_0000ff48 (0xff48; clear = J1939 reference peak fueling) cm550_FUN_0001c8a0 (0x1c8d8) cm550_FUN_0001cc72 (0x1cc8e) and cm550_FUN_0001de58 (0x1de70 0x1df10 0x1df90) - torque curve and fueling paths. Clear */
    uint16_t reserved_bit_10 : 1;  /* bit 10: No e2m record in either firmware and no reader in either. Clear */
    uint16_t cruise_control_auto_resume_enable : 1;  /* bit 11: e2m AREN (N) 'BIT 11 OF 0-15. CRUISE CONTROL AUTO RESUME ENABLE/DISABLE' (CC_AR); CM848 same name and bit. No reference in the dumped ROM (none in CM848 either). Clear */
    uint16_t remote_throttle_enable : 1;  /* bit 12: e2m CTRMTHEN 0x1000 'REMOTE THROTTLE ENABLE BIT 12 OF 0-15' (APL_ADJ); CM848 same name and bit. Code: cm550_processJ1939RemoteAcceleratorPedalPosition (0x207c0; J1939 remote accelerator into analog_sensor_override_values[11]) cm550_FUN_0002ec50 (0x2ec6c; alternate throttle arbitration) and j1939HandlePgn61443Eec2 (0x32fca). Set in the dump */
    uint16_t remote_throttle_transition_verification_enable : 1;  /* bit 13: e2m CTRTTZEN 0x2000 'ENABLES REMTHROT/THROT PERC CALC BEFORE TRANS. BIT 13/15 WORD C'; CM848 same name and bit. Code: cm550_FUN_0002ec50 andi.l #0x2000 at 0x2ec90 (the remote throttle hand-over branch). Set in the dump */
    uint16_t engine_retarder_service_brake_activate_enable : 1;  /* bit 14: e2m EBBREN (N) 'WORD 12H BIT E OF 0-F - SERVICE BRAKE MUST BE TAPPED' (ENGBRK05 engine brake); CM848 same name and bit (read by cm848_updateEngineRetarderAllowedState). No reference in the CM550 dumped ROM. Clear */
    uint16_t engine_retarder_rate_limit_enable : 1;  /* bit 15: e2m EBRTLMEA (N) 'BIT 15 OF 0-15 - RATE LIMIT BETWEEN CURRENT AND DESIRED EB LEVELS'; CM848 same name and bit. No reference in the dumped ROM (none in CM848 either). Clear */
};

struct algorithm_enable_flags_25_t {
    uint16_t engine_retarder_rate_limit_defeat_enable : 1;  /* bit 0: e2m EBRTDFEN 'BIT 0 OF 0-15 - ENABLE BRAKE RATE LIMIT DEFEAT DURING ON/OFF TRANS'; no test in the dumped ROM; clear in the bench EEPROM (0x0180); same as CM848 */
    uint16_t powertrain_protection_enable : 1;  /* bit 1: e2m TCEN 'POWERTRAIN PROTECTION ENABLE WORD 19H BIT 1 OF 0 TO 15'; no test in the dumped ROM; clear; same as CM848 */
    uint16_t powertrain_protection_lugback_enable : 1;  /* bit 2: e2m TCLDEN 'POWERTRAIN PROTECTION LUGBACK ENABLE WORD 19H BIT 2 OF 0 TO 15'; no test in the dumped ROM; clear; same as CM848 */
    uint16_t j1939_multiplex_limp_home_on_analog_throttle_enable : 1;  /* bit 3: e2m MXLPANEA (mask 8) 'BIT 3 ENABLED INDICATES LIMPHOME VIA MUXING SHALL USE RAW SAMPLED THROTTLE' (v64t6_s puts it at +36 but the 7x/8x ISB e2m files and CM848's CHR e2m have +34); read by mc68k_updateIdleSwitchesFromLocalInputs (andi.w #8 at 0x205e0): set = idle switch states from the raw sampled throttle ADC (idle_check_accelerator_pedal_raw below 0x169 = at idle) / clear = the debounced hardware idle switch (timer 100 minus 50 per pass) - the twin of cm848_updateIdleSwitchesFromLocalInputs; clear in the bench EEPROM */
    uint16_t reserved_bit_4 : 1;  /* bit 4: no record in v64t6_s and no test in the dumped ROM; guess ISTSRVEN 'ENABLE TO FORCE THE RPM TO RAMP UP TO IS_TAS_PEAK_IDLE' (mask 0x10 at +34 in 13 7x/8x ISB e2m files); CM848 keeps reserved_bit_4 too; clear */
    uint16_t smart_road_speed_governor_enable : 1;  /* bit 5: e2m SREN 'SMART RSG ENABLE WORD 19H BIT 5 OF 0 TO 15' (RSG = road speed governor); no test in the dumped ROM; clear; same as CM848 */
    uint16_t fan_clutch_1_air_conditioning_enable : 1;  /* bit 6: e2m FCAKINEN 'AC INPUT ENABLE BIT 6 OF WORD 19H'; no test in the dumped ROM; clear; same as CM848 */
    uint16_t fan_clutch_1_coolant_temperature_enable : 1;  /* bit 7: e2m FCCLINEN 'CT INPUT ENABLE BIT 7 OF WORD 19H'; no test in the dumped ROM (a fan clutch reader may sit in the undumped code above 0x40000); SET in the bench EEPROM; same as CM848 */
    uint16_t fan_clutch_1_intake_manifold_temperature_enable : 1;  /* bit 8: e2m FCIMINEN 'IMT INPUT ENABLE BIT 8 OF WORD 19H'; no test in the dumped ROM; SET in the bench EEPROM; same as CM848 */
    uint16_t fan_clutch_2_air_conditioning_enable : 1;  /* bit 9: e2m FCAKI2EN 'AC INPUT ENABLE BIT 9 OF WORD 19H'; no test in the dumped ROM; clear; same as CM848 */
    uint16_t fan_clutch_2_air_conditioning_pressure_enable : 1;  /* bit 10: e2m FCAK02EN 'AC SWITCH ENABLE BIT 10 OF WORD 19H' (CM848's CHR e2m names the same mnemonic Fan_Clutch_2_AC_Pressure_Enable); no test in the dumped ROM; clear */
    uint16_t fan_clutch_2_coolant_temperature_enable : 1;  /* bit 11: e2m FCCLI2EN 'CT INPUT ENABLE BIT 11 OF WORD 19H'; no test in the dumped ROM; clear; same as CM848 */
    uint16_t fan_clutch_2_engine_retarder_enable : 1;  /* bit 12: e2m FCEBINEN 'FAN_CLUTCH_2_EB_ENABLE BIT 12 OF WORD 19H' (EB = engine brake); no test in the dumped ROM; clear; same as CM848 */
    uint16_t fan_clutch_2_intake_manifold_temperature_enable : 1;  /* bit 13: e2m FCIMI2EN 'IMT INPUT ENABLE BIT 13 OF WORD 19H'; no test in the dumped ROM; clear; same as CM848 */
    uint16_t fan_clutch_2_manual_input_enable : 1;  /* bit 14: e2m FCSW02EN 'FAN_CLUTCH_2_MANUAL_INPUT_ENABLE BIT 14 OF WORD 19H'; no test in the dumped ROM; clear; same as CM848 */
    uint16_t manual_fan_level_override : 1;  /* bit 15: e2m ADMNFMOD (mask 0x8000) 'A/D OVERRIDE FOR MANUAL FAN LEVEL (REQUESTED % FAN SPEED)'; read by cm550_processJ1939EngineFanRequestedSpeed (andi.w #0x8000 at 0x20440): set and the commanding source priority at least j1939_engine_fan_request_source_priority = j1939_engine_fan_requested_speed from the J1939 CM1 fan request (raw x 16 / 10; timeout or 0xfe = the global default) - the twin of cm848_processJ1939EngineFanRequestedSpeed; clear */
};

struct cm550_algorithm_enable_flags_27_t {
    uint16_t reserved_bit_0 : 1;  /* bit 0: no record in v64t6_s and no test in the dumped ROM; guess RTEN 'ENABLES/DISABLE REAL TIME CLOCK FUNCTION' (an S record with mask 1 at +38 in 11 other e2m files; an N record with no bit in 10 more); CM848 reserved_bit_0 too; clear in the bench EEPROM (0x2010) */
    uint16_t reserved_bit_1 : 1;  /* bit 1: e2m CRMFOGEA 'IF ENABLED USES CC/RSG MIN FUEL TRANSTION RAMP DURING' (N record with no bit; mask 2 in CM848's CHR e2m and 18 later ISB files) - OOG is never spelled out; no test in the dumped ROM; CM848 keeps reserved_bit_1 for the same reason; clear */
    uint16_t engine_retarder_fuel_to_brake_delay_enable : 1;  /* bit 2: e2m EBAEDYEN 'BIT 2 TO DELAY ON E-BRAKE TRANSITION'; no test in the dumped ROM; clear; same as CM848 */
    uint16_t switched_throttle_control_governor_select : 1;  /* bit 3: e2m STCGASDS 'SWITCHED THROTTLE CONTROL GOVERNOR SELECT (BIT 3 OF 0 - 15)'; read by cm550_acceleratorThrottleFaultDetector (0xd306: clear + throttle interlock switch bit 1 = the switch toggles the all speed governor throttle source) and cm550_FUN_0000d4ae (0xd4e8: set + interlock switch = the switch toggles the switched throttle control governor enable); clear; same as CM848 */
    uint16_t boost_pressure_in_range_diagnostic_enable : 1;  /* bit 4: e2m DGBSIREN 'ENABLE FLAG FOR BOOST PRESSURE IN-RANGE DIAGNOSTIC ALGORITHM' (N record with no bit; mask 0x10 in CM848's CHR e2m); read by cm550_monitorBoostPressureSensorInRangeHighReading (andi.w #0x10 at 0xe9b4): the boost in-range high check (boost_pressure_sensor_high_reading_minimum_boost_pressure / boost_pressure_sensor_high_reading_debounce_limit) while RUNNING; SET in the bench EEPROM; same as CM848 */
    uint16_t air_handling_enable : 1;  /* bit 5: e2m AHEN 'BIT 5 ENABLE/DISABLE FOR AIR HANDELING FEATURE. BIT 11' (two bit numbers in the text; 0x20 in CM848's CHR e2m and the 7x/8x S records); no test in the dumped ROM; clear */
    uint16_t air_mass_calculation_enable : 1;  /* bit 6: e2m TBAMEN 'BIT 6 ENABLE/DISABLE FOR AIRMASS CALCULATION. BIT 12 OF 0-15' (two bit numbers; 0x40 in CM848 and the later S records); no test in the dumped ROM; clear */
    uint16_t turbine_speed_and_temperature_calculation_enable : 1;  /* bit 7: e2m TBSPTMEN 'BIT 7 ENABLE/DISABLE TURBIN SPEED /TEMP. CALC. BIT 13 OF 0-15' (two bit numbers; 0x80 in CM848 and the later S records); no test in the dumped ROM; clear */
    uint16_t four_step_wastegate_control_enable : 1;  /* bit 8: e2m TUWGEN 'ENABLE/DISABLE FOR 4 STEP WG CONTROL. BIT8 15 OF 0-15' (two bit numbers; 0x100 in CM848 and the later S records); no test in the dumped ROM; clear */
    uint16_t wastegate_tool_override_enable : 1;  /* bit 9: e2m TUWGOVEN 'BIT9 ENABLE/DISABLE FOR TOOL OVERRIDE OF WASTEGATES. BIT 14 OF' (two bit numbers; 0x200 in CM848 and the later S records); no test in the dumped ROM; clear */
    uint16_t idle_shutdown_temperature_enable : 1;  /* bit 10: e2m ISAATPEN (mask 0x400) 'BIT 10 OF 15. SELECTS THE TEMP. INTERACTION OPTION FOR I[DLE SHUTDOWN]'; read by cm550_runIdleShutdownStateMachine (andi.l #0x400 at 0x1da6c; the idle shutdown state machine): set with its temperature condition flag (idle_shutdown_override_successful_flag = 1) sends state 1 to the 600-pass wait state 3 instead of counting down to the warning state 2; clear; same as CM848 */
    uint16_t reserved_bit_11 : 1;  /* bit 11: no record in v64t6_s and no test in the dumped ROM; guess AT01EN 'BIT 11 OF 15. ENABLES THE ANTI THEFT AT_AUTO MODULE' (0x800 in 18 7x/8x ISB e2m files; CM848 anti_theft_enable) or AHEN's second number; clear */
    uint16_t reserved_bit_12 : 1;  /* bit 12: no record in v64t6_s and no test in the dumped ROM; guess ATAULOEN 'BIT 12 OF 15. ENABLES THE AUTOMATIC LOCKING FUNCTIONALITY' (0x1000 in 18 later ISB e2m files; CM848 anti_theft_automatic_lock_enable) or TBAMEN's second number; clear */
    uint16_t reserved_bit_13 : 1;  /* bit 13: no record in v64t6_s and no test in the dumped ROM but SET in the bench EEPROM (0x2010); guess SRRMEN 'IF ENABLED RSG REF SPEED IS ALLOWED TO RAMP' (0x2000 in 18 later ISB e2m files; CM848 road_speed_governor_reference_speed_ramp_enable) or TBSPTMEN's second number (BIT 13 OF 0-15) */
    uint16_t reserved_bit_14 : 1;  /* bit 14: no record in v64t6_s and no test in the dumped ROM; guess CZEN continuous oil replacement system enable (0x4000 in one later ISB e2m) or TUWGOVEN's second number (BIT 14); CM848 reserved_bit_14 too; clear */
    uint16_t reserved_bit_15 : 1;  /* bit 15: no record in v64t6_s and no test in the dumped ROM; guess OMEN oil level monitor enable (0x8000 in one later ISB e2m) or TUWGEN's second number (15 OF 0-15); CM848 reserved_bit_15 too; clear */
};

struct cm550_algorithm_enable_flags_28_t {
    uint16_t reserved_bit_0 : 1;  /* bit 0: no record in any e2m and no test in the dumped ROM; CM848 reserved_bit_0 too; clear in the bench EEPROM (0x0000) */
    uint16_t reserved_bit_1 : 1;  /* bit 1: no record in any e2m and no test in the dumped ROM; CM848 reserved_bit_1 too; clear */
    uint16_t reserved_bit_2 : 1;  /* bit 2: no record in any e2m and no test in the dumped ROM; CM848 reserved_bit_2 too; clear */
    uint16_t reserved_bit_3 : 1;  /* bit 3: no record in v64t6_s and no test in the dumped ROM; guess ESNKASEN 'ALLOWS ENGINE TO RUN WHILE KEYSWITCH IS OFF' (0x8 in 18 7x/8x ISB e2m files; CM848 keyless_restart_enable); clear */
    uint16_t integrated_idle_management_enable : 1;  /* bit 4: e2m ISTAEN (mask 0x10) 'ENABLES TAS FEATURE.' in group 133 IIMSGR0 'INTEGRATED IDLE MANAGEMENT' (TAS is never spelled out in any e2m; CM848's STLOCKEN says starter lockout is exclusive of ISTAEN); read by cm550_runIdleShutdownStateMachine (0x1d9da: the idle shutdown state machine runs only while word 3 bit 1 ISAGEN is set and this bit is clear) and mc68k_sampleAndDebounceDiscreteInputs (0x15470: set + a rising edge of power_take_off_switch_state_bits bit 0x10 at zero road speed sets bit 0x40 of switch_status_cruise_coast_switch_bit_3_on_off); clear in the bench EEPROM; CM848 reserved_bit_4 */
    uint16_t reserved_bit_5 : 1;  /* bit 5: no record in v64t6_s and no test in the dumped ROM; guess ESALASEN 'ENABLES ALARM SOUNDING FOR AUTO-START KEYSWITCH ON' (0x20 in 18 later ISB e2m files; CM848 alarm_during_automatic_start_enable); clear */
    uint16_t reserved_bit_6 : 1;  /* bit 6: no record in v64t6_s and no test in the dumped ROM; guess ISEKGEN 'SELECTS PULSED SIGNAL TAMPER DETERRENCE FOR BUNK THERMO[STAT]' (0x40 in 18 later ISB e2m files); CM848 reserved_bit_6; clear */
    uint16_t reserved_bit_7 : 1;  /* bit 7: no record in v64t6_s and no test in the dumped ROM; guess STLOCKEN 'ENABLES STARTER LOCKOUT FEATURE (EXCLUSIVE OF ISTAEN)' (0x80 in 18 later ISB e2m files; CM848 starter_lockout_enable); clear */
    uint16_t reserved_bit_8 : 1;  /* bit 8: no record in v64t6_s and no test in the dumped ROM; guess TCWGTCEN 'ENABLE/DISABLE DIRECT TABLE CONTROL OF WG' (0x100 in 18 later ISB e2m files; CM848 wastegate_table_control_enable); clear */
    uint16_t reserved_bit_9 : 1;  /* bit 9: no record in any e2m and no test in the dumped ROM; CM848 reserved_bit_9 too; clear */
    uint16_t reserved_bit_10 : 1;  /* bit 10: no record in v64t6_s and no test in the dumped ROM (J90350.00's J1939 input handlers gate on word 25 bit 15 / word 33 bit 4 instead); guess JC39MXEA 'BIT 10 OF 0-15 ENABLES OR DISABLES MULTIPLEX PROCESSING' (0x400 in 18 later ISB e2m files; CM848 j1939_multiplex_enable); clear */
    uint16_t reserved_bit_11 : 1;  /* bit 11: no record in v64t6_s and no test in the dumped ROM; guess ISBKDLEN 'ENABLE TO TURN ON SENSING OF THE BUNK THERMOSTAT DATALINK' (0x800 in 18 later ISB e2m files) or AILSISEN alternate idle function enable (4 files); CM848 reserved_bit_11; clear */
    uint16_t reserved_bit_12 : 1;  /* bit 12: no record in v64t6_s and no test in the dumped ROM; guess ATRNGNEN 'ENABLE FOR GENERATION OF RANDOM NUMBERS (FOR VAT)' (0x1000 in 18 later ISB e2m files; CM848 anti_theft_random_number_generator_enable); clear */
    uint16_t reserved_bit_13 : 1;  /* bit 13: no record in v64t6_s and no test in the dumped ROM; guess SLNOCTEN 'ENABLES NORMALLY OPEN CONTACTS FOR SL RELAY' (0x2000 in 18 later ISB e2m files; CM848 starter_lockout_normally_open_contact_enable); clear */
    uint16_t reserved_bit_14 : 1;  /* bit 14: no record in v64t6_s and no test in the dumped ROM; guess OTIRDGEN 'SELECTS OIL TEMPERATURE STUCK IN RANGE DIAGNOSTIC' (0x4000 in 13 later ISB e2m files); CM848 reserved_bit_14; clear */
    uint16_t reserved_bit_15 : 1;  /* bit 15: no record in v64t6_s and no test in the dumped ROM; guess LSQAIHEN 'WHEN ENABLED LSG QPID IS INHIBITED FOR MIDDLE AND HIGH GEAR GAIN' (0x8000 in 13 later ISB e2m files; CM848 reserved_bit_15 for the same unexpanded QPID); clear */
};

struct cm550_algorithm_enable_flags_32_t {
    uint16_t misfire_timing_limit_enable : 1;  /* bit 0: e2m BSTALMEN (mask 01) 'MISFIRE TIMING LIMIT ALGORITHM ENABLE'; read by cm550_rpmLoadParameterLookup (0x26ac0: output_of_the_misfire_timing_limit_table_60_to_60 from the boost pressure x engine speed table e2m 8191 BSTATBZA) and cm550_applyMisfireTimingLimit (0x26b0c: raises the timing advance to that limit and sets intermediate timing state 11); SET in the bench EEPROM (0xf241) */
    uint16_t reserved_bit_1 : 1;  /* bit 1: no record in v64t6_s and no test in the dumped ROM; guess MPCACGEN 'ENABLES CASE SYSTEM CONFIGURATION MESSAGE PROCESSING' (0x2 in 16 later ISB e2m files); CM848 bit 1 is end_of_injection_limit_enable (different build); clear */
    uint16_t reserved_bit_2 : 1;  /* bit 2: no record in any ISB e2m and no test in the dumped ROM; CM848 bit 2 is equivalent_throttle_enable (different build); clear */
    uint16_t reserved_bit_3 : 1;  /* bit 3: no record in any e2m and no test in the dumped ROM; CM848 reserved_bit_3 too; clear */
    uint16_t ford_air_conditioning_enable : 1;  /* bit 4: e2m ACFDEN (mask 0x10) 'WHETHER OR NOT AND HOW THE FORD AC IS ENABLED'; no test in the dumped ROM; clear; CM848 bit 4 is intake_air_heater_24_volt_enable */
    uint16_t cooling_system_monitor_enable : 1;  /* bit 5: e2m CLMREN (mask 0x20) 'WHETHER OR NOT THE COOLING SYSTEM MONITOR IS ENABLED'; no test in the dumped ROM; clear */
    uint16_t intake_air_heater_control_enable : 1;  /* bit 6: e2m IHEN (mask 0x40) 'INTAKE AIR HEATER CONTROL ALGORITHM ENABLE'; no test in the dumped ROM (a reader may sit in the undumped code above 0x40000); SET in the bench EEPROM; CM848 has the same flag at bit 0 */
    uint16_t reserved_bit_7 : 1;  /* bit 7: e2m IHMREN (mask 0x80) 'WHETHER OR NOT AND HOW THE MISFIRE MONITOR IS ENA[BLED]' but the mnemonic reads intake heater monitor (IH as in IHEN / MR as in TBMREN and CLMREN); no test in the dumped ROM; guess misfire monitor enable or intake air heater monitor enable; clear */
    uint16_t turbocharger_monitor_enable : 1;  /* bit 8: e2m TBMREN (mask 0x100) 'TURBOCHARGER MONITOR ENABLE'; no test in the dumped ROM; clear */
    uint16_t low_speed_governor_no_load_fuel_enable : 1;  /* bit 9: e2m LSNLFLEN (mask 0x200) '(BIT X OF WORD Y) LSG USE OF LSG_NO_LOAD_FUEL_ENA[BLE]'; read by vp44_FUN_00025a34 (0x25ab0: subtracts no_load_fuel_quantity from the low speed governor integrator preset) and cm550_runLowSpeedGovernor (0x25f72: adds it to the low speed governor PID output before the clamp); SET in the bench EEPROM */
    uint16_t clutch_switch_inversion_cancel_enable : 1;  /* bit 10: e2m CHSWICEN (mask 0x400) 'TO CANCEL CLUTCH_SWITCH INVERSION'; read by mc68k_sampleAndDebounceDiscreteInputs (andi.w #0x400 at 0x150c6): XORs 0x400 into the discrete input sample; clear */
    uint16_t brake_switch_inversion_cancel_enable : 1;  /* bit 11: e2m BRSWICEN (mask 0x800) 'TO CANCEL BRAKE_SWITCH INVERSION'; read by mc68k_sampleAndDebounceDiscreteInputs (andi.w #0x800 at 0x150ea): XORs 0x800 into the discrete input sample; clear */
    uint16_t oil_pressure_high_error_disable : 1;  /* bit 12: e2m ADO2DBEN (mask 0x1000) 'FLAG (B12 W 020H) OIL PR. HIGH ERROR DISABLE FEAT[URE]'; no test in the dumped ROM; SET in the bench EEPROM */
    uint16_t vp44_governor_watchdog_enable : 1;  /* bit 13: e2m VPGVWDEN (mask 0x2000) 'FLAG (B13 W 020H) VP44 GOVERNOR WATCHDOG FEATURE' (VP44 = the Bosch VP44 injection pump; the sibling file 64t4 carries the same record under the mnemonic ADO2DBEN); no test in the dumped ROM; SET in the bench EEPROM */
    uint16_t air_fuel_control_coolant_temperature_adjustment_enable : 1;  /* bit 14: e2m AFCLAJEN (mask 0x4000) 'ENABLES ADDITION OF COOLANT TEMP FUEL TO AFC' (AFC = air fuel control); read by cm550_fuelTimingTransitionStateMachine (andi.l #0x4000 at 0xc1d4): adds the coolant temperature x engine speed table to air_fuel_control_fuel_limit unless system error status word 2 bits 0 / 1 / 4 are latched; SET in the bench EEPROM */
    uint16_t full_fueling_coolant_temperature_adjustment_enable : 1;  /* bit 15: e2m 5DCLAJEN (mask 0x8000) 'ENABLES ADDITION OF COOLANT TEMP FUEL TO 100% FUE[LING]'; read by cm550_FUN_0001cc72 (andi.l #0x8000 at 0x1cc9e): adds the coolant temperature x engine speed table to all three full fueling values it computes: throttle_100_fueling, full_fueling_value_at_hsg_bef_droop_speed_0_100 and throttle_100_fueling_low_horsepower_curve (the block runs only while word 18 bit 9 is clear) unless system error status word 2 bits 0 / 1 / 4 are latched; SET in the bench EEPROM */
};

struct cm550_algorithm_enable_flags_33_t {
    uint16_t cruise_resume_switch_inversion_cancel_enable : 1;  /* bit 0: e2m RUSWICEN (mask 01) 'TO CANCEL CRUISE_RESUME_SWITCH INVERSION'; read by mc68k_sampleAndDebounceDiscreteInputs (andi.w #1 at 0x1510e): XORs 2 into the discrete input sample; clear in the bench EEPROM (0x0000) */
    uint16_t cruise_set_switch_inversion_cancel_enable : 1;  /* bit 1: e2m SESWICEN (mask 02) 'TO CANCEL CRUISE_SET_SWITCH INVERSION'; read by mc68k_sampleAndDebounceDiscreteInputs (andi.w #2 at 0x1512e): XORs 4 into the discrete input sample; clear */
    uint16_t cruise_on_switch_inversion_cancel_enable : 1;  /* bit 2: e2m CRSWICEN (mask 04) 'TO CANCEL CRUISE_ON_SWITCH INVERSION'; read by mc68k_sampleAndDebounceDiscreteInputs (andi.w #4 at 0x1514e): XORs 8 into the discrete input sample; clear */
    uint16_t battery_voltage_low_at_cranking_enable : 1;  /* bit 3: e2m DGBTCKEN (mask 08) 'BATTERY VOLTAGE LOW AT CRANKING FEATURE ENABLE FLAG'; no test in the dumped ROM; clear */
    uint16_t engine_retarder_switch_level_override : 1;  /* bit 4: no record in v64t6_s; ADEBLVOD 'A/D OVERRIDE FOR ENGINE BRAKE SWITCH LEVEL' sits at +44 mask 0x10 in 10 later ISB e2m files (74be62rls .. Isbp700) and is CM848's algorithm_enable_flags_13_t bit 0 (same field name); read by cm550_processJ1939EngineRetarderSelection (andi.w #0x10 at 0x203a8): set and the commanding source priority at least j1939_engine_retarder_selection_source_priority = j1939_engine_retarder_selection_percent from the J1939 EBC1 engine retarder selection (raw x 4 / 10; timeout or 0xfe = j1939_engine_retarder_selection_default_percent) - the twin of cm848_processJ1939EngineRetarderSelection; clear */
    uint16_t reserved_bit_5 : 1;  /* bit 5: no record in any ISB e2m and no test in the dumped ROM; clear */
    uint16_t actual_sensor_values_enable : 1;  /* bit 6: e2m ADACSNEN (mask 40) 'ENABLE FLAG FOR ACTUAL SENSOR VALUES ALGORITHM'; no test in the dumped ROM; clear */
    uint16_t variable_geometry_turbocharger_enable : 1;  /* bit 7: e2m VGAGEN (mask 80) 'ENABLE FLAG FOR VGT ALGORITHM' (VGT = variable geometry turbocharger; 4 other files put VPTPMREN fuel temperature monitor here); no test in the dumped ROM; clear */
    uint16_t turbocharger_speed_enable : 1;  /* bit 8: e2m TBAGEN (mask 100) 'ENABLE FLAG FOR TURBOCHARGER SPEED ALGORITHM'; no test in the dumped ROM; clear */
    uint16_t low_speed_governor_temperature_idle_adjust_override_enable : 1;  /* bit 9: e2m LSTPIHEN (mask 200) 'ENABLE FOR OVERRIDING THE TEMP IDLE ADJUST IN THE LSG' (LSG = low speed governor); no test in the dumped ROM; clear */
    uint16_t missing_tooth_found_enable : 1;  /* bit 10: e2m MSTTFNEN (mask 400) 'MISSING TOOTH FOUND ENABLED = 1'; no test in the dumped ROM; clear */
    uint16_t reserved_bit_11 : 1;  /* bit 11: no record in v64t6_s and no test in the dumped ROM; guess EQTHEN 'EQUIVALENT THROTTLE FEATURE ENABLE FLAG' (0x800 in 20 other ISB e2m files) or EXRSDVEN exhaust restrictor device (3 files); clear */
    uint16_t reserved_bit_12 : 1;  /* bit 12: no record in v64t6_s and no test in the dumped ROM; guess MPCARSEN 'ENABLES CASE ASG AUTOMATIC RESCALING ALGORITHM' (0x1000 in 18 later ISB e2m files) or IHAAPREN ambient air pressure for the intake heater (3 files); clear */
    uint16_t reserved_bit_13 : 1;  /* bit 13: no record in v64t6_s and no test in the dumped ROM; guess PTFTEN 'FIRE TRUCK SET/RESUME PTO ENABLE FLAG' (0x2000 in 18 later ISB e2m files) or TCSTLEN torque converter stall torque management (3 files); clear */
    uint16_t reserved_bit_14 : 1;  /* bit 14: no record in v64t6_s and no test in the dumped ROM; guess SMS_EN shift management system (0x4000 in 13 later files) / TCTCPTEN powertrain protection torque converter (4) / VSBKSWEN brake switch diagnostics (3); clear */
    uint16_t ambient_pressure_control_enable : 1;  /* bit 15: e2m AAPRCOEN (mask 8000) 'AMBIENT PRESSURE CONTROL ALGORITHM ENABLE'; no test in the dumped ROM; clear */
};

struct cm550_fault_entry_t {
    uint32_t key_on_hour_meter;  /* key_on_hour_meter (0x80bda4) at capture (move.l) */
    uint16_t fault_code_index;  /* the fault code index (0-124) that owns the entry; 125 = free (cm550_releaseFaultFreezeFrameEntry). CM848 fault_entry_t.fault_code is a byte with 0xAA = free */
    uint16_t vehicle_speed;  /* 0x80a9d0 at capture: e2m 117D +C VSFTAVVS 'sampled road speed after it has been filtered' */
    uint16_t filtered_rpm;  /* 0x80ccf4 at capture: e2m 100C +2 ESCMES 'engine speed based from period of one cam rev' */
    uint16_t system_switch_status;  /* system_switch_status (0x80bcc8; e2m 1092 +0 SSSWSS01) at capture */
    uint16_t engine_load_at_current_speed;  /* engine_load_at_current_speed_percent (0x80db5e; e2m 10BF +0 JCPCLD) at capture */
    uint16_t accelerator_pedal_position;  /* 0x80aa82 at capture: e2m 1047 +0 THROTTLE 'validated percent throttle commanded by driver' */
    uint16_t intake_manifold_pressure;  /* boost_pressure_sensor_state.filtered_value at capture */
    uint16_t coolant_temperature;  /* coolant_temperature_sensor_state.filtered_value at capture */
    uint16_t intake_manifold_temperature;  /* intake_manifold_temperature_sensor_state.filtered_value at capture */
    uint16_t oil_pressure;  /* oil_pressure_sensor_state.filtered_value at capture */
    uint16_t system_switch_status_2;  /* system_switch_status_2 (0x80bcca; e2m 1092 +2 SSSWSS02) at capture */
    uint32_t engine_hour_meter;  /* engine_hour_meter (0x80ccee; e2m 11BC +0 CMEGTR 'time that the engine is not in stop state') at capture (move.l). CM848's fault_entry_t leaves these four bytes unwritten */
    FUELING_STATE final_fueling_state;  /* final_fueling_state (0x80d330) at capture; CM848 keeps only its low byte */
    uint16_t battery_voltage;  /* battery_voltage_sensor_state.filtered_value at capture */
    uint16_t final_fueling;  /* final_fueling (0x80d32e; e2m 1051 +0 FSFNFL) at capture */
    uint16_t selected_timing_advance;  /* selected_timing_advance_output_0_120 (0x80de6a; e2m 105B +2 TSFNTA) at capture; CM848's field here is main_injection_timing */
    uint16_t vp44_pump_status;  /* vp44_pump_status (0x80a18e; e2m 801A +1C FLFLSS) at capture. From here on CM848's fault_entry_t holds its common rail words instead */
    uint16_t vp44_fuel_temperature;  /* vp44_fuel_temperature (0x80a188; e2m 801A +16 FLFLTP) at capture */
    uint16_t cruise_control_switch_multiplexer;  /* cruise_control_switch_multiplexer_sensor_state.filtered_value at capture */
    uint16_t vp44_engine_speed;  /* vp44_engine_speed (0x80a17e; e2m 801A +C FLDFES) at capture */
    uint16_t system_switch_status_3;  /* system_switch_status_3 (0x80bccc; e2m 1092 +4 SSSWSS03) at capture */
};

struct cm550_commanded_throttle_state_t {
    uint16_t commanded_throttle;  /* e2m 1047 +0x0 THROTTLE 'VALIDATED PERCENT THROTTLE COMMANDED BY DRIVER' (0 - 100); CM848's commanded_throttle (+0x0) */
    uint16_t idle_validation_state;  /* e2m 1047 +0x2 CTTHID 'IDENTIFIES DIFFERENT COMBINATIONS OF THE THROTTLE POT AND SWITCHES' (0-9); CM848's idle_validation_state (+0x2) */
    uint16_t accelerator_off_idle;  /* e2m 1047 +0x4 CTTHSS 'STATUS OF THE IDLE VALIDATION SWITCH IDLE = 0; NOT_IDLE' (IDLE/NOT_IDLE); CM848's accelerator_off_idle (+0x4) */
    uint16_t throttle_transition_state;  /* e2m 1047 +0x6 CTTZST 'STATE OF POTENTIOMETER AND IDLE VALIDATION SWITCH READINGS' (0-3); CM848's throttle_transition_state (+0x6) */
    uint16_t throttle_minimum_confidence_counter;  /* e2m 1047 +0x8 CTCBCU 'CURRENT TIME OF COUNTER THAT MUST TIME OUT BEFORE A NEW THROTT' (0-25500); CM848's throttle_minimum_confidence_counter (+0x8) */
    uint16_t throttle_minimum;  /* e2m 1047 +0xa CTMNSATH 'MINIMUM SAMPLED_THROTTLE DETECTED' (0-21); CM848's throttle_minimum (+0xa) */
    uint16_t alternate_throttle;  /* e2m 1047 +0xc CTALTH 'PERCENT THROTTLE OVERRIDEN BY OTHER ALGORITHM' (0.0 - 100.0); CM848's alternate_throttle (+0xc) */
    uint16_t alternate_throttle_priority;  /* e2m 1047 +0xe CTTHSL 'ALTERNATE THROTTLE PRIORITY #, 0=NORMAL, 9=HIGHPR' (0 - 9); CM848's alternate_throttle_priority (+0xe) */
    uint16_t calculated_commanded_throttle;  /* e2m 1047 +0x10 CTEVTETH 'INTERMEDIATE CALCULATED VALUE OF COMMANDED THROTTLE BASED ON S' (0 - 100); CM848's calculated_commanded_throttle (+0x10) */
    uint16_t selected_alternate_throttle_priority;  /* e2m 1047 +0x12 CTALSLST 'STATE OF SELECTED ALTERNATE THROTTLE PRIORITY' (0 - 9); CM848's selected_alternate_throttle_priority (+0x12) */
    uint16_t idle_validation_inhibit_flag;  /* e2m 1047 +0x14 CTIVIH 'INHIBITS IDLE VALIDATION CALCULATIONS AND DIAGNOSTICS WHEN = 1' (0 - 1); CM550 only */
    uint16_t sampled_frequency_throttle;  /* e2m 1047 +0x16 FQTHSATH 'REQUESTED THROTTLE AFTER BEING LIN. AND FIL. VIA FREQ. THR. ALGO' (0-100); CM848's sampled_frequency_throttle (+0x14) */
    uint16_t frequency_throttle_active_flag;  /* e2m 1047 +0x18 FQTHAC 'INDICATES FREQUENCY THROTTLE HAS BEEN ENABLED' (0 - 1); CM848's frequency_throttle_active_flag (+0x16) */
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

struct j1939_periodic_transmit_entry_t {
    uint16_t pgn_key;  /* the PGN key of the periodic message (J2: the queue entry's +0) */
    uint16_t interval_ticks;  /* the transmit interval in 10 ms ticks */
    uint16_t next_tick;  /* the tick of the next transmission */
    void * builder;  /* the address of the message's builder function */
};

struct engine_tsc1_ignored_request_t {
    uint16_t data_link;  /* the network the request came on (the data link compared by findTsc1SourceConfiguration) */
    uint8_t source_address;  /* the source address of the ignored TSC1 request */
    uint8_t reserved_3;  /* no access */
    uint16_t control_mode;  /* the override control mode of the ignored request */
    uint16_t countdown;  /* counts down; the entry is removed at 0 */
};

struct cm550_retarder_tsc1_ignored_request_t {
    uint8_t source_address;  /* the source address of the ignored retarder TSC1 request */
    uint8_t reserved_1;  /* no access */
    uint16_t countdown;  /* counts down; the entry is removed at 0 (CM848's retarder entry is 6 bytes) */
};

struct table_lookup_2d_arguments_t {
    uint16_t x_axis_offset;  /* the byte offset of the last x axis point found; cached, written back by cm550_tableLookup2D */
    word* x_axis_pointer;  /* the x axis table (its first word is the byte count) */
    uint16_t x_input;  /* the x input value */
    uint16_t y_axis_offset;  /* the byte offset of the last y axis point found; cached, written back */
    word* y_axis_pointer;  /* the y axis table (its first word is the byte count) */
    uint16_t y_input;  /* the y input value */
    word* z_values_pointer;  /* the grid of z values, one row of x points per y point */
    uint16_t no_interpolation_flag;  /* nonzero: the lookup returns the grid value without interpolating */
};
