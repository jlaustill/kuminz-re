#ifndef EADAPTERSTATE_H
#define EADAPTERSTATE_H

#include <cstdint>

/**
 * @brief State of the CAN adapter (hardware/driver layer).
 *
 * This is separate from ECU connection state - the adapter can be
 * ready without an ECU being connected.
 */
enum class EAdapterState : uint8_t
{
    NotReady    = 0x00,  // Adapter not set up (no slcand, interface down)
    Setting_Up  = 0x01,  // Running slcand / bringing interface up
    Ready       = 0x02,  // Adapter ready, interface up
    Error       = 0x03   // Setup failed
};

#endif // EADAPTERSTATE_H
