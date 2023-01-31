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

    connect(this, SIGNAL(send(QString)), user_client, SLOT(slot_sendMessage(QString)));
    connect(user_client, SIGNAL(alreadyRead(QString)), this, SLOT(slot_displayMessage(QString)));
    connect(this->user_client, SIGNAL(disconnected()), this->server, SLOT(slot_disconnected()));
    connect(ui->send, SIGNAL(clicked()), this, SLOT(slot_sendMessage()));
    connect(ui->clearText, SIGNAL(clicked()), this, SLOT(slot_clearInput()));
    connect(server, SIGNAL(newConnection()), this, SLOT(slot_newClient()));
}

ChatRoom::~ChatRoom()
{
    delete ui;
}

void ChatRoom::setName(QString &name) {
    ui->name->setText(name);
}

void ChatRoom::newClient(ChatClient* newClient) {
    clients.push_back(newClient);
    connect(this, SIGNAL(send(QString)), newClient, SLOT(slot_sendMessage(QString)));
    connect(newClient, SIGNAL(alreadyRead(QString)), this, SLOT(slot_displayMessage(QString)));
    connect(newClient->getSocket(), SIGNAL(errorOccurred(QAbstractSocket::SocketError)), this->server, SLOT(slot_disconnected()));

}


void ChatRoom::setUserClient(ChatClient* &client) {
    QString name = client->getUsername();
    QPixmap pic = client->getAvatar();
    user_client->setUsername(name);
    user_client->setUserAvatar(pic);
}


// Slots
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


void ChatRoom::slot_newClient() {

}
