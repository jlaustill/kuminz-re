#ifndef TCANDEVICE_H
#define TCANDEVICE_H

#include <QString>
#include "EAdapterType.h"

/**
 * @brief Represents a detected CAN-capable device.
 *
 * Can be either a native SocketCAN interface or a serial device
 * that can be bridged to SocketCAN via slcand.
 */
struct TCanDevice
{
    QString displayName;      // User-friendly name: "OBDLink EX (ttyUSB1 → can0)"
    QString devicePath;       // Serial device path: "/dev/ttyUSB1" or interface name "can0"
    QString interfaceName;    // SocketCAN interface name: "can0", "slcan0"
    QString serialNumber;     // Device serial number if available
    EAdapterType adapterType; // Type of adapter
    bool needsSetup;          // True if slcand setup is required
    bool isActive;            // True if interface is already up

    TCanDevice()
        : adapterType(EAdapterType::Unknown)
        , needsSetup(false)
        , isActive(false)
    {}

    /**
     * @brief Check if this is a valid, usable device.
     */
    bool isValid() const
    {
        return adapterType != EAdapterType::Unknown && !devicePath.isEmpty();
    }
};

#endif // TCANDEVICE_H
