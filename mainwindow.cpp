#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTcpServer* tmp_server = server->getServer();
    QHostAddress tmp_host = tmp_server->serverAddress();
    client->connectToServer(tmp_host);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_tcpserver_button_clicked(){
    server->show();
}


void MainWindow::on_tcpclient_button_clicked(){
    client->show();
}

