#ifndef STATUSBARWIDGET_H
#define STATUSBARWIDGET_H

#include <QWidget>
#include <QLabel>
#include "../types/EAdapterState.h"
#include "../types/EConnectionState.h"

/**
 * @brief Compact connection status widget for status bar.
 *
 * Displays both adapter and ECU status:
 * [●] can0  [●] ECU Connected
 */
class StatusBarWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StatusBarWidget(QWidget* parent = nullptr);

public slots:
    void setAdapterState(EAdapterState state, const QString& deviceName = QString());
    void setEcuState(EConnectionState state);

private:
    void updateDisplay();

    // Adapter status
    QLabel* m_adapterIcon;
    QLabel* m_adapterText;

    // ECU status
    QLabel* m_ecuIcon;
    QLabel* m_ecuText;

    // Current states
    EAdapterState m_adapterState;
    EConnectionState m_ecuState;
    QString m_deviceName;
};

#endif // STATUSBARWIDGET_H
