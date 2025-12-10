#ifndef CLIPTRANSPORTLAYER_H
#define CLIPTRANSPORTLAYER_H

#include <cstdint>
#include <vector>
#include <functional>
#include "../types/ICanAdapter.h"
#include "types/EClipCommand.h"
#include "types/TClipPacket.h"
#include "J1939MessageBuilder.h"

/**
 * @brief Handles CLIP transport layer (multi-packet fragmentation/reassembly).
 *
 * CLIP uses a proprietary transport layer (NOT standard J1939 TP).
 *
 * Frame format (8 bytes max per CAN frame):
 *   Byte 0: (SessionID << 5) | MessageType
 *           Bits [7:5] = Session ID (0-7) or Sequence Number for data
 *           Bits [4:0] = Message type (0x02, 0x03, 0x04, 0x05)
 *   Byte 1: Connection ID (matches request to response)
 *   Byte 2: Control flags
 *   Bytes 3-7: Payload (max 5 bytes per frame)
 *
 * Message types:
 *   0x02 = Transport Open / Seed Reply
 *   0x03 = Data Transfer (sequence in bits 7:5)
 *   0x04 = CTS / Context Reply
 *   0x05 = Connection Refused
 *
 * Sequence handling:
 *   - 3-bit field (0-7), max 8 fragments per transfer
 *   - Expected sequence → process data
 *   - Previous sequence → duplicate, ignore with warning
 *   - Other → OUT OF SEQUENCE FATAL ERROR → close session
 *
 * Reference: ECU_PROGRAMMING_PROTOCOL.md, DeviceControl_ghidra.c:69799-70382
 */
class CLIPTransportLayer
{
public:
    /**
     * @brief Callback type for transport errors.
     */
    using ErrorCallback = std::function<void(EClipTransportError error, const std::string& message)>;

    CLIPTransportLayer(ICanAdapter* adapter, J1939MessageBuilder* j1939);
    ~CLIPTransportLayer() = default;

    /**
     * @brief Set ECU destination address.
     */
    void setDestAddress(uint8_t address);

    /**
     * @brief Get current destination address.
     */
    uint8_t getDestAddress() const;

    /**
     * @brief Set session ID for multiplexing.
     */
    void setSessionId(uint8_t sessionId);

    /**
     * @brief Get current session ID.
     */
    uint8_t getSessionId() const;

    /**
     * @brief Set connection ID for request/response matching.
     */
    void setConnectionId(uint8_t connectionId);

    /**
     * @brief Get current connection ID.
     */
    uint8_t getConnectionId() const;

    /**
     * @brief Increment and return next connection ID.
     */
    uint8_t nextConnectionId();

    /**
     * @brief Set error callback.
     */
    void setErrorCallback(ErrorCallback callback);

    /**
     * @brief Send a CLIP packet, fragmenting if necessary.
     * @param packet Complete CLIP packet to send
     * @param timeoutMs Timeout in milliseconds
     * @return true if sent successfully
     */
    bool sendPacket(const TClipPacket& packet, int timeoutMs = CLIP_DEFAULT_TIMEOUT_MS);

    /**
     * @brief Send raw data, fragmenting into CLIP frames.
     * @param data Raw bytes to send
     * @param timeoutMs Timeout in milliseconds
     * @return true if sent successfully
     */
    bool sendData(const std::vector<uint8_t>& data, int timeoutMs = CLIP_DEFAULT_TIMEOUT_MS);

    /**
     * @brief Receive a CLIP response, reassembling fragments.
     * @param data Output: reassembled response data
     * @param timeoutMs Timeout in milliseconds
     * @return true if response received successfully
     */
    bool receiveResponse(std::vector<uint8_t>& data, int timeoutMs = CLIP_DEFAULT_TIMEOUT_MS);

    /**
     * @brief Send a transport open message.
     * @param expectedPackets Expected number of packets (0-3, defaults to 4)
     * @return true if CTS received
     */
    bool sendTransportOpen(uint8_t expectedPackets = 0);

    /**
     * @brief Wait for CTS (Clear-to-Send) response.
     * @param timeoutMs Timeout in milliseconds
     * @return true if CTS received
     */
    bool waitForCts(int timeoutMs = CLIP_DEFAULT_TIMEOUT_MS);

    /**
     * @brief Send a single CLIP frame.
     * @param frame Frame to send
     * @return true if sent successfully
     */
    bool sendFrame(const TClipFrame& frame);

    /**
     * @brief Receive a single CLIP frame.
     * @param frame Output: received frame
     * @param timeoutMs Timeout in milliseconds
     * @return true if frame received
     */
    bool receiveFrame(TClipFrame& frame, int timeoutMs = CLIP_DEFAULT_TIMEOUT_MS);

private:
    ICanAdapter* m_adapter;
    J1939MessageBuilder* m_j1939;
    uint8_t m_destAddress;
    uint8_t m_sessionId;
    uint8_t m_connectionId;
    uint8_t m_expectedSequence;
    ErrorCallback m_errorCallback;

    void reportError(EClipTransportError error, const std::string& message);
};

#endif // CLIPTRANSPORTLAYER_H
