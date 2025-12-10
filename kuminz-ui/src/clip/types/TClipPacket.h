#ifndef TCLIPPACKET_H
#define TCLIPPACKET_H

#include <cstdint>
#include <vector>
#include <cstring>

/**
 * @brief Maximum payload size per CAN frame for CLIP.
 *
 * CAN frame = 8 bytes total
 * CLIP header = 3 bytes (session/type, connection ID, control)
 * Payload = 5 bytes max
 */
constexpr uint8_t CLIP_MAX_FRAME_PAYLOAD = 5;

/**
 * @brief Maximum number of fragments in a CLIP multi-packet transfer.
 *
 * Sequence number is 3 bits (0-7), so max 8 fragments.
 */
constexpr uint8_t CLIP_MAX_FRAGMENTS = 8;

/**
 * @brief Maximum block read size per CLIP request.
 *
 * From CUDL_ghidra.c: 0xD000 bytes (52,224 bytes)
 */
constexpr uint32_t CLIP_MAX_BLOCK_SIZE = 0xD000;

/**
 * @brief Default timeout for CLIP operations in milliseconds.
 */
constexpr int CLIP_DEFAULT_TIMEOUT_MS = 5000;

/**
 * @brief Session open timeout in milliseconds.
 */
constexpr int CLIP_SESSION_TIMEOUT_MS = 15000;

/**
 * @brief J1939 tool source address (standard diagnostic tool address).
 */
constexpr uint8_t J1939_TOOL_ADDRESS = 0xF9;

/**
 * @brief J1939 priority for CLIP messages (6 = typical data priority).
 */
constexpr uint8_t J1939_CLIP_PRIORITY = 6;

/**
 * @brief J1939 PGN PDU Format for CLIP data.
 */
constexpr uint8_t J1939_CLIP_PGN_PF = 0xEA;

/**
 * @brief J1939 PGN for CLIP response.
 */
constexpr uint8_t J1939_CLIP_RESPONSE_PGN = 0xEF;

// ============================================================================
// CM550 Memory Regions
// ============================================================================
// Derived from addressRangeValidator() table at 0x0002B512 in CM550 firmware.
// These define the readable memory regions for CM550 ECUs.
//
// Permission flags from firmware:
//   0x04 = Read allowed (ROM)
//   0x03 = Read allowed (RAM/registers)
//   0x05 = Read allowed (EEPROM)
//   0x00 = Disabled/protected

/**
 * @brief CM550 ROM region start address.
 * Contains firmware/code. 256KB total.
 */
constexpr uint32_t CM550_ROM_START = 0x00000000;
constexpr uint32_t CM550_ROM_END = 0x0003FFFF;
constexpr uint32_t CM550_ROM_SIZE = 0x00040000;  // 256KB

/**
 * @brief CM550 RAM region start address.
 * Contains runtime data. ~37KB accessible.
 */
constexpr uint32_t CM550_RAM_START = 0x00800000;
constexpr uint32_t CM550_RAM_END = 0x008091C2;
constexpr uint32_t CM550_RAM_SIZE = 0x000091C2;  // ~37KB

/**
 * @brief CM550 EEPROM region (calibration data).
 * Contains calibration parameters. 4KB total.
 */
constexpr uint32_t CM550_EEPROM_START = 0x01000000;
constexpr uint32_t CM550_EEPROM_END = 0x01000FFF;
constexpr uint32_t CM550_EEPROM_SIZE = 0x00001000;  // 4KB

/**
 * @brief CM550 hardware register region.
 * Contains peripheral registers. ~14KB.
 */
constexpr uint32_t CM550_HWREG_START = 0x00FFC800;
constexpr uint32_t CM550_HWREG_END = 0x00FFFFFF;
constexpr uint32_t CM550_HWREG_SIZE = 0x00003800;  // ~14KB

/**
 * @brief CM550 protected RAM region (NOT readable).
 * Upper RAM is disabled in validation table.
 */
constexpr uint32_t CM550_PROTECTED_RAM_START = 0x008091C2;
constexpr uint32_t CM550_PROTECTED_RAM_END = 0x0080FFFF;

/**
 * @brief CLIP transport frame structure.
 *
 * Represents a single CAN frame in CLIP format.
 */
struct TClipFrame
{
    uint8_t sessionId;      // 3-bit session ID (bits 7:5 of byte 0)
    uint8_t msgType;        // Message type (bits 4:0 of byte 0)
    uint8_t connectionId;   // Connection ID (byte 1)
    uint8_t control;        // Control flags (byte 2)
    uint8_t payload[CLIP_MAX_FRAME_PAYLOAD];
    uint8_t payloadLen;

    TClipFrame()
        : sessionId(0), msgType(0), connectionId(0), control(0), payloadLen(0)
    {
        std::memset(payload, 0, sizeof(payload));
    }

    /**
     * @brief Encode frame to raw CAN data.
     * @param data Output buffer (8 bytes)
     * @return Number of bytes written
     */
    uint8_t encode(uint8_t* data) const
    {
        data[0] = static_cast<uint8_t>((sessionId << 5) | (msgType & 0x1F));
        data[1] = connectionId;
        data[2] = control;
        std::memcpy(data + 3, payload, payloadLen);
        return static_cast<uint8_t>(3 + payloadLen);
    }

    /**
     * @brief Decode frame from raw CAN data.
     * @param data Input buffer
     * @param len Number of bytes in buffer
     * @return true if decoded successfully
     */
    bool decode(const uint8_t* data, uint8_t len)
    {
        if (len < 3) return false;

        sessionId = (data[0] >> 5) & 0x07;
        msgType = data[0] & 0x1F;
        connectionId = data[1];
        control = data[2];
        payloadLen = static_cast<uint8_t>(len > 3 ? len - 3 : 0);
        if (payloadLen > 0) {
            std::memcpy(payload, data + 3, payloadLen);
        }
        return true;
    }

    /**
     * @brief Get sequence number from data transfer frame.
     *
     * For DataTransfer (0x03) messages, the sequence is in bits 7:5 of byte 0.
     */
    uint8_t getSequence() const
    {
        return sessionId;  // Reuses session ID field for sequence in data frames
    }
};

/**
 * @brief CLIP instruction packet structure.
 *
 * Represents a complete CLIP command before fragmentation.
 */
struct TClipPacket
{
    uint8_t command;        // Command code (EClipCommand)
    uint8_t sequenceId;     // Request sequence ID for matching responses
    std::vector<uint8_t> payload;

    TClipPacket() : command(0), sequenceId(0) {}

    TClipPacket(uint8_t cmd, uint8_t seq)
        : command(cmd), sequenceId(seq) {}

    /**
     * @brief Get total packet size (header + payload).
     */
    size_t size() const
    {
        return 2 + payload.size();  // 2-byte header minimum
    }

    /**
     * @brief Serialize packet to byte vector.
     */
    std::vector<uint8_t> serialize() const
    {
        std::vector<uint8_t> data;
        data.reserve(size());
        data.push_back(command);
        data.push_back(sequenceId);
        data.insert(data.end(), payload.begin(), payload.end());
        return data;
    }
};

/**
 * @brief Seed reply packet data.
 */
struct TSeedReply
{
    uint8_t encryptionLevel1;
    uint8_t encryptionLevel2;
    uint8_t seed[4];

    TSeedReply() : encryptionLevel1(0), encryptionLevel2(0)
    {
        std::memset(seed, 0, sizeof(seed));
    }

    bool decode(const uint8_t* data, uint8_t len)
    {
        if (len < 6) return false;
        encryptionLevel1 = data[0];
        encryptionLevel2 = data[1];
        std::memcpy(seed, data + 2, 4);
        return true;
    }
};

#endif // TCLIPPACKET_H
