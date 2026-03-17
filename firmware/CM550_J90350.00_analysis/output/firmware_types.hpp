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
    uint32_t id;  /* CAN identifier containing PGN and addressing info */
    uint16_t length;  /* Message data length for single/multi-frame decision */
} j1939_header_t;

typedef struct {
    uint32_t id;  /* 11-bit CAN ID stored in 32-bit (ABI) */
    uint16_t length;  /* DLC */
    uint8_t * data_ptr;  /* Pointer to payload bytes */
} can_std_rx_desc_t;

typedef struct {
    uint32_t calculated_block;  /* Block x 256 x 4 calculation result */
    uint16_t offset;  /* Parameter offset within block */
    uint16_t result_value;  /* Retrieved parameter value (capped at 32000) */
} param_lookup_args_t;

typedef struct {
    uint16_t current_index;  /* Current interpolation index into table */
    uint32_t x_axis_ptr;  /* Pointer to X-axis table (input values) */
    uint16_t input_value;  /* Input value for table lookup */
    uint32_t y_axis_ptr;  /* Pointer to Y-axis table (output values) */
} table_interp_args_t;

typedef struct {
    uint32_t source_address;  /* DMA transfer source memory address */
    uint32_t dest_address;  /* DMA transfer destination memory address */
    uint16_t transfer_count;  /* Number of bytes/words to transfer */
    uint16_t control_flags;  /* DMA control flags (mode type enable etc) */
    uint32_t next_descriptor;  /* Pointer to next descriptor in chain */
} dma_descriptor_t;

typedef struct {
    uint32_t source_data_ptr;  /* Pointer to source data for memory operation */
    uint32_t target_data_ptr;  /* Pointer to destination memory location */
    uint16_t operation_size;  /* Number of bytes to copy (max 1764 bytes) */
    uint16_t metadata_value;  /* Logging metadata/timestamp for circular buffer */
} memory_operation_request_t;

typedef struct {
    uint16_t integer_part;  /* High 16 bits - integer/whole number portion */
    uint16_t fractional_part;  /* Low 16 bits - fractional portion */
} q16_fixed_point_t;

typedef struct {
    uint16_t value;  /* Primary 16-bit value (used for division) */
    uint16_t limit;  /* Secondary 16-bit limit/clamp value */
} division_operand_t;

typedef struct {
    uint8_t lo;  /* Low byte at offset 0 */
    uint8_t hi;  /* High byte at offset 1 */
    uint8_t lo;  /* qsm_sci_data_reg - QSM SCI data register */
    uint8_t hi;  /* qsm_sci_data_reg - QSM SCI data register */
    uint8_t lo;  /* sim_ddir - SIM port I data direction */
    uint8_t hi;  /* sim_ddir - SIM port I data direction */
    uint8_t lo;  /* sim_ddrd - SIM port D data direction */
    uint8_t hi;  /* sim_ddrd - SIM port D data direction */
    uint8_t lo;  /* sim_csor1 - SIM chip select option register 1 */
    uint8_t hi;  /* sim_csor1 - SIM chip select option register 1 */
    uint8_t lo;  /* tpu_cpr1 - TPU channel priority register 1 */
    uint8_t hi;  /* tpu_cpr1 - TPU channel priority register 1 */
    uint8_t lo;  /* TPU_PRAM_CH0_0 - TPU parameter RAM channel 0 */
    uint8_t hi;  /* TPU_PRAM_CH0_0 - TPU parameter RAM channel 0 */
} mc68336_reg16_t;

typedef struct {
    uint16_t timer_count;  /* Timer counter value (offset 0) */
    uint16_t reserved_02;  /* Reserved (offset 2) */
    uint16_t timer_config;  /* Timer configuration (offset 4) */
    uint16_t reserved_06;  /* Reserved (offset 6) */
    uint32_t reserved_08;  /* Reserved (offset 8-11) */
    uint16_t timer_compare;  /* Timer compare value (offset 12) */
    uint16_t reserved_14;  /* Reserved (offset 14) */
    uint16_t timer_capture;  /* Timer capture value (offset 16) */
    uint16_t reserved_18;  /* Reserved (offset 18) */
    uint16_t timer_status;  /* Timer status register (offset 20) */
    uint32_t timer_control;  /* Timer control value (offset 22) */
    uint16_t timer_count;  /* hardware_timer_register - SIM timer block */
} sim_timer_block_t;

typedef struct {
    uint8_t control_lo;  /* TPU DSCR control low byte (offset 0) */
    uint8_t control_hi;  /* TPU DSCR control high byte (offset 1) */
    uint16_t reserved_02;  /* Reserved (offset 2) */
    uint16_t dscr_config;  /* DSCR configuration (offset 4) */
    uint16_t dscr_status;  /* DSCR status register (offset 6) */
    uint16_t dscr_data;  /* DSCR data register (offset 8) */
    uint16_t dscr_addr;  /* DSCR address register (offset 10) */
    uint8_t control_lo;  /* tpu_dscr - TPU DSCR block */
} tpu_dscr_block_t;

typedef struct {
    uint8_t hsqr0_lo;  /* TPU host sequence register 0 low (offset 0) */
    uint8_t hsqr0_hi;  /* TPU host sequence register 0 high (offset 1) */
    uint8_t hsqr1_lo;  /* TPU host sequence register 1 low (offset 2) */
    uint8_t hsqr1_hi;  /* TPU host sequence register 1 high (offset 3) */
    uint16_t hsq_config;  /* HSQ configuration (offset 4) */
    uint16_t hsq_status;  /* HSQ status register (offset 6) */
    uint16_t hsq_data;  /* HSQ data register (offset 8) */
    uint8_t hsqr0_lo;  /* tpu_hsqr0 - TPU HSQ block */
} tpu_hsq_block_t;

typedef struct {
    uint8_t status;  /* Serial port status register (offset 0) */
    uint8_t config;  /* Serial port configuration (offset 1) */
    uint8_t data;  /* Serial port data register (offset 2) */
    uint8_t reserved;  /* Reserved (offset 3) */
    uint8_t status;  /* serial_port_1_base_register - QSM serial port */
} serial_port_regs_t;

typedef struct {
    uint16_t reserved_00;  /* Reserved/padding at offset 0x00 */
    uint16_t default_value;  /* Default sensor value on fault */
    uint16_t clear_threshold;  /* Threshold for fault clear */
    uint16_t decrement_value;  /* Debounce counter decrement */
    uint16_t increment_value;  /* Debounce counter increment */
    uint16_t set_threshold;  /* Threshold for fault set */
    uint16_t high_limit;  /* High error limit */
    uint16_t low_limit;  /* Low error limit */
    uint16_t adc_lookup_index;  /* A/D channel lookup table index */
    uint8_t reserved_12;  /* Reserved byte */
    uint8_t alt_fault_enable;  /* Alternative fault enable flag */
    uint8_t primary_fault_id;  /* Primary fault code */
    uint8_t secondary_fault_id;  /* Secondary fault code */
    uint8_t tertiary_fault_id;  /* Tertiary fault code */
    uint8_t debounce_max;  /* Maximum debounce count */
} sensor_fault_config_t;

typedef struct {
    uint8_t reserved_00[8];  /* Reserved bytes at offset 0x00-0x07 */
    uint16_t interpolated_value;  /* Interpolated sensor value */
    uint16_t lookup_result;  /* Table lookup result */
    uint16_t debounce_counter;  /* Current debounce count */
    uint8_t fault_active_flag;  /* Fault currently active flag */
    uint8_t sample_counter;  /* Sample phase counter */
    uint16_t adc_raw_value;  /* Raw A/D conversion value */
    uint8_t reserved_12[4];  /* Reserved bytes at offset 0x12-0x15 */
} sensor_debounce_state_t;

typedef struct {
    uint16_t data_plt_module_id;  /* Module identifier (EN=0x454E for CM550/VP44 ECUs) */
} cummins_data_plate_header_t;

typedef struct {
    uint16_t cm550_data_plate_offset;  /* CM550 data plate offset (0x2C0) */
    uint16_t vp44_data_plate_offset;  /* VP44 data plate offset (0x2C0-0x22=0x29E) */
    uint8_t incal_variant_code;  /* InCal calibration variant (A/B/C) */
} module_variant_offsets_t;

typedef struct {
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
} cummins_data_plate_t;

typedef struct {
    uint8_t response_buffer;  /* VP44 response buffer byte */
    uint8_t sequence_number;  /* VP44 message sequence number for retry logic */
    uint16_t message_id;  /* VP44 message identifier */
    uint8_t retry_flag;  /* VP44 retry flag (1 when response pending) */
    uint8_t retry_count;  /* VP44 actual retry count (max 5) */
    uint8_t timeout_counter;  /* VP44 timeout countdown (112 ticks) */
    uint32_t message_data;  /* VP44 stored command/data */
} vp44_message_t;

typedef struct {
    uint8_t data[8];  /* J1939 message payload data array */
    j1939_header_t header;  /* CAN message header (ID + length) */
} j1939_tx_msg_buffer_t;

typedef struct {
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
} j1939_vp44_msg_t;

typedef struct {
    uint8_t service_id;  /* Current diagnostic service ID */
    uint8_t sub_function;  /* Sub-function code */
    uint16_t session_state;  /* Diagnostic session state machine */
    uint16_t timeout_counter;  /* Session timeout countdown */
    uint8_t data_buffer[32];  /* Multi-purpose diagnostic data buffer */
} diagnostic_mode_buffer_t;

typedef struct {
    uint16_t mode_state;  /* VP44 diagnostic mode state machine */
    uint32_t command_data;  /* VP44 diagnostic command data */
    uint16_t response_status;  /* VP44 diagnostic response status */
} vp44_diagnostic_mode_t;

typedef struct {
    uint16_t fuel_adjustment;  /* Diagnostic mode fuel adjustment value */
    uint16_t boost_state;  /* Diagnostic mode boost state */
    uint16_t fuel_state;  /* Diagnostic mode fuel state */
    uint16_t vp44_state_2;  /* VP44 diagnostic state secondary */
} diagnostic_mode_fuel_t;

typedef struct {
    uint8_t message_length;  /* Total message length including header */
    uint8_t service_id;  /* Service identifier (3=secured 4=control 5=memory) */
    uint8_t sub_function;  /* Sub-function code for service routing */
    uint8_t data_payload[16];  /* Variable-length request data payload */
} diag_service_request_t;

typedef struct {
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
} diag_tp_state_t;

typedef struct {
    uint16_t target_address;  /* Target memory address for transfer */
    uint32_t data_pointer;  /* Pointer to source/dest data buffer */
    uint16_t remaining_length;  /* Remaining bytes to transfer */
    uint16_t byte_count;  /* Total byte count for operation */
    uint8_t tx_active_flag;  /* Transmit operation active (0/1) */
    uint8_t rx_active_flag;  /* Receive operation active (0/1) */
} diag_transfer_state_t;

typedef struct {
    int16_t out_cmd;  /* Final clamped output (governor/fueling command) */
    int16_t cmd_raw;  /* Current raw command (signed) */
    int16_t term_ff;  /* Feed-forward/scaling term (signed) */
    int16_t term_rate;  /* Rate/derivative term (signed saturating) */
    ushort accum_lo;  /* Q16.16 accumulator low 16 bits (fractional part) */
    ushort accum_hi;  /* Q16.16 accumulator high 16 bits (integer part) */
    int16_t limit_hi;  /* Accumulator integer ceiling (upper clamp) */
    int16_t limit_cap;  /* Accumulator/output cap */
    int16_t rpm_window;  /* RPM window/threshold term used for gating */
} fuel_governor_state_t;

typedef struct {
    uint16_t command;  /* Current fuel demand value */
    uint8_t source_identifier;  /* Source of fuel command (FUEL_SOURCE_ID enum) */
    uint8_t reserved_03;  /* Padding byte */
    uint16_t diagnostic_buffer;  /* Diagnostic parameter buffer */
    uint16_t timing_blend_factor;  /* Fuel timing blend factor 0-16384 */
    uint16_t table_output;  /* Fuel demand table output */
    uint16_t limit_minimum;  /* Fuel limit minimum value */
    uint16_t demand_source_id;  /* Fuel demand source identifier */
    uint16_t adjustment_active;  /* Fuel adjustment active flag */
} fuel_demand_state_t;

typedef struct {
    uint16_t source_id;  /* ID of current fuel limit source */
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
    uint16_t fuel_value;  /* Current minimum fuel limit value selected by arbitration */
    uint16_t init_value;  /* Shutdown minimum init value */
    uint16_t source_id;  /* Source ID that set minimum (17=selector17 etc) */
    uint16_t previous_value;  /* Previous minimum value for change tracking */
} shutdown_minimum_selector_t;

typedef struct {
    uint16_t control_mode;  /* Fuel arbitrator control mode */
    uint16_t response_timer;  /* Response timeout timer */
    uint16_t status_counter;  /* Status update counter */
    uint16_t speed_timer;  /* Speed control timer */
    uint16_t status_timer;  /* Status timer */
    uint16_t session_timer;  /* Diagnostic session timer */
    uint16_t session_counter;  /* Session counter */
    uint16_t throttle_override;  /* Throttle override value */
} fuel_arbitrator_diag_t;

typedef struct {
    uint16_t rpm_period_value;  /* Engine RPM period measurement from EPS */
    uint16_t current_engine_rpm;  /* Current calculated engine RPM (primary) */
    uint16_t cranking_threshold;  /* Engine RPM cranking detection threshold */
} engine_rpm_buffer_t;

typedef struct {
    uint16_t previous_engine_rpm;  /* Previous RPM sample for delta calculations */
    uint16_t previous_nonzero;  /* Previous non-zero RPM value */
    uint16_t previous_sample;  /* Previous RPM sample for rate of change */
    uint16_t rpm_delta;  /* RPM change between samples */
} engine_rpm_history_t;

typedef struct {
    uint16_t target_engine_rpm;  /* Commanded/target engine RPM */
} engine_rpm_target_t;

typedef struct {
    uint16_t eps_previous_engine_rpm;  /* EPS-calculated previous engine RPM */
    uint16_t eps_diagnostic_mode_counter;  /* EPS diagnostic mode counter */
    uint16_t snapshot_engine_rpm;  /* Snapshot of engine RPM at event */
} eps_rpm_snapshot_t;

typedef struct {
    uint16_t state;  /* Engine operating mode state 1-8 */
    uint16_t shutdown_complete_flag;  /* Engine shutdown complete flag */
} engine_operating_mode_t;

typedef struct {
    uint16_t fault_flag;  /* High RPM protection fault active flag */
    uint16_t state;  /* State machine state */
    uint16_t timer;  /* Countdown timer */
    uint16_t reserved_06;  /* Reserved/gap */
    uint16_t warning_flag;  /* Warning active flag */
} high_rpm_protection_t;

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
    uint16_t fault_status;  /* VP44 fault status register */
    uint16_t fso_fault_status;  /* VP44 FSO fault status register 2 */
} vp44_fault_state_t;

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
    uint16_t reserved_14;  /* Gap/reserved */
    uint16_t reserved_16;  /* Gap/reserved */
    uint16_t blend_accumulator;  /* Timing blend accumulator */
    uint16_t reserved_1A;  /* Gap/reserved */
    uint16_t fuel_source_mode_11_state;  /* Fuel source mode 11 state */
    uint16_t fuel_source_mode_11_timer;  /* Fuel source mode 11 timer */
    uint16_t fuel_mode_transition_state;  /* Fuel mode transition state */
    uint16_t fuel_mode_transition_timer;  /* Fuel mode transition timer */
} timing_mode_control_t;

typedef struct {
    uint32_t last_execution_time;  /* Timer value of last task execution */
    uint16_t runtime_ticks;  /* Task runtime duration in timer ticks */
    uint16_t deadline_ticks;  /* Task execution deadline (0xFFFF = disabled) */
    uint16_t execution_count;  /* Number of times task has been executed */
    uint16_t overrun_count;  /* Number of deadline overruns detected */
    uint32_t reserved;  /* Reserved/padding bytes for alignment */
} scheduler_phase_slot_t;

typedef struct {
    scheduler_phase_slot_t[] slots;  /* Array of phase slots - size depends on scheduler_phase_slot_count */
} scheduler_phase_table_t;

typedef struct {
    uint16_t overrun_counter;  /* Count of scheduler overruns detected */
    uint16_t wait_loop_counter;  /* Wait loop iteration counter */
    uint16_t wait_loop_limit;  /* Maximum wait loop iterations */
    uint16_t wait_loop_index;  /* Current wait loop index */
    uint16_t phase_slot_count;  /* Number of scheduler phase slots */
    uint16_t phase_timeout;  /* Phase execution timeout value */
    uint16_t overrun_threshold;  /* Overrun detection threshold */
    uint16_t tick_interval;  /* Scheduler tick interval */
} scheduler_control_t;

typedef struct {
    uint32_t engine_position_sensor_isr;  /* EPS position sensor ISR handler */
    uint32_t tpu_adc_isr;  /* TPU/QADC interrupt handler */
    uint32_t main_loop_callback;  /* Main scheduler loop callback */
} system_callback_table_t;

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
    uint32_t start_address;  /* Start of valid address range (big-endian) */
    uint32_t end_address;  /* End of valid address range (big-endian) */
    uint8_t special_mode_flag;  /* Access flag when water_in_fuel_detection_flag==1 */
    uint8_t normal_mode_flag;  /* Access flag in normal operation */
} address_range_entry_t;

typedef struct {
    uint32_t read_ptr;  /* Current read position pointer */
    uint32_t write_ptr;  /* Current write position pointer */
    uint32_t base_ptr;  /* Start address of buffer data */
    uint32_t end_ptr;  /* End address of buffer data */
    uint8_t full_flag;  /* Buffer full indicator (1=full 0=space available) */
} circular_buffer_control_t;

typedef struct {
    uint8_t metadata[1024];  /* Buffer metadata storage area */
    uint8_t data[512];  /* Actual circular buffer data storage */
    uint16_t read_index;  /* Current read index into buffer */
    uint16_t write_index;  /* Current write index into buffer */
    uint16_t count;  /* Number of entries in buffer */
    uint16_t current_value;  /* Most recent parameter value */
} param_circular_buffer_t;

typedef struct {
    uint16_t offset;  /* Current offset into QADC buffer */
    uint32_t dest_ptr;  /* Destination pointer for QADC data */
} qadc_circular_buffer_t;

typedef struct {
    uint16_t frequency;  /* Symbol frequency or combined weight */
    uint16_t left_child;  /* Index of left child node (0-512) */
    uint16_t right_child;  /* Index of right child node (0-512) */
} huffman_tree_node_t;

typedef struct {
    huffman_tree_node_t nodes;  /* Array of 513 tree nodes (256 leaves + 257 internal) */
    uint16_t root_marker;  /* Root node marker at offset 0x600 */
    uint16_t terminator;  /* Tree terminator at offset 0xC06 (set to 0xFFFF) */
} huffman_tree_t;

typedef struct {
    uint32_t buffer_ptr;  /* Current transmit buffer pointer */
    uint32_t buffer_2;  /* Secondary transmit buffer pointer */
    uint32_t buffer_end;  /* End of transmit buffer */
    uint8_t buffer_full_flag;  /* Transmit buffer full flag (1=full 0=empty) */
    uint8_t buffer_reserved;  /* Reserved/unused byte */
} j1708_tx_state_t;

typedef struct {
    uint32_t buffer_ptr_1;  /* Receive buffer pointer 1 */
    uint32_t buffer_ptr_2;  /* Receive buffer pointer 2 */
    uint32_t buffer_ptr_3;  /* Receive buffer pointer 3 (current position) */
    uint8_t buffer_full_flag;  /* Receive buffer full flag (1=full 0=empty) */
    uint8_t buffer_reserved;  /* Reserved/unused byte */
} j1708_rx_state_t;

typedef struct {
    uint32_t base_ptr;  /* Base pointer (offset 0) */
    uint8_t reserved_04[12];  /* Reserved bytes 4-15 */
    uint16_t length_16;  /* Length field at offset 16 */
    uint32_t data_ptr_18;  /* Data pointer at offset 18 */
    uint16_t count_22;  /* Count field at offset 22 */
    uint16_t field_24;  /* Field at offset 24 */
    uint16_t field_26;  /* Field at offset 26 */
    uint8_t reserved_28[8];  /* Reserved bytes 28-35 */
    uint32_t write_ptr;  /* Write pointer at offset 36 (100 uses) */
    uint32_t next_ptr;  /* Next pointer at offset 40 */
    uint32_t segment_ptr;  /* Segment pointer at offset 44 */
    uint8_t reserved_48[4];  /* Reserved bytes 48-51 */
    uint32_t buffer_ptr;  /* Buffer pointer at offset 52 */
    uint8_t reserved_56[32];  /* Reserved bytes 56-87 */
    uint32_t end_ptr;  /* End pointer at offset 88 */
    uint8_t reserved_92[10];  /* Reserved bytes 92-101 */
    uint16_t status_102;  /* Status field at offset 102 */
    uint16_t index_104;  /* Index field at offset 104 */
    uint16_t count_106;  /* Count field at offset 106 */
    uint32_t ctrl_ptr;  /* Control pointer at offset 108 */
    uint8_t reserved_112[10];  /* Reserved bytes 112-121 */
    uint32_t state_ptr;  /* State pointer at offset 122 */
    uint8_t reserved_126[16];  /* Reserved bytes 126-141 */
    uint32_t msg_ptr;  /* Message pointer at offset 142 */
    uint8_t reserved_146[8];  /* Reserved bytes 146-153 */
    uint16_t param_154;  /* Parameter at offset 154 */
    uint16_t param_156;  /* Parameter at offset 156 */
    uint16_t param_158;  /* Parameter at offset 158 */
    uint16_t param_160;  /* Parameter at offset 160 */
    uint16_t param_162;  /* Parameter at offset 162 */
    uint16_t param_164;  /* Parameter at offset 164 */
    uint8_t reserved_166[8];  /* Reserved bytes 166-173 */
    uint16_t param_174;  /* Parameter at offset 174 */
    uint16_t param_176;  /* Parameter at offset 176 */
    uint16_t param_178;  /* Parameter at offset 178 */
    uint16_t param_180;  /* Parameter at offset 180 */
    uint8_t tail_data[74];  /* Remaining data bytes 182-255 */
    uint32_t base_ptr;  /* J1708 transmit message buffer */
} j1708_multipacket_msg_t;

typedef struct {
    uint8_t rx_data[256];  /* J1708 receive data buffer */
} j1708_rx_buffer_t;

typedef struct {
    uint8_t tx_buffer_base[256];  /* Diagnostic transmit buffer (256 bytes) */
    uint8_t rx_buffer_base[256];  /* Diagnostic receive buffer (256 bytes) */
} diagnostic_buffers_t;

typedef struct {
    uint32_t tx_start_ptr;  /* Pointer to start of TX buffer */
    uint32_t rx_start_ptr;  /* Pointer to start of RX buffer */
    uint32_t end_address;  /* End address of diagnostic buffers */
    uint8_t logger_state;  /* CAN buffer logger state */
} diagnostic_buffer_ptrs_t;

typedef struct {
    uint32_t state;  /* Buffer state (0=idle 1=ready 2=active) */
    uint32_t data_ptr;  /* Pointer to buffer data area */
    uint32_t unused_ptr;  /* Unused/reserved pointer */
    uint8_t data[8];  /* Inline buffer data (8 bytes) */
    uint32_t state;  /* can_buffer_setup_t_00801a8a - CAN buffer setup instance */
} can_buffer_setup_t;

typedef struct {
    uint8_t buffer_start;  /* Start of CAN message buffer area */
    uint8_t buffer_end;  /* End of CAN message buffer area */
} can_message_buffer_t;

typedef struct {
    uint32_t ram_start_addr;  /* Actual starting RAM address of data collector buffer */
    uint32_t ram_end_addr;  /* Physical RAM address of end of buffer */
    uint32_t logical_start;  /* Logical beginning address of buffer */
    uint32_t logical_center;  /* Logical center address for trigger point */
} data_collector_t;

typedef struct {
    uint32_t buffer_ptr;  /* Pointer to response buffer */
    uint8_t data_offset;  /* Current data offset in buffer */
    uint8_t buffer_index;  /* Buffer index for multi-response */
    uint8_t buffer_length;  /* Current response length */
    uint8_t reserved;  /* Reserved/padding byte */
} insite_response_buffer_t;


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
    AS01CF = 3,  /* ASG throttle mode compensation filter coef. 1 */
    AS02CF = 4,  /* ASG throttle mode compensation filter coef. 2 */
    AS03CF = 5  /* ASG throttle mode compensation filter coef. 3 */
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
    SYSTEM_CONTROL = 0x04,  /* System control commands - no security check */
    MEMORY_OPERATIONS = 0x05,  /* Memory read/write with CRC validation */
    RETRY_CONTROL = 0x06,  /* Transmission retry control (subfunction 0x74) */
    FUEL_ARBITRATOR = 0x4A,  /* fuelArbitratorControlService - fuel system control */
    EXTENDED_4C = 0x4C,  /* extendedDiagnosticService4C */
    EXTENDED_4F = 0x4F,  /* extendedDiagnosticService4F */
    EXTENDED_51 = 0x51  /* extendedDiagnosticService51 */
} DIAG_SERVICE_ID;

typedef enum {
    SWITCH_TO_FACTORY_BANK = 0x40,  /* Switch to factory calibration bank - sets calibration_bank_selector=0 (switchToFactoryCalibrationBank) */
    FORCE_ACTIVE_BANK = 0x41,  /* Force switch to active calibration bank (forceActiveCalibrationBank) */
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
    SWITCH_TO_ACTIVE_BANK = 0x69,  /* Switch to active calibration bank - sets calibration_bank_selector=1 (switchToActiveCalibrationBank) */
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
    EXTENDED_4F = 0x4F,  /* Extended diagnostic service 0x4F */
    EXTENDED_51 = 0x51  /* Extended diagnostic service 0x51 */
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
} DIAG_RESPONSE_CODE;

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
    BYPASS_ENABLED = 0xFF,  /* Security checks completely bypassed */
    BYPASS_MAGIC = 0xB522,  /* Alternative bypass magic value (-0x4ADE signed) */
    SECURITY_ACTIVE = 0x00  /* Normal security - checks enforced */
} SECURITY_BYPASS_FLAG;

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
    SERVICE_SECURED_WRITE = 3,  /* Secured write operations (length=3) */
    SERVICE_SYSTEM_CONTROL = 4  /* System control operations (length=3) */
} SECURED_SERVICE_ID;

typedef enum {
    INIT = 0,  /* Initialize transmission - setup buffers and addresses */
    WRITE_BUFFER = 1,  /* Write buffer data with circular buffer */
    TRANSMIT = 2,  /* Execute circular buffer write transmission */
    VP44_COMM_IDLE = 3  /* Idle/complete - transmission inactive */
} VP44_COMM_STATE;

typedef enum {
    MODE_IDLE = 0,  /* Idle mode - transition to state 3 */
    MODE_ACTIVE = 1,  /* Active mode - perform mid-buffer transmission */
    MODE_RESET = 2  /* Reset mode - transmit to end address and reset pointers */
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
    FUEL_ARBITRATOR = 1,  /* Fuel arbitrator triggered (rpm_target == 2) */
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
    RESET_INACTIVE = 0,  /* Reset/inactive state - initialized in vp44ControlVariablesReset */
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
    QUERY_TERMINATE = 0x01,  /* QueryTerminate - CLIP - dispatch @ 0x0001183E - SECURED - in dispatch table */
    SYSTEM_SERVICE_04 = 0x04,  /* System service 04 - NOT in dispatch table (handled elsewhere?) */
    SYSTEM_SERVICE_05 = 0x05,  /* System service 05 - NOT in dispatch table (handled elsewhere?) */
    HIGH_RPM_SHUTDOWN_ACTIVATE = 0x06,  /* activateHighRpmShutdownFlag - dispatch @ 0x000118FC - SECURED - RESPONDS! in dispatch table */
    SYSTEM_SERVICE_07 = 0x07,  /* System service 07 - dispatch @ 0x0001188C - SECURED - in dispatch table */
    SYSTEM_SERVICE_0A = 0x0A,  /* System service 0A - dispatch @ 0x000118B2 - SECURED - in dispatch table */
    SYSTEM_SERVICE_0B = 0x0B,  /* System service 0B - dispatch @ 0x00011908 - SECURED - in dispatch table */
    GET_PARAMETERS_BY_ID_ALT = 0x0F,  /* getParametersByIdHandler - NOT in dispatch table - RESPONDS! (alternate path?) */
    GET_PARAMETERS_BY_ID = 0x10,  /* GetParametersByID - CLIP - NOT in dispatch table - RESPONDS! (alternate path?) */
    GET_ADDRESS_BY_PARAM_ID = 0x15,  /* GetAddressByParameterID - dispatch @ 0x00011A74 - SECURED - in dispatch table */
    SYSTEM_SERVICE_16 = 0x16,  /* System service 16 - dispatch @ 0x000118CC - SECURED - in dispatch table */
    SYSTEM_SERVICE_18 = 0x18,  /* System service 18 - dispatch @ 0x00011A68 - SECURED - in dispatch table */
    DIAG_ADDR_RESOLVER = 0x41,  /* canDiagnosticResponseSender - dispatch @ 0x000222B4 - UNSECURED - RESPONDS! in dispatch table */
    MEM_READ_2B_PARAM_4B_OFFSET = 0x43,  /* Memory read - dispatch @ 0x00022530 - UNSECURED - RESPONDS! Format: [43][Param:2][Offset:4] */
    SERVICE_44 = 0x44,  /* Service 44 - dispatch @ 0x0002167E - UNSECURED - in dispatch table */
    SERVICE_45 = 0x45,  /* Service 45 - dispatch @ 0x000216C6 - UNSECURED - in dispatch table */
    MEM_READ_2B_PARAM_ONLY = 0x46,  /* Memory read - dispatch @ 0x0002257C - UNSECURED - RESPONDS! Format: [46][Param:2] */
    SERVICE_47 = 0x47,  /* Service 47 - dispatch @ 0x00021714 - UNSECURED - in dispatch table */
    SERVICE_48 = 0x48,  /* Service 48 - dispatch @ 0x000225E0 - UNSECURED - in dispatch table */
    SERVICE_49 = 0x49,  /* Service 49 - dispatch @ 0x00021778 - UNSECURED - in dispatch table */
    MEM_READ_4B_ADDR_1B_LEN = 0x4A,  /* Memory read - dispatch @ 0x00022646 - UNSECURED - WORKING! Format: [4A][Addr:4][Len:1] */
    SERVICE_4B = 0x4B,  /* Service 4B - dispatch @ 0x000217DE - UNSECURED - in dispatch table */
    MEM_READ_4B_ADDR_4B_LEN = 0x4C,  /* Memory read - dispatch @ 0x0002268E - UNSECURED - Format: [4C][Addr:4][Len:4] multi-frame */
    SERVICE_4D = 0x4D  /* Service 4D - dispatch @ 0x00021826 - UNSECURED - in dispatch table */
} EF00_SERVICE_ID;

typedef enum {
    FIRMWARE_START = 0x00000000,  /* Valid firmware region start (256KB code space) */
    FIRMWARE_END = 0x0003FFFF,  /* Valid firmware region end */
    RAM_START = 0x00800000,  /* Valid RAM region start (~37KB data) */
    RAM_END = 0x008091C2  /* Valid RAM region end */
} VALID_MEMORY_RANGE;

typedef enum {
    INVALID_LENGTH = 0x02,  /* diagnosticServiceSecurityValidator - message length mismatch */
    SECURITY_FAILED = 0x03,  /* diagnosticServiceSecurityValidator - systemSecurityCheck returned non-zero */
    CONDITION_NOT_MET = 0x07,  /* memoryOperationDispatcher - system_logging_state check failed */
    ADDR_LOOKUP_FAIL = 0x08,  /* j1939MemoryDataCopyResolver - initial address lookup at 0xeaf0 failed */
    ADDR_RANGE_INVALID = 0x09,  /* addressRangeValidator @ 0x2b544 - address not in address_range_validation_table @ 0x2b512 */
    ADDR_ACCESS_DENIED = 0x0A,  /* addressRangeValidator @ 0x2b544 - normal_mode_flag=0x0A blocks access (high memory 0xFFC800-0xFFFFFF in normal mode) */
    BUFFER_WRITE_FAIL = 0x0B,  /* memoryOperationDispatcher - circularBufferWrite returned error */
    WRITE_DENIED = 0x0A,  /* memoryOperationDispatcher - write to read-only region (ROM/Flash case 4) */
    PATCH_LIMIT = 0x0E,  /* diagnosticResponseBuilder - memory patch count exceeded limit */
    UNKNOWN_SERVICE = 0x18,  /* diagnosticServiceDispatcher - service ID not in dispatch table */
    AUTH_REQUIRED_MISSING = 0x1A  /* memoryOperationDispatcher - EEPROM write requires auth but none provided */
} DIAG_ERROR_SOURCE;

typedef enum {
    SUCCESS = 0x00,  /* Memory operation completed successfully (masked from memcpy return) */
    INVALID_LENGTH = 0x02,  /* Message length mismatch - expected calculated_msg_length or +10 for auth */
    AUTH_FAILED = 0x03,  /* hourMeterSecurityValidator returned non-zero (auth payload invalid) */
    CALIBRATION_WRITE_BLOCKED = 0x07,  /* EEPROM write blocked - calibration_write_protect_state==1 and calibration_bank_selector!=FACTORY */
    WRITE_DENIED = 0x0A,  /* Region type 4 (ROM/Flash) - write operations not permitted */
    BUFFER_WRITE_FAIL = 0x0B,  /* circularBufferWrite returned error during EEPROM logging */
    AUTH_REQUIRED_MISSING = 0x1A  /* EEPROM write (region type 5) requires auth but has_auth_payload=false */
} MEMORY_OP_RESULT;

typedef enum {
    SUCCESS = 0x4B  /* Service 0x4A success response code (service ID + 1) */
} SERVICE_4A_RESPONSE;

typedef enum {
    DIRECT_ACCESS = 0x00,  /* READ: Allowed | WRITE: Direct access no security check (Extended RAM) */
    SECURITY_REQUIRED = 0x03,  /* READ: Allowed | WRITE: Requires security check or bypass (RAM) */
    WRITE_DENIED = 0x04,  /* READ: Allowed | WRITE: Denied - returns error 0x0A (Flash/ROM) */
    LOGGING_MODE = 0x05,  /* READ: Allowed | WRITE: Requires system_logging_state check (EEPROM) */
    RANGE_INVALID = 0x09,  /* READ: Denied | WRITE: Error - address not in validation table */
    ACCESS_DENIED = 0x0A  /* READ: Denied | WRITE: Error - explicitly blocked region */
} MEMORY_ACCESS_FLAG;

typedef enum {
    BYPASS_ENABLED = 0xB522,  /* Magic value to bypass security checks (stored at 0x803586) */
    LEGACY_BYPASS = 0x00FF  /* Legacy security bypass value check in memoryOperationDispatcher */
} SECURITY_BYPASS;

typedef enum {
    SWITCH_TO_FACTORY_BANK = 0x40,  /* switchToFactoryCalibrationBank - select factory calibration bank (calibration_bank_selector=0) */
    FORCE_ACTIVE_BANK = 0x41,  /* forceActiveCalibrationBank - force active calibration bank if write protect allows */
    HIGH_RPM_SHUTDOWN = 0x42,  /* activateHighRpmShutdownFlag - trigger high RPM shutdown */
    SYSTEM_RESET = 0x43,  /* triggerDiagnosticSystemReset - diagnostic system reset */
    NOP = 0x50,  /* No operation - returns success (0x00) */
    MEMORY_PATCH = 0x51,  /* memoryPatchingSystem - apply queued memory patches */
    SECURED_SHUTDOWN = 0x52,  /* requestSecuredShutdown - request secured engine shutdown */
    RESERVED_ERROR = 0x53,  /* Reserved - always returns error 0x04 */
    CAN_BUFFER_LOG = 0x54  /* canMessageBufferLogger - log CAN message buffer */
} DIAG_SERVICE_3_CMD;

typedef enum {
    CONTROL_64 = 0x64,  /* systemControl64 - system control function */
    FAULT_SCANNER = 0x65,  /* enableFaultFlagScanner - enable fault flag scanning */
    STATE_RESET = 0x66,  /* Reset diagnostic_command_state to 0 */
    SWITCH_TO_ACTIVE_BANK = 0x69,  /* switchToActiveCalibrationBank - select active calibration bank (calibration_bank_selector=1) */
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
    ACTIVE_FAULT_LIST = 0xC1,  /* insiteActiveFaultListBuilder - list of active DTCs */
    FAULT_DETAIL = 0xC2,  /* insiteFaultDetailBuilder - detailed fault information */
    PID_DTC_REQUEST = 0xC3,  /* PID/DTC handler request - triggers insitePidDtcHandler */
    PID_DTC_RESPONSE = 0xC4,  /* PID/DTC response - response length 4 or 7 */
    CAPACITY_INFO = 0xEA,  /* insiteCapacityResponseBuilder - response length 0x18 (24 bytes) */
    ECU_ID = 0xED,  /* insiteEcuIdResponseBuilder - ECU identification (3 parts with 0x2A separator) */
    VERSION_INFO = 0xF3  /* insiteVersionInfoBuilder - response length 0x1F (31 bytes) */
} INSITE_CMD;

typedef enum {
    FACTORY = 0,  /* Factory calibration bank - reads bytes 0-3 of parameter entries (original OEM values) */
    ACTIVE = 1  /* Active calibration bank - reads bytes 4-7 of parameter entries (tunable values) */
} CALIBRATION_BANK;

typedef enum {
    NOT_LOADED = 0,  /* Calibration not loaded from flash */
    PRIMARY_FLASH = 1,  /* Loaded from primary flash bank @ 0x4000-0x55b2 */
    SECONDARY_FLASH = 2  /* Loaded from secondary flash bank @ 0x6000-0x75b2 */
} CALIBRATION_FLASH_SOURCE;

typedef enum {
    ACTIVE_BANK_SELECTED = 0xEEEE,  /* Active calibration bank is selected */
    FACTORY_BANK_SELECTED = 0xEAEA,  /* Factory calibration bank is selected */
    TRANSITION_PENDING = 0xEAEB,  /* Transition to active bank pending */
    SYNC_COMPLETE = 0xEEEF  /* RAM to flash sync complete */
} CALIBRATION_STATE_SIGNATURE;

typedef enum {
    WRITES_ALLOWED = 0,  /* EEPROM writes allowed - no restrictions */
    WRITES_BLOCKED_IF_ACTIVE = 1,  /* EEPROM writes blocked when active bank selected */
    WRITES_ALLOWED_OVERRIDE = 2  /* EEPROM writes allowed via special override */
} CALIBRATION_WRITE_PROTECT;
