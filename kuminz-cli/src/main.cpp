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
#include <clip/types/TClipPacket.h>

#include <iostream>
#include <iomanip>
#include <csignal>
#include <cstring>

// Global flag for clean shutdown on Ctrl+C
volatile bool g_running = true;

void signalHandler(int)
{
    g_running = false;
    std::cerr << "\n[INFO] Interrupted - shutting down...\n";
}

void printUsage(const char* progname)
{
    std::cerr << "kuminz-cli - CM550 ECU Memory Dump Tool\n\n";
    std::cerr << "Usage:\n";
    std::cerr << "  " << progname << " <can-interface> <command> [options]\n\n";
    std::cerr << "Commands:\n";
    std::cerr << "  --dump-ram [file]           Dump main RAM (37KB) to file\n";
    std::cerr << "  --dump-extended-ram [file]  Dump extended RAM (28KB) to file\n";
    std::cerr << "  --dump-eeprom [file]        Dump EEPROM (4KB) to file\n";
    std::cerr << "  --dump-rom [file]           Dump ROM/Flash (256KB) to file\n";
    std::cerr << "  --dump-all [dir]            Dump all regions to directory\n";
    std::cerr << "  --help, -h                  Show this help\n\n";
    std::cerr << "Examples:\n";
    std::cerr << "  " << progname << " can0 --dump-ram\n";
    std::cerr << "  " << progname << " can0 --dump-eeprom cm550_eeprom.bin\n";
    std::cerr << "  " << progname << " can0 --dump-all ./dumps/\n\n";
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
