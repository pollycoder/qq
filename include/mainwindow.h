#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "register.h"
#include "chatroom.h"
#include "database.h"

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
    void slot_login();
    void slot_register();




private:
    Ui::MainWindow *ui;
    Register *regwindow = new Register();
    ChatClient *user_client = new ChatClient();
    Database *client_db;
};




#endif // MAINWINDOW_H
