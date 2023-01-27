#include "chatclient.h"
#include "chatroom.h"
#include "ui_chatclient.h"


/******************************************
 * Client
 ******************************************/
ChatClient::ChatClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatClient)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(slot_readMessage()));
}

ChatClient::~ChatClient()
{
    delete ui;
}

void ChatClient::connectToServer() {
    if (!ifConnected) {
        socket->connectToHost("192.168.31.113", 9999);
        ifConnected = true;
    }
}

void ChatClient::slot_sendMessage(QString input_msg) {
    QString msg = input_msg;
    socket->write(msg.toStdString().data());
    socket->waitForBytesWritten();
}

void ChatClient::slot_readMessage() {
    QString ori_msg(socket->readAll().data());
    message = username + ":" + ori_msg;
    emit alreadyRead(message);
}







