#ifndef J1939_TRANSPORT_PROTOCOL_H
#define J1939_TRANSPORT_PROTOCOL_H

/**
 * @file J1939TransportProtocol.h
 * @brief J1939 Transport Protocol (TP) support for multi-frame messages
 *
 * This handles responses from CM550 Service 0x4A memory reads which return
 * large data via J1939 TP (RTS/CTS/DT handshake).
 */

#include <cstdint>
#include <vector>
#include <cstring>

namespace J1939TP {

// TP Protocol Constants
constexpr uint8_t PF_CM = 0xEC;        // Connection Management PF (PGN 60416)
constexpr uint8_t PF_DT = 0xEB;        // Data Transfer PF (PGN 60160)

// TP.CM Control Bytes
constexpr uint8_t CM_RTS = 0x10;       // Request To Send
constexpr uint8_t CM_CTS = 0x11;       // Clear To Send
constexpr uint8_t CM_EOM = 0x13;       // End Of Message Acknowledgment
constexpr uint8_t CM_BAM = 0x20;       // Broadcast Announce Message
constexpr uint8_t CM_ABORT = 0xFF;     // Connection Abort

constexpr uint8_t DT_MAX_PAYLOAD = 7;  // Max bytes per TP.DT frame

/**
 * @brief TP.CM (Connection Management) Message parser
 */
struct ConnectionMessage
{
    uint8_t controlByte;    // 0x10=RTS, 0x11=CTS, 0x13=EOM, 0x20=BAM, 0xFF=ABORT
    uint16_t totalBytes;    // Total message size
    uint8_t numPackets;     // Number of TP.DT frames expected
    uint32_t pgn;           // PGN being transferred (24-bit)

    ConnectionMessage()
        : controlByte(0), totalBytes(0), numPackets(0), pgn(0) {}

    /**
     * @brief Decode a TP.CM frame
     * @param data CAN frame payload (8 bytes)
     * @param len Length of data
     * @return true if successfully decoded
     */
    bool decode(const uint8_t* data, uint8_t len)
    {
        if (len < 8) return false;

        controlByte = data[0];
        totalBytes = static_cast<uint16_t>(data[1]) |
                    (static_cast<uint16_t>(data[2]) << 8);
        numPackets = data[3];
        // Byte 4 is reserved (usually 0xFF)
        pgn = static_cast<uint32_t>(data[5]) |
              (static_cast<uint32_t>(data[6]) << 8) |
              (static_cast<uint32_t>(data[7]) << 16);

        return true;
    }

    bool isRTS() const { return controlByte == CM_RTS; }
    bool isCTS() const { return controlByte == CM_CTS; }
    bool isEOM() const { return controlByte == CM_EOM; }
    bool isBAM() const { return controlByte == CM_BAM; }
    bool isAbort() const { return controlByte == CM_ABORT; }
};

/**
 * @brief TP Reassembly Session for accumulating multi-frame data
 */
struct Session
{
    uint32_t pgn;              // PGN being received
    uint8_t sourceAddress;     // Source address of sender
    uint16_t expectedBytes;    // Total bytes expected
    uint8_t expectedPackets;   // Total packets expected
    uint8_t receivedPackets;   // Packets received so far
    std::vector<uint8_t> data; // Reassembled data
    bool active;               // Session is active

    Session()
        : pgn(0), sourceAddress(0), expectedBytes(0)
        , expectedPackets(0), receivedPackets(0), active(false) {}

    /**
     * @brief Start session from RTS message
     */
    void startFromRTS(const ConnectionMessage& cm, uint8_t source)
    {
        pgn = cm.pgn;
        sourceAddress = source;
        expectedBytes = cm.totalBytes;
        expectedPackets = cm.numPackets;
        receivedPackets = 0;
        data.clear();
        data.reserve(expectedBytes);
        active = true;
    }

    /**
     * @brief Add a TP.DT frame to the reassembly buffer
     * @param seqNum Sequence number (1-based, from byte 0 of TP.DT)
     * @param payload Pointer to bytes 1-7 of the TP.DT frame
     * @param payloadLen Number of payload bytes (typically 7)
     * @return true if frame was added successfully
     */
    bool addFrame(uint8_t seqNum, const uint8_t* payload, uint8_t payloadLen)
    {
        if (!active) return false;

        // Sequence numbers are 1-based
        uint8_t expectedSeq = receivedPackets + 1;
        if (seqNum != expectedSeq) {
            return false;  // Out of order
        }

        // Calculate how many bytes to copy
        uint16_t bytesRemaining = expectedBytes - static_cast<uint16_t>(data.size());
        uint8_t bytesToCopy = (payloadLen < bytesRemaining) ?
                              payloadLen : static_cast<uint8_t>(bytesRemaining);

        for (uint8_t i = 0; i < bytesToCopy; i++) {
            data.push_back(payload[i]);
        }

        receivedPackets++;
        return true;
    }

    /**
     * @brief Check if transfer is complete
     */
    bool isComplete() const
    {
        return active &&
               receivedPackets >= expectedPackets &&
               data.size() >= expectedBytes;
    }

    /**
     * @brief Reset the session
     */
    void reset()
    {
        pgn = 0;
        sourceAddress = 0;
        expectedBytes = 0;
        expectedPackets = 0;
        receivedPackets = 0;
        data.clear();
        active = false;
    }
};

/**
 * @brief Build TP.CM CTS (Clear to Send) response
 */
inline void buildCTS(uint8_t numPackets, uint8_t nextPacket, uint32_t pgn, uint8_t* data)
{
    data[0] = CM_CTS;                             // 0x11
    data[1] = numPackets;                         // Packets to send
    data[2] = nextPacket;                         // Next packet (1-based)
    data[3] = 0xFF;                               // Reserved
    data[4] = 0xFF;                               // Reserved
    data[5] = static_cast<uint8_t>(pgn & 0xFF);           // PGN low
    data[6] = static_cast<uint8_t>((pgn >> 8) & 0xFF);    // PGN mid
    data[7] = static_cast<uint8_t>((pgn >> 16) & 0xFF);   // PGN high
}

/**
 * @brief Build TP.CM EOM (End of Message Acknowledgment)
 */
inline void buildEOM(uint16_t totalBytes, uint8_t numPackets, uint32_t pgn, uint8_t* data)
{
    data[0] = CM_EOM;                             // 0x13
    data[1] = static_cast<uint8_t>(totalBytes & 0xFF);    // Size LSB
    data[2] = static_cast<uint8_t>((totalBytes >> 8) & 0xFF); // Size MSB
    data[3] = numPackets;                         // Packet count
    data[4] = 0xFF;                               // Reserved
    data[5] = static_cast<uint8_t>(pgn & 0xFF);           // PGN low
    data[6] = static_cast<uint8_t>((pgn >> 8) & 0xFF);    // PGN mid
    data[7] = static_cast<uint8_t>((pgn >> 16) & 0xFF);   // PGN high
}

/**
 * @brief Build TP.CM arbitration ID for CTS/EOM response
 * @param destAddress Destination address (ECU)
 * @param sourceAddress Source address (tool = 0xF9)
 * @return Arbitration ID
 */
inline uint32_t buildCMArbId(uint8_t destAddress, uint8_t sourceAddress = 0xF9)
{
    // Priority 6, PF=0xEC, destination-specific
    return (6UL << 26) | (static_cast<uint32_t>(PF_CM) << 16) |
           (static_cast<uint32_t>(destAddress) << 8) | sourceAddress;
}

/**
 * @brief Check if arbitration ID is TP.CM message
 */
inline bool isConnectionMessage(uint32_t arbId)
{
    uint8_t pf = static_cast<uint8_t>((arbId >> 16) & 0xFF);
    return pf == PF_CM;
}

/**
 * @brief Check if arbitration ID is TP.DT message
 */
inline bool isDataMessage(uint32_t arbId)
{
    uint8_t pf = static_cast<uint8_t>((arbId >> 16) & 0xFF);
    return pf == PF_DT;
}

} // namespace J1939TP

#endif // J1939_TRANSPORT_PROTOCOL_H
