#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "chatserver.h"
#include "chatclient.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_tcpserver_button_clicked();

    void on_tcpclient_button_clicked();

private:
    Ui::MainWindow *ui;
    ChatServer *server = new ChatServer();
    ChatClient *client = new ChatClient();
};
#endif // MAINWINDOW_H
