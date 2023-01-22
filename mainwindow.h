#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>

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



static QSqlDatabase client_db = QSqlDatabase::addDatabase("QMYSQL");
const QString hostName = "localhost";
const QString dbName = "clients_db";
const QString userName = "root";
const QString password = "pollyjoe2003";
void init_database();
#endif // MAINWINDOW_H
