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
    std::cerr << "Other:\n";
    std::cerr << "  --help, -h                  Show this help\n\n";
    std::cerr << "Examples:\n";
    std::cerr << "  " << progname << " can0 --dump-ram\n";
    std::cerr << "  " << progname << " can0 --dump-eeprom cm550_eeprom.bin\n";
    std::cerr << "  " << progname << " can0 --scan-services\n";
    std::cerr << "  " << progname << " can0 --probe-service 4A\n";
    std::cerr << "  " << progname << " can0 --read-addr 801c7a 100\n\n";
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
