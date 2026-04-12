// Teensy MicroMod SLCAN Bridge
//
// Turns a Teensy MicroMod + CAN transceiver into a USB-to-CAN adapter
// compatible with Linux SocketCAN via slcand.
//
// Usage:
//   1. Flash this firmware onto the Teensy MicroMod
//   2. On Linux:
//      sudo slcand -o -c -s5 /dev/ttyACM0 slcan0
//      sudo ip link set slcan0 up
//   3. Use candump, cansend, kuminz-cli, etc. on slcan0
//
// CAN port: CAN2 (MicroMod CAN_B pins — matches OCT hardware config).
//           Change to CAN1 or CAN3 if your carrier board routes differently.
//
// SLCAN protocol reference: http://www.can232.com/docs/canusb_manual.pdf
//
// Supported commands:
//   Sn       Set speed (S5=250k, S6=500k, S8=1M — others ACK'd but use S5)
//   O        Open CAN channel
//   C        Close CAN channel
//   tIIILDD  Send standard frame (11-bit ID)
//   TIIIIIIIILDD Send extended frame (29-bit ID)
//   rIIIL    Send standard RTR
//   RIIIIIIIIL   Send extended RTR
//   F        Read status flags
//   V        Hardware/firmware version
//   N        Serial number

#include <Arduino.h>
#include <FlexCAN_T4.h>

// === CAN PORT SELECTION ===
// Change this to CAN1 or CAN3 to match your carrier board's transceiver wiring.
FlexCAN_T4<CAN2, RX_SIZE_256, TX_SIZE_16> can;

// === Configuration ===
static uint32_t can_baudrate = 250000;  // Default: J1939 standard
static bool channel_open = false;

// === SLCAN command buffer ===
static char cmd_buf[64];
static uint8_t cmd_idx = 0;

// === RX ring buffer (interrupt-safe) ===
static const int RX_RING_SIZE = 64;
static CAN_message_t rx_ring[RX_RING_SIZE];
static volatile int rx_head = 0;
static volatile int rx_tail = 0;

// === Hex conversion utilities ===

static uint8_t hex_to_nibble(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    return 0;
}

static char nibble_to_hex(uint8_t n) {
    return n < 10 ? '0' + n : 'A' + n - 10;
}

// === CAN RX callback (ISR context) ===

static void can_rx_callback(const CAN_message_t &msg) {
    int next = (rx_head + 1) % RX_RING_SIZE;
    if (next != rx_tail) {
        rx_ring[rx_head] = msg;
        rx_head = next;
    }
    // If ring is full, frame is silently dropped.
}

// === SLCAN frame formatting ===

static void format_rx_frame(const CAN_message_t &msg) {
    // Format: T[8-hex-id][dlc][2*dlc hex data bytes]\r  (extended)
    //     or: t[3-hex-id][dlc][2*dlc hex data bytes]\r  (standard)
    char out[32];
    int pos = 0;

    if (msg.flags.extended) {
        out[pos++] = 'T';
        for (int i = 7; i >= 0; i--) {
            out[pos++] = nibble_to_hex((msg.id >> (i * 4)) & 0xF);
        }
    } else {
        out[pos++] = 't';
        out[pos++] = nibble_to_hex((msg.id >> 8) & 0xF);
        out[pos++] = nibble_to_hex((msg.id >> 4) & 0xF);
        out[pos++] = nibble_to_hex(msg.id & 0xF);
    }

    uint8_t len = msg.len > 8 ? 8 : msg.len;
    out[pos++] = nibble_to_hex(len);

    for (int i = 0; i < len; i++) {
        out[pos++] = nibble_to_hex(msg.buf[i] >> 4);
        out[pos++] = nibble_to_hex(msg.buf[i] & 0xF);
    }

    out[pos++] = '\r';
    out[pos] = '\0';
    Serial.print(out);
}

// === SLCAN TX frame parsing ===

static void send_can_frame(const char *cmd, bool extended) {
    CAN_message_t msg;
    memset(&msg, 0, sizeof(msg));
    int pos;

    if (extended) {
        // TIIIIIIIILDD...
        if (strlen(cmd) < 10) { Serial.print('\a'); return; }
        msg.id = 0;
        for (int i = 1; i <= 8; i++) {
            msg.id = (msg.id << 4) | hex_to_nibble(cmd[i]);
        }
        msg.flags.extended = 1;
        msg.len = hex_to_nibble(cmd[9]);
        pos = 10;
    } else {
        // tIIILDD...
        if (strlen(cmd) < 5) { Serial.print('\a'); return; }
        msg.id = (hex_to_nibble(cmd[1]) << 8) |
                 (hex_to_nibble(cmd[2]) << 4) |
                  hex_to_nibble(cmd[3]);
        msg.flags.extended = 0;
        msg.len = hex_to_nibble(cmd[4]);
        pos = 5;
    }

    if (msg.len > 8) msg.len = 8;
    for (int i = 0; i < msg.len; i++) {
        msg.buf[i] = (hex_to_nibble(cmd[pos]) << 4) | hex_to_nibble(cmd[pos + 1]);
        pos += 2;
    }

    if (channel_open) {
        can.write(msg);
    }
    Serial.print('\r');  // ACK
}

// === CAN initialization ===

static void can_init() {
    can.begin();
    can.setBaudRate(can_baudrate);
    can.setMaxMB(16);
    can.enableFIFO();
    can.enableFIFOInterrupt();
    can.onReceive(can_rx_callback);
}

// === SLCAN command processing ===

static void process_command(const char *cmd) {
    if (cmd[0] == '\0') return;

    switch (cmd[0]) {
        case 'S': {
            // Set baud rate: S0-S8
            // S3=100k, S4=125k, S5=250k, S6=500k, S7=800k, S8=1M
            switch (cmd[1]) {
                case '3': can_baudrate = 100000; break;
                case '4': can_baudrate = 125000; break;
                case '5': can_baudrate = 250000; break;
                case '6': can_baudrate = 500000; break;
                case '7': can_baudrate = 800000; break;
                case '8': can_baudrate = 1000000; break;
                default: break;  // Keep current
            }
            Serial.print('\r');
            break;
        }
        case 'O':
            can_init();
            channel_open = true;
            Serial.print('\r');
            break;
        case 'C':
            channel_open = false;
            Serial.print('\r');
            break;
        case 't':
            send_can_frame(cmd, false);
            break;
        case 'T':
            send_can_frame(cmd, true);
            break;
        case 'r':  // Standard RTR
        case 'R':  // Extended RTR
            Serial.print('\r');
            break;
        case 'F':  // Status flags
            Serial.print("F00\r");
            break;
        case 'V':  // Version
            Serial.print("V0101\r");
            break;
        case 'N':  // Serial number
            Serial.print("NSLCAN\r");
            break;
        default:
            Serial.print('\a');  // NAK
            break;
    }
}

// === Main ===

void setup() {
    Serial.begin(115200);
    // Don't call can_init() here — wait for SLCAN 'O' command.
    // slcand sends S5 then O on connect.
}

void loop() {
    // Process FlexCAN events (required for interrupt-driven RX)
    can.events();

    // Process incoming serial (SLCAN commands from host)
    while (Serial.available()) {
        char c = Serial.read();
        if (c == '\r' || c == '\n') {
            if (cmd_idx > 0) {
                cmd_buf[cmd_idx] = '\0';
                process_command(cmd_buf);
                cmd_idx = 0;
            }
        } else if (cmd_idx < sizeof(cmd_buf) - 1) {
            cmd_buf[cmd_idx++] = c;
        }
    }

    // Forward received CAN frames to host
    while (rx_tail != rx_head) {
        if (channel_open) {
            format_rx_frame(rx_ring[rx_tail]);
        }
        rx_tail = (rx_tail + 1) % RX_RING_SIZE;
    }
}
