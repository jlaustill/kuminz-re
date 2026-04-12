// CM848D EEPROM Dumper — outputs full 8KB EEPROM as hex for diffing.
// Run between HP Tuners flashes to identify runtime counter addresses.
//
// Output format: raw hex lines, one u16 word per line with address prefix.
// Easy to diff with standard tools.

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

    // Sanity check
    uint16_t rpm;
    if (!readWord(0x0040B7BA, rpm)) {
        Serial.println("ERROR: ECU NOT RESPONDING");
        while (1) delay(1000);
    }

    Serial.println("EEPROM_DUMP_START");

    uint32_t base = 0x01000000;
    uint32_t end = 0x01002000;  // 8KB
    int errors = 0;

    for (uint32_t addr = base; addr < end; addr += 2) {
        uint16_t val;
        if (readWord(addr, val)) {
            // Format: ADDRESS XXXX
            Serial.print(addr, HEX);
            Serial.print(" ");
            if (val < 0x1000) Serial.print("0");
            if (val < 0x100) Serial.print("0");
            if (val < 0x10) Serial.print("0");
            Serial.println(val, HEX);
        } else {
            Serial.print(addr, HEX);
            Serial.println(" DEAD");
            errors++;
        }

        // Progress every 512 words (1KB)
        if (((addr - base) & 0x3FF) == 0 && addr != base) {
            // Print progress to stderr-style marker that won't break the diff
            Serial.print("# Progress: ");
            Serial.print((addr - base) / 2);
            Serial.print("/4096 words (");
            Serial.print((addr - base) * 100 / (end - base));
            Serial.println("%)");
        }
    }

    Serial.print("EEPROM_DUMP_END errors=");
    Serial.println(errors);

    while (1) { can.events(); delay(100); }
}

void loop() {}
