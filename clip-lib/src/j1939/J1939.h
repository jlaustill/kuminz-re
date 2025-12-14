#ifndef J1939_H
#define J1939_H

#include <cstdint>
#include <string>
#include <sstream>
#include <iomanip>

/**
 * J1939 CAN arbitration ID utilities.
 *
 * 29-bit Extended CAN ID Format:
 *   Bits [28:26] = Priority (3 bits)
 *   Bits [25:24] = Reserved/Data Page (2 bits)
 *   Bits [23:16] = PDU Format (PF) - determines PGN type
 *   Bits [15:8]  = PDU Specific (PS) - destination or group extension
 *   Bits [7:0]   = Source Address (SA)
 *
 * For CLIP (Cummins protocol) - uses J1939 Proprietary A (PGN 0xEF00):
 *   TX: PF=0xEF, PS=ECU address, SA=tool address
 *   RX: PF=0xEF, PS=tool address, SA=ECU address
 *
 * NOTE: PF=0xEA is J1939 Request PGN - NOT for CLIP data!
 */
namespace J1939
{
    // Default addresses
    constexpr uint8_t TOOL_ADDRESS = 0xF9;      // Diagnostic tool address
    constexpr uint8_t BROADCAST_ADDRESS = 0xFF; // Broadcast address

    // CLIP protocol uses Proprietary A (PGN 0xEF00)
    constexpr uint8_t CLIP_PF_DATA = 0xEF;      // CLIP data (both TX and RX)

    // Legacy names for compatibility
    constexpr uint8_t CLIP_PF_REQUEST = 0xEF;   // CLIP request to ECU (Proprietary A)
    constexpr uint8_t CLIP_PF_RESPONSE = 0xEF;  // CLIP response from ECU (Proprietary A)

    // Standard J1939 PGNs
    constexpr uint8_t J1939_PF_ACK = 0xE8;      // J1939 Acknowledgment (59392)
    constexpr uint8_t J1939_PF_REQUEST = 0xEA;  // J1939 Request (59904) - NOT for CLIP!

    // J1939 Transport Protocol PGNs (for multi-frame messages)
    constexpr uint8_t J1939_PF_TP_DT = 0xEB;    // TP Data Transfer (60160)
    constexpr uint8_t J1939_PF_TP_CM = 0xEC;    // TP Connection Management (60416)

    // Default priority
    constexpr uint8_t DEFAULT_PRIORITY = 6;

    /**
     * Build a 29-bit arbitration ID
     */
    inline uint32_t buildArbId(uint8_t priority, uint8_t pf, uint8_t ps, uint8_t sa)
    {
        uint32_t id = 0;
        id |= (static_cast<uint32_t>(priority & 0x07) << 26);
        id |= (static_cast<uint32_t>(pf) << 16);
        id |= (static_cast<uint32_t>(ps) << 8);
        id |= static_cast<uint32_t>(sa);
        return id;
    }

    /**
     * Build CLIP request arbitration ID (tool -> ECU)
     */
    inline uint32_t buildClipRequestId(uint8_t ecuAddress, uint8_t toolAddress = TOOL_ADDRESS)
    {
        return buildArbId(DEFAULT_PRIORITY, CLIP_PF_REQUEST, ecuAddress, toolAddress);
    }

    /**
     * Build CLIP response filter ID (ECU -> tool)
     */
    inline uint32_t buildClipResponseId(uint8_t ecuAddress, uint8_t toolAddress = TOOL_ADDRESS)
    {
        return buildArbId(DEFAULT_PRIORITY, CLIP_PF_RESPONSE, toolAddress, ecuAddress);
    }

    /**
     * Build J1939 Request PGN arbitration ID (tool -> ECU)
     * Used for standard J1939 parameter requests, NOT for CLIP!
     */
    inline uint32_t buildRequestId(uint8_t ecuAddress, uint8_t toolAddress = TOOL_ADDRESS)
    {
        return buildArbId(DEFAULT_PRIORITY, J1939_PF_REQUEST, ecuAddress, toolAddress);
    }

    /**
     * Extract source address from arbitration ID
     */
    inline uint8_t extractSource(uint32_t arbId)
    {
        return static_cast<uint8_t>(arbId & 0xFF);
    }

    /**
     * Extract PDU specific (destination/PS) from arbitration ID
     */
    inline uint8_t extractDest(uint32_t arbId)
    {
        return static_cast<uint8_t>((arbId >> 8) & 0xFF);
    }

    /**
     * Extract PDU format from arbitration ID
     */
    inline uint8_t extractPF(uint32_t arbId)
    {
        return static_cast<uint8_t>((arbId >> 16) & 0xFF);
    }

    /**
     * Extract priority from arbitration ID
     */
    inline uint8_t extractPriority(uint32_t arbId)
    {
        return static_cast<uint8_t>((arbId >> 26) & 0x07);
    }

    /**
     * Check if this is a CLIP response (PF=0xEF)
     */
    inline bool isClipResponse(uint32_t arbId)
    {
        return extractPF(arbId) == CLIP_PF_RESPONSE;
    }

    /**
     * Check if this is a CLIP request (PF=0xEA)
     */
    inline bool isClipRequest(uint32_t arbId)
    {
        return extractPF(arbId) == CLIP_PF_REQUEST;
    }

    /**
     * Format arbitration ID for display
     */
    inline std::string formatArbId(uint32_t arbId)
    {
        std::ostringstream ss;
        ss << std::hex << std::uppercase << std::setfill('0') << std::setw(8) << arbId;
        ss << " (Pri=" << std::dec << static_cast<int>(extractPriority(arbId));
        ss << " PF=" << std::hex << std::setw(2) << static_cast<int>(extractPF(arbId));
        ss << " PS=" << std::setw(2) << static_cast<int>(extractDest(arbId));
        ss << " SA=" << std::setw(2) << static_cast<int>(extractSource(arbId)) << ")";
        return ss.str();
    }

    /**
     * Describe what type of message this is
     */
    inline std::string describeMessage(uint32_t arbId)
    {
        uint8_t pf = extractPF(arbId);
        uint8_t source = extractSource(arbId);

        std::ostringstream ss;

        // Common J1939 PGNs
        switch (pf) {
            case CLIP_PF_DATA:  // 0xEF - Proprietary A / CLIP
                ss << "CLIP/ProprietaryA from 0x" << std::hex << static_cast<int>(source);
                break;
            case J1939_PF_REQUEST:  // 0xEA - Request
                ss << "J1939 Request from 0x" << std::hex << static_cast<int>(source);
                break;
            case J1939_PF_ACK:  // 0xE8 - Acknowledgment
                ss << "J1939 ACK from 0x" << std::hex << static_cast<int>(source);
                break;
            case 0xF0:
                ss << "J1939 PF=F0 from 0x" << std::hex << static_cast<int>(source);
                break;
            case 0xFE:
                ss << "J1939 ProprietaryB from 0x" << std::hex << static_cast<int>(source);
                break;
            case 0xEC:
                ss << "J1939 TP.CM from 0x" << std::hex << static_cast<int>(source);
                break;
            case 0xEB:
                ss << "J1939 TP.DT from 0x" << std::hex << static_cast<int>(source);
                break;
            default:
                ss << "J1939 PF=0x" << std::hex << static_cast<int>(pf);
                ss << " from 0x" << static_cast<int>(source);
        }

        return ss.str();
    }
}

#endif // J1939_H
