// CM848D Broadcast Enable + Monitor
//
// Startup: sends 3-step J1939 broadcast enable sequence, then monitors.
// Periodic poll line (every second): RPM | fuel state | protection flags
// Received broadcasts: logged immediately as they arrive on CAN.

#include <Arduino.h>
#include <FlexCAN_T4.h>

FlexCAN_T4<CAN2, RX_SIZE_256, TX_SIZE_16> can;

static const uint32_t TX_ARB_ID = 0x18EF00F9;
static const uint32_t RX_ARB_ID = 0x18EFF900;

// Service 0x4B single-frame read response
static volatile bool got_response = false;
static volatile uint32_t resp_addr = 0;
static volatile uint16_t resp_data = 0;

static void printHex2(uint8_t v) {
    if (v < 0x10) Serial.print("0");
    Serial.print(v, HEX);
}

static void printHex4(uint16_t v) {
    if (v < 0x1000) Serial.print("0");
    if (v < 0x100)  Serial.print("0");
    if (v < 0x10)   Serial.print("0");
    Serial.print(v, HEX);
}

static void onReceive(const CAN_message_t &msg) {
    if (msg.id == RX_ARB_ID && msg.buf[0] == 0x4B) {
        resp_addr = ((uint32_t)msg.buf[1] << 24) | ((uint32_t)msg.buf[2] << 16) |
                    ((uint32_t)msg.buf[3] << 8) | msg.buf[4];
        resp_data = ((uint16_t)msg.buf[6] << 8) | msg.buf[7];
        got_response = true;
        return;
    }

    // Log all other CAN traffic — broadcasts from the ECU
    uint8_t pf  = (msg.id >> 16) & 0xFF;
    uint8_t ps  = (msg.id >> 8)  & 0xFF;
    uint8_t src = msg.id & 0xFF;
    uint32_t pgn = (pf >= 0xF0) ? ((uint32_t)pf << 8 | ps) : ((uint32_t)pf << 8);

    Serial.print("RX  PGN=");
    Serial.print(pgn, HEX);
    Serial.print(" src=");
    printHex2(src);
    Serial.print("  [");
    for (uint8_t i = 0; i < msg.len; i++) {
        printHex2(msg.buf[i]);
        if (i < msg.len - 1) Serial.print(" ");
    }
    Serial.println("]");
}

static void sendEF00(const uint8_t *payload, uint8_t len) {
    CAN_message_t msg;
    msg.id = TX_ARB_ID;
    msg.flags.extended = true;
    msg.len = 8;
    memset(msg.buf, 0, 8);
    for (uint8_t i = 0; i < len && i < 8; i++) msg.buf[i] = payload[i];
    can.write(msg);
}

static bool readWord(uint32_t addr, uint16_t &result, uint32_t timeout_ms = 300) {
    uint8_t req[8] = {
        0x4A,
        (uint8_t)(addr >> 24), (uint8_t)(addr >> 16),
        (uint8_t)(addr >> 8),  (uint8_t)(addr),
        0x02, 0x00, 0x00
    };
    got_response = false;
    sendEF00(req, 8);
    uint32_t start = millis();
    while (millis() - start < timeout_ms) {
        can.events();
        if (got_response && resp_addr == addr) {
            result = resp_data;
            return true;
        }
        delayMicroseconds(500);
    }
    return false;
}

static void sendService(const uint8_t *data, uint8_t len, uint32_t wait_ms = 200) {
    sendEF00(data, len);
    uint32_t start = millis();
    while (millis() - start < wait_ms) {
        can.events();
        delayMicroseconds(500);
    }
}

void setup() {
    Serial.begin(115200);
    delay(2000);

    can.begin();
    can.setBaudRate(250000);
    can.setMaxMB(16);
    can.enableFIFO();
    can.enableFIFOInterrupt();
    can.onReceive(onReceive);
    delay(100);

    uint16_t rpm;
    if (!readWord(0x0040B7BA, rpm)) {
        Serial.println("ERROR: ECU NOT RESPONDING");
        while (1) delay(1000);
    }

    Serial.println("=== CM848 BROADCAST ENABLE + MONITOR ===");

    Serial.print("[1/3] service 0x0a (initJ1939MessageBuffers)... ");
    uint8_t svc0a[] = {0x0a};
    sendService(svc0a, 1);
    Serial.println("sent");

    Serial.print("[2/3] service 0x07 (enableJ1939Output)... ");
    uint8_t svc07[] = {0x07};
    sendService(svc07, 1);
    Serial.println("sent");

    Serial.print("[3/3] service 0x05 01 01 (setProtectionConditionFlags)... ");
    uint8_t svc05[] = {0x05, 0x01, 0x01};
    sendService(svc05, 3);
    Serial.println("sent");

    Serial.println("---");
}

static uint32_t last_poll = 0;

void loop() {
    can.events();

    if (millis() - last_poll >= 1000) {
        last_poll = millis();

        uint16_t rpm = 0, fuel_state = 0, prot_flags = 0;
        bool rpm_ok   = readWord(0x0040B7BA, rpm);
        bool fuel_ok  = readWord(0x0040A7C0, fuel_state);
        bool prot_ok  = readWord(0x0040ADEE, prot_flags);

        Serial.print("--- RPM=");
        if (rpm_ok) { Serial.print((float)rpm * 0.125f, 0); } else { Serial.print("?"); }
        Serial.print("  fuel=0x");
        if (fuel_ok) { Serial.print(fuel_state, HEX); } else { Serial.print("?"); }
        Serial.print("  prot=0x");
        if (prot_ok) { printHex4(prot_flags); } else { Serial.print("????"); }
        Serial.println();
    }
}
