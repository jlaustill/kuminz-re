#ifndef TCONNECTIONSETTINGS_H
#define TCONNECTIONSETTINGS_H

#include <QString>
#include <cstdint>

/**
 * @brief Settings for CAN connection.
 *
 * Persisted via QSettings for quick connect functionality.
 */
struct TConnectionSettings
{
    QString deviceName;   // CAN device name: "can0", "vcan0", etc.
    uint8_t ecuAddress;   // ECU address, typically 0x00

    TConnectionSettings()
        : deviceName("can0")
        , ecuAddress(0x00)
    {}

    TConnectionSettings(const QString& device, uint8_t ecu)
        : deviceName(device)
        , ecuAddress(ecu)
    {}
};

#endif // TCONNECTIONSETTINGS_H
