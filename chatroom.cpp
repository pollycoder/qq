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

    connect(this, SIGNAL(send(QString)), client, SLOT(slot_sendMessage(QString)));
    connect(ui->send, SIGNAL(clicked()), this, SLOT(slot_sendMessage()));
    connect(client, SIGNAL(alreadyRead(QString)), this, SLOT(slot_displayMessage(QString)));
    connect(ui->clearText, SIGNAL(clicked()), this, SLOT(slot_clearInput()));
}

ChatRoom::~ChatRoom()
{
    delete ui;
}


void ChatRoom::slot_sendMessage() {
    QString msg = ui->inputMsg->toPlainText();
    emit send(msg);
    ui->inputMsg->clear();
}

void ChatRoom::slot_displayMessage(QString msg) {
    ui->textBrowser->append(msg);
}

void ChatRoom::slot_clearInput() {
    ui->inputMsg->clear();
}
