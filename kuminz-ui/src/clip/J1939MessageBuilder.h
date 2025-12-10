#ifndef J1939MESSAGEBUILDER_H
#define J1939MESSAGEBUILDER_H

#include <cstdint>
#include "types/TClipPacket.h"

/**
 * @brief Builds J1939 CAN message arbitration IDs for CLIP communication.
 *
 * J1939 uses 29-bit extended CAN arbitration IDs with the following format:
 *   Bits [28:26] = Priority (3 bits)
 *   Bits [25:24] = Reserved/Data Page (2 bits)
 *   Bits [23:16] = PDU Format (PF) - determines PGN type
 *   Bits [15:8]  = PDU Specific (PS) - destination or group extension
 *   Bits [7:0]   = Source Address (SA)
 *
 * For CLIP data (PGN 0x00EA00):
 *   Priority = 6 (0b110)
 *   PF = 0xEA (234)
 *   PS = Destination Address
 *   SA = Tool Address (typically 0xF9 = 249)
 *
 * Example: Tool (0xF9) → ECU (0x00) = 0x18EA00F9
 *
 * Reference: ECU_PROGRAMMING_PROTOCOL.md
 */
class J1939MessageBuilder
{
public:
    J1939MessageBuilder();
    ~J1939MessageBuilder() = default;

    /**
     * @brief Set the source address (tool address).
     * @param address Source address (default: 0xF9)
     */
    void setSourceAddress(uint8_t address);

    /**
     * @brief Get the current source address.
     */
    uint8_t getSourceAddress() const;

    /**
     * @brief Build arbitration ID for CLIP data message.
     * @param destAddress Destination ECU address
     * @return 29-bit arbitration ID
     */
    uint32_t buildClipDataArbId(uint8_t destAddress) const;

    /**
     * @brief Build arbitration ID for Component ID request (PGN 0xFEEB).
     * @param destAddress Destination address (0xFF for broadcast)
     * @return 29-bit arbitration ID
     */
    uint32_t buildComponentIdRequestArbId(uint8_t destAddress = 0xFF) const;

    /**
     * @brief Extract source address from received arbitration ID.
     * @param arbId 29-bit arbitration ID
     * @return Source address (bits 7:0)
     */
    static uint8_t extractSourceAddress(uint32_t arbId);

    /**
     * @brief Extract destination address from received arbitration ID.
     * @param arbId 29-bit arbitration ID
     * @return Destination address (bits 15:8)
     */
    static uint8_t extractDestAddress(uint32_t arbId);

    /**
     * @brief Extract PDU Format (PGN type) from arbitration ID.
     * @param arbId 29-bit arbitration ID
     * @return PDU Format (bits 23:16)
     */
    static uint8_t extractPduFormat(uint32_t arbId);

    /**
     * @brief Check if arbitration ID is a CLIP response (PGN 0xEF).
     * @param arbId 29-bit arbitration ID
     * @return true if CLIP response message
     */
    static bool isClipResponse(uint32_t arbId);

    /**
     * @brief Check if arbitration ID is a Component ID response (PGN 0xFEEB).
     * @param arbId 29-bit arbitration ID
     * @return true if Component ID response
     */
    static bool isComponentIdResponse(uint32_t arbId);

private:
    uint8_t m_sourceAddress;
};

#endif // J1939MESSAGEBUILDER_H
