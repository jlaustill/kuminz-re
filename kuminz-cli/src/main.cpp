/**
 * @file main.cpp
 * @brief kuminz-cli - Command line interface for CM550 ECU memory dumps
 *
 * This is a THIN WRAPPER - all protocol logic is in clip-core library.
 * This file only handles:
 *   - Command line argument parsing
 *   - stdout/stderr output
 *   - Signal handling (Ctrl+C)
 */

#include <clip/ECUReader.h>
#include <clip/SocketCanAdapter.h>
#include <clip/ServiceScanner.h>
#include <clip/SecurityAuth.h>
#include <clip/types/TClipPacket.h>

#include <iostream>
#include <iomanip>
#include <sstream>
#include <csignal>
#include <cstring>
#include <cctype>
#include <vector>

// Global flag for clean shutdown on Ctrl+C
volatile bool g_running = true;

void signalHandler(int)
{
    g_running = false;
    std::cerr << "\n[INFO] Interrupted - shutting down...\n";
}

void printUsage(const char* progname)
{
    std::cerr << "kuminz-cli - CM550 ECU Memory Dump & Service Scanner Tool\n\n";
    std::cerr << "Usage:\n";
    std::cerr << "  " << progname << " <can-interface> <command> [options]\n\n";
    std::cerr << "Memory Dump Commands:\n";
    std::cerr << "  --dump-ram [file]           Dump main RAM (37KB) to file\n";
    std::cerr << "  --dump-extended-ram [file]  Dump extended RAM (28KB) to file\n";
    std::cerr << "  --dump-eeprom [file]        Dump EEPROM (4KB) to file\n";
    std::cerr << "  --dump-rom [file]           Dump ROM/Flash (256KB) to file\n";
    std::cerr << "  --dump-all [dir]            Dump all regions to directory\n\n";
    std::cerr << "Service Scanner Commands:\n";
    std::cerr << "  --scan-services             Quick scan (0x40-0x5F, ~30 sec)\n";
    std::cerr << "  --scan-services-full        Full scan (0x00-0xFF, ~2-3 min)\n";
    std::cerr << "  --probe-service <hex-id>    Probe single service (e.g., 4A)\n\n";
    std::cerr << "Address Read Commands:\n";
    std::cerr << "  --read-addr <hex-addr> <len>  Read bytes at address (e.g., 801c7a 100)\n\n";
    std::cerr << "Memory Write Commands (EXPERIMENTAL - USE AT OWN RISK):\n";
    std::cerr << "  --write-service4b <hex-addr> <hex-value>  Write via Service 0x4B (RECOMMENDED)\n";
    std::cerr << "                                            J1939 write path with auth, no CRC needed\n";
    std::cerr << "                                            e.g., 800100 AA55 (write 0xAA55 to 0x800100)\n";
    std::cerr << "  --write-service5 <hex-addr> <hex-value>   Write via Service 0x05 (J1708 ONLY - won't work on CAN)\n";
    std::cerr << "  --write-addr <hex-addr> <hex-value>       Write via 0x4A (DEPRECATED - read service)\n";
    std::cerr << "  --write-addr-auth <hex-addr> <hex-value>  Auth write via 0x4A (DEPRECATED)\n";
    std::cerr << "  --write-clip <hex-addr> <hex-value>       Write via CLIP session (command 0x15)\n\n";
    std::cerr << "Security Authentication Commands:\n";
    std::cerr << "  --auth-test                 Test security algorithm (offline - no ECU needed)\n";
    std::cerr << "  --auth-gen <hex-hour-meter> Generate auth payload for hour meter value\n";
    std::cerr << "  --auth-live                 Read hour meter from ECU and generate auth payload\n";
    std::cerr << "  --auth-tables               Print algorithm lookup tables\n\n";
    std::cerr << "Other:\n";
    std::cerr << "  --help, -h                  Show this help\n\n";
    std::cerr << "Examples:\n";
    std::cerr << "  " << progname << " can0 --dump-ram\n";
    std::cerr << "  " << progname << " can0 --dump-eeprom cm550_eeprom.bin\n";
    std::cerr << "  " << progname << " can0 --scan-services\n";
    std::cerr << "  " << progname << " can0 --probe-service 4A\n";
    std::cerr << "  " << progname << " can0 --read-addr 801c7a 100\n";
    std::cerr << "  " << progname << " can0 --write-service4b 800100 AA55\n\n";
    std::cerr << "Note: CAN interface must be configured before running:\n";
    std::cerr << "  sudo ip link set can0 type can bitrate 250000\n";
    std::cerr << "  sudo ip link set can0 up\n";
}

// Progress callback - ONLY displays to stdout, NO logic
void progressCallback(uint32_t current, uint32_t total, const std::string& msg)
{
    int percent = (total > 0) ? static_cast<int>((current * 100) / total) : 0;
    std::cout << "\r[" << std::setw(3) << percent << "%] " << msg << std::flush;
}

// Log callback - displays to stderr
void logCallback(const std::string& msg)
{
    std::cerr << "[LOG] " << msg << "\n";
}

int main(int argc, char* argv[])
{
    signal(SIGINT, signalHandler);
    signal(SIGTERM, signalHandler);

    // Parse command line arguments
    if (argc < 3) {
        printUsage(argv[0]);
        return 1;
    }

    std::string canDevice = argv[1];
    std::string command = argv[2];

    // Handle help
    if (command == "--help" || command == "-h" || canDevice == "--help" || canDevice == "-h") {
        printUsage(argv[0]);
        return 0;
    }

    // Get optional output file/directory
    std::string outputArg = (argc >= 4) ? argv[3] : "";

    // =========================================================================
    // Offline Security Auth Commands (no ECU connection needed)
    // =========================================================================
    if (command == "--auth-test") {
        std::cerr << "\n=== CM550 Security Algorithm Test ===\n\n";

        // Test with known values
        uint32_t testHourMeter = 0x12345678;
        std::cerr << "Test hour meter: 0x" << std::hex << std::uppercase
                  << std::setw(8) << std::setfill('0') << testHourMeter << std::dec << "\n\n";

        // Generate auth payload
        std::vector<uint8_t> payload;
        if (SecurityAuth::generateAuthPayload(testHourMeter, payload)) {
            std::cerr << "Generated auth payload (10 bytes):\n  ";
            for (size_t i = 0; i < payload.size(); i++) {
                std::cerr << std::hex << std::uppercase << std::setw(2)
                          << std::setfill('0') << static_cast<int>(payload[i]) << " ";
            }
            std::cerr << std::dec << "\n\n";

            // Verify by running forward algorithm
            std::vector<uint8_t> result;
            SecurityAuth::bitPackingForward(payload, result);

            std::cerr << "Forward algorithm result:\n  ";
            for (size_t i = 0; i < result.size(); i++) {
                std::cerr << std::hex << std::uppercase << std::setw(2)
                          << std::setfill('0') << static_cast<int>(result[i]) << " ";
            }
            std::cerr << "\n\n";

            // Check components
            std::string secKey(result.begin(), result.begin() + 6);
            uint32_t resultHM = (result[6] << 24) | (result[7] << 16) |
                                (result[8] << 8) | result[9];

            std::cerr << "Decoded result:\n";
            std::cerr << "  Security key: \"" << secKey << "\" ";
            if (secKey == "ABCDEF") {
                std::cerr << "[PASS]\n";
            } else {
                std::cerr << "[FAIL - expected \"ABCDEF\"]\n";
            }

            std::cerr << "  Hour meter:   0x" << std::hex << std::uppercase
                      << std::setw(8) << std::setfill('0') << resultHM << " ";
            if (resultHM == testHourMeter) {
                std::cerr << "[PASS]\n";
            } else {
                std::cerr << "[FAIL - expected 0x" << testHourMeter << "]\n";
            }

            std::cerr << std::dec << "\n";

            if (SecurityAuth::verifyPayload(payload, testHourMeter)) {
                std::cerr << "=== ALGORITHM VERIFICATION: PASS ===\n";
                return 0;
            } else {
                std::cerr << "=== ALGORITHM VERIFICATION: FAIL ===\n";
                return 1;
            }
        } else {
            std::cerr << "[ERROR] Failed to generate auth payload\n";
            return 1;
        }
    }
    else if (command == "--auth-gen") {
        if (outputArg.empty()) {
            std::cerr << "[ERROR] --auth-gen requires <hex-hour-meter>\n";
            std::cerr << "Example: --auth-gen 12345678\n";
            return 1;
        }

        // Parse hex hour meter
        uint32_t hourMeter;
        std::stringstream ss;
        ss << std::hex << outputArg;
        ss >> hourMeter;

        std::cerr << "\n=== Generate Auth Payload ===\n\n";
        std::cerr << "Hour meter: 0x" << std::hex << std::uppercase
                  << std::setw(8) << std::setfill('0') << hourMeter << std::dec << "\n\n";

        std::vector<uint8_t> payload;
        if (SecurityAuth::generateAuthPayload(hourMeter, payload)) {
            std::cerr << "Auth payload (10 bytes):\n";
            std::cerr << "  Hex: ";
            for (size_t i = 0; i < payload.size(); i++) {
                std::cerr << std::hex << std::uppercase << std::setw(2)
                          << std::setfill('0') << static_cast<int>(payload[i]) << " ";
            }
            std::cerr << "\n";

            // Also print as C array
            std::cerr << "  C:   {";
            for (size_t i = 0; i < payload.size(); i++) {
                std::cerr << "0x" << std::hex << std::uppercase << std::setw(2)
                          << std::setfill('0') << static_cast<int>(payload[i]);
                if (i < payload.size() - 1) std::cerr << ", ";
            }
            std::cerr << "}\n\n" << std::dec;

            // Verify
            if (SecurityAuth::verifyPayload(payload, hourMeter)) {
                std::cerr << "[VERIFIED] Payload generates correct output\n";
                return 0;
            } else {
                std::cerr << "[ERROR] Verification failed!\n";
                return 1;
            }
        } else {
            std::cerr << "[ERROR] Failed to generate auth payload\n";
            return 1;
        }
    }
    else if (command == "--auth-tables") {
        SecurityAuth::printTables();
        return 0;
    }

    // Create adapter and reader from clip-core
    SocketCanAdapter adapter;
    ECUReader reader(&adapter);
    reader.setProgressCallback(progressCallback);
    reader.setLogCallback(logCallback);

    // Connect using Service 0x4A mode (no CLIP session - this WORKS for CM550)
    std::cerr << "[INFO] Connecting to ECU on " << canDevice << " (Service 0x4A mode)...\n";
    if (!reader.connectSimple(canDevice)) {
        std::cerr << "[ERROR] Failed to open CAN device " << canDevice << "\n";
        return 1;
    }
    std::cerr << "[INFO] Connected successfully\n";

    int result = 0;

    // Execute command using Service 0x4A (the WORKING approach for CM550)
    if (command == "--dump-ram") {
        std::string filename = outputArg.empty() ? "cm550_ram.bin" : outputArg;
        std::cerr << "[INFO] Dumping RAM to " << filename << " (Service 0x4A)\n";
        result = reader.dumpMemoryService4AToFile(CM550_RAM_START, CM550_RAM_SIZE, filename) ? 0 : 1;
    }
    else if (command == "--dump-extended-ram") {
        std::string filename = outputArg.empty() ? "cm550_extended_ram.bin" : outputArg;
        uint32_t extendedSize = CM550_PROTECTED_RAM_END - CM550_PROTECTED_RAM_START + 1;
        std::cerr << "[INFO] Dumping extended RAM to " << filename << " (Service 0x4A)\n";
        std::cerr << "[WARNING] Extended RAM may be protected - read may fail\n";
        result = reader.dumpMemoryService4AToFile(CM550_PROTECTED_RAM_START, extendedSize, filename) ? 0 : 1;
    }
    else if (command == "--dump-eeprom") {
        std::string filename = outputArg.empty() ? "cm550_eeprom.bin" : outputArg;
        std::cerr << "[INFO] Dumping EEPROM to " << filename << " (Service 0x4A)\n";
        result = reader.dumpMemoryService4AToFile(CM550_EEPROM_START, CM550_EEPROM_SIZE, filename) ? 0 : 1;
    }
    else if (command == "--dump-rom") {
        std::string filename = outputArg.empty() ? "cm550_rom.bin" : outputArg;
        std::cerr << "[INFO] Dumping ROM to " << filename << " (Service 0x4A - this may take a while...)\n";
        result = reader.dumpMemoryService4AToFile(CM550_ROM_START, CM550_ROM_SIZE, filename) ? 0 : 1;
    }
    else if (command == "--dump-all") {
        std::string dir = outputArg.empty() ? "." : outputArg;
        // Ensure directory ends with /
        if (!dir.empty() && dir.back() != '/') {
            dir += '/';
        }

        std::cerr << "[INFO] Dumping all memory regions to " << dir << " (Service 0x4A)\n";

        // RAM
        std::cerr << "\n=== RAM ===\n";
        if (!reader.dumpMemoryService4AToFile(CM550_RAM_START, CM550_RAM_SIZE, dir + "cm550_ram.bin")) {
            std::cerr << "[ERROR] RAM dump failed\n";
            result = 1;
        }
        std::cout << "\n";

        // EEPROM
        std::cerr << "\n=== EEPROM ===\n";
        if (!reader.dumpMemoryService4AToFile(CM550_EEPROM_START, CM550_EEPROM_SIZE, dir + "cm550_eeprom.bin")) {
            std::cerr << "[ERROR] EEPROM dump failed\n";
            result = 1;
        }
        std::cout << "\n";

        // ROM
        std::cerr << "\n=== ROM ===\n";
        if (!reader.dumpMemoryService4AToFile(CM550_ROM_START, CM550_ROM_SIZE, dir + "cm550_rom.bin")) {
            std::cerr << "[ERROR] ROM dump failed\n";
            result = 1;
        }
        std::cout << "\n";

        // Extended RAM (may fail)
        std::cerr << "\n=== Extended RAM (may be protected) ===\n";
        uint32_t extendedSize = CM550_PROTECTED_RAM_END - CM550_PROTECTED_RAM_START + 1;
        if (!reader.dumpMemoryService4AToFile(CM550_PROTECTED_RAM_START, extendedSize, dir + "cm550_extended_ram.bin")) {
            std::cerr << "[WARNING] Extended RAM dump failed (this region may be protected)\n";
            // Don't fail the whole operation for extended RAM
        }
        std::cout << "\n";
    }
    // =========================================================================
    // Service Scanner Commands
    // =========================================================================
    else if (command == "--scan-services" || command == "--scan-services-full") {
        bool fullScan = (command == "--scan-services-full");
        uint8_t startId = fullScan ? 0x00 : 0x40;
        uint8_t endId = fullScan ? 0xFF : 0x5F;

        std::cerr << "\n=== CLIP Service Scanner ===\n";
        std::cerr << (fullScan ? "Full Scan (0x00-0xFF)\n" : "Quick Scan (0x40-0x5F)\n");
        std::cerr << "=============================\n\n";

        ServiceScanner scanner(&adapter);
        scanner.setLogCallback(logCallback);
        scanner.setProgressCallback([](uint32_t current, uint32_t total, const std::string& msg) {
            int percent = (total > 0) ? static_cast<int>((current * 100) / total) : 0;
            std::cout << "\r[" << std::setw(3) << percent << "%] " << msg << std::flush;
        });

        auto results = scanner.scanServices(startId, endId);
        std::cout << "\n\n";

        // Tally results
        int found = 0, errors = 0, timeouts = 0;
        std::vector<TServiceProbeResult> foundServices;
        std::vector<TServiceProbeResult> errorServices;

        for (const auto& r : results) {
            if (r.responded) {
                if (r.isError) {
                    errors++;
                    errorServices.push_back(r);
                } else {
                    found++;
                    foundServices.push_back(r);
                }
            } else {
                timeouts++;
            }
        }

        // Print results
        std::cerr << "=== RESULTS ===\n\n";

        if (!foundServices.empty()) {
            std::cerr << "Services Found: " << found << "\n";
            for (const auto& r : foundServices) {
                std::cerr << "  0x" << std::hex << std::uppercase << std::setw(2)
                          << std::setfill('0') << static_cast<int>(r.serviceId)
                          << " -> Response 0x" << std::setw(2)
                          << static_cast<int>(r.responseCode)
                          << " (" << ServiceScanner::getServiceName(r.serviceId) << ")\n";
            }
            std::cerr << "\n";
        }

        if (!errorServices.empty()) {
            std::cerr << "Services with Errors: " << errors << "\n";
            for (const auto& r : errorServices) {
                std::cerr << "  0x" << std::hex << std::uppercase << std::setw(2)
                          << std::setfill('0') << static_cast<int>(r.serviceId)
                          << " -> Error code 0x" << std::setw(2)
                          << static_cast<int>(r.responseCode) << "\n";
            }
            std::cerr << "\n";
        }

        std::cerr << std::dec << "Not implemented (timeout): " << timeouts << "\n";
    }
    else if (command == "--probe-service") {
        if (outputArg.empty()) {
            std::cerr << "[ERROR] --probe-service requires a hex service ID (e.g., 4A)\n";
            result = 1;
        } else {
            // Parse hex service ID
            uint32_t serviceId;
            std::stringstream ss;
            ss << std::hex << outputArg;
            ss >> serviceId;

            if (serviceId > 0xFF) {
                std::cerr << "[ERROR] Service ID must be 0x00-0xFF\n";
                result = 1;
            } else {
                std::cerr << "\n=== Probing Service 0x" << std::hex << std::uppercase
                          << std::setw(2) << std::setfill('0') << serviceId << " ===\n\n";

                ServiceScanner scanner(&adapter);
                scanner.setLogCallback(logCallback);

                // Show request
                std::cerr << "Request:  " << std::hex << std::uppercase << std::setfill('0');
                std::cerr << std::setw(2) << serviceId << " 00 00 00 00 01 00 00\n";

                auto r = scanner.probeService(static_cast<uint8_t>(serviceId), 1000);

                if (r.responded) {
                    std::cerr << "Response: ";
                    for (int i = 0; i < r.responseLen; i++) {
                        std::cerr << std::setw(2) << static_cast<int>(r.rawResponse[i]) << " ";
                    }
                    std::cerr << "\n\n";

                    if (r.isError) {
                        std::cerr << "Status: ERROR - Service recognized but rejected (code 0x"
                                  << std::setw(2) << static_cast<int>(r.responseCode) << ")\n";
                    } else {
                        std::cerr << "Status: FOUND - " << ServiceScanner::getServiceName(r.responseCode) << "\n";
                    }
                } else {
                    std::cerr << "Response: (timeout)\n\n";
                    std::cerr << "Status: NOT IMPLEMENTED - No response from ECU\n";
                }
                std::cerr << std::dec;
            }
        }
    }
    // =========================================================================
    // Address Read Command
    // =========================================================================
    else if (command == "--read-addr") {
        if (argc < 5) {
            std::cerr << "[ERROR] --read-addr requires <hex-addr> <length>\n";
            std::cerr << "Example: --read-addr 801c7a 100\n";
            result = 1;
        } else {
            // Parse hex address
            uint32_t address;
            std::stringstream ss;
            ss << std::hex << argv[3];
            ss >> address;

            // Parse length
            int length = std::atoi(argv[4]);
            if (length < 1 || length > 255) {
                std::cerr << "[ERROR] Length must be 1-255\n";
                result = 1;
            } else {
                std::cerr << "[INFO] Reading " << std::dec << length
                          << " bytes from 0x" << std::hex << std::uppercase
                          << std::setw(8) << std::setfill('0') << address << "\n\n";

                std::vector<uint8_t> data;
                if (reader.readMemoryService4A(address, static_cast<uint8_t>(length), data)) {
                    // Hex dump with ASCII
                    std::cout << "Address    | 00 01 02 03 04 05 06 07  08 09 0A 0B 0C 0D 0E 0F | ASCII\n";
                    std::cout << "-----------+--------------------------------------------------+----------------\n";

                    for (size_t i = 0; i < data.size(); i += 16) {
                        // Address column
                        std::cout << std::hex << std::uppercase << std::setw(8)
                                  << std::setfill('0') << (address + i) << " | ";

                        // Hex bytes
                        for (size_t j = 0; j < 16; j++) {
                            if (i + j < data.size()) {
                                std::cout << std::setw(2) << static_cast<int>(data[i + j]) << " ";
                            } else {
                                std::cout << "   ";
                            }
                            if (j == 7) std::cout << " ";
                        }
                        std::cout << "| ";

                        // ASCII column
                        for (size_t j = 0; j < 16 && i + j < data.size(); j++) {
                            char c = static_cast<char>(data[i + j]);
                            std::cout << (isprint(c) ? c : '.');
                        }
                        std::cout << "\n";
                    }
                    std::cout << std::dec;
                } else {
                    std::cerr << "[ERROR] Failed to read memory\n";
                    result = 1;
                }
            }
        }
    }
    // =========================================================================
    // Memory Write Command (EXPERIMENTAL)
    // =========================================================================
    else if (command == "--write-addr") {
        if (argc < 5) {
            std::cerr << "[ERROR] --write-addr requires <hex-addr> <hex-value>\n";
            std::cerr << "Example: --write-addr 803586 B522\n";
            result = 1;
        } else {
            // Parse hex address
            uint32_t address;
            std::stringstream ssAddr;
            ssAddr << std::hex << argv[3];
            ssAddr >> address;

            // Parse hex value (1-4 hex chars = 1-2 bytes)
            std::string valueStr = argv[4];
            if (valueStr.length() > 4) {
                std::cerr << "[ERROR] Value must be 1-4 hex chars (1-2 bytes)\n";
                result = 1;
            } else {
                uint32_t value;
                std::stringstream ssVal;
                ssVal << std::hex << valueStr;
                ssVal >> value;

                // Convert value to bytes (big-endian for ECU)
                std::vector<uint8_t> data;
                if (value > 0xFF) {
                    // 2-byte value (big-endian)
                    data.push_back(static_cast<uint8_t>((value >> 8) & 0xFF));
                    data.push_back(static_cast<uint8_t>(value & 0xFF));
                } else {
                    // 1-byte value
                    data.push_back(static_cast<uint8_t>(value & 0xFF));
                }

                std::cerr << "\n";
                std::cerr << "╔════════════════════════════════════════════════════════╗\n";
                std::cerr << "║  ⚠️  EXPERIMENTAL MEMORY WRITE - USE AT OWN RISK  ⚠️    ║\n";
                std::cerr << "╠════════════════════════════════════════════════════════╣\n";
                std::cerr << "║  Address: 0x" << std::hex << std::uppercase
                          << std::setw(8) << std::setfill('0') << address
                          << "                             ║\n";
                std::cerr << "║  Value:   0x" << std::setw(4) << value
                          << " (" << std::dec << data.size() << " byte"
                          << (data.size() > 1 ? "s" : "") << ")"
                          << "                                 ║\n";
                std::cerr << "╚════════════════════════════════════════════════════════╝\n";
                std::cerr << std::dec;

                // First, read current value
                std::vector<uint8_t> currentData;
                if (reader.readMemoryService4A(address, static_cast<uint8_t>(data.size()), currentData)) {
                    std::cerr << "[INFO] Current value at 0x" << std::hex << std::uppercase
                              << std::setw(8) << std::setfill('0') << address << ": ";
                    for (size_t i = 0; i < currentData.size(); i++) {
                        std::cerr << std::setw(2) << static_cast<int>(currentData[i]);
                    }
                    std::cerr << std::dec << "\n";
                }

                // Attempt write
                std::cerr << "[INFO] Attempting write...\n";
                if (reader.writeMemoryService4A(address, data)) {
                    std::cerr << "[SUCCESS] Write command acknowledged!\n";

                    // Verify by reading back
                    std::vector<uint8_t> verifyData;
                    if (reader.readMemoryService4A(address, static_cast<uint8_t>(data.size()), verifyData)) {
                        std::cerr << "[INFO] Verification read: ";
                        bool match = (verifyData.size() == data.size());
                        for (size_t i = 0; i < verifyData.size(); i++) {
                            std::cerr << std::hex << std::uppercase << std::setw(2)
                                      << std::setfill('0') << static_cast<int>(verifyData[i]);
                            if (i < data.size() && verifyData[i] != data[i]) {
                                match = false;
                            }
                        }
                        std::cerr << std::dec << "\n";

                        if (match) {
                            std::cerr << "[✓] Write verified successfully!\n";
                        } else {
                            std::cerr << "[✗] Verification FAILED - value did not change\n";
                            std::cerr << "    (ECU may have rejected write, or address is read-only)\n";
                            result = 1;
                        }
                    }
                } else {
                    std::cerr << "[ERROR] Write failed - no acknowledgment from ECU\n";
                    result = 1;
                }
            }
        }
    }
    // =========================================================================
    // Service 0x4B Memory Write (RECOMMENDED - J1939 write path)
    // =========================================================================
    else if (command == "--write-service4b") {
        if (argc < 5) {
            std::cerr << "[ERROR] --write-service4b requires <hex-addr> <hex-value>\n";
            std::cerr << "Example: --write-service4b 800100 AA55\n";
            result = 1;
        } else {
            // Parse hex address
            uint32_t address;
            std::stringstream ss;
            ss << std::hex << argv[3];
            ss >> address;

            // Parse hex value
            std::vector<uint8_t> data;
            std::string valueStr = argv[4];
            for (size_t i = 0; i < valueStr.length(); i += 2) {
                if (i + 1 < valueStr.length()) {
                    uint8_t byte = static_cast<uint8_t>(
                        std::stoi(valueStr.substr(i, 2), nullptr, 16)
                    );
                    data.push_back(byte);
                }
            }

            if (data.empty()) {
                std::cerr << "[ERROR] Invalid hex value\n";
                result = 1;
            } else {
                std::cerr << "\n";
                std::cerr << "╔════════════════════════════════════════════════════════╗\n";
                std::cerr << "║  SERVICE 0x4B MEMORY WRITE (J1939 - Authenticated)     ║\n";
                std::cerr << "╠════════════════════════════════════════════════════════╣\n";
                std::cerr << "║  Address: 0x" << std::hex << std::uppercase
                          << std::setw(8) << std::setfill('0') << address << "                       ║\n";
                std::cerr << "║  Value:   0x";
                for (auto b : data) {
                    std::cerr << std::hex << std::uppercase << std::setw(2) << std::setfill('0')
                              << static_cast<int>(b);
                }
                std::cerr << " (" << std::dec << data.size() << " bytes)                              ║\n";
                std::cerr << "║  Valid RAM range: 0x800000 - 0x8091C1                   ║\n";
                std::cerr << "╚════════════════════════════════════════════════════════╝\n";
                std::cerr << std::dec;

                // Validate address range
                if (address < 0x800000 || address > 0x8091C1) {
                    std::cerr << "\n[WARNING] Address 0x" << std::hex << address << std::dec
                              << " is outside Main RAM range!\n";
                    std::cerr << "Main RAM: 0x800000 - 0x8091C1 (requires auth)\n";
                    std::cerr << "Extended RAM (0x8091DC+) may work without auth.\n\n";
                }

                // Step 1: Read hour meter
                std::cerr << "\n[1/3] Reading hour meter from ECU...\n";
                uint32_t hourMeter;
                if (!reader.readHourMeter(hourMeter)) {
                    std::cerr << "[ERROR] Failed to read hour meter\n";
                    result = 1;
                } else {
                    std::cerr << "[OK] Hour meter: 0x" << std::hex << std::uppercase
                              << std::setw(8) << std::setfill('0') << hourMeter << std::dec << "\n";

                    // Step 2: Show what will be sent
                    std::cerr << "\n[2/3] Generating auth payload...\n";
                    std::vector<uint8_t> authPayload;
                    if (SecurityAuth::generateAuthPayload(hourMeter, authPayload)) {
                        std::cerr << "[OK] Auth payload: ";
                        for (auto b : authPayload) {
                            std::cerr << std::hex << std::uppercase << std::setw(2)
                                      << std::setfill('0') << static_cast<int>(b) << " ";
                        }
                        std::cerr << std::dec << "\n";
                    }

                    // Step 3: Send authenticated write via Service 0x4B
                    std::cerr << "\n[3/3] Sending Service 0x4B write via J1939 TP...\n";
                    if (reader.writeMemoryService4B(address, data, hourMeter)) {
                        std::cerr << "\n[✓] Service 0x4B write completed and verified!\n";
                    } else {
                        std::cerr << "\n[✗] Service 0x4B write failed\n";
                        result = 1;
                    }
                }
            }
        }
    }
    // =========================================================================
    // Service 0x05 Memory Write (J1708 ONLY - won't work on CAN)
    // =========================================================================
    else if (command == "--write-service5") {
        if (argc < 5) {
            std::cerr << "[ERROR] --write-service5 requires <hex-addr> <hex-value>\n";
            std::cerr << "Example: --write-service5 800100 AA55\n";
            result = 1;
        } else {
            // Parse hex address
            uint32_t address;
            std::stringstream ss;
            ss << std::hex << argv[3];
            ss >> address;

            // Parse hex value
            std::vector<uint8_t> data;
            std::string valueStr = argv[4];
            for (size_t i = 0; i < valueStr.length(); i += 2) {
                if (i + 1 < valueStr.length()) {
                    uint8_t byte = static_cast<uint8_t>(
                        std::stoi(valueStr.substr(i, 2), nullptr, 16)
                    );
                    data.push_back(byte);
                }
            }

            if (data.empty()) {
                std::cerr << "[ERROR] Invalid hex value\n";
                result = 1;
            } else {
                std::cerr << "\n";
                std::cerr << "╔════════════════════════════════════════════════════════╗\n";
                std::cerr << "║  SERVICE 0x05 MEMORY WRITE (Authenticated + CRC)       ║\n";
                std::cerr << "╠════════════════════════════════════════════════════════╣\n";
                std::cerr << "║  Address: 0x" << std::hex << std::uppercase
                          << std::setw(8) << std::setfill('0') << address << "                       ║\n";
                std::cerr << "║  Value:   0x";
                for (auto b : data) {
                    std::cerr << std::hex << std::uppercase << std::setw(2) << std::setfill('0')
                              << static_cast<int>(b);
                }
                std::cerr << " (" << std::dec << data.size() << " bytes)                              ║\n";
                std::cerr << "║  Valid RAM range: 0x800000 - 0x8091C1                   ║\n";
                std::cerr << "╚════════════════════════════════════════════════════════╝\n";
                std::cerr << std::dec;

                // Validate address range
                if (address < 0x800000 || address > 0x8091C1) {
                    std::cerr << "\n[WARNING] Address 0x" << std::hex << address << std::dec
                              << " is outside Main RAM range!\n";
                    std::cerr << "Main RAM: 0x800000 - 0x8091C1 (requires auth)\n";
                    std::cerr << "Extended RAM (0x8091DC+) is NOT in validation table.\n\n";
                }

                // Step 1: Read hour meter
                std::cerr << "\n[1/3] Reading hour meter from ECU...\n";
                uint32_t hourMeter;
                if (!reader.readHourMeter(hourMeter)) {
                    std::cerr << "[ERROR] Failed to read hour meter\n";
                    result = 1;
                } else {
                    std::cerr << "[OK] Hour meter: 0x" << std::hex << std::uppercase
                              << std::setw(8) << std::setfill('0') << hourMeter << std::dec << "\n";

                    // Step 2: Show what will be sent
                    std::cerr << "\n[2/3] Generating auth payload and CRC...\n";
                    std::vector<uint8_t> authPayload;
                    if (SecurityAuth::generateAuthPayload(hourMeter, authPayload)) {
                        std::cerr << "[OK] Auth payload: ";
                        for (auto b : authPayload) {
                            std::cerr << std::hex << std::uppercase << std::setw(2)
                                      << std::setfill('0') << static_cast<int>(b) << " ";
                        }
                        std::cerr << std::dec << "\n";
                    }

                    // Step 3: Send authenticated write via Service 0x05
                    std::cerr << "\n[3/3] Sending Service 0x05 write via J1939 TP...\n";
                    if (reader.writeMemoryService5(address, data, hourMeter)) {
                        std::cerr << "\n[✓] Service 0x05 write completed and verified!\n";
                    } else {
                        std::cerr << "\n[✗] Service 0x05 write failed\n";
                        result = 1;
                    }
                }
            }
        }
    }
    // =========================================================================
    // Authenticated Memory Write Command (DEPRECATED - uses Service 0x4A)
    // =========================================================================
    else if (command == "--write-addr-auth") {
        if (argc < 5) {
            std::cerr << "[ERROR] --write-addr-auth requires <hex-addr> <hex-value>\n";
            std::cerr << "Example: --write-addr-auth 803064 AA55\n";
            result = 1;
        } else {
            // Parse hex address
            uint32_t address;
            std::stringstream ss;
            ss << std::hex << argv[3];
            ss >> address;

            // Parse hex value
            std::vector<uint8_t> data;
            std::string valueStr = argv[4];
            for (size_t i = 0; i < valueStr.length(); i += 2) {
                if (i + 1 < valueStr.length()) {
                    uint8_t byte = static_cast<uint8_t>(
                        std::stoi(valueStr.substr(i, 2), nullptr, 16)
                    );
                    data.push_back(byte);
                }
            }

            if (data.empty()) {
                std::cerr << "[ERROR] Invalid hex value\n";
                result = 1;
            } else {
                std::cerr << "\n";
                std::cerr << "╔════════════════════════════════════════════════════════╗\n";
                std::cerr << "║  ⚠️  AUTHENTICATED MEMORY WRITE - USE AT OWN RISK  ⚠️   ║\n";
                std::cerr << "╠════════════════════════════════════════════════════════╣\n";
                std::cerr << "║  Address: 0x" << std::hex << std::uppercase
                          << std::setw(8) << std::setfill('0') << address << "                       ║\n";
                std::cerr << "║  Value:   0x";
                for (auto b : data) {
                    std::cerr << std::hex << std::uppercase << std::setw(2) << std::setfill('0')
                              << static_cast<int>(b);
                }
                std::cerr << " (" << std::dec << data.size() << " bytes)                              ║\n";
                std::cerr << "╚════════════════════════════════════════════════════════╝\n";
                std::cerr << std::dec;

                // Step 1: Read hour meter
                std::cerr << "\n[1/3] Reading hour meter from ECU...\n";
                uint32_t hourMeter;
                if (!reader.readHourMeter(hourMeter)) {
                    std::cerr << "[ERROR] Failed to read hour meter\n";
                    result = 1;
                } else {
                    std::cerr << "[LOG] Hour meter: 0x" << std::hex << std::uppercase
                              << std::setw(8) << std::setfill('0') << hourMeter << std::dec << "\n";

                    // Step 2: Show auth payload that will be used
                    std::cerr << "\n[2/3] Generating auth payload...\n";
                    std::vector<uint8_t> authPayload;
                    if (SecurityAuth::generateAuthPayload(hourMeter, authPayload)) {
                        std::cerr << "[LOG] Auth payload: ";
                        for (auto b : authPayload) {
                            std::cerr << std::hex << std::uppercase << std::setw(2)
                                      << std::setfill('0') << static_cast<int>(b) << " ";
                        }
                        std::cerr << std::dec << "\n";
                    }

                    // Step 3: Send authenticated write
                    std::cerr << "\n[3/3] Sending authenticated write via J1939 TP...\n";
                    if (reader.writeMemoryService4AAuth(address, data, hourMeter)) {
                        std::cerr << "\n[✓] Authenticated write completed!\n";
                    } else {
                        std::cerr << "\n[✗] Authenticated write failed\n";
                        result = 1;
                    }
                }
            }
        }
    }
    // =========================================================================
    // CLIP Session Write Command (Proper protocol - command 0x15)
    // =========================================================================
    else if (command == "--write-clip") {
        if (argc < 5) {
            std::cerr << "[ERROR] --write-clip requires <hex-addr> <hex-value>\n";
            std::cerr << "Example: --write-clip 803064 AA55\n";
            result = 1;
        } else {
            // Parse hex address
            uint32_t address;
            std::stringstream ss;
            ss << std::hex << argv[3];
            ss >> address;

            // Parse hex value
            std::vector<uint8_t> data;
            std::string valueStr = argv[4];
            for (size_t i = 0; i < valueStr.length(); i += 2) {
                if (i + 1 < valueStr.length()) {
                    uint8_t byte = static_cast<uint8_t>(
                        std::stoi(valueStr.substr(i, 2), nullptr, 16)
                    );
                    data.push_back(byte);
                }
            }

            if (data.empty()) {
                std::cerr << "[ERROR] Invalid hex value\n";
                result = 1;
            } else {
                std::cerr << "\n";
                std::cerr << "╔════════════════════════════════════════════════════════╗\n";
                std::cerr << "║  CLIP SESSION WRITE (Command 0x15 - SetDataByAddress)  ║\n";
                std::cerr << "╠════════════════════════════════════════════════════════╣\n";
                std::cerr << "║  Address: 0x" << std::hex << std::uppercase
                          << std::setw(8) << std::setfill('0') << address << "                       ║\n";
                std::cerr << "║  Value:   0x";
                for (auto b : data) {
                    std::cerr << std::hex << std::uppercase << std::setw(2) << std::setfill('0')
                              << static_cast<int>(b);
                }
                std::cerr << " (" << std::dec << data.size() << " bytes)                              ║\n";
                std::cerr << "╚════════════════════════════════════════════════════════╝\n";
                std::cerr << std::dec;

                // Need to reconnect using CLIP session (not simple mode)
                reader.disconnect();

                std::cerr << "\n[1/4] Opening CLIP session with ECU...\n";
                if (!reader.connect(canDevice)) {
                    std::cerr << "[ERROR] Failed to establish CLIP session\n";
                    result = 1;
                } else {
                    // Read current value first
                    std::cerr << "\n[2/4] Reading current value at address...\n";
                    std::vector<uint8_t> currentData;
                    if (reader.readMemory(address, static_cast<uint16_t>(data.size()), currentData)) {
                        std::cerr << "[LOG] Current value: 0x";
                        for (auto b : currentData) {
                            std::cerr << std::hex << std::uppercase << std::setw(2)
                                      << std::setfill('0') << static_cast<int>(b);
                        }
                        std::cerr << std::dec << "\n";
                    }

                    // Attempt write using CLIP command 0x15
                    std::cerr << "\n[3/4] Sending SetDataByAddress (0x15)...\n";
                    if (reader.writeMemory(address, data)) {
                        std::cerr << "[LOG] Write command sent successfully\n";

                        // Verify by reading back
                        std::cerr << "\n[4/4] Verifying write...\n";
                        std::vector<uint8_t> verifyData;
                        if (reader.readMemory(address, static_cast<uint16_t>(data.size()), verifyData)) {
                            std::cerr << "[LOG] Read back: 0x";
                            bool match = (verifyData.size() == data.size());
                            for (size_t i = 0; i < verifyData.size(); i++) {
                                std::cerr << std::hex << std::uppercase << std::setw(2)
                                          << std::setfill('0') << static_cast<int>(verifyData[i]);
                                if (i < data.size() && verifyData[i] != data[i]) {
                                    match = false;
                                }
                            }
                            std::cerr << std::dec << "\n";

                            if (match) {
                                std::cerr << "\n[✓] CLIP write verified successfully!\n";
                            } else {
                                std::cerr << "\n[✗] Verification FAILED - value did not change\n";
                                result = 1;
                            }
                        }
                    } else {
                        std::cerr << "[ERROR] CLIP write failed\n";
                        result = 1;
                    }
                }
            }
        }
    }
    // =========================================================================
    // Live Security Authentication Command
    // =========================================================================
    else if (command == "--auth-live") {
        std::cerr << "\n=== Live ECU Authentication ===\n\n";

        // Addresses from firmware analysis (global_variables.csv)
        const uint32_t HOUR_METER_ADDR = 0x80BDA4;      // hour_meter_ecm_run_time_none
        const uint32_t SECURITY_ENABLED_ADDR = 0x803B98; // security_enabled
        const uint32_t SECURITY_RETRY_ADDR = 0x801E76;   // security_retry_counter

        // Read security_enabled flag first
        std::vector<uint8_t> secEnabled;
        if (reader.readMemoryService4A(SECURITY_ENABLED_ADDR, 1, secEnabled)) {
            std::cerr << "security_enabled @ 0x803B98: 0x"
                      << std::hex << std::uppercase << std::setw(2) << std::setfill('0')
                      << static_cast<int>(secEnabled[0]) << std::dec;
            if (secEnabled[0] == 0xFF) {
                std::cerr << " [SECURITY DISABLED - no auth needed!]\n";
            } else if (secEnabled[0] == 0x00) {
                std::cerr << " [SECURITY ENABLED]\n";
            } else {
                std::cerr << " [UNKNOWN STATE]\n";
            }
        }

        // Read retry counter
        std::vector<uint8_t> retryCounter;
        if (reader.readMemoryService4A(SECURITY_RETRY_ADDR, 1, retryCounter)) {
            std::cerr << "retry_counter @ 0x801E76:   0x"
                      << std::hex << std::uppercase << std::setw(2) << std::setfill('0')
                      << static_cast<int>(retryCounter[0]) << std::dec;
            if (retryCounter[0] >= 0x11) {
                std::cerr << " [LOCKED OUT! 17+ failed attempts]\n";
            } else {
                std::cerr << " [" << static_cast<int>(retryCounter[0]) << " failed attempts]\n";
            }
        }

        // Read hour meter (4 bytes, big-endian)
        std::vector<uint8_t> hourMeterBytes;
        if (!reader.readMemoryService4A(HOUR_METER_ADDR, 4, hourMeterBytes)) {
            std::cerr << "[ERROR] Failed to read hour meter from ECU\n";
            result = 1;
        } else {
            uint32_t hourMeter = (hourMeterBytes[0] << 24) | (hourMeterBytes[1] << 16) |
                                 (hourMeterBytes[2] << 8) | hourMeterBytes[3];

            std::cerr << "\nhour_meter @ 0x80BDA4:      0x"
                      << std::hex << std::uppercase << std::setw(8) << std::setfill('0')
                      << hourMeter << std::dec << "\n";
            std::cerr << "  Raw bytes: ";
            for (size_t i = 0; i < hourMeterBytes.size(); i++) {
                std::cerr << std::hex << std::uppercase << std::setw(2) << std::setfill('0')
                          << static_cast<int>(hourMeterBytes[i]) << " ";
            }
            std::cerr << std::dec << "\n\n";

            // Generate auth payload
            std::vector<uint8_t> payload;
            if (SecurityAuth::generateAuthPayload(hourMeter, payload)) {
                std::cerr << "=== Generated Auth Payload ===\n";
                std::cerr << "Hex: ";
                for (size_t i = 0; i < payload.size(); i++) {
                    std::cerr << std::hex << std::uppercase << std::setw(2) << std::setfill('0')
                              << static_cast<int>(payload[i]) << " ";
                }
                std::cerr << "\n";

                // Print as C array
                std::cerr << "C:   {";
                for (size_t i = 0; i < payload.size(); i++) {
                    std::cerr << "0x" << std::hex << std::uppercase << std::setw(2)
                              << std::setfill('0') << static_cast<int>(payload[i]);
                    if (i < payload.size() - 1) std::cerr << ", ";
                }
                std::cerr << "}\n\n" << std::dec;

                // Verify
                if (SecurityAuth::verifyPayload(payload, hourMeter)) {
                    std::cerr << "[VERIFIED] Payload generates correct output\n\n";

                    // Show what the ECU will see
                    std::vector<uint8_t> result;
                    SecurityAuth::bitPackingForward(payload, result);
                    std::cerr << "ECU will decode to:\n";
                    std::cerr << "  Security key: \"";
                    for (int i = 0; i < 6; i++) std::cerr << static_cast<char>(result[i]);
                    std::cerr << "\"\n";
                    std::cerr << "  Hour meter:   0x" << std::hex << std::uppercase;
                    for (int i = 6; i < 10; i++) {
                        std::cerr << std::setw(2) << std::setfill('0') << static_cast<int>(result[i]);
                    }
                    std::cerr << std::dec << "\n";
                } else {
                    std::cerr << "[ERROR] Verification failed!\n";
                    result = 1;
                }
            } else {
                std::cerr << "[ERROR] Failed to generate auth payload\n";
                result = 1;
            }
        }
    }
    else {
        std::cerr << "[ERROR] Unknown command: " << command << "\n";
        printUsage(argv[0]);
        result = 1;
    }

    // Disconnect
    reader.disconnect();
    std::cerr << "[INFO] Disconnected from ECU\n";

    if (result == 0) {
        std::cerr << "[INFO] Done!\n";
    }

    return result;
}
