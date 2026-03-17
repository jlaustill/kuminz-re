#pragma once
#include <stdint.h>
typedef uint8_t   undefined;
typedef uint8_t   undefined1;
typedef uint16_t  undefined2;
typedef uint32_t  undefined4;
typedef uint64_t  undefined8;
typedef uint8_t   byte;
typedef uint16_t  ushort;
typedef uint32_t  uint;
typedef uint16_t  word;
typedef uint32_t  dword;
typedef int32_t   bool32;


/* ---- Structures ---- */

typedef struct {
    uint8_t source_address;  /* Destination address for J1939 response message */
    uint8_t service_id;  /* UDS service ID (0x67=SecAccess 0x7F=NegResp 0x60/0x68=Cummins) */
    uint8_t subfunction;  /* UDS subfunction code for service routing */
    uint8_t error_code;  /* Negative response error code (0x11=serviceNotSupported 0x37=requiredTimeDelayNotExpired) */
    uint8_t data_length;  /* Length of data payload in response */
    uint8_t data[5];  /* Variable response payload (security seeds etc) */
    uint8_t response_pending;  /* Flag to trigger transmission (1=send response) */
} uds_response_t;

typedef struct {
    uint16_t calculated;  /* Final calculated fuel demand value */
    uint16_t mode;  /* Fuel demand mode selector (0=normal) */
    uint16_t enable_flag;  /* Fuel demand enable flag (1=enabled) */
    uint16_t rate_limiter_state;  /* Rate limiter state machine value */
    uint16_t rate_delta;  /* Fuel demand rate of change delta */
    uint16_t throttle_based;  /* Throttle-based fuel demand component */
    uint16_t override_value;  /* Diagnostic override fuel demand value */
    uint16_t override_active;  /* Override mode active flag (1=override) */
    uint16_t rate_limited;  /* Rate-limited fuel demand output */
    uint16_t override_countdown;  /* Override timeout countdown (offset 0x12) */
    uint16_t reserved_14;  /* Gap/reserved (0x58e-0x590) */
    uint16_t reserved_16;  /* Gap/reserved (0x590-0x592) */
    uint16_t delta;  /* Fuel demand delta for rate calculations */
    uint16_t delta_filtered;  /* Filtered fuel demand delta */
} fuel_demand_control_t;

typedef struct {
    uint8_t condition_eval;  /* Protection condition evaluation result */
    uint8_t condition_flags_1;  /* Protection condition flags set 1 */
    uint8_t load_condition_flags;  /* Load-based protection condition flags */
    uint8_t overtemp_flags;  /* Overtemperature protection flags */
    uint8_t reserved_04;  /* Gap/reserved byte at offset 0x04 */
    uint8_t condition_flags_3;  /* Protection condition flags set 3 */
    uint8_t condition_flags_2;  /* Protection condition flags set 2 */
    uint8_t reserved_07;  /* Gap/reserved byte at offset 0x07 */
    uint8_t threshold_current;  /* Current threshold index for protection lookup */
    uint8_t action_flags;  /* Protection action trigger flags */
} protection_condition_flags_t;

typedef struct {
    uint16_t status_flags;  /* Protection status word (bit flags) */
    uint8_t flags[3];  /* Protection flags (3 bytes of packed bits) */
    uint8_t output_flags;  /* Protection output control flags */
    uint8_t reserved_06;  /* Gap/reserved */
    uint8_t rate_limit_flags;  /* Rate limit protection flags (offset 0x0c from 0xb0f2 is 0xb0fe) */
} protection_status_flags_t;

typedef struct {
    uint32_t status_code;  /* Protection status code (PROTECTION_STATUS_CODE enum) */
    uint16_t timeout_counter;  /* Protection timeout countdown counter */
    uint16_t state1_timer;  /* Level 1 protection state timer value */
    uint16_t state2_timer;  /* Level 2 protection state timer value */
} protection_timer_state_t;

typedef struct {
    uint16_t start_counter;  /* Engine start attempt counter */
    uint16_t crank_state;  /* Cranking state machine value */
    uint16_t cranking_flag;  /* Engine currently cranking flag (1=cranking) */
    uint16_t run_state;  /* Engine run state (ENGINE_OPERATING_MODE enum) */
} engine_crank_state_t;

typedef struct {
    uint8_t sync_status;  /* Sync detection status (0=lost 1=synced) */
    uint16_t reference_count;  /* Sync reference pulse count */
    uint16_t speed_raw;  /* Raw engine speed from position sensor */
    uint8_t reserved_05;  /* Padding for alignment */
} engine_sync_state_t;

typedef struct {
    uint16_t target_rpm;  /* Target engine RPM setpoint */
    uint16_t reserved_02;  /* Gap/reserved (0xb7ae) */
    uint16_t reserved_04;  /* Gap/reserved (0xb7b0) */
    uint16_t reserved_06;  /* Gap/reserved (0xb7b2) */
    uint16_t reserved_08;  /* Gap/reserved (0xb7b4) */
    uint16_t reserved_0a;  /* Gap/reserved (0xb7b6) */
    uint16_t reserved_0c;  /* Gap/reserved (0xb7b8) */
    uint16_t current_rpm;  /* Current engine RPM measurement */
} engine_rpm_state_t;

typedef struct {
    uint16_t oil_pressure;  /* Oil pressure sensor reading (PSI scaled) */
    uint16_t coolant_temp;  /* Coolant temperature sensor (deg C scaled) */
    uint16_t intake_air_temp;  /* Intake manifold air temperature */
    uint16_t battery_voltage;  /* Battery voltage raw ADC value */
} sensor_readings_t;

typedef struct {
    uint16_t version_marker;  /* EEPROM data version marker */
    uint16_t magic;  /* Validation magic (EEPROM_MAGIC enum: 0x600D=valid) */
    uint8_t header_block[6];  /* EEPROM header data block */
    uint32_t config_dword;  /* EEPROM configuration dword */
    uint16_t config_word;  /* EEPROM configuration word */
    uint8_t calibration_block1[6];  /* Calibration data block 1 */
    uint16_t cal_word1;  /* Calibration parameter word 1 */
    uint16_t cal_word2;  /* Calibration parameter word 2 */
    uint16_t cal_word3;  /* Calibration parameter word 3 */
    uint16_t cal_word4;  /* Calibration parameter word 4 */
    uint32_t serial_number;  /* ECU serial number from EEPROM */
} eeprom_header_t;

typedef struct {
    uint32_t integrator;  /* Speed control PID integrator (Q16.16 fixed point) */
    uint32_t output;  /* Governor output command value */
} governor_output_t;

typedef struct {
    uint8_t enable_ch0_7;  /* Injector enable bitmap channels 0-7 */
    uint8_t enable_ch8_15;  /* Injector enable bitmap channels 8-15 */
    uint8_t channel_status;  /* Output channel status flags */
    uint8_t timing_mode;  /* Injector timing mode selector */
    uint8_t output_ch0;  /* Channel 0 output state */
    uint8_t fault_flags;  /* Injector fault detection flags */
    uint8_t output_ch1;  /* Channel 1 output state */
} injector_control_t;

typedef struct {
    uint8_t message_index;  /* Current message buffer index */
    uint8_t message_buffer;  /* Message buffer selector */
    uint16_t message_counter;  /* Received message counter */
    uint16_t dm1_pending;  /* DM1 diagnostic message pending flag */
} can_rx_state_t;

typedef struct {
    uint8_t mode_bits;  /* Protection mode selection bits */
    uint8_t system_enable_bits;  /* Protection subsystem enable flags */
    uint8_t reserved_02;  /* Gap/reserved */
    uint8_t control_word;  /* Protection control word */
} protection_enable_t;

typedef struct {
    uint16_t write_index;  /* Next write position in fault list */
    uint16_t read_index;  /* Current read position in fault list */
    uint16_t emission_count;  /* Count of emission-related faults */
    uint16_t total_emission_faults;  /* Total emission fault counter */
} fault_list_state_t;

typedef struct {
    uint16_t byte_count;  /* Bytes remaining to transfer */
    uint16_t reserved_02;  /* Gap (0x3fec84-0x3fec85) */
    uint16_t reserved_04;  /* Gap (0x3fec86-0x3fec87) */
    uint16_t reserved_06;  /* Gap (0x3fec88-0x3fec89) */
    uint16_t state;  /* Transfer state machine value */
    uint16_t status;  /* Transfer status/result code */
} data_transfer_state_t;

typedef struct {
    uint8_t session_flags;  /* Diagnostic session active flags */
    uint8_t enable_flags_2;  /* Secondary diagnostic enable flags */
    uint8_t eeprom_status;  /* EEPROM operation status byte */
    uint8_t reserved_03;  /* Gap/reserved */
    uint8_t reserved_04;  /* Gap/reserved */
    uint8_t checksum_status;  /* EEPROM checksum validation status */
} diag_session_state_t;

typedef struct {
    uint16_t enable_state;  /* System master enable state */
    uint16_t condition_monitor;  /* Condition monitor flags */
    uint16_t reserved_04;  /* Gap (0x3fe978-0x3fe979) */
    uint16_t safety_bits_1;  /* Safety condition bits set 1 */
    uint16_t safety_bits_2;  /* Safety condition bits set 2 */
    uint16_t sensor_diag;  /* Sensor diagnostic flags */
    uint16_t lamp_status;  /* Fault lamp status (MIL/warning) */
    uint16_t emission_faults;  /* Emission-related fault flags */
    uint16_t reserved_10;  /* Gap (0x3fe984-0x3fe985) */
    uint16_t reserved_12;  /* Gap (0x3fe986-0x3fe987) */
    uint16_t system_faults;  /* System fault flags */
    uint16_t reserved_16;  /* Gap (0x3fe98a-0x3fe98f) */
    uint16_t reserved_18;  /* Gap */
    uint16_t reserved_1a;  /* Gap */
    uint16_t reserved_1c;  /* Gap */
    uint16_t severity_flags;  /* Fault severity flags */
    uint16_t comm_faults;  /* Communication fault flags */
    uint16_t engine_status;  /* Engine status flags */
    uint16_t pending_faults;  /* Fault pending flags */
    uint16_t reserved_28;  /* Gap (0x3fe99c-0x3fe9a1) */
    uint16_t protection_active;  /* Protection active flags */
} system_status_flags_t;

typedef struct {
    uint16_t current_value;  /* Current speed value */
    uint16_t reserved_02;  /* Gap (0xa3cc) */
    uint16_t reserved_04;  /* Gap (0xa3ce) */
    uint16_t reserved_06;  /* Gap (0xa3d0) */
    uint16_t lower_limit;  /* Speed lower limit */
    uint16_t limit_adjustment;  /* Speed limit adjustment factor */
    uint16_t reserved_0c;  /* Gap (0xa3d6) */
    uint16_t reserved_0e;  /* Gap (0xa3d8) */
    uint16_t target_setpoint;  /* Target speed setpoint */
    uint16_t adjustment_delta;  /* Speed adjustment delta */
    uint16_t lookup_result;  /* Speed table lookup result */
} speed_control_state_t;

typedef struct {
    uint16_t efficiency_filtered;  /* Throttle efficiency filtered value */
    uint16_t fuel_demand_final;  /* Final throttle-based fuel demand */
    uint16_t final_trim;  /* Final fuel trim value */
    uint16_t load_adjusted;  /* Load-adjusted fuel value */
    uint16_t load_based_trim;  /* Load-based fuel trim */
    uint16_t rpm_based_trim;  /* RPM-based fuel trim */
    uint16_t reserved_0c;  /* Gap (0xa3f6) */
    uint16_t rpm_conversion;  /* RPM to fuel conversion factor */
    uint16_t reserved_10;  /* Gap (0xa3fa) */
    uint16_t reserved_12;  /* Gap (0xa3fc) */
    uint16_t throttle_conversion;  /* Throttle to fuel conversion factor */
    uint16_t reserved_16;  /* Gap */
} throttle_fuel_trim_t;

typedef struct {
    uint16_t blend_mode;  /* Fuel blend mode selector */
    uint16_t reserved_02;  /* Gap (0xa496) */
    uint16_t reserved_04;  /* Gap (0xa498) */
    uint16_t reserved_06;  /* Gap (0xa49a) */
    uint16_t reserved_08;  /* Gap (0xa49c) */
    uint16_t blend_weight;  /* Fuel blend weight factor (0-100%) */
} fuel_blend_state_t;

typedef struct {
    uint16_t load_input;  /* Boost-based load input */
    uint16_t rpm_modifier;  /* RPM-based boost modifier */
    uint16_t lookup_result;  /* Boost table lookup result */
    uint16_t computed_value;  /* Computed boost pressure value */
    uint16_t pressure_ratio;  /* Boost pressure ratio */
    uint16_t reserved_0a;  /* Gap */
    uint16_t reserved_0c;  /* Gap */
    uint16_t reserved_0e;  /* Gap */
} boost_pressure_state_t;

typedef struct {
    uint16_t source_priority;  /* Limit source priority ranking */
    uint16_t source_active;  /* Currently active limit source ID */
    uint16_t limit_source;  /* Torque limit source selector */
    uint16_t fuel_minimum;  /* Minimum fuel limit from arbitration */
} torque_limit_arb_t;

typedef struct {
    uint16_t proportional_gain;  /* PID proportional gain value */
    uint16_t integral_term;  /* PID integral accumulator */
    uint16_t reserved_04;  /* Gap */
    uint16_t reserved_06;  /* Gap */
    uint16_t reserved_08;  /* Gap */
} governor_pid_t;

typedef struct {
    uint16_t thermal_lockout;  /* Thermal protection lockout flag */
    uint16_t load_lockout;  /* Load protection lockout flag */
    uint16_t rpm_lockout;  /* RPM protection lockout flag */
    uint16_t sensor_fault_active;  /* Sensor fault lockout flag */
    uint16_t reserved_08;  /* Gap (0xb124-0xb125) */
    uint16_t timer_expired;  /* Lockout timer expired flag */
} protection_lockout_t;

typedef struct {
    uint32_t id;  /* CAN identifier containing PGN priority and addressing info */
    uint16_t length;  /* Message data length for single/multi-frame decision */
} j1939_header_t;

typedef struct {
    uint32_t id;  /* 11-bit or 29-bit CAN ID stored in 32-bit */
    uint16_t length;  /* DLC (Data Length Code) */
    uint32_t data_ptr;  /* Pointer to payload bytes */
} can_std_rx_desc_t;

typedef struct {
    uint8_t error_code;  /* Error code (0=success non-zero=error) */
    uint16_t param_value;  /* Retrieved parameter value */
    uint8_t scaling_applied;  /* Flag indicating if scaling was applied */
    uint32_t timestamp;  /* Response generation timestamp */
} parameter_response_t;

typedef struct {
    uint8_t command_id;  /* CalTerm command identifier */
    uint8_t parameter_count;  /* Number of parameters in request/response */
    uint8_t data_payload[8];  /* Parameter data payload (up to 8 bytes) */
    uint8_t checksum;  /* Message integrity checksum */
} calterm_protocol_t;

typedef struct {
    uint8_t function_code;  /* Insite function code */
    uint8_t live_data_request;  /* Live data monitoring request flag */
    uint8_t status_flags;  /* Monitoring status flags */
    uint8_t response_data[6];  /* Live parameter response data */
} insite_protocol_t;

typedef struct {
    uint16_t current_index;  /* Current interpolation index into table */
    uint32_t x_axis_ptr;  /* Pointer to X-axis table (input values) */
    uint16_t input_value;  /* Input value for table lookup */
    uint32_t y_axis_ptr;  /* Pointer to Y-axis table (output values) */
} table_interp_args_t;

typedef struct {
    uint16_t integer_part;  /* High 16 bits - integer/whole number portion */
    uint16_t fractional_part;  /* Low 16 bits - fractional portion */
} q16_fixed_point_t;

typedef struct {
    uint32_t source_address;  /* DMA transfer source memory address */
    uint32_t dest_address;  /* DMA transfer destination memory address */
    uint16_t transfer_count;  /* Number of bytes/words to transfer */
    uint16_t control_flags;  /* DMA control flags (mode type enable etc) */
    uint32_t next_descriptor;  /* Pointer to next descriptor in chain */
} dma_descriptor_t;

typedef struct {
    uint32_t target_address;  /* Memory address to patch */
    uint8_t patch_size;  /* Number of bytes to copy to target address */
    uint8_t reserved;  /* Unused padding byte for 6-byte alignment */
} memory_patch_entry_t;

typedef struct {
    uint8_t pgn_byte_1;  /* First PGN byte for matching (compared against msg+6+1) */
    uint8_t pgn_byte_0;  /* Second PGN byte for matching (compared against msg+6+0) */
    uint32_t handler_func;  /* Function pointer to PGN handler callback */
} j1939_pgn_handler_entry_t;

typedef struct {
    uint8_t priority;  /* J1939 message priority (0-7) */
    uint8_t reserved_01;  /* Reserved/padding byte */
    uint8_t dest_address;  /* Destination address (0xFF=broadcast) */
    uint8_t source_address;  /* Source address of requester */
    uint16_t reserved_04;  /* Reserved/message flags */
    uint32_t pgn_data_ptr;  /* Pointer to PGN data bytes */
} j1939_request_msg_t;

typedef struct {
    uint8_t control_byte;  /* ACK control byte (0=ACK 1=NACK 2=AccessDenied 3=CannotRespond) */
    uint8_t group_function;  /* Group function value from original request */
    uint16_t reserved_02;  /* Reserved bytes 2-3 */
    uint8_t address_acknowledged;  /* Address being acknowledged */
    uint8_t pgn_low;  /* Acknowledged PGN low byte */
    uint8_t pgn_mid;  /* Acknowledged PGN mid byte */
    uint8_t pgn_high;  /* Acknowledged PGN high byte */
} j1939_ack_msg_t;

typedef struct {
    uint16_t value;  /* Parameter value (resolution varies per parameter) */
    uint16_t min_limit;  /* Minimum allowed value for parameter */
    uint16_t max_limit;  /* Maximum allowed value for parameter */
    uint16_t default_value;  /* Factory default value */
} eeprom_param_t;

typedef struct {
    uint32_t calculated_block;  /* Block × 256 × 4 calculation result */
    uint16_t offset;  /* Parameter offset within block */
    uint16_t result_value;  /* Retrieved parameter value (capped at 32000) */
} param_lookup_args_t;

typedef struct {
    uint8_t msg_id;  /* Message identifier */
    uint8_t param_1;  /* First parameter byte */
    uint8_t param_2;  /* Second parameter byte */
    uint8_t param_3;  /* Third parameter byte */
    uint8_t param_4;  /* Fourth parameter byte */
    uint16_t timestamp;  /* Message timestamp */
    uint8_t checksum;  /* Message checksum */
} can_param_msg_t;

typedef struct {
    uint32_t last_execution_time;  /* Timer value of last task execution */
    uint16_t runtime_ticks;  /* Task runtime duration in timer ticks */
    uint16_t deadline_ticks;  /* Task execution deadline (0xFFFF = disabled) */
    uint16_t execution_count;  /* Number of times task has been executed */
    uint16_t overrun_count;  /* Number of deadline overruns detected */
    uint32_t reserved;  /* Reserved/padding bytes for alignment */
} scheduler_phase_slot_t;

typedef struct {
    uint16_t channel_addr;  /* A/D channel address for sensor input */
    uint16_t filter_const;  /* Digital filter constant (0-1) */
    uint16_t fault_clear_count;  /* Fault clear counter threshold */
    uint16_t fault_decrement;  /* Fault counter decrement value */
    uint16_t fault_increment;  /* Fault counter increment value */
    uint16_t fault_set_threshold;  /* Fault set threshold */
    uint16_t high_error_limit;  /* A/D high error limit (0-1023) */
    uint16_t low_error_limit;  /* A/D low error limit (0-1023) */
} ad_sensor_config_t;

typedef struct {
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
} sensor_fault_config_t;

typedef struct {
    uint8_t reserved_00[8];  /* Reserved bytes at offset 0x00-0x07 */
    uint16_t interpolated_value;  /* Interpolated sensor value (offset 0x08) */
    uint16_t lookup_result;  /* Table lookup result (offset 0x0a) */
    uint16_t debounce_counter;  /* Current debounce count (offset 0x0c) */
    uint8_t fault_active_flag;  /* Fault currently active flag (offset 0x0e) */
    uint8_t sample_counter;  /* Sample phase counter (offset 0x0f) */
    uint16_t adc_raw_value;  /* Raw A/D conversion value (offset 0x10) */
    uint8_t reserved_12[4];  /* Reserved bytes at offset 0x12-0x15 */
} sensor_debounce_state_t;

typedef struct {
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
} cummins_data_plate_t;

typedef struct {
    uint32_t source_data_ptr;  /* Pointer to source data for memory operation */
    uint32_t target_data_ptr;  /* Pointer to destination memory location */
    uint16_t operation_size;  /* Number of bytes to copy (max varies) */
    uint16_t metadata_value;  /* Logging metadata/timestamp for circular buffer */
} memory_operation_request_t;

typedef struct {
    uint16_t source_addr_1;  /* J1939 source address 1 */
    uint16_t source_addr_2;  /* J1939 source address 2 */
    uint16_t source_addr_3;  /* J1939 source address 3 */
    uint16_t source_addr_4;  /* J1939 source address 4 */
    uint16_t source_addr_5;  /* J1939 source address 5 */
} j1939_source_addresses_t;

typedef struct {
    uint8_t type_switch_1;  /* Network type switch 1 (0=J1922 1=J1939) */
    uint8_t type_switch_2;  /* Network type switch 2 (0=J1922 1=J1939) */
    uint8_t type_switch_3;  /* Network type switch 3 (0=J1922 1=J1939) */
    uint8_t type_switch_4;  /* Network type switch 4 (0=J1922 1=J1939) */
    uint8_t type_switch_5;  /* Network type switch 5 (0=J1922 1=J1939) */
} network_type_switches_t;

typedef struct {
    uint16_t target_address;  /* Target memory address for transfer */
    uint32_t data_pointer;  /* Pointer to source/dest data buffer */
    uint16_t remaining_length;  /* Remaining bytes to transfer */
    uint16_t byte_count;  /* Total byte count for operation */
    uint8_t tx_active_flag;  /* Transmit operation active (0/1) */
    uint8_t rx_active_flag;  /* Receive operation active (0/1) */
} diag_transfer_state_t;

typedef struct {
    uint8_t message_length;  /* Total message length including header */
    uint8_t service_id;  /* Service identifier (3=secured 4=control 5=memory) */
    uint8_t sub_function;  /* Sub-function code for service routing */
    uint8_t data_payload[16];  /* Variable-length request data payload */
} diag_service_request_t;

typedef struct {
    uint16_t write_index;  /* Current write position (0-N) */
    uint16_t entry_count;  /* Number of entries in buffer */
    uint16_t read_index;  /* Current read position (0-N) */
    uint16_t buffer_size;  /* Maximum buffer capacity */
} circular_buffer_t;

typedef struct {
    uint32_t start_address;  /* Start of valid address range (big-endian) */
    uint32_t end_address;  /* End of valid address range (big-endian) */
    uint8_t special_mode_flag;  /* Access flag when in special mode (non-0x09/0x0A = allow) */
    uint8_t normal_mode_flag;  /* Access flag in normal operation (0x09=invalid 0x0A=denied other=allow) */
} address_range_entry_t;

typedef struct {
    uint16_t source_id;  /* ID of current fuel limit source (arbitrator output) */
    uint16_t demand_limited;  /* Rate-limited fuel demand */
    uint16_t arbitration_threshold;  /* Fuel limit arbitration threshold */
    uint16_t demand_delta;  /* Fuel demand delta for rate limiting */
    uint16_t maximum_limit;  /* Maximum fuel demand limit */
    uint16_t offset_value;  /* Fuel limit offset value */
    uint16_t comparison_low;  /* Fuel limit comparison low value */
    uint16_t comparison_high;  /* Fuel limit comparison high value */
    uint16_t rate_limit;  /* Fuel demand rate limiting value */
} fuel_limit_arbitration_t;

typedef struct {
    uint16_t fuel_demand_control;  /* Fuel demand mode control flags */
    uint16_t protection_system;  /* Protection system status flags */
    uint16_t engine_operating_state;  /* Engine operating state flags */
    uint16_t reserved_06;  /* Gap/reserved */
    uint16_t reserved_08;  /* Gap/reserved */
    uint16_t fuel_temp_control;  /* Fuel temp control bit flags */
} engine_control_flags_t;

typedef struct {
    uint16_t fault_flag;  /* High RPM protection fault active flag */
    uint16_t state;  /* State machine state */
    uint16_t timer;  /* Countdown timer */
    uint16_t reserved_06;  /* Reserved/gap */
    uint16_t warning_flag;  /* Warning active flag */
} high_rpm_protection_t;

typedef struct {
    uint32_t sensor_status_history_bits;  /* Sensor status history bits - shifting record */
    uint16_t rpm_ramp_complete;  /* Flag indicating RPM ramp complete */
    uint16_t rpm_limit_current;  /* Current RPM limit from oil pressure */
    uint16_t rpm_limit_target;  /* Target RPM limit for oil pressure */
    uint16_t rpm_limit_previous;  /* Previous RPM limit for tracking */
    uint16_t state_index;  /* State index for oil pressure protection */
    uint16_t validation_timer;  /* Timer for oil pressure validation */
    uint16_t sensor_validation_counter;  /* Sensor status validation counter */
} oil_pressure_protection_t;

typedef struct {
    uint8_t periodic_monitor_phase;  /* 5-phase counter for periodic fault monitoring */
    uint8_t can_pin_fault;  /* CAN pin switching fault persistence counter */
    uint8_t io_fault_1;  /* I/O control fault 1 persistence counter */
    uint8_t io_fault_2;  /* I/O control fault 2 persistence counter */
    uint8_t io_fault_3;  /* I/O control fault 3 persistence counter */
    uint8_t io_fault_4;  /* I/O control fault 4 persistence counter */
    uint8_t io_fault_5;  /* I/O control fault 5 persistence counter */
    uint8_t io_fault_6;  /* I/O control fault 6 persistence counter */
} fault_persistence_counters_t;

typedef struct {
    uint16_t sensor_fault_status;  /* Sensor fault status register */
    uint16_t fault_status_2;  /* Fault status flags register 2 */
    uint16_t engine_fault_status;  /* Engine fault status register */
    uint16_t reserved_06;  /* Reserved/gap */
    uint16_t io_fault_status_1;  /* IO fault status register 1 */
    uint16_t io_fault_status_2;  /* IO fault status register 2 */
    uint16_t io_fault_status_3;  /* IO fault status register 3 */
    uint16_t io_fault_status_4;  /* IO fault status register 4 */
} fault_status_registers_t;

typedef struct {
    uint16_t sensor_fault_latch;  /* Sensor fault latch register */
    uint16_t fault_status_8_previous;  /* Previous state for edge detection */
    uint16_t engine_fault_latch;  /* Engine fault latch register */
    uint16_t reserved_06;  /* Reserved/gap */
    uint16_t io_fault_latch_1;  /* IO fault latch register 1 */
    uint16_t io_fault_latch_2;  /* IO fault latch register 2 */
    uint16_t io_fault_latch_3;  /* IO fault latch register 3 */
    uint16_t io_fault_latch_4;  /* IO fault latch register 4 */
} fault_latch_registers_t;

typedef struct {
    uint16_t state;  /* Engine operating mode state 1-8 */
    uint16_t shutdown_complete_flag;  /* Engine shutdown complete flag */
} engine_operating_mode_t;

typedef struct {
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
} rpm_fuel_protection_t;

typedef struct {
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
} timing_mode_control_t;

typedef struct {
    uint16_t speed_previous;  /* Previous speed request value stored */
    uint8_t byte0_control_mode;  /* TSC1 byte 0: Engine Override Control Mode (bits 0-1=mode 2-3=speed_cond 4-5=coast) */
    uint16_t bytes12_requested_speed;  /* TSC1 bytes 1-2: Requested speed (0.125 RPM/bit little-endian) */
    uint8_t reserved_05;  /* Gap/reserved byte */
    uint8_t byte4_priority;  /* TSC1 byte 4: Override Control Mode Priority/Status */
    uint8_t reserved_07[3];  /* Gap/reserved bytes */
    uint8_t auxiliary_state;  /* TSC1 auxiliary state byte */
    uint8_t reserved_0b[9];  /* Gap/reserved bytes to offset 0x14 */
    uint8_t control_word;  /* TSC1 control word from message */
    uint16_t requested_speed;  /* TSC1 requested speed value (0.125 RPM/bit) */
    uint8_t requested_torque;  /* TSC1 requested torque percentage */
    uint8_t reserved_18[4];  /* Gap/reserved bytes */
    uint8_t priority_byte;  /* TSC1 message priority level */
    uint16_t speed_stored;  /* TSC1 requested speed stored for governor */
    uint8_t torque_stored;  /* TSC1 requested torque stored for governor */
} tsc1_message_t;

typedef struct {
    uint16_t mode3_speed_target;  /* TSC1 mode 3 requested speed target */
    uint16_t speed_setpoint;  /* TSC1 speed setpoint for torque calculation */
    uint16_t capped_speed_target;  /* TSC1 mode 1 speed target capped at 24000 (3000 RPM) */
    uint16_t control_flags;  /* TSC1 control flags */
    uint16_t mode3_torque_limit;  /* TSC1 mode 3 calculated torque limit */
    uint16_t torque_limit_calc;  /* Calculated torque limit from TSC1 request (signed) */
    uint16_t speed_control_mode;  /* Speed control mode bits extracted from TSC1 byte 0 */
    uint16_t active_state;  /* TSC1 active state (1=control active) */
    uint16_t reserved_10;  /* Reserved/gap at offset 0x10 */
    uint16_t mode_active;  /* TSC1 mode active flag (1=TSC1 control active) */
    uint16_t disable_override;  /* TSC1 disable override flag (1=disable 0=enable) */
    uint16_t handler_initialized;  /* TSC1 handler initialized flag */
    uint16_t speed_control_target;  /* Speed control target setpoint (0.125 RPM/bit) */
    uint8_t coast_brake_mode;  /* TSC1 coast/brake mode flag (from byte 0 bits 4-5) */
    uint8_t address_filter;  /* TSC1 source address filter value (0xFF=any) */
    uint8_t reserved_1c[10];  /* Gap to timer region */
    uint16_t torque_mode_timer;  /* TSC1 torque mode timeout counter */
    uint16_t torque_active_timer;  /* TSC1 torque active timeout counter */
    uint16_t speed_override_timer;  /* TSC1 speed override timeout counter */
    uint16_t torque_limit_timer;  /* TSC1 torque limit timeout counter */
    uint16_t speed_mode_flag;  /* TSC1 speed mode flag */
    uint16_t mode_timeout;  /* TSC1 mode timeout counter */
    uint16_t speed_cmd_timeout;  /* TSC1 speed command timeout counter */
    uint16_t override_timeout;  /* TSC1 override timeout counter */
    uint8_t reserved_36[3];  /* Gap to source address */
    uint8_t source_address;  /* TSC1 source address of current command */
    uint32_t config_entry_ptr;  /* Pointer to TSC1 configuration table entry */
    uint32_t active_config_ptr;  /* Pointer to active TSC1 configuration */
    uint32_t secondary_config_ptr;  /* Pointer to secondary TSC1 configuration */
    uint16_t torque_limit_active;  /* TSC1 torque limit mode active flag */
    uint16_t message_timeout;  /* TSC1 message timeout counter (lost message detection) */
} tsc1_state_t;

typedef struct {
    uint16_t tsc1_control_word;  /* TSC1 control word stored from message */
    uint16_t mode_request;  /* Governor mode request (GOVERNOR_MODE enum) */
    uint16_t mode;  /* Current governor mode (GOVERNOR_MODE enum) */
    uint16_t torque_limit_select;  /* Torque limit mode selection (0=off 1=active) */
    uint16_t disable_control;  /* TSC1 disable control flag */
    uint32_t limit_state;  /* TSC1 limit state (low=torque_limit high=speed_limit) */
} governor_control_t;

typedef struct {
    uint16_t param_id;  /* Parameter ID (0x0000-0x12A9 for CM848) */
    uint32_t address;  /* Resolved memory address (EEPROM/ROM/MPC555 regs) */
} param_id_entry_t;

typedef struct {
    uint8_t service_id;  /* EF00 service ID (see EF00_SERVICE_ID enum) */
    uint8_t reserved;  /* Padding byte */
    uint32_t handler_ptr;  /* Function pointer to service handler */
} ef00_dispatch_entry_t;

typedef struct {
    uint8_t service_id;  /* Diagnostic service ID (0x43=paramRead 0x4A=memRead 0x4C=memReadExt) */
    uint32_t handler_ptr;  /* Function pointer to service handler */
} diag_dispatch_entry_t;

typedef struct {
    uint32_t total_ticks;  /* Cumulative execution time in timer ticks */
    uint16_t call_count;  /* Number of times task has been executed */
    uint16_t min_time;  /* Minimum execution time (initialized to 0xFFFF) */
    uint16_t max_time;  /* Maximum execution time observed */
    uint16_t overrun_count;  /* Number of deadline overruns detected */
} scheduler_task_stat_t;

typedef struct {
    uint16_t derivative_term;  /* Governor derivative term bitmask (0xFFFF=inactive) */
    uint16_t channel_identifier;  /* Channel ID for matching incoming governor commands */
    uint16_t gain_schedule;  /* Gain schedule countdown timer (0=expired) */
} governor_channel_t;

typedef struct {
    uint16_t threshold_scaled;  /* Scaled protection threshold from table lookup */
    uint16_t recovery_threshold;  /* Recovery/hysteresis exit threshold */
    uint16_t hysteresis;  /* Protection hysteresis band value */
    uint16_t threshold_scaled_alt;  /* Alternate scaled threshold (same input different context) */
    uint16_t threshold_base;  /* Base protection threshold before correction */
} protection_threshold_set_t;

typedef struct {
    uint32_t timing_snapshot;  /* Fuel timing advance value at capture time */
    uint8_t fault_code;  /* Fault code ID (0xAA = empty/available slot) */
    uint16_t temperature_trim;  /* Temperature compensation trim calculation */
    uint16_t target_rpm;  /* Target engine RPM at fault time */
    uint16_t sensor_scale_1;  /* Sensor scale factor 1 */
    uint16_t fault_status;  /* Fault active status value at capture */
    uint16_t protection_high;  /* Protection output high word */
    uint16_t protection_low;  /* Protection output low word */
    uint16_t timing_param_1;  /* Fuel timing parameter 1 */
    uint16_t timing_param_2;  /* Fuel timing parameter 2 */
    uint16_t timing_param_3;  /* Fuel timing parameter 3 */
    uint16_t sensor_scale_2;  /* Sensor scale factor 2 */
    uint32_t reserved;  /* Reserved gap (not written by set/capture functions) */
    uint8_t pressure_adj;  /* Pressure fuel adjustment byte */
    uint16_t battery_voltage;  /* Battery voltage reading at fault time */
    uint16_t load_throttle;  /* Processed load/throttle value */
    uint16_t torque_limit;  /* Torque limit factor at fault time */
    uint16_t diagnostic_word_1;  /* Diagnostic data word 1 */
    uint8_t diagnostic_byte_3;  /* Diagnostic data byte 3 */
    uint8_t diagnostic_byte_4;  /* Diagnostic data byte 4 */
    uint16_t diagnostic_word_2;  /* Diagnostic data word 2 */
    uint16_t diagnostic_word_3;  /* Diagnostic data word 3 */
    uint16_t coolant_temp_raw;  /* Coolant temperature raw sensor value */
    uint16_t status_flags;  /* Fault entry status/severity flags (bit 0 = newly active) */
} fault_entry_t;


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
    MODE_STOP = 0x00,  /* Engine stopped / key on state */
    MODE_TRANSITION = 0x02,  /* Engine state transition */
    MODE_RUN = 0x07,  /* Engine running / normal operation */
    MODE_CRANK = 0x1e,  /* Engine cranking / starting (30 decimal) */
    MODE_SHUTDOWN = 0x25  /* Engine shutdown sequence (37 decimal) */
} ENGINE_OPERATING_MODE;

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
    HANDLER_GOVERNOR_CONTROL = 0xdf00,  /* Governor control message (TSC1) */
    HANDLER_DM1_REQUEST = 0xe300,  /* DM1 active fault request handler */
    HANDLER_DIAGNOSTIC_SERVICE = 0xef00,  /* Diagnostic service handler (DM14) */
    HANDLER_TORQUE_SPEED_CONTROL = 0xf002,  /* Torque/Speed Control (TSC1 PGN 0) */
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
    FUELMODE_DISABLED = 0,  /* Fuel control disabled/idle */
    FUELMODE_BASE = 1,  /* Base fuel control mode */
    FUELMODE_LIMIT_A = 2,  /* Fuel limit source A (calibration) */
    FUELMODE_LIMIT_B = 3,  /* Fuel limit source B (governor) */
    FUELMODE_LIMIT_C = 4,  /* Fuel limit source C (protection) */
    FUELMODE_OVERRIDE = 5  /* Fuel override/diagnostic mode */
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
    SECURITY_FAILED = 0x03,  /* Security validator - security check returned non-zero */
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
    MEMORY_PATCH = 0x51,  /* Apply queued memory patches */
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
    QUERY_TERMINATE = 0x01,  /* QueryTerminate - CLIP compatible */
    SYSTEM_SERVICE_04 = 0x04,  /* System service 04 */
    SYSTEM_SERVICE_05 = 0x05,  /* System service 05 */
    SYSTEM_SERVICE_06 = 0x06,  /* High RPM shutdown activation */
    SYSTEM_SERVICE_07 = 0x07,  /* System service 07 */
    SYSTEM_SERVICE_0A = 0x0A,  /* System service 0A */
    SYSTEM_SERVICE_0B = 0x0B,  /* System service 0B */
    GET_PARAMETERS_BY_ID_ALT = 0x0F,  /* GetParametersByID alternate */
    GET_PARAMETERS_BY_ID = 0x10,  /* GetParametersByID - CLIP compatible */
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
    TSC1_RECEIVE_ENABLE = 1,  /* TSC1 message reception enable */
    J1939_MESSAGE_FLAGS = 2,  /* J1939 message enable flags table */
    ASG_THROTTLE_COEFF_1 = 3,  /* ASG throttle mode compensation filter coef 1 */
    ASG_THROTTLE_COEFF_2 = 4,  /* ASG throttle mode compensation filter coef 2 */
    ASG_THROTTLE_COEFF_3 = 5  /* ASG throttle mode compensation filter coef 3 */
} J1939_THROTTLE_ENABLE;

typedef enum {
    DISABLE_OVERRIDE = 0,  /* Disable speed/torque override - return to pedal control */
    SPEED_CONTROL = 1,  /* Speed control mode - target engine speed */
    TORQUE_CONTROL = 2,  /* Torque control mode - limit engine torque */
    SPEED_TORQUE_LIMIT = 3  /* Speed/torque limit mode - apply both limits */
} TSC1_ENGINE_CONTROL_MODE;

typedef enum {
    NO_SPEED_CONDITION = 0,  /* No speed condition - use requested speed directly */
    APPLY_AS_LIMIT = 1,  /* Apply requested speed as upper limit only */
    NOT_AVAILABLE = 2,  /* Speed condition not available */
    DONT_CARE = 3  /* Speed condition don't care */
} TSC1_SPEED_CONDITION;

typedef enum {
    NO_COAST_BRAKE = 0,  /* No coast/brake override active */
    COAST_DECEL = 1,  /* Coast deceleration mode active */
    ENGINE_BRAKE = 2,  /* Engine brake / exhaust brake active */
    RESERVED = 3  /* Reserved coast/brake mode */
} TSC1_COAST_BRAKE_MODE;

typedef enum {
    GOV_DISABLED = 0,  /* Governor control disabled - pedal/throttle control */
    GOV_SPEED_CONTROL = 1,  /* Speed control mode - maintain target RPM */
    GOV_TORQUE_CONTROL = 2,  /* Torque control mode - limit engine torque */
    GOV_SPEED_TORQUE = 3  /* Combined speed and torque control mode */
} GOVERNOR_MODE;

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
    ACTIVE_FAULT_LIST = 0xC1,  /* Active DTC list builder */
    FAULT_DETAIL = 0xC2,  /* Detailed fault information builder */
    PID_DTC_REQUEST = 0xC3,  /* PID/DTC handler request */
    PID_DTC_RESPONSE = 0xC4,  /* PID/DTC response - response length 4 or 7 */
    CAPACITY_INFO = 0xEA,  /* Capacity response builder - 24 bytes */
    ECU_ID = 0xED,  /* ECU identification builder */
    VERSION_INFO = 0xF3  /* Version info builder - 31 bytes */
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
    SUCCESS = 0x00,  /* Memory operation completed successfully */
    INVALID_LENGTH = 0x02,  /* Message length mismatch */
    AUTH_FAILED = 0x03,  /* Security check returned non-zero */
    LOGGING_STATE_ERROR = 0x07,  /* EEPROM write blocked - logging state check failed */
    WRITE_DENIED = 0x0A,  /* ROM/Flash region - write not permitted */
    BUFFER_WRITE_FAIL = 0x0B,  /* Circular buffer write error during EEPROM logging */
    AUTH_REQUIRED_MISSING = 0x1A  /* EEPROM write requires auth but not provided */
} MEMORY_OP_RESULT;

typedef enum {
    AUTH_SUCCESS = 0x00,  /* Security check passed - operation authorized */
    SECURITY_INVALID_LENGTH = 0x02,  /* Invalid message length for service */
    AUTH_FAILED = 0x03,  /* Security check failed - access denied */
    CONDITION_NOT_MET = 0x07,  /* Pre-condition not satisfied */
    INVALID_ADDR = 0x0A,  /* Invalid memory address range */
    BUFFER_WRITE_FAIL = 0x0B,  /* Circular buffer write failed */
    PROCEED_TO_HANDLER = 0xFF  /* Proceed to handler (auth passed or not required) */
} SECURITY_RESULT;

typedef enum {
    BYPASS_ENABLED = 0xB522,  /* Magic value to bypass security checks */
    LEGACY_BYPASS = 0x00FF  /* Legacy security bypass value */
} SECURITY_BYPASS;

typedef enum {
    BYPASS_ENABLED = 0xFF,  /* Security checks completely bypassed */
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
    PROTECTION_OVERRIDE = 5  /* Protection/override state - init and fault recovery */
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
    RETARDER_DISABLED = 0,  /* Retarder control disabled */
    RETARDER_SPEED_SYNC = 1,  /* Speed synchronization mode */
    RETARDER_LOAD_BASED = 2,  /* Load-based retard mode */
    RETARDER_PROPORTIONAL = 3  /* Proportional control mode */
} RETARDER_MODE_STATE;

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
