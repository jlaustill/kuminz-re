#include "StatusBarWidget.h"
#include <QHBoxLayout>

StatusBarWidget::StatusBarWidget(QWidget* parent)
    : QWidget(parent)
    , m_adapterIcon(new QLabel(this))
    , m_adapterText(new QLabel(this))
    , m_ecuIcon(new QLabel(this))
    , m_ecuText(new QLabel(this))
    , m_adapterState(EAdapterState::NotReady)
    , m_ecuState(EConnectionState::Disconnected)
{
    auto* layout = new QHBoxLayout(this);
    layout->setContentsMargins(4, 0, 4, 0);
    layout->setSpacing(4);

    // Adapter status
    m_adapterIcon->setFixedWidth(14);
    layout->addWidget(m_adapterIcon);
    layout->addWidget(m_adapterText);

    // Separator
    auto* separator = new QLabel("|", this);
    separator->setStyleSheet("color: #666666;");
    layout->addWidget(separator);

    // ECU status
    m_ecuIcon->setFixedWidth(14);
    layout->addWidget(m_ecuIcon);
    layout->addWidget(m_ecuText);

    setLayout(layout);

    // Set initial state
    updateDisplay();
}

void StatusBarWidget::setAdapterState(EAdapterState state, const QString& deviceName)
{
    m_adapterState = state;
    m_deviceName = deviceName;
    updateDisplay();
}

void StatusBarWidget::setEcuState(EConnectionState state)
{
    m_ecuState = state;
    updateDisplay();
}

void StatusBarWidget::updateDisplay()
{
    // Adapter status
    QString adapterColor;
    QString adapterText;

    switch (m_adapterState) {
    case EAdapterState::NotReady:
        adapterColor = "#888888";
        adapterText = tr("Adapter: Off");
        break;

    case EAdapterState::Setting_Up:
        adapterColor = "#FFA500";
        adapterText = tr("Adapter: Setting up...");
        break;

    case EAdapterState::Ready:
        adapterColor = "#00AA00";
        if (m_deviceName.isEmpty()) {
            adapterText = tr("Adapter: Ready");
        } else {
            adapterText = tr("Adapter: %1").arg(m_deviceName);
        }
        break;

    case EAdapterState::Error:
        adapterColor = "#CC0000";
        adapterText = tr("Adapter: Error");
        break;
    }

    m_adapterIcon->setText(QString::fromUtf8("\u25CF"));
    m_adapterIcon->setStyleSheet(QString("color: %1;").arg(adapterColor));
    m_adapterText->setText(adapterText);

    // ECU status
    QString ecuColor;
    QString ecuText;

    switch (m_ecuState) {
    case EConnectionState::Disconnected:
        ecuColor = "#888888";
        ecuText = tr("ECU: --");
        break;

    case EConnectionState::Connecting:
        ecuColor = "#FFA500";
        ecuText = tr("ECU: Connecting...");
        break;

    case EConnectionState::Connected:
        ecuColor = "#00AA00";
        ecuText = tr("ECU: Connected");
        break;

    case EConnectionState::Error:
        ecuColor = "#CC0000";
        ecuText = tr("ECU: Error");
        break;
    }

    m_ecuIcon->setText(QString::fromUtf8("\u25CF"));
    m_ecuIcon->setStyleSheet(QString("color: %1;").arg(ecuColor));
    m_ecuText->setText(ecuText);
}
