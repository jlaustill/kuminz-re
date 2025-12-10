#ifndef CANDEVICEMANAGER_H
#define CANDEVICEMANAGER_H

#include <QObject>
#include <QList>
#include <QMap>
#include <QProcess>
#include "../ui/types/TCanDevice.h"

/**
 * @brief Manages CAN device detection and setup.
 *
 * Detects:
 * - Native SocketCAN interfaces (can0, vcan0, etc.)
 * - SLCAN-compatible USB devices (OBDLink EX, etc.)
 *
 * Handles:
 * - Running slcand to bridge serial devices to SocketCAN
 * - Bringing interfaces up/down via ip link
 */
class CanDeviceManager : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief SLCAN speed flags for slcand -s parameter.
     */
    enum class CanSpeed : uint8_t
    {
        Speed10K   = 0,  // -s0: 10 Kbps
        Speed20K   = 1,  // -s1: 20 Kbps
        Speed50K   = 2,  // -s2: 50 Kbps
        Speed100K  = 3,  // -s3: 100 Kbps
        Speed125K  = 4,  // -s4: 125 Kbps
        Speed250K  = 5,  // -s5: 250 Kbps (J1939)
        Speed500K  = 6,  // -s6: 500 Kbps (OBD-II)
        Speed800K  = 7,  // -s7: 800 Kbps
        Speed1M    = 8   // -s8: 1000 Kbps
    };

    explicit CanDeviceManager(QObject* parent = nullptr);
    ~CanDeviceManager() override;

    /**
     * @brief Scan for all available CAN devices.
     * @return List of detected devices (native + serial adapters)
     */
    QList<TCanDevice> detectDevices();

    /**
     * @brief Set up a device for use.
     *
     * For native interfaces: brings the interface up
     * For SLCAN devices: runs slcand then brings interface up
     *
     * @param device The device to set up
     * @param speed CAN bus speed (for SLCAN devices)
     * @return true if setup succeeded
     */
    bool setupDevice(const TCanDevice& device, CanSpeed speed = CanSpeed::Speed250K);

    /**
     * @brief Tear down a device.
     *
     * Brings interface down and kills slcand if applicable.
     *
     * @param device The device to tear down
     * @return true if teardown succeeded
     */
    bool teardownDevice(const TCanDevice& device);

    /**
     * @brief Check if a device is currently active.
     * @param interfaceName The SocketCAN interface name
     * @return true if interface exists and is up
     */
    bool isDeviceActive(const QString& interfaceName);

    /**
     * @brief Get the last error message.
     */
    QString lastError() const { return m_lastError; }

signals:
    void deviceSetupComplete(const QString& interfaceName, bool success);
    void deviceTeardownComplete(const QString& interfaceName, bool success);
    void logMessage(const QString& message);

private:
    QMap<QString, QString> detectRunningSlcand();
    QList<TCanDevice> detectNativeInterfaces(const QMap<QString, QString>& slcandMap);
    QList<TCanDevice> detectSerialAdapters(const QMap<QString, QString>& slcandMap);

    bool runSlcand(const QString& serialDevice, const QString& interfaceName, CanSpeed speed);
    bool killSlcand(const QString& interfaceName);
    bool setInterfaceUp(const QString& interfaceName);
    bool setInterfaceDown(const QString& interfaceName);

    QString findAvailableInterfaceName();
    TCanDevice parseSerialDeviceId(const QString& symlinkName, const QString& targetDevice, const QString& existingInterface = QString());

    QString m_lastError;
    QList<QProcess*> m_slcandProcesses;
};

#endif // CANDEVICEMANAGER_H
