#include "chatclient.h"
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
    connect(ui->sendbutton, SIGNAL(clicked()), this, SLOT(slot_sendMessage()));
}

ChatClient::~ChatClient()
{
    delete ui;
}

void ChatClient::connectToServer(QHostAddress &host) {
    if (!ifConnected) {
        socket->connectToHost(host, 9999);
        ifConnected = true;
    }
}

void ChatClient::slot_sendMessage() {
    QString msg = ui->inputbox->toPlainText();
    socket->write(msg.toStdString().data());
    socket->waitForBytesWritten();
    ui->inputbox->clear();
}

void ChatClient::slot_readMessage() {
    QString ori_msg(socket->readAll().data());
    message = username + ":" + ori_msg;
}







