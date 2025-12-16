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

// Note: EClipMsgType is defined in TClipPacket.h to avoid duplication

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
