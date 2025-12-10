#ifndef CONNECTIONWIDGET_H
#define CONNECTIONWIDGET_H

#include <QWidget>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <memory>
#include "../types/EAdapterState.h"
#include "../types/EConnectionState.h"
#include "../types/TConnectionSettings.h"
#include "../types/TCanDevice.h"

class SocketCanAdapter;
class ECUReader;
class CanDeviceManager;

/**
 * @brief Inline connection panel for CAN adapter configuration.
 *
 * Separates two concerns:
 * 1. Adapter setup (slcand, interface up) - hardware layer
 * 2. ECU connection (CLIP protocol) - protocol layer
 *
 * Layout:
 * +----------------------------------------------+
 * |  Device:   [v] OBDLink EX (ttyUSB1→can0)     |
 * |  Adapter:  [●] Ready        [ Setup Adapter ]|
 * +----------------------------------------------+
 * |  ECU Addr: [  0x00  ]                        |
 * |  ECU:      [●] Disconnected [ Connect ECU  ] |
 * +----------------------------------------------+
 */
class ConnectionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ConnectionWidget(QWidget* parent = nullptr);
    ~ConnectionWidget() override;

    // Prevent copying
    ConnectionWidget(const ConnectionWidget&) = delete;
    ConnectionWidget& operator=(const ConnectionWidget&) = delete;

    // Settings management
    void loadSettings();
    void saveSettings();
    TConnectionSettings getSettings() const;
    void setSettings(const TConnectionSettings& settings);

    // State access
    EAdapterState adapterState() const { return m_adapterState; }
    EConnectionState ecuState() const { return m_ecuState; }
    bool isAdapterReady() const { return m_adapterState == EAdapterState::Ready; }
    bool isEcuConnected() const { return m_ecuState == EConnectionState::Connected; }

    // Access to reader for other UI components
    ECUReader* reader() const;

    // Get list of detected devices (for toolbar menu)
    QList<TCanDevice> detectedDevices() const { return m_detectedDevices; }

signals:
    void adapterStateChanged(EAdapterState state);
    void ecuStateChanged(EConnectionState state);
    void adapterReady();
    void adapterStopped();
    void ecuConnected();
    void ecuDisconnected();
    void errorOccurred(const QString& message);
    void logMessage(const QString& message);

public slots:
    void setupAdapterClicked();
    void connectEcuClicked();
    void quickSetupAdapter();  // Use last saved device
    void refreshDevices();
    void selectDeviceByPath(const QString& devicePath);

private slots:
    void onDeviceSelectionChanged(int index);

private:
    void setupUi();
    void detectAvailableDevices();
    void setAdapterState(EAdapterState state);
    void setEcuState(EConnectionState state);
    void updateAdapterStatus();
    void updateEcuStatus();
    void doSetupAdapter();
    void doStopAdapter();
    void doConnectEcu();
    void doDisconnectEcu();

    // UI components - Adapter section
    QComboBox* m_deviceCombo;
    QLabel* m_adapterStatusIcon;
    QLabel* m_adapterStatusText;
    QPushButton* m_adapterButton;

    // UI components - ECU section
    QLineEdit* m_ecuAddressEdit;
    QLabel* m_ecuStatusIcon;
    QLabel* m_ecuStatusText;
    QPushButton* m_ecuButton;

    // Device management
    std::unique_ptr<CanDeviceManager> m_deviceManager;
    QList<TCanDevice> m_detectedDevices;
    TCanDevice m_selectedDevice;

    // Business logic (owned)
    std::unique_ptr<SocketCanAdapter> m_adapter;
    std::unique_ptr<ECUReader> m_reader;

    // State
    EAdapterState m_adapterState;
    EConnectionState m_ecuState;
};

#endif // CONNECTIONWIDGET_H
