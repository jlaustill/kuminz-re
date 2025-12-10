#include "CLIPTransportLayer.h"
#include <cstring>

CLIPTransportLayer::CLIPTransportLayer(ICanAdapter* adapter, J1939MessageBuilder* j1939)
    : m_adapter(adapter)
    , m_j1939(j1939)
    , m_destAddress(0x00)
    , m_sessionId(0)
    , m_connectionId(0)
    , m_expectedSequence(0)
    , m_errorCallback(nullptr)
{
}

void CLIPTransportLayer::setDestAddress(uint8_t address)
{
    m_destAddress = address;
}

uint8_t CLIPTransportLayer::getDestAddress() const
{
    return m_destAddress;
}

void CLIPTransportLayer::setSessionId(uint8_t sessionId)
{
    m_sessionId = sessionId & 0x07;  // 3-bit field
}

uint8_t CLIPTransportLayer::getSessionId() const
{
    return m_sessionId;
}

void CLIPTransportLayer::setConnectionId(uint8_t connectionId)
{
    m_connectionId = connectionId;
}

uint8_t CLIPTransportLayer::getConnectionId() const
{
    return m_connectionId;
}

uint8_t CLIPTransportLayer::nextConnectionId()
{
    return m_connectionId++;
}

void CLIPTransportLayer::setErrorCallback(ErrorCallback callback)
{
    m_errorCallback = std::move(callback);
}

void CLIPTransportLayer::reportError(EClipTransportError error, const std::string& message)
{
    if (m_errorCallback) {
        m_errorCallback(error, message);
    }
}

bool CLIPTransportLayer::sendFrame(const TClipFrame& frame)
{
    if (!m_adapter || !m_adapter->isOpen()) {
        reportError(EClipTransportError::Aborted, "CAN adapter not open");
        return false;
    }

    uint8_t data[8];
    uint8_t len = frame.encode(data);

    uint32_t arbId = m_j1939->buildClipDataArbId(m_destAddress);
    return m_adapter->send(arbId, data, len);
}

bool CLIPTransportLayer::receiveFrame(TClipFrame& frame, int timeoutMs)
{
    if (!m_adapter || !m_adapter->isOpen()) {
        reportError(EClipTransportError::Aborted, "CAN adapter not open");
        return false;
    }

    uint32_t arbId;
    uint8_t data[8];
    uint8_t len;

    // Keep receiving until we get a CLIP response for our connection
    while (m_adapter->recv(arbId, data, len, timeoutMs)) {
        // Check if this is a CLIP response (PGN 0xEF)
        if (!J1939MessageBuilder::isClipResponse(arbId)) {
            continue;  // Not a CLIP response, keep waiting
        }

        // Check if response is from our target ECU
        uint8_t sourceAddr = J1939MessageBuilder::extractSourceAddress(arbId);
        if (sourceAddr != m_destAddress) {
            continue;  // From different ECU
        }

        // Decode the frame
        if (!frame.decode(data, len)) {
            reportError(EClipTransportError::Aborted, "Failed to decode CLIP frame");
            return false;
        }

        // Check connection ID matches
        if (frame.connectionId != m_connectionId) {
            continue;  // Different connection
        }

        return true;
    }

    reportError(EClipTransportError::Timeout, "Timeout waiting for CLIP response");
    return false;
}

bool CLIPTransportLayer::sendPacket(const TClipPacket& packet, int timeoutMs)
{
    std::vector<uint8_t> data = packet.serialize();
    return sendData(data, timeoutMs);
}

bool CLIPTransportLayer::sendData(const std::vector<uint8_t>& data, int timeoutMs)
{
    if (data.empty()) {
        return true;  // Nothing to send
    }

    // Check if data fits in single frame
    if (data.size() <= CLIP_MAX_FRAME_PAYLOAD) {
        // Single frame transfer
        TClipFrame frame;
        frame.sessionId = m_sessionId;
        frame.msgType = static_cast<uint8_t>(EClipMsgType::DataTransfer);
        frame.connectionId = m_connectionId;
        frame.control = 0;
        frame.payloadLen = static_cast<uint8_t>(data.size());
        std::memcpy(frame.payload, data.data(), data.size());

        return sendFrame(frame);
    }

    // Multi-frame transfer
    // First, send transport open
    uint8_t numPackets = static_cast<uint8_t>((data.size() + CLIP_MAX_FRAME_PAYLOAD - 1) / CLIP_MAX_FRAME_PAYLOAD);
    if (numPackets > CLIP_MAX_FRAGMENTS) {
        reportError(EClipTransportError::Aborted, "Data too large for CLIP transport");
        return false;
    }

    if (!sendTransportOpen(numPackets)) {
        return false;
    }

    // Wait for CTS
    if (!waitForCts(timeoutMs)) {
        return false;
    }

    // Send data frames with sequence numbers
    size_t offset = 0;
    uint8_t sequence = 0;

    while (offset < data.size()) {
        TClipFrame frame;
        frame.sessionId = sequence;  // Sequence number in session ID field for data frames
        frame.msgType = static_cast<uint8_t>(EClipMsgType::DataTransfer);
        frame.connectionId = m_connectionId;
        frame.control = 0;

        size_t remaining = data.size() - offset;
        frame.payloadLen = static_cast<uint8_t>(
            remaining > CLIP_MAX_FRAME_PAYLOAD ? CLIP_MAX_FRAME_PAYLOAD : remaining
        );
        std::memcpy(frame.payload, data.data() + offset, frame.payloadLen);

        if (!sendFrame(frame)) {
            return false;
        }

        offset += frame.payloadLen;
        sequence = (sequence + 1) & 0x07;  // Wrap at 8
    }

    return true;
}

bool CLIPTransportLayer::receiveResponse(std::vector<uint8_t>& data, int timeoutMs)
{
    data.clear();
    m_expectedSequence = 0;

    TClipFrame frame;
    bool firstFrame = true;

    while (true) {
        if (!receiveFrame(frame, timeoutMs)) {
            return false;
        }

        uint8_t msgType = frame.msgType & 0x1F;

        // Check for connection refused
        if (msgType == static_cast<uint8_t>(EClipMsgType::ConnectionRefused)) {
            reportError(EClipTransportError::Aborted, "Connection refused by ECU");
            return false;
        }

        // Check for transport open (seed reply) - handle in session layer
        if (msgType == static_cast<uint8_t>(EClipMsgType::TransportOpen)) {
            // This is a seed reply or transport negotiation
            data.insert(data.end(), frame.payload, frame.payload + frame.payloadLen);
            return true;
        }

        // Check for CTS (context reply or ack)
        if (msgType == static_cast<uint8_t>(EClipMsgType::ClearToSend)) {
            // Acknowledgment received
            data.insert(data.end(), frame.payload, frame.payload + frame.payloadLen);
            return true;
        }

        // Data transfer frame
        if (msgType == static_cast<uint8_t>(EClipMsgType::DataTransfer)) {
            uint8_t sequence = frame.getSequence();

            if (firstFrame) {
                m_expectedSequence = sequence;
                firstFrame = false;
            }

            // Validate sequence
            if (sequence == m_expectedSequence) {
                // Expected sequence - append data
                data.insert(data.end(), frame.payload, frame.payload + frame.payloadLen);
                m_expectedSequence = (m_expectedSequence + 1) & 0x07;

                // Check if this is the last frame (payload < max means end)
                if (frame.payloadLen < CLIP_MAX_FRAME_PAYLOAD) {
                    return true;  // Transfer complete
                }
            }
            else if (sequence == ((m_expectedSequence - 1) & 0x07)) {
                // Previous sequence - duplicate, ignore
                continue;
            }
            else {
                // Out of sequence - fatal error
                reportError(EClipTransportError::OutOfSequence,
                           "CLIP transport received message out of sequence");
                return false;
            }
        }
    }

    return false;
}

bool CLIPTransportLayer::sendTransportOpen(uint8_t expectedPackets)
{
    // Transport open message format:
    // Byte 0: 0x02 (Open type)
    // Byte 1: 0xFF (control)
    // Byte 2: 0x01 (control)
    // Byte 3: Unknown control
    // Byte 4: Expected packet count (0-3, defaults to 4)
    // Byte 5: Unknown control

    TClipFrame frame;
    frame.sessionId = m_sessionId;
    frame.msgType = static_cast<uint8_t>(EClipMsgType::TransportOpen);
    frame.connectionId = m_connectionId;
    frame.control = 0xFF;
    frame.payload[0] = 0x01;
    frame.payload[1] = 0x00;
    frame.payload[2] = expectedPackets > 3 ? 0 : expectedPackets;  // 0 means default to 4
    frame.payload[3] = 0x00;
    frame.payload[4] = 0x00;
    frame.payloadLen = 5;

    return sendFrame(frame);
}

bool CLIPTransportLayer::waitForCts(int timeoutMs)
{
    TClipFrame frame;

    if (!receiveFrame(frame, timeoutMs)) {
        return false;
    }

    uint8_t msgType = frame.msgType & 0x1F;

    if (msgType == static_cast<uint8_t>(EClipMsgType::ClearToSend)) {
        return true;
    }

    if (msgType == static_cast<uint8_t>(EClipMsgType::ConnectionRefused)) {
        reportError(EClipTransportError::Aborted, "Connection refused by ECU");
        return false;
    }

    reportError(EClipTransportError::Aborted, "Unexpected response waiting for CTS");
    return false;
}
