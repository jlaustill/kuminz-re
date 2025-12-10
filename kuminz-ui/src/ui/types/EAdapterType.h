#ifndef EADAPTERTYPE_H
#define EADAPTERTYPE_H

#include <cstdint>

/**
 * @brief Type of CAN adapter.
 *
 * Used to determine how to set up and communicate with the device.
 */
enum class EAdapterType : uint8_t
{
    Unknown = 0x00,       // Unknown/unsupported device
    NativeSocketCAN,      // Native SocketCAN interface (can0, vcan0)
    SLCAN_OBDLinkEX,      // OBDLink EX - requires slcand setup
    SLCAN_Generic         // Generic SLCAN/LAWICEL device
};

#endif // EADAPTERTYPE_H
