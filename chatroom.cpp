#include "chatroom.h"
#include "ui_chatroom.h"

ChatRoom::ChatRoom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatRoom)
{
    ui->setupUi(this);

    // Initialize tcpserver
    QTcpServer* tmp_server = server->getServer();
    QHostAddress tmp_host = tmp_server->serverAddress();
    client->connectToServer(tmp_host);
}

ChatRoom::~ChatRoom()
{
    delete ui;
}
