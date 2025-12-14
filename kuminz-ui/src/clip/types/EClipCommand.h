#ifndef ECLIPCOMMAND_H
#define ECLIPCOMMAND_H

#include <cstdint>

/**
 * @brief CLIP instruction command codes.
 *
 * These are the command opcodes used in the CLIP (Cummins Insite Protocol)
 * for ECU communication.
 *
 * Reference: ECU_PROGRAMMING_PROTOCOL.md, DeviceControl_ghidra.c:63470-65220
 */
enum class EClipCommand : uint8_t
{
    GetParametersByID      = 0x10,  // Read parameter values by ID
    SetParametersByID      = 0x11,  // Write parameter values by ID
    ExecuteOperation       = 0x12,  // Execute an ECU operation
    // 0x13 is reserved/unused
    GetDataByAddress       = 0x14,  // Read raw data from memory address
    SetDataByAddress       = 0x15,  // Write raw data to memory address
    GetAddressByParameterID = 0x16  // Get memory address for a parameter
};

/**
 * @brief CLIP transport message types.
 *
 * These are the control bits in byte 0 of CLIP transport frames
 * (bits 4:0 after extracting session ID from bits 7:5).
 *
 * Reference: Insite PCLSystem_ghidra.c - CLIPProtocolManager methods
 */
enum class EClipMsgType : uint8_t
{
    TransportOpen     = 0x02,  // Session open / seed reply
    DataTransfer      = 0x03,  // Data transfer with sequence number
    ClearToSend       = 0x04,  // CTS / context reply / acknowledgment
    ConnectionRefused = 0x05,  // Connection refused by ECU
    TransportClose    = 0x06   // Session close request (per Insite PCLSystem_ghidra.c:45421)
};

/**
 * @brief CLIP request status codes.
 */
enum class EClipRequestStatus : uint8_t
{
    Success    = 1,
    Fail       = 2,
    Processing = 3,
    NeedProcess = 4
};

/**
 * @brief CLIP transport error codes.
 */
enum class EClipTransportError : uint8_t
{
    None           = 0,
    Timeout        = 1,
    Aborted        = 2,
    Collision      = 3,
    OutOfSequence  = 4
};

#endif // ECLIPCOMMAND_H
