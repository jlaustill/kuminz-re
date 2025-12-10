#include "CanDeviceManager.h"
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QRegularExpression>
#include <QThread>
#include <QMap>
#include <QSet>

CanDeviceManager::CanDeviceManager(QObject* parent)
    : QObject(parent)
{
}

CanDeviceManager::~CanDeviceManager()
{
    // Clean up any running slcand processes
    for (QProcess* proc : m_slcandProcesses) {
        if (proc->state() != QProcess::NotRunning) {
            proc->terminate();
            proc->waitForFinished(1000);
            if (proc->state() != QProcess::NotRunning) {
                proc->kill();
            }
        }
        delete proc;
    }
    m_slcandProcesses.clear();
}

QList<TCanDevice> CanDeviceManager::detectDevices()
{
    QList<TCanDevice> devices;

    // First, detect running slcand processes to map serial devices to CAN interfaces
    QMap<QString, QString> slcandMap = detectRunningSlcand();

    // Detect serial adapters (this will use slcandMap to find existing interfaces)
    devices.append(detectSerialAdapters(slcandMap));

    // Detect native SocketCAN interfaces (excluding slcan interfaces)
    devices.append(detectNativeInterfaces(slcandMap));

    return devices;
}

QMap<QString, QString> CanDeviceManager::detectRunningSlcand()
{
    // Map from serial device path (e.g., "/dev/ttyUSB1") to CAN interface (e.g., "can0")
    QMap<QString, QString> result;

    QDir procDir("/proc");
    QStringList pids = procDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);

    for (const QString& pid : pids) {
        bool isNumber;
        pid.toInt(&isNumber);
        if (!isNumber) continue;

        // Read the command line
        QString cmdlinePath = QString("/proc/%1/cmdline").arg(pid);
        QFile cmdlineFile(cmdlinePath);
        if (!cmdlineFile.open(QIODevice::ReadOnly)) continue;

        QByteArray cmdline = cmdlineFile.readAll();
        // cmdline is null-separated
        QList<QByteArray> args = cmdline.split('\0');

        // Look for slcand
        if (args.isEmpty()) continue;
        QString exe = QString::fromUtf8(args[0]);
        if (!exe.contains("slcand")) continue;

        // Parse args to find the serial device and interface name
        // Format: slcand [options] <tty> [canif]
        QString serialDevice;
        QString canInterface;

        for (int i = 1; i < args.size(); ++i) {
            QString arg = QString::fromUtf8(args[i]);
            if (arg.isEmpty()) continue;
            if (arg.startsWith("-")) continue;  // Skip options

            // First non-option is the tty
            if (serialDevice.isEmpty()) {
                serialDevice = arg;
                // Normalize to full path
                if (!serialDevice.startsWith("/dev/")) {
                    serialDevice = "/dev/" + serialDevice;
                }
            } else if (canInterface.isEmpty()) {
                // Second non-option is the interface name
                canInterface = arg;
                break;
            }
        }

        if (!serialDevice.isEmpty() && !canInterface.isEmpty()) {
            result[serialDevice] = canInterface;
        }
    }

    return result;
}

QList<TCanDevice> CanDeviceManager::detectNativeInterfaces(const QMap<QString, QString>& slcandMap)
{
    QList<TCanDevice> devices;

    // Build a set of CAN interfaces that are managed by slcand (to exclude them)
    QSet<QString> slcanInterfaces;
    for (auto it = slcandMap.begin(); it != slcandMap.end(); ++it) {
        slcanInterfaces.insert(it.value());
    }

    QDir netDir("/sys/class/net");
    QStringList entries = netDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);

    for (const QString& entry : entries) {
        // Skip interfaces managed by slcand - they'll be shown via serial adapters
        if (slcanInterfaces.contains(entry)) {
            continue;
        }

        QString typePath = QString("/sys/class/net/%1/type").arg(entry);
        QFile typeFile(typePath);
        if (typeFile.open(QIODevice::ReadOnly)) {
            QString typeStr = QString::fromUtf8(typeFile.readLine()).trimmed();
            if (typeStr == "280") {  // ARPHRD_CAN
                // Check if this is a virtual/slcan interface without a running slcand
                // (orphaned interface from a previous session)
                QString deviceLink = QString("/sys/class/net/%1/device").arg(entry);
                if (!QFile::exists(deviceLink)) {
                    // Virtual interface (slcan or vcan) - skip unless it's vcan
                    if (!entry.startsWith("vcan")) {
                        continue;  // Orphaned slcan interface, skip it
                    }
                }

                TCanDevice device;
                device.displayName = entry;
                device.devicePath = entry;
                device.interfaceName = entry;
                device.adapterType = EAdapterType::NativeSocketCAN;
                device.needsSetup = false;
                device.isActive = isDeviceActive(entry);

                devices.append(device);
            }
        }
    }

    return devices;
}

QList<TCanDevice> CanDeviceManager::detectSerialAdapters(const QMap<QString, QString>& slcandMap)
{
    QList<TCanDevice> devices;

    QDir serialDir("/dev/serial/by-id");
    if (!serialDir.exists()) {
        return devices;
    }

    QStringList entries = serialDir.entryList(QDir::Files | QDir::NoDotAndDotDot);

    for (const QString& entry : entries) {
        QString fullPath = serialDir.absoluteFilePath(entry);
        QFileInfo fi(fullPath);

        if (fi.isSymLink()) {
            QString target = fi.symLinkTarget();
            // Get just the device name (ttyUSB1)
            QString deviceName = QFileInfo(target).fileName();
            QString devicePath = "/dev/" + deviceName;

            // Check if slcand is already running for this device
            QString existingInterface = slcandMap.value(devicePath);

            TCanDevice device = parseSerialDeviceId(entry, devicePath, existingInterface);
            if (device.isValid()) {
                devices.append(device);
            }
        }
    }

    return devices;
}

TCanDevice CanDeviceManager::parseSerialDeviceId(const QString& symlinkName, const QString& targetDevice, const QString& existingInterface)
{
    TCanDevice device;
    device.devicePath = targetDevice;

    // If slcand is already running for this device, use that interface
    bool alreadySetup = !existingInterface.isEmpty();
    device.needsSetup = !alreadySetup;
    device.isActive = alreadySetup && isDeviceActive(existingInterface);

    // Parse the symlink name to identify the device
    // Format: usb-<Vendor>_<Product>_<Serial>-if<N>-port<N>

    // OBDLink EX detection
    // Example: usb-ScanTool.net_LLC_OBDLink_EX_223010258164-if00-port0
    if (symlinkName.contains("OBDLink_EX", Qt::CaseInsensitive)) {
        device.adapterType = EAdapterType::SLCAN_OBDLinkEX;

        // Extract serial number
        QRegularExpression serialRx("OBDLink_EX_([0-9]+)");
        QRegularExpressionMatch match = serialRx.match(symlinkName);
        if (match.hasMatch()) {
            device.serialNumber = match.captured(1);
        }

        // Use existing interface or find a new one
        device.interfaceName = alreadySetup ? existingInterface : findAvailableInterfaceName();

        // Extract device file name for display (ttyUSB1)
        QString devName = QFileInfo(targetDevice).fileName();
        device.displayName = QString("OBDLink EX (%1 → %2)")
                                 .arg(devName)
                                 .arg(device.interfaceName);

        return device;
    }

    // OBDLink SX detection
    if (symlinkName.contains("OBDLink_SX", Qt::CaseInsensitive)) {
        device.adapterType = EAdapterType::SLCAN_Generic;
        device.interfaceName = alreadySetup ? existingInterface : findAvailableInterfaceName();
        QString devName = QFileInfo(targetDevice).fileName();
        device.displayName = QString("OBDLink SX (%1 → %2)")
                                 .arg(devName)
                                 .arg(device.interfaceName);
        return device;
    }

    // OBDLink MX/MX+ detection
    if (symlinkName.contains("OBDLink_MX", Qt::CaseInsensitive)) {
        device.adapterType = EAdapterType::SLCAN_Generic;
        device.interfaceName = alreadySetup ? existingInterface : findAvailableInterfaceName();
        QString devName = QFileInfo(targetDevice).fileName();
        device.displayName = QString("OBDLink MX (%1 → %2)")
                                 .arg(devName)
                                 .arg(device.interfaceName);
        return device;
    }

    // CANable detection
    if (symlinkName.contains("CANable", Qt::CaseInsensitive) ||
        symlinkName.contains("canable", Qt::CaseInsensitive)) {
        device.adapterType = EAdapterType::SLCAN_Generic;
        device.interfaceName = alreadySetup ? existingInterface : findAvailableInterfaceName();
        QString devName = QFileInfo(targetDevice).fileName();
        device.displayName = QString("CANable (%1 → %2)")
                                 .arg(devName)
                                 .arg(device.interfaceName);
        return device;
    }

    // Generic FTDI device - might be SLCAN compatible
    // Be conservative - only include if it looks CAN-related
    if (symlinkName.contains("CAN", Qt::CaseInsensitive) ||
        symlinkName.contains("SLCAN", Qt::CaseInsensitive)) {
        device.adapterType = EAdapterType::SLCAN_Generic;
        device.interfaceName = alreadySetup ? existingInterface : findAvailableInterfaceName();
        QString devName = QFileInfo(targetDevice).fileName();
        device.displayName = QString("SLCAN Device (%1 → %2)")
                                 .arg(devName)
                                 .arg(device.interfaceName);
        return device;
    }

    // Unknown device - return invalid
    device.adapterType = EAdapterType::Unknown;
    return device;
}

QString CanDeviceManager::findAvailableInterfaceName()
{
    // Find an unused can<N> name
    for (int i = 0; i < 100; i++) {
        QString name = QString("can%1").arg(i);
        QString path = QString("/sys/class/net/%1").arg(name);
        if (!QFile::exists(path)) {
            return name;
        }
    }
    return "can0";  // Fallback
}

bool CanDeviceManager::setupDevice(const TCanDevice& device, CanSpeed speed)
{
    emit logMessage(QString("Setting up device: %1").arg(device.displayName));

    if (device.adapterType == EAdapterType::NativeSocketCAN) {
        // Native interface - just bring it up
        if (!device.isActive) {
            return setInterfaceUp(device.interfaceName);
        }
        return true;
    }

    // SLCAN device - run slcand and ip link in one pkexec call to minimize password prompts
    emit logMessage(QString("Setting up SLCAN: %1 → %2 (speed %3)")
                        .arg(device.devicePath)
                        .arg(device.interfaceName)
                        .arg(static_cast<int>(speed)));

    // Build a shell command that:
    // 1. Kills any existing slcand processes (use -x for exact match, not -f which would match this shell too!)
    // 2. Brings down any existing interface
    // 3. Starts slcand
    // 4. Brings the interface up
    // NOTE: We use "pkill -x slcand" instead of "pkill -f 'slcand.*can0'" because
    // the -f flag matches the full command line, which would include this sh -c command itself!
    QString shellCmd = QString(
        "pkill -x slcand 2>/dev/null; "
        "ip link set %3 down 2>/dev/null; "
        "sleep 0.1; "
        "slcand -o -c -s%1 %2 %3 && sleep 0.2 && ip link set %3 up")
                           .arg(static_cast<int>(speed))
                           .arg(device.devicePath)  // Full path with /dev/
                           .arg(device.interfaceName);

    emit logMessage(QString("Requesting elevated privileges..."));

    QProcess setup;
    setup.start("pkexec", QStringList() << "sh" << "-c" << shellCmd);

    if (!setup.waitForStarted(5000)) {
        m_lastError = QString("Failed to start pkexec: %1").arg(setup.errorString());
        emit logMessage(m_lastError);
        return false;
    }

    if (!setup.waitForFinished(30000)) {  // 30 second timeout for password prompt
        m_lastError = QString("Timeout waiting for setup (did you cancel the password prompt?)");
        emit logMessage(m_lastError);
        setup.kill();
        return false;
    }

    if (setup.exitCode() != 0) {
        QString stdoutStr = QString::fromUtf8(setup.readAllStandardOutput());
        QString stderrStr = QString::fromUtf8(setup.readAllStandardError());

        QString combined = stderrStr.isEmpty() ? stdoutStr : stderrStr;

        if (setup.exitCode() == 126) {
            m_lastError = QString("Authorization denied - password prompt was cancelled");
        } else if (setup.exitCode() == 127) {
            m_lastError = QString("slcand not found - is can-utils installed?");
        } else {
            m_lastError = QString("Setup failed (exit %1): %2")
                              .arg(setup.exitCode())
                              .arg(combined.isEmpty() ? "unknown error" : combined.trimmed());
        }
        emit logMessage(m_lastError);
        return false;
    }

    // Verify interface was created
    QString ifPath = QString("/sys/class/net/%1").arg(device.interfaceName);
    if (!QFile::exists(ifPath)) {
        m_lastError = QString("Failed to create interface %1").arg(device.interfaceName);
        emit logMessage(m_lastError);
        return false;
    }

    emit logMessage(QString("Device %1 ready").arg(device.interfaceName));
    emit deviceSetupComplete(device.interfaceName, true);
    return true;
}

bool CanDeviceManager::teardownDevice(const TCanDevice& device)
{
    emit logMessage(QString("Tearing down device: %1").arg(device.displayName));

    if (device.adapterType == EAdapterType::NativeSocketCAN) {
        // Just bring interface down
        setInterfaceDown(device.interfaceName);
    } else {
        // SLCAN device - bring down and kill slcand in one pkexec call
        // Use pkill -x for exact process name match (not -f which matches command line and could match this shell)
        QString shellCmd = QString("ip link set %1 down 2>/dev/null; pkill -x slcand 2>/dev/null; true")
                               .arg(device.interfaceName);

        QProcess teardown;
        teardown.start("pkexec", QStringList() << "sh" << "-c" << shellCmd);
        teardown.waitForFinished(30000);
    }

    emit deviceTeardownComplete(device.interfaceName, true);
    return true;
}

bool CanDeviceManager::runSlcand(const QString& serialDevice, const QString& interfaceName, CanSpeed speed)
{
    emit logMessage(QString("Running slcand: %1 → %2 (speed %3)")
                        .arg(serialDevice)
                        .arg(interfaceName)
                        .arg(static_cast<int>(speed)));

    // Use pkexec for privilege escalation - will prompt user for password
    QProcess slcand;

    QStringList args;
    args << "slcand"                                // Command to run with elevated privileges
         << "-o"                                    // Send open command
         << "-c"                                    // Send close command on exit
         << QString("-s%1").arg(static_cast<int>(speed))  // Speed
         << serialDevice.mid(5)                     // Device without /dev/ prefix
         << interfaceName;                          // Interface name

    emit logMessage(QString("Requesting elevated privileges for slcand..."));
    slcand.start("pkexec", args);

    if (!slcand.waitForStarted(5000)) {
        m_lastError = QString("Failed to start pkexec: %1").arg(slcand.errorString());
        emit logMessage(m_lastError);
        return false;
    }

    // pkexec + slcand: wait for completion (slcand daemonizes after pkexec returns)
    if (!slcand.waitForFinished(30000)) {  // 30 second timeout for user to enter password
        m_lastError = QString("Timeout waiting for slcand (did you cancel the password prompt?)");
        emit logMessage(m_lastError);
        slcand.kill();
        return false;
    }

    if (slcand.exitCode() != 0) {
        QString stderr = QString::fromUtf8(slcand.readAllStandardError());
        if (slcand.exitCode() == 126) {
            m_lastError = QString("Authorization denied - password prompt was cancelled");
        } else if (slcand.exitCode() == 127) {
            m_lastError = QString("slcand not found - is can-utils installed?");
        } else {
            m_lastError = QString("slcand failed (exit %1): %2")
                              .arg(slcand.exitCode())
                              .arg(stderr.isEmpty() ? "unknown error" : stderr.trimmed());
        }
        emit logMessage(m_lastError);
        return false;
    }

    // Check if the interface was created
    QThread::msleep(200);  // Give it a moment
    QString ifPath = QString("/sys/class/net/%1").arg(interfaceName);
    if (!QFile::exists(ifPath)) {
        m_lastError = QString("slcand failed to create interface %1").arg(interfaceName);
        emit logMessage(m_lastError);
        return false;
    }

    emit logMessage(QString("slcand started successfully"));
    return true;
}

bool CanDeviceManager::killSlcand(const QString& interfaceName)
{
    // Kill slcand process by finding and terminating it
    // slcand daemonizes and runs as root, so we need pkexec to kill it
    // Use -x for exact process name match (not -f which would also match this process)
    Q_UNUSED(interfaceName);  // We kill all slcand processes for simplicity
    emit logMessage(QString("Stopping slcand..."));

    QProcess pkill;
    pkill.start("pkexec", QStringList() << "pkill" << "-x" << "slcand");
    pkill.waitForFinished(30000);

    return true;
}

bool CanDeviceManager::setInterfaceUp(const QString& interfaceName)
{
    emit logMessage(QString("Bringing up interface: %1").arg(interfaceName));

    // Use pkexec for privilege escalation
    QProcess ip;
    ip.start("pkexec", QStringList() << "ip" << "link" << "set" << interfaceName << "up");

    if (!ip.waitForFinished(30000)) {  // 30 second timeout for password prompt
        m_lastError = QString("Failed to bring up %1: timeout").arg(interfaceName);
        emit logMessage(m_lastError);
        return false;
    }

    if (ip.exitCode() != 0) {
        if (ip.exitCode() == 126) {
            m_lastError = QString("Authorization denied for ip link");
        } else {
            m_lastError = QString("Failed to bring up %1: %2")
                              .arg(interfaceName)
                              .arg(QString::fromUtf8(ip.readAllStandardError()));
        }
        emit logMessage(m_lastError);
        return false;
    }

    emit logMessage(QString("Interface %1 is up").arg(interfaceName));
    return true;
}

bool CanDeviceManager::setInterfaceDown(const QString& interfaceName)
{
    emit logMessage(QString("Bringing down interface: %1").arg(interfaceName));

    // Use pkexec for privilege escalation
    QProcess ip;
    ip.start("pkexec", QStringList() << "ip" << "link" << "set" << interfaceName << "down");
    ip.waitForFinished(30000);
    return ip.exitCode() == 0;
}

bool CanDeviceManager::isDeviceActive(const QString& interfaceName)
{
    QString operstatePath = QString("/sys/class/net/%1/operstate").arg(interfaceName);
    QFile operstateFile(operstatePath);
    if (operstateFile.open(QIODevice::ReadOnly)) {
        QString state = QString::fromUtf8(operstateFile.readLine()).trimmed();
        return (state == "up" || state == "unknown");
    }
    return false;
}
