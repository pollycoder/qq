#ifndef CHATCLIENT_H
#define CHATCLIENT_H

#include <QWidget>
#include <QTcpSocket>
#include <QHostAddress>
#include <QString>


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

    void connectToServer(); // Connect to the server

    QString getUsername() { return username; }

private slots:
    void slot_sendMessage(QString);
    void slot_readMessage();
    signals:
    void alreadyRead(QString);


private:
    Ui::ChatClient *ui;
    QTcpSocket *socket;
    QString username;
    QString password;
    bool ifConnected = false;
    QString message;
};



#endif // CHATCLIENT_H
