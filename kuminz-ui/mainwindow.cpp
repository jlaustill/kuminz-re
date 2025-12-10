#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "src/ui/widgets/ConnectionWidget.h"
#include "src/ui/widgets/StatusBarWidget.h"
#include "src/ui/types/TConnectionSettings.h"
#include "src/ui/types/TCanDevice.h"

#include <QToolBar>
#include <QSettings>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_connectionDock(nullptr)
    , m_connectionWidget(nullptr)
    , m_statusBarWidget(nullptr)
    , m_quickConnectButton(nullptr)
    , m_deviceMenu(nullptr)
    , m_actionShowConnectionPanel(nullptr)
{
    ui->setupUi(this);

    setWindowTitle(tr("Kuminz ECU Tool"));

    setupDockWidget();
    setupToolbar();
    setupStatusBar();
    loadWindowState();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    saveWindowState();
    event->accept();
}

void MainWindow::setupToolbar()
{
    QToolBar* toolbar = addToolBar(tr("Connection"));
    toolbar->setObjectName("ConnectionToolbar");
    toolbar->setMovable(false);

    // Quick Setup button with dropdown menu
    m_quickConnectButton = new QToolButton(this);
    m_quickConnectButton->setText(tr("Quick Setup"));
    m_quickConnectButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    m_quickConnectButton->setPopupMode(QToolButton::MenuButtonPopup);

    // Device selection menu
    m_deviceMenu = new QMenu(m_quickConnectButton);
    m_quickConnectButton->setMenu(m_deviceMenu);

    // Populate menu with detected devices from ConnectionWidget
    connect(m_deviceMenu, &QMenu::aboutToShow, this, [this]() {
        m_deviceMenu->clear();

        // Refresh device list
        m_connectionWidget->refreshDevices();
        QList<TCanDevice> devices = m_connectionWidget->detectedDevices();

        for (const TCanDevice& device : devices) {
            QAction* action = m_deviceMenu->addAction(device.displayName);
            QString devicePath = device.devicePath;
            connect(action, &QAction::triggered, this, [this, devicePath]() {
                m_connectionWidget->selectDeviceByPath(devicePath);
                m_connectionWidget->quickSetupAdapter();
            });
        }

        if (m_deviceMenu->isEmpty()) {
            QAction* noDevices = m_deviceMenu->addAction(tr("No CAN devices found"));
            noDevices->setEnabled(false);
        }
    });

    connect(m_quickConnectButton, &QToolButton::clicked,
            this, &MainWindow::onQuickConnectTriggered);

    toolbar->addWidget(m_quickConnectButton);

    toolbar->addSeparator();

    // Toggle connection panel visibility
    m_actionShowConnectionPanel = new QAction(tr("Connection Panel"), this);
    m_actionShowConnectionPanel->setCheckable(true);
    m_actionShowConnectionPanel->setChecked(true);
    connect(m_actionShowConnectionPanel, &QAction::triggered,
            m_connectionDock, &QDockWidget::setVisible);

    // Sync dock visibility with action (dock created before toolbar)
    connect(m_connectionDock, &QDockWidget::visibilityChanged,
            m_actionShowConnectionPanel, &QAction::setChecked);

    toolbar->addAction(m_actionShowConnectionPanel);
}

void MainWindow::setupDockWidget()
{
    // Create dock widget
    m_connectionDock = new QDockWidget(tr("Connection"), this);
    m_connectionDock->setObjectName("ConnectionDock");
    m_connectionDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    m_connectionDock->setFeatures(
        QDockWidget::DockWidgetClosable |
        QDockWidget::DockWidgetMovable);

    // Create connection widget
    m_connectionWidget = new ConnectionWidget(m_connectionDock);
    m_connectionDock->setWidget(m_connectionWidget);

    addDockWidget(Qt::LeftDockWidgetArea, m_connectionDock);

    // Connect signals
    connect(m_connectionWidget, &ConnectionWidget::adapterStateChanged,
            this, &MainWindow::onAdapterStateChanged);

    connect(m_connectionWidget, &ConnectionWidget::ecuStateChanged,
            this, &MainWindow::onEcuStateChanged);

    connect(m_connectionWidget, &ConnectionWidget::logMessage,
            this, &MainWindow::onLogMessage);

    connect(m_connectionWidget, &ConnectionWidget::errorOccurred,
            this, [this](const QString& msg) {
                statusBar()->showMessage(msg, 5000);
            });
}

void MainWindow::setupStatusBar()
{
    m_statusBarWidget = new StatusBarWidget(this);
    statusBar()->addPermanentWidget(m_statusBarWidget);

    // Connect to connection widget for adapter state
    connect(m_connectionWidget, &ConnectionWidget::adapterStateChanged,
            this, [this](EAdapterState state) {
                m_statusBarWidget->setAdapterState(
                    state,
                    m_connectionWidget->getSettings().deviceName);
            });

    // Connect to connection widget for ECU state
    connect(m_connectionWidget, &ConnectionWidget::ecuStateChanged,
            this, [this](EConnectionState state) {
                m_statusBarWidget->setEcuState(state);
            });
}

void MainWindow::loadWindowState()
{
    QSettings settings;

    // Restore window geometry
    if (settings.contains("ui/mainWindowGeometry")) {
        restoreGeometry(settings.value("ui/mainWindowGeometry").toByteArray());
    }

    // Restore dock/toolbar state
    if (settings.contains("ui/mainWindowState")) {
        restoreState(settings.value("ui/mainWindowState").toByteArray());
    }
}

void MainWindow::saveWindowState()
{
    QSettings settings;
    settings.setValue("ui/mainWindowGeometry", saveGeometry());
    settings.setValue("ui/mainWindowState", saveState());
}

void MainWindow::onAdapterStateChanged(EAdapterState state)
{
    updateQuickConnectButton();

    // Update window title based on adapter state
    if (m_connectionWidget->isEcuConnected()) {
        setWindowTitle(tr("Kuminz ECU Tool - ECU Connected"));
    } else if (state == EAdapterState::Ready) {
        setWindowTitle(tr("Kuminz ECU Tool - Adapter Ready"));
    } else {
        setWindowTitle(tr("Kuminz ECU Tool"));
    }
}

void MainWindow::onEcuStateChanged(EConnectionState state)
{
    // Update window title based on ECU state
    if (state == EConnectionState::Connected) {
        setWindowTitle(tr("Kuminz ECU Tool - ECU Connected"));
    } else if (m_connectionWidget->isAdapterReady()) {
        setWindowTitle(tr("Kuminz ECU Tool - Adapter Ready"));
    } else {
        setWindowTitle(tr("Kuminz ECU Tool"));
    }
}

void MainWindow::onQuickConnectTriggered()
{
    if (m_connectionWidget->isAdapterReady()) {
        // Stop adapter
        m_connectionWidget->setupAdapterClicked();
    } else {
        // Quick setup with saved settings
        m_connectionWidget->quickSetupAdapter();
    }
}

void MainWindow::onLogMessage(const QString& message)
{
    // Show log messages in status bar (temporary display)
    statusBar()->showMessage(message, 3000);
}

void MainWindow::updateQuickConnectButton()
{
    if (m_connectionWidget->isAdapterReady()) {
        m_quickConnectButton->setText(tr("Stop Adapter"));
    } else {
        m_quickConnectButton->setText(tr("Quick Setup"));
    }
}
