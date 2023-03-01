#include "chatclient.h"
#include "chatroom.h"
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

    connect(ui->chats, SIGNAL(clicked()), this, SLOT(slot_chats()));
    connect(ui->friends, SIGNAL(clicked()), this, SLOT(slot_friends()));
    connect(ui->logout, SIGNAL(clicked()), this, SLOT(slot_logout()));

    connect(ui->chatrooms, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(slot_doubleclickedChatRoom(QModelIndex)));

    socket = new QTcpSocket(this);
    SetKeepAlive(socket);
    connect(socket, SIGNAL(readyRead()), this, SLOT(slot_readMessage()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(slot_disconnected()));
    connect(socket, SIGNAL(hostFound()), this, SLOT(slot_connected()));
    connectToServer();

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
        socket->connectToHost("192.168.31.113", 9999);

        if (!ifConnected){
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
            emit userInfo(username);
        }
    } else {
        QMessageBox::warning(NULL, "Something is wrong !", "Something bad happens, please try again.");
    }
}



void ChatClient::slot_sendMessage(QString input_msg) {
    QDateTime time = QDateTime::currentDateTime();
    QString msg = QString("<font color=orange>%1</font>").
                  arg("[" + time.toString("yyyy-MM-dd hh:mm:ss dddd") + "]")
                  + username + ": " + input_msg;
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
    switch (socket->state()) {
        case QAbstractSocket::UnconnectedState: {
            socket->close();
            socket->abort();
            socket->connectToHost("192.168.31.113", 9999);
            break;
        }
        case QAbstractSocket::HostLookupState:
            break;
        case QAbstractSocket::ConnectingState:
            break;
        case QAbstractSocket::ConnectedState:
            break;
        case QAbstractSocket::BoundState:
            break;
        case QAbstractSocket::ListeningState:
            break;
        case QAbstractSocket::ClosingState:
            break;
    }
}

void ChatClient::slot_sendUserInfo() {
    emit userInfo(username);
}

void ChatClient::slot_chats() {
    QStandardItemModel* root_model = new QStandardItemModel();
    QStandardItem* model1 = new QStandardItem(QIcon(":/img/chatroom.png"), "Chattery Forum");
    QStandardItem* model2 = new QStandardItem(QIcon(":/img/chatroom.png"), "Chattery Family");
    root_model->appendRow(model1);
    root_model->appendRow(model2);
    ui->chatrooms->setModel(root_model);
}

void ChatClient::slot_friends() {
    QStandardItemModel* root_model = new QStandardItemModel();
    QStandardItem* model1 = new QStandardItem(QIcon(":/img/user_boy.png"), "Mary");
    QStandardItem* model2 = new QStandardItem(QIcon(":/img/user_boy.png"), "Jessie");
    root_model->appendRow(model1);
    root_model->appendRow(model2);
    ui->chatrooms->setModel(root_model);
}

void ChatClient::slot_logout() {
    emit logout();
}

void ChatClient::slot_doubleclickedChatRoom(QModelIndex model) {
    qDebug() << "Chatroom open !";
    QString roomName = ui->chatrooms->model()->data(model).toString();
    emit openRoom(roomName);
}

