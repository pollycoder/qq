#ifndef CHATROOM_H
#define CHATROOM_H

#include <QWidget>

#include "chatserver.h"
#include "chatclient.h"

namespace Ui {
class ChatRoom;
}

class ChatRoom : public QWidget
{
    Q_OBJECT

public:
    explicit ChatRoom(QWidget *parent = nullptr);
    ~ChatRoom();

    ChatServer* getServer() { return server; }
    void newClient(ChatClient* newClient);

private slots:
    void slot_sendMessage();
    void slot_displayMessage(QString msg);
    void slot_clearInput();
    void slot_newClient(ChatClient* client);

    signals:
    void send(QString);

public:
    ChatServer *server = new ChatServer();
    QVector<ChatClient*> clients;

    Ui::ChatRoom* getUi() { return ui; }
private:
    Ui::ChatRoom *ui;

};

#endif // CHATROOM_H
