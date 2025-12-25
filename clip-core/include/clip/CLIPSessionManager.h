#ifndef CLIPSESSIONMANAGER_H
#define CLIPSESSIONMANAGER_H

#include <cstdint>
#include <vector>
#include <string>
#include <functional>
#include "types/ESessionState.h"
#include "types/TClipPacket.h"
#include "CLIPTransportLayer.h"
#include "CLIPInstructionBuilder.h"

/**
 * @brief Manages CLIP session state and authentication.
 *
 * Session state machine:
 *   CLOSED (0x01) → REQUESTING_SEED (0x04) → SEEDED (0x05) → AUTHENTICATED (0x07)
 *
 * Authentication flow:
 *   1. Send Open Request
 *   2. Receive Seed Reply (msg type 0x02, 4-byte seed)
 *   3. Send Encrypted Context (proprietary cipher) [NOT YET IMPLEMENTED]
 *   4. Receive Context Reply (msg type 0x04)
 *   5. Session authenticated, data transfer enabled
 *
 * Note: The encryption algorithm is proprietary and needs reverse-engineering
 * from DeviceControl_ghidra.c:67039-67207. Currently, only unauthenticated
 * sessions are supported.
 *
 * Reference: ECU_PROGRAMMING_PROTOCOL.md, DeviceControl_ghidra.c:66987-67758
 */
class CLIPSessionManager
{
public:
    /**
     * @brief Callback for state changes.
     */
    using StateCallback = std::function<void(ESessionState oldState, ESessionState newState)>;

    /**
     * @brief Callback for logging/debugging.
     */
    using LogCallback = std::function<void(const std::string& message)>;

    CLIPSessionManager(CLIPTransportLayer* transport, CLIPInstructionBuilder* builder);
    ~CLIPSessionManager() = default;

    /**
     * @brief Get current session state.
     */
    ESessionState getState() const;

    /**
     * @brief Check if session allows data transfer.
     */
    bool isAuthenticated() const;

    /**
     * @brief Set state change callback.
     */
    void setStateCallback(StateCallback callback);

    /**
     * @brief Set log callback.
     */
    void setLogCallback(LogCallback callback);

    /**
     * @brief Open a session to the ECU.
     * @param ecuAddress ECU address
     * @param timeoutMs Timeout in milliseconds
     * @return true if session opened successfully
     *
     * Note: Full authentication requires encryption which is not yet implemented.
     * This may only work for unauthenticated/open ECUs.
     */
    bool openSession(uint8_t ecuAddress, int timeoutMs = CLIP_SESSION_TIMEOUT_MS);

    /**
     * @brief Close the current session.
     */
    void closeSession();

    /**
     * @brief Send a CLIP command and wait for response.
     * @param packet Command packet
     * @param response Output: response data
     * @param timeoutMs Timeout in milliseconds
     * @return true if command succeeded
     */
    bool sendCommand(const TClipPacket& packet,
                     std::vector<uint8_t>& response,
                     int timeoutMs = CLIP_DEFAULT_TIMEOUT_MS);

    /**
     * @brief Read memory from ECU using GetDataByAddress.
     * @param address Memory address
     * @param length Number of bytes to read
     * @param data Output: read data
     * @param timeoutMs Timeout in milliseconds
     * @return true if read succeeded
     */
    bool readMemory(uint32_t address, uint16_t length,
                    std::vector<uint8_t>& data,
                    int timeoutMs = CLIP_DEFAULT_TIMEOUT_MS);

    /**
     * @brief Read a parameter by ID.
     * @param paramId Parameter ID
     * @param data Output: parameter data
     * @param timeoutMs Timeout in milliseconds
     * @return true if read succeeded
     */
    bool readParameter(uint16_t paramId,
                       std::vector<uint8_t>& data,
                       int timeoutMs = CLIP_DEFAULT_TIMEOUT_MS);

    /**
     * @brief Write memory to ECU using SetDataByAddress (0x15).
     * @param address Memory address
     * @param data Data to write
     * @param timeoutMs Timeout in milliseconds
     * @return true if write succeeded
     *
     * NOTE: This requires an open authenticated session (openSession first).
     * CM550 ECUs don't enforce security, so session can proceed without encryption.
     */
    bool writeMemory(uint32_t address,
                     const std::vector<uint8_t>& data,
                     int timeoutMs = CLIP_DEFAULT_TIMEOUT_MS);

    /**
     * @brief Get the last received seed (for debugging/reverse engineering).
     */
    const TSeedReply& getLastSeed() const;

private:
    CLIPTransportLayer* m_transport;
    CLIPInstructionBuilder* m_builder;
    ESessionState m_state;
    TSeedReply m_lastSeed;
    StateCallback m_stateCallback;
    LogCallback m_logCallback;

    void setState(ESessionState newState);
    void log(const std::string& message);
};

#endif // CLIPSESSIONMANAGER_H
