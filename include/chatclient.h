#ifndef CHATCLIENT_H
#define CHATCLIENT_H

#include <QWidget>
#include <QTcpSocket>
#include <QHostAddress>
#include <QString>
#include <QPixmap>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QStandardItemModel>
#include <QIcon>
#include <QPainter>

#include "utils.h"

class ChatRoom;

namespace Ui {
class ChatClient;
}

class ChatClient : public QWidget
{
    Q_OBJECT

public:
    explicit ChatClient(QWidget *parent = nullptr);
    ~ChatClient();

    void paintEvent(QPaintEvent *);

    void connectToServer(); // Connect to the server

    void setUsername(QString &name) { username = name; }
    void setUserAvatar(QPixmap pic) { avatar = pic; }
    QString getUsername() { return username; }
    QPixmap getAvatar() { return avatar; }
    QTcpSocket* getSocket() { return socket; }
    void setUser(const QString &tel);
    void newUser() {
        username = "";
        avatar = QPixmap();
        friends.clear();
        message = "";
        failureTime = 0;
    }



private slots:
    void slot_sendMessage(QString);
    void slot_readMessage();
    void slot_disconnected();
    void slot_connected() { ifConnected = true; }
    void slot_sendUserInfo();
    void slot_chats();
    void slot_friends();
    void slot_logout();
    void slot_doubleclickedChatRoom(QModelIndex model);
    signals:
    void alreadyRead(QString);
    void logout();
    void openRoom(QString);


private:
    int failureTime = 0;
    Ui::ChatClient *ui;
    QTcpSocket *socket;
    QString username = "polly1";
    bool ifConnected = false;
    QString message;
    QVector<ChatClient*> friends;
    QPixmap avatar;
};



#endif // CHATCLIENT_H
