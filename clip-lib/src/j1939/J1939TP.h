#ifndef J1939_TP_H
#define J1939_TP_H

#include <cstdint>
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
#include <iomanip>

/**
 * J1939 Transport Protocol (TP) Implementation
 *
 * Handles multi-frame message reassembly using:
 * - TP.CM (PF=0xEC, PGN 60416): Connection Management
 * - TP.DT (PF=0xEB, PGN 60160): Data Transfer
 *
 * BAM (Broadcast Announce Message) mode is used when ECU broadcasts
 * multi-frame responses. The CM550 uses BAM for Engine Configuration (50 bytes).
 */
namespace J1939
{
    // TP Protocol Constants
    constexpr uint8_t TP_PF_CM = 0xEC;      // Connection Management PF
    constexpr uint8_t TP_PF_DT = 0xEB;      // Data Transfer PF
    constexpr uint8_t TP_CM_BAM = 0x20;     // Broadcast Announce Message
    constexpr uint8_t TP_CM_RTS = 0x10;     // Request To Send
    constexpr uint8_t TP_CM_CTS = 0x11;     // Clear To Send
    constexpr uint8_t TP_CM_EOM = 0x13;     // End Of Message Acknowledgment
    constexpr uint8_t TP_CM_ABORT = 0xFF;   // Connection Abort

    constexpr uint8_t TP_DT_MAX_PAYLOAD = 7; // Max bytes per TP.DT frame

    /**
     * TP.CM (Connection Management) Message
     *
     * BAM format (8 bytes):
     *   Byte 0: 0x20 (BAM control byte)
     *   Byte 1: Total message length (LSB)
     *   Byte 2: Total message length (MSB)
     *   Byte 3: Number of packets
     *   Byte 4: 0xFF (reserved)
     *   Bytes 5-7: PGN being transmitted (little-endian, 3 bytes)
     */
    struct TPConnectionMessage
    {
        uint8_t controlByte;    // 0x20 for BAM, 0x10 for RTS, etc.
        uint16_t totalBytes;    // Total message size
        uint8_t numPackets;     // Number of TP.DT frames to expect
        uint32_t pgn;           // PGN being transferred (24-bit)

        TPConnectionMessage()
            : controlByte(0)
            , totalBytes(0)
            , numPackets(0)
            , pgn(0)
        {}

        /**
         * Decode a TP.CM frame
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

        bool isBAM() const { return controlByte == TP_CM_BAM; }
        bool isRTS() const { return controlByte == TP_CM_RTS; }
        bool isAbort() const { return controlByte == TP_CM_ABORT; }

        std::string toString() const
        {
            std::ostringstream ss;
            ss << "TP.CM ";

            switch (controlByte) {
                case TP_CM_BAM:   ss << "BAM"; break;
                case TP_CM_RTS:   ss << "RTS"; break;
                case TP_CM_CTS:   ss << "CTS"; break;
                case TP_CM_EOM:   ss << "EOM"; break;
                case TP_CM_ABORT: ss << "ABORT"; break;
                default:
                    ss << "Unknown(0x" << std::hex << static_cast<int>(controlByte) << ")";
            }

            ss << ": " << std::dec << totalBytes << " bytes in "
               << static_cast<int>(numPackets) << " packets for PGN 0x"
               << std::hex << std::uppercase << std::setfill('0') << std::setw(6) << pgn;

            return ss.str();
        }
    };

    /**
     * TP Reassembly Session
     *
     * Manages the state of an ongoing multi-frame transfer.
     * Accumulates TP.DT frames until the complete message is received.
     */
    struct TPSession
    {
        uint32_t pgn;              // PGN being received
        uint8_t sourceAddress;     // Source address of sender
        uint16_t expectedBytes;    // Total bytes expected
        uint8_t expectedPackets;   // Total packets expected
        uint8_t receivedPackets;   // Packets received so far
        std::vector<uint8_t> data; // Reassembled data
        bool active;               // Session is active

        TPSession()
            : pgn(0)
            , sourceAddress(0)
            , expectedBytes(0)
            , expectedPackets(0)
            , receivedPackets(0)
            , active(false)
        {}

        /**
         * Start a new reassembly session from a TP.CM BAM message
         */
        void startFromBAM(const TPConnectionMessage& cm, uint8_t source)
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
         * Add a TP.DT frame to the reassembly buffer
         *
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
                // Out of order or duplicate
                return false;
            }

            // Calculate how many bytes to copy (may be less on last frame)
            uint16_t bytesRemaining = expectedBytes - static_cast<uint16_t>(data.size());
            uint8_t bytesToCopy = (payloadLen < bytesRemaining) ?
                                  payloadLen : static_cast<uint8_t>(bytesRemaining);

            // Append data
            for (uint8_t i = 0; i < bytesToCopy; i++) {
                data.push_back(payload[i]);
            }

            receivedPackets++;
            return true;
        }

        /**
         * Check if all expected packets have been received
         */
        bool isComplete() const
        {
            return active &&
                   receivedPackets >= expectedPackets &&
                   data.size() >= expectedBytes;
        }

        /**
         * Reset the session
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

        /**
         * Format the reassembled data as hex dump
         */
        std::string hexDump() const
        {
            std::ostringstream ss;
            for (size_t i = 0; i < data.size(); i++) {
                if (i > 0 && (i % 16) == 0) {
                    ss << "\n";
                }
                if ((i % 16) == 0) {
                    ss << std::hex << std::setfill('0') << std::setw(4)
                       << i << ": ";
                }
                ss << std::hex << std::setfill('0') << std::setw(2)
                   << static_cast<int>(data[i]) << " ";
            }
            return ss.str();
        }
    };

    /**
     * Check if an arbitration ID is a TP.CM message
     */
    inline bool isTPConnectionMessage(uint32_t arbId)
    {
        uint8_t pf = static_cast<uint8_t>((arbId >> 16) & 0xFF);
        return pf == TP_PF_CM;
    }

    /**
     * Check if an arbitration ID is a TP.DT message
     */
    inline bool isTPDataMessage(uint32_t arbId)
    {
        uint8_t pf = static_cast<uint8_t>((arbId >> 16) & 0xFF);
        return pf == TP_PF_DT;
    }

    /**
     * Extract the source address from an arbitration ID
     */
    inline uint8_t extractTPSource(uint32_t arbId)
    {
        return static_cast<uint8_t>(arbId & 0xFF);
    }

    /**
     * Format a TP.DT frame for display
     */
    inline std::string formatTPData(uint8_t seqNum, uint8_t totalPackets,
                                    const uint8_t* payload, uint8_t len)
    {
        std::ostringstream ss;
        ss << "TP.DT " << std::dec << static_cast<int>(seqNum) << "/"
           << static_cast<int>(totalPackets) << ": ";

        for (uint8_t i = 0; i < len && i < TP_DT_MAX_PAYLOAD; i++) {
            ss << std::hex << std::setfill('0') << std::setw(2)
               << static_cast<int>(payload[i]);
            if (i < len - 1) ss << " ";
        }

        return ss.str();
    }

} // namespace J1939

#endif // J1939_TP_H
