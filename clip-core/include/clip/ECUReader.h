#ifndef ECUREADER_H
#define ECUREADER_H

#include <cstdint>
#include <vector>
#include <string>
#include <functional>
#include "ICanAdapter.h"
#include "J1939MessageBuilder.h"
#include "J1939TransportProtocol.h"
#include "CLIPInstructionBuilder.h"
#include "CLIPTransportLayer.h"
#include "CLIPSessionManager.h"

/**
 * @brief High-level API for reading data from Cummins ECUs.
 *
 * This class provides a simple interface for the display layer to
 * communicate with ECUs via the CLIP protocol.
 *
 * Features:
 *   - Connect/disconnect to ECUs
 *   - Read raw memory (firmware extraction)
 *   - Read parameters by ID
 *   - Dump memory regions to files
 *
 * Usage:
 *   SocketCanAdapter adapter;
 *   ECUReader reader(&adapter);
 *
 *   if (reader.connect("can0", 0x00)) {
 *       std::vector<uint8_t> data;
 *       reader.readMemory(0x00000000, 1024, data);
 *       reader.disconnect();
 *   }
 */
class ECUReader
{
public:
    /**
     * @brief Progress callback for long operations.
     * @param current Current byte/item number
     * @param total Total bytes/items
     * @param message Status message
     */
    using ProgressCallback = std::function<void(uint32_t current, uint32_t total, const std::string& message)>;

    /**
     * @brief Log callback for debugging.
     */
    using LogCallback = std::function<void(const std::string& message)>;

    /**
     * @brief Construct ECUReader with a CAN adapter.
     * @param adapter CAN adapter (must remain valid for lifetime of ECUReader)
     */
    explicit ECUReader(ICanAdapter* adapter);
    ~ECUReader();

    // Prevent copying
    ECUReader(const ECUReader&) = delete;
    ECUReader& operator=(const ECUReader&) = delete;

    /**
     * @brief Set progress callback for long operations.
     */
    void setProgressCallback(ProgressCallback callback);

    /**
     * @brief Set log callback for debugging.
     */
    void setLogCallback(LogCallback callback);

    /**
     * @brief Connect to an ECU.
     * @param canDevice CAN device name (e.g., "can0", "vcan0")
     * @param ecuAddress ECU address (typically 0x00)
     * @return true if connection successful
     */
    bool connect(const std::string& canDevice, uint8_t ecuAddress = 0x00);

    /**
     * @brief Disconnect from ECU.
     */
    void disconnect();

    /**
     * @brief Check if connected to ECU.
     */
    bool isConnected() const;

    /**
     * @brief Read raw memory from ECU.
     * @param address Memory address
     * @param length Number of bytes to read
     * @param data Output: read data
     * @return true if read successful
     *
     * This is the key method for firmware extraction!
     * Max length per call: 0xD000 bytes (52,224)
     */
    bool readMemory(uint32_t address, uint16_t length, std::vector<uint8_t>& data);

    /**
     * @brief Read a large memory region (handles chunking automatically).
     * @param address Starting address
     * @param totalLength Total bytes to read
     * @param data Output: read data
     * @return true if all reads successful
     */
    bool readMemoryLarge(uint32_t address, uint32_t totalLength, std::vector<uint8_t>& data);

    /**
     * @brief Read parameter by ID.
     * @param paramId Parameter ID
     * @param data Output: parameter value
     * @return true if read successful
     */
    bool readParameter(uint16_t paramId, std::vector<uint8_t>& data);

    /**
     * @brief Read multiple parameters by ID.
     * @param paramIds List of parameter IDs
     * @param data Output: combined parameter data
     * @return true if read successful
     */
    bool readParameters(const std::vector<uint16_t>& paramIds, std::vector<uint8_t>& data);

    /**
     * @brief Dump memory region to a binary file.
     * @param address Starting address
     * @param length Total bytes to dump
     * @param outputPath Output file path
     * @return true if dump successful
     */
    bool dumpMemoryToFile(uint32_t address, uint32_t length, const std::string& outputPath);

    /**
     * @brief Get address for a parameter ID.
     * @param paramId Parameter ID
     * @param address Output: memory address
     * @return true if lookup successful
     */
    bool getParameterAddress(uint16_t paramId, uint32_t& address);

    /**
     * @brief Get the last seed received from ECU (for debugging).
     */
    const TSeedReply& getLastSeed() const;

    /**
     * @brief Write memory to ECU using CLIP SetDataByAddress (0x15).
     * @param address Memory address
     * @param data Data to write
     * @return true if write succeeded
     *
     * NOTE: Requires connect() first (establishes CLIP session).
     * Uses CLIP command 0x15 - the proper way to write memory.
     */
    bool writeMemory(uint32_t address, const std::vector<uint8_t>& data);

    // =========================================================================
    // Service 0x4A Memory Read Methods (Direct, No CLIP Session)
    // =========================================================================
    // These methods bypass CLIP session management and use Service 0x4A directly.
    // This is the WORKING approach for CM550 ECUs.

    /**
     * @brief Connect to ECU without CLIP session (for Service 0x4A).
     * @param canDevice CAN device name (e.g., "can0")
     * @param ecuAddress ECU address (typically 0x00)
     * @return true if CAN adapter opened successfully
     *
     * This is a lightweight connect that just opens the CAN adapter.
     * Use with readMemoryService4A().
     */
    bool connectSimple(const std::string& canDevice, uint8_t ecuAddress = 0x00);

    /**
     * @brief Read memory using Service 0x4A (direct, no CLIP session).
     * @param address 32-bit memory address
     * @param length Bytes to read (max 255 per call)
     * @param data Output: read data
     * @param timeoutMs Timeout in milliseconds
     * @return true if read successful
     *
     * This is the WORKING method for CM550 memory dumps.
     * Response comes via J1939 Transport Protocol (RTS/CTS/DT).
     */
    bool readMemoryService4A(uint32_t address, uint8_t length,
                            std::vector<uint8_t>& data, int timeoutMs = 5000);

    /**
     * @brief Read large memory region using Service 0x4A.
     * @param address Starting address
     * @param totalLength Total bytes to read
     * @param data Output: read data
     * @param chunkSize Bytes per read (max 255, default 128)
     * @return true if all reads successful
     */
    bool readMemoryService4ALarge(uint32_t address, uint32_t totalLength,
                                  std::vector<uint8_t>& data, uint8_t chunkSize = 128);

    /**
     * @brief Dump memory region to file using Service 0x4A.
     * @param address Starting address
     * @param length Total bytes to dump
     * @param outputPath Output file path
     * @return true if dump successful
     */
    bool dumpMemoryService4AToFile(uint32_t address, uint32_t length,
                                   const std::string& outputPath);

    // =========================================================================
    // Service 0x4A Memory Write Methods (Experimental)
    // =========================================================================
    // These methods attempt to write to ECU memory using Service 0x4A format.
    // WARNING: Use at your own risk! Writing to wrong addresses can brick ECU.

    /**
     * @brief Write memory using Service 0x4A format (experimental).
     * @param address 32-bit memory address
     * @param data Data to write (max 2 bytes for single frame)
     * @param timeoutMs Timeout in milliseconds
     * @return true if write acknowledged
     *
     * Format: [0x4A][addr:4][len:1][data:2]
     *
     * This is experimental - the ECU may or may not accept writes this way.
     * For testing security_bypass_flag at 0x803586 with value 0xB522.
     */
    bool writeMemoryService4A(uint32_t address, const std::vector<uint8_t>& data,
                              int timeoutMs = 5000);

    /**
     * @brief Write memory with authentication using Service 0x4A format.
     * @param address 32-bit memory address
     * @param data Data to write
     * @param hourMeter Current ECU hour meter value (for auth payload generation)
     * @param timeoutMs Timeout in milliseconds
     * @return true if write acknowledged
     *
     * Format: [0x4A][addr:4][len:1][data:N][auth:10]
     *
     * This sends via J1939 Transport Protocol (RTS/CTS) since message > 8 bytes.
     * The auth payload is generated from the security key "ABCDEF" + hour_meter.
     */
    bool writeMemoryService4AAuth(uint32_t address, const std::vector<uint8_t>& data,
                                  uint32_t hourMeter, int timeoutMs = 5000);

    /**
     * @brief Get current hour meter from ECU for authentication.
     * @param hourMeter Output: hour meter value
     * @param timeoutMs Timeout in milliseconds
     * @return true if read successful
     *
     * Reads 4 bytes from 0x80BDA4 (hour_meter_ecm_run_time_none).
     */
    bool readHourMeter(uint32_t& hourMeter, int timeoutMs = 5000);

private:
    ICanAdapter* m_adapter;
    J1939MessageBuilder m_j1939;
    CLIPInstructionBuilder m_builder;
    CLIPTransportLayer m_transport;
    CLIPSessionManager m_session;
    bool m_connected;
    uint8_t m_ecuAddress;  // ECU address for Service 0x4A operations
    ProgressCallback m_progressCallback;
    LogCallback m_logCallback;

    void log(const std::string& message);
    void reportProgress(uint32_t current, uint32_t total, const std::string& message);

    // Build Service 0x4A request frame
    void buildService4ARequest(uint32_t address, uint8_t length, uint8_t* data);
};

#endif // ECUREADER_H
