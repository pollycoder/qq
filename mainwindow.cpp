#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize tcpserver
    QTcpServer* tmp_server = server->getServer();
    QHostAddress tmp_host = tmp_server->serverAddress();
    client->connectToServer(tmp_host);

    // Initialize the database of clients
    init_database();
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


// Initialize MYSQL
void init_database() {
    client_db.setHostName(hostName);
    client_db.setDatabaseName(dbName);
    client_db.setUserName(userName);
    client_db.setPassword(password);
    qDebug("Database open successfully ! %d\n", client_db.open());
    QSqlError error = client_db.lastError();
    qDebug() << error.text();
}
