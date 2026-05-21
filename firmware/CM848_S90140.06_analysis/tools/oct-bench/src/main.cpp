// CM848D Broadcast Diagnostic Monitor
//
// Reads the three variables that gate J1939 EEC1/EEC2 broadcasts:
//   fuel_demand_accumulator    0x0040A7C0 — engine state (1=key-on, 2+=running)
//   protection_condition_flags 0x0040ADEE — broadcast gate (needs bit 2 or 3 set)
//   current_engine_rpm         0x0040B7BA — RPM (x0.125)
//
// If protection_condition_flags stays 0x0000 with engine running, the
// protection parameter init path never fired — that's the broadcast blocker.

#include <Arduino.h>
#include <FlexCAN_T4.h>

FlexCAN_T4<CAN2, RX_SIZE_256, TX_SIZE_16> can;

static volatile bool got_response = false;
static volatile uint32_t resp_addr = 0;
static volatile uint16_t resp_data = 0;

static void onReceive(const CAN_message_t &msg) {
    if (msg.id == 0x18EFF900 && msg.buf[0] == 0x4B && msg.len == 8) {
        resp_addr = ((uint32_t)msg.buf[1] << 24) | ((uint32_t)msg.buf[2] << 16) |
                    ((uint32_t)msg.buf[3] << 8) | msg.buf[4];
        resp_data = ((uint16_t)msg.buf[6] << 8) | msg.buf[7];
        got_response = true;
    }
}

static void readMem(uint32_t addr, uint8_t len) {
    CAN_message_t msg;
    msg.id = 0x18EF00F9;
    msg.flags.extended = true;
    msg.len = 8;
    msg.buf[0] = 0x4A;
    msg.buf[1] = (addr >> 24) & 0xFF;
    msg.buf[2] = (addr >> 16) & 0xFF;
    msg.buf[3] = (addr >> 8) & 0xFF;
    msg.buf[4] = addr & 0xFF;
    msg.buf[5] = len;
    msg.buf[6] = 0x00;
    msg.buf[7] = 0x00;
    can.write(msg);
}

static bool readWord(uint32_t addr, uint16_t &result, uint32_t timeout_ms = 300) {
    got_response = false;
    readMem(addr, 2);
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

    Serial.println("=== CM848 BROADCAST DIAGNOSTIC ===");
    Serial.println("fuel_demand_accumulator    : 1=key-on/idle, 2+=running");
    Serial.println("protection_condition_flags : needs bit2/3 set for EEC1/EEC2");
    Serial.println("rpm                        : raw x0.125 = RPM");
    Serial.println("---");
}

void loop() {
    uint16_t rpm = 0, fuel_state = 0, prot_flags = 0;
    bool rpm_ok   = readWord(0x0040B7BA, rpm);
    bool fuel_ok  = readWord(0x0040A7C0, fuel_state);
    bool prot_ok  = readWord(0x0040ADEE, prot_flags);

    Serial.print("RPM=");
    if (rpm_ok) { Serial.print((float)rpm * 0.125f, 0); } else { Serial.print("?"); }

    Serial.print("  fuel_demand_accumulator=0x");
    if (fuel_ok) { Serial.print(fuel_state, HEX); } else { Serial.print("?"); }

    Serial.print("  protection_condition_flags=0x");
    if (prot_ok) {
        if (prot_flags < 0x1000) Serial.print("0");
        if (prot_flags < 0x100)  Serial.print("0");
        if (prot_flags < 0x10)   Serial.print("0");
        Serial.print(prot_flags, HEX);
        if ((prot_flags & 0x000C) == 0) Serial.print(" <-- BROADCAST BLOCKED");
    } else {
        Serial.print("?");
    }

    Serial.println();
    delay(1000);
}
