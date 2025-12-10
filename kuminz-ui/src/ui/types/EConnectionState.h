#ifndef ECONNECTIONSTATE_H
#define ECONNECTIONSTATE_H

#include <cstdint>

/**
 * @brief ECU connection state (protocol layer).
 *
 * This represents the state of the CLIP protocol connection to an ECU.
 * Separate from adapter state - you can have an adapter ready but no ECU connected.
 */
enum class EConnectionState : uint8_t
{
    Disconnected = 0x00,  // Not connected to ECU
    Connecting   = 0x01,  // Connection attempt in progress
    Connected    = 0x02,  // Successfully connected and authenticated
    Error        = 0x03   // Connection failed or lost
};

#endif // ECONNECTIONSTATE_H
