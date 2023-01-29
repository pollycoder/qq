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
    QString qssDir = ":/qss/chatclient.qss";
    SetStyleSheet(this, qssDir);
}

ChatClient::~ChatClient()
{
    delete ui;
}

void ChatClient::connectToServer() {
    if (!ifConnected) {
        socket->connectToHost("192.168.31.113", 9999);
        ifConnected = true;
        qDebug() << "New connection !" << username;
    }
}


void ChatClient::setUser(const QString &tel) {
    QString select = QString("select * from clients");
    QSqlQuery query;
    if (query.exec(select)) {
        QSqlTableModel model;
        model.setTable("clients");
        model.setFilter(QString("tel = '%1'").arg(tel));
        if (model.select()) {
            QSqlRecord record = model.record(0);
            avatar.loadFromData(record.value("avatar").toByteArray(), "JPG");
            LoadPixmap(ui->avatar, avatar);
            username = record.value("username").toString();
            ui->username->setText(username);
        }
    } else {
        QMessageBox::warning(NULL, "Something is wrong !", "Something bad happens, please try again.");
    }
}

void ChatClient::slot_sendMessage(QString input_msg) {
    QString msg = username + ": " + input_msg;
    socket->write(msg.toStdString().data());
    socket->waitForBytesWritten();
}

void ChatClient::slot_readMessage() {
    QString ori_msg(socket->readAll().data());
    message = ori_msg;
    emit alreadyRead(message);
}







