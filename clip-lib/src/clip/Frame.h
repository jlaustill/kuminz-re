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
     * CLIP Transport Layer message types (byte 0)
     *
     * From Insite PCLSystem.dll decompilation (CLIPTransport.cpp):
     * - 0x01 = TransportOpenRequest (initiator -> responder)
     * - 0x02 = TransportOpenResponse (responder -> initiator)
     * - 0x03+ = DataTransfer (lower 2 bits = 0x03, upper bits = sequence)
     * - 0x04 = ClearToSend
     *
     * CM550 ECU uses 0x0D for session open response instead of standard 0x02.
     */
    enum class MsgType : uint8_t
    {
        TransportOpenRequest  = 0x01,  // Session open REQUEST (tool -> ECU) - CORRECT!
        TransportOpenResponse = 0x02,  // Session open RESPONSE (ECU -> tool) - standard
        TransportOpen         = 0x02,  // Alias for compatibility
        DataTransfer          = 0x03,  // Data transfer with sequence
        ClearToSend           = 0x04,  // CTS / acknowledgment
        ConnectionRefused     = 0x05,  // Refused by ECU
        TransportClose        = 0x06,  // Close request
        SessionOpenResponse   = 0x0D   // Session open response (ECU -> tool) - CM550 variant
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
     * Service numbers for diagnostic commands
     * From CM550 firmware diagnosticCommandDispatcher @ 0x12484
     */
    enum class ServiceNum : uint8_t
    {
        Service3 = 3,  // System commands (0x40-0x54)
        Service4 = 4,  // System control (0x64-0x75)
        Service5 = 5,  // Memory read/write, multi-packet
        Service6 = 6   // Cancel/abort (0x74)
    };

    /**
     * Service 5 command codes (high nibble of command byte)
     * From CM550 firmware diagnosticCommandDispatcher @ 0x12484 (lines 6939-6960)
     *
     * Format: CAN frame byte 2 = service number, payload[0] = command code
     */
    enum class Service5Cmd : uint8_t
    {
        MemoryRead3  = 0x60,  // Memory read type 3 → diagnosticMemoryReadHandler(3)
        MemoryWrite4 = 0x80,  // Memory write type 4 → diagnosticMemoryWriteHandler(4)
        MemoryWrite2 = 0xA0,  // Memory write type 2 → diagnosticMemoryWriteHandler(2)
        MultiPktRecv = 0xB0,  // Multi-packet receive (read from ECU) → multiPacketReceiveHandler
        MemoryRead2  = 0xC0,  // Memory read type 2 → diagnosticMemoryReadHandler(2)
        MemoryRead1  = 0xE0,  // Memory read type 1 → diagnosticMemoryReadHandler(1)
        MultiPktXmit = 0xF0   // Multi-packet transmit (write to ECU) → multiPacketTransmitHandler
    };

    /**
     * CM550 CAN Message Dispatcher Types (byte 0 of 8-byte CAN frame)
     *
     * From CM550 firmware vp44CanMessageDispatcher @ 0x1c846:
     * The dispatcher routes messages based on byte[0] value.
     * ONLY these values are recognized - all others are IGNORED silently!
     *
     * CRITICAL: Standard CLIP DataTransfer (0x03) is NOT handled by this dispatcher!
     * Use 0x11 (ParamRequest) or 0x13 (StatusRequest) for diagnostic commands.
     */
    enum class CM550MsgType : uint8_t
    {
        VP44FuelTemp   = 0x10,  // vp44FuelTempHandler - VP44 pump fuel temperature
        ParamRequest   = 0x11,  // diagnosticParamRequestHandler - Parameter read/write
        StatusRequest  = 0x13,  // diagnosticStatusRequestHandler - Status queries
        Response       = 0x80,  // Response wrapper (insiteParameterResponseBuilder output)
        ErrorHandler   = 0xFF   // diagnosticErrorHandler - Error handling
    };

    /**
     * CM550 Parameter Command Codes (byte 1 inner protocol)
     * From insiteLiveDataHandler @ 0x19a0a and insiteCommandByteDispatcher
     */
    enum class CM550ParamCmd : uint8_t
    {
        GetStatus     = 0x00,  // Basic status/parameter request
        LiveDataStart = 0x80,  // Multi-frame live data stream start
        FaultQuery    = 0xC3,  // Fault/DTC detail query
        FaultResponse = 0xC4   // Fault detail response
    };

    // =========================================================================
    // CM550 EF00 DIAGNOSTIC SERVICE IDS
    // From firmware diagnosticServiceDispatcher @ 0x272a0
    // Service ID goes DIRECTLY in byte[0] of message - no DPA wrapping!
    // =========================================================================

    /**
     * CM550 EF00 Diagnostic Service IDs
     *
     * From firmware analysis of diagnosticServiceDispatcher:
     * - Table at 0x8018d8, counter at 0x801998
     * - Each entry: 1 byte service ID + 1 padding + 4-byte handler pointer
     * - Max 32 entries (0x20)
     *
     * The dispatcher compares byte[0] of incoming message against this table.
     * If no match found, returns error 0x18 (Unknown Service).
     *
     * NOTE: 0x10 and 0x15 match CLIP instruction codes!
     */
    enum class EF00ServiceID : uint8_t
    {
        // *** CLIP-compatible service IDs ***
        QueryTerminate         = 0x01,  // Matches CLIP QueryTerminate
        GetParametersByID      = 0x10,  // Matches CLIP GetParametersByID!
        GetAddressByParameterID = 0x15, // Matches CLIP GetAddressByParameterID!

        // *** System services ***
        SystemService04        = 0x04,  // Handler @ 0x1b150
        SystemService05        = 0x05,  // Handler @ 0x1b160
        SystemService06        = 0x06,  // Handler @ 0xf8d8
        SystemService07        = 0x07,  // Handler @ 0xf876
        SystemService0A        = 0x0A,  // Handler @ 0xf89c
        SystemService0B        = 0x0B,  // Handler @ 0xf8e4
        SystemService0F        = 0x0F,  // Handler @ 0x1b07e (same as 0x10!)
        SystemService16        = 0x16,  // Handler @ 0xf8b6
        SystemService18        = 0x18,  // Handler @ 0xf9e4

        // *** 0x4x range services ***
        Service41              = 0x41,  // Handler @ 0x1bc9c
        Service43              = 0x43,  // Handler @ 0x1bf18
        Service44              = 0x44,  // Handler @ 0x1b56e (same as 0x45)
        Service45              = 0x45,  // Handler @ 0x1b56e
        Service46              = 0x46,  // Handler @ 0x1bf64
        Service47              = 0x47,  // Handler @ 0x1b604
        Service48              = 0x48,  // Handler @ 0x1bfc8
        Service49              = 0x49,  // Handler @ 0x1b668
        Service4A              = 0x4A,  // Handler @ 0x1c02e
        Service4B              = 0x4B,  // Handler @ 0x1b6ce
        Service4C              = 0x4C,  // Handler @ 0x1c076
        Service4D              = 0x4D   // Handler @ 0x1b716
    };

    // =========================================================================
    // INSITE DPA/CLIP PROTOCOL LAYER
    // From decompiled Insite code (dpas32_ghidra.c, Interop.DeviceControl.cs)
    // =========================================================================

    /**
     * CLIP Instruction Set (from Interop.DeviceControl.cs:3924-3932)
     * tagCICLIPInstructionEnum - Operations carried inside DPA frames
     *
     * These are the logical operations Insite requests. They are wrapped
     * in DPA frames before being sent over CAN.
     */
    enum class CLIPInstruction : uint8_t
    {
        QueryInitialize        = 0x00,  // Initialize query session
        QueryTerminate         = 0x01,  // Terminate query session
        GetParametersByID      = 0x10,  // Read parameters by ID
        SetParametersByID      = 0x11,  // Write parameters by ID
        ExecuteOperation       = 0x12,  // Execute ECU operation
        GetDataByAddress       = 0x13,  // Read memory by address
        SetDataByAddress       = 0x14,  // Write memory by address
        GetAddressByParameterID = 0x15  // Get parameter address
    };

    /**
     * DPA Frame Header Types (from dpas32_ghidra.c)
     * Byte 0 of DPA-wrapped CAN frames
     */
    enum class DPAFrameType : uint8_t
    {
        Async = 0xC0,  // Asynchronous frame (no immediate response expected)
        Sync  = 0x80   // Synchronous frame (wait for response)
    };

    /**
     * DPA Instruction Codes (from dpas32_ghidra.c:2366-2370)
     * Byte 3 of DPA-wrapped CAN frames
     */
    enum class DPAInstruction : uint8_t
    {
        Transmit = 0x49,  // Send data to ECU
        Receive  = 0x48   // Receive data from ECU
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
            switch (type) {
                case 0x01: return "TransportOpenRequest";
                case 0x02: return "TransportOpenResponse";
                case 0x03: return "DataTransfer(seq=0)";
                case 0x04: return "ClearToSend";
                case 0x05: return "ConnectionRefused";
                case 0x06: return "TransportClose";
                case 0x0D: return "SessionOpenResponse(CM550)";
                default:
                    // Check for DataTransfer with sequence
                    if ((type & 0x03) == 0x03) {
                        std::ostringstream ss;
                        ss << "DataTransfer(seq=" << ((type >> 2) & 0x07) << ")";
                        return ss.str();
                    }
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
     * Build a session open frame (TransportOpenRequest)
     *
     * From Insite CLIPTransport::createTransportMsg():
     * - Byte 0: 0x01 (TransportOpenRequest)
     * - Byte 1: Connection ID
     * - Byte 2: 0xFF
     * - Byte 3: 0x01
     * - Byte 4: 0xFF
     * - Bytes 5-7: padding (0x00)
     */
    inline Frame buildSessionOpen(uint8_t connectionId, uint8_t sessionId = 0)
    {
        Frame f;
        f.sessionId = sessionId;
        f.msgType = static_cast<uint8_t>(MsgType::TransportOpenRequest);  // 0x01, not 0x02!
        f.connectionId = connectionId;
        f.control = 0xFF;           // Byte 2
        f.payload[0] = 0x01;        // Byte 3
        f.payload[1] = 0xFF;        // Byte 4 (was 0x00, should be 0xFF per Insite)
        f.payload[2] = 0x00;        // Padding
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

    /**
     * Build a Service 5 memory read request (single-frame, type 0xC0)
     *
     * From CM550 firmware diagnosticCommandDispatcher @ 0x12484:
     * - CAN frame byte 2 (control) = Service number (5)
     * - CAN frame byte 3 (payload[0]) = Command (0xC0 = MemoryRead2)
     * - CAN frame bytes 4-6 (payload[1-3]) = 24-bit address (big-endian)
     * - CAN frame byte 7 (payload[4]) = Length (max 255 bytes for single frame)
     *
     * @param connectionId Connection ID assigned by ECU (e.g., 0x18)
     * @param address 24-bit memory address to read
     * @param length Number of bytes to read (1-255)
     * @param sessionId Session ID (default 0)
     * @param cmdType Service 5 command type (default MemoryRead2 = 0xC0)
     */
    inline Frame buildMemoryReadRequest(uint8_t connectionId,
                                        uint32_t address,
                                        uint8_t length,
                                        uint8_t sessionId = 0,
                                        Service5Cmd cmdType = Service5Cmd::MemoryRead2)
    {
        Frame f;
        f.sessionId = sessionId;
        f.msgType = static_cast<uint8_t>(MsgType::DataTransfer);  // 0x03
        f.connectionId = connectionId;
        f.control = static_cast<uint8_t>(ServiceNum::Service5);   // 0x05
        f.payload[0] = static_cast<uint8_t>(cmdType);             // 0xC0 default
        f.payload[1] = (address >> 16) & 0xFF;  // Address high byte
        f.payload[2] = (address >> 8) & 0xFF;   // Address mid byte
        f.payload[3] = address & 0xFF;          // Address low byte
        f.payload[4] = length;                  // Bytes to read
        f.payloadLen = 5;
        return f;
    }

    /**
     * Build a multi-packet receive request (0xB0 command)
     *
     * From CM550 firmware multiPacketReceiveHandler @ 0x12d76:
     * Multi-packet transfers use a different format with connection ID embedded
     * in the payload (bytes 3-4) for transfers larger than single frame.
     *
     * Initial frame format (message length == 6):
     * - Byte 0: Message length (6)
     * - Byte 1: Service (5)
     * - Byte 2: Command (0xB0 | count)
     * - Bytes 3-4: Connection ID (big-endian, e.g., 0x00 0x18)
     * - Byte 5: rx_active_flag
     * - Byte 6: tx_active_flag
     *
     * @param connectionId Connection ID assigned by ECU (e.g., 0x18)
     * @param sessionId Session ID (default 0)
     */
    inline Frame buildMultiPacketReceiveRequest(uint8_t connectionId,
                                                 uint8_t sessionId = 0)
    {
        Frame f;
        f.sessionId = sessionId;
        f.msgType = static_cast<uint8_t>(MsgType::DataTransfer);  // 0x03
        f.connectionId = connectionId;
        f.control = static_cast<uint8_t>(ServiceNum::Service5);   // 0x05
        f.payload[0] = static_cast<uint8_t>(Service5Cmd::MultiPktRecv);  // 0xB0
        f.payload[1] = 0x00;                    // Connection ID high byte
        f.payload[2] = connectionId;            // Connection ID low byte
        f.payload[3] = 0x01;                    // rx_active_flag
        f.payload[4] = 0x01;                    // tx_active_flag
        f.payloadLen = 5;
        return f;
    }

    /**
     * Describe Service 5 command code
     */
    static inline std::string describeService5Cmd(uint8_t cmd)
    {
        switch (cmd & 0xF0) {
            case 0x60: return "MemoryRead3";
            case 0x80: return "MemoryWrite4";
            case 0xA0: return "MemoryWrite2";
            case 0xB0: return "MultiPktRecv";
            case 0xC0: return "MemoryRead2";
            case 0xE0: return "MemoryRead1";
            case 0xF0: return "MultiPktXmit";
            default:
                std::ostringstream ss;
                ss << "Svc5Cmd(0x" << std::hex << static_cast<int>(cmd) << ")";
                return ss.str();
        }
    }

    /**
     * Describe CM550 dispatcher message type
     */
    static inline std::string describeCM550MsgType(uint8_t type)
    {
        switch (type) {
            case 0x10: return "VP44FuelTemp";
            case 0x11: return "ParamRequest";
            case 0x13: return "StatusRequest";
            case 0x80: return "Response";
            case 0xFF: return "ErrorHandler";
            default:
                std::ostringstream ss;
                ss << "CM550Unknown(0x" << std::hex << static_cast<int>(type) << ")";
                return ss.str();
        }
    }

    // =========================================================================
    // CM550-SPECIFIC MESSAGE BUILDERS
    // These use the dispatcher format (byte[0] = 0x11/0x13) NOT CLIP format!
    // =========================================================================

    /**
     * Raw CAN frame for CM550 (8 bytes, no CLIP framing)
     * Used for dispatcher-level communication with vp44CanMessageDispatcher
     */
    struct RawFrame
    {
        uint8_t data[8];
        uint8_t len;

        RawFrame() : len(8) {
            std::memset(data, 0xFF, sizeof(data));  // Pad with 0xFF
        }

        std::string toString() const {
            std::ostringstream ss;
            ss << "Raw[" << static_cast<int>(len) << "]: ";
            for (int i = 0; i < len; i++) {
                ss << std::hex << std::setfill('0') << std::setw(2)
                   << static_cast<int>(data[i]);
                if (i < len - 1) ss << " ";
            }
            return ss.str();
        }
    };

    /**
     * Build a CM550 parameter request frame (0x11 format)
     *
     * From CM550 firmware diagnosticParamRequestHandler @ 0x1c33e:
     * The handler validates:
     *   - diag_state == 1 (session active)
     *   - expected_id matches
     *   - sequence <= total_packets
     *   - guard_word matches expected
     *
     * Frame format:
     *   Byte 0: 0x11 (ParamRequest message type)
     *   Byte 1: Sequence number
     *   Byte 2: Total packet count
     *   Bytes 3-5: Parameter/command data
     *   Bytes 6-7: Guard word (for validation)
     *
     * @param sequence Packet sequence number
     * @param totalPackets Total packets in this request
     * @param paramCmd Parameter command code (CM550ParamCmd)
     * @param paramData Additional parameter data (2 bytes)
     * @param guardWord Guard validation word (default 0x0000)
     */
    inline RawFrame buildCM550ParamRequest(uint8_t sequence = 0,
                                            uint8_t totalPackets = 1,
                                            uint8_t paramCmd = 0x00,
                                            uint16_t paramData = 0x0000,
                                            uint16_t guardWord = 0x0000)
    {
        RawFrame f;
        f.data[0] = static_cast<uint8_t>(CM550MsgType::ParamRequest);  // 0x11
        f.data[1] = sequence;
        f.data[2] = totalPackets;
        f.data[3] = paramCmd;
        f.data[4] = (paramData >> 8) & 0xFF;   // Param high byte
        f.data[5] = paramData & 0xFF;          // Param low byte
        f.data[6] = (guardWord >> 8) & 0xFF;   // Guard high byte
        f.data[7] = guardWord & 0xFF;          // Guard low byte
        f.len = 8;
        return f;
    }

    /**
     * Build a CM550 status request frame (0x13 format)
     *
     * From CM550 firmware diagnosticStatusRequestHandler @ 0x1c776:
     * Queries ECU status without full parameter request handshake.
     *
     * @param statusType Type of status to query (TBD from firmware analysis)
     */
    inline RawFrame buildCM550StatusRequest(uint8_t statusType = 0x00)
    {
        RawFrame f;
        f.data[0] = static_cast<uint8_t>(CM550MsgType::StatusRequest);  // 0x13
        f.data[1] = statusType;
        f.data[2] = 0x00;
        f.data[3] = 0x00;
        f.data[4] = 0x00;
        f.data[5] = 0x00;
        f.data[6] = 0x00;
        f.data[7] = 0x00;
        f.len = 8;
        return f;
    }

    /**
     * Build a raw CAN frame from hex bytes
     * Useful for testing arbitrary message formats
     *
     * @param hexBytes Array of up to 8 bytes
     * @param count Number of bytes (1-8)
     */
    inline RawFrame buildRawFrame(const uint8_t* hexBytes, uint8_t count)
    {
        RawFrame f;
        f.len = (count > 8) ? 8 : count;
        for (int i = 0; i < f.len; i++) {
            f.data[i] = hexBytes[i];
        }
        // Pad remaining with 0xFF
        for (int i = f.len; i < 8; i++) {
            f.data[i] = 0xFF;
        }
        return f;
    }

    /**
     * Check if a response frame is a CM550 response (starts with 0x80)
     */
    inline bool isCM550Response(const uint8_t* data, uint8_t len)
    {
        return len >= 1 && data[0] == static_cast<uint8_t>(CM550MsgType::Response);
    }

    /**
     * Parse CM550 response command echo (byte 1 of response)
     */
    inline uint8_t getCM550ResponseCmd(const uint8_t* data, uint8_t len)
    {
        return (len >= 2) ? data[1] : 0xFF;
    }

    // =========================================================================
    // DPA FRAME BUILDERS (from dpas32_ghidra.c analysis)
    // These wrap CLIP instructions in DPA frame format for CAN transmission
    // =========================================================================

    /**
     * Build a DPA-wrapped CLIP request frame
     *
     * From dpas32_ghidra.c canbus_async_transmit @ 2366:
     *   byte[0] = 0xC0 (async) or 0x80 (sync) - DPA frame type
     *   byte[1] = reserved/padding
     *   byte[2] = reserved/padding
     *   byte[3] = 0x49 (transmit) or 0x48 (receive) - DPA instruction
     *   byte[4] = CLIP instruction (0x10-0x15)
     *   byte[5] = parameter byte
     *   byte[6] = flags
     *   byte[7] = payload start / padding
     *
     * @param frameType DPA frame type (Async=0xC0 or Sync=0x80)
     * @param clipInstr CLIP instruction code (0x00-0x15)
     * @param paramByte Parameter identifier byte
     * @param flags Operation flags
     */
    inline RawFrame buildDPAFrame(DPAFrameType frameType,
                                   CLIPInstruction clipInstr,
                                   uint8_t paramByte = 0x00,
                                   uint8_t flags = 0x00)
    {
        RawFrame f;
        f.data[0] = static_cast<uint8_t>(frameType);       // 0xC0 or 0x80
        f.data[1] = 0x00;                                   // Reserved
        f.data[2] = 0x00;                                   // Reserved
        f.data[3] = static_cast<uint8_t>(DPAInstruction::Transmit);  // 0x49
        f.data[4] = static_cast<uint8_t>(clipInstr);       // CLIP instruction
        f.data[5] = paramByte;                              // Parameter
        f.data[6] = flags;                                  // Flags
        f.data[7] = 0x00;                                   // Payload/padding
        f.len = 8;
        return f;
    }

    /**
     * Build DPA GetParametersByID request (0x10)
     * Attempts to read a parameter by its ID using DPA frame format
     *
     * @param paramId Parameter ID to read
     * @param flags Request flags (default 0)
     */
    inline RawFrame buildDPAGetParam(uint8_t paramId, uint8_t flags = 0x00)
    {
        return buildDPAFrame(DPAFrameType::Async,
                              CLIPInstruction::GetParametersByID,
                              paramId,
                              flags);
    }

    /**
     * Build DPA GetDataByAddress request (0x13)
     * Attempts to read memory at a given address using DPA frame format
     *
     * @param addrByte Address byte (simplified - full address may need multiple bytes)
     * @param flags Request flags
     */
    inline RawFrame buildDPAGetData(uint8_t addrByte, uint8_t flags = 0x00)
    {
        return buildDPAFrame(DPAFrameType::Async,
                              CLIPInstruction::GetDataByAddress,
                              addrByte,
                              flags);
    }

    /**
     * Build DPA QueryInitialize request (0x00)
     * Attempts to initialize a diagnostic session using DPA format
     */
    inline RawFrame buildDPAQueryInit()
    {
        return buildDPAFrame(DPAFrameType::Sync,  // Use sync for init
                              CLIPInstruction::QueryInitialize,
                              0x00,
                              0x00);
    }

    /**
     * Describe CLIP instruction code
     */
    static inline std::string describeCLIPInstruction(uint8_t instr)
    {
        switch (instr) {
            case 0x00: return "QueryInitialize";
            case 0x01: return "QueryTerminate";
            case 0x10: return "GetParametersByID";
            case 0x11: return "SetParametersByID";
            case 0x12: return "ExecuteOperation";
            case 0x13: return "GetDataByAddress";
            case 0x14: return "SetDataByAddress";
            case 0x15: return "GetAddressByParameterID";
            default:
                std::ostringstream ss;
                ss << "CLIPInstr(0x" << std::hex << static_cast<int>(instr) << ")";
                return ss.str();
        }
    }

    /**
     * Describe DPA frame type
     */
    static inline std::string describeDPAFrameType(uint8_t type)
    {
        switch (type) {
            case 0xC0: return "Async";
            case 0x80: return "Sync";
            default:
                std::ostringstream ss;
                ss << "DPAType(0x" << std::hex << static_cast<int>(type) << ")";
                return ss.str();
        }
    }

    /**
     * Check if a frame looks like a DPA frame (starts with 0xC0 or 0x80)
     */
    inline bool isDPAFrame(const uint8_t* data, uint8_t len)
    {
        if (len < 1) return false;
        return data[0] == 0xC0 || data[0] == 0x80;
    }

    /**
     * Parse DPA frame and extract CLIP instruction
     */
    inline CLIPInstruction getDPAClipInstruction(const uint8_t* data, uint8_t len)
    {
        if (len >= 5) {
            return static_cast<CLIPInstruction>(data[4]);
        }
        return CLIPInstruction::QueryInitialize;  // Default
    }

    // =========================================================================
    // DIRECT SERVICE ID FRAME BUILDERS
    // For PGN 0xEF00 diagnosticServiceDispatcher - NO DPA wrapper!
    // Service ID goes directly in byte[0]
    // =========================================================================

    /**
     * Build a direct service ID frame for EF00 dispatch
     *
     * From firmware diagnosticServiceDispatcher @ 0x272a0:
     * The dispatcher compares byte[0] of incoming CAN message against
     * the registered service ID table. No wrapping needed!
     *
     * @param serviceId Service ID (0x01, 0x10, 0x15, etc.)
     * @param payload Remaining 7 bytes of payload
     */
    inline RawFrame buildDirectServiceFrame(EF00ServiceID serviceId,
                                             const uint8_t* payload = nullptr,
                                             uint8_t payloadLen = 0)
    {
        RawFrame f;
        f.data[0] = static_cast<uint8_t>(serviceId);
        // Copy payload bytes
        uint8_t copyLen = (payloadLen > 7) ? 7 : payloadLen;
        for (uint8_t i = 0; i < copyLen; i++) {
            f.data[1 + i] = payload ? payload[i] : 0x00;
        }
        // Pad remaining with 0x00
        for (uint8_t i = copyLen; i < 7; i++) {
            f.data[1 + i] = 0x00;
        }
        f.len = 8;
        return f;
    }

    /**
     * Build GetParametersByID direct service frame (0x10)
     *
     * Service 0x10 maps to handler @ 0x1b07e
     * This is the CLIP-compatible GetParametersByID operation!
     *
     * @param paramId Parameter ID to read
     * @param flags Additional flags
     */
    inline RawFrame buildDirectGetParam(uint8_t paramId = 0x00, uint8_t flags = 0x00)
    {
        RawFrame f;
        f.data[0] = static_cast<uint8_t>(EF00ServiceID::GetParametersByID);  // 0x10
        f.data[1] = paramId;
        f.data[2] = flags;
        f.data[3] = 0x00;
        f.data[4] = 0x00;
        f.data[5] = 0x00;
        f.data[6] = 0x00;
        f.data[7] = 0x00;
        f.len = 8;
        return f;
    }

    /**
     * Build GetAddressByParameterID direct service frame (0x15)
     *
     * Service 0x15 maps to handler @ 0xf9f0
     * This is the CLIP-compatible GetAddressByParameterID operation!
     *
     * @param paramId Parameter ID to look up
     */
    inline RawFrame buildDirectGetAddress(uint8_t paramId = 0x00)
    {
        RawFrame f;
        f.data[0] = static_cast<uint8_t>(EF00ServiceID::GetAddressByParameterID);  // 0x15
        f.data[1] = paramId;
        f.data[2] = 0x00;
        f.data[3] = 0x00;
        f.data[4] = 0x00;
        f.data[5] = 0x00;
        f.data[6] = 0x00;
        f.data[7] = 0x00;
        f.len = 8;
        return f;
    }

    /**
     * Build QueryTerminate direct service frame (0x01)
     *
     * Service 0x01 maps to handler @ 0xf86a
     * This may be the CLIP-compatible QueryTerminate operation.
     */
    inline RawFrame buildDirectQueryTerminate()
    {
        RawFrame f;
        f.data[0] = static_cast<uint8_t>(EF00ServiceID::QueryTerminate);  // 0x01
        for (int i = 1; i < 8; i++) {
            f.data[i] = 0x00;
        }
        f.len = 8;
        return f;
    }

    /**
     * Build a test frame for any registered service ID
     * Useful for probing unknown services
     *
     * @param serviceId Raw service ID byte (0x01-0x4D)
     * @param byte1-7 Additional bytes
     */
    inline RawFrame buildServiceProbe(uint8_t serviceId,
                                       uint8_t byte1 = 0x00,
                                       uint8_t byte2 = 0x00,
                                       uint8_t byte3 = 0x00,
                                       uint8_t byte4 = 0x00,
                                       uint8_t byte5 = 0x00,
                                       uint8_t byte6 = 0x00,
                                       uint8_t byte7 = 0x00)
    {
        RawFrame f;
        f.data[0] = serviceId;
        f.data[1] = byte1;
        f.data[2] = byte2;
        f.data[3] = byte3;
        f.data[4] = byte4;
        f.data[5] = byte5;
        f.data[6] = byte6;
        f.data[7] = byte7;
        f.len = 8;
        return f;
    }

    /**
     * Describe EF00 service ID
     */
    static inline std::string describeEF00ServiceID(uint8_t svcId)
    {
        switch (svcId) {
            case 0x01: return "QueryTerminate (0x01)";
            case 0x04: return "SystemService04 (0x04)";
            case 0x05: return "SystemService05 (0x05)";
            case 0x06: return "SystemService06 (0x06)";
            case 0x07: return "SystemService07 (0x07)";
            case 0x0A: return "SystemService0A (0x0A)";
            case 0x0B: return "SystemService0B (0x0B)";
            case 0x0F: return "SystemService0F (0x0F)";
            case 0x10: return "GetParametersByID (0x10)";
            case 0x15: return "GetAddressByParameterID (0x15)";
            case 0x16: return "SystemService16 (0x16)";
            case 0x18: return "SystemService18 (0x18)";
            case 0x41: return "Service41 (0x41)";
            case 0x43: return "Service43 (0x43)";
            case 0x44: return "Service44 (0x44)";
            case 0x45: return "Service45 (0x45)";
            case 0x46: return "Service46 (0x46)";
            case 0x47: return "Service47 (0x47)";
            case 0x48: return "Service48 (0x48)";
            case 0x49: return "Service49 (0x49)";
            case 0x4A: return "Service4A (0x4A)";
            case 0x4B: return "Service4B (0x4B)";
            case 0x4C: return "Service4C (0x4C)";
            case 0x4D: return "Service4D (0x4D)";
            default:
                std::ostringstream ss;
                ss << "UnknownService(0x" << std::hex << static_cast<int>(svcId) << ")";
                return ss.str();
        }
    }

    /**
     * Check if a service ID is registered in the EF00 dispatch table
     */
    inline bool isRegisteredServiceID(uint8_t svcId)
    {
        // List of all registered service IDs
        static const uint8_t registered[] = {
            0x01, 0x04, 0x05, 0x06, 0x07, 0x0A, 0x0B, 0x0F,
            0x10, 0x15, 0x16, 0x18,
            0x41, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49,
            0x4A, 0x4B, 0x4C, 0x4D
        };
        for (size_t i = 0; i < sizeof(registered); i++) {
            if (svcId == registered[i]) return true;
        }
        return false;
    }

} // namespace Clip

#endif // CLIP_FRAME_H
