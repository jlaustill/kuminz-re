#include "clip/J1939MessageBuilder.h"

J1939MessageBuilder::J1939MessageBuilder()
    : m_sourceAddress(J1939_TOOL_ADDRESS)
{
}

void J1939MessageBuilder::setSourceAddress(uint8_t address)
{
    m_sourceAddress = address;
}

uint8_t J1939MessageBuilder::getSourceAddress() const
{
    return m_sourceAddress;
}

uint32_t J1939MessageBuilder::buildClipDataArbId(uint8_t destAddress) const
{
    // 29-bit extended ID format:
    // Bits [28:26] = Priority (6)
    // Bits [25:24] = Reserved (0)
    // Bits [23:16] = PDU Format (0xEA for CLIP)
    // Bits [15:8]  = Destination Address
    // Bits [7:0]   = Source Address

    uint32_t arbId = 0;
    arbId |= (static_cast<uint32_t>(J1939_CLIP_PRIORITY) << 26);  // Priority
    arbId |= (static_cast<uint32_t>(J1939_CLIP_PGN_PF) << 16);    // PF = 0xEA
    arbId |= (static_cast<uint32_t>(destAddress) << 8);           // Destination
    arbId |= static_cast<uint32_t>(m_sourceAddress);              // Source

    return arbId;
}

uint32_t J1939MessageBuilder::buildComponentIdRequestArbId(uint8_t destAddress) const
{
    // PGN 0xFEEB for Component ID request
    // PF = 0xFE, PS = 0xEB (group extension)
    // For PDU1 format (PF < 240), PS is destination
    // For PDU2 format (PF >= 240), PS is group extension

    // PGN 0xFEEB: PF = 0xFE (254), PS = 0xEB (235)
    // This is PDU2 format (broadcast/global)

    uint32_t arbId = 0;
    arbId |= (static_cast<uint32_t>(J1939_CLIP_PRIORITY) << 26);  // Priority
    arbId |= (static_cast<uint32_t>(0xFE) << 16);                 // PF = 0xFE
    arbId |= (static_cast<uint32_t>(0xEB) << 8);                  // PS = 0xEB (group ext)
    arbId |= static_cast<uint32_t>(m_sourceAddress);              // Source

    // Note: For broadcast, destAddress is ignored (PS is group extension)
    (void)destAddress;

    return arbId;
}

uint8_t J1939MessageBuilder::extractSourceAddress(uint32_t arbId)
{
    return static_cast<uint8_t>(arbId & 0xFF);
}

uint8_t J1939MessageBuilder::extractDestAddress(uint32_t arbId)
{
    return static_cast<uint8_t>((arbId >> 8) & 0xFF);
}

uint8_t J1939MessageBuilder::extractPduFormat(uint32_t arbId)
{
    return static_cast<uint8_t>((arbId >> 16) & 0xFF);
}

bool J1939MessageBuilder::isClipResponse(uint32_t arbId)
{
    uint8_t pf = extractPduFormat(arbId);
    return pf == J1939_CLIP_RESPONSE_PGN;  // 0xEF
}

bool J1939MessageBuilder::isComponentIdResponse(uint32_t arbId)
{
    // PGN 0xFEEB: check both PF (0xFE) and PS (0xEB)
    uint8_t pf = extractPduFormat(arbId);
    uint8_t ps = extractDestAddress(arbId);  // PS is in same position as dest for PDU2
    return (pf == 0xFE) && (ps == 0xEB);
}
