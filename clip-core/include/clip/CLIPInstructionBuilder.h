#ifndef CLIPINSTRUCTIONBUILDER_H
#define CLIPINSTRUCTIONBUILDER_H

#include <cstdint>
#include <vector>
#include "types/EClipCommand.h"
#include "types/TClipPacket.h"

/**
 * @brief Builds CLIP instruction packets.
 *
 * Creates properly formatted CLIP command packets for ECU communication.
 *
 * Command formats:
 *   GetParametersByID (0x10):  [CMD][SEQ][ParamID:2]...
 *   SetParametersByID (0x11):  [CMD][SEQ][ParamID:2][Value]...
 *   ExecuteOperation (0x12):   [CMD][SEQ][OpID:2][Args]...
 *   GetDataByAddress (0x14):   [CMD][SEQ][Addr:4BE][Len:2BE]
 *   SetDataByAddress (0x15):   [CMD][SEQ][Addr:4BE][Len:2BE][Data]...
 *   GetAddressByParamID (0x16): [CMD][SEQ][ParamID:2]
 *
 * Note: Address and length in memory commands use big-endian byte order.
 *
 * Reference: ECU_PROGRAMMING_PROTOCOL.md, DeviceControl_ghidra.c:63470-65220
 */
class CLIPInstructionBuilder
{
public:
    CLIPInstructionBuilder();
    ~CLIPInstructionBuilder() = default;

    /**
     * @brief Build GetParametersByID packet.
     * @param parameterIds List of 2-byte parameter IDs to read
     * @return Complete CLIP packet
     */
    TClipPacket buildGetParametersByID(const std::vector<uint16_t>& parameterIds);

    /**
     * @brief Build SetParametersByID packet.
     * @param parameterId 2-byte parameter ID
     * @param value Parameter value bytes
     * @return Complete CLIP packet
     */
    TClipPacket buildSetParametersByID(uint16_t parameterId,
                                        const std::vector<uint8_t>& value);

    /**
     * @brief Build ExecuteOperation packet.
     * @param operationId 2-byte operation ID
     * @param args Operation arguments
     * @return Complete CLIP packet
     */
    TClipPacket buildExecuteOperation(uint16_t operationId,
                                       const std::vector<uint8_t>& args = {});

    /**
     * @brief Build GetDataByAddress packet (raw memory read).
     * @param address 4-byte memory address
     * @param length Number of bytes to read (max 0xD000)
     * @return Complete CLIP packet
     *
     * This is the key command for firmware extraction!
     */
    TClipPacket buildGetDataByAddress(uint32_t address, uint16_t length);

    /**
     * @brief Build SetDataByAddress packet (raw memory write).
     * @param address 4-byte memory address
     * @param data Data to write
     * @return Complete CLIP packet
     */
    TClipPacket buildSetDataByAddress(uint32_t address,
                                       const std::vector<uint8_t>& data);

    /**
     * @brief Build GetAddressByParameterID packet.
     * @param parameterId 2-byte parameter ID
     * @return Complete CLIP packet
     */
    TClipPacket buildGetAddressByParameterID(uint16_t parameterId);

    /**
     * @brief Get the next sequence ID.
     *
     * Each request should use a unique sequence ID for matching responses.
     */
    uint8_t getNextSequenceId();

    /**
     * @brief Reset sequence ID counter.
     */
    void resetSequenceId();

private:
    uint8_t m_sequenceId;

    /**
     * @brief Append 16-bit value in big-endian format.
     */
    static void appendUint16BE(std::vector<uint8_t>& data, uint16_t value);

    /**
     * @brief Append 32-bit value in big-endian format.
     */
    static void appendUint32BE(std::vector<uint8_t>& data, uint32_t value);
};

#endif // CLIPINSTRUCTIONBUILDER_H
