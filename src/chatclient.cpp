#include "chatclient.h"
#include "ui_chatclient.h"
#include <QAbstractSocket>



/******************************************
 * Client
 ******************************************/
ChatClient::ChatClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatClient)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    SetKeepAlive(socket);
    connect(socket, SIGNAL(readyRead()), this, SLOT(slot_readMessage()));
    connect(socket, SIGNAL(errorOccurred(QAbstractSocket::SocketError)), this, SLOT(slot_disconnected()));
    connect(socket, SIGNAL(hostFound()), this, SLOT(slot_connected()));
    connectToServer();

    QStandardItemModel* root_model = new QStandardItemModel();
    QStandardItem* model_forum = new QStandardItem(QIcon(":/img/chatroom.png"), "Chattery Forum");
    QStandardItem* model_family = new QStandardItem(QIcon(":/img/chatroom.png"), "Chattery Family");
    root_model->appendRow(model_forum);
    root_model->appendRow(model_family);
    ui->chatrooms->setModel(root_model);

    setMinimumSize(588,408);
    setMaximumSize(588,408);
    QString qssDir = ":/qss/chatclient.qss";
    SetStyleSheet(this, qssDir);
}

ChatClient::~ChatClient()
{
    delete ui;
}


void ChatClient::paintEvent(QPaintEvent *) {
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}


void ChatClient::connectToServer() {
    if (!ifConnected) {
        qDebug() << "try to reconnect";
        socket->connectToHost("192.168.31.113", 9999);

        if (ifConnected) {
            qDebug() << "New connection !" << username;
        }
        else {
            failureTime += 1;
            connectToServer();
            if (failureTime >= 3) {
                QMessageBox::warning(NULL, "Failed to connect", "Too many failure times ! Please check your network and restart the app.");
                return;
            }
        }
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


void ChatClient::slot_disconnected() {
    ifConnected = false;
    connectToServer();
}

void ChatClient::slot_sendUserInfo() {
    socket->write(username.toStdString().data());
    socket->waitForBytesWritten();
}



