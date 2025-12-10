#ifndef ESESSIONSTATE_H
#define ESESSIONSTATE_H

#include <cstdint>

/**
 * @brief CLIP session states.
 *
 * State machine for CLIP session management with seed/key authentication.
 *
 * State flow:
 *   CLOSED -> REQUESTING_SEED -> SEEDED -> AUTHENTICATED
 *
 * Reference: ECU_PROGRAMMING_PROTOCOL.md, DeviceControl_ghidra.c:67039-67207
 */
enum class ESessionState : uint8_t
{
    Closed          = 0x01,  // No session
    Opening         = 0x02,  // Open request sent, waiting for response
    RequestingSeed  = 0x04,  // Waiting for seed reply
    Seeded          = 0x05,  // Seed received, ready to encrypt context
    Authenticated   = 0x07,  // Context exchanged, data transfer enabled
    SecuredLocked   = 0x08   // Encryption required but not licensed/available
};

/**
 * @brief Check if session state allows data transfer.
 */
inline bool canTransferData(ESessionState state)
{
    return state == ESessionState::Authenticated;
}

/**
 * @brief Check if session is in a connecting state.
 */
inline bool isConnecting(ESessionState state)
{
    return state == ESessionState::Opening ||
           state == ESessionState::RequestingSeed ||
           state == ESessionState::Seeded;
}

#endif // ESESSIONSTATE_H
