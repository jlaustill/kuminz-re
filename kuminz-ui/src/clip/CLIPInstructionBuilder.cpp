#include "CLIPInstructionBuilder.h"

CLIPInstructionBuilder::CLIPInstructionBuilder()
    : m_sequenceId(0)
{
}

uint8_t CLIPInstructionBuilder::getNextSequenceId()
{
    return m_sequenceId++;
}

void CLIPInstructionBuilder::resetSequenceId()
{
    m_sequenceId = 0;
}

void CLIPInstructionBuilder::appendUint16BE(std::vector<uint8_t>& data, uint16_t value)
{
    data.push_back(static_cast<uint8_t>((value >> 8) & 0xFF));  // High byte first
    data.push_back(static_cast<uint8_t>(value & 0xFF));         // Low byte
}

void CLIPInstructionBuilder::appendUint32BE(std::vector<uint8_t>& data, uint32_t value)
{
    data.push_back(static_cast<uint8_t>((value >> 24) & 0xFF));  // MSB first
    data.push_back(static_cast<uint8_t>((value >> 16) & 0xFF));
    data.push_back(static_cast<uint8_t>((value >> 8) & 0xFF));
    data.push_back(static_cast<uint8_t>(value & 0xFF));          // LSB last
}

TClipPacket CLIPInstructionBuilder::buildGetParametersByID(
    const std::vector<uint16_t>& parameterIds)
{
    // Format: [0x10][SEQ][ParamID:2]...
    // Header size: 2 bytes

    TClipPacket packet(static_cast<uint8_t>(EClipCommand::GetParametersByID),
                       getNextSequenceId());

    packet.payload.reserve(parameterIds.size() * 2);
    for (uint16_t id : parameterIds) {
        appendUint16BE(packet.payload, id);
    }

    return packet;
}

TClipPacket CLIPInstructionBuilder::buildSetParametersByID(
    uint16_t parameterId,
    const std::vector<uint8_t>& value)
{
    // Format: [0x11][SEQ][ParamID:2][Value]...
    // Header size: 2 bytes

    TClipPacket packet(static_cast<uint8_t>(EClipCommand::SetParametersByID),
                       getNextSequenceId());

    packet.payload.reserve(2 + value.size());
    appendUint16BE(packet.payload, parameterId);
    packet.payload.insert(packet.payload.end(), value.begin(), value.end());

    return packet;
}

TClipPacket CLIPInstructionBuilder::buildExecuteOperation(
    uint16_t operationId,
    const std::vector<uint8_t>& args)
{
    // Format: [0x12][SEQ][OpID:2][Args]...
    // Header size: 4 bytes (includes OpID in header)

    TClipPacket packet(static_cast<uint8_t>(EClipCommand::ExecuteOperation),
                       getNextSequenceId());

    packet.payload.reserve(2 + args.size());
    appendUint16BE(packet.payload, operationId);
    packet.payload.insert(packet.payload.end(), args.begin(), args.end());

    return packet;
}

TClipPacket CLIPInstructionBuilder::buildGetDataByAddress(
    uint32_t address,
    uint16_t length)
{
    // Format: [0x14][SEQ][Addr:4BE][Len:2BE]
    // Header size: 8 bytes (includes address and length)
    // This is the key command for firmware extraction!

    TClipPacket packet(static_cast<uint8_t>(EClipCommand::GetDataByAddress),
                       getNextSequenceId());

    packet.payload.reserve(6);  // 4 bytes address + 2 bytes length
    appendUint32BE(packet.payload, address);
    appendUint16BE(packet.payload, length);

    return packet;
}

TClipPacket CLIPInstructionBuilder::buildSetDataByAddress(
    uint32_t address,
    const std::vector<uint8_t>& data)
{
    // Format: [0x15][SEQ][Addr:4BE][Len:2BE][Data]...
    // Header size: 8 bytes

    TClipPacket packet(static_cast<uint8_t>(EClipCommand::SetDataByAddress),
                       getNextSequenceId());

    uint16_t length = static_cast<uint16_t>(data.size());

    packet.payload.reserve(6 + data.size());
    appendUint32BE(packet.payload, address);
    appendUint16BE(packet.payload, length);
    packet.payload.insert(packet.payload.end(), data.begin(), data.end());

    return packet;
}

TClipPacket CLIPInstructionBuilder::buildGetAddressByParameterID(uint16_t parameterId)
{
    // Format: [0x16][SEQ][ParamID:2]
    // Header size: 2 bytes

    TClipPacket packet(static_cast<uint8_t>(EClipCommand::GetAddressByParameterID),
                       getNextSequenceId());

    packet.payload.reserve(2);
    appendUint16BE(packet.payload, parameterId);

    return packet;
}
