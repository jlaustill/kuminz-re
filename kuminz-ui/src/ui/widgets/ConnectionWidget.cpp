#include "ConnectionWidget.h"
#include "../../can/CanDeviceManager.h"
#include <clip/SocketCanAdapter.h>
#include <clip/ECUReader.h>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QSettings>
#include <QRegularExpressionValidator>

ConnectionWidget::ConnectionWidget(QWidget* parent)
    : QWidget(parent)
    , m_deviceCombo(nullptr)
    , m_adapterStatusIcon(nullptr)
    , m_adapterStatusText(nullptr)
    , m_adapterButton(nullptr)
    , m_ecuAddressEdit(nullptr)
    , m_ecuStatusIcon(nullptr)
    , m_ecuStatusText(nullptr)
    , m_ecuButton(nullptr)
    , m_deviceManager(std::make_unique<CanDeviceManager>(this))
    , m_adapter(std::make_unique<SocketCanAdapter>())
    , m_reader(std::make_unique<ECUReader>(m_adapter.get()))
    , m_adapterState(EAdapterState::NotReady)
    , m_ecuState(EConnectionState::Disconnected)
{
    setupUi();
    loadSettings();
    detectAvailableDevices();
    updateAdapterStatus();
    updateEcuStatus();

    // Set up ECUReader logging
    m_reader->setLogCallback([this](const std::string& msg) {
        emit logMessage(QString::fromStdString(msg));
    });

    // Connect device manager signals
    connect(m_deviceManager.get(), &CanDeviceManager::logMessage,
            this, &ConnectionWidget::logMessage);
}

ConnectionWidget::~ConnectionWidget()
{
    if (isEcuConnected()) {
        doDisconnectEcu();
    }
    if (isAdapterReady()) {
        doStopAdapter();
    }
    saveSettings();
}

void ConnectionWidget::setupUi()
{
    auto* mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(8, 8, 8, 8);
    mainLayout->setSpacing(8);

    // === Adapter Section ===
    auto* adapterGroup = new QGroupBox(tr("CAN Adapter"), this);
    auto* adapterLayout = new QVBoxLayout(adapterGroup);

    // Device selection row
    auto* deviceLayout = new QHBoxLayout();
    auto* deviceLabel = new QLabel(tr("Device:"), this);
    m_deviceCombo = new QComboBox(this);
    m_deviceCombo->setEditable(false);
    m_deviceCombo->setToolTip(tr("Select a CAN adapter"));
    m_deviceCombo->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    connect(m_deviceCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &ConnectionWidget::onDeviceSelectionChanged);
    deviceLayout->addWidget(deviceLabel);
    deviceLayout->addWidget(m_deviceCombo);
    adapterLayout->addLayout(deviceLayout);

    // Adapter status row
    auto* adapterStatusLayout = new QHBoxLayout();
    adapterStatusLayout->setSpacing(6);

    m_adapterStatusIcon = new QLabel(this);
    m_adapterStatusIcon->setFixedWidth(16);
    adapterStatusLayout->addWidget(m_adapterStatusIcon);

    m_adapterStatusText = new QLabel(this);
    m_adapterStatusText->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    adapterStatusLayout->addWidget(m_adapterStatusText);

    m_adapterButton = new QPushButton(tr("Setup"), this);
    m_adapterButton->setFixedWidth(80);
    connect(m_adapterButton, &QPushButton::clicked,
            this, &ConnectionWidget::setupAdapterClicked);
    adapterStatusLayout->addWidget(m_adapterButton);

    adapterLayout->addLayout(adapterStatusLayout);
    mainLayout->addWidget(adapterGroup);

    // === ECU Section ===
    auto* ecuGroup = new QGroupBox(tr("ECU Connection"), this);
    auto* ecuLayout = new QVBoxLayout(ecuGroup);

    // ECU address row
    auto* addressLayout = new QHBoxLayout();
    auto* addressLabel = new QLabel(tr("ECU Addr:"), this);
    m_ecuAddressEdit = new QLineEdit("0x00", this);
    m_ecuAddressEdit->setToolTip(tr("ECU address in hex (e.g., 0x00)"));
    m_ecuAddressEdit->setMaximumWidth(80);
    auto* hexValidator = new QRegularExpressionValidator(
        QRegularExpression("0x[0-9A-Fa-f]{1,2}"), this);
    m_ecuAddressEdit->setValidator(hexValidator);
    addressLayout->addWidget(addressLabel);
    addressLayout->addWidget(m_ecuAddressEdit);
    addressLayout->addStretch();
    ecuLayout->addLayout(addressLayout);

    // ECU status row
    auto* ecuStatusLayout = new QHBoxLayout();
    ecuStatusLayout->setSpacing(6);

    m_ecuStatusIcon = new QLabel(this);
    m_ecuStatusIcon->setFixedWidth(16);
    ecuStatusLayout->addWidget(m_ecuStatusIcon);

    m_ecuStatusText = new QLabel(this);
    m_ecuStatusText->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    ecuStatusLayout->addWidget(m_ecuStatusText);

    m_ecuButton = new QPushButton(tr("Connect"), this);
    m_ecuButton->setFixedWidth(80);
    connect(m_ecuButton, &QPushButton::clicked,
            this, &ConnectionWidget::connectEcuClicked);
    ecuStatusLayout->addWidget(m_ecuButton);

    ecuLayout->addLayout(ecuStatusLayout);
    mainLayout->addWidget(ecuGroup);

    // Spacer to push everything to the top
    mainLayout->addStretch();

    setLayout(mainLayout);
}

void ConnectionWidget::detectAvailableDevices()
{
    QString previousSelection;
    if (m_deviceCombo->currentIndex() >= 0 &&
        m_deviceCombo->currentIndex() < m_detectedDevices.size()) {
        previousSelection = m_detectedDevices[m_deviceCombo->currentIndex()].devicePath;
    }

    m_deviceCombo->clear();
    m_detectedDevices = m_deviceManager->detectDevices();

    if (m_detectedDevices.isEmpty()) {
        m_deviceCombo->addItem(tr("No devices found"));
        m_deviceCombo->setEnabled(false);
        m_adapterButton->setEnabled(false);
        return;
    }

    m_deviceCombo->setEnabled(true);
    m_adapterButton->setEnabled(true);

    int restoreIndex = -1;
    for (int i = 0; i < m_detectedDevices.size(); ++i) {
        const TCanDevice& device = m_detectedDevices[i];
        m_deviceCombo->addItem(device.displayName);

        if (device.devicePath == previousSelection) {
            restoreIndex = i;
        }
    }

    // Try to restore previous selection, or select first device
    if (restoreIndex >= 0) {
        m_deviceCombo->setCurrentIndex(restoreIndex);
    } else if (!m_detectedDevices.isEmpty()) {
        m_deviceCombo->setCurrentIndex(0);
        onDeviceSelectionChanged(0);
    }
}

void ConnectionWidget::onDeviceSelectionChanged(int index)
{
    if (index >= 0 && index < m_detectedDevices.size()) {
        m_selectedDevice = m_detectedDevices[index];

        // Update adapter state based on whether device is already active
        if (m_selectedDevice.isActive) {
            setAdapterState(EAdapterState::Ready);
        } else {
            setAdapterState(EAdapterState::NotReady);
        }
    }
}

void ConnectionWidget::loadSettings()
{
    QSettings settings;
    uint8_t ecuAddr = static_cast<uint8_t>(
        settings.value("connection/ecuAddress", 0).toUInt());

    if (m_ecuAddressEdit) {
        m_ecuAddressEdit->setText(QString("0x%1").arg(ecuAddr, 2, 16, QChar('0')));
    }

    // Device selection is restored after detectAvailableDevices()
    QString lastDevice = settings.value("connection/lastDevice", "").toString();
    if (!lastDevice.isEmpty()) {
        selectDeviceByPath(lastDevice);
    }
}

void ConnectionWidget::saveSettings()
{
    QSettings settings;

    if (m_selectedDevice.isValid()) {
        settings.setValue("connection/lastDevice", m_selectedDevice.devicePath);
    }

    bool ok;
    uint ecuAddr = m_ecuAddressEdit->text().toUInt(&ok, 16);
    if (ok) {
        settings.setValue("connection/ecuAddress", ecuAddr);
    }
}

TConnectionSettings ConnectionWidget::getSettings() const
{
    TConnectionSettings settings;

    if (m_selectedDevice.isValid()) {
        settings.deviceName = m_selectedDevice.interfaceName;
    } else {
        settings.deviceName = "can0";
    }

    bool ok;
    settings.ecuAddress = static_cast<uint8_t>(
        m_ecuAddressEdit->text().toUInt(&ok, 16));
    if (!ok) {
        settings.ecuAddress = 0x00;
    }

    return settings;
}

void ConnectionWidget::setSettings(const TConnectionSettings& settings)
{
    // Try to find and select the device by interface name
    for (int i = 0; i < m_detectedDevices.size(); ++i) {
        if (m_detectedDevices[i].interfaceName == settings.deviceName ||
            m_detectedDevices[i].devicePath == settings.deviceName) {
            m_deviceCombo->setCurrentIndex(i);
            break;
        }
    }

    m_ecuAddressEdit->setText(QString("0x%1").arg(settings.ecuAddress, 2, 16, QChar('0')));
}

void ConnectionWidget::selectDeviceByPath(const QString& devicePath)
{
    for (int i = 0; i < m_detectedDevices.size(); ++i) {
        if (m_detectedDevices[i].devicePath == devicePath) {
            m_deviceCombo->setCurrentIndex(i);
            return;
        }
    }
}

ECUReader* ConnectionWidget::reader() const
{
    return m_reader.get();
}

void ConnectionWidget::setAdapterState(EAdapterState state)
{
    if (m_adapterState != state) {
        m_adapterState = state;
        updateAdapterStatus();
        emit adapterStateChanged(state);

        if (state == EAdapterState::Ready) {
            emit adapterReady();
        } else if (state == EAdapterState::NotReady) {
            emit adapterStopped();
        }
    }
}

void ConnectionWidget::setEcuState(EConnectionState state)
{
    if (m_ecuState != state) {
        m_ecuState = state;
        updateEcuStatus();
        emit ecuStateChanged(state);

        if (state == EConnectionState::Connected) {
            emit ecuConnected();
        } else if (state == EConnectionState::Disconnected) {
            emit ecuDisconnected();
        }
    }
}

void ConnectionWidget::updateAdapterStatus()
{
    QString color;
    QString text;
    QString buttonText;
    bool buttonEnabled = true;
    bool deviceEnabled = true;

    switch (m_adapterState) {
    case EAdapterState::NotReady:
        color = "#888888";
        text = tr("Not ready");
        buttonText = tr("Setup");
        break;

    case EAdapterState::Setting_Up:
        color = "#FFA500";
        text = tr("Setting up...");
        buttonText = tr("Setup");
        buttonEnabled = false;
        deviceEnabled = false;
        break;

    case EAdapterState::Ready:
        color = "#00AA00";
        text = tr("Ready (%1)").arg(m_selectedDevice.interfaceName);
        buttonText = tr("Stop");
        deviceEnabled = false;
        break;

    case EAdapterState::Error:
        color = "#CC0000";
        text = tr("Error");
        buttonText = tr("Retry");
        break;
    }

    // Unicode filled circle for status indicator
    m_adapterStatusIcon->setText(QString::fromUtf8("\u25CF"));
    m_adapterStatusIcon->setStyleSheet(QString("color: %1; font-size: 14px;").arg(color));
    m_adapterStatusText->setText(text);

    m_adapterButton->setText(buttonText);
    m_adapterButton->setEnabled(buttonEnabled && !m_detectedDevices.isEmpty());
    m_deviceCombo->setEnabled(deviceEnabled && !m_detectedDevices.isEmpty());

    // ECU button only enabled when adapter is ready
    m_ecuButton->setEnabled(m_adapterState == EAdapterState::Ready);
    m_ecuAddressEdit->setEnabled(m_ecuState != EConnectionState::Connected);
}

void ConnectionWidget::updateEcuStatus()
{
    QString color;
    QString text;
    QString buttonText;
    bool buttonEnabled = true;

    switch (m_ecuState) {
    case EConnectionState::Disconnected:
        color = "#888888";
        text = tr("Disconnected");
        buttonText = tr("Connect");
        buttonEnabled = isAdapterReady();
        break;

    case EConnectionState::Connecting:
        color = "#FFA500";
        text = tr("Connecting...");
        buttonText = tr("Connect");
        buttonEnabled = false;
        break;

    case EConnectionState::Connected:
        color = "#00AA00";
        text = tr("Connected");
        buttonText = tr("Disconnect");
        break;

    case EConnectionState::Error:
        color = "#CC0000";
        text = tr("Connection failed");
        buttonText = tr("Retry");
        buttonEnabled = isAdapterReady();
        break;
    }

    m_ecuStatusIcon->setText(QString::fromUtf8("\u25CF"));
    m_ecuStatusIcon->setStyleSheet(QString("color: %1; font-size: 14px;").arg(color));
    m_ecuStatusText->setText(text);

    m_ecuButton->setText(buttonText);
    m_ecuButton->setEnabled(buttonEnabled);
    m_ecuAddressEdit->setEnabled(m_ecuState != EConnectionState::Connected &&
                                  m_ecuState != EConnectionState::Connecting);
}

void ConnectionWidget::setupAdapterClicked()
{
    if (isAdapterReady()) {
        doStopAdapter();
    } else {
        doSetupAdapter();
    }
}

void ConnectionWidget::connectEcuClicked()
{
    if (isEcuConnected()) {
        doDisconnectEcu();
    } else {
        doConnectEcu();
    }
}

void ConnectionWidget::quickSetupAdapter()
{
    if (isAdapterReady()) {
        return;  // Already ready
    }

    loadSettings();
    doSetupAdapter();
}

void ConnectionWidget::refreshDevices()
{
    detectAvailableDevices();
}

void ConnectionWidget::doSetupAdapter()
{
    if (!m_selectedDevice.isValid()) {
        emit errorOccurred(tr("No device selected"));
        setAdapterState(EAdapterState::Error);
        return;
    }

    setAdapterState(EAdapterState::Setting_Up);
    saveSettings();

    // Set up the device (runs slcand for SLCAN devices)
    // Use 250kbps for J1939 (Cummins ECUs)
    if (!m_deviceManager->setupDevice(m_selectedDevice,
                                      CanDeviceManager::CanSpeed::Speed250K)) {
        emit errorOccurred(tr("Failed to set up adapter: %1")
                               .arg(m_deviceManager->lastError()));
        setAdapterState(EAdapterState::Error);
        return;
    }

    // Mark device as active now
    m_selectedDevice.isActive = true;
    m_selectedDevice.needsSetup = false;

    setAdapterState(EAdapterState::Ready);
    emit logMessage(tr("Adapter ready: %1").arg(m_selectedDevice.interfaceName));
}

void ConnectionWidget::doStopAdapter()
{
    // Disconnect ECU first if connected
    if (isEcuConnected()) {
        doDisconnectEcu();
    }

    // Tear down the adapter
    m_deviceManager->teardownDevice(m_selectedDevice);

    m_selectedDevice.isActive = false;
    m_selectedDevice.needsSetup = true;

    setAdapterState(EAdapterState::NotReady);
    emit logMessage(tr("Adapter stopped"));
}

void ConnectionWidget::doConnectEcu()
{
    if (!isAdapterReady()) {
        emit errorOccurred(tr("Adapter not ready"));
        return;
    }

    setEcuState(EConnectionState::Connecting);

    TConnectionSettings settings = getSettings();

    bool success = m_reader->connect(
        m_selectedDevice.interfaceName.toStdString(),
        settings.ecuAddress);

    if (success) {
        setEcuState(EConnectionState::Connected);
        emit logMessage(tr("Connected to ECU at 0x%1")
                            .arg(settings.ecuAddress, 2, 16, QChar('0')));
    } else {
        setEcuState(EConnectionState::Error);
        emit errorOccurred(tr("Failed to connect to ECU"));
    }
}

void ConnectionWidget::doDisconnectEcu()
{
    m_reader->disconnect();
    setEcuState(EConnectionState::Disconnected);
    emit logMessage(tr("Disconnected from ECU"));
}
