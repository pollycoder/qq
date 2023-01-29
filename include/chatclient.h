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

    QString getUsername() { return username; }
    QTcpSocket* getSocket() { return socket; }
    void setUser(const QString &tel);



private slots:
    void slot_sendMessage(QString);
    void slot_readMessage();
    void slot_disconnected();
    void slot_connected() {
        ifConnected = true;
        qDebug() << "Reconnected successfully !";
    }
    void slot_sendUserInfo();
    signals:
    void alreadyRead(QString);


private:
    int failureTime = 0;
    Ui::ChatClient *ui;
    QTcpSocket *socket;
    QString username;
    bool ifConnected = false;
    QString message;
    QVector<ChatClient*> friends;
    QPixmap avatar;
};



#endif // CHATCLIENT_H
