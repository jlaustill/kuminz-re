#ifndef CLIP_FRAME_H
#define CLIP_FRAME_H

#include <cstdint>
#include <cstring>
#include <string>
#include <sstream>
#include <iomanip>

namespace Clip
{
    /**
     * CLIP message types (lower 5 bits of byte 0)
     *
     * Note: CM550 ECU uses 0x0D for session open response instead of 0x02.
     * This may be a protocol variant or older implementation.
     */
    enum class MsgType : uint8_t
    {
        TransportOpen       = 0x02,  // Session open request (tool -> ECU)
        DataTransfer        = 0x03,  // Data transfer with sequence
        ClearToSend         = 0x04,  // CTS / acknowledgment
        ConnectionRefused   = 0x05,  // Refused by ECU
        TransportClose      = 0x06,  // Close request
        SessionOpenResponse = 0x0D   // Session open response (ECU -> tool) - CM550 variant
    };

    /**
     * CLIP control byte values (byte 2 of frame)
     * From Insite CLIPSession::dataReceived()
     */
    enum class ControlType : uint8_t
    {
        SeedReply    = 0x02,  // ECU is providing seed for authentication
        ContextReply = 0x04   // ECU context/status response
    };

    /**
     * CLIP frame structure.
     *
     * CAN frame format (8 bytes max):
     *   Byte 0: (SessionID << 5) | MsgType
     *   Byte 1: Connection ID
     *   Byte 2: Control flags
     *   Bytes 3-7: Payload (max 5 bytes)
     */
    struct Frame
    {
        uint8_t sessionId;      // 3-bit session ID (bits 7:5 of byte 0)
        uint8_t msgType;        // 5-bit message type (bits 4:0 of byte 0)
        uint8_t connectionId;   // Connection ID (byte 1)
        uint8_t control;        // Control flags (byte 2)
        uint8_t payload[5];     // Payload data (bytes 3-7)
        uint8_t payloadLen;     // Actual payload length (0-5)

        Frame()
            : sessionId(0)
            , msgType(0)
            , connectionId(0)
            , control(0)
            , payloadLen(0)
        {
            std::memset(payload, 0, sizeof(payload));
        }

        /**
         * Encode frame to CAN data bytes
         * @return Number of bytes encoded (3 + payloadLen)
         */
        uint8_t encode(uint8_t* data) const
        {
            data[0] = ((sessionId & 0x07) << 5) | (msgType & 0x1F);
            data[1] = connectionId;
            data[2] = control;

            uint8_t len = (payloadLen > 5) ? 5 : payloadLen;
            for (int i = 0; i < len; i++) {
                data[3 + i] = payload[i];
            }

            return 3 + len;
        }

        /**
         * Decode frame from CAN data bytes
         */
        bool decode(const uint8_t* data, uint8_t len)
        {
            if (len < 3) return false;

            sessionId = (data[0] >> 5) & 0x07;
            msgType = data[0] & 0x1F;
            connectionId = data[1];
            control = data[2];

            payloadLen = (len > 8) ? 5 : (len > 3 ? len - 3 : 0);
            for (int i = 0; i < payloadLen; i++) {
                payload[i] = data[3 + i];
            }

            return true;
        }

        /**
         * Get sequence number (same as sessionId for data frames)
         */
        uint8_t getSequence() const
        {
            return sessionId;
        }

        /**
         * Get message type as enum
         */
        MsgType getMsgType() const
        {
            return static_cast<MsgType>(msgType);
        }

        /**
         * Format frame for display
         */
        std::string toString() const
        {
            std::ostringstream ss;
            ss << "CLIP Frame: ";
            ss << "type=0x" << std::hex << static_cast<int>(msgType);
            ss << " sess=" << std::dec << static_cast<int>(sessionId);
            ss << " conn=" << static_cast<int>(connectionId);
            ss << " ctrl=0x" << std::hex << static_cast<int>(control);
            ss << " payload[" << std::dec << static_cast<int>(payloadLen) << "]=";

            for (int i = 0; i < payloadLen; i++) {
                ss << std::hex << std::setfill('0') << std::setw(2);
                ss << static_cast<int>(payload[i]);
                if (i < payloadLen - 1) ss << " ";
            }

            return ss.str();
        }

        /**
         * Describe message type
         */
        static std::string describeMsgType(uint8_t type)
        {
            switch (static_cast<MsgType>(type)) {
                case MsgType::TransportOpen:       return "TransportOpen(Request)";
                case MsgType::DataTransfer:        return "DataTransfer";
                case MsgType::ClearToSend:         return "ClearToSend/Ack";
                case MsgType::ConnectionRefused:   return "ConnectionRefused";
                case MsgType::TransportClose:      return "TransportClose";
                case MsgType::SessionOpenResponse: return "SessionOpenResponse(ECU)";
                default:
                    std::ostringstream ss;
                    ss << "Unknown(0x" << std::hex << static_cast<int>(type) << ")";
                    return ss.str();
            }
        }

        /**
         * Describe control byte
         */
        static std::string describeControl(uint8_t ctrl)
        {
            switch (static_cast<ControlType>(ctrl)) {
                case ControlType::SeedReply:    return "SeedReply";
                case ControlType::ContextReply: return "ContextReply";
                default:
                    std::ostringstream ss;
                    ss << "Control(0x" << std::hex << static_cast<int>(ctrl) << ")";
                    return ss.str();
            }
        }
    };

    /**
     * Build a session open frame
     */
    inline Frame buildSessionOpen(uint8_t connectionId, uint8_t sessionId = 0)
    {
        Frame f;
        f.sessionId = sessionId;
        f.msgType = static_cast<uint8_t>(MsgType::TransportOpen);
        f.connectionId = connectionId;
        f.control = 0xFF;
        f.payload[0] = 0x01;
        f.payload[1] = 0x00;
        f.payload[2] = 0x00;  // Expected packets (0 = default)
        f.payload[3] = 0x00;
        f.payload[4] = 0x00;
        f.payloadLen = 5;
        return f;
    }

    /**
     * Build a session close frame
     */
    inline Frame buildSessionClose(uint8_t connectionId, uint8_t sessionId = 0)
    {
        Frame f;
        f.sessionId = sessionId;
        f.msgType = static_cast<uint8_t>(MsgType::TransportClose);
        f.connectionId = connectionId;
        f.control = 0x00;
        f.payloadLen = 0;
        return f;
    }

} // namespace Clip

#endif // CLIP_FRAME_H
