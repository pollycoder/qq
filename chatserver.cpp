#include "chatserver.h"
#include "ui_chatserver.h"

ChatServer::ChatServer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatServer) {
    ui->setupUi(this);
    server = new QTcpServer();
    this->start_server();
    ui->ipaddr->setText(QString::number(this->getServer()->serverPort()));
}

ChatServer::~ChatServer() {
    this->close_server();
    delete ui;
}

void ChatServer::start_server() {
    server = new QTcpServer(this);
    server->listen(QHostAddress::Any, 9999);
    connect(server, SIGNAL(newConnection()), this, SLOT(slot_newConnection()));
}

void ChatServer::close_server() {
    server->close();
}

void ChatServer::send_message(const QByteArray &msg) {
    for(auto i : clients)
        i->write(msg);
}

void ChatServer::slot_newConnection() {
    QTcpSocket *new_client = server->nextPendingConnection();
    clients.push_back(new_client);
    connect(new_client, SIGNAL(readyRead()), this, SLOT(slot_readyRead()));
}

void ChatServer::slot_readyRead() {
    QTcpSocket *socket = (QTcpSocket*)QObject::sender();
    QByteArray str = socket->readAll().data();
    for(auto i : clients)
        i->write(str.toStdString().data());
}

void ChatServer::slot_disconnected() {

}
