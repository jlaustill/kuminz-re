#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>
#include <QToolButton>
#include <QMenu>
#include <QAction>
#include "src/ui/types/EAdapterState.h"
#include "src/ui/types/EConnectionState.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class ConnectionWidget;
class StatusBarWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent* event) override;

private slots:
    void onAdapterStateChanged(EAdapterState state);
    void onEcuStateChanged(EConnectionState state);
    void onQuickConnectTriggered();
    void onLogMessage(const QString& message);

private:
    void setupToolbar();
    void setupDockWidget();
    void setupStatusBar();
    void loadWindowState();
    void saveWindowState();
    void updateQuickConnectButton();

    Ui::MainWindow *ui;

    // Connection UI components
    QDockWidget* m_connectionDock;
    ConnectionWidget* m_connectionWidget;
    StatusBarWidget* m_statusBarWidget;

    // Toolbar
    QToolButton* m_quickConnectButton;
    QMenu* m_deviceMenu;
    QAction* m_actionShowConnectionPanel;
};

#endif // MAINWINDOW_H
