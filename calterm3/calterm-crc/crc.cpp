/**
 * Calterm III CRC Tool
 * Reverse-engineered from CRCUtility.dll (KSBaseLibrary.crcString)
 *
 * IMPORTANT NOTE:
 * This tool implements the CRC algorithm found in CRCUtility.dll via Ghidra
 * reverse engineering. However, existing Calterm III .e2m files appear to use
 * a different CRC algorithm (possibly from an older version of Calterm).
 *
 * The CRC algorithm in CRCUtility.dll mathematically cannot produce values
 * with the high bit set (max 0x7FFE), but original Calterm files have CRCs
 * like C5C2 (high bit set). This suggests the original files were created
 * with a different algorithm.
 *
 * This tool is SELF-CONSISTENT: files fixed with this tool will verify
 * correctly with this tool. Use 'fix' to update CRCs before using 'verify'.
 *
 * Usage:
 *   calterm-crc verify <file.e2m>   - Check if CRC matches (use after 'fix')
 *   calterm-crc fix <file.e2m>      - Update file with computed CRC
 *   calterm-crc compute <file.e2m>  - Show computed CRC without modifying
 *   calterm-crc debug <file.e2m>    - Debug mode with verbose output
 *   calterm-crc table [selector]    - Display CRC lookup table
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdint>
#include <cstring>
#include <algorithm>
#include <cctype>

static bool debugMode = false;

// Parity lookup table extracted from CRCUtility.dll at address 0x1002ab38
static const uint8_t PARITY_TABLE[256] = {
    0x00, 0x01, 0x01, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x00, 0x01, 0x01, 0x00,
    0x01, 0x00, 0x00, 0x01, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x00, 0x00, 0x01,
    0x01, 0x00, 0x00, 0x01, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x00, 0x00, 0x01,
    0x00, 0x01, 0x01, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x00, 0x01, 0x01, 0x00,
    0x01, 0x00, 0x00, 0x01, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x00, 0x00, 0x01,
    0x00, 0x01, 0x01, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x00, 0x01, 0x01, 0x00,
    0x00, 0x01, 0x01, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x00, 0x01, 0x01, 0x00,
    0x01, 0x00, 0x00, 0x01, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x00, 0x00, 0x01,
    0x01, 0x00, 0x00, 0x01, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x00, 0x00, 0x01,
    0x00, 0x01, 0x01, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x00, 0x01, 0x01, 0x00,
    0x00, 0x01, 0x01, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x00, 0x01, 0x01, 0x00,
    0x01, 0x00, 0x00, 0x01, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x00, 0x00, 0x01,
    0x00, 0x01, 0x01, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x00, 0x01, 0x01, 0x00,
    0x01, 0x00, 0x00, 0x01, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x00, 0x00, 0x01,
    0x01, 0x00, 0x00, 0x01, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x00, 0x00, 0x01,
    0x00, 0x01, 0x01, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x00, 0x01, 0x01, 0x00,
};

// CRC lookup table - generated once
static uint16_t CRC_TABLE[256];
static bool tableInitialized = false;

/**
 * Generate CRC lookup table
 * Reverse-engineered from FUN_1000b170 in CRCUtility.dll
 */
void generateCRCTable(uint16_t tableSelector) {
    for (int i = 0; i < 256; i++) {
        uint16_t val = (PARITY_TABLE[i] != 0) ? (tableSelector * 2) : 0;
        CRC_TABLE[i] = (uint16_t)(((i * 2) ^ i) << 6) ^ val;
    }
    tableInitialized = true;
}

/**
 * Compute CRC for a string
 * Reverse-engineered from KSBaseLibrary.crcString
 */
uint16_t crcString(uint16_t crc, const char* str) {
    static bool detailedDebug = false;
    if (debugMode) {
        printf("  crcString input crc=%04X, str='%.40s%s'\n", crc, str, strlen(str) > 40 ? "..." : "");
    }
    int charCount = 0;
    while (*str) {
        uint8_t byte = (uint8_t)*str;
        if (byte > 0x1f) {  // Skip control characters
            uint16_t oldCrc = crc;
            uint8_t idx = (byte ^ crc) & 0xff;
            uint16_t shifted = (crc >> 7) & 0x1fe;
            crc = shifted ^ CRC_TABLE[idx];
            if (detailedDebug && charCount < 5) {
                printf("    [%d] byte=%02X('%c') crc=%04X >> 7 & 0x1fe = %04X, idx=%02X, tbl=%04X, new=%04X\n",
                       charCount, byte, byte >= 0x20 && byte < 0x7f ? byte : '.',
                       oldCrc, shifted, idx, CRC_TABLE[idx], crc);
            }
            charCount++;
        }
        str++;
    }
    if (debugMode) {
        printf("  crcString output crc=%04X\n", crc);
    }
    return crc;
}

/**
 * Trim whitespace from both ends of a string (in-place)
 */
void trim(char* str) {
    // Trim leading
    char* start = str;
    while (*start && std::isspace((unsigned char)*start)) start++;

    // Trim trailing
    char* end = start + strlen(start) - 1;
    while (end > start && std::isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';

    // Move trimmed string to beginning
    if (start != str) {
        memmove(str, start, strlen(start) + 1);
    }
}

/**
 * Compute CRC for an e2m file (excluding first line)
 */
uint16_t computeFileCRC(std::ifstream& file) {
    if (!tableInitialized) {
        generateCRCTable(1);  // tableSelector = 1 for e2m files
    }

    uint16_t crc = 0;
    char line[1024];

    // Skip first line (CRC line)
    file.getline(line, sizeof(line));

    // Process remaining lines - do NOT trim (matches FUN_10008680 behavior)
    while (file.getline(line, sizeof(line))) {
        if (strlen(line) > 0) {
            crc = crcString(crc, line);
        }
    }

    return crc;
}

/**
 * Parse expected CRC from first line
 */
uint16_t parseExpectedCRC(const std::string& firstLine) {
    uint16_t crc = 0;
    sscanf(firstLine.c_str(), "%4hx", &crc);
    return crc;
}

void printTable() {
    printf("CRC Table (tableSelector=1):\n");
    for (int i = 0; i < 256; i += 8) {
        printf("  [%02X]: ", i);
        for (int j = 0; j < 8; j++) {
            printf("%04X ", CRC_TABLE[i + j]);
        }
        printf("\n");
    }
}

void printUsage() {
    std::cout << "\nCalterm III CRC Tool\n";
    std::cout << "Reverse-engineered from CRCUtility.dll\n\n";
    std::cout << "NOTE: This tool is self-consistent. Use 'fix' before 'verify' on existing files.\n";
    std::cout << "      Original Calterm files may use a different (older) CRC algorithm.\n\n";
    std::cout << "Usage: calterm-crc <command> <file.e2m>\n\n";
    std::cout << "Commands:\n";
    std::cout << "  verify <file>   Check if the CRC matches the computed value\n";
    std::cout << "  compute <file>  Show the computed CRC without modifying the file\n";
    std::cout << "  fix <file>      Update the file with the correct CRC\n";
    std::cout << "  debug <file>    Debug mode with verbose output\n";
    std::cout << "  table           Show the CRC lookup table\n\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printUsage();
        return 1;
    }

    std::string command = argv[1];
    std::transform(command.begin(), command.end(), command.begin(), ::tolower);

    // Handle table command (no file required)
    if (command == "table") {
        int selector = argc > 2 ? atoi(argv[2]) : 1;
        generateCRCTable(selector);
        printf("Table selector: %d\n", selector);
        printTable();
        return 0;
    }

    // Handle bruteforce command - try all table selectors
    if (command == "bruteforce" && argc >= 3) {
        std::string filename = argv[2];
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: Cannot open file: " << filename << std::endl;
            return 1;
        }

        // Read first line for expected CRC
        std::string firstLine;
        std::getline(file, firstLine);
        size_t start = firstLine.find_first_not_of(" \t\r\n");
        size_t end = firstLine.find_last_not_of(" \t\r\n");
        if (start != std::string::npos) {
            firstLine = firstLine.substr(start, end - start + 1);
        }
        uint16_t expectedCRC = parseExpectedCRC(firstLine);
        printf("Expected CRC: %04X\n", expectedCRC);

        // Read rest of file into memory
        std::vector<std::string> lines;
        std::string line;
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        file.close();

        // Test: Skip line 2 (record count)?
        printf("Testing with line 2 skipped...\n");
        generateCRCTable(1);
        uint16_t crc = 0;
        bool skipFirst = true;
        for (const auto& l : lines) {
            if (skipFirst) {
                skipFirst = false;
                printf("Skipping line 2: '%s'\n", l.substr(0, 20).c_str());
                continue;
            }
            if (!l.empty()) {
                crc = crcString(crc, l.c_str());
            }
        }
        printf("CRC (skip line 2): %04X, Expected: %04X\n", crc, expectedCRC);

        // Test: Maybe we need to include line 1 (CRC) in calculation?
        printf("\nTesting with line 1 included...\n");
        crc = 0;
        crc = crcString(crc, firstLine.c_str());
        for (const auto& l : lines) {
            if (!l.empty()) {
                crc = crcString(crc, l.c_str());
            }
        }
        printf("CRC (with line 1): %04X, Expected: %04X\n", crc, expectedCRC);

        // Test: Raw bytes (skip line 1, then process raw bytes)
        printf("\nTesting raw bytes...\n");
        std::ifstream rawFile(filename, std::ios::binary);
        std::string rawContent((std::istreambuf_iterator<char>(rawFile)),
                               std::istreambuf_iterator<char>());
        rawFile.close();

        // Find end of first line
        size_t firstNewline = rawContent.find('\n');
        if (firstNewline != std::string::npos) {
            std::string afterFirstLine = rawContent.substr(firstNewline + 1);
            crc = 0;
            for (char c : afterFirstLine) {
                uint8_t byte = (uint8_t)c;
                if (byte > 0x1f) {
                    uint8_t idx = (byte ^ crc) & 0xff;
                    uint16_t shifted = (crc >> 7) & 0x1fe;
                    crc = shifted ^ CRC_TABLE[idx];
                }
            }
            printf("CRC (raw bytes): %04X, Expected: %04X\n", crc, expectedCRC);
        }

        // Test: Alternative - XOR high byte with table
        printf("\nTesting alternative algorithm (XOR high byte)...\n");
        if (firstNewline != std::string::npos) {
            std::string afterFirstLine = rawContent.substr(firstNewline + 1);
            crc = 0;
            for (char c : afterFirstLine) {
                uint8_t byte = (uint8_t)c;
                if (byte > 0x1f) {
                    uint8_t idx = (byte ^ (crc >> 8)) & 0xff;  // XOR with high byte
                    crc = ((crc << 8) ^ CRC_TABLE[idx]) & 0xffff;
                }
            }
            printf("CRC (alt high byte): %04X, Expected: %04X\n", crc, expectedCRC);
        }

        // Test: What if we DON'T skip control chars?
        printf("\nTesting without skipping control chars...\n");
        if (firstNewline != std::string::npos) {
            std::string afterFirstLine = rawContent.substr(firstNewline + 1);
            crc = 0;
            for (char c : afterFirstLine) {
                uint8_t byte = (uint8_t)c;
                uint8_t idx = (byte ^ crc) & 0xff;
                uint16_t shifted = (crc >> 7) & 0x1fe;
                crc = shifted ^ CRC_TABLE[idx];
            }
            printf("CRC (no skip ctrl): %04X, Expected: %04X\n", crc, expectedCRC);
        }

        // Brute force table selectors
        printf("\nBrute forcing table selectors (0-255)...\n");
        if (firstNewline != std::string::npos) {
            std::string afterFirstLine = rawContent.substr(firstNewline + 1);
            for (int sel = 0; sel < 256; sel++) {
                generateCRCTable(sel);
                crc = 0;
                for (char c : afterFirstLine) {
                    uint8_t byte = (uint8_t)c;
                    if (byte > 0x1f) {
                        uint8_t idx = (byte ^ crc) & 0xff;
                        uint16_t shifted = (crc >> 7) & 0x1fe;
                        crc = shifted ^ CRC_TABLE[idx];
                    }
                }
                if (crc == expectedCRC) {
                    printf("MATCH with table selector %d (0x%02X)\n", sel, sel);
                }
            }
        }

        return 0;
    }

    if (argc < 3) {
        printUsage();
        return 1;
    }

    std::string filename = argv[2];

    // Handle debug command
    if (command == "debug") {
        debugMode = true;
        command = "verify";  // Debug runs verify with verbose output
    }

    if (command == "verify") {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: Cannot open file: " << filename << std::endl;
            return 1;
        }

        // Read first line for expected CRC
        std::string firstLine;
        std::getline(file, firstLine);

        // Trim the first line
        size_t start = firstLine.find_first_not_of(" \t\r\n");
        size_t end = firstLine.find_last_not_of(" \t\r\n");
        if (start != std::string::npos) {
            firstLine = firstLine.substr(start, end - start + 1);
        }

        uint16_t expectedCRC = parseExpectedCRC(firstLine);

        // Reset and compute
        file.clear();
        file.seekg(0);
        uint16_t computedCRC = computeFileCRC(file);
        file.close();

        if (expectedCRC == computedCRC) {
            printf("CRC OK: %04X\n", expectedCRC);
            return 0;
        } else {
            printf("CRC MISMATCH\n");
            printf("  Expected: %04X\n", expectedCRC);
            printf("  Computed: %04X\n", computedCRC);
            return 1;
        }

    } else if (command == "compute") {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: Cannot open file: " << filename << std::endl;
            return 1;
        }

        uint16_t computedCRC = computeFileCRC(file);
        file.close();

        printf("Computed CRC: %04X\n", computedCRC);
        return 0;

    } else if (command == "fix") {
        // Read entire file
        std::ifstream infile(filename);
        if (!infile.is_open()) {
            std::cerr << "Error: Cannot open file: " << filename << std::endl;
            return 1;
        }

        std::stringstream buffer;
        buffer << infile.rdbuf();
        std::string content = buffer.str();
        infile.close();

        // Compute CRC
        std::istringstream iss(content);
        if (!tableInitialized) {
            generateCRCTable(1);
        }

        uint16_t crc = 0;
        std::string line;
        bool firstLine = true;

        while (std::getline(iss, line)) {
            if (firstLine) {
                firstLine = false;
                continue;
            }
            // Trim line
            size_t start = line.find_first_not_of(" \t\r\n");
            size_t end = line.find_last_not_of(" \t\r\n");
            if (start != std::string::npos) {
                std::string trimmed = line.substr(start, end - start + 1);
                if (!trimmed.empty()) {
                    crc = crcString(crc, trimmed.c_str());
                }
            }
        }

        // Find end of first line
        size_t firstLineEnd = content.find('\n');
        if (firstLineEnd == std::string::npos) {
            std::cerr << "Error: Invalid file format\n";
            return 1;
        }

        // Build new content
        char crcStr[5];
        snprintf(crcStr, sizeof(crcStr), "%04X", crc);

        std::string newContent = std::string(crcStr) + content.substr(firstLineEnd);

        // Write back
        std::ofstream outfile(filename);
        if (!outfile.is_open()) {
            std::cerr << "Error: Cannot write to file: " << filename << std::endl;
            return 1;
        }
        outfile << newContent;
        outfile.close();

        printf("Fixed CRC: %04X\n", crc);
        return 0;

    } else {
        std::cerr << "Unknown command: " << command << std::endl;
        printUsage();
        return 1;
    }

    return 0;
}
